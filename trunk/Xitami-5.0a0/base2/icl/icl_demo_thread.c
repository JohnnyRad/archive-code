/*---------------------------------------------------------------------------
    icl_demo_thread.c - icl_demo_thread component

    Tests and demonstrates the iCL class framework.  This class creates
    a file object that you can open, close, and work with.
    Generated from icl_demo_thread.icl by icl_gen using GSL/4.
    
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
#include "icl_demo_thread.h"            //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_demo_thread_t

//  Shorthands for class methods                                               

#define self_new            icl_demo_thread_new
#define self_annihilate     icl_demo_thread_annihilate
#define self_selftest       icl_demo_thread_selftest
#define self_start          icl_demo_thread_start
#define self_join           icl_demo_thread_join
#define self_free           icl_demo_thread_free
#define self_terminate      icl_demo_thread_terminate
#define self_show           icl_demo_thread_show
#define self_destroy        icl_demo_thread_destroy
#define self_alloc          icl_demo_thread_alloc
#define self_link           icl_demo_thread_link
#define self_unlink         icl_demo_thread_unlink
#define self_show_animation  icl_demo_thread_show_animation
#define self_new_in_scope   icl_demo_thread_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_NEW))
static icl_stats_t *s_icl_demo_thread_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_DESTROY))
static icl_stats_t *s_icl_demo_thread_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_SELFTEST))
static icl_stats_t *s_icl_demo_thread_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_START))
static icl_stats_t *s_icl_demo_thread_start_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_JOIN))
static icl_stats_t *s_icl_demo_thread_join_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_FREE))
static icl_stats_t *s_icl_demo_thread_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_TERMINATE))
static icl_stats_t *s_icl_demo_thread_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_SHOW))
static icl_stats_t *s_icl_demo_thread_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_DESTROY_PUBLIC))
static icl_stats_t *s_icl_demo_thread_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_ALLOC))
static icl_stats_t *s_icl_demo_thread_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_LINK))
static icl_stats_t *s_icl_demo_thread_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_UNLINK))
static icl_stats_t *s_icl_demo_thread_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_SHOW_ANIMATION))
static icl_stats_t *s_icl_demo_thread_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_NEW_IN_SCOPE))
static icl_stats_t *s_icl_demo_thread_new_in_scope_stats = NULL;
#endif
#define icl_demo_thread_annihilate(self)  icl_demo_thread_annihilate_ (self, __FILE__, __LINE__)
static void
    icl_demo_thread_annihilate_ (
icl_demo_thread_t * ( * self_p ),       //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define icl_demo_thread_free(self)      icl_demo_thread_free_ (self, __FILE__, __LINE__)
static void
    icl_demo_thread_free_ (
icl_demo_thread_t * self,               //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define icl_demo_thread_alloc()         icl_demo_thread_alloc_ (__FILE__, __LINE__)
static icl_demo_thread_t *
    icl_demo_thread_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

Bool
    icl_demo_thread_animating = TRUE;   //  Animation enabled by default

void * APR_THREAD_FUNC s_test (apr_thread_t *apr_thread, void * data);
/*  -------------------------------------------------------------------------
    icl_demo_thread_new

    Type: Component method
    Creates and initialises a new icl_demo_thread_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_demo_thread_t *
    icl_demo_thread_new_ (
    char * file,                        //  Source file for callSource file for call
    size_t line,                        //  Line number for callLine number for call
    apr_thread_start_t startup,         //  Function to start the new thread
    char * text                         //  Not documented
)
{
    icl_demo_thread_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_NEW))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_NEW))
    icl_trace_record (NULL, icl_demo_thread_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_NEW))
    icl_stats_inc ("icl_demo_thread_new", &s_icl_demo_thread_new_stats);
#endif

    self = icl_demo_thread_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DEMO_THREAD_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_demo_thread_show_);
#endif

    self->file          = file;
    self->line          = line;
    self->started       = FALSE;
    icl_apr_assert (apr_pool_create (&self->pool, icl_global_pool));
    apr_pool_tag (self->pool, "icl_demo_thread_new");
#if (defined (BASE_THREADSAFE))
    self->threadattr = NULL;
    icl_apr_assert (apr_threadattr_create (&self->threadattr, self->pool));
#endif

    self->startup = startup;
    self->text    = icl_mem_strdup (text);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_NEW))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_NEW))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" text=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, text, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_demo_thread_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_thread_annihilate_ (
    icl_demo_thread_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    int
        history_last;
#endif

    icl_demo_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_DESTROY))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_DESTROY))
    icl_trace_record (NULL, icl_demo_thread_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_DESTROY))
    icl_stats_inc ("icl_demo_thread_annihilate", &s_icl_demo_thread_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = self->links;
#endif

    ICL_DEMO_THREAD_ASSERT_SANE (self);

icl_mem_free (self->text);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_DESTROY))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_DESTROY))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_destroy_finish"
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
    icl_demo_thread_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_thread_selftest (
void)
{
icl_demo_thread_t
    *thread_1,
    *thread_2,
    *thread_3,
    *thread_4,
    *thread_5,
    *thread_6,
    *thread_7,
    *thread_8;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_SELFTEST))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SELFTEST))
    icl_trace_record (NULL, icl_demo_thread_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_SELFTEST))
    icl_stats_inc ("icl_demo_thread_selftest", &s_icl_demo_thread_selftest_stats);
#endif

icl_console_mode (ICL_CONSOLE_THREAD, TRUE);

thread_1 = icl_demo_thread_new (s_test, "1");
thread_2 = icl_demo_thread_new (s_test, "2");
thread_3 = icl_demo_thread_new (s_test, "3");
thread_4 = icl_demo_thread_new (s_test, "4");
thread_5 = icl_demo_thread_new (s_test, "5");
thread_6 = icl_demo_thread_new (s_test, "6");
thread_7 = icl_demo_thread_new (s_test, "7");
thread_8 = icl_demo_thread_new (s_test, "8");
icl_demo_thread_start (thread_8);
icl_demo_thread_start (thread_7);
icl_demo_thread_start (thread_6);
icl_demo_thread_start (thread_5);
icl_demo_thread_start (thread_4);
icl_demo_thread_start (thread_3);
icl_demo_thread_start (thread_2);
icl_demo_thread_start (thread_1);

icl_demo_thread_join    (thread_1);
icl_demo_thread_destroy (&thread_1);

icl_demo_thread_join    (thread_2);
icl_demo_thread_destroy (&thread_2);

icl_demo_thread_join    (thread_3);
icl_demo_thread_destroy (&thread_3);

icl_demo_thread_join    (thread_4);
icl_demo_thread_destroy (&thread_4);

icl_demo_thread_join    (thread_5);
icl_demo_thread_destroy (&thread_5);

icl_demo_thread_join    (thread_6);
icl_demo_thread_destroy (&thread_6);

icl_demo_thread_join    (thread_7);
icl_demo_thread_destroy (&thread_7);

icl_demo_thread_join    (thread_8);
icl_demo_thread_destroy (&thread_8);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SELFTEST))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_SELFTEST))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_selftest_finish"
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
    icl_demo_thread_start

    Type: Component method
    Accepts a icl_demo_thread_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_thread_start (
    icl_demo_thread_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_START))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_start_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_START))
    icl_trace_record (NULL, icl_demo_thread_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_START))
    icl_stats_inc ("icl_demo_thread_start", &s_icl_demo_thread_start_stats);
#endif

ICL_DEMO_THREAD_ASSERT_SANE (self);
if (!self->zombie) {

    self->started = TRUE;
#if (defined (BASE_THREADSAFE))
    icl_demo_thread_link (self);        //  OS thread needs its own link
    icl_apr_assert (apr_thread_create (&self->thread, self->threadattr, self->startup, self, self->pool));
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_START))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_START))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_start_finish"
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
    icl_demo_thread_join

    Type: Component method
    Does a 'join' to the thread which waits until the thread terminates.
    
    Don't use 'function' template since it needs to be called with a zombie
    object.
    -------------------------------------------------------------------------
 */

