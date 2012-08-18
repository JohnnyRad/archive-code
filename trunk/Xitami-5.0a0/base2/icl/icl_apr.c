/*---------------------------------------------------------------------------
    icl_apr.c - icl_apr component

    Provides iCL wrappers for some APR functions.
    Generated from icl_apr.icl by icl_gen using GSL/4.
    
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
#include "icl_apr.h"                    //  Definitions for our class

//  Shorthands for class methods                                               

#define self_apr_assert     icl_apr_assert
#define self_apr_error_print  icl_apr_error_print
#define self_atomic_inc32   icl_atomic_inc32
#define self_atomic_dec32   icl_atomic_dec32
#define self_atomic_get32   icl_atomic_get32
#define self_atomic_set32   icl_atomic_set32
#define self_atomic_add32   icl_atomic_add32
#define self_atomic_sub32   icl_atomic_sub32
#define self_atomic_cas32   icl_atomic_cas32
#define self_atomic_casptr  icl_atomic_casptr
#define self_atomic_swap    icl_atomic_swap
#define self_selftest       icl_selftest
#define self_show_animation  icl_show_animation

Bool
    icl_apr_animating = TRUE;           //  Animation enabled by default
//  Global variables                                                           

apr_pool_t *
    icl_global_pool = NULL;
apr_allocator_t *
    icl_global_allocator = NULL;

#if (defined (BASE_THREADSAFE))
apr_thread_mutex_t *
    icl_global_mutex = NULL;
apr_thread_mutex_t *
    icl_global_allocator_mutex = NULL;
#endif
/*  -------------------------------------------------------------------------
    icl_apr_error_print

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_apr_error_print_ (
    apr_status_t status,                //  The status code to print
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
char
    buffer [128];

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_APR)  ||  defined (BASE_ANIMATE_ICL_APR_APR_ERROR_PRINT))
    if (icl_apr_animating)
        icl_console_print ("<icl_apr_apr_error_print_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_APR_ERROR_PRINT))
    icl_trace_record (NULL, icl_apr_dump, 2);
#endif

icl_console_print ("(%s %lu) %s", file, (long) line, apr_strerror (status, buffer, 128));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_APR_ERROR_PRINT))
    icl_trace_record (NULL, icl_apr_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_APR)   || defined (BASE_ANIMATE_ICL_APR_APR_ERROR_PRINT))
    if (icl_apr_animating)
        icl_console_print ("<icl_apr_apr_error_print_finish"
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

}
/*  -------------------------------------------------------------------------
    icl_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_APR)  ||  defined (BASE_ANIMATE_ICL_APR_SELFTEST))
    if (icl_apr_animating)
        icl_console_print ("<icl_apr_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_SELFTEST))
    icl_trace_record (NULL, icl_apr_dump, 12);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_SELFTEST))
    icl_trace_record (NULL, icl_apr_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_APR)   || defined (BASE_ANIMATE_ICL_APR_SELFTEST))
    if (icl_apr_animating)
        icl_console_print ("<icl_apr_selftest_finish"
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
    icl_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_APR)  ||  defined (BASE_ANIMATE_ICL_APR_SHOW_ANIMATION))
    if (icl_apr_animating)
        icl_console_print ("<icl_apr_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_apr_dump, 13);
#endif

icl_apr_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_apr_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_APR)   || defined (BASE_ANIMATE_ICL_APR_SHOW_ANIMATION))
    if (icl_apr_animating)
        icl_console_print ("<icl_apr_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_APR)   || defined (BASE_TRACE_ICL_APR_APR_ASSERT)   || defined (BASE_TRACE_ICL_APR_APR_ERROR_PRINT)   || defined (BASE_TRACE_ICL_APR_ATOMIC_INC32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_DEC32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_GET32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_SET32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_ADD32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_SUB32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_CAS32)   || defined (BASE_TRACE_ICL_APR_ATOMIC_CASPTR)   || defined (BASE_TRACE_ICL_APR_ATOMIC_SWAP)   || defined (BASE_TRACE_ICL_APR_SELFTEST)   || defined (BASE_TRACE_ICL_APR_SHOW_ANIMATION) )
void
icl_apr_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "apr assert"; break;
        case 2: method_name = "apr error print"; break;
        case 3: method_name = "atomic inc32"; break;
        case 4: method_name = "atomic dec32"; break;
        case 5: method_name = "atomic get32"; break;
        case 6: method_name = "atomic set32"; break;
        case 7: method_name = "atomic add32"; break;
        case 8: method_name = "atomic sub32"; break;
        case 9: method_name = "atomic cas32"; break;
        case 10: method_name = "atomic casptr"; break;
        case 11: method_name = "atomic swap"; break;
        case 12: method_name = "selftest"; break;
        case 13: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_apr %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_apr_version_start        = "VeRsIoNsTaRt:ipc";
char *icl_apr_component            = "icl_apr ";
char *icl_apr_version              = "1.1 ";
char *icl_apr_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_apr_filename             = "icl_apr.icl ";
char *icl_apr_builddate            = "2009/02/19 ";
char *icl_apr_version_end          = "VeRsIoNeNd:ipc";

