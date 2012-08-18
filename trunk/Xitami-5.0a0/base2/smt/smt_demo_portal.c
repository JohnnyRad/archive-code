/*---------------------------------------------------------------------------
    smt_demo_portal.c - smt_demo_portal component

    Generated from smt_demo_portal.icl by icl_gen using GSL/4.
    
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
#include "smt_demo_portal.h"            //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_demo_portal_t

//  Shorthands for class methods                                               

#define self_new            smt_demo_portal_new
#define self_factory        smt_demo_portal_factory
#define self_request_hello  smt_demo_portal_request_hello
#define self_request_print  smt_demo_portal_request_print
#define self_response_print  smt_demo_portal_response_print
#define self_response_mogrify  smt_demo_portal_response_mogrify
#define self_annihilate     smt_demo_portal_annihilate
#define self_ready          smt_demo_portal_ready
#define self_selftest       smt_demo_portal_selftest
#define self_terminate      smt_demo_portal_terminate
#define self_show           smt_demo_portal_show
#define self_destroy        smt_demo_portal_destroy
#define self_alloc          smt_demo_portal_alloc
#define self_free           smt_demo_portal_free
#define self_read_lock      smt_demo_portal_read_lock
#define self_write_lock     smt_demo_portal_write_lock
#define self_unlock         smt_demo_portal_unlock
#define self_link           smt_demo_portal_link
#define self_unlink         smt_demo_portal_unlink
#define self_cache_initialise  smt_demo_portal_cache_initialise
#define self_cache_purge    smt_demo_portal_cache_purge
#define self_cache_terminate  smt_demo_portal_cache_terminate
#define self_show_animation  smt_demo_portal_show_animation
#define self_new_in_scope   smt_demo_portal_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_NEW))
static icl_stats_t *s_smt_demo_portal_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_FACTORY))
static icl_stats_t *s_smt_demo_portal_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_REQUEST_HELLO))
static icl_stats_t *s_smt_demo_portal_request_hello_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_REQUEST_PRINT))
static icl_stats_t *s_smt_demo_portal_request_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_RESPONSE_PRINT))
static icl_stats_t *s_smt_demo_portal_response_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY))
static icl_stats_t *s_smt_demo_portal_response_mogrify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_DESTROY))
static icl_stats_t *s_smt_demo_portal_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_READY))
static icl_stats_t *s_smt_demo_portal_ready_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SELFTEST))
static icl_stats_t *s_smt_demo_portal_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_TERMINATE))
static icl_stats_t *s_smt_demo_portal_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SHOW))
static icl_stats_t *s_smt_demo_portal_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_DESTROY_PUBLIC))
static icl_stats_t *s_smt_demo_portal_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_ALLOC))
static icl_stats_t *s_smt_demo_portal_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_FREE))
static icl_stats_t *s_smt_demo_portal_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_READ_LOCK))
static icl_stats_t *s_smt_demo_portal_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_WRITE_LOCK))
static icl_stats_t *s_smt_demo_portal_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_UNLOCK))
static icl_stats_t *s_smt_demo_portal_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_LINK))
static icl_stats_t *s_smt_demo_portal_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_UNLINK))
static icl_stats_t *s_smt_demo_portal_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CACHE_INITIALISE))
static icl_stats_t *s_smt_demo_portal_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CACHE_PURGE))
static icl_stats_t *s_smt_demo_portal_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CACHE_TERMINATE))
static icl_stats_t *s_smt_demo_portal_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SHOW_ANIMATION))
static icl_stats_t *s_smt_demo_portal_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_NEW_IN_SCOPE))
static icl_stats_t *s_smt_demo_portal_new_in_scope_stats = NULL;
#endif
#define smt_demo_portal_annihilate(self)  smt_demo_portal_annihilate_ (self, __FILE__, __LINE__)
static void
    smt_demo_portal_annihilate_ (
smt_demo_portal_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define smt_demo_portal_alloc()         smt_demo_portal_alloc_ (__FILE__, __LINE__)
static smt_demo_portal_t *
    smt_demo_portal_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define smt_demo_portal_free(self)      smt_demo_portal_free_ (self, __FILE__, __LINE__)
static void
    smt_demo_portal_free_ (
smt_demo_portal_t * self,               //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_demo_portal_cache_initialise (
void);

static void
    smt_demo_portal_cache_purge (
void);

static void
    smt_demo_portal_cache_terminate (
void);

Bool
    smt_demo_portal_animating = TRUE;   //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_demo_portal_new

    Type: Component method
    Creates and initialises a new smt_demo_portal_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_demo_portal_t *
    smt_demo_portal_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink,   //  Not documented
    char * name                         //  Not documented
)
{
    smt_demo_portal_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_NEW))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server_object=\"%pp\""
" server_link=\"%pp\""
" server_unlink=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server_object, server_link, server_unlink, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_NEW))
    icl_trace_record (NULL, smt_demo_portal_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_NEW))
    icl_stats_inc ("smt_demo_portal_new", &s_smt_demo_portal_new_stats);
#endif

    self = smt_demo_portal_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_DEMO_PORTAL_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
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
        icl_mem_set_callback (self, smt_demo_portal_show_);
#endif

//
self->server_object = (server_link) (server_object);
self->server_unlink = server_unlink;

icl_shortstr_cpy (self->name, name);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_NEW))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_NEW))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server_object=\"%pp\""
" server_link=\"%pp\""
" server_unlink=\"%pp\""
" name=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server_object, server_link, server_unlink, name, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_factory

    Type: Component method
    Asks portal factory to create new portal with implicit server object. The
    server object is owned only by its portal; when you stop the owning portal
    the implicit server object is also stopped.
    -------------------------------------------------------------------------
 */

