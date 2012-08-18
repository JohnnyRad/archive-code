/*---------------------------------------------------------------------------
    demo_server_connection.c - demo_server_connection component

    This class implements the ASL connection class for the demo server.
    Generated from demo_server_connection.icl by icl_gen using GSL/4.
    
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
#include "demo_server_connection.h"     //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_server_connection_t

//  Shorthands for class methods                                               

#define self_start_ok       demo_server_connection_start_ok
#define self_initialise     demo_server_connection_initialise
#define self_new            demo_server_connection_new
#define self_annihilate     demo_server_connection_annihilate
#define self_free           demo_server_connection_free
#define self_set_address    demo_server_connection_set_address
#define self_set_trace      demo_server_connection_set_trace
#define self_kill           demo_server_connection_kill
#define self_ready          demo_server_connection_ready
#define self_raise_exception  demo_server_connection_raise_exception
#define self_error          demo_server_connection_error
#define self_exception_raised  demo_server_connection_exception_raised
#define self_tune_ok        demo_server_connection_tune_ok
#define self_open           demo_server_connection_open
#define self_selftest       demo_server_connection_selftest
#define self_count          demo_server_connection_count
#define self_remove_from_all_containers  demo_server_connection_remove_from_all_containers
#define self_show           demo_server_connection_show
#define self_terminate      demo_server_connection_terminate
#define self_destroy        demo_server_connection_destroy
#define self_alloc          demo_server_connection_alloc
#define self_read_lock      demo_server_connection_read_lock
#define self_write_lock     demo_server_connection_write_lock
#define self_unlock         demo_server_connection_unlock
#define self_link           demo_server_connection_link
#define self_unlink         demo_server_connection_unlink
#define self_cache_initialise  demo_server_connection_cache_initialise
#define self_cache_purge    demo_server_connection_cache_purge
#define self_cache_terminate  demo_server_connection_cache_terminate
#define self_show_animation  demo_server_connection_show_animation
#define self_new_in_scope   demo_server_connection_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_START_OK))
static icl_stats_t *s_demo_server_connection_start_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_INITIALISE))
static icl_stats_t *s_demo_server_connection_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_NEW))
static icl_stats_t *s_demo_server_connection_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_DESTROY))
static icl_stats_t *s_demo_server_connection_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_FREE))
static icl_stats_t *s_demo_server_connection_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SET_ADDRESS))
static icl_stats_t *s_demo_server_connection_set_address_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SET_TRACE))
static icl_stats_t *s_demo_server_connection_set_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_KILL))
static icl_stats_t *s_demo_server_connection_kill_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_READY))
static icl_stats_t *s_demo_server_connection_ready_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION))
static icl_stats_t *s_demo_server_connection_raise_exception_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_ERROR))
static icl_stats_t *s_demo_server_connection_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED))
static icl_stats_t *s_demo_server_connection_exception_raised_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_TUNE_OK))
static icl_stats_t *s_demo_server_connection_tune_ok_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_OPEN))
static icl_stats_t *s_demo_server_connection_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SELFTEST))
static icl_stats_t *s_demo_server_connection_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_COUNT))
static icl_stats_t *s_demo_server_connection_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_demo_server_connection_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SHOW))
static icl_stats_t *s_demo_server_connection_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_TERMINATE))
static icl_stats_t *s_demo_server_connection_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC))
static icl_stats_t *s_demo_server_connection_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_ALLOC))
static icl_stats_t *s_demo_server_connection_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_READ_LOCK))
static icl_stats_t *s_demo_server_connection_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_WRITE_LOCK))
static icl_stats_t *s_demo_server_connection_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_UNLOCK))
static icl_stats_t *s_demo_server_connection_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LINK))
static icl_stats_t *s_demo_server_connection_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_UNLINK))
static icl_stats_t *s_demo_server_connection_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_CACHE_INITIALISE))
static icl_stats_t *s_demo_server_connection_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_CACHE_PURGE))
static icl_stats_t *s_demo_server_connection_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_CACHE_TERMINATE))
static icl_stats_t *s_demo_server_connection_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SHOW_ANIMATION))
static icl_stats_t *s_demo_server_connection_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE))
static icl_stats_t *s_demo_server_connection_new_in_scope_stats = NULL;
#endif
static void
    demo_server_connection_initialise (
void);

#define demo_server_connection_annihilate(self)  demo_server_connection_annihilate_ (self, __FILE__, __LINE__)
static void
    demo_server_connection_annihilate_ (
demo_server_connection_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_server_connection_free(self)  demo_server_connection_free_ (self, __FILE__, __LINE__)
static void
    demo_server_connection_free_ (
demo_server_connection_t * self,        //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    demo_server_connection_terminate (
void);

#define demo_server_connection_alloc()  demo_server_connection_alloc_ (__FILE__, __LINE__)
static demo_server_connection_t *
    demo_server_connection_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    demo_server_connection_cache_initialise (
void);

static void
    demo_server_connection_cache_purge (
void);

static void
    demo_server_connection_cache_terminate (
void);

Bool
    demo_server_connection_animating = TRUE;  //  Animation enabled by default
static Bool
    s_demo_server_connection_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_demo_server_connection_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_demo_server_connection_count = 0;
static int
    s_auth_plain (demo_server_connection_t *self, demo_server_connection_start_ok_t *method);
static uint
    s_collect_plain_token (byte *data, char *token, uint token_end);
static volatile qbyte
    s_context_seq_lo,                   //  Next context sequence id
    s_context_seq_hi;                   //  High part (64-bits)
//  Sets and returns connection group, zero indicating an error

static int s_auth_plain (
    demo_server_connection_t *self,
    demo_server_connection_start_ok_t *method)
{
    icl_shortstr_t
        login,
        password;
    uint
        token_null;

    //  method->response holds PLAIN data in format "[NULL]login[NULL]password"
    token_null = s_collect_plain_token (
        method->response->data, password, method->response->cur_size);
    if (token_null) 
        s_collect_plain_token (method->response->data, login, token_null);

    if (strnull (login) || strnull (password)) {
        self_raise_exception (self, ASL_SYNTAX_ERROR, 
            "Missing authentication data",
            DEMO_SERVER_CONNECTION, DEMO_SERVER_CONNECTION_START_OK);
        return (0);
    }
    if (streq (login, "guest") && streq (password, "guest"))
        return (TRUE);
    else
        return (FALSE);
}

//  Collects a token, returns offset of null octet at start
static uint
s_collect_plain_token (byte *data, char *token, uint token_end)
{
    uint
        token_null,
        token_size;

    //  Find start of token, scanning back from known end
    token_null = --token_end;
    while (token_null && data [token_null])
        token_null--;

    strclr (token);
    //  Token start must point to a null octet before the string
    token_size = token_end - token_null;
    if (token_size > ICL_SHORTSTR_MAX)
        smt_log_print (demo_broker->alert_log,
            "W: client used over-long authentication value - rejected");
    else {
        memcpy (token, data + token_null + 1, token_size);
        token [token_size] = 0;
    }
    return (token_null);
}
/*  -------------------------------------------------------------------------
    demo_server_connection_start_ok

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the ASL Connection.Start-Ok protocol method.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_start_ok (
    demo_server_connection_t * self,    //  Reference to object
    demo_server_connection_start_ok_t * method  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

asl_field_list_t
    *fields;                        //  Decoded responses
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_START_OK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_start_ok_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_START_OK))
    icl_trace_record (NULL, demo_server_connection_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_START_OK))
    icl_stats_inc ("demo_server_connection_start_ok", &s_demo_server_connection_start_ok_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

//
self->authorised = FALSE;
fields = asl_field_list_new (method->client_properties);
if (fields) {
    asl_field_list_cpy (fields, self->client_product,     "product");
    asl_field_list_cpy (fields, self->client_version,     "version");
    asl_field_list_cpy (fields, self->client_platform,    "platform");
    asl_field_list_cpy (fields, self->client_copyright,   "copyright");
    asl_field_list_cpy (fields, self->client_information, "information");
    //  Optionally, we could handle the following cases:
    //  1. duplicate connection instance name
    //  2. empty connection instance name
    asl_field_list_cpy (fields, self->client_instance,    "instance");
    asl_field_list_cpy (fields, self->client_proxy_name,  "proxy name");
    asl_field_list_cpy (fields, self->client_proxy_host,  "proxy host");
    asl_field_list_destroy (&fields);
}

if (s_auth_plain (self, method))
    self->authorised = TRUE;
else
    self_raise_exception (self, ASL_ACCESS_REFUSED, 
        "Invalid authentication data",
        DEMO_SERVER_CONNECTION, DEMO_SERVER_CONNECTION_START_OK);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_START_OK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_START_OK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_start_ok_finish"
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
    demo_server_connection_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_INITIALISE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_INITIALISE))
    icl_trace_record (NULL, demo_server_connection_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_INITIALISE))
    icl_stats_inc ("demo_server_connection_initialise", &s_demo_server_connection_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_demo_server_connection_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_demo_server_connection_mutex)
            s_demo_server_connection_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_demo_server_connection_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_demo_server_connection_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_context_seq_hi = 0;
s_context_seq_lo = 1;
            s_demo_server_connection_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_demo_server_connection_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_INITIALISE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_INITIALISE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_initialise_finish"
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
    demo_server_connection_new

    Type: Component method
    Creates and initialises a new demo_server_connection_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    demo_server_connection_table_t * table,   //  Table to insert into
    smt_thread_t * thread               //  Parent thread
)
{
#define key self->id
qbyte
    seq_lo,
    seq_hi;
    demo_server_connection_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_NEW))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_NEW))
    icl_trace_record (NULL, demo_server_connection_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_NEW))
    icl_stats_inc ("demo_server_connection_new", &s_demo_server_connection_new_stats);
#endif

if (!s_demo_server_connection_active)
    self_initialise ();
    self = demo_server_connection_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_SERVER_CONNECTION_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, demo_server_connection_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
icl_atomic_inc32 ((volatile qbyte *) &s_demo_server_connection_count);

//
if (thread)
    self->thread  = smt_thread_link (thread);
self->started     = smt_time_now ();
self->channel_max = 1;              //  We only support one channel 
self->frame_max   = demo_server_config_frame_max (demo_server_config);
self->heartbeat   = demo_server_config_heartbeat (demo_server_config);
self->trace       = demo_server_config_trace (demo_server_config);
self->channels    = demo_server_channel_table_new ();

//  Get 64-bit connection id, no wraparound handling
seq_lo = icl_atomic_inc32 (&s_context_seq_lo);
if (seq_lo == 0)
    seq_hi = icl_atomic_inc32 (&s_context_seq_hi);
else
    seq_hi = s_context_seq_hi;
icl_shortstr_fmt (self->id, "%x-%x", seq_hi, seq_lo);
if (table && self && demo_server_connection_table_insert (table, key, self))
    demo_server_connection_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_NEW))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_NEW))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, thread, self);
#endif


    return (self);
}
#undef key
/*  -------------------------------------------------------------------------
    demo_server_connection_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_annihilate_ (
    demo_server_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    int
        history_last;
#endif

    demo_server_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_DESTROY))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_DESTROY))
    icl_trace_record (NULL, demo_server_connection_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_DESTROY))
    icl_stats_inc ("demo_server_connection_annihilate", &s_demo_server_connection_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = file;
    self->history_line  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = line;
    self->history_type  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = self->links;
#endif

    DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
    demo_server_connection_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_atomic_dec32 ((volatile qbyte *) &s_demo_server_connection_count);

//  This closes all channels when we call destroy on the connection
demo_server_channel_table_destroy (&self->channels);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_DESTROY))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_DESTROY))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_destroy_finish"
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
    demo_server_connection_free

    Type: Component method
    Freess a demo_server_connection_t object.
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_free_ (
    demo_server_connection_t * self,    //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_FREE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_FREE))
    icl_trace_record (NULL, demo_server_connection_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_FREE))
    icl_stats_inc ("demo_server_connection_free", &s_demo_server_connection_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = "free";
        self->history_links [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = self->links;
#endif

//  This ensures the thread is valid until the connection is no longer used
smt_thread_unlink (&self->thread);
#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (demo_server_connection_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_server_connection_t));
        self->object_tag = DEMO_SERVER_CONNECTION_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_FREE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_FREE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_free_finish"
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
    demo_server_connection_set_address

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the connection's address string, which can be used for logging
    and reporting.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_set_address (
    demo_server_connection_t * self,    //  Reference to object
    char * address                      //  Client address
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SET_ADDRESS))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_set_address_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SET_ADDRESS))
    icl_trace_record (NULL, demo_server_connection_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SET_ADDRESS))
    icl_stats_inc ("demo_server_connection_set_address", &s_demo_server_connection_set_address_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
icl_shortstr_cpy (self->client_address, address);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SET_ADDRESS))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SET_ADDRESS))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_set_address_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_connection_set_trace

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the connection's trace level, used to determine the logging done
    at the connection thread level (in the server agent).
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_set_trace (
    demo_server_connection_t * self,    //  Reference to object
    int trace                           //  Desired trace level
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SET_TRACE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_set_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SET_TRACE))
    icl_trace_record (NULL, demo_server_connection_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SET_TRACE))
    icl_stats_inc ("demo_server_connection_set_trace", &s_demo_server_connection_set_trace_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
demo_server_agent_set_trace (self->thread, trace);
self->trace = trace;                //  Last known value
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SET_TRACE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SET_TRACE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_set_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_server_connection_kill

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Kills the connection by sending a connection-kill method to the
    agent.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_kill (
    demo_server_connection_t * self     //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_KILL))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_kill_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_KILL))
    icl_trace_record (NULL, demo_server_connection_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_KILL))
    icl_stats_inc ("demo_server_connection_kill", &s_demo_server_connection_kill_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
demo_server_agent_kill_connection (self->thread);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_KILL))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_KILL))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_kill_finish"
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
    demo_server_connection_ready

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_ready (
    demo_server_connection_t * self     //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_READY))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_ready_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_READY))
    icl_trace_record (NULL, demo_server_connection_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_READY))
    icl_stats_inc ("demo_server_connection_ready", &s_demo_server_connection_ready_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

rc = TRUE;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_READY))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_READY))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_ready_finish"
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
    demo_server_connection_raise_exception

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Raise a connection exception.  This method is for internal use by 
    the connection class or server agent only.  External callers should 
    call the "error" method instead.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_raise_exception (
    demo_server_connection_t * self,    //  Reference to object
    dbyte reply_code,                   //  Error code
    char * reply_text,                  //  Error text
    dbyte faulting_method_id,           //  Faulting method id
    dbyte faulting_class_id             //  Faulting class id
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_raise_exception_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION))
    icl_trace_record (NULL, demo_server_connection_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION))
    icl_stats_inc ("demo_server_connection_raise_exception", &s_demo_server_connection_raise_exception_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
//  TODO Find a way to assert this is not being called from the wrong place
self->exception_raised  = TRUE;
self->reply_code = reply_code;
icl_shortstr_cpy (self->reply_text, reply_text);
self->faulting_class_id = faulting_class_id;
self->faulting_method_id = faulting_method_id;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_raise_exception_finish"
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
    demo_server_connection_error

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Raise a connection exception.  This method is for external use only,
    internal callers should call the "raise exception" method instead.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_error (
    demo_server_connection_t * self,    //  Reference to object
    dbyte reply_code,                   //  Error code
    char * reply_text,                  //  Error text
    dbyte faulting_method_id,           //  Faulting method id
    dbyte faulting_class_id             //  Faulting class id
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_ERROR))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_error_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_ERROR))
    icl_trace_record (NULL, demo_server_connection_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_ERROR))
    icl_stats_inc ("demo_server_connection_error", &s_demo_server_connection_error_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
demo_server_agent_connection_error (self->thread, reply_code, reply_text,
    faulting_method_id, faulting_class_id);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_ERROR))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_ERROR))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_error_finish"
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
    demo_server_connection_exception_raised

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Returns TRUE if a connection exception has been raised.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_exception_raised (
    demo_server_connection_t * self     //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_exception_raised_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED))
    icl_trace_record (NULL, demo_server_connection_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED))
    icl_stats_inc ("demo_server_connection_exception_raised", &s_demo_server_connection_exception_raised_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

rc = self->exception_raised;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_exception_raised_finish"
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
    demo_server_connection_tune_ok

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the ASL Connection.Tune-Ok protocol method.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_tune_ok (
    demo_server_connection_t * self,    //  Reference to object
    demo_server_connection_tune_ok_t * method  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_TUNE_OK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_tune_ok_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_TUNE_OK))
    icl_trace_record (NULL, demo_server_connection_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_TUNE_OK))
    icl_stats_inc ("demo_server_connection_tune_ok", &s_demo_server_connection_tune_ok_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

//
self->heartbeat = method->heartbeat;
self->frame_max = method->frame_max;
if (self->frame_max < ASL_FRAME_MIN_SIZE
&&  self->frame_max > 0)
    self->frame_max = ASL_FRAME_MIN_SIZE;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_TUNE_OK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_TUNE_OK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_tune_ok_finish"
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
    demo_server_connection_open

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    Implements the ASL Connection.Open protocol method.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_open (
    demo_server_connection_t * self,    //  Reference to object
    demo_server_connection_open_t * method  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_OPEN))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_open_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_OPEN))
    icl_trace_record (NULL, demo_server_connection_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_OPEN))
    icl_stats_inc ("demo_server_connection_open", &s_demo_server_connection_open_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_OPEN))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_OPEN))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_open_finish"
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
    demo_server_connection_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SELFTEST))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SELFTEST))
    icl_trace_record (NULL, demo_server_connection_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SELFTEST))
    icl_stats_inc ("demo_server_connection_selftest", &s_demo_server_connection_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SELFTEST))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SELFTEST))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_selftest_finish"
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
    demo_server_connection_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    demo_server_connection_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_COUNT))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_COUNT))
    icl_trace_record (NULL, demo_server_connection_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_COUNT))
    icl_stats_inc ("demo_server_connection_count", &s_demo_server_connection_count_stats);
#endif

count = (int) s_demo_server_connection_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_COUNT))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_COUNT))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    demo_server_connection_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_remove_from_all_containers (
    demo_server_connection_t * self     //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_server_connection_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("demo_server_connection_remove_from_all_containers", &s_demo_server_connection_remove_from_all_containers_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
demo_server_connection_table_remove (self);
demo_server_connection_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_remove_from_all_containers_finish"
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
    demo_server_connection_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_server_connection_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SHOW))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SHOW))
    icl_trace_record (NULL, demo_server_connection_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SHOW))
    icl_stats_inc ("demo_server_connection_show", &s_demo_server_connection_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <demo_server_connection zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    if (self->history_last > DEMO_SERVER_CONNECTION_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % DEMO_SERVER_CONNECTION_HISTORY_LENGTH;
        self->history_last %= DEMO_SERVER_CONNECTION_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % DEMO_SERVER_CONNECTION_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </demo_server_connection>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SHOW))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SHOW))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_show_finish"
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
    demo_server_connection_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_TERMINATE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_TERMINATE))
    icl_trace_record (NULL, demo_server_connection_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_TERMINATE))
    icl_stats_inc ("demo_server_connection_terminate", &s_demo_server_connection_terminate_stats);
#endif

if (s_demo_server_connection_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_demo_server_connection_mutex);
#endif
        s_demo_server_connection_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_TERMINATE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_TERMINATE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_terminate_finish"
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
    demo_server_connection_destroy

    Type: Component method
    Destroys a demo_server_connection_t object. Takes the address of a
    demo_server_connection_t reference (a pointer to a pointer) and nullifies the
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
    demo_server_connection_destroy_ (
    demo_server_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    demo_server_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_server_connection_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC))
    icl_stats_inc ("demo_server_connection_destroy", &s_demo_server_connection_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        demo_server_connection_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on demo_server_connection object");
        demo_server_connection_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        demo_server_connection_free_ ((demo_server_connection_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_destroy_public_finish"
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
    demo_server_connection_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_server_connection_t *
    demo_server_connection_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_server_connection_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_ALLOC))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_ALLOC))
    icl_trace_record (NULL, demo_server_connection_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_ALLOC))
    icl_stats_inc ("demo_server_connection_alloc", &s_demo_server_connection_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_server_connection_cache_initialise ();

self = (demo_server_connection_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_server_connection_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_ALLOC))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_ALLOC))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_alloc_finish"
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
    demo_server_connection_read_lock

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_read_lock (
    demo_server_connection_t * self     //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_READ_LOCK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_READ_LOCK))
    icl_trace_record (NULL, demo_server_connection_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_READ_LOCK))
    icl_stats_inc ("demo_server_connection_read_lock", &s_demo_server_connection_read_lock_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_READ_LOCK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_READ_LOCK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_read_lock_finish"
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
    demo_server_connection_write_lock

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_write_lock (
    demo_server_connection_t * self     //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_WRITE_LOCK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_WRITE_LOCK))
    icl_trace_record (NULL, demo_server_connection_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_WRITE_LOCK))
    icl_stats_inc ("demo_server_connection_write_lock", &s_demo_server_connection_write_lock_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_WRITE_LOCK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_WRITE_LOCK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_write_lock_finish"
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
    demo_server_connection_unlock

    Type: Component method
    Accepts a demo_server_connection_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_unlock (
    demo_server_connection_t * self     //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_UNLOCK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_UNLOCK))
    icl_trace_record (NULL, demo_server_connection_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_UNLOCK))
    icl_stats_inc ("demo_server_connection_unlock", &s_demo_server_connection_unlock_stats);
#endif

DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_UNLOCK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_UNLOCK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_unlock_finish"
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
    demo_server_connection_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_link_ (
    demo_server_connection_t * self,    //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LINK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LINK))
    icl_trace_record (NULL, demo_server_connection_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LINK))
    icl_stats_inc ("demo_server_connection_link", &s_demo_server_connection_link_stats);
#endif

    if (self) {
        DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = "link";
        self->history_links [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LINK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LINK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_link_finish"
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
    demo_server_connection_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_unlink_ (
    demo_server_connection_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
    int
        history_last;
#endif

    demo_server_connection_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_UNLINK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_UNLINK))
    icl_trace_record (NULL, demo_server_connection_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_UNLINK))
    icl_stats_inc ("demo_server_connection_unlink", &s_demo_server_connection_unlink_stats);
#endif

    if (self) {
        DEMO_SERVER_CONNECTION_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on demo_server_connection object");
            demo_server_connection_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % DEMO_SERVER_CONNECTION_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            demo_server_connection_annihilate_ (self_p, file, line);
        demo_server_connection_free_ ((demo_server_connection_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_UNLINK))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_UNLINK))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_unlink_finish"
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
    demo_server_connection_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_CACHE_INITIALISE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_server_connection_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_CACHE_INITIALISE))
    icl_stats_inc ("demo_server_connection_cache_initialise", &s_demo_server_connection_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_server_connection_t));
icl_system_register (demo_server_connection_cache_purge, demo_server_connection_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_CACHE_INITIALISE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_cache_initialise_finish"
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
    demo_server_connection_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_CACHE_PURGE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_PURGE))
    icl_trace_record (NULL, demo_server_connection_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_CACHE_PURGE))
    icl_stats_inc ("demo_server_connection_cache_purge", &s_demo_server_connection_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_PURGE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_CACHE_PURGE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_cache_purge_finish"
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
    demo_server_connection_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_CACHE_TERMINATE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_server_connection_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_CACHE_TERMINATE))
    icl_stats_inc ("demo_server_connection_cache_terminate", &s_demo_server_connection_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_CACHE_TERMINATE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_cache_terminate_finish"
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
    demo_server_connection_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SHOW_ANIMATION))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_server_connection_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_SHOW_ANIMATION))
    icl_stats_inc ("demo_server_connection_show_animation", &s_demo_server_connection_show_animation_stats);
#endif

demo_server_connection_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_SHOW_ANIMATION))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_show_animation_finish"
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
    demo_server_connection_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_new_in_scope_ (
    demo_server_connection_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    demo_server_connection_table_t * table,   //  Table to insert into
    smt_thread_t * thread               //  Parent thread
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_server_connection_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE))
    icl_stats_inc ("demo_server_connection_new_in_scope", &s_demo_server_connection_new_in_scope_stats);
#endif

*self_p = demo_server_connection_new_ (file,line,table,thread);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_server_connection_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_server_connection_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE))
    if (demo_server_connection_animating)
        icl_console_print ("<demo_server_connection_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" thread=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, thread, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_START_OK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_INITIALISE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_NEW)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_DESTROY)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_FREE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SET_ADDRESS)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SET_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_KILL)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_READY)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_RAISE_EXCEPTION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_ERROR)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_EXCEPTION_RAISED)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_TUNE_OK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_OPEN)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SELFTEST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_COUNT)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SHOW)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_ALLOC)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_READ_LOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_WRITE_LOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_UNLOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LINK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_UNLINK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_NEW_IN_SCOPE) )
void
demo_server_connection_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "start ok"; break;
        case 2: method_name = "initialise"; break;
        case 3: method_name = "new"; break;
        case 4: method_name = "destroy"; break;
        case 5: method_name = "free"; break;
        case 6: method_name = "set address"; break;
        case 7: method_name = "set trace"; break;
        case 8: method_name = "kill"; break;
        case 9: method_name = "ready"; break;
        case 10: method_name = "raise exception"; break;
        case 11: method_name = "error"; break;
        case 12: method_name = "exception raised"; break;
        case 13: method_name = "tune ok"; break;
        case 14: method_name = "open"; break;
        case 15: method_name = "selftest"; break;
        case 16: method_name = "count"; break;
        case 17: method_name = "remove from all containers"; break;
        case 18: method_name = "show"; break;
        case 19: method_name = "terminate"; break;
        case 20: method_name = "destroy public"; break;
        case 21: method_name = "alloc"; break;
        case 22: method_name = "read lock"; break;
        case 23: method_name = "write lock"; break;
        case 24: method_name = "unlock"; break;
        case 25: method_name = "link"; break;
        case 26: method_name = "unlink"; break;
        case 27: method_name = "cache initialise"; break;
        case 28: method_name = "cache purge"; break;
        case 29: method_name = "cache terminate"; break;
        case 30: method_name = "show animation"; break;
        case 31: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_server_connection %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_server_connection_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_server_connection_component  = "demo_server_connection ";
char *demo_server_connection_version  = "1.0 ";
char *demo_server_connection_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_server_connection_filename  = "demo_server_connection.icl ";
char *demo_server_connection_builddate  = "2009/02/19 ";
char *demo_server_connection_version_end  = "VeRsIoNeNd:ipc";

