/*---------------------------------------------------------------------------
    ipr_stat.c - ipr_stat component

    The statistics module is designed to capture information (raw integers)
    and process these into useful information.  The sample size is arbitrarily
    large.  Samples are double-precision floating point.
    Generated from ipr_stat.icl by icl_gen using GSL/4.
    
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
#include "ipr_stat.h"                   //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_stat_t

//  Shorthands for class methods                                               

#define self_new            ipr_stat_new
#define self_record         ipr_stat_record
#define self_min            ipr_stat_min
#define self_max            ipr_stat_max
#define self_count          ipr_stat_count
#define self_sum            ipr_stat_sum
#define self_mean           ipr_stat_mean
#define self_var            ipr_stat_var
#define self_dev            ipr_stat_dev
#define self_selftest       ipr_stat_selftest
#define self_terminate      ipr_stat_terminate
#define self_show           ipr_stat_show
#define self_destroy        ipr_stat_destroy
#define self_annihilate     ipr_stat_annihilate
#define self_alloc          ipr_stat_alloc
#define self_free           ipr_stat_free
#define self_cache_initialise  ipr_stat_cache_initialise
#define self_cache_purge    ipr_stat_cache_purge
#define self_cache_terminate  ipr_stat_cache_terminate
#define self_show_animation  ipr_stat_show_animation
#define self_new_in_scope   ipr_stat_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_NEW))
static icl_stats_t *s_ipr_stat_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_RECORD))
static icl_stats_t *s_ipr_stat_record_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_MIN))
static icl_stats_t *s_ipr_stat_min_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_MAX))
static icl_stats_t *s_ipr_stat_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_COUNT))
static icl_stats_t *s_ipr_stat_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SUM))
static icl_stats_t *s_ipr_stat_sum_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_MEAN))
static icl_stats_t *s_ipr_stat_mean_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_VAR))
static icl_stats_t *s_ipr_stat_var_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_DEV))
static icl_stats_t *s_ipr_stat_dev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SELFTEST))
static icl_stats_t *s_ipr_stat_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_TERMINATE))
static icl_stats_t *s_ipr_stat_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SHOW))
static icl_stats_t *s_ipr_stat_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_stat_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_DESTROY))
static icl_stats_t *s_ipr_stat_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_ALLOC))
static icl_stats_t *s_ipr_stat_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_FREE))
static icl_stats_t *s_ipr_stat_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_CACHE_INITIALISE))
static icl_stats_t *s_ipr_stat_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_CACHE_PURGE))
static icl_stats_t *s_ipr_stat_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_CACHE_TERMINATE))
static icl_stats_t *s_ipr_stat_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SHOW_ANIMATION))
static icl_stats_t *s_ipr_stat_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_stat_new_in_scope_stats = NULL;
#endif
static void
    ipr_stat_annihilate (
ipr_stat_t * ( * self_p )               //  Reference to object reference
);

#define ipr_stat_alloc()                ipr_stat_alloc_ (__FILE__, __LINE__)
static ipr_stat_t *
    ipr_stat_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_stat_free (
ipr_stat_t * self                       //  Object reference
);

static void
    ipr_stat_cache_initialise (
void);

static void
    ipr_stat_cache_purge (
void);

static void
    ipr_stat_cache_terminate (
void);

Bool
    ipr_stat_animating = TRUE;          //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_stat_new

    Type: Component method
    Creates and initialises a new ipr_stat_t object, returns a
    reference to the created object.
    Initialises a new statistics set.
    -------------------------------------------------------------------------
 */

ipr_stat_t *
    ipr_stat_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_stat_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_NEW))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_NEW))
    icl_trace_record (NULL, ipr_stat_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_NEW))
    icl_stats_inc ("ipr_stat_new", &s_ipr_stat_new_stats);
#endif

    self = ipr_stat_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_STAT_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_stat_show_);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_NEW))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_NEW))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_new_finish"
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
    ipr_stat_record

    Type: Component method
    Accepts a ipr_stat_t reference and returns zero in case of success,
    1 in case of errors.
    Records a new sample.  The standard deviation is calculated using Knuth's
    algorithm, from http://en.wikipedia.org/wiki/Algorithms_for_calculating_variance:

        double mean = 0;
        double S = 0;
        long N;
        for N = 1 to data.length
            double delta = data[N] - mean;
            mean = mean + delta / N;
            S = S + delta * ( data[N] - mean ); 
        end for
        return S / ( N - 1 ) // the variance
    -------------------------------------------------------------------------
 */

