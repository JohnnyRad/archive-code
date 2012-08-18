/*---------------------------------------------------------------------------
    http_access_logger.c - http_access_logger component

    Logs the result of access control.
    Generated from http_access_logger.icl by smt_object_gen using GSL/4.
    
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
#include "http_access_logger.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_access_logger_t

//  Shorthands for class methods                                               

#define self_announce       http_access_logger_announce
#define self_after          http_access_logger_after
#define self_new            http_access_logger_new
#define self_annihilate     http_access_logger_annihilate
#define self_initialise     http_access_logger_initialise
#define self_terminate      http_access_logger_terminate
#define self__http_access_module_new  http_access_logger__http_access_module_new
#define self__http_access_module_factory  http_access_logger__http_access_module_factory
#define self__http_access_module_unbind_shim  http_access_logger__http_access_module_unbind_shim
#define self__http_access_module_unbind  http_access_logger__http_access_module_unbind
#define self_announce_shim  http_access_logger_announce_shim
#define self_open_shim      http_access_logger_open_shim
#define self_open           http_access_logger_open
#define self_before_shim    http_access_logger_before_shim
#define self_before         http_access_logger_before
#define self_after_shim     http_access_logger_after_shim
#define self_close_shim     http_access_logger_close_shim
#define self_close          http_access_logger_close
#define self__http_access_module_link  http_access_logger__http_access_module_link
#define self__http_access_module_unlink  http_access_logger__http_access_module_unlink
#define self_selftest       http_access_logger_selftest
#define self_destroy        http_access_logger_destroy
#define self_unlink         http_access_logger_unlink
#define self_show_animation  http_access_logger_show_animation
#define self_free           http_access_logger_free
#define self_show           http_access_logger_show
#define self_alloc          http_access_logger_alloc
#define self_link           http_access_logger_link
#define self_cache_initialise  http_access_logger_cache_initialise
#define self_cache_purge    http_access_logger_cache_purge
#define self_cache_terminate  http_access_logger_cache_terminate
#define self_new_in_scope   http_access_logger_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_ANNOUNCE))
static icl_stats_t *s_http_access_logger_announce_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_AFTER))
static icl_stats_t *s_http_access_logger_after_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_NEW))
static icl_stats_t *s_http_access_logger_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_DESTROY))
static icl_stats_t *s_http_access_logger_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_INITIALISE))
static icl_stats_t *s_http_access_logger_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_TERMINATE))
static icl_stats_t *s_http_access_logger_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW))
static icl_stats_t *s_http_access_logger__http_access_module_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY))
static icl_stats_t *s_http_access_logger__http_access_module_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM))
static icl_stats_t *s_http_access_logger__http_access_module_unbind_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND))
static icl_stats_t *s_http_access_logger__http_access_module_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM))
static icl_stats_t *s_http_access_logger_announce_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_OPEN_SHIM))
static icl_stats_t *s_http_access_logger_open_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_OPEN))
static icl_stats_t *s_http_access_logger_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_BEFORE_SHIM))
static icl_stats_t *s_http_access_logger_before_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_BEFORE))
static icl_stats_t *s_http_access_logger_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_AFTER_SHIM))
static icl_stats_t *s_http_access_logger_after_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CLOSE_SHIM))
static icl_stats_t *s_http_access_logger_close_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CLOSE))
static icl_stats_t *s_http_access_logger_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK))
static icl_stats_t *s_http_access_logger__http_access_module_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK))
static icl_stats_t *s_http_access_logger__http_access_module_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_SELFTEST))
static icl_stats_t *s_http_access_logger_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC))
static icl_stats_t *s_http_access_logger_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_UNLINK))
static icl_stats_t *s_http_access_logger_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_SHOW_ANIMATION))
static icl_stats_t *s_http_access_logger_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_FREE))
static icl_stats_t *s_http_access_logger_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_SHOW))
static icl_stats_t *s_http_access_logger_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_ALLOC))
static icl_stats_t *s_http_access_logger_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_LINK))
static icl_stats_t *s_http_access_logger_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CACHE_INITIALISE))
static icl_stats_t *s_http_access_logger_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CACHE_PURGE))
static icl_stats_t *s_http_access_logger_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CACHE_TERMINATE))
static icl_stats_t *s_http_access_logger_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE))
static icl_stats_t *s_http_access_logger_new_in_scope_stats = NULL;
#endif
#define http_access_logger_annihilate(self)  http_access_logger_annihilate_ (self, __FILE__, __LINE__)
static int
    http_access_logger_annihilate_ (
http_access_logger_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    http_access_logger_initialise (
void);

static void
    http_access_logger__http_access_module_unbind_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal           //  Portal reference
);

static int
    http_access_logger_announce_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
smt_log_t * log                         //  Not documented
);

static int
    http_access_logger_open_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    http_access_logger_before_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    http_access_logger_after_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    http_access_logger_close_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static void *
    http_access_logger__http_access_module_link (
void * object                           //  Reference cast as a void *
);

static void
    http_access_logger__http_access_module_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define http_access_logger_alloc()      http_access_logger_alloc_ (__FILE__, __LINE__)
static http_access_logger_t *
    http_access_logger_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    http_access_logger_cache_initialise (
void);

static void
    http_access_logger_cache_purge (
void);

static void
    http_access_logger_cache_terminate (
void);

Bool
    http_access_logger_animating = TRUE;  //  Animation enabled by default
static Bool
    s_http_access_logger_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_http_access_logger_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_http_access_module_list;         //  List of portal factories
static Bool
    s_http_access_module_stopped;       //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    http_access_logger_announce

    Type: Component method
    Accepts a http_access_logger_t reference and returns zero in case of success,
    1 in case of errors.
    This is the announce incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_logger_announce (
    http_access_logger_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_ANNOUNCE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_announce_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" log=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ANNOUNCE))
    icl_trace_record (NULL, http_access_logger_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_ANNOUNCE))
    icl_stats_inc ("http_access_logger_announce", &s_http_access_logger_announce_stats);
#endif

HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
if (!self->zombie) {

    smt_log_print (log, "I: X5 access logging module loaded");

if (self) {
    assert (self->thread);
    if (http_access_logger_agent_announce (self->thread,portal,log)) {
        //icl_console_print ("Error sending 'announce' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ANNOUNCE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_ANNOUNCE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_announce_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" log=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_after

    Type: Component method
    Accepts a http_access_logger_t reference and returns zero in case of success,
    1 in case of errors.
    This is the after incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    Logs the HTTP transaction in the configured log format.
    -------------------------------------------------------------------------
 */

