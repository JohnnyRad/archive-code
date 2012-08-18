/*---------------------------------------------------------------------------
    ipr_dir.c - ipr_dir component

    Provides a directory listing object that can be resorted in various
    ways.
    Generated from ipr_dir.icl by icl_gen using GSL/4.
    
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
#include "ipr_dir.h"                    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_dir_t

//  Shorthands for class methods                                               

#define self_new            ipr_dir_new
#define self_annihilate     ipr_dir_annihilate
#define self_resort         ipr_dir_resort
#define self_dump           ipr_dir_dump
#define self_create         ipr_dir_create
#define self_remove         ipr_dir_remove
#define self_selftest       ipr_dir_selftest
#define self_terminate      ipr_dir_terminate
#define self_show           ipr_dir_show
#define self_destroy        ipr_dir_destroy
#define self_alloc          ipr_dir_alloc
#define self_free           ipr_dir_free
#define self_cache_initialise  ipr_dir_cache_initialise
#define self_cache_purge    ipr_dir_cache_purge
#define self_cache_terminate  ipr_dir_cache_terminate
#define self_show_animation  ipr_dir_show_animation
#define self_new_in_scope   ipr_dir_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_NEW))
static icl_stats_t *s_ipr_dir_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_DESTROY))
static icl_stats_t *s_ipr_dir_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_RESORT))
static icl_stats_t *s_ipr_dir_resort_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_DUMP))
static icl_stats_t *s_ipr_dir_dump_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CREATE))
static icl_stats_t *s_ipr_dir_create_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_REMOVE))
static icl_stats_t *s_ipr_dir_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_SELFTEST))
static icl_stats_t *s_ipr_dir_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_TERMINATE))
static icl_stats_t *s_ipr_dir_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_SHOW))
static icl_stats_t *s_ipr_dir_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_dir_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_ALLOC))
static icl_stats_t *s_ipr_dir_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_FREE))
static icl_stats_t *s_ipr_dir_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CACHE_INITIALISE))
static icl_stats_t *s_ipr_dir_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CACHE_PURGE))
static icl_stats_t *s_ipr_dir_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CACHE_TERMINATE))
static icl_stats_t *s_ipr_dir_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_SHOW_ANIMATION))
static icl_stats_t *s_ipr_dir_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_dir_new_in_scope_stats = NULL;
#endif
static void
    ipr_dir_annihilate (
ipr_dir_t * ( * self_p )                //  Reference to object reference
);

#define ipr_dir_alloc()                 ipr_dir_alloc_ (__FILE__, __LINE__)
static ipr_dir_t *
    ipr_dir_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_dir_free (
ipr_dir_t * self                        //  Object reference
);

static void
    ipr_dir_cache_initialise (
void);

static void
    ipr_dir_cache_purge (
void);

static void
    ipr_dir_cache_terminate (
void);

Bool
    ipr_dir_animating = TRUE;           //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static int
    s_sort_by_name       (const void *info1, const void *info2);
static int
    s_sort_by_time       (const void *info1, const void *info2);
static int
    s_sort_by_time_desc  (const void *info1, const void *info2);
static int
    s_sort_by_size       (const void *info1, const void *info2);
static int
    s_sort_by_size_desc  (const void *info1, const void *info2);
/*  -------------------------------------------------------------------------
    ipr_dir_new

    Type: Component method
    Creates and initialises a new ipr_dir_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_dir_t *
    ipr_dir_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * path,                        //  Directory path to load
    char sortby                         //  Sort key
)
{
apr_dir_t
    *dir = NULL;
apr_status_t
    rc;
apr_finfo_t
    apr_finfo;
ipr_finfo_t
    *finfo;
    ipr_dir_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_NEW))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_NEW))
    icl_trace_record (NULL, ipr_dir_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_NEW))
    icl_stats_inc ("ipr_dir_new", &s_ipr_dir_new_stats);
#endif

    self = ipr_dir_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_DIR_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_dir_show_);
#endif

//
apr_pool_create (&self->pool, NULL);
self->finfo_list = ipr_finfo_list_new ();

rc = apr_dir_open (&dir, path, self->pool);
if (rc == APR_SUCCESS) {
    rc = apr_dir_read (&apr_finfo, APR_FINFO_MIN + APR_FINFO_OWNER, dir);
    while (rc == APR_SUCCESS || rc == APR_INCOMPLETE) {
        finfo = ipr_finfo_new (&apr_finfo);
        ipr_finfo_list_push (self->finfo_list, finfo);
        ipr_finfo_unlink (&finfo);
        rc = apr_dir_read (&apr_finfo, APR_FINFO_MIN + APR_FINFO_OWNER, dir);
    }
    apr_dir_close (dir);
    self_resort (self, sortby);
}
else
    self_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_NEW))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_NEW))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" path=\"%s\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, path, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_dir_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dir_annihilate (
    ipr_dir_t * ( * self_p )            //  Reference to object reference
)
{

    ipr_dir_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_DESTROY))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_DESTROY))
    icl_trace_record (NULL, ipr_dir_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_DESTROY))
    icl_stats_inc ("ipr_dir_annihilate", &s_ipr_dir_annihilate_stats);
#endif

IPR_DIR_ASSERT_SANE (self);

icl_mem_free (self->index);
ipr_finfo_list_destroy (&self->finfo_list);
apr_pool_destroy (self->pool);
self->pool = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_DESTROY))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_DESTROY))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_destroy_finish"
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
    ipr_dir_resort

    Type: Component method
    Accepts a ipr_dir_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_dir_resort (
    ipr_dir_t * self,                   //  Reference to object
    char sortby                         //  Sort key
)
{
ipr_finfo_t
    *finfo;
uint
    finfo_nbr;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_RESORT))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_resort_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_RESORT))
    icl_trace_record (NULL, ipr_dir_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_RESORT))
    icl_stats_inc ("ipr_dir_resort", &s_ipr_dir_resort_stats);
#endif

IPR_DIR_ASSERT_SANE (self);

//
//  Allocate an index to sort the finfo entries
if (self->index)
    icl_mem_free (self->index);
self->index_size = ipr_finfo_list_count (self->finfo_list);
self->index = icl_mem_alloc (self->index_size * sizeof (ipr_finfo_t *));

finfo = ipr_finfo_list_first (self->finfo_list);
for (finfo_nbr = 0; finfo_nbr < self->index_size; finfo_nbr++) {
    self->index [finfo_nbr] = finfo;
    finfo = ipr_finfo_list_next (&finfo);
}
qsort (self->index, self->index_size, sizeof (ipr_finfo_t *),
    sortby == 'n'? s_sort_by_name:
    sortby == 't'? s_sort_by_time:
    sortby == 'T'? s_sort_by_time_desc:
    sortby == 's'? s_sort_by_size:
    sortby == 'S'? s_sort_by_size_desc:
                   s_sort_by_name);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_RESORT))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_RESORT))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_resort_finish"
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
    ipr_dir_dump

    Type: Component method
    Accepts a ipr_dir_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_dir_dump (
    ipr_dir_t * self                    //  Reference to object
)
{
ipr_finfo_t
    *finfo;
uint
    finfo_nbr;
icl_shortstr_t
    buffer;                         //  Formatted directory entry
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_DUMP))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_dump_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_DUMP))
    icl_trace_record (NULL, ipr_dir_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_DUMP))
    icl_stats_inc ("ipr_dir_dump", &s_ipr_dir_dump_stats);
#endif

IPR_DIR_ASSERT_SANE (self);

//
assert (self->index);
for (finfo_nbr = 0; finfo_nbr < self->index_size; finfo_nbr++) {
    finfo = self->index [finfo_nbr];
    ipr_finfo_print (finfo, buffer);
    icl_console_print (buffer);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_DUMP))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_DUMP))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_dump_finish"
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
    ipr_dir_create

    Type: Component method
    Create a new directory.  Returns 0 if the directory was created;
    -1 if there was an error.  Under Windows and OpenVMS, accepts directory
    names with '/'.  Will create multiple levels of directory if required.
    -------------------------------------------------------------------------
 */

