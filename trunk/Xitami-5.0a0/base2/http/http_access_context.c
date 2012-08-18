/*---------------------------------------------------------------------------
    http_access_context.c - http_access_context component

    This class holds properties for access control.  These properties are
    provided to and modified by the various access modules.  The object is
    for local use by access modules.
    Generated from http_access_context.icl by icl_gen using GSL/4.
    
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
#include "http_access_context.h"        //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_access_context_t

//  Shorthands for class methods                                               

#define self_new            http_access_context_new
#define self_annihilate     http_access_context_annihilate
#define self_set_thread     http_access_context_set_thread
#define self_set_address    http_access_context_set_address
#define self_set_request    http_access_context_set_request
#define self_set_response   http_access_context_set_response
#define self_set_auth       http_access_context_set_auth
#define self_set_fail       http_access_context_set_fail
#define self_format         http_access_context_format
#define self_selftest       http_access_context_selftest
#define self_terminate      http_access_context_terminate
#define self_show           http_access_context_show
#define self_destroy        http_access_context_destroy
#define self_alloc          http_access_context_alloc
#define self_free           http_access_context_free
#define self_cache_initialise  http_access_context_cache_initialise
#define self_cache_purge    http_access_context_cache_purge
#define self_cache_terminate  http_access_context_cache_terminate
#define self_show_animation  http_access_context_show_animation
#define self_new_in_scope   http_access_context_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_NEW))
static icl_stats_t *s_http_access_context_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_DESTROY))
static icl_stats_t *s_http_access_context_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_THREAD))
static icl_stats_t *s_http_access_context_set_thread_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_ADDRESS))
static icl_stats_t *s_http_access_context_set_address_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_REQUEST))
static icl_stats_t *s_http_access_context_set_request_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_RESPONSE))
static icl_stats_t *s_http_access_context_set_response_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_AUTH))
static icl_stats_t *s_http_access_context_set_auth_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_FAIL))
static icl_stats_t *s_http_access_context_set_fail_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_FORMAT))
static icl_stats_t *s_http_access_context_format_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SELFTEST))
static icl_stats_t *s_http_access_context_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_TERMINATE))
static icl_stats_t *s_http_access_context_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SHOW))
static icl_stats_t *s_http_access_context_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC))
static icl_stats_t *s_http_access_context_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_ALLOC))
static icl_stats_t *s_http_access_context_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_FREE))
static icl_stats_t *s_http_access_context_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE))
static icl_stats_t *s_http_access_context_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_CACHE_PURGE))
static icl_stats_t *s_http_access_context_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE))
static icl_stats_t *s_http_access_context_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION))
static icl_stats_t *s_http_access_context_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE))
static icl_stats_t *s_http_access_context_new_in_scope_stats = NULL;
#endif
static void
    http_access_context_annihilate (
http_access_context_t * ( * self_p )    //  Reference to object reference
);

#define http_access_context_alloc()     http_access_context_alloc_ (__FILE__, __LINE__)
static http_access_context_t *
    http_access_context_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    http_access_context_free (
http_access_context_t * self            //  Object reference
);

static void
    http_access_context_cache_initialise (
void);

static void
    http_access_context_cache_purge (
void);

static void
    http_access_context_cache_terminate (
void);

Bool
    http_access_context_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    http_access_context_new

    Type: Component method
    Creates and initialises a new http_access_context_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

http_access_context_t *
    http_access_context_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    http_server_t * server              //  Not documented
)
{
    http_access_context_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_NEW))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_NEW))
    icl_trace_record (NULL, http_access_context_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_NEW))
    icl_stats_inc ("http_access_context_new", &s_http_access_context_new_stats);
#endif

    self = http_access_context_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_ACCESS_CONTEXT_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, http_access_context_show_);
#endif

//
self->basic  = ipr_password_table_link (server->basic);
self->digest = ipr_password_table_link (server->digest);
self->access_log = smt_log_link (server->access_log);
self->alert_log  = smt_log_link (server->alert_log);
self->debug_log  = smt_log_link (server->debug_log);
self->blacklist  = ipr_dict_table_link (server->blacklist);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_NEW))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_NEW))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    http_access_context_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_context_annihilate (
    http_access_context_t * ( * self_p )  //  Reference to object reference
)
{

    http_access_context_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_DESTROY))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_DESTROY))
    icl_trace_record (NULL, http_access_context_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_DESTROY))
    icl_stats_inc ("http_access_context_annihilate", &s_http_access_context_annihilate_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

smt_thread_unlink (&self->thread);
icl_mem_strfree (&self->address);
http_request_unlink  (&self->request);
http_response_unlink (&self->response);
ipr_password_table_unlink (&self->basic);
ipr_password_table_unlink (&self->digest);
smt_log_unlink  (&self->access_log);
smt_log_unlink  (&self->alert_log);
smt_log_unlink  (&self->debug_log);
icl_mem_strfree (&self->fail_user);
icl_mem_strfree (&self->fail_realm);
icl_mem_strfree (&self->auth_user);
icl_mem_strfree (&self->auth_group);
ipr_process_destroy (&self->process);
ipr_dict_table_unlink (&self->blacklist);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_DESTROY))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_DESTROY))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_destroy_finish"
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
    http_access_context_set_thread

    Type: Component method
    Accepts a http_access_context_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_access_context_set_thread (
    http_access_context_t * self,       //  Reference to object
    smt_thread_t * thread               //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_THREAD))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_thread_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_THREAD))
    icl_trace_record (NULL, http_access_context_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_THREAD))
    icl_stats_inc ("http_access_context_set_thread", &s_http_access_context_set_thread_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

//
smt_thread_unlink (&self->thread);
self->thread = smt_thread_link (thread);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_THREAD))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_THREAD))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_thread_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_context_set_address

    Type: Component method
    Accepts a http_access_context_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_access_context_set_address (
    http_access_context_t * self,       //  Reference to object
    char * address                      //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_ADDRESS))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_address_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_ADDRESS))
    icl_trace_record (NULL, http_access_context_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_ADDRESS))
    icl_stats_inc ("http_access_context_set_address", &s_http_access_context_set_address_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

//
icl_mem_strfree (&self->address);
self->address = icl_mem_strdup (address);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_ADDRESS))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_ADDRESS))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_address_finish"
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
    http_access_context_set_request

    Type: Component method
    Accepts a http_access_context_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_access_context_set_request (
    http_access_context_t * self,       //  Reference to object
    http_request_t * request            //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_REQUEST))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_request_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_REQUEST))
    icl_trace_record (NULL, http_access_context_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_REQUEST))
    icl_stats_inc ("http_access_context_set_request", &s_http_access_context_set_request_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

//
http_request_unlink (&self->request);
self->request = http_request_link (request);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_REQUEST))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_REQUEST))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_request_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" request=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, request, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_context_set_response

    Type: Component method
    Accepts a http_access_context_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_access_context_set_response (
    http_access_context_t * self,       //  Reference to object
    http_response_t * response          //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_RESPONSE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_response_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" response=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, response);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_RESPONSE))
    icl_trace_record (NULL, http_access_context_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_RESPONSE))
    icl_stats_inc ("http_access_context_set_response", &s_http_access_context_set_response_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

//
http_response_unlink (&self->response);
self->response = http_response_link (response);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_RESPONSE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_RESPONSE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_response_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" response=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, response, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_context_set_auth

    Type: Component method
    Accepts a http_access_context_t reference and returns zero in case of success,
    1 in case of errors.
    Stores the user name and group after successful authentication.
    -------------------------------------------------------------------------
 */

