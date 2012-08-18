/*---------------------------------------------------------------------------
    smt_signal.c - smt_signal component

    The smt_signal class is used to manage signal handlers in an SMT
    application.
    Generated from smt_signal.icl by icl_gen using GSL/4.
    
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
#include "smt_signal.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_signal_t

//  Shorthands for class methods                                               

#define self_initialise     smt_signal_initialise
#define self_terminate      smt_signal_terminate
#define self_new            smt_signal_new
#define self_annihilate     smt_signal_annihilate
#define self_register       smt_signal_register
#define self_register_shut_down  smt_signal_register_shut_down
#define self_deregister     smt_signal_deregister
#define self_handler        smt_signal_handler
#define self_selftest       smt_signal_selftest
#define self_remove_from_all_containers  smt_signal_remove_from_all_containers
#define self_show           smt_signal_show
#define self_destroy        smt_signal_destroy
#define self_alloc          smt_signal_alloc
#define self_free           smt_signal_free
#define self_read_lock      smt_signal_read_lock
#define self_write_lock     smt_signal_write_lock
#define self_unlock         smt_signal_unlock
#define self_cache_initialise  smt_signal_cache_initialise
#define self_cache_purge    smt_signal_cache_purge
#define self_cache_terminate  smt_signal_cache_terminate
#define self_show_animation  smt_signal_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_INITIALISE))
static icl_stats_t *s_smt_signal_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_TERMINATE))
static icl_stats_t *s_smt_signal_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_NEW))
static icl_stats_t *s_smt_signal_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_DESTROY))
static icl_stats_t *s_smt_signal_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_REGISTER))
static icl_stats_t *s_smt_signal_register_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_REGISTER_SHUT_DOWN))
static icl_stats_t *s_smt_signal_register_shut_down_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_DEREGISTER))
static icl_stats_t *s_smt_signal_deregister_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_HANDLER))
static icl_stats_t *s_smt_signal_handler_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_SELFTEST))
static icl_stats_t *s_smt_signal_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_smt_signal_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_SHOW))
static icl_stats_t *s_smt_signal_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_DESTROY_PUBLIC))
static icl_stats_t *s_smt_signal_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_ALLOC))
static icl_stats_t *s_smt_signal_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_FREE))
static icl_stats_t *s_smt_signal_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_READ_LOCK))
static icl_stats_t *s_smt_signal_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_WRITE_LOCK))
static icl_stats_t *s_smt_signal_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_UNLOCK))
static icl_stats_t *s_smt_signal_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_CACHE_INITIALISE))
static icl_stats_t *s_smt_signal_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_CACHE_PURGE))
static icl_stats_t *s_smt_signal_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_CACHE_TERMINATE))
static icl_stats_t *s_smt_signal_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_SHOW_ANIMATION))
static icl_stats_t *s_smt_signal_show_animation_stats = NULL;
#endif
static void
    smt_signal_terminate (
void);

#define smt_signal_new(table,key)       smt_signal_new_ (__FILE__, __LINE__, table, key)
static smt_signal_t *
    smt_signal_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
smt_signal_table_t * table,             //  Table to insert into
int key                                 //  Hash key
);

static void
    smt_signal_annihilate (
smt_signal_t * ( * self_p )             //  Reference to object reference
);

static void
    smt_signal_handler (
int the_signal                          //  Not documented
);

#define smt_signal_alloc()              smt_signal_alloc_ (__FILE__, __LINE__)
static smt_signal_t *
    smt_signal_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_signal_free (
smt_signal_t * self                     //  Object reference
);

static void
    smt_signal_cache_initialise (
void);

static void
    smt_signal_cache_purge (
void);

static void
    smt_signal_cache_terminate (
void);

Bool
    smt_signal_animating = TRUE;        //  Animation enabled by default
static Bool
    s_smt_signal_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_signal_mutex       = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


smt_thread_t
    *s_signal_thread;                   //  Only one thread may receive signals

smt_signal_table_t
    *s_signal_table;
/*  -------------------------------------------------------------------------
    smt_signal_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_INITIALISE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_INITIALISE))
    icl_trace_record (NULL, smt_signal_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_INITIALISE))
    icl_stats_inc ("smt_signal_initialise", &s_smt_signal_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_signal_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_signal_mutex)
            s_smt_signal_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_signal_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_signal_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_signal_thread = NULL;
s_signal_table  = smt_signal_table_new ();
            s_smt_signal_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_signal_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_INITIALISE))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_INITIALISE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_initialise_finish"
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
    smt_signal_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TERMINATE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_TERMINATE))
    icl_trace_record (NULL, smt_signal_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_TERMINATE))
    icl_stats_inc ("smt_signal_terminate", &s_smt_signal_terminate_stats);
#endif

if (s_smt_signal_active) {

smt_signal_table_destroy (&s_signal_table);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_signal_mutex);
#endif
        s_smt_signal_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_TERMINATE))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_TERMINATE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_terminate_finish"
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
    smt_signal_new

    Type: Component method
    Creates and initialises a new smt_signal_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

static smt_signal_t *
    smt_signal_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    smt_signal_table_t * table,         //  Table to insert into
    int key                             //  Hash key
)
{
    smt_signal_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_NEW))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_NEW))
    icl_trace_record (NULL, smt_signal_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_NEW))
    icl_stats_inc ("smt_signal_new", &s_smt_signal_new_stats);
#endif

if (!s_smt_signal_active)
    self_initialise ();
    self = smt_signal_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_SIGNAL_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_signal_show_);
#endif

self->by_thread_next = self;
self->by_thread_prev = self;
self->by_thread_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->event = SMT_NULL_EVENT;
if (table && self && smt_signal_table_insert (table, key, self))
    smt_signal_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_NEW))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_NEW))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_signal_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_annihilate (
    smt_signal_t * ( * self_p )         //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

int                                 //  Need to save key value because it
    the_signal = (*self_p)->key;    //  gets lost on removal from table.
    smt_signal_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_DESTROY))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_DESTROY))
    icl_trace_record (NULL, smt_signal_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_DESTROY))
    icl_stats_inc ("smt_signal_annihilate", &s_smt_signal_annihilate_stats);
#endif

    SMT_SIGNAL_ASSERT_SANE (self);
    smt_signal_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

if (the_signal)                     //  Will be zero when purging signals
    signal (the_signal, SIG_DFL);

//  If thread no longer has any signals registered, reset s_signal_thread
if (s_signal_thread
&&  smt_signal_by_thread_isempty (s_signal_thread->signal_list))
    s_signal_thread = NULL;
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_DESTROY))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_DESTROY))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_destroy_finish"
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
    smt_signal_register

    Type: Component method
    Register a signal handler.  Upon receipt of the_signal, SMT will deliver
    the requested event to the specified thread.  If the signal was already
    registered by a different thread, returns -1.
    -------------------------------------------------------------------------
 */