int
    http_access_logger_after (
    http_access_logger_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
char
    *format;
icl_shortstr_t
    time_str;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_AFTER))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_after_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_AFTER))
    icl_trace_record (NULL, http_access_logger_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_AFTER))
    icl_stats_inc ("http_access_logger_after", &s_http_access_logger_after_stats);
#endif

HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
if (!self->zombie) {

    //
    format = http_config_access_log_format (http_config);
    if (streq (format, "CLF"))
        smt_log_print (context->access_log,
            "%s -%s [%s] \"%s\" %d %ld",
            context->request->address,
            context->auth_user? context->auth_user: "-",
            ipr_http_time_str (time_str),
            context->request->request_line,
            context->response->reply_code,
            context->response->content_length);
    else
    if (streq (format, "CLFX"))
        smt_log_print (context->access_log,
            "%s - %s [%s] \"%s\" %d %ld \"%s\" \"%s\"",
            context->request->address,
            context->auth_user? context->auth_user: "-",
            ipr_http_time_str (time_str),
            context->request->request_line,
            context->response->reply_code,
            context->response->content_length,
            http_request_get_header (context->request, "referer"),
            http_request_get_header (context->request, "user-agent"));
    else {
        char
            *formatted = http_access_context_format (context, format);
        smt_log_print (context->access_log, "%s", formatted);
        icl_mem_free (formatted);
    }
    switch (context->fail_code) {
        case IPR_PASSWORD_OK:
        case IPR_PASSWORD_CHALLENGE:
        case IPR_PASSWORD_TRYAGAIN:
            break;                      //  Ignore, not worth logging
        case IPR_PASSWORD_NOTFOUND:
            smt_log_print (context->alert_log,
                "W: (%s) authentication failed: inexistent user '%s'",
                context->request->address, context->fail_user);
            break;
        case IPR_PASSWORD_EXPIRED:
            smt_log_print (context->alert_log,
                "W: (%s) authentication failed: user '%s' password expired",
                context->request->address, context->fail_user);
            break;
        case IPR_PASSWORD_INCORRECT:
            smt_log_print (context->alert_log,
                "W: (%s) authentication failed: incorrect password for user '%s'",
                context->request->address, context->fail_user);
            break;
        case IPR_PASSWORD_BADTYPE:
            smt_log_print (context->alert_log,
                "W: (%s) authentication failed: wrong type of authentication",
                context->request->address);
            break;
        case IPR_PASSWORD_SYNTAX:
            smt_log_print (context->alert_log,
                "W: (%s) authentication failed: syntax error in credentials",
                context->request->address);
            break;
        case IPR_PASSWORD_HOSTILE:
            smt_log_print (context->alert_log,
                "W: (%s) authentication failed: possible hostile action",
                context->request->address);
            break;
    }

if (self) {
    assert (self->thread);
    if (http_access_logger_agent_after (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'after' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_AFTER))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_AFTER))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_after_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_new

    Type: Component method
    Creates and initialises a new http_access_logger_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

