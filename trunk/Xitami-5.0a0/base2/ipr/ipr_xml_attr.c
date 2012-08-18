/*---------------------------------------------------------------------------
    ipr_xml_attr.c - ipr_xml_attr component

    Implements XML attributes.
    Generated from ipr_xml_attr.icl by icl_gen using GSL/4.
    
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
#include "ipr_xml_attr.h"               //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_xml_attr_t

//  Shorthands for class methods                                               

#define self_new            ipr_xml_attr_new
#define self_annihilate     ipr_xml_attr_annihilate
#define self_name           ipr_xml_attr_name
#define self_value          ipr_xml_attr_value
#define self_modify_value   ipr_xml_attr_modify_value
#define self_lookup         ipr_xml_attr_lookup
#define self_get            ipr_xml_attr_get
#define self_set            ipr_xml_attr_set
#define self_first          ipr_xml_attr_first
#define self_next           ipr_xml_attr_next
#define self_selftest       ipr_xml_attr_selftest
#define self_remove_from_all_containers  ipr_xml_attr_remove_from_all_containers
#define self_show           ipr_xml_attr_show
#define self_terminate      ipr_xml_attr_terminate
#define self_destroy        ipr_xml_attr_destroy
#define self_alloc          ipr_xml_attr_alloc
#define self_free           ipr_xml_attr_free
#define self_read_lock      ipr_xml_attr_read_lock
#define self_write_lock     ipr_xml_attr_write_lock
#define self_unlock         ipr_xml_attr_unlock
#define self_link           ipr_xml_attr_link
#define self_unlink         ipr_xml_attr_unlink
#define self_cache_initialise  ipr_xml_attr_cache_initialise
#define self_cache_purge    ipr_xml_attr_cache_purge
#define self_cache_terminate  ipr_xml_attr_cache_terminate
#define self_show_animation  ipr_xml_attr_show_animation
#define self_new_in_scope   ipr_xml_attr_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NEW))
static icl_stats_t *s_ipr_xml_attr_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_DESTROY))
static icl_stats_t *s_ipr_xml_attr_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NAME))
static icl_stats_t *s_ipr_xml_attr_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_VALUE))
static icl_stats_t *s_ipr_xml_attr_value_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_MODIFY_VALUE))
static icl_stats_t *s_ipr_xml_attr_modify_value_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_LOOKUP))
static icl_stats_t *s_ipr_xml_attr_lookup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_GET))
static icl_stats_t *s_ipr_xml_attr_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SET))
static icl_stats_t *s_ipr_xml_attr_set_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_FIRST))
static icl_stats_t *s_ipr_xml_attr_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NEXT))
static icl_stats_t *s_ipr_xml_attr_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SELFTEST))
static icl_stats_t *s_ipr_xml_attr_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_xml_attr_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SHOW))
static icl_stats_t *s_ipr_xml_attr_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_TERMINATE))
static icl_stats_t *s_ipr_xml_attr_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_xml_attr_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_ALLOC))
static icl_stats_t *s_ipr_xml_attr_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_FREE))
static icl_stats_t *s_ipr_xml_attr_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_READ_LOCK))
static icl_stats_t *s_ipr_xml_attr_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_WRITE_LOCK))
static icl_stats_t *s_ipr_xml_attr_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_UNLOCK))
static icl_stats_t *s_ipr_xml_attr_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_LINK))
static icl_stats_t *s_ipr_xml_attr_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_UNLINK))
static icl_stats_t *s_ipr_xml_attr_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_CACHE_INITIALISE))
static icl_stats_t *s_ipr_xml_attr_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_CACHE_PURGE))
static icl_stats_t *s_ipr_xml_attr_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_CACHE_TERMINATE))
static icl_stats_t *s_ipr_xml_attr_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SHOW_ANIMATION))
static icl_stats_t *s_ipr_xml_attr_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_xml_attr_new_in_scope_stats = NULL;
#endif
#define ipr_xml_attr_annihilate(self)   ipr_xml_attr_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_xml_attr_annihilate_ (
ipr_xml_attr_t * ( * self_p ),          //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static ipr_xml_attr_t *
    ipr_xml_attr_lookup (
ipr_xml_t * item,                       //  The XML item
char * name                             //  The attribute name
);

#define ipr_xml_attr_alloc()            ipr_xml_attr_alloc_ (__FILE__, __LINE__)
static ipr_xml_attr_t *
    ipr_xml_attr_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_xml_attr_free(self)         ipr_xml_attr_free_ (self, __FILE__, __LINE__)
static void
    ipr_xml_attr_free_ (
ipr_xml_attr_t * self,                  //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    ipr_xml_attr_cache_initialise (
void);

static void
    ipr_xml_attr_cache_purge (
void);

static void
    ipr_xml_attr_cache_terminate (
void);

Bool
    ipr_xml_attr_animating = TRUE;      //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_xml_attr_new

    Type: Component method
    Creates and initialises a new ipr_xml_attr_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

ipr_xml_attr_t *
    ipr_xml_attr_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_xml_t * parent,                 //  The XML item to which the attribute belongs
    char * name,                        //  The name of the new item
    char * value                        //  The value of the new item
)
{
    ipr_xml_attr_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_NEW))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" parent=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, parent, name, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEW))
    icl_trace_record (NULL, ipr_xml_attr_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NEW))
    icl_stats_inc ("ipr_xml_attr_new", &s_ipr_xml_attr_new_stats);
#endif

    self = ipr_xml_attr_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_XML_ATTR_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
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
        icl_mem_set_callback (self, ipr_xml_attr_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
if (name)
    self->name  = icl_mem_strdup (name);
if (value)
    self->value = icl_mem_strdup (value);
ipr_xml_attr_list_queue (parent->attrs, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEW))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_NEW))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" parent=\"%pp\""
" name=\"%s\""
" value=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, parent, name, value, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_attr_annihilate_ (
    ipr_xml_attr_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    int
        history_last;
#endif

    ipr_xml_attr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_DESTROY))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_DESTROY))
    icl_trace_record (NULL, ipr_xml_attr_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_DESTROY))
    icl_stats_inc ("ipr_xml_attr_annihilate", &s_ipr_xml_attr_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = self->links;
#endif

    IPR_XML_ATTR_ASSERT_SANE (self);
    ipr_xml_attr_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_mem_free (self->name);
icl_mem_free (self->value);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_DESTROY))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_DESTROY))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_destroy_finish"
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
    ipr_xml_attr_name

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    ipr_xml_attr_name (
    ipr_xml_attr_t * self               //  Not documented
)
{
    char *
        name;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_NAME))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_name_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NAME))
    icl_trace_record (NULL, ipr_xml_attr_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NAME))
    icl_stats_inc ("ipr_xml_attr_name", &s_ipr_xml_attr_name_stats);
#endif

name = self->name;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NAME))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_NAME))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_name_finish"
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


    return (name);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_value

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    ipr_xml_attr_value (
    ipr_xml_attr_t * self               //  Not documented
)
{
    char *
        value;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_VALUE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_value_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_VALUE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_VALUE))
    icl_stats_inc ("ipr_xml_attr_value", &s_ipr_xml_attr_value_stats);
#endif

value = self->value;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_VALUE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_VALUE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_value_finish"
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


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_modify_value

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_modify_value (
    ipr_xml_attr_t * self,              //  Not documented
    char * value                        //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_MODIFY_VALUE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_modify_value_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_MODIFY_VALUE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_MODIFY_VALUE))
    icl_stats_inc ("ipr_xml_attr_modify_value", &s_ipr_xml_attr_modify_value_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

if (!self->value) {
    if (value)
        self->value = icl_mem_strdup (value);
}
else
if (value) {
    if (strneq (value, self->value)) {
        icl_mem_strfree (&self->value);
        self->value = icl_mem_strdup (value);
    }
}
else
    icl_mem_strfree (&self->value);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_MODIFY_VALUE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_MODIFY_VALUE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_modify_value_finish"
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

}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_lookup

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_xml_attr_t *
    ipr_xml_attr_lookup (
    ipr_xml_t * item,                   //  The XML item
    char * name                         //  The attribute name
)
{
    ipr_xml_attr_t *
        attr;                           //  The attribute

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_LOOKUP))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_lookup_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_LOOKUP))
    icl_trace_record (NULL, ipr_xml_attr_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_LOOKUP))
    icl_stats_inc ("ipr_xml_attr_lookup", &s_ipr_xml_attr_lookup_stats);
#endif

attr = ipr_xml_attr_list_first (item->attrs);
while (attr) {
    if (attr->name
    &&  streq (name, attr->name))
        break;
    else
        attr = ipr_xml_attr_list_next (&attr);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_LOOKUP))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_LOOKUP))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_lookup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%s\""
" attr=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name, attr);
#endif


    return (attr);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_get

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    ipr_xml_attr_get (
    ipr_xml_t * item,                   //  The XML item
    char * name,                        //  The attribute name
    char * dflt                         //  The value to return if the attribute is undefined
)
{
    ipr_xml_attr_t *
        attr;                           //  The attribute
    char *
        value = NULL;                   //  The attribute value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_GET))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%s\""
" dflt=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name, dflt);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_GET))
    icl_trace_record (NULL, ipr_xml_attr_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_GET))
    icl_stats_inc ("ipr_xml_attr_get", &s_ipr_xml_attr_get_stats);
#endif

attr = ipr_xml_attr_lookup (item, name);
if (attr)
    value = ipr_xml_attr_value (attr);
if (!value)
    value = dflt;

ipr_xml_attr_unlink (&attr);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_GET))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_GET))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%s\""
" dflt=\"%s\""
" attr=\"%pp\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name, dflt, attr, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_set

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_set (
    ipr_xml_t * item,                   //  The XML item
    char * name,                        //  The attribute name
    char * value                        //  The attribute value
)
{
ipr_xml_attr_t
    *attr;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_SET))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_set_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SET))
    icl_trace_record (NULL, ipr_xml_attr_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SET))
    icl_stats_inc ("ipr_xml_attr_set", &s_ipr_xml_attr_set_stats);
#endif

attr = ipr_xml_attr_lookup (item, name);
if (attr)
    ipr_xml_attr_modify_value (attr, value);
else
    attr = ipr_xml_attr_new (item, name, value);

ipr_xml_attr_unlink (&attr);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SET))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_SET))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_set_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name, value);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_first

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_attr_t *
    ipr_xml_attr_first (
    ipr_xml_t * item                    //  The XML item
)
{
    ipr_xml_attr_t *
        attr;                           //  The attribute

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_FIRST))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_FIRST))
    icl_trace_record (NULL, ipr_xml_attr_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_FIRST))
    icl_stats_inc ("ipr_xml_attr_first", &s_ipr_xml_attr_first_stats);
#endif

attr = ipr_xml_attr_list_first (item->attrs);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_FIRST))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_FIRST))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_first_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" attr=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, attr);
#endif


    return (attr);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_next

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_attr_t *
    ipr_xml_attr_next (
    ipr_xml_attr_t ** attr              //  The attribute
)
{
    ipr_xml_attr_t *
        next;                           //  The next attribute

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_NEXT))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_next_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" attr=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, attr);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEXT))
    icl_trace_record (NULL, ipr_xml_attr_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NEXT))
    icl_stats_inc ("ipr_xml_attr_next", &s_ipr_xml_attr_next_stats);
#endif

next = ipr_xml_attr_list_next (attr);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEXT))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_NEXT))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_next_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" attr=\"%pp\""
" next=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, attr, next);
#endif


    return (next);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_SELFTEST))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SELFTEST))
    icl_trace_record (NULL, ipr_xml_attr_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SELFTEST))
    icl_stats_inc ("ipr_xml_attr_selftest", &s_ipr_xml_attr_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SELFTEST))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_SELFTEST))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_selftest_finish"
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
    ipr_xml_attr_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_remove_from_all_containers (
    ipr_xml_attr_t * self               //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_xml_attr_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_xml_attr_remove_from_all_containers", &s_ipr_xml_attr_remove_from_all_containers_stats);
#endif

ipr_xml_attr_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_remove_from_all_containers_finish"
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
    ipr_xml_attr_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_xml_attr_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_SHOW))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SHOW))
    icl_trace_record (NULL, ipr_xml_attr_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SHOW))
    icl_stats_inc ("ipr_xml_attr_show", &s_ipr_xml_attr_show_stats);
#endif

self = item;
container_links = 0;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_xml_attr zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    if (self->history_last > IPR_XML_ATTR_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_XML_ATTR_HISTORY_LENGTH;
        self->history_last %= IPR_XML_ATTR_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_XML_ATTR_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_xml_attr>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SHOW))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_SHOW))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_show_finish"
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
    ipr_xml_attr_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_TERMINATE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_TERMINATE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_TERMINATE))
    icl_stats_inc ("ipr_xml_attr_terminate", &s_ipr_xml_attr_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_TERMINATE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_TERMINATE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_terminate_finish"
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
    ipr_xml_attr_destroy

    Type: Component method
    Destroys a ipr_xml_attr_t object. Takes the address of a
    ipr_xml_attr_t reference (a pointer to a pointer) and nullifies the
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
    ipr_xml_attr_destroy_ (
    ipr_xml_attr_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_xml_attr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_DESTROY_PUBLIC))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_xml_attr_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_xml_attr_destroy", &s_ipr_xml_attr_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_xml_attr_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_xml_attr object");
        ipr_xml_attr_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_xml_attr_free_ ((ipr_xml_attr_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_DESTROY_PUBLIC))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_destroy_public_finish"
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
    ipr_xml_attr_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_xml_attr_t *
    ipr_xml_attr_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_xml_attr_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_ALLOC))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_ALLOC))
    icl_trace_record (NULL, ipr_xml_attr_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_ALLOC))
    icl_stats_inc ("ipr_xml_attr_alloc", &s_ipr_xml_attr_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_xml_attr_cache_initialise ();

self = (ipr_xml_attr_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_xml_attr_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_ALLOC))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_ALLOC))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_alloc_finish"
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
    ipr_xml_attr_free

    Type: Component method
    Freess a ipr_xml_attr_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_attr_free_ (
    ipr_xml_attr_t * self,              //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_FREE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_FREE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_FREE))
    icl_stats_inc ("ipr_xml_attr_free", &s_ipr_xml_attr_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_xml_attr_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_xml_attr_t));
        self->object_tag = IPR_XML_ATTR_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_FREE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_FREE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_free_finish"
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
    ipr_xml_attr_read_lock

    Type: Component method
    Accepts a ipr_xml_attr_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_xml_attr_read_lock (
    ipr_xml_attr_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_READ_LOCK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_READ_LOCK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_READ_LOCK))
    icl_stats_inc ("ipr_xml_attr_read_lock", &s_ipr_xml_attr_read_lock_stats);
#endif

IPR_XML_ATTR_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_READ_LOCK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_READ_LOCK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_read_lock_finish"
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
    ipr_xml_attr_write_lock

    Type: Component method
    Accepts a ipr_xml_attr_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_xml_attr_write_lock (
    ipr_xml_attr_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_WRITE_LOCK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_WRITE_LOCK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_WRITE_LOCK))
    icl_stats_inc ("ipr_xml_attr_write_lock", &s_ipr_xml_attr_write_lock_stats);
#endif

IPR_XML_ATTR_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_WRITE_LOCK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_WRITE_LOCK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_write_lock_finish"
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
    ipr_xml_attr_unlock

    Type: Component method
    Accepts a ipr_xml_attr_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_xml_attr_unlock (
    ipr_xml_attr_t * self               //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_UNLOCK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_UNLOCK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_UNLOCK))
    icl_stats_inc ("ipr_xml_attr_unlock", &s_ipr_xml_attr_unlock_stats);
#endif

IPR_XML_ATTR_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_UNLOCK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_UNLOCK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_unlock_finish"
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
    ipr_xml_attr_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_xml_attr_t *
    ipr_xml_attr_link_ (
    ipr_xml_attr_t * self,              //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_LINK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_LINK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_LINK))
    icl_stats_inc ("ipr_xml_attr_link", &s_ipr_xml_attr_link_stats);
#endif

    if (self) {
        IPR_XML_ATTR_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_LINK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_LINK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_link_finish"
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
    ipr_xml_attr_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_unlink_ (
    ipr_xml_attr_t * ( * self_p ),      //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
    int
        history_last;
#endif

    ipr_xml_attr_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_UNLINK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_UNLINK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_UNLINK))
    icl_stats_inc ("ipr_xml_attr_unlink", &s_ipr_xml_attr_unlink_stats);
#endif

    if (self) {
        IPR_XML_ATTR_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_xml_attr object");
            ipr_xml_attr_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML_ATTR)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_XML_ATTR_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_xml_attr_annihilate_ (self_p, file, line);
        ipr_xml_attr_free_ ((ipr_xml_attr_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_UNLINK))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_UNLINK))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_unlink_finish"
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
    ipr_xml_attr_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_attr_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_CACHE_INITIALISE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_CACHE_INITIALISE))
    icl_stats_inc ("ipr_xml_attr_cache_initialise", &s_ipr_xml_attr_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_xml_attr_t));
icl_system_register (ipr_xml_attr_cache_purge, ipr_xml_attr_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_CACHE_INITIALISE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_cache_initialise_finish"
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
    ipr_xml_attr_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_attr_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_CACHE_PURGE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_PURGE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_CACHE_PURGE))
    icl_stats_inc ("ipr_xml_attr_cache_purge", &s_ipr_xml_attr_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_PURGE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_CACHE_PURGE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_cache_purge_finish"
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
    ipr_xml_attr_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_attr_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_CACHE_TERMINATE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_CACHE_TERMINATE))
    icl_stats_inc ("ipr_xml_attr_cache_terminate", &s_ipr_xml_attr_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_CACHE_TERMINATE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_cache_terminate_finish"
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
    ipr_xml_attr_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_SHOW_ANIMATION))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_xml_attr_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_SHOW_ANIMATION))
    icl_stats_inc ("ipr_xml_attr_show_animation", &s_ipr_xml_attr_show_animation_stats);
#endif

ipr_xml_attr_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_SHOW_ANIMATION))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_show_animation_finish"
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
    ipr_xml_attr_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attr_new_in_scope_ (
    ipr_xml_attr_t * * self_p,          //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_xml_t * parent,                 //  The XML item to which the attribute belongs
    char * name,                        //  The name of the new item
    char * value                        //  The value of the new item
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR_NEW_IN_SCOPE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" parent=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, parent, name, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML_ATTR)  ||  defined (BASE_STATS_IPR_XML_ATTR_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_xml_attr_new_in_scope", &s_ipr_xml_attr_new_in_scope_stats);
#endif

*self_p = ipr_xml_attr_new_ (file,line,parent,name,value);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_xml_attr_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_xml_attr_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML_ATTR)   || defined (BASE_ANIMATE_IPR_XML_ATTR_NEW_IN_SCOPE))
    if (ipr_xml_attr_animating)
        icl_console_print ("<ipr_xml_attr_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" parent=\"%pp\""
" name=\"%s\""
" value=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, parent, name, value, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_ATTR_NEW)   || defined (BASE_TRACE_IPR_XML_ATTR_DESTROY)   || defined (BASE_TRACE_IPR_XML_ATTR_NAME)   || defined (BASE_TRACE_IPR_XML_ATTR_VALUE)   || defined (BASE_TRACE_IPR_XML_ATTR_MODIFY_VALUE)   || defined (BASE_TRACE_IPR_XML_ATTR_LOOKUP)   || defined (BASE_TRACE_IPR_XML_ATTR_GET)   || defined (BASE_TRACE_IPR_XML_ATTR_SET)   || defined (BASE_TRACE_IPR_XML_ATTR_FIRST)   || defined (BASE_TRACE_IPR_XML_ATTR_NEXT)   || defined (BASE_TRACE_IPR_XML_ATTR_SELFTEST)   || defined (BASE_TRACE_IPR_XML_ATTR_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_XML_ATTR_SHOW)   || defined (BASE_TRACE_IPR_XML_ATTR_TERMINATE)   || defined (BASE_TRACE_IPR_XML_ATTR_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_XML_ATTR_ALLOC)   || defined (BASE_TRACE_IPR_XML_ATTR_FREE)   || defined (BASE_TRACE_IPR_XML_ATTR_READ_LOCK)   || defined (BASE_TRACE_IPR_XML_ATTR_WRITE_LOCK)   || defined (BASE_TRACE_IPR_XML_ATTR_UNLOCK)   || defined (BASE_TRACE_IPR_XML_ATTR_LINK)   || defined (BASE_TRACE_IPR_XML_ATTR_UNLINK)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_PURGE)   || defined (BASE_TRACE_IPR_XML_ATTR_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_XML_ATTR_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_XML_ATTR_NEW_IN_SCOPE) )
void
ipr_xml_attr_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "name"; break;
        case 4: method_name = "value"; break;
        case 5: method_name = "modify value"; break;
        case 6: method_name = "lookup"; break;
        case 7: method_name = "get"; break;
        case 8: method_name = "set"; break;
        case 9: method_name = "first"; break;
        case 10: method_name = "next"; break;
        case 11: method_name = "selftest"; break;
        case 12: method_name = "remove from all containers"; break;
        case 13: method_name = "show"; break;
        case 14: method_name = "terminate"; break;
        case 15: method_name = "destroy public"; break;
        case 16: method_name = "alloc"; break;
        case 17: method_name = "free"; break;
        case 18: method_name = "read lock"; break;
        case 19: method_name = "write lock"; break;
        case 20: method_name = "unlock"; break;
        case 21: method_name = "link"; break;
        case 22: method_name = "unlink"; break;
        case 23: method_name = "cache initialise"; break;
        case 24: method_name = "cache purge"; break;
        case 25: method_name = "cache terminate"; break;
        case 26: method_name = "show animation"; break;
        case 27: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_xml_attr %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_xml_attr_version_start   = "VeRsIoNsTaRt:ipc";
char *ipr_xml_attr_component       = "ipr_xml_attr ";
char *ipr_xml_attr_version         = "1.1 ";
char *ipr_xml_attr_copyright       = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_xml_attr_filename        = "ipr_xml_attr.icl ";
char *ipr_xml_attr_builddate       = "2009/02/19 ";
char *ipr_xml_attr_version_end     = "VeRsIoNeNd:ipc";

