/*---------------------------------------------------------------------------
    http_response.c - http_response component

    This class holds properties and methods for representing an HTTP
    response and turning it into HTML to send back to the client.  The
    response is the primary object exchanged between all components,
    and it holds references to all other key objects.
    Generated from http_response.icl by icl_gen using GSL/4.
    
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
#include "http_response.h"              //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_response_t

//  Shorthands for class methods                                               

#define self_new            http_response_new
#define self_annihilate     http_response_annihilate
#define self_set_header     http_response_set_header
#define self_set_from_file  http_response_set_from_file
#define self_set_from_bucket  http_response_set_from_bucket
#define self_set_from_xml_str  http_response_set_from_xml_str
#define self_set_no_cache   http_response_set_no_cache
#define self_set_redirect   http_response_set_redirect
#define self_set_error      http_response_set_error
#define self_format_reply   http_response_format_reply
#define self_selftest       http_response_selftest
#define self_terminate      http_response_terminate
#define self_show           http_response_show
#define self_destroy        http_response_destroy
#define self_alloc          http_response_alloc
#define self_free           http_response_free
#define self_link           http_response_link
#define self_unlink         http_response_unlink
#define self_cache_initialise  http_response_cache_initialise
#define self_cache_purge    http_response_cache_purge
#define self_cache_terminate  http_response_cache_terminate
#define self_show_animation  http_response_show_animation
#define self_new_in_scope   http_response_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_NEW))
static icl_stats_t *s_http_response_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_DESTROY))
static icl_stats_t *s_http_response_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_HEADER))
static icl_stats_t *s_http_response_set_header_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_FROM_FILE))
static icl_stats_t *s_http_response_set_from_file_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_FROM_BUCKET))
static icl_stats_t *s_http_response_set_from_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_FROM_XML_STR))
static icl_stats_t *s_http_response_set_from_xml_str_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_NO_CACHE))
static icl_stats_t *s_http_response_set_no_cache_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_REDIRECT))
static icl_stats_t *s_http_response_set_redirect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_ERROR))
static icl_stats_t *s_http_response_set_error_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_FORMAT_REPLY))
static icl_stats_t *s_http_response_format_reply_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SELFTEST))
static icl_stats_t *s_http_response_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_TERMINATE))
static icl_stats_t *s_http_response_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SHOW))
static icl_stats_t *s_http_response_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_DESTROY_PUBLIC))
static icl_stats_t *s_http_response_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_ALLOC))
static icl_stats_t *s_http_response_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_FREE))
static icl_stats_t *s_http_response_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_LINK))
static icl_stats_t *s_http_response_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_UNLINK))
static icl_stats_t *s_http_response_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_CACHE_INITIALISE))
static icl_stats_t *s_http_response_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_CACHE_PURGE))
static icl_stats_t *s_http_response_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_CACHE_TERMINATE))
static icl_stats_t *s_http_response_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SHOW_ANIMATION))
static icl_stats_t *s_http_response_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_NEW_IN_SCOPE))
static icl_stats_t *s_http_response_new_in_scope_stats = NULL;
#endif
#define http_response_annihilate(self)  http_response_annihilate_ (self, __FILE__, __LINE__)
static void
    http_response_annihilate_ (
http_response_t * ( * self_p ),         //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_response_alloc()           http_response_alloc_ (__FILE__, __LINE__)
static http_response_t *
    http_response_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define http_response_free(self)        http_response_free_ (self, __FILE__, __LINE__)
static void
    http_response_free_ (
http_response_t * self,                 //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    http_response_cache_initialise (
void);

static void
    http_response_cache_purge (
void);

static void
    http_response_cache_terminate (
void);

Bool
    http_response_animating = TRUE;     //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


//  Insert URI
//  TODO: abstract this into an HTML-production class
#define ERROR_HEADER_1 \
    "[!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"\n" \
    "    \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\"]\n" \
    "[html]\n" \
    "[head]\n" \
    "  [title]Error[/title]\n" \
    "  [style type=\"text/css\"]\\n" \
    ""
#define ERROR_HEADER_2 \
    "  [/style]\n" \
    "  [link rel=\"stylesheet\" href=\"/http.css\" type=\"text/css\"/]\n" \
    "[/head]\n" \
    "[body]\n" \
    "  [div id=\"error_head\"]\n" \
    "    "
#define ERROR_HEADER_3  \
    "\n" \
    "  [/div]\n" \
    "  [div id=\"error_text\"]\n" \
    "    "
#define ERROR_FOOTER \
    "\n" \
    "  [/div]\n" \
    "  [div id=\"footer\"]Powered by X5[/div]\n" \
    "[/body]\n" \
    "[/html]\n" \
    ""

static void
    s_format_root_uri (http_response_t *self);
static void
    s_format_error_page (http_response_t *self);
/*  -------------------------------------------------------------------------
    http_response_new

    Type: Component method
    Creates and initialises a new http_response_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

http_response_t *
    http_response_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    http_server_t * server,             //  Parent server
    http_request_t * request            //  Request context
)
{
    http_response_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_NEW))
    if (http_response_animating)
        icl_console_print ("<http_response_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_NEW))
    icl_trace_record (NULL, http_response_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_NEW))
    icl_stats_inc ("http_response_new", &s_http_response_new_stats);
#endif

    self = http_response_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_RESPONSE_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, http_response_show_);
#endif

//
self->server = http_server_link (server);
self->request = http_request_link (request);
self->reply_code = http_request_parse (self->request);
self->headers = ipr_dict_table_new ();
self->bucket_list = ipr_bucket_list_new ();
s_format_root_uri (self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_NEW))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_NEW))
    if (http_response_animating)
        icl_console_print ("<http_response_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
" request=\"%pp\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, server, request, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    http_response_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_response_annihilate_ (
    http_response_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    int
        history_last;
#endif

    http_response_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_DESTROY))
    if (http_response_animating)
        icl_console_print ("<http_response_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_DESTROY))
    icl_trace_record (NULL, http_response_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_DESTROY))
    icl_stats_inc ("http_response_annihilate", &s_http_response_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = file;
    self->history_line  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = line;
    self->history_type  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = self->links;
#endif

    HTTP_RESPONSE_ASSERT_SANE (self);

http_server_unlink (&self->server);
http_request_unlink (&self->request);
ipr_bucket_list_destroy (&self->bucket_list);
ipr_dict_table_destroy (&self->headers);
icl_mem_strfree (&self->filename);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_DESTROY))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_DESTROY))
    if (http_response_animating)
        icl_console_print ("<http_response_destroy_finish"
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
    http_response_set_header

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the value of a specified header in the HTTP response. The header value
    is a printf format, followed by insertion arguments.
    -------------------------------------------------------------------------
 */

