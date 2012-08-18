/*---------------------------------------------------------------------------
    ipr_dict.c - ipr_dict component

Implements a symbol-table dictionary.  The dictionary holds string
values indexed by string keys.  The string values are duplicated.
All access to the dictionary is unlocked, and dictionary items do
not use links, so the dictionary should not be used from multiple
threads in parallel.
    Generated from ipr_dict.icl by icl_gen using GSL/4.
    
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
#include "ipr_dict.h"                   //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_dict_t

//  Shorthands for class methods                                               

#define self_new            ipr_dict_new
#define self_annihilate     ipr_dict_annihilate
#define self_update         ipr_dict_update
#define self_assume         ipr_dict_assume
#define self_assume_fmt     ipr_dict_assume_fmt
#define self_selftest       ipr_dict_selftest
#define self_remove_from_all_containers  ipr_dict_remove_from_all_containers
#define self_show           ipr_dict_show
#define self_terminate      ipr_dict_terminate
#define self_destroy        ipr_dict_destroy
#define self_alloc          ipr_dict_alloc
#define self_free           ipr_dict_free
#define self_cache_initialise  ipr_dict_cache_initialise
#define self_cache_purge    ipr_dict_cache_purge
#define self_cache_terminate  ipr_dict_cache_terminate
#define self_show_animation  ipr_dict_show_animation
#define self_new_in_scope   ipr_dict_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_NEW))
static icl_stats_t *s_ipr_dict_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_DESTROY))
static icl_stats_t *s_ipr_dict_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_UPDATE))
static icl_stats_t *s_ipr_dict_update_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_ASSUME))
static icl_stats_t *s_ipr_dict_assume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_ASSUME_FMT))
static icl_stats_t *s_ipr_dict_assume_fmt_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_SELFTEST))
static icl_stats_t *s_ipr_dict_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_dict_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_SHOW))
static icl_stats_t *s_ipr_dict_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_TERMINATE))
static icl_stats_t *s_ipr_dict_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_dict_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_ALLOC))
static icl_stats_t *s_ipr_dict_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_FREE))
static icl_stats_t *s_ipr_dict_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_CACHE_INITIALISE))
static icl_stats_t *s_ipr_dict_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_CACHE_PURGE))
static icl_stats_t *s_ipr_dict_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_CACHE_TERMINATE))
static icl_stats_t *s_ipr_dict_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_SHOW_ANIMATION))
static icl_stats_t *s_ipr_dict_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_dict_new_in_scope_stats = NULL;
#endif
static void
    ipr_dict_annihilate (
ipr_dict_t * ( * self_p )               //  Reference to object reference
);

#define ipr_dict_alloc()                ipr_dict_alloc_ (__FILE__, __LINE__)
static ipr_dict_t *
    ipr_dict_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_dict_free (
ipr_dict_t * self                       //  Object reference
);

static void
    ipr_dict_cache_initialise (
void);

static void
    ipr_dict_cache_purge (
void);

static void
    ipr_dict_cache_terminate (
void);

Bool
    ipr_dict_animating = TRUE;          //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_dict_new

    Type: Component method
    Creates and initialises a new ipr_dict_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

ipr_dict_t *
    ipr_dict_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_dict_table_t * table,           //  Table to insert into
    char * key,                         //  Hash key
    char * value                        //  Not documented
)
{
    ipr_dict_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_NEW))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_NEW))
    icl_trace_record (NULL, ipr_dict_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_NEW))
    icl_stats_inc ("ipr_dict_new", &s_ipr_dict_new_stats);
#endif

    self = ipr_dict_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_DICT_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_dict_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
self->value = icl_mem_strdup (value);
if (table && self && ipr_dict_table_insert (table, key, self))
    ipr_dict_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_NEW))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_NEW))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" value=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, value, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_dict_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_annihilate (
    ipr_dict_t * ( * self_p )           //  Reference to object reference
)
{

    ipr_dict_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_DESTROY))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_DESTROY))
    icl_trace_record (NULL, ipr_dict_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_DESTROY))
    icl_stats_inc ("ipr_dict_annihilate", &s_ipr_dict_annihilate_stats);
#endif

IPR_DICT_ASSERT_SANE (self);
ipr_dict_remove_from_all_containers (self);

icl_mem_free (self->value);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_DESTROY))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_DESTROY))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_destroy_finish"
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
    ipr_dict_update

    Type: Component method
    Accepts a ipr_dict_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_update (
    ipr_dict_t * self,                  //  Reference to object
    char * value                        //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_UPDATE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_update_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_UPDATE))
    icl_trace_record (NULL, ipr_dict_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_UPDATE))
    icl_stats_inc ("ipr_dict_update", &s_ipr_dict_update_stats);
#endif

IPR_DICT_ASSERT_SANE (self);

icl_mem_free (self->value);
self->value = icl_mem_strdup (value);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_UPDATE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_UPDATE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_update_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" value=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, value, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_assume

    Type: Component method
    Create or update symbol with specified value.  Returns TRUE if the symbol
    was created, FALSE if it already existed.
    -------------------------------------------------------------------------
 */

