/*---------------------------------------------------------------------------
    demo_server_channel.c - demo_server_channel component

    This class implements the ASL demo server channel class.
    Generated from demo_server_channel.icl by smt_object_gen using GSL/4.
    
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
#include "demo_server_channel.h"        //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_server_channel_t

//  Shorthands for class methods                                               

#define self_consume        demo_server_channel_consume
#define self_cancel         demo_server_channel_cancel
#define self_initialise     demo_server_channel_initialise
#define self_new            demo_server_channel_new
#define self_annihilate     demo_server_channel_annihilate
#define self_spend          demo_server_channel_spend
#define self_earn           demo_server_channel_earn
#define self_error          demo_server_channel_error
#define self_selftest       demo_server_channel_selftest
#define self_remove_from_all_containers  demo_server_channel_remove_from_all_containers
#define self_show           demo_server_channel_show
#define self_destroy        demo_server_channel_destroy
#define self_unlink         demo_server_channel_unlink
#define self_show_animation  demo_server_channel_show_animation
#define self_free           demo_server_channel_free
#define self_terminate      demo_server_channel_terminate
#define self_alloc          demo_server_channel_alloc
#define self_link           demo_server_channel_link
#define self_cache_initialise  demo_server_channel_cache_initialise
#define self_cache_purge    demo_server_channel_cache_purge
#define self_cache_terminate  demo_server_channel_cache_terminate
#define self_new_in_scope   demo_server_channel_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CONSUME))
static icl_stats_t *s_demo_server_channel_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CANCEL))
static icl_stats_t *s_demo_server_channel_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_INITIALISE))
static icl_stats_t *s_demo_server_channel_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_NEW))
static icl_stats_t *s_demo_server_channel_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_DESTROY))
static icl_stats_t *s_demo_server_channel_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SPEND))
static icl_stats_t *s_demo_server_channel_spend_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_EARN))
static icl_stats_t *s_demo_server_channel_earn_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_ERROR))
static icl_stats_t *s_demo_server_channel_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SELFTEST))
static icl_stats_t *s_demo_server_channel_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_demo_server_channel_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SHOW))
static icl_stats_t *s_demo_server_channel_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC))
static icl_stats_t *s_demo_server_channel_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_UNLINK))
static icl_stats_t *s_demo_server_channel_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SHOW_ANIMATION))
static icl_stats_t *s_demo_server_channel_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_FREE))
static icl_stats_t *s_demo_server_channel_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_TERMINATE))
static icl_stats_t *s_demo_server_channel_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_ALLOC))
static icl_stats_t *s_demo_server_channel_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_LINK))
static icl_stats_t *s_demo_server_channel_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CACHE_INITIALISE))
static icl_stats_t *s_demo_server_channel_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CACHE_PURGE))
static icl_stats_t *s_demo_server_channel_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CACHE_TERMINATE))
static icl_stats_t *s_demo_server_channel_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE))
static icl_stats_t *s_demo_server_channel_new_in_scope_stats = NULL;
#endif
static void
    demo_server_channel_initialise (
void);

#define demo_server_channel_annihilate(self)  demo_server_channel_annihilate_ (self, __FILE__, __LINE__)
static int
    demo_server_channel_annihilate_ (
demo_server_channel_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_server_channel_alloc()     demo_server_channel_alloc_ (__FILE__, __LINE__)
static demo_server_channel_t *
    demo_server_channel_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    demo_server_channel_cache_initialise (
void);

static void
    demo_server_channel_cache_purge (
void);

static void
    demo_server_channel_cache_terminate (
void);

Bool
    demo_server_channel_animating = TRUE;  //  Animation enabled by default
static Bool
    s_demo_server_channel_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_demo_server_channel_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static volatile qbyte
    s_channel_id_seq_lo,                //  Next channel id
    s_channel_id_seq_hi;                //  High part (64-bits)
/*  -------------------------------------------------------------------------
    demo_server_channel_consume

    Type: Component method
    Accepts a demo_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Creates a new channel consumer to specified queue.  Only has an effect
    in Direct Protocol feed access.  Consumers are implemented as leases on
    queues.
    - find queue for consume
    - check queue is exclusive (required for lease)
    - lease may not yet be activated (happens asynchronously)
    - return consume-tag from queue name
    - set queue->feed_on to true
    -------------------------------------------------------------------------
 */

int
    demo_server_channel_consume (
    demo_server_channel_t * self,       //  Reference to object
    demo_server_method_t * method       //  Consume method
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CONSUME))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_consume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CONSUME))
    icl_trace_record (NULL, demo_server_channel_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CONSUME))
    icl_stats_inc ("demo_server_channel_consume", &s_demo_server_channel_consume_stats);
