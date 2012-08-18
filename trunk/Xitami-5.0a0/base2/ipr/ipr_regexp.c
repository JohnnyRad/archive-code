/*---------------------------------------------------------------------------
    ipr_regexp.c - ipr_regexp component

    Provides an interface to the PCRE library.  This is a snippet
    from the PCRE documentation:

    There are two different sets of meta-characters: those  that
    are  recognized anywhere in the pattern except within square
    brackets, and those that are recognized in square  brackets.
    Outside square brackets, the meta-characters are as follows:

           general escape character with several uses
    ^      assert start of subject (or line, in multiline mode)
    $      assert end of subject (or line, in multiline mode)
    .      match any character except newline (by default)
    [      start character class definition
    |      start of alternative branch
    (      start subpattern
    )      end subpattern
    ?      extends the meaning of (
           also 0 or 1 quantifier
           also quantifier minimizer
    *      0 or more quantifier
    +      1 or more quantifier
    {      start min/max quantifier

    Part of a pattern that is in square brackets is called a
    "character class".  In a character class the only meta-
    characters are:

           general escape character
    ^      negate the class, but only if the first character
    -      indicates character range
    ]      terminates the character class
    Generated from ipr_regexp.icl by icl_gen using GSL/4.
    
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
#include "ipr_regexp.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_regexp_t

//  Shorthands for class methods                                               

#define self_new            ipr_regexp_new
#define self_annihilate     ipr_regexp_annihilate
#define self_match          ipr_regexp_match
#define self_eq             ipr_regexp_eq
#define self_selftest       ipr_regexp_selftest
#define self_terminate      ipr_regexp_terminate
#define self_show           ipr_regexp_show
#define self_destroy        ipr_regexp_destroy
#define self_alloc          ipr_regexp_alloc
#define self_free           ipr_regexp_free
#define self_read_lock      ipr_regexp_read_lock
#define self_write_lock     ipr_regexp_write_lock
#define self_unlock         ipr_regexp_unlock
#define self_cache_initialise  ipr_regexp_cache_initialise
#define self_cache_purge    ipr_regexp_cache_purge
#define self_cache_terminate  ipr_regexp_cache_terminate
#define self_show_animation  ipr_regexp_show_animation
#define self_new_in_scope   ipr_regexp_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_NEW))
static icl_stats_t *s_ipr_regexp_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_DESTROY))
static icl_stats_t *s_ipr_regexp_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_MATCH))
static icl_stats_t *s_ipr_regexp_match_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_EQ))
static icl_stats_t *s_ipr_regexp_eq_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_SELFTEST))
static icl_stats_t *s_ipr_regexp_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_TERMINATE))
static icl_stats_t *s_ipr_regexp_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_SHOW))
static icl_stats_t *s_ipr_regexp_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_regexp_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_ALLOC))
static icl_stats_t *s_ipr_regexp_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_FREE))
static icl_stats_t *s_ipr_regexp_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_READ_LOCK))
static icl_stats_t *s_ipr_regexp_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_WRITE_LOCK))
static icl_stats_t *s_ipr_regexp_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_UNLOCK))
static icl_stats_t *s_ipr_regexp_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_CACHE_INITIALISE))
static icl_stats_t *s_ipr_regexp_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_CACHE_PURGE))
static icl_stats_t *s_ipr_regexp_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_CACHE_TERMINATE))
static icl_stats_t *s_ipr_regexp_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_SHOW_ANIMATION))
static icl_stats_t *s_ipr_regexp_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_regexp_new_in_scope_stats = NULL;
#endif
static void
    ipr_regexp_annihilate (
ipr_regexp_t * ( * self_p )             //  Reference to object reference
);

#define ipr_regexp_alloc()              ipr_regexp_alloc_ (__FILE__, __LINE__)
static ipr_regexp_t *
    ipr_regexp_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_regexp_free (
ipr_regexp_t * self                     //  Object reference
);

static void
    ipr_regexp_cache_initialise (
void);

static void
    ipr_regexp_cache_purge (
void);

static void
    ipr_regexp_cache_terminate (
void);

Bool
    ipr_regexp_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_regexp_new

    Type: Component method
    Creates and initialises a new ipr_regexp_t object, returns a
    reference to the created object.
    Create new regular expression.  Note that we allow '`' to be used
    in place of '\' which causes difficulties for C and code generation.
    If you really want to use ` in the expression, double the character.
    -------------------------------------------------------------------------
 */