int
    ipr_stat_record (
    ipr_stat_t * self,                  //  Reference to object
    double value                        //  Sample value
)
{
double
    delta;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_RECORD))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_record_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_RECORD))
    icl_trace_record (NULL, ipr_stat_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_RECORD))
    icl_stats_inc ("ipr_stat_record", &s_ipr_stat_record_stats);
#endif

IPR_STAT_ASSERT_SANE (self);

//
self->sum += value;
self->min  = self->count? min (value, self->min): value;
self->max  = max (value, self->max);
self->count++;

delta = value - self->mean;
self->mean += delta / self->count;
self->sum2 += delta * (value - self->mean);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_RECORD))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_RECORD))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_record_finish"
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
    ipr_stat_min

    Type: Component method
    Returns the minimum sample value.  If the sample size is zero,
    returns zero.
    -------------------------------------------------------------------------
 */

double
    ipr_stat_min (
    ipr_stat_t * self                   //  Reference to object
)
{
    double
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_MIN))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_min_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_MIN))
    icl_trace_record (NULL, ipr_stat_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_MIN))
    icl_stats_inc ("ipr_stat_min", &s_ipr_stat_min_stats);
#endif

IPR_STAT_ASSERT_SANE (self);
//
rc = self->min;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_MIN))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_MIN))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_min_finish"
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_stat_max

    Type: Component method
    Returns the maximum sample value.
    -------------------------------------------------------------------------
 */

double
    ipr_stat_max (
    ipr_stat_t * self                   //  Reference to object
)
{
    double
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_MAX))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_max_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_MAX))
    icl_trace_record (NULL, ipr_stat_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_MAX))
    icl_stats_inc ("ipr_stat_max", &s_ipr_stat_max_stats);
#endif

IPR_STAT_ASSERT_SANE (self);
//
rc = self->max;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_MAX))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_MAX))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_max_finish"
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_stat_count

    Type: Component method
    Accepts a ipr_stat_t reference and returns zero in case of success,
    1 in case of errors.
    Returns the number of samples.
    -------------------------------------------------------------------------
 */

int
    ipr_stat_count (
    ipr_stat_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_COUNT))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_COUNT))
    icl_trace_record (NULL, ipr_stat_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_COUNT))
    icl_stats_inc ("ipr_stat_count", &s_ipr_stat_count_stats);
#endif

IPR_STAT_ASSERT_SANE (self);

//
rc = self->count;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_COUNT))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_COUNT))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_count_finish"
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
    ipr_stat_sum

    Type: Component method
    Returns the sum of all samples.
    -------------------------------------------------------------------------
 */

double
    ipr_stat_sum (
    ipr_stat_t * self                   //  Reference to object
)
{
    double
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_SUM))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_sum_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SUM))
    icl_trace_record (NULL, ipr_stat_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SUM))
    icl_stats_inc ("ipr_stat_sum", &s_ipr_stat_sum_stats);
#endif

IPR_STAT_ASSERT_SANE (self);
//
rc = self->sum;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SUM))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_SUM))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_sum_finish"
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_stat_mean

    Type: Component method
    Returns the mean of the sample set.
    -------------------------------------------------------------------------
 */

double
    ipr_stat_mean (
    ipr_stat_t * self                   //  Reference to object
)
{
    double
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_MEAN))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_mean_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_MEAN))
    icl_trace_record (NULL, ipr_stat_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_MEAN))
    icl_stats_inc ("ipr_stat_mean", &s_ipr_stat_mean_stats);
#endif

IPR_STAT_ASSERT_SANE (self);
//
rc = self->mean;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_MEAN))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_MEAN))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_mean_finish"
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_stat_var

    Type: Component method
    Returns the variance of the sample set.
    -------------------------------------------------------------------------
 */

double
    ipr_stat_var (
    ipr_stat_t * self                   //  Reference to object
)
{
    double
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_VAR))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_var_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_VAR))
    icl_trace_record (NULL, ipr_stat_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_VAR))
    icl_stats_inc ("ipr_stat_var", &s_ipr_stat_var_stats);
#endif