http_access_logger_t *
    http_access_logger_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    http_access_logger_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_NEW))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_NEW))
    icl_trace_record (NULL, http_access_logger_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_NEW))
    icl_stats_inc ("http_access_logger_new", &s_http_access_logger_new_stats);
#endif

if (!s_http_access_logger_active)
    self_initialise ();
    self = http_access_logger_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_ACCESS_LOGGER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, http_access_logger_show_);
#endif

self->thread = http_access_logger_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->http_access_module_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_NEW))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_NEW))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_new_finish"
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
    http_access_logger_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_logger_annihilate_ (
    http_access_logger_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    int
        history_last;
#endif

    http_access_logger_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_DESTROY))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_DESTROY))
    icl_trace_record (NULL, http_access_logger_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_DESTROY))
    icl_stats_inc ("http_access_logger_annihilate", &s_http_access_logger_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (http_access_logger_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_DESTROY))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_DESTROY))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_destroy_finish"
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
    http_access_logger_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_logger_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_INITIALISE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_INITIALISE))
    icl_trace_record (NULL, http_access_logger_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_INITIALISE))
    icl_stats_inc ("http_access_logger_initialise", &s_http_access_logger_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_http_access_logger_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_http_access_logger_mutex)
            s_http_access_logger_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_http_access_logger_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_http_access_logger_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

http_access_logger_agent_init ();

s_http_access_module_list = ipr_looseref_list_new ();
            s_http_access_logger_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_http_access_logger_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_INITIALISE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_INITIALISE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_initialise_finish"
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
    http_access_logger_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_logger_terminate (
void)
{
http_access_module_t
    *http_access_module;            //  Portal factory object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_TERMINATE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_TERMINATE))
    icl_trace_record (NULL, http_access_logger_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_TERMINATE))
    icl_stats_inc ("http_access_logger_terminate", &s_http_access_logger_terminate_stats);
#endif

if (s_http_access_logger_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_http_access_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_access_module = (http_access_module_t *) ipr_looseref_pop (s_http_access_module_list))) {
        http_access_module->server_looseref = NULL;
        http_access_module_destroy (&http_access_module);
    }
}
ipr_looseref_list_destroy (&s_http_access_module_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_http_access_logger_mutex);
#endif
        s_http_access_logger_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_TERMINATE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_TERMINATE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_terminate_finish"
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
    http_access_logger__http_access_module_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

http_access_module_t *
    http_access_logger__http_access_module_new (
    void * self_v                       //  Untyped server reference
)
{
http_access_logger_t
    *self;
    http_access_module_t *
        http_access_module;             //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW))
    icl_trace_record (NULL, http_access_logger_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW))
    icl_stats_inc ("http_access_logger__http_access_module_new", &s_http_access_logger__http_access_module_new_stats);
#endif

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((http_access_logger_t *) self_v);
else
    self = self_new ();

http_access_module = http_access_module_new (self, self__http_access_module_link, self__http_access_module_unlink);
http_access_module->server_looseref = ipr_looseref_queue (
    self->http_access_module_list, http_access_module_link (http_access_module));

//  Build virtual methods for server-side methods
http_access_module->server_unbind = self__http_access_module_unbind_shim;
http_access_module->request_announce = self_announce_shim;
http_access_module->request_open = self_open_shim;
http_access_module->request_before = self_before_shim;
http_access_module->request_after = self_after_shim;
http_access_module->request_close = self_close_shim;

