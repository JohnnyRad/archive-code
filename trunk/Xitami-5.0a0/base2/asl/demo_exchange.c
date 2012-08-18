/*---------------------------------------------------------------------------
    demo_exchange.c - demo_exchange component

    This class implements the ASL demo server exchange class (this is a
    fanout exchange).
    Generated from demo_exchange.icl by smt_object_gen using GSL/4.
    
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
#include "demo_exchange.h"              //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_exchange_t

//  Shorthands for class methods                                               

#define self_new            demo_exchange_new
#define self_annihilate     demo_exchange_annihilate
#define self_search         demo_exchange_search
#define self_bind           demo_exchange_bind
#define self_publish        demo_exchange_publish
#define self_initialise     demo_exchange_initialise
#define self_terminate      demo_exchange_terminate
#define self_selftest       demo_exchange_selftest
#define self_remove_from_all_containers  demo_exchange_remove_from_all_containers
#define self_show           demo_exchange_show
#define self_destroy        demo_exchange_destroy
#define self_unlink         demo_exchange_unlink
#define self_show_animation  demo_exchange_show_animation
#define self_free           demo_exchange_free
#define self_alloc          demo_exchange_alloc
#define self_link           demo_exchange_link
#define self_cache_initialise  demo_exchange_cache_initialise
#define self_cache_purge    demo_exchange_cache_purge
#define self_cache_terminate  demo_exchange_cache_terminate
#define self_new_in_scope   demo_exchange_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_NEW))
static icl_stats_t *s_demo_exchange_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_DESTROY))
static icl_stats_t *s_demo_exchange_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SEARCH))
static icl_stats_t *s_demo_exchange_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_BIND))
static icl_stats_t *s_demo_exchange_bind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_PUBLISH))
static icl_stats_t *s_demo_exchange_publish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_INITIALISE))
static icl_stats_t *s_demo_exchange_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_TERMINATE))
static icl_stats_t *s_demo_exchange_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SELFTEST))
static icl_stats_t *s_demo_exchange_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_demo_exchange_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SHOW))
static icl_stats_t *s_demo_exchange_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_DESTROY_PUBLIC))
static icl_stats_t *s_demo_exchange_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_UNLINK))
static icl_stats_t *s_demo_exchange_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SHOW_ANIMATION))
static icl_stats_t *s_demo_exchange_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_FREE))
static icl_stats_t *s_demo_exchange_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_ALLOC))
static icl_stats_t *s_demo_exchange_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_LINK))
static icl_stats_t *s_demo_exchange_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_CACHE_INITIALISE))
static icl_stats_t *s_demo_exchange_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_CACHE_PURGE))
static icl_stats_t *s_demo_exchange_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_CACHE_TERMINATE))
static icl_stats_t *s_demo_exchange_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_NEW_IN_SCOPE))
static icl_stats_t *s_demo_exchange_new_in_scope_stats = NULL;
#endif
#define demo_exchange_annihilate(self)  demo_exchange_annihilate_ (self, __FILE__, __LINE__)
static int
    demo_exchange_annihilate_ (
demo_exchange_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    demo_exchange_initialise (
void);

#define demo_exchange_alloc()           demo_exchange_alloc_ (__FILE__, __LINE__)
static demo_exchange_t *
    demo_exchange_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    demo_exchange_cache_initialise (
void);

static void
    demo_exchange_cache_purge (
void);

static void
    demo_exchange_cache_terminate (
void);

Bool
    demo_exchange_animating = TRUE;     //  Animation enabled by default
static Bool
    s_demo_exchange_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_demo_exchange_mutex    = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static demo_exchange_table_t
    *s_demo_exchange_table;             //  The table of existing items
/*  -------------------------------------------------------------------------
    demo_exchange_new

    Type: Component method
    Creates and initialises a new demo_exchange_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

demo_exchange_t *
    demo_exchange_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Exchange name
    Bool durable,                       //  Is exchange durable?
    Bool auto_delete                    //  Auto-delete unused exchange?
)
{
#define table s_demo_exchange_table
#define key name
    demo_exchange_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_NEW))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" name=\"%s\""
" durable=\"%i\""
" auto_delete=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, name, durable, auto_delete);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_NEW))
    icl_trace_record (NULL, demo_exchange_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_NEW))
    icl_stats_inc ("demo_exchange_new", &s_demo_exchange_new_stats);
#endif

if (!s_demo_exchange_active)
    self_initialise ();
    self = demo_exchange_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_EXCHANGE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, demo_exchange_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread = demo_exchange_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->name        = icl_mem_strdup (name);
self->durable     = durable;
self->auto_delete = auto_delete;
self->queue_list  = demo_queue_list_new ();
if (table && self && demo_exchange_table_insert (table, key, self))
    demo_exchange_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_NEW))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_NEW))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" name=\"%s\""
" durable=\"%i\""
" auto_delete=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, name, durable, auto_delete, self);
#endif


    return (self);
}
#undef table
#undef key
/*  -------------------------------------------------------------------------
    demo_exchange_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    demo_exchange_annihilate_ (
    demo_exchange_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    int
        history_last;
#endif

    demo_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_DESTROY))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_DESTROY))
    icl_trace_record (NULL, demo_exchange_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_DESTROY))
    icl_stats_inc ("demo_exchange_annihilate", &s_demo_exchange_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (demo_exchange_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to demo_exchange agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_DESTROY))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_DESTROY))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_destroy_finish"
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
    demo_exchange_search

    Type: Component method
    -------------------------------------------------------------------------
 */