int
    http_access_context_set_auth (
    http_access_context_t * self,       //  Reference to object
    ipr_password_table_t * table,       //  Not documented
    char * group                        //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_AUTH))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_auth_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" table=\"%pp\""
" group=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, table, group);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_AUTH))
    icl_trace_record (NULL, http_access_context_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_AUTH))
    icl_stats_inc ("http_access_context_set_auth", &s_http_access_context_set_auth_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

//
icl_mem_strfree (&self->fail_user);
icl_mem_strfree (&self->fail_realm);
icl_mem_strfree (&self->auth_user);
icl_mem_strfree (&self->auth_group);
self->auth_user  = icl_mem_strdup (table->username);
self->auth_group = icl_mem_strdup (group);
self->fail_code  = table->result;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_AUTH))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_AUTH))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_auth_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" table=\"%pp\""
" group=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, table, group, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_context_set_fail

    Type: Component method
    Accepts a http_access_context_t reference and returns zero in case of success,
    1 in case of errors.
    Stores the user name which tried but failed to authenticated, and its
    realm.
    -------------------------------------------------------------------------
 */

int
    http_access_context_set_fail (
    http_access_context_t * self,       //  Reference to object
    ipr_password_table_t * table        //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_FAIL))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_fail_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_FAIL))
    icl_trace_record (NULL, http_access_context_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SET_FAIL))
    icl_stats_inc ("http_access_context_set_fail", &s_http_access_context_set_fail_stats);
#endif

HTTP_ACCESS_CONTEXT_ASSERT_SANE (self);