//  Drop link to server object
self_unlink (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" http_access_module=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, http_access_module);
#endif


    return (http_access_module);
}
/*  -------------------------------------------------------------------------
    http_access_logger__http_access_module_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

http_access_module_t *
    http_access_logger__http_access_module_factory (
void)
{
    http_access_module_t *
        http_access_module;             //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_factory_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY))
    icl_trace_record (NULL, http_access_logger_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY))
    icl_stats_inc ("http_access_logger__http_access_module_factory", &s_http_access_logger__http_access_module_factory_stats);
#endif

//
if (!s_http_access_logger_active)
    self_initialise ();             //  Since we don't call http_access_logger_new
http_access_module = http_access_module_new (NULL, self__http_access_module_link, self__http_access_module_unlink);
http_access_module->server_looseref = ipr_looseref_queue (
    s_http_access_module_list, http_access_module_link (http_access_module));

//  Build virtual methods for server-side methods
http_access_module->server_new = self__http_access_module_new;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_factory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" http_access_module=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, http_access_module);
#endif


    return (http_access_module);
}
/*  -------------------------------------------------------------------------
    http_access_logger__http_access_module_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_logger__http_access_module_unbind_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal       //  Portal reference
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_unbind_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    icl_stats_inc ("http_access_logger__http_access_module_unbind_shim", &s_http_access_logger__http_access_module_unbind_shim_stats);
#endif

self__http_access_module_unbind ((http_access_logger_t *) self_v, portal);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_unbind_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal);
#endif

}
/*  -------------------------------------------------------------------------
    http_access_logger__http_access_module_unbind

    Type: Component method
    Accepts a http_access_logger_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    http_access_logger__http_access_module_unbind (
    http_access_logger_t * self,        //  Reference to object
    http_access_module_t * portal       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_unbind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND))
    icl_trace_record (NULL, http_access_logger_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND))
    icl_stats_inc ("http_access_logger__http_access_module_unbind", &s_http_access_logger__http_access_module_unbind_stats);
#endif

HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (http_access_logger_agent__http_access_module_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_http_access_module unbind' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_unbind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_announce_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_logger_announce_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_announce_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" log=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM))
    icl_stats_inc ("http_access_logger_announce_shim", &s_http_access_logger_announce_shim_stats);
#endif

rc = self_announce ((http_access_logger_t *) self_v, portal, log);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_announce_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" log=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_open_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_logger_open_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_OPEN_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_open_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_OPEN_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_OPEN_SHIM))
    icl_stats_inc ("http_access_logger_open_shim", &s_http_access_logger_open_shim_stats);
#endif

rc = self_open ((http_access_logger_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_OPEN_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_OPEN_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_open_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_open

    Type: Component method
    Accepts a http_access_logger_t reference and returns zero in case of success,
    1 in case of errors.
    This is the open incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_logger_open (
    http_access_logger_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_OPEN))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_OPEN))
    icl_trace_record (NULL, http_access_logger_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_OPEN))
    icl_stats_inc ("http_access_logger_open", &s_http_access_logger_open_stats);
#endif

HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_access_logger_agent_open (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'open' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_OPEN))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_OPEN))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_before_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_logger_before_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_BEFORE_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_before_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_BEFORE_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_BEFORE_SHIM))
    icl_stats_inc ("http_access_logger_before_shim", &s_http_access_logger_before_shim_stats);
#endif

rc = self_before ((http_access_logger_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_BEFORE_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_BEFORE_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_before_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_before

    Type: Component method
    Accepts a http_access_logger_t reference and returns zero in case of success,
    1 in case of errors.
    This is the before incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_logger_before (
    http_access_logger_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_BEFORE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_before_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_BEFORE))
    icl_trace_record (NULL, http_access_logger_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_BEFORE))
    icl_stats_inc ("http_access_logger_before", &s_http_access_logger_before_stats);
#endif

HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_access_logger_agent_before (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'before' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_BEFORE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_BEFORE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_before_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_after_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_logger_after_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_AFTER_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_after_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_AFTER_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_AFTER_SHIM))
    icl_stats_inc ("http_access_logger_after_shim", &s_http_access_logger_after_shim_stats);
#endif

rc = self_after ((http_access_logger_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_AFTER_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_AFTER_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_after_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_close_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_logger_close_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CLOSE_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_close_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CLOSE_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CLOSE_SHIM))
    icl_stats_inc ("http_access_logger_close_shim", &s_http_access_logger_close_shim_stats);
#endif

rc = self_close ((http_access_logger_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CLOSE_SHIM))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CLOSE_SHIM))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_close_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger_close

    Type: Component method
    Accepts a http_access_logger_t reference and returns zero in case of success,
    1 in case of errors.
    This is the close incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_logger_close (
    http_access_logger_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CLOSE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_close_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CLOSE))
    icl_trace_record (NULL, http_access_logger_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CLOSE))
    icl_stats_inc ("http_access_logger_close", &s_http_access_logger_close_stats);
#endif

HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_access_logger_agent_close (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'close' method to http_access_logger agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CLOSE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CLOSE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_close_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" context=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, context, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_logger__http_access_module_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    http_access_logger__http_access_module_link (
    void * object                       //  Reference cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK))
    icl_trace_record (NULL, http_access_logger_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK))
    icl_stats_inc ("http_access_logger__http_access_module_link", &s_http_access_logger__http_access_module_link_stats);
#endif

//
object = (void *) http_access_logger_link (((http_access_logger_t *) object));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object);
#endif


    return (object);
}
/*  -------------------------------------------------------------------------
    http_access_logger__http_access_module_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_logger__http_access_module_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object_p=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object_p);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK))
    icl_trace_record (NULL, http_access_logger_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK))
    icl_stats_inc ("http_access_logger__http_access_module_unlink", &s_http_access_logger__http_access_module_unlink_stats);
#endif

//
http_access_logger_unlink (((http_access_logger_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger__http_access_module_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" object_p=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, object_p);
#endif

}
/*  -------------------------------------------------------------------------
    http_access_logger_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_logger_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_SELFTEST))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SELFTEST))
    icl_trace_record (NULL, http_access_logger_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_SELFTEST))
    icl_stats_inc ("http_access_logger_selftest", &s_http_access_logger_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SELFTEST))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_SELFTEST))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_selftest_finish"
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
    http_access_logger_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_access_logger_destroy_ (
    http_access_logger_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_access_logger_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_access_logger_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC))
    icl_stats_inc ("http_access_logger_destroy", &s_http_access_logger_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = http_access_logger_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        http_access_logger_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_destroy_public_finish"
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
    http_access_logger_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    http_access_logger_unlink_ (
    http_access_logger_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    int
        history_last;
#endif
    http_access_logger_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_UNLINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_UNLINK))
    icl_trace_record (NULL, http_access_logger_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_UNLINK))
    icl_stats_inc ("http_access_logger_unlink", &s_http_access_logger_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on http_access_logger object");
            http_access_logger_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                http_access_logger_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                http_access_logger_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_UNLINK))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_UNLINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_unlink_finish"
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
    http_access_logger_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_access_logger_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_SHOW_ANIMATION))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SHOW_ANIMATION))
    icl_trace_record (NULL, http_access_logger_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_SHOW_ANIMATION))
    icl_stats_inc ("http_access_logger_show_animation", &s_http_access_logger_show_animation_stats);
#endif

http_access_logger_animating = enabled;

http_access_logger_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SHOW_ANIMATION))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_SHOW_ANIMATION))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_show_animation_finish"
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
    http_access_logger_free

    Type: Component method
    Freess a http_access_logger_t object.
    -------------------------------------------------------------------------
 */