int
    icl_demo_thread_join (
    icl_demo_thread_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_JOIN))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_join_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_JOIN))
    icl_trace_record (NULL, icl_demo_thread_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_JOIN))
    icl_stats_inc ("icl_demo_thread_join", &s_icl_demo_thread_join_stats);
#endif

    ICL_DEMO_THREAD_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    apr_thread_join (&rc, self->thread);
#endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_JOIN))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_JOIN))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_join_finish"
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
    icl_demo_thread_free

    Type: Component method
    Freess a icl_demo_thread_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_thread_free_ (
    icl_demo_thread_t * self,           //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_FREE))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_FREE))
    icl_trace_record (NULL, icl_demo_thread_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_FREE))
    icl_stats_inc ("icl_demo_thread_free", &s_icl_demo_thread_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = self->links;
#endif

apr_pool_destroy (self->pool);
        memset (&self->object_tag, 0, sizeof (icl_demo_thread_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_thread_t));
        self->object_tag = ICL_DEMO_THREAD_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_FREE))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_FREE))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_free_finish"
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
    icl_demo_thread_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_thread_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_TERMINATE))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_TERMINATE))
    icl_trace_record (NULL, icl_demo_thread_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_TERMINATE))
    icl_stats_inc ("icl_demo_thread_terminate", &s_icl_demo_thread_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_TERMINATE))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_TERMINATE))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_terminate_finish"
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
    icl_demo_thread_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_thread_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    icl_demo_thread_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_SHOW))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SHOW))
    icl_trace_record (NULL, icl_demo_thread_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_SHOW))
    icl_stats_inc ("icl_demo_thread_show", &s_icl_demo_thread_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <icl_demo_thread zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    if (self->history_last > ICL_DEMO_THREAD_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ICL_DEMO_THREAD_HISTORY_LENGTH;
        self->history_last %= ICL_DEMO_THREAD_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ICL_DEMO_THREAD_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </icl_demo_thread>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SHOW))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_SHOW))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_show_finish"
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
    icl_demo_thread_destroy

    Type: Component method
    Destroys a icl_demo_thread_t object. Takes the address of a
    icl_demo_thread_t reference (a pointer to a pointer) and nullifies the
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
    icl_demo_thread_destroy_ (
    icl_demo_thread_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_DESTROY_PUBLIC))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_thread_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_DESTROY_PUBLIC))
    icl_stats_inc ("icl_demo_thread_destroy", &s_icl_demo_thread_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        icl_demo_thread_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on icl_demo_thread object");
        icl_demo_thread_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        icl_demo_thread_free_ ((icl_demo_thread_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_DESTROY_PUBLIC))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_destroy_public_finish"
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
    icl_demo_thread_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_thread_t *
    icl_demo_thread_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_demo_thread_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_ALLOC))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_ALLOC))
    icl_trace_record (NULL, icl_demo_thread_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_ALLOC))
    icl_stats_inc ("icl_demo_thread_alloc", &s_icl_demo_thread_alloc_stats);