#endif

DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (demo_server_channel_agent_consume (self->thread,method)) {
        //icl_console_print ("Error sending 'consume' method to demo_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CONSUME))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CONSUME))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_consume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_channel_cancel

    Type: Component method
    Accepts a demo_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Cancels a channel consumer on specified queue.  Only has an effect in
    Direct Protocol feed access.  Consumers are implemented as leases on
    queues.
    - find queue for cancel (consumer-tag is queue name)
    - check queue is exclusive (required for lease)
    - set queue->feed_on to true
    -------------------------------------------------------------------------
 */

int
    demo_server_channel_cancel (
    demo_server_channel_t * self,       //  Reference to object
    demo_server_method_t * method       //  Cancel method
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CANCEL))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cancel_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CANCEL))
    icl_trace_record (NULL, demo_server_channel_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CANCEL))
    icl_stats_inc ("demo_server_channel_cancel", &s_demo_server_channel_cancel_stats);
#endif

DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (demo_server_channel_agent_cancel (self->thread,method)) {
        //icl_console_print ("Error sending 'cancel' method to demo_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CANCEL))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CANCEL))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cancel_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_channel_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_channel_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_INITIALISE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_INITIALISE))
    icl_trace_record (NULL, demo_server_channel_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_INITIALISE))
    icl_stats_inc ("demo_server_channel_initialise", &s_demo_server_channel_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_demo_server_channel_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_demo_server_channel_mutex)
            s_demo_server_channel_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_demo_server_channel_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_demo_server_channel_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

demo_server_channel_agent_init ();

s_channel_id_seq_hi = 0;
s_channel_id_seq_lo = 1;
            s_demo_server_channel_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_demo_server_channel_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_INITIALISE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_INITIALISE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_initialise_finish"
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
    demo_server_channel_new

    Type: Component method
    Creates and initialises a new demo_server_channel_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

demo_server_channel_t *
    demo_server_channel_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    demo_server_channel_table_t * table,   //  Table to insert into
    demo_server_connection_t * connection,   //  Parent connection
    dbyte number                        //  Channel number
)
{
#define key number
qbyte
    seq_lo,
    seq_hi;
    demo_server_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_NEW))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, connection);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_NEW))
    icl_trace_record (NULL, demo_server_channel_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_NEW))
    icl_stats_inc ("demo_server_channel_new", &s_demo_server_channel_new_stats);
#endif

if (!s_demo_server_channel_active)
    self_initialise ();
    self = demo_server_channel_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_SERVER_CHANNEL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, demo_server_channel_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread = demo_server_channel_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->active = TRUE;

//
self->connection = demo_server_connection_link (connection);
self->number = number;

//  Get 64-bit channel id, no wraparound handling
seq_lo = icl_atomic_inc32 (&s_channel_id_seq_lo);
if (seq_lo == 0)
    seq_hi = icl_atomic_inc32 (&s_channel_id_seq_hi);
else
    seq_hi = s_channel_id_seq_hi;
icl_shortstr_fmt (self->id, "%x-%x", seq_hi, seq_lo);
if (table && self && demo_server_channel_table_insert (table, key, self))
    demo_server_channel_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_NEW))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_NEW))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, connection, self);
#endif


    return (self);
}
#undef key
/*  -------------------------------------------------------------------------
    demo_server_channel_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    demo_server_channel_annihilate_ (
    demo_server_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    int
        history_last;
#endif

    demo_server_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_DESTROY))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_DESTROY))
    icl_trace_record (NULL, demo_server_channel_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_DESTROY))
    icl_stats_inc ("demo_server_channel_annihilate", &s_demo_server_channel_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (demo_server_channel_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to demo_server_channel agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_DESTROY))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_DESTROY))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_channel_spend

    Type: Component method
    Accepts a demo_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_channel_spend (
    demo_server_channel_t * self        //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SPEND))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_spend_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SPEND))
    icl_trace_record (NULL, demo_server_channel_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SPEND))
    icl_stats_inc ("demo_server_channel_spend", &s_demo_server_channel_spend_stats);
#endif

DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

icl_atomic_dec32 ((volatile qbyte *) &self->credit);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SPEND))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SPEND))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_spend_finish"
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
    demo_server_channel_earn

    Type: Component method
    Accepts a demo_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_channel_earn (
    demo_server_channel_t * self        //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_EARN))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_earn_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_EARN))
    icl_trace_record (NULL, demo_server_channel_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_EARN))
    icl_stats_inc ("demo_server_channel_earn", &s_demo_server_channel_earn_stats);
#endif

DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

icl_atomic_inc32 ((volatile qbyte *) &self->credit);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_EARN))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_EARN))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_earn_finish"
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
    demo_server_channel_error

    Type: Component method
    Accepts a demo_server_channel_t reference and returns zero in case of success,
    1 in case of errors.
    Raises a channel exception.
    -------------------------------------------------------------------------
 */