IPR_STAT_ASSERT_SANE (self);
//
rc = self->sum2 / (self->count - 1);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_VAR))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_VAR))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_var_finish"
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_stat_dev

    Type: Component method
    Returns the standard deviation of the sample set.
    -------------------------------------------------------------------------
 */

double
    ipr_stat_dev (
    ipr_stat_t * self                   //  Reference to object
)
{
    double
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_DEV))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_dev_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_DEV))
    icl_trace_record (NULL, ipr_stat_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_DEV))
    icl_stats_inc ("ipr_stat_dev", &s_ipr_stat_dev_stats);
#endif

IPR_STAT_ASSERT_SANE (self);
//
rc = sqrt (self->sum2 / (self->count - 1));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_DEV))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_DEV))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_dev_finish"
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


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_stat_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_stat_selftest (
void)
{
ipr_stat_t
    *stat;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_SELFTEST))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SELFTEST))
    icl_trace_record (NULL, ipr_stat_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SELFTEST))
    icl_stats_inc ("ipr_stat_selftest", &s_ipr_stat_selftest_stats);
#endif

stat = ipr_stat_new ();

ipr_stat_record (stat, 5);
ipr_stat_record (stat, 7);
ipr_stat_record (stat, 8);
ipr_stat_record (stat, 10);
ipr_stat_record (stat, 10);

assert (ipr_stat_count (stat) == 5);
assert (ipr_stat_sum   (stat) == 40);
assert (ipr_stat_min   (stat) == 5);
assert (ipr_stat_max   (stat) == 10);
assert (ipr_stat_mean  (stat) == 8);
assert (ipr_stat_var   (stat) == 4.5);
assert (ipr_stat_dev   (stat) > 2.12);
assert (ipr_stat_dev   (stat) < 2.13);

ipr_stat_destroy (&stat);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SELFTEST))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_SELFTEST))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_selftest_finish"
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
    ipr_stat_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_stat_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_TERMINATE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_TERMINATE))
    icl_trace_record (NULL, ipr_stat_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_TERMINATE))
    icl_stats_inc ("ipr_stat_terminate", &s_ipr_stat_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_TERMINATE))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_TERMINATE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_terminate_finish"
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
    ipr_stat_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_stat_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_stat_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_SHOW))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SHOW))
    icl_trace_record (NULL, ipr_stat_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SHOW))
    icl_stats_inc ("ipr_stat_show", &s_ipr_stat_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_stat file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SHOW))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_SHOW))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_show_finish"
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
    ipr_stat_destroy

    Type: Component method
    Destroys a ipr_stat_t object. Takes the address of a
    ipr_stat_t reference (a pointer to a pointer) and nullifies the
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
    ipr_stat_destroy_ (
    ipr_stat_t * ( * self_p ),          //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_stat_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_DESTROY_PUBLIC))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_stat_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_stat_destroy", &s_ipr_stat_destroy_stats);
#endif

if (self) {
    ipr_stat_annihilate (self_p);
    ipr_stat_free ((ipr_stat_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_DESTROY_PUBLIC))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_destroy_public_finish"
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
    ipr_stat_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_stat_annihilate (
    ipr_stat_t * ( * self_p )           //  Reference to object reference
)
{

    ipr_stat_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_DESTROY))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_DESTROY))
    icl_trace_record (NULL, ipr_stat_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_DESTROY))
    icl_stats_inc ("ipr_stat_annihilate", &s_ipr_stat_annihilate_stats);
#endif

IPR_STAT_ASSERT_SANE (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_DESTROY))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_DESTROY))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_destroy_finish"
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
    ipr_stat_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_stat_t *
    ipr_stat_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_stat_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_ALLOC))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_ALLOC))
    icl_trace_record (NULL, ipr_stat_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_ALLOC))
    icl_stats_inc ("ipr_stat_alloc", &s_ipr_stat_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_stat_cache_initialise ();

self = (ipr_stat_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_stat_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_ALLOC))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_ALLOC))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_alloc_finish"
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
    ipr_stat_free

    Type: Component method
    Freess a ipr_stat_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_stat_free (
    ipr_stat_t * self                   //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_FREE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_FREE))
    icl_trace_record (NULL, ipr_stat_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_FREE))
    icl_stats_inc ("ipr_stat_free", &s_ipr_stat_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_stat_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_stat_t));
        self->object_tag = IPR_STAT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_FREE))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_FREE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_free_finish"
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
    ipr_stat_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_stat_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_CACHE_INITIALISE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_stat_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_CACHE_INITIALISE))
    icl_stats_inc ("ipr_stat_cache_initialise", &s_ipr_stat_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_stat_t));
