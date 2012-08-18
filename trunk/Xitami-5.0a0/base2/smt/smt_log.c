/*---------------------------------------------------------------------------
    smt_log.c - smt_log component

    Defines a log. This is a lock-free asynchronous class.
    Generated from smt_log.icl by smt_object_gen using GSL/4.
    
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
#include "smt_log.h"                    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_log_t

//  Shorthands for class methods                                               

#define self_new            smt_log_new
#define self_annihilate     smt_log_annihilate
#define self_open           smt_log_open
#define self_close          smt_log_close
#define self_set_copyto     smt_log_set_copyto
#define self_set_stderr     smt_log_set_stderr
#define self_set_raw        smt_log_set_raw
#define self_print          smt_log_print
#define self_write_bucket   smt_log_write_bucket
#define self_cycle          smt_log_cycle
#define self_dump           smt_log_dump
#define self_dump_env       smt_log_dump_env
#define self_selftest       smt_log_selftest
#define self_destroy        smt_log_destroy
#define self_unlink         smt_log_unlink
#define self_show_animation  smt_log_show_animation
#define self_free           smt_log_free
#define self_initialise     smt_log_initialise
#define self_terminate      smt_log_terminate
#define self_show           smt_log_show
#define self_alloc          smt_log_alloc
#define self_link           smt_log_link
#define self_cache_initialise  smt_log_cache_initialise
#define self_cache_purge    smt_log_cache_purge
#define self_cache_terminate  smt_log_cache_terminate
#define self_new_in_scope   smt_log_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_NEW))
static icl_stats_t *s_smt_log_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DESTROY))
static icl_stats_t *s_smt_log_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_OPEN))
static icl_stats_t *s_smt_log_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CLOSE))
static icl_stats_t *s_smt_log_close_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SET_COPYTO))
static icl_stats_t *s_smt_log_set_copyto_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SET_STDERR))
static icl_stats_t *s_smt_log_set_stderr_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SET_RAW))
static icl_stats_t *s_smt_log_set_raw_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_PRINT))
static icl_stats_t *s_smt_log_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_WRITE_BUCKET))
static icl_stats_t *s_smt_log_write_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CYCLE))
static icl_stats_t *s_smt_log_cycle_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DUMP))
static icl_stats_t *s_smt_log_dump_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DUMP_ENV))
static icl_stats_t *s_smt_log_dump_env_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SELFTEST))
static icl_stats_t *s_smt_log_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DESTROY_PUBLIC))
static icl_stats_t *s_smt_log_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_UNLINK))
static icl_stats_t *s_smt_log_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SHOW_ANIMATION))
static icl_stats_t *s_smt_log_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_FREE))
static icl_stats_t *s_smt_log_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_INITIALISE))
static icl_stats_t *s_smt_log_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_TERMINATE))
static icl_stats_t *s_smt_log_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SHOW))
static icl_stats_t *s_smt_log_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_ALLOC))
static icl_stats_t *s_smt_log_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_LINK))
static icl_stats_t *s_smt_log_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CACHE_INITIALISE))
static icl_stats_t *s_smt_log_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CACHE_PURGE))
static icl_stats_t *s_smt_log_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CACHE_TERMINATE))
static icl_stats_t *s_smt_log_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_NEW_IN_SCOPE))
static icl_stats_t *s_smt_log_new_in_scope_stats = NULL;
#endif
#define smt_log_annihilate(self)        smt_log_annihilate_ (self, __FILE__, __LINE__)
static int
    smt_log_annihilate_ (
smt_log_t * ( * self_p ),               //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    smt_log_initialise (
void);

#define smt_log_alloc()                 smt_log_alloc_ (__FILE__, __LINE__)
static smt_log_t *
    smt_log_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_log_cache_initialise (
void);

static void
    smt_log_cache_purge (
void);

static void
    smt_log_cache_terminate (
void);

Bool
    smt_log_animating = TRUE;           //  Animation enabled by default
static Bool
    s_smt_log_active = FALSE;
#if (defined (BASE_THREADSAFE))
static icl_mutex_t
    *s_smt_log_mutex          = NULL;
#endif
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_log_new

    Type: Component method
    Creates and initialises a new smt_log_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_log_t *
    smt_log_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_log_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_NEW))
    if (smt_log_animating)
        icl_console_print ("<smt_log_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_NEW))
    icl_trace_record (NULL, smt_log_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_NEW))
    icl_stats_inc ("smt_log_new", &s_smt_log_new_stats);
#endif

if (!s_smt_log_active)
    self_initialise ();
    self = smt_log_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_LOG_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_log_show_);
#endif

self->thread = smt_log_agent_class_thread_new (self);
self->thread->animate = TRUE;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_NEW))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_NEW))
    if (smt_log_animating)
        icl_console_print ("<smt_log_new_finish"
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
    smt_log_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static int
    smt_log_annihilate_ (
    smt_log_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    int
        history_last;
#endif

    smt_log_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_DESTROY))
    if (smt_log_animating)
        icl_console_print ("<smt_log_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DESTROY))
    icl_trace_record (NULL, smt_log_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DESTROY))
    icl_stats_inc ("smt_log_annihilate", &s_smt_log_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % SMT_LOG_HISTORY_LENGTH] = file;
    self->history_line  [history_last % SMT_LOG_HISTORY_LENGTH] = line;
    self->history_type  [history_last % SMT_LOG_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % SMT_LOG_HISTORY_LENGTH] = self->links;
#endif


if (self) {
    assert (self->thread);
    if (smt_log_agent_destroy (self->thread,file,line)) {
        //icl_console_print ("Error sending 'destroy' method to smt_log agent");
        rc = -1;
    }
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DESTROY))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_DESTROY))
    if (smt_log_animating)
        icl_console_print ("<smt_log_destroy_finish"
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
    smt_log_open

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Opens the log file output stream, so that data is written to disk.
    If you do not open the log file, data sent to it will be thrown
    away.
    -------------------------------------------------------------------------
 */

