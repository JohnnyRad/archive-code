/*---------------------------------------------------------------------------
    http_driver_module.c - http_driver_module component

    This class enables the creation of plug-in modules that handle specific
    URI paths for the server.  The plug-in accepts HTTP methods and an
    http_request object and returns a http_response object.
    Generated from http_driver_module.icl by icl_gen using GSL/4.
    
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
#include "http_driver_module.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_driver_module_t

//  Shorthands for class methods                                               

#define self_new            http_driver_module_new
#define self_factory        http_driver_module_factory
#define self_request_announce  http_driver_module_request_announce
#define self_request_get    http_driver_module_request_get
#define self_request_head   http_driver_module_request_head
#define self_request_post   http_driver_module_request_post
#define self_request_put    http_driver_module_request_put
#define self_request_delete  http_driver_module_request_delete
#define self_request_move   http_driver_module_request_move
#define self_request_copy   http_driver_module_request_copy
#define self_annihilate     http_driver_module_annihilate
#define self_ready          http_driver_module_ready
#define self_selftest       http_driver_module_selftest
#define self_terminate      http_driver_module_terminate
#define self_show           http_driver_module_show
#define self_destroy        http_driver_module_destroy
#define self_alloc          http_driver_module_alloc
#define self_free           http_driver_module_free
#define self_read_lock      http_driver_module_read_lock
#define self_write_lock     http_driver_module_write_lock
#define self_unlock         http_driver_module_unlock
#define self_link           http_driver_module_link
#define self_unlink         http_driver_module_unlink
#define self_cache_initialise  http_driver_module_cache_initialise
#define self_cache_purge    http_driver_module_cache_purge
#define self_cache_terminate  http_driver_module_cache_terminate
#define self_show_animation  http_driver_module_show_animation
#define self_new_in_scope   http_driver_module_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_NEW))
static icl_stats_t *s_http_driver_module_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_FACTORY))
static icl_stats_t *s_http_driver_module_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE))
static icl_stats_t *s_http_driver_module_request_announce_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_GET))
static icl_stats_t *s_http_driver_module_request_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_HEAD))
static icl_stats_t *s_http_driver_module_request_head_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_POST))
static icl_stats_t *s_http_driver_module_request_post_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_PUT))
static icl_stats_t *s_http_driver_module_request_put_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_DELETE))
static icl_stats_t *s_http_driver_module_request_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_MOVE))
static icl_stats_t *s_http_driver_module_request_move_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_COPY))
static icl_stats_t *s_http_driver_module_request_copy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_DESTROY))
static icl_stats_t *s_http_driver_module_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_READY))
static icl_stats_t *s_http_driver_module_ready_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_SELFTEST))
static icl_stats_t *s_http_driver_module_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_TERMINATE))
static icl_stats_t *s_http_driver_module_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_SHOW))
static icl_stats_t *s_http_driver_module_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_DESTROY_PUBLIC))
static icl_stats_t *s_http_driver_module_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_ALLOC))
static icl_stats_t *s_http_driver_module_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_FREE))
static icl_stats_t *s_http_driver_module_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_READ_LOCK))
static icl_stats_t *s_http_driver_module_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_WRITE_LOCK))
static icl_stats_t *s_http_driver_module_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_UNLOCK))
static icl_stats_t *s_http_driver_module_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_LINK))
static icl_stats_t *s_http_driver_module_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_UNLINK))
static icl_stats_t *s_http_driver_module_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_CACHE_INITIALISE))
static icl_stats_t *s_http_driver_module_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_CACHE_PURGE))
static icl_stats_t *s_http_driver_module_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_CACHE_TERMINATE))
static icl_stats_t *s_http_driver_module_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_SHOW_ANIMATION))
static icl_stats_t *s_http_driver_module_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_NEW_IN_SCOPE))
static icl_stats_t *s_http_driver_module_new_in_scope_stats = NULL;
#endif
#define http_driver_module_annihilate(self)  http_driver_module_annihilate_ (self, __FILE__, __LINE__)
static void
    http_driver_module_annihilate_ (
http_driver_module_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_module_alloc()      http_driver_module_alloc_ (__FILE__, __LINE__)
static http_driver_module_t *
    http_driver_module_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define http_driver_module_free(self)   http_driver_module_free_ (self, __FILE__, __LINE__)
static void
    http_driver_module_free_ (
http_driver_module_t * self,            //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    http_driver_module_cache_initialise (
void);

static void
    http_driver_module_cache_purge (
void);

static void
    http_driver_module_cache_terminate (
void);

Bool
    http_driver_module_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    http_driver_module_new

    Type: Component method
    Creates and initialises a new http_driver_module_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    http_driver_module_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink,   //  Not documented
    char * path                         //  Not documented
)
{
    http_driver_module_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_NEW))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server_object=\"%pp\""
" server_link=\"%pp\""
" server_unlink=\"%pp\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server_object, server_link, server_unlink, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_NEW))
    icl_trace_record (NULL, http_driver_module_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_NEW))
    icl_stats_inc ("http_driver_module_new", &s_http_driver_module_new_stats);
#endif

    self = http_driver_module_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_DRIVER_MODULE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
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
        icl_mem_set_callback (self, http_driver_module_show_);
#endif

//
self->server_object = (server_link) (server_object);
self->server_unlink = server_unlink;

icl_shortstr_cpy (self->path, path);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_NEW))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_NEW))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server_object=\"%pp\""
" server_link=\"%pp\""
" server_unlink=\"%pp\""
" path=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server_object, server_link, server_unlink, path, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    http_driver_module_factory

    Type: Component method
    Asks portal factory to create new portal with implicit server object. The
    server object is owned only by its portal; when you stop the owning portal
    the implicit server object is also stopped.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    http_driver_module_factory (
    http_driver_module_t * self,        //  Portal factory
    char * path                         //  Not documented
)
{
    http_driver_module_t *
        portal;                         //  New portal object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_FACTORY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_factory_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_FACTORY))
    icl_trace_record (NULL, http_driver_module_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_FACTORY))
    icl_stats_inc ("http_driver_module_factory", &s_http_driver_module_factory_stats);
#endif

//
//  Check this is a valid factory
if (self->server_object)
    icl_console_print ("E: factory method is only allowed on portal factories");
assert (!self->server_object);
assert (self->server_new);
//
portal = (self->server_new) (NULL, path);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_FACTORY))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_FACTORY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_factory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, portal);
#endif


    return (portal);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_announce

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_announce (
    http_driver_module_t * self,        //  Not documented
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_announce_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE))
    icl_trace_record (NULL, http_driver_module_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE))
    icl_stats_inc ("http_driver_module_request_announce", &s_http_driver_module_request_announce_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_announce) (self->server_object, self, log);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_announce_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_get

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_get (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_GET))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_GET))
    icl_trace_record (NULL, http_driver_module_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_GET))
    icl_stats_inc ("http_driver_module_request_get", &s_http_driver_module_request_get_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_get) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_GET))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_GET))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_head

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_head (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_HEAD))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_head_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_HEAD))
    icl_trace_record (NULL, http_driver_module_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_HEAD))
    icl_stats_inc ("http_driver_module_request_head", &s_http_driver_module_request_head_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_head) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_HEAD))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_HEAD))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_head_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_post

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_post (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_POST))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_post_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_POST))
    icl_trace_record (NULL, http_driver_module_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_POST))
    icl_stats_inc ("http_driver_module_request_post", &s_http_driver_module_request_post_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_post) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_POST))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_POST))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_post_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_put

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_put (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_PUT))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_put_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_PUT))
    icl_trace_record (NULL, http_driver_module_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_PUT))
    icl_stats_inc ("http_driver_module_request_put", &s_http_driver_module_request_put_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_put) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_PUT))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_PUT))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_put_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_delete

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_delete (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_DELETE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_DELETE))
    icl_trace_record (NULL, http_driver_module_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_DELETE))
    icl_stats_inc ("http_driver_module_request_delete", &s_http_driver_module_request_delete_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_delete) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_DELETE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_DELETE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_move

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_move (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_MOVE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_move_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_MOVE))
    icl_trace_record (NULL, http_driver_module_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_MOVE))
    icl_stats_inc ("http_driver_module_request_move", &s_http_driver_module_request_move_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_move) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_MOVE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_MOVE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_move_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_request_copy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_module_request_copy (
    http_driver_module_t * self,        //  Not documented
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_COPY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_copy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_COPY))
    icl_trace_record (NULL, http_driver_module_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_REQUEST_COPY))
    icl_stats_inc ("http_driver_module_request_copy", &s_http_driver_module_request_copy_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_copy) (self->server_object, self, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_COPY))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_REQUEST_COPY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_request_copy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_driver_module_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_module_annihilate_ (
    http_driver_module_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    int
        history_last;
#endif

    http_driver_module_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_DESTROY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_DESTROY))
    icl_trace_record (NULL, http_driver_module_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_DESTROY))
    icl_stats_inc ("http_driver_module_annihilate", &s_http_driver_module_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = self->links;
#endif

    HTTP_DRIVER_MODULE_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

if (icl_atomic_cas32 ((volatile qbyte *) &self->stopped, TRUE, FALSE) == FALSE) {
    self->bound = FALSE;
    (self->client_unbind) (self->client_object, self);
    if (self->server_object) {
        (self->server_unbind) (self->server_object, self);
        (self->server_unlink) (&self->server_object);
    }
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_DESTROY))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_DESTROY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_destroy_finish"
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
    http_driver_module_ready

    Type: Component method
    Accepts a http_driver_module_t reference and returns zero in case of success,
    1 in case of errors.
    Signals to the server that the portal has been bound by the client and
    is now ready for use.
    -------------------------------------------------------------------------
 */