Bool
    ipr_dir_create (
    char * path_to_create               //  Directory path to create
)
{
    icl_shortstr_t
        path;
#   if (defined (GATES_FILESYSTEM))
    char
        *char_ptr;
#   endif
    char
        *slash;
    Bool
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_CREATE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_create_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path_to_create=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path_to_create);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CREATE))
    icl_trace_record (NULL, ipr_dir_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CREATE))
    icl_stats_inc ("ipr_dir_create", &s_ipr_dir_create_stats);
#endif

    //  Get working copy so we can mangle it a little                          
    icl_shortstr_cpy (path, path_to_create);
#   if (defined (GATES_FILESYSTEM))
    for (char_ptr = path; *char_ptr; char_ptr++)
        if (*char_ptr == '/')
            *char_ptr = '\\';

    //  Handle \systemdrive specially
    if (path [0] == '\\' && path [1] == '\\') {
        slash = strchr (path + 2, '\\');
        if (slash)
            slash = strchr (slash + 1, '\\');
    }
    else
#   endif
    slash = strchr (path + 1, PATHEND);

    //  Create each component of directory as required                         
    FOREVER {                           //  Create any parent directories      
        if (slash)
            *slash = '\0';              //  Cut at slash                       
        if (!ipr_file_is_directory (path)) {
#   if (defined (__UNIX__) || defined (__VMS_XOPEN) || defined (__OS2__))
            rc = mkdir (path, 0775);    //  User RWE Group RWE World RE        

#   elif (defined (WIN32))
            if (CreateDirectory (path, NULL))
                rc = 0;
            else
                rc = -1;
#   elif (defined (GATES_FILESYSTEM))
            rc = mkdir (path);          //  Protection?  What's that?          
#   else
            rc = -1;                    //  Not a known system                 
#   endif
            if (rc)                     //  End if error                       
                break;
        }
        if (slash == NULL)              //  End if last directory              
            break;
        *slash = PATHEND;               //  Restore path name                  
        slash = strchr (slash + 1, PATHEND);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CREATE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_CREATE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_create_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path_to_create=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path_to_create, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dir_remove

    Type: Component method
    Remove a directory.  Returns 0 if the directory could be
    removed; -1 if there was an error.  Under MS-DOS and OpenVMS accepts
    a directory name in UNIX format, i.e. containing '/' delimiters.  The
    directory does not need to be empty to be removed; any child directories
    and contained files will be deleted.
    -------------------------------------------------------------------------
 */

Bool
    ipr_dir_remove (
    char * path                         //  Directory path to remove
)
{
    ipr_dir_t
        *dir;                           //  Get list of contained files
    uint
        finfo_nbr;
    ipr_finfo_t
        *finfo;
    icl_shortstr_t
        path_filename;                  //  Path/filename
#   if (defined (GATES_FILESYSTEM))
    icl_shortstr_t
        copy_path;
    char
        *char_ptr;
#   endif
    Bool
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_REMOVE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_remove_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_REMOVE))
    icl_trace_record (NULL, ipr_dir_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_REMOVE))
    icl_stats_inc ("ipr_dir_remove", &s_ipr_dir_remove_stats);