int
    smt_log_open (
    smt_log_t * self,                   //  Reference to object
    char * filename,                    //  Log filename
    char * log_path,                    //  Log path name
    char * archive_path,                //  Archive path name
    char * cycle_cmd                    //  Cycle command
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_OPEN))
    if (smt_log_animating)
        icl_console_print ("<smt_log_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" log_path=\"%s\""
" archive_path=\"%s\""
" cycle_cmd=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, log_path, archive_path, cycle_cmd);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_OPEN))
    icl_trace_record (NULL, smt_log_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_OPEN))
    icl_stats_inc ("smt_log_open", &s_smt_log_open_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

    //

    //

if (self) {
    assert (self->thread);
    if (smt_log_agent_open (self->thread,filename,log_path,archive_path,cycle_cmd)) {
        //icl_console_print ("Error sending 'open' method to smt_log agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_OPEN))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_OPEN))
    if (smt_log_animating)
        icl_console_print ("<smt_log_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" log_path=\"%s\""
" archive_path=\"%s\""
" cycle_cmd=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, log_path, archive_path, cycle_cmd, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_log_close

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Closes the log file output, if any.
    -------------------------------------------------------------------------
 */

int
    smt_log_close (
    smt_log_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_CLOSE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_close_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CLOSE))
    icl_trace_record (NULL, smt_log_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CLOSE))
    icl_stats_inc ("smt_log_close", &s_smt_log_close_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (smt_log_agent_close (self->thread)) {
        //icl_console_print ("Error sending 'close' method to smt_log agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CLOSE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_CLOSE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_close_finish"
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
    smt_log_set_copyto

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Set a copy-to log file.  All data printed to the current log file
    will also be sent to the cc log file, in an identical format.  If
    null, the copy-to functionality for this log file is disabled.  Not
    threadsafe; this method should not be called from multiple threads
    at once. It is implemented as a synchronous method so that it takes
    effect immediately.
    -------------------------------------------------------------------------
 */

int
    smt_log_set_copyto (
    smt_log_t * self,                   //  Reference to object
    smt_log_t * copyto                  //  Copy to logfile
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_SET_COPYTO))
    if (smt_log_animating)
        icl_console_print ("<smt_log_set_copyto_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" copyto=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, copyto);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SET_COPYTO))
    icl_trace_record (NULL, smt_log_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SET_COPYTO))
    icl_stats_inc ("smt_log_set_copyto", &s_smt_log_set_copyto_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

//
self->copyto = copyto;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SET_COPYTO))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_SET_COPYTO))
    if (smt_log_animating)
        icl_console_print ("<smt_log_set_copyto_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" copyto=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, copyto, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_log_set_stderr

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Set the stderr option, in which all data sent to the log file will also
    be copied to stderr, and flushed. This is most useful for errors and
    traces, where you don't want to lose cached output if the application
    ends unexpectedly.  Not threadsafe; this method should not be called
    from multiple threads at once. It is implemented as a synchronous
    method so that it takes effect immediately.
    -------------------------------------------------------------------------
 */

int
    smt_log_set_stderr (
    smt_log_t * self,                   //  Reference to object
    Bool option                         //  TRUE or FALSE
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_SET_STDERR))
    if (smt_log_animating)
        icl_console_print ("<smt_log_set_stderr_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" option=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, option);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SET_STDERR))
    icl_trace_record (NULL, smt_log_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SET_STDERR))
    icl_stats_inc ("smt_log_set_stderr", &s_smt_log_set_stderr_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

//
self->tostderr = option;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SET_STDERR))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_SET_STDERR))
    if (smt_log_animating)
        icl_console_print ("<smt_log_set_stderr_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" option=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, option, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_log_set_raw

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Set the raw option, in which data will not be printed with date
    and time.
    -------------------------------------------------------------------------
 */

int
    smt_log_set_raw (
    smt_log_t * self,                   //  Reference to object
    Bool option                         //  TRUE or FALSE
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_SET_RAW))
    if (smt_log_animating)
        icl_console_print ("<smt_log_set_raw_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" option=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, option);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SET_RAW))
    icl_trace_record (NULL, smt_log_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SET_RAW))
    icl_stats_inc ("smt_log_set_raw", &s_smt_log_set_raw_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

//
self->raw = option;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SET_RAW))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_SET_RAW))
    if (smt_log_animating)
        icl_console_print ("<smt_log_set_raw_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" option=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, option, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_log_print

    Type: Component method
    Writes a line of text to the log file, formatting the string using the
    provided format and arguments. The string is prefixed by the current
    date and time unless the raw option was set.  The log file object can
    be null, in which case this method does nothing.
    -------------------------------------------------------------------------
 */

void
    smt_log_print (
    smt_log_t * self,                   //  Log file object
    char * format,                      //  Format specifier
...                                     //  Variable arguments
)
{
    va_list
        args;
    va_start (args, format);
    smt_log_print_v (self, format, args );
    va_end (args);
}
/*  -------------------------------------------------------------------------
    smt_log_print_v

    Type: Component method
    Writes a line of text to the log file, formatting the string using the
    provided format and arguments. The string is prefixed by the current
    date and time unless the raw option was set.  The log file object can
    be null, in which case this method does nothing.
    -------------------------------------------------------------------------
 */

void
    smt_log_print_v (
    smt_log_t * self,                   //  Log file object
    char * format,                      //  Format specifier
va_list args                            //  Variable arguments
)
{
apr_time_exp_t
    time_exp;
apr_size_t
    fmtsize;                        //  Size of formatted string
ipr_bucket_t
    *bucket;                        //  Bucket to write

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_PRINT))
    if (smt_log_animating)
        icl_console_print ("<smt_log_print_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_PRINT))
    icl_trace_record (NULL, smt_log_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_PRINT))
    icl_stats_inc ("smt_log_print", &s_smt_log_print_stats);
