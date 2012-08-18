/*---------------------------------------------------------------------------
    ipr_token_list.c - ipr_token_list component

    This class implements the list container for ipr_token
    Generated from ipr_token_list.icl by icl_gen using GSL/4.
    
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
#include "ipr_token_list.h"             //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_token_list_t

//  Shorthands for class methods                                               

#define self_cat            ipr_token_list_cat
#define self_merge          ipr_token_list_merge
#define self_selftest       ipr_token_list_selftest
#define self_new            ipr_token_list_new
#define self_annihilate     ipr_token_list_annihilate
#define self_isempty        ipr_token_list_isempty
#define self_push           ipr_token_list_push
#define self_pop            ipr_token_list_pop
#define self_queue          ipr_token_list_queue
#define self_relink_before  ipr_token_list_relink_before
#define self_remove         ipr_token_list_remove
#define self_first          ipr_token_list_first
#define self_last           ipr_token_list_last
#define self_next           ipr_token_list_next
#define self_prev           ipr_token_list_prev
#define self_count          ipr_token_list_count
#define self_rehook         ipr_token_list_rehook
#define self_unhook         ipr_token_list_unhook
#define self_terminate      ipr_token_list_terminate
#define self_show           ipr_token_list_show
#define self_destroy        ipr_token_list_destroy
#define self_alloc          ipr_token_list_alloc
#define self_free           ipr_token_list_free
#define self_show_animation  ipr_token_list_show_animation
#define self_new_in_scope   ipr_token_list_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_CAT))
static icl_stats_t *s_ipr_token_list_cat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_MERGE))
static icl_stats_t *s_ipr_token_list_merge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_SELFTEST))
static icl_stats_t *s_ipr_token_list_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_NEW))
static icl_stats_t *s_ipr_token_list_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_DESTROY))
static icl_stats_t *s_ipr_token_list_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_ISEMPTY))
static icl_stats_t *s_ipr_token_list_isempty_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_PUSH))
static icl_stats_t *s_ipr_token_list_push_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_POP))
static icl_stats_t *s_ipr_token_list_pop_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_QUEUE))
static icl_stats_t *s_ipr_token_list_queue_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_RELINK_BEFORE))
static icl_stats_t *s_ipr_token_list_relink_before_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_REMOVE))
static icl_stats_t *s_ipr_token_list_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_FIRST))
static icl_stats_t *s_ipr_token_list_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_LAST))
static icl_stats_t *s_ipr_token_list_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_NEXT))
static icl_stats_t *s_ipr_token_list_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_PREV))
static icl_stats_t *s_ipr_token_list_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_COUNT))
static icl_stats_t *s_ipr_token_list_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_REHOOK))
static icl_stats_t *s_ipr_token_list_rehook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_UNHOOK))
static icl_stats_t *s_ipr_token_list_unhook_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_TERMINATE))
static icl_stats_t *s_ipr_token_list_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_SHOW))
static icl_stats_t *s_ipr_token_list_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_token_list_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_ALLOC))
static icl_stats_t *s_ipr_token_list_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_FREE))
static icl_stats_t *s_ipr_token_list_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_SHOW_ANIMATION))
static icl_stats_t *s_ipr_token_list_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_token_list_new_in_scope_stats = NULL;
#endif
static void
    ipr_token_list_annihilate (
ipr_token_list_t * ( * self_p )         //  Reference to object reference
);

static inline void
    ipr_token_list_rehook (
ipr_token_t * item,                     //  Not documented
ipr_token_t * left,                     //  Not documented
ipr_token_t * right                     //  Not documented
);

static inline ipr_token_t *
    ipr_token_list_unhook (
ipr_token_t * item                      //  Not documented
);

#define ipr_token_list_alloc()          ipr_token_list_alloc_ (__FILE__, __LINE__)
static ipr_token_list_t *
    ipr_token_list_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_token_list_free (
ipr_token_list_t * self                 //  Object reference
);

Bool
    ipr_token_list_animating = TRUE;    //  Animation enabled by default

/*  -------------------------------------------------------------------------
    ipr_token_list_cat

    Type: Component method
    Accepts a ipr_token_list_t reference and returns zero in case of success,
    1 in case of errors.
    Concatenates one token list onto another.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_cat (
    ipr_token_list_t * self,            //  Reference to object
    ipr_token_list_t * source           //  List to copy from
)
{
ipr_token_t
    *token,
    *copy;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_CAT))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_cat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" source=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, source);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_CAT))
    icl_trace_record (NULL, ipr_token_list_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_CAT))
    icl_stats_inc ("ipr_token_list_cat", &s_ipr_token_list_cat_stats);
#endif

IPR_TOKEN_LIST_ASSERT_SANE (self);

//
token = ipr_token_list_first (source);
while (token) {
    copy = ipr_token_new ();
    icl_shortstr_cpy (copy->value, token->value);
    ipr_token_list_queue (self, copy);
    ipr_token_unlink (&copy);
    token = ipr_token_list_next (&token);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_CAT))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_CAT))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_cat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" source=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, source, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_token_list_merge

    Type: Component method
    Accepts a ipr_token_list_t reference and returns zero in case of success,
    1 in case of errors.
    Merges one token list into another, appending only tokens that
    are not already in the first list.  Note: this function will be
    slow for large lists, since it does sequential scans.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_merge (
    ipr_token_list_t * self,            //  Reference to object
    ipr_token_list_t * source           //  List to copy from
)
{
ipr_token_t
    *token,
    *copy;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_MERGE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_merge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" source=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, source);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_MERGE))
    icl_trace_record (NULL, ipr_token_list_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_MERGE))
    icl_stats_inc ("ipr_token_list_merge", &s_ipr_token_list_merge_stats);
#endif

IPR_TOKEN_LIST_ASSERT_SANE (self);

//
token = ipr_token_list_first (source);
while (token) {
    copy = ipr_token_list_first (self);
    while (copy) {
        if (streq (token->value, copy->value))
            break;                  //  Token already exists in list
        copy = ipr_token_list_next (&copy);
    }
    //  Append only if the token was not already there
    if (!copy) {
        copy = ipr_token_new ();
        icl_shortstr_cpy (copy->value, token->value);
        ipr_token_list_queue (self, copy);
    }
    ipr_token_unlink (&copy);
    token = ipr_token_list_next (&token);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_MERGE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_MERGE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_merge_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" source=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, source, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_token_list_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_token_list_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_SELFTEST))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SELFTEST))
    icl_trace_record (NULL, ipr_token_list_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_SELFTEST))
    icl_stats_inc ("ipr_token_list_selftest", &s_ipr_token_list_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SELFTEST))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_SELFTEST))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_selftest_finish"
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
    ipr_token_list_new

    Type: Component method
    Creates and initialises a new ipr_token_list_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_token_list_t *
    ipr_token_list_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_token_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_NEW))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEW))
    icl_trace_record (NULL, ipr_token_list_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_NEW))
    icl_stats_inc ("ipr_token_list_new", &s_ipr_token_list_new_stats);
#endif

    self = ipr_token_list_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_TOKEN_LIST_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_token_list_show_);
#endif

self->ipr_token.list_next = &self->ipr_token;
self->ipr_token.list_prev = &self->ipr_token;
self->ipr_token.list_head = self;
self->count = 0;

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEW))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_NEW))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_new_finish"
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
    ipr_token_list_annihilate

    Type: Component method
    Destroys the list and unlinks all attached items.
    -------------------------------------------------------------------------
 */

