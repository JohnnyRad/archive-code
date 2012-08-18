/*---------------------------------------------------------------------------
    smt_method_queue.c - smt_method_queue component

    This class implements the queue container for SMT method queues.
    Generated from smt_method_queue.icl by icl_gen using GSL/4.
    
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
#include "smt_method_queue.h"           //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_method_queue_t

//  Shorthands for class methods                                               

#define self_new            smt_method_queue_new
#define self_sync_new       smt_method_queue_sync_new
#define self_wait           smt_method_queue_wait
#define self_isempty        smt_method_queue_isempty
#define self_trigger        smt_method_queue_trigger
#define self_register       smt_method_queue_register
#define self_annihilate     smt_method_queue_annihilate
#define self_free           smt_method_queue_free
#define self_selftest       smt_method_queue_selftest
#define self_pop            smt_method_queue_pop
#define self_queue          smt_method_queue_queue
#define self_terminate      smt_method_queue_terminate
#define self_show           smt_method_queue_show
#define self_destroy        smt_method_queue_destroy
#define self_alloc          smt_method_queue_alloc
#define self_link           smt_method_queue_link
#define self_unlink         smt_method_queue_unlink
#define self_cache_initialise  smt_method_queue_cache_initialise
#define self_cache_purge    smt_method_queue_cache_purge
#define self_cache_terminate  smt_method_queue_cache_terminate
#define self_show_animation  smt_method_queue_show_animation
#define self_new_in_scope   smt_method_queue_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_NEW))
static icl_stats_t *s_smt_method_queue_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SYNC_NEW))
static icl_stats_t *s_smt_method_queue_sync_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_WAIT))
static icl_stats_t *s_smt_method_queue_wait_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_ISEMPTY))
static icl_stats_t *s_smt_method_queue_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_TRIGGER))
static icl_stats_t *s_smt_method_queue_trigger_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_REGISTER))
static icl_stats_t *s_smt_method_queue_register_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_DESTROY))
static icl_stats_t *s_smt_method_queue_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_FREE))
static icl_stats_t *s_smt_method_queue_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SELFTEST))
static icl_stats_t *s_smt_method_queue_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_POP))
static icl_stats_t *s_smt_method_queue_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_QUEUE))
static icl_stats_t *s_smt_method_queue_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_TERMINATE))
static icl_stats_t *s_smt_method_queue_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SHOW))
static icl_stats_t *s_smt_method_queue_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_DESTROY_PUBLIC))
static icl_stats_t *s_smt_method_queue_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_ALLOC))
static icl_stats_t *s_smt_method_queue_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_LINK))
static icl_stats_t *s_smt_method_queue_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_UNLINK))
static icl_stats_t *s_smt_method_queue_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_CACHE_INITIALISE))
static icl_stats_t *s_smt_method_queue_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_CACHE_PURGE))
static icl_stats_t *s_smt_method_queue_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_CACHE_TERMINATE))
static icl_stats_t *s_smt_method_queue_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SHOW_ANIMATION))
static icl_stats_t *s_smt_method_queue_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_NEW_IN_SCOPE))
static icl_stats_t *s_smt_method_queue_new_in_scope_stats = NULL;
#endif
#define smt_method_queue_annihilate(self)  smt_method_queue_annihilate_ (self, __FILE__, __LINE__)
static void
    smt_method_queue_annihilate_ (
smt_method_queue_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_method_queue_free(self)     smt_method_queue_free_ (self, __FILE__, __LINE__)
static void
    smt_method_queue_free_ (
smt_method_queue_t * self,              //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_method_queue_alloc()        smt_method_queue_alloc_ (__FILE__, __LINE__)
static smt_method_queue_t *
    smt_method_queue_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_method_queue_cache_initialise (
void);

static void
    smt_method_queue_cache_purge (
void);

static void
    smt_method_queue_cache_terminate (
void);

Bool
    smt_method_queue_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_method_queue_new

    Type: Component method
    Creates and initialises a new smt_method_queue_t object, returns a
    reference to the created object.
    Creates a simple method queue without synchrononisation methods.
    -------------------------------------------------------------------------
 */

smt_method_queue_t *
    smt_method_queue_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_method_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_NEW))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_NEW))
    icl_trace_record (NULL, smt_method_queue_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_NEW))
    icl_stats_inc ("smt_method_queue_new", &s_smt_method_queue_new_stats);
#endif

    self = smt_method_queue_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_METHOD_QUEUE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_method_queue_show_);
#endif

#if (defined (BASE_THREADSAFE))
    self->mutex = icl_mutex_new ();
