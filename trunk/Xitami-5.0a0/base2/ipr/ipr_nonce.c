/*---------------------------------------------------------------------------
    ipr_nonce.c - ipr_nonce component

Nonces are held in a hash table.  The nonce value is the key into the
table.  This class generates the nonce value.
    Generated from ipr_nonce.icl by icl_gen using GSL/4.
    
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
#include "ipr_nonce.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_nonce_t

//  Shorthands for class methods                                               

#define self_new            ipr_nonce_new
#define self_assume         ipr_nonce_assume
#define self_expired        ipr_nonce_expired
#define self_annihilate     ipr_nonce_annihilate
#define self_selftest       ipr_nonce_selftest
#define self_remove_from_all_containers  ipr_nonce_remove_from_all_containers
#define self_show           ipr_nonce_show
#define self_terminate      ipr_nonce_terminate
#define self_destroy        ipr_nonce_destroy
#define self_alloc          ipr_nonce_alloc
#define self_free           ipr_nonce_free
#define self_cache_initialise  ipr_nonce_cache_initialise
#define self_cache_purge    ipr_nonce_cache_purge
#define self_cache_terminate  ipr_nonce_cache_terminate
#define self_show_animation  ipr_nonce_show_animation
#define self_new_in_scope   ipr_nonce_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_NEW))
static icl_stats_t *s_ipr_nonce_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_ASSUME))
static icl_stats_t *s_ipr_nonce_assume_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_EXPIRED))
static icl_stats_t *s_ipr_nonce_expired_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_DESTROY))
static icl_stats_t *s_ipr_nonce_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_SELFTEST))
static icl_stats_t *s_ipr_nonce_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_nonce_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_SHOW))
static icl_stats_t *s_ipr_nonce_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_TERMINATE))
static icl_stats_t *s_ipr_nonce_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_nonce_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_ALLOC))
static icl_stats_t *s_ipr_nonce_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_FREE))
static icl_stats_t *s_ipr_nonce_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_CACHE_INITIALISE))
static icl_stats_t *s_ipr_nonce_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_CACHE_PURGE))
static icl_stats_t *s_ipr_nonce_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_CACHE_TERMINATE))
static icl_stats_t *s_ipr_nonce_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_SHOW_ANIMATION))
static icl_stats_t *s_ipr_nonce_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_nonce_new_in_scope_stats = NULL;
#endif
static void
    ipr_nonce_annihilate (
ipr_nonce_t * ( * self_p )              //  Reference to object reference
);

#define ipr_nonce_alloc()               ipr_nonce_alloc_ (__FILE__, __LINE__)
static ipr_nonce_t *
    ipr_nonce_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_nonce_free (
ipr_nonce_t * self                      //  Object reference
);

static void
    ipr_nonce_cache_initialise (
void);

static void
    ipr_nonce_cache_purge (
void);

static void
    ipr_nonce_cache_terminate (
void);

Bool
    ipr_nonce_animating = TRUE;         //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_nonce_new

    Type: Component method
    Creates and initialises a new ipr_nonce_t object, returns a
    reference to the created object.
    Initialises a new hash table item and plases it into the specified hash
    table, if not null.
    -------------------------------------------------------------------------
 */

ipr_nonce_t *
    ipr_nonce_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_nonce_table_t * table,          //  Table to insert into
    char * key,                         //  Hash keyNonce value or NULL
    size_t ttl,                         //  Time to live, seconds
    size_t quota                        //  Lifespan, in hits
)
{
icl_shortstr_t
    nonce_data;
char
    *digest;
    ipr_nonce_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_NEW))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" key=\"%s\""
" ttl=\"%u\""
" quota=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, key, ttl, quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_NEW))
    icl_trace_record (NULL, ipr_nonce_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_NEW))
    icl_stats_inc ("ipr_nonce_new", &s_ipr_nonce_new_stats);
#endif

    self = ipr_nonce_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_NONCE_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_nonce_show_);
#endif

self->table_head = NULL;
self->table_index = 0;              //  Will be set by container
//
if (!key) {
    //  nonce is "time:{md5(time:random)}"
    //  This is overkill, a simpler nonce would work as well
    sprintf (nonce_data, "%016llx:", (long long unsigned int) apr_time_now ());
    ipr_str_random (nonce_data + strlen (nonce_data), "Ax16");
    digest = ipr_str_md5 (nonce_data);
    icl_shortstr_fmt (nonce_data + 16, digest);
    icl_mem_free (digest);
    key = nonce_data;
}
self->quota = quota;
self->expiry = apr_time_now () + (ttl * 1000 * 1000);
if (table && self && ipr_nonce_table_insert (table, key, self))
    ipr_nonce_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_NEW))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_NEW))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" key=\"%s\""
" ttl=\"%u\""
" quota=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, table, key, ttl, quota, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_nonce_assume

    Type: Component method
    Create or update nonce with specified key
    -------------------------------------------------------------------------
 */

