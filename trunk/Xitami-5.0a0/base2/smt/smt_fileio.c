/*---------------------------------------------------------------------------
    smt_fileio.c - smt_fileio component

    The smt_fileio class is used to create socket objects for use with the
    smt_fileio_request class.
    Generated from smt_fileio.icl by icl_gen using GSL/4.
    
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
#include "smt_fileio.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_fileio_t

//  Shorthands for class methods                                               

#define self_new            smt_fileio_new
#define self_annihilate     smt_fileio_annihilate
#define self_open           smt_fileio_open
#define self_temp           smt_fileio_temp
#define self_eof            smt_fileio_eof
#define self_selftest       smt_fileio_selftest
#define self_terminate      smt_fileio_terminate
#define self_show           smt_fileio_show
#define self_destroy        smt_fileio_destroy
#define self_alloc          smt_fileio_alloc
#define self_free           smt_fileio_free
#define self_cache_initialise  smt_fileio_cache_initialise
#define self_cache_purge    smt_fileio_cache_purge
#define self_cache_terminate  smt_fileio_cache_terminate
#define self_show_animation  smt_fileio_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_NEW))
static icl_stats_t *s_smt_fileio_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_DESTROY))
static icl_stats_t *s_smt_fileio_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_OPEN))
static icl_stats_t *s_smt_fileio_open_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_TEMP))
static icl_stats_t *s_smt_fileio_temp_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_EOF))
static icl_stats_t *s_smt_fileio_eof_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_SELFTEST))
static icl_stats_t *s_smt_fileio_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_TERMINATE))
static icl_stats_t *s_smt_fileio_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_SHOW))
static icl_stats_t *s_smt_fileio_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_DESTROY_PUBLIC))
static icl_stats_t *s_smt_fileio_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_ALLOC))
static icl_stats_t *s_smt_fileio_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_FREE))
static icl_stats_t *s_smt_fileio_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_CACHE_INITIALISE))
static icl_stats_t *s_smt_fileio_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_CACHE_PURGE))
static icl_stats_t *s_smt_fileio_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_CACHE_TERMINATE))
static icl_stats_t *s_smt_fileio_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_SHOW_ANIMATION))
static icl_stats_t *s_smt_fileio_show_animation_stats = NULL;
#endif
#define smt_fileio_new()                smt_fileio_new_ (__FILE__, __LINE__)
static smt_fileio_t *
    smt_fileio_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_fileio_annihilate (
smt_fileio_t * ( * self_p )             //  Reference to object reference
);

#define smt_fileio_alloc()              smt_fileio_alloc_ (__FILE__, __LINE__)
static smt_fileio_t *
    smt_fileio_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_fileio_free (
smt_fileio_t * self                     //  Object reference
);

static void
    smt_fileio_cache_initialise (
void);

static void
    smt_fileio_cache_purge (
void);

static void
    smt_fileio_cache_terminate (
void);

Bool
    smt_fileio_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_fileio_new

    Type: Component method
    Creates and initialises a new smt_fileio_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

static smt_fileio_t *
    smt_fileio_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_fileio_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_NEW))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_NEW))
    icl_trace_record (NULL, smt_fileio_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_NEW))
    icl_stats_inc ("smt_fileio_new", &s_smt_fileio_new_stats);
#endif

    self = smt_fileio_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_FILEIO_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_fileio_show_);
#endif

self->handle  = NULL;
self->io_size = 0;
self->eof     = FALSE;
icl_apr_assert (apr_pool_create (&self->pool, icl_global_pool));
apr_pool_tag (self->pool, "smt_fileio_new");
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_NEW))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_NEW))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_new_finish"
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
    smt_fileio_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_fileio_annihilate (
    smt_fileio_t * ( * self_p )         //  Reference to object reference
)
{

    smt_fileio_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_DESTROY))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_DESTROY))
    icl_trace_record (NULL, smt_fileio_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_DESTROY))
    icl_stats_inc ("smt_fileio_annihilate", &s_smt_fileio_annihilate_stats);
#endif

SMT_FILEIO_ASSERT_SANE (self);

apr_file_close (self->handle);
apr_pool_destroy (self->pool);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_DESTROY))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_DESTROY))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_destroy_finish"
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
    smt_fileio_open

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_fileio_t *
    smt_fileio_open (
    smt_thread_t * thread,              //  Thread to deliver reply to
    const char * path,                  //  The optional path???
    const char * name,                  //  The name of the file to open
    smt_file_mode_e mode,               //  The mode (read/write/append)
    Bool binary,                        //  Open file for binary data?
    smt_event_t event                   //  Event to deliver on open; SMT_NULL_EVENT for simple thread-blocking
)
{
    apr_status_t
        status;
    apr_int32_t
#if (defined (BASE_THREADSAFE))
        flag = APR_XTHREAD;
#else
        flag = 0;
#endif
    smt_fileio_t *
        self;                           //  The fileio item

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_OPEN))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_open_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" path=\"%pp\""
" name=\"%pp\""
" binary=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, path, name, binary);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_OPEN))
    icl_trace_record (NULL, smt_fileio_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_OPEN))
    icl_stats_inc ("smt_fileio_open", &s_smt_fileio_open_stats);
#endif

self = smt_fileio_new ();
switch (mode) {
    case SMT_FILE_READ:   flag = APR_READ;                break;
    case SMT_FILE_WRITE:  flag = APR_WRITE | APR_CREATE;  break;
    case SMT_FILE_APPEND: flag = APR_WRITE | APR_APPEND;  break;
}
if (binary)
    flag |= APR_BINARY;

status = apr_file_open (&self->handle, name, flag,
                        APR_OS_DEFAULT, self->pool);
if (status == APR_SUCCESS)
    thread->result = SMT_OK;
    if (event != SMT_NULL_EVENT)
        smt_thread_set_next_event (thread, event);
else {
    smt_fileio_destroy (&self);
    thread->result = SMT_FILEIO_ERROR;
    thread->error  = status;
    thread->catcher (thread);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_OPEN))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_OPEN))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_open_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" path=\"%pp\""
" name=\"%pp\""
" binary=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, path, name, binary, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_fileio_temp

    Type: Component method
    -------------------------------------------------------------------------
 */

