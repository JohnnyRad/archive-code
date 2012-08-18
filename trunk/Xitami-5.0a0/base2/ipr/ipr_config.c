/*---------------------------------------------------------------------------
    ipr_config.c - ipr_config component

    Generated from ipr_config.icl by icl_gen using GSL/4.
    
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
#include "ipr_config.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_config_t

//  Shorthands for class methods                                               

#define self_new            ipr_config_new
#define self_annihilate     ipr_config_annihilate
#define self_dup            ipr_config_dup
#define self_load           ipr_config_load
#define self_load_bucket    ipr_config_load_bucket
#define self_save           ipr_config_save
#define self_locate         ipr_config_locate
#define self_next           ipr_config_next
#define self_item           ipr_config_item
#define self_value          ipr_config_value
#define self_get            ipr_config_get
#define self_getn           ipr_config_getn
#define self_getp           ipr_config_getp
#define self_put            ipr_config_put
#define self_putp           ipr_config_putp
#define self_selftest       ipr_config_selftest
#define self_terminate      ipr_config_terminate
#define self_show           ipr_config_show
#define self_destroy        ipr_config_destroy
#define self_alloc          ipr_config_alloc
#define self_free           ipr_config_free
#define self_read_lock      ipr_config_read_lock
#define self_write_lock     ipr_config_write_lock
#define self_unlock         ipr_config_unlock
#define self_cache_initialise  ipr_config_cache_initialise
#define self_cache_purge    ipr_config_cache_purge
#define self_cache_terminate  ipr_config_cache_terminate
#define self_show_animation  ipr_config_show_animation
#define self_new_in_scope   ipr_config_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_NEW))
static icl_stats_t *s_ipr_config_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_DESTROY))
static icl_stats_t *s_ipr_config_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_DUP))
static icl_stats_t *s_ipr_config_dup_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_LOAD))
static icl_stats_t *s_ipr_config_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_LOAD_BUCKET))
static icl_stats_t *s_ipr_config_load_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SAVE))
static icl_stats_t *s_ipr_config_save_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_LOCATE))
static icl_stats_t *s_ipr_config_locate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_NEXT))
static icl_stats_t *s_ipr_config_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_ITEM))
static icl_stats_t *s_ipr_config_item_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_VALUE))
static icl_stats_t *s_ipr_config_value_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_GET))
static icl_stats_t *s_ipr_config_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_GETN))
static icl_stats_t *s_ipr_config_getn_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_GETP))
static icl_stats_t *s_ipr_config_getp_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_PUT))
static icl_stats_t *s_ipr_config_put_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_PUTP))
static icl_stats_t *s_ipr_config_putp_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SELFTEST))
static icl_stats_t *s_ipr_config_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_TERMINATE))
static icl_stats_t *s_ipr_config_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SHOW))
static icl_stats_t *s_ipr_config_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_config_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_ALLOC))
static icl_stats_t *s_ipr_config_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_FREE))
static icl_stats_t *s_ipr_config_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_READ_LOCK))
static icl_stats_t *s_ipr_config_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_WRITE_LOCK))
static icl_stats_t *s_ipr_config_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_UNLOCK))
static icl_stats_t *s_ipr_config_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_CACHE_INITIALISE))
static icl_stats_t *s_ipr_config_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_CACHE_PURGE))
static icl_stats_t *s_ipr_config_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_CACHE_TERMINATE))
static icl_stats_t *s_ipr_config_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SHOW_ANIMATION))
static icl_stats_t *s_ipr_config_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_config_new_in_scope_stats = NULL;
#endif
static void
    ipr_config_annihilate (
ipr_config_t * ( * self_p )             //  Reference to object reference
);

#define ipr_config_alloc()              ipr_config_alloc_ (__FILE__, __LINE__)
static ipr_config_t *
    ipr_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_config_free (
ipr_config_t * self                     //  Object reference
);

static void
    ipr_config_cache_initialise (
void);

static void
    ipr_config_cache_purge (
void);

static void
    ipr_config_cache_terminate (
void);

Bool
    ipr_config_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void
s_merge_trees (ipr_xml_t *xml_dest, ipr_xml_t *xml_source);
#include "ipr_xmll.h"
/*  -------------------------------------------------------------------------
    ipr_config_new

    Type: Component method
    Creates and initialises a new ipr_config_t object, returns a
    reference to the created object.
    If a filename is specified, loads the configuration table from the
    XML file (see ipr_config_load method).
    -------------------------------------------------------------------------
 */