#endif

//
if (self) {
    bucket = ipr_bucket_new (SMT_LOG_LINEMAX + 1);
    if (self->raw)
        apr_vsnprintf ((char *) bucket->data, SMT_LOG_LINEMAX, format, args);
    else {
        apr_time_exp_lt (&time_exp, apr_time_now ());
        apr_strftime  ((char *) (bucket->data), &fmtsize, SMT_LOG_LINEMAX, "%Y-%m-%d %T: ", &time_exp);
        apr_vsnprintf ((char *) (bucket->data) + strlen ((char *) (bucket->data)),
            SMT_LOG_LINEMAX - strlen ((char *) (bucket->data)), format, args);
    }
    if (self->tostderr) {
        //  Always printf into %s to guard against %'s in data
        fprintf (stderr, "%s", (char *) (bucket->data));
        fprintf (stderr, "\n");
        fflush  (stderr);
    }
    smt_log_write_bucket (self, bucket);
    if (self->copyto)
        smt_log_write_bucket (self->copyto, bucket);
    ipr_bucket_unlink (&bucket);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_PRINT))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_PRINT))
    if (smt_log_animating)
        icl_console_print ("<smt_log_print_finish"
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

}
/*  -------------------------------------------------------------------------
    smt_log_write_bucket

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Writes a bucket of text to the log file.  The text is not modified or
    prefixed in any way.  Does not flush the log file, so if the server
    is halted abruptly, logging data may be lost.  The bucket text must
    be null-terminated correctly.
    -------------------------------------------------------------------------
 */

