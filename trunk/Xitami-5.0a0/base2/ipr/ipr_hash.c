/*---------------------------------------------------------------------------
    ipr_hash.c - ipr_hash component

Implements a loose-reference hash with no locking, for use in lock-free agents.
The hash is indexed by a string key, and holds a void pointer reference.  Hash
items are reference counted, so use unlink and destroy appropriately.
    Generated from ipr_hash.icl by icl_gen using GSL/4.
    
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
#include "ipr_hash.h"                   //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_hash_t

//  Shorthands for class methods                                               

#define self_new            ipr_hash_new
#define self_insert         ipr_hash_insert
#define self_lookup         ipr_hash_lookup
#define self_delete         ipr_hash_delete
#define self_selftest       ipr_hash_selftest
#define self_remove_from_all_containers  ipr_hash_remove_from_all_containers
#define self_show           ipr_hash_show
#define self_terminate      ipr_hash_terminate
#define self_destroy        ipr_hash_destroy
#define self_annihilate     ipr_hash_annihilate
#define self_alloc          ipr_hash_alloc
#define self_free           ipr_hash_free
#define self_link           ipr_hash_link
#define self_unlink         ipr_hash_unlink
#define self_cache_initialise  ipr_hash_cache_initialise
#define self_cache_purge    ipr_hash_cache_purge
#define self_cache_terminate  ipr_hash_cache_terminate
#define self_show_animation  ipr_hash_show_animation
#define self_new_in_scope   ipr_hash_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_NEW))
static icl_stats_t *s_ipr_hash_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_INSERT))
static icl_stats_t *s_ipr_hash_insert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_LOOKUP))
static icl_stats_t *s_ipr_hash_lookup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_DELETE))
static icl_stats_t *s_ipr_hash_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_SELFTEST))
static icl_stats_t *s_ipr_hash_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_hash_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_SHOW))
static icl_stats_t *s_ipr_hash_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_TERMINATE))
static icl_stats_t *s_ipr_hash_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_hash_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_DESTROY))
static icl_stats_t *s_ipr_hash_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_ALLOC))
static icl_stats_t *s_ipr_hash_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_FREE))
static icl_stats_t *s_ipr_hash_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_LINK))
static icl_stats_t *s_ipr_hash_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_UNLINK))
static icl_stats_t *s_ipr_hash_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_CACHE_INITIALISE))
static icl_stats_t *s_ipr_hash_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_CACHE_PURGE))
static icl_stats_t *s_ipr_hash_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_CACHE_TERMINATE))
static icl_stats_t *s_ipr_hash_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_SHOW_ANIMATION))
static icl_stats_t *s_ipr_hash_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_hash_new_in_scope_stats = NULL;
#endif
#define ipr_hash_annihilate(self)       ipr_hash_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_hash_annihilate_ (
ipr_hash_t * ( * self_p ),              //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_hash_alloc()                ipr_hash_alloc_ (__FILE__, __LINE__)
static ipr_hash_t *
    ipr_hash_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_hash_free(self)             ipr_hash_free_ (self, __FILE__, __LINE__)
static void
    ipr_hash_free_ (
ipr_hash_t * self,                      //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    ipr_hash_cache_initialise (
void);

static void
    ipr_hash_cache_purge (
void);

static void
    ipr_hash_cache_terminate (
void);

Bool
    ipr_hash_animating = TRUE;          //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_hash_new

    Type: Component method
    Creates and initialises a new ipr_hash_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

ipr_hash_t *
    ipr_hash_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_hash_table_t * table,           //  Table to insert into
    char * key,                         //  Hash key
    void * data                         //  Not documented
)
{
    ipr_hash_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_NEW))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_NEW))
    icl_trace_record (NULL, ipr_hash_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_NEW))
    icl_stats_inc ("ipr_hash_new", &s_ipr_hash_new_stats);
#endif

    self = ipr_hash_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_HASH_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_hash_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
//
self->data = data;
if (table && self && ipr_hash_table_insert (table, key, self))
    ipr_hash_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_NEW))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_NEW))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, data, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_hash_insert

    Type: Component method
    Creates a new hash for the specified data value, does not return
    a hash item.  Asserts that the specified key does not already
    exist.
    -------------------------------------------------------------------------
 */

