/*---------------------------------------------------------------------------
    icl_demo_hash_str_table.c - icl_demo_hash_str_table component

    This class implements the hash table container for icl_demo_hash_str
    Generated from icl_demo_hash_str_table.icl by icl_gen using GSL/4.
    
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
#include "icl_demo_hash_str_table.h"    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_demo_hash_str_table_t

//  Shorthands for class methods                                               

#define self_new            icl_demo_hash_str_table_new
#define self_annihilate     icl_demo_hash_str_table_annihilate
#define self_selftest       icl_demo_hash_str_table_selftest
#define self_insert         icl_demo_hash_str_table_insert
#define self_remove         icl_demo_hash_str_table_remove
#define self_search         icl_demo_hash_str_table_search
#define self_apply          icl_demo_hash_str_table_apply
#define self_terminate      icl_demo_hash_str_table_terminate
#define self_show           icl_demo_hash_str_table_show
#define self_destroy        icl_demo_hash_str_table_destroy
#define self_alloc          icl_demo_hash_str_table_alloc
#define self_free           icl_demo_hash_str_table_free
#define self_read_lock      icl_demo_hash_str_table_read_lock
#define self_write_lock     icl_demo_hash_str_table_write_lock
#define self_unlock         icl_demo_hash_str_table_unlock
#define self_link           icl_demo_hash_str_table_link
#define self_unlink         icl_demo_hash_str_table_unlink
#define self_cache_initialise  icl_demo_hash_str_table_cache_initialise
#define self_cache_purge    icl_demo_hash_str_table_cache_purge
#define self_cache_terminate  icl_demo_hash_str_table_cache_terminate
#define self_show_animation  icl_demo_hash_str_table_show_animation
#define self_new_in_scope   icl_demo_hash_str_table_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_NEW))
static icl_stats_t *s_icl_demo_hash_str_table_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_DESTROY))
static icl_stats_t *s_icl_demo_hash_str_table_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SELFTEST))
static icl_stats_t *s_icl_demo_hash_str_table_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_INSERT))
static icl_stats_t *s_icl_demo_hash_str_table_insert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_REMOVE))
static icl_stats_t *s_icl_demo_hash_str_table_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SEARCH))
static icl_stats_t *s_icl_demo_hash_str_table_search_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_APPLY))
static icl_stats_t *s_icl_demo_hash_str_table_apply_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_TERMINATE))
static icl_stats_t *s_icl_demo_hash_str_table_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SHOW))
static icl_stats_t *s_icl_demo_hash_str_table_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC))
static icl_stats_t *s_icl_demo_hash_str_table_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_ALLOC))
static icl_stats_t *s_icl_demo_hash_str_table_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_FREE))
static icl_stats_t *s_icl_demo_hash_str_table_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_READ_LOCK))
static icl_stats_t *s_icl_demo_hash_str_table_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK))
static icl_stats_t *s_icl_demo_hash_str_table_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_UNLOCK))
static icl_stats_t *s_icl_demo_hash_str_table_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_LINK))
static icl_stats_t *s_icl_demo_hash_str_table_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_UNLINK))
static icl_stats_t *s_icl_demo_hash_str_table_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE))
static icl_stats_t *s_icl_demo_hash_str_table_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE))
static icl_stats_t *s_icl_demo_hash_str_table_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE))
static icl_stats_t *s_icl_demo_hash_str_table_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION))
static icl_stats_t *s_icl_demo_hash_str_table_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE))
static icl_stats_t *s_icl_demo_hash_str_table_new_in_scope_stats = NULL;
#endif
#define icl_demo_hash_str_table_annihilate(self)  icl_demo_hash_str_table_annihilate_ (self, __FILE__, __LINE__)
static void
    icl_demo_hash_str_table_annihilate_ (
icl_demo_hash_str_table_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define icl_demo_hash_str_table_alloc()  icl_demo_hash_str_table_alloc_ (__FILE__, __LINE__)
static icl_demo_hash_str_table_t *
    icl_demo_hash_str_table_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define icl_demo_hash_str_table_free(self)  icl_demo_hash_str_table_free_ (self, __FILE__, __LINE__)
static void
    icl_demo_hash_str_table_free_ (
icl_demo_hash_str_table_t * self,       //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    icl_demo_hash_str_table_cache_initialise (
void);

static void
    icl_demo_hash_str_table_cache_purge (
void);

static void
    icl_demo_hash_str_table_cache_terminate (
void);

Bool
    icl_demo_hash_str_table_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


//  Hash support functions
static inline unsigned int
    s_key_hash (char * key, size_t hash_size);
static inline Bool
    s_key_equal (char * key1, char * key2);

//  Table functions to be called once locks are in place
static int
    s_icl_demo_hash_str_table_insert (icl_demo_hash_str_table_t *self, icl_demo_hash_str_t *item, char * key);
static icl_demo_hash_str_t *
    s_icl_demo_hash_str_table_lookup (icl_demo_hash_str_table_t *self, char * key);
static void
    s_icl_demo_hash_str_table_remove (icl_demo_hash_str_t *item);
static void
    s_icl_demo_hash_str_table_purge (icl_demo_hash_str_table_t *self);
/*  -------------------------------------------------------------------------
    icl_demo_hash_str_table_new

    Type: Component method
    Creates and initialises a new icl_demo_hash_str_table_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_demo_hash_str_table_t *
    icl_demo_hash_str_table_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_demo_hash_str_table_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_NEW))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_NEW))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_NEW))
    icl_stats_inc ("icl_demo_hash_str_table_new", &s_icl_demo_hash_str_table_new_stats);
#endif

    self = icl_demo_hash_str_table_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DEMO_HASH_STR_TABLE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_demo_hash_str_table_show_);
#endif

self->max_items = ICL_DEMO_HASH_STR_TABLE_INITIAL_SIZE;
self->table_items = icl_mem_alloc (sizeof (icl_demo_hash_str_t*) *
    ICL_DEMO_HASH_STR_TABLE_INITIAL_SIZE);
assert (self->table_items);
memset (self->table_items, 0, sizeof (icl_demo_hash_str_t*) *
    ICL_DEMO_HASH_STR_TABLE_INITIAL_SIZE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_NEW))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_NEW))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_new_finish"
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
    icl_demo_hash_str_table_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_str_table_annihilate_ (
    icl_demo_hash_str_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    int
        history_last;
#endif

    icl_demo_hash_str_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_DESTROY))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_DESTROY))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_DESTROY))
    icl_stats_inc ("icl_demo_hash_str_table_annihilate", &s_icl_demo_hash_str_table_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = self->links;
#endif

    ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

s_icl_demo_hash_str_table_purge (self);
if (self->table_items)
    icl_mem_free (self->table_items);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_DESTROY))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_DESTROY))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_destroy_finish"
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
    icl_demo_hash_str_table_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SELFTEST))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SELFTEST))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SELFTEST))
    icl_stats_inc ("icl_demo_hash_str_table_selftest", &s_icl_demo_hash_str_table_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SELFTEST))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SELFTEST))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_selftest_finish"
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
    icl_demo_hash_str_table_insert

    Type: Component method
    Accepts a icl_demo_hash_str_table_t reference and returns zero in case of success,
    1 in case of errors.
    Insert a new item into the hash table if possible. If successful,
    the number of links to the item is automatically incremented.
    Trying to insert a duplicate key will result in nothing being inserted.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_str_table_insert (
    icl_demo_hash_str_table_t * self,   //  Reference to object
    char * key,                         //  Hash key
    icl_demo_hash_str_t * item          //  Item to insert
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_INSERT))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_insert_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_INSERT))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_INSERT))
    icl_stats_inc ("icl_demo_hash_str_table_insert", &s_icl_demo_hash_str_table_insert_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

//
if (item->table_head) {
    if (item->table_head != self) {
        icl_console_print ("E: icl_demo_hash_str item inserted into multiple table containers");
        assert (item->table_head == self);
    }
    s_icl_demo_hash_str_table_remove (item);
    icl_demo_hash_str_unlink (&item);
}
rc = s_icl_demo_hash_str_table_insert (self, item, key);
if (item->table_head)
    icl_demo_hash_str_link (item);

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_INSERT))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_INSERT))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_insert_finish"
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
    icl_demo_hash_str_table_remove

    Type: Component method
    Remove an item from a hash table.  If the item was not in any hash
    table, this function does nothing.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_str_table_remove (
    icl_demo_hash_str_t * item          //  Item to remove
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    icl_demo_hash_str_table_t *
        self = item->table_head;        //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_REMOVE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_REMOVE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_REMOVE))
    icl_stats_inc ("icl_demo_hash_str_table_remove", &s_icl_demo_hash_str_table_remove_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->table_head) { //      Catch case where item moved
    s_icl_demo_hash_str_table_remove (item);
    icl_demo_hash_str_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_REMOVE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_REMOVE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_remove_finish"
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
    icl_demo_hash_str_table_search

    Type: Component method
    Find object by key in the hash table. Returns reference to object
    if found, else null.
    -------------------------------------------------------------------------
 */

