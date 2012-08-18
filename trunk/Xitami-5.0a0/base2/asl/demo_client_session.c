/*---------------------------------------------------------------------------
    demo_client_session.c - demo_client_session component

This class provides the session serialisation API.
    Generated from demo_client_session.icl by icl_gen using GSL/4.
    
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
#include "demo_client_session.h"        //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_client_session_t

//  Shorthands for class methods                                               

#define self_new            demo_client_session_new
#define self_annihilate     demo_client_session_annihilate
#define self_wait           demo_client_session_wait
#define self_channel_flow   demo_client_session_channel_flow
#define self_channel_flow_ok  demo_client_session_channel_flow_ok
#define self_exchange_declare  demo_client_session_exchange_declare
#define self_exchange_delete  demo_client_session_exchange_delete
#define self_queue_declare  demo_client_session_queue_declare
#define self_queue_bind     demo_client_session_queue_bind
#define self_queue_purge    demo_client_session_queue_purge
#define self_queue_delete   demo_client_session_queue_delete
#define self_basic_consume  demo_client_session_basic_consume
#define self_basic_cancel   demo_client_session_basic_cancel
#define self_basic_publish  demo_client_session_basic_publish
#define self_basic_get      demo_client_session_basic_get
#define self_push_arrived   demo_client_session_push_arrived
#define self_push_returned  demo_client_session_push_returned
#define self_get_basic_arrived_count  demo_client_session_get_basic_arrived_count
#define self_basic_arrived  demo_client_session_basic_arrived
#define self_get_basic_returned_count  demo_client_session_get_basic_returned_count
#define self_basic_returned  demo_client_session_basic_returned
#define self_get_alive      demo_client_session_get_alive
#define self_get_error_text  demo_client_session_get_error_text
#define self_get_channel_id  demo_client_session_get_channel_id
#define self_get_active     demo_client_session_get_active
#define self_get_reply_code  demo_client_session_get_reply_code
#define self_get_reply_text  demo_client_session_get_reply_text
#define self_get_class_id   demo_client_session_get_class_id
#define self_get_method_id  demo_client_session_get_method_id
#define self_get_lease      demo_client_session_get_lease
#define self_get_consumer_tag  demo_client_session_get_consumer_tag
#define self_get_exchange   demo_client_session_get_exchange
#define self_get_routing_key  demo_client_session_get_routing_key
#define self_get_message_count  demo_client_session_get_message_count
#define self_get_queue      demo_client_session_get_queue
#define self_get_properties  demo_client_session_get_properties
#define self_dp_new         demo_client_session_dp_new
#define self_dp_lookup      demo_client_session_dp_lookup
#define self_dp_destroy     demo_client_session_dp_destroy
#define self_initialise     demo_client_session_initialise
#define self_selftest       demo_client_session_selftest
#define self_terminate      demo_client_session_terminate
#define self_show           demo_client_session_show
#define self_destroy        demo_client_session_destroy
#define self_alloc          demo_client_session_alloc
#define self_free           demo_client_session_free
#define self_cache_initialise  demo_client_session_cache_initialise
#define self_cache_purge    demo_client_session_cache_purge
#define self_cache_terminate  demo_client_session_cache_terminate
#define self_show_animation  demo_client_session_show_animation
#define self_new_in_scope   demo_client_session_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_NEW))
static icl_stats_t *s_demo_client_session_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DESTROY))
static icl_stats_t *s_demo_client_session_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_WAIT))
static icl_stats_t *s_demo_client_session_wait_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CHANNEL_FLOW))
static icl_stats_t *s_demo_client_session_channel_flow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK))
static icl_stats_t *s_demo_client_session_channel_flow_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE))
static icl_stats_t *s_demo_client_session_exchange_declare_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_EXCHANGE_DELETE))
static icl_stats_t *s_demo_client_session_exchange_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_DECLARE))
static icl_stats_t *s_demo_client_session_queue_declare_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_BIND))
static icl_stats_t *s_demo_client_session_queue_bind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_PURGE))
static icl_stats_t *s_demo_client_session_queue_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_DELETE))
static icl_stats_t *s_demo_client_session_queue_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_CONSUME))
static icl_stats_t *s_demo_client_session_basic_consume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_CANCEL))
static icl_stats_t *s_demo_client_session_basic_cancel_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_PUBLISH))
static icl_stats_t *s_demo_client_session_basic_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_GET))
static icl_stats_t *s_demo_client_session_basic_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_PUSH_ARRIVED))
static icl_stats_t *s_demo_client_session_push_arrived_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_PUSH_RETURNED))
static icl_stats_t *s_demo_client_session_push_returned_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT))
static icl_stats_t *s_demo_client_session_get_basic_arrived_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_ARRIVED))
static icl_stats_t *s_demo_client_session_basic_arrived_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT))
static icl_stats_t *s_demo_client_session_get_basic_returned_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_RETURNED))
static icl_stats_t *s_demo_client_session_basic_returned_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ALIVE))
static icl_stats_t *s_demo_client_session_get_alive_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ERROR_TEXT))
static icl_stats_t *s_demo_client_session_get_error_text_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_CHANNEL_ID))
static icl_stats_t *s_demo_client_session_get_channel_id_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ACTIVE))
static icl_stats_t *s_demo_client_session_get_active_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_REPLY_CODE))
static icl_stats_t *s_demo_client_session_get_reply_code_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_REPLY_TEXT))
static icl_stats_t *s_demo_client_session_get_reply_text_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_CLASS_ID))
static icl_stats_t *s_demo_client_session_get_class_id_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_METHOD_ID))
static icl_stats_t *s_demo_client_session_get_method_id_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_LEASE))
static icl_stats_t *s_demo_client_session_get_lease_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG))
static icl_stats_t *s_demo_client_session_get_consumer_tag_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_EXCHANGE))
static icl_stats_t *s_demo_client_session_get_exchange_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ROUTING_KEY))
static icl_stats_t *s_demo_client_session_get_routing_key_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT))
static icl_stats_t *s_demo_client_session_get_message_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_QUEUE))
static icl_stats_t *s_demo_client_session_get_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_PROPERTIES))
static icl_stats_t *s_demo_client_session_get_properties_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DP_NEW))
static icl_stats_t *s_demo_client_session_dp_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DP_LOOKUP))
static icl_stats_t *s_demo_client_session_dp_lookup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DP_DESTROY))
static icl_stats_t *s_demo_client_session_dp_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_INITIALISE))
static icl_stats_t *s_demo_client_session_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_SELFTEST))
static icl_stats_t *s_demo_client_session_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_TERMINATE))
static icl_stats_t *s_demo_client_session_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_SHOW))
static icl_stats_t *s_demo_client_session_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DESTROY_PUBLIC))
static icl_stats_t *s_demo_client_session_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_ALLOC))
static icl_stats_t *s_demo_client_session_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_FREE))
static icl_stats_t *s_demo_client_session_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CACHE_INITIALISE))
static icl_stats_t *s_demo_client_session_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CACHE_PURGE))
static icl_stats_t *s_demo_client_session_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CACHE_TERMINATE))
static icl_stats_t *s_demo_client_session_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_SHOW_ANIMATION))
static icl_stats_t *s_demo_client_session_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_NEW_IN_SCOPE))
static icl_stats_t *s_demo_client_session_new_in_scope_stats = NULL;
#endif
static void
    demo_client_session_annihilate (
demo_client_session_t * ( * self_p )    //  Reference to object reference
);

static void
    demo_client_session_initialise (
void);

static void
    demo_client_session_terminate (
void);

#define demo_client_session_alloc()     demo_client_session_alloc_ (__FILE__, __LINE__)
static demo_client_session_t *
    demo_client_session_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    demo_client_session_free (
demo_client_session_t * self            //  Object reference
);

static void
    demo_client_session_cache_initialise (
void);

static void
    demo_client_session_cache_purge (
void);

static void
    demo_client_session_cache_terminate (
void);

Bool
    demo_client_session_animating = TRUE;  //  Animation enabled by default
static Bool
    s_demo_client_session_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_demo_client_session_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static int
    s_wait_for_methods (demo_client_session_t *self, int timeout, Bool blocking, Bool on_content);
static void
    s_process_chrono (demo_client_session_t *self, demo_content_basic_t *content);
static void
    s_close_dp_sink (ipr_hash_t *hash, void *argument);
static void
    s_close_dp_feed (ipr_hash_t *hash, void *argument);
/*  -------------------------------------------------------------------------
    demo_client_session_new

    Type: Component method
    Creates and initialises a new demo_client_session_t object, returns a
    reference to the created object.
    Create new session on an established connection.

    The connection argument refers to a previously-created connection
    object.
    -------------------------------------------------------------------------
 */