int
    smt_log_write_bucket (
    smt_log_t * self,                   //  Reference to object
    ipr_bucket_t * bucket               //  Bucket data to print
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_WRITE_BUCKET))
    if (smt_log_animating)
        icl_console_print ("<smt_log_write_bucket_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_WRITE_BUCKET))
    icl_trace_record (NULL, smt_log_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_WRITE_BUCKET))
    icl_stats_inc ("smt_log_write_bucket", &s_smt_log_write_bucket_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

    //

if (self) {
    assert (self->thread);
    if (smt_log_agent_write_bucket (self->thread,bucket)) {
        //icl_console_print ("Error sending 'write bucket' method to smt_log agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_WRITE_BUCKET))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_WRITE_BUCKET))
    if (smt_log_animating)
        icl_console_print ("<smt_log_write_bucket_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_log_cycle

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Standard function template for asynchronous functions.
    Archives the log file explicitly.
    -------------------------------------------------------------------------
 */

int
    smt_log_cycle (
    smt_log_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_CYCLE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cycle_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CYCLE))
    icl_trace_record (NULL, smt_log_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CYCLE))
    icl_stats_inc ("smt_log_cycle", &s_smt_log_cycle_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

if (self) {
    assert (self->thread);
    if (smt_log_agent_cycle (self->thread)) {
        //icl_console_print ("Error sending 'cycle' method to smt_log agent");
        rc = -1;
    }
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CYCLE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_CYCLE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cycle_finish"
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
    smt_log_dump

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the contents of a bucket to the specified log file.  Filters
    unprintable characters.  Does not apply any specific formatting.
    -------------------------------------------------------------------------
 */

int
    smt_log_dump (
    smt_log_t * self,                   //  Reference to object
    ipr_bucket_t * bucket,              //  Bucket to dump
    char * prefix                       //  Prefix for each line
)
{
#   define BYTES_PER_LINE   (16)
    static const char
        *hex_digit = "0123456789abcdef";
    size_t
        size = bucket->cur_size,
        count,
        repeat_count = 0;
    byte
        *ucbuffer = bucket->data,
        cur_byte;
    char
        last_buffer [(BYTES_PER_LINE * 2) + 1],
        hex_buffer  [(BYTES_PER_LINE * 2) + 1],
        text_buffer [ BYTES_PER_LINE + 1],
        *hex,
        *text;
    int
        remainder;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_DUMP))
    if (smt_log_animating)
        icl_console_print ("<smt_log_dump_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" prefix=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, prefix);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DUMP))
    icl_trace_record (NULL, smt_log_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DUMP))
    icl_stats_inc ("smt_log_dump", &s_smt_log_dump_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

//
memset (last_buffer, 0, sizeof (last_buffer));
while (size > 0) {
    hex       = hex_buffer;
    text      = text_buffer;
    count     = BYTES_PER_LINE;
    remainder = BYTES_PER_LINE - size;
    while (size > 0 && count > 0) {
        size--;
        count--;
        cur_byte = *ucbuffer;

        //  Is current byte a printable character?
        *text++ = (cur_byte < 32 || cur_byte > 127) ? '.' : cur_byte;
        *hex++  = hex_digit [cur_byte >> 4];
        *hex++  = hex_digit [cur_byte & 0x0f];
        ucbuffer++;
    }
    while (remainder > 0) {
        *hex++ = ' ';
        *hex++ = ' ';
        remainder--;
    }
    *hex = '\0';
    *text = '\0';
    if (memcmp (last_buffer, hex_buffer, sizeof (last_buffer)) == 0)
        repeat_count++;
    else {
        if (repeat_count) {
            self_print (self, "%s[repeated %d times]", prefix, repeat_count);
            repeat_count = 0;
        }
        self_print (self, "%s%s | %s", prefix, hex_buffer, text_buffer);
        memcpy (last_buffer, hex_buffer, sizeof (last_buffer));
    }
}
if (repeat_count)
    self_print (self, "%s[repeated %d times]", prefix, repeat_count);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DUMP))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_DUMP))
    if (smt_log_animating)
        icl_console_print ("<smt_log_dump_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" prefix=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, prefix, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_log_dump_env

    Type: Component method
    Accepts a smt_log_t reference and returns zero in case of success,
    1 in case of errors.
    Prints the current environment to the log file.
    -------------------------------------------------------------------------
 */

int
    smt_log_dump_env (
    smt_log_t * self                    //  Reference to object
)
{
int
    string_nbr;                     //  Index into string table
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_DUMP_ENV))
    if (smt_log_animating)
        icl_console_print ("<smt_log_dump_env_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DUMP_ENV))
    icl_trace_record (NULL, smt_log_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DUMP_ENV))
    icl_stats_inc ("smt_log_dump_env", &s_smt_log_dump_env_stats);