icl_demo_hash_str_t *
    icl_demo_hash_str_table_search (
    icl_demo_hash_str_table_t * self,   //  Table to search
    char * key                          //  Hash key
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    icl_demo_hash_str_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SEARCH))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_search_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SEARCH))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SEARCH))
    icl_stats_inc ("icl_demo_hash_str_table_search", &s_icl_demo_hash_str_table_search_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

//
ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
if (key)
    item = s_icl_demo_hash_str_table_lookup (self, key);
if (item)
    icl_demo_hash_str_link (item);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SEARCH))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SEARCH))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_search_finish"
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
    icl_demo_hash_str_table_apply

    Type: Component method
    This method iterates through all the items in the hash and calls the
    callback function for each of them.
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_apply (
    icl_demo_hash_str_table_t * self,   //  Table to iterate
    icl_demo_hash_str_table_callback_fn * callback,   //  Not documented
    void * argument                     //  Arbitrary argument pointer
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

size_t
    pos;
icl_demo_hash_str_t
    *item;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_APPLY))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_apply_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_APPLY))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_APPLY))
    icl_stats_inc ("icl_demo_hash_str_table_apply", &s_icl_demo_hash_str_table_apply_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

//
ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_APPLY))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_APPLY))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_apply_finish"
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
    icl_demo_hash_str_table_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_TERMINATE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_TERMINATE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_TERMINATE))
    icl_stats_inc ("icl_demo_hash_str_table_terminate", &s_icl_demo_hash_str_table_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_TERMINATE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_TERMINATE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_terminate_finish"
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
    icl_demo_hash_str_table_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    icl_demo_hash_str_table_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SHOW))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SHOW))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SHOW))
    icl_stats_inc ("icl_demo_hash_str_table_show", &s_icl_demo_hash_str_table_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <icl_demo_hash_str_table zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    if (self->history_last > ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH;
        self->history_last %= ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </icl_demo_hash_str_table>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SHOW))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SHOW))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_show_finish"
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
    icl_demo_hash_str_table_destroy

    Type: Component method
    Destroys a icl_demo_hash_str_table_t object. Takes the address of a
    icl_demo_hash_str_table_t reference (a pointer to a pointer) and nullifies the
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
    icl_demo_hash_str_table_destroy_ (
    icl_demo_hash_str_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_hash_str_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC))
    icl_stats_inc ("icl_demo_hash_str_table_destroy", &s_icl_demo_hash_str_table_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        icl_demo_hash_str_table_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on icl_demo_hash_str_table object");
        icl_demo_hash_str_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        icl_demo_hash_str_table_free_ ((icl_demo_hash_str_table_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_destroy_public_finish"
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
    icl_demo_hash_str_table_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_hash_str_table_t *
    icl_demo_hash_str_table_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_demo_hash_str_table_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_ALLOC))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_ALLOC))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_ALLOC))
    icl_stats_inc ("icl_demo_hash_str_table_alloc", &s_icl_demo_hash_str_table_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    icl_demo_hash_str_table_cache_initialise ();

self = (icl_demo_hash_str_table_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_demo_hash_str_table_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_ALLOC))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_ALLOC))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_alloc_finish"
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
    icl_demo_hash_str_table_free

    Type: Component method
    Freess a icl_demo_hash_str_table_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_str_table_free_ (
    icl_demo_hash_str_table_t * self,   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_FREE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_FREE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_FREE))
    icl_stats_inc ("icl_demo_hash_str_table_free", &s_icl_demo_hash_str_table_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (icl_demo_hash_str_table_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_hash_str_table_t));
        self->object_tag = ICL_DEMO_HASH_STR_TABLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_FREE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_FREE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_free_finish"
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
    icl_demo_hash_str_table_read_lock

    Type: Component method
    Accepts a icl_demo_hash_str_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_str_table_read_lock (
    icl_demo_hash_str_table_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_READ_LOCK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_READ_LOCK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_READ_LOCK))
    icl_stats_inc ("icl_demo_hash_str_table_read_lock", &s_icl_demo_hash_str_table_read_lock_stats);
