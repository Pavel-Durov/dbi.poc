#include "dr_api.h"

void handle_mark_mem_defined_if_addressable(void *p, size_t size)
{
    size_t *skip_size = dr_global_alloc(sizeof(size_t));
    hashtable_add_replace(skip_init_check_table, p, skip_size);
}
 
DR_EXPORT void dr_client_main(client_id_t id, int argc, const char *argv[])
{
    dr_annotation_register_call("memclient_mark_mem_defined_if_addressable",
                                handle_mark_mem_defined_if_addressable, false, 2);
}