int
    http_response_set_header (
    http_response_t * self,             //  Reference to object
    char * header_name,                 //  Name of header, case insensitive
    char * format,                      //  Format specifier
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, format);
    _rc = http_response_set_header_v (self, header_name, format, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    http_response_set_header_v

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the value of a specified header in the HTTP response. The header value
    is a printf format, followed by insertion arguments.
    -------------------------------------------------------------------------
 */

int
    http_response_set_header_v (
    http_response_t * self,             //  Reference to object
    char * header_name,                 //  Name of header, case insensitive
    char * format,                      //  Format specifier
va_list args                            //  Variable arguments
)
{
char
    *string;                        //  Holds formatted value
int
    str_size = 1024,
    fmt_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_HEADER))
    if (http_response_animating)
        icl_console_print ("<http_response_set_header_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" header_name=\"%s\""
" format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, header_name, format);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_HEADER))
    icl_trace_record (NULL, http_response_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_HEADER))
    icl_stats_inc ("http_response_set_header", &s_http_response_set_header_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Format a string with the value
string = icl_mem_alloc (str_size + 1);
fmt_size = apr_vsnprintf (string, str_size, format, args);
if (fmt_size >= str_size) {
    //  If formatted value overflowed string, resize and repeat
    icl_mem_free (string);
    str_size = fmt_size;
    string = icl_mem_alloc (str_size + 1);
    fmt_size = apr_vsnprintf (string, str_size, format, args);
}
ipr_dict_assume (self->headers, header_name, string);
icl_mem_free (string);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_HEADER))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_HEADER))
    if (http_response_animating)
        icl_console_print ("<http_response_set_header_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" header_name=\"%s\""
" format=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, header_name, format, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_response_set_from_file

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the response to send the file headers back to the browser.  Sets the
    content length, modified date, ETag and content type from the file info.
    For GET methods, prepares to return the file content.
    -------------------------------------------------------------------------
 */

int
    http_response_set_from_file (
    http_response_t * self,             //  Reference to object
    char * filename                     //  File to send
)
{
ipr_finfo_t
    *finfo;
icl_shortstr_t
    mime_date;
ipr_dict_t
    *content_type;
char
    *etag = NULL,                   //  Calculated ETag, if any
    *extension;                     //  File extension, if any
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_FROM_FILE))
    if (http_response_animating)
        icl_console_print ("<http_response_set_from_file_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_FILE))
    icl_trace_record (NULL, http_response_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_FROM_FILE))
    icl_stats_inc ("http_response_set_from_file", &s_http_response_set_from_file_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Set response to return file content iff method is GET
icl_mem_strfree (&self->filename);
if (self->request->method == HTTP_METHOD_GET)
    self->filename = icl_mem_strdup (filename);

//  Calculate Content-Length: and Last-Modified: headers
finfo = ipr_file_get_info (filename);
self->content_length = (size_t) finfo->size;
ipr_time_mime (finfo->mtime, mime_date);
self_set_header (self, "last-modified", mime_date);

//  Calculate ETag: header
etag = ipr_file_etag (filename, http_config_etag (http_config));
self_set_header (self, "etag", etag);
icl_mem_free (etag);

//  Calculate Content-type header from file extension
extension = strchr (filename, '.');
if (!extension)
    extension = "default";
content_type = ipr_dict_table_search (self->server->content_types, extension);
if (content_type)
    self_set_header (self, "content-type", content_type->value);
else
    self_set_header (self, "content-type", "*/*");

ipr_finfo_destroy (&finfo);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_FILE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_FROM_FILE))
    if (http_response_animating)
        icl_console_print ("<http_response_set_from_file_finish"
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
    http_response_set_from_bucket

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the response to send a bucket back to the browser. Updates the content
    length from the bucket and the content type if not null. If you send back
    multiple buckets, the last content type you specify will be used.
    -------------------------------------------------------------------------
 */

int
    http_response_set_from_bucket (
    http_response_t * self,             //  Reference to object
    ipr_bucket_t * bucket,              //  Bucket to return
    char * content_type                 //  Content type
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_FROM_BUCKET))
    if (http_response_animating)
        icl_console_print ("<http_response_set_from_bucket_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" content_type=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, content_type);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_BUCKET))
    icl_trace_record (NULL, http_response_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_FROM_BUCKET))
    icl_stats_inc ("http_response_set_from_bucket", &s_http_response_set_from_bucket_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
ipr_bucket_list_queue (self->bucket_list, bucket);
self->bucket_list->cur_size += bucket->cur_size;
self->content_length = (size_t) self->bucket_list->cur_size;
if (content_type)
    self_set_header (self, "content-type", content_type);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_BUCKET))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_FROM_BUCKET))
    if (http_response_animating)
        icl_console_print ("<http_response_set_from_bucket_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket=\"%pp\""
" content_type=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket, content_type, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_response_set_from_xml_str

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the response to send an XML string back to the browser.  To make it
    easier to code, the string uses [ and ] instead of lt and gt.  Sets the
    content length and content type to text/xml.  Automatically prefixes the
    XML string with an ?xml tag.
    -------------------------------------------------------------------------
 */

int
    http_response_set_from_xml_str (
    http_response_t * self,             //  Reference to object
    char * xml_string                   //  XML to return
)
{
ipr_bucket_t
    *bucket;                        //  Serialized XML
char
    *xml_tag = "[?xml version=\"1.0\"?]";
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_FROM_XML_STR))
    if (http_response_animating)
        icl_console_print ("<http_response_set_from_xml_str_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_string=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_string);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_XML_STR))
    icl_trace_record (NULL, http_response_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_FROM_XML_STR))
    icl_stats_inc ("http_response_set_from_xml_str", &s_http_response_set_from_xml_str_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
bucket = ipr_bucket_new (strlen (xml_tag) + strlen (xml_string) + 1);
ipr_bucket_cat (bucket, xml_tag, strlen (xml_tag));
ipr_bucket_cat (bucket, xml_string, strlen (xml_string) + 1);
ipr_str_subch ((char *) bucket->data, '[', '<');
ipr_str_subch ((char *) bucket->data, ']', '>');
http_response_set_from_bucket (self, bucket, "text/xml");
ipr_bucket_unlink (&bucket);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_XML_STR))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_FROM_XML_STR))
    if (http_response_animating)
        icl_console_print ("<http_response_set_from_xml_str_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" xml_string=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, xml_string, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_response_set_no_cache

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the response so that the browser does not cache the URI.
    -------------------------------------------------------------------------
 */

int
    http_response_set_no_cache (
    http_response_t * self              //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_NO_CACHE))
    if (http_response_animating)
        icl_console_print ("<http_response_set_no_cache_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_NO_CACHE))
    icl_trace_record (NULL, http_response_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_NO_CACHE))
    icl_stats_inc ("http_response_set_no_cache", &s_http_response_set_no_cache_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
self_set_header (self, "cache-control", "no-cache");
self_set_header (self, "expires", "0");
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_NO_CACHE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_NO_CACHE))
    if (http_response_animating)
        icl_console_print ("<http_response_set_no_cache_finish"
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
    http_response_set_redirect

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Redirects the response to the specified URI.  The URI can be a relative
    URI in which case the browser is redirected to the same server and port,
    or an absolute URI on the same or other server.
    -------------------------------------------------------------------------
 */

int
    http_response_set_redirect (
    http_response_t * self,             //  Reference to object
    char * new_uri                      //  New URI location
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_REDIRECT))
    if (http_response_animating)
        icl_console_print ("<http_response_set_redirect_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" new_uri=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, new_uri);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_REDIRECT))
    icl_trace_record (NULL, http_response_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_REDIRECT))
    icl_stats_inc ("http_response_set_redirect", &s_http_response_set_redirect_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
//  Set Location: header into response headers table
//  If we have an absolute URI with proto name, use as-is
if (ipr_regexp_eq ("^[a-zA-Z0-9`.`-`+]+:", new_uri))
    self_set_header (self, "location", new_uri);
else
    self_set_header (self, "location", "%s%s", self->root_uri, new_uri);

self_set_error (self, HTTP_REPLY_FOUND, NULL);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_REDIRECT))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_REDIRECT))
    if (http_response_animating)
        icl_console_print ("<http_response_set_redirect_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" new_uri=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, new_uri, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_response_set_error

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the response reply code.
    -------------------------------------------------------------------------
 */

int
    http_response_set_error (
    http_response_t * self,             //  Reference to object
    uint reply_code,                    //  Reply code
    char * reply_text,                  //  Reply text
...                                     //  Variable arguments
)
{
    int
        _rc;
    va_list
        args;
    va_start (args, reply_text);
    _rc = http_response_set_error_v (self, reply_code, reply_text, args );
    va_end (args);
    return _rc;
}
/*  -------------------------------------------------------------------------
    http_response_set_error_v

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the response reply code.
    -------------------------------------------------------------------------
 */

int
    http_response_set_error_v (
    http_response_t * self,             //  Reference to object
    uint reply_code,                    //  Reply code
    char * reply_text,                  //  Reply text
va_list args                            //  Variable arguments
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SET_ERROR))
    if (http_response_animating)
        icl_console_print ("<http_response_set_error_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_code=\"%u\""
" reply_text=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_code, reply_text);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_ERROR))
    icl_trace_record (NULL, http_response_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SET_ERROR))
    icl_stats_inc ("http_response_set_error", &s_http_response_set_error_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
self->reply_code = reply_code;
if (reply_text)
    apr_vsnprintf (self->reply_text, ICL_SHORTSTR_MAX, reply_text, args);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_ERROR))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SET_ERROR))
    if (http_response_animating)
        icl_console_print ("<http_response_set_error_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" reply_code=\"%u\""
" reply_text=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, reply_code, reply_text, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_response_format_reply

    Type: Component method
    Accepts a http_response_t reference and returns zero in case of success,
    1 in case of errors.
    Formats a response header and (in case of errors) body and places
    these at the start of the response bucket list, before any buckets
    the list might contain.
    -------------------------------------------------------------------------
 */

int
    http_response_format_reply (
    http_response_t * self              //  Reference to object
)
{
icl_shortstr_t
    mime_date;                      //  Holds formatted date/time
ipr_bucket_t
    *bucket;                        //  Holds formatted header
icl_longstr_t
    *prefix;                        //  Holds formatted first line
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_FORMAT_REPLY))
    if (http_response_animating)
        icl_console_print ("<http_response_format_reply_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_FORMAT_REPLY))
    icl_trace_record (NULL, http_response_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_FORMAT_REPLY))
    icl_stats_inc ("http_response_format_reply", &s_http_response_format_reply_stats);