#endif

ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_READ_LOCK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_READ_LOCK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_read_lock_finish"
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
    icl_demo_hash_str_table_write_lock

    Type: Component method
    Accepts a icl_demo_hash_str_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_str_table_write_lock (
    icl_demo_hash_str_table_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK))
    icl_stats_inc ("icl_demo_hash_str_table_write_lock", &s_icl_demo_hash_str_table_write_lock_stats);
#endif

ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_write_lock_finish"
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
    icl_demo_hash_str_table_unlock

    Type: Component method
    Accepts a icl_demo_hash_str_table_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_hash_str_table_unlock (
    icl_demo_hash_str_table_t * self    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_UNLOCK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_UNLOCK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_UNLOCK))
    icl_stats_inc ("icl_demo_hash_str_table_unlock", &s_icl_demo_hash_str_table_unlock_stats);
#endif

ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_UNLOCK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_UNLOCK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_unlock_finish"
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
    icl_demo_hash_str_table_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

icl_demo_hash_str_table_t *
    icl_demo_hash_str_table_link_ (
    icl_demo_hash_str_table_t * self,   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_LINK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_LINK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_LINK))
    icl_stats_inc ("icl_demo_hash_str_table_link", &s_icl_demo_hash_str_table_link_stats);
#endif

    if (self) {
        ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_LINK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_LINK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_link_finish"
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
    icl_demo_hash_str_table_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_unlink_ (
    icl_demo_hash_str_table_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
    int
        history_last;
#endif

    icl_demo_hash_str_table_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_UNLINK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_UNLINK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_UNLINK))
    icl_stats_inc ("icl_demo_hash_str_table_unlink", &s_icl_demo_hash_str_table_unlink_stats);
