/*---------------------------------------------------------------------------
    ipr_bucket.h - ipr_bucket component

    Defines a bucket, being a buffer of variable size as chosen at creation
    time.  Buckets can be passed in messages and freed by the recipient.
    Buckets are cached so that heavy new/destroy use is very cheap.  We
    use reference counting so that buckets can be freely passed between
    objects.
    Generated from ipr_bucket.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_IPR_BUCKET_SAFE
#   define INCLUDE_IPR_BUCKET_SAFE
#   define INCLUDE_IPR_BUCKET_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_IPR_BUCKET_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _ipr_bucket_t ipr_bucket_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_BUCKET)
#    define IPR_BUCKET_HISTORY_LENGTH 32
#endif

#define IPR_BUCKET_ALIVE                0xFABB
#define IPR_BUCKET_DEAD                 0xDEAD

#define IPR_BUCKET_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL ipr_bucket\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != IPR_BUCKET_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "ipr_bucket at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, IPR_BUCKET_ALIVE, self->object_tag);\
        ipr_bucket_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
extern volatile void *
    ipr_bucket_total_used;
#   ifdef __cplusplus
}
#   endif

#   include "ipr_mother.h"
#   include "ipr_bucket_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_BUCKET_ACTIVE
#   if defined (ICL_IMPORT_IPR_BUCKET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_IPR_BUCKET_UNSAFE
#   define INCLUDE_IPR_BUCKET_UNSAFE
#   define INCLUDE_IPR_BUCKET_ACTIVE

#   include "ipr_mother.h"
#   include "ipr_bucket_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    ipr_bucket_animating;
#include "base_apr.h"

#define IPR_BUCKET_MAX_SIZE  2097152

//  Structure of the ipr_bucket object

struct _ipr_bucket_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_BUCKET)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [IPR_BUCKET_HISTORY_LENGTH];
    int
        history_line  [IPR_BUCKET_HISTORY_LENGTH];
    char
        *history_type [IPR_BUCKET_HISTORY_LENGTH];
    int
        history_links [IPR_BUCKET_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
ipr_mother_t
    *mother;
size_t
    cur_size;
size_t
    max_size;
byte
    *data;
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define ipr_bucket_new(size)            ipr_bucket_new_ (__FILE__, __LINE__, size)
ipr_bucket_t *
    ipr_bucket_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
size_t size                             //  Required length of data
);

void
    ipr_bucket_cache_purge (
void);

int
    ipr_bucket_empty (
ipr_bucket_t * self                     //  Reference to object
);

int
    ipr_bucket_fill (
ipr_bucket_t * self,                    //  Reference to object
void * data,                            //  Address of data to copy from
size_t size                             //  Amount of data to copy
);

int
    ipr_bucket_fill_null (
ipr_bucket_t * self,                    //  Reference to object
size_t size                             //  Amount of data to copy
);

int
    ipr_bucket_fill_random (
ipr_bucket_t * self,                    //  Reference to object
size_t fill_size                        //  Amount of random data to insert
);

int
    ipr_bucket_fill_repeat (
ipr_bucket_t * self,                    //  Reference to object
byte * data,                            //  Address of data to copy from
size_t size,                            //  Size of source data
size_t fill_size                        //  Amount of data to fill
);

int
    ipr_bucket_cat (
ipr_bucket_t * self,                    //  Reference to object
void * source,                          //  Address of data to copy from
size_t size                             //  Amount of data to copy
);

int
    ipr_bucket_load (
ipr_bucket_t * self,                    //  Reference to object
FILE * file                             //  Open file to read from
);

int
    ipr_bucket_save (
ipr_bucket_t * self,                    //  Reference to object
FILE * file                             //  Open file to write to
);

byte *
    ipr_bucket_find (
ipr_bucket_t * self,                    //  Reference to bucket
size_t offset,                          //  Start searching at this offset
byte * pattern,                         //  Pattern to look for
size_t patsize                          //  Size of pattern, in octets
);

int
    ipr_bucket_dump (
ipr_bucket_t * self,                    //  Reference to object
char * prefix                           //  Prefix for each line
);

static inline void
    ipr_bucket_increment_used (
size_t size                             //  The amount by which to increment the total
);

static inline void
    ipr_bucket_decrement_used (
size_t size                             //  The amount by which to decrement the total
);

size_t
    ipr_bucket_used (
void);

void
    ipr_bucket_selftest (
void);

#define ipr_bucket_show(item,opcode,trace_file)  ipr_bucket_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    ipr_bucket_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_bucket_destroy(self)        ipr_bucket_destroy_ (self, __FILE__, __LINE__)
void
    ipr_bucket_destroy_ (
ipr_bucket_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

#define ipr_bucket_link(self)           ipr_bucket_link_ (self, __FILE__, __LINE__)
ipr_bucket_t *
    ipr_bucket_link_ (
ipr_bucket_t * self,                    //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_bucket_unlink(self)         ipr_bucket_unlink_ (self, __FILE__, __LINE__)
void
    ipr_bucket_unlink_ (
ipr_bucket_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    ipr_bucket_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define ipr_bucket_new_in_scope(self_p,_scope,size)  ipr_bucket_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, size)
void
    ipr_bucket_new_in_scope_ (
ipr_bucket_t * * self_p,                //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
size_t size                             //  Required length of data
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_BUCKET_ACTIVE
#   if defined (ICL_IMPORT_IPR_BUCKET_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_IPR_BUCKET_INLINE)
#   define INCLUDE_IPR_BUCKET_INLINE
#   define INCLUDE_IPR_BUCKET_ACTIVE

#   include "ipr_mother.h"
#   include "ipr_bucket_list.h"
#   include "icl_mem.h"

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BUCKET)  ||  defined (BASE_STATS_IPR_BUCKET_INCREMENT_USED))
extern icl_stats_t *s_ipr_bucket_increment_used_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BUCKET)  ||  defined (BASE_STATS_IPR_BUCKET_DECREMENT_USED))
extern icl_stats_t *s_ipr_bucket_decrement_used_stats;
#endif
#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BUCKET)   || defined (BASE_TRACE_IPR_BUCKET_NEW)   || defined (BASE_TRACE_IPR_BUCKET_DESTROY)   || defined (BASE_TRACE_IPR_BUCKET_ALLOC)   || defined (BASE_TRACE_IPR_BUCKET_FREE)   || defined (BASE_TRACE_IPR_BUCKET_CACHE_PURGE)   || defined (BASE_TRACE_IPR_BUCKET_EMPTY)   || defined (BASE_TRACE_IPR_BUCKET_FILL)   || defined (BASE_TRACE_IPR_BUCKET_FILL_NULL)   || defined (BASE_TRACE_IPR_BUCKET_FILL_RANDOM)   || defined (BASE_TRACE_IPR_BUCKET_FILL_REPEAT)   || defined (BASE_TRACE_IPR_BUCKET_CAT)   || defined (BASE_TRACE_IPR_BUCKET_LOAD)   || defined (BASE_TRACE_IPR_BUCKET_SAVE)   || defined (BASE_TRACE_IPR_BUCKET_FIND)   || defined (BASE_TRACE_IPR_BUCKET_DUMP)   || defined (BASE_TRACE_IPR_BUCKET_INITIALISE)   || defined (BASE_TRACE_IPR_BUCKET_TERMINATE)   || defined (BASE_TRACE_IPR_BUCKET_INCREMENT_USED)   || defined (BASE_TRACE_IPR_BUCKET_DECREMENT_USED)   || defined (BASE_TRACE_IPR_BUCKET_USED)   || defined (BASE_TRACE_IPR_BUCKET_SELFTEST)   || defined (BASE_TRACE_IPR_BUCKET_SHOW)   || defined (BASE_TRACE_IPR_BUCKET_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_BUCKET_LINK)   || defined (BASE_TRACE_IPR_BUCKET_UNLINK)   || defined (BASE_TRACE_IPR_BUCKET_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_BUCKET_NEW_IN_SCOPE) )
void
    ipr_bucket_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

/*  -------------------------------------------------------------------------
    ipr_bucket_increment_used

    Type: Component method
    Increment the record of the total memory allocations.
    
    This is non-trivial because it must be thread-safe, and it must work on
    64 bit architectures.
    -------------------------------------------------------------------------
 */

