/*---------------------------------------------------------------------------
    demo_client_config.h - demo_client_config component

    Generated from demo_client_config.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_DEMO_CLIENT_CONFIG_SAFE
#   define INCLUDE_DEMO_CLIENT_CONFIG_SAFE
#   define INCLUDE_DEMO_CLIENT_CONFIG_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_DEMO_CLIENT_CONFIG_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _demo_client_config_t demo_client_config_t;

#define DEMO_CLIENT_CONFIG_ALIVE        0xFABB
#define DEMO_CLIENT_CONFIG_DEAD         0xDEAD

#define DEMO_CLIENT_CONFIG_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL demo_client_config\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != DEMO_CLIENT_CONFIG_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "demo_client_config at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, DEMO_CLIENT_CONFIG_ALIVE, self->object_tag);\
        demo_client_config_show (self, ICL_CALLBACK_DUMP, stderr);\
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
#   undef INCLUDE_DEMO_CLIENT_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_DEMO_CLIENT_CONFIG_UNSAFE
#   define INCLUDE_DEMO_CLIENT_CONFIG_UNSAFE
#   define INCLUDE_DEMO_CLIENT_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
#include "ipr.h"
//  Global variables

extern Bool
    demo_client_config_animating;
extern demo_client_config_t
    *demo_client_config;                //  Global properties object

//  Structure of the demo_client_config object

struct _demo_client_config_t {
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
Bool
    tcp_nodelay;                    //  TCP/IP NODELAY option
int
    tcp_rcvbuf;                     //  TCP/IP receive buffer, in bytes
int
    tcp_sndbuf;                     //  TCP/IP send buffer, in bytes
int
    high_water;                     //  High water mark for message flow control
int
    low_water;                      //  Low water mark for message flow control
int
    direct;                         //  Enables Direct Mode for connections
int
    batching;                       //  Maximum size of Direct Mode batches
char *
    on_overflow;                    //  Sets action for high-water overflow
int
    chrono_enabled;                 //  Enable chrono pingbacks?
int
    chrono_floor;                   //  Floor for chrono pingbacks
int
    chrono_density;                 //  Sample density as permille
int
    chrono_batch;                   //  Batch size for chrono pingbacks
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define demo_client_config_new()        demo_client_config_new_ (__FILE__, __LINE__)
demo_client_config_t *
    demo_client_config_new_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

int
    demo_client_config_load_xmlfile (
demo_client_config_t * self,            //  Reference to object
char * filename,                        //  Config file to load
Bool required                           //  Config file is required?
);

int
    demo_client_config_load_bucket (
demo_client_config_t * self,            //  Reference to object
ipr_bucket_t * bucket                   //  Config data to load
);

int
    demo_client_config_shadow (
demo_client_config_t * self,            //  Reference to object
ipr_config_t * source                   //  Config data to shadow
);

int
    demo_client_config_commit (
demo_client_config_t * self,            //  Reference to object
char * filename                         //  Config file to save
);

int
    demo_client_config_rollback (
demo_client_config_t * self             //  Reference to object
);

void
    demo_client_config_cmdline_help (
void);

int
    demo_client_config_cmdline_parse (
demo_client_config_t * self,            //  Reference to object
char * name,                            //  Name of application
int argc,                               //  Argument count
char ** argv                            //  Argument list
);

int
    demo_client_config_options_help (
demo_client_config_t * self,            //  Reference to object
char * name                             //  Name of application
);

int
    demo_client_config_set_tcp_nodelay (
demo_client_config_t * self,            //  Reference to object
Bool tcp_nodelay                        //  Not documented
);

Bool
    demo_client_config_tcp_nodelay (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_tcp_rcvbuf (
demo_client_config_t * self,            //  Reference to object
int tcp_rcvbuf                          //  Not documented
);

int
    demo_client_config_tcp_rcvbuf (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_tcp_sndbuf (
demo_client_config_t * self,            //  Reference to object
int tcp_sndbuf                          //  Not documented
);

int
    demo_client_config_tcp_sndbuf (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_high_water (
demo_client_config_t * self,            //  Reference to object
int high_water                          //  Not documented
);

int
    demo_client_config_high_water (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_low_water (
demo_client_config_t * self,            //  Reference to object
int low_water                           //  Not documented
);

int
    demo_client_config_low_water (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_direct (
demo_client_config_t * self,            //  Reference to object
int direct                              //  Not documented
);

int
    demo_client_config_direct (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_batching (
demo_client_config_t * self,            //  Reference to object
int batching                            //  Not documented
);

int
    demo_client_config_batching (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_on_overflow (
demo_client_config_t * self,            //  Reference to object
char * on_overflow                      //  Not documented
);

char *
    demo_client_config_on_overflow (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_chrono_enabled (
demo_client_config_t * self,            //  Reference to object
int chrono_enabled                      //  Not documented
);

int
    demo_client_config_chrono_enabled (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_chrono_floor (
demo_client_config_t * self,            //  Reference to object
int chrono_floor                        //  Not documented
);

int
    demo_client_config_chrono_floor (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_chrono_density (
demo_client_config_t * self,            //  Reference to object
int chrono_density                      //  Not documented
);

int
    demo_client_config_chrono_density (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_set_chrono_batch (
demo_client_config_t * self,            //  Reference to object
int chrono_batch                        //  Not documented
);

int
    demo_client_config_chrono_batch (
demo_client_config_t * self             //  Reference to self
);

int
    demo_client_config_dump_log (
demo_client_config_t * self,            //  Reference to object
smt_log_t * logfile                     //  Log file to dump to
);

void
    demo_client_config_selftest (
void);

void
    demo_client_config_terminate (
void);

#define demo_client_config_show(item,opcode,trace_file)  demo_client_config_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    demo_client_config_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_client_config_destroy(self)  demo_client_config_destroy_ (self, __FILE__, __LINE__)
void
    demo_client_config_destroy_ (
demo_client_config_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    demo_client_config_read_lock (
demo_client_config_t * self             //  Reference to object
);

int
    demo_client_config_write_lock (
demo_client_config_t * self             //  Reference to object
);

int
    demo_client_config_unlock (
demo_client_config_t * self             //  Reference to object
);

void
    demo_client_config_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define demo_client_config_new_in_scope(self_p,_scope)  demo_client_config_new_in_scope_ (self_p, _scope, __FILE__, __LINE__)
void
    demo_client_config_new_in_scope_ (
demo_client_config_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_CONFIG_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_DEMO_CLIENT_CONFIG_INLINE)
#   define INCLUDE_DEMO_CLIENT_CONFIG_INLINE
#   define INCLUDE_DEMO_CLIENT_CONFIG_ACTIVE

#   include "smt_log.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHADOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_COMMIT)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ROLLBACK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_HIGH_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_HIGH_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_LOW_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOW_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_DIRECT)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DIRECT)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_BATCHING)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_BATCHING)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ON_OVERFLOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_ENABLED)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_FLOOR)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_DENSITY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_BATCH)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SELFTEST)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ALLOC)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_FREE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_READ_LOCK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_UNLOCK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE) )
void
    demo_client_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#include "ipr.h"
#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_CONFIG_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_CONFIG_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_DEMO_CLIENT_CONFIG_ROOT
#   endif
# endif
#endif