Bool
    ipr_dict_assume (
    ipr_dict_table_t * table,           //  Symbol table
    char * name,                        //  Symbol name
    char * value                        //  Symbol value
)
{
ipr_dict_t
    *item;                          //  Inserted item
    Bool
        rc = FALSE;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_ASSUME))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_assume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, name, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_ASSUME))
    icl_trace_record (NULL, ipr_dict_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_ASSUME))
    icl_stats_inc ("ipr_dict_assume", &s_ipr_dict_assume_stats);
#endif

item = ipr_dict_table_search (table, name);
if (item) {
    if (value && strneq (value, item->value))
        ipr_dict_update (item, value);
}
else {
    ipr_dict_new (table, name, value);
    rc = TRUE;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_ASSUME))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_ASSUME))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_assume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" name=\"%s\""
" value=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, name, value, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_assume_fmt

    Type: Component method
    Create or update symbol with formatted value. Allows printf-style
    formatting to be done on a value prior to inserting it into the
    symbol table.  That the formatted value may not be larger than a
    shortstr, or it will be truncated.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_assume_fmt (
    ipr_dict_table_t * table,           //  Symbol table
    char * name,                        //  Symbol name
    char * format,                      //  Format specifier
...                                     //  Variable arguments
)
{
    va_list
        args;
    va_start (args, format);
    ipr_dict_assume_fmt_v (table, name, format, args );
    va_end (args);
}
/*  -------------------------------------------------------------------------
    ipr_dict_assume_fmt_v

    Type: Component method
    Create or update symbol with formatted value. Allows printf-style
    formatting to be done on a value prior to inserting it into the
    symbol table.  That the formatted value may not be larger than a
    shortstr, or it will be truncated.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_assume_fmt_v (
    ipr_dict_table_t * table,           //  Symbol table
    char * name,                        //  Symbol name
    char * format,                      //  Format specifier
va_list args                            //  Variable arguments
)
{
icl_shortstr_t
    value;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_ASSUME_FMT))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_assume_fmt_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" name=\"%s\""
" format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, name, format);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_ASSUME_FMT))
    icl_trace_record (NULL, ipr_dict_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_ASSUME_FMT))
    icl_stats_inc ("ipr_dict_assume_fmt", &s_ipr_dict_assume_fmt_stats);
#endif

//
apr_vsnprintf (value, ICL_SHORTSTR_MAX, format, args);
self_assume (table, name, value);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_ASSUME_FMT))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_ASSUME_FMT))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_assume_fmt_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" name=\"%s\""
" format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, name, format);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_dict_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_SELFTEST))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_SELFTEST))
    icl_trace_record (NULL, ipr_dict_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_SELFTEST))
    icl_stats_inc ("ipr_dict_selftest", &s_ipr_dict_selftest_stats);
#endif

//  selftest is in ipr_dict_table.icl
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_SELFTEST))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_SELFTEST))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_selftest_finish"
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
    ipr_dict_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_remove_from_all_containers (
    ipr_dict_t * self                   //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_dict_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_dict_remove_from_all_containers", &s_ipr_dict_remove_from_all_containers_stats);
#endif

IPR_DICT_ASSERT_SANE (self);
ipr_dict_table_remove (self);
ipr_dict_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_remove_from_all_containers_finish"
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
    ipr_dict_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_dict_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_SHOW))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_SHOW))
    icl_trace_record (NULL, ipr_dict_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_SHOW))
    icl_stats_inc ("ipr_dict_show", &s_ipr_dict_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->list_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_dict file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_SHOW))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_SHOW))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_show_finish"
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
    ipr_dict_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_TERMINATE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_TERMINATE))
    icl_trace_record (NULL, ipr_dict_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_TERMINATE))
    icl_stats_inc ("ipr_dict_terminate", &s_ipr_dict_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_TERMINATE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_TERMINATE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_terminate_finish"
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
    ipr_dict_destroy

    Type: Component method
    Destroys a ipr_dict_t object. Takes the address of a
    ipr_dict_t reference (a pointer to a pointer) and nullifies the
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
    ipr_dict_destroy_ (
    ipr_dict_t * ( * self_p ),          //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_dict_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_DESTROY_PUBLIC))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_dict_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_dict_destroy", &s_ipr_dict_destroy_stats);
#endif

if (self) {
    ipr_dict_annihilate (self_p);
    ipr_dict_free ((ipr_dict_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_DESTROY_PUBLIC))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_destroy_public_finish"
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
    ipr_dict_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_dict_t *
    ipr_dict_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_dict_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_ALLOC))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_ALLOC))
    icl_trace_record (NULL, ipr_dict_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_ALLOC))
    icl_stats_inc ("ipr_dict_alloc", &s_ipr_dict_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_dict_cache_initialise ();

self = (ipr_dict_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_dict_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_ALLOC))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_ALLOC))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_alloc_finish"
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
    ipr_dict_free

    Type: Component method
    Freess a ipr_dict_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_free (
    ipr_dict_t * self                   //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_FREE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_FREE))
    icl_trace_record (NULL, ipr_dict_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_FREE))
    icl_stats_inc ("ipr_dict_free", &s_ipr_dict_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_dict_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_dict_t));
        self->object_tag = IPR_DICT_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_FREE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_FREE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_free_finish"
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
    ipr_dict_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_CACHE_INITIALISE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_dict_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_CACHE_INITIALISE))
    icl_stats_inc ("ipr_dict_cache_initialise", &s_ipr_dict_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_dict_t));
icl_system_register (ipr_dict_cache_purge, ipr_dict_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_CACHE_INITIALISE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_cache_initialise_finish"
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
    ipr_dict_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_CACHE_PURGE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_CACHE_PURGE))
    icl_trace_record (NULL, ipr_dict_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_CACHE_PURGE))
    icl_stats_inc ("ipr_dict_cache_purge", &s_ipr_dict_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_CACHE_PURGE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_CACHE_PURGE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_cache_purge_finish"
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
    ipr_dict_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_CACHE_TERMINATE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_dict_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_CACHE_TERMINATE))
    icl_stats_inc ("ipr_dict_cache_terminate", &s_ipr_dict_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_CACHE_TERMINATE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_cache_terminate_finish"
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
    ipr_dict_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_SHOW_ANIMATION))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_dict_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_SHOW_ANIMATION))
    icl_stats_inc ("ipr_dict_show_animation", &s_ipr_dict_show_animation_stats);
#endif

ipr_dict_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_SHOW_ANIMATION))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_show_animation_finish"
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
    ipr_dict_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_new_in_scope_ (
    ipr_dict_t * * self_p,              //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_dict_table_t * table,           //  Table to insert into
    char * key,                         //  Hash key
    char * value                        //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT)  ||  defined (BASE_ANIMATE_IPR_DICT_NEW_IN_SCOPE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_dict_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT)  ||  defined (BASE_STATS_IPR_DICT_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_dict_new_in_scope", &s_ipr_dict_new_in_scope_stats);
#endif

*self_p = ipr_dict_new_ (file,line,table,key,value);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_dict_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_dict_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT)   || defined (BASE_ANIMATE_IPR_DICT_NEW_IN_SCOPE))
    if (ipr_dict_animating)
        icl_console_print ("<ipr_dict_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" value=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, value, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT)   || defined (BASE_TRACE_IPR_DICT_NEW)   || defined (BASE_TRACE_IPR_DICT_DESTROY)   || defined (BASE_TRACE_IPR_DICT_UPDATE)   || defined (BASE_TRACE_IPR_DICT_ASSUME)   || defined (BASE_TRACE_IPR_DICT_ASSUME_FMT)   || defined (BASE_TRACE_IPR_DICT_SELFTEST)   || defined (BASE_TRACE_IPR_DICT_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_DICT_SHOW)   || defined (BASE_TRACE_IPR_DICT_TERMINATE)   || defined (BASE_TRACE_IPR_DICT_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_DICT_ALLOC)   || defined (BASE_TRACE_IPR_DICT_FREE)   || defined (BASE_TRACE_IPR_DICT_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_DICT_CACHE_PURGE)   || defined (BASE_TRACE_IPR_DICT_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_DICT_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_DICT_NEW_IN_SCOPE) )
void
ipr_dict_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "update"; break;
        case 4: method_name = "assume"; break;
        case 5: method_name = "assume_fmt"; break;
        case 6: method_name = "selftest"; break;
        case 7: method_name = "remove from all containers"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "terminate"; break;
        case 10: method_name = "destroy public"; break;
        case 11: method_name = "alloc"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "cache initialise"; break;
        case 14: method_name = "cache purge"; break;
        case 15: method_name = "cache terminate"; break;
        case 16: method_name = "show animation"; break;
        case 17: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_dict %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_dict_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_dict_component           = "ipr_dict ";
char *ipr_dict_version             = "1.0 ";
char *ipr_dict_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_dict_filename            = "ipr_dict.icl ";
char *ipr_dict_builddate           = "2009/02/19 ";
char *ipr_dict_version_end         = "VeRsIoNeNd:ipc";

