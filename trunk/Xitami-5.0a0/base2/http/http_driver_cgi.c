/*---------------------------------------------------------------------------
    http_driver_cgi.c - http_driver_cgi component

    This class implements a driver module to handle CGI POSTs.
    NB: this is a stub implementation, not complete and not usable.
    Generated from http_driver_cgi.icl by smt_object_gen using GSL/4.
    
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
#include "http_driver_cgi.h"            //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_driver_cgi_t

//  Shorthands for class methods                                               

#define self_announce       http_driver_cgi_announce
#define self_annihilate     http_driver_cgi_annihilate
#define self_get            http_driver_cgi_get
#define self_head           http_driver_cgi_head
#define self_post           http_driver_cgi_post
#define self_put            http_driver_cgi_put
#define self_delete         http_driver_cgi_delete
#define self_move           http_driver_cgi_move
#define self_copy           http_driver_cgi_copy
#define self_new            http_driver_cgi_new
#define self_initialise     http_driver_cgi_initialise
#define self_terminate      http_driver_cgi_terminate
#define self__http_driver_module_new  http_driver_cgi__http_driver_module_new
#define self__http_driver_module_factory  http_driver_cgi__http_driver_module_factory
#define self__http_driver_module_unbind_shim  http_driver_cgi__http_driver_module_unbind_shim
#define self__http_driver_module_unbind  http_driver_cgi__http_driver_module_unbind
#define self_announce_shim  http_driver_cgi_announce_shim
#define self_get_shim       http_driver_cgi_get_shim
#define self_head_shim      http_driver_cgi_head_shim
#define self_post_shim      http_driver_cgi_post_shim
#define self_put_shim       http_driver_cgi_put_shim
#define self_delete_shim    http_driver_cgi_delete_shim
#define self_move_shim      http_driver_cgi_move_shim
#define self_copy_shim      http_driver_cgi_copy_shim
#define self__http_driver_module_link  http_driver_cgi__http_driver_module_link
#define self__http_driver_module_unlink  http_driver_cgi__http_driver_module_unlink
#define self_selftest       http_driver_cgi_selftest
#define self_destroy        http_driver_cgi_destroy
#define self_unlink         http_driver_cgi_unlink
#define self_show_animation  http_driver_cgi_show_animation
#define self_free           http_driver_cgi_free
#define self_show           http_driver_cgi_show
#define self_alloc          http_driver_cgi_alloc
#define self_link           http_driver_cgi_link
#define self_cache_initialise  http_driver_cgi_cache_initialise
#define self_cache_purge    http_driver_cgi_cache_purge
#define self_cache_terminate  http_driver_cgi_cache_terminate
#define self_new_in_scope   http_driver_cgi_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_ANNOUNCE))
static icl_stats_t *s_http_driver_cgi_announce_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DESTROY))
static icl_stats_t *s_http_driver_cgi_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_GET))
static icl_stats_t *s_http_driver_cgi_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_HEAD))
static icl_stats_t *s_http_driver_cgi_head_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_POST))
static icl_stats_t *s_http_driver_cgi_post_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_PUT))
static icl_stats_t *s_http_driver_cgi_put_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DELETE))
static icl_stats_t *s_http_driver_cgi_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_MOVE))
static icl_stats_t *s_http_driver_cgi_move_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_COPY))
static icl_stats_t *s_http_driver_cgi_copy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_NEW))
static icl_stats_t *s_http_driver_cgi_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_INITIALISE))
static icl_stats_t *s_http_driver_cgi_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_TERMINATE))
static icl_stats_t *s_http_driver_cgi_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW))
static icl_stats_t *s_http_driver_cgi__http_driver_module_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY))
static icl_stats_t *s_http_driver_cgi__http_driver_module_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM))
static icl_stats_t *s_http_driver_cgi__http_driver_module_unbind_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND))
static icl_stats_t *s_http_driver_cgi__http_driver_module_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_ANNOUNCE_SHIM))
static icl_stats_t *s_http_driver_cgi_announce_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_GET_SHIM))
static icl_stats_t *s_http_driver_cgi_get_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_HEAD_SHIM))
static icl_stats_t *s_http_driver_cgi_head_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_POST_SHIM))
static icl_stats_t *s_http_driver_cgi_post_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_PUT_SHIM))
static icl_stats_t *s_http_driver_cgi_put_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DELETE_SHIM))
static icl_stats_t *s_http_driver_cgi_delete_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_MOVE_SHIM))
static icl_stats_t *s_http_driver_cgi_move_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_COPY_SHIM))
static icl_stats_t *s_http_driver_cgi_copy_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK))
static icl_stats_t *s_http_driver_cgi__http_driver_module_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK))
static icl_stats_t *s_http_driver_cgi__http_driver_module_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_SELFTEST))
static icl_stats_t *s_http_driver_cgi_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DESTROY_PUBLIC))
static icl_stats_t *s_http_driver_cgi_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_UNLINK))
static icl_stats_t *s_http_driver_cgi_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_SHOW_ANIMATION))
static icl_stats_t *s_http_driver_cgi_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_FREE))
static icl_stats_t *s_http_driver_cgi_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_SHOW))
static icl_stats_t *s_http_driver_cgi_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_ALLOC))
static icl_stats_t *s_http_driver_cgi_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_LINK))
static icl_stats_t *s_http_driver_cgi_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_CACHE_INITIALISE))
static icl_stats_t *s_http_driver_cgi_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_CACHE_PURGE))
static icl_stats_t *s_http_driver_cgi_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_CACHE_TERMINATE))
static icl_stats_t *s_http_driver_cgi_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_NEW_IN_SCOPE))
static icl_stats_t *s_http_driver_cgi_new_in_scope_stats = NULL;
#endif
#define http_driver_cgi_annihilate(self)  http_driver_cgi_annihilate_ (self, __FILE__, __LINE__)
static int
    http_driver_cgi_annihilate_ (
http_driver_cgi_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    http_driver_cgi_initialise (
void);

static void
    http_driver_cgi__http_driver_module_unbind_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal           //  Portal reference
);

static int
    http_driver_cgi_announce_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
smt_log_t * log                         //  Not documented
);

static int
    http_driver_cgi_get_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    http_driver_cgi_head_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    http_driver_cgi_post_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    http_driver_cgi_put_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    http_driver_cgi_delete_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    http_driver_cgi_move_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static int
    http_driver_cgi_copy_shim (
void * self_v,                          //  Self as void pointer
http_driver_module_t * portal,          //  Portal back to server
http_driver_context_t * context         //  Not documented
);

static void *
    http_driver_cgi__http_driver_module_link (
void * object                           //  Reference cast as a void *
);

static void
    http_driver_cgi__http_driver_module_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define http_driver_cgi_alloc()         http_driver_cgi_alloc_ (__FILE__, __LINE__)
static http_driver_cgi_t *
    http_driver_cgi_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    http_driver_cgi_cache_initialise (
void);

static void
    http_driver_cgi_cache_purge (
void);

static void
    http_driver_cgi_cache_terminate (
void);

Bool
    http_driver_cgi_animating = TRUE;   //  Animation enabled by default
static Bool
    s_http_driver_cgi_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_http_driver_cgi_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_http_driver_module_list;         //  List of portal factories
static Bool
    s_http_driver_module_stopped;       //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    http_driver_cgi_announce

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the announce incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_announce (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_ANNOUNCE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_announce_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ANNOUNCE))
    icl_trace_record (NULL, http_driver_cgi_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_ANNOUNCE))
    icl_stats_inc ("http_driver_cgi_announce", &s_http_driver_cgi_announce_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

    smt_log_print (log, "I: X5 CGI driver loaded at '%s'", portal->path);

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_announce (self->thread,portal,log)) {
        //icl_console_print ("Error sending 'announce' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ANNOUNCE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_ANNOUNCE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_announce_finish"
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
    http_driver_cgi_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_annihilate_ (
    http_driver_cgi_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    int
        history_last;
#endif

    http_driver_cgi_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DESTROY))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DESTROY))
    icl_trace_record (NULL, http_driver_cgi_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DESTROY))
    icl_stats_inc ("http_driver_cgi_annihilate", &s_http_driver_cgi_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = file;
    self->history_line  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = line;
    self->history_type  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DESTROY))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DESTROY))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_destroy_finish"
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
    http_driver_cgi_get

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the get incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_get (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_GET))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_get_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_GET))
    icl_trace_record (NULL, http_driver_cgi_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_GET))
    icl_stats_inc ("http_driver_cgi_get", &s_http_driver_cgi_get_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_get (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'get' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_GET))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_GET))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_get_finish"
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
    http_driver_cgi_head

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the head incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_head (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_HEAD))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_head_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_HEAD))
    icl_trace_record (NULL, http_driver_cgi_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_HEAD))
    icl_stats_inc ("http_driver_cgi_head", &s_http_driver_cgi_head_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_head (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'head' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_HEAD))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_HEAD))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_head_finish"
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
    http_driver_cgi_post

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the post incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_post (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_POST))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_post_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_POST))
    icl_trace_record (NULL, http_driver_cgi_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_POST))
    icl_stats_inc ("http_driver_cgi_post", &s_http_driver_cgi_post_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_post (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'post' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_POST))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_POST))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_post_finish"
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
    http_driver_cgi_put

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the put incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_put (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_PUT))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_put_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_PUT))
    icl_trace_record (NULL, http_driver_cgi_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_PUT))
    icl_stats_inc ("http_driver_cgi_put", &s_http_driver_cgi_put_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_put (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'put' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_PUT))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_PUT))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_put_finish"
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
    http_driver_cgi_delete

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the delete incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_delete (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DELETE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_delete_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DELETE))
    icl_trace_record (NULL, http_driver_cgi_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DELETE))
    icl_stats_inc ("http_driver_cgi_delete", &s_http_driver_cgi_delete_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_delete (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'delete' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DELETE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DELETE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_delete_finish"
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
    http_driver_cgi_move

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the move incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_move (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_MOVE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_move_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_MOVE))
    icl_trace_record (NULL, http_driver_cgi_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_MOVE))
    icl_stats_inc ("http_driver_cgi_move", &s_http_driver_cgi_move_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_move (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'move' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_MOVE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_MOVE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_move_finish"
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
    http_driver_cgi_copy

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    This is the copy incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_copy (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal,      //  Portal back to client
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_COPY))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_copy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_COPY))
    icl_trace_record (NULL, http_driver_cgi_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_COPY))
    icl_stats_inc ("http_driver_cgi_copy", &s_http_driver_cgi_copy_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent_copy (self->thread,portal,context)) {
        //icl_console_print ("Error sending 'copy' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_COPY))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_COPY))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_copy_finish"
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
    http_driver_cgi_new

    Type: Component method
    Creates and initialises a new http_driver_cgi_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

http_driver_cgi_t *
    http_driver_cgi_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    http_driver_cgi_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_NEW))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_NEW))
    icl_trace_record (NULL, http_driver_cgi_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_NEW))
    icl_stats_inc ("http_driver_cgi_new", &s_http_driver_cgi_new_stats);
#endif

if (!s_http_driver_cgi_active)
    self_initialise ();
    self = http_driver_cgi_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_DRIVER_CGI_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, http_driver_cgi_show_);
#endif

self->thread = http_driver_cgi_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->http_driver_module_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_NEW))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_NEW))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_new_finish"
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
    http_driver_cgi_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_cgi_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_INITIALISE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_INITIALISE))
    icl_trace_record (NULL, http_driver_cgi_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_INITIALISE))
    icl_stats_inc ("http_driver_cgi_initialise", &s_http_driver_cgi_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_http_driver_cgi_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_http_driver_cgi_mutex)
            s_http_driver_cgi_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_http_driver_cgi_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_http_driver_cgi_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

http_driver_cgi_agent_init ();

s_http_driver_module_list = ipr_looseref_list_new ();
            s_http_driver_cgi_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_http_driver_cgi_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_INITIALISE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_INITIALISE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_initialise_finish"
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
    http_driver_cgi_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_terminate (
void)
{
http_driver_module_t
    *http_driver_module;            //  Portal factory object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_TERMINATE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_TERMINATE))
    icl_trace_record (NULL, http_driver_cgi_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_TERMINATE))
    icl_stats_inc ("http_driver_cgi_terminate", &s_http_driver_cgi_terminate_stats);
#endif

if (s_http_driver_cgi_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_http_driver_module_stopped, TRUE, FALSE) == FALSE) {
    while ((http_driver_module = (http_driver_module_t *) ipr_looseref_pop (s_http_driver_module_list))) {
        http_driver_module->server_looseref = NULL;
        http_driver_module_destroy (&http_driver_module);
    }
}
ipr_looseref_list_destroy (&s_http_driver_module_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_http_driver_cgi_mutex);
#endif
        s_http_driver_cgi_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_TERMINATE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_TERMINATE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_terminate_finish"
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
    http_driver_cgi__http_driver_module_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    http_driver_cgi__http_driver_module_new (
    void * self_v,                      //  Untyped server reference
    char * path                         //  Not documented
)
{
http_driver_cgi_t
    *self;
    http_driver_module_t *
        http_driver_module;             //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW))
    icl_trace_record (NULL, http_driver_cgi_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW))
    icl_stats_inc ("http_driver_cgi__http_driver_module_new", &s_http_driver_cgi__http_driver_module_new_stats);
#endif

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((http_driver_cgi_t *) self_v);
else
    self = self_new ();

http_driver_module = http_driver_module_new (self, self__http_driver_module_link, self__http_driver_module_unlink, path);
http_driver_module->server_looseref = ipr_looseref_queue (
    self->http_driver_module_list, http_driver_module_link (http_driver_module));

//  Build virtual methods for server-side methods
http_driver_module->server_unbind = self__http_driver_module_unbind_shim;
http_driver_module->request_announce = self_announce_shim;
http_driver_module->request_get = self_get_shim;
http_driver_module->request_head = self_head_shim;
http_driver_module->request_post = self_post_shim;
http_driver_module->request_put = self_put_shim;
http_driver_module->request_delete = self_delete_shim;
http_driver_module->request_move = self_move_shim;
http_driver_module->request_copy = self_copy_shim;

//  Drop link to server object
self_unlink (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" path=\"%s\""
" http_driver_module=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, path, http_driver_module);
#endif


    return (http_driver_module);
}
/*  -------------------------------------------------------------------------
    http_driver_cgi__http_driver_module_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

http_driver_module_t *
    http_driver_cgi__http_driver_module_factory (
    char * path                         //  Not documented
)
{
    http_driver_module_t *
        http_driver_module;             //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_factory_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY))
    icl_trace_record (NULL, http_driver_cgi_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY))
    icl_stats_inc ("http_driver_cgi__http_driver_module_factory", &s_http_driver_cgi__http_driver_module_factory_stats);
#endif

//
if (!s_http_driver_cgi_active)
    self_initialise ();             //  Since we don't call http_driver_cgi_new
http_driver_module = http_driver_module_new (NULL, self__http_driver_module_link, self__http_driver_module_unlink, path);
http_driver_module->server_looseref = ipr_looseref_queue (
    s_http_driver_module_list, http_driver_module_link (http_driver_module));

//  Build virtual methods for server-side methods
http_driver_module->server_new = self__http_driver_module_new;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_factory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path=\"%s\""
" http_driver_module=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path, http_driver_module);
#endif


    return (http_driver_module);
}
/*  -------------------------------------------------------------------------
    http_driver_cgi__http_driver_module_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_cgi__http_driver_module_unbind_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal       //  Portal reference
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_unbind_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM))
    icl_stats_inc ("http_driver_cgi__http_driver_module_unbind_shim", &s_http_driver_cgi__http_driver_module_unbind_shim_stats);
#endif

self__http_driver_module_unbind ((http_driver_cgi_t *) self_v, portal);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_unbind_shim_finish"
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
    http_driver_cgi__http_driver_module_unbind

    Type: Component method
    Accepts a http_driver_cgi_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi__http_driver_module_unbind (
    http_driver_cgi_t * self,           //  Reference to object
    http_driver_module_t * portal       //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_unbind_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND))
    icl_trace_record (NULL, http_driver_cgi_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND))
    icl_stats_inc ("http_driver_cgi__http_driver_module_unbind", &s_http_driver_cgi__http_driver_module_unbind_stats);
#endif

HTTP_DRIVER_CGI_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (http_driver_cgi_agent__http_driver_module_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_http_driver_module unbind' method to http_driver_cgi agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_unbind_finish"
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
    http_driver_cgi_announce_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_announce_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_ANNOUNCE_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_announce_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ANNOUNCE_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_ANNOUNCE_SHIM))
    icl_stats_inc ("http_driver_cgi_announce_shim", &s_http_driver_cgi_announce_shim_stats);
#endif

rc = self_announce ((http_driver_cgi_t *) self_v, portal, log);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ANNOUNCE_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_ANNOUNCE_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_announce_shim_finish"
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
    http_driver_cgi_get_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_get_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_GET_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_get_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_GET_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_GET_SHIM))
    icl_stats_inc ("http_driver_cgi_get_shim", &s_http_driver_cgi_get_shim_stats);
#endif

rc = self_get ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_GET_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_GET_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_get_shim_finish"
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
    http_driver_cgi_head_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_head_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_HEAD_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_head_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_HEAD_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_HEAD_SHIM))
    icl_stats_inc ("http_driver_cgi_head_shim", &s_http_driver_cgi_head_shim_stats);
#endif

rc = self_head ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_HEAD_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_HEAD_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_head_shim_finish"
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
    http_driver_cgi_post_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_post_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_POST_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_post_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_POST_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_POST_SHIM))
    icl_stats_inc ("http_driver_cgi_post_shim", &s_http_driver_cgi_post_shim_stats);
#endif

rc = self_post ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_POST_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_POST_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_post_shim_finish"
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
    http_driver_cgi_put_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_put_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_PUT_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_put_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_PUT_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_PUT_SHIM))
    icl_stats_inc ("http_driver_cgi_put_shim", &s_http_driver_cgi_put_shim_stats);
#endif

rc = self_put ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_PUT_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_PUT_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_put_shim_finish"
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
    http_driver_cgi_delete_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_delete_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DELETE_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_delete_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DELETE_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DELETE_SHIM))
    icl_stats_inc ("http_driver_cgi_delete_shim", &s_http_driver_cgi_delete_shim_stats);
#endif

rc = self_delete ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DELETE_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DELETE_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_delete_shim_finish"
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
    http_driver_cgi_move_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_move_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_MOVE_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_move_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_MOVE_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_MOVE_SHIM))
    icl_stats_inc ("http_driver_cgi_move_shim", &s_http_driver_cgi_move_shim_stats);
#endif

rc = self_move ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_MOVE_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_MOVE_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_move_shim_finish"
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
    http_driver_cgi_copy_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    http_driver_cgi_copy_shim (
    void * self_v,                      //  Self as void pointer
    http_driver_module_t * portal,      //  Portal back to server
    http_driver_context_t * context     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_COPY_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_copy_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_COPY_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_COPY_SHIM))
    icl_stats_inc ("http_driver_cgi_copy_shim", &s_http_driver_cgi_copy_shim_stats);
#endif

rc = self_copy ((http_driver_cgi_t *) self_v, portal, context);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_COPY_SHIM))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_COPY_SHIM))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_copy_shim_finish"
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
    http_driver_cgi__http_driver_module_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    http_driver_cgi__http_driver_module_link (
    void * object                       //  Reference cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK))
    icl_stats_inc ("http_driver_cgi__http_driver_module_link", &s_http_driver_cgi__http_driver_module_link_stats);
#endif

//
object = (void *) http_driver_cgi_link (((http_driver_cgi_t *) object));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_link_finish"
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
    http_driver_cgi__http_driver_module_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_cgi__http_driver_module_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK))
    icl_stats_inc ("http_driver_cgi__http_driver_module_unlink", &s_http_driver_cgi__http_driver_module_unlink_stats);
#endif

//
http_driver_cgi_unlink (((http_driver_cgi_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi__http_driver_module_unlink_finish"
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
    http_driver_cgi_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_SELFTEST))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SELFTEST))
    icl_trace_record (NULL, http_driver_cgi_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_SELFTEST))
    icl_stats_inc ("http_driver_cgi_selftest", &s_http_driver_cgi_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SELFTEST))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_SELFTEST))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_selftest_finish"
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
    http_driver_cgi_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_driver_cgi_destroy_ (
    http_driver_cgi_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_driver_cgi_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DESTROY_PUBLIC))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_driver_cgi_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_DESTROY_PUBLIC))
    icl_stats_inc ("http_driver_cgi_destroy", &s_http_driver_cgi_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = http_driver_cgi_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        http_driver_cgi_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_DESTROY_PUBLIC))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_destroy_public_finish"
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
    http_driver_cgi_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_unlink_ (
    http_driver_cgi_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    int
        history_last;
#endif
    http_driver_cgi_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_UNLINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_UNLINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_UNLINK))
    icl_stats_inc ("http_driver_cgi_unlink", &s_http_driver_cgi_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on http_driver_cgi object");
            http_driver_cgi_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                http_driver_cgi_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                http_driver_cgi_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_UNLINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_UNLINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_unlink_finish"
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
    http_driver_cgi_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_SHOW_ANIMATION))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SHOW_ANIMATION))
    icl_trace_record (NULL, http_driver_cgi_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_SHOW_ANIMATION))
    icl_stats_inc ("http_driver_cgi_show_animation", &s_http_driver_cgi_show_animation_stats);
#endif

http_driver_cgi_animating = enabled;

http_driver_cgi_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SHOW_ANIMATION))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_SHOW_ANIMATION))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_show_animation_finish"
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
    http_driver_cgi_free

    Type: Component method
    Freess a http_driver_cgi_t object.
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_free_ (
    http_driver_cgi_t * self,           //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_FREE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_FREE))
    icl_trace_record (NULL, http_driver_cgi_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_FREE))
    icl_stats_inc ("http_driver_cgi_free", &s_http_driver_cgi_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = "free";
        self->history_links [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (http_driver_cgi_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_driver_cgi_t));
        self->object_tag = HTTP_DRIVER_CGI_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_FREE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_FREE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_free_finish"
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
    http_driver_cgi_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_driver_cgi_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_SHOW))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SHOW))
    icl_trace_record (NULL, http_driver_cgi_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_SHOW))
    icl_stats_inc ("http_driver_cgi_show", &s_http_driver_cgi_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <http_driver_cgi zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    if (self->history_last > HTTP_DRIVER_CGI_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % HTTP_DRIVER_CGI_HISTORY_LENGTH;
        self->history_last %= HTTP_DRIVER_CGI_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % HTTP_DRIVER_CGI_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </http_driver_cgi>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SHOW))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_SHOW))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_show_finish"
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
    http_driver_cgi_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_driver_cgi_t *
    http_driver_cgi_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_driver_cgi_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_ALLOC))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ALLOC))
    icl_trace_record (NULL, http_driver_cgi_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_ALLOC))
    icl_stats_inc ("http_driver_cgi_alloc", &s_http_driver_cgi_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_driver_cgi_cache_initialise ();

self = (http_driver_cgi_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_driver_cgi_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ALLOC))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_ALLOC))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_alloc_finish"
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
    http_driver_cgi_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

http_driver_cgi_t *
    http_driver_cgi_link_ (
    http_driver_cgi_t * self,           //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_LINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_LINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_LINK))
    icl_stats_inc ("http_driver_cgi_link", &s_http_driver_cgi_link_stats);
#endif

    if (self) {
        HTTP_DRIVER_CGI_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_CGI)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = "link";
        self->history_links [history_last % HTTP_DRIVER_CGI_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_LINK))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_LINK))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_link_finish"
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
    http_driver_cgi_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_driver_cgi_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_CACHE_INITIALISE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_INITIALISE))
    icl_trace_record (NULL, http_driver_cgi_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_CACHE_INITIALISE))
    icl_stats_inc ("http_driver_cgi_cache_initialise", &s_http_driver_cgi_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_driver_cgi_t));
icl_system_register (http_driver_cgi_cache_purge, http_driver_cgi_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_INITIALISE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_CACHE_INITIALISE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_cache_initialise_finish"
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
    http_driver_cgi_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_cgi_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_CACHE_PURGE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_PURGE))
    icl_trace_record (NULL, http_driver_cgi_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_CACHE_PURGE))
    icl_stats_inc ("http_driver_cgi_cache_purge", &s_http_driver_cgi_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_PURGE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_CACHE_PURGE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_cache_purge_finish"
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
    http_driver_cgi_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_driver_cgi_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_CACHE_TERMINATE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_TERMINATE))
    icl_trace_record (NULL, http_driver_cgi_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_CACHE_TERMINATE))
    icl_stats_inc ("http_driver_cgi_cache_terminate", &s_http_driver_cgi_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_TERMINATE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_CACHE_TERMINATE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_cache_terminate_finish"
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
    http_driver_cgi_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_driver_cgi_new_in_scope_ (
    http_driver_cgi_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI)  ||  defined (BASE_ANIMATE_HTTP_DRIVER_CGI_NEW_IN_SCOPE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_driver_cgi_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI)  ||  defined (BASE_STATS_HTTP_DRIVER_CGI_NEW_IN_SCOPE))
    icl_stats_inc ("http_driver_cgi_new_in_scope", &s_http_driver_cgi_new_in_scope_stats);
#endif

*self_p = http_driver_cgi_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_driver_cgi_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_driver_cgi_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI)   || defined (BASE_ANIMATE_HTTP_DRIVER_CGI_NEW_IN_SCOPE))
    if (http_driver_cgi_animating)
        icl_console_print ("<http_driver_cgi_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ANNOUNCE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DESTROY)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_GET)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_HEAD)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_POST)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_PUT)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DELETE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_MOVE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_COPY)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_NEW)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_INITIALISE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_TERMINATE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_NEW)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_FACTORY)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNBIND)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ANNOUNCE_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_GET_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_HEAD_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_POST_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_PUT_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DELETE_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_MOVE_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_COPY_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_LINK)   || defined (BASE_TRACE_HTTP_DRIVER_CGI__HTTP_DRIVER_MODULE_UNLINK)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SELFTEST)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_UNLINK)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_FREE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_SHOW)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_ALLOC)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_LINK)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_DRIVER_CGI_NEW_IN_SCOPE) )
void
http_driver_cgi_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "announce"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "get"; break;
        case 4: method_name = "head"; break;
        case 5: method_name = "post"; break;
        case 6: method_name = "put"; break;
        case 7: method_name = "delete"; break;
        case 8: method_name = "move"; break;
        case 9: method_name = "copy"; break;
        case 10: method_name = "new"; break;
        case 11: method_name = "initialise"; break;
        case 12: method_name = "terminate"; break;
        case 13: method_name = "_http_driver_module new"; break;
        case 14: method_name = "_http_driver_module factory"; break;
        case 15: method_name = "_http_driver_module unbind shim"; break;
        case 16: method_name = "_http_driver_module unbind"; break;
        case 17: method_name = "announce shim"; break;
        case 18: method_name = "get shim"; break;
        case 19: method_name = "head shim"; break;
        case 20: method_name = "post shim"; break;
        case 21: method_name = "put shim"; break;
        case 22: method_name = "delete shim"; break;
        case 23: method_name = "move shim"; break;
        case 24: method_name = "copy shim"; break;
        case 25: method_name = "_http_driver_module link"; break;
        case 26: method_name = "_http_driver_module unlink"; break;
        case 27: method_name = "selftest"; break;
        case 28: method_name = "destroy public"; break;
        case 29: method_name = "unlink"; break;
        case 30: method_name = "show animation"; break;
        case 31: method_name = "free"; break;
        case 32: method_name = "show"; break;
        case 33: method_name = "alloc"; break;
        case 34: method_name = "link"; break;
        case 35: method_name = "cache initialise"; break;
        case 36: method_name = "cache purge"; break;
        case 37: method_name = "cache terminate"; break;
        case 38: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_driver_cgi %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *http_driver_cgi_version_start  = "VeRsIoNsTaRt:ipc";
char *http_driver_cgi_component    = "http_driver_cgi ";
char *http_driver_cgi_version      = "0.0 ";
char *http_driver_cgi_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_driver_cgi_filename     = "http_driver_cgi.icl ";
char *http_driver_cgi_builddate    = "2009/02/19 ";
char *http_driver_cgi_version_end  = "VeRsIoNeNd:ipc";

