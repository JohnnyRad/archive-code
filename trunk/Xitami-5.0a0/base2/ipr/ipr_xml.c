/*---------------------------------------------------------------------------
    ipr_xml.c - ipr_xml component

    Implements XML objects.
    Generated from ipr_xml.icl by icl_gen using GSL/4.
    
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
#include "ipr_xml.h"                    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_xml_t

//  Shorthands for class methods                                               

#define self_new            ipr_xml_new
#define self_annihilate     ipr_xml_annihilate
#define self_parse_file     ipr_xml_parse_file
#define self_parse_string   ipr_xml_parse_string
#define self_parse_bucket   ipr_xml_parse_bucket
#define self_attach_child   ipr_xml_attach_child
#define self_attach_sibling  ipr_xml_attach_sibling
#define self_detach         ipr_xml_detach
#define self_first_child    ipr_xml_first_child
#define self_next_sibling   ipr_xml_next_sibling
#define self_parent         ipr_xml_parent
#define self_name           ipr_xml_name
#define self_value          ipr_xml_value
#define self_rename         ipr_xml_rename
#define self_value_set      ipr_xml_value_set
#define self_text           ipr_xml_text
#define self_find_item      ipr_xml_find_item
#define self_next_item      ipr_xml_next_item
#define self_attr           ipr_xml_attr
#define self_selftest       ipr_xml_selftest
#define self_remove_from_all_containers  ipr_xml_remove_from_all_containers
#define self_show           ipr_xml_show
#define self_terminate      ipr_xml_terminate
#define self_destroy        ipr_xml_destroy
#define self_alloc          ipr_xml_alloc
#define self_free           ipr_xml_free
#define self_read_lock      ipr_xml_read_lock
#define self_write_lock     ipr_xml_write_lock
#define self_unlock         ipr_xml_unlock
#define self_link           ipr_xml_link
#define self_unlink         ipr_xml_unlink
#define self_cache_initialise  ipr_xml_cache_initialise
#define self_cache_purge    ipr_xml_cache_purge
#define self_cache_terminate  ipr_xml_cache_terminate
#define self_show_animation  ipr_xml_show_animation
#define self_new_in_scope   ipr_xml_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEW))
static icl_stats_t *s_ipr_xml_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_DESTROY))
static icl_stats_t *s_ipr_xml_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARSE_FILE))
static icl_stats_t *s_ipr_xml_parse_file_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARSE_STRING))
static icl_stats_t *s_ipr_xml_parse_string_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARSE_BUCKET))
static icl_stats_t *s_ipr_xml_parse_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ATTACH_CHILD))
static icl_stats_t *s_ipr_xml_attach_child_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ATTACH_SIBLING))
static icl_stats_t *s_ipr_xml_attach_sibling_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_DETACH))
static icl_stats_t *s_ipr_xml_detach_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_FIRST_CHILD))
static icl_stats_t *s_ipr_xml_first_child_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEXT_SIBLING))
static icl_stats_t *s_ipr_xml_next_sibling_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARENT))
static icl_stats_t *s_ipr_xml_parent_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NAME))
static icl_stats_t *s_ipr_xml_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_VALUE))
static icl_stats_t *s_ipr_xml_value_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_RENAME))
static icl_stats_t *s_ipr_xml_rename_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_VALUE_SET))
static icl_stats_t *s_ipr_xml_value_set_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_TEXT))
static icl_stats_t *s_ipr_xml_text_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_FIND_ITEM))
static icl_stats_t *s_ipr_xml_find_item_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEXT_ITEM))
static icl_stats_t *s_ipr_xml_next_item_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ATTR))
static icl_stats_t *s_ipr_xml_attr_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_SELFTEST))
static icl_stats_t *s_ipr_xml_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_REMOVE_FROM_ALL_CONTAINERS))
static icl_stats_t *s_ipr_xml_remove_from_all_containers_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_SHOW))
static icl_stats_t *s_ipr_xml_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_TERMINATE))
static icl_stats_t *s_ipr_xml_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_xml_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ALLOC))
static icl_stats_t *s_ipr_xml_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_FREE))
static icl_stats_t *s_ipr_xml_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_READ_LOCK))
static icl_stats_t *s_ipr_xml_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_WRITE_LOCK))
static icl_stats_t *s_ipr_xml_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_UNLOCK))
static icl_stats_t *s_ipr_xml_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_LINK))
static icl_stats_t *s_ipr_xml_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_UNLINK))
static icl_stats_t *s_ipr_xml_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_CACHE_INITIALISE))
static icl_stats_t *s_ipr_xml_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_CACHE_PURGE))
static icl_stats_t *s_ipr_xml_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_CACHE_TERMINATE))
static icl_stats_t *s_ipr_xml_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_SHOW_ANIMATION))
static icl_stats_t *s_ipr_xml_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_xml_new_in_scope_stats = NULL;
#endif
#define ipr_xml_annihilate(self)        ipr_xml_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_xml_annihilate_ (
ipr_xml_t * ( * self_p ),               //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_xml_alloc()                 ipr_xml_alloc_ (__FILE__, __LINE__)
static ipr_xml_t *
    ipr_xml_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_xml_free(self)              ipr_xml_free_ (self, __FILE__, __LINE__)
static void
    ipr_xml_free_ (
ipr_xml_t * self,                       //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    ipr_xml_cache_initialise (
void);

static void
    ipr_xml_cache_purge (
void);

static void
    ipr_xml_cache_terminate (
void);

Bool
    ipr_xml_animating = TRUE;           //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


#include "ipr_bucket.h"
#include "ipr_xmll.h"
/*  -------------------------------------------------------------------------
    ipr_xml_new

    Type: Component method
    Creates and initialises a new ipr_xml_t object, returns a
    reference to the created object.
    Initialises the new item to be a valid list item.
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_xml_t * parent,                 //  The parent of the new item
    char * name,                        //  The name of the new item
    char * value                        //  The value of the new item
)
{
    ipr_xml_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_NEW))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEW))
    icl_trace_record (NULL, ipr_xml_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEW))
    icl_stats_inc ("ipr_xml_new", &s_ipr_xml_new_stats);
#endif

    self = ipr_xml_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_XML_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
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
        icl_mem_set_callback (self, ipr_xml_show_);
#endif

self->list_next = self;
self->list_prev = self;
self->list_head = NULL;
if (name)
    self->name  = icl_mem_strdup (name);
if (value)
    self->value = icl_mem_strdup (value);
self->children  = ipr_xml_list_new ();
self->attrs     = ipr_xml_attr_list_new ();
if (parent)
    ipr_xml_attach_child (parent, self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEW))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_NEW))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_new_finish"
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
    ipr_xml_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_annihilate_ (
    ipr_xml_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    int
        history_last;
#endif

    ipr_xml_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_DESTROY))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_DESTROY))
    icl_trace_record (NULL, ipr_xml_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_DESTROY))
    icl_stats_inc ("ipr_xml_annihilate", &s_ipr_xml_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_XML_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_XML_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_XML_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_XML_HISTORY_LENGTH] = self->links;
#endif

    IPR_XML_ASSERT_SANE (self);
    ipr_xml_remove_from_all_containers (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_mem_free (self->name);
icl_mem_free (self->value);
ipr_xml_list_destroy      (&self->children);
ipr_xml_attr_list_destroy (&self->attrs);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_DESTROY))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_DESTROY))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_destroy_finish"
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
    ipr_xml_parse_file

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_parse_file (
    char * path,                        //  Not documented
    char * filename                     //  Not documented
)
{
    ipr_xml_t *
        self;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_PARSE_FILE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parse_file_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path=\"%s\""
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARSE_FILE))
    icl_trace_record (NULL, ipr_xml_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARSE_FILE))
    icl_stats_inc ("ipr_xml_parse_file", &s_ipr_xml_parse_file_stats);
#endif

//
self = NULL;
if (ipr_xml_load_file (&self, path, filename, FALSE))
    self = self_new (NULL, "", NULL);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARSE_FILE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_PARSE_FILE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parse_file_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path=\"%s\""
" filename=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path, filename, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_xml_parse_string

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_parse_string (
    char * string                       //  Not documented
)
{
    ipr_xml_t *
        self;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_PARSE_STRING))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parse_string_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARSE_STRING))
    icl_trace_record (NULL, ipr_xml_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARSE_STRING))
    icl_stats_inc ("ipr_xml_parse_string", &s_ipr_xml_parse_string_stats);
#endif

//
self = NULL;
if (ipr_xml_load_string (&self, string, FALSE))
    self = self_new (NULL, "", NULL);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARSE_STRING))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_PARSE_STRING))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parse_string_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" string=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, string, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_xml_parse_bucket

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_parse_bucket (
    ipr_bucket_t * bucket               //  Not documented
)
{
    ipr_xml_t *
        self;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_PARSE_BUCKET))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parse_bucket_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, bucket);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARSE_BUCKET))
    icl_trace_record (NULL, ipr_xml_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARSE_BUCKET))
    icl_stats_inc ("ipr_xml_parse_bucket", &s_ipr_xml_parse_bucket_stats);
#endif

//
self = NULL;
if (bucket && ipr_xml_load_bucket (&self, bucket, FALSE))
    self = self_new (NULL, "", NULL);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARSE_BUCKET))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_PARSE_BUCKET))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parse_bucket_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" bucket=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, bucket, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attach_child

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attach_child (
    ipr_xml_t * parent,                 //  The new parent of the item
    ipr_xml_t * self                    //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_ATTACH_CHILD))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_attach_child_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" parent=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, parent, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ATTACH_CHILD))
    icl_trace_record (NULL, ipr_xml_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ATTACH_CHILD))
    icl_stats_inc ("ipr_xml_attach_child", &s_ipr_xml_attach_child_stats);
#endif

if (self->parent)
    ipr_xml_list_remove (self);
self->parent = parent;
ipr_xml_list_queue (parent->children, self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ATTACH_CHILD))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_ATTACH_CHILD))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_attach_child_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" parent=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, parent, self);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_xml_attach_sibling

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_attach_sibling (
    ipr_xml_t * sibling,                //  Item inserted before the sibling
    ipr_xml_t * self                    //  The item
)
{
ipr_xml_t
    *sibling_link,
    *parent_link;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_ATTACH_SIBLING))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_attach_sibling_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" sibling=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, sibling, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ATTACH_SIBLING))
    icl_trace_record (NULL, ipr_xml_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ATTACH_SIBLING))
    icl_stats_inc ("ipr_xml_attach_sibling", &s_ipr_xml_attach_sibling_stats);
#endif

if (self->parent)
    ipr_xml_list_remove (self);

sibling_link = ipr_xml_link (sibling);
self->parent = ipr_xml_parent (&sibling_link);
ipr_xml_list_relink_before (self, sibling);

//  A bit messy.  We don't keep a link for our parent.
parent_link = self->parent;
ipr_xml_unlink (&parent_link);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ATTACH_SIBLING))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_ATTACH_SIBLING))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_attach_sibling_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" sibling=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, sibling, self);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_xml_detach

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_detach (
    ipr_xml_t * self                    //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_DETACH))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_detach_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_DETACH))
    icl_trace_record (NULL, ipr_xml_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_DETACH))
    icl_stats_inc ("ipr_xml_detach", &s_ipr_xml_detach_stats);
#endif

if (self->parent)
    ipr_xml_list_remove (self);
self->parent = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_DETACH))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_DETACH))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_detach_finish"
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
    ipr_xml_first_child

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_first_child (
    ipr_xml_t * self                    //  Not documented
)
{
    ipr_xml_t *
        child;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_FIRST_CHILD))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_first_child_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_FIRST_CHILD))
    icl_trace_record (NULL, ipr_xml_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_FIRST_CHILD))
    icl_stats_inc ("ipr_xml_first_child", &s_ipr_xml_first_child_stats);
#endif

child = ipr_xml_list_first (self->children);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_FIRST_CHILD))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_FIRST_CHILD))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_first_child_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" child=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, child);
#endif


    return (child);
}
/*  -------------------------------------------------------------------------
    ipr_xml_next_sibling

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_next_sibling (
    ipr_xml_t ** pself                  //  Not documented
)
{
    ipr_xml_t *
        sibling;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_NEXT_SIBLING))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_next_sibling_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" pself=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, pself);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEXT_SIBLING))
    icl_trace_record (NULL, ipr_xml_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEXT_SIBLING))
    icl_stats_inc ("ipr_xml_next_sibling", &s_ipr_xml_next_sibling_stats);
#endif

sibling = ipr_xml_list_next (pself);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEXT_SIBLING))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_NEXT_SIBLING))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_next_sibling_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" pself=\"%pp\""
" sibling=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, pself, sibling);
#endif


    return (sibling);
}
/*  -------------------------------------------------------------------------
    ipr_xml_parent

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_parent (
    ipr_xml_t ** pself                  //  Not documented
)
{
    ipr_xml_t *
        parent;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_PARENT))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parent_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" pself=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, pself);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARENT))
    icl_trace_record (NULL, ipr_xml_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_PARENT))
    icl_stats_inc ("ipr_xml_parent", &s_ipr_xml_parent_stats);
#endif

parent = (*pself)->parent;
ipr_xml_link (parent);
ipr_xml_unlink (pself);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_PARENT))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_PARENT))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_parent_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" pself=\"%pp\""
" parent=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, pself, parent);
#endif


    return (parent);
}
/*  -------------------------------------------------------------------------
    ipr_xml_name

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    ipr_xml_name (
    ipr_xml_t * self                    //  Not documented
)
{
    char *
        name;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_NAME))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_name_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NAME))
    icl_trace_record (NULL, ipr_xml_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NAME))
    icl_stats_inc ("ipr_xml_name", &s_ipr_xml_name_stats);
#endif

name = self->name;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NAME))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_NAME))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_name_finish"
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
    ipr_xml_value

    Type: Component method
    Returns the value for a node.  Do not use to get the value for an
    element, use text() for that.
    -------------------------------------------------------------------------
 */

