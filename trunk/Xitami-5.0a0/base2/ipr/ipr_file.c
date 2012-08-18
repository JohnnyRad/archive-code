/*---------------------------------------------------------------------------
    ipr_file.c - ipr_file component

Provides a general set of file and filename manipulation functions that
return information about a file specified by name. The maximum length of
a filename is set at 255 characters, to fit in an icl_shortstr_t. All
filenames should be defined using this type.
    Generated from ipr_file.icl by icl_gen using GSL/4.
    
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
#include "ipr_file.h"                   //  Definitions for our class

//  Shorthands for class methods                                               

#define self_exists         ipr_file_exists
#define self_size           ipr_file_size
#define self_time           ipr_file_time
#define self_lines          ipr_file_lines
#define self_inode          ipr_file_inode
#define self_slurp          ipr_file_slurp
#define self_where          ipr_file_where
#define self_delete         ipr_file_delete
#define self_rename         ipr_file_rename
#define self_truncate       ipr_file_truncate
#define self_strip_path     ipr_file_strip_path
#define self_set_path       ipr_file_set_path
#define self_set_extension  ipr_file_set_extension
#define self_move           ipr_file_move
#define self_is_readable    ipr_file_is_readable
#define self_is_writeable   ipr_file_is_writeable
#define self_is_directory   ipr_file_is_directory
#define self_get_info       ipr_file_get_info
#define self_digest         ipr_file_digest
#define self_tmpfile        ipr_file_tmpfile
#define self_etag           ipr_file_etag
#define self_selftest       ipr_file_selftest
#define self_show_animation  ipr_file_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_EXISTS))
static icl_stats_t *s_ipr_file_exists_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SIZE))
static icl_stats_t *s_ipr_file_size_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_TIME))
static icl_stats_t *s_ipr_file_time_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_LINES))
static icl_stats_t *s_ipr_file_lines_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_INODE))
static icl_stats_t *s_ipr_file_inode_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SLURP))
static icl_stats_t *s_ipr_file_slurp_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_WHERE))
static icl_stats_t *s_ipr_file_where_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_DELETE))
static icl_stats_t *s_ipr_file_delete_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_RENAME))
static icl_stats_t *s_ipr_file_rename_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_TRUNCATE))
static icl_stats_t *s_ipr_file_truncate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_STRIP_PATH))
static icl_stats_t *s_ipr_file_strip_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SET_PATH))
static icl_stats_t *s_ipr_file_set_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SET_EXTENSION))
static icl_stats_t *s_ipr_file_set_extension_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_MOVE))
static icl_stats_t *s_ipr_file_move_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_IS_READABLE))
static icl_stats_t *s_ipr_file_is_readable_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_IS_WRITEABLE))
static icl_stats_t *s_ipr_file_is_writeable_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_IS_DIRECTORY))
static icl_stats_t *s_ipr_file_is_directory_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_GET_INFO))
static icl_stats_t *s_ipr_file_get_info_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_DIGEST))
static icl_stats_t *s_ipr_file_digest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_TMPFILE))
static icl_stats_t *s_ipr_file_tmpfile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_ETAG))
static icl_stats_t *s_ipr_file_etag_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SELFTEST))
static icl_stats_t *s_ipr_file_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SHOW_ANIMATION))
static icl_stats_t *s_ipr_file_show_animation_stats = NULL;
#endif
Bool
    ipr_file_animating = TRUE;          //  Animation enabled by default
static dbyte s_file_mode        (const char *filename);
#   if (defined (__WINDOWS__))
static Bool s_system_devicename (const char *filename);
static Bool s_dos_exe_file      (const char *filename);
#   endif
/*  -------------------------------------------------------------------------
    ipr_file_exists

    Type: Component method
    Returns TRUE if the specified file exists, else FALSE.
    -------------------------------------------------------------------------
 */

Bool
    ipr_file_exists (
    char * filename                     //  File to examine
)
{
    Bool
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_EXISTS))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_exists_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_EXISTS))
    icl_trace_record (NULL, ipr_file_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_EXISTS))
    icl_stats_inc ("ipr_file_exists", &s_ipr_file_exists_stats);
#endif

//
assert (filename);
rc = s_file_mode (filename) > 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_EXISTS))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_EXISTS))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_exists_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_size

    Type: Component method
    Returns the size, in bytes, of the specified file or directory.
    The size of a directory is not a portable concept. If there is an error,
    returns 0.
    -------------------------------------------------------------------------
 */

int64_t
    ipr_file_size (
    char * filename                     //  File to measure
)
{
ipr_finfo_t
    *finfo = NULL;
    int64_t
        size = 0;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_SIZE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_size_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SIZE))
    icl_trace_record (NULL, ipr_file_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SIZE))
    icl_stats_inc ("ipr_file_size", &s_ipr_file_size_stats);
#endif

    //
    assert (filename);
#   if (defined (__WINDOWS__))
    if (!s_system_devicename (filename))