#endif

    self->head = NULL;
    self->tail = NULL;

    self->count = 0;

    self->notify = NULL;
    self->data   = NULL;
#if (defined (BASE_THREADSAFE))
    self->sync_mutex    = NULL;
    self->sync_cond     = NULL;
    self->sync_wait_cnt = 0;
#else
    self->sync = FALSE;
#endif
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_NEW))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_NEW))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_new_finish"
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
    smt_method_queue_sync_new

    Type: Component method
    Creates and initialises a new smt_method_queue_t object, returns a
    reference to the created object.
    Creates a method queue with synchrononisation methods (wait and trigger).
    -------------------------------------------------------------------------
 */

smt_method_queue_t *
    smt_method_queue_sync_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_method_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SYNC_NEW))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_sync_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SYNC_NEW))
    icl_trace_record (NULL, smt_method_queue_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SYNC_NEW))
    icl_stats_inc ("smt_method_queue_sync_new", &s_smt_method_queue_sync_new_stats);
#endif

    self = smt_method_queue_new ();
#if (defined (BASE_THREADSAFE))
    self->sync_mutex = icl_mutex_new ();
    self->sync_cond  = icl_cond_new ();
#else
    self->sync = TRUE;
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SYNC_NEW))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SYNC_NEW))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_sync_new_finish"
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
    smt_method_queue_wait

    Type: Component method
    Accepts a smt_method_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Wait until the method queue gets triggered or timeout occurs.

    In a multi-thread environment this means waiting on the thread's
    condition variable.  The trigger method will signal that condition
    variable, allowing this method to terminate.

    In a single-thread environment this means running the SMT engine as long
    as it wants to run.  The trigger method will signal to SMT that it's time
    to stop, allowing this method to terminate.

    The method returns zero if an event arrived or the request timed out
    and -1 if the queue was destroyed.
    -------------------------------------------------------------------------
 */

int
    smt_method_queue_wait (
    smt_method_queue_t * self,          //  Reference to object
    qbyte msecs                         //  Timeout for wait
)
{
    int64_t
        usecs = msecs * 1000;
#if defined (BASE_THREADSAFE)
    int
        wait_rc = 0;
    apr_time_t
        time_at_call = 0,
        time_at_return;
#else
    smt_timer_request_t
        *timer_request = NULL;
#endif
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_WAIT))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_wait_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" msecs=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, msecs);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_WAIT))
    icl_trace_record (NULL, smt_method_queue_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_WAIT))
    icl_stats_inc ("smt_method_queue_wait", &s_smt_method_queue_wait_stats);
#endif

SMT_METHOD_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

#if defined (BASE_THREADSAFE)
    assert (self->sync_mutex);

    //  First check that we can't return immediately without placing lock
    if (smt_method_queue_isempty (self)) {
        icl_mutex_lock (self->sync_mutex);

        while (!self->zombie
           &&  smt_method_queue_isempty (self)
           &&  !wait_rc) {
            self->sync_wait_cnt++;
            if (usecs) {
                time_at_return = smt_time_now ();
                if (time_at_call != 0)  //  Not first time through
                    usecs -= (time_at_return - time_at_call);
                if (usecs > 0) {
                    time_at_call = time_at_return;
                    wait_rc = icl_cond_timed_wait (self->sync_cond, self->sync_mutex, usecs);
                }
                else
                    wait_rc = APR_TIMEUP;
            }
            else
                icl_cond_wait (self->sync_cond, self->sync_mutex);

            self->sync_wait_cnt--;
        }
        icl_mutex_unlock (self->sync_mutex);
    }
#else
    assert (self->sync);

    if (usecs)
        timer_request = smt_timer_request_new (smt_os_thread, 
                                               smt_time_now () + usecs,
                                               SMT_NULL_EVENT);
    while (!self->zombie
       &&  smt_method_queue_isempty (self)) {
        smt_wait (0);
        if (timer_request
        &&  timer_request->expired) {
            rc = SMT_TIMEOUT;
            break;
        }
    }
    if (timer_request)
        smt_timer_request_destroy (&timer_request);
#endif
    if (self->zombie)
        rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_WAIT))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_WAIT))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_wait_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" msecs=\"%lu\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, msecs, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_method_queue_isempty

    Type: Component method
    Accepts a smt_method_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    smt_method_queue_isempty (
    smt_method_queue_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_ISEMPTY))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_ISEMPTY))
    icl_trace_record (NULL, smt_method_queue_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_ISEMPTY))
    icl_stats_inc ("smt_method_queue_isempty", &s_smt_method_queue_isempty_stats);
#endif

