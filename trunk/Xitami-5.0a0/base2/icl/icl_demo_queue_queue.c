/*---------------------------------------------------------------------------
    icl_demo_queue_queue.c - icl_demo_queue_queue component

    This class implements the queue container for icl_demo_queue
    Generated from icl_demo_queue_queue.icl by icl_gen using GSL/4.
    
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
#include "icl_demo_queue_queue.h"       //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_demo_queue_queue_t

//  Shorthands for class methods                                               

#define self_new            icl_demo_queue_queue_new
#define self_annihilate     icl_demo_queue_queue_annihilate
#define self_selftest       icl_demo_queue_queue_selftest
#define self_free           icl_demo_queue_queue_free
#define self_pop            icl_demo_queue_queue_pop
#define self_queue          icl_demo_queue_queue_queue
#define self_terminate      icl_demo_queue_queue_terminate
#define self_show           icl_demo_queue_queue_show
#define self_destroy        icl_demo_queue_queue_destroy
#define self_alloc          icl_demo_queue_queue_alloc
#define self_cache_initialise  icl_demo_queue_queue_cache_initialise
#define self_cache_purge    icl_demo_queue_queue_cache_purge
#define self_cache_terminate  icl_demo_queue_queue_cache_terminate
#define self_show_animation  icl_demo_queue_queue_show_animation
#define self_new_in_scope   icl_demo_queue_queue_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_NEW))
static icl_stats_t *s_icl_demo_queue_queue_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_DESTROY))
static icl_stats_t *s_icl_demo_queue_queue_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_SELFTEST))
static icl_stats_t *s_icl_demo_queue_queue_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_FREE))
static icl_stats_t *s_icl_demo_queue_queue_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_POP))
static icl_stats_t *s_icl_demo_queue_queue_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_QUEUE))
static icl_stats_t *s_icl_demo_queue_queue_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_TERMINATE))
static icl_stats_t *s_icl_demo_queue_queue_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_SHOW))
static icl_stats_t *s_icl_demo_queue_queue_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC))
static icl_stats_t *s_icl_demo_queue_queue_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_ALLOC))
static icl_stats_t *s_icl_demo_queue_queue_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE))
static icl_stats_t *s_icl_demo_queue_queue_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE))
static icl_stats_t *s_icl_demo_queue_queue_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE))
static icl_stats_t *s_icl_demo_queue_queue_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION))
static icl_stats_t *s_icl_demo_queue_queue_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE))
static icl_stats_t *s_icl_demo_queue_queue_new_in_scope_stats = NULL;
#endif
static void
    icl_demo_queue_queue_annihilate (
icl_demo_queue_queue_t * ( * self_p )   //  Reference to object reference
);

static void
    icl_demo_queue_queue_free (
icl_demo_queue_queue_t * self           //  Object reference
);

#define icl_demo_queue_queue_alloc()    icl_demo_queue_queue_alloc_ (__FILE__, __LINE__)
static icl_demo_queue_queue_t *
    icl_demo_queue_queue_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_demo_queue_queue_cache_initialise (
void);

static void
    icl_demo_queue_queue_cache_purge (
void);

static void
    icl_demo_queue_queue_cache_terminate (
void);

Bool
    icl_demo_queue_queue_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    icl_demo_queue_queue_new

    Type: Component method
    Creates and initialises a new icl_demo_queue_queue_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_demo_queue_queue_t *
    icl_demo_queue_queue_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_demo_queue_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_NEW))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_NEW))
    icl_trace_record (1, icl_demo_queue_queue_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_NEW))
    icl_stats_inc ("icl_demo_queue_queue_new", &s_icl_demo_queue_queue_new_stats);
#endif

    self = icl_demo_queue_queue_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DEMO_QUEUE_QUEUE_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_demo_queue_queue_show_);
#endif

#if (defined (BASE_THREADSAFE))
    self->mutex = icl_mutex_new ();
#endif

    self->head = NULL;
    self->tail = NULL;


}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_NEW))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_NEW))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_new_finish"
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
    icl_demo_queue_queue_annihilate

    Type: Component method
    Destroys the queue and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_queue_queue_annihilate (
    icl_demo_queue_queue_t * ( * self_p )  //  Reference to object reference
)
{

    icl_demo_queue_t
        *item;
#if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#endif
    icl_demo_queue_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_DESTROY))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_DESTROY))
    icl_trace_record (1, icl_demo_queue_queue_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_DESTROY))
    icl_stats_inc ("icl_demo_queue_queue_annihilate", &s_icl_demo_queue_queue_annihilate_stats);
#endif

ICL_DEMO_QUEUE_QUEUE_ASSERT_SANE (self);

#if defined (BASE_THREADSAFE)
    mutex = self->mutex;
    if (mutex)
         icl_mutex_lock (mutex);
#endif


    item = (icl_demo_queue_t *) self->head;
    while (item != NULL) {
        //  Unlink child without lock (we already have the lock)               
        self->head = item->queue_next;

        icl_demo_queue_unlink (&item);
        item = (icl_demo_queue_t *) self->head;
    }
#if defined (BASE_THREADSAFE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_DESTROY))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_DESTROY))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_destroy_finish"
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
    icl_demo_queue_queue_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_queue_queue_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_SELFTEST))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SELFTEST))
    icl_trace_record (1, icl_demo_queue_queue_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_SELFTEST))
    icl_stats_inc ("icl_demo_queue_queue_selftest", &s_icl_demo_queue_queue_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SELFTEST))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_SELFTEST))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_selftest_finish"
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
    icl_demo_queue_queue_free

    Type: Component method
    Freess a icl_demo_queue_queue_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_queue_queue_free (
    icl_demo_queue_queue_t * self       //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_FREE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_FREE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_FREE))
    icl_stats_inc ("icl_demo_queue_queue_free", &s_icl_demo_queue_queue_free_stats);
#endif

if (self) {

#if defined (BASE_THREADSAFE)
    if (self->mutex)
        icl_mutex_destroy (&self->mutex);
#endif
        memset (&self->object_tag, 0, sizeof (icl_demo_queue_queue_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_queue_queue_t));
        self->object_tag = ICL_DEMO_QUEUE_QUEUE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_FREE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_FREE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_free_finish"
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
    icl_demo_queue_queue_pop

    Type: Component method
    Removes the next item in the queue, if any, and returns it.  If
    the queue was empty, returns NULL.
    
    The number of links is unchanged; removing from the queue and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

icl_demo_queue_t *
    icl_demo_queue_queue_pop (
    icl_demo_queue_queue_t * self       //  The queue
)
{
#if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#endif
    icl_demo_queue_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_POP))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_POP))
    icl_trace_record (1, icl_demo_queue_queue_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_POP))
    icl_stats_inc ("icl_demo_queue_queue_pop", &s_icl_demo_queue_queue_pop_stats);
#endif

    ICL_DEMO_QUEUE_QUEUE_ASSERT_SANE (self);
#if defined (BASE_THREADSAFE)
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

        item = (icl_demo_queue_t *) self->head;
        if (item) {
            self->head = item->queue_next;
            if (self->head == NULL)
                self->tail = NULL;
            item->queue_next = NULL;
            item->queue_head = NULL;
        }

        if (item) {
        }

#if defined (BASE_THREADSAFE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_POP))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_POP))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_pop_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    icl_demo_queue_queue_queue

    Type: Component method
    Attaches the item to the end of the specified queue.  The item may not
    be in a queue of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the queue, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    icl_demo_queue_queue_queue (
    icl_demo_queue_queue_t * self,      //  Reference to object
    icl_demo_queue_t * item             //  Not documented
)
{
#if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#endif
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_QUEUE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_QUEUE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_QUEUE))
    icl_stats_inc ("icl_demo_queue_queue_queue", &s_icl_demo_queue_queue_queue_stats);
#endif

#if defined (BASE_THREADSAFE)
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

    ICL_DEMO_QUEUE_QUEUE_ASSERT_SANE (self);

        if (! item->queue_head) {
            icl_demo_queue_link (item);

            if (self->tail)
                self->tail->queue_next = item;
            else
                self->head = item;
            self->tail = item;
            item->queue_next = NULL;
            item->queue_head = self;
        }
        else {
            //  Requeuing into the same queue isn't allowed.
            icl_console_print ("E: icl_demo_queue item inserted into multiple queue containers");
            assert (item->queue_head == NULL);
        }



#if defined (BASE_THREADSAFE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_QUEUE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_QUEUE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_demo_queue_queue_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_queue_queue_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_TERMINATE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_TERMINATE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_TERMINATE))
    icl_stats_inc ("icl_demo_queue_queue_terminate", &s_icl_demo_queue_queue_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_TERMINATE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_TERMINATE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_terminate_finish"
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
    icl_demo_queue_queue_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_queue_queue_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
icl_demo_queue_queue_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_SHOW))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SHOW))
    icl_trace_record (1, icl_demo_queue_queue_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_SHOW))
    icl_stats_inc ("icl_demo_queue_queue_show", &s_icl_demo_queue_queue_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <icl_demo_queue_queue file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SHOW))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_SHOW))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_show_finish"
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
    icl_demo_queue_queue_destroy

    Type: Component method
    Destroys a icl_demo_queue_queue_t object. Takes the address of a
    icl_demo_queue_queue_t reference (a pointer to a pointer) and nullifies the
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
    icl_demo_queue_queue_destroy_ (
    icl_demo_queue_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_queue_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC))
    icl_trace_record (1, icl_demo_queue_queue_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC))
    icl_stats_inc ("icl_demo_queue_queue_destroy", &s_icl_demo_queue_queue_destroy_stats);
#endif

if (self) {
    icl_demo_queue_queue_annihilate (self_p);
    icl_demo_queue_queue_free ((icl_demo_queue_queue_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_destroy_public_finish"
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
    icl_demo_queue_queue_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_queue_queue_t *
    icl_demo_queue_queue_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_demo_queue_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_ALLOC))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_ALLOC))
    icl_trace_record (1, icl_demo_queue_queue_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_ALLOC))
    icl_stats_inc ("icl_demo_queue_queue_alloc", &s_icl_demo_queue_queue_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    icl_demo_queue_queue_cache_initialise ();

self = (icl_demo_queue_queue_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_demo_queue_queue_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_ALLOC))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_ALLOC))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_alloc_finish"
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
    icl_demo_queue_queue_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_queue_queue_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE))
    icl_stats_inc ("icl_demo_queue_queue_cache_initialise", &s_icl_demo_queue_queue_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (icl_demo_queue_queue_t));
icl_system_register (icl_demo_queue_queue_cache_purge, icl_demo_queue_queue_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_cache_initialise_finish"
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
    icl_demo_queue_queue_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_queue_queue_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE))
    icl_stats_inc ("icl_demo_queue_queue_cache_purge", &s_icl_demo_queue_queue_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_cache_purge_finish"
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
    icl_demo_queue_queue_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_queue_queue_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE))
    icl_stats_inc ("icl_demo_queue_queue_cache_terminate", &s_icl_demo_queue_queue_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_cache_terminate_finish"
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
    icl_demo_queue_queue_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_queue_queue_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION))
    icl_trace_record (1, icl_demo_queue_queue_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION))
    icl_stats_inc ("icl_demo_queue_queue_show_animation", &s_icl_demo_queue_queue_show_animation_stats);
#endif

icl_demo_queue_queue_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_show_animation_finish"
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
    icl_demo_queue_queue_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_queue_queue_new_in_scope_ (
    icl_demo_queue_queue_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE)  ||  defined (BASE_STATS_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE))
    icl_stats_inc ("icl_demo_queue_queue_new_in_scope", &s_icl_demo_queue_queue_new_in_scope_stats);
#endif

*self_p = icl_demo_queue_queue_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_queue_queue_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE))
    icl_trace_record (1, icl_demo_queue_queue_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_ANIMATE_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE))
    if (icl_demo_queue_queue_animating)
        icl_console_print ("<icl_demo_queue_queue_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_NEW)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_FREE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_POP)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_QUEUE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SHOW)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_PURGE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_SHOW_ANIMATION)   || defined (BASE_TRACE_ICL_DEMO_QUEUE_QUEUE_NEW_IN_SCOPE) )
void
icl_demo_queue_queue_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "free"; break;
        case 5: method_name = "pop"; break;
        case 6: method_name = "queue"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "cache initialise"; break;
        case 12: method_name = "cache purge"; break;
        case 13: method_name = "cache terminate"; break;
        case 14: method_name = "show animation"; break;
        case 15: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_demo_queue_queue %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_demo_queue_queue_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_demo_queue_queue_component  = "icl_demo_queue_queue ";
char *icl_demo_queue_queue_version  = "1.0 ";
char *icl_demo_queue_queue_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_demo_queue_queue_filename  = "icl_demo_queue_queue.icl ";
char *icl_demo_queue_queue_builddate  = "2009/02/19 ";
char *icl_demo_queue_queue_version_end  = "VeRsIoNeNd:ipc";

