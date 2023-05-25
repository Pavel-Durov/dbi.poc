#include "dr_api.h"


static void thread_init_event(void *drcontext)
{
    dr_fprintf(STDOUT, "Hello, from DynamoRIO client !\n");
}

DR_EXPORT void dr_client_main(client_id_t id, int argc, const char *argv[])
{
    dr_register_thread_init_event(thread_init_event);
}