SMT_METHOD_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->count == 0);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_ISEMPTY))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_ISEMPTY))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_isempty_finish"
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
    smt_method_queue_trigger

    Type: Component method
    Accepts a smt_method_queue_t reference and returns zero in case of success,
    1 in case of errors.
    Trigger the queue.  See the description of the 'wait' method.
    -------------------------------------------------------------------------
 */

int
    smt_method_queue_trigger (
    smt_method_queue_t * self,          //  Reference to object
    smt_method_queue_notify_t event     //  What kind of trigger is this?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_TRIGGER))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_trigger_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_TRIGGER))
    icl_trace_record (NULL, smt_method_queue_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_TRIGGER))
    icl_stats_inc ("smt_method_queue_trigger", &s_smt_method_queue_trigger_stats);
#endif

SMT_METHOD_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

    //  Call registered notify callback.
    if (self->notify)
        (self->notify) (self->data, event);

    //  Do thread synchronisation.                                             
#if defined (BASE_THREADSAFE)
    if (self->sync_mutex) {
        icl_mutex_lock    (self->sync_mutex);
        if (self->sync_wait_cnt)
            icl_cond_signal (self->sync_cond);
        icl_mutex_unlock  (self->sync_mutex);
    }
#else
    if (self->sync)
        smt_request_break ();
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_TRIGGER))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_TRIGGER))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_trigger_finish"
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
    smt_method_queue_register

    Type: Component method
    Accepts a smt_method_queue_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_method_queue_register (
    smt_method_queue_t * self,          //  Reference to object
    smt_method_queue_notify_fn * notify,   //  Function to call on arrival
    void * data                         //  Data for notify
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_REGISTER))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_register_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" notify=\"%pp\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, notify, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_REGISTER))
    icl_trace_record (NULL, smt_method_queue_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_REGISTER))
    icl_stats_inc ("smt_method_queue_register", &s_smt_method_queue_register_stats);
#endif