char *
    ipr_xml_value (
    ipr_xml_t * self                    //  Not documented
)
{
    char *
        value;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_VALUE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_value_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_VALUE))
    icl_trace_record (NULL, ipr_xml_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_VALUE))
    icl_stats_inc ("ipr_xml_value", &s_ipr_xml_value_stats);
#endif

value = self->value;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_VALUE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_VALUE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_value_finish"
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
    ipr_xml_rename

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_rename (
    ipr_xml_t * self,                   //  Not documented
    char * name                         //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_RENAME))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_rename_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_RENAME))
    icl_trace_record (NULL, ipr_xml_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_RENAME))
    icl_stats_inc ("ipr_xml_rename", &s_ipr_xml_rename_stats);
#endif

icl_mem_strfree (&self->name);
if (name)
    self->name=icl_mem_strdup (name);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_RENAME))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_RENAME))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_rename_finish"
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

}
/*  -------------------------------------------------------------------------
    ipr_xml_value_set

    Type: Component method
    Sets the value for a node.  Do not use to set the value for an element,
    but create a child node with no name, and set the value on the child
    node.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_value_set (
    ipr_xml_t * self,                   //  Not documented
    char * value                        //  Not documented
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_VALUE_SET))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_value_set_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_VALUE_SET))
    icl_trace_record (NULL, ipr_xml_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_VALUE_SET))
    icl_stats_inc ("ipr_xml_value_set", &s_ipr_xml_value_set_stats);
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_VALUE_SET))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_VALUE_SET))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_value_set_finish"
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
    ipr_xml_text

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    ipr_xml_text (
    ipr_xml_t * self                    //  Not documented
)
{
ipr_xml_t
    *child;
long
    length;
char
    *childvalue,
    *target,
    *source;
    char *
        value = NULL;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_TEXT))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_text_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_TEXT))
    icl_trace_record (NULL, ipr_xml_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_TEXT))
    icl_stats_inc ("ipr_xml_text", &s_ipr_xml_text_stats);
#endif

//
length = 0;
IPR_FOR_XML_VALUES (child, self) {
    childvalue = ipr_xml_value (child);
    if (childvalue)
        length += strlen (childvalue);
}
if (length > 0) {
    value = icl_mem_alloc (length + 1);
    if (value != NULL) {
        target = value;
        IPR_FOR_XML_VALUES (child, self) {
            source = ipr_xml_value (child);
            if (source) {
                while (*source)
                   *target++ = *source++;
            }
        }
        *target  = 0;
    }
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_TEXT))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_TEXT))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_text_finish"
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
    ipr_xml_find_item

    Type: Component method
    Locates a child item according to a path, which is name/name/name.
    Returns the item if found, else null.
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_find_item (
    ipr_xml_t * xml_root,               //  Not documented
    char * p_path                       //  Not documented
)
{
ipr_xml_t
    *xml_item,
    *xml_child;
char
    *path,
    *cur_path,
    *next_path;
    ipr_xml_t *
        xml_found;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_FIND_ITEM))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_find_item_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" xml_root=\"%pp\""
" p_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, xml_root, p_path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_FIND_ITEM))
    icl_trace_record (NULL, ipr_xml_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_FIND_ITEM))
    icl_stats_inc ("ipr_xml_find_item", &s_ipr_xml_find_item_stats);
#endif

//
path = icl_mem_strdup ((byte *) p_path);
cur_path = path;
xml_item = xml_root;
xml_child = NULL;
xml_found = NULL;

/*  Traverse the XML Tree, starting at xml_root passed to us, keeping
 *  track of our current position in the path passed to us and in the
 *  XML Tree.  Stop when we have run out of either.
 */