demo_client_session_t *
    demo_client_session_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    demo_client_connection_t * connection  //  Not documented
)
{
int
    rc;
    demo_client_session_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_NEW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" connection=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, connection);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW))
    icl_trace_record (NULL, demo_client_session_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_NEW))
    icl_stats_inc ("demo_client_session_new", &s_demo_client_session_new_stats);
#endif

if (!s_demo_client_session_active)
    self_initialise ();
    self = demo_client_session_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_CLIENT_SESSION_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, demo_client_session_show_);
#endif

//
assert (connection);

self->connection   = connection;
self->channel_nbr  = ++connection->channel_nbr;
self->method_queue = smt_method_queue_sync_new ();
self->error_text   = "no error";
self->arrived_basic_list = demo_content_basic_list_new ();
self->returned_basic_list = demo_content_basic_list_new ();
self->chrono_list = demo_content_basic_list_new ();
self->dp_sinks = ipr_hash_table_new ();
self->dp_feeds = ipr_hash_table_new ();

//  Chrono block is the batch size plus enough for one delta
//  Thus we dispatch the chrono block when it's GE the batch size
self->chrono_block = icl_mem_alloc (
    demo_client_config_chrono_batch (demo_client_config)
    + ICL_SHORTSTR_MAX);
strclr (self->chrono_block);

