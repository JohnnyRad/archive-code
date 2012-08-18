/*---------------------------------------------------------------------------
    icl_mem_thin.h - icl_mem_thin component

    A lightwieght memory allocator using a lock-free singly-linked stack.
    Generated from icl_mem_thin.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_ICL_MEM_THIN_SAFE
#   define INCLUDE_ICL_MEM_THIN_SAFE
#   define INCLUDE_ICL_MEM_THIN_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_MEM_THIN_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _icl_mem_thin_t icl_mem_thin_t;
#   ifdef __cplusplus
}
#   endif

#   include "icl_cache.h"
#   include "icl_mem_thin_list.h"
#   include "icl_system.h"
#   include "icl_stats.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_MEM_THIN_ACTIVE
#   if defined (ICL_IMPORT_ICL_MEM_THIN_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_MEM_THIN_UNSAFE
#   define INCLUDE_ICL_MEM_THIN_UNSAFE
#   define INCLUDE_ICL_MEM_THIN_ACTIVE

#   include "icl_cache.h"
#   include "icl_system.h"
#   include "icl_stats.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_mem_thin_animating;
//  Macros                                                                     

#define ICL_MEM_THIN_SIZE (((sizeof (icl_mem_thin_t) + 7) / 8) * 8)

#define ICL_MEM_THIN_ASSERT_SANE(self, item)\
{\
    if (self->tag != ICL_CACHE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Allocated item at %p expected tag=0x%x, actual tag=0x%x\n", item, ICL_CACHE_ALIVE, self->tag);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}

//  Global variables

extern Bool
    s_icl_mem_thin_active;

//  Structure of the icl_mem_thin object

struct _icl_mem_thin_t {
qbyte
    tag;                            //  To detect corruption               
icl_cache_t
    *cache;                         //  The cache for this object          
qbyte
    size;                           //  The size of this object
volatile icl_mem_thin_list_t *list_head;
volatile icl_mem_thin_t *list_prev;
volatile icl_mem_thin_t *list_next;
};

#   ifdef __cplusplus
}
#   endif
#   include "icl_mem_thin_list.h"
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define icl_mem_thin_cache_alloc(cache)  icl_mem_thin_cache_alloc_ (cache, __FILE__, __LINE__)
static inline void *
    icl_mem_thin_cache_alloc_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_mem_thin_alloc(size)        icl_mem_thin_alloc_ (size, __FILE__, __LINE__)
static inline void *
    icl_mem_thin_alloc_ (
size_t size,                            //  How much memory to allocate
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_mem_thin_realloc(item,size)  icl_mem_thin_realloc_ (item, size, __FILE__, __LINE__)
static inline void *
    icl_mem_thin_realloc_ (
void * item,                            //  Cient buffer to reallocate
qbyte size,                             //  How much memory to allocate
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static inline void
    icl_mem_thin_free (
void * item                             //  Client buffer to free
);

static inline void
    icl_mem_thin_cache_insert (
icl_cache_t * cache,                    //  The cache for the allocation
icl_mem_thin_t * self                   //  The allocation block
);

#define icl_mem_thin_cache_reuse(cache)  icl_mem_thin_cache_reuse_ (cache, __FILE__, __LINE__)
static inline void *
    icl_mem_thin_cache_reuse_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static inline void
    icl_mem_thin_cache_recycle (
icl_mem_thin_t * ( * self_p )           //  The allocation block
);

void
    icl_mem_thin_cache_purge (
icl_cache_t * cache                     //  The cache to purge
);

static inline void
    icl_mem_thin_cache_reset (
icl_mem_thin_t * self                   //  The allocation block
);

int
    icl_mem_thin_cache_assert (
icl_cache_t * cache,                    //  The cache for the allocation
FILE ** trace_file                      //  File to print to, opened on error
);

void
    icl_mem_thin_show (
void);

#define icl_mem_thin_possess(item)      icl_mem_thin_possess_ (item, __FILE__, __LINE__)
static inline void
    icl_mem_thin_possess_ (
void * item,                            //  Client buffer to free
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static inline void
    icl_mem_thin_set_callback (
void * item,                            //  Client buffer to free
icl_callback_fn * callback              //  Callback function to set
);

void
    icl_mem_thin_selftest (
void);

icl_mem_thin_t *
    icl_mem_thin_new (
size_t size                             //  How much memory to allocate
);

void
    icl_mem_thin_remove_from_all_containers (
icl_mem_thin_t * self                   //  The item
);

#define icl_mem_thin_cache_pop(cache)   icl_mem_thin_cache_pop_ (cache, __FILE__, __LINE__)
void *
    icl_mem_thin_cache_pop_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_mem_thin_cache_new(cache)   icl_mem_thin_cache_new_ (cache, __FILE__, __LINE__)
void *
    icl_mem_thin_cache_new_ (
icl_cache_t * cache,                    //  The cache for the allocation
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    icl_mem_thin_destroy (
icl_mem_thin_t * ( * self_p )           //  The allocation block
);

void
    icl_mem_thin_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_MEM_THIN_ACTIVE
#   if defined (ICL_IMPORT_ICL_MEM_THIN_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_MEM_THIN_INLINE)
#   define INCLUDE_ICL_MEM_THIN_INLINE
#   define INCLUDE_ICL_MEM_THIN_ACTIVE

#   include "icl_cache.h"
#   include "icl_mem_thin_list.h"
#   include "icl_system.h"
#   include "icl_stats.h"

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_ALLOC))
extern icl_stats_t *s_icl_mem_thin_cache_alloc_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_ALLOC))
extern icl_stats_t *s_icl_mem_thin_alloc_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_REALLOC))
extern icl_stats_t *s_icl_mem_thin_realloc_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_FREE))
extern icl_stats_t *s_icl_mem_thin_free_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_INSERT))
extern icl_stats_t *s_icl_mem_thin_cache_insert_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_REUSE))
extern icl_stats_t *s_icl_mem_thin_cache_reuse_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_RECYCLE))
extern icl_stats_t *s_icl_mem_thin_cache_recycle_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_RESET))
extern icl_stats_t *s_icl_mem_thin_cache_reset_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_POSSESS))
extern icl_stats_t *s_icl_mem_thin_possess_stats;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_SET_CALLBACK))
extern icl_stats_t *s_icl_mem_thin_set_callback_stats;
#endif
#   ifdef __cplusplus
extern "C" {
#   endif

/*  -------------------------------------------------------------------------
    icl_mem_thin_cache_alloc

    Type: Component method
    Reuses or allocates a block in a cache.  The size of the block is the size 
    of the cache.
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_thin_cache_alloc_ (
    icl_cache_t * cache,                //  The cache for the allocation
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    void *
        item = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_ALLOC))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_ALLOC))
    icl_stats_inc ("icl_mem_thin_cache_alloc", &s_icl_mem_thin_cache_alloc_stats);
#endif

item = icl_mem_thin_cache_pop_ (cache, file, line);
if (!item)
    item = icl_mem_thin_cache_new_ (cache, file, line);
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_ALLOC))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_thin_alloc

    Type: Component method
    Allocate a block of a given size in the direct cache.  This isn't really
    a cache at all and just serves to track allocated blocks.
    cache.
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_thin_alloc_ (
    size_t size,                        //  How much memory to allocate
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_mem_thin_t
    *self;
    void *
        item = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_ALLOC))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_ALLOC))
    icl_stats_inc ("icl_mem_thin_alloc", &s_icl_mem_thin_alloc_stats);
#endif

    if (!s_direct_cache)
        icl_cache_initialise ();

    self = icl_mem_thin_new (size);
    if (self) {
        self->cache = s_direct_cache;
        self->size  = size;
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_THIN))
        icl_stats_inc (NULL, &s_direct_cache->allocs_stat);
#endif
        self->tag = ICL_CACHE_ALIVE;
        icl_mem_thin_cache_insert (s_direct_cache, self);
        item = (byte *) self + ICL_MEM_THIN_SIZE;
        icl_mem_thin_possess_ (item, file, line);
    }
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_ALLOC))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_thin_realloc

    Type: Component method
    Adjust the size of the pointed to 'buffer' to the new 'size'.
    If 'buffer' is NULL, self call behaves as a regular alloc().
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_thin_realloc_ (
    void * item,                        //  Cient buffer to reallocate
    qbyte size,                         //  How much memory to allocate
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_mem_thin_t
    *self;

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_REALLOC))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_realloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" size=\"%lu\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, size, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_REALLOC))
    icl_stats_inc ("icl_mem_thin_realloc", &s_icl_mem_thin_realloc_stats);
#endif

if (item == NULL)
    item = icl_mem_thin_alloc_ (size, file, line);
else {
    self = (icl_mem_thin_t *) (((byte *) item) - ICL_MEM_THIN_SIZE);
    ICL_MEM_THIN_ASSERT_SANE (self, item);

    item = NULL;
    if (!self->cache->size) {       //  ie direct cache
        icl_mem_thin_cache_recycle (&self);
        self = (icl_mem_thin_t*) realloc (self, ICL_MEM_THIN_SIZE + size);
        if (self) {
            //  Need to reset the cache pointer(s) following realloc.
            icl_mem_thin_cache_reset (self);

            self->size  = size;
            self->tag = ICL_CACHE_ALIVE;
            icl_mem_thin_cache_insert (s_direct_cache, self);

            item = (byte *) self + ICL_MEM_THIN_SIZE;
        }
    }
}
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_REALLOC))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_realloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" size=\"%lu\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, size, file, line);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_mem_thin_free

    Type: Component method
    Destroys an allocation block.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_thin_free (
    void * item                         //  Client buffer to free
)
{
icl_mem_thin_t
    *self;

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_FREE))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_FREE))
    icl_stats_inc ("icl_mem_thin_free", &s_icl_mem_thin_free_stats);
#endif

    if (item) {
        self = (icl_mem_thin_t *) (((byte *) item) - ICL_MEM_THIN_SIZE);
        ICL_MEM_THIN_ASSERT_SANE (self, item);
        self->tag = ICL_CACHE_DEAD;

        icl_mem_thin_cache_recycle (&self);
        if (!self->cache->size) {       //  ie direct cache
            icl_mem_thin_destroy (&self);
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_THIN))
            icl_stats_inc (NULL, &s_direct_cache->frees_stat);
#endif
        }
    }
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_FREE))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_thin_cache_insert

    Type: Component method
    This is a private method used by icl_mem_thin_cache_alloc.
    
    Its purpose is to record an allocator block in use.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_thin_cache_insert (
    icl_cache_t * cache,                //  The cache for the allocation
    icl_mem_thin_t * self               //  The allocation block
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_INSERT))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_insert_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, self);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_INSERT))
    icl_stats_inc ("icl_mem_thin_cache_insert", &s_icl_mem_thin_cache_insert_stats);
#endif

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_THIN))
    icl_stats_inc (NULL, &cache->used_stat);
#endif

    icl_atomic_inc32 (&cache->thin_used_count);
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_INSERT))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_insert_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, self);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_thin_cache_reuse

    Type: Component method
    This is a private method used by icl_mem_thin_cache_alloc.
    
    Its purpose is to find an allocator block from the cache for reuse.
    -------------------------------------------------------------------------
 */

