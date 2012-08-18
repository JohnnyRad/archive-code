/*---------------------------------------------------------------------------
    ipr_mother.h - ipr_mother component

    [Todo]
    Generated from ipr_mother.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_IPR_MOTHER_SAFE
#   define INCLUDE_IPR_MOTHER_SAFE
#   define INCLUDE_IPR_MOTHER_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_MOTHER_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _ipr_mother_t ipr_mother_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
#    define IPR_MOTHER_HISTORY_LENGTH 32
#endif

#define IPR_MOTHER_ALIVE                0xFABB
#define IPR_MOTHER_DEAD                 0xDEAD

#define IPR_MOTHER_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL ipr_mother\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != IPR_MOTHER_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "ipr_mother at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, IPR_MOTHER_ALIVE, self->object_tag);\
        ipr_mother_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "ipr_bucket.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_MOTHER_ACTIVE
#   if defined (ICL_IMPORT_IPR_MOTHER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_MOTHER_UNSAFE
#   define INCLUDE_IPR_MOTHER_UNSAFE
#   define INCLUDE_IPR_MOTHER_ACTIVE

#   include "ipr_bucket.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_mother_animating;
#define IPR_MOTHER_BUCKET_SIZE 65536

//  Structure of the ipr_mother object

struct _ipr_mother_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [IPR_MOTHER_HISTORY_LENGTH];
    int
        history_line  [IPR_MOTHER_HISTORY_LENGTH];
    char
        *history_type [IPR_MOTHER_HISTORY_LENGTH];
    int
        history_links [IPR_MOTHER_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    apr_os_thread_t     apr_os_thread;  //  So we can assert no contention
#endif
    uint                slave_count;    //  Number of slave buckets
    size_t              allocated,      //  Total master data allocated
                        filled,         //  Total master data filled
                        claimed;        //  Total master date claimed
    Bool                closed;
    byte                data[IPR_MOTHER_BUCKET_SIZE];
                                        //  The actual data
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define ipr_mother_new()                ipr_mother_new_ (__FILE__, __LINE__)
ipr_mother_t *
    ipr_mother_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

byte *
    ipr_mother_allocate (
ipr_mother_t * ( * self_p ),            //  The mother to extend
size_t size                             //  Required length of data
);

static inline size_t
    ipr_mother_unfilled (
ipr_mother_t * self                     //  The mother object
);

static inline size_t
    ipr_mother_overhang (
ipr_mother_t * self                     //  The mother object
);

#define ipr_mother_claim(self,size)     ipr_mother_claim_ (self, size, __FILE__, __LINE__)
ipr_bucket_t *
    ipr_mother_claim_ (
ipr_mother_t * self,                    //  The mother from which to obtain data
size_t size,                            //  Required length of obtained data
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    ipr_mother_fill (
ipr_mother_t * self,                    //  Reference to objectThe mother from which to consume data
size_t size                             //  Required length of consumed data
);

void
    ipr_mother_remove (
ipr_bucket_t * slave                    //  Slave bucket being destroyed
);

void
    ipr_mother_selftest (
void);

void
    ipr_mother_terminate (
void);

#define ipr_mother_show(item,opcode,trace_file)  ipr_mother_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    ipr_mother_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_mother_destroy(self)        ipr_mother_destroy_ (self, __FILE__, __LINE__)
void
    ipr_mother_destroy_ (
ipr_mother_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define ipr_mother_link(self)           ipr_mother_link_ (self, __FILE__, __LINE__)
ipr_mother_t *
    ipr_mother_link_ (
ipr_mother_t * self,                    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_mother_unlink(self)         ipr_mother_unlink_ (self, __FILE__, __LINE__)
void
    ipr_mother_unlink_ (
ipr_mother_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    ipr_mother_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define ipr_mother_new_in_scope(self_p,_scope)  ipr_mother_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    ipr_mother_new_in_scope_ (
ipr_mother_t * * self_p,                //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_MOTHER_ACTIVE
#   if defined (ICL_IMPORT_IPR_MOTHER_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_MOTHER_INLINE)
#   define INCLUDE_IPR_MOTHER_INLINE
#   define INCLUDE_IPR_MOTHER_ACTIVE

#   include "ipr_bucket.h"
#   include "icl_mem.h"

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_UNFILLED))
extern icl_stats_t *s_ipr_mother_unfilled_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_OVERHANG))
extern icl_stats_t *s_ipr_mother_overhang_stats;
#endif
#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_NEW)   || defined (BASE_TRACE_IPR_MOTHER_ALLOCATE)   || defined (BASE_TRACE_IPR_MOTHER_UNFILLED)   || defined (BASE_TRACE_IPR_MOTHER_OVERHANG)   || defined (BASE_TRACE_IPR_MOTHER_CLAIM)   || defined (BASE_TRACE_IPR_MOTHER_FILL)   || defined (BASE_TRACE_IPR_MOTHER_REMOVE)   || defined (BASE_TRACE_IPR_MOTHER_SELFTEST)   || defined (BASE_TRACE_IPR_MOTHER_TERMINATE)   || defined (BASE_TRACE_IPR_MOTHER_SHOW)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY)   || defined (BASE_TRACE_IPR_MOTHER_ALLOC)   || defined (BASE_TRACE_IPR_MOTHER_FREE)   || defined (BASE_TRACE_IPR_MOTHER_LINK)   || defined (BASE_TRACE_IPR_MOTHER_UNLINK)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_PURGE)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_MOTHER_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_MOTHER_NEW_IN_SCOPE) )
void
    ipr_mother_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

/*  -------------------------------------------------------------------------
    ipr_mother_unfilled

    Type: Component method
    Returns the remaining allocated master data size.
    -------------------------------------------------------------------------
 */

static inline size_t
    ipr_mother_unfilled (
    ipr_mother_t * self                 //  The mother object
)
{
    size_t
        remaining;                      //  The remaining data size

#if (defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_UNFILLED))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_unfilled_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_UNFILLED))
    icl_trace_record (NULL, ipr_mother_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_UNFILLED))
    icl_stats_inc ("ipr_mother_unfilled", &s_ipr_mother_unfilled_stats);
#endif

if (self->closed)
    remaining = self->allocated - self->filled;
else
    remaining = IPR_MOTHER_BUCKET_SIZE - self->filled;
#if (defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_UNFILLED))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_UNFILLED))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_unfilled_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" remaining=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, remaining);
#endif


    return (remaining);
}
/*  -------------------------------------------------------------------------
    ipr_mother_overhang

    Type: Component method
    Returns the number of overhanging bytes, ie the number of bytes in the
    master bucket that haven't been claimed by a slave bucket.
    -------------------------------------------------------------------------
 */

static inline size_t
    ipr_mother_overhang (
    ipr_mother_t * self                 //  The mother object
)
{
    size_t
        overhang;                       //  The overhanging data size

#if (defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_OVERHANG))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_overhang_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self);
#endif

#if (defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_OVERHANG))
    icl_trace_record (NULL, ipr_mother_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_OVERHANG))
    icl_stats_inc ("ipr_mother_overhang", &s_ipr_mother_overhang_stats);
#endif

overhang = self->filled - self->claimed;
#if (defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_OVERHANG))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_OVERHANG))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_overhang_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" overhang=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, overhang);
#endif


    return (overhang);
}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_MOTHER_ACTIVE
#   if defined (ICL_IMPORT_IPR_MOTHER_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_MOTHER_ROOT
#   endif
# endif
#endif