static inline void
    ipr_bucket_increment_used (
    size_t size                         //  The amount by which to increment the total
)
{
void
    *old_used;

#if (defined (BASE_ANIMATE_IPR_BUCKET)  ||  defined (BASE_ANIMATE_IPR_BUCKET_INCREMENT_USED))
    if (ipr_bucket_animating)
        icl_console_print ("<ipr_bucket_increment_used_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

#if (defined (BASE_TRACE_IPR_BUCKET)   || defined (BASE_TRACE_IPR_BUCKET_INCREMENT_USED))
    icl_trace_record (NULL, ipr_bucket_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BUCKET)  ||  defined (BASE_STATS_IPR_BUCKET_INCREMENT_USED))
    icl_stats_inc ("ipr_bucket_increment_used", &s_ipr_bucket_increment_used_stats);
#endif

do
    old_used = (void *) ipr_bucket_total_used;
while (icl_atomic_casptr (&ipr_bucket_total_used, (byte *) old_used + size, old_used) != old_used);
#if (defined (BASE_TRACE_IPR_BUCKET)   || defined (BASE_TRACE_IPR_BUCKET_INCREMENT_USED))
    icl_trace_record (NULL, ipr_bucket_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE_IPR_BUCKET)   || defined (BASE_ANIMATE_IPR_BUCKET_INCREMENT_USED))
    if (ipr_bucket_animating)
        icl_console_print ("<ipr_bucket_increment_used_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_bucket_decrement_used

    Type: Component method
    Decrement the record of the total memory allocations.
    
    This is non-trivial because it must be thread-safe, and it must work on
    64 bit architectures.
    -------------------------------------------------------------------------
 */

static inline void
    ipr_bucket_decrement_used (
    size_t size                         //  The amount by which to decrement the total
)
{
void
    *old_used;

#if (defined (BASE_ANIMATE_IPR_BUCKET)  ||  defined (BASE_ANIMATE_IPR_BUCKET_DECREMENT_USED))
    if (ipr_bucket_animating)
        icl_console_print ("<ipr_bucket_decrement_used_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

#if (defined (BASE_TRACE_IPR_BUCKET)   || defined (BASE_TRACE_IPR_BUCKET_DECREMENT_USED))
    icl_trace_record (NULL, ipr_bucket_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BUCKET)  ||  defined (BASE_STATS_IPR_BUCKET_DECREMENT_USED))
    icl_stats_inc ("ipr_bucket_decrement_used", &s_ipr_bucket_decrement_used_stats);
#endif

do
    old_used = (void *) ipr_bucket_total_used;
while (icl_atomic_casptr (&ipr_bucket_total_used, (byte *) old_used - size, old_used) != old_used);
#if (defined (BASE_TRACE_IPR_BUCKET)   || defined (BASE_TRACE_IPR_BUCKET_DECREMENT_USED))
    icl_trace_record (NULL, ipr_bucket_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE_IPR_BUCKET)   || defined (BASE_ANIMATE_IPR_BUCKET_DECREMENT_USED))
    if (ipr_bucket_animating)
        icl_console_print ("<ipr_bucket_decrement_used_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_IPR_BUCKET_ACTIVE
#   if defined (ICL_IMPORT_IPR_BUCKET_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_IPR_BUCKET_ROOT
#   endif
# endif
#endif