ipr_config_t *
    ipr_config_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * filename,                    //  Name of configuration file
    Bool required                       //  Complain if file not found
)
{
    ipr_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_NEW))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" filename=\"%s\""
" required=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, filename, required);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEW))
    icl_trace_record (NULL, ipr_config_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_NEW))
    icl_stats_inc ("ipr_config_new", &s_ipr_config_new_stats);
#endif

    self = ipr_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_CONFIG_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_config_show_);
#endif

//
//  Empty config tree has just a root item
self->xml_root = ipr_xml_new (NULL, "root", "");
if (filename)
    self_load (self, filename, required);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEW))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_NEW))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" filename=\"%s\""
" required=\"%i\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, filename, required, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_config_annihilate (
    ipr_config_t * ( * self_p )         //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    ipr_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_DESTROY))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_DESTROY))
    icl_trace_record (NULL, ipr_config_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_DESTROY))
    icl_stats_inc ("ipr_config_annihilate", &s_ipr_config_annihilate_stats);
#endif

    IPR_CONFIG_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

if (self->duplicated)
    ipr_xml_unlink (&self->xml_root);
else
    ipr_xml_destroy (&self->xml_root);

ipr_xml_unlink (&self->xml_item);
icl_mem_free (self->cur_value);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_DESTROY))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_DESTROY))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_destroy_finish"
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
    ipr_config_dup

    Type: Component method
    Duplicates a configuration tree, used to create a local copy
    for navigation.  Copies the exact tree state.
    -------------------------------------------------------------------------
 */

ipr_config_t *
    ipr_config_dup (
    ipr_config_t * self                 //  Reference to object
)
{
    ipr_config_t *
        copy;                           //  New instance

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_DUP))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_dup_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_DUP))
    icl_trace_record (NULL, ipr_config_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_DUP))
    icl_stats_inc ("ipr_config_dup", &s_ipr_config_dup_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
copy = self_new (NULL, FALSE);
ipr_xml_destroy (&copy->xml_root);
copy->xml_root   = ipr_xml_link (self->xml_root);
copy->xml_item   = ipr_xml_link (self->xml_item);
copy->located    = self->located;
copy->duplicated = TRUE;
if (copy->xml_item)
    copy->cur_value = ipr_xml_text (copy->xml_item);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_DUP))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_DUP))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_dup_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" copy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, copy);
#endif


    return (copy);
}
/*  -------------------------------------------------------------------------
    ipr_config_load

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads an XML file into the current configuration tree.  The load method
    merges data in the loaded file with any data already in the tree.  This
    allows configuration file inheritence.  The merge process works by
    matching and merging items at each level in the tree.  Two items with the
    same item name are matched if they both have the same 'name' attribute or
    both have no 'name' attribute, and no other attributes.  The default action
    is to merge items.  Merging means that all attributes of the new item are
    applied to the existing one, and all children of the two items are in turn
    matched and merged.  If the item has the property 'config_meta' set to
    'discrete', matching children are not merged but replaced.  By definition
    a configuration tree cannot have two items with the same name at any given
    level.  Apart from this, configuration trees can have any XML syntax.
    Returns 0 if the configuration file was loaded, else -1.  Searches for the
    XML file on the PATH and reports the full path of the file loaded.
    -------------------------------------------------------------------------
 */