if (connection->alive) {
    rc = demo_client_agent_channel_open (
        self->connection->thread,
        self->method_queue,
        &self->alive,
        &self->reply_code,
        self->reply_text,
        self->channel_nbr);

    //  If no immediate error, wait for confirmation that session was OK
    if (!rc) {
        if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE) == 0) {
            self->alive = TRUE;     //  Session is ready for use
            self->timestamp = apr_time_now ();
        }
    }
}
else {
    self->error_text = "connection is closed";
    rc = -1;
}
if (!self->alive)
    self_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_NEW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" connection=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, connection, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    demo_client_session_annihilate

    Type: Component method
    Close the session.
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_annihilate (
    demo_client_session_t * ( * self_p )  //  Reference to object reference
)
{

    demo_client_session_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DESTROY))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY))
    icl_trace_record (NULL, demo_client_session_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DESTROY))
    icl_stats_inc ("demo_client_session_annihilate", &s_demo_client_session_annihilate_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

//  Close and flush any Direct Mode connections
ipr_hash_table_apply (self->dp_sinks, s_close_dp_sink, self);
ipr_hash_table_destroy (&self->dp_sinks);
ipr_hash_table_apply (self->dp_feeds, s_close_dp_feed, self);
ipr_hash_table_destroy (&self->dp_feeds);

//  Close main connection
if (self->alive) {
    demo_client_agent_channel_close (self->connection->thread, self->channel_nbr);
    while (self->alive) {
        //  Wait until we get back an CLOSED method, or timeout
        s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE);
    }
}
icl_longstr_destroy (&self->channel_id);
icl_longstr_destroy (&self->properties);
icl_mem_free (self->chrono_block);
smt_method_queue_destroy (&self->method_queue);
demo_content_basic_list_destroy (&self->arrived_basic_list);
demo_content_basic_list_destroy (&self->returned_basic_list);
demo_content_basic_list_destroy (&self->chrono_list);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DESTROY))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_destroy_finish"
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
    demo_client_session_wait

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Waits for any activity on the session.  Returns 0 if content arrived
    or the timeout expired, -1 if the session ended abnormally.  If the timeout
    is zero, waits forever.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_wait (
    demo_client_session_t * self,       //  Reference to object
    int timeout                         //  Timeout, in milliseconds
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_WAIT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_wait_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_WAIT))
    icl_trace_record (NULL, demo_client_session_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_WAIT))
    icl_stats_inc ("demo_client_session_wait", &s_demo_client_session_wait_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

//
if (!demo_content_basic_list_isempty (self->arrived_basic_list))
    return (0);                    //  Return if there is content to process
if (self->alive) {
    if (s_wait_for_methods (self, timeout, FALSE, TRUE))
        rc = -1;
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_WAIT))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_WAIT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_wait_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_channel_flow

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Enable/Disable Flow From Peer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_channel_flow (
    demo_client_session_t * self,       //  Reference to object
    Bool active                         //  start/stop content frames
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CHANNEL_FLOW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_channel_flow_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW))
    icl_trace_record (NULL, demo_client_session_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CHANNEL_FLOW))
    icl_stats_inc ("demo_client_session_channel_flow", &s_demo_client_session_channel_flow_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_channel_flow (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        active);                     //  start/stop content frames

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CHANNEL_FLOW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_channel_flow_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_channel_flow_ok

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Confirm A Flow Method.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_channel_flow_ok (
    demo_client_session_t * self,       //  Reference to object
    Bool active                         //  current flow setting
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_channel_flow_ok_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK))
    icl_trace_record (NULL, demo_client_session_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK))
    icl_stats_inc ("demo_client_session_channel_flow_ok", &s_demo_client_session_channel_flow_ok_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_channel_flow_ok (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        active);                     //  current flow setting

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_channel_flow_ok_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_exchange_declare

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Declare Exchange, Create If Needed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_exchange_declare (
    demo_client_session_t * self,       //  Reference to object
    char * exchange,                    //  exchange name
    char * type,                        //  exchange class
    Bool passive,                       //  do not create exchange
    Bool durable,                       //  request a durable exchange
    Bool auto_delete                    //  auto-delete when unused
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_exchange_declare_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange=\"%s\""
" type=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" auto_delete=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange, type, passive, durable, auto_delete);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE))
    icl_trace_record (NULL, demo_client_session_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE))
    icl_stats_inc ("demo_client_session_exchange_declare", &s_demo_client_session_exchange_declare_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_exchange_declare (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        exchange,                    //  exchange name
        type,                        //  exchange class
        passive,                     //  do not create exchange
        durable,                     //  request a durable exchange
        auto_delete);                //  auto-delete when unused

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_exchange_declare_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange=\"%s\""
" type=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" auto_delete=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange, type, passive, durable, auto_delete, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_exchange_delete

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_exchange_delete (
    demo_client_session_t * self,       //  Reference to object
    char * exchange,                    //  exchange name
    Bool if_unused                      //  delete only if unused
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_EXCHANGE_DELETE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_exchange_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange=\"%s\""
" if_unused=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange, if_unused);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DELETE))
    icl_trace_record (NULL, demo_client_session_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_EXCHANGE_DELETE))
    icl_stats_inc ("demo_client_session_exchange_delete", &s_demo_client_session_exchange_delete_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_exchange_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        exchange,                    //  exchange name
        if_unused);                  //  delete only if unused

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DELETE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_EXCHANGE_DELETE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_exchange_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange=\"%s\""
" if_unused=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange, if_unused, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_queue_declare

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Declare Queue, Create If Needed.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_queue_declare (
    demo_client_session_t * self,       //  Reference to object
    char * queue,                       //  queue name
    Bool passive,                       //  do not create queue
    Bool durable,                       //  request a durable queue
    Bool exclusive,                     //  request an exclusive queue
    Bool auto_delete                    //  auto-delete queue when unused
)
{
smt_thread_t
*thread;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_DECLARE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_declare_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, passive, durable, exclusive, auto_delete);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DECLARE))
    icl_trace_record (NULL, demo_client_session_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_DECLARE))
    icl_stats_inc ("demo_client_session_queue_declare", &s_demo_client_session_queue_declare_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_queue_declare (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        queue,                       //  queue name
        passive,                     //  do not create queue
        durable,                     //  request a durable queue
        exclusive,                   //  request an exclusive queue
        auto_delete);                //  auto-delete queue when unused

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}
//  Action handler after calling method
if (rc == 0) {
if (self->connection->direct && exclusive) {
    thread = demo_client_session_dp_lookup (self, queue, DP_FEED);
    if (!thread) {
        thread = demo_client_session_dp_new (self, queue, DP_FEED);
        assert (thread);
    }
    smt_thread_unlink (&thread);
}
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DECLARE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_DECLARE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_declare_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" passive=\"%i\""
" durable=\"%i\""
" exclusive=\"%i\""
" auto_delete=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, passive, durable, exclusive, auto_delete, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_queue_bind

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Bind Queue To An Exchange.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_queue_bind (
    demo_client_session_t * self,       //  Reference to object
    char * queue,                       //  queue name
    char * exchange,                    //  exchange name
    icl_longstr_t * arguments           //  arguments for binding
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_BIND))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_bind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" exchange=\"%s\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, exchange, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_BIND))
    icl_trace_record (NULL, demo_client_session_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_BIND))
    icl_stats_inc ("demo_client_session_queue_bind", &s_demo_client_session_queue_bind_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_queue_bind (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        queue,                       //  queue name
        exchange,                    //  exchange name
        arguments);                  //  arguments for binding

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_BIND))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_BIND))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_bind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" exchange=\"%s\""
" arguments=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, exchange, arguments, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_queue_purge

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Purge A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_queue_purge (
    demo_client_session_t * self,       //  Reference to object
    char * queue                        //  queue name
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_PURGE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_PURGE))
    icl_trace_record (NULL, demo_client_session_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_PURGE))
    icl_stats_inc ("demo_client_session_queue_purge", &s_demo_client_session_queue_purge_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_queue_purge (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        queue);                      //  queue name

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_PURGE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_PURGE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_purge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_queue_delete

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Delete A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_queue_delete (
    demo_client_session_t * self,       //  Reference to object
    char * queue,                       //  queue name
    Bool if_unused,                     //  delete only if unused
    Bool if_empty                       //  delete only if empty
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_DELETE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" if_unused=\"%i\""
" if_empty=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, if_unused, if_empty);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DELETE))
    icl_trace_record (NULL, demo_client_session_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_QUEUE_DELETE))
    icl_stats_inc ("demo_client_session_queue_delete", &s_demo_client_session_queue_delete_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_queue_delete (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        queue,                       //  queue name
        if_unused,                   //  delete only if unused
        if_empty);                   //  delete only if empty

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}
//  Action handler after calling method
if (rc == 0) {
if (self->connection->direct)
    demo_client_session_dp_destroy (self, queue, DP_FEED);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DELETE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_QUEUE_DELETE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_queue_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" if_unused=\"%i\""
" if_empty=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, if_unused, if_empty, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_basic_consume

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Start A Queue Consumer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_basic_consume (
    demo_client_session_t * self,       //  Reference to object
    char * queue                        //  queue name
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_CONSUME))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_consume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CONSUME))
    icl_trace_record (NULL, demo_client_session_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_CONSUME))
    icl_stats_inc ("demo_client_session_basic_consume", &s_demo_client_session_basic_consume_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_basic_consume (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        queue);                      //  queue name

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CONSUME))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_CONSUME))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_consume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_basic_cancel

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    End A Queue Consumer.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_basic_cancel (
    demo_client_session_t * self,       //  Reference to object
    char * consumer_tag                 //  consumer tag
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_CANCEL))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_cancel_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer_tag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer_tag);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CANCEL))
    icl_trace_record (NULL, demo_client_session_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_CANCEL))
    icl_stats_inc ("demo_client_session_basic_cancel", &s_demo_client_session_basic_cancel_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_basic_cancel (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        consumer_tag);               //  consumer tag

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CANCEL))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_CANCEL))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_cancel_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer_tag=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer_tag, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_basic_publish

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Publish A Message.
    The caller must create a new demo_content_basic object
    for this call; the object is destroyed after being sent.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_basic_publish (
    demo_client_session_t * self,       //  Reference to object
    demo_content_basic_t * content,     //  Message content
    char * exchange,                    //  exchange name
    char * routing_key                  //  Message routing key
)
{
smt_thread_t
*thread;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_PUBLISH))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_publish_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" exchange=\"%s\""
" routing_key=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, exchange, routing_key);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_PUBLISH))
    icl_trace_record (NULL, demo_client_session_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_PUBLISH))
    icl_stats_inc ("demo_client_session_basic_publish", &s_demo_client_session_basic_publish_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

assert (content);                   //  Content must be supplied
//  Action handler before calling method
if (self->connection->direct) {
    thread = demo_client_session_dp_lookup (self, exchange, DP_SINK);
    if (!thread) {
        thread = demo_client_session_dp_new (self, exchange, DP_SINK);
        assert (thread);
    }
    demo_content_basic_set_routing_key (content, exchange, routing_key, NULL);
    demo_client_agent_direct_out (thread, content, 0);
    smt_thread_unlink (&thread);
}
else
if (self->alive) {
    rc = demo_client_agent_basic_publish (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        content,                     //  message content
        exchange,                    //  exchange name
        routing_key);                //  message routing key

    if (rc == 0) {
        if (s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE))
            rc = -1;
    }
    else
        self->error_text = "unable to send method to protocol agent";
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_PUBLISH))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_PUBLISH))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_publish_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" exchange=\"%s\""
" routing_key=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, exchange, routing_key, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_basic_get

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Direct Access To A Queue.
    Returns 0 on success, 1 on failure.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_basic_get (
    demo_client_session_t * self,       //  Reference to object
    char * queue                        //  queue name
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_GET))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_GET))
    icl_trace_record (NULL, demo_client_session_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_GET))
    icl_stats_inc ("demo_client_session_basic_get", &s_demo_client_session_basic_get_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

if (self->alive) {
    rc = demo_client_agent_basic_get (
        self->connection->thread,    //  connection thread
        self->channel_nbr,           //  channel to send on
        queue);                      //  queue name

    if (rc == 0) {
        if (self->alive) {
            //  Wait until the agent has synchronised with us
            if (s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE))
                rc = -1;
        }
        else {
            self->error_text = "session is closed";
            rc = -1;
        }
    }
}
else {
    self->error_text = "session is closed";
    rc = -1;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_GET))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_GET))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_push_arrived

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Stores an arrived content, and takes appropriate action if the arrived
    queue hits the high water mark.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_push_arrived (
    demo_client_session_t * self,       //  Reference to object
    demo_content_basic_t * content,     //  Message content
    char * exchange,                    //  Value to stamp into content
    char * routing_key,                 //  Value to stamp into content
    char * consumer_tag                 //  Value to stamp into content
)
{
size_t
    high_water,                     //  Value of high water setting
    queue_size;                     //  Queue size before we push our content
char
    *on_overflow;                   //  on_overflow action for direct connections
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_PUSH_ARRIVED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_push_arrived_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" exchange=\"%s\""
" routing_key=\"%s\""
" consumer_tag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, exchange, routing_key, consumer_tag);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_ARRIVED))
    icl_trace_record (NULL, demo_client_session_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_PUSH_ARRIVED))
    icl_stats_inc ("demo_client_session_push_arrived", &s_demo_client_session_push_arrived_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

//
//  Stamp content with values from method, if any
if (exchange && *exchange)
    icl_shortstr_cpy (content->exchange, exchange);
if (routing_key && routing_key)
    icl_shortstr_cpy (content->routing_key, routing_key);
if (consumer_tag && *consumer_tag)
    icl_shortstr_cpy (content->consumer_tag, consumer_tag);
//  Send chronometer deltas, if any, to chrono@amq.status exchange
if (demo_client_config_chrono_enabled (demo_client_config))
    s_process_chrono (self, content);

//  Check if queue would overflow, take appropriate action
high_water = demo_client_config_high_water (demo_client_config);
if (high_water) {                   //  If it's zero, we don't interfere
    queue_size = self_get_basic_arrived_count (self);
    if (queue_size == high_water) {
        if (self->connection->direct) {
            on_overflow = demo_client_config_on_overflow (demo_client_config);
            if (streq (on_overflow, "warn")) {
                //  Warn that we hit high-water, but only once per tide
                if (icl_atomic_cas32 (&self->flow_stopped, TRUE, FALSE) == FALSE) {
                    icl_console_print ("W: high-water mark reached, application is too slow");
                    icl_console_print ("I: contact iMatix for help on tuning your application");
                }
            }
            else
            if (streq (on_overflow, "trim")) {
                //  Chuck away oldest content on arrived list
                demo_content_basic_t
                    *trimmed;
                trimmed = demo_content_basic_list_pop (self->arrived_basic_list);
                demo_content_basic_unlink (&trimmed);
            }
            else
            if (streq (on_overflow, "drop")) {
                //  Chuck away new incoming content
                content = NULL;     //  Just don't store the content
            }
            else
            if (streq (on_overflow, "kill")) {
                //  To die. In the rain. Alone.
                icl_console_print ("E: high water reached (%d): on_overflow requested fatal stop", high_water);
                icl_console_print ("I: contact iMatix for help on tuning your application");
                exit (1);
            }
        }
        else
        //  If we're in normal AMQP mode, send Channel.Flow Off if needed
        if (icl_atomic_cas32 (&self->flow_stopped, TRUE, FALSE) == FALSE)
            demo_client_session_channel_flow (self, FALSE);
    }
}
//  Queue content if we did not discard it
if (content)
    demo_content_basic_list_queue (self->arrived_basic_list, content);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_ARRIVED))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_PUSH_ARRIVED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_push_arrived_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" exchange=\"%s\""