void
    http_access_logger_free_ (
    http_access_logger_t * self,        //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_FREE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_FREE))
    icl_trace_record (NULL, http_access_logger_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_FREE))
    icl_stats_inc ("http_access_logger_free", &s_http_access_logger_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (http_access_logger_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_access_logger_t));
        self->object_tag = HTTP_ACCESS_LOGGER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_FREE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_FREE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_free_finish"
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
    http_access_logger_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_logger_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_access_logger_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_SHOW))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SHOW))
    icl_trace_record (NULL, http_access_logger_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_SHOW))
    icl_stats_inc ("http_access_logger_show", &s_http_access_logger_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <http_access_logger zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    if (self->history_last > HTTP_ACCESS_LOGGER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % HTTP_ACCESS_LOGGER_HISTORY_LENGTH;
        self->history_last %= HTTP_ACCESS_LOGGER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % HTTP_ACCESS_LOGGER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </http_access_logger>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SHOW))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_SHOW))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_show_finish"
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
    http_access_logger_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_access_logger_t *
    http_access_logger_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_access_logger_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_ALLOC))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ALLOC))
    icl_trace_record (NULL, http_access_logger_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_ALLOC))
    icl_stats_inc ("http_access_logger_alloc", &s_http_access_logger_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_access_logger_cache_initialise ();

self = (http_access_logger_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_access_logger_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ALLOC))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_ALLOC))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_alloc_finish"
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
    http_access_logger_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

