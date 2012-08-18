/*---------------------------------------------------------------------------
    http_address.c - http_address component

    Stores data about a known IP address, used for DoS detection and other
    administration.  The address holds a looseref list of http_agent threads.
    Generated from http_address.icl by icl_gen using GSL/4.
    
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
#include "http_address.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_address_t

//  Shorthands for class methods                                               

#define self_new            http_address_new
#define self_annihilate     http_address_annihilate
#define self_thread_open    http_address_thread_open
#define self_thread_close   http_address_thread_close
#define self_selftest       http_address_selftest
#define self_remove_from_all_containers  http_address_remove_from_all_containers
#define self_show           http_address_show
#define self_terminate      http_address_terminate
#define self_destroy        http_address_destroy
#define self_alloc          http_address_alloc
#define self_free           http_address_free
#define self_lock           http_address_lock
#define self_unlock         http_address_unlock
#define self_cache_initialise  http_address_cache_initialise
#define self_cache_purge    http_address_cache_purge
#define self_cache_terminate  http_address_cache_terminate
#define self_show_animation  http_address_show_animation
#define self_new_in_scope   http_address_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_NEW))
static icl_stats_t *s_http_address_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_DESTROY))
static icl_stats_t *s_http_address_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_THREAD_OPEN))
static icl_stats_t *s_http_address_thread_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_THREAD_CLOSE))
static icl_stats_t *s_http_address_thread_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_SELFTEST))
static icl_stats_t *s_http_address_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_http_address_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_SHOW))
static icl_stats_t *s_http_address_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_TERMINATE))
static icl_stats_t *s_http_address_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_DESTROY_PUBLIC))
static icl_stats_t *s_http_address_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_ALLOC))
static icl_stats_t *s_http_address_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_FREE))
static icl_stats_t *s_http_address_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_LOCK))
static icl_stats_t *s_http_address_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_UNLOCK))
static icl_stats_t *s_http_address_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_CACHE_INITIALISE))
static icl_stats_t *s_http_address_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_CACHE_PURGE))
static icl_stats_t *s_http_address_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_CACHE_TERMINATE))
static icl_stats_t *s_http_address_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_SHOW_ANIMATION))
static icl_stats_t *s_http_address_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_NEW_IN_SCOPE))
static icl_stats_t *s_http_address_new_in_scope_stats = NULL;
#endif
static void
    http_address_annihilate (
http_address_t * ( * self_p )           //  Reference to object reference
);

#define http_address_alloc()            http_address_alloc_ (__FILE__, __LINE__)
static http_address_t *
    http_address_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    http_address_free (
http_address_t * self                   //  Object reference
);

static void
    http_address_cache_initialise (
void);

static void
    http_address_cache_purge (
void);

static void
    http_address_cache_terminate (
void);

Bool
    http_address_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    http_address_new

    Type: Component method
    Creates and initialises a new http_address_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

http_address_t *
    http_address_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    http_address_table_t * table,       //  Table to insert into
    char * key                          //  Hash key
)
{
    http_address_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_NEW))
    if (http_address_animating)
        icl_console_print ("<http_address_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_NEW))
    icl_trace_record (NULL, http_address_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_NEW))
    icl_stats_inc ("http_address_new", &s_http_address_new_stats);
#endif

    self = http_address_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_ADDRESS_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->mutex = icl_mutex_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, http_address_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->thread_list = ipr_looseref_list_new ();
self->thread_quota = http_config_address_quota (http_config);
//todo: if address is on whitelist then set to infinity
if (table && self && http_address_table_insert (table, key, self))
    http_address_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_NEW))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_NEW))
    if (http_address_animating)
        icl_console_print ("<http_address_new_finish"
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
    http_address_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_address_annihilate (
    http_address_t * ( * self_p )       //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

smt_thread_t
    *thread;
    http_address_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_DESTROY))
    if (http_address_animating)
        icl_console_print ("<http_address_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_DESTROY))
    icl_trace_record (NULL, http_address_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_DESTROY))
    icl_stats_inc ("http_address_annihilate", &s_http_address_annihilate_stats);
#endif

    HTTP_ADDRESS_ASSERT_SANE (self);
    http_address_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    mutex = self->mutex;
    if (mutex)
         icl_mutex_lock (mutex);
#endif

//
while ((thread = (smt_thread_t *) ipr_looseref_pop (self->thread_list))) {
icl_console_print ("end thread=%pp", thread);
    smt_thread_shut_down (thread);
    smt_thread_unlink (&thread);
}
ipr_looseref_list_destroy (&self->thread_list);
#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_DESTROY))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_DESTROY))
    if (http_address_animating)
        icl_console_print ("<http_address_destroy_finish"
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
    http_address_thread_open

    Type: Component method
    Adds an http_agent thread to the address's list of threads and culls
    the oldest thread if the address has gone over quota.
    -------------------------------------------------------------------------
 */

