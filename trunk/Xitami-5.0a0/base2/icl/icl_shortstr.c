/*---------------------------------------------------------------------------
    icl_shortstr.c - icl_shortstr component

    We define the icl_shortstr_t type in order to provide a simple way of
    storing and serialising short strings.  A "short string" is defined
    as one that can be serialised as a single-octet length indicator
    plus 0-255 octets of data.  The icl_shortstr_t type is held in memory
    as C-compatible null-terminated char arrays of 255+1 bytes.  There
    are no constructor/destructor methods for icl_shortstr_t variables since
    this would create incompatabilities with normal C strings.  See the
    selftest method for examples of using icl_shortstr_t.  When writing a
    icl_shortstr_t you should always use the icl_shortstr_cpy method to
    avoid the risk of overflows.
    Generated from icl_shortstr.icl by icl_gen using GSL/4.
    
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
#include "icl_shortstr.h"               //  Definitions for our class

//  Shorthands for class methods                                               

#define self_cpy            icl_shortstr_cpy
#define self_cat            icl_shortstr_cat
#define self_ncpy           icl_shortstr_ncpy
#define self_ncat           icl_shortstr_ncat
#define self_fmt            icl_shortstr_fmt
#define self_read           icl_shortstr_read
#define self_selftest       icl_shortstr_selftest
#define self_show_animation  icl_shortstr_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_CPY))
static icl_stats_t *s_icl_shortstr_cpy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_CAT))
static icl_stats_t *s_icl_shortstr_cat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_NCPY))
static icl_stats_t *s_icl_shortstr_ncpy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_NCAT))
static icl_stats_t *s_icl_shortstr_ncat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_FMT))
static icl_stats_t *s_icl_shortstr_fmt_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_READ))
static icl_stats_t *s_icl_shortstr_read_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_SELFTEST))
static icl_stats_t *s_icl_shortstr_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_SHOW_ANIMATION))
static icl_stats_t *s_icl_shortstr_show_animation_stats = NULL;
#endif
Bool
    icl_shortstr_animating = TRUE;      //  Animation enabled by default
/*  -------------------------------------------------------------------------
    icl_shortstr_cpy

    Type: Component method
    Copies data into a specified short string.  Returns the number of chars
    actually copied.  If this is less than strlen (src), the string was
    truncated.  Allows a null source, in which case dest is cleared.
    -------------------------------------------------------------------------
 */

size_t
    icl_shortstr_cpy (
    char * dest,                        //  String to copy into
    char * src                          //  String to copy from
)
{
register char
    *from = src;
register size_t
    remaining;
    size_t
        count;                          //  Number of chars copied

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_CPY))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_cpy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_CPY))
    icl_trace_record (NULL, icl_shortstr_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_CPY))
    icl_stats_inc ("icl_shortstr_cpy", &s_icl_shortstr_cpy_stats);
#endif

if (src) {
    remaining = ICL_SHORTSTR_MAX;
    while (*from && remaining) {
        *dest++ = *from++;
        remaining--;
    }
    *dest = 0;
    count = from - src;
}
else {
    *dest = 0;
    count = 0;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_CPY))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_CPY))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_cpy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
" count=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    icl_shortstr_cat

    Type: Component method
    Appends data onto a specified short string.  Returns the number of
    chars actually copied.  If this is less than strlen (src), the string
    was truncated.  Allows a null src in which case dest is unchanged.
    -------------------------------------------------------------------------
 */

size_t
    icl_shortstr_cat (
    char * dest,                        //  String to copy into
    char * src                          //  String to copy from
)
{
register char
    *from = src;
register size_t
    remaining;
size_t
    dest_len = strlen (dest);
    size_t
        count = 0;                      //  Number of chars copied

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_CAT))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_cat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_CAT))
    icl_trace_record (NULL, icl_shortstr_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_CAT))
    icl_stats_inc ("icl_shortstr_cat", &s_icl_shortstr_cat_stats);
#endif

if (src) {
    dest += dest_len;
    remaining = ICL_SHORTSTR_MAX - dest_len;
    while (*from && remaining) {
        *dest++ = *from++;
        remaining--;
    }
    *dest = 0;
    count = from - src;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_CAT))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_CAT))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_cat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
" count=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    icl_shortstr_ncpy

    Type: Component method
    Copies length-specified data into a specified short string. The source
    string should not contain zero octets. Returns the number of chars
    actually copied.  If this is less than the specified length, the string
    was truncated.  Allows a null source, in which case dest is cleared.
    The resulting string is always null-terminated.
    -------------------------------------------------------------------------
 */