SMT_METHOD_QUEUE_ASSERT_SANE (self);
if (!self->zombie) {

self->notify = notify;
self->data   = data;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_REGISTER))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_REGISTER))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_register_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" notify=\"%pp\""
" data=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, notify, data, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_method_queue_annihilate

    Type: Component method
    Destroys the queue and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    smt_method_queue_annihilate_ (
    smt_method_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    int
        history_last;
#endif

    smt_method_t
        *item;
#if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#endif
    smt_method_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_DESTROY))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_DESTROY))
    icl_trace_record (NULL, smt_method_queue_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_DESTROY))
    icl_stats_inc ("smt_method_queue_annihilate", &s_smt_method_queue_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = self->links;
#endif

    SMT_METHOD_QUEUE_ASSERT_SANE (self);

#if defined (BASE_THREADSAFE)
    mutex = self->mutex;
    if (mutex)
         icl_mutex_lock (mutex);
#endif


    item = (smt_method_t *) self->head;
    while (item != NULL) {
        //  Unlink child without lock (we already have the lock)               
        self->head = item->queue_next;

        smt_method_unlink (&item);
        item = (smt_method_t *) self->head;
    }
smt_method_queue_trigger (self, SMT_METHOD_QUEUE_DESTROY);
#if defined (BASE_THREADSAFE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_DESTROY))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_DESTROY))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

}
/*  -------------------------------------------------------------------------
    smt_method_queue_free

    Type: Component method
    Freess a smt_method_queue_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_method_queue_free_ (
    smt_method_queue_t * self,          //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_FREE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_FREE))
    icl_trace_record (NULL, smt_method_queue_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_FREE))
    icl_stats_inc ("smt_method_queue_free", &s_smt_method_queue_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = self->links;
#endif

#if defined (BASE_THREADSAFE)
    //  Get and release lock before destroying.  Otherwise we may clash        
    //  with another thread.                                                   
    if (self->sync_mutex) {
        icl_mutex_lock    (self->sync_mutex);
        icl_mutex_unlock  (self->sync_mutex);
        icl_mutex_destroy (&self->sync_mutex);

        icl_cond_destroy  (&self->sync_cond);
    }
#endif
#if defined (BASE_THREADSAFE)
    if (self->mutex)
        icl_mutex_destroy (&self->mutex);
#endif
    self->object_tag = SMT_METHOD_QUEUE_DEAD;
    icl_mem_free (self);
}
self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_FREE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_FREE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    smt_method_queue_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_method_queue_selftest (
void)
{
smt_method_queue_t *self;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SELFTEST))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SELFTEST))
    icl_trace_record (NULL, smt_method_queue_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SELFTEST))
    icl_stats_inc ("smt_method_queue_selftest", &s_smt_method_queue_selftest_stats);
#endif

self = smt_method_queue_new ();
smt_method_queue_destroy (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SELFTEST))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SELFTEST))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_selftest_finish"
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
    smt_method_queue_pop

    Type: Component method
    Removes the next item in the queue, if any, and returns it.  If
    the queue was empty, returns NULL.
    
    The number of links is unchanged; removing from the queue and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

smt_method_t *
    smt_method_queue_pop (
    smt_method_queue_t * self           //  The queue
)
{
#if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#endif
    smt_method_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_POP))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_POP))
    icl_trace_record (NULL, smt_method_queue_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_POP))
    icl_stats_inc ("smt_method_queue_pop", &s_smt_method_queue_pop_stats);
#endif

    SMT_METHOD_QUEUE_ASSERT_SANE (self);
#if defined (BASE_THREADSAFE)
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

    if (!self->zombie) {
        item = (smt_method_t *) self->head;
        if (item) {
            self->head = item->queue_next;
            if (self->head == NULL)
                self->tail = NULL;
            item->queue_next = NULL;
            item->queue_head = NULL;
        }

        if (item) {
            icl_atomic_dec32 (&self->count);
        }
    }

#if defined (BASE_THREADSAFE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_POP))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_POP))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_pop_finish"
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
    smt_method_queue_queue

    Type: Component method
    Attaches the item to the end of the specified queue.  The item may not
    be in a queue of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the queue, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    smt_method_queue_queue (
    smt_method_queue_t * self,          //  Reference to object
    smt_method_t * item                 //  Not documented
)
{
#if defined (BASE_THREADSAFE)
    icl_mutex_t
        *mutex;
#endif
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_QUEUE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_QUEUE))
    icl_trace_record (NULL, smt_method_queue_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_QUEUE))
    icl_stats_inc ("smt_method_queue_queue", &s_smt_method_queue_queue_stats);
#endif

#if defined (BASE_THREADSAFE)
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

    SMT_METHOD_QUEUE_ASSERT_SANE (self);
    if (!self->zombie) {

        if (! item->queue_head) {
            smt_method_link (item);

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
            icl_console_print ("E: smt_method item inserted into multiple queue containers");
            assert (item->queue_head == NULL);
        }

        icl_atomic_inc32 (&self->count);

    }
    else
        rc = -1;

#if defined (BASE_THREADSAFE)
    if (mutex)
        icl_mutex_unlock (mutex);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_QUEUE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_QUEUE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_queue_finish"
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
    smt_method_queue_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_method_queue_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_TERMINATE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_TERMINATE))
    icl_trace_record (NULL, smt_method_queue_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_TERMINATE))
    icl_stats_inc ("smt_method_queue_terminate", &s_smt_method_queue_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_TERMINATE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_TERMINATE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_terminate_finish"
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
    smt_method_queue_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_method_queue_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_method_queue_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SHOW))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SHOW))
    icl_trace_record (NULL, smt_method_queue_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SHOW))
    icl_stats_inc ("smt_method_queue_show", &s_smt_method_queue_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_method_queue zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    if (self->history_last > SMT_METHOD_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_METHOD_QUEUE_HISTORY_LENGTH;
        self->history_last %= SMT_METHOD_QUEUE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_METHOD_QUEUE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_method_queue>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SHOW))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SHOW))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_show_finish"
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
    smt_method_queue_destroy

    Type: Component method
    Destroys a smt_method_queue_t object. Takes the address of a
    smt_method_queue_t reference (a pointer to a pointer) and nullifies the
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
    smt_method_queue_destroy_ (
    smt_method_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_method_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_DESTROY_PUBLIC))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_method_queue_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_DESTROY_PUBLIC))
    icl_stats_inc ("smt_method_queue_destroy", &s_smt_method_queue_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        smt_method_queue_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on smt_method_queue object");
        smt_method_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_method_queue_free_ ((smt_method_queue_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_DESTROY_PUBLIC))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    smt_method_queue_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_method_queue_t *
    smt_method_queue_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_method_queue_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_ALLOC))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_ALLOC))
    icl_trace_record (NULL, smt_method_queue_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_ALLOC))
    icl_stats_inc ("smt_method_queue_alloc", &s_smt_method_queue_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_method_queue_cache_initialise ();

self = (smt_method_queue_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_ALLOC))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_ALLOC))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_alloc_finish"
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
    smt_method_queue_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_method_queue_t *
    smt_method_queue_link_ (
    smt_method_queue_t * self,          //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_LINK))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_LINK))
    icl_trace_record (NULL, smt_method_queue_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_LINK))
    icl_stats_inc ("smt_method_queue_link", &s_smt_method_queue_link_stats);
#endif

    if (self) {
        SMT_METHOD_QUEUE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_LINK))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_LINK))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_method_queue_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_method_queue_unlink_ (
    smt_method_queue_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
    int
        history_last;
#endif

    smt_method_queue_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_UNLINK))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_UNLINK))
    icl_trace_record (NULL, smt_method_queue_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_UNLINK))
    icl_stats_inc ("smt_method_queue_unlink", &s_smt_method_queue_unlink_stats);
#endif

    if (self) {
        SMT_METHOD_QUEUE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_method_queue object");
            smt_method_queue_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_METHOD_QUEUE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_METHOD_QUEUE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            smt_method_queue_annihilate_ (self_p, file, line);
        smt_method_queue_free_ ((smt_method_queue_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_UNLINK))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_UNLINK))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    smt_method_queue_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_method_queue_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_CACHE_INITIALISE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_method_queue_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_CACHE_INITIALISE))
    icl_stats_inc ("smt_method_queue_cache_initialise", &s_smt_method_queue_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_method_queue_t));
icl_system_register (smt_method_queue_cache_purge, smt_method_queue_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_CACHE_INITIALISE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_cache_initialise_finish"
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
    smt_method_queue_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_method_queue_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_CACHE_PURGE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_PURGE))
    icl_trace_record (NULL, smt_method_queue_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_CACHE_PURGE))
    icl_stats_inc ("smt_method_queue_cache_purge", &s_smt_method_queue_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_PURGE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_CACHE_PURGE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_cache_purge_finish"
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
    smt_method_queue_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_method_queue_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_CACHE_TERMINATE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_method_queue_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_CACHE_TERMINATE))
    icl_stats_inc ("smt_method_queue_cache_terminate", &s_smt_method_queue_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_CACHE_TERMINATE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_cache_terminate_finish"
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
    smt_method_queue_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_method_queue_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SHOW_ANIMATION))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_method_queue_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_SHOW_ANIMATION))
    icl_stats_inc ("smt_method_queue_show_animation", &s_smt_method_queue_show_animation_stats);
#endif

smt_method_queue_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_SHOW_ANIMATION))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_show_animation_finish"
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
    smt_method_queue_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_method_queue_new_in_scope_ (
    smt_method_queue_t * * self_p,      //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE)  ||  defined (BASE_ANIMATE_SMT_METHOD_QUEUE_NEW_IN_SCOPE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_method_queue_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE)  ||  defined (BASE_STATS_SMT_METHOD_QUEUE_NEW_IN_SCOPE))
    icl_stats_inc ("smt_method_queue_new_in_scope", &s_smt_method_queue_new_in_scope_stats);
#endif

*self_p = smt_method_queue_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_method_queue_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_method_queue_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE)   || defined (BASE_ANIMATE_SMT_METHOD_QUEUE_NEW_IN_SCOPE))
    if (smt_method_queue_animating)
        icl_console_print ("<smt_method_queue_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_NEW)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SYNC_NEW)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_WAIT)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_ISEMPTY)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_TRIGGER)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_REGISTER)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_DESTROY)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_FREE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SELFTEST)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_POP)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_QUEUE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_TERMINATE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SHOW)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_ALLOC)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_LINK)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_UNLINK)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_PURGE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_METHOD_QUEUE_NEW_IN_SCOPE) )
void
smt_method_queue_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "sync new"; break;
        case 3: method_name = "wait"; break;
        case 4: method_name = "isempty"; break;
        case 5: method_name = "trigger"; break;
        case 6: method_name = "register"; break;
        case 7: method_name = "destroy"; break;
        case 8: method_name = "free"; break;
        case 9: method_name = "selftest"; break;
        case 10: method_name = "pop"; break;
        case 11: method_name = "queue"; break;
        case 12: method_name = "terminate"; break;
        case 13: method_name = "show"; break;
        case 14: method_name = "destroy public"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "link"; break;
        case 17: method_name = "unlink"; break;
        case 18: method_name = "cache initialise"; break;
        case 19: method_name = "cache purge"; break;
        case 20: method_name = "cache terminate"; break;
        case 21: method_name = "show animation"; break;
        case 22: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_method_queue %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_method_queue_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_method_queue_component   = "smt_method_queue ";
char *smt_method_queue_version     = "1.0 ";
char *smt_method_queue_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_method_queue_filename    = "smt_method_queue.icl ";
char *smt_method_queue_builddate   = "2009/02/19 ";
char *smt_method_queue_version_end  = "VeRsIoNeNd:ipc";