int
    http_address_thread_open (
    http_address_table_t * table,       //  Not documented
    http_access_context_t * context     //  Not documented
)
{
http_address_t
    *self;
smt_thread_t
    *thread;
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_THREAD_OPEN))
    if (http_address_animating)
        icl_console_print ("<http_address_thread_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_THREAD_OPEN))
    icl_trace_record (NULL, http_address_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_THREAD_OPEN))
    icl_stats_inc ("http_address_thread_open", &s_http_address_thread_open_stats);
#endif

//
assert (table);
assert (context);
assert (context->address);
assert (context->thread);

self = http_address_table_search (table, context->address);
if (!self) {
    self = http_address_new (table, context->address);
    //  This can return null if two threads create the same address at
    //  the same time... so let's go find the actual address object
    if (!self) {
        self = http_address_table_search (table, context->address);
        assert (self);
    }
}
assert (self);

self_lock (self);
ipr_looseref_queue (self->thread_list, smt_thread_link (context->thread));
//  Cull oldest thread if quota is non-zero but would become zero
//  I.e. if it's exactly one... a quota of zero means "unlimited".
if ( self->thread_quota
&& --self->thread_quota == 0) {
    //  Find oldest looseref entry
    thread = (smt_thread_t *) ipr_looseref_pop (self->thread_list);
    assert (thread);
    smt_thread_shut_down (thread);
    smt_thread_unlink (&thread);
    self->thread_quota++;
}
self_unlock (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_THREAD_OPEN))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_THREAD_OPEN))
    if (http_address_animating)
        icl_console_print ("<http_address_thread_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_address_thread_close

    Type: Component method
    Removes an http_agent thread from the address's list of threads.  The
    thread will be missing from the table, if it was already culled.
    -------------------------------------------------------------------------
 */

int
    http_address_thread_close (
    http_address_table_t * table,       //  Not documented
    http_access_context_t * context     //  Not documented
)
{
ipr_looseref_t
    *looseref;
http_address_t
    *self;
smt_thread_t
    *thread;
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_THREAD_CLOSE))
    if (http_address_animating)
        icl_console_print ("<http_address_thread_close_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_THREAD_CLOSE))
    icl_trace_record (NULL, http_address_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_THREAD_CLOSE))
    icl_stats_inc ("http_address_thread_close", &s_http_address_thread_close_stats);
#endif

//
assert (table);
assert (context);
assert (context->address);
assert (context->thread);

self = http_address_table_search (table, context->address);
assert (self);
self_lock (self);

//  Find looseref entry for context->thread
looseref = ipr_looseref_list_first (self->thread_list);
while (looseref
&& (smt_thread_t *) looseref->object != context->thread)
    looseref = ipr_looseref_list_next (&looseref);