while (cur_path) {
    next_path = strchr (cur_path, '/');
    if (next_path)
        *next_path++ = 0;

    IPR_FOR_XML_CHILDREN (xml_child, xml_item) {
        if (strcmp (ipr_xml_name (xml_child), cur_path) == 0) {
            if (next_path == NULL) {
                xml_found = xml_child;
                break;
            }
            else
                xml_item = xml_child;
        }
    }
    cur_path = next_path;
}
icl_mem_strfree (&path);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_FIND_ITEM))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_FIND_ITEM))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_find_item_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" xml_root=\"%pp\""
" p_path=\"%s\""
" xml_found=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, xml_root, p_path, xml_found);
#endif


    return (xml_found);
}
/*  -------------------------------------------------------------------------
    ipr_xml_next_item

    Type: Component method
    Returns the next sibling with the same item name as the provided
    item.  Use to walk through a collection of elements and process all
    those of a specific type.
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_next_item (
    ipr_xml_t ** pself                  //  Not documented
)
{
char
    *item_name;
    ipr_xml_t *
        sibling;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_NEXT_ITEM))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_next_item_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" pself=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, pself);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEXT_ITEM))
    icl_trace_record (NULL, ipr_xml_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEXT_ITEM))
    icl_stats_inc ("ipr_xml_next_item", &s_ipr_xml_next_item_stats);
#endif

//
assert (pself && *pself);
item_name = ipr_xml_name (*pself);
sibling = ipr_xml_list_next (pself);
while (sibling && strneq (ipr_xml_name (sibling), item_name))
    sibling = ipr_xml_list_next (&sibling);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEXT_ITEM))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_NEXT_ITEM))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_next_item_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" pself=\"%pp\""
" sibling=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, pself, sibling);
#endif


    return (sibling);
}
/*  -------------------------------------------------------------------------
    ipr_xml_attr

    Type: Component method
    -------------------------------------------------------------------------
 */

