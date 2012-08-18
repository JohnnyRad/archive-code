/*---------------------------------------------------------------------------
    ipr_stat.h - ipr_stat component

    The statistics module is designed to capture information (raw integers)
    and process these into useful information.  The sample size is arbitrarily
    large.  Samples are double-precision floating point.
    Generated from ipr_stat.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_IPR_STAT_SAFE
#   define INCLUDE_IPR_STAT_SAFE
#   define INCLUDE_IPR_STAT_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_STAT_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _ipr_stat_t ipr_stat_t;

#define IPR_STAT_ALIVE                  0xFABB
#define IPR_STAT_DEAD                   0xDEAD

#define IPR_STAT_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL ipr_stat\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != IPR_STAT_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "ipr_stat at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, IPR_STAT_ALIVE, self->object_tag);\
        ipr_stat_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_STAT_ACTIVE
#   if defined (ICL_IMPORT_IPR_STAT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_STAT_UNSAFE
#   define INCLUDE_IPR_STAT_UNSAFE
#   define INCLUDE_IPR_STAT_ACTIVE

#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_stat_animating;

//  Structure of the ipr_stat object

struct _ipr_stat_t {
dbyte
    object_tag;                     //  Object validity marker
double
    sum,                            //  Sum of all values
    sum2,                           //  Running deviation sum
    min,                            //  Minimum value
    max,                            //  Maximum value
    mean;                           //  Current mean
size_t      
    count;                          //  Sample size
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define ipr_stat_new()                  ipr_stat_new_ (__FILE__, __LINE__)
ipr_stat_t *
    ipr_stat_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    ipr_stat_record (
ipr_stat_t * self,                      //  Reference to object
double value                            //  Sample value
);

double
    ipr_stat_min (
ipr_stat_t * self                       //  Reference to object
);

double
    ipr_stat_max (
ipr_stat_t * self                       //  Reference to object
);

int
    ipr_stat_count (
ipr_stat_t * self                       //  Reference to object
);

double
    ipr_stat_sum (
ipr_stat_t * self                       //  Reference to object
);

double
    ipr_stat_mean (
ipr_stat_t * self                       //  Reference to object
);

double
    ipr_stat_var (
ipr_stat_t * self                       //  Reference to object
);

double
    ipr_stat_dev (
ipr_stat_t * self                       //  Reference to object
);

void
    ipr_stat_selftest (
void);

void
    ipr_stat_terminate (
void);

#define ipr_stat_show(item,opcode,trace_file)  ipr_stat_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    ipr_stat_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_stat_destroy(self)          ipr_stat_destroy_ (self, __FILE__, __LINE__)
void
    ipr_stat_destroy_ (
ipr_stat_t * ( * self_p ),              //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    ipr_stat_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define ipr_stat_new_in_scope(self_p,_scope)  ipr_stat_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    ipr_stat_new_in_scope_ (
ipr_stat_t * * self_p,                  //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_STAT_ACTIVE
#   if defined (ICL_IMPORT_IPR_STAT_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_STAT_INLINE)
#   define INCLUDE_IPR_STAT_INLINE
#   define INCLUDE_IPR_STAT_ACTIVE

#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_NEW)   || defined (BASE_TRACE_IPR_STAT_RECORD)   || defined (BASE_TRACE_IPR_STAT_MIN)   || defined (BASE_TRACE_IPR_STAT_MAX)   || defined (BASE_TRACE_IPR_STAT_COUNT)   || defined (BASE_TRACE_IPR_STAT_SUM)   || defined (BASE_TRACE_IPR_STAT_MEAN)   || defined (BASE_TRACE_IPR_STAT_VAR)   || defined (BASE_TRACE_IPR_STAT_DEV)   || defined (BASE_TRACE_IPR_STAT_SELFTEST)   || defined (BASE_TRACE_IPR_STAT_TERMINATE)   || defined (BASE_TRACE_IPR_STAT_SHOW)   || defined (BASE_TRACE_IPR_STAT_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_STAT_DESTROY)   || defined (BASE_TRACE_IPR_STAT_ALLOC)   || defined (BASE_TRACE_IPR_STAT_FREE)   || defined (BASE_TRACE_IPR_STAT_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_STAT_CACHE_PURGE)   || defined (BASE_TRACE_IPR_STAT_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_STAT_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_STAT_NEW_IN_SCOPE) )
void
    ipr_stat_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_STAT_ACTIVE
#   if defined (ICL_IMPORT_IPR_STAT_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_STAT_ROOT
#   endif
# endif
#endif
