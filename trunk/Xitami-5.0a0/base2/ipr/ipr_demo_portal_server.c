/*---------------------------------------------------------------------------
    ipr_demo_portal_server.c - ipr_demo_portal_server component

    Generated from ipr_demo_portal_server.icl by icl_gen using GSL/4.
    
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
#include "ipr_demo_portal_server.h"     //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_demo_portal_server_t

//  Shorthands for class methods                                               

#define self_selftest       ipr_demo_portal_server_selftest
#define self_print          ipr_demo_portal_server_print
#define self_new            ipr_demo_portal_server_new
#define self_annihilate     ipr_demo_portal_server_annihilate
#define self_initialise     ipr_demo_portal_server_initialise
#define self_terminate      ipr_demo_portal_server_terminate
#define self__ipr_demo_portal_new  ipr_demo_portal_server__ipr_demo_portal_new
#define self__ipr_demo_portal_factory  ipr_demo_portal_server__ipr_demo_portal_factory
#define self__ipr_demo_portal_unbind  ipr_demo_portal_server__ipr_demo_portal_unbind
#define self_hello          ipr_demo_portal_server_hello
#define self__ipr_demo_portal_link  ipr_demo_portal_server__ipr_demo_portal_link
#define self__ipr_demo_portal_unlink  ipr_demo_portal_server__ipr_demo_portal_unlink
#define self_show           ipr_demo_portal_server_show
#define self_destroy        ipr_demo_portal_server_destroy
#define self_alloc          ipr_demo_portal_server_alloc
#define self_free           ipr_demo_portal_server_free
#define self_link           ipr_demo_portal_server_link
#define self_unlink         ipr_demo_portal_server_unlink
#define self_show_animation  ipr_demo_portal_server_show_animation
#define self_new_in_scope   ipr_demo_portal_server_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_SELFTEST))
static icl_stats_t *s_ipr_demo_portal_server_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_PRINT))
static icl_stats_t *s_ipr_demo_portal_server_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_NEW))
static icl_stats_t *s_ipr_demo_portal_server_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_DESTROY))
static icl_stats_t *s_ipr_demo_portal_server_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_INITIALISE))
static icl_stats_t *s_ipr_demo_portal_server_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_TERMINATE))
static icl_stats_t *s_ipr_demo_portal_server_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW))
static icl_stats_t *s_ipr_demo_portal_server__ipr_demo_portal_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY))
static icl_stats_t *s_ipr_demo_portal_server__ipr_demo_portal_factory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND))
static icl_stats_t *s_ipr_demo_portal_server__ipr_demo_portal_unbind_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_HELLO))
static icl_stats_t *s_ipr_demo_portal_server_hello_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK))
static icl_stats_t *s_ipr_demo_portal_server__ipr_demo_portal_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK))
static icl_stats_t *s_ipr_demo_portal_server__ipr_demo_portal_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_SHOW))
static icl_stats_t *s_ipr_demo_portal_server_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_demo_portal_server_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_ALLOC))
static icl_stats_t *s_ipr_demo_portal_server_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_FREE))
static icl_stats_t *s_ipr_demo_portal_server_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_LINK))
static icl_stats_t *s_ipr_demo_portal_server_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_UNLINK))
static icl_stats_t *s_ipr_demo_portal_server_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
static icl_stats_t *s_ipr_demo_portal_server_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_demo_portal_server_new_in_scope_stats = NULL;
#endif
static int
    ipr_demo_portal_server_print (
void * self_v,                          //  Self as void pointer
ipr_demo_portal_t * portal,             //  Portal back to client
char * string                           //  Not documented
);

#define ipr_demo_portal_server_annihilate(self)  ipr_demo_portal_server_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_demo_portal_server_annihilate_ (
ipr_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    ipr_demo_portal_server_initialise (
void);

static void
    ipr_demo_portal_server_terminate (
void);

static void
    ipr_demo_portal_server__ipr_demo_portal_unbind (
void * self_v,                          //  Self as void pointer
ipr_demo_portal_t * portal              //  Portal reference
);

static int
    ipr_demo_portal_server_hello (
void * self_v,                          //  Self as void pointer
ipr_demo_portal_t * portal              //  Portal back to client
);

static void *
    ipr_demo_portal_server__ipr_demo_portal_link (
void * object                           //  Reference cast as a void *
);

static void
    ipr_demo_portal_server__ipr_demo_portal_unlink (
void * object_p                         //  Reference pointer cast as a void *
);

#define ipr_demo_portal_server_alloc()  ipr_demo_portal_server_alloc_ (__FILE__, __LINE__)
static ipr_demo_portal_server_t *
    ipr_demo_portal_server_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_demo_portal_server_free(self)  ipr_demo_portal_server_free_ (self, __FILE__, __LINE__)
static void
    ipr_demo_portal_server_free_ (
ipr_demo_portal_server_t * self,        //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

Bool
    ipr_demo_portal_server_animating = TRUE;  //  Animation enabled by default
static Bool
    s_ipr_demo_portal_server_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_ipr_demo_portal_server_mutex  = NULL;
#endif

static ipr_looseref_list_t
    *s_ipr_demo_portal_list;            //  List of portal factories
static Bool
    s_ipr_demo_portal_stopped;          //  Is this portal factory stopped?
/*  -------------------------------------------------------------------------
    ipr_demo_portal_server_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_demo_portal_server_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_SELFTEST))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SELFTEST))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_SELFTEST))
    icl_stats_inc ("ipr_demo_portal_server_selftest", &s_ipr_demo_portal_server_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SELFTEST))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_SELFTEST))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_selftest_finish"
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
    ipr_demo_portal_server_print

    Type: Component method
    This is the print incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    ipr_demo_portal_server_print (
    void * self_v,                      //  Self as void pointer
    ipr_demo_portal_t * portal,         //  Portal back to client
    char * string                       //  Not documented
)
{
ipr_demo_portal_server_t
    *self;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_PRINT))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_print_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_PRINT))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_PRINT))
    icl_stats_inc ("ipr_demo_portal_server_print", &s_ipr_demo_portal_server_print_stats);
#endif

self = (ipr_demo_portal_server_t *) self_v;
icl_console_print ("SERVER PRINT: %s", string);
ipr_demo_portal_response_mogrify (portal, string, NULL, TRUE);
rc = 666;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_PRINT))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_PRINT))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_print_finish"
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
    ipr_demo_portal_server_new

    Type: Component method
    Creates and initialises a new ipr_demo_portal_server_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_demo_portal_server_t *
    ipr_demo_portal_server_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_demo_portal_server_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_NEW))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_NEW))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_NEW))
    icl_stats_inc ("ipr_demo_portal_server_new", &s_ipr_demo_portal_server_new_stats);
#endif

if (!s_ipr_demo_portal_server_active)
    self_initialise ();
    self = ipr_demo_portal_server_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_DEMO_PORTAL_SERVER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_demo_portal_server_show_);
#endif

self->ipr_demo_portal_list = ipr_looseref_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_NEW))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_NEW))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_new_finish"
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
    ipr_demo_portal_server_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_demo_portal_server_annihilate_ (
    ipr_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif

ipr_demo_portal_t
    *ipr_demo_portal;               //  Portal object
    ipr_demo_portal_server_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_DESTROY))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_DESTROY))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_DESTROY))
    icl_stats_inc ("ipr_demo_portal_server_annihilate", &s_ipr_demo_portal_server_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links;
#endif

    IPR_DEMO_PORTAL_SERVER_ASSERT_SANE (self);

//
if (icl_atomic_cas32 ((volatile qbyte *) &self->ipr_demo_portal_stopped, TRUE, FALSE) == FALSE) {
    while ((ipr_demo_portal = (ipr_demo_portal_t *) ipr_looseref_pop (self->ipr_demo_portal_list))) {
        ipr_demo_portal->server_looseref = NULL;
        ipr_demo_portal_destroy (&ipr_demo_portal);
    }
}
ipr_looseref_list_destroy (&self->ipr_demo_portal_list);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_DESTROY))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_DESTROY))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_destroy_finish"
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
    ipr_demo_portal_server_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_demo_portal_server_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_INITIALISE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_INITIALISE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_INITIALISE))
    icl_stats_inc ("ipr_demo_portal_server_initialise", &s_ipr_demo_portal_server_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_ipr_demo_portal_server_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_ipr_demo_portal_server_mutex)
            s_ipr_demo_portal_server_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_ipr_demo_portal_server_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_ipr_demo_portal_server_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

s_ipr_demo_portal_list = ipr_looseref_list_new ();
            s_ipr_demo_portal_server_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_ipr_demo_portal_server_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_INITIALISE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_INITIALISE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_initialise_finish"
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
    ipr_demo_portal_server_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_demo_portal_server_terminate (
void)
{
ipr_demo_portal_t
    *ipr_demo_portal;               //  Portal factory object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_TERMINATE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_TERMINATE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_TERMINATE))
    icl_stats_inc ("ipr_demo_portal_server_terminate", &s_ipr_demo_portal_server_terminate_stats);
#endif

if (s_ipr_demo_portal_server_active) {

//
if (icl_atomic_cas32 ((volatile qbyte *) &s_ipr_demo_portal_stopped, TRUE, FALSE) == FALSE) {
    while ((ipr_demo_portal = (ipr_demo_portal_t *) ipr_looseref_pop (s_ipr_demo_portal_list))) {
        ipr_demo_portal->server_looseref = NULL;
        ipr_demo_portal_destroy (&ipr_demo_portal);
    }
}
ipr_looseref_list_destroy (&s_ipr_demo_portal_list);
#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_ipr_demo_portal_server_mutex);
#endif
        s_ipr_demo_portal_server_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_TERMINATE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_TERMINATE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_terminate_finish"
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
    ipr_demo_portal_server__ipr_demo_portal_new

    Type: Component method
    Creates and initialises a new portal instance.  If the _server argument is
    null, creates a hidden server object that can only be referenced through
    the portal.  This is recommended for most purposes.
    -------------------------------------------------------------------------
 */

