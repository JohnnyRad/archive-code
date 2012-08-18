/*---------------------------------------------------------------------------
    ipr_log.c - ipr_log component

    Generated from ipr_log.icl by icl_gen using GSL/4.
    
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
#include "ipr_log.h"                    //  Definitions for our class

//  Shorthands for class methods                                               

#define self_cycle          ipr_log_cycle
#define self_selftest       ipr_log_selftest
#define self_show_animation  ipr_log_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOG)  ||  defined (BASE_STATS_IPR_LOG_CYCLE))
static icl_stats_t *s_ipr_log_cycle_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOG)  ||  defined (BASE_STATS_IPR_LOG_SELFTEST))
static icl_stats_t *s_ipr_log_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOG)  ||  defined (BASE_STATS_IPR_LOG_SHOW_ANIMATION))
static icl_stats_t *s_ipr_log_show_animation_stats = NULL;
#endif
Bool
    ipr_log_animating = TRUE;           //  Animation enabled by default
static void
    s_timestamp_filename (char *stamped_name, char *filename);
/*  -------------------------------------------------------------------------
    ipr_log_cycle

    Type: Component method
    Cycles an application log file:
     - the file must exist
     - if required we move the file to some directory
     - we generate a unique archive name for the file
     - we rename the file to the archive name
     - if required we run a command on the archived file
     - if the file is empty, it is deleted, and not archived
    -------------------------------------------------------------------------
 */

int
    ipr_log_cycle (
    char * filename,                    //  File to examine
    char * directory,                   //  Archive directory, or NULL
    char * command                      //  Command to run
)
{
icl_shortstr_t
    stamped_name,                   //  File name, time-stamped
    destination;                    //  New name of file
ipr_process_t
    *process;                       //  Cycler process
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOG)  ||  defined (BASE_ANIMATE_IPR_LOG_CYCLE))
    if (ipr_log_animating)
        icl_console_print ("<ipr_log_cycle_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" directory=\"%s\""
" command=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, directory, command);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_CYCLE))
    icl_trace_record (NULL, ipr_log_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOG)  ||  defined (BASE_STATS_IPR_LOG_CYCLE))
    icl_stats_inc ("ipr_log_cycle", &s_ipr_log_cycle_stats);
#endif

//

//
assert (filename);
if (ipr_file_exists (filename)) {
    if (ipr_file_size (filename)) {
        icl_shortstr_cpy (destination, filename);
        if (directory) {
            ipr_file_set_path (destination, directory);
            ipr_file_rename (destination, filename);
        }
        s_timestamp_filename (stamped_name, destination);
        rc = ipr_file_rename (stamped_name, destination);
        if (command && *command) {
            icl_shortstr_fmt (destination, "%s %s", command, stamped_name);
            process = ipr_process_new (destination, NULL, NULL, NULL);
            ipr_process_start (process, ".");
            ipr_process_wait  (process, TRUE);
            rc = process->exitcode;
            ipr_process_destroy (&process);
        }
    }
    else
        //  To cycle an empty file, we delete it
        ipr_file_delete (filename);
}
else
    rc = -1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_CYCLE))
    icl_trace_record (NULL, ipr_log_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOG)   || defined (BASE_ANIMATE_IPR_LOG_CYCLE))
    if (ipr_log_animating)
        icl_console_print ("<ipr_log_cycle_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" directory=\"%s\""
" command=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, directory, command, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_log_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_log_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOG)  ||  defined (BASE_ANIMATE_IPR_LOG_SELFTEST))
    if (ipr_log_animating)
        icl_console_print ("<ipr_log_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_SELFTEST))
    icl_trace_record (NULL, ipr_log_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOG)  ||  defined (BASE_STATS_IPR_LOG_SELFTEST))
    icl_stats_inc ("ipr_log_selftest", &s_ipr_log_selftest_stats);
#endif

//
//ipr_log_cycle ("logs/normal.log", "archive", "zip -m packed");
//ipr_log_cycle ("empty.log", "archive", "zip -m packed");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_SELFTEST))
    icl_trace_record (NULL, ipr_log_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOG)   || defined (BASE_ANIMATE_IPR_LOG_SELFTEST))
    if (ipr_log_animating)
        icl_console_print ("<ipr_log_selftest_finish"
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
    ipr_log_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_log_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_LOG)  ||  defined (BASE_ANIMATE_IPR_LOG_SHOW_ANIMATION))
    if (ipr_log_animating)
        icl_console_print ("<ipr_log_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_log_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_LOG)  ||  defined (BASE_STATS_IPR_LOG_SHOW_ANIMATION))
    icl_stats_inc ("ipr_log_show_animation", &s_ipr_log_show_animation_stats);
#endif

ipr_log_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_log_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_LOG)   || defined (BASE_ANIMATE_IPR_LOG_SHOW_ANIMATION))
    if (ipr_log_animating)
        icl_console_print ("<ipr_log_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_LOG)   || defined (BASE_TRACE_IPR_LOG_CYCLE)   || defined (BASE_TRACE_IPR_LOG_SELFTEST)   || defined (BASE_TRACE_IPR_LOG_SHOW_ANIMATION) )
void
ipr_log_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "cycle"; break;
        case 2: method_name = "selftest"; break;
        case 3: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_log %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Add current date and time to filename, before extension
static void
s_timestamp_filename (char *stamped_name, char *filename)
{
    char
        *extension,
        *end_of_name;
    icl_shortstr_t
        suffix;
    apr_time_t
        time_now;
    apr_time_exp_t
        time_exp;
    int
        instance = 0;

    //  Get base filename up to extension
    extension = strchr (filename, '.');
    if (extension)
        icl_shortstr_ncpy (stamped_name, filename, extension - filename);
    else
        icl_shortstr_cpy (stamped_name, filename);

    time_now = apr_time_now ();
    assert (apr_time_exp_lt (&time_exp, time_now) == APR_SUCCESS);
    icl_shortstr_fmt (suffix, "-%04d%02d%02d-%02d%02d%02d", 
        time_exp.tm_year + 1900, time_exp.tm_mon  + 1, 
        time_exp.tm_mday, time_exp.tm_hour, 
        time_exp.tm_min, time_exp.tm_sec);

    //  Append time stamp to base filename
    icl_shortstr_cat (stamped_name, suffix);

    //  Append extension, if any
    if (extension)
        icl_shortstr_cat (stamped_name, extension);

    end_of_name = stamped_name + strlen (stamped_name);
    while (ipr_file_exists (stamped_name)) {
        *end_of_name = 0;               //  Remove any prior instance
        icl_shortstr_fmt (suffix, "#%d", ++instance);
        icl_shortstr_cat (stamped_name, suffix);
    }
}

//  Embed the version information in the resulting binary                      

char *ipr_log_version_start        = "VeRsIoNsTaRt:ipc";
char *ipr_log_component            = "ipr_log ";
char *ipr_log_version              = "1.0 ";
char *ipr_log_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_log_filename             = "ipr_log.icl ";
char *ipr_log_builddate            = "2009/02/19 ";
char *ipr_log_version_end          = "VeRsIoNeNd:ipc";