ipr_regexp_t *
    ipr_regexp_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * pattern                      //  Not documented
)
{
int
    pcre_offset;
char
    *scan,
    *pcre_error;                    //  Last error if any
    ipr_regexp_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_NEW))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" pattern=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, pattern);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_NEW))
    icl_trace_record (NULL, ipr_regexp_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_NEW))
    icl_stats_inc ("ipr_regexp_new", &s_ipr_regexp_new_stats);
#endif

    self = ipr_regexp_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_REGEXP_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_regexp_show_);
#endif

//  Copy the pattern so we can play with it
self->pattern = icl_mem_strdup (pattern);
scan = self->pattern;
while (*scan) {
    if (*scan == '`') {
        *scan = '\\';
        if (*(scan + 1) == '`')
            scan++;                 //  Allow `` to mean `
    }
    scan++;
}
self->regexp = pcre_compile (self->pattern, 0, (const char **) &pcre_error, &pcre_offset, NULL);
if (self->regexp) {
    pcre_fullinfo (self->regexp, NULL, PCRE_INFO_CAPTURECOUNT, &self->match_count);
    self->match_size = (self->match_count + 1) * 3;
    self->match_list = (int *) icl_mem_alloc (self->match_size * sizeof (int));
}
else {
    icl_console_print ("E: ipr_regexp - invalid regexp: %s\n%s\n%*c",
        pcre_error, self->pattern, pcre_offset + 1, '^');
    self_destroy (&self);
}
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_NEW))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_NEW))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" pattern=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, pattern, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_regexp_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_regexp_annihilate (
    ipr_regexp_t * ( * self_p )         //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    ipr_regexp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_DESTROY))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_DESTROY))
    icl_trace_record (NULL, ipr_regexp_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_DESTROY))
    icl_stats_inc ("ipr_regexp_annihilate", &s_ipr_regexp_annihilate_stats);
#endif

    IPR_REGEXP_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_mem_free (self->pattern);
icl_mem_free (self->match_list);
if (self->regexp)
    pcre_free (self->regexp);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_DESTROY))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_DESTROY))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_destroy_finish"
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
    ipr_regexp_match

    Type: Component method
    Accepts a ipr_regexp_t reference and returns zero in case of success,
    1 in case of errors.
    Parses a string using a regular expression and loads zero or more
    patterns into supplied strings. Returns the number of matched
    strings, or 1 if no strings were supplied and the expression
    matched. Returns zero if the expression did not match at all.
    -------------------------------------------------------------------------
 */

int
    ipr_regexp_match (
    ipr_regexp_t * self,                //  Reference to object
    char * string,                      //  Not documented
...                                     //  Not documented
)
{
    int
        _rc;
    va_list
        argptr;
    va_start (argptr, string);
    _rc = ipr_regexp_match_v (self, string, argptr );
    va_end (argptr);
    return _rc;
}
/*  -------------------------------------------------------------------------
    ipr_regexp_match_v

    Type: Component method
    Accepts a ipr_regexp_t reference and returns zero in case of success,
    1 in case of errors.
    Parses a string using a regular expression and loads zero or more
    patterns into supplied strings. Returns the number of matched
    strings, or 1 if no strings were supplied and the expression
    matched. Returns zero if the expression did not match at all.
    -------------------------------------------------------------------------
 */

int
    ipr_regexp_match_v (
    ipr_regexp_t * self,                //  Reference to object
    char * string,                      //  Not documented
va_list argptr                          //  Not documented
)
{
char
    **symbol;                       //  Passed to the function
int
    match_okay,                     //  Did string match pattern?
    match_index,                    //  Work through each match...
    start,
    length;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_MATCH))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_match_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_MATCH))
    icl_trace_record (NULL, ipr_regexp_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_MATCH))
    icl_stats_inc ("ipr_regexp_match", &s_ipr_regexp_match_stats);
#endif

IPR_REGEXP_ASSERT_SANE (self);

assert (string);
match_okay = pcre_exec (
    self->regexp, NULL, string, strlen (string), 0, 0,
    self->match_list, self->match_size);

