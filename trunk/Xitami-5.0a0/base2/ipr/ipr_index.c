/*---------------------------------------------------------------------------
    ipr_index.c - ipr_index component

This class provides a mechanism for indexing objects.  An index is a number
from 0 to IPR_INDEX_MAX - 1. The class keeps indexes low by hashing across
a variable part of the index rather than across its full size.  Does not
support the retrieval of objects by their reference, only by index.
    Generated from ipr_index.icl by icl_gen using GSL/4.
    
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
#include "ipr_index.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_index_t

//  Shorthands for class methods                                               

#define self_insert         ipr_index_insert
#define self_delete         ipr_index_delete
#define self_selftest       ipr_index_selftest
#define self_new            ipr_index_new
#define self_annihilate     ipr_index_annihilate
#define self_count          ipr_index_count
#define self_terminate      ipr_index_terminate
#define self_show           ipr_index_show
#define self_destroy        ipr_index_destroy
#define self_alloc          ipr_index_alloc
#define self_free           ipr_index_free
#define self_read_lock      ipr_index_read_lock
#define self_write_lock     ipr_index_write_lock
#define self_unlock         ipr_index_unlock
#define self_cache_initialise  ipr_index_cache_initialise
#define self_cache_purge    ipr_index_cache_purge
#define self_cache_terminate  ipr_index_cache_terminate
#define self_show_animation  ipr_index_show_animation
#define self_new_in_scope   ipr_index_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_INSERT))
static icl_stats_t *s_ipr_index_insert_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_DELETE))
static icl_stats_t *s_ipr_index_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_SELFTEST))
static icl_stats_t *s_ipr_index_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_NEW))
static icl_stats_t *s_ipr_index_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_DESTROY))
static icl_stats_t *s_ipr_index_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_COUNT))
static icl_stats_t *s_ipr_index_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_TERMINATE))
static icl_stats_t *s_ipr_index_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_SHOW))
static icl_stats_t *s_ipr_index_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_index_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_ALLOC))
static icl_stats_t *s_ipr_index_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_FREE))
static icl_stats_t *s_ipr_index_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_READ_LOCK))
static icl_stats_t *s_ipr_index_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_WRITE_LOCK))
static icl_stats_t *s_ipr_index_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_UNLOCK))
static icl_stats_t *s_ipr_index_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_CACHE_INITIALISE))
static icl_stats_t *s_ipr_index_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_CACHE_PURGE))
static icl_stats_t *s_ipr_index_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_CACHE_TERMINATE))
static icl_stats_t *s_ipr_index_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_SHOW_ANIMATION))
static icl_stats_t *s_ipr_index_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_index_new_in_scope_stats = NULL;
#endif
static void
    ipr_index_annihilate (
ipr_index_t * ( * self_p )              //  Reference to object reference
);

#define ipr_index_alloc()               ipr_index_alloc_ (__FILE__, __LINE__)
static ipr_index_t *
    ipr_index_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_index_free (
ipr_index_t * self                      //  Object reference
);

static void
    ipr_index_cache_initialise (
void);

static void
    ipr_index_cache_purge (
void);

static void
    ipr_index_cache_terminate (
void);

Bool
    ipr_index_animating = TRUE;         //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_ipr_index_count = 0;
/*  -------------------------------------------------------------------------
    ipr_index_insert

    Type: Component method
    Accepts a ipr_index_t reference and returns zero in case of success,
    1 in case of errors.
    Inserts a new object into the index.  Returns the resulting index
    value, 1 and upwards.  If the same object is inserted twice, will
    create two index entries.  A return value of zero indicates that the
    table was full.
    -------------------------------------------------------------------------
 */