" routing_key=\"%s\""
" consumer_tag=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, exchange, routing_key, consumer_tag, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_push_returned

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    Stores a returned content.  Currently not guarded by any high water marks.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_push_returned (
    demo_client_session_t * self,       //  Reference to object
    demo_content_basic_t * content,     //  Message content
    char * exchange,                    //  Value to stamp into content
    char * routing_key,                 //  Value to stamp into content
    char * consumer_tag                 //  Value to stamp into content
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_PUSH_RETURNED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_push_returned_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" exchange=\"%s\""
" routing_key=\"%s\""
" consumer_tag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, exchange, routing_key, consumer_tag);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_RETURNED))
    icl_trace_record (NULL, demo_client_session_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_PUSH_RETURNED))
    icl_stats_inc ("demo_client_session_push_returned", &s_demo_client_session_push_returned_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

//
//  Stamp content with values from method, if any
if (exchange && *exchange)
    icl_shortstr_cpy (content->exchange, exchange);
if (routing_key && routing_key)
    icl_shortstr_cpy (content->routing_key, routing_key);
if (consumer_tag && *consumer_tag)
    icl_shortstr_cpy (content->consumer_tag, consumer_tag);

//  Set the returned flag - is this actually useful?
content->returned = TRUE;

//  Queue content
demo_content_basic_list_queue (self->returned_basic_list, content);
if (!self->connection->silent)
    icl_console_print ("W: basic message was returned: %d - %s",
        self->reply_code, self->reply_text);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_RETURNED))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_PUSH_RETURNED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_push_returned_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" exchange=\"%s\""
