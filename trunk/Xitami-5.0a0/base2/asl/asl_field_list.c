/*---------------------------------------------------------------------------
    asl_field_list.c - asl_field_list component

    Provides functionality to implement the ASL RFC 'Field Table'
    data type.  This class provides functions at the field-table level.
    Each field table is represented as a list of fields.  This class
    provides methods to transform field lists to and from aslP binary
    formats, and lookup and operate on field lists.
    Generated from asl_field_list.icl by icl_gen using GSL/4.
    
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
#include "asl_field_list.h"             //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              asl_field_list_t

//  Shorthands for class methods                                               

#define self_new            asl_field_list_new
#define self_annihilate     asl_field_list_annihilate
#define self_parse          asl_field_list_parse
#define self_flatten        asl_field_list_flatten
#define self_search         asl_field_list_search
#define self_cpy            asl_field_list_cpy
#define self_string         asl_field_list_string
#define self_integer        asl_field_list_integer
#define self_print          asl_field_list_print
#define self_dump           asl_field_list_dump
#define self_to_tree        asl_field_list_to_tree
#define self_build          asl_field_list_build
#define self_selftest       asl_field_list_selftest
#define self_isempty        asl_field_list_isempty
#define self_push           asl_field_list_push
#define self_pop            asl_field_list_pop
#define self_queue          asl_field_list_queue
#define self_relink_before  asl_field_list_relink_before
#define self_remove         asl_field_list_remove
#define self_first          asl_field_list_first
#define self_last           asl_field_list_last
#define self_next           asl_field_list_next
#define self_prev           asl_field_list_prev
#define self_rehook         asl_field_list_rehook
#define self_unhook         asl_field_list_unhook
#define self_terminate      asl_field_list_terminate
#define self_show           asl_field_list_show
#define self_destroy        asl_field_list_destroy
#define self_alloc          asl_field_list_alloc
#define self_free           asl_field_list_free
#define self_link           asl_field_list_link
#define self_unlink         asl_field_list_unlink
#define self_show_animation  asl_field_list_show_animation
#define self_new_in_scope   asl_field_list_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_NEW))
static icl_stats_t *s_asl_field_list_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_DESTROY))
static icl_stats_t *s_asl_field_list_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PARSE))
static icl_stats_t *s_asl_field_list_parse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_FLATTEN))
static icl_stats_t *s_asl_field_list_flatten_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SEARCH))
static icl_stats_t *s_asl_field_list_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_CPY))
static icl_stats_t *s_asl_field_list_cpy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_STRING))
static icl_stats_t *s_asl_field_list_string_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_INTEGER))
static icl_stats_t *s_asl_field_list_integer_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PRINT))
static icl_stats_t *s_asl_field_list_print_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_DUMP))
static icl_stats_t *s_asl_field_list_dump_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_TO_TREE))
static icl_stats_t *s_asl_field_list_to_tree_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_BUILD))
static icl_stats_t *s_asl_field_list_build_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SELFTEST))
static icl_stats_t *s_asl_field_list_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_ISEMPTY))
static icl_stats_t *s_asl_field_list_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PUSH))
static icl_stats_t *s_asl_field_list_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_POP))
static icl_stats_t *s_asl_field_list_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_QUEUE))
static icl_stats_t *s_asl_field_list_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_RELINK_BEFORE))
static icl_stats_t *s_asl_field_list_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_REMOVE))
static icl_stats_t *s_asl_field_list_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_FIRST))
static icl_stats_t *s_asl_field_list_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_LAST))
static icl_stats_t *s_asl_field_list_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_NEXT))
static icl_stats_t *s_asl_field_list_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PREV))
static icl_stats_t *s_asl_field_list_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_REHOOK))
static icl_stats_t *s_asl_field_list_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_UNHOOK))
static icl_stats_t *s_asl_field_list_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_TERMINATE))
static icl_stats_t *s_asl_field_list_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SHOW))
static icl_stats_t *s_asl_field_list_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_DESTROY_PUBLIC))
static icl_stats_t *s_asl_field_list_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_ALLOC))
static icl_stats_t *s_asl_field_list_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_FREE))
static icl_stats_t *s_asl_field_list_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_LINK))
static icl_stats_t *s_asl_field_list_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_UNLINK))
static icl_stats_t *s_asl_field_list_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SHOW_ANIMATION))
static icl_stats_t *s_asl_field_list_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_NEW_IN_SCOPE))
static icl_stats_t *s_asl_field_list_new_in_scope_stats = NULL;
#endif
#define asl_field_list_annihilate(self)  asl_field_list_annihilate_ (self, __FILE__, __LINE__)
static void
    asl_field_list_annihilate_ (
asl_field_list_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    asl_field_list_rehook (
asl_field_t * item,                     //  Not documented
asl_field_t * left,                     //  Not documented
asl_field_t * right                     //  Not documented
);

static inline asl_field_t *
    asl_field_list_unhook (
asl_field_t * item                      //  Not documented
);

#define asl_field_list_alloc()          asl_field_list_alloc_ (__FILE__, __LINE__)
static asl_field_list_t *
    asl_field_list_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define asl_field_list_free(self)       asl_field_list_free_ (self, __FILE__, __LINE__)
static void
    asl_field_list_free_ (
asl_field_list_t * self,                //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

Bool
    asl_field_list_animating = TRUE;    //  Animation enabled by default

/*  -------------------------------------------------------------------------
    asl_field_list_new

    Type: Component method
    Creates and initialises a new asl_field_list_t object, returns a
    reference to the created object.
    If the field table argument is not null, parses the field table into
    the field list.  If the field table contained invalid data, destroys
    self.
    -------------------------------------------------------------------------
 */

