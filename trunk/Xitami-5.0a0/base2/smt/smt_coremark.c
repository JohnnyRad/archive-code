/*---------------------------------------------------------------------------
    smt_coremark.c - smt_coremark component

    CoreMark is the Base2 performance unit for asynchronous multithreaded
    servers.  It measures the event-processing capacity of a single CPU core
    which can be multiplied by the number of available cores to give an
    overall server capacity.

    To use, send a start, then N cycles (10k-1M) and then a finish.
    Generated from smt_coremark.icl by smt_object_gen using GSL/4.
    
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
#include "smt_coremark.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_coremark_t

//  Shorthands for class methods                                               

#define self_start          smt_coremark_start
#define self_cycle          smt_coremark_cycle
#define self_finish         smt_coremark_finish
#define self_calculate      smt_coremark_calculate
#define self_selftest       smt_coremark_selftest
#define self_new            smt_coremark_new
#define self_destroy        smt_coremark_destroy
#define self_annihilate     smt_coremark_annihilate
#define self_unlink         smt_coremark_unlink
#define self_show_animation  smt_coremark_show_animation
#define self_free           smt_coremark_free
#define self_initialise     smt_coremark_initialise
#define self_terminate      smt_coremark_terminate
#define self_show           smt_coremark_show
#define self_alloc          smt_coremark_alloc
#define self_link           smt_coremark_link
#define self_cache_initialise  smt_coremark_cache_initialise
#define self_cache_purge    smt_coremark_cache_purge
#define self_cache_terminate  smt_coremark_cache_terminate
#define self_new_in_scope   smt_coremark_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_START))
static icl_stats_t *s_smt_coremark_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CYCLE))
static icl_stats_t *s_smt_coremark_cycle_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_FINISH))
static icl_stats_t *s_smt_coremark_finish_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CALCULATE))
static icl_stats_t *s_smt_coremark_calculate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_SELFTEST))
static icl_stats_t *s_smt_coremark_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_NEW))
static icl_stats_t *s_smt_coremark_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_DESTROY_PUBLIC))
static icl_stats_t *s_smt_coremark_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_DESTROY))
static icl_stats_t *s_smt_coremark_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_UNLINK))
static icl_stats_t *s_smt_coremark_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_SHOW_ANIMATION))
static icl_stats_t *s_smt_coremark_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_FREE))
static icl_stats_t *s_smt_coremark_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_INITIALISE))
static icl_stats_t *s_smt_coremark_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_TERMINATE))
static icl_stats_t *s_smt_coremark_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_SHOW))
static icl_stats_t *s_smt_coremark_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_ALLOC))
static icl_stats_t *s_smt_coremark_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_LINK))
static icl_stats_t *s_smt_coremark_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CACHE_INITIALISE))
static icl_stats_t *s_smt_coremark_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CACHE_PURGE))
static icl_stats_t *s_smt_coremark_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CACHE_TERMINATE))
static icl_stats_t *s_smt_coremark_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_NEW_IN_SCOPE))
static icl_stats_t *s_smt_coremark_new_in_scope_stats = NULL;
#endif
#define smt_coremark_annihilate(self)   smt_coremark_annihilate_ (self, __FILE__, __LINE__)
static int
    smt_coremark_annihilate_ (
smt_coremark_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_coremark_initialise (
void);

#define smt_coremark_alloc()            smt_coremark_alloc_ (__FILE__, __LINE__)
static smt_coremark_t *
    smt_coremark_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_coremark_cache_initialise (
void);

static void
    smt_coremark_cache_purge (
void);

static void
    smt_coremark_cache_terminate (
void);

Bool
    smt_coremark_animating = TRUE;      //  Animation enabled by default
static Bool
    s_smt_coremark_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_coremark_mutex     = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_coremark_start

    Type: Component method
    Accepts a smt_coremark_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    smt_coremark_start (
    smt_coremark_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_START))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_start_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_START))
    icl_trace_record (NULL, smt_coremark_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_START))
    icl_stats_inc ("smt_coremark_start", &s_smt_coremark_start_stats);
#endif

SMT_COREMARK_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_coremark_agent_start (self->thread)) {
        //icl_console_print ("Error sending 'start' method to smt_coremark agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_START))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_START))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_start_finish"
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
    smt_coremark_cycle

    Type: Component method
    Accepts a smt_coremark_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    smt_coremark_cycle (
    smt_coremark_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_CYCLE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cycle_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CYCLE))
    icl_trace_record (NULL, smt_coremark_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CYCLE))
    icl_stats_inc ("smt_coremark_cycle", &s_smt_coremark_cycle_stats);
#endif

SMT_COREMARK_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_coremark_agent_cycle (self->thread)) {
        //icl_console_print ("Error sending 'cycle' method to smt_coremark agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CYCLE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_CYCLE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cycle_finish"
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
    smt_coremark_finish

    Type: Component method
    Accepts a smt_coremark_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    -------------------------------------------------------------------------
 */

