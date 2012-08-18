/*---------------------------------------------------------------------------
    ipr_dict_table.c - ipr_dict_table component

    This class implements the hash table container for ipr_dict.  Note
    that this class is not thread safe and uses no rwlocks.  The table
    allows linking for reference counting.
    Generated from ipr_dict_table.icl by icl_gen using GSL/4.
    
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
#include "ipr_dict_table.h"             //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_dict_table_t

//  Shorthands for class methods                                               

#define self_new            ipr_dict_table_new
#define self_annihilate     ipr_dict_table_annihilate
#define self_insert         ipr_dict_table_insert
#define self_remove         ipr_dict_table_remove
#define self_lookup         ipr_dict_table_lookup
#define self_matches        ipr_dict_table_matches
#define self_template       ipr_dict_table_template
#define self_export         ipr_dict_table_export
#define self_import         ipr_dict_table_import
#define self_headers_load   ipr_dict_table_headers_load
#define self_headers_save   ipr_dict_table_headers_save
#define self_headers_search  ipr_dict_table_headers_search
#define self_uri_load       ipr_dict_table_uri_load
#define self_props_load     ipr_dict_table_props_load
#define self_file_load      ipr_dict_table_file_load
#define self_file_save      ipr_dict_table_file_save
#define self_file_sync      ipr_dict_table_file_sync
#define self_selftest       ipr_dict_table_selftest
#define self_search         ipr_dict_table_search
#define self_apply          ipr_dict_table_apply
#define self_terminate      ipr_dict_table_terminate
#define self_show           ipr_dict_table_show
#define self_destroy        ipr_dict_table_destroy
#define self_alloc          ipr_dict_table_alloc
#define self_free           ipr_dict_table_free
#define self_link           ipr_dict_table_link
#define self_unlink         ipr_dict_table_unlink
#define self_show_animation  ipr_dict_table_show_animation
#define self_new_in_scope   ipr_dict_table_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_NEW))
static icl_stats_t *s_ipr_dict_table_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_DESTROY))
static icl_stats_t *s_ipr_dict_table_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_INSERT))
static icl_stats_t *s_ipr_dict_table_insert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_REMOVE))
static icl_stats_t *s_ipr_dict_table_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_LOOKUP))
static icl_stats_t *s_ipr_dict_table_lookup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_MATCHES))
static icl_stats_t *s_ipr_dict_table_matches_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_TEMPLATE))
static icl_stats_t *s_ipr_dict_table_template_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_EXPORT))
static icl_stats_t *s_ipr_dict_table_export_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_IMPORT))
static icl_stats_t *s_ipr_dict_table_import_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_HEADERS_LOAD))
static icl_stats_t *s_ipr_dict_table_headers_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_HEADERS_SAVE))
static icl_stats_t *s_ipr_dict_table_headers_save_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_HEADERS_SEARCH))
static icl_stats_t *s_ipr_dict_table_headers_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_URI_LOAD))
static icl_stats_t *s_ipr_dict_table_uri_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_PROPS_LOAD))
static icl_stats_t *s_ipr_dict_table_props_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FILE_LOAD))
static icl_stats_t *s_ipr_dict_table_file_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FILE_SAVE))
static icl_stats_t *s_ipr_dict_table_file_save_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FILE_SYNC))
static icl_stats_t *s_ipr_dict_table_file_sync_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SELFTEST))
static icl_stats_t *s_ipr_dict_table_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SEARCH))
static icl_stats_t *s_ipr_dict_table_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_APPLY))
static icl_stats_t *s_ipr_dict_table_apply_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_TERMINATE))
static icl_stats_t *s_ipr_dict_table_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SHOW))
static icl_stats_t *s_ipr_dict_table_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_dict_table_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_ALLOC))
static icl_stats_t *s_ipr_dict_table_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FREE))
static icl_stats_t *s_ipr_dict_table_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_LINK))
static icl_stats_t *s_ipr_dict_table_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_UNLINK))
static icl_stats_t *s_ipr_dict_table_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SHOW_ANIMATION))
static icl_stats_t *s_ipr_dict_table_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_dict_table_new_in_scope_stats = NULL;
#endif
#define ipr_dict_table_annihilate(self)  ipr_dict_table_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_dict_table_annihilate_ (
ipr_dict_table_t * ( * self_p ),        //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_dict_table_alloc()          ipr_dict_table_alloc_ (__FILE__, __LINE__)
static ipr_dict_table_t *
    ipr_dict_table_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_dict_table_free(self)       ipr_dict_table_free_ (self, __FILE__, __LINE__)
static void
    ipr_dict_table_free_ (
ipr_dict_table_t * self,                //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

Bool
    ipr_dict_table_animating = TRUE;    //  Animation enabled by default

//  Hash support functions
static inline unsigned int
    s_key_hash (char * key, size_t hash_size);
static inline Bool
    s_key_equal (char * key1, char * key2);

//  Table functions to be called once locks are in place
static int
    s_ipr_dict_table_insert (ipr_dict_table_t *self, ipr_dict_t *item, char * key);
static ipr_dict_t *
    s_ipr_dict_table_lookup (ipr_dict_table_t *self, char * key);
static void
    s_ipr_dict_table_remove (ipr_dict_t *item);
static void
    s_ipr_dict_table_purge (ipr_dict_table_t *self);
/*  -------------------------------------------------------------------------
    ipr_dict_table_new

    Type: Component method
    Creates and initialises a new ipr_dict_table_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_dict_table_t *
    ipr_dict_table_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_dict_table_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_NEW))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_NEW))
    icl_trace_record (NULL, ipr_dict_table_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_NEW))
    icl_stats_inc ("ipr_dict_table_new", &s_ipr_dict_table_new_stats);
#endif

    self = ipr_dict_table_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_DICT_TABLE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_dict_table_show_);
#endif

self->max_items = IPR_DICT_TABLE_INITIAL_SIZE;
self->table_items = icl_mem_alloc (sizeof (ipr_dict_t*) *
    IPR_DICT_TABLE_INITIAL_SIZE);
assert (self->table_items);
memset (self->table_items, 0, sizeof (ipr_dict_t*) *
    IPR_DICT_TABLE_INITIAL_SIZE);

self->list = ipr_dict_list_new ();
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_NEW))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_NEW))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_new_finish"
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
    ipr_dict_table_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_table_annihilate_ (
    ipr_dict_table_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    int
        history_last;
#endif

    ipr_dict_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_DESTROY))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_DESTROY))
    icl_trace_record (NULL, ipr_dict_table_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_DESTROY))
    icl_stats_inc ("ipr_dict_table_annihilate", &s_ipr_dict_table_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = self->links;
#endif

    IPR_DICT_TABLE_ASSERT_SANE (self);

s_ipr_dict_table_purge (self);
if (self->table_items)
    icl_mem_free (self->table_items);

ipr_dict_list_destroy (&self->list);
icl_mem_free (self->file_name);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_DESTROY))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_DESTROY))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_destroy_finish"
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
    ipr_dict_table_insert

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Insert a new item into the hash table if possible. If successful,
    the number of links to the item is automatically incremented.
    Trying to insert a duplicate key will result in nothing being inserted.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_insert (
    ipr_dict_table_t * self,            //  Reference to object
    char * key,                         //  Hash key
    ipr_dict_t * item                   //  Item to insert
)
{

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_INSERT))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_insert_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_INSERT))
    icl_trace_record (NULL, ipr_dict_table_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_INSERT))
    icl_stats_inc ("ipr_dict_table_insert", &s_ipr_dict_table_insert_stats);
#endif


IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
if (item->table_head) {
    if (item->table_head != self) {
        icl_console_print ("E: ipr_dict item inserted into multiple table containers");
        assert (item->table_head == self);
    }
    s_ipr_dict_table_remove (item);
}
rc = s_ipr_dict_table_insert (self, item, key);

ipr_dict_list_queue (self->list, item);
assert (ipr_dict_list_count (self->list) == self->nbr_items);
}
else
    rc = -1;                        //  Return error on zombie object.


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_INSERT))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_INSERT))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_insert_finish"
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
    ipr_dict_table_remove

    Type: Component method
    Remove an item from a hash table.  If the item was not in any hash
    table, this function does nothing.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_remove (
    ipr_dict_t * item                   //  Item to remove
)
{

    ipr_dict_table_t *
        self = item->table_head;        //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_REMOVE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_REMOVE))
    icl_trace_record (NULL, ipr_dict_table_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_REMOVE))
    icl_stats_inc ("ipr_dict_table_remove", &s_ipr_dict_table_remove_stats);
#endif


if (self
&&  self == item->table_head) { //      Catch case where item moved
    s_ipr_dict_table_remove (item);
}

ipr_dict_list_remove (item);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_REMOVE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_REMOVE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_remove_finish"
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
    ipr_dict_table_lookup

    Type: Component method
    Returns the value for the specified field.  If the field was not
    present in the table, returns an empty string.
    -------------------------------------------------------------------------
 */