int
    ipr_config_load (
    ipr_config_t * self,                //  Reference to object
    char * filename,                    //  Name of configuration file
    Bool required                       //  Complain if file not found
)
{
ipr_xml_t
    *xml_root = NULL;                //  Tree of file we've loaded
ipr_xml_t
    *child;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_LOAD))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_load_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" required=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, required);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_LOAD))
    icl_trace_record (NULL, ipr_config_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_LOAD))
    icl_stats_inc ("ipr_config_load", &s_ipr_config_load_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

//
rc = ipr_xml_load_file (&xml_root, "PATH", filename, FALSE);
switch (rc) {
    case IPR_XML_NOERROR:            //  Just a long name for zero :-/
        child = ipr_xml_first_child (self->xml_root);
        icl_console_print ("I: loaded configuration from %s",
            ipr_xml_attr_get (xml_root, "fullname", "missing?"));
        ipr_xml_unlink (&child);

        s_merge_trees (self->xml_root, xml_root);
        ipr_xml_unlink (&self->xml_item);
        self->xml_item = ipr_xml_first_child (self->xml_root);
        break;
    case IPR_XML_FILEERROR:
        if (required) {
            icl_console_print ("ipr_config E: '%s' not found", filename);
            icl_console_print ("ipr_config W: %s", ipr_xml_error ());
            rc = -1;
        }
        break;
    case IPR_XML_LOADERROR:
        icl_console_print ("ipr_config W: syntax error in config file '%s'", filename);
        icl_console_print ("ipr_config W: %s", ipr_xml_error ());
        rc = -1;
        break;
}
ipr_xml_destroy (&xml_root);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_LOAD))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_LOAD))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_load_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" required=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, required, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_config_load_bucket

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a bucket of XML data into the current configuration tree.  Merges
    data in the loaded data with any data already in the tree, as for the
    load method.  Returns 0 if the data was loaded, else -1.
    -------------------------------------------------------------------------
 */

int
    ipr_config_load_bucket (
    ipr_config_t * self,                //  Reference to object
    ipr_bucket_t * bucket               //  Bucket of XML data
)
{
ipr_xml_t
    *xml_root = NULL;                //  Tree of file we've loaded
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_LOAD_BUCKET))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_load_bucket_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, ipr_config_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_LOAD_BUCKET))
    icl_stats_inc ("ipr_config_load_bucket", &s_ipr_config_load_bucket_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

//
rc = ipr_xml_load_bucket (&xml_root, bucket, FALSE);
switch (rc) {
    case IPR_XML_NOERROR:
        s_merge_trees (self->xml_root, xml_root);
        ipr_xml_unlink (&self->xml_item);
        self->xml_item = ipr_xml_first_child (self->xml_root);
        break;
    case IPR_XML_LOADERROR:
        rc = -1;
        break;
}
ipr_xml_destroy (&xml_root);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_LOAD_BUCKET))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_load_bucket_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_config_save

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the configuration tree to the specified file.
    -------------------------------------------------------------------------
 */

