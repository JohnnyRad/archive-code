/*---------------------------------------------------------------------------
    http_access_policy.c - http_access_policy component

    Applies access control policies to the HTTP request.
    Generated from http_access_policy.icl by smt_object_gen using GSL/4.
    
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
#include "http_access_policy.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_access_policy_t

//  Shorthands for class methods                                               

#define self_announce       http_access_policy_announce
#define self_before         http_access_policy_before
#define self_selftest       http_access_policy_selftest
#define self_new            http_access_policy_new
#define self_annihilate     http_access_policy_annihilate
#define self_initialise     http_access_policy_initialise
#define self_terminate      http_access_policy_terminate
#define self__http_access_module_new  http_access_policy__http_access_module_new
#define self__http_access_module_factory  http_access_policy__http_access_module_factory
#define self__http_access_module_unbind_shim  http_access_policy__http_access_module_unbind_shim
#define self__http_access_module_unbind  http_access_policy__http_access_module_unbind
#define self_announce_shim  http_access_policy_announce_shim
#define self_open_shim      http_access_policy_open_shim
#define self_open           http_access_policy_open
#define self_before_shim    http_access_policy_before_shim
#define self_after_shim     http_access_policy_after_shim
#define self_after          http_access_policy_after
#define self_close_shim     http_access_policy_close_shim
#define self_close          http_access_policy_close
#define self__http_access_module_link  http_access_policy__http_access_module_link
#define self__http_access_module_unlink  http_access_policy__http_access_module_unlink
#define self_destroy        http_access_policy_destroy
#define self_unlink         http_access_policy_unlink
#define self_show_animation  http_access_policy_show_animation
#define self_free           http_access_policy_free
#define self_show           http_access_policy_show
#define self_alloc          http_access_policy_alloc
#define self_link           http_access_policy_link
#define self_cache_initialise  http_access_policy_cache_initialise
#define self_cache_purge    http_access_policy_cache_purge
#define self_cache_terminate  http_access_policy_cache_terminate
#define self_new_in_scope   http_access_policy_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_ANNOUNCE))
static icl_stats_t *s_http_access_policy_announce_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_BEFORE))
static icl_stats_t *s_http_access_policy_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_SELFTEST))
static icl_stats_t *s_http_access_policy_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_NEW))
static icl_stats_t *s_http_access_policy_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_DESTROY))
static icl_stats_t *s_http_access_policy_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_INITIALISE))
static icl_stats_t *s_http_access_policy_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_TERMINATE))
static icl_stats_t *s_http_access_policy_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW))
static icl_stats_t *s_http_access_policy__http_access_module_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY))
static icl_stats_t *s_http_access_policy__http_access_module_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM))
static icl_stats_t *s_http_access_policy__http_access_module_unbind_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND))
static icl_stats_t *s_http_access_policy__http_access_module_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM))
static icl_stats_t *s_http_access_policy_announce_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_OPEN_SHIM))
static icl_stats_t *s_http_access_policy_open_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_OPEN))
static icl_stats_t *s_http_access_policy_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_BEFORE_SHIM))
static icl_stats_t *s_http_access_policy_before_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_AFTER_SHIM))
static icl_stats_t *s_http_access_policy_after_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_AFTER))
static icl_stats_t *s_http_access_policy_after_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CLOSE_SHIM))
static icl_stats_t *s_http_access_policy_close_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CLOSE))
static icl_stats_t *s_http_access_policy_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK))
static icl_stats_t *s_http_access_policy__http_access_module_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK))
static icl_stats_t *s_http_access_policy__http_access_module_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_DESTROY_PUBLIC))
static icl_stats_t *s_http_access_policy_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_UNLINK))
static icl_stats_t *s_http_access_policy_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_SHOW_ANIMATION))
static icl_stats_t *s_http_access_policy_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_FREE))
static icl_stats_t *s_http_access_policy_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_SHOW))
static icl_stats_t *s_http_access_policy_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_ALLOC))
static icl_stats_t *s_http_access_policy_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_LINK))
static icl_stats_t *s_http_access_policy_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CACHE_INITIALISE))
static icl_stats_t *s_http_access_policy_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CACHE_PURGE))
static icl_stats_t *s_http_access_policy_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CACHE_TERMINATE))
static icl_stats_t *s_http_access_policy_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_NEW_IN_SCOPE))
static icl_stats_t *s_http_access_policy_new_in_scope_stats = NULL;
#endif
#define http_access_policy_annihilate(self)  http_access_policy_annihilate_ (self, __FILE__, __LINE__)
static int
    http_access_policy_annihilate_ (
http_access_policy_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    http_access_policy_initialise (
void);

static void
    http_access_policy__http_access_module_unbind_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal           //  Portal reference
);

static int
    http_access_policy_announce_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
smt_log_t * log                         //  Not documented
);

static int
    http_access_policy_open_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    http_access_policy_before_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    http_access_policy_after_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static int
    http_access_policy_close_shim (
void * self_v,                          //  Self as void pointer
http_access_module_t * portal,          //  Portal back to server
http_access_context_t * context         //  Not documented
);

static void *
    http_access_policy__http_access_module_link (
void * object                           //  Reference cast as a void *
);

static void
    http_access_policy__http_access_module_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define http_access_policy_alloc()      http_access_policy_alloc_ (__FILE__, __LINE__)
static http_access_policy_t *
    http_access_policy_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    http_access_policy_cache_initialise (
void);

static void
    http_access_policy_cache_purge (
void);

static void
    http_access_policy_cache_terminate (
void);

Bool
    http_access_policy_animating = TRUE;  //  Animation enabled by default
static Bool
    s_http_access_policy_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_http_access_policy_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_http_access_module_list;         //  List of portal factories
static Bool
    s_http_access_module_stopped;       //  Is this portal factory stopped?
static void
s_trace (http_access_context_t *context, char *format, ...);
static Bool
s_execute_policy (http_access_context_t *context, ipr_config_t *config);
static int
s_execute_rule (http_access_context_t *context, ipr_config_t *config);
static int
s_execute_actions (http_access_context_t *context, ipr_config_t *config);
static int
s_execute_authenticate (http_access_context_t *context, ipr_config_t *config);
/*  -------------------------------------------------------------------------
    http_access_policy_announce

    Type: Component method
    Accepts a http_access_policy_t reference and returns zero in case of success,
    1 in case of errors.
    This is the announce incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_policy_announce (
    http_access_policy_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_ANNOUNCE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_announce_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE))
    icl_trace_record (NULL, http_access_policy_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_ANNOUNCE))
    icl_stats_inc ("http_access_policy_announce", &s_http_access_policy_announce_stats);
#endif

HTTP_ACCESS_POLICY_ASSERT_SANE (self);
if (!self->zombie) {

    smt_log_print (log, "I: X5 access policy module loaded");

if (self) {
    assert (self->thread);
    if (http_access_policy_agent_announce (self->thread,portal,log)) {
        //icl_console_print ("Error sending 'announce' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_ANNOUNCE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_announce_finish"
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
    http_access_policy_before

    Type: Component method
    Accepts a http_access_policy_t reference and returns zero in case of success,
    1 in case of errors.
    This is the before incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    Checks the request against the defined access policies.  If the policies
    decided a firm allow/deny, returns 1.  For a deny, prepares the response
    object accordingly.

    Sets the response accordingly, and returns 1 if the request was allowed
    or denied, and -1 if the request is still in progress.  In that case the
    calling thread will receive a deny or allow method at some later time.
    -------------------------------------------------------------------------
 */

