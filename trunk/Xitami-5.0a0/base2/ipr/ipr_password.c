/*---------------------------------------------------------------------------
    ipr_password.c - ipr_password component

    Password tables are held as dictionaries.  Supports passwords in
    either basic or digest format as defined by RFC 2617. ipr_password
    items do not use links.  This class is threadsafe and can be used
    from concurrent threads.
    Generated from ipr_password.icl by icl_gen using GSL/4.
    
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
#include "ipr_password.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_password_t

//  Shorthands for class methods                                               

#define self_new            ipr_password_new
#define self_annihilate     ipr_password_annihilate
#define self_update         ipr_password_update
#define self_assume         ipr_password_assume
#define self_guard_set      ipr_password_guard_set
#define self_guard_get      ipr_password_guard_get
#define self_guard_put      ipr_password_guard_put
#define self_hit            ipr_password_hit
#define self_miss           ipr_password_miss
#define self_selftest       ipr_password_selftest
#define self_remove_from_all_containers  ipr_password_remove_from_all_containers
#define self_show           ipr_password_show
#define self_terminate      ipr_password_terminate
#define self_destroy        ipr_password_destroy
#define self_alloc          ipr_password_alloc
#define self_free           ipr_password_free
#define self_lock           ipr_password_lock
#define self_unlock         ipr_password_unlock
#define self_cache_initialise  ipr_password_cache_initialise
#define self_cache_purge    ipr_password_cache_purge
#define self_cache_terminate  ipr_password_cache_terminate
#define self_show_animation  ipr_password_show_animation
#define self_new_in_scope   ipr_password_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_NEW))
static icl_stats_t *s_ipr_password_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_DESTROY))
static icl_stats_t *s_ipr_password_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_UPDATE))
static icl_stats_t *s_ipr_password_update_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_ASSUME))
static icl_stats_t *s_ipr_password_assume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_GUARD_SET))
static icl_stats_t *s_ipr_password_guard_set_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_GUARD_GET))
static icl_stats_t *s_ipr_password_guard_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_GUARD_PUT))
static icl_stats_t *s_ipr_password_guard_put_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_HIT))
static icl_stats_t *s_ipr_password_hit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_MISS))
static icl_stats_t *s_ipr_password_miss_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_SELFTEST))
static icl_stats_t *s_ipr_password_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_password_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_SHOW))
static icl_stats_t *s_ipr_password_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_TERMINATE))
static icl_stats_t *s_ipr_password_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_password_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_ALLOC))
static icl_stats_t *s_ipr_password_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_FREE))
static icl_stats_t *s_ipr_password_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_LOCK))
static icl_stats_t *s_ipr_password_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_UNLOCK))
static icl_stats_t *s_ipr_password_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_CACHE_INITIALISE))
static icl_stats_t *s_ipr_password_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_CACHE_PURGE))
static icl_stats_t *s_ipr_password_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_CACHE_TERMINATE))
static icl_stats_t *s_ipr_password_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_SHOW_ANIMATION))
static icl_stats_t *s_ipr_password_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_password_new_in_scope_stats = NULL;
#endif
static void
    ipr_password_annihilate (
ipr_password_t * ( * self_p )           //  Reference to object reference
);

#define ipr_password_alloc()            ipr_password_alloc_ (__FILE__, __LINE__)
static ipr_password_t *
    ipr_password_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_password_free (
ipr_password_t * self                   //  Object reference
);

static void
    ipr_password_cache_initialise (
void);

static void
    ipr_password_cache_purge (
void);

static void
    ipr_password_cache_terminate (
void);

Bool
    ipr_password_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_password_new

    Type: Component method
    Creates and initialises a new ipr_password_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

ipr_password_t *
    ipr_password_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_password_table_t * table,       //  Table to insert into
    char * key,                         //  Hash key
    char * hash                         //  Not documented
)
{
    ipr_password_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_NEW))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" hash=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, hash);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_NEW))
    icl_trace_record (NULL, ipr_password_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_NEW))
    icl_stats_inc ("ipr_password_new", &s_ipr_password_new_stats);
#endif

    self = ipr_password_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_PASSWORD_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->mutex = icl_mutex_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_password_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
//
self->hash = icl_mem_strdup (hash);

//  Basic password keys are user
//  Digest password keys are realm:user
if (strchr (key, ':'))
    self->type = IPR_PASSWD_DIGEST;
else
    self->type = IPR_PASSWD_BASIC;
if (table && self && ipr_password_table_insert (table, key, self))
    ipr_password_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_NEW))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_NEW))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" hash=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, hash, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_password_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_password_annihilate (
    ipr_password_t * ( * self_p )       //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    ipr_password_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_DESTROY))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_DESTROY))
    icl_trace_record (NULL, ipr_password_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_DESTROY))
    icl_stats_inc ("ipr_password_annihilate", &s_ipr_password_annihilate_stats);
#endif

    IPR_PASSWORD_ASSERT_SANE (self);
    ipr_password_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    mutex = self->mutex;
    if (mutex)
         icl_mutex_lock (mutex);
#endif

icl_mem_free (self->hash);
#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_DESTROY))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_DESTROY))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_destroy_finish"
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
    ipr_password_update

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    Forces an update/clean of the password, removing any guard it had.
    -------------------------------------------------------------------------
 */

