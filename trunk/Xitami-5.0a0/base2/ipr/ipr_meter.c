/*---------------------------------------------------------------------------
    ipr_meter.c - ipr_meter component

    The traffic rate meter tracks activity per time segment.
    Generated from ipr_meter.icl by icl_gen using GSL/4.
    
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
#include "ipr_meter.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_meter_t

//  Shorthands for class methods                                               

#define self_count          ipr_meter_count
#define self_mark           ipr_meter_mark
#define self_selftest       ipr_meter_selftest
#define self_terminate      ipr_meter_terminate
#define self_new            ipr_meter_new
#define self_show           ipr_meter_show
#define self_destroy        ipr_meter_destroy
#define self_annihilate     ipr_meter_annihilate
#define self_alloc          ipr_meter_alloc
#define self_free           ipr_meter_free
#define self_cache_initialise  ipr_meter_cache_initialise
#define self_cache_purge    ipr_meter_cache_purge
#define self_cache_terminate  ipr_meter_cache_terminate
#define self_show_animation  ipr_meter_show_animation
#define self_new_in_scope   ipr_meter_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_COUNT))
       icl_stats_t *s_ipr_meter_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_MARK))
static icl_stats_t *s_ipr_meter_mark_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_SELFTEST))
static icl_stats_t *s_ipr_meter_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_TERMINATE))
static icl_stats_t *s_ipr_meter_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_NEW))
static icl_stats_t *s_ipr_meter_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_SHOW))
static icl_stats_t *s_ipr_meter_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_meter_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_DESTROY))
static icl_stats_t *s_ipr_meter_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_ALLOC))
static icl_stats_t *s_ipr_meter_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_FREE))
static icl_stats_t *s_ipr_meter_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_CACHE_INITIALISE))
static icl_stats_t *s_ipr_meter_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_CACHE_PURGE))
static icl_stats_t *s_ipr_meter_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_CACHE_TERMINATE))
static icl_stats_t *s_ipr_meter_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_SHOW_ANIMATION))
static icl_stats_t *s_ipr_meter_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_meter_new_in_scope_stats = NULL;
#endif
static void
    ipr_meter_annihilate (
ipr_meter_t * ( * self_p )              //  Reference to object reference
);

#define ipr_meter_alloc()               ipr_meter_alloc_ (__FILE__, __LINE__)
static ipr_meter_t *
    ipr_meter_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_meter_free (
ipr_meter_t * self                      //  Object reference
);

static void
    ipr_meter_cache_initialise (
void);

static void
    ipr_meter_cache_purge (
void);

static void
    ipr_meter_cache_terminate (
void);

Bool
    ipr_meter_animating = TRUE;         //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_meter_mark

    Type: Component method
    Accepts a ipr_meter_t reference and returns zero in case of success,
    1 in case of errors.
    Returns the current metered rate.  This is calculated by taking the
    difference between the current sample rate and the last measured
    rate and then calculating the average over the history.
    -------------------------------------------------------------------------
 */

int
    ipr_meter_mark (
    ipr_meter_t * self,                 //  Reference to object
    int interval                        //  Interval, in seconds
)
{
uint
    cur_index,
    sample_size;
qbyte
    sample_total;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_MARK))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_mark_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" interval=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, interval);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_MARK))
    icl_trace_record (NULL, ipr_meter_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_MARK))
    icl_stats_inc ("ipr_meter_mark", &s_ipr_meter_mark_stats);
#endif

IPR_METER_ASSERT_SANE (self);

assert (interval);
//
//  Unsigned arithmetic will always give us correct difference
self->current = (self->sample - self->last_sample) / interval;
self->last_sample = self->sample;