#   endif
    finfo = ipr_file_get_info (filename);
    if (finfo) {
        size = finfo->size;
        ipr_finfo_destroy (&finfo);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SIZE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_SIZE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_size_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" size=\"%lli\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, size);
#endif


    return (size);
}
/*  -------------------------------------------------------------------------
    ipr_file_time

    Type: Component method
    Returns the modification time of the file, or zero if the file
    is not present or readable.  Returns an apr_time_t in microseconds,
    compatible with APR.
    -------------------------------------------------------------------------
 */

apr_time_t
    ipr_file_time (
    char * filename                     //  File to check
)
{
ipr_finfo_t
    *finfo = NULL;
    apr_time_t
        mtime = 0;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_TIME))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_time_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_TIME))
    icl_trace_record (NULL, ipr_file_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_TIME))
    icl_stats_inc ("ipr_file_time", &s_ipr_file_time_stats);
#endif

    //
    assert (filename);
#   if (defined (__WINDOWS__))
    if (!s_system_devicename (filename))
#   endif
    finfo = ipr_file_get_info (filename);
    if (finfo) {
        mtime = finfo->mtime;
        ipr_finfo_destroy (&finfo);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_TIME))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_TIME))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_time_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif


    return (mtime);
}
/*  -------------------------------------------------------------------------
    ipr_file_lines

    Type: Component method
    Returns the size of the file, in lines, or zero if the file
    is not present or readable.  Reads the entire file, and will
    be slow on large files.  Lines of text that do not end in a
    newline will not be counted.
    -------------------------------------------------------------------------
 */

size_t
    ipr_file_lines (
    char * filename                     //  File to check
)
{
FILE
    *file_stream;
int
    ch;
    size_t
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_LINES))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_lines_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_LINES))
    icl_trace_record (NULL, ipr_file_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_LINES))
    icl_stats_inc ("ipr_file_lines", &s_ipr_file_lines_stats);
#endif

//
assert (filename);
file_stream = fopen (filename, "r");
if (file_stream) {
    while ((ch = fgetc (file_stream)) != EOF)
        if (ch == '\n')
            rc++;
    fclose (file_stream);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_LINES))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_LINES))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_lines_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" rc=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_inode

    Type: Component method
    Returns the inode of the file, or zero if the file is not present or
    readable.  Returns an apr_ino_t compatible with APR.
    -------------------------------------------------------------------------
 */

apr_ino_t
    ipr_file_inode (
    char * filename                     //  File to check
)
{
ipr_finfo_t
    *finfo = NULL;
    apr_ino_t
        inode = 0;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_INODE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_inode_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_INODE))
    icl_trace_record (NULL, ipr_file_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_INODE))
    icl_stats_inc ("ipr_file_inode", &s_ipr_file_inode_stats);
#endif

    //
    assert (filename);
#   if (defined (__WINDOWS__))
    if (!s_system_devicename (filename))
#   endif
    finfo = ipr_file_get_info (filename);
    if (finfo) {
        inode = finfo->inode;
        ipr_finfo_destroy (&finfo);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_INODE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_INODE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_inode_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif


    return (inode);
}
/*  -------------------------------------------------------------------------
    ipr_file_slurp

    Type: Component method
    Reads an entire file, and returns a bucket containing the file
    data.  The file is read as binary data on systems that make such
    distinctions.  Returns NULL if the file cannot be found.  The
    current implementation returns at most one bucket of data from
    the file.
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    ipr_file_slurp (
    char * filename                     //  File to read
)
{
size_t
    file_size;
FILE
    *file_stream = NULL;
    ipr_bucket_t *
        bucket = NULL;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_SLURP))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_slurp_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SLURP))
    icl_trace_record (NULL, ipr_file_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SLURP))
    icl_stats_inc ("ipr_file_slurp", &s_ipr_file_slurp_stats);
#endif

//
assert (filename);
//  Measure amount of data to read
file_size = (size_t) ipr_file_size (filename);
if (file_size >= 0) {
    file_stream = fopen (filename, "rb");
    if (file_size > IPR_BUCKET_MAX_SIZE)
        file_size = IPR_BUCKET_MAX_SIZE;
}
//  Read the data into the bucket
if (file_stream) {
    bucket = ipr_bucket_new (file_size);
    bucket->cur_size = file_size;
    if (fread (bucket->data, (size_t) file_size, 1, file_stream) != 1)
        ipr_bucket_destroy (&bucket);
    fclose (file_stream);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SLURP))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_SLURP))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_slurp_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, bucket);
#endif


    return (bucket);
}
/*  -------------------------------------------------------------------------
    ipr_file_where

    Type: Component method
    Scans a user-specified path symbol for a specific file, and returns a
    fully-specified filename.  If the path is null or empty, it is ignored.
    Otherwise, the path is translated as an environment variable, and cut
    into a list of directory names.  The path is cut up as follows:

        Unix      directory names separated by ':'. :: means current.
        win32     directory names separated by ';'. ;; means current.
        OS/2      directory names separated by ';'. ;; means current.
        VMS       directory names separated by ','. " ", means current.
        Other     single directory name.

    Always searches the current directory before considering the path value.
    When the path cannot be translated, and is not null or empty, it is used
    as a literal value.

    All parameters are case-sensitive; the precise effect of this depends on
    the system.  On win32, filenames are always folded to uppercase, but the
    path must be supplied in uppercase correctly.  On UNIX, all parameters are
    case sensitive.  On VMS, path and filenames are folded into uppercase.

    Under VMS, all filenames are handled in POSIX mode, i.e. /disk/path/file
    instead of $disk:[path]file.

    Returns 0 in case of success, -1 in case the file was not found.
    -------------------------------------------------------------------------
 */