int
    smt_signal_register (
    int the_signal,                     //  The signal to register
    smt_thread_t * thread,              //  The thread to register the signal with
    smt_event_t event                   //  The event to be sent on signal
)
{
smt_signal_t
    *self;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_REGISTER))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_register_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_REGISTER))
    icl_trace_record (NULL, smt_signal_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_REGISTER))
    icl_stats_inc ("smt_signal_register", &s_smt_signal_register_stats);
#endif

if (!s_smt_signal_active)
    self_initialise ();
if (!s_signal_thread) {
    s_signal_thread = thread;
    if (!thread->signal_list)
        thread->signal_list = smt_signal_by_thread_new ();
}
else
if (thread != s_signal_thread)
    rc = -1;
else
if (event == SMT_NULL_EVENT) {
    icl_console_print ("Event must be provided in signal registration.");
    rc = -1;
}
if (!rc) {
    //  Find or create a signal entry.
    self = smt_signal_table_search (s_signal_table, the_signal);
    if (!self)
        self = smt_signal_new (s_signal_table, the_signal);

    if (self->event == SMT_NULL_EVENT)          
        smt_signal_by_thread_queue (thread->signal_list, self);

    self->event = event;

    //  And register the signal handler.
    signal (the_signal, smt_signal_handler);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_REGISTER))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_REGISTER))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_register_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