static void
    ipr_token_list_annihilate (
    ipr_token_list_t * ( * self_p )     //  Reference to object reference
)
{

ipr_token_t
    *item;
    ipr_token_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_DESTROY))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_DESTROY))
    icl_trace_record (NULL, ipr_token_list_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_DESTROY))
    icl_stats_inc ("ipr_token_list_annihilate", &s_ipr_token_list_annihilate_stats);
#endif

IPR_TOKEN_LIST_ASSERT_SANE (self);

item = (ipr_token_t *) self->ipr_token.list_next;
while (item != &self->ipr_token) {
    //  Unlink child without lock (we already have the lock)               
    ipr_token_list_unhook (item);

    ipr_token_unlink (&item);
    item = (ipr_token_t *) self->ipr_token.list_next;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_DESTROY))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_DESTROY))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_destroy_finish"
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
    ipr_token_list_isempty

    Type: Component method
    Accepts a ipr_token_list_t reference and returns zero in case of success,
    1 in case of errors.
    Returns true if the list is empty, else returns false.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_isempty (
    ipr_token_list_t * self             //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_ISEMPTY))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_isempty_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_ISEMPTY))
    icl_trace_record (NULL, ipr_token_list_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_ISEMPTY))
    icl_stats_inc ("ipr_token_list_isempty", &s_ipr_token_list_isempty_stats);