int
    ipr_file_where (
    char * filename,                    //  File to locate
    char * path,                        //  Path to use
    char * fullname                     //  Resulting name
)
{
char
    *pathptr,                       //  End of directory in path
    *charptr;
icl_shortstr_t
    workname;
int
    length;                         //  Length of directory name
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_WHERE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_where_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" path=\"%s\""
" fullname=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, path, fullname);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_WHERE))
    icl_trace_record (NULL, ipr_file_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_WHERE))
    icl_stats_inc ("ipr_file_where", &s_ipr_file_where_stats);
#endif

//
//  Translate path into list of directories
if (path && *path) {
    pathptr = getenv (path);
    if (pathptr == NULL)
        pathptr = path;             //  If not found, use literally
    for (charptr = pathptr; *charptr; charptr++)
        if (*charptr == '\\')
            *charptr = '/';
}
else
    pathptr = NULL;

//  If file exists as defined, prefix with current directory if not an
//  absolute filename, then return the resulting filename
if (strchr (filename, '/')) {
    if (ipr_file_exists (filename))
        icl_shortstr_cpy (fullname, filename);
    else
        rc = -1;                    //  Assume we don't find the file
}
else
if (ipr_file_exists (filename))
    icl_shortstr_fmt (fullname, "./%s", filename);
else {
    rc = -1;                        //  Assume we don't find the file
    while (pathptr && *pathptr) {
        length = strcspn (pathptr, PATHSEP);
        strncpy (workname, pathptr, length);
        pathptr += length;
        if (*pathptr)
            pathptr++;

        //  Add path-to-filename delimiter
        if (length && workname [length - 1] != '/')
            workname [length++] = '/';

        workname [length] = 0;
        icl_shortstr_cat (workname, filename);
        if (ipr_file_exists (workname)) {
            icl_shortstr_cpy (fullname, workname);
            rc = 0;
            break;
        }
    }
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_WHERE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_WHERE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_where_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" path=\"%s\""
" fullname=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, path, fullname, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_delete

    Type: Component method
    Delete specified file, return 0 if ok, else -1.
    -------------------------------------------------------------------------
 */

int
    ipr_file_delete (
    char * filename                     //  File to delete
)
{
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_DELETE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_delete_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_DELETE))
    icl_trace_record (NULL, ipr_file_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_DELETE))
    icl_stats_inc ("ipr_file_delete", &s_ipr_file_delete_stats);
#endif

    //
    assert (filename);
#   if (defined (__WINDOWS__))
    if (s_system_devicename (filename))
        rc = -1;                        //  Not allowed on device names
    else {
        rc = !DeleteFile (filename);
        if (rc && errno == EACCES) {
            //  Under WinNT and Win95, a delete of a freshly-created file can
            //  sometimes fail with a permission error which passes after a
            //  short delay.  Ugly but it seems to work.
            Sleep (100);                //  Win32 milliseconds
            rc = !DeleteFile (filename);
        }
    }
#   elif (defined (__VMS__))
    rc = remove (filename);
#   else
    rc = unlink (filename);
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_DELETE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_DELETE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_delete_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_rename

    Type: Component method
    Rename file as specified, return 0 if ok, else -1.  Will move files
    between directories.  If destination file already exists, it will be
    deleted.
    -------------------------------------------------------------------------
 */

int
    ipr_file_rename (
    char * newname,                     //  Rename file to this
    char * oldname                      //  Actual name of file
)
{
#   if (defined (__WINDOWS__))
    char
        *dos_newname;
#   endif
    int
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_RENAME))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_rename_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" newname=\"%s\""
" oldname=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, newname, oldname);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_RENAME))
    icl_trace_record (NULL, ipr_file_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_RENAME))
    icl_stats_inc ("ipr_file_rename", &s_ipr_file_rename_stats);
#endif

    //
    assert (oldname);
    assert (newname);
#   if (defined (__WINDOWS__))
    if (s_system_devicename (oldname)
    ||  s_system_devicename (newname))
        rc = -1;                        //  Not allowed on device names
    else {
        dos_newname = icl_mem_strdup (newname);
        ipr_str_subch (dos_newname, '/', '\\');
        DeleteFile (dos_newname);
        rc = rename (oldname, dos_newname);
        if (rc && errno == EACCES) {
            /*  Under WinNT and Win95, a rename of a freshly-created file can
             *  sometimes fail with a permission error which passes after a
             *  short delay.  Ugly but it seems to work.
             */
            Sleep (200);
            rc = rename (oldname, dos_newname);
        }
        icl_mem_free (dos_newname);
    }
