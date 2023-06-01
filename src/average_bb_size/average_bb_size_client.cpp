#include "dr_api.h"
#define DISPLAY_STRING(msg) dr_printf("%s\n", msg)
 
typedef struct bb_counts {
   uint64 blocks;
   uint64 total_size;
} bb_counts;
 
static bb_counts counts_as_built;
void *as_built_lock;

static bb_counts counts_dynamic;
void *count_lock;
 
static void
event_exit(void);
static dr_emit_flags_t
event_basic_block(void *drcontext, void *tag, instrlist_t *bb,
                  bool for_trace, bool translating);
 
DR_EXPORT void
dr_client_main(client_id_t id, int argc, const char *argv[])
{
    /* register events */
    dr_register_exit_event(event_exit);
    dr_register_bb_event(event_basic_block);
   /* initialize lock */
   as_built_lock = dr_mutex_create();
   count_lock = dr_mutex_create();
}

static void event_exit(void)
{
    /* Display results - we must first snpritnf the string as on windows
     * dr_printf(), dr_messagebox() and dr_fprintf() can't print floats. */
    char msg[512];
    int len;
    len = snprintf(msg, sizeof(msg)/sizeof(msg[0]),
                   "Number of blocks built : %" UINT64_FORMAT_CODE "\n"
                   "     Average size      : %5.2lf instructions\n"
                   "Number of blocks executed  : %" UINT64_FORMAT_CODE "\n"
                   "     Average weighted size : %5.2lf instructions\n",
                   counts_as_built.blocks,
                   counts_as_built.total_size / (double)counts_as_built.blocks,
                   counts_dynamic.blocks,
                   counts_dynamic.total_size / (double)counts_dynamic.blocks);

    DR_ASSERT(len > 0);
    msg[sizeof(msg)/sizeof(msg[0])-1] = '\0'; /* NUll terminate */
    DISPLAY_STRING(msg);

    /* free mutex */
    dr_mutex_destroy(as_built_lock);
    dr_mutex_destroy(count_lock);
}

static dr_emit_flags_t event_basic_block(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
    uint num_instructions = 0;
    instr_t *instr;
    /* count the number of instructions in this block */
    for (instr = instrlist_first(bb); instr != NULL; instr = instr_get_next(instr)) {
        num_instructions++;
    }

    /* update the as-built counts */
    dr_mutex_lock(as_built_lock);

    counts_as_built.blocks++;
    counts_as_built.total_size += num_instructions;
    dr_mutex_unlock(as_built_lock);

     /* increment counters */
     instr_t *where = instrlist_first(bb);
     dr_save_arith_flags(drcontext, bb, where, SPILL_SLOT_1);
 #ifdef X86_32
     /* Since the counters are 64-bit we must use an add + an addc to increment.
      * The operations is still effectively atomic since we're only increasing
      * the count. */
     instrlist_meta_preinsert(bb, where,
         LOCK(INSTR_CREATE_add(drcontext,
                               OPND_CREATE_ABSMEM((byte *)&counts_dynamic.blocks, OPSZ_4),
                               OPND_CREATE_INT8(1))));
     instrlist_meta_preinsert(bb, where,
         LOCK(INSTR_CREATE_adc(drcontext,
                               OPND_CREATE_ABSMEM((byte *)&counts_dynamic.blocks + 4, OPSZ_4),
                               OPND_CREATE_INT8(0))));

     instrlist_meta_preinsert(bb, where,
         LOCK(INSTR_CREATE_add(drcontext,
                               OPND_CREATE_ABSMEM((byte *)&counts_dynamic.total_size, OPSZ_4),
                               OPND_CREATE_INT_32OR8(num_instructions))));
     instrlist_meta_preinsert(bb, where,
         LOCK(INSTR_CREATE_adc(drcontext,
                               OPND_CREATE_ABSMEM((byte *)&counts_dynamic.total_size + 4, OPSZ_4),
                               OPND_CREATE_INT8(0))));
 #else /* X86_64 */
     instrlist_meta_preinsert(bb, where,
         LOCK(INSTR_CREATE_inc(drcontext,
                               OPND_CREATE_ABSMEM((byte *)&counts_dynamic.blocks, OPSZ_8))));
     instrlist_meta_preinsert(bb, where,
         LOCK(INSTR_CREATE_add(drcontext,
                               OPND_CREATE_ABSMEM((byte *)&counts_dynamic.total_size, OPSZ_8),
                               OPND_CREATE_INT_32OR8(num_instructions))));
 #endif
     dr_restore_arith_flags(drcontext, bb, where, SPILL_SLOT_1);

    return DR_EMIT_DEFAULT;
}