#endif

IPR_TOKEN_LIST_ASSERT_SANE (self);

rc = (self->ipr_token.list_next == &self->ipr_token);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_ISEMPTY))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_ISEMPTY))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_isempty_finish"
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
    ipr_token_list_push

    Type: Component method
    Accepts a ipr_token_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the start of the specified list. If the item
    was on another list, it is first detached.  After this method,
    list->next points to the item.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_push (
    ipr_token_list_t * self,            //  Reference to object
    ipr_token_t * item                  //  Not documented
)
{


    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_PUSH))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_push_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_PUSH))
    icl_trace_record (NULL, ipr_token_list_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_PUSH))
    icl_stats_inc ("ipr_token_list_push", &s_ipr_token_list_push_stats);
#endif



IPR_TOKEN_LIST_ASSERT_SANE (self);

//  If list_head is non-null then we are moving within the
//  list to another so don't need to adjust links. Otherwise it
//  is illegitimate to move from one list to another in one step,
//  because we don't have a lock on the other list.
if (! item->list_head) {
    ipr_token_link (item);
    icl_atomic_inc32 (&self->count);
}
else
if (item->list_head != self) {
    icl_console_print ("E: ipr_token item inserted into multiple list containers");
    assert (item->list_head == self);
}
ipr_token_list_unhook (item);
ipr_token_list_rehook (item, &self->ipr_token, (ipr_token_t *) self->ipr_token.list_next);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_PUSH))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_PUSH))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_push_finish"
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
    ipr_token_list_pop

    Type: Component method
    Removes the next item in the list, if any, and returns it.  If
    the list was empty, returns NULL.
    
    The number of links is unchanged; removing from the list and returning
    the value cancel each other out.
    -------------------------------------------------------------------------
 */

ipr_token_t *
    ipr_token_list_pop (
    ipr_token_list_t * self             //  The list
)
{


    ipr_token_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_POP))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_pop_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_POP))
    icl_trace_record (NULL, ipr_token_list_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_POP))
    icl_stats_inc ("ipr_token_list_pop", &s_ipr_token_list_pop_stats);
#endif



IPR_TOKEN_LIST_ASSERT_SANE (self);

if (self->ipr_token.list_next == &self->ipr_token)
    item = NULL;
else {
    item = ipr_token_list_unhook ((ipr_token_t *) self->ipr_token.list_next);
    icl_atomic_dec32 (&self->count);
}



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_POP))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_POP))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_pop_finish"
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
    ipr_token_list_queue

    Type: Component method
    Accepts a ipr_token_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item to the end of the specified list.  The item may not
    be in another list of the same class.
    
    The number of links is automatically adjusted - if the item was already
    in the list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_queue (
    ipr_token_list_t * self,            //  Reference to object
    ipr_token_t * item                  //  Not documented
)
{


    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_QUEUE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_queue_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_QUEUE))
    icl_trace_record (NULL, ipr_token_list_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_QUEUE))
    icl_stats_inc ("ipr_token_list_queue", &s_ipr_token_list_queue_stats);