demo_exchange_t *
    demo_exchange_search (
    char * name                         //  Exchange name
)
{
    demo_exchange_t *
        self;                           //  The found object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_SEARCH))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_search_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SEARCH))
    icl_trace_record (NULL, demo_exchange_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SEARCH))
    icl_stats_inc ("demo_exchange_search", &s_demo_exchange_search_stats);
#endif

//
if (!s_demo_exchange_active)
    demo_exchange_initialise ();

self = demo_exchange_table_search (s_demo_exchange_table, name);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SEARCH))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_SEARCH))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_search_finish"
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
    demo_exchange_bind

    Type: Component method
    Accepts a demo_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    demo_exchange_bind (
    demo_exchange_t * self,             //  Reference to object
    demo_server_channel_t * channel,    //  The channel in question
    demo_queue_t * queue,               //  The queue to bind
    icl_longstr_t * arguments           //  Bind arguments
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_BIND))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_bind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" queue=\"%pp\""
" arguments=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, queue, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_BIND))
    icl_trace_record (NULL, demo_exchange_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_BIND))
    icl_stats_inc ("demo_exchange_bind", &s_demo_exchange_bind_stats);
#endif

DEMO_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (demo_exchange_agent_bind (self->thread,channel,queue,arguments)) {
        //icl_console_print ("Error sending 'bind' method to demo_exchange agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_BIND))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_BIND))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_bind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" queue=\"%pp\""
" arguments=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, queue, arguments, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_exchange_publish

    Type: Component method
    Accepts a demo_exchange_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Sends the content to all registered queues.
    -------------------------------------------------------------------------
 */

int
    demo_exchange_publish (
    demo_exchange_t * self,             //  Reference to object
    demo_server_channel_t * channel,    //  The channel in question
    demo_content_basic_t * content      //  The message content
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_PUBLISH))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_publish_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" content=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, content);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_PUBLISH))
    icl_trace_record (NULL, demo_exchange_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_PUBLISH))
    icl_stats_inc ("demo_exchange_publish", &s_demo_exchange_publish_stats);
#endif

DEMO_EXCHANGE_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (demo_exchange_agent_publish (self->thread,channel,content)) {
        //icl_console_print ("Error sending 'publish' method to demo_exchange agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_PUBLISH))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_PUBLISH))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_publish_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" channel=\"%pp\""
" content=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, channel, content, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_exchange_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_exchange_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_INITIALISE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_INITIALISE))
    icl_trace_record (NULL, demo_exchange_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_INITIALISE))
    icl_stats_inc ("demo_exchange_initialise", &s_demo_exchange_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_demo_exchange_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_demo_exchange_mutex)
            s_demo_exchange_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_demo_exchange_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_demo_exchange_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

demo_exchange_agent_init ();

s_demo_exchange_table = demo_exchange_table_new ();
            s_demo_exchange_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_demo_exchange_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_INITIALISE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_INITIALISE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_initialise_finish"
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
    demo_exchange_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_exchange_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_TERMINATE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TERMINATE))
    icl_trace_record (NULL, demo_exchange_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_TERMINATE))
    icl_stats_inc ("demo_exchange_terminate", &s_demo_exchange_terminate_stats);