int
    http_access_policy_before (
    http_access_policy_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
ipr_config_t
    *config;
Bool
    decision = FALSE;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_BEFORE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_before_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE))
    icl_trace_record (NULL, http_access_policy_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_BEFORE))
    icl_stats_inc ("http_access_policy_before", &s_http_access_policy_before_stats);
#endif

HTTP_ACCESS_POLICY_ASSERT_SANE (self);
if (!self->zombie) {

    //
    //  Get a threadsafe handle of the config for our work here
    config = ipr_config_dup (http_config->config);
    s_trace (context, "P: starting policy check on request '%s'", context->request->request_line);

    //  Execute all policies except the default
    ipr_config_locate (config, "/config/access/policy", NULL);
    while (config->located && !decision) {
        if (strneq (ipr_config_get (config, "name", ""), "default")) {
            s_trace (context, "P: executing '%s' policy", ipr_config_get (config, "name", ""));
            decision = s_execute_policy (context, config);
        }
        ipr_config_next (config);
    }
    //  If no decision, execute the default policy
    if (!decision) {
        ipr_config_locate (config, "/config/access/policy", "default");
        if (config->located) {
            s_trace (context, "P: no decision - executing default policy");
            decision = s_execute_policy (context, config);
        }
    }
    //  If still decision, deny the URI
    if (decision)
        s_trace (context, "P: ending policy check, reply_code=%d", context->response->reply_code);
    else {
        s_trace (context, "P: no decision - denying access to resource");
        http_response_set_error (context->response, HTTP_REPLY_FORBIDDEN, "No access policy");
    }
    //  Drop our handle to the config
    ipr_config_destroy (&config);

if (self) {
    assert (self->thread);
    if (http_access_policy_agent_before (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'before' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_BEFORE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_before_finish"
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
    http_access_policy_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_policy_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_SELFTEST))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SELFTEST))
    icl_trace_record (NULL, http_access_policy_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_SELFTEST))
    icl_stats_inc ("http_access_policy_selftest", &s_http_access_policy_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SELFTEST))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_SELFTEST))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_selftest_finish"
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
    http_access_policy_new

    Type: Component method
    Creates and initialises a new http_access_policy_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