#endif



IPR_TOKEN_LIST_ASSERT_SANE (self);

//  If list_head is non-null then we are moving within the             
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->list_head) {
    ipr_token_link (item);
    icl_atomic_inc32 (&self->count);
}
else
if (item->list_head != self) {
    icl_console_print ("E: ipr_token item inserted into multiple list containers");
    assert (item->list_head == self);
}
ipr_token_list_unhook (item);
ipr_token_list_rehook (item, (ipr_token_t *) self->ipr_token.list_prev, &self->ipr_token);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_QUEUE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_QUEUE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_queue_finish"
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
    ipr_token_list_relink_before

    Type: Component method
    Accepts a ipr_token_list_t reference and returns zero in case of success,
    1 in case of errors.
    Attaches the item before a specified item. If the item was on another list,
    it is first detached.
    
    The number of links is automatically adjusted - if the item was previously
    in a list, it remains unchanged; otherwise it is incremented.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_relink_before (
    ipr_token_t * item,                 //  Not documented
    ipr_token_t * where                 //  Not documented
)
{


    int
        rc = 0;                         //  Return code
    ipr_token_list_t *
        self = (ipr_token_list_t *) where->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_RELINK_BEFORE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_relink_before_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_RELINK_BEFORE))
    icl_trace_record (NULL, ipr_token_list_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_RELINK_BEFORE))
    icl_stats_inc ("ipr_token_list_relink_before", &s_ipr_token_list_relink_before_stats);
#endif



IPR_TOKEN_LIST_ASSERT_SANE (self);

//  If list_head is non-null then we are moving within the             
//  list to another so don't need to adjust links. Otherwise it        
//  is illegitimate to move from one list to another in one step,      
//  because we don't have a lock on the other list.                    
if (! item->list_head) {
    ipr_token_link (item);
    icl_atomic_inc32 (&self->count);
}
else
if (item->list_head != self) {
    icl_console_print ("E: ipr_token item inserted into multiple list containers");
    assert (item->list_head == self);
}            
ipr_token_list_unhook (item);
ipr_token_list_rehook (item, (ipr_token_t *) where->list_prev, where);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_RELINK_BEFORE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_RELINK_BEFORE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_relink_before_finish"
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
    ipr_token_list_remove

    Type: Component method
    Removes the item from any list it is in.
    
    If it was in a list, the number of links is decremented.
    -------------------------------------------------------------------------
 */

int
    ipr_token_list_remove (
    ipr_token_t * item                  //  Not documented
)
{


    ipr_token_list_t *
        self = (ipr_token_list_t *) item->list_head;  //  The list
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_REMOVE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_remove_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_REMOVE))
    icl_trace_record (NULL, ipr_token_list_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_REMOVE))
    icl_stats_inc ("ipr_token_list_remove", &s_ipr_token_list_remove_stats);
#endif



if (self
&&  self == item->list_head) { //       Catch case where item moved
    ipr_token_list_unhook (item);
    ipr_token_unlink (&item);
    icl_atomic_dec32 (&self->count);
}


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_REMOVE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_REMOVE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_remove_finish"
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
    ipr_token_list_first

    Type: Component method
    Returns the first ipr_token item on the list.     If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

ipr_token_t *
    ipr_token_list_first_ (
    ipr_token_list_t * self,            //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    ipr_token_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_FIRST))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_FIRST))
    icl_trace_record (NULL, ipr_token_list_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_FIRST))
    icl_stats_inc ("ipr_token_list_first", &s_ipr_token_list_first_stats);
#endif



IPR_TOKEN_LIST_ASSERT_SANE (self);

item = (ipr_token_t *) self->ipr_token.list_next;
if (item == &self->ipr_token)
    item = NULL;