#endif

    //
    //  Delete all child directories and contained files
    dir = ipr_dir_new (path, 'n');
    assert (dir->index);
    for (finfo_nbr = 0; finfo_nbr < dir->index_size; finfo_nbr++) {
        finfo = dir->index [finfo_nbr];
        icl_shortstr_fmt (path_filename, "%s/%s", path, finfo->name);
        if (finfo->filetype == APR_DIR) {
            if (*finfo->name != '.')
                ipr_dir_remove (path_filename);
        }
        else
            ipr_file_delete (path_filename);
    }
    ipr_dir_destroy (&dir);

#   if (defined (__UNIX__) || defined (__VMS_XOPEN) || defined (__OS2__))
    if (ipr_file_is_directory (path))
        rc = rmdir (path);
    else
        rc = -1;

#   elif (defined (GATES_FILESYSTEM))
    //  Check that directory exists                                            
    if (ipr_file_is_directory (path)) {
        icl_shortstr_cpy (copy_path, path);
        for (char_ptr = copy_path; *char_ptr; char_ptr++)
            if (*char_ptr == '/')
                *char_ptr = '\\';
#   if (defined (WIN32))
        if (RemoveDirectory (copy_path))
            rc = 0;
        else
            rc = -1;
#   else
        rc = rmdir (copy_path);
#   endif
    }
    else
        rc = -1;
#   else
    rc = -1;                            //  Unsupported platform               
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_REMOVE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_REMOVE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_remove_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" path=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, path, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_dir_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dir_selftest (
void)
{
ipr_dir_t
    *dir;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_SELFTEST))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_SELFTEST))
    icl_trace_record (NULL, ipr_dir_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_SELFTEST))
    icl_stats_inc ("ipr_dir_selftest", &s_ipr_dir_selftest_stats);
#endif

//
dir = ipr_dir_new (".", 'n');
ipr_dir_resort (dir, 't');
ipr_dir_resort (dir, 'T');
ipr_dir_resort (dir, 's');
ipr_dir_resort (dir, 'S');
ipr_dir_dump (dir);
ipr_dir_destroy (&dir);