#   else
    rc = rename (oldname, newname);
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_RENAME))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_RENAME))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_rename_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" newname=\"%s\""
" oldname=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, newname, oldname, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_truncate

    Type: Component method
    Truncate a file: creates or empties the file.
    -------------------------------------------------------------------------
 */

void
    ipr_file_truncate (
    char * filename                     //  File to truncate
)
{
FILE
    *file_stream = NULL;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_TRUNCATE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_truncate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_TRUNCATE))
    icl_trace_record (NULL, ipr_file_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_TRUNCATE))
    icl_stats_inc ("ipr_file_truncate", &s_ipr_file_truncate_stats);
#endif

//
assert (filename);
file_stream = fopen (filename, "wb");
fclose (file_stream);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_TRUNCATE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_TRUNCATE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_truncate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_file_strip_path

    Type: Component method
    Removes the leading path, if any, from the filename.  Returns
    the filename.  The filename can be specified using the local
    operating system syntax.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_strip_path (
    char * filename                     //  Filename to process
)
{
char
    *path_end;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_STRIP_PATH))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_strip_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_STRIP_PATH))
    icl_trace_record (NULL, ipr_file_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_STRIP_PATH))
    icl_stats_inc ("ipr_file_strip_path", &s_ipr_file_strip_path_stats);
#endif

    //
    assert (filename);
    path_end = strrchr (filename, '/');
#   if (defined (__WINDOWS__))
    if (path_end == NULL)
        path_end = strrchr (filename, '\\');
#   endif
    if (path_end)
        memmove (filename, path_end + 1, strlen (path_end));
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_STRIP_PATH))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_STRIP_PATH))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_strip_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif


    return (filename);
}
/*  -------------------------------------------------------------------------
    ipr_file_set_path

    Type: Component method
    Prefixes the filename with the specified path.  Strips any
    existing path from the filename.  Returns filename.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_set_path (
    char * filename,                    //  Filename to process
    char * path                         //  Desired path
)
{
icl_shortstr_t
    formatted;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_SET_PATH))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_set_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SET_PATH))
    icl_trace_record (NULL, ipr_file_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SET_PATH))
    icl_stats_inc ("ipr_file_set_path", &s_ipr_file_set_path_stats);
#endif

    //
    assert (filename);
    assert (path);

    ipr_file_strip_path (filename);
    icl_shortstr_cpy (formatted, path);
#   if (defined (__WINDOWS__))
    if (strlast (path) != '/' && strlast (path) != '\\')
#   else
    if (strlast (path) != '/')
#   endif
        icl_shortstr_cat (formatted, "/");

    icl_shortstr_cat (formatted, filename);
    icl_shortstr_cpy (filename, formatted);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SET_PATH))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_SET_PATH))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_set_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, path);
#endif


    return (filename);
}
/*  -------------------------------------------------------------------------
    ipr_file_set_extension

    Type: Component method
    Adds extension to filename if it does not already have an
    extension.  Returns filename.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_set_extension (
    char * filename,                    //  Filename to process
    char * extension                    //  Extension to add
)
{
char
    *terminal;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_SET_EXTENSION))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_set_extension_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" extension=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, extension);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SET_EXTENSION))
    icl_trace_record (NULL, ipr_file_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SET_EXTENSION))
    icl_stats_inc ("ipr_file_set_extension", &s_ipr_file_set_extension_stats);
#endif

    assert (filename);
    assert (extension);

    for (terminal = filename + strlen (filename); terminal > filename; terminal--)
#   if (defined (__WINDOWS__))
        if (*terminal == '.' || *terminal == '/' || *terminal == '\\')
            break;
#   else
        if (*terminal == '.' || *terminal == '/')
            break;
#   endif
    if (*terminal != '.') {
        if (*extension == '.')
            extension++;
        icl_shortstr_cat (terminal, ".");
        icl_shortstr_cat (terminal, extension);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SET_EXTENSION))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_SET_EXTENSION))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_set_extension_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" extension=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, extension);
#endif


    return (filename);
}
/*  -------------------------------------------------------------------------
    ipr_file_move

    Type: Component method
    Moves a file to a specific directory.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_move (
    char * directory,                   //  Desired directory path
    char * filename                     //  Filename to process
)
{
icl_shortstr_t
    destination;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_MOVE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_move_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" directory=\"%s\""
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, directory, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_MOVE))
    icl_trace_record (NULL, ipr_file_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_MOVE))
    icl_stats_inc ("ipr_file_move", &s_ipr_file_move_stats);
#endif

//
assert (directory);
assert (filename);

icl_shortstr_cpy  (destination, filename);
ipr_file_set_path (destination, directory);
ipr_file_rename   (destination, filename);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_MOVE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_MOVE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_move_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" directory=\"%s\""
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, directory, filename);
#endif


    return (filename);
}
/*  -------------------------------------------------------------------------
    ipr_file_is_readable

    Type: Component method
    Returns TRUE if the current process can read the specified
    file or directory.  The filename may end in a slash (/ or ) only if
    it is a directory.
    -------------------------------------------------------------------------
 */