#endif

SMT_LOG_ASSERT_SANE (self);
if (!self->zombie) {

//
self_print (self, "****************  Process Environment Variables  ****************");
for (string_nbr = 0; environ [string_nbr]; string_nbr++)
    self_print (self, "%s", environ [string_nbr]);
self_print (self, "");
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DUMP_ENV))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_DUMP_ENV))
    if (smt_log_animating)
        icl_console_print ("<smt_log_dump_env_finish"
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
    smt_log_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_log_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_SELFTEST))
    if (smt_log_animating)
        icl_console_print ("<smt_log_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SELFTEST))
    icl_trace_record (NULL, smt_log_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SELFTEST))
    icl_stats_inc ("smt_log_selftest", &s_smt_log_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SELFTEST))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_SELFTEST))
    if (smt_log_animating)
        icl_console_print ("<smt_log_selftest_finish"
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
    smt_log_destroy

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    smt_log_destroy_ (
    smt_log_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_log_t *
        self = *self_p;                 //  Dereferenced Reference to object reference
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_DESTROY_PUBLIC))
    if (smt_log_animating)
        icl_console_print ("<smt_log_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_log_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_DESTROY_PUBLIC))
    icl_stats_inc ("smt_log_destroy", &s_smt_log_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        rc = smt_log_annihilate_ (self_p, file, line);
    else
    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        smt_log_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_DESTROY_PUBLIC))
    if (smt_log_animating)
        icl_console_print ("<smt_log_destroy_public_finish"
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
    smt_log_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    smt_log_unlink_ (
    smt_log_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    int
        history_last;
#endif
    smt_log_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_UNLINK))
    if (smt_log_animating)
        icl_console_print ("<smt_log_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_UNLINK))
    icl_trace_record (NULL, smt_log_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_UNLINK))
    icl_stats_inc ("smt_log_unlink", &s_smt_log_unlink_stats);
#endif

    if (self) {
        if (self->links == 0) {
            icl_console_print ("Missing link on smt_log object");
            smt_log_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        }
        assert (self->links > 0);

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_LOG_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_LOG_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_LOG_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % SMT_LOG_HISTORY_LENGTH] = self->links - 1;
#endif

        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {
            if (self->zombie)
                smt_log_free (self);
            else {
                //  JS: Have to make the object look like it was called from the
                //      application.  _destroy will decrement links again.
                icl_atomic_inc32 ((volatile qbyte *) &self->links);
                smt_log_destroy_ (self_p, file, line);
            }
        }
        else
            *self_p = NULL;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_UNLINK))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_UNLINK))
    if (smt_log_animating)
        icl_console_print ("<smt_log_unlink_finish"
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
    smt_log_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_log_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_SHOW_ANIMATION))
    if (smt_log_animating)
        icl_console_print ("<smt_log_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_log_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SHOW_ANIMATION))
    icl_stats_inc ("smt_log_show_animation", &s_smt_log_show_animation_stats);
#endif

smt_log_animating = enabled;

smt_log_agent_animate (enabled);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_SHOW_ANIMATION))
    if (smt_log_animating)
        icl_console_print ("<smt_log_show_animation_finish"
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
    smt_log_free

    Type: Component method
    Freess a smt_log_t object.
    -------------------------------------------------------------------------
 */

void
    smt_log_free_ (
    smt_log_t * self,                   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_FREE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_FREE))
    icl_trace_record (NULL, smt_log_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_FREE))
    icl_stats_inc ("smt_log_free", &s_smt_log_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_LOG_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_LOG_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_LOG_HISTORY_LENGTH] = "free";
        self->history_links [history_last % SMT_LOG_HISTORY_LENGTH] = self->links;
