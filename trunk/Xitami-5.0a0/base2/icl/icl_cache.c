/*---------------------------------------------------------------------------
    icl_cache.c - icl_cache component

    Generated from icl_cache.icl by icl_gen using GSL/4.
    
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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "icl_cache.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_cache_t

//  Shorthands for class methods                                               

#define self_new            icl_cache_new
#define self_annihilate     icl_cache_annihilate
#define self_create         icl_cache_create
#define self_get            icl_cache_get
#define self_assert         icl_cache_assert
#define self_initialise     icl_cache_initialise
#define self_terminate      icl_cache_terminate
#define self_selftest       icl_cache_selftest
#define self_remove_from_all_containers  icl_cache_remove_from_all_containers
#define self_destroy        icl_cache_destroy
#define self_alloc          icl_cache_alloc
#define self_free           icl_cache_free
#define self_lock           icl_cache_lock
#define self_unlock         icl_cache_unlock
#define self_show_animation  icl_cache_show_animation
#define self_new_in_scope   icl_cache_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_NEW))
static icl_stats_t *s_icl_cache_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_DESTROY))
static icl_stats_t *s_icl_cache_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_CREATE))
static icl_stats_t *s_icl_cache_create_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_GET))
static icl_stats_t *s_icl_cache_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_ASSERT))
static icl_stats_t *s_icl_cache_assert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_INITIALISE))
static icl_stats_t *s_icl_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_TERMINATE))
static icl_stats_t *s_icl_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_SELFTEST))
static icl_stats_t *s_icl_cache_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_icl_cache_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_DESTROY_PUBLIC))
static icl_stats_t *s_icl_cache_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_ALLOC))
static icl_stats_t *s_icl_cache_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_FREE))
static icl_stats_t *s_icl_cache_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_LOCK))
static icl_stats_t *s_icl_cache_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_UNLOCK))
static icl_stats_t *s_icl_cache_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_SHOW_ANIMATION))
static icl_stats_t *s_icl_cache_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_NEW_IN_SCOPE))
static icl_stats_t *s_icl_cache_new_in_scope_stats = NULL;
#endif
static void
    icl_cache_annihilate (
icl_cache_t * ( * self_p )              //  Reference to object reference
);

static void
    icl_cache_terminate (
void);

#define icl_cache_alloc()               icl_cache_alloc_ (__FILE__, __LINE__)
static icl_cache_t *
    icl_cache_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_cache_free (
icl_cache_t * self                      //  Object reference
);

static Bool
    s_icl_cache_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_icl_cache_mutex        = NULL;
#endif
Bool
    icl_cache_animating = TRUE;         //  Animation enabled by default

//  Global variables local to this source                                      

static icl_cache_list_t
    *s_cache_list = NULL;               //  The cache list

//  Global variables                                                           

icl_cache_t
    *s_direct_cache = NULL;             //  Pseudo-cache for direct alloc'ns
/*  -------------------------------------------------------------------------
    icl_cache_new

    Type: Component method
    Creates and initialises a new icl_cache_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

icl_cache_t *
    icl_cache_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_cache_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_NEW))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_NEW))
    icl_stats_inc ("icl_cache_new", &s_icl_cache_new_stats);
#endif

if (!s_icl_cache_active)
    self_initialise ();
    self = icl_cache_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_CACHE_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->mutex = icl_mutex_new ();
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
    self->fat_used_list         = icl_mem_fat_list_new ();
    self->fat_unused_list       = icl_mem_fat_list_new ();
    self->thin_unused_list      = icl_mem_thin_list_new ();
    self->thin_used_count       = 0;
    self->size                  = 0;

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
    self->used_stat   = NULL;
    self->unused_stat = NULL;
    self->allocs_stat = NULL;
    self->frees_stat  = NULL;
#endif
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_NEW))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_cache_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_cache_annihilate (
    icl_cache_t * ( * self_p )          //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    icl_cache_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_DESTROY))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_destroy_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_DESTROY))
    icl_stats_inc ("icl_cache_annihilate", &s_icl_cache_annihilate_stats);
#endif

    ICL_CACHE_ASSERT_SANE (self);
    icl_cache_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    mutex = self->mutex;
    if (mutex)
         icl_mutex_lock (mutex);
#endif

icl_mem_fat_list_destroy      (&self->fat_used_list);
icl_mem_fat_list_destroy      (&self->fat_unused_list);
icl_mem_thin_list_destroy     (&self->thin_unused_list);
#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_DESTROY))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_destroy_finish"
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

}
/*  -------------------------------------------------------------------------
    icl_cache_create

    Type: Component method
    Create a new cache with a given size.  Use for objects that don't share
    their cache, presumably because they re-use more than the memory.
    -------------------------------------------------------------------------
 */

icl_cache_t *
    icl_cache_create (
    qbyte size                          //  Not documented
)
{
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
    char
        name [] = "icl_mem_xxxxxx_yyyyyy ";
#endif
    icl_cache_t *
        self;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_CREATE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_create_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_CREATE))
    icl_stats_inc ("icl_cache_create", &s_icl_cache_create_stats);
