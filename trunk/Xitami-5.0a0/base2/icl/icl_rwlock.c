/*---------------------------------------------------------------------------
    icl_rwlock.c - icl_rwlock component

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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "icl_rwlock.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_rwlock_t

//  Shorthands for class methods                                               

#define self_alloc          icl_rwlock_alloc
#define self_free           icl_rwlock_free
#define self_cache_initialise  icl_rwlock_cache_initialise
#define self_read_lock      icl_rwlock_read_lock
#define self_write_lock     icl_rwlock_write_lock
#define self_unlock         icl_rwlock_unlock
#define self_selftest       icl_rwlock_selftest
#define self_terminate      icl_rwlock_terminate
#define self_new            icl_rwlock_new
#define self_show           icl_rwlock_show
#define self_destroy        icl_rwlock_destroy
#define self_annihilate     icl_rwlock_annihilate
#define self_cache_purge    icl_rwlock_cache_purge
#define self_cache_terminate  icl_rwlock_cache_terminate
#define self_show_animation  icl_rwlock_show_animation
#define self_new_in_scope   icl_rwlock_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_ALLOC))
static icl_stats_t *s_icl_rwlock_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_FREE))
static icl_stats_t *s_icl_rwlock_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_CACHE_INITIALISE))
static icl_stats_t *s_icl_rwlock_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_READ_LOCK))
       icl_stats_t *s_icl_rwlock_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_WRITE_LOCK))
       icl_stats_t *s_icl_rwlock_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_UNLOCK))
       icl_stats_t *s_icl_rwlock_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_SELFTEST))
static icl_stats_t *s_icl_rwlock_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_TERMINATE))
static icl_stats_t *s_icl_rwlock_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_NEW))
static icl_stats_t *s_icl_rwlock_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_SHOW))
static icl_stats_t *s_icl_rwlock_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_DESTROY_PUBLIC))
static icl_stats_t *s_icl_rwlock_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_DESTROY))
static icl_stats_t *s_icl_rwlock_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_CACHE_PURGE))
static icl_stats_t *s_icl_rwlock_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_CACHE_TERMINATE))
static icl_stats_t *s_icl_rwlock_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_SHOW_ANIMATION))
static icl_stats_t *s_icl_rwlock_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_NEW_IN_SCOPE))
static icl_stats_t *s_icl_rwlock_new_in_scope_stats = NULL;
#endif
#define icl_rwlock_alloc()              icl_rwlock_alloc_ (__FILE__, __LINE__)
static icl_rwlock_t *
    icl_rwlock_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_rwlock_free (
icl_rwlock_t * self                     //  Object reference
);

static void
    icl_rwlock_cache_initialise (
void);

static void
    icl_rwlock_annihilate (
icl_rwlock_t * ( * self_p )             //  Reference to object reference
);

static void
    icl_rwlock_cache_purge (
void);

static void
    icl_rwlock_cache_terminate (
void);

Bool
    icl_rwlock_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    icl_rwlock_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_rwlock_t *
    icl_rwlock_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_rwlock_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_ALLOC))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_ALLOC))
    icl_trace_record (NULL, icl_rwlock_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_ALLOC))
    icl_stats_inc ("icl_rwlock_alloc", &s_icl_rwlock_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    icl_rwlock_cache_initialise ();

self = (icl_rwlock_t *) icl_mem_cache_pop_ (s_cache, file, line);
if (!self) {
    self = (icl_rwlock_t *) icl_mem_cache_new_ (s_cache, file, line);

#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_pool_create (&self->pool, icl_global_pool));
    apr_pool_tag   (self->pool, "icl_rwlock_alloc");
    icl_apr_assert (apr_thread_rwlock_create (&self->rwlock, self->pool));
#endif
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_ALLOC))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_ALLOC))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_alloc_finish"
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
    icl_rwlock_free

    Type: Component method
    Freess a icl_rwlock_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_rwlock_free (
    icl_rwlock_t * self                 //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_FREE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_FREE))
    icl_trace_record (NULL, icl_rwlock_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_FREE))
    icl_stats_inc ("icl_rwlock_free", &s_icl_rwlock_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (icl_mem_allocator == ICL_MEM_DIRECT) {
        icl_apr_assert (apr_thread_rwlock_destroy (self->rwlock));
        apr_pool_destroy (self->pool);
    }
#endif
    self->object_tag = ICL_RWLOCK_DEAD;
    icl_mem_free (self);
}
self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_FREE))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_FREE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_free_finish"
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
    icl_rwlock_cache_initialise

    Type: Component method
    We need a private cache since we're going to re-use the apr_rwlock fields.
    -------------------------------------------------------------------------
 */

static void
    icl_rwlock_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_CACHE_INITIALISE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_rwlock_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_CACHE_INITIALISE))
    icl_stats_inc ("icl_rwlock_cache_initialise", &s_icl_rwlock_cache_initialise_stats);
#endif

s_cache = icl_cache_create (sizeof (icl_rwlock_t));
icl_system_register (icl_rwlock_cache_purge, icl_rwlock_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_CACHE_INITIALISE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_cache_initialise_finish"
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
    icl_rwlock_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_rwlock_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_SELFTEST))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SELFTEST))
    icl_trace_record (NULL, icl_rwlock_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_SELFTEST))
    icl_stats_inc ("icl_rwlock_selftest", &s_icl_rwlock_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SELFTEST))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_SELFTEST))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_selftest_finish"
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
    icl_rwlock_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_rwlock_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_TERMINATE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_TERMINATE))
    icl_trace_record (NULL, icl_rwlock_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_TERMINATE))
    icl_stats_inc ("icl_rwlock_terminate", &s_icl_rwlock_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_TERMINATE))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_TERMINATE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_terminate_finish"
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
    icl_rwlock_new

    Type: Component method
    Creates and initialises a new icl_rwlock_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_rwlock_t *
    icl_rwlock_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_rwlock_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_NEW))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_NEW))
    icl_trace_record (NULL, icl_rwlock_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_NEW))
    icl_stats_inc ("icl_rwlock_new", &s_icl_rwlock_new_stats);