ipr_demo_portal_t *
    ipr_demo_portal_server__ipr_demo_portal_new (
    void * self_v,                      //  Untyped server reference
    char * name                         //  Not documented
)
{
ipr_demo_portal_server_t
    *self;
    ipr_demo_portal_t *
        ipr_demo_portal;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW))
    icl_stats_inc ("ipr_demo_portal_server__ipr_demo_portal_new", &s_ipr_demo_portal_server__ipr_demo_portal_new_stats);
#endif

//
//  Grab a link to a new or the provided server object
if (self_v)
    self = self_link ((ipr_demo_portal_server_t *) self_v);
else
    self = self_new ();

ipr_demo_portal = ipr_demo_portal_new (self, self__ipr_demo_portal_link, self__ipr_demo_portal_unlink, name);
ipr_demo_portal->server_looseref = ipr_looseref_queue (
    self->ipr_demo_portal_list, ipr_demo_portal_link (ipr_demo_portal));

//  Build virtual methods for server-side methods
ipr_demo_portal->server_unbind = self__ipr_demo_portal_unbind;
ipr_demo_portal->request_hello = self_hello;
ipr_demo_portal->request_print = self_print;
//  Drop link to server object
self_unlink (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_v=\"%pp\""
" name=\"%s\""
" ipr_demo_portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_v, name, ipr_demo_portal);
#endif


    return (ipr_demo_portal);
}
/*  -------------------------------------------------------------------------
    ipr_demo_portal_server__ipr_demo_portal_factory

    Type: Component method
    Creates and initialises a new portal factory instance.
    -------------------------------------------------------------------------
 */