http_access_policy_t *
    http_access_policy_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    http_access_policy_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_NEW))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW))
    icl_trace_record (NULL, http_access_policy_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_NEW))
    icl_stats_inc ("http_access_policy_new", &s_http_access_policy_new_stats);
#endif

if (!s_http_access_policy_active)
    self_initialise ();
    self = http_access_policy_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_ACCESS_POLICY_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, http_access_policy_show_);
#endif

self->thread = http_access_policy_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->http_access_module_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_NEW))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_new_finish"
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
    http_access_policy_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_policy_annihilate_ (
    http_access_policy_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    int
        history_last;
#endif

    http_access_policy_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_DESTROY))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY))
    icl_trace_record (NULL, http_access_policy_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_DESTROY))
    icl_stats_inc ("http_access_policy_annihilate", &s_http_access_policy_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = file;
    self->history_line  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = line;
    self->history_type  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (http_access_policy_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_DESTROY))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_destroy_finish"
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
    http_access_policy_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_policy_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_INITIALISE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_INITIALISE))
    icl_trace_record (NULL, http_access_policy_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_INITIALISE))
    icl_stats_inc ("http_access_policy_initialise", &s_http_access_policy_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_http_access_policy_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_http_access_policy_mutex)
            s_http_access_policy_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_http_access_policy_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_http_access_policy_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

http_access_policy_agent_init ();

s_http_access_module_list = ipr_looseref_list_new ();
            s_http_access_policy_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_http_access_policy_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_INITIALISE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_INITIALISE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_initialise_finish"
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
    http_access_policy_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_policy_terminate (
void)
{
http_access_module_t
    *http_access_module;            //  Portal factory object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_TERMINATE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_TERMINATE))
    icl_trace_record (NULL, http_access_policy_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_TERMINATE))
    icl_stats_inc ("http_access_policy_terminate", &s_http_access_policy_terminate_stats);
#endif

if (s_http_access_policy_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_http_access_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_access_module = (http_access_module_t *) ipr_looseref_pop (s_http_access_module_list))) {
        http_access_module->server_looseref = NULL;
        http_access_module_destroy (&http_access_module);
    }
}
ipr_looseref_list_destroy (&s_http_access_module_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_http_access_policy_mutex);
#endif
        s_http_access_policy_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_TERMINATE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_TERMINATE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_terminate_finish"
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
    http_access_policy__http_access_module_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

http_access_module_t *
    http_access_policy__http_access_module_new (
    void * self_v                       //  Untyped server reference
)
{
http_access_policy_t
    *self;
    http_access_module_t *
        http_access_module;             //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW))
    icl_trace_record (NULL, http_access_policy_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW))
    icl_stats_inc ("http_access_policy__http_access_module_new", &s_http_access_policy__http_access_module_new_stats);
#endif

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((http_access_policy_t *) self_v);
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_new_finish"
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
    http_access_policy__http_access_module_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

http_access_module_t *
    http_access_policy__http_access_module_factory (
void)
{
    http_access_module_t *
        http_access_module;             //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_factory_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY))
    icl_trace_record (NULL, http_access_policy_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY))
    icl_stats_inc ("http_access_policy__http_access_module_factory", &s_http_access_policy__http_access_module_factory_stats);
#endif

//
if (!s_http_access_policy_active)
    self_initialise ();             //  Since we don't call http_access_policy_new
http_access_module = http_access_module_new (NULL, self__http_access_module_link, self__http_access_module_unlink);
http_access_module->server_looseref = ipr_looseref_queue (
    s_http_access_module_list, http_access_module_link (http_access_module));