else
    ipr_token_link (item);




#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_FIRST))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_FIRST))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_first_finish"
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
    ipr_token_list_last

    Type: Component method
    Returns the last ipr_token item on the list.     If the list is empty,
    returns null.
    -------------------------------------------------------------------------
 */

ipr_token_t *
    ipr_token_list_last_ (
    ipr_token_list_t * self,            //  The list
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    ipr_token_t *
        item = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_LAST))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_LAST))
    icl_trace_record (NULL, ipr_token_list_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_LAST))
    icl_stats_inc ("ipr_token_list_last", &s_ipr_token_list_last_stats);
#endif



IPR_TOKEN_LIST_ASSERT_SANE (self);

item = (ipr_token_t *) self->ipr_token.list_prev;
if (item == &self->ipr_token)
    item = NULL;
else
    ipr_token_link (item);




#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_LAST))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_LAST))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_last_finish"
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
    ipr_token_list_next

    Type: Component method
    Returns the following item on the ipr_token list. If the provided item
    is null, returns the first item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

ipr_token_t *
    ipr_token_list_next_ (
    ipr_token_t * ( * item_p ),         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    ipr_token_t *
        item = *item_p;                 //  Dereferenced item
    ipr_token_t *
        next = NULL;                    //  The item to return
    ipr_token_list_t *
        self = (ipr_token_list_t *) item->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_NEXT))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_next_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEXT))
    icl_trace_record (NULL, ipr_token_list_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_NEXT))
    icl_stats_inc ("ipr_token_list_next", &s_ipr_token_list_next_stats);
#endif



if (self
&&  self == item->list_head) { //       Catch case where item moved
    next = (ipr_token_t *) item->list_next;
    if (next == &self->ipr_token)
        next = NULL;
    else
        ipr_token_link (next);

}
ipr_token_unlink (item_p);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEXT))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_NEXT))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_next_finish"
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
    ipr_token_list_prev

    Type: Component method
    Returns the preceding item on the ipr_token list. If the provided item
    is null, returns the last item.  If there were no (more) items, returns
    null.
    -------------------------------------------------------------------------
 */

ipr_token_t *
    ipr_token_list_prev_ (
    ipr_token_t * ( * item_p ),         //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{


    ipr_token_t *
        item = *item_p;                 //  Dereferenced item
    ipr_token_t *
        prev = NULL;                    //  The item to return
    ipr_token_list_t *
        self = (ipr_token_list_t *) item->list_head;  //  The list

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_PREV))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_prev_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_PREV))
    icl_trace_record (NULL, ipr_token_list_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_PREV))
    icl_stats_inc ("ipr_token_list_prev", &s_ipr_token_list_prev_stats);
#endif



if (self
&&  self == item->list_head) { //       Catch case where item moved
    prev = (ipr_token_t *) item->list_prev;
    if (prev == &self->ipr_token)
        prev = NULL;
    else
        ipr_token_link (prev);

}
ipr_token_unlink (item_p);



#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_PREV))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_PREV))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_prev_finish"
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
    ipr_token_list_count

    Type: Component method
    Return the count of the number of objects in the list.
    -------------------------------------------------------------------------
 */

qbyte
    ipr_token_list_count (
    ipr_token_list_t * self             //  The list
)
{
    qbyte
        count;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_COUNT))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_count_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_COUNT))
    icl_trace_record (NULL, ipr_token_list_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_COUNT))
    icl_stats_inc ("ipr_token_list_count", &s_ipr_token_list_count_stats);
#endif

IPR_TOKEN_LIST_ASSERT_SANE (self);
count = icl_atomic_get32 (&self->count);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_COUNT))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_COUNT))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    ipr_token_list_rehook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline void
    ipr_token_list_rehook (
    ipr_token_t * item,                 //  Not documented
    ipr_token_t * left,                 //  Not documented
    ipr_token_t * right                 //  Not documented
)
{
ipr_token_t
    *swap;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_REHOOK))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_rehook_start"
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