http_access_logger_t *
    http_access_logger_link_ (
    http_access_logger_t * self,        //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_LINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_LINK))
    icl_trace_record (NULL, http_access_logger_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_LINK))
    icl_stats_inc ("http_access_logger_link", &s_http_access_logger_link_stats);
#endif

    if (self) {
        HTTP_ACCESS_LOGGER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_LOGGER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % HTTP_ACCESS_LOGGER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_LINK))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_LINK))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_link_finish"
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
    http_access_logger_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_access_logger_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CACHE_INITIALISE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_INITIALISE))
    icl_trace_record (NULL, http_access_logger_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CACHE_INITIALISE))
    icl_stats_inc ("http_access_logger_cache_initialise", &s_http_access_logger_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_access_logger_t));
icl_system_register (http_access_logger_cache_purge, http_access_logger_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_INITIALISE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CACHE_INITIALISE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_cache_initialise_finish"
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
    http_access_logger_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_logger_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CACHE_PURGE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_PURGE))
    icl_trace_record (NULL, http_access_logger_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CACHE_PURGE))
    icl_stats_inc ("http_access_logger_cache_purge", &s_http_access_logger_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_PURGE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CACHE_PURGE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_cache_purge_finish"
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
    http_access_logger_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_logger_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CACHE_TERMINATE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_TERMINATE))
    icl_trace_record (NULL, http_access_logger_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_CACHE_TERMINATE))
    icl_stats_inc ("http_access_logger_cache_terminate", &s_http_access_logger_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_TERMINATE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_CACHE_TERMINATE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_cache_terminate_finish"
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
    http_access_logger_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_logger_new_in_scope_ (
    http_access_logger_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_access_logger_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER)  ||  defined (BASE_STATS_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE))
    icl_stats_inc ("http_access_logger_new_in_scope", &s_http_access_logger_new_in_scope_stats);
#endif

*self_p = http_access_logger_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_access_logger_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_access_logger_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER)   || defined (BASE_ANIMATE_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE))
    if (http_access_logger_animating)
        icl_console_print ("<http_access_logger_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ANNOUNCE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_AFTER)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_DESTROY)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_FACTORY)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNBIND)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ANNOUNCE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_OPEN_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_OPEN)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_BEFORE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_BEFORE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_AFTER_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CLOSE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CLOSE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_LINK)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER__HTTP_ACCESS_MODULE_UNLINK)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SELFTEST)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_UNLINK)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_FREE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_SHOW)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_ALLOC)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_LINK)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_LOGGER_NEW_IN_SCOPE) )
void
http_access_logger_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "announce"; break;
        case 2: method_name = "after"; break;
        case 3: method_name = "new"; break;
        case 4: method_name = "destroy"; break;
        case 5: method_name = "initialise"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "_http_access_module new"; break;
        case 8: method_name = "_http_access_module factory"; break;
        case 9: method_name = "_http_access_module unbind shim"; break;
        case 10: method_name = "_http_access_module unbind"; break;
        case 11: method_name = "announce shim"; break;
        case 12: method_name = "open shim"; break;
        case 13: method_name = "open"; break;
        case 14: method_name = "before shim"; break;
        case 15: method_name = "before"; break;
        case 16: method_name = "after shim"; break;
        case 17: method_name = "close shim"; break;
        case 18: method_name = "close"; break;
        case 19: method_name = "_http_access_module link"; break;
        case 20: method_name = "_http_access_module unlink"; break;
        case 21: method_name = "selftest"; break;
        case 22: method_name = "destroy public"; break;
        case 23: method_name = "unlink"; break;
        case 24: method_name = "show animation"; break;
        case 25: method_name = "free"; break;
        case 26: method_name = "show"; break;
        case 27: method_name = "alloc"; break;
        case 28: method_name = "link"; break;
        case 29: method_name = "cache initialise"; break;
        case 30: method_name = "cache purge"; break;
        case 31: method_name = "cache terminate"; break;
        case 32: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_access_logger %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *http_access_logger_version_start  = "VeRsIoNsTaRt:ipc";
char *http_access_logger_component  = "http_access_logger ";
char *http_access_logger_version   = "0.0 ";
char *http_access_logger_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_access_logger_filename  = "http_access_logger.icl ";
char *http_access_logger_builddate  = "2009/02/19 ";
char *http_access_logger_version_end  = "VeRsIoNeNd:ipc";