#endif

    if (!s_icl_cache_active)
        icl_cache_initialise ();

#if (defined (BASE_THREADSAFE))
    icl_mutex_lock (s_icl_cache_mutex);
#endif

    //  Shift size up to nearest 64-byte boundary
    size = (size + 63) & 0xFFFFFFC0;

    self = icl_cache_new ();
    self->size = size;

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
    sprintf (&name [8], "%06lu ", (long) size);
    strcpy (&name [15], "used");
    self->used_stat = icl_stats_new (name);
    strcpy (&name [15], "unused");
    self->unused_stat = icl_stats_new (name);
    strcpy (&name [15], "allocs");
    self->allocs_stat = icl_stats_new (name);
    strcpy (&name [15], "frees");
    self->frees_stat = icl_stats_new (name);
#endif
    icl_cache_list_queue (s_cache_list, self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_unlock (s_icl_cache_mutex);
#endif
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_CREATE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_create_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%lu\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_cache_get

    Type: Component method
    Find or create a cache of a given size.
    -------------------------------------------------------------------------
 */

icl_cache_t *
    icl_cache_get (
    qbyte size                          //  Not documented
)
{
    icl_cache_t
        *old_cache;
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
    char
        name [] = "icl_mem_xxxxxx_yyyyyy ";
#endif
    icl_cache_t *
        self;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_GET))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_GET))
    icl_stats_inc ("icl_cache_get", &s_icl_cache_get_stats);
#endif

    if (!s_icl_cache_active)
        icl_cache_initialise ();

#if (defined (BASE_THREADSAFE))
    icl_mutex_lock (s_icl_cache_mutex);
#endif
    //  Shift size up to nearest 64-byte boundary
    size = (size + 63) & 0xFFFFFFC0;

    old_cache = icl_cache_list_first (s_cache_list);
    while (old_cache) {
        if (old_cache->size >= size)
            break;
        old_cache = icl_cache_list_next (&old_cache);
    }
    if (old_cache
    &&  old_cache->size == size)
        self = old_cache;
    else {
        self = icl_cache_new ();
        self->size = size;

#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
        sprintf (&name [8], "%06lu ", (long) size);
        strcpy (&name [15], "used");
        self->used_stat = icl_stats_new (name);
        strcpy (&name [15], "unused");
        self->unused_stat = icl_stats_new (name);
        strcpy (&name [15], "allocs");
        self->allocs_stat = icl_stats_new (name);
        strcpy (&name [15], "frees");
        self->frees_stat = icl_stats_new (name);
#endif
        if (old_cache)
            icl_cache_list_relink_before (self, old_cache);
        else
            icl_cache_list_queue (s_cache_list, self);
    }

#if (defined (BASE_THREADSAFE))
    icl_mutex_unlock (s_icl_cache_mutex);
#endif
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_GET))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" size=\"%lu\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, size, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_cache_assert

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    icl_cache_assert_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
icl_cache_t
    *self;
FILE
    *trace_file = NULL;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_ASSERT))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_assert_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_ASSERT))
    icl_stats_inc ("icl_cache_assert", &s_icl_cache_assert_stats);
#endif

if (s_cache_list) {
    rc |= icl_mem_fat_cache_assert      (s_direct_cache, &trace_file);
    rc |= icl_mem_thin_cache_assert     (s_direct_cache, &trace_file);
    self = icl_cache_list_first (s_cache_list);
    while (self) {
        rc |= icl_mem_fat_cache_assert      (self, &trace_file);
        rc |= icl_mem_thin_cache_assert     (self, &trace_file);
        self = icl_cache_list_next (&self);
    }
    if (trace_file) {
        icl_console_redirect (trace_file);
        icl_trace_dump (NULL);
        icl_trace_terminate ();
        icl_console_redirect (NULL);
        fclose (trace_file);
    }
    //  Let user choose exit procedure (profiling breaks with aborts)
    if (rc) {
        char answer [3];
        printf ("Press [Enter] to end process, or [d] to get a core dump: ");
        strclr (answer);
        if (fgets (answer, 2, stdin) && *answer == 'd')
            abort ();
     }
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_ASSERT))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_assert_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_cache_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_INITIALISE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_INITIALISE))
    icl_stats_inc ("icl_cache_initialise", &s_icl_cache_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_icl_cache_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_icl_cache_mutex)
            s_icl_cache_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_icl_cache_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_icl_cache_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

    s_icl_cache_active = TRUE;          //  To prevent recursion

    s_cache_list   = icl_cache_list_new ();
    s_direct_cache = icl_cache_new ();
#if (defined (BASE_STATS) || defined (BASE_STATS_ICL_CACHE))
    s_direct_cache->used_stat   = icl_stats_new ("icl_mem_direct_used");
    s_direct_cache->allocs_stat = icl_stats_new ("icl_mem_direct_allocs");
    s_direct_cache->frees_stat  = icl_stats_new ("icl_mem_direct_frees");
#endif
            s_icl_cache_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_icl_cache_mutex);