int
    ipr_config_save (
    ipr_config_t * self,                //  Reference to object
    char * filename                     //  Name of configuration file
)
{
ipr_xml_t
    *xml_item;                      //  Current item in our new tree
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_SAVE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_save_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SAVE))
    icl_trace_record (NULL, ipr_config_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SAVE))
    icl_stats_inc ("ipr_config_save", &s_ipr_config_save_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

//
xml_item = ipr_xml_first_child (self->xml_root);
ipr_xml_save_file (xml_item, filename);
ipr_xml_unlink (&xml_item);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SAVE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_SAVE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_save_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_config_locate

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    Locates an item in the configuration tree.  We use a simple path
    notation. The path to an item is specified as an absolute path:
    "/item/item..." or a relative path (with no leading slash). The
    last item in the path may be selected by its 'name' attribute.
    You can use ".." in the path to move to the parent item, or "+"
    to move to the first child item.  The name may be null. Having
    located an item you can locate further items relative to it, or
    access the item's value and attributes.  Returns 0 if the item
    was located successfully, -1 if not.  After a locate the located
    property also indicates whether the item was found or not.
    -------------------------------------------------------------------------
 */

int
    ipr_config_locate (
    ipr_config_t * self,                //  Reference to object
    char * path,                        //  Path to item
    char * name                         //  Name selector
)
{
char
    *s_path,
    *token_start,
    *token_end;
int
    token_nbr;
ipr_xml_t
    *xml_item,
    *xml_child;
Bool
    have_match;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_LOCATE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_locate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_LOCATE))
    icl_trace_record (NULL, ipr_config_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_LOCATE))
    icl_stats_inc ("ipr_config_locate", &s_ipr_config_locate_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

//
assert (path);
if (*path == '/') {
    path++;
    if (self->xml_item)                 //  Remove ref to old item
        ipr_xml_unlink (&self->xml_item);
    self->xml_item = self->xml_root;
    ipr_xml_link (self->xml_item);      //  Add ref to item
}
//  Now process path unless XML tree is empty
if (self->xml_item) {
    xml_item  = self->xml_item;
    ipr_xml_link (xml_item);
    token_nbr = 0;
    s_path = icl_mem_strdup (path);
    token_end = s_path;
    do {
        token_start = token_end;
        token_end   = strchr (token_end, '/');
        if (token_end)
            *token_end = 0;

        if (streq (token_start, "..")) {
            if (xml_item != self->xml_root)
                xml_item = ipr_xml_parent (&xml_item);
        }
        else
        if (streq (token_start, "+")) {
            xml_child = ipr_xml_first_child (xml_item);
            if (xml_child) {
                ipr_xml_unlink (&xml_item);
                xml_item = xml_child;
            }
            else
                rc = -1;                //  No child items
        }
        else {
            //  Find first child item with name of this token
            have_match = FALSE;
            IPR_FOR_XML_CHILDREN (xml_child, xml_item) {
                if (streq (ipr_xml_name (xml_child), token_start)) {
                    //  If at end of path, use name selector
                    if ((!token_end) && name) {
                        if (streq (ipr_xml_attr_get (xml_child, "name", ""), name))
                            have_match = TRUE;
                    }
                    else
                        have_match = TRUE;
                }
                if (have_match) {
                    ipr_xml_unlink (&xml_item);
                    xml_item = xml_child;
                    break;
                }
            }
            if (!have_match) {
                rc = -1;
                break;              //  No match, quit searching
            }
        }
        if (token_end)
            token_end++;            //  Bump to after slash

    } while (token_end);            //  Until we end the path

    if (rc == 0) {
        ipr_xml_unlink (&self->xml_item);   //  Remove ref to old item
        self->xml_item = xml_item;
    }
    else
        ipr_xml_unlink (&xml_item);

    icl_mem_free (s_path);
}
else
    rc = -1;

self->located = (rc == 0);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_LOCATE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_LOCATE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_locate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_config_next

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    Locates the next sibling item in the configuration tree.  This
    will be the next item at the same level as the current item, if
    any.  Returns 0 if there was a next item, -1 if not.
    -------------------------------------------------------------------------
 */

int
    ipr_config_next (
    ipr_config_t * self                 //  Reference to object
)
{
ipr_xml_t
    *xml_item;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_NEXT))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_next_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEXT))
    icl_trace_record (NULL, ipr_config_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_NEXT))
    icl_stats_inc ("ipr_config_next", &s_ipr_config_next_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

//
IPR_CONFIG_ASSERT_SANE (self);
xml_item = ipr_xml_link (self->xml_item);
self->xml_item = ipr_xml_next_sibling (&self->xml_item);
if (self->xml_item)
    ipr_xml_unlink (&xml_item);
else {
    self->xml_item = xml_item;
    rc = -1;
}
self->located = (rc == 0);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEXT))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_NEXT))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_next_finish"
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
    ipr_config_item

    Type: Component method
    Returns the item name of the current item. You should not modify
    the returned string.
    -------------------------------------------------------------------------
 */

char *
    ipr_config_item (
    ipr_config_t * self                 //  Reference to object
)
{
    char *
        item;                           //  Returned name

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_ITEM))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_item_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_ITEM))
    icl_trace_record (NULL, ipr_config_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_ITEM))
    icl_stats_inc ("ipr_config_item", &s_ipr_config_item_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
assert (self->xml_item);
item = ipr_xml_name (self->xml_item);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_ITEM))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_ITEM))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_item_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" item=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, item);
#endif


    return (item);
}
/*  -------------------------------------------------------------------------
    ipr_config_value

    Type: Component method
    Returns the value of the current item.  This can include newlines
    and leading and trailing spaces.  You should not modify the returned
    string.  The returned string is valid until you request another item
    value.
    -------------------------------------------------------------------------
 */

