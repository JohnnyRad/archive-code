/*---------------------------------------------------------------------------
    demo_lease.c - demo_lease component

    Implements the Direct Protocol lease for the demo server.
    Creates and resolves leases for sinks (exchanges) and
    feeds (queues).
    Generated from demo_lease.icl by icl_gen using GSL/4.
    
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
#include "demo_lease.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_lease_t

//  Shorthands for class methods                                               

#define self_new            demo_lease_new
#define self_annihilate     demo_lease_annihilate
#define self_search         demo_lease_search
#define self_acquire        demo_lease_acquire
#define self_sink           demo_lease_sink
#define self_initialise     demo_lease_initialise
#define self_terminate      demo_lease_terminate
#define self_selftest       demo_lease_selftest
#define self_remove_from_all_containers  demo_lease_remove_from_all_containers
#define self_show           demo_lease_show
#define self_destroy        demo_lease_destroy
#define self_alloc          demo_lease_alloc
#define self_free           demo_lease_free
#define self_link           demo_lease_link
#define self_unlink         demo_lease_unlink
#define self_cache_initialise  demo_lease_cache_initialise
#define self_cache_purge    demo_lease_cache_purge
#define self_cache_terminate  demo_lease_cache_terminate
#define self_show_animation  demo_lease_show_animation
#define self_new_in_scope   demo_lease_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_NEW))
static icl_stats_t *s_demo_lease_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_DESTROY))
static icl_stats_t *s_demo_lease_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SEARCH))
static icl_stats_t *s_demo_lease_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_ACQUIRE))
static icl_stats_t *s_demo_lease_acquire_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SINK))
static icl_stats_t *s_demo_lease_sink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_INITIALISE))
static icl_stats_t *s_demo_lease_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_TERMINATE))
static icl_stats_t *s_demo_lease_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SELFTEST))
static icl_stats_t *s_demo_lease_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_demo_lease_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SHOW))
static icl_stats_t *s_demo_lease_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_DESTROY_PUBLIC))
static icl_stats_t *s_demo_lease_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_ALLOC))
static icl_stats_t *s_demo_lease_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_FREE))
static icl_stats_t *s_demo_lease_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_LINK))
static icl_stats_t *s_demo_lease_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_UNLINK))
static icl_stats_t *s_demo_lease_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_CACHE_INITIALISE))
static icl_stats_t *s_demo_lease_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_CACHE_PURGE))
static icl_stats_t *s_demo_lease_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_CACHE_TERMINATE))
static icl_stats_t *s_demo_lease_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SHOW_ANIMATION))
static icl_stats_t *s_demo_lease_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_NEW_IN_SCOPE))
static icl_stats_t *s_demo_lease_new_in_scope_stats = NULL;
#endif
#define demo_lease_annihilate(self)     demo_lease_annihilate_ (self, __FILE__, __LINE__)
static void
    demo_lease_annihilate_ (
demo_lease_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    demo_lease_initialise (
void);

static void
    demo_lease_terminate (
void);

#define demo_lease_alloc()              demo_lease_alloc_ (__FILE__, __LINE__)
static demo_lease_t *
    demo_lease_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_lease_free(self)           demo_lease_free_ (self, __FILE__, __LINE__)
static void
    demo_lease_free_ (
demo_lease_t * self,                    //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    demo_lease_cache_initialise (
void);

static void
    demo_lease_cache_purge (
void);

static void
    demo_lease_cache_terminate (
void);

Bool
    demo_lease_animating = TRUE;        //  Animation enabled by default
static Bool
    s_demo_lease_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_demo_lease_mutex       = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static demo_lease_table_t
    *s_demo_lease_table;                //  The table of existing items
/*  -------------------------------------------------------------------------
    demo_lease_new

    Type: Component method
    Creates and initialises a new demo_lease_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

demo_lease_t *
    demo_lease_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Sink or feed name
    int type,                           //  DP_SINK or DP_FEED
    demo_server_channel_t * channel     //  Parent channel
)
{
#define table s_demo_lease_table
#define key self->name
apr_time_t
    time_now;
    demo_lease_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_NEW))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" name=\"%s\""
" type=\"%i\""
" channel=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, name, type, channel);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_NEW))
    icl_trace_record (NULL, demo_lease_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_NEW))
    icl_stats_inc ("demo_lease_new", &s_demo_lease_new_stats);
#endif

if (!s_demo_lease_active)
    self_initialise ();
    self = demo_lease_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_LEASE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, demo_lease_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
//

assert (type == DP_SINK || type == DP_FEED);
self->type = type;
self->channel = demo_server_channel_link (channel);
self->connection = demo_server_connection_link (channel->connection);
time_now = apr_time_now ();

if (type == DP_SINK) {
    self->sink = demo_exchange_search (name);
    if (self->sink)
        icl_shortstr_fmt (self->name, "S-%08X%08X-%s",
            (qbyte) (time_now >> 32), (qbyte) time_now & 0xFFFFFFFF, self->sink->name);
    else
        self_destroy (&self);
}
else
if (type == DP_FEED) {
    //  Only allow one lease per queue
    self->feed = demo_queue_search (name);
    if (self->feed && !self->feed->lease) {
        self->feed->lease = self;
        icl_shortstr_fmt (self->name, "F-%08X%08X-%s",
            (qbyte) (time_now >> 32), (qbyte) time_now & 0xFFFFFFFF, self->feed->name);
    }
    else
        self_destroy (&self);
}
if (table && self && demo_lease_table_insert (table, key, self))
    demo_lease_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_NEW))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_NEW))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" name=\"%s\""
" type=\"%i\""
" channel=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, name, type, channel, self);
#endif


    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    demo_lease_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_lease_annihilate_ (
    demo_lease_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    int
        history_last;
#endif

    demo_lease_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_DESTROY))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_DESTROY))
    icl_trace_record (NULL, demo_lease_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_DESTROY))
    icl_stats_inc ("demo_lease_annihilate", &s_demo_lease_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % DEMO_LEASE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % DEMO_LEASE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % DEMO_LEASE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % DEMO_LEASE_HISTORY_LENGTH] = self->links;
#endif

    DEMO_LEASE_ASSERT_SANE (self);
    demo_lease_remove_from_all_containers (self);

demo_server_channel_unlink (&self->channel);
demo_server_connection_unlink (&self->connection);
demo_exchange_unlink (&self->sink);
demo_queue_unlink (&self->feed);
smt_thread_unlink (&self->thread);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_DESTROY))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_DESTROY))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_destroy_finish"
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
    demo_lease_search

    Type: Component method
    -------------------------------------------------------------------------
 */