char *
    ipr_dict_table_lookup (
    ipr_dict_table_t * self,            //  Reference to self
    char * name                         //  Field to look for
)
{
ipr_dict_t
    *item;                        //  Field item in dictionary, if any
    char *
        value;                          //  Value of header field

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_LOOKUP))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_lookup_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_LOOKUP))
    icl_trace_record (NULL, ipr_dict_table_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_LOOKUP))
    icl_stats_inc ("ipr_dict_table_lookup", &s_ipr_dict_table_lookup_stats);
#endif

//
assert (name);
item = ipr_dict_table_search (self, name);
value = item? item->value: "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_LOOKUP))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_LOOKUP))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_lookup_finish"
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
    ipr_dict_table_matches

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Returns TRUE if the specified item exists and matches the supplied regular
    expression, FALSE if the item does not exist or exists but does not match
    the specified expression.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_matches (
    ipr_dict_table_t * self,            //  Reference to object
    char * name,                        //  Name of item to look for
    char * match                        //  Regular expression to check
)
{
ipr_dict_t
    *item;                          //  Symbol in dictionary
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_MATCHES))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_matches_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" match=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, match);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_MATCHES))
    icl_trace_record (NULL, ipr_dict_table_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_MATCHES))
    icl_stats_inc ("ipr_dict_table_matches", &s_ipr_dict_table_matches_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
item = self_search (self, name);
if (item)
    rc = ipr_regexp_eq (match, item->value);
else
    rc = FALSE;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_MATCHES))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_MATCHES))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_matches_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" match=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, match, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_template

    Type: Component method
    Performs symbol substitution into a specified string. Returns a
    newly-allocated string containing the result.  The dictionary holds
    the set of symbols that may be inserted.  Undefined symbols are
    inserted as an empty value. Symbols are specified in the string
    using this syntax: $name, where 'name' is case-sensitive. The name
    can be terminated by a backslash.  $ is replaced by $.   Backslashes
    elsewhere are not modified.  The name must consist of letters,
    digits, hyphens, and underscores.
    -------------------------------------------------------------------------
 */

char *
    ipr_dict_table_template (
    ipr_dict_table_t * self,            //  Symbol table
    char * string                       //  Original string
)
{
ipr_regexp_t
    *regexp;                        //  The compiled regexp
int
    nbr_matches;                    //  Number of matched items
char
    *before,                        //  Text before symbol
    *name,                          //  Matched symbol name
    *after,                         //  Text after symbol
    *value;                         //  Value of symbol
ipr_dict_t
    *item;                          //  Symbol in dictionary
    char *
        result;                         //  Returned value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_TEMPLATE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_template_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_TEMPLATE))
    icl_trace_record (NULL, ipr_dict_table_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_TEMPLATE))
    icl_stats_inc ("ipr_dict_table_template", &s_ipr_dict_table_template_stats);
#endif

//
//  Duplicate string into working copy
result = icl_mem_strdup (string);
string = result;

//  Compile regular expression that will match symbols
//  Code generation turns two backslashes into a single one
//  and we need two in the regular expression, and C will turn
//  two into one... we could use ` except ipr_regexp treats ``
//  as `.  Sorry for this, it's the best deal I could get.
regexp = ipr_regexp_new (
    "(.*)"                          //  Anything up to symbol
    "`$([A-Za-z0-9-_]*)\\\\?"       //  Match symbol name
    "(.*)");                        //  Everything after symbol