ipr_nonce_t *
    ipr_nonce_assume (
    ipr_nonce_table_t * table,          //  Nonce table
    char * key,                         //  Nonce value
    size_t ttl,                         //  Time to live, seconds
    size_t quota                        //  Lifespan, in hits
)
{
ipr_nonce_t
    *nonce;
    ipr_nonce_t *
        self;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_ASSUME))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_assume_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" ttl=\"%u\""
" quota=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, ttl, quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_ASSUME))
    icl_trace_record (NULL, ipr_nonce_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_ASSUME))
    icl_stats_inc ("ipr_nonce_assume", &s_ipr_nonce_assume_stats);
#endif

//
nonce = ipr_nonce_table_search (table, key);
if (!nonce)
    nonce = ipr_nonce_new (table, key, ttl, quota);
return (nonce);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_ASSUME))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_ASSUME))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_assume_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" table=\"%pp\""
" key=\"%s\""
" ttl=\"%u\""
" quota=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, table, key, ttl, quota, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_nonce_expired

    Type: Component method
    Accepts a ipr_nonce_t reference and returns zero in case of success,
    1 in case of errors.
    Tries to consume one request quota from the nonce, and checks the current
    time. If the nonce did not have sufficient quota, or TTL was expired,
    returns TRUE, else returns FALSE.
    -------------------------------------------------------------------------
 */

int
    ipr_nonce_expired (
    ipr_nonce_t * self                  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_EXPIRED))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_expired_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_EXPIRED))
    icl_trace_record (NULL, ipr_nonce_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_EXPIRED))
    icl_stats_inc ("ipr_nonce_expired", &s_ipr_nonce_expired_stats);
#endif

IPR_NONCE_ASSERT_SANE (self);

//
rc = FALSE;
if (self->quota) {
    self->quota--;
    if (apr_time_now () > self->expiry)
        rc = TRUE;
}
else 
    rc = TRUE;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_EXPIRED))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_EXPIRED))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_expired_finish"
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
    ipr_nonce_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_nonce_annihilate (
    ipr_nonce_t * ( * self_p )          //  Reference to object reference
)
{

    ipr_nonce_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_DESTROY))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_DESTROY))
    icl_trace_record (NULL, ipr_nonce_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_DESTROY))
    icl_stats_inc ("ipr_nonce_annihilate", &s_ipr_nonce_annihilate_stats);
#endif

IPR_NONCE_ASSERT_SANE (self);
ipr_nonce_remove_from_all_containers (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_DESTROY))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_DESTROY))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_destroy_finish"
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
    ipr_nonce_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_nonce_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_SELFTEST))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_SELFTEST))
    icl_trace_record (NULL, ipr_nonce_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_SELFTEST))
    icl_stats_inc ("ipr_nonce_selftest", &s_ipr_nonce_selftest_stats);
#endif

ipr_nonce_table_t
    *table;
ipr_nonce_t
    *nonce;

table = ipr_nonce_table_new ();
nonce = ipr_nonce_new (table, NULL, 60, 10);
assert (strlen (nonce->key) == 48);
ipr_nonce_table_destroy (&table);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_SELFTEST))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_SELFTEST))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_selftest_finish"
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
    ipr_nonce_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_nonce_remove_from_all_containers (
    ipr_nonce_t * self                  //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_nonce_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_nonce_remove_from_all_containers", &s_ipr_nonce_remove_from_all_containers_stats);
#endif

IPR_NONCE_ASSERT_SANE (self);
ipr_nonce_table_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_remove_from_all_containers_finish"
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
    ipr_nonce_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_nonce_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_nonce_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_SHOW))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_SHOW))
    icl_trace_record (NULL, ipr_nonce_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_SHOW))
    icl_stats_inc ("ipr_nonce_show", &s_ipr_nonce_show_stats);
#endif

self = item;
container_links = 0;
if (self->table_head)
   container_links++;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_nonce file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_SHOW))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_SHOW))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_show_finish"
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
    ipr_nonce_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_nonce_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_TERMINATE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_TERMINATE))
    icl_trace_record (NULL, ipr_nonce_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_TERMINATE))
    icl_stats_inc ("ipr_nonce_terminate", &s_ipr_nonce_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_TERMINATE))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_TERMINATE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_terminate_finish"
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
    ipr_nonce_destroy

    Type: Component method
    Destroys a ipr_nonce_t object. Takes the address of a
    ipr_nonce_t reference (a pointer to a pointer) and nullifies the
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
    ipr_nonce_destroy_ (
    ipr_nonce_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_nonce_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_DESTROY_PUBLIC))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_nonce_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_nonce_destroy", &s_ipr_nonce_destroy_stats);
#endif

