/*---------------------------------------------------------------------------
    smt_signal_table.c - smt_signal_table component

    This class implements the hash table container for smt_signal
    Generated from smt_signal_table.icl by icl_gen using GSL/4.
    
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
#include "smt_signal_table.h"           //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_signal_table_t

//  Shorthands for class methods                                               

#define self_new            smt_signal_table_new
#define self_annihilate     smt_signal_table_annihilate
#define self_selftest       smt_signal_table_selftest
#define self_insert         smt_signal_table_insert
#define self_remove         smt_signal_table_remove
#define self_search         smt_signal_table_search
#define self_apply          smt_signal_table_apply
#define self_terminate      smt_signal_table_terminate
#define self_show           smt_signal_table_show
#define self_destroy        smt_signal_table_destroy
#define self_alloc          smt_signal_table_alloc
#define self_free           smt_signal_table_free
#define self_read_lock      smt_signal_table_read_lock
#define self_write_lock     smt_signal_table_write_lock
#define self_unlock         smt_signal_table_unlock
#define self_cache_initialise  smt_signal_table_cache_initialise
#define self_cache_purge    smt_signal_table_cache_purge
#define self_cache_terminate  smt_signal_table_cache_terminate
#define self_show_animation  smt_signal_table_show_animation
#define self_new_in_scope   smt_signal_table_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_NEW))
static icl_stats_t *s_smt_signal_table_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_DESTROY))
static icl_stats_t *s_smt_signal_table_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SELFTEST))
static icl_stats_t *s_smt_signal_table_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_INSERT))
static icl_stats_t *s_smt_signal_table_insert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_REMOVE))
static icl_stats_t *s_smt_signal_table_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SEARCH))
static icl_stats_t *s_smt_signal_table_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_APPLY))
static icl_stats_t *s_smt_signal_table_apply_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_TERMINATE))
static icl_stats_t *s_smt_signal_table_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SHOW))
static icl_stats_t *s_smt_signal_table_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_DESTROY_PUBLIC))
static icl_stats_t *s_smt_signal_table_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_ALLOC))
static icl_stats_t *s_smt_signal_table_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_FREE))
static icl_stats_t *s_smt_signal_table_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_READ_LOCK))
static icl_stats_t *s_smt_signal_table_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_WRITE_LOCK))
static icl_stats_t *s_smt_signal_table_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_UNLOCK))
static icl_stats_t *s_smt_signal_table_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_CACHE_INITIALISE))
static icl_stats_t *s_smt_signal_table_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_CACHE_PURGE))
static icl_stats_t *s_smt_signal_table_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_CACHE_TERMINATE))
static icl_stats_t *s_smt_signal_table_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SHOW_ANIMATION))
static icl_stats_t *s_smt_signal_table_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_NEW_IN_SCOPE))
static icl_stats_t *s_smt_signal_table_new_in_scope_stats = NULL;
#endif
static void
    smt_signal_table_annihilate (
smt_signal_table_t * ( * self_p )       //  Reference to object reference
);

#define smt_signal_table_alloc()        smt_signal_table_alloc_ (__FILE__, __LINE__)
static smt_signal_table_t *
    smt_signal_table_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_signal_table_free (
smt_signal_table_t * self               //  Object reference
);

static void
    smt_signal_table_cache_initialise (
void);

static void
    smt_signal_table_cache_purge (
void);

static void
    smt_signal_table_cache_terminate (
void);

Bool
    smt_signal_table_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


//  Hash support functions
static inline unsigned int
    s_key_hash (int key, size_t hash_size);
static inline Bool
    s_key_equal (int key1, int key2);

//  Table functions to be called once locks are in place
static int
    s_smt_signal_table_insert (smt_signal_table_t *self, smt_signal_t *item, int key);
static smt_signal_t *
    s_smt_signal_table_lookup (smt_signal_table_t *self, int key);
static void
    s_smt_signal_table_remove (smt_signal_t *item);
static void
    s_smt_signal_table_purge (smt_signal_table_t *self);
/*  -------------------------------------------------------------------------
    smt_signal_table_new

    Type: Component method
    Creates and initialises a new smt_signal_table_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

smt_signal_table_t *
    smt_signal_table_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    smt_signal_table_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_NEW))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_NEW))
    icl_trace_record (1, smt_signal_table_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_NEW))
    icl_stats_inc ("smt_signal_table_new", &s_smt_signal_table_new_stats);
#endif

    self = smt_signal_table_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_SIGNAL_TABLE_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_signal_table_show_);
#endif

self->max_items = SMT_SIGNAL_TABLE_INITIAL_SIZE;
self->table_items = icl_mem_alloc (sizeof (smt_signal_t*) *
    SMT_SIGNAL_TABLE_INITIAL_SIZE);
assert (self->table_items);
memset (self->table_items, 0, sizeof (smt_signal_t*) *
    SMT_SIGNAL_TABLE_INITIAL_SIZE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_NEW))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_NEW))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_new_finish"
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
    smt_signal_table_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_table_annihilate (
    smt_signal_table_t * ( * self_p )   //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    smt_signal_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_DESTROY))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_DESTROY))
    icl_trace_record (1, smt_signal_table_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_DESTROY))
    icl_stats_inc ("smt_signal_table_annihilate", &s_smt_signal_table_annihilate_stats);
#endif

    SMT_SIGNAL_TABLE_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

s_smt_signal_table_purge (self);
if (self->table_items)
    icl_mem_free (self->table_items);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_DESTROY))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_DESTROY))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_destroy_finish"
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
    smt_signal_table_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_table_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SELFTEST))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SELFTEST))
    icl_trace_record (1, smt_signal_table_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SELFTEST))
    icl_stats_inc ("smt_signal_table_selftest", &s_smt_signal_table_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SELFTEST))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SELFTEST))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_selftest_finish"
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
    smt_signal_table_insert

    Type: Component method
    Accepts a smt_signal_table_t reference and returns zero in case of success,
    1 in case of errors.
    Insert a new item into the hash table if possible. If successful,
    the number of links to the item is automatically incremented.
    Trying to insert a duplicate key will result in nothing being inserted.
    -------------------------------------------------------------------------
 */