size_t
    icl_shortstr_ncpy (
    char * dest,                        //  String to copy into
    char * src,                         //  String to copy from
    size_t size                         //  Length of source string
)
{
register char
    *from = src;
register size_t
    remaining;
    size_t
        count;                          //  Number of chars copied

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_NCPY))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_ncpy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src, size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_NCPY))
    icl_trace_record (NULL, icl_shortstr_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_NCPY))
    icl_stats_inc ("icl_shortstr_ncpy", &s_icl_shortstr_ncpy_stats);
#endif

if (src) {
    remaining = ICL_SHORTSTR_MAX;
    while (*from && remaining && size) {
        *dest++ = *from++;
        remaining--;
        size--;
    }
    *dest = 0;
    count = from - src;
}
else {
    *dest = 0;
    count = 0;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_NCPY))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_NCPY))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_ncpy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
" size=\"%u\""
" count=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src, size, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    icl_shortstr_ncat

    Type: Component method
    Appends length-specified data onto a specified short string.  The source
    stringh should not contain zero octets.  Returns the number of chars
    actually copied.  If this is less than the specified length, the string
    was truncated.  Allows a null src in which case dest is unchanged.  The
    resulting string is always null-terminated.
    -------------------------------------------------------------------------
 */

size_t
    icl_shortstr_ncat (
    char * dest,                        //  String to copy into
    char * src,                         //  String to copy from
    size_t size                         //  Length of source string
)
{
register char
    *from = src;
register size_t
    remaining;
size_t
    dest_len = strlen (dest);
    size_t
        count = 0;                      //  Number of chars copied

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_NCAT))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_ncat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src, size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_NCAT))
    icl_trace_record (NULL, icl_shortstr_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_NCAT))
    icl_stats_inc ("icl_shortstr_ncat", &s_icl_shortstr_ncat_stats);
#endif

if (src) {
    dest += dest_len;
    remaining = ICL_SHORTSTR_MAX - dest_len;
    while (*from && remaining && size) {
        *dest++ = *from++;
        remaining--;
        size--;
    }
    *dest = 0;
    count = from - src;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_NCAT))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_NCAT))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_ncat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" src=\"%s\""
" size=\"%u\""
" count=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, src, size, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    icl_shortstr_fmt

    Type: Component method
    Formats an icl_shortstr_t with the specified format and arguments.
    Returns the destination string.
    -------------------------------------------------------------------------
 */

char *
    icl_shortstr_fmt (
    char * dest,                        //  String to format into
    char * format,                      //  Format specifier
...                                     //  Variable arguments
)
{
    char *
        _rc;
    va_list
        args;
    va_start (args, format);
    _rc = icl_shortstr_fmt_v (dest, format, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    icl_shortstr_fmt_v

    Type: Component method
    Formats an icl_shortstr_t with the specified format and arguments.
    Returns the destination string.
    -------------------------------------------------------------------------
 */

char *
    icl_shortstr_fmt_v (
    char * dest,                        //  String to format into
    char * format,                      //  Format specifier
va_list args                            //  Variable arguments
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_FMT))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_fmt_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, format);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_FMT))
    icl_trace_record (NULL, icl_shortstr_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_FMT))
    icl_stats_inc ("icl_shortstr_fmt", &s_icl_shortstr_fmt_stats);
#endif

apr_vsnprintf (dest, ICL_SHORTSTR_MAX, format, args);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_FMT))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_FMT))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_fmt_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" dest=\"%s\""
" format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, dest, format);
#endif


    return (dest);
}
/*  -------------------------------------------------------------------------
    icl_shortstr_read

    Type: Component method
    Reads a short line of text from an open text file.  If the
    line is more than ICL_SHORTSTR_MAX characters long, it will
    be truncated. Safe to use on DOS or Unix-formatted files.
    -------------------------------------------------------------------------
 */

size_t
    icl_shortstr_read (
    char * string,                      //  Short string to fill
    FILE * file                         //  File to read from
)
{
int
    nextch;                         //  Character read from file
    size_t
        count = 0;                      //  Number of chars read

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_READ))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_read_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" string=\"%s\""
" file=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, string, file);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_READ))
    icl_trace_record (NULL, icl_shortstr_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_READ))
    icl_stats_inc ("icl_shortstr_read", &s_icl_shortstr_read_stats);
#endif