#endif

self = (icl_demo_thread_t *) icl_mem_alloc_ (sizeof (icl_demo_thread_t), file, line);
if (self)
    memset (self, 0, sizeof (icl_demo_thread_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_ALLOC))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_ALLOC))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_alloc_finish"
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
    icl_demo_thread_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

icl_demo_thread_t *
    icl_demo_thread_link_ (
    icl_demo_thread_t * self,           //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_LINK))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_LINK))
    icl_trace_record (NULL, icl_demo_thread_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_LINK))
    icl_stats_inc ("icl_demo_thread_link", &s_icl_demo_thread_link_stats);
#endif

    if (self) {
        ICL_DEMO_THREAD_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_LINK))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_LINK))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_link_finish"
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
    icl_demo_thread_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    icl_demo_thread_unlink_ (
    icl_demo_thread_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
    int
        history_last;
#endif

    icl_demo_thread_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_UNLINK))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_UNLINK))
    icl_trace_record (NULL, icl_demo_thread_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_UNLINK))
    icl_stats_inc ("icl_demo_thread_unlink", &s_icl_demo_thread_unlink_stats);
#endif

    if (self) {
        ICL_DEMO_THREAD_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on icl_demo_thread object");
            icl_demo_thread_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_THREAD)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ICL_DEMO_THREAD_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            icl_demo_thread_annihilate_ (self_p, file, line);
        icl_demo_thread_free_ ((icl_demo_thread_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_UNLINK))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_UNLINK))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_unlink_finish"
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
    icl_demo_thread_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_thread_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_SHOW_ANIMATION))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_demo_thread_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_SHOW_ANIMATION))
    icl_stats_inc ("icl_demo_thread_show_animation", &s_icl_demo_thread_show_animation_stats);