//  Build virtual methods for server-side methods
http_access_module->server_new = self__http_access_module_new;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_factory_finish"
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
    http_access_policy__http_access_module_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_policy__http_access_module_unbind_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal       //  Portal reference
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_unbind_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    icl_stats_inc ("http_access_policy__http_access_module_unbind_shim", &s_http_access_policy__http_access_module_unbind_shim_stats);
#endif

self__http_access_module_unbind ((http_access_policy_t *) self_v, portal);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_unbind_shim_finish"
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
    http_access_policy__http_access_module_unbind

    Type: Component method
    Accepts a http_access_policy_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    http_access_policy__http_access_module_unbind (
    http_access_policy_t * self,        //  Reference to object
    http_access_module_t * portal       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_unbind_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND))
    icl_trace_record (NULL, http_access_policy_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND))
    icl_stats_inc ("http_access_policy__http_access_module_unbind", &s_http_access_policy__http_access_module_unbind_stats);
#endif

HTTP_ACCESS_POLICY_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (http_access_policy_agent__http_access_module_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_http_access_module unbind' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_unbind_finish"
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
    http_access_policy_announce_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_policy_announce_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_announce_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM))
    icl_stats_inc ("http_access_policy_announce_shim", &s_http_access_policy_announce_shim_stats);
#endif

rc = self_announce ((http_access_policy_t *) self_v, portal, log);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_announce_shim_finish"
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
    http_access_policy_open_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_policy_open_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_OPEN_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_open_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_OPEN_SHIM))
    icl_stats_inc ("http_access_policy_open_shim", &s_http_access_policy_open_shim_stats);
#endif

rc = self_open ((http_access_policy_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_OPEN_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_open_shim_finish"
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
    http_access_policy_open

    Type: Component method
    Accepts a http_access_policy_t reference and returns zero in case of success,
    1 in case of errors.
    This is the open incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_policy_open (
    http_access_policy_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_OPEN))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_open_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN))
    icl_trace_record (NULL, http_access_policy_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_OPEN))
    icl_stats_inc ("http_access_policy_open", &s_http_access_policy_open_stats);
#endif

HTTP_ACCESS_POLICY_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_access_policy_agent_open (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'open' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_OPEN))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_open_finish"
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
    http_access_policy_before_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_policy_before_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_BEFORE_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_before_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_BEFORE_SHIM))
    icl_stats_inc ("http_access_policy_before_shim", &s_http_access_policy_before_shim_stats);
#endif

rc = self_before ((http_access_policy_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_BEFORE_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_before_shim_finish"
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
    http_access_policy_after_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_policy_after_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_AFTER_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_after_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_AFTER_SHIM))
    icl_stats_inc ("http_access_policy_after_shim", &s_http_access_policy_after_shim_stats);
#endif

rc = self_after ((http_access_policy_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_AFTER_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_after_shim_finish"
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
    http_access_policy_after

    Type: Component method
    Accepts a http_access_policy_t reference and returns zero in case of success,
    1 in case of errors.
    This is the after incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_policy_after (
    http_access_policy_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_AFTER))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_after_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER))
    icl_trace_record (NULL, http_access_policy_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_AFTER))
    icl_stats_inc ("http_access_policy_after", &s_http_access_policy_after_stats);
#endif

HTTP_ACCESS_POLICY_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_access_policy_agent_after (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'after' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_AFTER))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_after_finish"
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
    http_access_policy_close_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_access_policy_close_shim (
    void * self_v,                      //  Self as void pointer
    http_access_module_t * portal,      //  Portal back to server
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CLOSE_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_close_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CLOSE_SHIM))
    icl_stats_inc ("http_access_policy_close_shim", &s_http_access_policy_close_shim_stats);
#endif

rc = self_close ((http_access_policy_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE_SHIM))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CLOSE_SHIM))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_close_shim_finish"
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
    http_access_policy_close

    Type: Component method
    Accepts a http_access_policy_t reference and returns zero in case of success,
    1 in case of errors.
    This is the close incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_access_policy_close (
    http_access_policy_t * self,        //  Reference to object
    http_access_module_t * portal,      //  Portal back to client
    http_access_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CLOSE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_close_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE))
    icl_trace_record (NULL, http_access_policy_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CLOSE))
    icl_stats_inc ("http_access_policy_close", &s_http_access_policy_close_stats);
#endif