char *
    ipr_config_value (
    ipr_config_t * self                 //  Reference to object
)
{
    char *
        value;                          //  Returned value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_VALUE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_value_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_VALUE))
    icl_trace_record (NULL, ipr_config_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_VALUE))
    icl_stats_inc ("ipr_config_value", &s_ipr_config_value_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
assert (self->xml_item);
if (self->cur_value)
    icl_mem_free (self->cur_value);
self->cur_value = ipr_xml_text (self->xml_item);
value = self->cur_value;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_VALUE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_VALUE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_value_finish"
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
    ipr_config_get

    Type: Component method
    Returns the specified attribute, if it exists. The attribute value
    can (but does usually not) include newlines. You should not modify
    the returned string. Returns the default value if the attribute is
    not defined.
    -------------------------------------------------------------------------
 */

char *
    ipr_config_get (
    ipr_config_t * self,                //  Reference to object
    char * name,                        //  Attribute name
    char * dflt                         //  Default value
)
{
    char *
        value;                          //  Returned value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_GET))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" dflt=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, dflt);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_GET))
    icl_trace_record (NULL, ipr_config_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_GET))
    icl_stats_inc ("ipr_config_get", &s_ipr_config_get_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
value = ipr_xml_attr_get (self->xml_item, name, dflt);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_GET))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_GET))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" dflt=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, dflt, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_config_getn

    Type: Component method
    Returns the numeric value for the specified attribute, or zero if
    not defined.
    -------------------------------------------------------------------------
 */

long
    ipr_config_getn (
    ipr_config_t * self,                //  Reference to object
    char * name                         //  Attribute name
)
{
    long
        value;                          //  Returned value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_GETN))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_getn_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_GETN))
    icl_trace_record (NULL, ipr_config_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_GETN))
    icl_stats_inc ("ipr_config_getn", &s_ipr_config_getn_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
value = atol (ipr_xml_attr_get (self->xml_item, name, "0"));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_GETN))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_GETN))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_getn_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" value=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_config_getp

    Type: Component method
    Locates a path in the configuration tree and returns an attribute
    of that item.  Combines the ipr_config_locate and ipr_config_get
    methods and leaves the current object in the same state as the locate
    method would.
    -------------------------------------------------------------------------
 */

char *
    ipr_config_getp (
    ipr_config_t * self,                //  Reference to object
    char * path,                        //  Path to item
    char * name,                        //  Attribute name
    char * dflt                         //  Default value
)
{
    char *
        value;                          //  Returned value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_GETP))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_getp_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" name=\"%s\""
" dflt=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, name, dflt);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_GETP))
    icl_trace_record (NULL, ipr_config_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_GETP))
    icl_stats_inc ("ipr_config_getp", &s_ipr_config_getp_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
self_locate (self, path, NULL);
value = self_get (self, name, dflt);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_GETP))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_GETP))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_getp_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" name=\"%s\""
" dflt=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, name, dflt, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_config_put

    Type: Component method
    Updates or inserts an attribute value at the current position in
    the configuration file.
    -------------------------------------------------------------------------
 */

char *
    ipr_config_put (
    ipr_config_t * self,                //  Reference to object
    char * name,                        //  Attribute name
    char * value                        //  Attribute value
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_PUT))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_put_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_PUT))
    icl_trace_record (NULL, ipr_config_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_PUT))
    icl_stats_inc ("ipr_config_put", &s_ipr_config_put_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
ipr_xml_attr_set (self->xml_item, name, value);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_PUT))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_PUT))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_put_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_config_putp

    Type: Component method
    Locates a path in the configuration tree and updates an attribute
    of that item.  Combines the ipr_config_locate and ipr_config_put
    methods and leaves the current object in the same state as the locate
    method would.
    -------------------------------------------------------------------------
 */

char *
    ipr_config_putp (
    ipr_config_t * self,                //  Reference to object
    char * path,                        //  Path to item
    char * name,                        //  Attribute name
    char * value                        //  Attribute value
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_PUTP))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_putp_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, name, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_PUTP))
    icl_trace_record (NULL, ipr_config_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_PUTP))
    icl_stats_inc ("ipr_config_putp", &s_ipr_config_putp_stats);
#endif