asl_field_list_t *
    asl_field_list_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    icl_longstr_t * field_table         //  Field table
)
{
    asl_field_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_NEW))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" field_table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, field_table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEW))
    icl_trace_record (NULL, asl_field_list_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_NEW))
    icl_stats_inc ("asl_field_list_new", &s_asl_field_list_new_stats);
#endif

    self = asl_field_list_alloc_ (file, line);
    if (self) {
        self->object_tag   = ASL_FIELD_LIST_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, asl_field_list_show_);
#endif

self->asl_field.list_next = &self->asl_field;
self->asl_field.list_prev = &self->asl_field;
self->asl_field.list_head = self;

//
if (field_table)
    if (self_parse (self, field_table))
        self_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEW))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_NEW))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" field_table=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, field_table, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    asl_field_list_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    asl_field_list_annihilate_ (
    asl_field_list_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    int
        history_last;
#endif

asl_field_t
    *item;
    asl_field_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_DESTROY))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_DESTROY))
    icl_trace_record (NULL, asl_field_list_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_DESTROY))
    icl_stats_inc ("asl_field_list_annihilate", &s_asl_field_list_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = self->links;
#endif

    ASL_FIELD_LIST_ASSERT_SANE (self);

item = (asl_field_t *) self->asl_field.list_next;
while (item != &self->asl_field) {
    //  Unlink child without lock (we already have the lock)               
    asl_field_list_unhook (item);

    asl_field_unlink (&item);
    item = (asl_field_t *) self->asl_field.list_next;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_DESTROY))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_DESTROY))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_destroy_finish"
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
    asl_field_list_parse

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Parses a longstr string into a list of fields.  Does not empty the
    list before appending new fields to it.  Returns the number of fields
    parsed, or -1 if the supplied string was invalid.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_parse (
    asl_field_list_t * self,            //  Reference to object
    icl_longstr_t * field_table         //  Field table
)
{
byte
    *input,                         //  Current position in string
    *limit;                         //  Limit of string (max + 1)
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_PARSE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_parse_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" field_table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, field_table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PARSE))
    icl_trace_record (NULL, asl_field_list_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PARSE))
    icl_stats_inc ("asl_field_list_parse", &s_asl_field_list_parse_stats);
#endif

ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//
assert (field_table);

input = field_table->data;
limit = input + field_table->cur_size;
while (input < limit) {
    input = asl_field_parse (self, input, limit);
    if (!input) {
        rc = -1;                    //  Error in fields
        break;
    }
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PARSE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_PARSE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_parse_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" field_table=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, field_table, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_flatten

    Type: Component method
    Encodes the field list as a longstr string.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    asl_field_list_flatten (
    asl_field_list_t * self             //  Reference to object
)
{
size_t
    flat_size = 0;
asl_field_t
    *field;                         //  Field object
    icl_longstr_t *
        field_table;                    //  Field table

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_FLATTEN))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_flatten_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_FLATTEN))
    icl_trace_record (NULL, asl_field_list_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_FLATTEN))
    icl_stats_inc ("asl_field_list_flatten", &s_asl_field_list_flatten_stats);
#endif

//
//  Compute required total size for all fields
field = self_first (self);
while (field) {
    flat_size += asl_field_flat_size (field);
    field = self_next (&field);
}
//  Flatten all fields into a string
field_table = icl_longstr_new (NULL, flat_size);
field = self_first (self);
while (field) {
    asl_field_flatten (field, field_table);
    field = self_next (&field);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_FLATTEN))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_FLATTEN))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_flatten_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" field_table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, field_table);
#endif


    return (field_table);
}
/*  -------------------------------------------------------------------------
    asl_field_list_search

    Type: Component method
    Looks for a field with the specified name, returns the field object
    if found, else NULL.  Field names are case-significant.
    -------------------------------------------------------------------------
 */

