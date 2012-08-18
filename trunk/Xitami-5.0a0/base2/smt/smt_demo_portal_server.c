/*---------------------------------------------------------------------------
    smt_demo_portal_server.c - smt_demo_portal_server component

    Generated from smt_demo_portal_server.icl by smt_object_gen using GSL/4.
    
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
#include "smt_demo_portal_server.h"     //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_demo_portal_server_t

//  Shorthands for class methods                                               

#define self_selftest       smt_demo_portal_server_selftest
#define self_print          smt_demo_portal_server_print
#define self_new            smt_demo_portal_server_new
#define self_annihilate     smt_demo_portal_server_annihilate
#define self_initialise     smt_demo_portal_server_initialise
#define self_terminate      smt_demo_portal_server_terminate
#define self__smt_demo_portal_new  smt_demo_portal_server__smt_demo_portal_new
#define self__smt_demo_portal_factory  smt_demo_portal_server__smt_demo_portal_factory
#define self__smt_demo_portal_unbind_shim  smt_demo_portal_server__smt_demo_portal_unbind_shim
#define self__smt_demo_portal_unbind  smt_demo_portal_server__smt_demo_portal_unbind
#define self_hello_shim     smt_demo_portal_server_hello_shim
#define self_hello          smt_demo_portal_server_hello
#define self_print_shim     smt_demo_portal_server_print_shim
#define self__smt_demo_portal_link  smt_demo_portal_server__smt_demo_portal_link
#define self__smt_demo_portal_unlink  smt_demo_portal_server__smt_demo_portal_unlink
#define self_destroy        smt_demo_portal_server_destroy
#define self_unlink         smt_demo_portal_server_unlink
#define self_show_animation  smt_demo_portal_server_show_animation
#define self_free           smt_demo_portal_server_free
#define self_show           smt_demo_portal_server_show
#define self_alloc          smt_demo_portal_server_alloc
#define self_link           smt_demo_portal_server_link
#define self_cache_initialise  smt_demo_portal_server_cache_initialise
#define self_cache_purge    smt_demo_portal_server_cache_purge
#define self_cache_terminate  smt_demo_portal_server_cache_terminate
#define self_new_in_scope   smt_demo_portal_server_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_SELFTEST))
static icl_stats_t *s_smt_demo_portal_server_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_PRINT))
static icl_stats_t *s_smt_demo_portal_server_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_NEW))
static icl_stats_t *s_smt_demo_portal_server_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_DESTROY))
static icl_stats_t *s_smt_demo_portal_server_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_INITIALISE))
static icl_stats_t *s_smt_demo_portal_server_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_TERMINATE))
static icl_stats_t *s_smt_demo_portal_server_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW))
static icl_stats_t *s_smt_demo_portal_server__smt_demo_portal_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY))
static icl_stats_t *s_smt_demo_portal_server__smt_demo_portal_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM))
static icl_stats_t *s_smt_demo_portal_server__smt_demo_portal_unbind_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND))
static icl_stats_t *s_smt_demo_portal_server__smt_demo_portal_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM))
static icl_stats_t *s_smt_demo_portal_server_hello_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_HELLO))
static icl_stats_t *s_smt_demo_portal_server_hello_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM))
static icl_stats_t *s_smt_demo_portal_server_print_shim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK))
static icl_stats_t *s_smt_demo_portal_server__smt_demo_portal_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK))
static icl_stats_t *s_smt_demo_portal_server__smt_demo_portal_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
static icl_stats_t *s_smt_demo_portal_server_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_UNLINK))
static icl_stats_t *s_smt_demo_portal_server_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
static icl_stats_t *s_smt_demo_portal_server_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_FREE))
static icl_stats_t *s_smt_demo_portal_server_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_SHOW))
static icl_stats_t *s_smt_demo_portal_server_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_ALLOC))
static icl_stats_t *s_smt_demo_portal_server_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_LINK))
static icl_stats_t *s_smt_demo_portal_server_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE))
static icl_stats_t *s_smt_demo_portal_server_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE))
static icl_stats_t *s_smt_demo_portal_server_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE))
static icl_stats_t *s_smt_demo_portal_server_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
static icl_stats_t *s_smt_demo_portal_server_new_in_scope_stats = NULL;
#endif
#define smt_demo_portal_server_annihilate(self)  smt_demo_portal_server_annihilate_ (self, __FILE__, __LINE__)
static int
    smt_demo_portal_server_annihilate_ (
smt_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_demo_portal_server_initialise (
void);

static void
    smt_demo_portal_server__smt_demo_portal_unbind_shim (
void * self_v,                          //  Self as void pointer
smt_demo_portal_t * portal              //  Portal reference
);

static int
    smt_demo_portal_server_hello_shim (
void * self_v,                          //  Self as void pointer
smt_demo_portal_t * portal              //  Portal back to server
);

static int
    smt_demo_portal_server_print_shim (
void * self_v,                          //  Self as void pointer
smt_demo_portal_t * portal,             //  Portal back to server
char * string                           //  Not documented
);

static void *
    smt_demo_portal_server__smt_demo_portal_link (
void * object                           //  Reference cast as a void *
);

static void
    smt_demo_portal_server__smt_demo_portal_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define smt_demo_portal_server_alloc()  smt_demo_portal_server_alloc_ (__FILE__, __LINE__)
static smt_demo_portal_server_t *
    smt_demo_portal_server_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_demo_portal_server_cache_initialise (
void);

static void
    smt_demo_portal_server_cache_purge (
void);

static void
    smt_demo_portal_server_cache_terminate (
void);

Bool
    smt_demo_portal_server_animating = TRUE;  //  Animation enabled by default
static Bool
    s_smt_demo_portal_server_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_demo_portal_server_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


static ipr_looseref_list_t
    *s_smt_demo_portal_list;            //  List of portal factories
static Bool
    s_smt_demo_portal_stopped;          //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    smt_demo_portal_server_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_SELFTEST))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SELFTEST))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_SELFTEST))
    icl_stats_inc ("smt_demo_portal_server_selftest", &s_smt_demo_portal_server_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SELFTEST))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_SELFTEST))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_selftest_finish"
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
    smt_demo_portal_server_print

    Type: Component method
    Accepts a smt_demo_portal_server_t reference and returns zero in case of success,
    1 in case of errors.
    This is the print incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_server_print (
    smt_demo_portal_server_t * self,    //  Reference to object
    smt_demo_portal_t * portal,         //  Portal back to client
    char * string                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_PRINT))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_print_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_PRINT))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_PRINT))
    icl_stats_inc ("smt_demo_portal_server_print", &s_smt_demo_portal_server_print_stats);
#endif

SMT_DEMO_PORTAL_SERVER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_demo_portal_server_agent_print (self->thread,portal,string)) {
        //icl_console_print ("Error sending 'print' method to smt_demo_portal_server agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_PRINT))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_PRINT))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_print_finish"
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
    smt_demo_portal_server_new

    Type: Component method
    Creates and initialises a new smt_demo_portal_server_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_demo_portal_server_t *
    smt_demo_portal_server_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_demo_portal_server_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_NEW))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_NEW))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_NEW))
    icl_stats_inc ("smt_demo_portal_server_new", &s_smt_demo_portal_server_new_stats);
#endif

if (!s_smt_demo_portal_server_active)
    self_initialise ();
    self = smt_demo_portal_server_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_DEMO_PORTAL_SERVER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_demo_portal_server_show_);
#endif

self->thread = smt_demo_portal_server_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->smt_demo_portal_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_NEW))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_NEW))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_new_finish"
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
    smt_demo_portal_server_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_portal_server_annihilate_ (
    smt_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif

    smt_demo_portal_server_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_DESTROY))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_DESTROY))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_DESTROY))
    icl_stats_inc ("smt_demo_portal_server_annihilate", &s_smt_demo_portal_server_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (smt_demo_portal_server_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to smt_demo_portal_server agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_DESTROY))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_DESTROY))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_destroy_finish"
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
    smt_demo_portal_server_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_server_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_INITIALISE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_INITIALISE))
    icl_stats_inc ("smt_demo_portal_server_initialise", &s_smt_demo_portal_server_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_demo_portal_server_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_demo_portal_server_mutex)
            s_smt_demo_portal_server_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_demo_portal_server_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_demo_portal_server_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

smt_demo_portal_server_agent_init ();

s_smt_demo_portal_list = ipr_looseref_list_new ();
            s_smt_demo_portal_server_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_demo_portal_server_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_INITIALISE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_initialise_finish"
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
    smt_demo_portal_server_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_terminate (
void)
{
smt_demo_portal_t
    *smt_demo_portal;               //  Portal factory object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_TERMINATE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_TERMINATE))
    icl_stats_inc ("smt_demo_portal_server_terminate", &s_smt_demo_portal_server_terminate_stats);
#endif

if (s_smt_demo_portal_server_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_smt_demo_portal_stopped, TRUE, FALSE) == FALSE) {
    while ((smt_demo_portal = (smt_demo_portal_t *) ipr_looseref_pop (s_smt_demo_portal_list))) {
        smt_demo_portal->server_looseref = NULL;
        smt_demo_portal_destroy (&smt_demo_portal);
    }
}
ipr_looseref_list_destroy (&s_smt_demo_portal_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_demo_portal_server_mutex);
#endif
        s_smt_demo_portal_server_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_TERMINATE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_terminate_finish"
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
    smt_demo_portal_server__smt_demo_portal_new

    Type: Component method
    Creates and initialises a new portal instance.  If the server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

smt_demo_portal_t *
    smt_demo_portal_server__smt_demo_portal_new (
    void * self_v,                      //  Untyped server reference
    char * name                         //  Not documented
)
{
smt_demo_portal_server_t
    *self;
    smt_demo_portal_t *
        smt_demo_portal;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW))
    icl_stats_inc ("smt_demo_portal_server__smt_demo_portal_new", &s_smt_demo_portal_server__smt_demo_portal_new_stats);
#endif

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((smt_demo_portal_server_t *) self_v);
else
    self = self_new ();

smt_demo_portal = smt_demo_portal_new (self, self__smt_demo_portal_link, self__smt_demo_portal_unlink, name);
smt_demo_portal->server_looseref = ipr_looseref_queue (
    self->smt_demo_portal_list, smt_demo_portal_link (smt_demo_portal));

//  Build virtual methods for server-side methods
smt_demo_portal->server_unbind = self__smt_demo_portal_unbind_shim;
smt_demo_portal->request_hello = self_hello_shim;
smt_demo_portal->request_print = self_print_shim;

//  Drop link to server object
self_unlink (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" name=\"%s\""
" smt_demo_portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, name, smt_demo_portal);
#endif


    return (smt_demo_portal);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_server__smt_demo_portal_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

smt_demo_portal_t *
    smt_demo_portal_server__smt_demo_portal_factory (
    char * name                         //  Not documented
)
{
    smt_demo_portal_t *
        smt_demo_portal;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_factory_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY))
    icl_stats_inc ("smt_demo_portal_server__smt_demo_portal_factory", &s_smt_demo_portal_server__smt_demo_portal_factory_stats);
#endif

//
if (!s_smt_demo_portal_server_active)
    self_initialise ();             //  Since we don't call smt_demo_portal_server_new
smt_demo_portal = smt_demo_portal_new (NULL, self__smt_demo_portal_link, self__smt_demo_portal_unlink, name);
smt_demo_portal->server_looseref = ipr_looseref_queue (
    s_smt_demo_portal_list, smt_demo_portal_link (smt_demo_portal));

//  Build virtual methods for server-side methods
smt_demo_portal->server_new = self__smt_demo_portal_new;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_factory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
" smt_demo_portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, smt_demo_portal);
#endif


    return (smt_demo_portal);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_server__smt_demo_portal_unbind_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_server__smt_demo_portal_unbind_shim (
    void * self_v,                      //  Self as void pointer
    smt_demo_portal_t * portal          //  Portal reference
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_unbind_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM))
    icl_stats_inc ("smt_demo_portal_server__smt_demo_portal_unbind_shim", &s_smt_demo_portal_server__smt_demo_portal_unbind_shim_stats);
#endif

self__smt_demo_portal_unbind ((smt_demo_portal_server_t *) self_v, portal);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_unbind_shim_finish"
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
    smt_demo_portal_server__smt_demo_portal_unbind

    Type: Component method
    Accepts a smt_demo_portal_server_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_server__smt_demo_portal_unbind (
    smt_demo_portal_server_t * self,    //  Reference to object
    smt_demo_portal_t * portal          //  Portal reference
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_unbind_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND))
    icl_stats_inc ("smt_demo_portal_server__smt_demo_portal_unbind", &s_smt_demo_portal_server__smt_demo_portal_unbind_stats);
#endif

SMT_DEMO_PORTAL_SERVER_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (smt_demo_portal_server_agent__smt_demo_portal_unbind (self->thread,portal)) {
        //icl_console_print ("Error sending '_smt_demo_portal unbind' method to smt_demo_portal_server agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_unbind_finish"
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
    smt_demo_portal_server_hello_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_portal_server_hello_shim (
    void * self_v,                      //  Self as void pointer
    smt_demo_portal_t * portal          //  Portal back to server
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_hello_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM))
    icl_stats_inc ("smt_demo_portal_server_hello_shim", &s_smt_demo_portal_server_hello_shim_stats);
#endif

rc = self_hello ((smt_demo_portal_server_t *) self_v, portal);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_hello_shim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" portal=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, portal, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_portal_server_hello

    Type: Component method
    Accepts a smt_demo_portal_server_t reference and returns zero in case of success,
    1 in case of errors.
    This is the hello incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_server_hello (
    smt_demo_portal_server_t * self,    //  Reference to object
    smt_demo_portal_t * portal          //  Portal back to client
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_HELLO))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_hello_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_HELLO))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_HELLO))
    icl_stats_inc ("smt_demo_portal_server_hello", &s_smt_demo_portal_server_hello_stats);
#endif

SMT_DEMO_PORTAL_SERVER_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_demo_portal_server_agent_hello (self->thread,portal)) {
        //icl_console_print ("Error sending 'hello' method to smt_demo_portal_server agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_HELLO))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_HELLO))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_hello_finish"
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
    smt_demo_portal_server_print_shim

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_portal_server_print_shim (
    void * self_v,                      //  Self as void pointer
    smt_demo_portal_t * portal,         //  Portal back to server
    char * string                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_print_shim_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM))
    icl_stats_inc ("smt_demo_portal_server_print_shim", &s_smt_demo_portal_server_print_shim_stats);
#endif

rc = self_print ((smt_demo_portal_server_t *) self_v, portal, string);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_print_shim_finish"
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
    smt_demo_portal_server__smt_demo_portal_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    smt_demo_portal_server__smt_demo_portal_link (
    void * object                       //  Reference cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK))
    icl_stats_inc ("smt_demo_portal_server__smt_demo_portal_link", &s_smt_demo_portal_server__smt_demo_portal_link_stats);
#endif

//
object = (void *) smt_demo_portal_server_link (((smt_demo_portal_server_t *) object));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_link_finish"
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
    smt_demo_portal_server__smt_demo_portal_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_server__smt_demo_portal_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK))
    icl_stats_inc ("smt_demo_portal_server__smt_demo_portal_unlink", &s_smt_demo_portal_server__smt_demo_portal_unlink_stats);
#endif

//
smt_demo_portal_server_unlink (((smt_demo_portal_server_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server__smt_demo_portal_unlink_finish"
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
    smt_demo_portal_server_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_portal_server_destroy_ (
    smt_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_portal_server_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    icl_stats_inc ("smt_demo_portal_server_destroy", &s_smt_demo_portal_server_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = smt_demo_portal_server_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_demo_portal_server_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_destroy_public_finish"
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
    smt_demo_portal_server_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_unlink_ (
    smt_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif
    smt_demo_portal_server_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_UNLINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_UNLINK))
    icl_stats_inc ("smt_demo_portal_server_unlink", &s_smt_demo_portal_server_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_demo_portal_server object");
            smt_demo_portal_server_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                smt_demo_portal_server_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                smt_demo_portal_server_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_UNLINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_UNLINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_unlink_finish"
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
    smt_demo_portal_server_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    icl_stats_inc ("smt_demo_portal_server_show_animation", &s_smt_demo_portal_server_show_animation_stats);
#endif

smt_demo_portal_server_animating = enabled;

smt_demo_portal_server_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_show_animation_finish"
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
    smt_demo_portal_server_free

    Type: Component method
    Freess a smt_demo_portal_server_t object.
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_free_ (
    smt_demo_portal_server_t * self,    //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_FREE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_FREE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_FREE))
    icl_stats_inc ("smt_demo_portal_server_free", &s_smt_demo_portal_server_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (smt_demo_portal_server_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_demo_portal_server_t));
        self->object_tag = SMT_DEMO_PORTAL_SERVER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_FREE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_FREE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_free_finish"
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
    smt_demo_portal_server_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_portal_server_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_SHOW))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SHOW))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_SHOW))
    icl_stats_inc ("smt_demo_portal_server_show", &s_smt_demo_portal_server_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_demo_portal_server zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    if (self->history_last > SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH;
        self->history_last %= SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_demo_portal_server>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SHOW))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_SHOW))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_show_finish"
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
    smt_demo_portal_server_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_demo_portal_server_t *
    smt_demo_portal_server_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_demo_portal_server_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_ALLOC))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_ALLOC))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_ALLOC))
    icl_stats_inc ("smt_demo_portal_server_alloc", &s_smt_demo_portal_server_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_demo_portal_server_cache_initialise ();

self = (smt_demo_portal_server_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_demo_portal_server_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_ALLOC))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_ALLOC))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_alloc_finish"
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
    smt_demo_portal_server_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_demo_portal_server_t *
    smt_demo_portal_server_link_ (
    smt_demo_portal_server_t * self,    //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_LINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_LINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_LINK))
    icl_stats_inc ("smt_demo_portal_server_link", &s_smt_demo_portal_server_link_stats);
#endif

    if (self) {
        SMT_DEMO_PORTAL_SERVER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_PORTAL_SERVER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_LINK))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_LINK))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_link_finish"
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
    smt_demo_portal_server_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_server_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE))
    icl_stats_inc ("smt_demo_portal_server_cache_initialise", &s_smt_demo_portal_server_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_demo_portal_server_t));
icl_system_register (smt_demo_portal_server_cache_purge, smt_demo_portal_server_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_cache_initialise_finish"
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
    smt_demo_portal_server_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_server_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE))
    icl_stats_inc ("smt_demo_portal_server_cache_purge", &s_smt_demo_portal_server_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_cache_purge_finish"
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
    smt_demo_portal_server_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_portal_server_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE))
    icl_stats_inc ("smt_demo_portal_server_cache_terminate", &s_smt_demo_portal_server_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_cache_terminate_finish"
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
    smt_demo_portal_server_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_portal_server_new_in_scope_ (
    smt_demo_portal_server_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    icl_stats_inc ("smt_demo_portal_server_new_in_scope", &s_smt_demo_portal_server_new_in_scope_stats);
#endif

*self_p = smt_demo_portal_server_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_demo_portal_server_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_portal_server_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    if (smt_demo_portal_server_animating)
        icl_console_print ("<smt_demo_portal_server_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SELFTEST)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_PRINT)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_NEW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_DESTROY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_NEW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_FACTORY)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND_SHIM)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNBIND)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_HELLO_SHIM)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_HELLO)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_PRINT_SHIM)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_LINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER__SMT_DEMO_PORTAL_UNLINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_UNLINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_FREE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_SHOW)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_ALLOC)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_LINK)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_PURGE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_PORTAL_SERVER_NEW_IN_SCOPE) )
void
smt_demo_portal_server_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "selftest"; break;
        case 2: method_name = "print"; break;
        case 3: method_name = "new"; break;
        case 4: method_name = "destroy"; break;
        case 5: method_name = "initialise"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "_smt_demo_portal new"; break;
        case 8: method_name = "_smt_demo_portal factory"; break;
        case 9: method_name = "_smt_demo_portal unbind shim"; break;
        case 10: method_name = "_smt_demo_portal unbind"; break;
        case 11: method_name = "hello shim"; break;
        case 12: method_name = "hello"; break;
        case 13: method_name = "print shim"; break;
        case 14: method_name = "_smt_demo_portal link"; break;
        case 15: method_name = "_smt_demo_portal unlink"; break;
        case 16: method_name = "destroy public"; break;
        case 17: method_name = "unlink"; break;
        case 18: method_name = "show animation"; break;
        case 19: method_name = "free"; break;
        case 20: method_name = "show"; break;
        case 21: method_name = "alloc"; break;
        case 22: method_name = "link"; break;
        case 23: method_name = "cache initialise"; break;
        case 24: method_name = "cache purge"; break;
        case 25: method_name = "cache terminate"; break;
        case 26: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_demo_portal_server %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_demo_portal_server_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_demo_portal_server_component  = "smt_demo_portal_server ";
char *smt_demo_portal_server_version  = "0.0 ";
char *smt_demo_portal_server_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_demo_portal_server_filename  = "smt_demo_portal_server.icl ";
char *smt_demo_portal_server_builddate  = "2009/02/19 ";
char *smt_demo_portal_server_version_end  = "VeRsIoNeNd:ipc";