if (looseref) {
    //  Now kill the thread and get back our quota
    thread = (smt_thread_t *) looseref->object;
    ipr_looseref_destroy (&looseref);
    assert (thread);
    smt_thread_shut_down (thread);
    smt_thread_unlink (&thread);
    self->thread_quota++;
}
self_unlock (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_THREAD_CLOSE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_THREAD_CLOSE))
    if (http_address_animating)
        icl_console_print ("<http_address_thread_close_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_address_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_address_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_SELFTEST))
    if (http_address_animating)
        icl_console_print ("<http_address_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_SELFTEST))
    icl_trace_record (NULL, http_address_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_SELFTEST))
    icl_stats_inc ("http_address_selftest", &s_http_address_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_SELFTEST))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_SELFTEST))
    if (http_address_animating)
        icl_console_print ("<http_address_selftest_finish"
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
    http_address_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    http_address_remove_from_all_containers (
    http_address_t * self               //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS))
    if (http_address_animating)
        icl_console_print ("<http_address_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, http_address_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("http_address_remove_from_all_containers", &s_http_address_remove_from_all_containers_stats);
#endif

HTTP_ADDRESS_ASSERT_SANE (self);
http_address_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS))
    if (http_address_animating)
        icl_console_print ("<http_address_remove_from_all_containers_finish"
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
    http_address_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_address_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
http_address_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_SHOW))
    if (http_address_animating)
        icl_console_print ("<http_address_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_SHOW))
    icl_trace_record (NULL, http_address_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_SHOW))
    icl_stats_inc ("http_address_show", &s_http_address_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <http_address file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_SHOW))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_SHOW))
    if (http_address_animating)
        icl_console_print ("<http_address_show_finish"
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
    http_address_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_address_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_TERMINATE))
    if (http_address_animating)
        icl_console_print ("<http_address_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_TERMINATE))
    icl_trace_record (NULL, http_address_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_TERMINATE))
    icl_stats_inc ("http_address_terminate", &s_http_address_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_TERMINATE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_TERMINATE))
    if (http_address_animating)
        icl_console_print ("<http_address_terminate_finish"
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
    http_address_destroy

    Type: Component method
    Destroys a http_address_t object. Takes the address of a
    http_address_t reference (a pointer to a pointer) and nullifies the
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
    http_address_destroy_ (
    http_address_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    http_address_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_DESTROY_PUBLIC))
    if (http_address_animating)
        icl_console_print ("<http_address_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_address_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_DESTROY_PUBLIC))
    icl_stats_inc ("http_address_destroy", &s_http_address_destroy_stats);
#endif

if (self) {
    http_address_annihilate (self_p);
    http_address_free ((http_address_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_DESTROY_PUBLIC))
    if (http_address_animating)
        icl_console_print ("<http_address_destroy_public_finish"
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
    http_address_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_address_t *
    http_address_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_address_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_ALLOC))
    if (http_address_animating)
        icl_console_print ("<http_address_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_ALLOC))
    icl_trace_record (NULL, http_address_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_ALLOC))
    icl_stats_inc ("http_address_alloc", &s_http_address_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_address_cache_initialise ();

self = (http_address_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_address_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_ALLOC))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_ALLOC))
    if (http_address_animating)
        icl_console_print ("<http_address_alloc_finish"
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
    http_address_free

    Type: Component method
    Freess a http_address_t object.
    -------------------------------------------------------------------------
 */

static void
    http_address_free (
    http_address_t * self               //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_FREE))
    if (http_address_animating)
        icl_console_print ("<http_address_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_FREE))
    icl_trace_record (NULL, http_address_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_FREE))
    icl_stats_inc ("http_address_free", &s_http_address_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->mutex)
        icl_mutex_destroy (&self->mutex);
#endif
        memset (&self->object_tag, 0, sizeof (http_address_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_address_t));
        self->object_tag = HTTP_ADDRESS_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_FREE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_FREE))
    if (http_address_animating)
        icl_console_print ("<http_address_free_finish"
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
    http_address_lock

    Type: Component method
    Accepts a http_address_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_address_lock (
    http_address_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_LOCK))
    if (http_address_animating)
        icl_console_print ("<http_address_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_LOCK))
    icl_trace_record (NULL, http_address_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_LOCK))
    icl_stats_inc ("http_address_lock", &s_http_address_lock_stats);
#endif

HTTP_ADDRESS_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_lock (self->mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_LOCK))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_LOCK))
    if (http_address_animating)
        icl_console_print ("<http_address_lock_finish"
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
    http_address_unlock

    Type: Component method
    Accepts a http_address_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_address_unlock (
    http_address_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_UNLOCK))
    if (http_address_animating)
        icl_console_print ("<http_address_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_UNLOCK))
    icl_trace_record (NULL, http_address_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_UNLOCK))
    icl_stats_inc ("http_address_unlock", &s_http_address_unlock_stats);
#endif

HTTP_ADDRESS_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_unlock (self->mutex);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_UNLOCK))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_UNLOCK))
    if (http_address_animating)
        icl_console_print ("<http_address_unlock_finish"
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
    http_address_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_address_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_CACHE_INITIALISE))
    if (http_address_animating)
        icl_console_print ("<http_address_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_INITIALISE))
    icl_trace_record (NULL, http_address_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_CACHE_INITIALISE))
    icl_stats_inc ("http_address_cache_initialise", &s_http_address_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_address_t));