#endif

if (s_demo_exchange_active) {

demo_exchange_table_destroy (&s_demo_exchange_table);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_demo_exchange_mutex);
#endif
        s_demo_exchange_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TERMINATE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_TERMINATE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_terminate_finish"
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
    demo_exchange_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_exchange_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_SELFTEST))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SELFTEST))
    icl_trace_record (NULL, demo_exchange_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SELFTEST))
    icl_stats_inc ("demo_exchange_selftest", &s_demo_exchange_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SELFTEST))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_SELFTEST))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_selftest_finish"
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
    demo_exchange_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    demo_exchange_remove_from_all_containers (
    demo_exchange_t * self              //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_exchange_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("demo_exchange_remove_from_all_containers", &s_demo_exchange_remove_from_all_containers_stats);
#endif

DEMO_EXCHANGE_ASSERT_SANE (self);
demo_exchange_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_remove_from_all_containers_finish"
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
    demo_exchange_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_exchange_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_exchange_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_SHOW))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SHOW))
    icl_trace_record (NULL, demo_exchange_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SHOW))
    icl_stats_inc ("demo_exchange_show", &s_demo_exchange_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <demo_exchange zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    if (self->history_last > DEMO_EXCHANGE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % DEMO_EXCHANGE_HISTORY_LENGTH;
        self->history_last %= DEMO_EXCHANGE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % DEMO_EXCHANGE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </demo_exchange>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SHOW))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_SHOW))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_show_finish"
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
    demo_exchange_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_exchange_destroy_ (
    demo_exchange_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_DESTROY_PUBLIC))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_exchange_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_DESTROY_PUBLIC))
    icl_stats_inc ("demo_exchange_destroy", &s_demo_exchange_destroy_stats);
#endif

    if (self) {
demo_exchange_remove_from_all_containers (self);
        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            rc = demo_exchange_annihilate_ (self_p, file, line);
        else
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
            demo_exchange_free (self);
        *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_DESTROY_PUBLIC))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_destroy_public_finish"
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
    demo_exchange_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    demo_exchange_unlink_ (
    demo_exchange_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    int
        history_last;
#endif
    demo_exchange_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_UNLINK))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_UNLINK))
    icl_trace_record (NULL, demo_exchange_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_UNLINK))
    icl_stats_inc ("demo_exchange_unlink", &s_demo_exchange_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on demo_exchange object");
            demo_exchange_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                demo_exchange_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                demo_exchange_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_UNLINK))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_UNLINK))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_unlink_finish"
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
    demo_exchange_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_exchange_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_SHOW_ANIMATION))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_exchange_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_SHOW_ANIMATION))
    icl_stats_inc ("demo_exchange_show_animation", &s_demo_exchange_show_animation_stats);
#endif

demo_exchange_animating = enabled;

demo_exchange_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_SHOW_ANIMATION))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_show_animation_finish"
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
    demo_exchange_free

    Type: Component method
    Freess a demo_exchange_t object.
    -------------------------------------------------------------------------
 */

void
    demo_exchange_free_ (
    demo_exchange_t * self,             //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_FREE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_FREE))
    icl_trace_record (NULL, demo_exchange_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_FREE))
    icl_stats_inc ("demo_exchange_free", &s_demo_exchange_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (demo_exchange_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_exchange_t));
        self->object_tag = DEMO_EXCHANGE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_FREE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_FREE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_free_finish"
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
    demo_exchange_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_exchange_t *
    demo_exchange_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_exchange_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_ALLOC))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_ALLOC))
    icl_trace_record (NULL, demo_exchange_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_ALLOC))
    icl_stats_inc ("demo_exchange_alloc", &s_demo_exchange_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_exchange_cache_initialise ();

self = (demo_exchange_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_exchange_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_ALLOC))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_ALLOC))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_alloc_finish"
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
    demo_exchange_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

demo_exchange_t *
    demo_exchange_link_ (
    demo_exchange_t * self,             //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_LINK))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_LINK))
    icl_trace_record (NULL, demo_exchange_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_LINK))
    icl_stats_inc ("demo_exchange_link", &s_demo_exchange_link_stats);