int
    smt_coremark_finish (
    smt_coremark_t * self,              //  Reference to object
    smt_log_t * log                     //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_FINISH))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_finish_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_FINISH))
    icl_trace_record (NULL, smt_coremark_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_FINISH))
    icl_stats_inc ("smt_coremark_finish", &s_smt_coremark_finish_stats);
#endif

SMT_COREMARK_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_coremark_agent_finish (self->thread,log)) {
        //icl_console_print ("Error sending 'finish' method to smt_coremark agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_FINISH))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_FINISH))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_finish_finish"
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
    smt_coremark_calculate

    Type: Component method
    Runs the CoreMark test, if cycles not zero.
    -------------------------------------------------------------------------
 */

void
    smt_coremark_calculate (
    smt_log_t * log,                    //  Not documented
    int cycles                          //  Not documented
)
{
smt_coremark_t
    *coremark;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_CALCULATE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_calculate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" log=\"%pp\""
" cycles=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, log, cycles);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CALCULATE))
    icl_trace_record (NULL, smt_coremark_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CALCULATE))
    icl_stats_inc ("smt_coremark_calculate", &s_smt_coremark_calculate_stats);
#endif

//
if (cycles) {
    coremark = smt_coremark_new ();
    smt_coremark_start (coremark);
    while (cycles--)
        smt_coremark_cycle (coremark);
    smt_coremark_finish (coremark, log);
    smt_coremark_unlink (&coremark);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CALCULATE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_CALCULATE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_calculate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" log=\"%pp\""
" cycles=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, log, cycles);
#endif

}
/*  -------------------------------------------------------------------------
    smt_coremark_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_coremark_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_SELFTEST))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_SELFTEST))
    icl_trace_record (NULL, smt_coremark_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_SELFTEST))
    icl_stats_inc ("smt_coremark_selftest", &s_smt_coremark_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_SELFTEST))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_SELFTEST))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_selftest_finish"
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
    smt_coremark_new

    Type: Component method
    Creates and initialises a new smt_coremark_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_coremark_t *
    smt_coremark_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_coremark_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_NEW))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_NEW))
    icl_trace_record (NULL, smt_coremark_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_NEW))
    icl_stats_inc ("smt_coremark_new", &s_smt_coremark_new_stats);
#endif

if (!s_smt_coremark_active)
    self_initialise ();
    self = smt_coremark_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_COREMARK_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_coremark_show_);
#endif

self->thread = smt_coremark_agent_class_thread_new (self);
self->thread->animate = TRUE;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_NEW))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_NEW))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_new_finish"
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
    smt_coremark_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_coremark_destroy_ (
    smt_coremark_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_coremark_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_DESTROY_PUBLIC))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_coremark_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_DESTROY_PUBLIC))
    icl_stats_inc ("smt_coremark_destroy", &s_smt_coremark_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = smt_coremark_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_coremark_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_DESTROY_PUBLIC))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_destroy_public_finish"
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
    smt_coremark_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_coremark_annihilate_ (
    smt_coremark_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    int
        history_last;
#endif

    smt_coremark_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_DESTROY))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_DESTROY))
    icl_trace_record (NULL, smt_coremark_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_DESTROY))
    icl_stats_inc ("smt_coremark_annihilate", &s_smt_coremark_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_COREMARK_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_COREMARK_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_COREMARK_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_COREMARK_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (smt_coremark_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to smt_coremark agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_DESTROY))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_DESTROY))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_destroy_finish"
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
    smt_coremark_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_coremark_unlink_ (
    smt_coremark_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    int
        history_last;
#endif
    smt_coremark_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_UNLINK))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_UNLINK))
    icl_trace_record (NULL, smt_coremark_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_UNLINK))
    icl_stats_inc ("smt_coremark_unlink", &s_smt_coremark_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_coremark object");
            smt_coremark_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_COREMARK_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_COREMARK_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_COREMARK_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_COREMARK_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                smt_coremark_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                smt_coremark_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_UNLINK))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_UNLINK))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_unlink_finish"
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
    smt_coremark_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_coremark_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_SHOW_ANIMATION))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_coremark_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_SHOW_ANIMATION))
    icl_stats_inc ("smt_coremark_show_animation", &s_smt_coremark_show_animation_stats);
#endif

smt_coremark_animating = enabled;

smt_coremark_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_SHOW_ANIMATION))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_show_animation_finish"
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
    smt_coremark_free

    Type: Component method
    Freess a smt_coremark_t object.
    -------------------------------------------------------------------------
 */

void
    smt_coremark_free_ (
    smt_coremark_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_FREE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_FREE))
    icl_trace_record (NULL, smt_coremark_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_FREE))
    icl_stats_inc ("smt_coremark_free", &s_smt_coremark_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_COREMARK_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_COREMARK_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_COREMARK_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_COREMARK_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (smt_coremark_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_coremark_t));
        self->object_tag = SMT_COREMARK_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_FREE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_FREE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_free_finish"
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
    smt_coremark_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_coremark_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_INITIALISE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_INITIALISE))
    icl_trace_record (NULL, smt_coremark_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_INITIALISE))
    icl_stats_inc ("smt_coremark_initialise", &s_smt_coremark_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_coremark_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_coremark_mutex)
            s_smt_coremark_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_coremark_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_coremark_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