smt_demo_portal_t *
    smt_demo_portal_factory (
    smt_demo_portal_t * self,           //  Portal factory
    char * name                         //  Not documented
)
{
    smt_demo_portal_t *
        portal;                         //  New portal object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_FACTORY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_factory_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_FACTORY))
    icl_trace_record (NULL, smt_demo_portal_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_FACTORY))
    icl_stats_inc ("smt_demo_portal_factory", &s_smt_demo_portal_factory_stats);
#endif

//
//  Check this is a valid factory
if (self->server_object)
    icl_console_print ("E: factory method is only allowed on portal factories");
assert (!self->server_object);
assert (self->server_new);
//
portal = (self->server_new) (NULL, name);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_FACTORY))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_FACTORY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_factory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, portal);
#endif


    return (portal);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_request_hello

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_request_hello (
    smt_demo_portal_t * self            //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_REQUEST_HELLO))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_request_hello_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_REQUEST_HELLO))
    icl_trace_record (NULL, smt_demo_portal_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_REQUEST_HELLO))
    icl_stats_inc ("smt_demo_portal_request_hello", &s_smt_demo_portal_request_hello_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_hello) (self->server_object, self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_REQUEST_HELLO))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_REQUEST_HELLO))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_request_hello_finish"
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
    smt_demo_portal_request_print

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_request_print (
    smt_demo_portal_t * self,           //  Not documented
    char * string                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_REQUEST_PRINT))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_request_print_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_REQUEST_PRINT))
    icl_trace_record (NULL, smt_demo_portal_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_REQUEST_PRINT))
    icl_stats_inc ("smt_demo_portal_request_print", &s_smt_demo_portal_request_print_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->request_print) (self->server_object, self, string);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_REQUEST_PRINT))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_REQUEST_PRINT))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_request_print_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_response_print

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_response_print (
    smt_demo_portal_t * self,           //  Not documented
    char * string                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_RESPONSE_PRINT))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_response_print_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_RESPONSE_PRINT))
    icl_trace_record (NULL, smt_demo_portal_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_RESPONSE_PRINT))
    icl_stats_inc ("smt_demo_portal_response_print", &s_smt_demo_portal_response_print_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_print) (self->client_object, self, string);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_RESPONSE_PRINT))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_RESPONSE_PRINT))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_response_print_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_response_mogrify

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_response_mogrify (
    smt_demo_portal_t * self,           //  Not documented
    char * string,                      //  Not documented
    ipr_bucket_t * bucket,              //  Not documented
    Bool option                         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_response_mogrify_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
" bucket=\"%pp\""
" option=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string, bucket, option);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY))
    icl_trace_record (NULL, smt_demo_portal_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY))
    icl_stats_inc ("smt_demo_portal_response_mogrify", &s_smt_demo_portal_response_mogrify_stats);
#endif

if (!self->bound)
    icl_console_print ("E: portal was not properly bound to client");
assert (self->bound);
rc = (self->response_mogrify) (self->client_object, self, string, bucket, option);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_response_mogrify_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
" bucket=\"%pp\""
" option=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string, bucket, option, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_annihilate_ (
    smt_demo_portal_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    int
        history_last;
#endif

    smt_demo_portal_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_DESTROY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_DESTROY))
    icl_trace_record (NULL, smt_demo_portal_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_DESTROY))
    icl_stats_inc ("smt_demo_portal_annihilate", &s_smt_demo_portal_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = self->links;
#endif

    SMT_DEMO_PORTAL_ASSERT_SANE (self);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_DESTROY))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_DESTROY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_destroy_finish"
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
    smt_demo_portal_ready

    Type: Component method
    Accepts a smt_demo_portal_t reference and returns zero in case of success,
    1 in case of errors.
    Signals to the server that the portal has been bound by the client and
    is now ready for use.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_ready (
    smt_demo_portal_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_READY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_ready_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_READY))
    icl_trace_record (NULL, smt_demo_portal_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_READY))
    icl_stats_inc ("smt_demo_portal_ready", &s_smt_demo_portal_ready_stats);