for (match_index = 0; match_index < self->match_count; match_index++) {
    symbol = va_arg (argptr, char **);
    if (symbol) {
        if (match_okay >= 0) {
            icl_mem_strfree (symbol);
            start  = self->match_list [match_index * 2 + 2];
            length = self->match_list [match_index * 2 + 3] - start;
            *symbol = (char *) icl_mem_alloc (length + 1);
            if (length > 0)
                memcpy (*symbol, string + start, length);
            (*symbol) [length] = 0;
        }
        else {
            //  No match, so return empty string
            if (*symbol) {
                icl_mem_strfree (symbol);
                *symbol = icl_mem_strdup ("");
            }
        }
    }
}
if (match_okay >= 0) {
    if (self->match_count)
        rc = self->match_count;     //  Matched N items
    else
        rc = 1;                     //  Match succeeded
}
else
    rc = 0;                         //  Match failed

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_MATCH))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_MATCH))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_match_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_regexp_eq

    Type: Component method
    Matches a string with a regular expression and returns TRUE
    if the string matches, FALSE if not.  Does not require any
    set-up, but is slower than the match method when comparing
    many strings, since a ipr_regexp object is created and
    destroyed for each call.
    -------------------------------------------------------------------------
 */

int
    ipr_regexp_eq (
    char * regexp,                      //  Regular expression
    char * string                       //  String to compare
)
{
ipr_regexp_t
    *self;                          //  The compiled regexp
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_EQ))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_eq_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" regexp=\"%s\""
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, regexp, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_EQ))
    icl_trace_record (NULL, ipr_regexp_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_EQ))
    icl_stats_inc ("ipr_regexp_eq", &s_ipr_regexp_eq_stats);
#endif

self = self_new (regexp);
if (ipr_regexp_match (self, string))
    rc = TRUE;
else
    rc = FALSE;

self_destroy (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_EQ))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_EQ))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_eq_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" regexp=\"%s\""
" string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, regexp, string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_regexp_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_regexp_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_SELFTEST))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_SELFTEST))
    icl_trace_record (NULL, ipr_regexp_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_SELFTEST))
    icl_stats_inc ("ipr_regexp_selftest", &s_ipr_regexp_selftest_stats);
#endif

char
    *regexp_str;                    //  The regexp string
ipr_regexp_t
    *regexp;                        //  The compiled regexp
char
    *item = NULL;                   //  A matched item
int
    nbr_items;                      //  Number of matched items

//  This is an example of a Perl5-compatible regular expression
//  Note that ipr_regexp lets us use ` instead of a back slash,
//  since back-slashes require a lot of escaping in iCL code.
//  The ( ) groups indicate matched items.  {} is used to define
//  min/max occurrences.
//
regexp_str = "^[0-9]{3}`-[0-9]{3}`-[0-9]{3,6}$";

//  The simplest way to get a yes/no match is to use ipr_regexp_eq
assert (ipr_regexp_eq  (regexp_str, "123-456-789"));
assert (ipr_regexp_eq  (regexp_str, "123-456-789123"));
assert (!ipr_regexp_eq (regexp_str, "123-456-7891239"));
assert (!ipr_regexp_eq (regexp_str, "123-456-abc"));

//  Here is an expression with three subpatterns:
regexp_str = "([0-9]+)`-([0-9]+)`-([0-9]+)";

//  We compile our regular expression into an ipr_regexp object
//  If we did a lot of matching on a single expression, it would
//  be worth keeping this object around.
//
regexp = ipr_regexp_new (regexp_str);

//  Now we do the matching
//  Note that item must be initialised to NULL, otherwise the
//  match method will free it first (to allow reuse).
//
nbr_items = ipr_regexp_match (regexp, "123-456-789", NULL, &item, NULL);

//  We must have matched all three items and extracted the second one
//
assert (nbr_items == 3);
assert (streq (item, "456"));

//  Clean up - destroy all objects and free allocated memory
//
ipr_regexp_destroy (&regexp);
icl_mem_free (item);

//  Let's try some more complex expressions
//
regexp_str = "^`w+`.eur$";
regexp = ipr_regexp_new (regexp_str);
assert (ipr_regexp_match (regexp, "stocks.eur") == 1);
assert (ipr_regexp_match (regexp, "stocks.usd") == 0);
ipr_regexp_destroy (&regexp);

//  To define subsequences that are not captured, we use (?: ... )
//
regexp_str = "^`w+(?:[`./]`w+)*[`./]eur$";
regexp = ipr_regexp_new (regexp_str);
assert (ipr_regexp_match (regexp, "stocks/aapl/eur") == 1);
assert (ipr_regexp_match (regexp, "stocks.msft/eur") == 1);
assert (ipr_regexp_match (regexp, "stocks/csco.usd") == 0);
ipr_regexp_destroy (&regexp);