smt_coremark_agent_init ();
            s_smt_coremark_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_coremark_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_INITIALISE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_INITIALISE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_initialise_finish"
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
    smt_coremark_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_coremark_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_TERMINATE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_TERMINATE))
    icl_trace_record (NULL, smt_coremark_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_TERMINATE))
    icl_stats_inc ("smt_coremark_terminate", &s_smt_coremark_terminate_stats);
#endif

if (s_smt_coremark_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_coremark_mutex);
#endif
        s_smt_coremark_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_TERMINATE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_TERMINATE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_terminate_finish"
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
    smt_coremark_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_coremark_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_coremark_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_SHOW))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_SHOW))
    icl_trace_record (NULL, smt_coremark_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_SHOW))
    icl_stats_inc ("smt_coremark_show", &s_smt_coremark_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_coremark zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    if (self->history_last > SMT_COREMARK_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_COREMARK_HISTORY_LENGTH;
        self->history_last %= SMT_COREMARK_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_COREMARK_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_coremark>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_SHOW))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_SHOW))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_show_finish"
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
    smt_coremark_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_coremark_t *
    smt_coremark_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_coremark_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_ALLOC))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_ALLOC))
    icl_trace_record (NULL, smt_coremark_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_ALLOC))
    icl_stats_inc ("smt_coremark_alloc", &s_smt_coremark_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_coremark_cache_initialise ();

self = (smt_coremark_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_coremark_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_ALLOC))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_ALLOC))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_alloc_finish"
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
    smt_coremark_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_coremark_t *
    smt_coremark_link_ (
    smt_coremark_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_LINK))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_LINK))
    icl_trace_record (NULL, smt_coremark_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_LINK))
    icl_stats_inc ("smt_coremark_link", &s_smt_coremark_link_stats);