demo_lease_t *
    demo_lease_search (
    char * name                         //  Exchange name
)
{
    demo_lease_t *
        self;                           //  The found object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_SEARCH))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_search_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SEARCH))
    icl_trace_record (NULL, demo_lease_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SEARCH))
    icl_stats_inc ("demo_lease_search", &s_demo_lease_search_stats);
#endif

if (!s_demo_lease_active)
    demo_lease_initialise ();
self = demo_lease_table_search (s_demo_lease_table, name);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SEARCH))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_SEARCH))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_search_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    demo_lease_acquire

    Type: Component method
    Accepts a demo_lease_t reference and returns zero in case of success,
    1 in case of errors.
    Acquires the lease; returns -1 if the lease was already acquired by
    another thread.  The acquiring thread will receive messages when the
    lease is for a feed.
    -------------------------------------------------------------------------
 */

int
    demo_lease_acquire (
    demo_lease_t * self,                //  Reference to object
    smt_thread_t * thread,              //  Not documented
    smt_socket_t * socket               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_ACQUIRE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_acquire_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" socket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, socket);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_ACQUIRE))
    icl_trace_record (NULL, demo_lease_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_ACQUIRE))
    icl_stats_inc ("demo_lease_acquire", &s_demo_lease_acquire_stats);
#endif

DEMO_LEASE_ASSERT_SANE (self);
if (!self->zombie) {

if (self->thread)
    rc = -1;                        //  Already acquired
self->thread = smt_thread_link (thread);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_ACQUIRE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_ACQUIRE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_acquire_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" socket=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, socket, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_lease_sink

    Type: Component method
    Accepts a demo_lease_t reference and returns zero in case of success,
    1 in case of errors.
    Send a content to a sink.  This function does the application specific
    processing for a sink, which in this instance is an exchange.
    -------------------------------------------------------------------------
 */

int
    demo_lease_sink (
    demo_lease_t * self,                //  Reference to object
    demo_content_basic_t * content,     //  Not documented
    byte options                        //  Publish options octet
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_SINK))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_sink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SINK))
    icl_trace_record (NULL, demo_lease_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SINK))
    icl_stats_inc ("demo_lease_sink", &s_demo_lease_sink_stats);
#endif