asl_field_t *
    asl_field_list_search (
    asl_field_list_t * self,            //  Reference to object
    char * name                         //  Field name
)
{
    asl_field_t *
        field;                          //  Field object

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_SEARCH))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_search_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SEARCH))
    icl_trace_record (NULL, asl_field_list_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SEARCH))
    icl_stats_inc ("asl_field_list_search", &s_asl_field_list_search_stats);
#endif

//
field = self_first (self);
while (field) {
    if (streq (field->name, name))
        break;
    field = self_next (&field);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SEARCH))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_SEARCH))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_search_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" field=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, field);
#endif


    return (field);
}
/*  -------------------------------------------------------------------------
    asl_field_list_cpy

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Looks for a field with the specified name, if found copies the
    field value into the specified string, else clears the string.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_cpy (
    asl_field_list_t * self,            //  Reference to objectReference to object
    char * dest,                        //  Destination shortstr
    char * name                         //  Field name
)
{
asl_field_t
    *field;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_CPY))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_cpy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dest=\"%s\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dest, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_CPY))
    icl_trace_record (NULL, asl_field_list_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_CPY))
    icl_stats_inc ("asl_field_list_cpy", &s_asl_field_list_cpy_stats);
#endif

ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//
field = asl_field_list_search (self, name);
if (field) {
    icl_shortstr_cpy (dest, asl_field_string (field));
    asl_field_unlink (&field);
}
else
    strclr (dest);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_CPY))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_CPY))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_cpy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dest=\"%s\""
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dest, name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_string

    Type: Component method
    Looks for a field with the specified name, returns the field's string
    value if found, else NULL.
    -------------------------------------------------------------------------
 */

char *
    asl_field_list_string (
    asl_field_list_t * self,            //  Reference to object
    char * name                         //  Field name
)
{
asl_field_t
    *field;
    char *
        value;                          //  String value to return

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_STRING))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_string_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_STRING))
    icl_trace_record (NULL, asl_field_list_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_STRING))
    icl_stats_inc ("asl_field_list_string", &s_asl_field_list_string_stats);
#endif

//
field = self_search (self, name);
if (field) {
    value = asl_field_string (field);
    asl_field_unlink (&field);
}
else
    value = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_STRING))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_STRING))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_string_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    asl_field_list_integer

    Type: Component method
    Looks for a field with the specified name, returns the field's integer
    value if found, else zero.
    -------------------------------------------------------------------------
 */

long
    asl_field_list_integer (
    asl_field_list_t * self,            //  Reference to object
    char * name                         //  Field name
)
{
asl_field_t
    *field;
    long
        value;                          //  Integer value to return

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_INTEGER))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_integer_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_INTEGER))
    icl_trace_record (NULL, asl_field_list_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_INTEGER))
    icl_stats_inc ("asl_field_list_integer", &s_asl_field_list_integer_stats);
#endif

//
field = self_search (self, name);
if (field) {
    value = asl_field_integer (field);
    asl_field_unlink (&field);
}
else
    value = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_INTEGER))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_INTEGER))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_integer_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" value=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    asl_field_list_print

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Dumps the contents of the field list for debugging purposes.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_print (
    asl_field_list_t * self             //  Reference to object
)
{
asl_field_t
    *field;                         //  Field object
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_PRINT))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_print_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PRINT))
    icl_trace_record (NULL, asl_field_list_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PRINT))
    icl_stats_inc ("asl_field_list_print", &s_asl_field_list_print_stats);
#endif

ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//
field = self_first (self);
while (field) {
    asl_field_print (field);
    field = self_next (&field);
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PRINT))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_PRINT))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_print_finish"
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
    asl_field_list_dump

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Dumps the contents of the field list as a NULL terminated icl_shortstr_t
    of NAME=VALUE pairs separated by spaces.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_dump (
    asl_field_list_t * self,            //  Reference to object
    char * dest                         //  Not documented
)
{
asl_field_t
    *field;                         //  Field object
icl_longstr_t
    *string;                        //  Used to build up the final string
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_DUMP))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_dump_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dest=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dest);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_DUMP))
    icl_trace_record (NULL, asl_field_list_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_DUMP))
    icl_stats_inc ("asl_field_list_dump", &s_asl_field_list_dump_stats);
#endif

ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Create empty longstr to store the result
string = icl_longstr_new (NULL, ICL_SHORTSTR_MAX + 1);
string->data [0] = 0;