assert (ipr_dir_create ("level1/level2/level3") == 0);
assert (ipr_file_is_directory ("level1/level2/level3"));
assert (ipr_dir_remove ("level1") == 0);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_SELFTEST))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_SELFTEST))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_selftest_finish"
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
    ipr_dir_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dir_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_TERMINATE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_TERMINATE))
    icl_trace_record (NULL, ipr_dir_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_TERMINATE))
    icl_stats_inc ("ipr_dir_terminate", &s_ipr_dir_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_TERMINATE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_TERMINATE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_terminate_finish"
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
    ipr_dir_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dir_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_dir_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_SHOW))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_SHOW))
    icl_trace_record (NULL, ipr_dir_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_SHOW))
    icl_stats_inc ("ipr_dir_show", &s_ipr_dir_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_dir file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_SHOW))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_SHOW))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_show_finish"
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
    ipr_dir_destroy

    Type: Component method
    Destroys a ipr_dir_t object. Takes the address of a
    ipr_dir_t reference (a pointer to a pointer) and nullifies the
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
    ipr_dir_destroy_ (
    ipr_dir_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_dir_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_DESTROY_PUBLIC))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_dir_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_dir_destroy", &s_ipr_dir_destroy_stats);
#endif

if (self) {
    ipr_dir_annihilate (self_p);
    ipr_dir_free ((ipr_dir_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_DESTROY_PUBLIC))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_destroy_public_finish"
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
    ipr_dir_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_dir_t *
    ipr_dir_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_dir_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_ALLOC))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_ALLOC))
    icl_trace_record (NULL, ipr_dir_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_ALLOC))
    icl_stats_inc ("ipr_dir_alloc", &s_ipr_dir_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_dir_cache_initialise ();

self = (ipr_dir_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_dir_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_ALLOC))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_ALLOC))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_alloc_finish"
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
    ipr_dir_free

    Type: Component method
    Freess a ipr_dir_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_dir_free (
    ipr_dir_t * self                    //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_FREE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_FREE))
    icl_trace_record (NULL, ipr_dir_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_FREE))
    icl_stats_inc ("ipr_dir_free", &s_ipr_dir_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (ipr_dir_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_dir_t));
        self->object_tag = IPR_DIR_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_FREE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_FREE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_free_finish"
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
    ipr_dir_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_dir_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_CACHE_INITIALISE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_dir_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CACHE_INITIALISE))
    icl_stats_inc ("ipr_dir_cache_initialise", &s_ipr_dir_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_dir_t));
icl_system_register (ipr_dir_cache_purge, ipr_dir_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_CACHE_INITIALISE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_cache_initialise_finish"
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
    ipr_dir_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dir_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_CACHE_PURGE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CACHE_PURGE))
    icl_trace_record (NULL, ipr_dir_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CACHE_PURGE))
    icl_stats_inc ("ipr_dir_cache_purge", &s_ipr_dir_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CACHE_PURGE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_CACHE_PURGE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_cache_purge_finish"
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
    ipr_dir_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_dir_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_CACHE_TERMINATE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_dir_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_CACHE_TERMINATE))
    icl_stats_inc ("ipr_dir_cache_terminate", &s_ipr_dir_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_CACHE_TERMINATE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_cache_terminate_finish"
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
    ipr_dir_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_dir_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_SHOW_ANIMATION))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_dir_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_SHOW_ANIMATION))
    icl_stats_inc ("ipr_dir_show_animation", &s_ipr_dir_show_animation_stats);
#endif