ipr_xml_attr_t*
    ipr_xml_attr (
    ipr_xml_t* item,                    //  Not documented
    const char* name                    //  Not documented
)
{
    ipr_xml_attr_t*
        attr = NULL;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_ATTR))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_attr_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, item, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ATTR))
    icl_trace_record (NULL, ipr_xml_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ATTR))
    icl_stats_inc ("ipr_xml_attr", &s_ipr_xml_attr_stats);
#endif

//
assert (item);
assert (name);
IPR_FOR_XML_ATTRIBUTES (attr, item)
    if (attr-> name? strcmp (attr-> name, name) == 0: FALSE)
        break;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ATTR))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_ATTR))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_attr_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" item=\"%pp\""
" name=\"%pp\""
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
    ipr_xml_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_selftest (
void)
{
ipr_xml_t
    *item,
    *child;
char
    *value;
int
    rc;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_SELFTEST))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_SELFTEST))
    icl_trace_record (NULL, ipr_xml_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_SELFTEST))
    icl_stats_inc ("ipr_xml_selftest", &s_ipr_xml_selftest_stats);
#endif

    //
    item = ipr_xml_new (NULL, "item", NULL);
    value = ipr_xml_attr_get (item, "attr", NULL);
    assert (value == NULL);
    ipr_xml_attr_set (item, "attr", "value");
    value = ipr_xml_attr_get (item, "attr", "");
    assert (streq (value, "value"));

    child = ipr_xml_new (item, "child", NULL);
    ipr_xml_value_set (child, "New value for child");
    child = ipr_xml_parent (&child);
    assert (child == item);
    ipr_xml_unlink (&child);

    child = ipr_xml_first_child (item);
    assert (streq (ipr_xml_value (child), "New value for child"));
    ipr_xml_unlink (&child);
    ipr_xml_destroy (&item);

    ipr_xml_load_string (&item, "<restms><feed name=\"test.fanout\"/>", FALSE);
    ipr_xml_destroy (&item);

    value =