int
    ipr_password_update (
    ipr_password_t * self,              //  Reference to object
    char * hash                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_UPDATE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_update_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hash=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hash);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_UPDATE))
    icl_trace_record (NULL, ipr_password_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_UPDATE))
    icl_stats_inc ("ipr_password_update", &s_ipr_password_update_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

//
icl_mem_free (self->hash);
self->hash = icl_mem_strdup (hash);

//  The entry is unguarded until it is re-guarded
self->hits          = 0;
self->hit_quota     = 0;
self->misses        = 0;
self->miss_quota    = 0;
self->expiry        = 0;
self->hit_time      = 0;
self->miss_time     = 0;
self->hit_from  [0] = 0;
self->miss_from [0] = 0;
self->expired   = FALSE;
self->table_head->dirty = TRUE;

#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_UPDATE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_UPDATE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_update_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hash=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hash, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_password_assume

    Type: Component method
    Create or update entry with specified hash.  Returns reference to entry.
    -------------------------------------------------------------------------
 */

ipr_password_t *
    ipr_password_assume (
    ipr_password_table_t * table,       //  Not documented
    char * key,                         //  Not documented
    char * hash                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    ipr_password_t *
        self = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_ASSUME))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_assume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" hash=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, hash);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_ASSUME))
    icl_trace_record (NULL, ipr_password_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_ASSUME))
    icl_stats_inc ("ipr_password_assume", &s_ipr_password_assume_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

//
self = ipr_password_table_search (table, key);
if (self) {
    if (hash && strneq (hash, self->hash))
        ipr_password_update (self, hash);
}
else
    self = ipr_password_new (table, key, hash);
#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_ASSUME))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_ASSUME))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_assume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" hash=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, hash, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_password_guard_set

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the guard data for hits, misses, and expiry.  Does not destroy data
    already collected.  Does not change the guard data for expired passwords.
    -------------------------------------------------------------------------
 */

int
    ipr_password_guard_set (
    ipr_password_t * self,              //  Reference to object
    size_t hit_quota,                   //  Not documented
    size_t miss_quota,                  //  Not documented
    size_t time_to_live                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_GUARD_SET))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_guard_set_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hit_quota=\"%u\""