#endif

    self = icl_rwlock_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_RWLOCK_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_rwlock_show_);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_NEW))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_NEW))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_new_finish"
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
    icl_rwlock_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_rwlock_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
icl_rwlock_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_SHOW))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_show_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW))
    icl_trace_record (NULL, icl_rwlock_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_SHOW))
    icl_stats_inc ("icl_rwlock_show", &s_icl_rwlock_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <icl_rwlock file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_SHOW))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_show_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" opcode=\"%i\""
" trace_file=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, opcode, trace_file, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    icl_rwlock_destroy

    Type: Component method
    Destroys a icl_rwlock_t object. Takes the address of a
    icl_rwlock_t reference (a pointer to a pointer) and nullifies the
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
    icl_rwlock_destroy_ (
    icl_rwlock_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_rwlock_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_DESTROY_PUBLIC))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_rwlock_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_DESTROY_PUBLIC))
    icl_stats_inc ("icl_rwlock_destroy", &s_icl_rwlock_destroy_stats);
#endif

if (self) {
    icl_rwlock_annihilate (self_p);
    icl_rwlock_free ((icl_rwlock_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_DESTROY_PUBLIC))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_destroy_public_finish"
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
    icl_rwlock_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_rwlock_annihilate (
    icl_rwlock_t * ( * self_p )         //  Reference to object reference
)
{

    icl_rwlock_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_DESTROY))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY))
    icl_trace_record (NULL, icl_rwlock_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_DESTROY))
    icl_stats_inc ("icl_rwlock_annihilate", &s_icl_rwlock_annihilate_stats);
#endif

ICL_RWLOCK_ASSERT_SANE (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_DESTROY))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_destroy_finish"
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
    icl_rwlock_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_rwlock_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_CACHE_PURGE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_PURGE))
    icl_trace_record (NULL, icl_rwlock_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_CACHE_PURGE))
    icl_stats_inc ("icl_rwlock_cache_purge", &s_icl_rwlock_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_PURGE))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_CACHE_PURGE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_cache_purge_finish"
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
    icl_rwlock_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_rwlock_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_CACHE_TERMINATE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_rwlock_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_CACHE_TERMINATE))
    icl_stats_inc ("icl_rwlock_cache_terminate", &s_icl_rwlock_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_CACHE_TERMINATE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_cache_terminate_finish"
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
    icl_rwlock_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_rwlock_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_SHOW_ANIMATION))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_rwlock_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_SHOW_ANIMATION))
    icl_stats_inc ("icl_rwlock_show_animation", &s_icl_rwlock_show_animation_stats);
#endif

icl_rwlock_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_SHOW_ANIMATION))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_show_animation_finish"
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
    icl_rwlock_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_rwlock_new_in_scope_ (
    icl_rwlock_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_RWLOCK)  ||  defined (BASE_ANIMATE_ICL_RWLOCK_NEW_IN_SCOPE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_rwlock_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_RWLOCK)  ||  defined (BASE_STATS_ICL_RWLOCK_NEW_IN_SCOPE))
    icl_stats_inc ("icl_rwlock_new_in_scope", &s_icl_rwlock_new_in_scope_stats);
#endif

*self_p = icl_rwlock_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_rwlock_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_rwlock_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_RWLOCK)   || defined (BASE_ANIMATE_ICL_RWLOCK_NEW_IN_SCOPE))
    if (icl_rwlock_animating)
        icl_console_print ("<icl_rwlock_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_RWLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_ALLOC)   || defined (BASE_TRACE_ICL_RWLOCK_FREE)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_RWLOCK_READ_LOCK)   || defined (BASE_TRACE_ICL_RWLOCK_WRITE_LOCK)   || defined (BASE_TRACE_ICL_RWLOCK_UNLOCK)   || defined (BASE_TRACE_ICL_RWLOCK_SELFTEST)   || defined (BASE_TRACE_ICL_RWLOCK_TERMINATE)   || defined (BASE_TRACE_ICL_RWLOCK_NEW)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_RWLOCK_DESTROY)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_PURGE)   || defined (BASE_TRACE_ICL_RWLOCK_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_RWLOCK_SHOW_ANIMATION)   || defined (BASE_TRACE_ICL_RWLOCK_NEW_IN_SCOPE) )
void
icl_rwlock_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "alloc"; break;
        case 2: method_name = "free"; break;
        case 3: method_name = "cache initialise"; break;
        case 4: method_name = "read lock"; break;
        case 5: method_name = "write lock"; break;
        case 6: method_name = "unlock"; break;
        case 7: method_name = "selftest"; break;
        case 8: method_name = "terminate"; break;
        case 9: method_name = "new"; break;
        case 10: method_name = "show"; break;
        case 11: method_name = "destroy public"; break;
        case 12: method_name = "destroy"; break;
        case 13: method_name = "cache purge"; break;
        case 14: method_name = "cache terminate"; break;
        case 15: method_name = "show animation"; break;
        case 16: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_rwlock %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_rwlock_version_start     = "VeRsIoNsTaRt:ipc";
char *icl_rwlock_component         = "icl_rwlock ";
char *icl_rwlock_version           = "1.2 ";
char *icl_rwlock_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_rwlock_filename          = "icl_rwlock.icl ";
char *icl_rwlock_builddate         = "2009/02/19 ";
char *icl_rwlock_version_end       = "VeRsIoNeNd:ipc";