" routing_key=\"%s\""
" consumer_tag=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, exchange, routing_key, consumer_tag, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_basic_arrived_count

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_get_basic_arrived_count (
    demo_client_session_t * self        //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_basic_arrived_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT))
    icl_trace_record (NULL, demo_client_session_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT))
    icl_stats_inc ("demo_client_session_get_basic_arrived_count", &s_demo_client_session_get_basic_arrived_count_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

rc = demo_content_basic_list_count (self->arrived_basic_list);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_basic_arrived_count_finish"
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
    demo_client_session_basic_arrived

    Type: Component method
    -------------------------------------------------------------------------
 */

demo_content_basic_t *
    demo_client_session_basic_arrived (
    demo_client_session_t * self        //  Session object
)
{
    demo_content_basic_t *
        content = NULL;                 //  Message content

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_ARRIVED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_arrived_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_ARRIVED))
    icl_trace_record (NULL, demo_client_session_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_ARRIVED))
    icl_stats_inc ("demo_client_session_basic_arrived", &s_demo_client_session_basic_arrived_stats);
#endif

//
//  Get next message off list, if any
content = demo_content_basic_list_pop (self->arrived_basic_list);

//  Patch session to properly reflect this content's properties
if (content) {
    icl_shortstr_cpy (self->exchange, content->exchange);
    icl_shortstr_cpy (self->routing_key, content->routing_key);
    if (*content->consumer_tag)
        icl_shortstr_cpy (self->consumer_tag, content->consumer_tag);
}
if (demo_client_config_high_water (demo_client_config)
&& self_get_basic_arrived_count (self) == demo_client_config_low_water (demo_client_config)
&& icl_atomic_cas32 (&self->flow_stopped, FALSE, TRUE) == TRUE)
    self_channel_flow (self, TRUE);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_ARRIVED))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_ARRIVED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_arrived_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content);
#endif


    return (content);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_basic_returned_count

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_get_basic_returned_count (
    demo_client_session_t * self        //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_basic_returned_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT))
    icl_trace_record (NULL, demo_client_session_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT))
    icl_stats_inc ("demo_client_session_get_basic_returned_count", &s_demo_client_session_get_basic_returned_count_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

rc = demo_content_basic_list_count (self->returned_basic_list);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_basic_returned_count_finish"
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
    demo_client_session_basic_returned

    Type: Component method
    -------------------------------------------------------------------------
 */

demo_content_basic_t *
    demo_client_session_basic_returned (
    demo_client_session_t * self        //  Session object
)
{
    demo_content_basic_t *
        content = NULL;                 //  Message content

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_RETURNED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_returned_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_RETURNED))
    icl_trace_record (NULL, demo_client_session_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_BASIC_RETURNED))
    icl_stats_inc ("demo_client_session_basic_returned", &s_demo_client_session_basic_returned_stats);
#endif

//
//  Get next message off list, if any
content = demo_content_basic_list_pop (self->returned_basic_list);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_RETURNED))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_BASIC_RETURNED))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_basic_returned_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content);
#endif


    return (content);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_alive

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    demo_client_session_get_alive (
    demo_client_session_t * self        //  Object reference
)
{
    Bool
        alive;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ALIVE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_alive_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ALIVE))
    icl_trace_record (NULL, demo_client_session_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ALIVE))
    icl_stats_inc ("demo_client_session_get_alive", &s_demo_client_session_get_alive_stats);
#endif

//
alive = self->alive;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ALIVE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ALIVE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_alive_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alive=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alive);
#endif


    return (alive);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_error_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_error_text (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        error_text;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ERROR_TEXT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_error_text_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ERROR_TEXT))
    icl_trace_record (NULL, demo_client_session_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ERROR_TEXT))
    icl_stats_inc ("demo_client_session_get_error_text", &s_demo_client_session_get_error_text_stats);
#endif

//
error_text = self->error_text;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ERROR_TEXT))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ERROR_TEXT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_error_text_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" error_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, error_text);
#endif


    return (error_text);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_channel_id

    Type: Component method
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    demo_client_session_get_channel_id (
    demo_client_session_t * self        //  Object reference
)
{
    icl_longstr_t *
        channel_id;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_CHANNEL_ID))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_channel_id_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CHANNEL_ID))
    icl_trace_record (NULL, demo_client_session_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_CHANNEL_ID))
    icl_stats_inc ("demo_client_session_get_channel_id", &s_demo_client_session_get_channel_id_stats);
#endif

//
channel_id = self->channel_id;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CHANNEL_ID))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_CHANNEL_ID))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_channel_id_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel_id=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel_id);
#endif


    return (channel_id);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_active

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    demo_client_session_get_active (
    demo_client_session_t * self        //  Object reference
)
{
    Bool
        active;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ACTIVE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_active_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ACTIVE))
    icl_trace_record (NULL, demo_client_session_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ACTIVE))
    icl_stats_inc ("demo_client_session_get_active", &s_demo_client_session_get_active_stats);
#endif

//
active = self->active;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ACTIVE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ACTIVE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_active_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" active=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, active);
#endif


    return (active);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_reply_code

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_session_get_reply_code (
    demo_client_session_t * self        //  Object reference
)
{
    int
        reply_code;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_REPLY_CODE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_reply_code_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_CODE))
    icl_trace_record (NULL, demo_client_session_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_REPLY_CODE))
    icl_stats_inc ("demo_client_session_get_reply_code", &s_demo_client_session_get_reply_code_stats);
#endif

//
reply_code = self->reply_code;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_CODE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_REPLY_CODE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_reply_code_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_code=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_code);
#endif


    return (reply_code);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_reply_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_reply_text (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        reply_text;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_REPLY_TEXT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_reply_text_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_TEXT))
    icl_trace_record (NULL, demo_client_session_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_REPLY_TEXT))
    icl_stats_inc ("demo_client_session_get_reply_text", &s_demo_client_session_get_reply_text_stats);
#endif

//
reply_text = self->reply_text;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_TEXT))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_REPLY_TEXT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_reply_text_finish"
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


    return (reply_text);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_class_id

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_session_get_class_id (
    demo_client_session_t * self        //  Object reference
)
{
    int
        class_id;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_CLASS_ID))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_class_id_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CLASS_ID))
    icl_trace_record (NULL, demo_client_session_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_CLASS_ID))
    icl_stats_inc ("demo_client_session_get_class_id", &s_demo_client_session_get_class_id_stats);
#endif

//
class_id = self->class_id;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CLASS_ID))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_CLASS_ID))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_class_id_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" class_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, class_id);
#endif


    return (class_id);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_method_id

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_session_get_method_id (
    demo_client_session_t * self        //  Object reference
)
{
    int
        method_id;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_METHOD_ID))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_method_id_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_METHOD_ID))
    icl_trace_record (NULL, demo_client_session_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_METHOD_ID))
    icl_stats_inc ("demo_client_session_get_method_id", &s_demo_client_session_get_method_id_stats);
#endif

