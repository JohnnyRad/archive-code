/*---------------------------------------------------------------------------
    smt_demo_object.c - smt_demo_object component

This object is a demonstration of SMT objects.
    Generated from smt_demo_object.icl by smt_object_gen using GSL/4.
    
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
#include "smt_demo_object.h"            //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_demo_object_t

//  Shorthands for class methods                                               

#define self_new            smt_demo_object_new
#define self_print          smt_demo_object_print
#define self_annihilate     smt_demo_object_annihilate
#define self_selftest       smt_demo_object_selftest
#define self_destroy        smt_demo_object_destroy
#define self_unlink         smt_demo_object_unlink
#define self_show_animation  smt_demo_object_show_animation
#define self_free           smt_demo_object_free
#define self_initialise     smt_demo_object_initialise
#define self_terminate      smt_demo_object_terminate
#define self_show           smt_demo_object_show
#define self_alloc          smt_demo_object_alloc
#define self_link           smt_demo_object_link
#define self_cache_initialise  smt_demo_object_cache_initialise
#define self_cache_purge    smt_demo_object_cache_purge
#define self_cache_terminate  smt_demo_object_cache_terminate
#define self_new_in_scope   smt_demo_object_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_NEW))
static icl_stats_t *s_smt_demo_object_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_PRINT))
static icl_stats_t *s_smt_demo_object_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_DESTROY))
static icl_stats_t *s_smt_demo_object_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_SELFTEST))
static icl_stats_t *s_smt_demo_object_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_DESTROY_PUBLIC))
static icl_stats_t *s_smt_demo_object_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_UNLINK))
static icl_stats_t *s_smt_demo_object_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_SHOW_ANIMATION))
static icl_stats_t *s_smt_demo_object_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_FREE))
static icl_stats_t *s_smt_demo_object_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_INITIALISE))
static icl_stats_t *s_smt_demo_object_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_TERMINATE))
static icl_stats_t *s_smt_demo_object_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_SHOW))
static icl_stats_t *s_smt_demo_object_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_ALLOC))
static icl_stats_t *s_smt_demo_object_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_LINK))
static icl_stats_t *s_smt_demo_object_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_CACHE_INITIALISE))
static icl_stats_t *s_smt_demo_object_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_CACHE_PURGE))
static icl_stats_t *s_smt_demo_object_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_CACHE_TERMINATE))
static icl_stats_t *s_smt_demo_object_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_NEW_IN_SCOPE))
static icl_stats_t *s_smt_demo_object_new_in_scope_stats = NULL;
#endif
#define smt_demo_object_annihilate(self)  smt_demo_object_annihilate_ (self, __FILE__, __LINE__)
static int
    smt_demo_object_annihilate_ (
smt_demo_object_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_demo_object_initialise (
void);

#define smt_demo_object_alloc()         smt_demo_object_alloc_ (__FILE__, __LINE__)
static smt_demo_object_t *
    smt_demo_object_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_demo_object_cache_initialise (
void);

static void
    smt_demo_object_cache_purge (
void);

static void
    smt_demo_object_cache_terminate (
void);

Bool
    smt_demo_object_animating = TRUE;   //  Animation enabled by default
static Bool
    s_smt_demo_object_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_demo_object_mutex  = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_demo_object_new

    Type: Component method
    Creates and initialises a new smt_demo_object_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_demo_object_t *
    smt_demo_object_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * string                       //  Not documented
)
{
    smt_demo_object_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_NEW))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_NEW))
    icl_trace_record (NULL, smt_demo_object_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_NEW))
    icl_stats_inc ("smt_demo_object_new", &s_smt_demo_object_new_stats);
#endif

if (!s_smt_demo_object_active)
    self_initialise ();
    self = smt_demo_object_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_DEMO_OBJECT_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_demo_object_show_);
#endif

self->thread = smt_demo_object_agent_class_thread_new (self);
self->thread->animate = TRUE;

self->string = icl_mem_strdup (string);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_NEW))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_NEW))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" string=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, string, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_demo_object_print

    Type: Component method
    Accepts a smt_demo_object_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    smt_demo_object_print (
    smt_demo_object_t * self,           //  Reference to object
    char * prefix                       //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_PRINT))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_print_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" prefix=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, prefix);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_PRINT))
    icl_trace_record (NULL, smt_demo_object_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_PRINT))
    icl_stats_inc ("smt_demo_object_print", &s_smt_demo_object_print_stats);
#endif

SMT_DEMO_OBJECT_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_demo_object_agent_print (self->thread,prefix)) {
        //icl_console_print ("Error sending 'print' method to smt_demo_object agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_PRINT))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_PRINT))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_print_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" prefix=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, prefix, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_demo_object_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_demo_object_annihilate_ (
    smt_demo_object_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    int
        history_last;
#endif

    smt_demo_object_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_DESTROY))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_DESTROY))
    icl_trace_record (NULL, smt_demo_object_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_DESTROY))
    icl_stats_inc ("smt_demo_object_annihilate", &s_smt_demo_object_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (smt_demo_object_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to smt_demo_object agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_DESTROY))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_DESTROY))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_destroy_finish"
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
    smt_demo_object_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_selftest (
void)
{
smt_demo_object_t
    *self,
    *self_link;
char
    prefix [] = "I say, ";

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_SELFTEST))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SELFTEST))
    icl_trace_record (NULL, smt_demo_object_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_SELFTEST))
    icl_stats_inc ("smt_demo_object_selftest", &s_smt_demo_object_selftest_stats);
#endif

smt_initialise ();
smt_demo_object_agent_animate (TRUE);

self = smt_demo_object_new ("Hello World");
self_link = smt_demo_object_link (self);
smt_demo_object_print (self, prefix);

//  Wipe the prefix now to show that possess did its work.
memset (prefix, 0, sizeof (prefix));

//  Make sure that multiple destroys work
smt_demo_object_destroy (&self);
smt_demo_object_destroy (&self_link);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SELFTEST))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_SELFTEST))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_selftest_finish"
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
    smt_demo_object_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_demo_object_destroy_ (
    smt_demo_object_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_object_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_DESTROY_PUBLIC))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_object_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_DESTROY_PUBLIC))
    icl_stats_inc ("smt_demo_object_destroy", &s_smt_demo_object_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = smt_demo_object_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_demo_object_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_DESTROY_PUBLIC))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_destroy_public_finish"
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
    smt_demo_object_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_unlink_ (
    smt_demo_object_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    int
        history_last;
#endif
    smt_demo_object_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_UNLINK))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_UNLINK))
    icl_trace_record (NULL, smt_demo_object_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_UNLINK))
    icl_stats_inc ("smt_demo_object_unlink", &s_smt_demo_object_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_demo_object object");
            smt_demo_object_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                smt_demo_object_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                smt_demo_object_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_UNLINK))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_UNLINK))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_unlink_finish"
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
    smt_demo_object_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_SHOW_ANIMATION))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_object_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_SHOW_ANIMATION))
    icl_stats_inc ("smt_demo_object_show_animation", &s_smt_demo_object_show_animation_stats);
#endif

smt_demo_object_animating = enabled;

smt_demo_object_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_SHOW_ANIMATION))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_show_animation_finish"
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
    smt_demo_object_free

    Type: Component method
    Freess a smt_demo_object_t object.
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_free_ (
    smt_demo_object_t * self,           //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_FREE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_FREE))
    icl_trace_record (NULL, smt_demo_object_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_FREE))
    icl_stats_inc ("smt_demo_object_free", &s_smt_demo_object_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (smt_demo_object_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_demo_object_t));
        self->object_tag = SMT_DEMO_OBJECT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_FREE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_FREE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_free_finish"
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
    smt_demo_object_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_object_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_INITIALISE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_INITIALISE))
    icl_trace_record (NULL, smt_demo_object_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_INITIALISE))
    icl_stats_inc ("smt_demo_object_initialise", &s_smt_demo_object_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_demo_object_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_demo_object_mutex)
            s_smt_demo_object_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_demo_object_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_demo_object_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

smt_demo_object_agent_init ();
            s_smt_demo_object_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_demo_object_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_INITIALISE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_INITIALISE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_initialise_finish"
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
    smt_demo_object_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_TERMINATE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_TERMINATE))
    icl_trace_record (NULL, smt_demo_object_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_TERMINATE))
    icl_stats_inc ("smt_demo_object_terminate", &s_smt_demo_object_terminate_stats);
#endif

if (s_smt_demo_object_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_demo_object_mutex);
#endif
        s_smt_demo_object_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_TERMINATE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_TERMINATE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_terminate_finish"
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
    smt_demo_object_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_demo_object_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_SHOW))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SHOW))
    icl_trace_record (NULL, smt_demo_object_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_SHOW))
    icl_stats_inc ("smt_demo_object_show", &s_smt_demo_object_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_demo_object zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    if (self->history_last > SMT_DEMO_OBJECT_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_DEMO_OBJECT_HISTORY_LENGTH;
        self->history_last %= SMT_DEMO_OBJECT_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_DEMO_OBJECT_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_demo_object>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SHOW))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_SHOW))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_show_finish"
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
    smt_demo_object_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_demo_object_t *
    smt_demo_object_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_demo_object_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_ALLOC))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ALLOC))
    icl_trace_record (NULL, smt_demo_object_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_ALLOC))
    icl_stats_inc ("smt_demo_object_alloc", &s_smt_demo_object_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_demo_object_cache_initialise ();

self = (smt_demo_object_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_demo_object_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ALLOC))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_ALLOC))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_alloc_finish"
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
    smt_demo_object_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_demo_object_t *
    smt_demo_object_link_ (
    smt_demo_object_t * self,           //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_LINK))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_LINK))
    icl_trace_record (NULL, smt_demo_object_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_LINK))
    icl_stats_inc ("smt_demo_object_link", &s_smt_demo_object_link_stats);
#endif

    if (self) {
        SMT_DEMO_OBJECT_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_DEMO_OBJECT)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_DEMO_OBJECT_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_LINK))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_LINK))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_link_finish"
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
    smt_demo_object_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_demo_object_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_CACHE_INITIALISE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_object_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_CACHE_INITIALISE))
    icl_stats_inc ("smt_demo_object_cache_initialise", &s_smt_demo_object_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_demo_object_t));
icl_system_register (smt_demo_object_cache_purge, smt_demo_object_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_CACHE_INITIALISE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_cache_initialise_finish"
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
    smt_demo_object_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_object_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_CACHE_PURGE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_object_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_CACHE_PURGE))
    icl_stats_inc ("smt_demo_object_cache_purge", &s_smt_demo_object_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_PURGE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_CACHE_PURGE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_cache_purge_finish"
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
    smt_demo_object_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_demo_object_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_CACHE_TERMINATE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_object_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_CACHE_TERMINATE))
    icl_stats_inc ("smt_demo_object_cache_terminate", &s_smt_demo_object_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_CACHE_TERMINATE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_cache_terminate_finish"
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
    smt_demo_object_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_demo_object_new_in_scope_ (
    smt_demo_object_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * string                       //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT)  ||  defined (BASE_ANIMATE_SMT_DEMO_OBJECT_NEW_IN_SCOPE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_object_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT)  ||  defined (BASE_STATS_SMT_DEMO_OBJECT_NEW_IN_SCOPE))
    icl_stats_inc ("smt_demo_object_new_in_scope", &s_smt_demo_object_new_in_scope_stats);
#endif

*self_p = smt_demo_object_new_ (file,line,string);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_demo_object_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_demo_object_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT)   || defined (BASE_ANIMATE_SMT_DEMO_OBJECT_NEW_IN_SCOPE))
    if (smt_demo_object_animating)
        icl_console_print ("<smt_demo_object_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" string=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, string, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_NEW)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_PRINT)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_DESTROY)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SELFTEST)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_UNLINK)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_FREE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_SHOW)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_ALLOC)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_LINK)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_PURGE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_DEMO_OBJECT_NEW_IN_SCOPE) )
void
smt_demo_object_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "print"; break;
        case 3: method_name = "destroy"; break;
        case 4: method_name = "selftest"; break;
        case 5: method_name = "destroy public"; break;
        case 6: method_name = "unlink"; break;
        case 7: method_name = "show animation"; break;
        case 8: method_name = "free"; break;
        case 9: method_name = "initialise"; break;
        case 10: method_name = "terminate"; break;
        case 11: method_name = "show"; break;
        case 12: method_name = "alloc"; break;
        case 13: method_name = "link"; break;
        case 14: method_name = "cache initialise"; break;
        case 15: method_name = "cache purge"; break;
        case 16: method_name = "cache terminate"; break;
        case 17: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_demo_object %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_demo_object_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_demo_object_component    = "smt_demo_object ";
char *smt_demo_object_version      = "1.0 ";
char *smt_demo_object_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_demo_object_filename     = "smt_demo_object.icl ";
char *smt_demo_object_builddate    = "2009/02/19 ";
char *smt_demo_object_version_end  = "VeRsIoNeNd:ipc";