Bool
    ipr_file_is_readable (
    char * filename                     //  File to examine
)
{
    Bool
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_IS_READABLE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_is_readable_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_IS_READABLE))
    icl_trace_record (NULL, ipr_file_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_IS_READABLE))
    icl_stats_inc ("ipr_file_is_readable", &s_ipr_file_is_readable_stats);
#endif

//
assert (filename);
if (ipr_file_is_directory (filename))
    rc = ((s_file_mode (filename) & S_IREAD) != 0);
else
if (strlast (filename) == '/')
    rc = FALSE;
else
    rc = ((s_file_mode (filename) & S_IREAD) != 0);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_IS_READABLE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_IS_READABLE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_is_readable_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_is_writeable

    Type: Component method
    Returns TRUE if the current process can write the specified file or
    directory.  The filename may end in a slash (/ or ) only if it is
    a directory.
    -------------------------------------------------------------------------
 */

Bool
    ipr_file_is_writeable (
    char * filename                     //  File to examine
)
{
    Bool
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_IS_WRITEABLE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_is_writeable_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_IS_WRITEABLE))
    icl_trace_record (NULL, ipr_file_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_IS_WRITEABLE))
    icl_stats_inc ("ipr_file_is_writeable", &s_ipr_file_is_writeable_stats);
#endif

//
assert (filename);
if (ipr_file_is_directory (filename))
    rc = ((s_file_mode (filename) & S_IWRITE) != 0);
else
if (strlast (filename) == '/')
    rc = FALSE;
else
    rc = ((s_file_mode (filename) & S_IWRITE) != 0);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_IS_WRITEABLE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_IS_WRITEABLE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_is_writeable_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_is_directory

    Type: Component method
    Returns TRUE if the specified file is a directory.  The
    filename may end in a slash (/ or ).   Under MS-DOS/OS2/Windows, a
    directory name may consist solely of a disk-drive specifier.  Under
    VMS the directory may optionally take the extension '.dir'.
    -------------------------------------------------------------------------
 */

Bool
    ipr_file_is_directory (
    char * filename                     //  File to examine
)
{
icl_shortstr_t
    dir_name;
    Bool
        rc = 0;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_IS_DIRECTORY))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_is_directory_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_IS_DIRECTORY))
    icl_trace_record (NULL, ipr_file_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_IS_DIRECTORY))
    icl_stats_inc ("ipr_file_is_directory", &s_ipr_file_is_directory_stats);
#endif

    assert (filename);

    //TODO when ipr_dir_clean_path is implemented
    //dir_name = mem_strdup (clean_path (filename));
    icl_shortstr_cpy (dir_name, filename);
#   if (defined (__VMS__))
    if (!ipr_file_exists (dir_name))
        ipr_file_set_extension (dir_name, "dir");
#   endif
    rc = (s_file_mode (dir_name) & S_IFDIR) != 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_IS_DIRECTORY))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_IS_DIRECTORY))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_is_directory_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_file_get_info

    Type: Component method
    Returns a finfo block containing file information in APR-compatible
    formats.  Returns NULL if the file was not readable.
    -------------------------------------------------------------------------
 */

ipr_finfo_t *
    ipr_file_get_info (
    char * filename                     //  File to examine
)
{
apr_pool_t
    *pool;                          //  Pool for all allocations
apr_file_t
    *handle;
apr_finfo_t
    apr_finfo;
    ipr_finfo_t *
        finfo = NULL;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_GET_INFO))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_get_info_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_GET_INFO))
    icl_trace_record (NULL, ipr_file_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_GET_INFO))
    icl_stats_inc ("ipr_file_get_info", &s_ipr_file_get_info_stats);
#endif