//
method_id = self->method_id;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_METHOD_ID))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_METHOD_ID))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_method_id_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" method_id=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, method_id);
#endif


    return (method_id);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_lease

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_lease (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        lease;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_LEASE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_lease_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_LEASE))
    icl_trace_record (NULL, demo_client_session_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_LEASE))
    icl_stats_inc ("demo_client_session_get_lease", &s_demo_client_session_get_lease_stats);
#endif

//
lease = self->lease;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_LEASE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_LEASE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_lease_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" lease=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, lease);
#endif


    return (lease);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_consumer_tag

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_consumer_tag (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        consumer_tag;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_consumer_tag_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG))
    icl_trace_record (NULL, demo_client_session_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG))
    icl_stats_inc ("demo_client_session_get_consumer_tag", &s_demo_client_session_get_consumer_tag_stats);
#endif

//
consumer_tag = self->consumer_tag;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_consumer_tag_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" consumer_tag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, consumer_tag);
#endif


    return (consumer_tag);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_exchange

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_exchange (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        exchange;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_EXCHANGE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_exchange_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_EXCHANGE))
    icl_trace_record (NULL, demo_client_session_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_EXCHANGE))
    icl_stats_inc ("demo_client_session_get_exchange", &s_demo_client_session_get_exchange_stats);
#endif

//
exchange = self->exchange;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_EXCHANGE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_EXCHANGE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_exchange_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" exchange=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, exchange);
#endif


    return (exchange);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_routing_key

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_routing_key (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        routing_key;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ROUTING_KEY))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_routing_key_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ROUTING_KEY))
    icl_trace_record (NULL, demo_client_session_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_ROUTING_KEY))
    icl_stats_inc ("demo_client_session_get_routing_key", &s_demo_client_session_get_routing_key_stats);
#endif

//
routing_key = self->routing_key;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ROUTING_KEY))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_ROUTING_KEY))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_routing_key_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" routing_key=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, routing_key);
#endif


    return (routing_key);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_message_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    demo_client_session_get_message_count (
    demo_client_session_t * self        //  Object reference
)
{
    qbyte
        message_count;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_message_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT))
    icl_trace_record (NULL, demo_client_session_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT))
    icl_stats_inc ("demo_client_session_get_message_count", &s_demo_client_session_get_message_count_stats);
#endif

//
message_count = self->message_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_message_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" message_count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, message_count);
#endif


    return (message_count);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_queue

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_session_get_queue (
    demo_client_session_t * self        //  Object reference
)
{
    char *
        queue;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_QUEUE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_QUEUE))
    icl_trace_record (NULL, demo_client_session_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_QUEUE))
    icl_stats_inc ("demo_client_session_get_queue", &s_demo_client_session_get_queue_stats);
#endif