void
    ipr_hash_insert (
    ipr_hash_table_t * table,           //  Not documented
    char * key,                         //  Not documented
    void * data                         //  Not documented
)
{
ipr_hash_t
    *hash;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_INSERT))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_insert_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_INSERT))
    icl_trace_record (NULL, ipr_hash_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_INSERT))
    icl_stats_inc ("ipr_hash_insert", &s_ipr_hash_insert_stats);
#endif

//
assert (!ipr_hash_table_search (table, key));
hash = ipr_hash_new (table, key, data);
ipr_hash_unlink (&hash);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_INSERT))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_INSERT))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_insert_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, data);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_hash_lookup

    Type: Component method
    Searches a hash table for a key value and returns the data reference if
    found, else null.
    -------------------------------------------------------------------------
 */

void *
    ipr_hash_lookup (
    ipr_hash_table_t * table,           //  Not documented
    char * key                          //  Not documented
)
{
ipr_hash_t
    *hash;
    void *
        data = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_LOOKUP))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_lookup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_LOOKUP))
    icl_trace_record (NULL, ipr_hash_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_LOOKUP))
    icl_stats_inc ("ipr_hash_lookup", &s_ipr_hash_lookup_stats);
#endif

hash = ipr_hash_table_search (table, key);
if (hash) {
    data = hash->data;
    ipr_hash_unlink (&hash);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_LOOKUP))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_LOOKUP))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_lookup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, data);
#endif


    return (data);
}
/*  -------------------------------------------------------------------------
    ipr_hash_delete

    Type: Component method
    Deletes the hash for the specified data value, does not return
    a hash item.  Asserts that the specified key alreadys exists.
    -------------------------------------------------------------------------
 */

void
    ipr_hash_delete (
    ipr_hash_table_t * table,           //  Not documented
    char * key                          //  Not documented
)
{
ipr_hash_t
    *hash;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_DELETE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_DELETE))
    icl_trace_record (NULL, ipr_hash_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_DELETE))
    icl_stats_inc ("ipr_hash_delete", &s_ipr_hash_delete_stats);
#endif

//
hash = ipr_hash_table_search (table, key);
assert (hash);
ipr_hash_destroy (&hash);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_DELETE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_DELETE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_hash_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_hash_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_SELFTEST))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_SELFTEST))
    icl_trace_record (NULL, ipr_hash_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_SELFTEST))
    icl_stats_inc ("ipr_hash_selftest", &s_ipr_hash_selftest_stats);
#endif

ipr_hash_table_t
    *table;
ipr_hash_t
    *hash;
char
    *some_data = "hello";

table = ipr_hash_table_new ();
hash = ipr_hash_new (table, "tmp_000000", some_data);
ipr_hash_unlink (&hash);