#endif

    }
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_INITIALISE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_initialise_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    icl_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_TERMINATE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_TERMINATE))
    icl_stats_inc ("icl_cache_terminate", &s_icl_cache_terminate_stats);
#endif

if (s_icl_cache_active) {

icl_cache_assert ();
icl_cache_list_destroy (&s_cache_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_icl_cache_mutex);
#endif
        s_icl_cache_active = FALSE;
    }
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_TERMINATE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_terminate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    icl_cache_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_cache_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_SELFTEST))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_SELFTEST))
    icl_stats_inc ("icl_cache_selftest", &s_icl_cache_selftest_stats);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_SELFTEST))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_selftest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

}
/*  -------------------------------------------------------------------------
    icl_cache_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    icl_cache_remove_from_all_containers (
    icl_cache_t * self                  //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_REMOVE_FROM_ALL_CONTAINERS))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_remove_from_all_containers_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("icl_cache_remove_from_all_containers", &s_icl_cache_remove_from_all_containers_stats);
#endif

icl_cache_list_remove (self);
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_REMOVE_FROM_ALL_CONTAINERS))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_remove_from_all_containers_finish"
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
    icl_cache_destroy

    Type: Component method
    Destroys a icl_cache_t object. Takes the address of a
    icl_cache_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    Performs an agressive destroy of an object.  This involves:
    1. Removing the object from any containers it is in.
    2. Making the object an zombie
    3. Decrementing the object's link count
    4. If the link count is zero then freeing the object.
    -------------------------------------------------------------------------
 */

void
    icl_cache_destroy_ (
    icl_cache_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_cache_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_DESTROY_PUBLIC))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_DESTROY_PUBLIC))
    icl_stats_inc ("icl_cache_destroy", &s_icl_cache_destroy_stats);
#endif

if (self) {
    icl_cache_annihilate (self_p);
    icl_cache_free ((icl_cache_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_DESTROY_PUBLIC))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    icl_cache_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_cache_t *
    icl_cache_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_cache_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_ALLOC))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_alloc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_ALLOC))
    icl_stats_inc ("icl_cache_alloc", &s_icl_cache_alloc_stats);
#endif

self = (icl_cache_t *) malloc (sizeof (icl_cache_t));
if (self)
    memset (self, 0, sizeof (icl_cache_t));


#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_ALLOC))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_alloc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_cache_free

    Type: Component method
    Freess a icl_cache_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_cache_free (
    icl_cache_t * self                  //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_FREE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_free_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_FREE))
    icl_stats_inc ("icl_cache_free", &s_icl_cache_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->mutex)
        icl_mutex_destroy (&self->mutex);
#endif
        memset (&self->object_tag, 0, sizeof (icl_cache_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_cache_t));
        self->object_tag = ICL_CACHE_DEAD;
        free (self);
    }
    self = NULL;
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_FREE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_free_finish"
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
    icl_cache_lock

    Type: Component method
    Accepts a icl_cache_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_cache_lock (
    icl_cache_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_LOCK))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_lock_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_LOCK))
    icl_stats_inc ("icl_cache_lock", &s_icl_cache_lock_stats);
#endif

ICL_CACHE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_lock (self->mutex);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_LOCK))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_lock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_cache_unlock

    Type: Component method
    Accepts a icl_cache_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_cache_unlock (
    icl_cache_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_UNLOCK))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_unlock_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_UNLOCK))
    icl_stats_inc ("icl_cache_unlock", &s_icl_cache_unlock_stats);
#endif

ICL_CACHE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_unlock (self->mutex);
#endif


#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_UNLOCK))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_unlock_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_cache_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_cache_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_SHOW_ANIMATION))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_show_animation_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_SHOW_ANIMATION))
    icl_stats_inc ("icl_cache_show_animation", &s_icl_cache_show_animation_stats);
#endif

icl_cache_animating = enabled;
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_SHOW_ANIMATION))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_show_animation_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, enabled);
#endif

}
/*  -------------------------------------------------------------------------
    icl_cache_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_cache_new_in_scope_ (
    icl_cache_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_CACHE)  ||  defined (BASE_ANIMATE_ICL_CACHE_NEW_IN_SCOPE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_CACHE)  ||  defined (BASE_STATS_ICL_CACHE_NEW_IN_SCOPE))
    icl_stats_inc ("icl_cache_new_in_scope", &s_icl_cache_new_in_scope_stats);
#endif

*self_p = icl_cache_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_cache_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_CACHE)   || defined (BASE_ANIMATE_ICL_CACHE_NEW_IN_SCOPE))
    if (icl_cache_animating)
        icl_console_print ("<icl_cache_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, _destroy);
#endif

}
//  Embed the version information in the resulting binary                      

char *icl_cache_version_start      = "VeRsIoNsTaRt:ipc";
char *icl_cache_component          = "icl_cache ";
char *icl_cache_version            = "1.0 ";
char *icl_cache_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_cache_filename           = "icl_cache.icl ";
char *icl_cache_builddate          = "2009/02/19 ";
char *icl_cache_version_end        = "VeRsIoNeNd:ipc";

