/*---------------------------------------------------------------------------
    icl_longstr.c - icl_longstr component

    We define the icl_longstr_t type in order to provide a secure way of
    storing and serialising long strings.  A "long string" is defined
    as one that can be serialised as a 32-bit length indicator
    plus 0-4Gb-1 octets of data. The icl_longstr_t type is held in memory
    as descriptor consisting of a size field and a data reference.
    Generated from icl_longstr.icl by icl_gen using GSL/4.
    
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
#include "icl_longstr.h"                //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_longstr_t

//  Shorthands for class methods                                               

#define self_new            icl_longstr_new
#define self_destroy        icl_longstr_destroy
#define self_resize         icl_longstr_resize
#define self_eq             icl_longstr_eq
#define self_dup            icl_longstr_dup
#define self_fmt            icl_longstr_fmt
#define self_cat            icl_longstr_cat
#define self_selftest       icl_longstr_selftest
#define self_show_animation  icl_longstr_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_NEW))
static icl_stats_t *s_icl_longstr_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_DESTROY))
static icl_stats_t *s_icl_longstr_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_RESIZE))
static icl_stats_t *s_icl_longstr_resize_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_EQ))
static icl_stats_t *s_icl_longstr_eq_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_DUP))
static icl_stats_t *s_icl_longstr_dup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_FMT))
static icl_stats_t *s_icl_longstr_fmt_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_CAT))
static icl_stats_t *s_icl_longstr_cat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_SELFTEST))
static icl_stats_t *s_icl_longstr_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_SHOW_ANIMATION))
static icl_stats_t *s_icl_longstr_show_animation_stats = NULL;
#endif
Bool
    icl_longstr_animating = TRUE;       //  Animation enabled by default
/*  -------------------------------------------------------------------------
    icl_longstr_new

    Type: Component method
    Creates and initialises a new icl_longstr_t object, returns a
    reference to the created object.
    Allocates an icl_longstr_t block for a specified block of data.  Returns
    a pointer to an allocated icl_longstr_t, or NULL if there was not enough
    memory. If the data_block argument is not null, its contents are copied
    into the newly allocated memory area.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    icl_longstr_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    void * data,                        //  Data to copy
    size_t size                         //  Length of data
)
{
    icl_longstr_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_NEW))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" data=\"%pp\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, data, size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_NEW))
    icl_trace_record (NULL, icl_longstr_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_NEW))
    icl_stats_inc ("icl_longstr_new", &s_icl_longstr_new_stats);
#endif

self = (icl_longstr_t *) icl_mem_alloc_ (sizeof (icl_longstr_t) + size, file, line);
if (self) {
    self->object_tag = ICL_LONGSTR_ALIVE;
    self->max_size = size;
    self->data = (byte *) self + sizeof (icl_longstr_t);
    if (data) {
        self->cur_size = size;
        memcpy (self->data, data, size);
    }
    else
        self->cur_size = 0;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_NEW))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_NEW))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" data=\"%pp\""
" size=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, data, size, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_longstr_destroy

    Type: Component method
    Destroys a icl_longstr_t object. Takes the address of a
    icl_longstr_t reference (a pointer to a pointer) and nullifies the
    reference after use.  Does nothing if the reference is already
    null.
    -------------------------------------------------------------------------
 */

void
    icl_longstr_destroy_ (
    icl_longstr_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    icl_longstr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_DESTROY))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_DESTROY))
    icl_trace_record (NULL, icl_longstr_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_DESTROY))
    icl_stats_inc ("icl_longstr_destroy", &s_icl_longstr_destroy_stats);
#endif

if (self) {
    //  If data was reallocated independently, free it independently
    self->object_tag = ICL_LONGSTR_DEAD;
    if (self->data != (byte *) self + sizeof (icl_longstr_t))
        icl_mem_free (self->data);
    icl_mem_free (self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_DESTROY))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_DESTROY))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_destroy_finish"
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
    icl_longstr_resize

    Type: Component method
    Accepts a icl_longstr_t reference and returns zero in case of success,
    1 in case of errors.
    Increases or decreases the allocated size of the string as requested
    by the size argument.  Sets the max_size property to size, and the
    cur_size property to zero.
    -------------------------------------------------------------------------
 */