#endif

HTTP_RESPONSE_ASSERT_SANE (self);
if (!self->zombie) {

//
//  If we have an error, switch off keep-alive and format an error
//  message as a bucket of dynamic response data.
if (self->reply_code >= 400) {
    self->request->persistent = FALSE;
    s_format_error_page (self);
}
//  Define standard header fields
ipr_time_mime (apr_time_now (), mime_date);
self_set_header (self, "server", http_config_server_name (http_config));
self_set_header (self, "date", mime_date);
self_set_header (self, "content-length", "%u", self->content_length);

//  Set connection header
if (self->request->persistent) {
    if (self->request->version == HTTP_VERSION_1_0)
        self_set_header (self, "connection", "Keep-Alive");
}
else
    if (self->request->version == HTTP_VERSION_1_1)
        self_set_header (self, "connection", "Close");

//  Format HTTP header block from header fields
prefix = icl_longstr_new (NULL, 1024);
icl_longstr_fmt (prefix, "HTTP/%s %d",
    self->request->version == HTTP_VERSION_1_0? "1.0": "1.1",
    self->reply_code);

if (http_config_verbose (http_config)) {
    icl_console_print ("I: HTTP response ----------------------------------------");
    icl_console_print ("I: %s", (char *) prefix->data);
}
icl_longstr_cat (prefix, "\r\n");
bucket = ipr_dict_table_headers_save (
    self->headers, prefix, http_config_verbose (http_config));
ipr_bucket_list_push (self->bucket_list, bucket);
ipr_bucket_unlink (&bucket);
icl_longstr_destroy (&prefix);
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_FORMAT_REPLY))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_FORMAT_REPLY))
    if (http_response_animating)
        icl_console_print ("<http_response_format_reply_finish"
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
    http_response_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_response_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SELFTEST))
    if (http_response_animating)
        icl_console_print ("<http_response_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SELFTEST))
    icl_trace_record (NULL, http_response_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SELFTEST))
    icl_stats_inc ("http_response_selftest", &s_http_response_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SELFTEST))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SELFTEST))
    if (http_response_animating)
        icl_console_print ("<http_response_selftest_finish"
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
    http_response_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_response_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_TERMINATE))
    if (http_response_animating)
        icl_console_print ("<http_response_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_TERMINATE))
    icl_trace_record (NULL, http_response_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_TERMINATE))
    icl_stats_inc ("http_response_terminate", &s_http_response_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_TERMINATE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_TERMINATE))
    if (http_response_animating)
        icl_console_print ("<http_response_terminate_finish"
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
    http_response_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_response_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    http_response_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SHOW))
    if (http_response_animating)
        icl_console_print ("<http_response_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SHOW))
    icl_trace_record (NULL, http_response_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SHOW))
    icl_stats_inc ("http_response_show", &s_http_response_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <http_response zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    if (self->history_last > HTTP_RESPONSE_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % HTTP_RESPONSE_HISTORY_LENGTH;
        self->history_last %= HTTP_RESPONSE_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % HTTP_RESPONSE_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </http_response>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SHOW))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SHOW))
    if (http_response_animating)
        icl_console_print ("<http_response_show_finish"
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
    http_response_destroy

    Type: Component method
    Destroys a http_response_t object. Takes the address of a
    http_response_t reference (a pointer to a pointer) and nullifies the
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
    http_response_destroy_ (
    http_response_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    http_response_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_DESTROY_PUBLIC))
    if (http_response_animating)
        icl_console_print ("<http_response_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_response_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_DESTROY_PUBLIC))
    icl_stats_inc ("http_response_destroy", &s_http_response_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        http_response_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on http_response object");
        http_response_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        http_response_free_ ((http_response_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_DESTROY_PUBLIC))
    if (http_response_animating)
        icl_console_print ("<http_response_destroy_public_finish"
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
    http_response_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_response_t *
    http_response_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_response_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_ALLOC))
    if (http_response_animating)
        icl_console_print ("<http_response_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_ALLOC))
    icl_trace_record (NULL, http_response_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_ALLOC))
    icl_stats_inc ("http_response_alloc", &s_http_response_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_response_cache_initialise ();

self = (http_response_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_response_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_ALLOC))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_ALLOC))
    if (http_response_animating)
        icl_console_print ("<http_response_alloc_finish"
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
    http_response_free

    Type: Component method
    Freess a http_response_t object.
    -------------------------------------------------------------------------
 */

static void
    http_response_free_ (
    http_response_t * self,             //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_FREE))
    if (http_response_animating)
        icl_console_print ("<http_response_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_FREE))
    icl_trace_record (NULL, http_response_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_FREE))
    icl_stats_inc ("http_response_free", &s_http_response_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = "free";
        self->history_links [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (http_response_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_response_t));
        self->object_tag = HTTP_RESPONSE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_FREE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_FREE))
    if (http_response_animating)
        icl_console_print ("<http_response_free_finish"
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
    http_response_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

http_response_t *
    http_response_link_ (
    http_response_t * self,             //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_LINK))
    if (http_response_animating)
        icl_console_print ("<http_response_link_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_LINK))
    icl_trace_record (NULL, http_response_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_LINK))
    icl_stats_inc ("http_response_link", &s_http_response_link_stats);
#endif

    if (self) {
        HTTP_RESPONSE_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = "link";
        self->history_links [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_LINK))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_LINK))
    if (http_response_animating)
        icl_console_print ("<http_response_link_finish"
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
    http_response_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    http_response_unlink_ (
    http_response_t * ( * self_p ),     //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
    int
        history_last;
#endif

    http_response_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_UNLINK))
    if (http_response_animating)
        icl_console_print ("<http_response_unlink_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_UNLINK))
    icl_trace_record (NULL, http_response_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_UNLINK))
    icl_stats_inc ("http_response_unlink", &s_http_response_unlink_stats);
#endif

    if (self) {
        HTTP_RESPONSE_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on http_response object");
            http_response_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_RESPONSE)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = file;
        self->history_line  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = line;
        self->history_type  [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % HTTP_RESPONSE_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            http_response_annihilate_ (self_p, file, line);
        http_response_free_ ((http_response_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_UNLINK))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_UNLINK))
    if (http_response_animating)
        icl_console_print ("<http_response_unlink_finish"
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
    http_response_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_response_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_CACHE_INITIALISE))
    if (http_response_animating)
        icl_console_print ("<http_response_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_INITIALISE))
    icl_trace_record (NULL, http_response_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_CACHE_INITIALISE))
    icl_stats_inc ("http_response_cache_initialise", &s_http_response_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_response_t));