#if (defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_REHOOK))
    icl_trace_record (NULL, ipr_token_list_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_REHOOK))
    icl_stats_inc ("ipr_token_list_rehook", &s_ipr_token_list_rehook_stats);
#endif

swap = (ipr_token_t *) left->list_next;
left->list_next = item->list_next;
item->list_next = swap;

swap = (ipr_token_t *) item->list_prev;
item->list_prev = right->list_prev;
right->list_prev = swap;

item->list_head = left->list_head;
#if (defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_REHOOK))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_REHOOK))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_rehook_finish"
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
    ipr_token_list_unhook

    Type: Component method
    -------------------------------------------------------------------------
 */

static inline ipr_token_t *
    ipr_token_list_unhook (
    ipr_token_t * item                  //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_UNHOOK))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_unhook_start"
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

#if (defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_UNHOOK))
    icl_trace_record (NULL, ipr_token_list_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_UNHOOK))
    icl_stats_inc ("ipr_token_list_unhook", &s_ipr_token_list_unhook_stats);
#endif

ipr_token_list_rehook (item, (ipr_token_t *) item->list_prev, (ipr_token_t *) item->list_next);
item->list_head = NULL;
#if (defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_UNHOOK))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_UNHOOK))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_unhook_finish"
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
    ipr_token_list_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_token_list_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_TERMINATE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_TERMINATE))
    icl_trace_record (NULL, ipr_token_list_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_TERMINATE))
    icl_stats_inc ("ipr_token_list_terminate", &s_ipr_token_list_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_TERMINATE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_TERMINATE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_terminate_finish"
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
    ipr_token_list_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_token_list_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_token_list_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_SHOW))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SHOW))
    icl_trace_record (NULL, ipr_token_list_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_SHOW))
    icl_stats_inc ("ipr_token_list_show", &s_ipr_token_list_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_token_list file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SHOW))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_SHOW))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_show_finish"
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
    ipr_token_list_destroy

    Type: Component method
    Destroys a ipr_token_list_t object. Takes the address of a
    ipr_token_list_t reference (a pointer to a pointer) and nullifies the
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
    ipr_token_list_destroy_ (
    ipr_token_list_t * ( * self_p ),    //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_token_list_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_DESTROY_PUBLIC))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_token_list_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_token_list_destroy", &s_ipr_token_list_destroy_stats);
#endif

if (self) {
    ipr_token_list_annihilate (self_p);
    ipr_token_list_free ((ipr_token_list_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_DESTROY_PUBLIC))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_destroy_public_finish"
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
    ipr_token_list_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_token_list_t *
    ipr_token_list_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_token_list_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_ALLOC))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_ALLOC))
    icl_trace_record (NULL, ipr_token_list_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_ALLOC))
    icl_stats_inc ("ipr_token_list_alloc", &s_ipr_token_list_alloc_stats);
#endif

self = (ipr_token_list_t *) icl_mem_alloc_ (sizeof (ipr_token_list_t), file, line);
if (self)
    memset (self, 0, sizeof (ipr_token_list_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_ALLOC))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_ALLOC))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_alloc_finish"
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
    ipr_token_list_free

    Type: Component method
    Freess a ipr_token_list_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_token_list_free (
    ipr_token_list_t * self             //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_FREE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_FREE))
    icl_trace_record (NULL, ipr_token_list_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_FREE))
    icl_stats_inc ("ipr_token_list_free", &s_ipr_token_list_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_token_list_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_token_list_t));
        self->object_tag = IPR_TOKEN_LIST_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_FREE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_FREE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_free_finish"
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
    ipr_token_list_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_token_list_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_SHOW_ANIMATION))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_token_list_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_SHOW_ANIMATION))
    icl_stats_inc ("ipr_token_list_show_animation", &s_ipr_token_list_show_animation_stats);
#endif

