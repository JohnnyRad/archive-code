/*---------------------------------------------------------------------------
    smt_timer_request.c - smt_timer_request component

    The smt_timer_request class handles timing requests made either directly
    by application code or indirectly via socket requests with timeouts.
    Generated from smt_timer_request.icl by icl_gen using GSL/4.
    
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
#include "smt_timer_request.h"          //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_timer_request_t

//  Shorthands for class methods                                               

#define self_initialise     smt_timer_request_initialise
#define self_new            smt_timer_request_new
#define self_annihilate     smt_timer_request_annihilate
#define self_wakeup         smt_timer_request_wakeup
#define self_delay          smt_timer_request_delay
#define self_expire_all     smt_timer_request_expire_all
#define self_first          smt_timer_request_first
#define self_selftest       smt_timer_request_selftest
#define self_remove_from_all_containers  smt_timer_request_remove_from_all_containers
#define self_show           smt_timer_request_show
#define self_terminate      smt_timer_request_terminate
#define self_destroy        smt_timer_request_destroy
#define self_alloc          smt_timer_request_alloc
#define self_free           smt_timer_request_free
#define self_show_animation  smt_timer_request_show_animation
#define self_new_in_scope   smt_timer_request_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_INITIALISE))
static icl_stats_t *s_smt_timer_request_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_NEW))
static icl_stats_t *s_smt_timer_request_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_DESTROY))
static icl_stats_t *s_smt_timer_request_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_WAKEUP))
static icl_stats_t *s_smt_timer_request_wakeup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_DELAY))
static icl_stats_t *s_smt_timer_request_delay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_EXPIRE_ALL))
static icl_stats_t *s_smt_timer_request_expire_all_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_FIRST))
static icl_stats_t *s_smt_timer_request_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_SELFTEST))
static icl_stats_t *s_smt_timer_request_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_smt_timer_request_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_SHOW))
static icl_stats_t *s_smt_timer_request_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_TERMINATE))
static icl_stats_t *s_smt_timer_request_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_DESTROY_PUBLIC))
static icl_stats_t *s_smt_timer_request_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_ALLOC))
static icl_stats_t *s_smt_timer_request_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_FREE))
static icl_stats_t *s_smt_timer_request_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_SHOW_ANIMATION))
static icl_stats_t *s_smt_timer_request_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_NEW_IN_SCOPE))
static icl_stats_t *s_smt_timer_request_new_in_scope_stats = NULL;
#endif
static void
    smt_timer_request_annihilate (
smt_timer_request_t * ( * self_p )      //  Reference to object reference
);

static void
    smt_timer_request_terminate (
void);

#define smt_timer_request_alloc()       smt_timer_request_alloc_ (__FILE__, __LINE__)
static smt_timer_request_t *
    smt_timer_request_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_timer_request_free (
smt_timer_request_t * self              //  Object reference
);

Bool
    smt_timer_request_animating = TRUE;  //  Animation enabled by default
static Bool
    s_smt_timer_request_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_timer_request_mutex  = NULL;
#endif
#if (defined (BASE_THREADSAFE))
static apr_threadkey_t
    *threadkey;                         //  To hold thread-local cache header
#else
static smt_timer_request_t
        *s_cache = NULL;
#endif

/*  -------------------------------------------------------------------------
    smt_timer_request_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_INITIALISE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_INITIALISE))
    icl_trace_record (NULL, smt_timer_request_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_INITIALISE))
    icl_stats_inc ("smt_timer_request_initialise", &s_smt_timer_request_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_timer_request_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_timer_request_mutex)
            s_smt_timer_request_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_timer_request_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_timer_request_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);
#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_threadkey_private_create (&threadkey, NULL, icl_global_pool));
#endif

            s_smt_timer_request_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_timer_request_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_INITIALISE))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_INITIALISE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_initialise_finish"
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
    smt_timer_request_new

    Type: Component method
    Creates and initialises a new smt_timer_request_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    Initialises the new item to be a valid list item.
    Sets an alarm for a specific time.  When that time is reached, the event
    is delivered, and/or the thread is woken.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    smt_os_thread_t * os_thread,        //  OS thread managing this request
    apr_time_t time,                    //  Time at which to deliver reply
    smt_event_t event                   //  Event to deliver on alarm; SMT_NULL_EVENT for simple thread-blocking
)
{
smt_timer_request_t 
    *insert_point,
    *prev_point;
    smt_timer_request_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_NEW))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" os_thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, os_thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_NEW))
    icl_trace_record (NULL, smt_timer_request_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_NEW))
    icl_stats_inc ("smt_timer_request_new", &s_smt_timer_request_new_stats);
#endif

if (!s_smt_timer_request_active)
    self_initialise ();
self = smt_timer_request_alloc_ (file, line);
if (self) {
    self->object_tag   = SMT_TIMER_REQUEST_ALIVE;

self->by_thread_next = self;
self->by_thread_prev = self;
self->by_thread_head = NULL;
self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == os_thread->apr_os_thread);
#endif

    self->thread         = NULL;
    self->os_thread      = os_thread;
    self->time           = time;
    self->event          = event;
    self->socket_request = NULL;
#if !defined (BASE_THREADSAFE)
    self->expired        = FALSE;
#endif

    //  Start searching from back of list
    insert_point = NULL;
    prev_point = smt_timer_request_list_last (os_thread->timer_request_list);
    while (prev_point
       && (self->time < prev_point->time)) {
        insert_point = prev_point;
        prev_point = smt_timer_request_list_prev (&prev_point);
    }
    if (insert_point)
        smt_timer_request_list_relink_before (self, insert_point);
    else
        smt_timer_request_list_queue (os_thread->timer_request_list, self);

    os_thread->timer_request_count++;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_NEW))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_NEW))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" os_thread=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, os_thread, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_timer_request_annihilate

    Type: Component method
    The purge method is for internal use only.
    
    It destroys a timer request but does not wake a sleeping thread.
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_annihilate (
    smt_timer_request_t * ( * self_p )  //  Reference to object reference
)
{

    smt_timer_request_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_DESTROY))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DESTROY))
    icl_trace_record (NULL, smt_timer_request_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_DESTROY))
    icl_stats_inc ("smt_timer_request_annihilate", &s_smt_timer_request_annihilate_stats);
#endif

SMT_TIMER_REQUEST_ASSERT_SANE (self);
smt_timer_request_remove_from_all_containers (self);

self->os_thread->timer_request_count--;

if (self->event == SMT_NULL_EVENT
&& !self->socket_request
&&  self->thread) {
    assert (self->thread->pending_count);
    icl_atomic_dec32 (&self->thread->pending_count);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DESTROY))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_DESTROY))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_destroy_finish"
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
    smt_timer_request_wakeup

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_wakeup (
    smt_thread_t * thread,              //  Thread to deliver reply to
    apr_time_t time,                    //  Time at which to deliver reply
    smt_event_t event                   //  Event to deliver on alarm; SMT_NULL_EVENT for simple thread-blocking
)
{
int
    rc = SMT_OK;
    smt_timer_request_t *
        request = NULL;                 //  The timer request

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_WAKEUP))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_wakeup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_WAKEUP))
    icl_trace_record (NULL, smt_timer_request_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_WAKEUP))
    icl_stats_inc ("smt_timer_request_wakeup", &s_smt_timer_request_wakeup_stats);
#endif

request = smt_timer_request_new (thread->os_thread, time, event);
if (request) {
    request->thread = thread;
    if (event == SMT_NULL_EVENT)
        icl_atomic_inc32 (&thread->pending_count);

    smt_timer_request_by_thread_queue (thread->timer_request_list, request);
}
else
    rc = SMT_ILLEGAL_ARGUMENT;

if (rc != SMT_OK) {
    thread->result = rc;
    if (event != SMT_NULL_EVENT)
        smt_thread_set_next_event (thread, event);
    thread->catcher (thread);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_WAKEUP))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_WAKEUP))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_wakeup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, request);
#endif


    return (request);
}
/*  -------------------------------------------------------------------------
    smt_timer_request_delay

    Type: Component method
    Set a timer; on timeout, the event is delivered, and/or the thread is woken.
    -------------------------------------------------------------------------
 */

