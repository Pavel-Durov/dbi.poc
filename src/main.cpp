
#include <iostream>
using std::cout;

#define LINUX
#define X86_32

#include "../drio/include/dr_api.h"

static void event_exit(void);

DR_EXPORT void dr_client_main(client_id_t id, int argc, const char *argv[])
{
    /* empty client */
    // dr_set_client_name("DynamoRIO Sample Client 'empty'", "http://dynamorio.org/issues");
    dr_register_exit_event(event_exit);
}

static void
event_exit(void)
{
    /* empty client */
}