//
icl_mem_strfree (&self->fail_user);
icl_mem_strfree (&self->fail_realm);
icl_mem_strfree (&self->auth_user);
icl_mem_strfree (&self->auth_group);
self->fail_user  = icl_mem_strdup (table->username);
self->fail_realm = icl_mem_strdup (table->realm);
self->fail_code  = table->result;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_FAIL))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SET_FAIL))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_set_fail_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" table=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, table, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_access_context_format

    Type: Component method
    Formats a line of logging information, inserting logging symbols.  Returns
    freshly allocated line with formatted text. The template symbools are:
    * $agent - User-Agent header value
    * $arguments - requested URI arguments
    * $datetime - date/time in NCSA format
    * $day - day as two digits
    * $file - filename to which request was translated
    * $from - client address, as dotted number
    * $hh - hour, using 24-hour clock
    * $method - HTTP method
    * $mm - minutes as two digits
    * $mon - month as two digits
    * $path - requested URI path
    * $query - query string, if any
    * $recd - request size, in bytes
    * $referer - Referer header
    * $request - complete request line
    * $sent - response size, in bytes
    * $ss - seconds as two digits
    * $status - response code, 3 digits
    * $user - user name, if authenticated, else -
    * $year - year as four digits
    * $yy - year as two digits
    * $VAR - environment variable VAR
    -------------------------------------------------------------------------
 */

char *
    http_access_context_format (
    http_access_context_t * self,       //  Not documented
    char * format                       //  Not documented
)
{
static char
    *months = "Jan0Feb0Mar0Apr0May0Jun0Jul0Aug0Sep0Oct0Nov0Dec";
ipr_dict_table_t
    *table;
apr_time_t
    apr_time;
apr_time_exp_t
    time_exp;
icl_shortstr_t
    time_str;
    char *
        formatted = NULL;               //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_FORMAT))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_format_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, format);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_FORMAT))
    icl_trace_record (NULL, http_access_context_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_FORMAT))
    icl_stats_inc ("http_access_context_format", &s_http_access_context_format_stats);
#endif

//
table = ipr_dict_table_new ();
//  Import environment
ipr_dict_table_import (table, environ, TRUE);

apr_time = apr_time_now ();
apr_time_exp_lt (&time_exp, apr_time);

//  Define all variables
ipr_dict_assume     (table, "agent",        http_request_get_header (self->request, "user-agent"));
ipr_dict_assume     (table, "arguments",    self->request->request_arguments);
ipr_dict_assume     (table, "datetime",     ipr_http_time_str (time_str));
ipr_dict_assume_fmt (table, "day", "%02d",  time_exp.tm_mday);
ipr_dict_assume     (table, "file",         self->response->filename? self->response->filename: "-");
ipr_dict_assume     (table, "from",         self->request->address);
ipr_dict_assume_fmt (table, "hh", "%02d",   time_exp.tm_hour);
ipr_dict_assume     (table, "method",       self->request->request_method);
ipr_dict_assume_fmt (table, "mm", "%02d",   time_exp.tm_mon + 1);
ipr_dict_assume     (table, "mon",          months + time_exp.tm_mon * 4);
ipr_dict_assume     (table, "path",         self->request->request_path);
ipr_dict_assume_fmt (table, "recd", "%ld",  self->request->content_length);
ipr_dict_assume     (table, "referer",      http_request_get_header (self->request, "referer"));
ipr_dict_assume     (table, "request",      self->request->request_line);
ipr_dict_assume_fmt (table, "sent", "%ld",  self->response->content_length);
ipr_dict_assume_fmt (table, "ss", "%02d",   time_exp.tm_sec);
ipr_dict_assume_fmt (table, "status", "%d", self->response->reply_code);
ipr_dict_assume     (table, "user",         self->auth_user? self->auth_user: "-");
ipr_dict_assume_fmt (table, "year", "%04d", time_exp.tm_year + 1900);
ipr_dict_assume_fmt (table, "yy", "%02d",   time_exp.tm_year);

