+#ifndef _MEMCLIENT_ANNOTATIONS_H_
+#define _MEMCLIENT_ANNOTATIONS_H_ 1

#include "dr_annotations_asm.h"

/* To simplify project configuration, this pragma excludes the file from GCC warnings. */
#ifdef __GNUC__
# pragma GCC system_header
#endif

#define MEMCLIENT_MARK_MEM_DEFINED_IF_ADDRESSABLE(start, size) DR_ANNOTATION(memclient_mark_mem_defined_if_addressable, start, size)


extern "C" {
    DR_DECLARE_ANNOTATION(void, memclient_mark_mem_defined_if_addressable, (void *p, size_t size));
}

#endif