smt_timer_request_t *
    smt_timer_request_delay (
    smt_thread_t * thread,              //  Thread to deliver reply to
    int64_t usecs,                      //  Delay timeout
    smt_event_t event                   //  Event to deliver on timeout; SMT_NULL_EVENT for simple thread-blocking
)
{
apr_time_t time;
    smt_timer_request_t *
        request = NULL;                 //  The timer request

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_DELAY))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_delay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" usecs=\"%lli\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, usecs);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DELAY))
    icl_trace_record (NULL, smt_timer_request_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_DELAY))
    icl_stats_inc ("smt_timer_request_delay", &s_smt_timer_request_delay_stats);
#endif

time = smt_time_now ();
time += usecs;

request = smt_timer_request_wakeup (thread, time, event);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DELAY))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_DELAY))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_delay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" usecs=\"%lli\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, usecs, request);
#endif


    return (request);
}
/*  -------------------------------------------------------------------------
    smt_timer_request_expire_all

    Type: Component method
    This method detects expired timers, activating their corresponding threads.
    It returns TRUE if a timer was expired.
    
    This method is for internal use only.
    -------------------------------------------------------------------------
 */

Bool
    smt_timer_request_expire_all (
    smt_os_thread_t * os_thread,        //  Not documented
    apr_time_t time_now                 //  Not documented
)
{
smt_timer_request_t
    *request,
    *next_request;
smt_socket_request_t
    *socket_request;
smt_event_t
    event;
smt_thread_t
    *thread;
    Bool
        expired = FALSE;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_EXPIRE_ALL))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_expire_all_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" os_thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, os_thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_EXPIRE_ALL))
    icl_trace_record (NULL, smt_timer_request_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_EXPIRE_ALL))
    icl_stats_inc ("smt_timer_request_expire_all", &s_smt_timer_request_expire_all_stats);
