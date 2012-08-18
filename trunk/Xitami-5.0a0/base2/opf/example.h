/*---------------------------------------------------------------------------
    example.h - example component

    Generated from example.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_EXAMPLE_SAFE
#   define INCLUDE_EXAMPLE_SAFE
#   define INCLUDE_EXAMPLE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_EXAMPLE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _example_t example_t;

#define EXAMPLE_ALIVE                   0xFABB
#define EXAMPLE_DEAD                    0xDEAD

#define EXAMPLE_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL example\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != EXAMPLE_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "example at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, EXAMPLE_ALIVE, self->object_tag);\
        example_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_EXAMPLE_ACTIVE
#   if defined (ICL_IMPORT_EXAMPLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_EXAMPLE_UNSAFE
#   define INCLUDE_EXAMPLE_UNSAFE
#   define INCLUDE_EXAMPLE_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    example_animating;
extern example_t
    *example_config;                    //  Global properties object

//  Structure of the example object

struct _example_t {
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
    port;                           //  Server port for client connections
int
    monitor;                        //  Monitor interval, seconds
size_t
    max_memory_mb;                  //  Maximum allowed memory, MBytes
Bool
    record_stats;                   //  Record performance statistics
int
    packio;                         //  Pack network data before writing
int
    heartbeat;                      //  Heartbeat from client to server, seconds
int
    read_timeout;                   //  Timeout on network reads, seconds
int
    write_timeout;                  //  Timeout on network writes, seconds
Bool
    tcp_nodelay;                    //  TCP/IP NDELAY option
int
    tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
int
    tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
int
    frame_max;                      //  Maximum size of AMQP content frames
char *
    log_path;                       //  Active log file directory
Bool
    keep_logs;                      //  Keep log files
char *
    archive_path;                   //  Archive log file directory
char *
    archive_cmd;                    //  Archive command
char *
    alert_log;                      //  Alert log file name
char *
    daily_log;                      //  Daily log file name
char *
    debug_log;                      //  Debug log file name
int
    trace;                          //  Protocol trace level
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define example_new()                   example_new_ (__FILE__, __LINE__)
example_t *
    example_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    example_load_xmlfile (
example_t * self,                       //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    example_load_bucket (
example_t * self,                       //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    example_shadow (
example_t * self,                       //  Reference to object
ipr_config_t * source                   //  Config data to shadow
);

int
    example_commit (
example_t * self,                       //  Reference to object
char * filename                         //  Config file to save
);

int
    example_rollback (
example_t * self                        //  Reference to object
);

void
    example_cmdline_help (
void);

int
    example_cmdline_parse (
example_t * self,                       //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    example_options_help (
example_t * self,                       //  Reference to object
char * name                             //  Name of application
);

int
    example_set_port (
example_t * self,                       //  Reference to object
char * port                             //  Not documented
);

char *
    example_port (
example_t * self                        //  Reference to self
);

int
    example_set_monitor (
example_t * self,                       //  Reference to object
int monitor                             //  Not documented
);

int
    example_monitor (
example_t * self                        //  Reference to self
);

int
    example_set_max_memory_mb (
example_t * self,                       //  Reference to object
size_t max_memory_mb                    //  Not documented
);

size_t
    example_max_memory_mb (
example_t * self                        //  Reference to self
);

int
    example_set_record_stats (
example_t * self,                       //  Reference to object
Bool record_stats                       //  Not documented
);

Bool
    example_record_stats (
example_t * self                        //  Reference to self
);

int
    example_set_packio (
example_t * self,                       //  Reference to object
int packio                              //  Not documented
);

int
    example_packio (
example_t * self                        //  Reference to self
);

int
    example_set_heartbeat (
example_t * self,                       //  Reference to object
int heartbeat                           //  Not documented
);

int
    example_heartbeat (
example_t * self                        //  Reference to self
);

int
    example_set_read_timeout (
example_t * self,                       //  Reference to object
int read_timeout                        //  Not documented
);

int
    example_read_timeout (
example_t * self                        //  Reference to self
);

int
    example_set_write_timeout (
example_t * self,                       //  Reference to object
int write_timeout                       //  Not documented
);

int
    example_write_timeout (
example_t * self                        //  Reference to self
);

int
    example_set_tcp_nodelay (
example_t * self,                       //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    example_tcp_nodelay (
example_t * self                        //  Reference to self
);

int
    example_set_tcp_rcvbuf (
example_t * self,                       //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    example_tcp_rcvbuf (
example_t * self                        //  Reference to self
);

int
    example_set_tcp_sndbuf (
example_t * self,                       //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    example_tcp_sndbuf (
example_t * self                        //  Reference to self
);

int
    example_set_frame_max (
example_t * self,                       //  Reference to object
int frame_max                           //  Not documented
);

int
    example_frame_max (
example_t * self                        //  Reference to self
);

int
    example_set_log_path (
example_t * self,                       //  Reference to object
char * log_path                         //  Not documented
);

char *
    example_log_path (
example_t * self                        //  Reference to self
);

int
    example_set_keep_logs (
example_t * self,                       //  Reference to object
Bool keep_logs                          //  Not documented
);

Bool
    example_keep_logs (
example_t * self                        //  Reference to self
);

int
    example_set_archive_path (
example_t * self,                       //  Reference to object
char * archive_path                     //  Not documented
);

char *
    example_archive_path (
example_t * self                        //  Reference to self
);

int
    example_set_archive_cmd (
example_t * self,                       //  Reference to object
char * archive_cmd                      //  Not documented
);

char *
    example_archive_cmd (
example_t * self                        //  Reference to self
);

int
    example_set_alert_log (
example_t * self,                       //  Reference to object
char * alert_log                        //  Not documented
);

char *
    example_alert_log (
example_t * self                        //  Reference to self
);

int
    example_set_daily_log (
example_t * self,                       //  Reference to object
char * daily_log                        //  Not documented
);

char *
    example_daily_log (
example_t * self                        //  Reference to self
);

int
    example_set_debug_log (
example_t * self,                       //  Reference to object
char * debug_log                        //  Not documented
);

char *
    example_debug_log (
example_t * self                        //  Reference to self
);

int
    example_set_trace (
example_t * self,                       //  Reference to object
int trace                               //  Not documented
);

int
    example_trace (
example_t * self                        //  Reference to self
);

int
    example_dump_log (
example_t * self,                       //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    example_selftest (
void);

void
    example_terminate (
void);

#define example_show(item,opcode,trace_file)  example_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    example_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define example_destroy(self)           example_destroy_ (self, __FILE__, __LINE__)
void
    example_destroy_ (
example_t * ( * self_p ),               //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    example_read_lock (
example_t * self                        //  Reference to object
);

int
    example_write_lock (
example_t * self                        //  Reference to object
);

int
    example_unlock (
example_t * self                        //  Reference to object
);

void
    example_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define example_new_in_scope(self_p,_scope)  example_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    example_new_in_scope_ (
example_t * * self_p,                   //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_EXAMPLE_ACTIVE
#   if defined (ICL_IMPORT_EXAMPLE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_EXAMPLE_INLINE)
#   define INCLUDE_EXAMPLE_INLINE
#   define INCLUDE_EXAMPLE_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_NEW)   || defined (BASE_TRACE_EXAMPLE_DESTROY)   || defined (BASE_TRACE_EXAMPLE_LOAD_XMLFILE)   || defined (BASE_TRACE_EXAMPLE_LOAD_BUCKET)   || defined (BASE_TRACE_EXAMPLE_SHADOW)   || defined (BASE_TRACE_EXAMPLE_COMMIT)   || defined (BASE_TRACE_EXAMPLE_ROLLBACK)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_HELP)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_PARSE)   || defined (BASE_TRACE_EXAMPLE_OPTIONS_HELP)   || defined (BASE_TRACE_EXAMPLE_SET_PORT)   || defined (BASE_TRACE_EXAMPLE_PORT)   || defined (BASE_TRACE_EXAMPLE_SET_MONITOR)   || defined (BASE_TRACE_EXAMPLE_MONITOR)   || defined (BASE_TRACE_EXAMPLE_SET_MAX_MEMORY_MB)   || defined (BASE_TRACE_EXAMPLE_MAX_MEMORY_MB)   || defined (BASE_TRACE_EXAMPLE_SET_RECORD_STATS)   || defined (BASE_TRACE_EXAMPLE_RECORD_STATS)   || defined (BASE_TRACE_EXAMPLE_SET_PACKIO)   || defined (BASE_TRACE_EXAMPLE_PACKIO)   || defined (BASE_TRACE_EXAMPLE_SET_HEARTBEAT)   || defined (BASE_TRACE_EXAMPLE_HEARTBEAT)   || defined (BASE_TRACE_EXAMPLE_SET_READ_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_READ_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_SET_WRITE_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_WRITE_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_NODELAY)   || defined (BASE_TRACE_EXAMPLE_TCP_NODELAY)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_RCVBUF)   || defined (BASE_TRACE_EXAMPLE_TCP_RCVBUF)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_SNDBUF)   || defined (BASE_TRACE_EXAMPLE_TCP_SNDBUF)   || defined (BASE_TRACE_EXAMPLE_SET_FRAME_MAX)   || defined (BASE_TRACE_EXAMPLE_FRAME_MAX)   || defined (BASE_TRACE_EXAMPLE_SET_LOG_PATH)   || defined (BASE_TRACE_EXAMPLE_LOG_PATH)   || defined (BASE_TRACE_EXAMPLE_SET_KEEP_LOGS)   || defined (BASE_TRACE_EXAMPLE_KEEP_LOGS)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_PATH)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_PATH)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_CMD)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_CMD)   || defined (BASE_TRACE_EXAMPLE_SET_ALERT_LOG)   || defined (BASE_TRACE_EXAMPLE_ALERT_LOG)   || defined (BASE_TRACE_EXAMPLE_SET_DAILY_LOG)   || defined (BASE_TRACE_EXAMPLE_DAILY_LOG)   || defined (BASE_TRACE_EXAMPLE_SET_DEBUG_LOG)   || defined (BASE_TRACE_EXAMPLE_DEBUG_LOG)   || defined (BASE_TRACE_EXAMPLE_SET_TRACE)   || defined (BASE_TRACE_EXAMPLE_TRACE)   || defined (BASE_TRACE_EXAMPLE_DUMP_LOG)   || defined (BASE_TRACE_EXAMPLE_SELFTEST)   || defined (BASE_TRACE_EXAMPLE_TERMINATE)   || defined (BASE_TRACE_EXAMPLE_SHOW)   || defined (BASE_TRACE_EXAMPLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_EXAMPLE_ALLOC)   || defined (BASE_TRACE_EXAMPLE_FREE)   || defined (BASE_TRACE_EXAMPLE_READ_LOCK)   || defined (BASE_TRACE_EXAMPLE_WRITE_LOCK)   || defined (BASE_TRACE_EXAMPLE_UNLOCK)   || defined (BASE_TRACE_EXAMPLE_CACHE_INITIALISE)   || defined (BASE_TRACE_EXAMPLE_CACHE_PURGE)   || defined (BASE_TRACE_EXAMPLE_CACHE_TERMINATE)   || defined (BASE_TRACE_EXAMPLE_SHOW_ANIMATION)   || defined (BASE_TRACE_EXAMPLE_NEW_IN_SCOPE) )
void
    example_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "ipr.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_EXAMPLE_ACTIVE
#   if defined (ICL_IMPORT_EXAMPLE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_EXAMPLE_ROOT
#   endif
# endif
#endif
