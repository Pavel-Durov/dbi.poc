#include "dr_api.h"

typedef struct bb_counts
{
    uint64 blocks;
    uint64 total_size;
} bb_counts;

static bb_counts counts_as_built;
void *as_built_lock;

static void event_exit(void)
{
    dr_fprintf(STDOUT, "DEBUG: event_exit.\n");
    /* Display results - we must first snpritnf the string as on windows
     * dr_printf(), dr_messagebox() and dr_fprintf() can't print floats. */
    char msg[512];
    int len;
    len = snprintf(msg, sizeof(msg) / sizeof(msg[0]),
                   "Number of basic blocks built : %" UINT64_FORMAT_CODE "\n"
                   "     Average size            : %5.2lf instructions\n",
                   counts_as_built.blocks,
                   counts_as_built.total_size / (double)counts_as_built.blocks);
    DR_ASSERT(len > 0);
    msg[sizeof(msg) / sizeof(msg[0]) - 1] = '\0'; /* NUll terminate */
    dr_fprintf(STDOUT, msg);
    
    dr_mutex_destroy(as_built_lock); // free mutex 
}

static dr_emit_flags_t event_basic_block(void *drcontext, void *tag, instrlist_t *bb, bool for_trace, bool translating)
{
    dr_fprintf(STDOUT, "DEBUG: event_basic_block.\n");
    return DR_EMIT_DEFAULT;
}

DR_EXPORT void dr_client_main(client_id_t id, int argc, const char *argv[])
{
    dr_register_exit_event(event_exit);
    dr_register_bb_event(event_basic_block);
    
    as_built_lock = dr_mutex_create(); // initialize lock
}