FOREVER {
    nextch = fgetc (file);
    if (nextch == 13)             
        continue;                   //  Ignore DOS CR
    else
    if (nextch == 10                //  Have end of line
    ||  nextch == EOF               //    or end of file
    ||  nextch == 26) {             //    or DOS Ctrl-Z
        string [count] = 0;         //  Terminate string
        break;
    }
    else {
        string [count++] = (char) nextch;
        if (count == ICL_SHORTSTR_MAX) {
            string [count] = 0;
            break;                  //  Oversized string
        }
    }
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_READ))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_READ))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_read_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" string=\"%s\""
" file=\"%pp\""
" count=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, string, file, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    icl_shortstr_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_shortstr_selftest (
void)
{
icl_shortstr_t
    sstr;                           //  Short string for tutorial
size_t
    length;                         //  Number of characters in string
icl_shortstr_t
    string1,                        //  Test string
    string2;                        //  Test string

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_SELFTEST))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_SELFTEST))
    icl_trace_record (NULL, icl_shortstr_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_SELFTEST))
    icl_stats_inc ("icl_shortstr_selftest", &s_icl_shortstr_selftest_stats);
#endif

//  The cpy method sets the string and returns its new size
length = icl_shortstr_cpy (sstr, "hello world\n");

//  The cat method returns the number of characters appended
length += icl_shortstr_cat (sstr, "goodbye world!\n");

assert (streq  (sstr, "hello world\ngoodbye world!\n"));
assert (strlen (sstr) == length);

//  The ncpy and ncat methods can be used to copy just part of a string
length  = icl_shortstr_ncpy (sstr, "Help!", 3);
length += icl_shortstr_ncat (sstr, "local", 2);

assert (streq  (sstr, "Hello"));
assert (strlen (sstr) == length);

//- Regression testing starts here ---------------------------------------

//  Check that the cat method does not overflow
icl_shortstr_cpy (string1, "...............X...............X...............X...............A");
icl_shortstr_cat (string1, "...............X...............X...............X...............B");
icl_shortstr_cat (string1, "...............X...............X...............X...............C");
icl_shortstr_cat (string1, "...............X...............X...............X...............D");
icl_shortstr_cat (string1, "...............X...............X...............X...............E");
assert (strlen (string1) == ICL_SHORTSTR_MAX);

//  Copy the truncated shortstr to another shortstr
icl_shortstr_cpy (string2, string1);
icl_shortstr_cat (string2, "*****************");
assert (strlen (string2) == ICL_SHORTSTR_MAX);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_SELFTEST))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_SELFTEST))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_selftest_finish"
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
    icl_shortstr_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_shortstr_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR)  ||  defined (BASE_ANIMATE_ICL_SHORTSTR_SHOW_ANIMATION))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_shortstr_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_SHORTSTR)  ||  defined (BASE_STATS_ICL_SHORTSTR_SHOW_ANIMATION))
    icl_stats_inc ("icl_shortstr_show_animation", &s_icl_shortstr_show_animation_stats);
#endif

icl_shortstr_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_shortstr_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_SHORTSTR)   || defined (BASE_ANIMATE_ICL_SHORTSTR_SHOW_ANIMATION))
    if (icl_shortstr_animating)
        icl_console_print ("<icl_shortstr_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_SHORTSTR)   || defined (BASE_TRACE_ICL_SHORTSTR_CPY)   || defined (BASE_TRACE_ICL_SHORTSTR_CAT)   || defined (BASE_TRACE_ICL_SHORTSTR_NCPY)   || defined (BASE_TRACE_ICL_SHORTSTR_NCAT)   || defined (BASE_TRACE_ICL_SHORTSTR_FMT)   || defined (BASE_TRACE_ICL_SHORTSTR_READ)   || defined (BASE_TRACE_ICL_SHORTSTR_SELFTEST)   || defined (BASE_TRACE_ICL_SHORTSTR_SHOW_ANIMATION) )
void
icl_shortstr_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "cpy"; break;
        case 2: method_name = "cat"; break;
        case 3: method_name = "ncpy"; break;
        case 4: method_name = "ncat"; break;
        case 5: method_name = "fmt"; break;
        case 6: method_name = "read"; break;
        case 7: method_name = "selftest"; break;
        case 8: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_shortstr %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_shortstr_version_start   = "VeRsIoNsTaRt:ipc";
char *icl_shortstr_component       = "icl_shortstr ";
char *icl_shortstr_version         = "1.1 ";
char *icl_shortstr_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_shortstr_filename        = "icl_shortstr.icl ";
char *icl_shortstr_builddate       = "2009/02/19 ";
char *icl_shortstr_version_end     = "VeRsIoNeNd:ipc";