int
    ipr_index_insert (
    ipr_index_t * self,                 //  Reference to object
    void * object                       //  Object to index
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

unsigned int
    hash_range,                     //  Size of hash range
    hash_index;                     //  Calculated index
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_INSERT))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_insert_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" object=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, object);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_INSERT))
    icl_trace_record (NULL, ipr_index_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_INSERT))
    icl_stats_inc ("ipr_index_insert", &s_ipr_index_insert_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

IPR_INDEX_ASSERT_SANE (self);

assert (self->size < IPR_INDEX_MAX);
hash_range = self->size * 2;
if (hash_range > IPR_INDEX_MAX)
    hash_range = IPR_INDEX_MAX;
else
if (hash_range < 16)
    hash_range = 16;                //  Minimum hash range

hash_index = (((unsigned long) object) % (hash_range - 1)) + 1;
while (self->data [hash_index]) {
    hash_index++;
    if (hash_index == IPR_INDEX_MAX)
        hash_index = 0;
}
if (hash_index) {
    self->data [hash_index] = object;
    self->size++;
}
rc = hash_index;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_INSERT))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_INSERT))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_insert_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" object=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, object, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_index_delete

    Type: Component method
    Accepts a ipr_index_t reference and returns zero in case of success,
    1 in case of errors.
    Deletes the specified index entry.  Note that you must specify
    the index value, not the object address.
    -------------------------------------------------------------------------
 */

int
    ipr_index_delete (
    ipr_index_t * self,                 //  Reference to object
    int index                           //  Index entry to delete
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_DELETE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_DELETE))
    icl_trace_record (NULL, ipr_index_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_DELETE))
    icl_stats_inc ("ipr_index_delete", &s_ipr_index_delete_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

IPR_INDEX_ASSERT_SANE (self);

assert (index > 0 && index < IPR_INDEX_MAX);
if (self->size > 0) {
    self->data [index] = 0;
    self->size--;
}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_DELETE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_DELETE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_index_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_index_selftest (
void)
{
ipr_index_t
    *index_table;
char
    *value1 = "abc",
    *value2 = "abc",
    *value3 = "abc";
int
    index;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_SELFTEST))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_SELFTEST))
    icl_trace_record (NULL, ipr_index_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_SELFTEST))
    icl_stats_inc ("ipr_index_selftest", &s_ipr_index_selftest_stats);
#endif

index_table = ipr_index_new ();
ipr_index_insert (index_table, value1);
ipr_index_insert (index_table, value2);
ipr_index_insert (index_table, value3);
ipr_index_insert (index_table, value1);
ipr_index_insert (index_table, value2);
ipr_index_insert (index_table, value3);

//  Fill the table half-full
for (index = 0; index < IPR_INDEX_MAX / 2; index++)
    ipr_index_insert (index_table, value3);
//  Insert a limit pointer
index = ipr_index_insert (index_table, (void*) ((uint) (IPR_INDEX_MAX - 1)));
ipr_index_delete (index_table, index);

//  Clean-up
ipr_index_destroy (&index_table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_SELFTEST))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_SELFTEST))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_selftest_finish"
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
    ipr_index_new

    Type: Component method
    Creates and initialises a new ipr_index_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_index_t *
    ipr_index_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_index_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_NEW))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_NEW))
    icl_trace_record (NULL, ipr_index_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_NEW))
    icl_stats_inc ("ipr_index_new", &s_ipr_index_new_stats);
#endif

    self = ipr_index_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_INDEX_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_index_show_);
#endif

icl_atomic_inc32 ((volatile qbyte *) &s_ipr_index_count);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_NEW))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_NEW))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_new_finish"
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
    ipr_index_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_index_annihilate (
    ipr_index_t * ( * self_p )          //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    ipr_index_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_DESTROY))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_DESTROY))
    icl_trace_record (NULL, ipr_index_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_DESTROY))
    icl_stats_inc ("ipr_index_annihilate", &s_ipr_index_annihilate_stats);