"<message address=\"address.multi.1\" message_id=\"ID1\">" //
"    <header name=\"serial-number\" value=\"0001\" />" //
"    <content>It's too cold</content>" //
"</message>" //
"<message address=\"address.multi.2\" message_id=\"ID2\">" //
"    <header name=\"serial-number\" value=\"0002\" />" //
"    <content>It's too hot</content>" //
"</message>" //
"";
    rc = ipr_xml_load_string (&item, value, FALSE);
    icl_console_print ("RC=%d %s", rc, ipr_xml_error ());
    ipr_xml_destroy (&item);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_SELFTEST))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_SELFTEST))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_selftest_finish"
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
    ipr_xml_remove_from_all_containers

    Type: Component method
    The method to call to remove an item from its container.  Is called by
    the 'destroy' method if the possession count hits zero.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_remove_from_all_containers (
    ipr_xml_t * self                    //  The item
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_remove_from_all_containers_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_xml_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_REMOVE_FROM_ALL_CONTAINERS))
    icl_stats_inc ("ipr_xml_remove_from_all_containers", &s_ipr_xml_remove_from_all_containers_stats);
#endif

ipr_xml_list_remove (self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_REMOVE_FROM_ALL_CONTAINERS))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_REMOVE_FROM_ALL_CONTAINERS))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_remove_from_all_containers_finish"
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
    ipr_xml_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_xml_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_SHOW))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_SHOW))
    icl_trace_record (NULL, ipr_xml_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_SHOW))
    icl_stats_inc ("ipr_xml_show", &s_ipr_xml_show_stats);