#endif

    if (self) {
        SMT_COREMARK_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_COREMARK)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_COREMARK_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_COREMARK_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_COREMARK_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_COREMARK_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_LINK))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_LINK))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_link_finish"
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
    smt_coremark_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_coremark_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_CACHE_INITIALISE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_coremark_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CACHE_INITIALISE))
    icl_stats_inc ("smt_coremark_cache_initialise", &s_smt_coremark_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_coremark_t));
icl_system_register (smt_coremark_cache_purge, smt_coremark_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_CACHE_INITIALISE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cache_initialise_finish"
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
    smt_coremark_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_coremark_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_CACHE_PURGE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_PURGE))
    icl_trace_record (NULL, smt_coremark_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CACHE_PURGE))
    icl_stats_inc ("smt_coremark_cache_purge", &s_smt_coremark_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_PURGE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_CACHE_PURGE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cache_purge_finish"
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
    smt_coremark_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_coremark_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_CACHE_TERMINATE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_coremark_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_CACHE_TERMINATE))
    icl_stats_inc ("smt_coremark_cache_terminate", &s_smt_coremark_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_CACHE_TERMINATE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_cache_terminate_finish"
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
    smt_coremark_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_coremark_new_in_scope_ (
    smt_coremark_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_COREMARK)  ||  defined (BASE_ANIMATE_SMT_COREMARK_NEW_IN_SCOPE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_coremark_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_COREMARK)  ||  defined (BASE_STATS_SMT_COREMARK_NEW_IN_SCOPE))
    icl_stats_inc ("smt_coremark_new_in_scope", &s_smt_coremark_new_in_scope_stats);
#endif

*self_p = smt_coremark_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_coremark_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_coremark_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_COREMARK)   || defined (BASE_ANIMATE_SMT_COREMARK_NEW_IN_SCOPE))
    if (smt_coremark_animating)
        icl_console_print ("<smt_coremark_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_COREMARK)   || defined (BASE_TRACE_SMT_COREMARK_START)   || defined (BASE_TRACE_SMT_COREMARK_CYCLE)   || defined (BASE_TRACE_SMT_COREMARK_FINISH)   || defined (BASE_TRACE_SMT_COREMARK_CALCULATE)   || defined (BASE_TRACE_SMT_COREMARK_SELFTEST)   || defined (BASE_TRACE_SMT_COREMARK_NEW)   || defined (BASE_TRACE_SMT_COREMARK_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_COREMARK_DESTROY)   || defined (BASE_TRACE_SMT_COREMARK_UNLINK)   || defined (BASE_TRACE_SMT_COREMARK_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_COREMARK_FREE)   || defined (BASE_TRACE_SMT_COREMARK_INITIALISE)   || defined (BASE_TRACE_SMT_COREMARK_TERMINATE)   || defined (BASE_TRACE_SMT_COREMARK_SHOW)   || defined (BASE_TRACE_SMT_COREMARK_ALLOC)   || defined (BASE_TRACE_SMT_COREMARK_LINK)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_PURGE)   || defined (BASE_TRACE_SMT_COREMARK_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_COREMARK_NEW_IN_SCOPE) )
void
smt_coremark_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "start"; break;
        case 2: method_name = "cycle"; break;
        case 3: method_name = "finish"; break;
        case 4: method_name = "calculate"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "new"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "destroy"; break;
        case 9: method_name = "unlink"; break;
        case 10: method_name = "show animation"; break;
        case 11: method_name = "free"; break;
        case 12: method_name = "initialise"; break;
        case 13: method_name = "terminate"; break;
        case 14: method_name = "show"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "link"; break;
        case 17: method_name = "cache initialise"; break;
        case 18: method_name = "cache purge"; break;
        case 19: method_name = "cache terminate"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_coremark %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_coremark_version_start   = "VeRsIoNsTaRt:ipc";
char *smt_coremark_component       = "smt_coremark ";
char *smt_coremark_version         = "1.0 ";
char *smt_coremark_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_coremark_filename        = "smt_coremark.icl ";
char *smt_coremark_builddate       = "2009/02/19 ";
char *smt_coremark_version_end     = "VeRsIoNeNd:ipc";