//  Dump individual fields of the list
field = self_first (self);
while (field) {
    //  Need a copy here since string may get reallocated
    char
        *append = icl_mem_strdup ((char *) string->data);

    icl_longstr_fmt (string, "%s%s=%s ", append, field->name, asl_field_string (field));
    field = self_next (&field);
    icl_mem_strfree (&append);
}
string->data [ICL_SHORTSTR_MAX] = 0;
icl_shortstr_cpy (dest, (char *) string->data);
icl_longstr_destroy (&string);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_DUMP))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_DUMP))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_dump_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" dest=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, dest, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_to_tree

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Converts the field list to a set of leaves in the provided tree.  
    The tree is built using the ipr_tree class.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_to_tree (
    asl_field_list_t * self,            //  Reference to object
    ipr_tree_t * tree                   //  Not documented
)
{
asl_field_t
    *field;                         //  Field object
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_TO_TREE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_to_tree_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tree=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tree);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_TO_TREE))
    icl_trace_record (NULL, asl_field_list_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_TO_TREE))
    icl_stats_inc ("asl_field_list_to_tree", &s_asl_field_list_to_tree_stats);
#endif

ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Dump individual fields of the list
field = self_first (self);
while (field) {
    ipr_tree_leaf (tree, field->name, asl_field_string (field));
    field = self_next (&field);
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_TO_TREE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_TO_TREE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_to_tree_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tree=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tree, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_build

    Type: Component method
    Builds a flattened field list suitable for sending across a socket
    or writing to a file.  The field list is limited to string values.
    Accepts a series of name, value argument pairs, ending in a null
    name. Returns a icl_longstr, which the caller must destroy after use.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    asl_field_list_build (
    char * start,                       //  First field name
...                                     //  Variable arguments
)
{
    icl_longstr_t *
        _rc;
    va_list
        argptr;
    va_start (argptr, start);
    _rc = asl_field_list_build_v (start, argptr );
    va_end (argptr);
    return _rc;
}
/*  -------------------------------------------------------------------------
    asl_field_list_build_v

    Type: Component method
    Builds a flattened field list suitable for sending across a socket
    or writing to a file.  The field list is limited to string values.
    Accepts a series of name, value argument pairs, ending in a null
    name. Returns a icl_longstr, which the caller must destroy after use.
    -------------------------------------------------------------------------
 */

icl_longstr_t *
    asl_field_list_build_v (
    char * start,                       //  First field name
va_list argptr                          //  Variable arguments
)
{
char
    *field_name,
    *field_value;
asl_field_list_t
    *field_list;
    icl_longstr_t *
        string;                         //  Flat field list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_BUILD))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_build_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" start=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, start);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_BUILD))
    icl_trace_record (NULL, asl_field_list_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_BUILD))
    icl_stats_inc ("asl_field_list_build", &s_asl_field_list_build_stats);
#endif

//
field_name = start;
field_list = self_new (NULL);
while (field_name) {
    field_value = va_arg (argptr, char *);
    asl_field_new_string (field_list, field_name, field_value);
    field_name  = va_arg (argptr, char *);
}
string = asl_field_list_flatten (field_list);
asl_field_list_destroy (&field_list);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_BUILD))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_BUILD))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_build_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" start=\"%s\""
" string=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, start, string);
#endif


    return (string);
}
/*  -------------------------------------------------------------------------
    asl_field_list_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    asl_field_list_selftest (
void)
{
asl_field_list_t
    *list;
icl_longstr_t
    *string1,
    *string2;
icl_shortstr_t
    shortstr;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_SELFTEST))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SELFTEST))
    icl_trace_record (NULL, asl_field_list_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SELFTEST))
    icl_stats_inc ("asl_field_list_selftest", &s_asl_field_list_selftest_stats);
#endif

//
list = asl_field_list_new (NULL);
asl_field_new_string  (list, "testfield0", "Collateral damage");
asl_field_new_integer (list, "testfield1", 1234567890);
asl_field_new_decimal (list, "testfield2", 199900, 2);
asl_field_new_time    (list, "testfield3", time (NULL));
asl_field_new_string  (list, "testfield4", "S1");
asl_field_new_string  (list, "testfield5", "P12");
string1 = asl_field_list_flatten (list);
asl_field_list_dump (list, shortstr);
asl_field_list_destroy (&list);

list = asl_field_list_new (string1);
string2 = asl_field_list_flatten (list);
asl_field_list_destroy (&list);

assert (string1->cur_size == string2->cur_size);
icl_longstr_destroy (&string1);
icl_longstr_destroy (&string2);

//  We can build a flattened field list in one step
string1 = asl_field_list_build (
    "host",  "Sleeper Service",
    "guest", "My Homework Ate My Dog",
    NULL);
icl_longstr_destroy (&string1);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SELFTEST))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_SELFTEST))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_selftest_finish"
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
    asl_field_list_isempty

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_isempty (
    asl_field_list_t * self             //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_ISEMPTY))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_ISEMPTY))
    icl_trace_record (NULL, asl_field_list_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_ISEMPTY))
    icl_stats_inc ("asl_field_list_isempty", &s_asl_field_list_isempty_stats);
#endif

ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->asl_field.list_next == &self->asl_field);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_ISEMPTY))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_ISEMPTY))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_isempty_finish"
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
    asl_field_list_push

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_push (
    asl_field_list_t * self,            //  Reference to object
    asl_field_t * item                  //  Not documented
)
{


    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_PUSH))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_push_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PUSH))
    icl_trace_record (NULL, asl_field_list_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PUSH))
    icl_stats_inc ("asl_field_list_push", &s_asl_field_list_push_stats);
#endif



ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->list_head) {
    asl_field_link (item);
}
else
if (item->list_head != self) {
    icl_console_print ("E: asl_field item inserted into multiple list containers");
    assert (item->list_head == self);
}
asl_field_list_unhook (item);
asl_field_list_rehook (item, &self->asl_field, (asl_field_t *) self->asl_field.list_next);
}
else
    rc = -1;                        //  Return error on zombie object.



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PUSH))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_PUSH))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_push_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

asl_field_t *
    asl_field_list_pop (
    asl_field_list_t * self             //  The list
)
{


    asl_field_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_POP))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_POP))
    icl_trace_record (NULL, asl_field_list_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_POP))
    icl_stats_inc ("asl_field_list_pop", &s_asl_field_list_pop_stats);
#endif



ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

if (self->asl_field.list_next == &self->asl_field)
    item = NULL;
else {
    item = asl_field_list_unhook ((asl_field_t *) self->asl_field.list_next);
}
}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_POP))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_POP))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_pop_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    asl_field_list_queue

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_queue (
    asl_field_list_t * self,            //  Reference to object
    asl_field_t * item                  //  Not documented
)
{


    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_QUEUE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_queue_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_QUEUE))
    icl_trace_record (NULL, asl_field_list_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_QUEUE))
    icl_stats_inc ("asl_field_list_queue", &s_asl_field_list_queue_stats);
#endif



ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the             
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->list_head) {
    asl_field_link (item);
}
else
if (item->list_head != self) {
    icl_console_print ("E: asl_field item inserted into multiple list containers");
    assert (item->list_head == self);
}
asl_field_list_unhook (item);
asl_field_list_rehook (item, (asl_field_t *) self->asl_field.list_prev, &self->asl_field);
}
else
    rc = -1;                        //  Return error on zombie object.



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_QUEUE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_QUEUE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_queue_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_relink_before

    Type: Component method
    Accepts a asl_field_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_relink_before (
    asl_field_t * item,                 //  Not documented
    asl_field_t * where                 //  Not documented
)
{


    int
        rc = 0;                         //  Return code
    asl_field_list_t *
        self = (asl_field_list_t *) where->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_RELINK_BEFORE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_relink_before_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" where=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, where);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_RELINK_BEFORE))
    icl_trace_record (NULL, asl_field_list_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_RELINK_BEFORE))
    icl_stats_inc ("asl_field_list_relink_before", &s_asl_field_list_relink_before_stats);
#endif



ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the             
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->list_head) {
    asl_field_link (item);
}
else
if (item->list_head != self) {
    icl_console_print ("E: asl_field item inserted into multiple list containers");
    assert (item->list_head == self);
}            
asl_field_list_unhook (item);
asl_field_list_rehook (item, (asl_field_t *) where->list_prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_RELINK_BEFORE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_RELINK_BEFORE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_relink_before_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" where=\"%pp\""
" rc=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, where, rc, self);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_remove

    Type: Component method
    Removes the item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    asl_field_list_remove (
    asl_field_t * item                  //  Not documented
)
{


    asl_field_list_t *
        self = (asl_field_list_t *) item->list_head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_REMOVE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_remove_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_REMOVE))
    icl_trace_record (NULL, asl_field_list_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_REMOVE))
    icl_stats_inc ("asl_field_list_remove", &s_asl_field_list_remove_stats);
#endif



if (self
&&  self == item->list_head) { //       Catch case where item moved
    asl_field_list_unhook (item);
    asl_field_unlink (&item);
}


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_REMOVE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_REMOVE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_remove_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" self=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    asl_field_list_first

    Type: Component method
    Returns the first asl_field item on the list.     If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

asl_field_t *
    asl_field_list_first_ (
    asl_field_list_t * self,            //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    asl_field_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_FIRST))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_FIRST))
    icl_trace_record (NULL, asl_field_list_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_FIRST))
    icl_stats_inc ("asl_field_list_first", &s_asl_field_list_first_stats);
#endif



ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (asl_field_t *) self->asl_field.list_next;
if (item == &self->asl_field)
    item = NULL;
else
    asl_field_link (item);

}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_FIRST))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_FIRST))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_first_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    asl_field_list_last

    Type: Component method
    Returns the last asl_field item on the list.     If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

asl_field_t *
    asl_field_list_last_ (
    asl_field_list_t * self,            //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    asl_field_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_LAST))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_LAST))
    icl_trace_record (NULL, asl_field_list_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_LAST))
    icl_stats_inc ("asl_field_list_last", &s_asl_field_list_last_stats);
#endif



ASL_FIELD_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (asl_field_t *) self->asl_field.list_prev;
if (item == &self->asl_field)
    item = NULL;
else
    asl_field_link (item);

}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_LAST))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_LAST))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_last_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    asl_field_list_next

    Type: Component method
    Returns the following item on the asl_field list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

asl_field_t *
    asl_field_list_next_ (
    asl_field_t * ( * item_p ),         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    asl_field_t *
        item = *item_p;                 //  Dereferenced item
    asl_field_t *
        next = NULL;                    //  The item to return
    asl_field_list_t *
        self = (asl_field_list_t *) item->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_NEXT))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_next_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEXT))
    icl_trace_record (NULL, asl_field_list_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_NEXT))
    icl_stats_inc ("asl_field_list_next", &s_asl_field_list_next_stats);
#endif



if (self
&&  self == item->list_head) { //       Catch case where item moved
    next = (asl_field_t *) item->list_next;
    if (next == &self->asl_field)
        next = NULL;
    else
        asl_field_link (next);

}
asl_field_unlink (item_p);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEXT))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_NEXT))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_next_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
" next=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item, next, self);
#endif


    return (next);
}
/*  -------------------------------------------------------------------------
    asl_field_list_prev

    Type: Component method
    Returns the preceding item on the asl_field list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

asl_field_t *
    asl_field_list_prev_ (
    asl_field_t * ( * item_p ),         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    asl_field_t *
        item = *item_p;                 //  Dereferenced item
    asl_field_t *
        prev = NULL;                    //  The item to return
    asl_field_list_t *
        self = (asl_field_list_t *) item->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_PREV))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_prev_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PREV))
    icl_trace_record (NULL, asl_field_list_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_PREV))
    icl_stats_inc ("asl_field_list_prev", &s_asl_field_list_prev_stats);
#endif



if (self
&&  self == item->list_head) { //       Catch case where item moved
    prev = (asl_field_t *) item->list_prev;
    if (prev == &self->asl_field)
        prev = NULL;
    else
        asl_field_link (prev);

}
asl_field_unlink (item_p);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_PREV))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_PREV))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_prev_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" item=\"%pp\""
" prev=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, file, line, item, prev, self);
#endif


    return (prev);
}
/*  -------------------------------------------------------------------------
    asl_field_list_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    asl_field_list_rehook (
    asl_field_t * item,                 //  Not documented
    asl_field_t * left,                 //  Not documented
    asl_field_t * right                 //  Not documented
)
{
asl_field_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_REHOOK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_rehook_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" left=\"%pp\""
" right=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, left, right);
#endif

#if (defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_REHOOK))
    icl_trace_record (NULL, asl_field_list_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_REHOOK))
    icl_stats_inc ("asl_field_list_rehook", &s_asl_field_list_rehook_stats);
#endif

swap = (asl_field_t *) left->list_next;
left->list_next = item->list_next;
item->list_next = swap;

swap = (asl_field_t *) item->list_prev;
item->list_prev = right->list_prev;
right->list_prev = swap;

item->list_head = left->list_head;
#if (defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_REHOOK))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_REHOOK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_rehook_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" left=\"%pp\""
" right=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, left, right);
#endif

}
/*  -------------------------------------------------------------------------
    asl_field_list_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline asl_field_t *
    asl_field_list_unhook (
    asl_field_t * item                  //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_UNHOOK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_unhook_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif

#if (defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_UNHOOK))
    icl_trace_record (NULL, asl_field_list_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_UNHOOK))
    icl_stats_inc ("asl_field_list_unhook", &s_asl_field_list_unhook_stats);
#endif

asl_field_list_rehook (item, (asl_field_t *) item->list_prev, (asl_field_t *) item->list_next);
item->list_head = NULL;
#if (defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_UNHOOK))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_UNHOOK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_unhook_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    asl_field_list_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    asl_field_list_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_TERMINATE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_TERMINATE))
    icl_trace_record (NULL, asl_field_list_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_TERMINATE))
    icl_stats_inc ("asl_field_list_terminate", &s_asl_field_list_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_TERMINATE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_TERMINATE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_terminate_finish"
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
    asl_field_list_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    asl_field_list_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    asl_field_list_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_SHOW))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SHOW))
    icl_trace_record (NULL, asl_field_list_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SHOW))
    icl_stats_inc ("asl_field_list_show", &s_asl_field_list_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <asl_field_list zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    if (self->history_last > ASL_FIELD_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ASL_FIELD_LIST_HISTORY_LENGTH;
        self->history_last %= ASL_FIELD_LIST_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ASL_FIELD_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </asl_field_list>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SHOW))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_SHOW))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_show_finish"
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
    asl_field_list_destroy

    Type: Component method
    Destroys a asl_field_list_t object. Takes the address of a
    asl_field_list_t reference (a pointer to a pointer) and nullifies the
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
    asl_field_list_destroy_ (
    asl_field_list_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    asl_field_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_DESTROY_PUBLIC))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_DESTROY_PUBLIC))
    icl_trace_record (NULL, asl_field_list_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_DESTROY_PUBLIC))
    icl_stats_inc ("asl_field_list_destroy", &s_asl_field_list_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        asl_field_list_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on asl_field_list object");
        asl_field_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        asl_field_list_free_ ((asl_field_list_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_DESTROY_PUBLIC))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_DESTROY_PUBLIC))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_destroy_public_finish"
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
    asl_field_list_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static asl_field_list_t *
    asl_field_list_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    asl_field_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_ALLOC))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_ALLOC))
    icl_trace_record (NULL, asl_field_list_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_ALLOC))
    icl_stats_inc ("asl_field_list_alloc", &s_asl_field_list_alloc_stats);
#endif

self = (asl_field_list_t *) icl_mem_alloc_ (sizeof (asl_field_list_t), file, line);
if (self)
    memset (self, 0, sizeof (asl_field_list_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_ALLOC))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_ALLOC))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_alloc_finish"
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
    asl_field_list_free

    Type: Component method
    Freess a asl_field_list_t object.
    -------------------------------------------------------------------------
 */