ipr_demo_portal_t *
    ipr_demo_portal_server__ipr_demo_portal_factory (
    char * name                         //  Not documented
)
{
    ipr_demo_portal_t *
        ipr_demo_portal;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_factory_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY))
    icl_stats_inc ("ipr_demo_portal_server__ipr_demo_portal_factory", &s_ipr_demo_portal_server__ipr_demo_portal_factory_stats);
#endif

//
if (!s_ipr_demo_portal_server_active)
    self_initialise ();             //  Since we don't call ipr_demo_portal_server_new
ipr_demo_portal = ipr_demo_portal_new (NULL, self__ipr_demo_portal_link, self__ipr_demo_portal_unlink, name);
ipr_demo_portal->server_looseref = ipr_looseref_queue (
    s_ipr_demo_portal_list, ipr_demo_portal_link (ipr_demo_portal));

//  Build virtual methods for server-side methods
ipr_demo_portal->server_new = self__ipr_demo_portal_new;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_factory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
" ipr_demo_portal=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, ipr_demo_portal);
#endif


    return (ipr_demo_portal);
}
/*  -------------------------------------------------------------------------
    ipr_demo_portal_server__ipr_demo_portal_unbind

    Type: Component method
    Server-to-portal unbind.
    -------------------------------------------------------------------------
 */