regexp = ipr_regexp_new ("^^[a-zA-Z0-9-_.:]*$$");
for (nbr_items = 0; nbr_items < 10000; nbr_items++)
    ipr_regexp_match (regexp, "This-is-a-queue");
ipr_regexp_destroy (&regexp);

//  Heap stress test
for (nbr_items = 0; nbr_items < 250000; nbr_items++) {
    regexp = ipr_regexp_new ("^^[a-zA-Z0-9-_.:]*$$");
    ipr_regexp_destroy (&regexp);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_SELFTEST))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_SELFTEST))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_selftest_finish"
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
    ipr_regexp_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_regexp_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_TERMINATE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_TERMINATE))
    icl_trace_record (NULL, ipr_regexp_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_TERMINATE))
    icl_stats_inc ("ipr_regexp_terminate", &s_ipr_regexp_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_TERMINATE))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_TERMINATE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_terminate_finish"
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
    ipr_regexp_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_regexp_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_regexp_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_SHOW))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_SHOW))
    icl_trace_record (NULL, ipr_regexp_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_SHOW))
    icl_stats_inc ("ipr_regexp_show", &s_ipr_regexp_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_regexp file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_SHOW))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_SHOW))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_show_finish"
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
    ipr_regexp_destroy

    Type: Component method
    Destroys a ipr_regexp_t object. Takes the address of a
    ipr_regexp_t reference (a pointer to a pointer) and nullifies the
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
    ipr_regexp_destroy_ (
    ipr_regexp_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_regexp_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_DESTROY_PUBLIC))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_regexp_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_regexp_destroy", &s_ipr_regexp_destroy_stats);
#endif

if (self) {
    ipr_regexp_annihilate (self_p);
    ipr_regexp_free ((ipr_regexp_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_DESTROY_PUBLIC))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_destroy_public_finish"
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
    ipr_regexp_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_regexp_t *
    ipr_regexp_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_regexp_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_ALLOC))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_ALLOC))
    icl_trace_record (NULL, ipr_regexp_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_ALLOC))
    icl_stats_inc ("ipr_regexp_alloc", &s_ipr_regexp_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_regexp_cache_initialise ();

self = (ipr_regexp_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_regexp_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_ALLOC))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_ALLOC))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_alloc_finish"
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
    ipr_regexp_free

    Type: Component method
    Freess a ipr_regexp_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_regexp_free (
    ipr_regexp_t * self                 //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_FREE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_FREE))
    icl_trace_record (NULL, ipr_regexp_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_FREE))
    icl_stats_inc ("ipr_regexp_free", &s_ipr_regexp_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_regexp_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_regexp_t));
        self->object_tag = IPR_REGEXP_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_FREE))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_FREE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_free_finish"
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
    ipr_regexp_read_lock

    Type: Component method
    Accepts a ipr_regexp_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_regexp_read_lock (
    ipr_regexp_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_READ_LOCK))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_READ_LOCK))
    icl_trace_record (NULL, ipr_regexp_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_READ_LOCK))
    icl_stats_inc ("ipr_regexp_read_lock", &s_ipr_regexp_read_lock_stats);
#endif

IPR_REGEXP_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_READ_LOCK))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_READ_LOCK))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_read_lock_finish"
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
    ipr_regexp_write_lock

    Type: Component method
    Accepts a ipr_regexp_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_regexp_write_lock (
    ipr_regexp_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_WRITE_LOCK))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_WRITE_LOCK))
    icl_trace_record (NULL, ipr_regexp_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_WRITE_LOCK))
    icl_stats_inc ("ipr_regexp_write_lock", &s_ipr_regexp_write_lock_stats);
#endif

IPR_REGEXP_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_WRITE_LOCK))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_WRITE_LOCK))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_write_lock_finish"
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
    ipr_regexp_unlock

    Type: Component method
    Accepts a ipr_regexp_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_regexp_unlock (
    ipr_regexp_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_UNLOCK))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_UNLOCK))
    icl_trace_record (NULL, ipr_regexp_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_UNLOCK))
    icl_stats_inc ("ipr_regexp_unlock", &s_ipr_regexp_unlock_stats);
#endif