int
    icl_longstr_resize_ (
    icl_longstr_t * self,               //  Reference to object
    size_t size,                        //  New length of data
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_RESIZE))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_resize_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_RESIZE))
    icl_trace_record (NULL, icl_longstr_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_RESIZE))
    icl_stats_inc ("icl_longstr_resize", &s_icl_longstr_resize_stats);
#endif

ICL_LONGSTR_ASSERT_SANE (self);
//  If data was reallocated independently, free it independently
if (self->data != (byte *) self + sizeof (icl_longstr_t))
    icl_mem_free (self->data);

self->data = icl_mem_alloc_ (size, file, line);
self->max_size = size;
self->cur_size = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_RESIZE))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_RESIZE))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_resize_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, file, line, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_longstr_eq

    Type: Component method
    Returns TRUE if the two specified longstrings are equal.  Either
    of the strings may be null references.
    -------------------------------------------------------------------------
 */

int
    icl_longstr_eq (
    icl_longstr_t * self,               //  First string
    icl_longstr_t * second              //  String to compare with
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_EQ))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_eq_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" second=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, second);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_EQ))
    icl_trace_record (NULL, icl_longstr_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_EQ))
    icl_stats_inc ("icl_longstr_eq", &s_icl_longstr_eq_stats);
#endif

//
if (self == NULL || second == NULL)
    rc = (self == second);
else {
    ICL_LONGSTR_ASSERT_SANE (self);
    ICL_LONGSTR_ASSERT_SANE (second);
    if (self->cur_size == second->cur_size
    &&  memcmp (self->data, second->data, self->cur_size) == 0)
        rc = TRUE;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_EQ))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_EQ))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_eq_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" second=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, second, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_longstr_dup

    Type: Component method
    Returns a new icl_longstr duplicating the supplied string.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    icl_longstr_dup (
    icl_longstr_t * self                //  Source string
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_DUP))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_dup_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_DUP))
    icl_trace_record (NULL, icl_longstr_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_DUP))
    icl_stats_inc ("icl_longstr_dup", &s_icl_longstr_dup_stats);
#endif

//
if (self) {
    ICL_LONGSTR_ASSERT_SANE (self);
    self = self_new (self->data, self->cur_size);
}
else
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_DUP))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_DUP))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_dup_finish"
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


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_longstr_fmt

    Type: Component method
    Accepts a icl_longstr_t reference and returns zero in case of success,
    1 in case of errors.
    Formats an icl_longstr_t with the specified format and arguments.  If
    the string was too short for the requested output, it is reallocated
    with some elasticity.  Always terminates the longstr data with a null.
    -------------------------------------------------------------------------
 */

int
    icl_longstr_fmt (
    icl_longstr_t * self,               //  Reference to object
    char * format,                      //  Format specifier
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, format);
    _rc = icl_longstr_fmt_v (self, format, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    icl_longstr_fmt_v

    Type: Component method
    Accepts a icl_longstr_t reference and returns zero in case of success,
    1 in case of errors.
    Formats an icl_longstr_t with the specified format and arguments.  If
    the string was too short for the requested output, it is reallocated
    with some elasticity.  Always terminates the longstr data with a null.
    -------------------------------------------------------------------------
 */

int
    icl_longstr_fmt_v (
    icl_longstr_t * self,               //  Reference to object
    char * format,                      //  Format specifier
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_FMT))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_fmt_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_FMT))
    icl_trace_record (NULL, icl_longstr_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_FMT))
    icl_stats_inc ("icl_longstr_fmt", &s_icl_longstr_fmt_stats);
#endif

ICL_LONGSTR_ASSERT_SANE (self);
//
self->cur_size = apr_vsnprintf ((char *) self->data, self->max_size, format, args);
if (self->cur_size >= self->max_size) {
    self_resize (self, self->cur_size * 2);
    self->cur_size = apr_vsnprintf ((char *) self->data, self->max_size, format, args);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_FMT))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_FMT))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_fmt_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" format=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, format, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_longstr_cat

    Type: Component method
    Accepts a icl_longstr_t reference and returns zero in case of success,
    1 in case of errors.
    Appends a formatted string to the specified longstring and updates it
    current size.  The string is automatically resized if needed.
    -------------------------------------------------------------------------
 */