" miss_quota=\"%u\""
" time_to_live=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hit_quota, miss_quota, time_to_live);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_SET))
    icl_trace_record (NULL, ipr_password_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_GUARD_SET))
    icl_stats_inc ("ipr_password_guard_set", &s_ipr_password_guard_set_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

//
if (!self->expired) {
    if (self->hit_quota == 0)
        self->hit_quota = hit_quota;
    if (self->miss_quota == 0)
        self->miss_quota = miss_quota;
    if (self->expiry == 0 && time_to_live)
        self->expiry = apr_time_now () + (time_to_live * 1000 * 1000);
}

#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_SET))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_GUARD_SET))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_guard_set_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hit_quota=\"%u\""
" miss_quota=\"%u\""
" time_to_live=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hit_quota, miss_quota, time_to_live, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_password_guard_get

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the password options from a serialized string, the same format
    as produced by the save method.
    -------------------------------------------------------------------------
 */

int
    ipr_password_guard_get (
    ipr_password_t * self,              //  Reference to object
    char * options                      //  name=value ...
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

ipr_regexp_t
    *regexp;                        //  Regexp for matching each line
char
    *name = NULL,
    *value = NULL,
    *rest =  NULL;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_GUARD_GET))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_guard_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" options=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, options);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_GET))
    icl_trace_record (NULL, ipr_password_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_GUARD_GET))
    icl_stats_inc ("ipr_password_guard_get", &s_ipr_password_guard_get_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

//
options = icl_mem_strdup (options);
regexp = ipr_regexp_new ("^`s*([`w-]+)`s*=`s*([^`s]+)(.*)");
while (ipr_regexp_match (regexp, options, &name, &value, &rest) == 3) {
    if (streq (name, "expiry"))
        self->expiry = ipr_time_iso8601_decode (value);
    else
    if (streq (name, "expired"))
        self->expired = atoi (value);
    else
    if (streq (name, "hits"))
        self->hits = atoi (value);
    else
    if (streq (name, "hit-quota"))
        self->hit_quota = atoi (value);
    else
    if (streq (name, "hit-time"))
        self->hit_time = ipr_time_iso8601_decode (value);
    else
    if (streq (name, "hit-from"))
        icl_shortstr_cpy (self->hit_from, value);
    else
    if (streq (name, "misses"))
        self->misses = atoi (value);
    else
    if (streq (name, "miss-quota"))
        self->miss_quota = atoi (value);
    else
    if (streq (name, "miss-time"))
        self->miss_time = ipr_time_iso8601_decode (value);
    else
    if (streq (name, "miss-from"))
        icl_shortstr_cpy (self->miss_from, value);

    icl_mem_strfree (&name);
    icl_mem_strfree (&value);
    icl_mem_strfree (&options);
    options = rest;
    rest = NULL;
    self->table_head->dirty = TRUE;
}
ipr_regexp_destroy (&regexp);
icl_mem_free (options);

#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_GET))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_GUARD_GET))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_guard_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" options=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, options, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_password_guard_put

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    Writes the password to a text file.  The password is serialised in this
    format: '{key}:{proplist}' where proplist is a pair=value list.
    -------------------------------------------------------------------------
 */

int
    ipr_password_guard_put (
    ipr_password_t * self,              //  Reference to object
    FILE * file                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

icl_shortstr_t
    time_str;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_GUARD_PUT))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_guard_put_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_PUT))
    icl_trace_record (NULL, ipr_password_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_GUARD_PUT))
    icl_stats_inc ("ipr_password_guard_put", &s_ipr_password_guard_put_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

//
assert (file);
fprintf (file, "%s:", self->key);
if (self->expiry) {
    ipr_time_iso8601 (self->expiry, ipr_date_format_minute, 0, TRUE, time_str);
    fprintf (file, " expiry=%s", time_str);
}
if (self->expired)
    fprintf (file, " expired=1");
if (self->hits)
    fprintf (file, " hits=%lu", (unsigned long) self->hits);
if (self->hit_quota)
    fprintf (file, " hit-quota=%lu", (unsigned long) self->hit_quota);
if (*self->hit_from)
    fprintf (file, " hit-from=%s", self->hit_from);
if (self->hit_time) {
    ipr_time_iso8601 (self->hit_time, ipr_date_format_minute, 0, TRUE, time_str);
    fprintf (file, " hit-time=%s", time_str);
}
if (self->misses)
    fprintf (file, " misses=%lu", (unsigned long) self->misses);
if (self->miss_quota)
    fprintf (file, " miss-quota=%lu", (unsigned long) self->miss_quota);
if (*self->miss_from)
    fprintf (file, " miss-from=%s", self->miss_from);
if (self->miss_time) {
    ipr_time_iso8601 (self->miss_time, ipr_date_format_minute, 0, TRUE, time_str);
    fprintf (file, " miss-time=%s", time_str);
}
fprintf (file, "\n");

#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_PUT))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_GUARD_PUT))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_guard_put_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_password_hit

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    Updates the password for a successful hit and expires the password if
    it ran out of hit quotas, or passed its expiry time.  We do not reset
    the miss quota even after a successful hit, since that would mask any
    ongoing slow dictionary attack.
    -------------------------------------------------------------------------
 */

int
    ipr_password_hit (
    ipr_password_t * self,              //  Reference to object
    char * address                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_HIT))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_hit_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_HIT))
    icl_trace_record (NULL, ipr_password_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_HIT))
    icl_stats_inc ("ipr_password_hit", &s_ipr_password_hit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

//
icl_shortstr_cpy (self->hit_from, address);
self->hit_time = apr_time_now ();
self->hits++;

//  Expire password if the hit quota went down to 1
//  Ignore the hit quota and expiry if they are already zero
if ((self->hit_quota && --self->hit_quota == 0)
||  (self->expiry && apr_time_now () > self->expiry))
    self->expired = TRUE;

self->table_head->dirty = TRUE;

#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_HIT))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_HIT))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_hit_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_password_miss

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    Updates the password for a failed request and expires the password if
    it ran out of miss quotas, or passed its expiry time.
    -------------------------------------------------------------------------
 */

int
    ipr_password_miss (
    ipr_password_t * self,              //  Reference to object
    char * address                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_mutex_t
        *mutex;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_MISS))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_miss_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_MISS))
    icl_trace_record (NULL, ipr_password_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_MISS))
    icl_stats_inc ("ipr_password_miss", &s_ipr_password_miss_stats);