if (self) {
    ipr_nonce_annihilate (self_p);
    ipr_nonce_free ((ipr_nonce_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_DESTROY_PUBLIC))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_destroy_public_finish"
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
    ipr_nonce_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_nonce_t *
    ipr_nonce_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_nonce_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_ALLOC))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_ALLOC))
    icl_trace_record (NULL, ipr_nonce_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_ALLOC))
    icl_stats_inc ("ipr_nonce_alloc", &s_ipr_nonce_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_nonce_cache_initialise ();

self = (ipr_nonce_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_nonce_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_ALLOC))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_ALLOC))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_alloc_finish"
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
    ipr_nonce_free

    Type: Component method
    Freess a ipr_nonce_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_nonce_free (
    ipr_nonce_t * self                  //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_FREE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_FREE))
    icl_trace_record (NULL, ipr_nonce_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_FREE))
    icl_stats_inc ("ipr_nonce_free", &s_ipr_nonce_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_nonce_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_nonce_t));
        self->object_tag = IPR_NONCE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_FREE))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_FREE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_free_finish"
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
    ipr_nonce_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_nonce_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_CACHE_INITIALISE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_nonce_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_CACHE_INITIALISE))
    icl_stats_inc ("ipr_nonce_cache_initialise", &s_ipr_nonce_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_nonce_t));
icl_system_register (ipr_nonce_cache_purge, ipr_nonce_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_CACHE_INITIALISE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_cache_initialise_finish"
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
    ipr_nonce_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_nonce_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_CACHE_PURGE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_PURGE))
    icl_trace_record (NULL, ipr_nonce_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_CACHE_PURGE))
    icl_stats_inc ("ipr_nonce_cache_purge", &s_ipr_nonce_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_PURGE))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_CACHE_PURGE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_cache_purge_finish"
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
    ipr_nonce_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_nonce_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_CACHE_TERMINATE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_nonce_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_CACHE_TERMINATE))
    icl_stats_inc ("ipr_nonce_cache_terminate", &s_ipr_nonce_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_CACHE_TERMINATE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_cache_terminate_finish"
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
    ipr_nonce_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_nonce_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_SHOW_ANIMATION))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_nonce_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_SHOW_ANIMATION))
    icl_stats_inc ("ipr_nonce_show_animation", &s_ipr_nonce_show_animation_stats);
#endif

ipr_nonce_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_SHOW_ANIMATION))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_show_animation_finish"
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
    ipr_nonce_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_nonce_new_in_scope_ (
    ipr_nonce_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_nonce_table_t * table,          //  Table to insert into
    char * key,                         //  Hash keyNonce value or NULL
    size_t ttl,                         //  Time to live, seconds
    size_t quota                        //  Lifespan, in hits
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_NONCE)  ||  defined (BASE_ANIMATE_IPR_NONCE_NEW_IN_SCOPE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" key=\"%s\""
" ttl=\"%u\""
" quota=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, key, ttl, quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_nonce_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_NONCE)  ||  defined (BASE_STATS_IPR_NONCE_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_nonce_new_in_scope", &s_ipr_nonce_new_in_scope_stats);
#endif

*self_p = ipr_nonce_new_ (file,line,table,key,ttl,quota);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_nonce_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_nonce_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_NONCE)   || defined (BASE_ANIMATE_IPR_NONCE_NEW_IN_SCOPE))
    if (ipr_nonce_animating)
        icl_console_print ("<ipr_nonce_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" table=\"%pp\""
" key=\"%s\""
" ttl=\"%u\""
" quota=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, table, key, ttl, quota, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_NONCE)   || defined (BASE_TRACE_IPR_NONCE_NEW)   || defined (BASE_TRACE_IPR_NONCE_ASSUME)   || defined (BASE_TRACE_IPR_NONCE_EXPIRED)   || defined (BASE_TRACE_IPR_NONCE_DESTROY)   || defined (BASE_TRACE_IPR_NONCE_SELFTEST)   || defined (BASE_TRACE_IPR_NONCE_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_NONCE_SHOW)   || defined (BASE_TRACE_IPR_NONCE_TERMINATE)   || defined (BASE_TRACE_IPR_NONCE_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_NONCE_ALLOC)   || defined (BASE_TRACE_IPR_NONCE_FREE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_PURGE)   || defined (BASE_TRACE_IPR_NONCE_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_NONCE_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_NONCE_NEW_IN_SCOPE) )
void
ipr_nonce_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "assume"; break;
        case 3: method_name = "expired"; break;
        case 4: method_name = "destroy"; break;
        case 5: method_name = "selftest"; break;
        case 6: method_name = "remove from all containers"; break;
        case 7: method_name = "show"; break;
        case 8: method_name = "terminate"; break;
        case 9: method_name = "destroy public"; break;
        case 10: method_name = "alloc"; break;
        case 11: method_name = "free"; break;
        case 12: method_name = "cache initialise"; break;
        case 13: method_name = "cache purge"; break;
        case 14: method_name = "cache terminate"; break;
        case 15: method_name = "show animation"; break;
        case 16: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_nonce %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_nonce_version_start      = "VeRsIoNsTaRt:ipc";
char *ipr_nonce_component          = "ipr_nonce ";
char *ipr_nonce_version            = "1.0 ";
char *ipr_nonce_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_nonce_filename           = "ipr_nonce.icl ";
char *ipr_nonce_builddate          = "2009/02/19 ";
char *ipr_nonce_version_end        = "VeRsIoNeNd:ipc";