FOREVER {
    before = name = after = NULL;
    nbr_matches = ipr_regexp_match (regexp, string, &before, &name, &after);
    if (nbr_matches < 3)
        break;                      //  No symbol found to replace

    //  Lookup symbol by name
    if (streq (name, ""))
        value = "\001";
    else {
        item = self_search (self, name);
        if (item)
            value = item->value;
        else
            value = "";
    }
    //  Paste resulting pieces together into a new string
    result = icl_mem_alloc (strlen (before) + strlen (value) + strlen (after) + 1);
    strcpy (result, before);
    strcat (result, value);
    strcat (result, after);
    icl_mem_free (string);
    string = result;

    icl_mem_free (before);
    icl_mem_free (name);
    icl_mem_free (after);
}
ipr_str_subch (result, '\001', '$');
ipr_regexp_destroy (&regexp);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_TEMPLATE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_TEMPLATE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_template_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" string=\"%s\""
" result=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, string, result);
#endif


    return (result);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_export

    Type: Component method
    Saves the dictionary as an array of strings in name=value format.
    The env option formats names in uppercase with underscores in place
    of non-alphanumeric characters.
    -------------------------------------------------------------------------
 */

char **
    ipr_dict_table_export (
    ipr_dict_table_t * self,            //  Reference to self
    Bool env,                           //  Format as environment
    char * prefix                       //  Optional prefix for exported names
)
{
ipr_dict_t
    *item;
size_t
    dict_size;
uint
    string_nbr;                     //  Index into symbol_array
char
    *value_ptr,                     //  Pointer into value block
    *name_ptr;
    char **
        strings;                        //  Returned arrary of strings

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_EXPORT))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_export_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" env=\"%i\""
" prefix=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, env, prefix);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_EXPORT))
    icl_trace_record (NULL, ipr_dict_table_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_EXPORT))
    icl_stats_inc ("ipr_dict_table_export", &s_ipr_dict_table_export_stats);
#endif

//
//  Count total size of dictionary
//  Main array consist of N+1 char pointers
dict_size = sizeof (char *) * (self->nbr_items + 1);
item = ipr_dict_list_first (self->list);
while (item) {
    dict_size += strlen (item->key) + strlen (item->value) + 2;
    if (prefix)
        dict_size += strlen (prefix);
    item = ipr_dict_list_next (&item);
}
strings = icl_mem_alloc (dict_size);

//  Now save the strings into the array
string_nbr = 0;
value_ptr = (char *) strings + sizeof (char *) * (self->nbr_items + 1);
item = ipr_dict_list_first (self->list);
while (item) {
    if (prefix) {
        strcpy (value_ptr, prefix);
        strcat (value_ptr, item->key);
    }
    else
        strcpy (value_ptr, item->key);

    if (env) {
        for (name_ptr = value_ptr; *name_ptr; name_ptr++) {
            if (isalnum (*name_ptr))
                *name_ptr = toupper (*name_ptr);
            else
                *name_ptr = '_';
        }
    }
    strcat (value_ptr, "=");
    strcat (value_ptr, item->value);
    strings [string_nbr++] = value_ptr;
    value_ptr += strlen (value_ptr) + 1;
    item = ipr_dict_list_next (&item);
}
strings [string_nbr] = NULL;        //  Store final null pointer
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_EXPORT))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_EXPORT))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_export_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" env=\"%i\""
" prefix=\"%s\""
" strings=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, env, prefix, strings);
#endif


    return (strings);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_import

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Imports an array of strings in name=value format into the dictionary.
    The lower option converts the names to lower case.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_import (
    ipr_dict_table_t * self,            //  Reference to object
    char ** strings,                    //  Array of strings to import
    Bool lower                          //  Format names into lower case
)
{
char
    **stringp,                      //  Pointer to next string
    *equals;                        //  Position of '=' in string
icl_shortstr_t
    name;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_IMPORT))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_import_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" strings=\"%pp\""