" thread=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal, thread, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_signal_register_shut_down

    Type: Component method
    Register a shutdown signal.  Upon receipt of the_signal, SMT will proceed
    with a graceful shutdown of the application by sending a shutdown event to
    all agents.
    -------------------------------------------------------------------------
 */

void
    smt_signal_register_shut_down (
    int the_signal                      //  The signal to register
)
{
smt_signal_t
    *self;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_REGISTER_SHUT_DOWN))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_register_shut_down_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_REGISTER_SHUT_DOWN))
    icl_trace_record (NULL, smt_signal_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_REGISTER_SHUT_DOWN))
    icl_stats_inc ("smt_signal_register_shut_down", &s_smt_signal_register_shut_down_stats);
#endif

if (!s_smt_signal_active)
    self_initialise ();
//  Check whether signal is already registered with some thread
self = smt_signal_table_search (s_signal_table, the_signal);
if (!self)
    self = smt_signal_new (s_signal_table, the_signal);

if (self->event != SMT_NULL_EVENT)
    smt_signal_by_thread_remove (self);

self->event = SMT_NULL_EVENT;

//  And register the signal handler.
signal (the_signal, smt_signal_handler);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_REGISTER_SHUT_DOWN))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_REGISTER_SHUT_DOWN))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_register_shut_down_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal);
#endif

}
/*  -------------------------------------------------------------------------
    smt_signal_deregister

    Type: Component method
    Deregister the specified shutdown signal.
    -------------------------------------------------------------------------
 */

void
    smt_signal_deregister (
    int the_signal                      //  The signal to deregister
)
{
smt_signal_t
    *self;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_DEREGISTER))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_deregister_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_DEREGISTER))
    icl_trace_record (NULL, smt_signal_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_DEREGISTER))
    icl_stats_inc ("smt_signal_deregister", &s_smt_signal_deregister_stats);
#endif

if (!s_smt_signal_active)
    self_initialise ();
//  Check whether signal is already registered with some thread
self = smt_signal_table_search (s_signal_table, the_signal);
if (self)
    smt_signal_destroy (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_DEREGISTER))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_DEREGISTER))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_deregister_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal);
