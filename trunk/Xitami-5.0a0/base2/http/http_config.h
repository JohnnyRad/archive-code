/*---------------------------------------------------------------------------
    http_config.h - http_config component

    Generated from http_config.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_HTTP_CONFIG_SAFE
#   define INCLUDE_HTTP_CONFIG_SAFE
#   define INCLUDE_HTTP_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_HTTP_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _http_config_t http_config_t;

#define HTTP_CONFIG_ALIVE               0xFABB
#define HTTP_CONFIG_DEAD                0xDEAD

#define HTTP_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL http_config\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != HTTP_CONFIG_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "http_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, HTTP_CONFIG_ALIVE, self->object_tag);\
        http_config_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "smt_log.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_HTTP_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_HTTP_CONFIG_UNSAFE
#   define INCLUDE_HTTP_CONFIG_UNSAFE
#   define INCLUDE_HTTP_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    http_config_animating;
extern http_config_t
    *http_config;                   //  Server properties object

//  Structure of the http_config object

struct _http_config_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    dbyte
        object_tag;                     //  Object validity marker
ipr_config_t
    *config;                        //  Configuration table
icl_shortstr_t
    filename;                       //  Configuration file name
char *
    server_name;                    //  Announced server name
char *
    port;                           //  Server port for HTTP requests
char *
    public_port;                    //  Public port for HTTP requests
Bool
    trace;                          //  Trace network traffic?
Bool
    animate;                        //  Animate HTTP agent?
Bool
    verbose;                        //  Verbose output?
char *
    listen;                         //  Address (local network interface) to listen on
char *
    webroot;                        //  Path to web root directory
char *
    defaults;                       //  Default file names
char *
    default_types;                  //  Default document types
int
    monitor;                        //  Monitor interval, seconds
Bool
    record_stats;                   //  Record performance statistics
char *
    log_path;                       //  Active log file directory
Bool
    keep_logs;                      //  Keep log files
char *
    archive_path;                   //  Archive log file directory
char *
    archive_cmd;                    //  Archive log file command
char *
    alert_log;                      //  Error log file name
char *
    access_log;                     //  Access log file name
char *
    access_log_format;              //  Access log file format
char *
    debug_log;                      //  Debug log file name
char *
    blacklist;                      //  Blacklist filename
char *
    basic_auth;                     //  Basic authentication filename
char *
    digest_auth;                    //  Digest authentication filename
int
    password_ttl;                   //  Password time-to-live, in seconds
int
    hit_quota;                      //  Password hit quota in pages
int
    miss_quota;                     //  Password miss quota in requests
int
    password_guard;                 //  Password guard timer, in seconds.
Bool
    policy_trace;                   //  Debug policy execution?
int
    nervosity;                      //  Security nervosity, seconds
int
    nonce_ttl;                      //  Nonce time-to-live, seconds
int
    nonce_quota;                    //  Nonce quota in requests
char *
    refresh_by;                     //  Shell command for password refresh
char *
    refresh_log;                    //  Stdout for password refresh
int
    address_quota;                  //  Maximum open connections per address
int
    abort_delay;                    //  Pause time for hostile connections
int
    coremark_cycles;                //  Duration of CoreMark test
int
    header_max;                     //  Max size of HTTP header
int
    bucket_max;                     //  Max size of content bucket
int
    read_timeout;                   //  Network read timeout, seconds
int
    write_timeout;                  //  Network write timeout, seconds
Bool
    tcp_nodelay;                    //  TCP/IP NODELAY option
int
    tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
int
    tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
int
    polling_threads;                //  Number of polling OS threads
int
    working_threads;                //  Number of working OS threads
char *
    etag;                           //  ETag header for files
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define http_config_new()               http_config_new_ (__FILE__, __LINE__)
http_config_t *
    http_config_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    http_config_load_xmlfile (
http_config_t * self,                   //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    http_config_load_bucket (
http_config_t * self,                   //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    http_config_shadow (
http_config_t * self,                   //  Reference to object
ipr_config_t * source                   //  Config data to shadow
);

int
    http_config_commit (
http_config_t * self,                   //  Reference to object
char * filename                         //  Config file to save
);

int
    http_config_rollback (
http_config_t * self                    //  Reference to object
);

void
    http_config_cmdline_help (
void);

int
    http_config_cmdline_parse (
http_config_t * self,                   //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    http_config_options_help (
http_config_t * self,                   //  Reference to object
char * name                             //  Name of application
);

int
    http_config_set_server_name (
http_config_t * self,                   //  Reference to object
char * server_name                      //  Not documented
);

char *
    http_config_server_name (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_port (
http_config_t * self,                   //  Reference to object
char * port                             //  Not documented
);

char *
    http_config_port (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_public_port (
http_config_t * self,                   //  Reference to object
char * public_port                      //  Not documented
);

char *
    http_config_public_port (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_trace (
http_config_t * self,                   //  Reference to object
Bool trace                              //  Not documented
);

Bool
    http_config_trace (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_animate (
http_config_t * self,                   //  Reference to object
Bool animate                            //  Not documented
);

Bool
    http_config_animate (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_verbose (
http_config_t * self,                   //  Reference to object
Bool verbose                            //  Not documented
);

Bool
    http_config_verbose (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_listen (
http_config_t * self,                   //  Reference to object
char * listen                           //  Not documented
);

char *
    http_config_listen (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_webroot (
http_config_t * self,                   //  Reference to object
char * webroot                          //  Not documented
);

char *
    http_config_webroot (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_defaults (
http_config_t * self,                   //  Reference to object
char * defaults                         //  Not documented
);

char *
    http_config_defaults (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_default_types (
http_config_t * self,                   //  Reference to object
char * default_types                    //  Not documented
);

char *
    http_config_default_types (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_monitor (
http_config_t * self,                   //  Reference to object
int monitor                             //  Not documented
);

int
    http_config_monitor (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_record_stats (
http_config_t * self,                   //  Reference to object
Bool record_stats                       //  Not documented
);

Bool
    http_config_record_stats (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_log_path (
http_config_t * self,                   //  Reference to object
char * log_path                         //  Not documented
);

char *
    http_config_log_path (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_keep_logs (
http_config_t * self,                   //  Reference to object
Bool keep_logs                          //  Not documented
);

Bool
    http_config_keep_logs (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_archive_path (
http_config_t * self,                   //  Reference to object
char * archive_path                     //  Not documented
);

char *
    http_config_archive_path (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_archive_cmd (
http_config_t * self,                   //  Reference to object
char * archive_cmd                      //  Not documented
);

char *
    http_config_archive_cmd (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_alert_log (
http_config_t * self,                   //  Reference to object
char * alert_log                        //  Not documented
);

char *
    http_config_alert_log (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_access_log (
http_config_t * self,                   //  Reference to object
char * access_log                       //  Not documented
);

char *
    http_config_access_log (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_access_log_format (
http_config_t * self,                   //  Reference to object
char * access_log_format                //  Not documented
);

char *
    http_config_access_log_format (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_debug_log (
http_config_t * self,                   //  Reference to object
char * debug_log                        //  Not documented
);

char *
    http_config_debug_log (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_blacklist (
http_config_t * self,                   //  Reference to object
char * blacklist                        //  Not documented
);

char *
    http_config_blacklist (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_basic_auth (
http_config_t * self,                   //  Reference to object
char * basic_auth                       //  Not documented
);

char *
    http_config_basic_auth (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_digest_auth (
http_config_t * self,                   //  Reference to object
char * digest_auth                      //  Not documented
);

char *
    http_config_digest_auth (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_password_ttl (
http_config_t * self,                   //  Reference to object
int password_ttl                        //  Not documented
);

int
    http_config_password_ttl (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_hit_quota (
http_config_t * self,                   //  Reference to object
int hit_quota                           //  Not documented
);

int
    http_config_hit_quota (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_miss_quota (
http_config_t * self,                   //  Reference to object
int miss_quota                          //  Not documented
);

int
    http_config_miss_quota (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_password_guard (
http_config_t * self,                   //  Reference to object
int password_guard                      //  Not documented
);

int
    http_config_password_guard (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_policy_trace (
http_config_t * self,                   //  Reference to object
Bool policy_trace                       //  Not documented
);

Bool
    http_config_policy_trace (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_nervosity (
http_config_t * self,                   //  Reference to object
int nervosity                           //  Not documented
);

int
    http_config_nervosity (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_nonce_ttl (
http_config_t * self,                   //  Reference to object
int nonce_ttl                           //  Not documented
);

int
    http_config_nonce_ttl (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_nonce_quota (
http_config_t * self,                   //  Reference to object
int nonce_quota                         //  Not documented
);

int
    http_config_nonce_quota (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_refresh_by (
http_config_t * self,                   //  Reference to object
char * refresh_by                       //  Not documented
);

char *
    http_config_refresh_by (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_refresh_log (
http_config_t * self,                   //  Reference to object
char * refresh_log                      //  Not documented
);

char *
    http_config_refresh_log (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_address_quota (
http_config_t * self,                   //  Reference to object
int address_quota                       //  Not documented
);

int
    http_config_address_quota (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_abort_delay (
http_config_t * self,                   //  Reference to object
int abort_delay                         //  Not documented
);

int
    http_config_abort_delay (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_coremark_cycles (
http_config_t * self,                   //  Reference to object
int coremark_cycles                     //  Not documented
);

int
    http_config_coremark_cycles (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_header_max (
http_config_t * self,                   //  Reference to object
int header_max                          //  Not documented
);

int
    http_config_header_max (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_bucket_max (
http_config_t * self,                   //  Reference to object
int bucket_max                          //  Not documented
);

int
    http_config_bucket_max (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_read_timeout (
http_config_t * self,                   //  Reference to object
int read_timeout                        //  Not documented
);

int
    http_config_read_timeout (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_write_timeout (
http_config_t * self,                   //  Reference to object
int write_timeout                       //  Not documented
);

int
    http_config_write_timeout (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_tcp_nodelay (
http_config_t * self,                   //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    http_config_tcp_nodelay (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_tcp_rcvbuf (
http_config_t * self,                   //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    http_config_tcp_rcvbuf (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_tcp_sndbuf (
http_config_t * self,                   //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    http_config_tcp_sndbuf (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_polling_threads (
http_config_t * self,                   //  Reference to object
int polling_threads                     //  Not documented
);

int
    http_config_polling_threads (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_working_threads (
http_config_t * self,                   //  Reference to object
int working_threads                     //  Not documented
);

int
    http_config_working_threads (
http_config_t * self                    //  Reference to self
);

int
    http_config_set_etag (
http_config_t * self,                   //  Reference to object
char * etag                             //  Not documented
);

char *
    http_config_etag (
http_config_t * self                    //  Reference to self
);

int
    http_config_dump_log (
http_config_t * self,                   //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    http_config_selftest (
void);

void
    http_config_terminate (
void);

#define http_config_show(item,opcode,trace_file)  http_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    http_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_config_destroy(self)       http_config_destroy_ (self, __FILE__, __LINE__)
void
    http_config_destroy_ (
http_config_t * ( * self_p ),           //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    http_config_read_lock (
http_config_t * self                    //  Reference to object
);

int
    http_config_write_lock (
http_config_t * self                    //  Reference to object
);

int
    http_config_unlock (
http_config_t * self                    //  Reference to object
);

void
    http_config_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define http_config_new_in_scope(self_p,_scope)  http_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    http_config_new_in_scope_ (
http_config_t * * self_p,               //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_HTTP_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_HTTP_CONFIG_INLINE)
#   define INCLUDE_HTTP_CONFIG_INLINE
#   define INCLUDE_HTTP_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NEW)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_HTTP_CONFIG_SHADOW)   || defined (BASE_TRACE_HTTP_CONFIG_COMMIT)   || defined (BASE_TRACE_HTTP_CONFIG_ROLLBACK)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_HTTP_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_HTTP_CONFIG_SET_SERVER_NAME)   || defined (BASE_TRACE_HTTP_CONFIG_SERVER_NAME)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PUBLIC_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_PUBLIC_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ANIMATE)   || defined (BASE_TRACE_HTTP_CONFIG_ANIMATE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_VERBOSE)   || defined (BASE_TRACE_HTTP_CONFIG_VERBOSE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LISTEN)   || defined (BASE_TRACE_HTTP_CONFIG_LISTEN)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WEBROOT)   || defined (BASE_TRACE_HTTP_CONFIG_WEBROOT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULTS)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULTS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULT_TYPES)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULT_TYPES)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MONITOR)   || defined (BASE_TRACE_HTTP_CONFIG_MONITOR)   || defined (BASE_TRACE_HTTP_CONFIG_SET_RECORD_STATS)   || defined (BASE_TRACE_HTTP_CONFIG_RECORD_STATS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LOG_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_LOG_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_KEEP_LOGS)   || defined (BASE_TRACE_HTTP_CONFIG_KEEP_LOGS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_CMD)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_CMD)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ALERT_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_ALERT_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG_FORMAT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEBUG_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_DEBUG_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BLACKLIST)   || defined (BASE_TRACE_HTTP_CONFIG_BLACKLIST)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BASIC_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_BASIC_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DIGEST_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_DIGEST_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HIT_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_HIT_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MISS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_MISS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_GUARD)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_GUARD)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLICY_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_POLICY_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NERVOSITY)   || defined (BASE_TRACE_HTTP_CONFIG_NERVOSITY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_BY)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_BY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ADDRESS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_ADDRESS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ABORT_DELAY)   || defined (BASE_TRACE_HTTP_CONFIG_ABORT_DELAY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_COREMARK_CYCLES)   || defined (BASE_TRACE_HTTP_CONFIG_COREMARK_CYCLES)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HEADER_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_HEADER_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BUCKET_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_BUCKET_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_SET_READ_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_READ_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WRITE_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLLING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_POLLING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WORKING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_WORKING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ETAG)   || defined (BASE_TRACE_HTTP_CONFIG_ETAG)   || defined (BASE_TRACE_HTTP_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SELFTEST)   || defined (BASE_TRACE_HTTP_CONFIG_TERMINATE)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_CONFIG_ALLOC)   || defined (BASE_TRACE_HTTP_CONFIG_FREE)   || defined (BASE_TRACE_HTTP_CONFIG_READ_LOCK)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_HTTP_CONFIG_UNLOCK)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_CONFIG_NEW_IN_SCOPE) )
void
    http_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "ipr.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_HTTP_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_HTTP_CONFIG_ROOT
#   endif
# endif
#endif