#endif

    if (self) {
        ICL_DEMO_HASH_STR_TABLE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on icl_demo_hash_str_table object");
            icl_demo_hash_str_table_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_ICL_DEMO_HASH_STR_TABLE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % ICL_DEMO_HASH_STR_TABLE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            icl_demo_hash_str_table_annihilate_ (self_p, file, line);
        icl_demo_hash_str_table_free_ ((icl_demo_hash_str_table_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_UNLINK))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_UNLINK))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_unlink_finish"
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
    icl_demo_hash_str_table_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_str_table_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE))
    icl_stats_inc ("icl_demo_hash_str_table_cache_initialise", &s_icl_demo_hash_str_table_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (icl_demo_hash_str_table_t));
icl_system_register (icl_demo_hash_str_table_cache_purge, icl_demo_hash_str_table_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_cache_initialise_finish"
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
    icl_demo_hash_str_table_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_str_table_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE))
    icl_stats_inc ("icl_demo_hash_str_table_cache_purge", &s_icl_demo_hash_str_table_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_cache_purge_finish"
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
    icl_demo_hash_str_table_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_hash_str_table_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE))
    icl_stats_inc ("icl_demo_hash_str_table_cache_terminate", &s_icl_demo_hash_str_table_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_cache_terminate_finish"
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
    icl_demo_hash_str_table_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION))
    icl_stats_inc ("icl_demo_hash_str_table_show_animation", &s_icl_demo_hash_str_table_show_animation_stats);