" lower=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, strings, lower);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_IMPORT))
    icl_trace_record (NULL, ipr_dict_table_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_IMPORT))
    icl_stats_inc ("ipr_dict_table_import", &s_ipr_dict_table_import_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
for (stringp = strings; *stringp; stringp++) {
    //  Ignore any strings that are not in name=value format
    equals = strchr (*stringp, '=');
    if (equals) {
        icl_shortstr_ncpy (name, *stringp, equals - *stringp);
        if (lower)
            ipr_str_lower (name);
        ipr_dict_assume (self, name, equals + 1);
    }
}
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_IMPORT))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_IMPORT))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_import_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" strings=\"%pp\""
" lower=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, strings, lower, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_headers_load

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Imports a multi-line block of headers ('Name: value') into the dictionary.
    Converts the names to lower case.  The headers block is terminated by a
    NULL byte. The import process ends at the null byte, or if there is an
    invalid header or if there is a blank line.  Returns number of headers
    loaded.  Lines may end in CRLF or LF.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_headers_load (
    ipr_dict_table_t * self,            //  Reference to object
    char * headers,                     //  Headers block to import
    Bool trace                          //  Trace headers?
)
{
ipr_regexp_t
    *regexp;                        //  The compiled regexp
char
    *header_name = NULL,
    *header_value = NULL;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_HEADERS_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_headers_load_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" headers=\"%s\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, headers, trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_HEADERS_LOAD))
    icl_stats_inc ("ipr_dict_table_headers_load", &s_ipr_dict_table_headers_load_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
regexp = ipr_regexp_new ("^([`w-]+):`s+([^\r\n]*)\r?\n");
while (headers) {
    if (ipr_regexp_match (regexp, headers, &header_name, &header_value) == 2) {
        if (trace)
            icl_console_print ("I: %s: %s", header_name, header_value);
        ipr_str_lower (header_name);
        //  Chop header name and value to sane sizes to stop overflow attacks
        //  Header name fits into an icl_shortstr_t
        if (strlen (header_name) > ICL_SHORTSTR_MAX)
            header_name [ICL_SHORTSTR_MAX] = 0;
        //  We truncate the header value at 2K, arbitrarily
        if (strlen (header_value) > 2048)
            header_value [2048] = 0;

        ipr_dict_assume (self, header_name, header_value);
        icl_mem_strfree (&header_name);
        icl_mem_strfree (&header_value);
        rc++;
    }
    else
        break;                      //  Not a valid header, stop parsing

    headers = strchr (headers, '\n');
    if (headers)
        headers += 1;               //  Skip to start of next header line
}
ipr_regexp_destroy (&regexp);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_HEADERS_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_headers_load_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" headers=\"%s\""
" trace=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, headers, trace, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_headers_save

    Type: Component method
    Exports a dictionary as a multiline block of header fields in the
    format 'Name: value'. Converts the names to mixed case. Returns a new
    bucket containing the resulting headers.  The caller can ask for a block
    of text to be inserted at the start of the bucket (the prefix).
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    ipr_dict_table_headers_save (
    ipr_dict_table_t * self,            //  Reference to self
    icl_longstr_t * prefix,             //  Bucket prefix
    Bool trace                          //  Trace headers?
)
{
ipr_dict_t
    *item;
size_t
    dict_size;
byte
    *value_ptr;                     //  Pointer into value block
    ipr_bucket_t *
        bucket;                         //  Bucket to fill

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_HEADERS_SAVE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_headers_save_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" prefix=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, prefix, trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_SAVE))
    icl_trace_record (NULL, ipr_dict_table_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_HEADERS_SAVE))
    icl_stats_inc ("ipr_dict_table_headers_save", &s_ipr_dict_table_headers_save_stats);
#endif

//
//  Count total size of dictionary for bucket allocation
dict_size = 2;                      //  Ends in blank line
if (prefix)
    dict_size += prefix->cur_size;

item = ipr_dict_list_first (self->list);
while (item) {
    //  Allow for Name: item[cr][lf]
    dict_size += strlen (item->key) + strlen (item->value) + 4;
    item = ipr_dict_list_next (&item);
}
bucket = ipr_bucket_new (dict_size);
if (prefix)
    ipr_bucket_cat (bucket, prefix->data, prefix->cur_size);

value_ptr = bucket->data + bucket->cur_size;
item = ipr_dict_list_first (self->list);
while (item) {
    sprintf ((char *) value_ptr, "%s: %s", item->key, item->value);
    value_ptr [0] = toupper (value_ptr [0]);
    if (trace)
        icl_console_print ("I: %s", value_ptr);
    strcat ((char *) value_ptr, "\r\n");
    value_ptr += strlen ((char *) value_ptr);
    item = ipr_dict_list_next (&item);
}
//  End data with blank line
strcat ((char *) value_ptr, "\r\n");
value_ptr += strlen ((char *) value_ptr);
bucket->cur_size = value_ptr - bucket->data;
assert (bucket->cur_size <= bucket->max_size);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_SAVE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_HEADERS_SAVE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_headers_save_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" prefix=\"%pp\""
" trace=\"%i\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, prefix, trace, bucket);
#endif


    return (bucket);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_headers_search

    Type: Component method
    Returns the value for the specified header field.  If the field was not
    present in the table, returns an empty string, else returns the value.
    The field name may be specified in any case; the lookup disregards case.
    -------------------------------------------------------------------------
 */

char *
    ipr_dict_table_headers_search (
    ipr_dict_table_t * self,            //  Reference to self
    char * name                         //  Field to look for
)
{
icl_shortstr_t
    item_name;                     //  Field name, normalised to lowercase
ipr_dict_t
    *item;                    //  Field item in dictionary, if any
    char *
        value;                          //  Value of header field

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_HEADERS_SEARCH))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_headers_search_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_SEARCH))
    icl_trace_record (NULL, ipr_dict_table_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_HEADERS_SEARCH))
    icl_stats_inc ("ipr_dict_table_headers_search", &s_ipr_dict_table_headers_search_stats);
#endif