#endif

self = item;
container_links = 0;
if (self->list_head)
   container_links++;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_xml zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    if (self->history_last > IPR_XML_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_XML_HISTORY_LENGTH;
        self->history_last %= IPR_XML_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_XML_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_xml>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_SHOW))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_SHOW))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_show_finish"
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
    ipr_xml_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_TERMINATE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_TERMINATE))
    icl_trace_record (NULL, ipr_xml_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_TERMINATE))
    icl_stats_inc ("ipr_xml_terminate", &s_ipr_xml_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_TERMINATE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_TERMINATE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_terminate_finish"
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
    ipr_xml_destroy

    Type: Component method
    Destroys a ipr_xml_t object. Takes the address of a
    ipr_xml_t reference (a pointer to a pointer) and nullifies the
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
    ipr_xml_destroy_ (
    ipr_xml_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_xml_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_DESTROY_PUBLIC))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_xml_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_xml_destroy", &s_ipr_xml_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_xml_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_xml object");
        ipr_xml_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_xml_free_ ((ipr_xml_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_DESTROY_PUBLIC))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_destroy_public_finish"
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
    ipr_xml_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_xml_t *
    ipr_xml_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_xml_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_ALLOC))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ALLOC))
    icl_trace_record (NULL, ipr_xml_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_ALLOC))
    icl_stats_inc ("ipr_xml_alloc", &s_ipr_xml_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_xml_cache_initialise ();

self = (ipr_xml_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_xml_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_ALLOC))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_ALLOC))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_alloc_finish"
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
    ipr_xml_free

    Type: Component method
    Freess a ipr_xml_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_free_ (
    ipr_xml_t * self,                   //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_FREE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_FREE))
    icl_trace_record (NULL, ipr_xml_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_FREE))
    icl_stats_inc ("ipr_xml_free", &s_ipr_xml_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_XML_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_XML_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_XML_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_XML_HISTORY_LENGTH] = self->links;
#endif

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_xml_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_xml_t));
        self->object_tag = IPR_XML_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_FREE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_FREE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_free_finish"
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
    ipr_xml_read_lock

    Type: Component method
    Accepts a ipr_xml_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_xml_read_lock (
    ipr_xml_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_READ_LOCK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_READ_LOCK))
    icl_trace_record (NULL, ipr_xml_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_READ_LOCK))
    icl_stats_inc ("ipr_xml_read_lock", &s_ipr_xml_read_lock_stats);