static void
    asl_field_list_free_ (
    asl_field_list_t * self,            //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_FREE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_FREE))
    icl_trace_record (NULL, asl_field_list_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_FREE))
    icl_stats_inc ("asl_field_list_free", &s_asl_field_list_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (asl_field_list_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (asl_field_list_t));
        self->object_tag = ASL_FIELD_LIST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_FREE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_FREE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_free_finish"
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
    asl_field_list_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

asl_field_list_t *
    asl_field_list_link_ (
    asl_field_list_t * self,            //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_LINK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_LINK))
    icl_trace_record (NULL, asl_field_list_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_LINK))
    icl_stats_inc ("asl_field_list_link", &s_asl_field_list_link_stats);
#endif

    if (self) {
        ASL_FIELD_LIST_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_LINK))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_LINK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_link_finish"
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
    asl_field_list_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    asl_field_list_unlink_ (
    asl_field_list_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
    int
        history_last;
#endif

    asl_field_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_UNLINK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_UNLINK))
    icl_trace_record (NULL, asl_field_list_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_UNLINK))
    icl_stats_inc ("asl_field_list_unlink", &s_asl_field_list_unlink_stats);
#endif

    if (self) {
        ASL_FIELD_LIST_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on asl_field_list object");
            asl_field_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ASL_FIELD_LIST)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ASL_FIELD_LIST_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            asl_field_list_annihilate_ (self_p, file, line);
        asl_field_list_free_ ((asl_field_list_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_UNLINK))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_UNLINK))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_unlink_finish"
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
    asl_field_list_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    asl_field_list_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_SHOW_ANIMATION))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SHOW_ANIMATION))
    icl_trace_record (NULL, asl_field_list_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_SHOW_ANIMATION))
    icl_stats_inc ("asl_field_list_show_animation", &s_asl_field_list_show_animation_stats);