//
assert (name);
icl_shortstr_cpy (item_name, name);
ipr_str_lower (item_name);
item = ipr_dict_table_search (self, item_name);
value = item? item->value: "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_SEARCH))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_HEADERS_SEARCH))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_headers_search_finish"
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
    ipr_dict_table_uri_load

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Imports a URI argument string (name=value&name=value...) into the table.
    Returns number of argument fields loaded.  Each value is passed through
    ipr_http_unescape_uri ().
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_uri_load (
    ipr_dict_table_t * self,            //  Reference to object
    char * arguments                    //  Arguments to import
)
{
ipr_regexp_t
    *regexp;                        //  The compiled regexp
char
    *name = NULL,
    *value = NULL;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_URI_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_uri_load_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" arguments=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, arguments);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_URI_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_URI_LOAD))
    icl_stats_inc ("ipr_dict_table_uri_load", &s_ipr_dict_table_uri_load_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
regexp = ipr_regexp_new ("^&?([`w-_]+)=([^&#]*)");
while (arguments) {
    if (ipr_regexp_match (regexp, arguments, &name, &value) == 2) {
        //  Argument name fits into an icl_shortstr_t
        if (strlen (name) > ICL_SHORTSTR_MAX)
            name [ICL_SHORTSTR_MAX] = 0;
        //  We truncate the argument value at 2K, arbitrarily
        if (strlen (value) > 2048)
            value [2048] = 0;
        ipr_http_unescape_uri (value);

        ipr_dict_assume (self, name, value);
        icl_mem_strfree (&name);
        icl_mem_strfree (&value);
        arguments = strchr (arguments + 1, '&');
        rc++;                       //  We loaded one more argument
    }
    else
        break;                      //  Not valid, stop parsing
}
ipr_regexp_destroy (&regexp);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_URI_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_URI_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_uri_load_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" arguments=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, arguments, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_props_load

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Imports a property string into the table.  Property strings consist of
    zero or more 'name = value' pairs, where the value can optionally be
    enclosed in double or single quotes, and the pairs are seperated by an
    optional comma. Spaces are optional around '=' and between pairs. Returns
    number of argument fields loaded.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_props_load (
    ipr_dict_table_t * self,            //  Reference to object
    char * string                       //  Properties to import
)
{
ipr_regexp_t
    *regexp;                        //  The compiled regexp
char
    *name = NULL,
    *value1 = NULL,
    *value2 = NULL,
    *remainder = NULL;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_PROPS_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_props_load_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_PROPS_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_PROPS_LOAD))
    icl_stats_inc ("ipr_dict_table_props_load", &s_ipr_dict_table_props_load_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
string = icl_mem_strdup (string);
regexp = ipr_regexp_new ("^([`w-_]+)`s*=`s*(?:\"([^\"]*)\"|([^ ,]+))`s*,?`s*(.*)");
while (string) {
    if (ipr_regexp_match (regexp, string, &name, &value1, &value2, &remainder) == 4) {
        //  Argument name fits into an icl_shortstr_t
        if (strlen (name) > ICL_SHORTSTR_MAX)
            name [ICL_SHORTSTR_MAX] = 0;

        ipr_dict_assume (self, name, *value1? value1: value2);
        icl_mem_strfree (&name);
        icl_mem_strfree (&value1);
        icl_mem_strfree (&value2);
        icl_mem_strfree (&string);
        string = remainder;
        remainder = NULL;
        rc++;                       //  We loaded one more property
    }
    else
        break;                      //  Not valid, stop parsing
}
icl_mem_strfree (&string);
ipr_regexp_destroy (&regexp);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_PROPS_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_PROPS_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_props_load_finish"
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
    ipr_dict_table_file_load

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a text file into the dictionary.  If the pattern is null, a default
    pattern of "^([^:]+): (.*)$" is used.  If the pattern is specified it must
    contain two () substitution arguments, the first is the key and the second
    is the value.  Lines that do not match are silently discarded. Blank lines
    and lines starting with '#' are silently discarded, irrespective of the
    pattern.  Stores the loaded file's time and size, and returns the number of
    entries loaded from the file.  If the file could not be found, returns -1.
    Lines are limited to 4096 bytes, keys to 255 characters.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_file_load (
    ipr_dict_table_t * self,            //  Reference to object
    char * filename,                    //  Name of file to import
    char * pattern                      //  Regexp to match each line
)
{
#   define IPR_DICT_LINE_MAX    4096
    FILE
        *file;
    char
        *line;
    ipr_regexp_t
        *regexp;                        //  The compiled regexp
    char
        *name = NULL,
        *value = NULL;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_FILE_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_file_load_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" pattern=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, pattern);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FILE_LOAD))
    icl_stats_inc ("ipr_dict_table_file_load", &s_ipr_dict_table_file_load_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
file = fopen (filename, "r");
if (file) {
    icl_mem_free (self->file_name);
    self->file_name = icl_mem_strdup (filename);

    line = icl_mem_alloc (IPR_DICT_LINE_MAX + 1);
    if (!pattern)                   //  Default pattern is word + value
        pattern = "^([^:]+): (.*)$";
    regexp = ipr_regexp_new (pattern);
    while (fgets (line, IPR_DICT_LINE_MAX, file) != NULL) {
        if (line [0] == '#' || line [0] == 0)
            ;                       //  Ignore comments and empty lines
        else
        if (ipr_regexp_match (regexp, line, &name, &value) == 2) {
            if (strlen (name) > ICL_SHORTSTR_MAX)
                name [ICL_SHORTSTR_MAX] = 0;
            ipr_dict_assume (self, name, value);
            icl_mem_strfree (&name);
            icl_mem_strfree (&value);
            rc++;
        }
    }
    ipr_regexp_destroy (&regexp);
    icl_mem_free (line);
    fclose (file);

    self->file_size = ipr_file_size (self->file_name);
    self->file_time = ipr_file_time (self->file_name);
}
else
    rc = -1;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_LOAD))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_FILE_LOAD))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_file_load_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" pattern=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, pattern, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_file_save

    Type: Component method
    Accepts a ipr_dict_table_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the dictionary to a text file, one entry per line.  The format of
    each line in the file is specified a template.  The template is a string
    containing two '%s' string.  The first is the item name, and the second is
    the item value. If the template is null, a default template "%s: %s" is
    used.  Maximum length of one line is 4096 bytes.  If the filename is null,
    the saved dictionary filename is used.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_file_save (
    ipr_dict_table_t * self,            //  Reference to object
    char * filename,                    //  Name of file to import
    char * template                     //  Template for saved lines
)
{
FILE
    *file;
char
    *line;
ipr_dict_t
    *item;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_FILE_SAVE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_file_save_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" template=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, template);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_SAVE))
    icl_trace_record (NULL, ipr_dict_table_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FILE_SAVE))
    icl_stats_inc ("ipr_dict_table_file_save", &s_ipr_dict_table_file_save_stats);
#endif

IPR_DICT_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
if (!filename)
    filename = self->file_name;
assert (filename);
if (!template)
    template = "%s: %s";

file = fopen (filename, "w");
line = icl_mem_alloc (IPR_DICT_LINE_MAX + 1);
item = ipr_dict_list_first (self->list);
while (item) {
    apr_snprintf (line, IPR_DICT_LINE_MAX, template,  item->key, item->value);
    fprintf (file, "%s\n", line);
    item = ipr_dict_list_next (&item);
}
icl_mem_free (line);
fclose (file);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_SAVE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_FILE_SAVE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_file_save_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" template=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, template, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_file_sync

    Type: Component method
    Syncs the table with a disk file.  This method checks the time
    and size of the file on disk, and if changed from the table in memory,
    loads the file data into memory.  The reload is done in a thread-safe
    manner using an atomic compare-and-swap, so that applications can use the
    old table while the new one is being constructed.  If the file cannot be
    opened, the table will be empty.  The pattern argument defines the format
    of the file, as for the file_load() method.  The table reference may be
    NULL, meaning no table has been allocated.  Returns number of items loaded
    or -1 if the file could not be loaded.
    -------------------------------------------------------------------------
 */

int
    ipr_dict_table_file_sync (
    ipr_dict_table_t ** self_p,         //  Pointer to table reference
    char * filename,                    //  Name of file to import
    char * pattern                      //  Regexp to match each line
)
{
ipr_dict_table_t
    *table,                         //  Load here, then swap to self_p
    *old_table;                     //  For CAS operation
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_FILE_SYNC))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_file_sync_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" filename=\"%s\""
" pattern=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, filename, pattern);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_SYNC))
    icl_trace_record (NULL, ipr_dict_table_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FILE_SYNC))
    icl_stats_inc ("ipr_dict_table_file_sync", &s_ipr_dict_table_file_sync_stats);
#endif