#endif

IPR_XML_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_READ_LOCK))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_READ_LOCK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_read_lock_finish"
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
    ipr_xml_write_lock

    Type: Component method
    Accepts a ipr_xml_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_xml_write_lock (
    ipr_xml_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_WRITE_LOCK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_WRITE_LOCK))
    icl_trace_record (NULL, ipr_xml_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_WRITE_LOCK))
    icl_stats_inc ("ipr_xml_write_lock", &s_ipr_xml_write_lock_stats);
#endif

IPR_XML_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_WRITE_LOCK))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_WRITE_LOCK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_write_lock_finish"
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
    ipr_xml_unlock

    Type: Component method
    Accepts a ipr_xml_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_xml_unlock (
    ipr_xml_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_UNLOCK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_UNLOCK))
    icl_trace_record (NULL, ipr_xml_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_UNLOCK))
    icl_stats_inc ("ipr_xml_unlock", &s_ipr_xml_unlock_stats);
#endif

IPR_XML_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif

}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_UNLOCK))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_UNLOCK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_unlock_finish"
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
    ipr_xml_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_xml_t *
    ipr_xml_link_ (
    ipr_xml_t * self,                   //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_LINK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_LINK))
    icl_trace_record (NULL, ipr_xml_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_LINK))
    icl_stats_inc ("ipr_xml_link", &s_ipr_xml_link_stats);
#endif

    if (self) {
        IPR_XML_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_XML_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_XML_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_XML_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_XML_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_LINK))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_LINK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_link_finish"
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
    ipr_xml_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_unlink_ (
    ipr_xml_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
    int
        history_last;
#endif

    ipr_xml_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_UNLINK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_UNLINK))
    icl_trace_record (NULL, ipr_xml_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_UNLINK))
    icl_stats_inc ("ipr_xml_unlink", &s_ipr_xml_unlink_stats);
#endif

    if (self) {
        IPR_XML_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_xml object");
            ipr_xml_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_XML)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_XML_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_XML_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_XML_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_XML_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_xml_annihilate_ (self_p, file, line);
        ipr_xml_free_ ((ipr_xml_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_UNLINK))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_UNLINK))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_unlink_finish"
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
    ipr_xml_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_CACHE_INITIALISE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_xml_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_CACHE_INITIALISE))
    icl_stats_inc ("ipr_xml_cache_initialise", &s_ipr_xml_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_xml_t));
icl_system_register (ipr_xml_cache_purge, ipr_xml_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_CACHE_INITIALISE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_cache_initialise_finish"
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
    ipr_xml_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_CACHE_PURGE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_CACHE_PURGE))
    icl_trace_record (NULL, ipr_xml_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_CACHE_PURGE))
    icl_stats_inc ("ipr_xml_cache_purge", &s_ipr_xml_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_CACHE_PURGE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_CACHE_PURGE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_cache_purge_finish"
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
    ipr_xml_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_xml_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_CACHE_TERMINATE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_xml_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_CACHE_TERMINATE))
    icl_stats_inc ("ipr_xml_cache_terminate", &s_ipr_xml_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_CACHE_TERMINATE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_cache_terminate_finish"
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
    ipr_xml_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_xml_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_SHOW_ANIMATION))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_xml_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_SHOW_ANIMATION))
    icl_stats_inc ("ipr_xml_show_animation", &s_ipr_xml_show_animation_stats);
#endif