#endif

#if (defined (BASE_THREADSAFE))
    mutex = self ? self->mutex : NULL;
    if (mutex)
        icl_mutex_lock (mutex);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

//
icl_shortstr_cpy (self->miss_from, address);
self->miss_time = apr_time_now ();
self->misses++;

//  Expire password if the miss quota went down to 1
//  Ignore the miss quota and expiry if they are already zero
if ((self->miss_quota && --self->miss_quota == 0)
||  (self->expiry && apr_time_now () > self->expiry))
    self->expired = TRUE;

self->table_head->dirty = TRUE;

#if (defined (BASE_THREADSAFE))
    if (mutex)
        icl_mutex_unlock (mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_MISS))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_MISS))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_miss_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_password_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_password_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_SELFTEST))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_SELFTEST))
    icl_trace_record (NULL, ipr_password_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_SELFTEST))
    icl_stats_inc ("ipr_password_selftest", &s_ipr_password_selftest_stats);
#endif

//  selftest is in ipr_password_table
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_SELFTEST))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_SELFTEST))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_selftest_finish"
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
    ipr_password_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_password_remove_from_all_containers (
    ipr_password_t * self               //  The itemThe item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_password_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_password_remove_from_all_containers", &s_ipr_password_remove_from_all_containers_stats);
#endif

IPR_PASSWORD_ASSERT_SANE (self);
ipr_password_table_remove (self);
ipr_password_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_remove_from_all_containers_finish"
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
    ipr_password_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_password_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_password_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_SHOW))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_SHOW))
    icl_trace_record (NULL, ipr_password_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_SHOW))
    icl_stats_inc ("ipr_password_show", &s_ipr_password_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
if (self->list_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_password file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_SHOW))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_SHOW))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_show_finish"
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
    ipr_password_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_password_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_TERMINATE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_TERMINATE))
    icl_trace_record (NULL, ipr_password_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_TERMINATE))
    icl_stats_inc ("ipr_password_terminate", &s_ipr_password_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_TERMINATE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_TERMINATE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_terminate_finish"
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
    ipr_password_destroy

    Type: Component method
    Destroys a ipr_password_t object. Takes the address of a
    ipr_password_t reference (a pointer to a pointer) and nullifies the
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
    ipr_password_destroy_ (
    ipr_password_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_password_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_DESTROY_PUBLIC))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_password_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_password_destroy", &s_ipr_password_destroy_stats);
#endif

if (self) {
    ipr_password_annihilate (self_p);
    ipr_password_free ((ipr_password_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_DESTROY_PUBLIC))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_destroy_public_finish"
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
    ipr_password_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_password_t *
    ipr_password_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_password_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_ALLOC))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_ALLOC))
    icl_trace_record (NULL, ipr_password_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_ALLOC))
    icl_stats_inc ("ipr_password_alloc", &s_ipr_password_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_password_cache_initialise ();

self = (ipr_password_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_password_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_ALLOC))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_ALLOC))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_alloc_finish"
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
    ipr_password_free

    Type: Component method
    Freess a ipr_password_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_password_free (
    ipr_password_t * self               //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_FREE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_FREE))
    icl_trace_record (NULL, ipr_password_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_FREE))
    icl_stats_inc ("ipr_password_free", &s_ipr_password_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->mutex)
        icl_mutex_destroy (&self->mutex);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_password_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_password_t));
        self->object_tag = IPR_PASSWORD_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_FREE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_FREE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_free_finish"
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
    ipr_password_lock

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_password_lock (
    ipr_password_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_LOCK))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_LOCK))
    icl_trace_record (NULL, ipr_password_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_LOCK))
    icl_stats_inc ("ipr_password_lock", &s_ipr_password_lock_stats);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_lock (self->mutex);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_LOCK))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_LOCK))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_lock_finish"
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
    ipr_password_unlock

    Type: Component method
    Accepts a ipr_password_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_password_unlock (
    ipr_password_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_UNLOCK))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_UNLOCK))
    icl_trace_record (NULL, ipr_password_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_UNLOCK))
    icl_stats_inc ("ipr_password_unlock", &s_ipr_password_unlock_stats);
#endif