int
    demo_server_channel_error (
    demo_server_channel_t * self,       //  Reference to object
    dbyte reply_code,                   //  Error code
    char * reply_text,                  //  Error text
    dbyte faulting_class_id,            //  Faulting class id
    dbyte faulting_method_id            //  Faulting method id
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_ERROR))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_error_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_ERROR))
    icl_trace_record (NULL, demo_server_channel_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_ERROR))
    icl_stats_inc ("demo_server_channel_error", &s_demo_server_channel_error_stats);
#endif

DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
if (!self->zombie) {

//
demo_server_agent_channel_error (
    self->connection->thread, self, reply_code, reply_text,
    faulting_class_id, faulting_method_id);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_ERROR))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_ERROR))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_error_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_text=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_text, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_channel_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SELFTEST))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SELFTEST))
    icl_trace_record (NULL, demo_server_channel_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SELFTEST))
    icl_stats_inc ("demo_server_channel_selftest", &s_demo_server_channel_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SELFTEST))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SELFTEST))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_selftest_finish"
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
    demo_server_channel_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_remove_from_all_containers (
    demo_server_channel_t * self        //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_server_channel_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("demo_server_channel_remove_from_all_containers", &s_demo_server_channel_remove_from_all_containers_stats);
#endif

DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
demo_server_channel_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_remove_from_all_containers_finish"
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
    demo_server_channel_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_server_channel_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SHOW))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SHOW))
    icl_trace_record (NULL, demo_server_channel_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SHOW))
    icl_stats_inc ("demo_server_channel_show", &s_demo_server_channel_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <demo_server_channel zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    if (self->history_last > DEMO_SERVER_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % DEMO_SERVER_CHANNEL_HISTORY_LENGTH;
        self->history_last %= DEMO_SERVER_CHANNEL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % DEMO_SERVER_CHANNEL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </demo_server_channel>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SHOW))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SHOW))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_show_finish"
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
    demo_server_channel_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_server_channel_destroy_ (
    demo_server_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_server_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_server_channel_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC))
    icl_stats_inc ("demo_server_channel_destroy", &s_demo_server_channel_destroy_stats);
#endif

    if (self) {
demo_server_channel_remove_from_all_containers (self);
        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            rc = demo_server_channel_annihilate_ (self_p, file, line);
        else
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
            demo_server_channel_free (self);
        *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
" rc=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self, rc, self?self->links:0, self?self->zombie:0);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_channel_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_unlink_ (
    demo_server_channel_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    int
        history_last;
#endif
    demo_server_channel_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_UNLINK))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_UNLINK))
    icl_trace_record (NULL, demo_server_channel_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_UNLINK))
    icl_stats_inc ("demo_server_channel_unlink", &s_demo_server_channel_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on demo_server_channel object");
            demo_server_channel_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                demo_server_channel_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                demo_server_channel_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_UNLINK))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_UNLINK))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_unlink_finish"
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
    demo_server_channel_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SHOW_ANIMATION))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_server_channel_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_SHOW_ANIMATION))
    icl_stats_inc ("demo_server_channel_show_animation", &s_demo_server_channel_show_animation_stats);
#endif

demo_server_channel_animating = enabled;

demo_server_channel_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_SHOW_ANIMATION))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_show_animation_finish"
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
    demo_server_channel_free

    Type: Component method
    Freess a demo_server_channel_t object.
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_free_ (
    demo_server_channel_t * self,       //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_FREE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_FREE))
    icl_trace_record (NULL, demo_server_channel_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_FREE))
    icl_stats_inc ("demo_server_channel_free", &s_demo_server_channel_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (demo_server_channel_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_server_channel_t));
        self->object_tag = DEMO_SERVER_CHANNEL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_FREE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_FREE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_free_finish"
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
    demo_server_channel_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_TERMINATE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_TERMINATE))
    icl_trace_record (NULL, demo_server_channel_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_TERMINATE))
    icl_stats_inc ("demo_server_channel_terminate", &s_demo_server_channel_terminate_stats);