assert (ipr_hash_lookup (table, "tmp_000000") == some_data);
hash = ipr_hash_table_search (table, "tmp_000000");
assert (hash);
ipr_hash_destroy (&hash);
ipr_hash_table_destroy (&table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_SELFTEST))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_SELFTEST))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_selftest_finish"
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
    ipr_hash_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_hash_remove_from_all_containers (
    ipr_hash_t * self                   //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_hash_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_hash_remove_from_all_containers", &s_ipr_hash_remove_from_all_containers_stats);
#endif

IPR_HASH_ASSERT_SANE (self);
ipr_hash_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_remove_from_all_containers_finish"
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
    ipr_hash_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_hash_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_hash_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_SHOW))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_SHOW))
    icl_trace_record (NULL, ipr_hash_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_SHOW))
    icl_stats_inc ("ipr_hash_show", &s_ipr_hash_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_hash zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    if (self->history_last > IPR_HASH_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_HASH_HISTORY_LENGTH;
        self->history_last %= IPR_HASH_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_HASH_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_hash>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_SHOW))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_SHOW))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_show_finish"
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
    ipr_hash_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_hash_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_TERMINATE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_TERMINATE))
    icl_trace_record (NULL, ipr_hash_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_TERMINATE))
    icl_stats_inc ("ipr_hash_terminate", &s_ipr_hash_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_TERMINATE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_TERMINATE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_terminate_finish"
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
    ipr_hash_destroy

    Type: Component method
    Destroys a ipr_hash_t object. Takes the address of a
    ipr_hash_t reference (a pointer to a pointer) and nullifies the
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
    ipr_hash_destroy_ (
    ipr_hash_t * ( * self_p ),          //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_hash_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_DESTROY_PUBLIC))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_hash_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_hash_destroy", &s_ipr_hash_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_hash_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_hash object");
        ipr_hash_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_hash_free_ ((ipr_hash_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_DESTROY_PUBLIC))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_destroy_public_finish"
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
    ipr_hash_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_hash_annihilate_ (
    ipr_hash_t * ( * self_p ),          //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    int
        history_last;
#endif

    ipr_hash_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_DESTROY))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_DESTROY))
    icl_trace_record (NULL, ipr_hash_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_DESTROY))
    icl_stats_inc ("ipr_hash_annihilate", &s_ipr_hash_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_HASH_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_HASH_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_HASH_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_HASH_HISTORY_LENGTH] = self->links;
#endif

    IPR_HASH_ASSERT_SANE (self);
    ipr_hash_remove_from_all_containers (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_DESTROY))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_DESTROY))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_destroy_finish"
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
    ipr_hash_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_hash_t *
    ipr_hash_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_hash_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_ALLOC))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_ALLOC))
    icl_trace_record (NULL, ipr_hash_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_ALLOC))
    icl_stats_inc ("ipr_hash_alloc", &s_ipr_hash_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_hash_cache_initialise ();

self = (ipr_hash_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_hash_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_ALLOC))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_ALLOC))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_alloc_finish"
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
    ipr_hash_free

    Type: Component method
    Freess a ipr_hash_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_hash_free_ (
    ipr_hash_t * self,                  //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_FREE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_FREE))
    icl_trace_record (NULL, ipr_hash_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_FREE))
    icl_stats_inc ("ipr_hash_free", &s_ipr_hash_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_HASH_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_HASH_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_HASH_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_HASH_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (ipr_hash_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_hash_t));
        self->object_tag = IPR_HASH_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_FREE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_FREE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_free_finish"
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
    ipr_hash_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_hash_t *
    ipr_hash_link_ (
    ipr_hash_t * self,                  //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_LINK))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_LINK))
    icl_trace_record (NULL, ipr_hash_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_LINK))
    icl_stats_inc ("ipr_hash_link", &s_ipr_hash_link_stats);
#endif

    if (self) {
        IPR_HASH_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_HASH_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_HASH_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_HASH_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_HASH_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_LINK))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_LINK))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_link_finish"
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
    ipr_hash_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_hash_unlink_ (
    ipr_hash_t * ( * self_p ),          //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
    int
        history_last;
#endif

    ipr_hash_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_UNLINK))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_UNLINK))
    icl_trace_record (NULL, ipr_hash_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_UNLINK))
    icl_stats_inc ("ipr_hash_unlink", &s_ipr_hash_unlink_stats);
#endif

    if (self) {
        IPR_HASH_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_hash object");
            ipr_hash_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_HASH)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_HASH_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_HASH_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_HASH_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_HASH_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_hash_annihilate_ (self_p, file, line);
        ipr_hash_free_ ((ipr_hash_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_UNLINK))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_UNLINK))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_unlink_finish"
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
    ipr_hash_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_hash_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_CACHE_INITIALISE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_hash_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_CACHE_INITIALISE))
    icl_stats_inc ("ipr_hash_cache_initialise", &s_ipr_hash_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_hash_t));