int
    smt_signal_table_insert (
    smt_signal_table_t * self,          //  Reference to object
    int key,                            //  Hash key
    smt_signal_t * item                 //  Item to insert
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_INSERT))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_insert_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_INSERT))
    icl_trace_record (1, smt_signal_table_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_INSERT))
    icl_stats_inc ("smt_signal_table_insert", &s_smt_signal_table_insert_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

SMT_SIGNAL_TABLE_ASSERT_SANE (self);

//
if (item->table_head) {
    if (item->table_head != self) {
        icl_console_print ("E: smt_signal item inserted into multiple table containers");
        assert (item->table_head == self);
    }
    s_smt_signal_table_remove (item);
}
rc = s_smt_signal_table_insert (self, item, key);


#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_INSERT))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_INSERT))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_insert_finish"
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
    smt_signal_table_remove

    Type: Component method
    Remove an item from a hash table.  If the item was not in any hash
    table, this function does nothing.
    -------------------------------------------------------------------------
 */

int
    smt_signal_table_remove (
    smt_signal_t * item                 //  Item to remove
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    smt_signal_table_t *
        self = item->table_head;        //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_REMOVE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_REMOVE))
    icl_trace_record (1, smt_signal_table_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_REMOVE))
    icl_stats_inc ("smt_signal_table_remove", &s_smt_signal_table_remove_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->table_head) { //      Catch case where item moved
    s_smt_signal_table_remove (item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_REMOVE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_REMOVE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_remove_finish"
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
    smt_signal_table_search

    Type: Component method
    Find object by key in the hash table. Returns reference to object
    if found, else null.
    -------------------------------------------------------------------------
 */

smt_signal_t *
    smt_signal_table_search (
    smt_signal_table_t * self,          //  Table to search
    int key                             //  Hash key
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    smt_signal_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SEARCH))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_search_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SEARCH))
    icl_trace_record (1, smt_signal_table_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SEARCH))
    icl_stats_inc ("smt_signal_table_search", &s_smt_signal_table_search_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

//
SMT_SIGNAL_TABLE_ASSERT_SANE (self);
if (key)
    item = s_smt_signal_table_lookup (self, key);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SEARCH))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SEARCH))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_search_finish"
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
    smt_signal_table_apply

    Type: Component method
    This method iterates through all the items in the hash and calls the
    callback function for each of them.
    -------------------------------------------------------------------------
 */