static inline void *
    icl_mem_thin_cache_reuse_ (
    icl_cache_t * cache,                //  The cache for the allocation
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    void *
        self = NULL;                    //  The returned client pointer

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_REUSE))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_reuse_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_REUSE))
    icl_stats_inc ("icl_mem_thin_cache_reuse", &s_icl_mem_thin_cache_reuse_stats);
#endif

self = icl_mem_thin_list_pop (cache->thin_unused_list);
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_THIN))
    if (self)
        icl_stats_dec (NULL, &cache->unused_stat);
#endif
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_REUSE))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_reuse_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" cache=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, cache, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_mem_thin_cache_recycle

    Type: Component method
    This is a private method used by icl_mem_thin_cache_alloc.
    
    Its purpose is put an allocated block in the unused list of the cache.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_thin_cache_recycle (
    icl_mem_thin_t * ( * self_p )       //  The allocation block
)
{
    icl_mem_thin_t *
        self = *self_p;                 //  Dereferenced The allocation block
    icl_cache_t *
        cache = self->cache;            //  The cache for the allocation

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_RECYCLE))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_recycle_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_RECYCLE))
    icl_stats_inc ("icl_mem_thin_cache_recycle", &s_icl_mem_thin_cache_recycle_stats);
#endif

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_THIN))
    icl_stats_dec (NULL, &cache->used_stat);