//
assert (filename);
if (!(*self_p)
||  ipr_file_size (filename) != (*self_p)->file_size
||  ipr_file_time (filename) != (*self_p)->file_time) {
    table = ipr_dict_table_new ();
    rc = ipr_dict_table_file_load (table, filename, pattern);
    //  A 64-bit safe CAS will update the table reference safely
    do {
        old_table = *self_p;
    }
    while (icl_atomic_casptr ((volatile void **) self_p, table, old_table) != old_table);
    //  When the CAS has completed, old_table and *self_p have swapped
    ipr_dict_table_destroy (&old_table);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_SYNC))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_FILE_SYNC))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_file_sync_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" filename=\"%s\""
" pattern=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, filename, pattern, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dict_table_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_selftest (
void)
{
ipr_dict_table_t
    *table;
ipr_bucket_t
    *bucket;
ipr_dict_t
    *item;
size_t
    nbr_items;
char
    *template,
    **strings,                      //  Dictionary as array of strings
    **stringp;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_SELFTEST))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SELFTEST))
    icl_trace_record (NULL, ipr_dict_table_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SELFTEST))
    icl_stats_inc ("ipr_dict_table_selftest", &s_ipr_dict_table_selftest_stats);
#endif

table = ipr_dict_table_new ();

//  Insert some items
assert (ipr_dict_assume (table, "0xdeadbeef", "deadbeef"));
assert (ipr_dict_assume (table, "0xabadcafe", "abadcafe"));
assert (ipr_dict_assume (table, "0xabadcafe", "abadcafe") == FALSE);

//  Retrieve items
item = ipr_dict_table_search (table, "0xdeadbeef");
assert (item && streq (item->value, "deadbeef"));
item = ipr_dict_table_search (table, "0xabadcafe");
assert (item && streq (item->value, "abadcafe"));
assert (*ipr_dict_table_lookup (table, "0xdeadbeef"));
assert (*ipr_dict_table_lookup (table, "nosuch") == 0);

//  Get a non existent item
item = ipr_dict_table_search (table, "0xf0000000");
assert (item == NULL);

//  Template string
template = ipr_dict_table_template (table, "=$0xabadcafe\\xx$=");
assert (streq (template, "=abadcafexx$="));
icl_mem_free (template);

//  Import environment as table
ipr_dict_table_import (table, environ, TRUE);

//  Export list as array of name=value pairs
strings = ipr_dict_table_export (table, TRUE, "TEST_");
for (stringp = strings; *stringp; stringp++)
    assert (*stringp);
icl_mem_free (strings);

//  Delete an item
item = ipr_dict_table_search (table, "0xdeadbeef");
ipr_dict_destroy (&item);
item = ipr_dict_table_search (table, "0xdeadbeef");
assert (item == NULL);

ipr_dict_table_destroy (&table);

table = ipr_dict_table_new ();
assert (ipr_dict_table_headers_load (table,
    "Content: usually\n"
    "Disposition-mode: happy, sunny\n"
    "\n"
    "Difficulty: medium\n",
    FALSE) == 2);

bucket = ipr_dict_table_headers_save (table, NULL, FALSE);
assert (bucket);
assert (strlen ((char *) bucket->data) == 52);
ipr_bucket_unlink (&bucket);

assert (streq (ipr_dict_table_headers_search (table, "content"), "usually"));
assert (streq (ipr_dict_table_headers_search (table, "DISPOSITION-mode"), "happy, sunny"));
assert (streq (ipr_dict_table_headers_search (table, "Difficulty"), ""));

assert (ipr_dict_table_uri_load (table, "movie=mad%20max&ranking=great#id=wally") == 2);
assert (streq (ipr_dict_table_headers_search (table, "movie"), "mad max"));
assert (ipr_dict_table_props_load (table, "movie=\"snakes on a plane\", ranking=great, id=\"wally\"") == 3);
assert (streq (ipr_dict_table_headers_search (table, "movie"), "snakes on a plane"));

ipr_dict_table_destroy (&table);

//  Test file load/sync/save functions
table = ipr_dict_table_new ();
assert (ipr_dict_table_file_load (table, "ipr_dict_table.icl", "<method name = \"([^\"]+)\" (.*)>") > 0);
nbr_items = table->nbr_items;
assert (ipr_dict_table_file_save (table, "ipr_dict_table.lst", NULL) == 0);
assert (ipr_dict_table_file_sync (&table, "ipr_dict_table.lst", NULL) == nbr_items);
assert (table->nbr_items == nbr_items);
ipr_file_delete ("ipr_dict_table.lst");
assert (ipr_dict_table_file_sync (&table, "ipr_dict_table.lst", NULL) == -1);
assert (table->nbr_items == 0);
ipr_dict_table_destroy (&table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SELFTEST))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_SELFTEST))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_selftest_finish"
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
    ipr_dict_table_search

    Type: Component method
    Find object by key in the hash table. Returns reference to object
    if found, else null.
    -------------------------------------------------------------------------
 */

ipr_dict_t *
    ipr_dict_table_search (
    ipr_dict_table_t * self,            //  Table to search
    char * key                          //  Hash key
)
{

    ipr_dict_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_SEARCH))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_search_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SEARCH))
    icl_trace_record (NULL, ipr_dict_table_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SEARCH))
    icl_stats_inc ("ipr_dict_table_search", &s_ipr_dict_table_search_stats);
#endif


//
IPR_DICT_TABLE_ASSERT_SANE (self);
if (key)
    item = s_ipr_dict_table_lookup (self, key);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SEARCH))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_SEARCH))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_search_finish"
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
    ipr_dict_table_apply

    Type: Component method
    This method iterates through all the items in the hash and calls the
    callback function for each of them.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_apply (
    ipr_dict_table_t * self,            //  Table to iterate
    ipr_dict_table_callback_fn * callback,   //  Not documented
    void * argument                     //  Arbitrary argument pointer
)
{

size_t
    pos;
ipr_dict_t
    *item;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_APPLY))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_apply_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" callback=\"%pp\""
" argument=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, callback, argument);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_APPLY))
    icl_trace_record (NULL, ipr_dict_table_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_APPLY))
    icl_stats_inc ("ipr_dict_table_apply", &s_ipr_dict_table_apply_stats);
#endif


