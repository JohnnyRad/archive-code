/*---------------------------------------------------------------------------
    icl_rwlock.h - icl_rwlock component

    Defines wrappers to managed read-write lock objects.
    Generated from icl_rwlock.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ICL_RWLOCK_SAFE
#   define INCLUDE_ICL_RWLOCK_SAFE
#   define INCLUDE_ICL_RWLOCK_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_RWLOCK_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _icl_rwlock_t icl_rwlock_t;

#define ICL_RWLOCK_ALIVE                0xFABB
#define ICL_RWLOCK_DEAD                 0xDEAD

#define ICL_RWLOCK_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL icl_rwlock\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != ICL_RWLOCK_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "icl_rwlock at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, ICL_RWLOCK_ALIVE, self->object_tag);\
        icl_rwlock_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_ICL_RWLOCK_ACTIVE
#   if defined (ICL_IMPORT_ICL_RWLOCK_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_RWLOCK_UNSAFE
#   define INCLUDE_ICL_RWLOCK_UNSAFE
#   define INCLUDE_ICL_RWLOCK_ACTIVE

#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_rwlock_animating;

//  Structure of the icl_rwlock object

struct _icl_rwlock_t {
dbyte
    object_tag;                     //  Object validity marker
#if (defined (BASE_THREADSAFE))
    apr_thread_rwlock_t
        *rwlock;
    apr_pool_t
        *pool;
#else
    qbyte
        filler;
#endif
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
static inline void
    icl_rwlock_read_lock (
icl_rwlock_t * self                     //  Not documented
);

static inline void
    icl_rwlock_write_lock (
icl_rwlock_t * self                     //  Not documented
);

static inline void
    icl_rwlock_unlock (
icl_rwlock_t * self                     //  Not documented
);

void
    icl_rwlock_selftest (
void);

void
    icl_rwlock_terminate (
void);

#define icl_rwlock_new()                icl_rwlock_new_ (__FILE__, __LINE__)
icl_rwlock_t *
    icl_rwlock_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_rwlock_show(item,opcode,trace_file)  icl_rwlock_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    icl_rwlock_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define icl_rwlock_destroy(self)        icl_rwlock_destroy_ (self, __FILE__, __LINE__)
void
    icl_rwlock_destroy_ (
icl_rwlock_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    icl_rwlock_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define icl_rwlock_new_in_scope(self_p,_scope)  icl_rwlock_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    icl_rwlock_new_in_scope_ (
icl_rwlock_t * * self_p,                //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_RWLOCK_ACTIVE
#   if defined (ICL_IMPORT_ICL_RWLOCK_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_RWLOCK_INLINE)
#   define INCLUDE_ICL_RWLOCK_INLINE
#   define INCLUDE_ICL_RWLOCK_ACTIVE

#   include "icl_mem.h"

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_READ_LOCK))
extern icl_stats_t *s_icl_rwlock_read_lock_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_WRITE_LOCK))
extern icl_stats_t *s_icl_rwlock_write_lock_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_UNLOCK))
extern icl_stats_t *s_icl_rwlock_unlock_stats;
#endif
#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_ALLOC)   || defined (BASE_TRACE_ICL_RWLOCK_FREE)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_RWLOCK_READ_LOCK)   || defined (BASE_TRACE_ICL_RWLOCK_WRITE_LOCK)   || defined (BASE_TRACE_ICL_RWLOCK_UNLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SELFTEST)   || defined (BASE_TRACE_ICL_RWLOCK_TERMINATE)   || defined (BASE_TRACE_ICL_RWLOCK_NEW)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_PURGE)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW_ANIMATION)   || defined (BASE_TRACE_ICL_RWLOCK_NEW_IN_SCOPE) )
void
    icl_rwlock_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

/*  -------------------------------------------------------------------------
    icl_rwlock_read_lock

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_rwlock_read_lock (
    icl_rwlock_t * self                 //  Not documented
)
{

#if (defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_READ_LOCK))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_read_lock_start"
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

#if (defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_READ_LOCK))
    icl_trace_record (NULL, icl_rwlock_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_READ_LOCK))
    icl_stats_inc ("icl_rwlock_read_lock", &s_icl_rwlock_read_lock_stats);
#endif

#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_thread_rwlock_rdlock (self->rwlock));
#endif
#if (defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_READ_LOCK))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_READ_LOCK))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_read_lock_finish"
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

}
/*  -------------------------------------------------------------------------
    icl_rwlock_write_lock

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_rwlock_write_lock (
    icl_rwlock_t * self                 //  Not documented
)
{

#if (defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_WRITE_LOCK))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_write_lock_start"
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

#if (defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_WRITE_LOCK))
    icl_trace_record (NULL, icl_rwlock_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_WRITE_LOCK))
    icl_stats_inc ("icl_rwlock_write_lock", &s_icl_rwlock_write_lock_stats);
#endif

#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_thread_rwlock_wrlock (self->rwlock));
#endif
#if (defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_WRITE_LOCK))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_WRITE_LOCK))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_write_lock_finish"
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

}
/*  -------------------------------------------------------------------------
    icl_rwlock_unlock

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_rwlock_unlock (
    icl_rwlock_t * self                 //  Not documented
)
{

#if (defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_UNLOCK))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_unlock_start"
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

#if (defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_UNLOCK))
    icl_trace_record (NULL, icl_rwlock_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_UNLOCK))
    icl_stats_inc ("icl_rwlock_unlock", &s_icl_rwlock_unlock_stats);
#endif

#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_thread_rwlock_unlock (self->rwlock));
#endif
#if (defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_UNLOCK))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_UNLOCK))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_unlock_finish"
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

}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_RWLOCK_ACTIVE
#   if defined (ICL_IMPORT_ICL_RWLOCK_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_RWLOCK_ROOT
#   endif
# endif
#endif