#endif

}
/*  -------------------------------------------------------------------------
    smt_signal_handler

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_handler (
    int the_signal                      //  Not documented
)
{
smt_signal_t
    *self;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_HANDLER))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_handler_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_HANDLER))
    icl_trace_record (NULL, smt_signal_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_HANDLER))
    icl_stats_inc ("smt_signal_handler", &s_smt_signal_handler_stats);
#endif

//  If signal table doesn't exist then we do nothing.
//
if (s_signal_table) {
    self = smt_signal_table_search (s_signal_table, the_signal);

    //  Check that signal is still registered.  Can happen that signal
    //  is delivered to a thread after another thread has deregistered it.
    if (self) {
        //  See whether this is an event or shutdown signal.
        if (self->event != SMT_NULL_EVENT) {
            s_signal_thread->signal_raised = TRUE;
            s_signal_thread->signal_event  = self->event;
            smt_thread_wake (s_signal_thread);
        }
        else {
            //  Set flags so that running threads will notice.
            smt_signal_raised = TRUE;
            smt_break_requested = TRUE;
            smt_os_thread_wake (smt_os_thread);
        }
        //  Re-register the signal, seems to be needed on some systems
        signal (the_signal, smt_signal_handler);
    }
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_HANDLER))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_HANDLER))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_handler_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" the_signal=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, the_signal);
#endif

}
/*  -------------------------------------------------------------------------
    smt_signal_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_SELFTEST))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_SELFTEST))
    icl_trace_record (NULL, smt_signal_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_SELFTEST))
    icl_stats_inc ("smt_signal_selftest", &s_smt_signal_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_SELFTEST))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_SELFTEST))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_selftest_finish"
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
    smt_signal_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    smt_signal_remove_from_all_containers (
    smt_signal_t * self                 //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, smt_signal_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("smt_signal_remove_from_all_containers", &s_smt_signal_remove_from_all_containers_stats);
#endif

SMT_SIGNAL_ASSERT_SANE (self);
smt_signal_table_remove (self);
smt_signal_by_thread_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_remove_from_all_containers_finish"
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
    smt_signal_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
smt_signal_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_SHOW))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_SHOW))
    icl_trace_record (NULL, smt_signal_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_SHOW))
    icl_stats_inc ("smt_signal_show", &s_smt_signal_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->by_thread_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <smt_signal file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_SHOW))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_SHOW))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_show_finish"
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
    smt_signal_destroy

    Type: Component method
    Destroys a smt_signal_t object. Takes the address of a
    smt_signal_t reference (a pointer to a pointer) and nullifies the
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
    smt_signal_destroy_ (
    smt_signal_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_signal_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_DESTROY_PUBLIC))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_signal_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_DESTROY_PUBLIC))
    icl_stats_inc ("smt_signal_destroy", &s_smt_signal_destroy_stats);
#endif

if (self) {
    smt_signal_annihilate (self_p);
    smt_signal_free ((smt_signal_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_DESTROY_PUBLIC))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_destroy_public_finish"
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
    smt_signal_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_signal_t *
    smt_signal_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_signal_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_ALLOC))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_ALLOC))
    icl_trace_record (NULL, smt_signal_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_ALLOC))
    icl_stats_inc ("smt_signal_alloc", &s_smt_signal_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_signal_cache_initialise ();

self = (smt_signal_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_ALLOC))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_ALLOC))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_alloc_finish"
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
    smt_signal_free

    Type: Component method
    Freess a smt_signal_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_signal_free (
    smt_signal_t * self                 //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_FREE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_FREE))
    icl_trace_record (NULL, smt_signal_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_FREE))
    icl_stats_inc ("smt_signal_free", &s_smt_signal_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        self->object_tag = SMT_SIGNAL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_FREE))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_FREE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_free_finish"
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
    smt_signal_read_lock

    Type: Component method
    Accepts a smt_signal_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_signal_read_lock (
    smt_signal_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_READ_LOCK))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_READ_LOCK))
    icl_trace_record (NULL, smt_signal_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_READ_LOCK))
    icl_stats_inc ("smt_signal_read_lock", &s_smt_signal_read_lock_stats);
#endif

SMT_SIGNAL_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_READ_LOCK))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_READ_LOCK))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_read_lock_finish"
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
    smt_signal_write_lock

    Type: Component method
    Accepts a smt_signal_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_signal_write_lock (
    smt_signal_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_WRITE_LOCK))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_WRITE_LOCK))
    icl_trace_record (NULL, smt_signal_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_WRITE_LOCK))
    icl_stats_inc ("smt_signal_write_lock", &s_smt_signal_write_lock_stats);
#endif

SMT_SIGNAL_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_WRITE_LOCK))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_WRITE_LOCK))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_write_lock_finish"
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
    smt_signal_unlock

    Type: Component method
    Accepts a smt_signal_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_signal_unlock (
    smt_signal_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_UNLOCK))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_UNLOCK))
    icl_trace_record (NULL, smt_signal_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_UNLOCK))
    icl_stats_inc ("smt_signal_unlock", &s_smt_signal_unlock_stats);
#endif

SMT_SIGNAL_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_UNLOCK))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_UNLOCK))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_unlock_finish"
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
    smt_signal_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_signal_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_CACHE_INITIALISE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_signal_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_CACHE_INITIALISE))
    icl_stats_inc ("smt_signal_cache_initialise", &s_smt_signal_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_signal_t));
icl_system_register (smt_signal_cache_purge, smt_signal_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_CACHE_INITIALISE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_cache_initialise_finish"
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
    smt_signal_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_CACHE_PURGE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_PURGE))
    icl_trace_record (NULL, smt_signal_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_CACHE_PURGE))
    icl_stats_inc ("smt_signal_cache_purge", &s_smt_signal_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_PURGE))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_CACHE_PURGE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_cache_purge_finish"
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
    smt_signal_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_CACHE_TERMINATE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_signal_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_CACHE_TERMINATE))
    icl_stats_inc ("smt_signal_cache_terminate", &s_smt_signal_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_CACHE_TERMINATE))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_cache_terminate_finish"
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
    smt_signal_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_signal_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_SHOW_ANIMATION))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_signal_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL)  ||  defined (BASE_STATS_SMT_SIGNAL_SHOW_ANIMATION))
    icl_stats_inc ("smt_signal_show_animation", &s_smt_signal_show_animation_stats);
#endif

smt_signal_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_signal_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL)   || defined (BASE_ANIMATE_SMT_SIGNAL_SHOW_ANIMATION))
    if (smt_signal_animating)
        icl_console_print ("<smt_signal_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL)   || defined (BASE_TRACE_SMT_SIGNAL_INITIALISE)   || defined (BASE_TRACE_SMT_SIGNAL_TERMINATE)   || defined (BASE_TRACE_SMT_SIGNAL_NEW)   || defined (BASE_TRACE_SMT_SIGNAL_DESTROY)   || defined (BASE_TRACE_SMT_SIGNAL_REGISTER)   || defined (BASE_TRACE_SMT_SIGNAL_REGISTER_SHUT_DOWN)   || defined (BASE_TRACE_SMT_SIGNAL_DEREGISTER)   || defined (BASE_TRACE_SMT_SIGNAL_HANDLER)   || defined (BASE_TRACE_SMT_SIGNAL_SELFTEST)   || defined (BASE_TRACE_SMT_SIGNAL_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_SMT_SIGNAL_SHOW)   || defined (BASE_TRACE_SMT_SIGNAL_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_SIGNAL_ALLOC)   || defined (BASE_TRACE_SMT_SIGNAL_FREE)   || defined (BASE_TRACE_SMT_SIGNAL_READ_LOCK)   || defined (BASE_TRACE_SMT_SIGNAL_WRITE_LOCK)   || defined (BASE_TRACE_SMT_SIGNAL_UNLOCK)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_PURGE)   || defined (BASE_TRACE_SMT_SIGNAL_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_SIGNAL_SHOW_ANIMATION) )
void
smt_signal_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "initialise"; break;
        case 2: method_name = "terminate"; break;
        case 3: method_name = "new"; break;
        case 4: method_name = "destroy"; break;
        case 5: method_name = "register"; break;
        case 6: method_name = "register shut down"; break;
        case 7: method_name = "deregister"; break;
        case 8: method_name = "handler"; break;
        case 9: method_name = "selftest"; break;
        case 10: method_name = "remove from all containers"; break;
        case 11: method_name = "show"; break;
        case 12: method_name = "destroy public"; break;
        case 13: method_name = "alloc"; break;
        case 14: method_name = "free"; break;
        case 15: method_name = "read lock"; break;
        case 16: method_name = "write lock"; break;
        case 17: method_name = "unlock"; break;
        case 18: method_name = "cache initialise"; break;
        case 19: method_name = "cache purge"; break;
        case 20: method_name = "cache terminate"; break;
        case 21: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_signal %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_signal_version_start     = "VeRsIoNsTaRt:ipc";
char *smt_signal_component         = "smt_signal ";
char *smt_signal_version           = "1.0b0 ";
char *smt_signal_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_signal_filename          = "smt_signal.icl ";
char *smt_signal_builddate         = "2009/02/19 ";
char *smt_signal_version_end       = "VeRsIoNeNd:ipc";