smt_fileio_t *
    smt_fileio_temp (
    smt_thread_t * thread,              //  Thread to deliver reply to
    const char * path,                  //  The optional path???
    Bool binary,                        //  Open file for binary data?
    smt_event_t event                   //  Event to deliver on open; SMT_NULL_EVENT for simple thread-blocking
)
{
    apr_status_t
        status;
    apr_int32_t
#if (defined (BASE_THREADSAFE))
        flag = APR_XTHREAD | APR_CREATE | APR_READ | APR_WRITE | APR_EXCL | APR_DELONCLOSE;
#else
        flag = APR_CREATE | APR_READ | APR_WRITE | APR_EXCL | APR_DELONCLOSE;
#endif
    icl_shortstr_t
        name_template;
    smt_fileio_t *
        self;                           //  The fileio item

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_TEMP))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_temp_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" path=\"%pp\""
" binary=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, path, binary);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_TEMP))
    icl_trace_record (NULL, smt_fileio_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_TEMP))
    icl_stats_inc ("smt_fileio_temp", &s_smt_fileio_temp_stats);
#endif

icl_shortstr_cpy (name_template, (char *) path);
icl_shortstr_cat (name_template, "/tmp_XXXXXX");
self = smt_fileio_new ();
if (binary)
    flag |= APR_BINARY;

status = apr_file_mktemp (&self->handle, name_template, flag, self->pool);
if (status == APR_SUCCESS)
    thread->result = SMT_OK;
    if (event != SMT_NULL_EVENT)
        smt_thread_set_next_event (thread, event);
else {
    smt_fileio_destroy (&self);
    thread->result = SMT_FILEIO_ERROR;
    thread->error  = status;
    thread->catcher (thread);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_TEMP))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_TEMP))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_temp_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" thread=\"%pp\""
" path=\"%pp\""
" binary=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, thread, path, binary, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    smt_fileio_eof

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    smt_fileio_eof (
    smt_fileio_t * self                 //  The fileio item
)
{
    Bool
        rc;                             //  The result code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_EOF))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_eof_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_EOF))
    icl_trace_record (NULL, smt_fileio_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_EOF))
    icl_stats_inc ("smt_fileio_eof", &s_smt_fileio_eof_stats);
#endif

rc = self->eof;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_EOF))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_EOF))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_eof_finish"
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
    smt_fileio_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_fileio_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_SELFTEST))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_SELFTEST))
    icl_trace_record (NULL, smt_fileio_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_SELFTEST))
    icl_stats_inc ("smt_fileio_selftest", &s_smt_fileio_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_SELFTEST))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_SELFTEST))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_selftest_finish"
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
    smt_fileio_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_fileio_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_TERMINATE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_TERMINATE))
    icl_trace_record (NULL, smt_fileio_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_TERMINATE))
    icl_stats_inc ("smt_fileio_terminate", &s_smt_fileio_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_TERMINATE))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_TERMINATE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_terminate_finish"
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
    smt_fileio_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_fileio_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