int
    http_driver_module_ready (
    http_driver_module_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_READY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_ready_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_READY))
    icl_trace_record (NULL, http_driver_module_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_READY))
    icl_stats_inc ("http_driver_module_ready", &s_http_driver_module_ready_stats);
#endif

HTTP_DRIVER_MODULE_ASSERT_SANE (self);
if (!self->zombie) {

//
self->bound = TRUE;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_READY))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_READY))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_ready_finish"
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
    http_driver_module_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_module_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_SELFTEST))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SELFTEST))
    icl_trace_record (NULL, http_driver_module_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_SELFTEST))
    icl_stats_inc ("http_driver_module_selftest", &s_http_driver_module_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SELFTEST))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_SELFTEST))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_selftest_finish"
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
    http_driver_module_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_module_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_TERMINATE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_TERMINATE))
    icl_trace_record (NULL, http_driver_module_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_TERMINATE))
    icl_stats_inc ("http_driver_module_terminate", &s_http_driver_module_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_TERMINATE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_TERMINATE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_terminate_finish"
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
    http_driver_module_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_module_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_driver_module_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_SHOW))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SHOW))
    icl_trace_record (NULL, http_driver_module_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_SHOW))
    icl_stats_inc ("http_driver_module_show", &s_http_driver_module_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <http_driver_module zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    if (self->history_last > HTTP_DRIVER_MODULE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % HTTP_DRIVER_MODULE_HISTORY_LENGTH;
        self->history_last %= HTTP_DRIVER_MODULE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % HTTP_DRIVER_MODULE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </http_driver_module>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SHOW))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_SHOW))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_show_finish"
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
    http_driver_module_destroy

    Type: Component method
    Destroys a http_driver_module_t object. Takes the address of a
    http_driver_module_t reference (a pointer to a pointer) and nullifies the
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
    http_driver_module_destroy_ (
    http_driver_module_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    http_driver_module_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_DESTROY_PUBLIC))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_driver_module_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_DESTROY_PUBLIC))
    icl_stats_inc ("http_driver_module_destroy", &s_http_driver_module_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        http_driver_module_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on http_driver_module object");
        http_driver_module_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        http_driver_module_free_ ((http_driver_module_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_DESTROY_PUBLIC))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_destroy_public_finish"
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
    http_driver_module_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_driver_module_t *
    http_driver_module_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_driver_module_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_ALLOC))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_ALLOC))
    icl_trace_record (NULL, http_driver_module_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_ALLOC))
    icl_stats_inc ("http_driver_module_alloc", &s_http_driver_module_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_driver_module_cache_initialise ();

self = (http_driver_module_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_driver_module_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_ALLOC))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_ALLOC))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_alloc_finish"
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
    http_driver_module_free

    Type: Component method
    Freess a http_driver_module_t object.
    -------------------------------------------------------------------------
 */