#endif

    IPR_INDEX_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_atomic_dec32 ((volatile qbyte *) &s_ipr_index_count);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_DESTROY))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_DESTROY))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_destroy_finish"
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
    ipr_index_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    ipr_index_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_COUNT))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_COUNT))
    icl_trace_record (NULL, ipr_index_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_COUNT))
    icl_stats_inc ("ipr_index_count", &s_ipr_index_count_stats);
#endif

count = (int) s_ipr_index_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_COUNT))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_COUNT))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    ipr_index_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_index_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_TERMINATE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_TERMINATE))
    icl_trace_record (NULL, ipr_index_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_TERMINATE))
    icl_stats_inc ("ipr_index_terminate", &s_ipr_index_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_TERMINATE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_TERMINATE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_terminate_finish"
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
    ipr_index_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_index_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_index_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_SHOW))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_SHOW))
    icl_trace_record (NULL, ipr_index_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_SHOW))
    icl_stats_inc ("ipr_index_show", &s_ipr_index_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_index file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_SHOW))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_SHOW))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_show_finish"
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
    ipr_index_destroy

    Type: Component method
    Destroys a ipr_index_t object. Takes the address of a
    ipr_index_t reference (a pointer to a pointer) and nullifies the
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
    ipr_index_destroy_ (
    ipr_index_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_index_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_DESTROY_PUBLIC))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_index_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_index_destroy", &s_ipr_index_destroy_stats);
#endif

if (self) {
    ipr_index_annihilate (self_p);
    ipr_index_free ((ipr_index_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_DESTROY_PUBLIC))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_destroy_public_finish"
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
    ipr_index_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_index_t *
    ipr_index_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_index_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_ALLOC))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_ALLOC))
    icl_trace_record (NULL, ipr_index_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_ALLOC))
    icl_stats_inc ("ipr_index_alloc", &s_ipr_index_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_index_cache_initialise ();

self = (ipr_index_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_index_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_ALLOC))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_ALLOC))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_alloc_finish"
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
    ipr_index_free

    Type: Component method
    Freess a ipr_index_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_index_free (
    ipr_index_t * self                  //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_FREE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_FREE))
    icl_trace_record (NULL, ipr_index_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_FREE))
    icl_stats_inc ("ipr_index_free", &s_ipr_index_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_index_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_index_t));
        self->object_tag = IPR_INDEX_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_FREE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_FREE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_free_finish"
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
    ipr_index_read_lock

    Type: Component method
    Accepts a ipr_index_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_index_read_lock (
    ipr_index_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_READ_LOCK))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_READ_LOCK))
    icl_trace_record (NULL, ipr_index_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_READ_LOCK))
    icl_stats_inc ("ipr_index_read_lock", &s_ipr_index_read_lock_stats);
#endif

IPR_INDEX_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_READ_LOCK))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_READ_LOCK))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_read_lock_finish"
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
    ipr_index_write_lock

    Type: Component method
    Accepts a ipr_index_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_index_write_lock (
    ipr_index_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_WRITE_LOCK))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_WRITE_LOCK))
    icl_trace_record (NULL, ipr_index_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_WRITE_LOCK))
    icl_stats_inc ("ipr_index_write_lock", &s_ipr_index_write_lock_stats);
#endif

IPR_INDEX_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_WRITE_LOCK))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_WRITE_LOCK))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_write_lock_finish"
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
    ipr_index_unlock

    Type: Component method
    Accepts a ipr_index_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_index_unlock (
    ipr_index_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_UNLOCK))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_UNLOCK))
    icl_trace_record (NULL, ipr_index_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_UNLOCK))
    icl_stats_inc ("ipr_index_unlock", &s_ipr_index_unlock_stats);
#endif

IPR_INDEX_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_UNLOCK))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_UNLOCK))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_unlock_finish"
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
    ipr_index_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_index_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_CACHE_INITIALISE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_index_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_CACHE_INITIALISE))
    icl_stats_inc ("ipr_index_cache_initialise", &s_ipr_index_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_index_t));