smt_fileio_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_SHOW))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_SHOW))
    icl_trace_record (NULL, smt_fileio_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_SHOW))
    icl_stats_inc ("smt_fileio_show", &s_smt_fileio_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <smt_fileio file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_SHOW))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_SHOW))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_show_finish"
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
    smt_fileio_destroy

    Type: Component method
    Destroys a smt_fileio_t object. Takes the address of a
    smt_fileio_t reference (a pointer to a pointer) and nullifies the
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
    smt_fileio_destroy_ (
    smt_fileio_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_fileio_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_DESTROY_PUBLIC))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_fileio_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_DESTROY_PUBLIC))
    icl_stats_inc ("smt_fileio_destroy", &s_smt_fileio_destroy_stats);
#endif

if (self) {
    smt_fileio_annihilate (self_p);
    smt_fileio_free ((smt_fileio_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_DESTROY_PUBLIC))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_destroy_public_finish"
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
    smt_fileio_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_fileio_t *
    smt_fileio_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_fileio_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_ALLOC))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_ALLOC))
    icl_trace_record (NULL, smt_fileio_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_ALLOC))
    icl_stats_inc ("smt_fileio_alloc", &s_smt_fileio_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_fileio_cache_initialise ();

self = (smt_fileio_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_ALLOC))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_ALLOC))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_alloc_finish"
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
    smt_fileio_free

    Type: Component method
    Freess a smt_fileio_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_fileio_free (
    smt_fileio_t * self                 //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_FREE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_FREE))
    icl_trace_record (NULL, smt_fileio_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_FREE))
    icl_stats_inc ("smt_fileio_free", &s_smt_fileio_free_stats);
#endif

if (self) {

    self->object_tag = SMT_FILEIO_DEAD;
    icl_mem_free (self);
}
self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_FREE))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_FREE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_free_finish"
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
    smt_fileio_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_fileio_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_CACHE_INITIALISE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_fileio_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_CACHE_INITIALISE))
    icl_stats_inc ("smt_fileio_cache_initialise", &s_smt_fileio_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_fileio_t));
icl_system_register (smt_fileio_cache_purge, smt_fileio_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_CACHE_INITIALISE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_cache_initialise_finish"
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
    smt_fileio_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_fileio_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_CACHE_PURGE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_PURGE))
    icl_trace_record (NULL, smt_fileio_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_CACHE_PURGE))
    icl_stats_inc ("smt_fileio_cache_purge", &s_smt_fileio_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_PURGE))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_CACHE_PURGE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_cache_purge_finish"
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
    smt_fileio_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_fileio_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_CACHE_TERMINATE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_fileio_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_CACHE_TERMINATE))
    icl_stats_inc ("smt_fileio_cache_terminate", &s_smt_fileio_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_CACHE_TERMINATE))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_cache_terminate_finish"
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
    smt_fileio_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_fileio_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_FILEIO)  ||  defined (BASE_ANIMATE_SMT_FILEIO_SHOW_ANIMATION))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_fileio_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_FILEIO)  ||  defined (BASE_STATS_SMT_FILEIO_SHOW_ANIMATION))
    icl_stats_inc ("smt_fileio_show_animation", &s_smt_fileio_show_animation_stats);
#endif

smt_fileio_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_fileio_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_FILEIO)   || defined (BASE_ANIMATE_SMT_FILEIO_SHOW_ANIMATION))
    if (smt_fileio_animating)
        icl_console_print ("<smt_fileio_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_FILEIO)   || defined (BASE_TRACE_SMT_FILEIO_NEW)   || defined (BASE_TRACE_SMT_FILEIO_DESTROY)   || defined (BASE_TRACE_SMT_FILEIO_OPEN)   || defined (BASE_TRACE_SMT_FILEIO_TEMP)   || defined (BASE_TRACE_SMT_FILEIO_EOF)   || defined (BASE_TRACE_SMT_FILEIO_SELFTEST)   || defined (BASE_TRACE_SMT_FILEIO_TERMINATE)   || defined (BASE_TRACE_SMT_FILEIO_SHOW)   || defined (BASE_TRACE_SMT_FILEIO_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_FILEIO_ALLOC)   || defined (BASE_TRACE_SMT_FILEIO_FREE)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_PURGE)   || defined (BASE_TRACE_SMT_FILEIO_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_FILEIO_SHOW_ANIMATION) )
void
smt_fileio_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "open"; break;
        case 4: method_name = "temp"; break;
        case 5: method_name = "eof"; break;
        case 6: method_name = "selftest"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "free"; break;
        case 12: method_name = "cache initialise"; break;
        case 13: method_name = "cache purge"; break;
        case 14: method_name = "cache terminate"; break;
        case 15: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_fileio %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_fileio_version_start     = "VeRsIoNsTaRt:ipc";
char *smt_fileio_component         = "smt_fileio ";
char *smt_fileio_version           = "1.0 ";
char *smt_fileio_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_fileio_filename          = "smt_fileio.icl ";
char *smt_fileio_builddate         = "2009/02/19 ";
char *smt_fileio_version_end       = "VeRsIoNeNd:ipc";

