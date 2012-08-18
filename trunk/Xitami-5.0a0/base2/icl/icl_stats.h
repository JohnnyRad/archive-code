/*---------------------------------------------------------------------------
    icl_stats.h - icl_stats component

    Provides statistical reporting for other classes.
    
    Statistics are held in a shared memory block so they can easily be
    examined from another process, even if the running process is blocked.
    Generated from icl_stats.icl by icl_gen using GSL/4.
    
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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_ICL_STATS_SAFE
#   define INCLUDE_ICL_STATS_SAFE
#   define INCLUDE_ICL_STATS_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_ICL_STATS_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

typedef volatile unsigned int icl_stats_t;
#   ifdef __cplusplus
}
#   endif

#   include "icl_apr.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_STATS_ACTIVE
#   if defined (ICL_IMPORT_ICL_STATS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_ICL_STATS_UNSAFE
#   define INCLUDE_ICL_STATS_UNSAFE
#   define INCLUDE_ICL_STATS_ACTIVE

#   include "icl_apr.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    icl_stats_animating;
#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
icl_stats_t *
    icl_stats_new (
const char * name                       //  The name of the statistic
);

void
    icl_stats_dump (
void);

static inline void
    icl_stats_inc (
const char * name,                      //  The name of the statistic
icl_stats_t ** stat                     //  The statistic to increment
);

static inline void
    icl_stats_dec (
const char * name,                      //  The name of the statistic
icl_stats_t ** stat                     //  The statistic to decrement
);

static inline void
    icl_stats_add (
const char * name,                      //  The name of the statistic
icl_stats_t ** stat,                    //  The statistic to add to
icl_stats_t value                       //  The value to add to the statistic
);

static inline void
    icl_stats_assign (
const char * name,                      //  The name of the statistic
icl_stats_t ** stat,                    //  The statistic to assign to
icl_stats_t value                       //  The value to assign to the statistic
);

static inline void
    icl_stats_max (
const char * name,                      //  The name of the statistic
icl_stats_t ** stat,                    //  The statistic to add to
icl_stats_t value                       //  The value to add to the statistic
);

static inline void
    icl_stats_min (
const char * name,                      //  The name of the statistic
icl_stats_t ** stat,                    //  The statistic to add to
icl_stats_t value                       //  The value to add to the statistic
);

void
    icl_stats_selftest (
void);

void
    icl_stats_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_STATS_ACTIVE
#   if defined (ICL_IMPORT_ICL_STATS_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_ICL_STATS_INLINE)
#   define INCLUDE_ICL_STATS_INLINE
#   define INCLUDE_ICL_STATS_ACTIVE

#   include "icl_apr.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_INITIALISE)   || defined (BASE_TRACE_ICL_STATS_TERMINATE)   || defined (BASE_TRACE_ICL_STATS_NEW)   || defined (BASE_TRACE_ICL_STATS_DUMP)   || defined (BASE_TRACE_ICL_STATS_INC)   || defined (BASE_TRACE_ICL_STATS_DEC)   || defined (BASE_TRACE_ICL_STATS_ADD)   || defined (BASE_TRACE_ICL_STATS_ASSIGN)   || defined (BASE_TRACE_ICL_STATS_MAX)   || defined (BASE_TRACE_ICL_STATS_MIN)   || defined (BASE_TRACE_ICL_STATS_SELFTEST)   || defined (BASE_TRACE_ICL_STATS_SHOW_ANIMATION) )
void
    icl_stats_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

/*  -------------------------------------------------------------------------
    icl_stats_inc

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_stats_inc (
    const char * name,                  //  The name of the statistic
    icl_stats_t ** stat                 //  The statistic to increment
)
{

#if (defined (BASE_ANIMATE_ICL_STATS)  ||  defined (BASE_ANIMATE_ICL_STATS_INC))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_inc_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_INC))
    icl_trace_record (NULL, icl_stats_dump, 5);
#endif

if (!*stat)
    *stat = icl_stats_new (name);
icl_atomic_inc32 (*stat);
#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_INC))
    icl_trace_record (NULL, icl_stats_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE_ICL_STATS)   || defined (BASE_ANIMATE_ICL_STATS_INC))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_inc_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

}
/*  -------------------------------------------------------------------------
    icl_stats_dec

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_stats_dec (
    const char * name,                  //  The name of the statistic
    icl_stats_t ** stat                 //  The statistic to decrement
)
{

#if (defined (BASE_ANIMATE_ICL_STATS)  ||  defined (BASE_ANIMATE_ICL_STATS_DEC))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_dec_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_DEC))
    icl_trace_record (NULL, icl_stats_dump, 6);
#endif

if (!*stat)
    *stat = icl_stats_new (name);
icl_atomic_dec32 (*stat);
#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_DEC))
    icl_trace_record (NULL, icl_stats_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE_ICL_STATS)   || defined (BASE_ANIMATE_ICL_STATS_DEC))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_dec_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

}
/*  -------------------------------------------------------------------------
    icl_stats_add

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_stats_add (
    const char * name,                  //  The name of the statistic
    icl_stats_t ** stat,                //  The statistic to add to
    icl_stats_t value                   //  The value to add to the statistic
)
{

#if (defined (BASE_ANIMATE_ICL_STATS)  ||  defined (BASE_ANIMATE_ICL_STATS_ADD))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_add_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_ADD))
    icl_trace_record (NULL, icl_stats_dump, 7);
#endif

if (!*stat)
    *stat = icl_stats_new (name);
icl_atomic_add32 (*stat, value);
#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_ADD))
    icl_trace_record (NULL, icl_stats_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE_ICL_STATS)   || defined (BASE_ANIMATE_ICL_STATS_ADD))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_add_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

}
/*  -------------------------------------------------------------------------
    icl_stats_assign

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_stats_assign (
    const char * name,                  //  The name of the statistic
    icl_stats_t ** stat,                //  The statistic to assign to
    icl_stats_t value                   //  The value to assign to the statistic
)
{

#if (defined (BASE_ANIMATE_ICL_STATS)  ||  defined (BASE_ANIMATE_ICL_STATS_ASSIGN))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_assign_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_ASSIGN))
    icl_trace_record (NULL, icl_stats_dump, 8);
#endif

if (!*stat)
    *stat = icl_stats_new (name);
icl_atomic_set32 (*stat, value);
#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_ASSIGN))
    icl_trace_record (NULL, icl_stats_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE_ICL_STATS)   || defined (BASE_ANIMATE_ICL_STATS_ASSIGN))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_assign_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

}
/*  -------------------------------------------------------------------------
    icl_stats_max

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_stats_max (
    const char * name,                  //  The name of the statistic
    icl_stats_t ** stat,                //  The statistic to add to
    icl_stats_t value                   //  The value to add to the statistic
)
{
icl_stats_t
    cur_value,
    new_value;

#if (defined (BASE_ANIMATE_ICL_STATS)  ||  defined (BASE_ANIMATE_ICL_STATS_MAX))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_MAX))
    icl_trace_record (NULL, icl_stats_dump, 9);
#endif

if (!*stat)
    *stat = icl_stats_new (name);
cur_value = icl_atomic_get32 (*stat);
while (value > cur_value) {
    new_value = icl_atomic_cas32 (*stat, value, cur_value);
    if (new_value == cur_value)
        cur_value = value;
    else
        cur_value = new_value;
}
#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_MAX))
    icl_trace_record (NULL, icl_stats_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE_ICL_STATS)   || defined (BASE_ANIMATE_ICL_STATS_MAX))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

}
/*  -------------------------------------------------------------------------
    icl_stats_min

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    icl_stats_min (
    const char * name,                  //  The name of the statistic
    icl_stats_t ** stat,                //  The statistic to add to
    icl_stats_t value                   //  The value to add to the statistic
)
{
icl_stats_t
    cur_value,
    new_value;

#if (defined (BASE_ANIMATE_ICL_STATS)  ||  defined (BASE_ANIMATE_ICL_STATS_MIN))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_min_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_MIN))
    icl_trace_record (NULL, icl_stats_dump, 10);
#endif

if (!*stat)
    *stat = icl_stats_new (name);
cur_value = icl_atomic_get32 (*stat);
while (value < cur_value) {
    new_value = icl_atomic_cas32 (*stat, value, cur_value);
    if (cur_value == cur_value)
        cur_value = value;
    else
        cur_value = new_value;
}
#if (defined (BASE_TRACE_ICL_STATS)   || defined (BASE_TRACE_ICL_STATS_MIN))
    icl_trace_record (NULL, icl_stats_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE_ICL_STATS)   || defined (BASE_ANIMATE_ICL_STATS_MIN))
    if (icl_stats_animating)
        icl_console_print ("<icl_stats_min_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%pp\""
" stat=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, stat);
#endif

}
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_ICL_STATS_ACTIVE
#   if defined (ICL_IMPORT_ICL_STATS_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_ICL_STATS_ROOT
#   endif
# endif
#endif