#endif

icl_demo_thread_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_SHOW_ANIMATION))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_show_animation_finish"
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
    icl_demo_thread_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_thread_new_in_scope_ (
    icl_demo_thread_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for callSource file for call
    size_t line,                        //  Line number for callLine number for call
    apr_thread_start_t startup,         //  Function to start the new thread
    char * text                         //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD)  ||  defined (BASE_ANIMATE_ICL_DEMO_THREAD_NEW_IN_SCOPE))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_thread_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_THREAD)  ||  defined (BASE_STATS_ICL_DEMO_THREAD_NEW_IN_SCOPE))
    icl_stats_inc ("icl_demo_thread_new_in_scope", &s_icl_demo_thread_new_in_scope_stats);
#endif

*self_p = icl_demo_thread_new_ (file,line,startup,text);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_thread_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_thread_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD)   || defined (BASE_ANIMATE_ICL_DEMO_THREAD_NEW_IN_SCOPE))
    if (icl_demo_thread_animating)
        icl_console_print ("<icl_demo_thread_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" text=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, text, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_THREAD)   || defined (BASE_TRACE_ICL_DEMO_THREAD_NEW)   || defined (BASE_TRACE_ICL_DEMO_THREAD_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_THREAD_START)   || defined (BASE_TRACE_ICL_DEMO_THREAD_JOIN)   || defined (BASE_TRACE_ICL_DEMO_THREAD_FREE)   || defined (BASE_TRACE_ICL_DEMO_THREAD_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SHOW)   || defined (BASE_TRACE_ICL_DEMO_THREAD_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_THREAD_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_THREAD_LINK)   || defined (BASE_TRACE_ICL_DEMO_THREAD_UNLINK)   || defined (BASE_TRACE_ICL_DEMO_THREAD_SHOW_ANIMATION)   || defined (BASE_TRACE_ICL_DEMO_THREAD_NEW_IN_SCOPE) )
void
icl_demo_thread_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "start"; break;
        case 5: method_name = "join"; break;
        case 6: method_name = "free"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "link"; break;
        case 12: method_name = "unlink"; break;
        case 13: method_name = "show animation"; break;
        case 14: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_demo_thread %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

void * APR_THREAD_FUNC
s_test (apr_thread_t *apr_thread, void *data)
{
    icl_demo_thread_t
        *self = data;
    icl_demo_cache_t
        *demo_cache;
    int
        i;

    icl_console_print (self->text);
    for (i = 0; i < 100000; i++) {
        demo_cache = icl_demo_cache_new (NULL,0);
        icl_demo_cache_destroy (&demo_cache);
    }
    icl_console_print (self->text);
    icl_demo_thread_destroy (&self);
    return NULL;
}

//  Embed the version information in the resulting binary                      

char *icl_demo_thread_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_demo_thread_component    = "icl_demo_thread ";
char *icl_demo_thread_version      = "1.1 ";
char *icl_demo_thread_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_demo_thread_filename     = "icl_demo_thread.icl ";
char *icl_demo_thread_builddate    = "2009/02/19 ";
char *icl_demo_thread_version_end  = "VeRsIoNeNd:ipc";