ipr_xml_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_SHOW_ANIMATION))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_show_animation_finish"
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
    ipr_xml_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_xml_new_in_scope_ (
    ipr_xml_t * * self_p,               //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    ipr_xml_t * parent,                 //  The parent of the new item
    char * name,                        //  The name of the new item
    char * value                        //  The value of the new item
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_XML)  ||  defined (BASE_ANIMATE_IPR_XML_NEW_IN_SCOPE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_xml_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_XML)  ||  defined (BASE_STATS_IPR_XML_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_xml_new_in_scope", &s_ipr_xml_new_in_scope_stats);
#endif

*self_p = ipr_xml_new_ (file,line,parent,name,value);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_xml_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_xml_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_XML)   || defined (BASE_ANIMATE_IPR_XML_NEW_IN_SCOPE))
    if (ipr_xml_animating)
        icl_console_print ("<ipr_xml_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_XML)   || defined (BASE_TRACE_IPR_XML_NEW)   || defined (BASE_TRACE_IPR_XML_DESTROY)   || defined (BASE_TRACE_IPR_XML_PARSE_FILE)   || defined (BASE_TRACE_IPR_XML_PARSE_STRING)   || defined (BASE_TRACE_IPR_XML_PARSE_BUCKET)   || defined (BASE_TRACE_IPR_XML_ATTACH_CHILD)   || defined (BASE_TRACE_IPR_XML_ATTACH_SIBLING)   || defined (BASE_TRACE_IPR_XML_DETACH)   || defined (BASE_TRACE_IPR_XML_FIRST_CHILD)   || defined (BASE_TRACE_IPR_XML_NEXT_SIBLING)   || defined (BASE_TRACE_IPR_XML_PARENT)   || defined (BASE_TRACE_IPR_XML_NAME)   || defined (BASE_TRACE_IPR_XML_VALUE)   || defined (BASE_TRACE_IPR_XML_RENAME)   || defined (BASE_TRACE_IPR_XML_VALUE_SET)   || defined (BASE_TRACE_IPR_XML_TEXT)   || defined (BASE_TRACE_IPR_XML_FIND_ITEM)   || defined (BASE_TRACE_IPR_XML_NEXT_ITEM)   || defined (BASE_TRACE_IPR_XML_ATTR)   || defined (BASE_TRACE_IPR_XML_SELFTEST)   || defined (BASE_TRACE_IPR_XML_REMOVE_FROM_ALL_CONTAINERS)   || defined (BASE_TRACE_IPR_XML_SHOW)   || defined (BASE_TRACE_IPR_XML_TERMINATE)   || defined (BASE_TRACE_IPR_XML_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_XML_ALLOC)   || defined (BASE_TRACE_IPR_XML_FREE)   || defined (BASE_TRACE_IPR_XML_READ_LOCK)   || defined (BASE_TRACE_IPR_XML_WRITE_LOCK)   || defined (BASE_TRACE_IPR_XML_UNLOCK)   || defined (BASE_TRACE_IPR_XML_LINK)   || defined (BASE_TRACE_IPR_XML_UNLINK)   || defined (BASE_TRACE_IPR_XML_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_XML_CACHE_PURGE)   || defined (BASE_TRACE_IPR_XML_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_XML_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_XML_NEW_IN_SCOPE) )
void
ipr_xml_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "parse file"; break;
        case 4: method_name = "parse string"; break;
        case 5: method_name = "parse bucket"; break;
        case 6: method_name = "attach child"; break;
        case 7: method_name = "attach sibling"; break;
        case 8: method_name = "detach"; break;
        case 9: method_name = "first child"; break;
        case 10: method_name = "next sibling"; break;
        case 11: method_name = "parent"; break;
        case 12: method_name = "name"; break;
        case 13: method_name = "value"; break;
        case 14: method_name = "rename"; break;
        case 15: method_name = "value set"; break;
        case 16: method_name = "text"; break;
        case 17: method_name = "find item"; break;
        case 18: method_name = "next item"; break;
        case 19: method_name = "attr"; break;
        case 20: method_name = "selftest"; break;
        case 21: method_name = "remove from all containers"; break;
        case 22: method_name = "show"; break;
        case 23: method_name = "terminate"; break;
        case 24: method_name = "destroy public"; break;
        case 25: method_name = "alloc"; break;
        case 26: method_name = "free"; break;
        case 27: method_name = "read lock"; break;
        case 28: method_name = "write lock"; break;
        case 29: method_name = "unlock"; break;
        case 30: method_name = "link"; break;
        case 31: method_name = "unlink"; break;
        case 32: method_name = "cache initialise"; break;
        case 33: method_name = "cache purge"; break;
        case 34: method_name = "cache terminate"; break;
        case 35: method_name = "show animation"; break;
        case 36: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_xml %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_xml_version_start        = "VeRsIoNsTaRt:ipc";
char *ipr_xml_component            = "ipr_xml ";
char *ipr_xml_version              = "1.1 ";
char *ipr_xml_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_xml_filename             = "ipr_xml.icl ";
char *ipr_xml_builddate            = "2009/02/19 ";
char *ipr_xml_version_end          = "VeRsIoNeNd:ipc";