//
IPR_DICT_TABLE_ASSERT_SANE (self);
for (pos = 0; pos != self->max_items; pos ++) {
    item = self->table_items [pos];
    while (item) {
        callback (item, argument);
        item = item->table_next;
    }
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_APPLY))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_APPLY))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_apply_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" callback=\"%pp\""
" argument=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, callback, argument);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_dict_table_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_TERMINATE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_TERMINATE))
    icl_trace_record (NULL, ipr_dict_table_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_TERMINATE))
    icl_stats_inc ("ipr_dict_table_terminate", &s_ipr_dict_table_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_TERMINATE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_TERMINATE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_terminate_finish"
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
    ipr_dict_table_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_dict_table_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_SHOW))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SHOW))
    icl_trace_record (NULL, ipr_dict_table_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SHOW))
    icl_stats_inc ("ipr_dict_table_show", &s_ipr_dict_table_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_dict_table zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    if (self->history_last > IPR_DICT_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_DICT_TABLE_HISTORY_LENGTH;
        self->history_last %= IPR_DICT_TABLE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_DICT_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_dict_table>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SHOW))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_SHOW))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_show_finish"
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
    ipr_dict_table_destroy

    Type: Component method
    Destroys a ipr_dict_table_t object. Takes the address of a
    ipr_dict_table_t reference (a pointer to a pointer) and nullifies the
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
    ipr_dict_table_destroy_ (
    ipr_dict_table_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_dict_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_DESTROY_PUBLIC))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_dict_table_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_dict_table_destroy", &s_ipr_dict_table_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_dict_table_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_dict_table object");
        ipr_dict_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_dict_table_free_ ((ipr_dict_table_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_DESTROY_PUBLIC))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_destroy_public_finish"
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
    ipr_dict_table_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_dict_table_t *
    ipr_dict_table_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_dict_table_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_ALLOC))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_ALLOC))
    icl_trace_record (NULL, ipr_dict_table_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_ALLOC))
    icl_stats_inc ("ipr_dict_table_alloc", &s_ipr_dict_table_alloc_stats);
#endif

self = (ipr_dict_table_t *) icl_mem_alloc_ (sizeof (ipr_dict_table_t), file, line);
if (self)
    memset (self, 0, sizeof (ipr_dict_table_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_ALLOC))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_ALLOC))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_alloc_finish"
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
    ipr_dict_table_free

    Type: Component method
    Freess a ipr_dict_table_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_dict_table_free_ (
    ipr_dict_table_t * self,            //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_FREE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FREE))
    icl_trace_record (NULL, ipr_dict_table_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_FREE))
    icl_stats_inc ("ipr_dict_table_free", &s_ipr_dict_table_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (ipr_dict_table_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_dict_table_t));
        self->object_tag = IPR_DICT_TABLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FREE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_FREE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_free_finish"
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
    ipr_dict_table_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_dict_table_t *
    ipr_dict_table_link_ (
    ipr_dict_table_t * self,            //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_LINK))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_LINK))
    icl_trace_record (NULL, ipr_dict_table_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_LINK))
    icl_stats_inc ("ipr_dict_table_link", &s_ipr_dict_table_link_stats);
#endif

    if (self) {
        IPR_DICT_TABLE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_LINK))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_LINK))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_link_finish"
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
    ipr_dict_table_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_unlink_ (
    ipr_dict_table_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
    int
        history_last;
#endif

    ipr_dict_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_UNLINK))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_UNLINK))
    icl_trace_record (NULL, ipr_dict_table_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_UNLINK))
    icl_stats_inc ("ipr_dict_table_unlink", &s_ipr_dict_table_unlink_stats);
#endif

    if (self) {
        IPR_DICT_TABLE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_dict_table object");
            ipr_dict_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_DICT_TABLE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_DICT_TABLE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_dict_table_annihilate_ (self_p, file, line);
        ipr_dict_table_free_ ((ipr_dict_table_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_UNLINK))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_UNLINK))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_unlink_finish"
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
    ipr_dict_table_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_SHOW_ANIMATION))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_dict_table_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_SHOW_ANIMATION))
    icl_stats_inc ("ipr_dict_table_show_animation", &s_ipr_dict_table_show_animation_stats);
#endif

