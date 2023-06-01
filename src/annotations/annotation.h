#ifndef _DYNAMORIO_ANNOTATIONS_H_
#define _DYNAMORIO_ANNOTATIONS_H_ 1
 
#include "dr_annotations_asm.h"
 
/* To simplify project configuration, this pragma excludes the file from GCC warnings. */
#ifdef __GNUC__
# pragma GCC system_header
#endif
 
#define DYNAMORIO_ANNOTATE_RUNNING_ON_DYNAMORIO() \
    dynamorio_annotate_running_on_dynamorio()
 
#define DYNAMORIO_ANNOTATE_LOG(format, ...) \
    DR_ANNOTATION(dynamorio_annotate_log, format, ##__VA_ARGS__)
 
#ifdef __cplusplus
extern "C" {
#endif
 
DR_DECLARE_ANNOTATION(char, dynamorio_annotate_running_on_dynamorio, (void));
 
DR_DECLARE_ANNOTATION(unsigned int, dynamorio_annotate_log, (const char *format, ...));
 
#ifdef __cplusplus
}
#endif
 
#endif