#endif

asl_field_list_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_SHOW_ANIMATION))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_SHOW_ANIMATION))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_show_animation_finish"
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
    asl_field_list_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    asl_field_list_new_in_scope_ (
    asl_field_list_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    icl_longstr_t * field_table         //  Field table
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST)  ||  defined (BASE_ANIMATE_ASL_FIELD_LIST_NEW_IN_SCOPE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" field_table=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, field_table);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEW_IN_SCOPE))
    icl_trace_record (NULL, asl_field_list_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ASL_FIELD_LIST)  ||  defined (BASE_STATS_ASL_FIELD_LIST_NEW_IN_SCOPE))
    icl_stats_inc ("asl_field_list_new_in_scope", &s_asl_field_list_new_in_scope_stats);
#endif

*self_p = asl_field_list_new_ (file,line,field_table);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) asl_field_list_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEW_IN_SCOPE))
    icl_trace_record (NULL, asl_field_list_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ASL_FIELD_LIST)   || defined (BASE_ANIMATE_ASL_FIELD_LIST_NEW_IN_SCOPE))
    if (asl_field_list_animating)
        icl_console_print ("<asl_field_list_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" field_table=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, field_table, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ASL_FIELD_LIST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEW)   || defined (BASE_TRACE_ASL_FIELD_LIST_DESTROY)   || defined (BASE_TRACE_ASL_FIELD_LIST_PARSE)   || defined (BASE_TRACE_ASL_FIELD_LIST_FLATTEN)   || defined (BASE_TRACE_ASL_FIELD_LIST_SEARCH)   || defined (BASE_TRACE_ASL_FIELD_LIST_CPY)   || defined (BASE_TRACE_ASL_FIELD_LIST_STRING)   || defined (BASE_TRACE_ASL_FIELD_LIST_INTEGER)   || defined (BASE_TRACE_ASL_FIELD_LIST_PRINT)   || defined (BASE_TRACE_ASL_FIELD_LIST_DUMP)   || defined (BASE_TRACE_ASL_FIELD_LIST_TO_TREE)   || defined (BASE_TRACE_ASL_FIELD_LIST_BUILD)   || defined (BASE_TRACE_ASL_FIELD_LIST_SELFTEST)   || defined (BASE_TRACE_ASL_FIELD_LIST_ISEMPTY)   || defined (BASE_TRACE_ASL_FIELD_LIST_PUSH)   || defined (BASE_TRACE_ASL_FIELD_LIST_POP)   || defined (BASE_TRACE_ASL_FIELD_LIST_QUEUE)   || defined (BASE_TRACE_ASL_FIELD_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_ASL_FIELD_LIST_REMOVE)   || defined (BASE_TRACE_ASL_FIELD_LIST_FIRST)   || defined (BASE_TRACE_ASL_FIELD_LIST_LAST)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEXT)   || defined (BASE_TRACE_ASL_FIELD_LIST_PREV)   || defined (BASE_TRACE_ASL_FIELD_LIST_REHOOK)   || defined (BASE_TRACE_ASL_FIELD_LIST_UNHOOK)   || defined (BASE_TRACE_ASL_FIELD_LIST_TERMINATE)   || defined (BASE_TRACE_ASL_FIELD_LIST_SHOW)   || defined (BASE_TRACE_ASL_FIELD_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_ASL_FIELD_LIST_ALLOC)   || defined (BASE_TRACE_ASL_FIELD_LIST_FREE)   || defined (BASE_TRACE_ASL_FIELD_LIST_LINK)   || defined (BASE_TRACE_ASL_FIELD_LIST_UNLINK)   || defined (BASE_TRACE_ASL_FIELD_LIST_SHOW_ANIMATION)   || defined (BASE_TRACE_ASL_FIELD_LIST_NEW_IN_SCOPE) )