//
queue = self->queue;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_QUEUE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_QUEUE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" queue=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, queue);
#endif


    return (queue);
}
/*  -------------------------------------------------------------------------
    demo_client_session_get_properties

    Type: Component method
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    demo_client_session_get_properties (
    demo_client_session_t * self        //  Object reference
)
{
    icl_longstr_t *
        properties;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_PROPERTIES))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_properties_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_PROPERTIES))
    icl_trace_record (NULL, demo_client_session_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_GET_PROPERTIES))
    icl_stats_inc ("demo_client_session_get_properties", &s_demo_client_session_get_properties_stats);
#endif

//
properties = self->properties;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_PROPERTIES))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_GET_PROPERTIES))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_get_properties_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" properties=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, properties);
#endif


    return (properties);
}
/*  -------------------------------------------------------------------------
    demo_client_session_dp_new

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_thread_t *
    demo_client_session_dp_new (
    demo_client_session_t * self,       //  Session object
    char * name,                        //  Resource name
    int type                            //  Resource type
)
{
int
    rc = 0;
ipr_hash_t
    *hash;
    smt_thread_t *
        thread = NULL;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DP_NEW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_dp_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" type=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, type);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_NEW))
    icl_trace_record (NULL, demo_client_session_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DP_NEW))
    icl_stats_inc ("demo_client_session_dp_new", &s_demo_client_session_dp_new_stats);
#endif

//
//  Start a new direct connection
//  - send Direct.Put or Direct.Get via main connection
//  - server provides lease via Put-Ok or Get-Ok
//  - create new direct thread and give it the lease
//
assert (type == DP_SINK || type == DP_FEED);
if (name == NULL)
    name = "";                            //  Blank name is valid

//  Request lease and wait for response
if (type == DP_SINK)
    demo_client_agent_direct_put (self->connection->thread, self->channel_nbr, name);
else
    demo_client_agent_direct_get (self->connection->thread, self->channel_nbr, name);
rc = s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE);
assert (!rc);

//  Create direct connection thread and wait for it to signal ready
thread = demo_client_agent_direct_thread_new (
    type,
    self->method_queue,
    self->connection->host,
    self->lease,
    self->connection->trace,
    self->connection->timeout);
assert (thread);
smt_thread_wake (thread);
rc = s_wait_for_methods (self, self->connection->timeout, TRUE, FALSE);
assert (!rc);

//  Store thread in hash table with extra link, so that caller can
//  unlink thread properly.
if (type == DP_SINK)
    hash = ipr_hash_new (self->dp_sinks, name, smt_thread_link (thread));
else
    hash = ipr_hash_new (self->dp_feeds, name, smt_thread_link (thread));
ipr_hash_unlink (&hash);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_NEW))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DP_NEW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_dp_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" type=\"%i\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, type, thread);
#endif


    return (thread);
}
/*  -------------------------------------------------------------------------
    demo_client_session_dp_lookup

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_thread_t *
    demo_client_session_dp_lookup (
    demo_client_session_t * self,       //  Session object
    char * name,                        //  Resource name
    int type                            //  Resource type
)
{
ipr_hash_t
    *hash;
    smt_thread_t *
        thread = NULL;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DP_LOOKUP))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_dp_lookup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" type=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, type);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_LOOKUP))
    icl_trace_record (NULL, demo_client_session_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DP_LOOKUP))
    icl_stats_inc ("demo_client_session_dp_lookup", &s_demo_client_session_dp_lookup_stats);
#endif

//

assert (type == DP_SINK || type == DP_FEED);
if (type == DP_SINK)
    hash = ipr_hash_table_search (self->dp_sinks, name);
else
    hash = ipr_hash_table_search (self->dp_feeds, name);

if (hash) {
    thread = smt_thread_link ((smt_thread_t *) hash->data);
    ipr_hash_unlink (&hash);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_LOOKUP))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DP_LOOKUP))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_dp_lookup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" type=\"%i\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, type, thread);
#endif


    return (thread);
}
/*  -------------------------------------------------------------------------
    demo_client_session_dp_destroy

    Type: Component method
    Accepts a demo_client_session_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_session_dp_destroy (
    demo_client_session_t * self,       //  Reference to object
    char * name,                        //  Resource name
    int type                            //  Resource type
)
{
ipr_hash_t
    *hash;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DP_DESTROY))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_dp_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" type=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, type);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_DESTROY))
    icl_trace_record (NULL, demo_client_session_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DP_DESTROY))
    icl_stats_inc ("demo_client_session_dp_destroy", &s_demo_client_session_dp_destroy_stats);
#endif

DEMO_CLIENT_SESSION_ASSERT_SANE (self);

//
assert (type == DP_SINK || type == DP_FEED);
if (type == DP_SINK) {
    hash = ipr_hash_table_search (self->dp_sinks, name);
    if (hash) {
        s_close_dp_sink (hash, self);
        ipr_hash_destroy (&hash);
    }
}
else {
    hash = ipr_hash_table_search (self->dp_feeds, name);
    if (hash) {
        s_close_dp_feed (hash, self);
        ipr_hash_destroy (&hash);
    }
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_DESTROY))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DP_DESTROY))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_dp_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" type=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, type, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_session_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_INITIALISE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_INITIALISE))
    icl_trace_record (NULL, demo_client_session_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_INITIALISE))
    icl_stats_inc ("demo_client_session_initialise", &s_demo_client_session_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_demo_client_session_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_demo_client_session_mutex)
            s_demo_client_session_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_demo_client_session_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_demo_client_session_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

demo_client_agent_init ();
            s_demo_client_session_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_demo_client_session_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_INITIALISE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_INITIALISE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_initialise_finish"
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
    demo_client_session_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_session_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_SELFTEST))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SELFTEST))
    icl_trace_record (NULL, demo_client_session_dump, 41);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_SELFTEST))
    icl_stats_inc ("demo_client_session_selftest", &s_demo_client_session_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SELFTEST))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 41);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_SELFTEST))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_selftest_finish"
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
    demo_client_session_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_TERMINATE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_TERMINATE))
    icl_trace_record (NULL, demo_client_session_dump, 42);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_TERMINATE))
    icl_stats_inc ("demo_client_session_terminate", &s_demo_client_session_terminate_stats);
#endif

if (s_demo_client_session_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_demo_client_session_mutex);
#endif
        s_demo_client_session_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_TERMINATE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 42);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_TERMINATE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_terminate_finish"
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
    demo_client_session_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_session_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
demo_client_session_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_SHOW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW))
    icl_trace_record (NULL, demo_client_session_dump, 43);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_SHOW))
    icl_stats_inc ("demo_client_session_show", &s_demo_client_session_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <demo_client_session file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 43);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_SHOW))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_show_finish"
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
    demo_client_session_destroy

    Type: Component method
    Destroys a demo_client_session_t object. Takes the address of a
    demo_client_session_t reference (a pointer to a pointer) and nullifies the
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
    demo_client_session_destroy_ (
    demo_client_session_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    demo_client_session_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DESTROY_PUBLIC))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_client_session_dump, 44);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_DESTROY_PUBLIC))
    icl_stats_inc ("demo_client_session_destroy", &s_demo_client_session_destroy_stats);
#endif

if (self) {
    demo_client_session_annihilate (self_p);
    demo_client_session_free ((demo_client_session_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 44);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_DESTROY_PUBLIC))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_destroy_public_finish"
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
    demo_client_session_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_client_session_t *
    demo_client_session_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_client_session_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_ALLOC))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_ALLOC))
    icl_trace_record (NULL, demo_client_session_dump, 45);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_ALLOC))
    icl_stats_inc ("demo_client_session_alloc", &s_demo_client_session_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_client_session_cache_initialise ();

self = (demo_client_session_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_client_session_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_ALLOC))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 45);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_ALLOC))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_alloc_finish"
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
    demo_client_session_free

    Type: Component method
    Freess a demo_client_session_t object.
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_free (
    demo_client_session_t * self        //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_FREE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_FREE))
    icl_trace_record (NULL, demo_client_session_dump, 46);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_FREE))
    icl_stats_inc ("demo_client_session_free", &s_demo_client_session_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (demo_client_session_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_client_session_t));
        self->object_tag = DEMO_CLIENT_SESSION_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_FREE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 46);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_FREE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_free_finish"
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
    demo_client_session_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CACHE_INITIALISE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_client_session_dump, 47);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CACHE_INITIALISE))
    icl_stats_inc ("demo_client_session_cache_initialise", &s_demo_client_session_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_client_session_t));
icl_system_register (demo_client_session_cache_purge, demo_client_session_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 47);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CACHE_INITIALISE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_cache_initialise_finish"
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
    demo_client_session_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CACHE_PURGE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_PURGE))
    icl_trace_record (NULL, demo_client_session_dump, 48);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CACHE_PURGE))
    icl_stats_inc ("demo_client_session_cache_purge", &s_demo_client_session_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_PURGE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 48);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CACHE_PURGE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_cache_purge_finish"
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
    demo_client_session_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_session_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CACHE_TERMINATE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_client_session_dump, 49);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_CACHE_TERMINATE))
    icl_stats_inc ("demo_client_session_cache_terminate", &s_demo_client_session_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 49);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_CACHE_TERMINATE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_cache_terminate_finish"
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
    demo_client_session_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_client_session_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_SHOW_ANIMATION))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_client_session_dump, 50);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_SHOW_ANIMATION))
    icl_stats_inc ("demo_client_session_show_animation", &s_demo_client_session_show_animation_stats);
#endif

demo_client_session_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 50);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_SHOW_ANIMATION))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_show_animation_finish"
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
    demo_client_session_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_session_new_in_scope_ (
    demo_client_session_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    demo_client_connection_t * connection  //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_NEW_IN_SCOPE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" connection=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, connection);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_client_session_dump, 51);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION)  ||  defined (BASE_STATS_DEMO_CLIENT_SESSION_NEW_IN_SCOPE))
    icl_stats_inc ("demo_client_session_new_in_scope", &s_demo_client_session_new_in_scope_stats);
#endif

*self_p = demo_client_session_new_ (file,line,connection);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_client_session_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_client_session_dump, 0x10000 + 51);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION)   || defined (BASE_ANIMATE_DEMO_CLIENT_SESSION_NEW_IN_SCOPE))
    if (demo_client_session_animating)
        icl_console_print ("<demo_client_session_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" connection=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, connection, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_WAIT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DELETE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DECLARE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_BIND)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DELETE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CONSUME)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CANCEL)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_PUBLISH)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_GET)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_ARRIVED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_RETURNED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_ARRIVED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_RETURNED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ALIVE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ERROR_TEXT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CHANNEL_ID)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ACTIVE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_CODE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_TEXT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CLASS_ID)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_METHOD_ID)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_LEASE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_EXCHANGE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ROUTING_KEY)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_QUEUE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_PROPERTIES)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_LOOKUP)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SELFTEST)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_ALLOC)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_FREE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW_IN_SCOPE) )
void
demo_client_session_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "wait"; break;
        case 4: method_name = "channel flow"; break;
        case 5: method_name = "channel flow-ok"; break;
        case 6: method_name = "exchange declare"; break;
        case 7: method_name = "exchange delete"; break;
        case 8: method_name = "queue declare"; break;
        case 9: method_name = "queue bind"; break;
        case 10: method_name = "queue purge"; break;
        case 11: method_name = "queue delete"; break;
        case 12: method_name = "basic consume"; break;
        case 13: method_name = "basic cancel"; break;
        case 14: method_name = "basic publish"; break;
        case 15: method_name = "basic get"; break;
        case 16: method_name = "push arrived"; break;
        case 17: method_name = "push returned"; break;
        case 18: method_name = "get basic arrived count"; break;
        case 19: method_name = "basic arrived"; break;
        case 20: method_name = "get basic returned count"; break;
        case 21: method_name = "basic returned"; break;
        case 22: method_name = "get alive"; break;
        case 23: method_name = "get error text"; break;
        case 24: method_name = "get channel_id"; break;
        case 25: method_name = "get active"; break;
        case 26: method_name = "get reply_code"; break;
        case 27: method_name = "get reply_text"; break;
        case 28: method_name = "get class_id"; break;
        case 29: method_name = "get method_id"; break;
        case 30: method_name = "get lease"; break;
        case 31: method_name = "get consumer_tag"; break;
        case 32: method_name = "get exchange"; break;
        case 33: method_name = "get routing_key"; break;
        case 34: method_name = "get message_count"; break;
        case 35: method_name = "get queue"; break;
        case 36: method_name = "get properties"; break;
        case 37: method_name = "dp new"; break;
        case 38: method_name = "dp lookup"; break;
        case 39: method_name = "dp destroy"; break;
        case 40: method_name = "initialise"; break;
        case 41: method_name = "selftest"; break;
        case 42: method_name = "terminate"; break;
        case 43: method_name = "show"; break;
        case 44: method_name = "destroy public"; break;
        case 45: method_name = "alloc"; break;
        case 46: method_name = "free"; break;
        case 47: method_name = "cache initialise"; break;
        case 48: method_name = "cache purge"; break;
        case 49: method_name = "cache terminate"; break;
        case 50: method_name = "show animation"; break;
        case 51: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_client_session %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

/*  Waits for methods from the protocol agent.  If the blocking argument
    is true, returns only when receiving a synchronous reply method.  If not,
    returns when any incoming method is received.  Returns 0 if ok, -1 if
    the connection is closed or a blocking wait timed-out.
 */