static void
    ipr_demo_portal_server__ipr_demo_portal_unbind (
    void * self_v,                      //  Self as void pointer
    ipr_demo_portal_t * portal          //  Portal reference
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_unbind_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND))
    icl_stats_inc ("ipr_demo_portal_server__ipr_demo_portal_unbind", &s_ipr_demo_portal_server__ipr_demo_portal_unbind_stats);
#endif

//
//  Drop link to portal and remove portal from our list of active portals
if (portal->server_looseref) {
    ipr_looseref_destroy (&portal->server_looseref);
    ipr_demo_portal_unlink (&portal);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_unbind_finish"
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
    ipr_demo_portal_server_hello

    Type: Component method
    This is the hello incoming request method, which the server class should
    inherit and provide the body for.  This method is invoked by the portal when
    the client makes the request; it is a private method and not accessible as
    part of the normal class API for this object.
    -------------------------------------------------------------------------
 */

static int
    ipr_demo_portal_server_hello (
    void * self_v,                      //  Self as void pointer
    ipr_demo_portal_t * portal          //  Portal back to client
)
{
ipr_demo_portal_server_t
    *self;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_HELLO))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_hello_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_HELLO))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_HELLO))
    icl_stats_inc ("ipr_demo_portal_server_hello", &s_ipr_demo_portal_server_hello_stats);
#endif

self = (ipr_demo_portal_server_t *) self_v;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_HELLO))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_HELLO))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_hello_finish"
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
    ipr_demo_portal_server__ipr_demo_portal_link

    Type: Component method
    -------------------------------------------------------------------------
 */

static void *
    ipr_demo_portal_server__ipr_demo_portal_link (
    void * object                       //  Reference cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK))
    icl_stats_inc ("ipr_demo_portal_server__ipr_demo_portal_link", &s_ipr_demo_portal_server__ipr_demo_portal_link_stats);
#endif

//
object = (void *) ipr_demo_portal_server_link (((ipr_demo_portal_server_t *) object));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_link_finish"
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
    ipr_demo_portal_server__ipr_demo_portal_unlink

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_demo_portal_server__ipr_demo_portal_unlink (
    void * object_p                     //  Reference pointer cast as a void *
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK))
    icl_stats_inc ("ipr_demo_portal_server__ipr_demo_portal_unlink", &s_ipr_demo_portal_server__ipr_demo_portal_unlink_stats);
#endif

//
ipr_demo_portal_server_unlink (((ipr_demo_portal_server_t **) object_p));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server__ipr_demo_portal_unlink_finish"
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
    ipr_demo_portal_server_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_demo_portal_server_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_demo_portal_server_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_SHOW))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SHOW))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_SHOW))
    icl_stats_inc ("ipr_demo_portal_server_show", &s_ipr_demo_portal_server_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_demo_portal_server zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    if (self->history_last > IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH;
        self->history_last %= IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_demo_portal_server>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SHOW))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_SHOW))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_show_finish"
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
    ipr_demo_portal_server_destroy

    Type: Component method
    Destroys a ipr_demo_portal_server_t object. Takes the address of a
    ipr_demo_portal_server_t reference (a pointer to a pointer) and nullifies the
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
    ipr_demo_portal_server_destroy_ (
    ipr_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_demo_portal_server_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_demo_portal_server_destroy", &s_ipr_demo_portal_server_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_demo_portal_server_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_demo_portal_server object");
        ipr_demo_portal_server_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_demo_portal_server_free_ ((ipr_demo_portal_server_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_destroy_public_finish"
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
    ipr_demo_portal_server_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_demo_portal_server_t *
    ipr_demo_portal_server_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_demo_portal_server_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_ALLOC))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_ALLOC))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_ALLOC))
    icl_stats_inc ("ipr_demo_portal_server_alloc", &s_ipr_demo_portal_server_alloc_stats);
#endif