static void
    http_driver_module_free_ (
    http_driver_module_t * self,        //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_FREE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_FREE))
    icl_trace_record (NULL, http_driver_module_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_FREE))
    icl_stats_inc ("http_driver_module_free", &s_http_driver_module_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (http_driver_module_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_driver_module_t));
        self->object_tag = HTTP_DRIVER_MODULE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_FREE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_FREE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_free_finish"
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
    http_driver_module_read_lock

    Type: Component method
    Accepts a http_driver_module_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_driver_module_read_lock (
    http_driver_module_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_READ_LOCK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_READ_LOCK))
    icl_trace_record (NULL, http_driver_module_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_READ_LOCK))
    icl_stats_inc ("http_driver_module_read_lock", &s_http_driver_module_read_lock_stats);
#endif

HTTP_DRIVER_MODULE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_READ_LOCK))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_READ_LOCK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_read_lock_finish"
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
    http_driver_module_write_lock

    Type: Component method
    Accepts a http_driver_module_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_driver_module_write_lock (
    http_driver_module_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_WRITE_LOCK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_WRITE_LOCK))
    icl_trace_record (NULL, http_driver_module_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_WRITE_LOCK))
    icl_stats_inc ("http_driver_module_write_lock", &s_http_driver_module_write_lock_stats);