DEMO_LEASE_ASSERT_SANE (self);
if (!self->zombie) {

//
demo_exchange_publish (self->sink, self->channel, content);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SINK))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_SINK))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_sink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" content=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, content, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_lease_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_lease_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_INITIALISE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_INITIALISE))
    icl_trace_record (NULL, demo_lease_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_INITIALISE))
    icl_stats_inc ("demo_lease_initialise", &s_demo_lease_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_demo_lease_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_demo_lease_mutex)
            s_demo_lease_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_demo_lease_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_demo_lease_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_demo_lease_table = demo_lease_table_new ();
            s_demo_lease_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_demo_lease_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_INITIALISE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_INITIALISE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_initialise_finish"
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
    demo_lease_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_lease_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_TERMINATE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_TERMINATE))
    icl_trace_record (NULL, demo_lease_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_TERMINATE))
    icl_stats_inc ("demo_lease_terminate", &s_demo_lease_terminate_stats);
#endif

if (s_demo_lease_active) {

demo_lease_table_destroy (&s_demo_lease_table);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_demo_lease_mutex);
#endif
        s_demo_lease_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_TERMINATE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_TERMINATE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_terminate_finish"
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
    demo_lease_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_lease_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_SELFTEST))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SELFTEST))
    icl_trace_record (NULL, demo_lease_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SELFTEST))
    icl_stats_inc ("demo_lease_selftest", &s_demo_lease_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SELFTEST))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_SELFTEST))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_selftest_finish"
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
    demo_lease_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    demo_lease_remove_from_all_containers (
    demo_lease_t * self                 //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_lease_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("demo_lease_remove_from_all_containers", &s_demo_lease_remove_from_all_containers_stats);
#endif

DEMO_LEASE_ASSERT_SANE (self);
demo_lease_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_remove_from_all_containers_finish"
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
    demo_lease_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_lease_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_lease_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_SHOW))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SHOW))
    icl_trace_record (NULL, demo_lease_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SHOW))
    icl_stats_inc ("demo_lease_show", &s_demo_lease_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <demo_lease zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    if (self->history_last > DEMO_LEASE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % DEMO_LEASE_HISTORY_LENGTH;
        self->history_last %= DEMO_LEASE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % DEMO_LEASE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </demo_lease>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SHOW))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_SHOW))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_show_finish"
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
    demo_lease_destroy

    Type: Component method
    Destroys a demo_lease_t object. Takes the address of a
    demo_lease_t reference (a pointer to a pointer) and nullifies the
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
    demo_lease_destroy_ (
    demo_lease_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    demo_lease_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_DESTROY_PUBLIC))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_lease_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_DESTROY_PUBLIC))
    icl_stats_inc ("demo_lease_destroy", &s_demo_lease_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        demo_lease_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on demo_lease object");
        demo_lease_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        demo_lease_free_ ((demo_lease_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_DESTROY_PUBLIC))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_destroy_public_finish"
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
    demo_lease_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_lease_t *
    demo_lease_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_lease_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_ALLOC))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_ALLOC))
    icl_trace_record (NULL, demo_lease_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_ALLOC))
    icl_stats_inc ("demo_lease_alloc", &s_demo_lease_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_lease_cache_initialise ();

self = (demo_lease_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_lease_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_ALLOC))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_ALLOC))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_alloc_finish"
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
    demo_lease_free

    Type: Component method
    Freess a demo_lease_t object.
    -------------------------------------------------------------------------
 */

static void
    demo_lease_free_ (
    demo_lease_t * self,                //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_FREE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_FREE))
    icl_trace_record (NULL, demo_lease_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_FREE))
    icl_stats_inc ("demo_lease_free", &s_demo_lease_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_LEASE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_LEASE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_LEASE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % DEMO_LEASE_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (demo_lease_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_lease_t));
        self->object_tag = DEMO_LEASE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_FREE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_FREE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_free_finish"
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
    demo_lease_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

demo_lease_t *
    demo_lease_link_ (
    demo_lease_t * self,                //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_LINK))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_LINK))
    icl_trace_record (NULL, demo_lease_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_LINK))
    icl_stats_inc ("demo_lease_link", &s_demo_lease_link_stats);
#endif

    if (self) {
        DEMO_LEASE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_LEASE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_LEASE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_LEASE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % DEMO_LEASE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_LINK))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_LINK))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_link_finish"
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
    demo_lease_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    demo_lease_unlink_ (
    demo_lease_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
    int
        history_last;
#endif

    demo_lease_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_UNLINK))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_UNLINK))
    icl_trace_record (NULL, demo_lease_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_UNLINK))
    icl_stats_inc ("demo_lease_unlink", &s_demo_lease_unlink_stats);