//
assert (filename);
apr_pool_create (&pool, NULL);
if (!apr_file_open (&handle, filename, APR_READ, APR_OS_DEFAULT, pool)) {
    memset (&apr_finfo, 0, sizeof (apr_finfo_t));
    apr_file_info_get (&apr_finfo, APR_FINFO_NORM, handle);
    finfo = ipr_finfo_new (&apr_finfo);
    apr_file_close (handle);
}
apr_pool_destroy (pool);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_GET_INFO))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_GET_INFO))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_get_info_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" finfo=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, finfo);
#endif


    return (finfo);
}
/*  -------------------------------------------------------------------------
    ipr_file_digest

    Type: Component method
    Calculates the digest (currently SHA1) of a file, and returns this
    as a printable hex string.  The returned string must be freed by
    the caller.  If the file could not be read, returns NULL.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_digest (
    char * filename                     //  File to digest
)
{
FILE
    *file_stream;                   //  File stream to digest
ipr_bucket_t
    *bucket;                        //  Bucket of data from file
apr_sha1_ctx_t
    context;
apr_byte_t
    bin_digest [APR_SHA1_DIGESTSIZE];
    char *
        digest = NULL;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_DIGEST))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_digest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_DIGEST))
    icl_trace_record (NULL, ipr_file_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_DIGEST))
    icl_stats_inc ("ipr_file_digest", &s_ipr_file_digest_stats);
#endif

    //
    assert (filename);
#   define DIGEST_BLOCK 1000000         //  Read 1MB at a time from file
    file_stream = fopen (filename, "rb");
    if (file_stream) {
        apr_sha1_init (&context);
        bucket = ipr_bucket_new (DIGEST_BLOCK);
        while ((bucket->cur_size = fread (bucket->data, 1, DIGEST_BLOCK, file_stream)) > 0)
            apr_sha1_update (&context, (char *) bucket->data, bucket->cur_size);
        fclose (file_stream);
        ipr_bucket_destroy (&bucket);

        apr_sha1_final (bin_digest, &context);
        digest = icl_mem_alloc (ICL_SHORTSTR_MAX);
        apr_base64_encode (digest, (char *) bin_digest, APR_MD5_DIGESTSIZE);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_DIGEST))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_DIGEST))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_digest_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" digest=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, digest);
#endif


    return (digest);
}
/*  -------------------------------------------------------------------------
    ipr_file_tmpfile

    Type: Component method
    Generates a temporary file name.  The caller must free the returned name
    when finished with it.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_tmpfile (
void)
{
    char *
        filename;                       //  Filename to generate

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_TMPFILE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_tmpfile_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_TMPFILE))
    icl_trace_record (NULL, ipr_file_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_TMPFILE))
    icl_stats_inc ("ipr_file_tmpfile", &s_ipr_file_tmpfile_stats);
#endif

//
filename = icl_mem_alloc (4 + 10 + 1);      //  tmp_ + 10-digit random + 0
ipr_str_random (filename, "tmp_Ax10");
while (ipr_file_exists (filename))
    ipr_str_random (filename, "tmp_Ax10");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_TMPFILE))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_TMPFILE))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_tmpfile_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif


    return (filename);
}
/*  -------------------------------------------------------------------------
    ipr_file_etag

    Type: Component method
    Generates an entity tag (ETag) for the file.  The type argument can be
    'fixed', which generates an ETag of the file's modified time, size, and
    inode, or 'float', which generates an ETag of the file's modified time
    and size.  A floating ETag is file system independent, so gives the same
    ETag for the same file in different locations.  A fixed ETag includes the
    location (inode on the file system).  If the type is not 'fixed' or 'float'
    the resulting ETag is empty.
    -------------------------------------------------------------------------
 */

char *
    ipr_file_etag (
    char * filename,                    //  File to digest
    char * type                         //  ETag type: fixed, float
)
{
ipr_finfo_t
    *finfo = NULL;
    char *
        etag = NULL;                    //  ETag to generate

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_ETAG))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_etag_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" type=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, type);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_ETAG))
    icl_trace_record (NULL, ipr_file_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_ETAG))
    icl_stats_inc ("ipr_file_etag", &s_ipr_file_etag_stats);
#endif

    //
    assert (filename);
#   if (defined (__WINDOWS__))
    if (!s_system_devicename (filename))
