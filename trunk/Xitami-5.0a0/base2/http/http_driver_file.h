/*---------------------------------------------------------------------------
    http_driver_file.h - http_driver_file component

    This class implements a driver module to handle normal files.  This
    is an async class that replies by sending methods (to the front end,
    which is the http_server object).
    Generated from http_driver_file.icl by smt_object_gen using GSL/4.
    
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

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_HTTP_DRIVER_FILE_SAFE
#   define INCLUDE_HTTP_DRIVER_FILE_SAFE
#   define INCLUDE_HTTP_DRIVER_FILE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_HTTP_DRIVER_FILE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _http_driver_file_t http_driver_file_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_FILE)
#    define HTTP_DRIVER_FILE_HISTORY_LENGTH 32
#endif

#define HTTP_DRIVER_FILE_ALIVE          0xFABB
#define HTTP_DRIVER_FILE_DEAD           0xDEAD

#define HTTP_DRIVER_FILE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL http_driver_file\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != HTTP_DRIVER_FILE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "http_driver_file at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, HTTP_DRIVER_FILE_ALIVE, self->object_tag);\
        http_driver_file_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_driver_file_agent.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_FILE_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_FILE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_HTTP_DRIVER_FILE_UNSAFE
#   define INCLUDE_HTTP_DRIVER_FILE_UNSAFE
#   define INCLUDE_HTTP_DRIVER_FILE_ACTIVE

#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_driver_file_agent.h"
//  Global variables

extern Bool
    http_driver_file_animating;

//  Structure of the http_driver_file object

struct _http_driver_file_t {
    volatile int  
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_FILE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [HTTP_DRIVER_FILE_HISTORY_LENGTH];
    int
        history_line  [HTTP_DRIVER_FILE_HISTORY_LENGTH];
    char
        *history_type [HTTP_DRIVER_FILE_HISTORY_LENGTH];
    int
        history_links [HTTP_DRIVER_FILE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
smt_thread_t
    *thread;
ipr_looseref_list_t
    *http_driver_module_list;       //  List of portals
Bool
    http_driver_module_stopped;     //  Is this portal stopped?
icl_shortstr_t
    root;                           //  File system root that path maps to
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
int
    http_driver_file_announce (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
smt_log_t * log                         //  Not documented
);

int
    http_driver_file_get (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_file_head (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_file_post (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_file_put (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_file_delete (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_file_move (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

int
    http_driver_file_copy (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal,          //  Portal back to client
http_driver_context_t * context         //  Not documented
);

#define http_driver_file_new()          http_driver_file_new_ (__FILE__, __LINE__)
http_driver_file_t *
    http_driver_file_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_driver_file_terminate (
void);

http_driver_module_t *
    http_driver_file__http_driver_module_new (
void * self_v,                          //  Untyped server reference
char * path                             //  Not documented
);

http_driver_module_t *
    http_driver_file__http_driver_module_factory (
char * path                             //  Not documented
);

int
    http_driver_file__http_driver_module_unbind (
http_driver_file_t * self,              //  Reference to object
http_driver_module_t * portal           //  Portal reference
);

void
    http_driver_file_selftest (
void);

#define http_driver_file_destroy(self)  http_driver_file_destroy_ (self, __FILE__, __LINE__)
int
    http_driver_file_destroy_ (
http_driver_file_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_file_unlink(self)   http_driver_file_unlink_ (self, __FILE__, __LINE__)
void
    http_driver_file_unlink_ (
http_driver_file_t * ( * self_p ),      //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_driver_file_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define http_driver_file_free(self)     http_driver_file_free_ (self, __FILE__, __LINE__)
void
    http_driver_file_free_ (
http_driver_file_t * self,              //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_file_show(item,opcode,trace_file)  http_driver_file_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    http_driver_file_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_file_link(self)     http_driver_file_link_ (self, __FILE__, __LINE__)
http_driver_file_t *
    http_driver_file_link_ (
http_driver_file_t * self,              //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define http_driver_file_new_in_scope(self_p,_scope)  http_driver_file_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    http_driver_file_new_in_scope_ (
http_driver_file_t * * self_p,          //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_FILE_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_FILE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_HTTP_DRIVER_FILE_INLINE)
#   define INCLUDE_HTTP_DRIVER_FILE_INLINE
#   define INCLUDE_HTTP_DRIVER_FILE_ACTIVE

#   include "http_driver_module.h"
#   include "http.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_ANNOUNCE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_DESTROY)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_GET)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_HEAD)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_POST)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_PUT)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_DELETE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_MOVE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_COPY)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_NEW)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_INITIALISE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_TERMINATE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE__HTTP_DRIVER_MODULE_NEW)   || defined (BASE_TRACE_HTTP_DRIVER_FILE__HTTP_DRIVER_MODULE_FACTORY)   || defined (BASE_TRACE_HTTP_DRIVER_FILE__HTTP_DRIVER_MODULE_UNBIND_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE__HTTP_DRIVER_MODULE_UNBIND)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_ANNOUNCE_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_GET_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_HEAD_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_POST_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_PUT_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_DELETE_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_MOVE_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_COPY_SHIM)   || defined (BASE_TRACE_HTTP_DRIVER_FILE__HTTP_DRIVER_MODULE_LINK)   || defined (BASE_TRACE_HTTP_DRIVER_FILE__HTTP_DRIVER_MODULE_UNLINK)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_SELFTEST)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_UNLINK)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_FREE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_SHOW)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_ALLOC)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_LINK)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_DRIVER_FILE_NEW_IN_SCOPE) )
void
    http_driver_file_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "icl.h"
#include "ipr.h"
#include "smt.h"
#include "http_driver_file_agent.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_FILE_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_FILE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_HTTP_DRIVER_FILE_ROOT
#   endif
# endif
#endif