#endif

HTTP_DRIVER_MODULE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_WRITE_LOCK))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_WRITE_LOCK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_write_lock_finish"
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
    http_driver_module_unlock

    Type: Component method
    Accepts a http_driver_module_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_driver_module_unlock (
    http_driver_module_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_UNLOCK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_UNLOCK))
    icl_trace_record (NULL, http_driver_module_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_UNLOCK))
    icl_stats_inc ("http_driver_module_unlock", &s_http_driver_module_unlock_stats);
#endif

HTTP_DRIVER_MODULE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_UNLOCK))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_UNLOCK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_unlock_finish"
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
    http_driver_module_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    http_driver_module_link_ (
    http_driver_module_t * self,        //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_LINK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_LINK))
    icl_trace_record (NULL, http_driver_module_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_LINK))
    icl_stats_inc ("http_driver_module_link", &s_http_driver_module_link_stats);
#endif

    if (self) {
        HTTP_DRIVER_MODULE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_LINK))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_LINK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_link_finish"
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
    http_driver_module_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    http_driver_module_unlink_ (
    http_driver_module_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    int
        history_last;
#endif

    http_driver_module_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_UNLINK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_UNLINK))
    icl_trace_record (NULL, http_driver_module_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_UNLINK))
    icl_stats_inc ("http_driver_module_unlink", &s_http_driver_module_unlink_stats);
#endif

    if (self) {
        HTTP_DRIVER_MODULE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on http_driver_module object");
            http_driver_module_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % HTTP_DRIVER_MODULE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            http_driver_module_annihilate_ (self_p, file, line);
        http_driver_module_free_ ((http_driver_module_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_UNLINK))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_UNLINK))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_unlink_finish"
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
    http_driver_module_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_driver_module_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_CACHE_INITIALISE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_INITIALISE))
    icl_trace_record (NULL, http_driver_module_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_CACHE_INITIALISE))
    icl_stats_inc ("http_driver_module_cache_initialise", &s_http_driver_module_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_driver_module_t));