icl_system_register (ipr_index_cache_purge, ipr_index_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_CACHE_INITIALISE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_cache_initialise_finish"
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
    ipr_index_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_index_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_CACHE_PURGE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_CACHE_PURGE))
    icl_trace_record (NULL, ipr_index_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_CACHE_PURGE))
    icl_stats_inc ("ipr_index_cache_purge", &s_ipr_index_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_CACHE_PURGE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_CACHE_PURGE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_cache_purge_finish"
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
    ipr_index_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_index_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_CACHE_TERMINATE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_index_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_CACHE_TERMINATE))
    icl_stats_inc ("ipr_index_cache_terminate", &s_ipr_index_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_CACHE_TERMINATE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_cache_terminate_finish"
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
    ipr_index_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_index_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_SHOW_ANIMATION))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_index_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_SHOW_ANIMATION))
    icl_stats_inc ("ipr_index_show_animation", &s_ipr_index_show_animation_stats);
#endif

ipr_index_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_SHOW_ANIMATION))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_show_animation_finish"
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
    ipr_index_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_index_new_in_scope_ (
    ipr_index_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_INDEX)  ||  defined (BASE_ANIMATE_IPR_INDEX_NEW_IN_SCOPE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_index_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_INDEX)  ||  defined (BASE_STATS_IPR_INDEX_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_index_new_in_scope", &s_ipr_index_new_in_scope_stats);
#endif

*self_p = ipr_index_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_index_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_index_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_INDEX)   || defined (BASE_ANIMATE_IPR_INDEX_NEW_IN_SCOPE))
    if (ipr_index_animating)
        icl_console_print ("<ipr_index_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_INDEX)   || defined (BASE_TRACE_IPR_INDEX_INSERT)   || defined (BASE_TRACE_IPR_INDEX_DELETE)   || defined (BASE_TRACE_IPR_INDEX_SELFTEST)   || defined (BASE_TRACE_IPR_INDEX_NEW)   || defined (BASE_TRACE_IPR_INDEX_DESTROY)   || defined (BASE_TRACE_IPR_INDEX_COUNT)   || defined (BASE_TRACE_IPR_INDEX_TERMINATE)   || defined (BASE_TRACE_IPR_INDEX_SHOW)   || defined (BASE_TRACE_IPR_INDEX_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_INDEX_ALLOC)   || defined (BASE_TRACE_IPR_INDEX_FREE)   || defined (BASE_TRACE_IPR_INDEX_READ_LOCK)   || defined (BASE_TRACE_IPR_INDEX_WRITE_LOCK)   || defined (BASE_TRACE_IPR_INDEX_UNLOCK)   || defined (BASE_TRACE_IPR_INDEX_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_INDEX_CACHE_PURGE)   || defined (BASE_TRACE_IPR_INDEX_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_INDEX_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_INDEX_NEW_IN_SCOPE) )
void
ipr_index_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "insert"; break;
        case 2: method_name = "delete"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "new"; break;
        case 5: method_name = "destroy"; break;
        case 6: method_name = "count"; break;
        case 7: method_name = "terminate"; break;
        case 8: method_name = "show"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "free"; break;
        case 12: method_name = "read lock"; break;
        case 13: method_name = "write lock"; break;
        case 14: method_name = "unlock"; break;
        case 15: method_name = "cache initialise"; break;
        case 16: method_name = "cache purge"; break;
        case 17: method_name = "cache terminate"; break;
        case 18: method_name = "show animation"; break;
        case 19: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_index %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_index_version_start      = "VeRsIoNsTaRt:ipc";
char *ipr_index_component          = "ipr_index ";
char *ipr_index_version            = "1.0 ";
char *ipr_index_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_index_filename           = "ipr_index.icl ";
char *ipr_index_builddate          = "2009/02/19 ";
char *ipr_index_version_end        = "VeRsIoNeNd:ipc";