void
    smt_signal_table_apply (
    smt_signal_table_t * self,          //  Table to iterate
    smt_signal_table_callback_fn * callback,   //  Not documented
    void * argument                     //  Arbitrary argument pointer
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

size_t
    pos;
smt_signal_t
    *item;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_APPLY))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_apply_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_APPLY))
    icl_trace_record (1, smt_signal_table_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_APPLY))
    icl_stats_inc ("smt_signal_table_apply", &s_smt_signal_table_apply_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

//
SMT_SIGNAL_TABLE_ASSERT_SANE (self);
for (pos = 0; pos != self->max_items; pos ++) {
    item = self->table_items [pos];
    while (item) {
        callback (item, argument);
        item = item->table_next;
    }
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_APPLY))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_APPLY))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_apply_finish"
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
    smt_signal_table_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_table_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_TERMINATE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_TERMINATE))
    icl_trace_record (1, smt_signal_table_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_TERMINATE))
    icl_stats_inc ("smt_signal_table_terminate", &s_smt_signal_table_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_TERMINATE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_TERMINATE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_terminate_finish"
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
    smt_signal_table_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_table_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
smt_signal_table_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SHOW))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SHOW))
    icl_trace_record (1, smt_signal_table_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SHOW))
    icl_stats_inc ("smt_signal_table_show", &s_smt_signal_table_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <smt_signal_table file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SHOW))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SHOW))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_show_finish"
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
    smt_signal_table_destroy

    Type: Component method
    Destroys a smt_signal_table_t object. Takes the address of a
    smt_signal_table_t reference (a pointer to a pointer) and nullifies the
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
    smt_signal_table_destroy_ (
    smt_signal_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_signal_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_DESTROY_PUBLIC))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_DESTROY_PUBLIC))
    icl_trace_record (1, smt_signal_table_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_DESTROY_PUBLIC))
    icl_stats_inc ("smt_signal_table_destroy", &s_smt_signal_table_destroy_stats);
#endif

if (self) {
    smt_signal_table_annihilate (self_p);
    smt_signal_table_free ((smt_signal_table_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_DESTROY_PUBLIC))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_DESTROY_PUBLIC))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_destroy_public_finish"
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
    smt_signal_table_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_signal_table_t *
    smt_signal_table_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_signal_table_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_ALLOC))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_ALLOC))
    icl_trace_record (1, smt_signal_table_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_ALLOC))
    icl_stats_inc ("smt_signal_table_alloc", &s_smt_signal_table_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_signal_table_cache_initialise ();

self = (smt_signal_table_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (smt_signal_table_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_ALLOC))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_ALLOC))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_alloc_finish"
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
    smt_signal_table_free

    Type: Component method
    Freess a smt_signal_table_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_signal_table_free (
    smt_signal_table_t * self           //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_FREE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_FREE))
    icl_trace_record (1, smt_signal_table_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_FREE))
    icl_stats_inc ("smt_signal_table_free", &s_smt_signal_table_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (smt_signal_table_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (smt_signal_table_t));
        self->object_tag = SMT_SIGNAL_TABLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_FREE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_FREE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_free_finish"
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
    smt_signal_table_read_lock

    Type: Component method
    Accepts a smt_signal_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_signal_table_read_lock (
    smt_signal_table_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_READ_LOCK))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_READ_LOCK))
    icl_trace_record (1, smt_signal_table_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_READ_LOCK))
    icl_stats_inc ("smt_signal_table_read_lock", &s_smt_signal_table_read_lock_stats);
#endif

SMT_SIGNAL_TABLE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_READ_LOCK))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_READ_LOCK))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_read_lock_finish"
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
    smt_signal_table_write_lock

    Type: Component method
    Accepts a smt_signal_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_signal_table_write_lock (
    smt_signal_table_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_WRITE_LOCK))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_WRITE_LOCK))
    icl_trace_record (1, smt_signal_table_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_WRITE_LOCK))
    icl_stats_inc ("smt_signal_table_write_lock", &s_smt_signal_table_write_lock_stats);
#endif

SMT_SIGNAL_TABLE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_WRITE_LOCK))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_WRITE_LOCK))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_write_lock_finish"
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
    smt_signal_table_unlock

    Type: Component method
    Accepts a smt_signal_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    smt_signal_table_unlock (
    smt_signal_table_t * self           //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_UNLOCK))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_UNLOCK))
    icl_trace_record (1, smt_signal_table_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_UNLOCK))
    icl_stats_inc ("smt_signal_table_unlock", &s_smt_signal_table_unlock_stats);
#endif

SMT_SIGNAL_TABLE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_UNLOCK))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_UNLOCK))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_unlock_finish"
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
    smt_signal_table_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_signal_table_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_CACHE_INITIALISE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_INITIALISE))
    icl_trace_record (1, smt_signal_table_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_CACHE_INITIALISE))
    icl_stats_inc ("smt_signal_table_cache_initialise", &s_smt_signal_table_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_signal_table_t));
icl_system_register (smt_signal_table_cache_purge, smt_signal_table_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_INITIALISE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_CACHE_INITIALISE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_cache_initialise_finish"
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
    smt_signal_table_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_table_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_CACHE_PURGE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_PURGE))
    icl_trace_record (1, smt_signal_table_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_CACHE_PURGE))
    icl_stats_inc ("smt_signal_table_cache_purge", &s_smt_signal_table_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_PURGE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_CACHE_PURGE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_cache_purge_finish"
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
    smt_signal_table_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_signal_table_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_CACHE_TERMINATE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_TERMINATE))
    icl_trace_record (1, smt_signal_table_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_CACHE_TERMINATE))
    icl_stats_inc ("smt_signal_table_cache_terminate", &s_smt_signal_table_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_TERMINATE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_CACHE_TERMINATE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_cache_terminate_finish"
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
    smt_signal_table_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_signal_table_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SHOW_ANIMATION))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SHOW_ANIMATION))
    icl_trace_record (1, smt_signal_table_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_SHOW_ANIMATION))
    icl_stats_inc ("smt_signal_table_show_animation", &s_smt_signal_table_show_animation_stats);