void
asl_field_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "parse"; break;
        case 4: method_name = "flatten"; break;
        case 5: method_name = "search"; break;
        case 6: method_name = "cpy"; break;
        case 7: method_name = "string"; break;
        case 8: method_name = "integer"; break;
        case 9: method_name = "print"; break;
        case 10: method_name = "dump"; break;
        case 11: method_name = "to tree"; break;
        case 12: method_name = "build"; break;
        case 13: method_name = "selftest"; break;
        case 14: method_name = "isempty"; break;
        case 15: method_name = "push"; break;
        case 16: method_name = "pop"; break;
        case 17: method_name = "queue"; break;
        case 18: method_name = "relink before"; break;
        case 19: method_name = "remove"; break;
        case 20: method_name = "first"; break;
        case 21: method_name = "last"; break;
        case 22: method_name = "next"; break;
        case 23: method_name = "prev"; break;
        case 24: method_name = "rehook"; break;
        case 25: method_name = "unhook"; break;
        case 26: method_name = "terminate"; break;
        case 27: method_name = "show"; break;
        case 28: method_name = "destroy public"; break;
        case 29: method_name = "alloc"; break;
        case 30: method_name = "free"; break;
        case 31: method_name = "link"; break;
        case 32: method_name = "unlink"; break;
        case 33: method_name = "show animation"; break;
        case 34: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "asl_field_list %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *asl_field_list_version_start  = "VeRsIoNsTaRt:ipc";
char *asl_field_list_component     = "asl_field_list ";
char *asl_field_list_version       = "1.1 ";
char *asl_field_list_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *asl_field_list_filename      = "asl_field_list.icl ";
char *asl_field_list_builddate     = "2009/02/19 ";
char *asl_field_list_version_end   = "VeRsIoNeNd:ipc";

