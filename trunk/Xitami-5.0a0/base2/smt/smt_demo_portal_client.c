/*---------------------------------------------------------------------------
    smt_demo_portal_client.c - smt_demo_portal_client component

    Generated from smt_demo_portal_client.icl by smt_object_gen using GSL/4.
    
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
#include "smt_demo_portal_client.h"     //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_demo_portal_client_t

//  Shorthands for class methods                                               

#define self_mogrify        smt_demo_portal_client_mogrify
#define self_test_1         smt_demo_portal_client_test_1
#define self_test_2         smt_demo_portal_client_test_2
#define self_test_3         smt_demo_portal_client_test_3
#define self_selftest       smt_demo_portal_client_selftest
#define self_new            smt_demo_portal_client_new
#define self_annihilate     smt_demo_portal_client_annihilate
#define self__smt_demo_portal_bind  smt_demo_portal_client__smt_demo_portal_bind
#define self__smt_demo_portal_unbind_shim  smt_demo_portal_client__smt_demo_portal_unbind_shim
#define self__smt_demo_portal_unbind  smt_demo_portal_client__smt_demo_portal_unbind
#define self_print_shim     smt_demo_portal_client_print_shim
#define self_print          smt_demo_portal_client_print
#define self_mogrify_shim   smt_demo_portal_client_mogrify_shim
#define self_destroy        smt_demo_portal_client_destroy
#define self_unlink         smt_demo_portal_client_unlink
#define self_show_animation  smt_demo_portal_client_show_animation
#define self_free           smt_demo_portal_client_free
#define self_initialise     smt_demo_portal_client_initialise
#define self_terminate      smt_demo_portal_client_terminate
#define self_show           smt_demo_portal_client_show
#define self_alloc          smt_demo_portal_client_alloc
#define self_link           smt_demo_portal_client_link
#define self_cache_initialise  smt_demo_portal_client_cache_initialise
#define self_cache_purge    smt_demo_portal_client_cache_purge
#define self_cache_terminate  smt_demo_portal_client_cache_terminate
#define self_new_in_scope   smt_demo_portal_client_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_MOGRIFY))
static icl_stats_t *s_smt_demo_portal_client_mogrify_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TEST_1))
static icl_stats_t *s_smt_demo_portal_client_test_1_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TEST_2))
static icl_stats_t *s_smt_demo_portal_client_test_2_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TEST_3))
static icl_stats_t *s_smt_demo_portal_client_test_3_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_SELFTEST))
static icl_stats_t *s_smt_demo_portal_client_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_NEW))
static icl_stats_t *s_smt_demo_portal_client_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_DESTROY))
static icl_stats_t *s_smt_demo_portal_client_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND))
static icl_stats_t *s_smt_demo_portal_client__smt_demo_portal_bind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM))
static icl_stats_t *s_smt_demo_portal_client__smt_demo_portal_unbind_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND))
static icl_stats_t *s_smt_demo_portal_client__smt_demo_portal_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM))
static icl_stats_t *s_smt_demo_portal_client_print_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_PRINT))
static icl_stats_t *s_smt_demo_portal_client_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM))
static icl_stats_t *s_smt_demo_portal_client_mogrify_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC))
static icl_stats_t *s_smt_demo_portal_client_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_UNLINK))
static icl_stats_t *s_smt_demo_portal_client_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION))
static icl_stats_t *s_smt_demo_portal_client_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_FREE))
static icl_stats_t *s_smt_demo_portal_client_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_INITIALISE))
static icl_stats_t *s_smt_demo_portal_client_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TERMINATE))
static icl_stats_t *s_smt_demo_portal_client_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_SHOW))
static icl_stats_t *s_smt_demo_portal_client_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_ALLOC))
static icl_stats_t *s_smt_demo_portal_client_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_LINK))
static icl_stats_t *s_smt_demo_portal_client_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE))
static icl_stats_t *s_smt_demo_portal_client_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE))
static icl_stats_t *s_smt_demo_portal_client_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE))
static icl_stats_t *s_smt_demo_portal_client_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE))
static icl_stats_t *s_smt_demo_portal_client_new_in_scope_stats = NULL;
#endif
#define smt_demo_portal_client_annihilate(self)  smt_demo_portal_client_annihilate_ (self, __FILE__, __LINE__)
static int
    smt_demo_portal_client_annihilate_ (
smt_demo_portal_client_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_demo_portal_client__smt_demo_portal_unbind_shim (
void * self_v,                          //  Self as void pointer
smt_demo_portal_t * portal              //  Portal reference
);

static int
    smt_demo_portal_client_print_shim (
void * self_v,                          //  Self as void pointer
smt_demo_portal_t * portal,             //  Portal back to server
char * string                           //  Not documented
);

static int
    smt_demo_portal_client_mogrify_shim (
void * self_v,                          //  Self as void pointer
smt_demo_portal_t * portal,             //  Portal back to server
char * string,                          //  Not documented
ipr_bucket_t * bucket,                  //  Not documented
Bool option                             //  Not documented
);

static void
    smt_demo_portal_client_initialise (
void);

#define smt_demo_portal_client_alloc()  smt_demo_portal_client_alloc_ (__FILE__, __LINE__)
static smt_demo_portal_client_t *
    smt_demo_portal_client_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_demo_portal_client_cache_initialise (
void);

static void
    smt_demo_portal_client_cache_purge (
void);

static void
    smt_demo_portal_client_cache_terminate (
void);

Bool
    smt_demo_portal_client_animating = TRUE;  //  Animation enabled by default
static Bool
    s_smt_demo_portal_client_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_demo_portal_client_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_demo_portal_client_mogrify

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    This is the mogrify incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client_mogrify (
    smt_demo_portal_client_t * self,    //  Reference to object
    smt_demo_portal_t * portal,         //  Portal back to server
    char * string,                      //  Not documented
    ipr_bucket_t * bucket,              //  Not documented
    Bool option                         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_mogrify_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
" bucket=\"%pp\""
" option=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, string, bucket, option);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_MOGRIFY))
    icl_stats_inc ("smt_demo_portal_client_mogrify", &s_smt_demo_portal_client_mogrify_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_demo_portal_client_agent_mogrify (self->thread,portal,string,bucket,option)) {
        //icl_console_print ("Error sending 'mogrify' method to smt_demo_portal_client agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_mogrify_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
" bucket=\"%pp\""
" option=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, string, bucket, option, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_client_test_1

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client_test_1 (
    smt_demo_portal_client_t * self     //  Reference to object
)
{
smt_demo_portal_t
    *portal;
smt_demo_portal_server_t
    *server;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TEST_1))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_test_1_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_1))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TEST_1))
    icl_stats_inc ("smt_demo_portal_client_test_1", &s_smt_demo_portal_client_test_1_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Create an explicit server object and talk to it via a portal
server = smt_demo_portal_server_new ();
portal = smt_demo_portal_server__smt_demo_portal_new (server, "A");
smt_demo_portal_client__smt_demo_portal_bind (self, portal);
smt_demo_portal_request_print (portal, "Test explicit server");
apr_sleep (100000);
smt_demo_portal_unlink (&portal);
smt_demo_portal_server_unlink (&server);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_1))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TEST_1))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_test_1_finish"
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
    smt_demo_portal_client_test_2

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client_test_2 (
    smt_demo_portal_client_t * self     //  Reference to object
)
{
smt_demo_portal_t
    *portal;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TEST_2))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_test_2_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_2))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TEST_2))
    icl_stats_inc ("smt_demo_portal_client_test_2", &s_smt_demo_portal_client_test_2_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Create an implicit server object and talk to it via a portal
portal = smt_demo_portal_server__smt_demo_portal_new (NULL, "A");
smt_demo_portal_client__smt_demo_portal_bind (self, portal);
smt_demo_portal_request_print (portal, "Test implicit server");
apr_sleep (100000);
smt_demo_portal_unlink (&portal);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_2))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TEST_2))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_test_2_finish"
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
    smt_demo_portal_client_test_3

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client_test_3 (
    smt_demo_portal_client_t * self     //  Reference to object
)
{
smt_demo_portal_t
    *factory,
    *portal;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TEST_3))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_test_3_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_3))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TEST_3))
    icl_stats_inc ("smt_demo_portal_client_test_3", &s_smt_demo_portal_client_test_3_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Use a portal factory to create a new server portal
//  First, create a factory and bind it to ourselves
factory = smt_demo_portal_server__smt_demo_portal_factory ("C");
smt_demo_portal_client__smt_demo_portal_bind (self, factory);

//  Next, invoke the factory method to get a new server and portal
portal = smt_demo_portal_factory (factory, "D");
smt_demo_portal_client__smt_demo_portal_bind (self, portal);

//  Use the server portal
smt_demo_portal_request_print (portal, "test step 3");

//  Let SMT run a little
apr_sleep (100000);

//  Shut-down the portals
smt_demo_portal_unlink (&portal);
smt_demo_portal_unlink (&factory);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_3))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TEST_3))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_test_3_finish"
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
    smt_demo_portal_client_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_selftest (
void)
{
smt_demo_portal_client_t
    *client;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_SELFTEST))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SELFTEST))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_SELFTEST))
    icl_stats_inc ("smt_demo_portal_client_selftest", &s_smt_demo_portal_client_selftest_stats);
#endif

//
client = smt_demo_portal_client_new ();
smt_demo_portal_client_test_1 (client);
smt_wait (0);
smt_demo_portal_client_unlink (&client);
smt_wait (0);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SELFTEST))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_SELFTEST))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_selftest_finish"
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
    smt_demo_portal_client_new

    Type: Component method
    Creates and initialises a new smt_demo_portal_client_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_demo_portal_client_t *
    smt_demo_portal_client_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_demo_portal_client_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_NEW))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_NEW))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_NEW))
    icl_stats_inc ("smt_demo_portal_client_new", &s_smt_demo_portal_client_new_stats);
#endif

if (!s_smt_demo_portal_client_active)
    self_initialise ();
    self = smt_demo_portal_client_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_DEMO_PORTAL_CLIENT_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_demo_portal_client_show_);
#endif

self->thread = smt_demo_portal_client_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->smt_demo_portal_list = ipr_looseref_list_new ();
self->smt_demo_portal_factory_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_NEW))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_NEW))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_new_finish"
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
    smt_demo_portal_client_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_portal_client_annihilate_ (
    smt_demo_portal_client_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    int
        history_last;
#endif

    smt_demo_portal_client_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_DESTROY))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_DESTROY))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_DESTROY))
    icl_stats_inc ("smt_demo_portal_client_annihilate", &s_smt_demo_portal_client_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (smt_demo_portal_client_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to smt_demo_portal_client agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_DESTROY))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_DESTROY))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_destroy_finish"
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
    smt_demo_portal_client__smt_demo_portal_bind

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    Binds a smt_demo_portal portal, ready for use.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client__smt_demo_portal_bind (
    smt_demo_portal_client_t * self,    //  Reference to object
    smt_demo_portal_t * smt_demo_portal  //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client__smt_demo_portal_bind_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" smt_demo_portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, smt_demo_portal);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND))
    icl_stats_inc ("smt_demo_portal_client__smt_demo_portal_bind", &s_smt_demo_portal_client__smt_demo_portal_bind_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

//
smt_demo_portal->client_object = self;
if (smt_demo_portal->server_object)
    smt_demo_portal->client_looseref = ipr_looseref_queue (
        self->smt_demo_portal_list, smt_demo_portal_link (smt_demo_portal));
else                                //  server_object is null for factories
    smt_demo_portal->client_looseref = ipr_looseref_queue (
        self->smt_demo_portal_factory_list, smt_demo_portal_link (smt_demo_portal));

//  Build virtual function table for client-side methods
smt_demo_portal->client_unbind = self__smt_demo_portal_unbind_shim;
smt_demo_portal->response_print = self_print_shim;
smt_demo_portal->response_mogrify = self_mogrify_shim;

//  Signal that portal is ready for use
smt_demo_portal_ready (smt_demo_portal);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client__smt_demo_portal_bind_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" smt_demo_portal=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, smt_demo_portal, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_client__smt_demo_portal_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_client__smt_demo_portal_unbind_shim (
    void * self_v,                      //  Self as void pointer
    smt_demo_portal_t * portal          //  Portal reference
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client__smt_demo_portal_unbind_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM))
    icl_stats_inc ("smt_demo_portal_client__smt_demo_portal_unbind_shim", &s_smt_demo_portal_client__smt_demo_portal_unbind_shim_stats);
#endif

self__smt_demo_portal_unbind ((smt_demo_portal_client_t *) self_v, portal);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client__smt_demo_portal_unbind_shim_finish"
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
    smt_demo_portal_client__smt_demo_portal_unbind

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Client-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client__smt_demo_portal_unbind (
    smt_demo_portal_client_t * self,    //  Reference to object
    smt_demo_portal_t * portal          //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client__smt_demo_portal_unbind_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND))
    icl_stats_inc ("smt_demo_portal_client__smt_demo_portal_unbind", &s_smt_demo_portal_client__smt_demo_portal_unbind_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_demo_portal_client_agent__smt_demo_portal_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_smt_demo_portal unbind' method to smt_demo_portal_client agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client__smt_demo_portal_unbind_finish"
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
    smt_demo_portal_client_print_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_portal_client_print_shim (
    void * self_v,                      //  Self as void pointer
    smt_demo_portal_t * portal,         //  Portal back to server
    char * string                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_print_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM))
    icl_stats_inc ("smt_demo_portal_client_print_shim", &s_smt_demo_portal_client_print_shim_stats);
#endif

rc = self_print ((smt_demo_portal_client_t *) self_v, portal, string);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_print_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_client_print

    Type: Component method
    Accepts a smt_demo_portal_client_t reference and returns zero in case of success,
    1 in case of errors.
    This is the print incoming response method, which the client class should
    inherit and provide the body for.  This method is invoked by the portal when
    the server makes the response; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client_print (
    smt_demo_portal_client_t * self,    //  Reference to object
    smt_demo_portal_t * portal,         //  Portal back to server
    char * string                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_PRINT))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_print_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_PRINT))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_PRINT))
    icl_stats_inc ("smt_demo_portal_client_print", &s_smt_demo_portal_client_print_stats);
#endif

SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_demo_portal_client_agent_print (self->thread,portal,string)) {
        //icl_console_print ("Error sending 'print' method to smt_demo_portal_client agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_PRINT))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_PRINT))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_print_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, portal, string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_client_mogrify_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_portal_client_mogrify_shim (
    void * self_v,                      //  Self as void pointer
    smt_demo_portal_t * portal,         //  Portal back to server
    char * string,                      //  Not documented
    ipr_bucket_t * bucket,              //  Not documented
    Bool option                         //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_mogrify_shim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
" bucket=\"%pp\""
" option=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, string, bucket, option);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM))
    icl_stats_inc ("smt_demo_portal_client_mogrify_shim", &s_smt_demo_portal_client_mogrify_shim_stats);
#endif

rc = self_mogrify ((smt_demo_portal_client_t *) self_v, portal, string, bucket, option);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_mogrify_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" string=\"%s\""
" bucket=\"%pp\""
" option=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, string, bucket, option, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_client_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_client_destroy_ (
    smt_demo_portal_client_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_portal_client_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC))
    icl_stats_inc ("smt_demo_portal_client_destroy", &s_smt_demo_portal_client_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = smt_demo_portal_client_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_demo_portal_client_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_destroy_public_finish"
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
    smt_demo_portal_client_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_unlink_ (
    smt_demo_portal_client_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    int
        history_last;
#endif
    smt_demo_portal_client_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_UNLINK))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_UNLINK))
    icl_stats_inc ("smt_demo_portal_client_unlink", &s_smt_demo_portal_client_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_demo_portal_client object");
            smt_demo_portal_client_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                smt_demo_portal_client_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                smt_demo_portal_client_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_UNLINK))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_unlink_finish"
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
    smt_demo_portal_client_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION))
    icl_stats_inc ("smt_demo_portal_client_show_animation", &s_smt_demo_portal_client_show_animation_stats);
#endif

smt_demo_portal_client_animating = enabled;

smt_demo_portal_client_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_show_animation_finish"
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
    smt_demo_portal_client_free

    Type: Component method
    Freess a smt_demo_portal_client_t object.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_free_ (
    smt_demo_portal_client_t * self,    //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_FREE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_FREE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_FREE))
    icl_stats_inc ("smt_demo_portal_client_free", &s_smt_demo_portal_client_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (smt_demo_portal_client_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_demo_portal_client_t));
        self->object_tag = SMT_DEMO_PORTAL_CLIENT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_FREE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_FREE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_free_finish"
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
    smt_demo_portal_client_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_client_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_INITIALISE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_INITIALISE))
    icl_stats_inc ("smt_demo_portal_client_initialise", &s_smt_demo_portal_client_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_demo_portal_client_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_demo_portal_client_mutex)
            s_smt_demo_portal_client_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_demo_portal_client_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_demo_portal_client_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

smt_demo_portal_client_agent_init ();
            s_smt_demo_portal_client_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_demo_portal_client_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_INITIALISE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_initialise_finish"
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
    smt_demo_portal_client_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TERMINATE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_TERMINATE))
    icl_stats_inc ("smt_demo_portal_client_terminate", &s_smt_demo_portal_client_terminate_stats);
#endif

if (s_smt_demo_portal_client_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_demo_portal_client_mutex);
#endif
        s_smt_demo_portal_client_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_TERMINATE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_terminate_finish"
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
    smt_demo_portal_client_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_portal_client_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_SHOW))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SHOW))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_SHOW))
    icl_stats_inc ("smt_demo_portal_client_show", &s_smt_demo_portal_client_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_demo_portal_client zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    if (self->history_last > SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH;
        self->history_last %= SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_demo_portal_client>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SHOW))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_SHOW))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_show_finish"
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
    smt_demo_portal_client_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_demo_portal_client_t *
    smt_demo_portal_client_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_demo_portal_client_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_ALLOC))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_ALLOC))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_ALLOC))
    icl_stats_inc ("smt_demo_portal_client_alloc", &s_smt_demo_portal_client_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_demo_portal_client_cache_initialise ();

self = (smt_demo_portal_client_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_demo_portal_client_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_ALLOC))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_ALLOC))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_alloc_finish"
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
    smt_demo_portal_client_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_demo_portal_client_t *
    smt_demo_portal_client_link_ (
    smt_demo_portal_client_t * self,    //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_LINK))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_LINK))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_LINK))
    icl_stats_inc ("smt_demo_portal_client_link", &s_smt_demo_portal_client_link_stats);
#endif

    if (self) {
        SMT_DEMO_PORTAL_CLIENT_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_CLIENT)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_DEMO_PORTAL_CLIENT_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_LINK))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_LINK))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_link_finish"
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
    smt_demo_portal_client_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_client_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE))
    icl_stats_inc ("smt_demo_portal_client_cache_initialise", &s_smt_demo_portal_client_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_demo_portal_client_t));
icl_system_register (smt_demo_portal_client_cache_purge, smt_demo_portal_client_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_cache_initialise_finish"
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
    smt_demo_portal_client_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_client_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE))
    icl_stats_inc ("smt_demo_portal_client_cache_purge", &s_smt_demo_portal_client_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_cache_purge_finish"
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
    smt_demo_portal_client_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_client_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE))
    icl_stats_inc ("smt_demo_portal_client_cache_terminate", &s_smt_demo_portal_client_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_cache_terminate_finish"
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
    smt_demo_portal_client_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_client_new_in_scope_ (
    smt_demo_portal_client_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE))
    icl_stats_inc ("smt_demo_portal_client_new_in_scope", &s_smt_demo_portal_client_new_in_scope_stats);
#endif

*self_p = smt_demo_portal_client_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_demo_portal_client_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_portal_client_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE))
    if (smt_demo_portal_client_animating)
        icl_console_print ("<smt_demo_portal_client_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_1)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_2)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TEST_3)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SELFTEST)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_NEW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_DESTROY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_BIND)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND_SHIM)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT__SMT_DEMO_PORTAL_UNBIND)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_PRINT_SHIM)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_PRINT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_MOGRIFY_SHIM)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_UNLINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_FREE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_SHOW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_ALLOC)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_LINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_PURGE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_CLIENT_NEW_IN_SCOPE) )
void
smt_demo_portal_client_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "mogrify"; break;
        case 2: method_name = "test 1"; break;
        case 3: method_name = "test 2"; break;
        case 4: method_name = "test 3"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "new"; break;
        case 7: method_name = "destroy"; break;
        case 8: method_name = "_smt_demo_portal bind"; break;
        case 9: method_name = "_smt_demo_portal unbind shim"; break;
        case 10: method_name = "_smt_demo_portal unbind"; break;
        case 11: method_name = "print shim"; break;
        case 12: method_name = "print"; break;
        case 13: method_name = "mogrify shim"; break;
        case 14: method_name = "destroy public"; break;
        case 15: method_name = "unlink"; break;
        case 16: method_name = "show animation"; break;
        case 17: method_name = "free"; break;
        case 18: method_name = "initialise"; break;
        case 19: method_name = "terminate"; break;
        case 20: method_name = "show"; break;
        case 21: method_name = "alloc"; break;
        case 22: method_name = "link"; break;
        case 23: method_name = "cache initialise"; break;
        case 24: method_name = "cache purge"; break;
        case 25: method_name = "cache terminate"; break;
        case 26: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_demo_portal_client %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_demo_portal_client_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_demo_portal_client_component  = "smt_demo_portal_client ";
char *smt_demo_portal_client_version  = "0.0 ";
char *smt_demo_portal_client_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_demo_portal_client_filename  = "smt_demo_portal_client.icl ";
char *smt_demo_portal_client_builddate  = "2009/02/19 ";
char *smt_demo_portal_client_version_end  = "VeRsIoNeNd:ipc";