IPR_REGEXP_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_UNLOCK))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_UNLOCK))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_unlock_finish"
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
    ipr_regexp_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_regexp_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_CACHE_INITIALISE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_regexp_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_CACHE_INITIALISE))
    icl_stats_inc ("ipr_regexp_cache_initialise", &s_ipr_regexp_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_regexp_t));
icl_system_register (ipr_regexp_cache_purge, ipr_regexp_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_CACHE_INITIALISE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_cache_initialise_finish"
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
    ipr_regexp_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_regexp_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_CACHE_PURGE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_PURGE))
    icl_trace_record (NULL, ipr_regexp_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_CACHE_PURGE))
    icl_stats_inc ("ipr_regexp_cache_purge", &s_ipr_regexp_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_PURGE))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_CACHE_PURGE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_cache_purge_finish"
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
    ipr_regexp_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_regexp_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_CACHE_TERMINATE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_regexp_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_CACHE_TERMINATE))
    icl_stats_inc ("ipr_regexp_cache_terminate", &s_ipr_regexp_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_CACHE_TERMINATE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_cache_terminate_finish"
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
    ipr_regexp_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_regexp_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_SHOW_ANIMATION))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_regexp_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_SHOW_ANIMATION))
    icl_stats_inc ("ipr_regexp_show_animation", &s_ipr_regexp_show_animation_stats);
#endif

ipr_regexp_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_SHOW_ANIMATION))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_show_animation_finish"
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
    ipr_regexp_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_regexp_new_in_scope_ (
    ipr_regexp_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * pattern                      //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_REGEXP)  ||  defined (BASE_ANIMATE_IPR_REGEXP_NEW_IN_SCOPE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" pattern=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, pattern);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_regexp_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_REGEXP)  ||  defined (BASE_STATS_IPR_REGEXP_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_regexp_new_in_scope", &s_ipr_regexp_new_in_scope_stats);
#endif

*self_p = ipr_regexp_new_ (file,line,pattern);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_regexp_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_regexp_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_REGEXP)   || defined (BASE_ANIMATE_IPR_REGEXP_NEW_IN_SCOPE))
    if (ipr_regexp_animating)
        icl_console_print ("<ipr_regexp_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" pattern=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, pattern, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_REGEXP)   || defined (BASE_TRACE_IPR_REGEXP_NEW)   || defined (BASE_TRACE_IPR_REGEXP_DESTROY)   || defined (BASE_TRACE_IPR_REGEXP_MATCH)   || defined (BASE_TRACE_IPR_REGEXP_EQ)   || defined (BASE_TRACE_IPR_REGEXP_SELFTEST)   || defined (BASE_TRACE_IPR_REGEXP_TERMINATE)   || defined (BASE_TRACE_IPR_REGEXP_SHOW)   || defined (BASE_TRACE_IPR_REGEXP_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_REGEXP_ALLOC)   || defined (BASE_TRACE_IPR_REGEXP_FREE)   || defined (BASE_TRACE_IPR_REGEXP_READ_LOCK)   || defined (BASE_TRACE_IPR_REGEXP_WRITE_LOCK)   || defined (BASE_TRACE_IPR_REGEXP_UNLOCK)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_PURGE)   || defined (BASE_TRACE_IPR_REGEXP_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_REGEXP_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_REGEXP_NEW_IN_SCOPE) )
void
ipr_regexp_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "match"; break;
        case 4: method_name = "eq"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "terminate"; break;
        case 7: method_name = "show"; break;
        case 8: method_name = "destroy public"; break;
        case 9: method_name = "alloc"; break;
        case 10: method_name = "free"; break;
        case 11: method_name = "read lock"; break;
        case 12: method_name = "write lock"; break;
        case 13: method_name = "unlock"; break;
        case 14: method_name = "cache initialise"; break;
        case 15: method_name = "cache purge"; break;
        case 16: method_name = "cache terminate"; break;
        case 17: method_name = "show animation"; break;
        case 18: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_regexp %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_regexp_version_start     = "VeRsIoNsTaRt:ipc";
char *ipr_regexp_component         = "ipr_regexp ";
char *ipr_regexp_version           = "1.0 ";
char *ipr_regexp_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_regexp_filename          = "ipr_regexp.icl ";
char *ipr_regexp_builddate         = "2009/02/19 ";
char *ipr_regexp_version_end       = "VeRsIoNeNd:ipc";

