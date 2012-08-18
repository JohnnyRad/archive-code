/*---------------------------------------------------------------------------
    ipr_looseref.c - ipr_looseref component

    Allows classes to maintain lists of references to other classes without
    creating explicitly-typed classes for each case.  Uses a void * to refer
    to the target class.
    Generated from ipr_looseref.icl by icl_gen using GSL/4.
    
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
#include "ipr_looseref.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_looseref_t

//  Shorthands for class methods                                               

#define self_new            ipr_looseref_new
#define self_annihilate     ipr_looseref_annihilate
#define self_queue          ipr_looseref_queue
#define self_push           ipr_looseref_push
#define self_pop            ipr_looseref_pop
#define self_selftest       ipr_looseref_selftest
#define self_remove_from_all_containers  ipr_looseref_remove_from_all_containers
#define self_show           ipr_looseref_show
#define self_terminate      ipr_looseref_terminate
#define self_destroy        ipr_looseref_destroy
#define self_alloc          ipr_looseref_alloc
#define self_free           ipr_looseref_free
#define self_cache_initialise  ipr_looseref_cache_initialise
#define self_cache_purge    ipr_looseref_cache_purge
#define self_cache_terminate  ipr_looseref_cache_terminate
#define self_show_animation  ipr_looseref_show_animation
#define self_new_in_scope   ipr_looseref_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_NEW))
static icl_stats_t *s_ipr_looseref_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_DESTROY))
static icl_stats_t *s_ipr_looseref_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_QUEUE))
static icl_stats_t *s_ipr_looseref_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_PUSH))
static icl_stats_t *s_ipr_looseref_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_POP))
static icl_stats_t *s_ipr_looseref_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_SELFTEST))
static icl_stats_t *s_ipr_looseref_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_looseref_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_SHOW))
static icl_stats_t *s_ipr_looseref_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_TERMINATE))
static icl_stats_t *s_ipr_looseref_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_looseref_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_ALLOC))
static icl_stats_t *s_ipr_looseref_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_FREE))
static icl_stats_t *s_ipr_looseref_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_CACHE_INITIALISE))
static icl_stats_t *s_ipr_looseref_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_CACHE_PURGE))
static icl_stats_t *s_ipr_looseref_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_CACHE_TERMINATE))
static icl_stats_t *s_ipr_looseref_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_SHOW_ANIMATION))
static icl_stats_t *s_ipr_looseref_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_looseref_new_in_scope_stats = NULL;
#endif
static void
    ipr_looseref_annihilate (
ipr_looseref_t * ( * self_p )           //  Reference to object reference
);

#define ipr_looseref_alloc()            ipr_looseref_alloc_ (__FILE__, __LINE__)
static ipr_looseref_t *
    ipr_looseref_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_looseref_free (
ipr_looseref_t * self                   //  Object reference
);

static void
    ipr_looseref_cache_initialise (
void);

static void
    ipr_looseref_cache_purge (
void);

static void
    ipr_looseref_cache_terminate (
void);

Bool
    ipr_looseref_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_looseref_new

    Type: Component method
    Creates and initialises a new ipr_looseref_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

ipr_looseref_t *
    ipr_looseref_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_looseref_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_NEW))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_NEW))
    icl_trace_record (NULL, ipr_looseref_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_NEW))
    icl_stats_inc ("ipr_looseref_new", &s_ipr_looseref_new_stats);
#endif

    self = ipr_looseref_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_LOOSEREF_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_looseref_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_NEW))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_NEW))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_new_finish"
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
    ipr_looseref_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_looseref_annihilate (
    ipr_looseref_t * ( * self_p )       //  Reference to object reference
)
{

    ipr_looseref_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_DESTROY))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_DESTROY))
    icl_trace_record (NULL, ipr_looseref_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_DESTROY))
    icl_stats_inc ("ipr_looseref_annihilate", &s_ipr_looseref_annihilate_stats);
#endif

IPR_LOOSEREF_ASSERT_SANE (self);
ipr_looseref_remove_from_all_containers (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_DESTROY))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_DESTROY))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_destroy_finish"
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
    ipr_looseref_queue

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_looseref_t *
    ipr_looseref_queue (
    ipr_looseref_list_t * list,         //  List to attach to
    void * object                       //  Target object reference
)
{
    ipr_looseref_t *
        self;                           //  The item

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_QUEUE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" list=\"%pp\""
" object=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, list, object);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_QUEUE))
    icl_trace_record (NULL, ipr_looseref_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_QUEUE))
    icl_stats_inc ("ipr_looseref_queue", &s_ipr_looseref_queue_stats);
#endif

self = ipr_looseref_new ();
if (self) {
    self->object = object;
    ipr_looseref_list_queue (list, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_QUEUE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_QUEUE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" list=\"%pp\""
" object=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, list, object, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_looseref_push

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_looseref_t *
    ipr_looseref_push (
    ipr_looseref_list_t * list,         //  List to attach to
    void * object                       //  Target object reference
)
{
    ipr_looseref_t *
        self;                           //  The item

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_PUSH))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_push_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" list=\"%pp\""
" object=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, list, object);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_PUSH))
    icl_trace_record (NULL, ipr_looseref_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_PUSH))
    icl_stats_inc ("ipr_looseref_push", &s_ipr_looseref_push_stats);
#endif

self = ipr_looseref_new ();
if (self) {
    self->object = object;
    ipr_looseref_list_push (list, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_PUSH))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_PUSH))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_push_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" list=\"%pp\""
" object=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, list, object, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_looseref_pop

    Type: Component method
    -------------------------------------------------------------------------
 */