HTTP_ACCESS_POLICY_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_access_policy_agent_close (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'close' method to http_access_policy agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CLOSE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_close_finish"
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
    http_access_policy__http_access_module_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    http_access_policy__http_access_module_link (
    void * object                       //  Reference cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK))
    icl_trace_record (NULL, http_access_policy_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK))
    icl_stats_inc ("http_access_policy__http_access_module_link", &s_http_access_policy__http_access_module_link_stats);
#endif

//
object = (void *) http_access_policy_link (((http_access_policy_t *) object));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_link_finish"
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
    http_access_policy__http_access_module_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_policy__http_access_module_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK))
    icl_trace_record (NULL, http_access_policy_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK))
    icl_stats_inc ("http_access_policy__http_access_module_unlink", &s_http_access_policy__http_access_module_unlink_stats);
#endif

//
http_access_policy_unlink (((http_access_policy_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy__http_access_module_unlink_finish"
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
    http_access_policy_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_access_policy_destroy_ (
    http_access_policy_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_access_policy_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_DESTROY_PUBLIC))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_access_policy_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_DESTROY_PUBLIC))
    icl_stats_inc ("http_access_policy_destroy", &s_http_access_policy_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = http_access_policy_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        http_access_policy_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_DESTROY_PUBLIC))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_destroy_public_finish"
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
    http_access_policy_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    http_access_policy_unlink_ (
    http_access_policy_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    int
        history_last;
#endif
    http_access_policy_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_UNLINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_UNLINK))
    icl_trace_record (NULL, http_access_policy_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_UNLINK))
    icl_stats_inc ("http_access_policy_unlink", &s_http_access_policy_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on http_access_policy object");
            http_access_policy_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                http_access_policy_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                http_access_policy_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_UNLINK))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_UNLINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_unlink_finish"
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
    http_access_policy_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_access_policy_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_SHOW_ANIMATION))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW_ANIMATION))
    icl_trace_record (NULL, http_access_policy_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_SHOW_ANIMATION))
    icl_stats_inc ("http_access_policy_show_animation", &s_http_access_policy_show_animation_stats);
#endif

http_access_policy_animating = enabled;

http_access_policy_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW_ANIMATION))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_SHOW_ANIMATION))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_show_animation_finish"
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
    http_access_policy_free

    Type: Component method
    Freess a http_access_policy_t object.
    -------------------------------------------------------------------------
 */

void
    http_access_policy_free_ (
    http_access_policy_t * self,        //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_FREE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_FREE))
    icl_trace_record (NULL, http_access_policy_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_FREE))
    icl_stats_inc ("http_access_policy_free", &s_http_access_policy_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = "free";
        self->history_links [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (http_access_policy_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_access_policy_t));
        self->object_tag = HTTP_ACCESS_POLICY_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_FREE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_FREE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_free_finish"
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
    http_access_policy_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_policy_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_access_policy_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_SHOW))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW))
    icl_trace_record (NULL, http_access_policy_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_SHOW))
    icl_stats_inc ("http_access_policy_show", &s_http_access_policy_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <http_access_policy zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    if (self->history_last > HTTP_ACCESS_POLICY_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % HTTP_ACCESS_POLICY_HISTORY_LENGTH;
        self->history_last %= HTTP_ACCESS_POLICY_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % HTTP_ACCESS_POLICY_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </http_access_policy>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_SHOW))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_show_finish"
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
    http_access_policy_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_access_policy_t *
    http_access_policy_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_access_policy_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_ALLOC))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ALLOC))
    icl_trace_record (NULL, http_access_policy_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_ALLOC))
    icl_stats_inc ("http_access_policy_alloc", &s_http_access_policy_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_access_policy_cache_initialise ();

self = (http_access_policy_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_access_policy_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ALLOC))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_ALLOC))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_alloc_finish"
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
    http_access_policy_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

http_access_policy_t *
    http_access_policy_link_ (
    http_access_policy_t * self,        //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_LINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_LINK))
    icl_trace_record (NULL, http_access_policy_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_LINK))
    icl_stats_inc ("http_access_policy_link", &s_http_access_policy_link_stats);
#endif

    if (self) {
        HTTP_ACCESS_POLICY_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_ACCESS_POLICY)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = "link";
        self->history_links [history_last % HTTP_ACCESS_POLICY_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_LINK))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_LINK))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_link_finish"
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
    http_access_policy_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_access_policy_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CACHE_INITIALISE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_INITIALISE))
    icl_trace_record (NULL, http_access_policy_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CACHE_INITIALISE))
    icl_stats_inc ("http_access_policy_cache_initialise", &s_http_access_policy_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_access_policy_t));