#   endif
    finfo = ipr_file_get_info (filename);
    if (finfo) {
        if (streq (type, "fixed"))
            etag = ipr_str_format ("%qx-%qx-%lx",
                (long long unsigned int) finfo->mtime,
                (long long unsigned int) finfo->size,
                finfo->inode);
        else
        if (streq (type, "float"))
            etag = ipr_str_format ("%qx-%qx",
                (long long unsigned int) finfo->mtime,
                (long long unsigned int) finfo->size);
        else
            etag = icl_mem_strdup ("");

        ipr_finfo_destroy (&finfo);
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_ETAG))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_ETAG))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_etag_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" type=\"%s\""
" etag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, type, etag);
#endif


    return (etag);
}
/*  -------------------------------------------------------------------------
    ipr_file_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_file_selftest (
void)
{
#   define TEST_FILE  "ipr_file.icl"
    ipr_bucket_t
        *bucket;
    icl_shortstr_t
        fullname;
    char
        *tmpname,
        *digest,
        *etag;
    int
        rc;
    FILE
        *file;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_SELFTEST))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SELFTEST))
    icl_trace_record (NULL, ipr_file_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SELFTEST))
    icl_stats_inc ("ipr_file_selftest", &s_ipr_file_selftest_stats);
#endif

//  Some basic methods on files
assert (ipr_file_is_directory ("."));

//  Check that we can get the properties for a file
assert (ipr_file_lines (TEST_FILE));
assert (ipr_file_time  (TEST_FILE));
assert (ipr_file_size  (TEST_FILE));
assert (ipr_file_inode (TEST_FILE));

//  Check we can slurp the file
bucket = ipr_file_slurp (TEST_FILE);
assert (bucket);
assert (bucket->cur_size == (size_t) ipr_file_size (TEST_FILE));
ipr_bucket_destroy (&bucket);

//  Test the ipr_file_strip_path method
icl_shortstr_cpy (fullname, "/some/path/filename");
ipr_file_strip_path (fullname);
assert (streq (fullname, "filename"));

icl_shortstr_cpy (fullname, "/filename");
ipr_file_strip_path (fullname);
assert (streq (fullname, "filename"));

icl_shortstr_cpy (fullname, "filename");
ipr_file_strip_path (fullname);
assert (streq (fullname, "filename"));

icl_shortstr_cpy (fullname, "/");
ipr_file_strip_path (fullname);
assert (streq (fullname, ""));

//  Test the ipr_file_set_path method
icl_shortstr_cpy (fullname, "/some/path/filename");
ipr_file_set_path (fullname, "/new");
assert (streq (fullname, "/new/filename"));

icl_shortstr_cpy (fullname, "/filename");
ipr_file_set_path (fullname, "/new");
assert (streq (fullname, "/new/filename"));

icl_shortstr_cpy (fullname, "filename");
ipr_file_set_path (fullname, "/new");
assert (streq (fullname, "/new/filename"));

icl_shortstr_cpy (fullname, "/");
ipr_file_set_path (fullname, "/new");
assert (streq (fullname, "/new/"));

//  Test the ipr_file_set_extension method
icl_shortstr_cpy (fullname, "/some/path/filename");
ipr_file_set_extension (fullname, ".log");
assert (streq (fullname, "/some/path/filename.log"));

icl_shortstr_cpy (fullname, "/some/path.dir/filename");
ipr_file_set_extension (fullname, ".log");
assert (streq (fullname, "/some/path.dir/filename.log"));

icl_shortstr_cpy (fullname, "filename");
ipr_file_set_extension (fullname, ".log");
assert (streq (fullname, "filename.log"));

icl_shortstr_cpy (fullname, "/some/path/filename.zzz");
ipr_file_set_extension (fullname, ".log");
assert (streq (fullname, "/some/path/filename.zzz"));

icl_shortstr_cpy (fullname, "/some/path.dir/filename.zzz");
ipr_file_set_extension (fullname, ".log");
assert (streq (fullname, "/some/path.dir/filename.zzz"));

icl_shortstr_cpy (fullname, "filename.zzz");
ipr_file_set_extension (fullname, ".log");
assert (streq (fullname, "filename.zzz"));

//  Look for something well-known on the path
rc = ipr_file_where (TEST_FILE, "PATH", fullname);
assert (rc == 0);

file = fopen ("testdata1", "w");
assert (file);
fprintf (file, "test data 1\n");
fclose (file);
assert (ipr_file_lines ("testdata1") == 1);

file = fopen ("testdata2", "w");
assert (file);
fprintf (file, "test data 21\n");
fprintf (file, "test data 22\n");
fclose (file);
assert (ipr_file_lines ("testdata2") == 2);

ipr_file_rename ("testdata1", "testdata2");
assert (ipr_file_exists ("testdata1"));
assert (ipr_file_exists ("testdata2") == FALSE);
assert (ipr_file_lines ("testdata1") == 2);

ipr_file_delete ("testdata1");
assert (ipr_file_exists ("testdata2") == FALSE);

tmpname = ipr_file_tmpfile ();
assert (!ipr_file_exists (tmpname));
icl_mem_free (tmpname);

//  Digest method
digest = ipr_file_digest (fullname);
assert (digest);
icl_mem_free (digest);

//  ETag calculation
etag = ipr_file_etag (fullname, "fixed");
assert (strlen (etag) > 17);
icl_mem_free (etag);

etag = ipr_file_etag (fullname, "float");
assert (strlen (etag) > 15);
icl_mem_free (etag);

etag = ipr_file_etag (fullname, "other");
assert (strlen (etag) == 0);
icl_mem_free (etag);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SELFTEST))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_SELFTEST))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_selftest_finish"
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
    ipr_file_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_file_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_FILE)  ||  defined (BASE_ANIMATE_IPR_FILE_SHOW_ANIMATION))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_file_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_FILE)  ||  defined (BASE_STATS_IPR_FILE_SHOW_ANIMATION))
    icl_stats_inc ("ipr_file_show_animation", &s_ipr_file_show_animation_stats);
#endif

ipr_file_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_file_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_FILE)   || defined (BASE_ANIMATE_IPR_FILE_SHOW_ANIMATION))
    if (ipr_file_animating)
        icl_console_print ("<ipr_file_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_FILE)   || defined (BASE_TRACE_IPR_FILE_EXISTS)   || defined (BASE_TRACE_IPR_FILE_SIZE)   || defined (BASE_TRACE_IPR_FILE_TIME)   || defined (BASE_TRACE_IPR_FILE_LINES)   || defined (BASE_TRACE_IPR_FILE_INODE)   || defined (BASE_TRACE_IPR_FILE_SLURP)   || defined (BASE_TRACE_IPR_FILE_WHERE)   || defined (BASE_TRACE_IPR_FILE_DELETE)   || defined (BASE_TRACE_IPR_FILE_RENAME)   || defined (BASE_TRACE_IPR_FILE_TRUNCATE)   || defined (BASE_TRACE_IPR_FILE_STRIP_PATH)   || defined (BASE_TRACE_IPR_FILE_SET_PATH)   || defined (BASE_TRACE_IPR_FILE_SET_EXTENSION)   || defined (BASE_TRACE_IPR_FILE_MOVE)   || defined (BASE_TRACE_IPR_FILE_IS_READABLE)   || defined (BASE_TRACE_IPR_FILE_IS_WRITEABLE)   || defined (BASE_TRACE_IPR_FILE_IS_DIRECTORY)   || defined (BASE_TRACE_IPR_FILE_GET_INFO)   || defined (BASE_TRACE_IPR_FILE_DIGEST)   || defined (BASE_TRACE_IPR_FILE_TMPFILE)   || defined (BASE_TRACE_IPR_FILE_ETAG)   || defined (BASE_TRACE_IPR_FILE_SELFTEST)   || defined (BASE_TRACE_IPR_FILE_SHOW_ANIMATION) )
void
ipr_file_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "exists"; break;
        case 2: method_name = "size"; break;
        case 3: method_name = "time"; break;
        case 4: method_name = "lines"; break;
        case 5: method_name = "inode"; break;
        case 6: method_name = "slurp"; break;
        case 7: method_name = "where"; break;
        case 8: method_name = "delete"; break;
        case 9: method_name = "rename"; break;
        case 10: method_name = "truncate"; break;
        case 11: method_name = "strip path"; break;
        case 12: method_name = "set path"; break;
        case 13: method_name = "set extension"; break;
        case 14: method_name = "move"; break;
        case 15: method_name = "is readable"; break;
        case 16: method_name = "is writeable"; break;
        case 17: method_name = "is directory"; break;
        case 18: method_name = "get info"; break;
        case 19: method_name = "digest"; break;
        case 20: method_name = "tmpfile"; break;
        case 21: method_name = "etag"; break;
        case 22: method_name = "selftest"; break;
        case 23: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_file %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

/*  -------------------------------------------------------------------------
 *  s_file_mode
 *
 *  Returns the file mode for the specified file or directory name; returns
 *  0 if the specified file does not exist.
 */

