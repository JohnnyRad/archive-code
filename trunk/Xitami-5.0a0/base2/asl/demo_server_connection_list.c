/*---------------------------------------------------------------------------
    demo_server_connection_list.c - demo_server_connection_list component

    This class implements the list container for demo_server_connection
    Generated from demo_server_connection_list.icl by icl_gen using GSL/4.
    
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
#include "demo_server_connection_list.h"  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_server_connection_list_t

//  Shorthands for class methods                                               

#define self_new            demo_server_connection_list_new
#define self_annihilate     demo_server_connection_list_annihilate
#define self_selftest       demo_server_connection_list_selftest
#define self_isempty        demo_server_connection_list_isempty
#define self_push           demo_server_connection_list_push
#define self_pop            demo_server_connection_list_pop
#define self_queue          demo_server_connection_list_queue
#define self_relink_before  demo_server_connection_list_relink_before
#define self_remove         demo_server_connection_list_remove
#define self_first          demo_server_connection_list_first
#define self_last           demo_server_connection_list_last
#define self_next           demo_server_connection_list_next
#define self_prev           demo_server_connection_list_prev
#define self_rehook         demo_server_connection_list_rehook
#define self_unhook         demo_server_connection_list_unhook
#define self_terminate      demo_server_connection_list_terminate
#define self_show           demo_server_connection_list_show
#define self_destroy        demo_server_connection_list_destroy
#define self_alloc          demo_server_connection_list_alloc
#define self_free           demo_server_connection_list_free
#define self_read_lock      demo_server_connection_list_read_lock
#define self_write_lock     demo_server_connection_list_write_lock
#define self_unlock         demo_server_connection_list_unlock
#define self_link           demo_server_connection_list_link
#define self_unlink         demo_server_connection_list_unlink
#define self_cache_initialise  demo_server_connection_list_cache_initialise
#define self_cache_purge    demo_server_connection_list_cache_purge
#define self_cache_terminate  demo_server_connection_list_cache_terminate
#define self_show_animation  demo_server_connection_list_show_animation
#define self_new_in_scope   demo_server_connection_list_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_NEW))
static icl_stats_t *s_demo_server_connection_list_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_DESTROY))
static icl_stats_t *s_demo_server_connection_list_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_SELFTEST))
static icl_stats_t *s_demo_server_connection_list_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_ISEMPTY))
static icl_stats_t *s_demo_server_connection_list_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_PUSH))
static icl_stats_t *s_demo_server_connection_list_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_POP))
static icl_stats_t *s_demo_server_connection_list_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_QUEUE))
static icl_stats_t *s_demo_server_connection_list_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE))
static icl_stats_t *s_demo_server_connection_list_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_REMOVE))
static icl_stats_t *s_demo_server_connection_list_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_FIRST))
static icl_stats_t *s_demo_server_connection_list_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_LAST))
static icl_stats_t *s_demo_server_connection_list_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_NEXT))
static icl_stats_t *s_demo_server_connection_list_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_PREV))
static icl_stats_t *s_demo_server_connection_list_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_REHOOK))
static icl_stats_t *s_demo_server_connection_list_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_UNHOOK))
static icl_stats_t *s_demo_server_connection_list_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_TERMINATE))
static icl_stats_t *s_demo_server_connection_list_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_SHOW))
static icl_stats_t *s_demo_server_connection_list_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC))
static icl_stats_t *s_demo_server_connection_list_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_ALLOC))
static icl_stats_t *s_demo_server_connection_list_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_FREE))
static icl_stats_t *s_demo_server_connection_list_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_READ_LOCK))
static icl_stats_t *s_demo_server_connection_list_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK))
static icl_stats_t *s_demo_server_connection_list_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_UNLOCK))
static icl_stats_t *s_demo_server_connection_list_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_LINK))
static icl_stats_t *s_demo_server_connection_list_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_UNLINK))
static icl_stats_t *s_demo_server_connection_list_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE))
static icl_stats_t *s_demo_server_connection_list_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE))
static icl_stats_t *s_demo_server_connection_list_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE))
static icl_stats_t *s_demo_server_connection_list_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION))
static icl_stats_t *s_demo_server_connection_list_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE))
static icl_stats_t *s_demo_server_connection_list_new_in_scope_stats = NULL;
#endif
#define demo_server_connection_list_annihilate(self)  demo_server_connection_list_annihilate_ (self, __FILE__, __LINE__)
static void
    demo_server_connection_list_annihilate_ (
demo_server_connection_list_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static inline void
    demo_server_connection_list_rehook (
demo_server_connection_t * item,        //  Not documented
demo_server_connection_t * left,        //  Not documented
demo_server_connection_t * right        //  Not documented
);

static inline demo_server_connection_t *
    demo_server_connection_list_unhook (
demo_server_connection_t * item         //  Not documented
);

#define demo_server_connection_list_alloc()  demo_server_connection_list_alloc_ (__FILE__, __LINE__)
static demo_server_connection_list_t *
    demo_server_connection_list_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define demo_server_connection_list_free(self)  demo_server_connection_list_free_ (self, __FILE__, __LINE__)
static void
    demo_server_connection_list_free_ (
demo_server_connection_list_t * self,   //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    demo_server_connection_list_cache_initialise (
void);

static void
    demo_server_connection_list_cache_purge (
void);

static void
    demo_server_connection_list_cache_terminate (
void);

Bool
    demo_server_connection_list_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    demo_server_connection_list_new

    Type: Component method
    Creates and initialises a new demo_server_connection_list_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

demo_server_connection_list_t *
    demo_server_connection_list_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    demo_server_connection_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_NEW))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW))
    icl_trace_record (1, demo_server_connection_list_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_NEW))
    icl_stats_inc ("demo_server_connection_list_new", &s_demo_server_connection_list_new_stats);
#endif

    self = demo_server_connection_list_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_SERVER_CONNECTION_LIST_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
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
        icl_mem_set_callback (self, demo_server_connection_list_show_);
#endif

self->demo_server_connection.list_next = &self->demo_server_connection;
self->demo_server_connection.list_prev = &self->demo_server_connection;
self->demo_server_connection.list_head = self;

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_NEW))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_new_finish"
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
    demo_server_connection_list_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_list_annihilate_ (
    demo_server_connection_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    int
        history_last;
#endif

demo_server_connection_t
    *item;
    demo_server_connection_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_DESTROY))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY))
    icl_trace_record (1, demo_server_connection_list_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_DESTROY))
    icl_stats_inc ("demo_server_connection_list_annihilate", &s_demo_server_connection_list_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = file;
    self->history_line  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = line;
    self->history_type  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = self->links;
#endif

    DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

item = (demo_server_connection_t *) self->demo_server_connection.list_next;
while (item != &self->demo_server_connection) {
    //  Unlink child without lock (we already have the lock)               
    demo_server_connection_list_unhook (item);

    demo_server_connection_unlink (&item);
    item = (demo_server_connection_t *) self->demo_server_connection.list_next;
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_DESTROY))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_destroy_finish"
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
    demo_server_connection_list_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_list_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_SELFTEST))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SELFTEST))
    icl_trace_record (1, demo_server_connection_list_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_SELFTEST))
    icl_stats_inc ("demo_server_connection_list_selftest", &s_demo_server_connection_list_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SELFTEST))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_SELFTEST))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_selftest_finish"
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
    demo_server_connection_list_isempty

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_isempty (
    demo_server_connection_list_t * self  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_ISEMPTY))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ISEMPTY))
    icl_trace_record (1, demo_server_connection_list_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_ISEMPTY))
    icl_stats_inc ("demo_server_connection_list_isempty", &s_demo_server_connection_list_isempty_stats);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

rc = (self->demo_server_connection.list_next == &self->demo_server_connection);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ISEMPTY))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_ISEMPTY))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_isempty_finish"
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
    demo_server_connection_list_push

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_push (
    demo_server_connection_list_t * self,   //  Reference to object
    demo_server_connection_t * item     //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_PUSH))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_push_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PUSH))
    icl_trace_record (1, demo_server_connection_list_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_PUSH))
    icl_stats_inc ("demo_server_connection_list_push", &s_demo_server_connection_list_push_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->list_head) {
    demo_server_connection_link (item);
}
else
if (item->list_head != self) {
    icl_console_print ("E: demo_server_connection item inserted into multiple list containers");
    assert (item->list_head == self);
}
demo_server_connection_list_unhook (item);
demo_server_connection_list_rehook (item, &self->demo_server_connection, (demo_server_connection_t *) self->demo_server_connection.list_next);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PUSH))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_PUSH))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_push_finish"
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
    demo_server_connection_list_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_list_pop (
    demo_server_connection_list_t * self  //  The list
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_server_connection_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_POP))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_POP))
    icl_trace_record (1, demo_server_connection_list_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_POP))
    icl_stats_inc ("demo_server_connection_list_pop", &s_demo_server_connection_list_pop_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

if (self->demo_server_connection.list_next == &self->demo_server_connection)
    item = NULL;
else {
    item = demo_server_connection_list_unhook ((demo_server_connection_t *) self->demo_server_connection.list_next);
}
}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_POP))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_POP))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_pop_finish"
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
    demo_server_connection_list_queue

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_queue (
    demo_server_connection_list_t * self,   //  Reference to object
    demo_server_connection_t * item     //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_QUEUE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_QUEUE))
    icl_trace_record (1, demo_server_connection_list_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_QUEUE))
    icl_stats_inc ("demo_server_connection_list_queue", &s_demo_server_connection_list_queue_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the             
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->list_head) {
    demo_server_connection_link (item);
}
else
if (item->list_head != self) {
    icl_console_print ("E: demo_server_connection item inserted into multiple list containers");
    assert (item->list_head == self);
}
demo_server_connection_list_unhook (item);
demo_server_connection_list_rehook (item, (demo_server_connection_t *) self->demo_server_connection.list_prev, &self->demo_server_connection);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_QUEUE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_QUEUE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_queue_finish"
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
    demo_server_connection_list_relink_before

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_relink_before (
    demo_server_connection_t * item,    //  Not documented
    demo_server_connection_t * where    //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code
    demo_server_connection_list_t *
        self = (demo_server_connection_list_t *) where->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_relink_before_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE))
    icl_trace_record (1, demo_server_connection_list_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE))
    icl_stats_inc ("demo_server_connection_list_relink_before", &s_demo_server_connection_list_relink_before_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

//  If list_head is non-null then we are moving within the             
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->list_head) {
    demo_server_connection_link (item);
}
else
if (item->list_head != self) {
    icl_console_print ("E: demo_server_connection item inserted into multiple list containers");
    assert (item->list_head == self);
}            
demo_server_connection_list_unhook (item);
demo_server_connection_list_rehook (item, (demo_server_connection_t *) where->list_prev, where);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_relink_before_finish"
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
    demo_server_connection_list_remove

    Type: Component method
    Removes the item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_remove (
    demo_server_connection_t * item     //  Not documented
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_server_connection_list_t *
        self = (demo_server_connection_list_t *) item->list_head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_REMOVE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REMOVE))
    icl_trace_record (1, demo_server_connection_list_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_REMOVE))
    icl_stats_inc ("demo_server_connection_list_remove", &s_demo_server_connection_list_remove_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (self
&&  self == item->list_head) { //       Catch case where item moved
    demo_server_connection_list_unhook (item);
    demo_server_connection_unlink (&item);
}
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REMOVE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_REMOVE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_remove_finish"
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
    demo_server_connection_list_first

    Type: Component method
    Returns the first demo_server_connection item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_list_first_ (
    demo_server_connection_list_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_server_connection_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_FIRST))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FIRST))
    icl_trace_record (1, demo_server_connection_list_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_FIRST))
    icl_stats_inc ("demo_server_connection_list_first", &s_demo_server_connection_list_first_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (demo_server_connection_t *) self->demo_server_connection.list_next;
if (item == &self->demo_server_connection)
    item = NULL;
else
    demo_server_connection_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FIRST))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_FIRST))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_first_finish"
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
    demo_server_connection_list_last

    Type: Component method
    Returns the last demo_server_connection item on the list.  If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_list_last_ (
    demo_server_connection_list_t * self,   //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_server_connection_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_LAST))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LAST))
    icl_trace_record (1, demo_server_connection_list_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_LAST))
    icl_stats_inc ("demo_server_connection_list_last", &s_demo_server_connection_list_last_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

item = (demo_server_connection_t *) self->demo_server_connection.list_prev;
if (item == &self->demo_server_connection)
    item = NULL;
else
    demo_server_connection_link (item);

}

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LAST))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_LAST))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_last_finish"
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
    demo_server_connection_list_next

    Type: Component method
    Returns the following item on the demo_server_connection list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_list_next_ (
    demo_server_connection_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_server_connection_t *
        item = *item_p;                 //  Dereferenced item
    demo_server_connection_t *
        next = NULL;                    //  The item to return
    demo_server_connection_list_t *
        self = (demo_server_connection_list_t *) item->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_NEXT))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_next_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEXT))
    icl_trace_record (1, demo_server_connection_list_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_NEXT))
    icl_stats_inc ("demo_server_connection_list_next", &s_demo_server_connection_list_next_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->list_head) { //       Catch case where item moved
    next = (demo_server_connection_t *) item->list_next;
    if (next == &self->demo_server_connection)
        next = NULL;
    else
        demo_server_connection_link (next);

}
demo_server_connection_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEXT))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_NEXT))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_next_finish"
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
    demo_server_connection_list_prev

    Type: Component method
    Returns the preceding item on the demo_server_connection list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

demo_server_connection_t *
    demo_server_connection_list_prev_ (
    demo_server_connection_t * ( * item_p ),   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_server_connection_t *
        item = *item_p;                 //  Dereferenced item
    demo_server_connection_t *
        prev = NULL;                    //  The item to return
    demo_server_connection_list_t *
        self = (demo_server_connection_list_t *) item->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_PREV))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_prev_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PREV))
    icl_trace_record (1, demo_server_connection_list_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_PREV))
    icl_stats_inc ("demo_server_connection_list_prev", &s_demo_server_connection_list_prev_stats);
#endif


#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_read_lock (rwlock);
#endif

if (self
&&  self == item->list_head) { //       Catch case where item moved
    prev = (demo_server_connection_t *) item->list_prev;
    if (prev == &self->demo_server_connection)
        prev = NULL;
    else
        demo_server_connection_link (prev);

}
demo_server_connection_unlink (item_p);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PREV))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_PREV))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_prev_finish"
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
    demo_server_connection_list_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    demo_server_connection_list_rehook (
    demo_server_connection_t * item,    //  Not documented
    demo_server_connection_t * left,    //  Not documented
    demo_server_connection_t * right    //  Not documented
)
{
demo_server_connection_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_REHOOK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_rehook_start"
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

#if (defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REHOOK))
    icl_trace_record (1, demo_server_connection_list_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_REHOOK))
    icl_stats_inc ("demo_server_connection_list_rehook", &s_demo_server_connection_list_rehook_stats);
#endif

swap = (demo_server_connection_t *) left->list_next;
left->list_next = item->list_next;
item->list_next = swap;

swap = (demo_server_connection_t *) item->list_prev;
item->list_prev = right->list_prev;
right->list_prev = swap;

item->list_head = left->list_head;
#if (defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REHOOK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_REHOOK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_rehook_finish"
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
    demo_server_connection_list_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline demo_server_connection_t *
    demo_server_connection_list_unhook (
    demo_server_connection_t * item     //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_UNHOOK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_unhook_start"
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

#if (defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNHOOK))
    icl_trace_record (1, demo_server_connection_list_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_UNHOOK))
    icl_stats_inc ("demo_server_connection_list_unhook", &s_demo_server_connection_list_unhook_stats);
#endif

demo_server_connection_list_rehook (item, (demo_server_connection_t *) item->list_prev, (demo_server_connection_t *) item->list_next);
item->list_head = NULL;
#if (defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNHOOK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_UNHOOK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_unhook_finish"
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
    demo_server_connection_list_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_list_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_TERMINATE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_TERMINATE))
    icl_trace_record (1, demo_server_connection_list_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_TERMINATE))
    icl_stats_inc ("demo_server_connection_list_terminate", &s_demo_server_connection_list_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_TERMINATE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_TERMINATE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_terminate_finish"
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
    demo_server_connection_list_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_list_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    demo_server_connection_list_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_SHOW))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW))
    icl_trace_record (1, demo_server_connection_list_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_SHOW))
    icl_stats_inc ("demo_server_connection_list_show", &s_demo_server_connection_list_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <demo_server_connection_list zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    if (self->history_last > DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH;
        self->history_last %= DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </demo_server_connection_list>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_SHOW))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_show_finish"
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
    demo_server_connection_list_destroy

    Type: Component method
    Destroys a demo_server_connection_list_t object. Takes the address of a
    demo_server_connection_list_t reference (a pointer to a pointer) and nullifies the
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
    demo_server_connection_list_destroy_ (
    demo_server_connection_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    demo_server_connection_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC))
    icl_trace_record (1, demo_server_connection_list_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC))
    icl_stats_inc ("demo_server_connection_list_destroy", &s_demo_server_connection_list_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        demo_server_connection_list_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on demo_server_connection_list object");
        demo_server_connection_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        demo_server_connection_list_free_ ((demo_server_connection_list_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_destroy_public_finish"
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
    demo_server_connection_list_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_server_connection_list_t *
    demo_server_connection_list_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_server_connection_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_ALLOC))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ALLOC))
    icl_trace_record (1, demo_server_connection_list_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_ALLOC))
    icl_stats_inc ("demo_server_connection_list_alloc", &s_demo_server_connection_list_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_server_connection_list_cache_initialise ();

self = (demo_server_connection_list_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_server_connection_list_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ALLOC))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_ALLOC))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_alloc_finish"
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
    demo_server_connection_list_free

    Type: Component method
    Freess a demo_server_connection_list_t object.
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_list_free_ (
    demo_server_connection_list_t * self,   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_FREE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FREE))
    icl_trace_record (1, demo_server_connection_list_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_FREE))
    icl_stats_inc ("demo_server_connection_list_free", &s_demo_server_connection_list_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = "free";
        self->history_links [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (demo_server_connection_list_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_server_connection_list_t));
        self->object_tag = DEMO_SERVER_CONNECTION_LIST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FREE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_FREE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_free_finish"
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
    demo_server_connection_list_read_lock

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_read_lock (
    demo_server_connection_list_t * self  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_READ_LOCK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_READ_LOCK))
    icl_trace_record (1, demo_server_connection_list_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_READ_LOCK))
    icl_stats_inc ("demo_server_connection_list_read_lock", &s_demo_server_connection_list_read_lock_stats);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_READ_LOCK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_READ_LOCK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_read_lock_finish"
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
    demo_server_connection_list_write_lock

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_write_lock (
    demo_server_connection_list_t * self  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK))
    icl_trace_record (1, demo_server_connection_list_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK))
    icl_stats_inc ("demo_server_connection_list_write_lock", &s_demo_server_connection_list_write_lock_stats);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_write_lock_finish"
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
    demo_server_connection_list_unlock

    Type: Component method
    Accepts a demo_server_connection_list_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_server_connection_list_unlock (
    demo_server_connection_list_t * self  //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_UNLOCK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLOCK))
    icl_trace_record (1, demo_server_connection_list_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_UNLOCK))
    icl_stats_inc ("demo_server_connection_list_unlock", &s_demo_server_connection_list_unlock_stats);
#endif

DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLOCK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_UNLOCK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_unlock_finish"
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
    demo_server_connection_list_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

demo_server_connection_list_t *
    demo_server_connection_list_link_ (
    demo_server_connection_list_t * self,   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_LINK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LINK))
    icl_trace_record (1, demo_server_connection_list_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_LINK))
    icl_stats_inc ("demo_server_connection_list_link", &s_demo_server_connection_list_link_stats);
#endif

    if (self) {
        DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = "link";
        self->history_links [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LINK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_LINK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_link_finish"
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
    demo_server_connection_list_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_list_unlink_ (
    demo_server_connection_list_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
    int
        history_last;
#endif

    demo_server_connection_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_UNLINK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLINK))
    icl_trace_record (1, demo_server_connection_list_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_UNLINK))
    icl_stats_inc ("demo_server_connection_list_unlink", &s_demo_server_connection_list_unlink_stats);
#endif

    if (self) {
        DEMO_SERVER_CONNECTION_LIST_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on demo_server_connection_list object");
            demo_server_connection_list_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_DEMO_SERVER_CONNECTION_LIST)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = file;
        self->history_line  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = line;
        self->history_type  [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % DEMO_SERVER_CONNECTION_LIST_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            demo_server_connection_list_annihilate_ (self_p, file, line);
        demo_server_connection_list_free_ ((demo_server_connection_list_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLINK))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_UNLINK))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_unlink_finish"
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
    demo_server_connection_list_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_list_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE))
    icl_trace_record (1, demo_server_connection_list_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE))
    icl_stats_inc ("demo_server_connection_list_cache_initialise", &s_demo_server_connection_list_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_server_connection_list_t));
icl_system_register (demo_server_connection_list_cache_purge, demo_server_connection_list_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_cache_initialise_finish"
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
    demo_server_connection_list_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_list_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE))
    icl_trace_record (1, demo_server_connection_list_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE))
    icl_stats_inc ("demo_server_connection_list_cache_purge", &s_demo_server_connection_list_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_cache_purge_finish"
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
    demo_server_connection_list_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_server_connection_list_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE))
    icl_trace_record (1, demo_server_connection_list_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE))
    icl_stats_inc ("demo_server_connection_list_cache_terminate", &s_demo_server_connection_list_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_cache_terminate_finish"
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
    demo_server_connection_list_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_list_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION))
    icl_trace_record (1, demo_server_connection_list_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION))
    icl_stats_inc ("demo_server_connection_list_show_animation", &s_demo_server_connection_list_show_animation_stats);
#endif

demo_server_connection_list_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_show_animation_finish"
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
    demo_server_connection_list_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_server_connection_list_new_in_scope_ (
    demo_server_connection_list_t * * self_p,   //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE))
    icl_trace_record (1, demo_server_connection_list_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST)  ||  defined (BASE_STATS_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE))
    icl_stats_inc ("demo_server_connection_list_new_in_scope", &s_demo_server_connection_list_new_in_scope_stats);
#endif

*self_p = demo_server_connection_list_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_server_connection_list_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE))
    icl_trace_record (1, demo_server_connection_list_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_ANIMATE_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE))
    if (demo_server_connection_list_animating)
        icl_console_print ("<demo_server_connection_list_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SELFTEST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ISEMPTY)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PUSH)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_POP)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_QUEUE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REMOVE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FIRST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LAST)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEXT)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_PREV)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_REHOOK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNHOOK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_ALLOC)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_FREE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_READ_LOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_WRITE_LOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLOCK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_LINK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_UNLINK)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_SERVER_CONNECTION_LIST_NEW_IN_SCOPE) )
void
demo_server_connection_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "isempty"; break;
        case 5: method_name = "push"; break;
        case 6: method_name = "pop"; break;
        case 7: method_name = "queue"; break;
        case 8: method_name = "relink before"; break;
        case 9: method_name = "remove"; break;
        case 10: method_name = "first"; break;
        case 11: method_name = "last"; break;
        case 12: method_name = "next"; break;
        case 13: method_name = "prev"; break;
        case 14: method_name = "rehook"; break;
        case 15: method_name = "unhook"; break;
        case 16: method_name = "terminate"; break;
        case 17: method_name = "show"; break;
        case 18: method_name = "destroy public"; break;
        case 19: method_name = "alloc"; break;
        case 20: method_name = "free"; break;
        case 21: method_name = "read lock"; break;
        case 22: method_name = "write lock"; break;
        case 23: method_name = "unlock"; break;
        case 24: method_name = "link"; break;
        case 25: method_name = "unlink"; break;
        case 26: method_name = "cache initialise"; break;
        case 27: method_name = "cache purge"; break;
        case 28: method_name = "cache terminate"; break;
        case 29: method_name = "show animation"; break;
        case 30: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_server_connection_list %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_server_connection_list_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_server_connection_list_component  = "demo_server_connection_list ";
char *demo_server_connection_list_version  = "1.0 ";
char *demo_server_connection_list_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_server_connection_list_filename  = "demo_server_connection_list.icl ";
char *demo_server_connection_list_builddate  = "2009/02/19 ";
char *demo_server_connection_list_version_end  = "VeRsIoNeNd:ipc";