#endif

smt_thread_unlink (&self->thread);
        memset (&self->object_tag, 0, sizeof (smt_log_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_log_t));
        self->object_tag = SMT_LOG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_FREE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_FREE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_free_finish"
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
    smt_log_initialise

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_log_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_INITIALISE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_INITIALISE))
    icl_trace_record (NULL, smt_log_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_INITIALISE))
    icl_stats_inc ("smt_log_initialise", &s_smt_log_initialise_stats);
#endif

    //  Test for already active before applying any locks; avoids deadlock in
    //  some classes
    if (!s_smt_log_active) {

#if (defined (BASE_THREADSAFE))
        //  First make sure the object mutex has been created
        apr_thread_mutex_lock (icl_global_mutex);
        if (!s_smt_log_mutex)
            s_smt_log_mutex = icl_mutex_new ();
        apr_thread_mutex_unlock (icl_global_mutex);

        //  Now lock the object mutex
        icl_mutex_lock   (s_smt_log_mutex);

        //  Test again for already active now that we hold the lock
        if (!s_smt_log_active) {
#endif
            //  Register the class termination call-back functions
            icl_system_register (NULL, self_terminate);

smt_log_agent_init ();
            s_smt_log_active = TRUE;
#if (defined (BASE_THREADSAFE))
        }
        icl_mutex_unlock (s_smt_log_mutex);
#endif

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_INITIALISE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_INITIALISE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_initialise_finish"
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
    smt_log_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_log_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_TERMINATE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_TERMINATE))
    icl_trace_record (NULL, smt_log_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_TERMINATE))
    icl_stats_inc ("smt_log_terminate", &s_smt_log_terminate_stats);
#endif

if (s_smt_log_active) {

#if (defined (BASE_THREADSAFE))
        icl_mutex_destroy (&s_smt_log_mutex);
#endif
        s_smt_log_active = FALSE;
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_TERMINATE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_TERMINATE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_terminate_finish"
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
    smt_log_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_log_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    smt_log_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_SHOW))
    if (smt_log_animating)
        icl_console_print ("<smt_log_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SHOW))
    icl_trace_record (NULL, smt_log_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_SHOW))
    icl_stats_inc ("smt_log_show", &s_smt_log_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <smt_log zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    if (self->history_last > SMT_LOG_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % SMT_LOG_HISTORY_LENGTH;
        self->history_last %= SMT_LOG_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % SMT_LOG_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </smt_log>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_SHOW))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_SHOW))
    if (smt_log_animating)
        icl_console_print ("<smt_log_show_finish"
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
    smt_log_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_log_t *
    smt_log_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_log_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_ALLOC))
    if (smt_log_animating)
        icl_console_print ("<smt_log_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_ALLOC))
    icl_trace_record (NULL, smt_log_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_ALLOC))
    icl_stats_inc ("smt_log_alloc", &s_smt_log_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_log_cache_initialise ();

self = (smt_log_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_log_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_ALLOC))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_ALLOC))
    if (smt_log_animating)
        icl_console_print ("<smt_log_alloc_finish"
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
    smt_log_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

smt_log_t *
    smt_log_link_ (
    smt_log_t * self,                   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_LINK))
    if (smt_log_animating)
        icl_console_print ("<smt_log_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_LINK))
    icl_trace_record (NULL, smt_log_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_LINK))
    icl_stats_inc ("smt_log_link", &s_smt_log_link_stats);