//  Ignore meter values of zero
if (self->current) {
    self->history [self->history_index++] = self->current;
    self->history_index = self->history_index % IPR_METER_HISTORY;

    //  Calculate rolling average
    sample_total = 0;
    sample_size  = 0;
    self->maximum = 0;
    for (cur_index = 0; cur_index < IPR_METER_HISTORY; cur_index++) {
        if (self->history [cur_index]) {
            sample_total += self->history [cur_index];
            sample_size++;
            //  Show maximum of last recorded history
            if (self->maximum < self->history [cur_index])
                self->maximum = self->history [cur_index];
        }
    }
    self->average = sample_total / sample_size;
}
rc = (int) self->current;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_MARK))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_MARK))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_mark_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" interval=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, interval, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_meter_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_meter_selftest (
void)
{
ipr_meter_t
    *meter;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_SELFTEST))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_SELFTEST))
    icl_trace_record (NULL, ipr_meter_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_SELFTEST))
    icl_stats_inc ("ipr_meter_selftest", &s_ipr_meter_selftest_stats);
#endif

meter = ipr_meter_new ();

ipr_meter_count (meter);
ipr_meter_count (meter);
ipr_meter_count (meter);
ipr_meter_count (meter);
ipr_meter_count (meter);
ipr_meter_count (meter);

assert (ipr_meter_mark (meter, 1) == 6);
ipr_meter_destroy (&meter);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_SELFTEST))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_SELFTEST))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_selftest_finish"
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
    ipr_meter_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_meter_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_TERMINATE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_TERMINATE))
    icl_trace_record (NULL, ipr_meter_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_TERMINATE))
    icl_stats_inc ("ipr_meter_terminate", &s_ipr_meter_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_TERMINATE))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_TERMINATE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_terminate_finish"
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
    ipr_meter_new

    Type: Component method
    Creates and initialises a new ipr_meter_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_meter_t *
    ipr_meter_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_meter_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_NEW))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_NEW))
    icl_trace_record (NULL, ipr_meter_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_NEW))
    icl_stats_inc ("ipr_meter_new", &s_ipr_meter_new_stats);
#endif

    self = ipr_meter_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_METER_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_meter_show_);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_NEW))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_NEW))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_new_finish"
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
    ipr_meter_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_meter_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_meter_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_SHOW))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_SHOW))
    icl_trace_record (NULL, ipr_meter_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_SHOW))
    icl_stats_inc ("ipr_meter_show", &s_ipr_meter_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_meter file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_SHOW))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_SHOW))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_show_finish"
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
    ipr_meter_destroy

    Type: Component method
    Destroys a ipr_meter_t object. Takes the address of a
    ipr_meter_t reference (a pointer to a pointer) and nullifies the
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
    ipr_meter_destroy_ (
    ipr_meter_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_meter_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_DESTROY_PUBLIC))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_meter_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_meter_destroy", &s_ipr_meter_destroy_stats);
#endif

if (self) {
    ipr_meter_annihilate (self_p);
    ipr_meter_free ((ipr_meter_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_DESTROY_PUBLIC))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_destroy_public_finish"
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
    ipr_meter_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_meter_annihilate (
    ipr_meter_t * ( * self_p )          //  Reference to object reference
)
{

    ipr_meter_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_DESTROY))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_DESTROY))
    icl_trace_record (NULL, ipr_meter_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_DESTROY))
    icl_stats_inc ("ipr_meter_annihilate", &s_ipr_meter_annihilate_stats);
#endif

IPR_METER_ASSERT_SANE (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_DESTROY))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_DESTROY))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_destroy_finish"
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
    ipr_meter_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_meter_t *
    ipr_meter_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_meter_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_ALLOC))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_ALLOC))
    icl_trace_record (NULL, ipr_meter_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_ALLOC))
    icl_stats_inc ("ipr_meter_alloc", &s_ipr_meter_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_meter_cache_initialise ();

self = (ipr_meter_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_meter_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_ALLOC))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_ALLOC))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_alloc_finish"
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
    ipr_meter_free

    Type: Component method
    Freess a ipr_meter_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_meter_free (
    ipr_meter_t * self                  //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_FREE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_FREE))
    icl_trace_record (NULL, ipr_meter_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_FREE))
    icl_stats_inc ("ipr_meter_free", &s_ipr_meter_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_meter_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_meter_t));
        self->object_tag = IPR_METER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_FREE))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_FREE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_free_finish"
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
    ipr_meter_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_meter_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_CACHE_INITIALISE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_meter_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_CACHE_INITIALISE))
    icl_stats_inc ("ipr_meter_cache_initialise", &s_ipr_meter_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_meter_t));