icl_system_register (http_access_policy_cache_purge, http_access_policy_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_INITIALISE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CACHE_INITIALISE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_cache_initialise_finish"
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
    http_access_policy_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_policy_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CACHE_PURGE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_PURGE))
    icl_trace_record (NULL, http_access_policy_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CACHE_PURGE))
    icl_stats_inc ("http_access_policy_cache_purge", &s_http_access_policy_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_PURGE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CACHE_PURGE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_cache_purge_finish"
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
    http_access_policy_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_policy_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CACHE_TERMINATE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_TERMINATE))
    icl_trace_record (NULL, http_access_policy_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_CACHE_TERMINATE))
    icl_stats_inc ("http_access_policy_cache_terminate", &s_http_access_policy_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_TERMINATE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_CACHE_TERMINATE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_cache_terminate_finish"
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
    http_access_policy_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_policy_new_in_scope_ (
    http_access_policy_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_NEW_IN_SCOPE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_access_policy_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY)  ||  defined (BASE_STATS_HTTP_ACCESS_POLICY_NEW_IN_SCOPE))
    icl_stats_inc ("http_access_policy_new_in_scope", &s_http_access_policy_new_in_scope_stats);
#endif

*self_p = http_access_policy_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_access_policy_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_access_policy_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY)   || defined (BASE_ANIMATE_HTTP_ACCESS_POLICY_NEW_IN_SCOPE))
    if (http_access_policy_animating)
        icl_console_print ("<http_access_policy_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SELFTEST)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_FACTORY)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNBIND)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ANNOUNCE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_OPEN)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_BEFORE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_AFTER)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE_SHIM)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CLOSE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_LINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY__HTTP_ACCESS_MODULE_UNLINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_UNLINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_FREE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_SHOW)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_ALLOC)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_LINK)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_POLICY_NEW_IN_SCOPE) )
void
http_access_policy_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "announce"; break;
        case 2: method_name = "before"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "new"; break;
        case 5: method_name = "destroy"; break;
        case 6: method_name = "initialise"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "_http_access_module new"; break;
        case 9: method_name = "_http_access_module factory"; break;
        case 10: method_name = "_http_access_module unbind shim"; break;
        case 11: method_name = "_http_access_module unbind"; break;
        case 12: method_name = "announce shim"; break;
        case 13: method_name = "open shim"; break;
        case 14: method_name = "open"; break;
        case 15: method_name = "before shim"; break;
        case 16: method_name = "after shim"; break;
        case 17: method_name = "after"; break;
        case 18: method_name = "close shim"; break;
        case 19: method_name = "close"; break;
        case 20: method_name = "_http_access_module link"; break;
        case 21: method_name = "_http_access_module unlink"; break;
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
                                   "http_access_policy %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Traces a policy execution step, if the config asks for it
static void
s_trace (http_access_context_t *context, char *format, ...)
{
    icl_shortstr_t
        log_line;
    va_list
        va;
    va_start (va, format);
    if (http_config_policy_trace (http_config)) {
        apr_vsnprintf (log_line, ICL_SHORTSTR_MAX, format, va);
        smt_log_print (context->debug_log, log_line);
    }
    va_end (va);
}

//  Executes a policy, returns TRUE if decision was taken, else FALSE.
//  If the policy decided to deny, prepares the response object.
//
static Bool
s_execute_policy (http_access_context_t *context, ipr_config_t *config)
{
    Bool
        decision = FALSE;
    char
        *item_name = ipr_config_item (config);

    if (streq (item_name, "policy")) {
        char
            *uri = ipr_config_get (config, "uri", NULL);
        //  Check if policy uri matches request uri
        if (uri == NULL || ipr_str_prefixed (context->request->path, uri)) {
            ipr_config_locate (config, "+", NULL);
            if (config->located) {
                while (config->located && !decision) {
                    decision = s_execute_rule (context, config);
                    ipr_config_next (config);
                }
                ipr_config_locate (config, "..", NULL);
            }
        }
        else
            s_trace (context, "P: policy uri '%s' does not match - skipping", uri);
    }
    else {
        icl_console_print ("E: invalid access config, '%s' not expected (abort)",
            ipr_config_item (config));
        exit (EXIT_FAILURE);
    }
    //  Rules can return 0 or -1 (skip), neither are a policy decision
    return (decision == 1);
}

//  Executes a rule within the policy.
//  Returns 1 if decision was taken, 0 if not, -1 to skip rest of policy.
//  If the rule decided to deny, prepares the response object.
//
//    blacklist - check if the IP address of the client application is blacklisted
//    from value = "pattern" - check the IP address of the client application
//    header name = "name" value = "pattern" - check the value of a specific request header
//    local - check if the referrer is the current host
//    detect value = "string" comment = "text" - check if the request contains string
//    group value = "pattern" - check if the user is authenticated and in some group
//    always - always execute the actions
//    default - executes the actions for any matching rule that has //no// actions

static int
s_execute_rule (http_access_context_t *context, ipr_config_t *config)
{
    int
        decision = 0;
    char
        *rule = ipr_config_item (config);

    s_trace (context, "P: executing rule '%s'", rule);
    if (streq (rule, "blacklist")) {
        ipr_dict_t
            *entry;
        entry = ipr_dict_table_search (context->blacklist, context->request->address);
        if (entry) {
            s_trace (context, "P: rule match: address '%s' found in blacklist", context->request->address);
            decision = s_execute_actions (context, config);
        }
    }
    else
    if (streq (rule, "from")) {
        char
            *value = ipr_config_get (config, "value", NULL);
        if (value
        && (ipr_str_matches (context->request->address, value)
        ||  ipr_net_cidr_eq (context->request->address, value))) {
            s_trace (context, "P: rule match: address '%s' matches '%s'", context->request->address, value);
            decision = s_execute_actions (context, config);
        }
    }
    else
    if (streq (rule, "header")) {
        char
            *name = ipr_config_get (config, "name", NULL),
            *value = ipr_config_get (config, "value", NULL);
        if (name && value
        && ipr_str_lex_matches (http_request_get_header (context->request, name), value)) {
            s_trace (context, "P: rule match: header '%s=%s' matches '%s'",
                name, http_request_get_header (context->request, name), value);
            decision = s_execute_actions (context, config);
        }
    }
    else
    if (streq (rule, "local")) {
        char
            *referer = http_request_get_header (context->request, "referer");
        if (strnull (referer) || streq (referer, context->response->root_uri)) {
            s_trace (context, "P: rule match: referrer '%s' considered local", referer);
            decision = s_execute_actions (context, config);
        }
    }
    else
    if (streq (rule, "detect")) {
        char
            *limit = ipr_config_get (config, "limit", NULL),
            *value = ipr_config_get (config, "value", NULL);
        if (value
        &&  ipr_str_find (context->request->request_line, value)) {
            s_trace (context, "P: rule match: request contains '%s'", value);
            apr_env_set ("comment", ipr_config_get (config, "comment", ""), icl_global_pool);
            decision = s_execute_actions (context, config);
        }
        if (!decision
        &&  limit
        &&  strlen (context->request->request_line) > (uint) atoi (limit)) {
            s_trace (context, "P: rule match: request exceeds %d chars", atoi (limit));
            apr_env_set ("comment", ipr_config_get (config, "comment", ""), icl_global_pool);
            decision = s_execute_actions (context, config);
        }
    }
    else
    if (streq (rule, "group")) {
        char
            *value = ipr_config_get (config, "value", NULL);
        if (value && context->auth_group
        &&  ipr_str_lex_matches (context->auth_group, value)) {
            s_trace (context, "P: rule match: user is in group '%s'", value);
            decision = s_execute_actions (context, config);
        }
    }
    else
    if (streq (rule, "always")) {
        s_trace (context, "P: rule match: always");
            decision = s_execute_actions (context, config);
    }
    else
    if (streq (rule, "default"))
        ;                               //  Do nothing
    else {
        icl_console_print ("E: invalid policy rule: '%s' (abort)", rule);
        exit (EXIT_FAILURE);
    }
    return (decision);
}

//  Executes action list for current rule
//  Returns 1 if decision was taken, 0 if not, -1 to skip rest of policy.
//  If the action decided to deny, prepares the response object.
//    deny [ code = "reply-code" [ text = "reply-text" ] ]
//    allow
//    authenticate mechanism = "basic|digest" [ realm = "realmname" ]
//    redirect uri = "uri"
//    ban
//    skip
//    echo Message text

static int
s_execute_actions (http_access_context_t *context, ipr_config_t *config)
{
    int
        decision = 0;
    char
        *action;

    //  Push local copy of config state
    config = ipr_config_dup (config);

    //  Look for first action, if none then look in default rule
    ipr_config_locate (config, "+", NULL);
    if (!config->located) {
        ipr_config_locate (config, "../default", NULL);
        ipr_config_locate (config, "+", NULL);
    }
    while (config->located && !decision) {
        action = ipr_config_item (config);
        s_trace (context, "P: execute action '%s'", action);

        if (streq (action, "deny")) {
            http_response_set_error (context->response,
                atoi (ipr_config_get (config, "code", "503")),
                ipr_config_get (config, "text", "Access denied"));
            decision = 1;
        }
        else
        if (streq (action, "allow"))
            decision = 1;
        else
        if (streq (action, "authenticate"))
            decision = s_execute_authenticate (context, config);
        else
        if (streq (action, "redirect")) {
            http_response_set_redirect (context->response, ipr_config_get (config, "uri", "/"));
            decision = 1;
        }
        else
        if (streq (action, "ban")) {
            http_server_ban_address (context->response->server, context->request->address);
            http_response_set_error (context->response,
                atoi (ipr_config_get (config, "code", "503")),
                ipr_config_get (config, "text", "Access denied"));
            decision = 1;
        }
        else
        if (streq (action, "skip"))
            decision = -1;
        else
        if (streq (action, "echo")) {
            char
                *formatted = http_access_context_format (context, ipr_config_value (config));
            smt_log_print (context->alert_log, "%s", formatted);
            icl_mem_free (formatted);
        }
        else {
            icl_console_print ("E: invalid rule action: '%s' (abort)", action);
            exit (EXIT_FAILURE);
        }
        ipr_config_next (config);
    }
    ipr_config_destroy (&config);
    return (decision);
}

//  All the heavy work is done by ipr_password_table, which implements the
//  Basic and Digest authentication mechanisms.

static int
s_execute_authenticate (http_access_context_t *context, ipr_config_t *config)
{
    int
        decision = 0;
    char
        *mechanism,
        *realm;
    char
        *credentials,           //  Authorization header
        *challenge;             //  Response from authentication

    mechanism = ipr_config_get (config, "mechanism", "basic"),
    realm = ipr_config_get (config, "realm", context->response->hostname);
    credentials = http_request_get_header (context->request, "authorization");
    if (streq (mechanism, "basic")) {
        if (http_config_policy_trace (http_config))
            ipr_password_table_set_debug (context->basic, TRUE);
        challenge = ipr_password_table_basic (
            context->basic,
            context->request->address,
            realm,
            credentials);
        if (context->basic->result == IPR_PASSWORD_OK) {
            http_access_context_set_auth (context, context->basic, "users");
            s_trace (context, "P: successful Basic authentication for '%s'",
                context->auth_user);
        }
        else
            http_access_context_set_fail (context, context->basic);
    }
    else
    if (streq (mechanism, "digest")) {
        if (http_config_policy_trace (http_config)) {
            ipr_password_table_set_debug (context->digest, TRUE);
            //  If we're debugging, use the RFC2617 example nonce
            ipr_password_table_set_nonce_test (context->digest, "dcd98b7102dd2f0e8b11d0f600bfb0c093");
        }
        context->digest_auth = TRUE;
        challenge = ipr_password_table_digest (
            context->digest,
            context->request->address,
            realm,
            credentials,
            context->request->request_method,
            context->request->path);
        if (context->digest->result == IPR_PASSWORD_OK) {
            http_access_context_set_auth (context, context->digest, "users");
            s_trace (context, "P: successful Digest authentication for '%s'",
                context->auth_user);
        }
        else
            http_access_context_set_fail (context, context->digest);
    }
    else {
        icl_console_print ("E: invalid authentication mechanism: '%s' (abort)", mechanism);
        exit (EXIT_FAILURE);
    }
    if (challenge) {
        http_response_set_header (context->response, "www-authenticate", challenge);
        http_response_set_error  (context->response, HTTP_REPLY_UNAUTHORIZED,
            "Authenticate yourself to access this resource");
        icl_mem_strfree (&challenge);
        decision = 1;                       //  Deny access
    }
    return (decision);
}

//  Embed the version information in the resulting binary                      

char *http_access_policy_version_start  = "VeRsIoNsTaRt:ipc";
char *http_access_policy_component  = "http_access_policy ";
char *http_access_policy_version   = "0.0 ";
char *http_access_policy_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_access_policy_filename  = "http_access_policy.icl ";
char *http_access_policy_builddate  = "2009/02/19 ";
char *http_access_policy_version_end  = "VeRsIoNeNd:ipc";