ipr_dir_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_SHOW_ANIMATION))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_show_animation_finish"
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
    ipr_dir_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_dir_new_in_scope_ (
    ipr_dir_t * * self_p,               //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    char * path,                        //  Directory path to load
    char sortby                         //  Sort key
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_DIR)  ||  defined (BASE_ANIMATE_IPR_DIR_NEW_IN_SCOPE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_dir_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_DIR)  ||  defined (BASE_STATS_IPR_DIR_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_dir_new_in_scope", &s_ipr_dir_new_in_scope_stats);
#endif

*self_p = ipr_dir_new_ (file,line,path,sortby);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_dir_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_dir_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_DIR)   || defined (BASE_ANIMATE_IPR_DIR_NEW_IN_SCOPE))
    if (ipr_dir_animating)
        icl_console_print ("<ipr_dir_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" path=\"%s\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, path, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_DIR)   || defined (BASE_TRACE_IPR_DIR_NEW)   || defined (BASE_TRACE_IPR_DIR_DESTROY)   || defined (BASE_TRACE_IPR_DIR_RESORT)   || defined (BASE_TRACE_IPR_DIR_DUMP)   || defined (BASE_TRACE_IPR_DIR_CREATE)   || defined (BASE_TRACE_IPR_DIR_REMOVE)   || defined (BASE_TRACE_IPR_DIR_SELFTEST)   || defined (BASE_TRACE_IPR_DIR_TERMINATE)   || defined (BASE_TRACE_IPR_DIR_SHOW)   || defined (BASE_TRACE_IPR_DIR_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_DIR_ALLOC)   || defined (BASE_TRACE_IPR_DIR_FREE)   || defined (BASE_TRACE_IPR_DIR_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_DIR_CACHE_PURGE)   || defined (BASE_TRACE_IPR_DIR_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_DIR_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_DIR_NEW_IN_SCOPE) )
void
ipr_dir_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "resort"; break;
        case 4: method_name = "dump"; break;
        case 5: method_name = "create"; break;
        case 6: method_name = "remove"; break;
        case 7: method_name = "selftest"; break;
        case 8: method_name = "terminate"; break;
        case 9: method_name = "show"; break;
        case 10: method_name = "destroy public"; break;
        case 11: method_name = "alloc"; break;
        case 12: method_name = "free"; break;
        case 13: method_name = "cache initialise"; break;
        case 14: method_name = "cache purge"; break;
        case 15: method_name = "cache terminate"; break;
        case 16: method_name = "show animation"; break;
        case 17: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_dir %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Sort by name
static int
s_sort_by_name (const void *info1, const void *info2)
{
    int
        rc;
    ipr_finfo_t
        *finfo1 = *(ipr_finfo_t **) info1,
        *finfo2 = *(ipr_finfo_t **) info2;

#if defined (__WINDOWS__)
    rc = ipr_str_lexcmp (finfo1->name, finfo2->name);
#else
    rc = strcmp (finfo1->name, finfo2->name);
#endif
    return (rc);
}

//  Sort by date/time then name
static int
s_sort_by_time (const void *info1, const void *info2)
{
    int
        rc;
    ipr_finfo_t
        *finfo1 = *(ipr_finfo_t **) info1,
        *finfo2 = *(ipr_finfo_t **) info2;

    if (finfo1->mtime < finfo2->mtime)
        rc = -1;
    else
    if (finfo1->mtime > finfo2->mtime)
        rc = 1;
    else
#if defined (__WINDOWS__)
        rc = ipr_str_lexcmp (finfo1->name, finfo2->name);
#else
        rc = strcmp (finfo1->name, finfo2->name);
#endif
    return (rc);
}

//  Sort by descending date/time, then name
static int
s_sort_by_time_desc (const void *info1, const void *info2)
{
    int
        rc;
    ipr_finfo_t
        *finfo1 = *(ipr_finfo_t **) info1,
        *finfo2 = *(ipr_finfo_t **) info2;

    if (finfo1->mtime < finfo2->mtime)
        rc = 1;
    else
    if (finfo1->mtime > finfo2->mtime)
        rc = -1;
    else
#if defined (__WINDOWS__)
        rc = ipr_str_lexcmp (finfo1->name, finfo2->name);
#else
        rc = strcmp (finfo1->name, finfo2->name);
#endif
    return (rc);
}

//  Sort by size then name
static int
s_sort_by_size (const void *info1, const void *info2)
{
    int
        rc;
    ipr_finfo_t
        *finfo1 = *(ipr_finfo_t **) info1,
        *finfo2 = *(ipr_finfo_t **) info2;

    if (finfo1->size < finfo2->size)
        rc = -1;
    else
    if (finfo1->size > finfo2->size)
        rc = 1;
    else
#if defined (__WINDOWS__)
        rc = ipr_str_lexcmp (finfo1->name, finfo2->name);
#else
        rc = strcmp (finfo1->name, finfo2->name);
#endif
    return (rc);
}

//  Sort by descending size, then name
static int
s_sort_by_size_desc (const void *info1, const void *info2)
{
    int
        rc;
    ipr_finfo_t
        *finfo1 = *(ipr_finfo_t **) info1,
        *finfo2 = *(ipr_finfo_t **) info2;

    if (finfo1->size < finfo2->size)
        rc = 1;
    else
    if (finfo1->size > finfo2->size)
        rc = -1;
    else
#if defined (__WINDOWS__)
        rc = ipr_str_lexcmp (finfo1->name, finfo2->name);
#else
        rc = strcmp (finfo1->name, finfo2->name);
#endif
    return (rc);
}

//  Embed the version information in the resulting binary                      

char *ipr_dir_version_start        = "VeRsIoNsTaRt:ipc";
char *ipr_dir_component            = "ipr_dir ";
char *ipr_dir_version              = "1.0 ";
char *ipr_dir_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_dir_filename             = "ipr_dir.icl ";
char *ipr_dir_builddate            = "2009/02/19 ";
char *ipr_dir_version_end          = "VeRsIoNeNd:ipc";