#endif
icl_atomic_dec32 (&cache->thin_used_count);
if (cache->size)                    //  ie not direct cache
    icl_mem_thin_list_queue (cache->thin_unused_list, self);
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_MEM_THIN))
    if (cache->size)                    //  ie not direct cache
        icl_stats_inc (NULL, &cache->unused_stat);
#endif
#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_RECYCLE))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_recycle_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" cache=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, cache);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_thin_cache_reset

    Type: Component method
    This is a private method used by icl_mem_thin_cache_realloc.
    
    Its purpose is to reset the block's cache pointers following a realloc.
    Don't need to do anything.
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_thin_cache_reset (
    icl_mem_thin_t * self               //  The allocation block
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_RESET))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_reset_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_CACHE_RESET))
    icl_stats_inc ("icl_mem_thin_cache_reset", &s_icl_mem_thin_cache_reset_stats);
#endif

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_CACHE_RESET))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_cache_reset_finish"
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
    icl_mem_thin_possess

    Type: Component method
    Sets file and line number of memory allocation.
    Does nothing but required to get function declared
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_thin_possess_ (
    void * item,                        //  Client buffer to free
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_POSSESS))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_possess_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_POSSESS))
    icl_stats_inc ("icl_mem_thin_possess", &s_icl_mem_thin_possess_stats);
#endif

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_POSSESS))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_possess_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    icl_mem_thin_set_callback

    Type: Component method
    Sets callback of memory allocation.
    Does nothing but required to get function declared
    -------------------------------------------------------------------------
 */

static inline void
    icl_mem_thin_set_callback (
    void * item,                        //  Client buffer to free
    icl_callback_fn * callback          //  Callback function to set
)
{

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)  ||  defined (BASE_ANIMATE_ICL_MEM_THIN_SET_CALLBACK))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_set_callback_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" callback=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, callback);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_MEM_THIN)  ||  defined (BASE_STATS_ICL_MEM_THIN_SET_CALLBACK))
    icl_stats_inc ("icl_mem_thin_set_callback", &s_icl_mem_thin_set_callback_stats);
#endif

#if (defined (BASE_ANIMATE_ICL_MEM_THIN)   || defined (BASE_ANIMATE_ICL_MEM_THIN_SET_CALLBACK))
    if (icl_mem_thin_animating)
        icl_console_print ("<icl_mem_thin_set_callback_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" callback=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, callback);
#endif

}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_MEM_THIN_ACTIVE
#   if defined (ICL_IMPORT_ICL_MEM_THIN_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_MEM_THIN_ROOT
#   endif
# endif
#endif