#endif

    if (self) {
        DEMO_LEASE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on demo_lease object");
            demo_lease_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_LEASE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_LEASE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_LEASE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_LEASE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % DEMO_LEASE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            demo_lease_annihilate_ (self_p, file, line);
        demo_lease_free_ ((demo_lease_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_UNLINK))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_UNLINK))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_unlink_finish"
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
    demo_lease_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_lease_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_CACHE_INITIALISE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_lease_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_CACHE_INITIALISE))
    icl_stats_inc ("demo_lease_cache_initialise", &s_demo_lease_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_lease_t));
icl_system_register (demo_lease_cache_purge, demo_lease_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_CACHE_INITIALISE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_cache_initialise_finish"
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
    demo_lease_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_lease_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_CACHE_PURGE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_PURGE))
    icl_trace_record (NULL, demo_lease_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_CACHE_PURGE))
    icl_stats_inc ("demo_lease_cache_purge", &s_demo_lease_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_PURGE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_CACHE_PURGE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_cache_purge_finish"
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
    demo_lease_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_lease_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_CACHE_TERMINATE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_lease_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_CACHE_TERMINATE))
    icl_stats_inc ("demo_lease_cache_terminate", &s_demo_lease_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_CACHE_TERMINATE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_cache_terminate_finish"
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
    demo_lease_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_lease_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_SHOW_ANIMATION))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_lease_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_SHOW_ANIMATION))
    icl_stats_inc ("demo_lease_show_animation", &s_demo_lease_show_animation_stats);
#endif

demo_lease_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_SHOW_ANIMATION))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_show_animation_finish"
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
    demo_lease_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_lease_new_in_scope_ (
    demo_lease_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Sink or feed name
    int type,                           //  DP_SINK or DP_FEED
    demo_server_channel_t * channel     //  Parent channel
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_LEASE)  ||  defined (BASE_ANIMATE_DEMO_LEASE_NEW_IN_SCOPE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" type=\"%i\""
" channel=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, name, type, channel);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_lease_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_LEASE)  ||  defined (BASE_STATS_DEMO_LEASE_NEW_IN_SCOPE))
    icl_stats_inc ("demo_lease_new_in_scope", &s_demo_lease_new_in_scope_stats);
#endif

*self_p = demo_lease_new_ (file,line,name,type,channel);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_lease_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_lease_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_LEASE)   || defined (BASE_ANIMATE_DEMO_LEASE_NEW_IN_SCOPE))
    if (demo_lease_animating)
        icl_console_print ("<demo_lease_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" type=\"%i\""
" channel=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, name, type, channel, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_LEASE)   || defined (BASE_TRACE_DEMO_LEASE_NEW)   || defined (BASE_TRACE_DEMO_LEASE_DESTROY)   || defined (BASE_TRACE_DEMO_LEASE_SEARCH)   || defined (BASE_TRACE_DEMO_LEASE_ACQUIRE)   || defined (BASE_TRACE_DEMO_LEASE_SINK)   || defined (BASE_TRACE_DEMO_LEASE_INITIALISE)   || defined (BASE_TRACE_DEMO_LEASE_TERMINATE)   || defined (BASE_TRACE_DEMO_LEASE_SELFTEST)   || defined (BASE_TRACE_DEMO_LEASE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_DEMO_LEASE_SHOW)   || defined (BASE_TRACE_DEMO_LEASE_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_LEASE_ALLOC)   || defined (BASE_TRACE_DEMO_LEASE_FREE)   || defined (BASE_TRACE_DEMO_LEASE_LINK)   || defined (BASE_TRACE_DEMO_LEASE_UNLINK)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_LEASE_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_LEASE_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_LEASE_NEW_IN_SCOPE) )
void
demo_lease_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "search"; break;
        case 4: method_name = "acquire"; break;
        case 5: method_name = "sink"; break;
        case 6: method_name = "initialise"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "selftest"; break;
        case 9: method_name = "remove from all containers"; break;
        case 10: method_name = "show"; break;
        case 11: method_name = "destroy public"; break;
        case 12: method_name = "alloc"; break;
        case 13: method_name = "free"; break;
        case 14: method_name = "link"; break;
        case 15: method_name = "unlink"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "show animation"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_lease %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_lease_version_start     = "VeRsIoNsTaRt:ipc";
char *demo_lease_component         = "demo_lease ";
char *demo_lease_version           = "1.0 ";
char *demo_lease_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_lease_filename          = "demo_lease.icl ";
char *demo_lease_builddate         = "2009/02/19 ";
char *demo_lease_version_end       = "VeRsIoNeNd:ipc";