#endif

SMT_DEMO_PORTAL_ASSERT_SANE (self);
if (!self->zombie) {

//
self->bound = TRUE;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_READY))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_READY))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_ready_finish"
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
    smt_demo_portal_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SELFTEST))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SELFTEST))
    icl_trace_record (NULL, smt_demo_portal_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SELFTEST))
    icl_stats_inc ("smt_demo_portal_selftest", &s_smt_demo_portal_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SELFTEST))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SELFTEST))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_selftest_finish"
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
    smt_demo_portal_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_TERMINATE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_TERMINATE))
    icl_stats_inc ("smt_demo_portal_terminate", &s_smt_demo_portal_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_TERMINATE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_terminate_finish"
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
    smt_demo_portal_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_portal_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SHOW))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SHOW))
    icl_trace_record (NULL, smt_demo_portal_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SHOW))
    icl_stats_inc ("smt_demo_portal_show", &s_smt_demo_portal_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_demo_portal zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    if (self->history_last > SMT_DEMO_PORTAL_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_DEMO_PORTAL_HISTORY_LENGTH;
        self->history_last %= SMT_DEMO_PORTAL_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_DEMO_PORTAL_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_demo_portal>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SHOW))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SHOW))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_show_finish"
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
    smt_demo_portal_destroy

    Type: Component method
    Destroys a smt_demo_portal_t object. Takes the address of a
    smt_demo_portal_t reference (a pointer to a pointer) and nullifies the
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
    smt_demo_portal_destroy_ (
    smt_demo_portal_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_demo_portal_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_DESTROY_PUBLIC))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_portal_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_DESTROY_PUBLIC))
    icl_stats_inc ("smt_demo_portal_destroy", &s_smt_demo_portal_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        smt_demo_portal_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on smt_demo_portal object");
        smt_demo_portal_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_demo_portal_free_ ((smt_demo_portal_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_DESTROY_PUBLIC))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_destroy_public_finish"
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
    smt_demo_portal_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_demo_portal_t *
    smt_demo_portal_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_demo_portal_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_ALLOC))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_ALLOC))
    icl_trace_record (NULL, smt_demo_portal_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_ALLOC))
    icl_stats_inc ("smt_demo_portal_alloc", &s_smt_demo_portal_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_demo_portal_cache_initialise ();

self = (smt_demo_portal_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_demo_portal_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_ALLOC))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_ALLOC))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_alloc_finish"
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
    smt_demo_portal_free

    Type: Component method
    Freess a smt_demo_portal_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_free_ (
    smt_demo_portal_t * self,           //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_FREE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_FREE))
    icl_trace_record (NULL, smt_demo_portal_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_FREE))
    icl_stats_inc ("smt_demo_portal_free", &s_smt_demo_portal_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (smt_demo_portal_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_demo_portal_t));
        self->object_tag = SMT_DEMO_PORTAL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_FREE))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_FREE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_free_finish"
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
    smt_demo_portal_read_lock

    Type: Component method
    Accepts a smt_demo_portal_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_read_lock (
    smt_demo_portal_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_READ_LOCK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_READ_LOCK))
    icl_trace_record (NULL, smt_demo_portal_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_READ_LOCK))
    icl_stats_inc ("smt_demo_portal_read_lock", &s_smt_demo_portal_read_lock_stats);
#endif

SMT_DEMO_PORTAL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_READ_LOCK))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_READ_LOCK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_read_lock_finish"
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
    smt_demo_portal_write_lock

    Type: Component method
    Accepts a smt_demo_portal_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_write_lock (
    smt_demo_portal_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_WRITE_LOCK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_WRITE_LOCK))
    icl_trace_record (NULL, smt_demo_portal_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_WRITE_LOCK))
    icl_stats_inc ("smt_demo_portal_write_lock", &s_smt_demo_portal_write_lock_stats);
#endif

SMT_DEMO_PORTAL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_WRITE_LOCK))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_WRITE_LOCK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_write_lock_finish"
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
    smt_demo_portal_unlock

    Type: Component method
    Accepts a smt_demo_portal_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_unlock (
    smt_demo_portal_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_UNLOCK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_UNLOCK))
    icl_trace_record (NULL, smt_demo_portal_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_UNLOCK))
    icl_stats_inc ("smt_demo_portal_unlock", &s_smt_demo_portal_unlock_stats);
#endif

SMT_DEMO_PORTAL_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_UNLOCK))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_UNLOCK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_unlock_finish"
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
    smt_demo_portal_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_demo_portal_t *
    smt_demo_portal_link_ (
    smt_demo_portal_t * self,           //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_LINK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_LINK))
    icl_trace_record (NULL, smt_demo_portal_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_LINK))
    icl_stats_inc ("smt_demo_portal_link", &s_smt_demo_portal_link_stats);