static int
s_wait_for_methods (
    demo_client_session_t *self,
    int timeout,
    Bool blocking,
    Bool on_content)
{
    smt_method_t
        *smt_method = NULL;
    demo_client_method_t
        *proto_method;
    int
        rc = 0;                         //  OK by default

    assert (!self->method_queue->zombie);
    FOREVER {
        smt_method_unlink (&smt_method);
        smt_method_queue_wait (self->method_queue, timeout);
        smt_method = smt_method_queue_pop (self->method_queue);
        //  If we don't have a method, we timed-out
        if (!smt_method) {
            if (blocking) {
                if (self->method_queue->zombie)
                    self->error_text = "No reply - method queue destroyed";
                else
                    self->error_text = "No reply received - timeout";
                rc = -1;
            }
            break;
        }
        //  ALMOST means we should wait for the next method...
        if (smt_method->result == DEMO_CLIENT_REPLY_ALMOST) {
            proto_method = (demo_client_method_t *) smt_method->data;
            if (proto_method)
                demo_client_method_execute (proto_method, self->connection, self);
        }
        else
        //  INTERN is an internal synchronisation from the agent
        if (smt_method->result == DEMO_CLIENT_REPLY_INTERN)
            break;                      //  We can return to caller
        else
        //  METHOD means the agent is sending us either:
        //    - a sync method, which is a reply to a sync request
        //    - an async method, which we want to process and then continue
        //
        //  We always stop when we get a sync method. If we have an async
        //  method, we stop only if the queue is empty and we're not blocking.
        //  Blocking means we want a sync method within the timeout.
        //
        if (smt_method->result == DEMO_CLIENT_REPLY_METHOD) {
            proto_method = (demo_client_method_t *) smt_method->data;
            if (proto_method) {
                demo_client_method_execute (proto_method, self->connection, self);
                if (proto_method->sync
                || (proto_method->content && on_content))
                    break;              //  Got synchronous method, end
            }
            else
                break;                  //  Synchronisation from agent
        }
        else
        if (smt_method->result == DEMO_CLIENT_REPLY_CLOSED) {
            self->error_text = "session is closed";
            self->alive = FALSE;        //  Session is closed
            rc = -1;                    //  Signal session is closed
            break;                      //  We can return to caller
        }
        else
        //  DIRECT_OK means the direct thread started ok
        if (smt_method->result == DEMO_CLIENT_REPLY_DIRECT_OK)
            break;                      //  We can return to caller
        else
        //  DIRECT_NG means the direct thread did not start
        if (smt_method->result == DEMO_CLIENT_REPLY_DIRECT_NG) {
            self->error_text = "direct connection failed";
            rc = -1;                    //  Signal session is closed
            break;                      //  We can return to caller
        }
        else
        //  DIRECT_MSG means we have a message, process & continue
        if (smt_method->result == DEMO_CLIENT_REPLY_DIRECT_MSG) {
            self_push_arrived (
                self, (demo_content_basic_t *) smt_method->data, NULL, NULL, NULL);
            if (on_content)
                break;                  //  We were waiting for content
        }
        else {
            self->error_text = "Internal error - invalid reply method from protocol agent";
            icl_console_print ("E: invalid reply result %d", smt_method->result);
        }
    }
    smt_method_unlink (&smt_method);
    return (rc);
}

static void
s_process_chrono (
    demo_client_session_t *self,
    demo_content_basic_t *content)
{
}

static void
s_close_dp_sink (ipr_hash_t *hash, void *argument)
{
    demo_client_session_t
        *self = argument;
    smt_thread_t
        *thread = (smt_thread_t *) hash->data;

    //  If it's a sink connection, make sure all published messages are gone
    demo_client_agent_direct_sync (thread);
    s_wait_for_methods (self, self->connection->timeout, FALSE, FALSE);
//amq-599    smt_thread_shut_down (thread);
    smt_thread_unlink (&thread);
}

static void
s_close_dp_feed (ipr_hash_t *hash, void *argument)
{
    smt_thread_t
        *thread = (smt_thread_t *) hash->data;
//amq-599    smt_thread_shut_down (thread);
    smt_thread_unlink (&thread);
}

//  Embed the version information in the resulting binary                      

char *demo_client_session_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_client_session_component  = "demo_client_session ";
char *demo_client_session_version  = "1.0 ";
char *demo_client_session_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_client_session_filename  = "demo_client_session.icl ";
char *demo_client_session_builddate  = "2009/02/19 ";
char *demo_client_session_version_end  = "VeRsIoNeNd:ipc";