int
    icl_longstr_cat (
    icl_longstr_t * self,               //  Reference to object
    char * format,                      //  Format specifier
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, format);
    _rc = icl_longstr_cat_v (self, format, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    icl_longstr_cat_v

    Type: Component method
    Accepts a icl_longstr_t reference and returns zero in case of success,
    1 in case of errors.
    Appends a formatted string to the specified longstring and updates it
    current size.  The string is automatically resized if needed.
    -------------------------------------------------------------------------
 */

int
    icl_longstr_cat_v (
    icl_longstr_t * self,               //  Reference to object
    char * format,                      //  Format specifier
va_list args                            //  Variable arguments
)
{
size_t
    cat_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_CAT))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_cat_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_CAT))
    icl_trace_record (NULL, icl_longstr_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_CAT))
    icl_stats_inc ("icl_longstr_cat", &s_icl_longstr_cat_stats);
#endif

ICL_LONGSTR_ASSERT_SANE (self);
//
cat_size = apr_vsnprintf (
    (char *) self->data + self->cur_size,
    self->max_size - self->cur_size, format, args);
if (self->cur_size + cat_size >= self->max_size) {
    self_resize (self, (self->cur_size + cat_size) * 2);
    cat_size = apr_vsnprintf (
        (char *) self->data + self->cur_size,
        self->max_size - self->cur_size, format, args);
}
self->cur_size += cat_size;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_CAT))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_CAT))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_cat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" format=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, format, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_longstr_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_longstr_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_SELFTEST))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_SELFTEST))
    icl_trace_record (NULL, icl_longstr_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_SELFTEST))
    icl_stats_inc ("icl_longstr_selftest", &s_icl_longstr_selftest_stats);
#endif

icl_longstr_t
    *longstr;

longstr = icl_longstr_new ("....:....:....:....:", 20);
icl_longstr_cat (longstr, "This is more");
icl_longstr_cat (longstr, "We're now adding a whole lot more");
assert (longstr->cur_size <= longstr->max_size);
icl_longstr_destroy (&longstr);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_SELFTEST))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_SELFTEST))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_selftest_finish"
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
    icl_longstr_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_longstr_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_LONGSTR)  ||  defined (BASE_ANIMATE_ICL_LONGSTR_SHOW_ANIMATION))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_longstr_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_LONGSTR)  ||  defined (BASE_STATS_ICL_LONGSTR_SHOW_ANIMATION))
    icl_stats_inc ("icl_longstr_show_animation", &s_icl_longstr_show_animation_stats);
#endif

icl_longstr_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_longstr_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_LONGSTR)   || defined (BASE_ANIMATE_ICL_LONGSTR_SHOW_ANIMATION))
    if (icl_longstr_animating)
        icl_console_print ("<icl_longstr_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_LONGSTR)   || defined (BASE_TRACE_ICL_LONGSTR_NEW)   || defined (BASE_TRACE_ICL_LONGSTR_DESTROY)   || defined (BASE_TRACE_ICL_LONGSTR_RESIZE)   || defined (BASE_TRACE_ICL_LONGSTR_EQ)   || defined (BASE_TRACE_ICL_LONGSTR_DUP)   || defined (BASE_TRACE_ICL_LONGSTR_FMT)   || defined (BASE_TRACE_ICL_LONGSTR_CAT)   || defined (BASE_TRACE_ICL_LONGSTR_SELFTEST)   || defined (BASE_TRACE_ICL_LONGSTR_SHOW_ANIMATION) )
void
icl_longstr_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "resize"; break;
        case 4: method_name = "eq"; break;
        case 5: method_name = "dup"; break;
        case 6: method_name = "fmt"; break;
        case 7: method_name = "cat"; break;
        case 8: method_name = "selftest"; break;
        case 9: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_longstr %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_longstr_version_start    = "VeRsIoNsTaRt:ipc";
char *icl_longstr_component        = "icl_longstr ";
char *icl_longstr_version          = "1.0a1 ";
char *icl_longstr_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_longstr_filename         = "icl_longstr.icl ";
char *icl_longstr_builddate        = "2009/02/19 ";
char *icl_longstr_version_end      = "VeRsIoNeNd:ipc";