void *
    ipr_looseref_pop (
    ipr_looseref_list_t * list          //  List to attach to
)
{
ipr_looseref_t *self;
    void *
        object = NULL;                  //  Target object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_POP))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_pop_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" list=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, list);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_POP))
    icl_trace_record (NULL, ipr_looseref_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_POP))
    icl_stats_inc ("ipr_looseref_pop", &s_ipr_looseref_pop_stats);
#endif

self = ipr_looseref_list_pop (list);
if (self) {
    object = self->object;
    ipr_looseref_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_POP))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_POP))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_pop_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" list=\"%pp\""
" object=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, list, object);
#endif


    return (object);
}
/*  -------------------------------------------------------------------------
    ipr_looseref_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_looseref_selftest (
void)
{
ipr_looseref_list_t
    *list;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_SELFTEST))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_SELFTEST))
    icl_trace_record (NULL, ipr_looseref_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_SELFTEST))
    icl_stats_inc ("ipr_looseref_selftest", &s_ipr_looseref_selftest_stats);
#endif

list = ipr_looseref_list_new ();
ipr_looseref_queue (list, (void *) list);
ipr_looseref_queue (list, (void *) list);
ipr_looseref_queue (list, (void *) list);
assert (ipr_looseref_pop (list) == (void *) list);
ipr_looseref_list_destroy (&list);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_SELFTEST))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_SELFTEST))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_selftest_finish"
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
    ipr_looseref_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_looseref_remove_from_all_containers (
    ipr_looseref_t * self               //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_looseref_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_looseref_remove_from_all_containers", &s_ipr_looseref_remove_from_all_containers_stats);
#endif

ipr_looseref_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_remove_from_all_containers_finish"
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
    ipr_looseref_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_looseref_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_looseref_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_SHOW))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_SHOW))
    icl_trace_record (NULL, ipr_looseref_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_SHOW))
    icl_stats_inc ("ipr_looseref_show", &s_ipr_looseref_show_stats);
#endif

self = item;
container_links = 0;
if (self->list_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_looseref file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_SHOW))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_SHOW))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_show_finish"
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
    ipr_looseref_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_looseref_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_TERMINATE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_TERMINATE))
    icl_trace_record (NULL, ipr_looseref_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_TERMINATE))
    icl_stats_inc ("ipr_looseref_terminate", &s_ipr_looseref_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_TERMINATE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_TERMINATE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_terminate_finish"
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
    ipr_looseref_destroy

    Type: Component method
    Destroys a ipr_looseref_t object. Takes the address of a
    ipr_looseref_t reference (a pointer to a pointer) and nullifies the
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
    ipr_looseref_destroy_ (
    ipr_looseref_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_looseref_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_DESTROY_PUBLIC))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_looseref_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_looseref_destroy", &s_ipr_looseref_destroy_stats);
#endif

if (self) {
    ipr_looseref_annihilate (self_p);
    ipr_looseref_free ((ipr_looseref_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_DESTROY_PUBLIC))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_destroy_public_finish"
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
    ipr_looseref_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_looseref_t *
    ipr_looseref_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_looseref_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_ALLOC))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_ALLOC))
    icl_trace_record (NULL, ipr_looseref_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_ALLOC))
    icl_stats_inc ("ipr_looseref_alloc", &s_ipr_looseref_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_looseref_cache_initialise ();

self = (ipr_looseref_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_looseref_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_ALLOC))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_ALLOC))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_alloc_finish"
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
    ipr_looseref_free

    Type: Component method
    Freess a ipr_looseref_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_looseref_free (
    ipr_looseref_t * self               //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_FREE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_FREE))
    icl_trace_record (NULL, ipr_looseref_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_FREE))
    icl_stats_inc ("ipr_looseref_free", &s_ipr_looseref_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_looseref_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_looseref_t));
        self->object_tag = IPR_LOOSEREF_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_FREE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_FREE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_free_finish"
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
    ipr_looseref_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_looseref_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_CACHE_INITIALISE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_looseref_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_CACHE_INITIALISE))
    icl_stats_inc ("ipr_looseref_cache_initialise", &s_ipr_looseref_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_looseref_t));
icl_system_register (ipr_looseref_cache_purge, ipr_looseref_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_CACHE_INITIALISE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_cache_initialise_finish"
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
    ipr_looseref_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_looseref_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_CACHE_PURGE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_PURGE))
    icl_trace_record (NULL, ipr_looseref_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_CACHE_PURGE))
    icl_stats_inc ("ipr_looseref_cache_purge", &s_ipr_looseref_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_PURGE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_CACHE_PURGE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_cache_purge_finish"
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
    ipr_looseref_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_looseref_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_CACHE_TERMINATE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_looseref_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_CACHE_TERMINATE))
    icl_stats_inc ("ipr_looseref_cache_terminate", &s_ipr_looseref_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_CACHE_TERMINATE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_cache_terminate_finish"
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
    ipr_looseref_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_looseref_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_SHOW_ANIMATION))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_looseref_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_SHOW_ANIMATION))
    icl_stats_inc ("ipr_looseref_show_animation", &s_ipr_looseref_show_animation_stats);
#endif

ipr_looseref_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_SHOW_ANIMATION))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_show_animation_finish"
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
    ipr_looseref_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_looseref_new_in_scope_ (
    ipr_looseref_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF)  ||  defined (BASE_ANIMATE_IPR_LOOSEREF_NEW_IN_SCOPE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_looseref_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOOSEREF)  ||  defined (BASE_STATS_IPR_LOOSEREF_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_looseref_new_in_scope", &s_ipr_looseref_new_in_scope_stats);
#endif

*self_p = ipr_looseref_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_looseref_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_looseref_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOOSEREF)   || defined (BASE_ANIMATE_IPR_LOOSEREF_NEW_IN_SCOPE))
    if (ipr_looseref_animating)
        icl_console_print ("<ipr_looseref_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOOSEREF)   || defined (BASE_TRACE_IPR_LOOSEREF_NEW)   || defined (BASE_TRACE_IPR_LOOSEREF_DESTROY)   || defined (BASE_TRACE_IPR_LOOSEREF_QUEUE)   || defined (BASE_TRACE_IPR_LOOSEREF_PUSH)   || defined (BASE_TRACE_IPR_LOOSEREF_POP)   || defined (BASE_TRACE_IPR_LOOSEREF_SELFTEST)   || defined (BASE_TRACE_IPR_LOOSEREF_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_LOOSEREF_SHOW)   || defined (BASE_TRACE_IPR_LOOSEREF_TERMINATE)   || defined (BASE_TRACE_IPR_LOOSEREF_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_LOOSEREF_ALLOC)   || defined (BASE_TRACE_IPR_LOOSEREF_FREE)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_PURGE)   || defined (BASE_TRACE_IPR_LOOSEREF_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_LOOSEREF_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_LOOSEREF_NEW_IN_SCOPE) )
void
ipr_looseref_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "queue"; break;
        case 4: method_name = "push"; break;
        case 5: method_name = "pop"; break;
        case 6: method_name = "selftest"; break;
        case 7: method_name = "remove from all containers"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "terminate"; break;
        case 10: method_name = "destroy public"; break;
        case 11: method_name = "alloc"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "cache initialise"; break;
        case 14: method_name = "cache purge"; break;
        case 15: method_name = "cache terminate"; break;
        case 16: method_name = "show animation"; break;
        case 17: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_looseref %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_looseref_version_start   = "VeRsIoNsTaRt:ipc";
char *ipr_looseref_component       = "ipr_looseref ";
char *ipr_looseref_version         = "1.0 ";
char *ipr_looseref_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_looseref_filename        = "ipr_looseref.icl ";
char *ipr_looseref_builddate       = "2009/02/19 ";
char *ipr_looseref_version_end     = "VeRsIoNeNd:ipc";