IPR_PASSWORD_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_mutex_unlock (self->mutex);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_UNLOCK))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_UNLOCK))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_unlock_finish"
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
    ipr_password_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_password_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_CACHE_INITIALISE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_password_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_CACHE_INITIALISE))
    icl_stats_inc ("ipr_password_cache_initialise", &s_ipr_password_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_password_t));
icl_system_register (ipr_password_cache_purge, ipr_password_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_CACHE_INITIALISE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_cache_initialise_finish"
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
    ipr_password_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_password_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_CACHE_PURGE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_PURGE))
    icl_trace_record (NULL, ipr_password_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_CACHE_PURGE))
    icl_stats_inc ("ipr_password_cache_purge", &s_ipr_password_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_PURGE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_CACHE_PURGE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_cache_purge_finish"
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
    ipr_password_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_password_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_CACHE_TERMINATE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_password_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_CACHE_TERMINATE))
    icl_stats_inc ("ipr_password_cache_terminate", &s_ipr_password_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_CACHE_TERMINATE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_cache_terminate_finish"
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
    ipr_password_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_password_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_SHOW_ANIMATION))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_password_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_SHOW_ANIMATION))
    icl_stats_inc ("ipr_password_show_animation", &s_ipr_password_show_animation_stats);
#endif

ipr_password_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_SHOW_ANIMATION))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_show_animation_finish"
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
    ipr_password_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_password_new_in_scope_ (
    ipr_password_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_password_table_t * table,       //  Table to insert into
    char * key,                         //  Hash key
    char * hash                         //  Not documented
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_PASSWORD)  ||  defined (BASE_ANIMATE_IPR_PASSWORD_NEW_IN_SCOPE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" hash=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, hash);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_password_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_PASSWORD)  ||  defined (BASE_STATS_IPR_PASSWORD_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_password_new_in_scope", &s_ipr_password_new_in_scope_stats);
#endif

*self_p = ipr_password_new_ (file,line,table,key,hash);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_password_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_password_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_PASSWORD)   || defined (BASE_ANIMATE_IPR_PASSWORD_NEW_IN_SCOPE))
    if (ipr_password_animating)
        icl_console_print ("<ipr_password_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" hash=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, hash, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_PASSWORD)   || defined (BASE_TRACE_IPR_PASSWORD_NEW)   || defined (BASE_TRACE_IPR_PASSWORD_DESTROY)   || defined (BASE_TRACE_IPR_PASSWORD_UPDATE)   || defined (BASE_TRACE_IPR_PASSWORD_ASSUME)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_SET)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_GET)   || defined (BASE_TRACE_IPR_PASSWORD_GUARD_PUT)   || defined (BASE_TRACE_IPR_PASSWORD_HIT)   || defined (BASE_TRACE_IPR_PASSWORD_MISS)   || defined (BASE_TRACE_IPR_PASSWORD_SELFTEST)   || defined (BASE_TRACE_IPR_PASSWORD_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_PASSWORD_SHOW)   || defined (BASE_TRACE_IPR_PASSWORD_TERMINATE)   || defined (BASE_TRACE_IPR_PASSWORD_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_PASSWORD_ALLOC)   || defined (BASE_TRACE_IPR_PASSWORD_FREE)   || defined (BASE_TRACE_IPR_PASSWORD_LOCK)   || defined (BASE_TRACE_IPR_PASSWORD_UNLOCK)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_PURGE)   || defined (BASE_TRACE_IPR_PASSWORD_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_PASSWORD_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_PASSWORD_NEW_IN_SCOPE) )
void
ipr_password_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
        case 5: method_name = "guard set"; break;
        case 6: method_name = "guard get"; break;
        case 7: method_name = "guard put"; break;
        case 8: method_name = "hit"; break;
        case 9: method_name = "miss"; break;
        case 10: method_name = "selftest"; break;
        case 11: method_name = "remove from all containers"; break;
        case 12: method_name = "show"; break;
        case 13: method_name = "terminate"; break;
        case 14: method_name = "destroy public"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "free"; break;
        case 17: method_name = "lock"; break;
        case 18: method_name = "unlock"; break;
        case 19: method_name = "cache initialise"; break;
        case 20: method_name = "cache purge"; break;
        case 21: method_name = "cache terminate"; break;
        case 22: method_name = "show animation"; break;
        case 23: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_password %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_password_version_start   = "VeRsIoNsTaRt:ipc";
char *ipr_password_component       = "ipr_password ";
char *ipr_password_version         = "1.0 ";
char *ipr_password_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_password_filename        = "ipr_password.icl ";
char *ipr_password_builddate       = "2009/02/19 ";
char *ipr_password_version_end     = "VeRsIoNeNd:ipc";