//
IPR_CONFIG_ASSERT_SANE (self);
//TODO: should create path if it's not already defined
self_locate (self, path, NULL);
self_put    (self, name, value);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_PUTP))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_PUTP))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_putp_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" path=\"%s\""
" name=\"%s\""
" value=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, path, name, value);
#endif


    return (value);
}
/*  -------------------------------------------------------------------------
    ipr_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_config_selftest (
void)
{
ipr_config_t
    *config;
int
    items;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_SELFTEST))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SELFTEST))
    icl_trace_record (NULL, ipr_config_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SELFTEST))
    icl_stats_inc ("ipr_config_selftest", &s_ipr_config_selftest_stats);
#endif

//
config = ipr_config_new ("ipr_config_test1.xml", TRUE);
ipr_config_load (config, "ipr_config_test2.xml", TRUE);
ipr_config_load (config, "ipr_config_test3.xml", TRUE);
ipr_config_load (config, "no-such-file.xml",    FALSE);
ipr_config_save (config, "ipr_config_save.xml");

//  Test data has four queues, iterate through them
ipr_config_locate (config, "/config/queues/queue", "");
for (items = 0; items < 4; items++) {
    assert (config->located);
    ipr_config_next (config);
}
assert (config->located == FALSE);

//  Try some navigation
ipr_config_locate (config, "/config/general/security/profile", "custom");
assert (config->located);
ipr_config_locate (config, "..", "default");
assert (config->located);

//  Test config_meta = "discrete", we should see example profile from test3
ipr_config_locate (config, "/config/profiles/profile", "example");
assert (config->located);
ipr_config_locate (config, "limit", NULL);
for (items = 0; items < 3; items++) {
    assert (config->located);
    ipr_config_next (config);
}
assert (config->located == FALSE);

ipr_config_locate (config, "/config/queues/queue", "");
ipr_config_locate (config, "/config/queues/queue", "test");
assert (streq (ipr_config_value (config), "This is a test queue"));
assert (streq (ipr_config_get (config, "overflow", "?"), "2000"));

ipr_config_destroy (&config);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SELFTEST))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_SELFTEST))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_selftest_finish"
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
    ipr_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_config_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_TERMINATE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_TERMINATE))
    icl_trace_record (NULL, ipr_config_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_TERMINATE))
    icl_stats_inc ("ipr_config_terminate", &s_ipr_config_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_TERMINATE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_TERMINATE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_terminate_finish"
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
    ipr_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_config_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_SHOW))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SHOW))
    icl_trace_record (NULL, ipr_config_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SHOW))
    icl_stats_inc ("ipr_config_show", &s_ipr_config_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SHOW))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_SHOW))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_show_finish"
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
    ipr_config_destroy

    Type: Component method
    Destroys a ipr_config_t object. Takes the address of a
    ipr_config_t reference (a pointer to a pointer) and nullifies the
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
    ipr_config_destroy_ (
    ipr_config_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_DESTROY_PUBLIC))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_config_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_config_destroy", &s_ipr_config_destroy_stats);
#endif

if (self) {
    ipr_config_annihilate (self_p);
    ipr_config_free ((ipr_config_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_DESTROY_PUBLIC))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_destroy_public_finish"
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
    ipr_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_config_t *
    ipr_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_ALLOC))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_ALLOC))
    icl_trace_record (NULL, ipr_config_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_ALLOC))
    icl_stats_inc ("ipr_config_alloc", &s_ipr_config_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_config_cache_initialise ();

self = (ipr_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_config_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_ALLOC))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_ALLOC))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_alloc_finish"
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
    ipr_config_free

    Type: Component method
    Freess a ipr_config_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_config_free (
    ipr_config_t * self                 //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_FREE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_FREE))
    icl_trace_record (NULL, ipr_config_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_FREE))
    icl_stats_inc ("ipr_config_free", &s_ipr_config_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_config_t));
        self->object_tag = IPR_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_FREE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_FREE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_free_finish"
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
    ipr_config_read_lock

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_config_read_lock (
    ipr_config_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_READ_LOCK))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_READ_LOCK))
    icl_trace_record (NULL, ipr_config_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_READ_LOCK))
    icl_stats_inc ("ipr_config_read_lock", &s_ipr_config_read_lock_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_READ_LOCK))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_READ_LOCK))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_read_lock_finish"
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
    ipr_config_write_lock

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_config_write_lock (
    ipr_config_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_WRITE_LOCK))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, ipr_config_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_WRITE_LOCK))
    icl_stats_inc ("ipr_config_write_lock", &s_ipr_config_write_lock_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_WRITE_LOCK))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_write_lock_finish"
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
    ipr_config_unlock

    Type: Component method
    Accepts a ipr_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_config_unlock (
    ipr_config_t * self                 //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_UNLOCK))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_UNLOCK))
    icl_trace_record (NULL, ipr_config_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_UNLOCK))
    icl_stats_inc ("ipr_config_unlock", &s_ipr_config_unlock_stats);
#endif

IPR_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_UNLOCK))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_UNLOCK))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_unlock_finish"
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
    ipr_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_config_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_CACHE_INITIALISE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_config_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_CACHE_INITIALISE))
    icl_stats_inc ("ipr_config_cache_initialise", &s_ipr_config_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_config_t));
icl_system_register (ipr_config_cache_purge, ipr_config_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_CACHE_INITIALISE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_cache_initialise_finish"
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
    ipr_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_config_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_CACHE_PURGE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, ipr_config_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_CACHE_PURGE))
    icl_stats_inc ("ipr_config_cache_purge", &s_ipr_config_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_CACHE_PURGE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_cache_purge_finish"
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
    ipr_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_config_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_CACHE_TERMINATE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_config_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_CACHE_TERMINATE))
    icl_stats_inc ("ipr_config_cache_terminate", &s_ipr_config_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_CACHE_TERMINATE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_cache_terminate_finish"
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
    ipr_config_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_config_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_SHOW_ANIMATION))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_config_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_SHOW_ANIMATION))
    icl_stats_inc ("ipr_config_show_animation", &s_ipr_config_show_animation_stats);
#endif

ipr_config_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_SHOW_ANIMATION))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_show_animation_finish"
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
    ipr_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_config_new_in_scope_ (
    ipr_config_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * filename,                    //  Name of configuration file
    Bool required                       //  Complain if file not found
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_CONFIG)  ||  defined (BASE_ANIMATE_IPR_CONFIG_NEW_IN_SCOPE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" filename=\"%s\""
" required=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, filename, required);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_config_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_CONFIG)  ||  defined (BASE_STATS_IPR_CONFIG_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_config_new_in_scope", &s_ipr_config_new_in_scope_stats);
#endif

*self_p = ipr_config_new_ (file,line,filename,required);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_config_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_CONFIG)   || defined (BASE_ANIMATE_IPR_CONFIG_NEW_IN_SCOPE))
    if (ipr_config_animating)
        icl_console_print ("<ipr_config_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" filename=\"%s\""
" required=\"%i\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, filename, required, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_CONFIG)   || defined (BASE_TRACE_IPR_CONFIG_NEW)   || defined (BASE_TRACE_IPR_CONFIG_DESTROY)   || defined (BASE_TRACE_IPR_CONFIG_DUP)   || defined (BASE_TRACE_IPR_CONFIG_LOAD)   || defined (BASE_TRACE_IPR_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_IPR_CONFIG_SAVE)   || defined (BASE_TRACE_IPR_CONFIG_LOCATE)   || defined (BASE_TRACE_IPR_CONFIG_NEXT)   || defined (BASE_TRACE_IPR_CONFIG_ITEM)   || defined (BASE_TRACE_IPR_CONFIG_VALUE)   || defined (BASE_TRACE_IPR_CONFIG_GET)   || defined (BASE_TRACE_IPR_CONFIG_GETN)   || defined (BASE_TRACE_IPR_CONFIG_GETP)   || defined (BASE_TRACE_IPR_CONFIG_PUT)   || defined (BASE_TRACE_IPR_CONFIG_PUTP)   || defined (BASE_TRACE_IPR_CONFIG_SELFTEST)   || defined (BASE_TRACE_IPR_CONFIG_TERMINATE)   || defined (BASE_TRACE_IPR_CONFIG_SHOW)   || defined (BASE_TRACE_IPR_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_CONFIG_ALLOC)   || defined (BASE_TRACE_IPR_CONFIG_FREE)   || defined (BASE_TRACE_IPR_CONFIG_READ_LOCK)   || defined (BASE_TRACE_IPR_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_IPR_CONFIG_UNLOCK)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_IPR_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_CONFIG_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_CONFIG_NEW_IN_SCOPE) )
void
ipr_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "dup"; break;
        case 4: method_name = "load"; break;
        case 5: method_name = "load bucket"; break;
        case 6: method_name = "save"; break;
        case 7: method_name = "locate"; break;
        case 8: method_name = "next"; break;
        case 9: method_name = "item"; break;
        case 10: method_name = "value"; break;
        case 11: method_name = "get"; break;
        case 12: method_name = "getn"; break;
        case 13: method_name = "getp"; break;
        case 14: method_name = "put"; break;
        case 15: method_name = "putp"; break;
        case 16: method_name = "selftest"; break;
        case 17: method_name = "terminate"; break;
        case 18: method_name = "show"; break;
        case 19: method_name = "destroy public"; break;
        case 20: method_name = "alloc"; break;
        case 21: method_name = "free"; break;
        case 22: method_name = "read lock"; break;
        case 23: method_name = "write lock"; break;
        case 24: method_name = "unlock"; break;
        case 25: method_name = "cache initialise"; break;
        case 26: method_name = "cache purge"; break;
        case 27: method_name = "cache terminate"; break;
        case 28: method_name = "show animation"; break;
        case 29: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_config %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

static void
s_merge_trees (ipr_xml_t *xml_dest, ipr_xml_t *xml_source)
{
    ipr_xml_t
        *xml_item,                      //  Current item in our new tree
        *xml_item_link,                 //  Extra link to xml_item
        *xml_into,                      //  Destination item in config
        *xml_next;                      //  Next item on list
    ipr_xml_attr_t
        *xml_attr,                      //  Attribute of our current item
        *item_attr,                     //  First attribute of target item
        *into_attr;                     //  First attribute of destination item
    char
        *item_name,
        *into_name;
    Bool
        discrete,                       //  Replace children, don't merge
        processed;

    //  Check config_meta options
    discrete = streq (ipr_xml_attr_get (xml_dest, "config_meta", ""), "discrete");

    //  Merge attributes of source into dest
    IPR_FOR_XML_ATTRIBUTES (xml_attr, xml_source)
        ipr_xml_attr_set (xml_dest, ipr_xml_attr_name (xml_attr), ipr_xml_attr_value (xml_attr));

    //  Process each child item of xml_source
    xml_item = ipr_xml_first_child (xml_source);
    while (xml_item) {
        if (ipr_xml_name (xml_item)) {
            processed = FALSE;
            //  a) item is named, look for matching named item
            //  b) item is unnamed, merge only if both have no attributes
            item_name = ipr_xml_attr_get (xml_item, "name", NULL);
            item_attr = ipr_xml_attr_first (xml_item);
            IPR_FOR_XML_CHILDREN (xml_into, xml_dest) {
                if (streq (ipr_xml_name (xml_into), ipr_xml_name (xml_item))) {
                    into_name = ipr_xml_attr_get (xml_into, "name", NULL);
                    into_attr = ipr_xml_attr_first (xml_into);
                    //  Skip config_meta tag, on destination only
                    if (into_attr && streq (ipr_xml_attr_name (into_attr), "config_meta"))
                        into_attr = ipr_xml_attr_next (&into_attr);

                    if ((item_name && into_name && streq (into_name, item_name))
                    || (!item_name && !item_attr && !into_name && !into_attr)) {
                        //  We have a match, so now replace or merge item
                        if (discrete) {
                            xml_item_link = ipr_xml_link (xml_item);
                            ipr_xml_detach (xml_item);
                            ipr_xml_attach_sibling (xml_into, xml_item);
                            ipr_xml_unlink (&xml_item_link); //  Remove the extra link
                            xml_item = ipr_xml_next_sibling (&xml_item);
                            ipr_xml_destroy (&xml_into);
                        }
                        else
                            s_merge_trees (xml_into, xml_item);
                        processed = TRUE;
                    }
                    ipr_xml_attr_unlink (&into_attr);
                    if (processed) {
                        ipr_xml_unlink (&xml_into);
                        break;
                    }
                }
            }
            //  Move current item to destination if needed, and do next
            xml_item_link = ipr_xml_link (xml_item);
            xml_next = ipr_xml_next_sibling (&xml_item_link);
            if (!processed) {
                ipr_xml_detach (xml_item);
                ipr_xml_attach_child (xml_dest, xml_item);
            }
            ipr_xml_attr_unlink (&item_attr);
            ipr_xml_unlink (&xml_item);    //  Remove the extra link
            xml_item = xml_next;
        }
        else
            xml_item = ipr_xml_next_sibling (&xml_item);
    }
}

//  Embed the version information in the resulting binary                      

char *ipr_config_version_start     = "VeRsIoNsTaRt:ipc";
char *ipr_config_component         = "ipr_config ";
char *ipr_config_version           = "1.1 ";
char *ipr_config_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_config_filename          = "ipr_config.icl ";
char *ipr_config_builddate         = "2009/02/19 ";
char *ipr_config_version_end       = "VeRsIoNeNd:ipc";