icl_system_register (http_response_cache_purge, http_response_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_INITIALISE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_CACHE_INITIALISE))
    if (http_response_animating)
        icl_console_print ("<http_response_cache_initialise_finish"
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
    http_response_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_response_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_CACHE_PURGE))
    if (http_response_animating)
        icl_console_print ("<http_response_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_PURGE))
    icl_trace_record (NULL, http_response_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_CACHE_PURGE))
    icl_stats_inc ("http_response_cache_purge", &s_http_response_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_PURGE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_CACHE_PURGE))
    if (http_response_animating)
        icl_console_print ("<http_response_cache_purge_finish"
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
    http_response_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_response_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_CACHE_TERMINATE))
    if (http_response_animating)
        icl_console_print ("<http_response_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_TERMINATE))
    icl_trace_record (NULL, http_response_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_CACHE_TERMINATE))
    icl_stats_inc ("http_response_cache_terminate", &s_http_response_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_TERMINATE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_CACHE_TERMINATE))
    if (http_response_animating)
        icl_console_print ("<http_response_cache_terminate_finish"
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
    http_response_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_response_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_SHOW_ANIMATION))
    if (http_response_animating)
        icl_console_print ("<http_response_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SHOW_ANIMATION))
    icl_trace_record (NULL, http_response_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_SHOW_ANIMATION))
    icl_stats_inc ("http_response_show_animation", &s_http_response_show_animation_stats);