icl_system_register (http_driver_module_cache_purge, http_driver_module_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_INITIALISE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_CACHE_INITIALISE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_cache_initialise_finish"
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
    http_driver_module_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_module_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_CACHE_PURGE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_PURGE))
    icl_trace_record (NULL, http_driver_module_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_CACHE_PURGE))
    icl_stats_inc ("http_driver_module_cache_purge", &s_http_driver_module_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_PURGE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_CACHE_PURGE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_cache_purge_finish"
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
    http_driver_module_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_module_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_CACHE_TERMINATE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_TERMINATE))
    icl_trace_record (NULL, http_driver_module_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_CACHE_TERMINATE))
    icl_stats_inc ("http_driver_module_cache_terminate", &s_http_driver_module_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_TERMINATE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_CACHE_TERMINATE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_cache_terminate_finish"
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
    http_driver_module_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_driver_module_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_SHOW_ANIMATION))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SHOW_ANIMATION))
    icl_trace_record (NULL, http_driver_module_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_SHOW_ANIMATION))
    icl_stats_inc ("http_driver_module_show_animation", &s_http_driver_module_show_animation_stats);
#endif

http_driver_module_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SHOW_ANIMATION))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_SHOW_ANIMATION))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_show_animation_finish"
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
    http_driver_module_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_module_new_in_scope_ (
    http_driver_module_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink,   //  Not documented
    char * path                         //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_NEW_IN_SCOPE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" server_object=\"%pp\""
" server_link=\"%pp\""
" server_unlink=\"%pp\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server_object, server_link, server_unlink, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_driver_module_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE)  ||  defined (BASE_STATS_HTTP_DRIVER_MODULE_NEW_IN_SCOPE))
    icl_stats_inc ("http_driver_module_new_in_scope", &s_http_driver_module_new_in_scope_stats);
#endif

*self_p = http_driver_module_new_ (file,line,server_object,server_link,server_unlink,path);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_driver_module_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_driver_module_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE)   || defined (BASE_ANIMATE_HTTP_DRIVER_MODULE_NEW_IN_SCOPE))
    if (http_driver_module_animating)
        icl_console_print ("<http_driver_module_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" server_object=\"%pp\""
" server_link=\"%pp\""
" server_unlink=\"%pp\""
" path=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server_object, server_link, server_unlink, path, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_NEW)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_FACTORY)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_ANNOUNCE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_GET)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_HEAD)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_POST)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_PUT)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_DELETE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_MOVE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_REQUEST_COPY)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_DESTROY)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_READY)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SELFTEST)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_TERMINATE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SHOW)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_ALLOC)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_FREE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_READ_LOCK)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_WRITE_LOCK)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_UNLOCK)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_LINK)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_UNLINK)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_DRIVER_MODULE_NEW_IN_SCOPE) )
void
http_driver_module_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "factory"; break;
        case 3: method_name = "request announce"; break;
        case 4: method_name = "request get"; break;
        case 5: method_name = "request head"; break;
        case 6: method_name = "request post"; break;
        case 7: method_name = "request put"; break;
        case 8: method_name = "request delete"; break;
        case 9: method_name = "request move"; break;
        case 10: method_name = "request copy"; break;
        case 11: method_name = "destroy"; break;
        case 12: method_name = "ready"; break;
        case 13: method_name = "selftest"; break;
        case 14: method_name = "terminate"; break;
        case 15: method_name = "show"; break;
        case 16: method_name = "destroy public"; break;
        case 17: method_name = "alloc"; break;
        case 18: method_name = "free"; break;
        case 19: method_name = "read lock"; break;
        case 20: method_name = "write lock"; break;
        case 21: method_name = "unlock"; break;
        case 22: method_name = "link"; break;
        case 23: method_name = "unlink"; break;
        case 24: method_name = "cache initialise"; break;
        case 25: method_name = "cache purge"; break;
        case 26: method_name = "cache terminate"; break;
        case 27: method_name = "show animation"; break;
        case 28: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_driver_module %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *http_driver_module_version_start  = "VeRsIoNsTaRt:ipc";
char *http_driver_module_component  = "http_driver_module ";
char *http_driver_module_version   = "1.1 ";
char *http_driver_module_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_driver_module_filename  = "http_driver_module.icl ";
char *http_driver_module_builddate  = "2009/02/19 ";
char *http_driver_module_version_end  = "VeRsIoNeNd:ipc";