#endif

smt_signal_table_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SHOW_ANIMATION))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_SHOW_ANIMATION))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_show_animation_finish"
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
    smt_signal_table_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_signal_table_new_in_scope_ (
    smt_signal_table_t * * self_p,      //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)  ||  defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_NEW_IN_SCOPE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_NEW_IN_SCOPE))
    icl_trace_record (1, smt_signal_table_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE)  ||  defined (BASE_STATS_SMT_SIGNAL_TABLE_NEW_IN_SCOPE))
    icl_stats_inc ("smt_signal_table_new_in_scope", &s_smt_signal_table_new_in_scope_stats);
#endif

*self_p = smt_signal_table_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_signal_table_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_NEW_IN_SCOPE))
    icl_trace_record (1, smt_signal_table_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE)   || defined (BASE_ANIMATE_SMT_SIGNAL_TABLE_NEW_IN_SCOPE))
    if (smt_signal_table_animating)
        icl_console_print ("<smt_signal_table_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_NEW)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_DESTROY)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SELFTEST)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_INSERT)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_REMOVE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SEARCH)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_APPLY)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_TERMINATE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SHOW)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_ALLOC)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_FREE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_READ_LOCK)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_WRITE_LOCK)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_UNLOCK)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_PURGE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_SIGNAL_TABLE_NEW_IN_SCOPE) )
void
smt_signal_table_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "insert"; break;
        case 5: method_name = "remove"; break;
        case 6: method_name = "search"; break;
        case 7: method_name = "apply"; break;
        case 8: method_name = "terminate"; break;
        case 9: method_name = "show"; break;
        case 10: method_name = "destroy public"; break;
        case 11: method_name = "alloc"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "read lock"; break;
        case 14: method_name = "write lock"; break;
        case 15: method_name = "unlock"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "show animation"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_signal_table %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

static inline unsigned int
s_key_hash (int key, size_t hash_size)
{
    return ((uint) (((size_t) key) % hash_size));
}

static inline Bool
s_key_equal (int key1, int key2)
{
    return (key1 == key2);
}

static int
s_smt_signal_table_insert (smt_signal_table_t *self, smt_signal_t *item, int key)
{
    qbyte
        index,
        new_index;
    smt_signal_t
        *current_item,
        *next_item;
    int
        rc = 0;

    if (self->nbr_items >= self->max_items * SMT_SIGNAL_TABLE_LOAD_FACTOR / 100) {

        //  Load factor of hash table was exceeded
        //  We need to increase its size by GROWTH_FACTOR and rebuild it
        smt_signal_t
            **new_items;
        size_t
            new_max_items;

        //  Create new hash table
        new_max_items = self->max_items * SMT_SIGNAL_TABLE_GROWTH_FACTOR / 100;
        new_items = icl_mem_alloc (sizeof (smt_signal_t*) * new_max_items);
        assert (new_items);
        memset (new_items, 0, sizeof (smt_signal_t*) * new_max_items);

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
        item->key = key;
        self->nbr_items++;
    }
    return rc;
}

static smt_signal_t *
s_smt_signal_table_lookup (smt_signal_table_t *self, int key)
{
    qbyte
        index;
    smt_signal_t
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
s_smt_signal_table_remove (smt_signal_t *item)
{
    smt_signal_t
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
        item->key = 0;
    }
}

static void
s_smt_signal_table_purge (smt_signal_table_t *self)
{
    uint
        table_idx;
    smt_signal_t
        *current_item,
        *next_item;

    for (table_idx = 0; table_idx < self->max_items; table_idx++) {
        current_item = self->table_items [table_idx];
        while (current_item) {
            next_item = current_item->table_next;
            s_smt_signal_table_remove (current_item);
            smt_signal_destroy (&current_item);
            current_item = next_item;
        }
    }
}

//  Embed the version information in the resulting binary                      

char *smt_signal_table_version_start  = "VeRsIoNsTaRt:ipc";
char *smt_signal_table_component   = "smt_signal_table ";
char *smt_signal_table_version     = "1.0 ";
char *smt_signal_table_copyright   = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_signal_table_filename    = "smt_signal_table.icl ";
char *smt_signal_table_builddate   = "2009/02/19 ";
char *smt_signal_table_version_end  = "VeRsIoNeNd:ipc";