icl_system_register (ipr_meter_cache_purge, ipr_meter_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_CACHE_INITIALISE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_cache_initialise_finish"
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
    ipr_meter_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_meter_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_CACHE_PURGE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_CACHE_PURGE))
    icl_trace_record (NULL, ipr_meter_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_CACHE_PURGE))
    icl_stats_inc ("ipr_meter_cache_purge", &s_ipr_meter_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_CACHE_PURGE))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_CACHE_PURGE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_cache_purge_finish"
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
    ipr_meter_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_meter_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_CACHE_TERMINATE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_meter_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_CACHE_TERMINATE))
    icl_stats_inc ("ipr_meter_cache_terminate", &s_ipr_meter_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_CACHE_TERMINATE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_cache_terminate_finish"
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
    ipr_meter_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_meter_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_SHOW_ANIMATION))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_meter_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_SHOW_ANIMATION))
    icl_stats_inc ("ipr_meter_show_animation", &s_ipr_meter_show_animation_stats);
#endif

ipr_meter_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_SHOW_ANIMATION))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_show_animation_finish"
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
    ipr_meter_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_meter_new_in_scope_ (
    ipr_meter_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_METER)  ||  defined (BASE_ANIMATE_IPR_METER_NEW_IN_SCOPE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_meter_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_METER)  ||  defined (BASE_STATS_IPR_METER_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_meter_new_in_scope", &s_ipr_meter_new_in_scope_stats);
#endif

*self_p = ipr_meter_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_meter_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_meter_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_METER)   || defined (BASE_ANIMATE_IPR_METER_NEW_IN_SCOPE))
    if (ipr_meter_animating)
        icl_console_print ("<ipr_meter_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_METER)   || defined (BASE_TRACE_IPR_METER_COUNT)   || defined (BASE_TRACE_IPR_METER_MARK)   || defined (BASE_TRACE_IPR_METER_SELFTEST)   || defined (BASE_TRACE_IPR_METER_TERMINATE)   || defined (BASE_TRACE_IPR_METER_NEW)   || defined (BASE_TRACE_IPR_METER_SHOW)   || defined (BASE_TRACE_IPR_METER_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_METER_DESTROY)   || defined (BASE_TRACE_IPR_METER_ALLOC)   || defined (BASE_TRACE_IPR_METER_FREE)   || defined (BASE_TRACE_IPR_METER_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_METER_CACHE_PURGE)   || defined (BASE_TRACE_IPR_METER_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_METER_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_METER_NEW_IN_SCOPE) )
void
ipr_meter_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "count"; break;
        case 2: method_name = "mark"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "terminate"; break;
        case 5: method_name = "new"; break;
        case 6: method_name = "show"; break;
        case 7: method_name = "destroy public"; break;
        case 8: method_name = "destroy"; break;
        case 9: method_name = "alloc"; break;
        case 10: method_name = "free"; break;
        case 11: method_name = "cache initialise"; break;
        case 12: method_name = "cache purge"; break;
        case 13: method_name = "cache terminate"; break;
        case 14: method_name = "show animation"; break;
        case 15: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_meter %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_meter_version_start      = "VeRsIoNsTaRt:ipc";
char *ipr_meter_component          = "ipr_meter ";
char *ipr_meter_version            = "1.0 ";
char *ipr_meter_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_meter_filename           = "ipr_meter.icl ";
char *ipr_meter_builddate          = "2009/02/19 ";
char *ipr_meter_version_end        = "VeRsIoNeNd:ipc";