#endif

    if (self) {
        DEMO_EXCHANGE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_EXCHANGE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % DEMO_EXCHANGE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_LINK))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_LINK))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_link_finish"
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
    demo_exchange_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_exchange_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_CACHE_INITIALISE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_exchange_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_CACHE_INITIALISE))
    icl_stats_inc ("demo_exchange_cache_initialise", &s_demo_exchange_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_exchange_t));
icl_system_register (demo_exchange_cache_purge, demo_exchange_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_CACHE_INITIALISE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_cache_initialise_finish"
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
    demo_exchange_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_exchange_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_CACHE_PURGE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_PURGE))
    icl_trace_record (NULL, demo_exchange_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_CACHE_PURGE))
    icl_stats_inc ("demo_exchange_cache_purge", &s_demo_exchange_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_PURGE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_CACHE_PURGE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_cache_purge_finish"
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
    demo_exchange_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_exchange_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_CACHE_TERMINATE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_exchange_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_CACHE_TERMINATE))
    icl_stats_inc ("demo_exchange_cache_terminate", &s_demo_exchange_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_CACHE_TERMINATE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_cache_terminate_finish"
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
    demo_exchange_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_exchange_new_in_scope_ (
    demo_exchange_t * * self_p,         //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * name,                        //  Exchange name
    Bool durable,                       //  Is exchange durable?
    Bool auto_delete                    //  Auto-delete unused exchange?
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE)  ||  defined (BASE_ANIMATE_DEMO_EXCHANGE_NEW_IN_SCOPE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" durable=\"%i\""
" auto_delete=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, name, durable, auto_delete);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_exchange_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_EXCHANGE)  ||  defined (BASE_STATS_DEMO_EXCHANGE_NEW_IN_SCOPE))
    icl_stats_inc ("demo_exchange_new_in_scope", &s_demo_exchange_new_in_scope_stats);
#endif

*self_p = demo_exchange_new_ (file,line,name,durable,auto_delete);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_exchange_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_exchange_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE)   || defined (BASE_ANIMATE_DEMO_EXCHANGE_NEW_IN_SCOPE))
    if (demo_exchange_animating)
        icl_console_print ("<demo_exchange_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" name=\"%s\""
" durable=\"%i\""
" auto_delete=\"%i\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, name, durable, auto_delete, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_EXCHANGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_NEW)   || defined (BASE_TRACE_DEMO_EXCHANGE_DESTROY)   || defined (BASE_TRACE_DEMO_EXCHANGE_SEARCH)   || defined (BASE_TRACE_DEMO_EXCHANGE_BIND)   || defined (BASE_TRACE_DEMO_EXCHANGE_PUBLISH)   || defined (BASE_TRACE_DEMO_EXCHANGE_INITIALISE)   || defined (BASE_TRACE_DEMO_EXCHANGE_TERMINATE)   || defined (BASE_TRACE_DEMO_EXCHANGE_SELFTEST)   || defined (BASE_TRACE_DEMO_EXCHANGE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_DEMO_EXCHANGE_SHOW)   || defined (BASE_TRACE_DEMO_EXCHANGE_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_EXCHANGE_UNLINK)   || defined (BASE_TRACE_DEMO_EXCHANGE_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_EXCHANGE_FREE)   || defined (BASE_TRACE_DEMO_EXCHANGE_ALLOC)   || defined (BASE_TRACE_DEMO_EXCHANGE_LINK)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_EXCHANGE_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_EXCHANGE_NEW_IN_SCOPE) )
void
demo_exchange_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "search"; break;
        case 4: method_name = "bind"; break;
        case 5: method_name = "publish"; break;
        case 6: method_name = "initialise"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "selftest"; break;
        case 9: method_name = "remove from all containers"; break;
        case 10: method_name = "show"; break;
        case 11: method_name = "destroy public"; break;
        case 12: method_name = "unlink"; break;
        case 13: method_name = "show animation"; break;
        case 14: method_name = "free"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "link"; break;
        case 17: method_name = "cache initialise"; break;
        case 18: method_name = "cache purge"; break;
        case 19: method_name = "cache terminate"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_exchange %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_exchange_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_exchange_component      = "demo_exchange ";
char *demo_exchange_version        = "1.0 ";
char *demo_exchange_copyright      = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_exchange_filename       = "demo_exchange.icl ";
char *demo_exchange_builddate      = "2009/02/19 ";
char *demo_exchange_version_end    = "VeRsIoNeNd:ipc";