#endif

http_response_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_SHOW_ANIMATION))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_SHOW_ANIMATION))
    if (http_response_animating)
        icl_console_print ("<http_response_show_animation_finish"
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
    http_response_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_response_new_in_scope_ (
    http_response_t * * self_p,         //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    http_server_t * server,             //  Parent server
    http_request_t * request            //  Request context
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE)  ||  defined (BASE_ANIMATE_HTTP_RESPONSE_NEW_IN_SCOPE))
    if (http_response_animating)
        icl_console_print ("<http_response_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
" request=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server, request);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_response_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_RESPONSE)  ||  defined (BASE_STATS_HTTP_RESPONSE_NEW_IN_SCOPE))
    icl_stats_inc ("http_response_new_in_scope", &s_http_response_new_in_scope_stats);
#endif

*self_p = http_response_new_ (file,line,server,request);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_response_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_response_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_RESPONSE)   || defined (BASE_ANIMATE_HTTP_RESPONSE_NEW_IN_SCOPE))
    if (http_response_animating)
        icl_console_print ("<http_response_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" server=\"%pp\""
" request=\"%pp\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, server, request, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_RESPONSE)   || defined (BASE_TRACE_HTTP_RESPONSE_NEW)   || defined (BASE_TRACE_HTTP_RESPONSE_DESTROY)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_HEADER)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_FILE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_BUCKET)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_FROM_XML_STR)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_NO_CACHE)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_REDIRECT)   || defined (BASE_TRACE_HTTP_RESPONSE_SET_ERROR)   || defined (BASE_TRACE_HTTP_RESPONSE_FORMAT_REPLY)   || defined (BASE_TRACE_HTTP_RESPONSE_SELFTEST)   || defined (BASE_TRACE_HTTP_RESPONSE_TERMINATE)   || defined (BASE_TRACE_HTTP_RESPONSE_SHOW)   || defined (BASE_TRACE_HTTP_RESPONSE_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_RESPONSE_ALLOC)   || defined (BASE_TRACE_HTTP_RESPONSE_FREE)   || defined (BASE_TRACE_HTTP_RESPONSE_LINK)   || defined (BASE_TRACE_HTTP_RESPONSE_UNLINK)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_RESPONSE_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_RESPONSE_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_RESPONSE_NEW_IN_SCOPE) )
void
http_response_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "set header"; break;
        case 4: method_name = "set from file"; break;
        case 5: method_name = "set from bucket"; break;
        case 6: method_name = "set from xml str"; break;
        case 7: method_name = "set no cache"; break;
        case 8: method_name = "set redirect"; break;
        case 9: method_name = "set error"; break;
        case 10: method_name = "format reply"; break;
        case 11: method_name = "selftest"; break;
        case 12: method_name = "terminate"; break;
        case 13: method_name = "show"; break;
        case 14: method_name = "destroy public"; break;
        case 15: method_name = "alloc"; break;
        case 16: method_name = "free"; break;
        case 17: method_name = "link"; break;
        case 18: method_name = "unlink"; break;
        case 19: method_name = "cache initialise"; break;
        case 20: method_name = "cache purge"; break;
        case 21: method_name = "cache terminate"; break;
        case 22: method_name = "show animation"; break;
        case 23: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_response %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Formats the external URI to the root path /.  This URI is used
//  in any response that needs to refer the client application back
//  to the same service.  Also formats the response->hostname.
//
static void
    s_format_root_uri (http_response_t *self)
{
    char
        *public_port;                   //  Current client http port

    //  Format proto://
    icl_shortstr_cpy (self->root_uri, self->request->encrypted? "https://": "http://");

    //  Format proto://hostname
    if (*http_request_get_header (self->request, "host"))
        icl_shortstr_cpy (self->hostname, http_request_get_header (self->request, "host"));
    else
        ipr_net_get_hostname (self->hostname);
    icl_shortstr_cat (self->root_uri, self->hostname);

    //  Format proto://hostname:port if necessary
    if (strchr (self->hostname, ':') == NULL) {
        public_port = http_config_public_port (http_config);
        if (*public_port && strneq (public_port, "80")) {
            icl_shortstr_cat (self->root_uri, ":");
            icl_shortstr_cat (self->root_uri, public_port);
        }
    }
    icl_shortstr_cat (self->root_uri, "/");
}

static void
s_format_error_page (http_response_t *self)
{
    ipr_bucket_t
        *bucket,                        //  Bucket we will format
        *style;                         //  Built-in stylesheet
    char
        *text = "Unknown error";
    icl_shortstr_t
        error_filename;
    FILE
        *error_file;                    //  Handle to error_nnn.html file

    switch (self->reply_code) {
        case HTTP_REPLY_BADREQUEST:
            text = "Bad request: HTTP request seems to be invalid.";
            break;
        case HTTP_REPLY_UNAUTHORIZED:
            text = "Your username and/or password are invalid.";
            break;
        case HTTP_REPLY_PAYEMENT:
            text = "Payment is required to access this resource.";
            break;
        case HTTP_REPLY_FORBIDDEN:
            text = "You are not authorised to access this resource.";
            break;
        case HTTP_REPLY_NOTFOUND:
            text = "The resource you asked for does not exist on this website.";
            break;
        case HTTP_REPLY_PRECONDITION:
            text = "The operation failed because the file already exists.";
            break;
        case HTTP_REPLY_TOOLARGE:
            text = "This server cannot handle your request.";
            break;
        case HTTP_REPLY_INTERNALERROR:
            text = "Internal error: your request was unsuccessful.";
            break;
        case HTTP_REPLY_NOTIMPLEMENTED:
            text = "The function you requested is not implemented.";
            break;
        case HTTP_REPLY_OVERLOADED:
            text = "This server is currently overloaded, try again later.";
            break;
        case HTTP_REPLY_VERSIONUNSUP:
            text = "This server cannot work with your browser.";
            break;
    }
    //  Allocated working buffer, fairly arbitrary sizes
    bucket = ipr_bucket_new (65000);
    ipr_bucket_cat (bucket, ERROR_HEADER_1, strlen (ERROR_HEADER_1));

    //  Add built-in style sheet
    style = http_static_get ("http_base.css");
    assert (bucket);
    ipr_bucket_cat (bucket, style->data, style->cur_size);
    ipr_bucket_destroy (&style);
    ipr_bucket_cat (bucket, ERROR_HEADER_2, strlen (ERROR_HEADER_2));

    ipr_bucket_cat (bucket, text, strlen (text));
    if (strused (self->reply_text)) {
        ipr_bucket_cat (bucket, ERROR_HEADER_3, strlen (ERROR_HEADER_3));
        ipr_bucket_cat (bucket, self->reply_text, strlen (self->reply_text));
    }
    //  Load contents of error_nnn.html file, if present
    icl_shortstr_fmt (error_filename, "error_%d.html", self->reply_code);
    error_file = fopen (error_filename, "r");
    if (error_file) {
        ipr_bucket_cat (bucket, ERROR_HEADER_2, strlen (ERROR_HEADER_2));
        ipr_bucket_load (bucket, error_file);
        fclose (error_file);
    }
    ipr_bucket_cat (bucket, ERROR_FOOTER, strlen (ERROR_FOOTER));
    bucket->data [bucket->cur_size++] = 0;
    ipr_str_subch ((char *) bucket->data, '[', '<');
    ipr_str_subch ((char *) bucket->data, ']', '>');

    //  Add bucket to list of buckets returned to user
    http_response_set_from_bucket (self, bucket, "text/html");
    http_response_set_no_cache (self);
    ipr_bucket_unlink (&bucket);
}

//  Embed the version information in the resulting binary                      

char *http_response_version_start  = "VeRsIoNsTaRt:ipc";
char *http_response_component      = "http_response ";
char *http_response_version        = "1.0 ";
char *http_response_copyright      = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_response_filename       = "http_response.icl ";
char *http_response_builddate      = "2009/02/19 ";
char *http_response_version_end    = "VeRsIoNeNd:ipc";