ipr_token_list_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_SHOW_ANIMATION))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_show_animation_finish"
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
    ipr_token_list_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_token_list_new_in_scope_ (
    ipr_token_list_t * * self_p,        //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST)  ||  defined (BASE_ANIMATE_IPR_TOKEN_LIST_NEW_IN_SCOPE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_token_list_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_TOKEN_LIST)  ||  defined (BASE_STATS_IPR_TOKEN_LIST_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_token_list_new_in_scope", &s_ipr_token_list_new_in_scope_stats);
#endif

*self_p = ipr_token_list_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_token_list_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_token_list_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST)   || defined (BASE_ANIMATE_IPR_TOKEN_LIST_NEW_IN_SCOPE))
    if (ipr_token_list_animating)
        icl_console_print ("<ipr_token_list_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_TOKEN_LIST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_CAT)   || defined (BASE_TRACE_IPR_TOKEN_LIST_MERGE)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SELFTEST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEW)   || defined (BASE_TRACE_IPR_TOKEN_LIST_DESTROY)   || defined (BASE_TRACE_IPR_TOKEN_LIST_ISEMPTY)   || defined (BASE_TRACE_IPR_TOKEN_LIST_PUSH)   || defined (BASE_TRACE_IPR_TOKEN_LIST_POP)   || defined (BASE_TRACE_IPR_TOKEN_LIST_QUEUE)   || defined (BASE_TRACE_IPR_TOKEN_LIST_RELINK_BEFORE)   || defined (BASE_TRACE_IPR_TOKEN_LIST_REMOVE)   || defined (BASE_TRACE_IPR_TOKEN_LIST_FIRST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_LAST)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEXT)   || defined (BASE_TRACE_IPR_TOKEN_LIST_PREV)   || defined (BASE_TRACE_IPR_TOKEN_LIST_COUNT)   || defined (BASE_TRACE_IPR_TOKEN_LIST_REHOOK)   || defined (BASE_TRACE_IPR_TOKEN_LIST_UNHOOK)   || defined (BASE_TRACE_IPR_TOKEN_LIST_TERMINATE)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SHOW)   || defined (BASE_TRACE_IPR_TOKEN_LIST_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_TOKEN_LIST_ALLOC)   || defined (BASE_TRACE_IPR_TOKEN_LIST_FREE)   || defined (BASE_TRACE_IPR_TOKEN_LIST_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_TOKEN_LIST_NEW_IN_SCOPE) )
void
ipr_token_list_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "cat"; break;
        case 2: method_name = "merge"; break;
        case 3: method_name = "selftest"; break;
        case 4: method_name = "new"; break;
        case 5: method_name = "destroy"; break;
        case 6: method_name = "isempty"; break;
        case 7: method_name = "push"; break;
        case 8: method_name = "pop"; break;
        case 9: method_name = "queue"; break;
        case 10: method_name = "relink before"; break;
        case 11: method_name = "remove"; break;
        case 12: method_name = "first"; break;
        case 13: method_name = "last"; break;
        case 14: method_name = "next"; break;
        case 15: method_name = "prev"; break;
        case 16: method_name = "count"; break;
        case 17: method_name = "rehook"; break;
        case 18: method_name = "unhook"; break;
        case 19: method_name = "terminate"; break;
        case 20: method_name = "show"; break;
        case 21: method_name = "destroy public"; break;
        case 22: method_name = "alloc"; break;
        case 23: method_name = "free"; break;
        case 24: method_name = "show animation"; break;
        case 25: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_token_list %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_token_list_version_start  = "VeRsIoNsTaRt:ipc";
char *ipr_token_list_component     = "ipr_token_list ";
char *ipr_token_list_version       = "1.0 ";
char *ipr_token_list_copyright     = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_token_list_filename      = "ipr_token_list.icl ";
char *ipr_token_list_builddate     = "2009/02/19 ";
char *ipr_token_list_version_end   = "VeRsIoNeNd:ipc";