icl_system_register (ipr_stat_cache_purge, ipr_stat_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_CACHE_INITIALISE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_cache_initialise_finish"
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
    ipr_stat_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_stat_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_CACHE_PURGE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_CACHE_PURGE))
    icl_trace_record (NULL, ipr_stat_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_CACHE_PURGE))
    icl_stats_inc ("ipr_stat_cache_purge", &s_ipr_stat_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_CACHE_PURGE))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_CACHE_PURGE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_cache_purge_finish"
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
    ipr_stat_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_stat_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_CACHE_TERMINATE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_stat_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_CACHE_TERMINATE))
    icl_stats_inc ("ipr_stat_cache_terminate", &s_ipr_stat_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_CACHE_TERMINATE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_cache_terminate_finish"
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
    ipr_stat_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_stat_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_SHOW_ANIMATION))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_stat_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_SHOW_ANIMATION))
    icl_stats_inc ("ipr_stat_show_animation", &s_ipr_stat_show_animation_stats);
#endif

ipr_stat_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_SHOW_ANIMATION))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_show_animation_finish"
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
    ipr_stat_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_stat_new_in_scope_ (
    ipr_stat_t * * self_p,              //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_STAT)  ||  defined (BASE_ANIMATE_IPR_STAT_NEW_IN_SCOPE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_stat_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_STAT)  ||  defined (BASE_STATS_IPR_STAT_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_stat_new_in_scope", &s_ipr_stat_new_in_scope_stats);
#endif

*self_p = ipr_stat_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_stat_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_stat_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_STAT)   || defined (BASE_ANIMATE_IPR_STAT_NEW_IN_SCOPE))
    if (ipr_stat_animating)
        icl_console_print ("<ipr_stat_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_STAT)   || defined (BASE_TRACE_IPR_STAT_NEW)   || defined (BASE_TRACE_IPR_STAT_RECORD)   || defined (BASE_TRACE_IPR_STAT_MIN)   || defined (BASE_TRACE_IPR_STAT_MAX)   || defined (BASE_TRACE_IPR_STAT_COUNT)   || defined (BASE_TRACE_IPR_STAT_SUM)   || defined (BASE_TRACE_IPR_STAT_MEAN)   || defined (BASE_TRACE_IPR_STAT_VAR)   || defined (BASE_TRACE_IPR_STAT_DEV)   || defined (BASE_TRACE_IPR_STAT_SELFTEST)   || defined (BASE_TRACE_IPR_STAT_TERMINATE)   || defined (BASE_TRACE_IPR_STAT_SHOW)   || defined (BASE_TRACE_IPR_STAT_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_STAT_DESTROY)   || defined (BASE_TRACE_IPR_STAT_ALLOC)   || defined (BASE_TRACE_IPR_STAT_FREE)   || defined (BASE_TRACE_IPR_STAT_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_STAT_CACHE_PURGE)   || defined (BASE_TRACE_IPR_STAT_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_STAT_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_STAT_NEW_IN_SCOPE) )
void
ipr_stat_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "record"; break;
        case 3: method_name = "min"; break;
        case 4: method_name = "max"; break;
        case 5: method_name = "count"; break;
        case 6: method_name = "sum"; break;
        case 7: method_name = "mean"; break;
        case 8: method_name = "var"; break;
        case 9: method_name = "dev"; break;
        case 10: method_name = "selftest"; break;
        case 11: method_name = "terminate"; break;
        case 12: method_name = "show"; break;
        case 13: method_name = "destroy public"; break;
        case 14: method_name = "destroy"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "free"; break;
        case 17: method_name = "cache initialise"; break;
        case 18: method_name = "cache purge"; break;
        case 19: method_name = "cache terminate"; break;
        case 20: method_name = "show animation"; break;
        case 21: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_stat %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_stat_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_stat_component           = "ipr_stat ";
char *ipr_stat_version             = "1.0 ";
char *ipr_stat_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_stat_filename            = "ipr_stat.icl ";
char *ipr_stat_builddate           = "2009/02/19 ";
char *ipr_stat_version_end         = "VeRsIoNeNd:ipc";