#endif

if (s_demo_server_channel_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_demo_server_channel_mutex);
#endif
        s_demo_server_channel_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_TERMINATE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_TERMINATE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_terminate_finish"
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
    demo_server_channel_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_server_channel_t *
    demo_server_channel_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_server_channel_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_ALLOC))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_ALLOC))
    icl_trace_record (NULL, demo_server_channel_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_ALLOC))
    icl_stats_inc ("demo_server_channel_alloc", &s_demo_server_channel_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_server_channel_cache_initialise ();

self = (demo_server_channel_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_server_channel_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_ALLOC))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_ALLOC))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_alloc_finish"
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
    demo_server_channel_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

demo_server_channel_t *
    demo_server_channel_link_ (
    demo_server_channel_t * self,       //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_LINK))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_LINK))
    icl_trace_record (NULL, demo_server_channel_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_LINK))
    icl_stats_inc ("demo_server_channel_link", &s_demo_server_channel_link_stats);
#endif

    if (self) {
        DEMO_SERVER_CHANNEL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CHANNEL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % DEMO_SERVER_CHANNEL_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_LINK))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_LINK))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_link_finish"
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
    demo_server_channel_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_server_channel_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CACHE_INITIALISE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_server_channel_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CACHE_INITIALISE))
    icl_stats_inc ("demo_server_channel_cache_initialise", &s_demo_server_channel_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_server_channel_t));
icl_system_register (demo_server_channel_cache_purge, demo_server_channel_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CACHE_INITIALISE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cache_initialise_finish"
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
    demo_server_channel_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_channel_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CACHE_PURGE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_PURGE))
    icl_trace_record (NULL, demo_server_channel_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CACHE_PURGE))
    icl_stats_inc ("demo_server_channel_cache_purge", &s_demo_server_channel_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_PURGE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CACHE_PURGE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cache_purge_finish"
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
    demo_server_channel_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_channel_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CACHE_TERMINATE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_server_channel_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_CACHE_TERMINATE))
    icl_stats_inc ("demo_server_channel_cache_terminate", &s_demo_server_channel_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_CACHE_TERMINATE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_cache_terminate_finish"
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
    demo_server_channel_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_channel_new_in_scope_ (
    demo_server_channel_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    demo_server_channel_table_t * table,   //  Table to insert into
    demo_server_connection_t * connection,   //  Parent connection
    dbyte number                        //  Channel number
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, connection);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_server_channel_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL)  ||  defined (BASE_STATS_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE))
    icl_stats_inc ("demo_server_channel_new_in_scope", &s_demo_server_channel_new_in_scope_stats);
#endif

*self_p = demo_server_channel_new_ (file,line,table,connection,number);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_server_channel_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_server_channel_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL)   || defined (BASE_ANIMATE_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE))
    if (demo_server_channel_animating)
        icl_console_print ("<demo_server_channel_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" connection=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, connection, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CONSUME)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CANCEL)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_INITIALISE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_NEW)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_DESTROY)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SPEND)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_EARN)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_ERROR)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SELFTEST)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SHOW)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_UNLINK)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_FREE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_ALLOC)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_LINK)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CHANNEL_NEW_IN_SCOPE) )
void
demo_server_channel_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "consume"; break;
        case 2: method_name = "cancel"; break;
        case 3: method_name = "initialise"; break;
        case 4: method_name = "new"; break;
        case 5: method_name = "destroy"; break;
        case 6: method_name = "spend"; break;
        case 7: method_name = "earn"; break;
        case 8: method_name = "error"; break;
        case 9: method_name = "selftest"; break;
        case 10: method_name = "remove from all containers"; break;
        case 11: method_name = "show"; break;
        case 12: method_name = "destroy public"; break;
        case 13: method_name = "unlink"; break;
        case 14: method_name = "show animation"; break;
        case 15: method_name = "free"; break;
        case 16: method_name = "terminate"; break;
        case 17: method_name = "alloc"; break;
        case 18: method_name = "link"; break;
        case 19: method_name = "cache initialise"; break;
        case 20: method_name = "cache purge"; break;
        case 21: method_name = "cache terminate"; break;
        case 22: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_server_channel %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_server_channel_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_server_channel_component  = "demo_server_channel ";
char *demo_server_channel_version  = "1.0 ";
char *demo_server_channel_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_server_channel_filename  = "demo_server_channel.icl ";
char *demo_server_channel_builddate  = "2009/02/19 ";
char *demo_server_channel_version_end  = "VeRsIoNeNd:ipc";