#endif

    if (self) {
        SMT_LOG_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_SMT_LOG)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % SMT_LOG_HISTORY_LENGTH] = file;
        self->history_line  [history_last % SMT_LOG_HISTORY_LENGTH] = line;
        self->history_type  [history_last % SMT_LOG_HISTORY_LENGTH] = "link";
        self->history_links [history_last % SMT_LOG_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_LINK))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_LINK))
    if (smt_log_animating)
        icl_console_print ("<smt_log_link_finish"
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
    smt_log_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_log_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_CACHE_INITIALISE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_log_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CACHE_INITIALISE))
    icl_stats_inc ("smt_log_cache_initialise", &s_smt_log_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_log_t));
icl_system_register (smt_log_cache_purge, smt_log_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_CACHE_INITIALISE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cache_initialise_finish"
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
    smt_log_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_log_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_CACHE_PURGE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CACHE_PURGE))
    icl_trace_record (NULL, smt_log_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CACHE_PURGE))
    icl_stats_inc ("smt_log_cache_purge", &s_smt_log_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CACHE_PURGE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_CACHE_PURGE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cache_purge_finish"
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
    smt_log_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_log_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_CACHE_TERMINATE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_log_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_CACHE_TERMINATE))
    icl_stats_inc ("smt_log_cache_terminate", &s_smt_log_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_CACHE_TERMINATE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_cache_terminate_finish"
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
    smt_log_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_log_new_in_scope_ (
    smt_log_t * * self_p,               //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_LOG)  ||  defined (BASE_ANIMATE_SMT_LOG_NEW_IN_SCOPE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_log_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_LOG)  ||  defined (BASE_STATS_SMT_LOG_NEW_IN_SCOPE))
    icl_stats_inc ("smt_log_new_in_scope", &s_smt_log_new_in_scope_stats);
#endif

*self_p = smt_log_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_log_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_log_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_LOG)   || defined (BASE_ANIMATE_SMT_LOG_NEW_IN_SCOPE))
    if (smt_log_animating)
        icl_console_print ("<smt_log_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_LOG)   || defined (BASE_TRACE_SMT_LOG_NEW)   || defined (BASE_TRACE_SMT_LOG_DESTROY)   || defined (BASE_TRACE_SMT_LOG_OPEN)   || defined (BASE_TRACE_SMT_LOG_CLOSE)   || defined (BASE_TRACE_SMT_LOG_SET_COPYTO)   || defined (BASE_TRACE_SMT_LOG_SET_STDERR)   || defined (BASE_TRACE_SMT_LOG_SET_RAW)   || defined (BASE_TRACE_SMT_LOG_PRINT)   || defined (BASE_TRACE_SMT_LOG_WRITE_BUCKET)   || defined (BASE_TRACE_SMT_LOG_CYCLE)   || defined (BASE_TRACE_SMT_LOG_DUMP)   || defined (BASE_TRACE_SMT_LOG_DUMP_ENV)   || defined (BASE_TRACE_SMT_LOG_SELFTEST)   || defined (BASE_TRACE_SMT_LOG_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_LOG_UNLINK)   || defined (BASE_TRACE_SMT_LOG_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_LOG_FREE)   || defined (BASE_TRACE_SMT_LOG_INITIALISE)   || defined (BASE_TRACE_SMT_LOG_TERMINATE)   || defined (BASE_TRACE_SMT_LOG_SHOW)   || defined (BASE_TRACE_SMT_LOG_ALLOC)   || defined (BASE_TRACE_SMT_LOG_LINK)   || defined (BASE_TRACE_SMT_LOG_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_LOG_CACHE_PURGE)   || defined (BASE_TRACE_SMT_LOG_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_LOG_NEW_IN_SCOPE) )
void
smt_log_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "open"; break;
        case 4: method_name = "close"; break;
        case 5: method_name = "set copyto"; break;
        case 6: method_name = "set stderr"; break;
        case 7: method_name = "set raw"; break;
        case 8: method_name = "print"; break;
        case 9: method_name = "write bucket"; break;
        case 10: method_name = "cycle"; break;
        case 11: method_name = "dump"; break;
        case 12: method_name = "dump env"; break;
        case 13: method_name = "selftest"; break;
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
                                   "smt_log %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_log_version_start        = "VeRsIoNsTaRt:ipc";
char *smt_log_component            = "smt_log ";
char *smt_log_version              = "1.0 ";
char *smt_log_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_log_filename             = "smt_log.icl ";
char *smt_log_builddate            = "2009/02/19 ";
char *smt_log_version_end          = "VeRsIoNeNd:ipc";