#endif

    request = smt_timer_request_list_first (os_thread->timer_request_list);
    while (request
       && (time_now >= request->time)) {
        expired = TRUE;
        next_request = request;
        next_request = smt_timer_request_list_next (&next_request);
        if (request->socket_request) {       //  ie a socket timer      
            //  Take charge of the socket request
            socket_request = request->socket_request;
            //  Set pointer back here to NULL to avoid unwanted recursion.
            socket_request->timer_request = NULL;
            smt_timer_request_destroy (&request);

            smt_socket_request_return (&socket_request,
                                       SMT_TIMEOUT, APR_SUCCESS);
        }
        else {                          //  ie self is a timer request         
            thread = request->thread;
            if (request->event == SMT_NULL_EVENT) {
                if (!request->thread) { //  To implement timed SMT operation
#if (defined (BASE_THREADSAFE))
                    smt_timer_request_destroy (&request);
#else
                    //  Don't destroy timer request if this was a timed SMT
                    //  run; it will be destroyed elsewhere.  Just remove it
                    //  from its containers.
                    request->expired = TRUE;
                    smt_timer_request_remove_from_all_containers (request);
                    smt_request_break ();
#endif
                }
                else {
                    smt_timer_request_destroy (&request);
                    if (thread->pending_count == 0)
                        smt_thread_activate (thread);
                }
            }
            else {
                event    = request->event;
                smt_timer_request_destroy (&request);
                smt_method_send (thread->reply_queue,
                                 event,
                                 SMT_PRIORITY_HIGH,
                                 SMT_OK,
                                 NULL,
                                 NULL);
            }
        }
        request = next_request;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_EXPIRE_ALL))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_EXPIRE_ALL))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_expire_all_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" os_thread=\"%pp\""
" expired=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, os_thread, expired);
#endif


    return (expired);
}
/*  -------------------------------------------------------------------------
    smt_timer_request_first

    Type: Component method
    This method returns the time when the first timer expires,
    or { 0, 0 } if no timers are set.
    
    This method is for internal use only.
    -------------------------------------------------------------------------
 */

