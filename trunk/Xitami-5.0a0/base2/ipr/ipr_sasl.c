/*---------------------------------------------------------------------------
    ipr_sasl.c - ipr_sasl component

    Provides functions for working with SASL (simple authentication and
    security layer).
    Generated from ipr_sasl.icl by icl_gen using GSL/4.
    
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
#include "ipr_sasl.h"                   //  Definitions for our class

//  Shorthands for class methods                                               

#define self_plain_encode   ipr_sasl_plain_encode
#define self_plain_decode   ipr_sasl_plain_decode
#define self_selftest       ipr_sasl_selftest
#define self_show_animation  ipr_sasl_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_PLAIN_ENCODE))
static icl_stats_t *s_ipr_sasl_plain_encode_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_PLAIN_DECODE))
static icl_stats_t *s_ipr_sasl_plain_decode_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_SELFTEST))
static icl_stats_t *s_ipr_sasl_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_SHOW_ANIMATION))
static icl_stats_t *s_ipr_sasl_show_animation_stats = NULL;
#endif
Bool
    ipr_sasl_animating = TRUE;          //  Animation enabled by default
/*  -------------------------------------------------------------------------
    ipr_sasl_plain_encode

    Type: Component method
    Formats a new authentication data block for a plain login.  The protocol
    uses a SASL-style binary data block for authentication.  This method is
    a simple way of turning a name and password into such a block.  Note
    that plain authentication data is not encrypted and does not provide
    any degree of confidentiality.  The SASL PLAIN mechanism is defined here:
    http://www.ietf.org/internet-drafts/draft-ietf-sasl-plain-08.txt.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    ipr_sasl_plain_encode (
    char * login,                       //  User login name
    char * password                     //  User password
)
{
    icl_longstr_t *
        auth_data;                      //  Authentication data

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SASL)  ||  defined (BASE_ANIMATE_IPR_SASL_PLAIN_ENCODE))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_plain_encode_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" login=\"%s\""
" password=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, login, password);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_PLAIN_ENCODE))
    icl_trace_record (NULL, ipr_sasl_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_PLAIN_ENCODE))
    icl_stats_inc ("ipr_sasl_plain_encode", &s_ipr_sasl_plain_encode_stats);
#endif

//
//  PLAIN format is [null]login[null]password
auth_data = icl_longstr_new (NULL, strlen (login) + strlen (password) + 3);
auth_data->data [0] = 0;
strcpy ((char *) auth_data->data + 1, login);
strcpy ((char *) auth_data->data + 2 + strlen (login), password);

//  Do NOT include final null in binary block size
auth_data->cur_size = strlen (login) + strlen (password) + 2;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_PLAIN_ENCODE))
    icl_trace_record (NULL, ipr_sasl_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SASL)   || defined (BASE_ANIMATE_IPR_SASL_PLAIN_ENCODE))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_plain_encode_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" login=\"%s\""
" password=\"%s\""
" auth_data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, login, password, auth_data);
#endif


    return (auth_data);
}
/*  -------------------------------------------------------------------------
    ipr_sasl_plain_decode

    Type: Component method
    To be done.
    -------------------------------------------------------------------------
 */

int
    ipr_sasl_plain_decode (
    icl_longstr_t * auth_data,          //  Authentication data
    char * login,                       //  User login name
    char * password                     //  User password
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SASL)  ||  defined (BASE_ANIMATE_IPR_SASL_PLAIN_DECODE))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_plain_decode_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" auth_data=\"%pp\""
" login=\"%s\""
" password=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, auth_data, login, password);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_PLAIN_DECODE))
    icl_trace_record (NULL, ipr_sasl_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_PLAIN_DECODE))
    icl_stats_inc ("ipr_sasl_plain_decode", &s_ipr_sasl_plain_decode_stats);
#endif

//
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_PLAIN_DECODE))
    icl_trace_record (NULL, ipr_sasl_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SASL)   || defined (BASE_ANIMATE_IPR_SASL_PLAIN_DECODE))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_plain_decode_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" auth_data=\"%pp\""
" login=\"%s\""
" password=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, auth_data, login, password, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_sasl_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_sasl_selftest (
void)
{
icl_longstr_t
    *auth_data;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SASL)  ||  defined (BASE_ANIMATE_IPR_SASL_SELFTEST))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_SELFTEST))
    icl_trace_record (NULL, ipr_sasl_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_SELFTEST))
    icl_stats_inc ("ipr_sasl_selftest", &s_ipr_sasl_selftest_stats);
#endif

//
auth_data = ipr_sasl_plain_encode ("myname", "mypassword");
assert (auth_data);
icl_longstr_destroy (&auth_data);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_SELFTEST))
    icl_trace_record (NULL, ipr_sasl_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SASL)   || defined (BASE_ANIMATE_IPR_SASL_SELFTEST))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_selftest_finish"
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
    ipr_sasl_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_sasl_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_SASL)  ||  defined (BASE_ANIMATE_IPR_SASL_SHOW_ANIMATION))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_sasl_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_SASL)  ||  defined (BASE_STATS_IPR_SASL_SHOW_ANIMATION))
    icl_stats_inc ("ipr_sasl_show_animation", &s_ipr_sasl_show_animation_stats);
#endif

ipr_sasl_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_sasl_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_SASL)   || defined (BASE_ANIMATE_IPR_SASL_SHOW_ANIMATION))
    if (ipr_sasl_animating)
        icl_console_print ("<ipr_sasl_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_SASL)   || defined (BASE_TRACE_IPR_SASL_PLAIN_ENCODE)   || defined (BASE_TRACE_IPR_SASL_PLAIN_DECODE)   || defined (BASE_TRACE_IPR_SASL_SELFTEST)   || defined (BASE_TRACE_IPR_SASL_SHOW_ANIMATION) )
void
ipr_sasl_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "plain encode"; break;
        case 2: method_name = "plain decode"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_sasl %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_sasl_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_sasl_component           = "ipr_sasl ";
char *ipr_sasl_version             = "1.0 ";
char *ipr_sasl_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_sasl_filename            = "ipr_sasl.icl ";
char *ipr_sasl_builddate           = "2009/02/19 ";
char *ipr_sasl_version_end         = "VeRsIoNeNd:ipc";