static dbyte
s_file_mode (const char *filename)
{
#   if (defined (__WINDOWS__))
    DWORD
        dwfa;
    dbyte
        mode;

    assert (filename);
    if (s_system_devicename (filename))
        return (0);                     //  Not allowed on device names

    dwfa = GetFileAttributes (filename);
    if (dwfa == 0xffffffff)
        return (0);
    mode = 0;

    if (dwfa & FILE_ATTRIBUTE_DIRECTORY)
        mode |= S_IFDIR;
    else
        mode |= S_IFREG;
    if (!(dwfa & FILE_ATTRIBUTE_HIDDEN))
        mode |= S_IREAD;
    if (!(dwfa & FILE_ATTRIBUTE_READONLY))
        mode |= S_IWRITE;
    if (s_dos_exe_file (filename))
        mode |= S_IEXEC;
    return (mode);
#   else
    static struct stat
        stat_buf;

    assert (filename);
    if (strnull (filename))
        return (0);
    else
    if (stat ((char *) filename, &stat_buf) == 0)
        return ((dbyte) stat_buf.st_mode);
    else
        return (0);
#   endif
}

#   if (defined (__WINDOWS__))
static Bool
s_system_devicename (const char *supplied_filename)
{
    //  Under Win32 we can open the file, and ask what type it is; if it is
    //  not a disk file we reject it.  If we can't open it, we indicate that
    //  it is safe, so that the open will be retried and the correct error
    //  codes set for the caller.
    HANDLE
        fh;
    Bool
        is_devicefile = TRUE;

    fh = CreateFile (
        supplied_filename, GENERIC_READ, FILE_SHARE_READ, NULL,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (fh != INVALID_HANDLE_VALUE) {
        if (GetFileType(fh) == FILE_TYPE_DISK)
            is_devicefile = FALSE;
        CloseHandle(fh);
    }
    else
        is_devicefile = FALSE;          // Doesn't exist

    return (is_devicefile);
}

/*  s_dos_exe_file -- internal
 *
 *  Returns TRUE if the file corresponds to the criteria for an executable
 *  file under Windows.
 */
static Bool
s_dos_exe_file (const char *filename)
{
    Bool
        executable;                     //  Return code
    FILE
        *stream;                        //  Opened file stream

    stream = fopen (filename, "r");
    if (stream) {
        executable = (fgetc (stream) == 'M' && fgetc (stream) == 'Z');
        fclose (stream);
    }
    else
        executable = FALSE;             //  File not found

    return (executable);
}
#   endif

//  Embed the version information in the resulting binary                      

char *ipr_file_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_file_component           = "ipr_file ";
char *ipr_file_version             = "1.0 ";
char *ipr_file_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_file_filename            = "ipr_file.icl ";
char *ipr_file_builddate           = "2009/02/19 ";
char *ipr_file_version_end         = "VeRsIoNeNd:ipc";