icl_system_register (ipr_hash_cache_purge, ipr_hash_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_CACHE_INITIALISE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_cache_initialise_finish"
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
    ipr_hash_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_hash_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_CACHE_PURGE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_CACHE_PURGE))
    icl_trace_record (NULL, ipr_hash_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_CACHE_PURGE))
    icl_stats_inc ("ipr_hash_cache_purge", &s_ipr_hash_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_CACHE_PURGE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_CACHE_PURGE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_cache_purge_finish"
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
    ipr_hash_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_hash_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_CACHE_TERMINATE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_hash_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_CACHE_TERMINATE))
    icl_stats_inc ("ipr_hash_cache_terminate", &s_ipr_hash_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_CACHE_TERMINATE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_cache_terminate_finish"
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
    ipr_hash_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_hash_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_SHOW_ANIMATION))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_hash_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_SHOW_ANIMATION))
    icl_stats_inc ("ipr_hash_show_animation", &s_ipr_hash_show_animation_stats);
#endif

ipr_hash_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_SHOW_ANIMATION))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_show_animation_finish"
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
    ipr_hash_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_hash_new_in_scope_ (
    ipr_hash_t * * self_p,              //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_hash_table_t * table,           //  Table to insert into
    char * key,                         //  Hash key
    void * data                         //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_HASH)  ||  defined (BASE_ANIMATE_IPR_HASH_NEW_IN_SCOPE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, data);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_hash_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_HASH)  ||  defined (BASE_STATS_IPR_HASH_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_hash_new_in_scope", &s_ipr_hash_new_in_scope_stats);
#endif

*self_p = ipr_hash_new_ (file,line,table,key,data);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_hash_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_hash_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_HASH)   || defined (BASE_ANIMATE_IPR_HASH_NEW_IN_SCOPE))
    if (ipr_hash_animating)
        icl_console_print ("<ipr_hash_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" data=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, data, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_HASH)   || defined (BASE_TRACE_IPR_HASH_NEW)   || defined (BASE_TRACE_IPR_HASH_INSERT)   || defined (BASE_TRACE_IPR_HASH_LOOKUP)   || defined (BASE_TRACE_IPR_HASH_DELETE)   || defined (BASE_TRACE_IPR_HASH_SELFTEST)   || defined (BASE_TRACE_IPR_HASH_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_HASH_SHOW)   || defined (BASE_TRACE_IPR_HASH_TERMINATE)   || defined (BASE_TRACE_IPR_HASH_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_HASH_DESTROY)   || defined (BASE_TRACE_IPR_HASH_ALLOC)   || defined (BASE_TRACE_IPR_HASH_FREE)   || defined (BASE_TRACE_IPR_HASH_LINK)   || defined (BASE_TRACE_IPR_HASH_UNLINK)   || defined (BASE_TRACE_IPR_HASH_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_HASH_CACHE_PURGE)   || defined (BASE_TRACE_IPR_HASH_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_HASH_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_HASH_NEW_IN_SCOPE) )
void
ipr_hash_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "insert"; break;
        case 3: method_name = "lookup"; break;
        case 4: method_name = "delete"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "remove from all containers"; break;
        case 7: method_name = "show"; break;
        case 8: method_name = "terminate"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "destroy"; break;
        case 11: method_name = "alloc"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "link"; break;
        case 14: method_name = "unlink"; break;
        case 15: method_name = "cache initialise"; break;
        case 16: method_name = "cache purge"; break;
        case 17: method_name = "cache terminate"; break;
        case 18: method_name = "show animation"; break;
        case 19: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_hash %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_hash_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_hash_component           = "ipr_hash ";
char *ipr_hash_version             = "1.0 ";
char *ipr_hash_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_hash_filename            = "ipr_hash.icl ";
char *ipr_hash_builddate           = "2009/02/19 ";
char *ipr_hash_version_end         = "VeRsIoNeNd:ipc";