#endif

    if (self) {
        SMT_DEMO_PORTAL_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_LINK))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_LINK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_link_finish"
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
    smt_demo_portal_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_unlink_ (
    smt_demo_portal_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
    int
        history_last;
#endif

    smt_demo_portal_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_UNLINK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_UNLINK))
    icl_stats_inc ("smt_demo_portal_unlink", &s_smt_demo_portal_unlink_stats);
#endif

    if (self) {
        SMT_DEMO_PORTAL_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_demo_portal object");
            smt_demo_portal_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_DEMO_PORTAL_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            smt_demo_portal_annihilate_ (self_p, file, line);
        smt_demo_portal_free_ ((smt_demo_portal_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_UNLINK))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_unlink_finish"
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
    smt_demo_portal_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CACHE_INITIALISE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CACHE_INITIALISE))
    icl_stats_inc ("smt_demo_portal_cache_initialise", &s_smt_demo_portal_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_demo_portal_t));
icl_system_register (smt_demo_portal_cache_purge, smt_demo_portal_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CACHE_INITIALISE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_cache_initialise_finish"
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
    smt_demo_portal_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CACHE_PURGE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_portal_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CACHE_PURGE))
    icl_stats_inc ("smt_demo_portal_cache_purge", &s_smt_demo_portal_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CACHE_PURGE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_cache_purge_finish"
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
    smt_demo_portal_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CACHE_TERMINATE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CACHE_TERMINATE))
    icl_stats_inc ("smt_demo_portal_cache_terminate", &s_smt_demo_portal_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CACHE_TERMINATE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_cache_terminate_finish"
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
    smt_demo_portal_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SHOW_ANIMATION))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_portal_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SHOW_ANIMATION))
    icl_stats_inc ("smt_demo_portal_show_animation", &s_smt_demo_portal_show_animation_stats);
#endif

smt_demo_portal_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SHOW_ANIMATION))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_show_animation_finish"
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
    smt_demo_portal_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_new_in_scope_ (
    smt_demo_portal_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * server_object,               //  Not documented
    untyped_link_fn * server_link,      //  Not documented
    untyped_unlink_fn * server_unlink,   //  Not documented
    char * name                         //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_NEW_IN_SCOPE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_new_in_scope_start"
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
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server_object, server_link, server_unlink, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_portal_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_NEW_IN_SCOPE))
    icl_stats_inc ("smt_demo_portal_new_in_scope", &s_smt_demo_portal_new_in_scope_stats);
#endif

*self_p = smt_demo_portal_new_ (file,line,server_object,server_link,server_unlink,name);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_demo_portal_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_portal_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_NEW_IN_SCOPE))
    if (smt_demo_portal_animating)
        icl_console_print ("<smt_demo_portal_new_in_scope_finish"
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
" name=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server_object, server_link, server_unlink, name, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_NEW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_FACTORY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_REQUEST_HELLO)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_REQUEST_PRINT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_RESPONSE_PRINT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_RESPONSE_MOGRIFY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_DESTROY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_READY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SELFTEST)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SHOW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_ALLOC)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_FREE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_READ_LOCK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_WRITE_LOCK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_UNLOCK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_LINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_UNLINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_PURGE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_NEW_IN_SCOPE) )
void
smt_demo_portal_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "factory"; break;
        case 3: method_name = "request hello"; break;
        case 4: method_name = "request print"; break;
        case 5: method_name = "response print"; break;
        case 6: method_name = "response mogrify"; break;
        case 7: method_name = "destroy"; break;
        case 8: method_name = "ready"; break;
        case 9: method_name = "selftest"; break;
        case 10: method_name = "terminate"; break;
        case 11: method_name = "show"; break;
        case 12: method_name = "destroy public"; break;
        case 13: method_name = "alloc"; break;
        case 14: method_name = "free"; break;
        case 15: method_name = "read lock"; break;
        case 16: method_name = "write lock"; break;
        case 17: method_name = "unlock"; break;
        case 18: method_name = "link"; break;
        case 19: method_name = "unlink"; break;
        case 20: method_name = "cache initialise"; break;
        case 21: method_name = "cache purge"; break;
        case 22: method_name = "cache terminate"; break;
        case 23: method_name = "show animation"; break;
        case 24: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_demo_portal %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_demo_portal_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_demo_portal_component    = "smt_demo_portal ";
char *smt_demo_portal_version      = "1.1 ";
char *smt_demo_portal_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_demo_portal_filename     = "smt_demo_portal.icl ";
char *smt_demo_portal_builddate    = "2009/02/19 ";
char *smt_demo_portal_version_end  = "VeRsIoNeNd:ipc";