ipr_dict_table_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_SHOW_ANIMATION))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_show_animation_finish"
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
    ipr_dict_table_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dict_table_new_in_scope_ (
    ipr_dict_table_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE)  ||  defined (BASE_ANIMATE_IPR_DICT_TABLE_NEW_IN_SCOPE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_dict_table_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DICT_TABLE)  ||  defined (BASE_STATS_IPR_DICT_TABLE_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_dict_table_new_in_scope", &s_ipr_dict_table_new_in_scope_stats);
#endif

*self_p = ipr_dict_table_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_dict_table_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_dict_table_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE)   || defined (BASE_ANIMATE_IPR_DICT_TABLE_NEW_IN_SCOPE))
    if (ipr_dict_table_animating)
        icl_console_print ("<ipr_dict_table_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DICT_TABLE)   || defined (BASE_TRACE_IPR_DICT_TABLE_NEW)   || defined (BASE_TRACE_IPR_DICT_TABLE_DESTROY)   || defined (BASE_TRACE_IPR_DICT_TABLE_INSERT)   || defined (BASE_TRACE_IPR_DICT_TABLE_REMOVE)   || defined (BASE_TRACE_IPR_DICT_TABLE_LOOKUP)   || defined (BASE_TRACE_IPR_DICT_TABLE_MATCHES)   || defined (BASE_TRACE_IPR_DICT_TABLE_TEMPLATE)   || defined (BASE_TRACE_IPR_DICT_TABLE_EXPORT)   || defined (BASE_TRACE_IPR_DICT_TABLE_IMPORT)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_LOAD)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_SAVE)   || defined (BASE_TRACE_IPR_DICT_TABLE_HEADERS_SEARCH)   || defined (BASE_TRACE_IPR_DICT_TABLE_URI_LOAD)   || defined (BASE_TRACE_IPR_DICT_TABLE_PROPS_LOAD)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_LOAD)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_SAVE)   || defined (BASE_TRACE_IPR_DICT_TABLE_FILE_SYNC)   || defined (BASE_TRACE_IPR_DICT_TABLE_SELFTEST)   || defined (BASE_TRACE_IPR_DICT_TABLE_SEARCH)   || defined (BASE_TRACE_IPR_DICT_TABLE_APPLY)   || defined (BASE_TRACE_IPR_DICT_TABLE_TERMINATE)   || defined (BASE_TRACE_IPR_DICT_TABLE_SHOW)   || defined (BASE_TRACE_IPR_DICT_TABLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_DICT_TABLE_ALLOC)   || defined (BASE_TRACE_IPR_DICT_TABLE_FREE)   || defined (BASE_TRACE_IPR_DICT_TABLE_LINK)   || defined (BASE_TRACE_IPR_DICT_TABLE_UNLINK)   || defined (BASE_TRACE_IPR_DICT_TABLE_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_DICT_TABLE_NEW_IN_SCOPE) )
void
ipr_dict_table_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "insert"; break;
        case 4: method_name = "remove"; break;
        case 5: method_name = "lookup"; break;
        case 6: method_name = "matches"; break;
        case 7: method_name = "template"; break;
        case 8: method_name = "export"; break;
        case 9: method_name = "import"; break;
        case 10: method_name = "headers load"; break;
        case 11: method_name = "headers save"; break;
        case 12: method_name = "headers search"; break;
        case 13: method_name = "uri load"; break;
        case 14: method_name = "props load"; break;
        case 15: method_name = "file load"; break;
        case 16: method_name = "file save"; break;
        case 17: method_name = "file sync"; break;
        case 18: method_name = "selftest"; break;
        case 19: method_name = "search"; break;
        case 20: method_name = "apply"; break;
        case 21: method_name = "terminate"; break;
        case 22: method_name = "show"; break;
        case 23: method_name = "destroy public"; break;
        case 24: method_name = "alloc"; break;
        case 25: method_name = "free"; break;
        case 26: method_name = "link"; break;
        case 27: method_name = "unlink"; break;
        case 28: method_name = "show animation"; break;
        case 29: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_dict_table %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

static inline unsigned int
s_key_hash (char * key, size_t hash_size)
{
    uint
        key_hash = 0;

    //  Torek hashing function
    while (*key) {
        key_hash *= 33;
        key_hash += *key;
        key++;
    }
    key_hash %= hash_size;
    return (key_hash);
}

static inline Bool
s_key_equal (char * key1, char * key2)
{
    return (streq (key1, key2));
}

static int
s_ipr_dict_table_insert (ipr_dict_table_t *self, ipr_dict_t *item, char * key)
{
    qbyte
        index,
        new_index;
    ipr_dict_t
        *current_item,
        *next_item;
    int
        rc = 0;

    if (self->nbr_items >= self->max_items * IPR_DICT_TABLE_LOAD_FACTOR / 100) {

        //  Load factor of hash table was exceeded
        //  We need to increase its size by GROWTH_FACTOR and rebuild it
        ipr_dict_t
            **new_items;
        size_t
            new_max_items;

        //  Create new hash table
        new_max_items = self->max_items * IPR_DICT_TABLE_GROWTH_FACTOR / 100;
        new_items = icl_mem_alloc (sizeof (ipr_dict_t*) * new_max_items);
        assert (new_items);
        memset (new_items, 0, sizeof (ipr_dict_t*) * new_max_items);

        //  Move all items to the new hash table
        for (index = 0; index != self->max_items; index++) {
            current_item = self->table_items [index];
            while (current_item) {
                next_item = current_item->table_next;
                new_index = s_key_hash (current_item->key, new_max_items);
                current_item->table_index = new_index;
                current_item->table_next = new_items [new_index];
                new_items [new_index] = current_item;
                current_item = next_item;
            }
        }

        //  Destroy old hash table
        icl_mem_free (self->table_items);
        self->table_items = new_items;
        self->max_items = new_max_items;
    }

    //  Insert new item itself
    index = s_key_hash (key, self->max_items);
    current_item = self->table_items [index];
    while (current_item) {
        if (s_key_equal (current_item->key, key)) {
            //  Attempted duplicate insertion
            rc = -1;
            break;
        }
        current_item = current_item->table_next;
    }
    if (!current_item) {
        item->table_head = self;
        item->table_index = index;
        item->table_next = self->table_items [index];
        self->table_items [index] = item;
        icl_shortstr_cpy (item->key, key);
        self->nbr_items++;
    }
    return rc;
}

static ipr_dict_t *
s_ipr_dict_table_lookup (ipr_dict_table_t *self, char * key)
{
    qbyte
        index;
    ipr_dict_t
        *item;

    index = s_key_hash (key, self->max_items);
    item = self->table_items [index];

    while (item) {
        if (s_key_equal (item->key, key))
            break;
        item = item->table_next;
    }
    return item;
}

static void
s_ipr_dict_table_remove (ipr_dict_t *item)
{
    ipr_dict_t
        *current_item,
        **prev_item;

    prev_item = &(item->table_head->table_items [item->table_index]);
    current_item = item->table_head->table_items [item->table_index];

    while (current_item) {
        if (current_item == item)
            break;
        prev_item = &(current_item->table_next);
        current_item = current_item->table_next;
    }
    assert (current_item == item);

    if (item) {
        item->table_head->nbr_items--;
        *prev_item = item->table_next;
        item->table_head = NULL;
        item->table_index = 0;
        item->table_next = NULL;
        icl_shortstr_cpy (item->key, "");
    }
}

static void
s_ipr_dict_table_purge (ipr_dict_table_t *self)
{
    uint
        table_idx;
    ipr_dict_t
        *current_item,
        *next_item;

    for (table_idx = 0; table_idx < self->max_items; table_idx++) {
        current_item = self->table_items [table_idx];
        while (current_item) {
            next_item = current_item->table_next;
            s_ipr_dict_table_remove (current_item);
            ipr_dict_destroy (&current_item);
            current_item = next_item;
        }
    }
}

//  Embed the version information in the resulting binary                      

char *ipr_dict_table_version_start  = "VeRsIoNsTaRt:ipc";
char *ipr_dict_table_component     = "ipr_dict_table ";
char *ipr_dict_table_version       = "1.0 ";
char *ipr_dict_table_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_dict_table_filename      = "ipr_dict_table.icl ";
char *ipr_dict_table_builddate     = "2009/02/19 ";
char *ipr_dict_table_version_end   = "VeRsIoNeNd:ipc";