formatted = ipr_dict_table_template (table, format);
ipr_dict_table_destroy (&table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_FORMAT))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_FORMAT))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_format_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" format=\"%s\""
" formatted=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, format, formatted);
#endif


    return (formatted);
}
/*  -------------------------------------------------------------------------
    http_access_context_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_context_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SELFTEST))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SELFTEST))
    icl_trace_record (NULL, http_access_context_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SELFTEST))
    icl_stats_inc ("http_access_context_selftest", &s_http_access_context_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SELFTEST))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SELFTEST))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_selftest_finish"
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
    http_access_context_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_context_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_TERMINATE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_TERMINATE))
    icl_trace_record (NULL, http_access_context_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_TERMINATE))
    icl_stats_inc ("http_access_context_terminate", &s_http_access_context_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_TERMINATE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_TERMINATE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_terminate_finish"
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
    http_access_context_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_context_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
http_access_context_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SHOW))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SHOW))
    icl_trace_record (NULL, http_access_context_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SHOW))
    icl_stats_inc ("http_access_context_show", &s_http_access_context_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <http_access_context file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SHOW))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SHOW))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_show_finish"
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
    http_access_context_destroy

    Type: Component method
    Destroys a http_access_context_t object. Takes the address of a
    http_access_context_t reference (a pointer to a pointer) and nullifies the
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
    http_access_context_destroy_ (
    http_access_context_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    http_access_context_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_access_context_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC))
    icl_stats_inc ("http_access_context_destroy", &s_http_access_context_destroy_stats);
#endif

if (self) {
    http_access_context_annihilate (self_p);
    http_access_context_free ((http_access_context_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_destroy_public_finish"
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
    http_access_context_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_access_context_t *
    http_access_context_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_access_context_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_ALLOC))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_ALLOC))
    icl_trace_record (NULL, http_access_context_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_ALLOC))
    icl_stats_inc ("http_access_context_alloc", &s_http_access_context_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_access_context_cache_initialise ();

self = (http_access_context_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_access_context_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_ALLOC))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_ALLOC))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_alloc_finish"
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
    http_access_context_free

    Type: Component method
    Freess a http_access_context_t object.
    -------------------------------------------------------------------------
 */

static void
    http_access_context_free (
    http_access_context_t * self        //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_FREE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_FREE))
    icl_trace_record (NULL, http_access_context_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_FREE))
    icl_stats_inc ("http_access_context_free", &s_http_access_context_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (http_access_context_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_access_context_t));
        self->object_tag = HTTP_ACCESS_CONTEXT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_FREE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_FREE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_free_finish"
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
    http_access_context_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_access_context_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE))
    icl_trace_record (NULL, http_access_context_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE))
    icl_stats_inc ("http_access_context_cache_initialise", &s_http_access_context_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_access_context_t));
icl_system_register (http_access_context_cache_purge, http_access_context_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_cache_initialise_finish"
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
    http_access_context_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_context_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_CACHE_PURGE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_PURGE))
    icl_trace_record (NULL, http_access_context_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_CACHE_PURGE))
    icl_stats_inc ("http_access_context_cache_purge", &s_http_access_context_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_PURGE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_CACHE_PURGE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_cache_purge_finish"
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
    http_access_context_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_access_context_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE))
    icl_trace_record (NULL, http_access_context_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE))
    icl_stats_inc ("http_access_context_cache_terminate", &s_http_access_context_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_cache_terminate_finish"
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
    http_access_context_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_access_context_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION))
    icl_trace_record (NULL, http_access_context_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION))
    icl_stats_inc ("http_access_context_show_animation", &s_http_access_context_show_animation_stats);
#endif

http_access_context_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_show_animation_finish"
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
    http_access_context_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_access_context_new_in_scope_ (
    http_access_context_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    http_server_t * server              //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_access_context_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT)  ||  defined (BASE_STATS_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE))
    icl_stats_inc ("http_access_context_new_in_scope", &s_http_access_context_new_in_scope_stats);
#endif

*self_p = http_access_context_new_ (file,line,server);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_access_context_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_access_context_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT)   || defined (BASE_ANIMATE_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE))
    if (http_access_context_animating)
        icl_console_print ("<http_access_context_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_NEW)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_DESTROY)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_THREAD)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_ADDRESS)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_REQUEST)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_RESPONSE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_AUTH)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SET_FAIL)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_FORMAT)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SELFTEST)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SHOW)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_ALLOC)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_FREE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_ACCESS_CONTEXT_NEW_IN_SCOPE) )
void
http_access_context_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "set thread"; break;
        case 4: method_name = "set address"; break;
        case 5: method_name = "set request"; break;
        case 6: method_name = "set response"; break;
        case 7: method_name = "set auth"; break;
        case 8: method_name = "set fail"; break;
        case 9: method_name = "format"; break;
        case 10: method_name = "selftest"; break;
        case 11: method_name = "terminate"; break;
        case 12: method_name = "show"; break;
        case 13: method_name = "destroy public"; break;
        case 14: method_name = "alloc"; break;
        case 15: method_name = "free"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "show animation"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_access_context %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *http_access_context_version_start  = "VeRsIoNsTaRt:ipc";
char *http_access_context_component  = "http_access_context ";
char *http_access_context_version  = "1.0 ";
char *http_access_context_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_access_context_filename  = "http_access_context.icl ";
char *http_access_context_builddate  = "2009/02/19 ";
char *http_access_context_version_end  = "VeRsIoNeNd:ipc";