self = (ipr_demo_portal_server_t *) icl_mem_alloc_ (sizeof (ipr_demo_portal_server_t), file, line);
if (self)
    memset (self, 0, sizeof (ipr_demo_portal_server_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_ALLOC))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_ALLOC))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_alloc_finish"
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
    ipr_demo_portal_server_free

    Type: Component method
    Freess a ipr_demo_portal_server_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_demo_portal_server_free_ (
    ipr_demo_portal_server_t * self,    //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_FREE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_FREE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_FREE))
    icl_stats_inc ("ipr_demo_portal_server_free", &s_ipr_demo_portal_server_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (ipr_demo_portal_server_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_demo_portal_server_t));
        self->object_tag = IPR_DEMO_PORTAL_SERVER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_FREE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_FREE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_free_finish"
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
    ipr_demo_portal_server_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_demo_portal_server_t *
    ipr_demo_portal_server_link_ (
    ipr_demo_portal_server_t * self,    //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_LINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_LINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_LINK))
    icl_stats_inc ("ipr_demo_portal_server_link", &s_ipr_demo_portal_server_link_stats);
#endif

    if (self) {
        IPR_DEMO_PORTAL_SERVER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_LINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_LINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_link_finish"
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
    ipr_demo_portal_server_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_demo_portal_server_unlink_ (
    ipr_demo_portal_server_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
    int
        history_last;
#endif

    ipr_demo_portal_server_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_UNLINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_UNLINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_UNLINK))
    icl_stats_inc ("ipr_demo_portal_server_unlink", &s_ipr_demo_portal_server_unlink_stats);
#endif

    if (self) {
        IPR_DEMO_PORTAL_SERVER_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_demo_portal_server object");
            ipr_demo_portal_server_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DEMO_PORTAL_SERVER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_DEMO_PORTAL_SERVER_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_demo_portal_server_annihilate_ (self_p, file, line);
        ipr_demo_portal_server_free_ ((ipr_demo_portal_server_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_UNLINK))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_UNLINK))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_unlink_finish"
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
    ipr_demo_portal_server_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_demo_portal_server_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    icl_stats_inc ("ipr_demo_portal_server_show_animation", &s_ipr_demo_portal_server_show_animation_stats);
#endif

ipr_demo_portal_server_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_show_animation_finish"
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
    ipr_demo_portal_server_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_demo_portal_server_new_in_scope_ (
    ipr_demo_portal_server_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER)  ||  defined (BASE_STATS_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_demo_portal_server_new_in_scope", &s_ipr_demo_portal_server_new_in_scope_stats);
#endif

*self_p = ipr_demo_portal_server_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_demo_portal_server_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_demo_portal_server_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_ANIMATE_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE))
    if (ipr_demo_portal_server_animating)
        icl_console_print ("<ipr_demo_portal_server_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SELFTEST)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_PRINT)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_NEW)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_DESTROY)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_INITIALISE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_TERMINATE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_NEW)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_FACTORY)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNBIND)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_HELLO)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_LINK)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER__IPR_DEMO_PORTAL_UNLINK)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SHOW)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_ALLOC)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_FREE)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_LINK)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_UNLINK)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_DEMO_PORTAL_SERVER_NEW_IN_SCOPE) )
void
ipr_demo_portal_server_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
        case 7: method_name = "_ipr_demo_portal new"; break;
        case 8: method_name = "_ipr_demo_portal factory"; break;
        case 9: method_name = "_ipr_demo_portal unbind"; break;
        case 10: method_name = "hello"; break;
        case 11: method_name = "_ipr_demo_portal link"; break;
        case 12: method_name = "_ipr_demo_portal unlink"; break;
        case 13: method_name = "show"; break;
        case 14: method_name = "destroy public"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "free"; break;
        case 17: method_name = "link"; break;
        case 18: method_name = "unlink"; break;
        case 19: method_name = "show animation"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_demo_portal_server %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_demo_portal_server_version_start  = "VeRsIoNsTaRt:ipc";
char *ipr_demo_portal_server_component  = "ipr_demo_portal_server ";
char *ipr_demo_portal_server_version  = "1.1 ";
char *ipr_demo_portal_server_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_demo_portal_server_filename  = "ipr_demo_portal_server.icl ";
char *ipr_demo_portal_server_builddate  = "2009/02/19 ";
char *ipr_demo_portal_server_version_end  = "VeRsIoNeNd:ipc";