apr_time_t
    smt_timer_request_first (
    smt_os_thread_t * os_thread         //  Not documented
)
{
smt_timer_request_t
    *self;
    apr_time_t
        time = 0;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_FIRST))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_first_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" os_thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, os_thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_FIRST))
    icl_trace_record (NULL, smt_timer_request_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_FIRST))
    icl_stats_inc ("smt_timer_request_first", &s_smt_timer_request_first_stats);
#endif

self = smt_timer_request_list_first (os_thread->timer_request_list);
if (self)
    time = self->time;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_FIRST))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_FIRST))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_first_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" os_thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, os_thread);
#endif


    return (time);
}
/*  -------------------------------------------------------------------------
    smt_timer_request_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_SELFTEST))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SELFTEST))
    icl_trace_record (NULL, smt_timer_request_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_SELFTEST))
    icl_stats_inc ("smt_timer_request_selftest", &s_smt_timer_request_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SELFTEST))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_SELFTEST))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_selftest_finish"
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
    smt_timer_request_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_remove_from_all_containers (
    smt_timer_request_t * self          //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, smt_timer_request_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("smt_timer_request_remove_from_all_containers", &s_smt_timer_request_remove_from_all_containers_stats);
#endif

smt_timer_request_list_remove (self);
smt_timer_request_by_thread_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_remove_from_all_containers_finish"
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
    smt_timer_request_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
smt_timer_request_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_SHOW))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SHOW))
    icl_trace_record (NULL, smt_timer_request_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_SHOW))
    icl_stats_inc ("smt_timer_request_show", &s_smt_timer_request_show_stats);
#endif

self = item;
container_links = 0;
if (self->list_head)
   container_links++;
if (self->by_thread_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <smt_timer_request file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SHOW))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_SHOW))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_show_finish"
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
    smt_timer_request_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_TERMINATE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_TERMINATE))
    icl_trace_record (NULL, smt_timer_request_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_TERMINATE))
    icl_stats_inc ("smt_timer_request_terminate", &s_smt_timer_request_terminate_stats);
#endif

if (s_smt_timer_request_active) {
#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_threadkey_private_delete (threadkey));
#endif

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_timer_request_mutex);
#endif
        s_smt_timer_request_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_TERMINATE))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_TERMINATE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_terminate_finish"
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
    smt_timer_request_destroy

    Type: Component method
    Destroys a smt_timer_request_t object. Takes the address of a
    smt_timer_request_t reference (a pointer to a pointer) and nullifies the
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
    smt_timer_request_destroy_ (
    smt_timer_request_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_timer_request_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_DESTROY_PUBLIC))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_timer_request_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_DESTROY_PUBLIC))
    icl_stats_inc ("smt_timer_request_destroy", &s_smt_timer_request_destroy_stats);
#endif

if (self) {
    smt_timer_request_annihilate (self_p);
    smt_timer_request_free ((smt_timer_request_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_DESTROY_PUBLIC))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_destroy_public_finish"
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
    smt_timer_request_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_timer_request_t *
    smt_timer_request_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if (defined (BASE_THREADSAFE))
    smt_timer_request_t
        **s_cache;
    void
        *s_cache_p;
#endif

    smt_timer_request_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_ALLOC))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_ALLOC))
    icl_trace_record (NULL, smt_timer_request_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_ALLOC))
    icl_stats_inc ("smt_timer_request_alloc", &s_smt_timer_request_alloc_stats);
#endif

#if (defined (BASE_THREADSAFE))
    icl_apr_assert (apr_threadkey_private_get (&s_cache_p, threadkey));
    s_cache = s_cache_p;
    if (!s_cache) {
        s_cache = malloc (sizeof (smt_timer_request_t **));
        *s_cache = NULL;
        icl_apr_assert (apr_threadkey_private_set (s_cache, threadkey));
    }
    else
        self = *s_cache;

    if (self) {
        *s_cache = self->local_next;
        self->local_next = NULL;
    }
    else
        self = (smt_timer_request_t *) malloc (sizeof (smt_timer_request_t));
#else
    if (s_cache) {
        self = s_cache;
        s_cache = self->local_next;
        self->local_next = NULL;
    }
    else
        self = (smt_timer_request_t *) malloc (sizeof (smt_timer_request_t));
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_ALLOC))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_ALLOC))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_alloc_finish"
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
    smt_timer_request_free

    Type: Component method
    Freess a smt_timer_request_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_timer_request_free (
    smt_timer_request_t * self          //  Object reference
)
{
#if (defined (BASE_THREADSAFE))
    smt_timer_request_t
        **s_cache;
    void
        *s_cache_p;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_FREE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_FREE))
    icl_trace_record (NULL, smt_timer_request_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_FREE))
    icl_stats_inc ("smt_timer_request_free", &s_smt_timer_request_free_stats);
#endif

if (self) {

        self->object_tag = SMT_TIMER_REQUEST_DEAD;
#if (defined (BASE_THREADSAFE))
        icl_apr_assert (apr_threadkey_private_get (&s_cache_p, threadkey));
        s_cache = s_cache_p;
        self->local_next = *s_cache;
        *s_cache = self;
#else
        self->local_next = s_cache;
        s_cache = self;
#endif
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_FREE))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_FREE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_free_finish"
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
    smt_timer_request_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_SHOW_ANIMATION))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_timer_request_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_SHOW_ANIMATION))
    icl_stats_inc ("smt_timer_request_show_animation", &s_smt_timer_request_show_animation_stats);
#endif

smt_timer_request_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_SHOW_ANIMATION))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_show_animation_finish"
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
    smt_timer_request_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_timer_request_new_in_scope_ (
    smt_timer_request_t * * self_p,     //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    smt_os_thread_t * os_thread,        //  OS thread managing this request
    apr_time_t time,                    //  Time at which to deliver reply
    smt_event_t event                   //  Event to deliver on alarm; SMT_NULL_EVENT for simple thread-blocking
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST)  ||  defined (BASE_ANIMATE_SMT_TIMER_REQUEST_NEW_IN_SCOPE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" os_thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, os_thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_timer_request_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST)  ||  defined (BASE_STATS_SMT_TIMER_REQUEST_NEW_IN_SCOPE))
    icl_stats_inc ("smt_timer_request_new_in_scope", &s_smt_timer_request_new_in_scope_stats);
#endif

*self_p = smt_timer_request_new_ (file,line,os_thread,time,event);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_timer_request_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_timer_request_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST)   || defined (BASE_ANIMATE_SMT_TIMER_REQUEST_NEW_IN_SCOPE))
    if (smt_timer_request_animating)
        icl_console_print ("<smt_timer_request_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" os_thread=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, os_thread, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_INITIALISE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_NEW)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DESTROY)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_WAKEUP)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DELAY)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_EXPIRE_ALL)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_FIRST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SELFTEST)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SHOW)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_TERMINATE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_ALLOC)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_FREE)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_TIMER_REQUEST_NEW_IN_SCOPE) )
void
smt_timer_request_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "initialise"; break;
        case 2: method_name = "new"; break;
        case 3: method_name = "destroy"; break;
        case 4: method_name = "wakeup"; break;
        case 5: method_name = "delay"; break;
        case 6: method_name = "expire all"; break;
        case 7: method_name = "first"; break;
        case 8: method_name = "selftest"; break;
        case 9: method_name = "remove from all containers"; break;
        case 10: method_name = "show"; break;
        case 11: method_name = "terminate"; break;
        case 12: method_name = "destroy public"; break;
        case 13: method_name = "alloc"; break;
        case 14: method_name = "free"; break;
        case 15: method_name = "show animation"; break;
        case 16: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_timer_request %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_timer_request_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_timer_request_component  = "smt_timer_request ";
char *smt_timer_request_version    = "1.0 ";
char *smt_timer_request_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_timer_request_filename   = "smt_timer_request.icl ";
char *smt_timer_request_builddate  = "2009/02/19 ";
char *smt_timer_request_version_end  = "VeRsIoNeNd:ipc";