#endif

icl_demo_hash_str_table_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_show_animation_finish"
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
    icl_demo_hash_str_table_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_hash_str_table_new_in_scope_ (
    icl_demo_hash_str_table_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE)  ||  defined (BASE_STATS_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE))
    icl_stats_inc ("icl_demo_hash_str_table_new_in_scope", &s_icl_demo_hash_str_table_new_in_scope_stats);
#endif

*self_p = icl_demo_hash_str_table_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_hash_str_table_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE))
    icl_trace_record (1, icl_demo_hash_str_table_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_ANIMATE_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE))
    if (icl_demo_hash_str_table_animating)
        icl_console_print ("<icl_demo_hash_str_table_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_NEW)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_INSERT)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_REMOVE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SEARCH)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_APPLY)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SHOW)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_FREE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_READ_LOCK)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_WRITE_LOCK)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_UNLOCK)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_LINK)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_UNLINK)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_PURGE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_SHOW_ANIMATION)   || defined (BASE_TRACE_ICL_DEMO_HASH_STR_TABLE_NEW_IN_SCOPE) )
void
icl_demo_hash_str_table_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
        case 16: method_name = "link"; break;
        case 17: method_name = "unlink"; break;
        case 18: method_name = "cache initialise"; break;
        case 19: method_name = "cache purge"; break;
        case 20: method_name = "cache terminate"; break;
        case 21: method_name = "show animation"; break;
        case 22: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_demo_hash_str_table %s%s",
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
s_icl_demo_hash_str_table_insert (icl_demo_hash_str_table_t *self, icl_demo_hash_str_t *item, char * key)
{
    qbyte
        index,
        new_index;
    icl_demo_hash_str_t
        *current_item,
        *next_item;
    int
        rc = 0;

    if (self->nbr_items >= self->max_items * ICL_DEMO_HASH_STR_TABLE_LOAD_FACTOR / 100) {

        //  Load factor of hash table was exceeded
        //  We need to increase its size by GROWTH_FACTOR and rebuild it
        icl_demo_hash_str_t
            **new_items;
        size_t
            new_max_items;

        //  Create new hash table
        new_max_items = self->max_items * ICL_DEMO_HASH_STR_TABLE_GROWTH_FACTOR / 100;
        new_items = icl_mem_alloc (sizeof (icl_demo_hash_str_t*) * new_max_items);
        assert (new_items);
        memset (new_items, 0, sizeof (icl_demo_hash_str_t*) * new_max_items);

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

static icl_demo_hash_str_t *
s_icl_demo_hash_str_table_lookup (icl_demo_hash_str_table_t *self, char * key)
{
    qbyte
        index;
    icl_demo_hash_str_t
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
s_icl_demo_hash_str_table_remove (icl_demo_hash_str_t *item)
{
    icl_demo_hash_str_t
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
s_icl_demo_hash_str_table_purge (icl_demo_hash_str_table_t *self)
{
    uint
        table_idx;
    icl_demo_hash_str_t
        *current_item,
        *next_item;

    for (table_idx = 0; table_idx < self->max_items; table_idx++) {
        current_item = self->table_items [table_idx];
        while (current_item) {
            next_item = current_item->table_next;
            s_icl_demo_hash_str_table_remove (current_item);
            icl_demo_hash_str_unlink (&current_item);
            current_item = next_item;
        }
    }
}

//  Embed the version information in the resulting binary                      

char *icl_demo_hash_str_table_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_demo_hash_str_table_component  = "icl_demo_hash_str_table ";
char *icl_demo_hash_str_table_version  = "1.0 ";
char *icl_demo_hash_str_table_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_demo_hash_str_table_filename  = "icl_demo_hash_str_table.icl ";
char *icl_demo_hash_str_table_builddate  = "2009/02/19 ";
char *icl_demo_hash_str_table_version_end  = "VeRsIoNeNd:ipc";