icl_system_register (http_address_cache_purge, http_address_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_INITIALISE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_CACHE_INITIALISE))
    if (http_address_animating)
        icl_console_print ("<http_address_cache_initialise_finish"
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
    http_address_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_address_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_CACHE_PURGE))
    if (http_address_animating)
        icl_console_print ("<http_address_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_PURGE))
    icl_trace_record (NULL, http_address_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_CACHE_PURGE))
    icl_stats_inc ("http_address_cache_purge", &s_http_address_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_PURGE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_CACHE_PURGE))
    if (http_address_animating)
        icl_console_print ("<http_address_cache_purge_finish"
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
    http_address_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_address_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_CACHE_TERMINATE))
    if (http_address_animating)
        icl_console_print ("<http_address_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_TERMINATE))
    icl_trace_record (NULL, http_address_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_CACHE_TERMINATE))
    icl_stats_inc ("http_address_cache_terminate", &s_http_address_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_TERMINATE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_CACHE_TERMINATE))
    if (http_address_animating)
        icl_console_print ("<http_address_cache_terminate_finish"
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
    http_address_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_address_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_SHOW_ANIMATION))
    if (http_address_animating)
        icl_console_print ("<http_address_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_SHOW_ANIMATION))
    icl_trace_record (NULL, http_address_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_SHOW_ANIMATION))
    icl_stats_inc ("http_address_show_animation", &s_http_address_show_animation_stats);
#endif

http_address_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_SHOW_ANIMATION))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_SHOW_ANIMATION))
    if (http_address_animating)
        icl_console_print ("<http_address_show_animation_finish"
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
    http_address_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_address_new_in_scope_ (
    http_address_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    http_address_table_t * table,       //  Table to insert into
    char * key                          //  Hash key
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS)  ||  defined (BASE_ANIMATE_HTTP_ADDRESS_NEW_IN_SCOPE))
    if (http_address_animating)
        icl_console_print ("<http_address_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_address_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ADDRESS)  ||  defined (BASE_STATS_HTTP_ADDRESS_NEW_IN_SCOPE))
    icl_stats_inc ("http_address_new_in_scope", &s_http_address_new_in_scope_stats);
#endif

*self_p = http_address_new_ (file,line,table,key);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_address_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_address_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ADDRESS)   || defined (BASE_ANIMATE_HTTP_ADDRESS_NEW_IN_SCOPE))
    if (http_address_animating)
        icl_console_print ("<http_address_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ADDRESS)   || defined (BASE_TRACE_HTTP_ADDRESS_NEW)   || defined (BASE_TRACE_HTTP_ADDRESS_DESTROY)   || defined (BASE_TRACE_HTTP_ADDRESS_THREAD_OPEN)   || defined (BASE_TRACE_HTTP_ADDRESS_THREAD_CLOSE)   || defined (BASE_TRACE_HTTP_ADDRESS_SELFTEST)   || defined (BASE_TRACE_HTTP_ADDRESS_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_HTTP_ADDRESS_SHOW)   || defined (BASE_TRACE_HTTP_ADDRESS_TERMINATE)   || defined (BASE_TRACE_HTTP_ADDRESS_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_ADDRESS_ALLOC)   || defined (BASE_TRACE_HTTP_ADDRESS_FREE)   || defined (BASE_TRACE_HTTP_ADDRESS_LOCK)   || defined (BASE_TRACE_HTTP_ADDRESS_UNLOCK)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_ADDRESS_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_ADDRESS_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_ADDRESS_NEW_IN_SCOPE) )
void
http_address_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "thread open"; break;
        case 4: method_name = "thread close"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "remove from all containers"; break;
        case 7: method_name = "show"; break;
        case 8: method_name = "terminate"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "free"; break;
        case 12: method_name = "lock"; break;
        case 13: method_name = "unlock"; break;
        case 14: method_name = "cache initialise"; break;
        case 15: method_name = "cache purge"; break;
        case 16: method_name = "cache terminate"; break;
        case 17: method_name = "show animation"; break;
        case 18: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_address %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *http_address_version_start   = "VeRsIoNsTaRt:ipc";
char *http_address_component       = "http_address ";
char *http_address_version         = "1.0 ";
char *http_address_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_address_filename        = "http_address.icl ";
char *http_address_builddate       = "2009/02/19 ";
char *http_address_version_end     = "VeRsIoNeNd:ipc";

