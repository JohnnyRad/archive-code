/*---------------------------------------------------------------------------
    demo_client_session.h - demo_client_session component

This class provides the session serialisation API.
    Generated from demo_client_session.icl by icl_gen using GSL/4.
    
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
# ifndef INCLUDE_DEMO_CLIENT_SESSION_SAFE
#   define INCLUDE_DEMO_CLIENT_SESSION_SAFE
#   define INCLUDE_DEMO_CLIENT_SESSION_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_DEMO_CLIENT_SESSION_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _demo_client_session_t demo_client_session_t;

#define DEMO_CLIENT_SESSION_ALIVE       0xFABB
#define DEMO_CLIENT_SESSION_DEAD        0xDEAD

#define DEMO_CLIENT_SESSION_ASSERT_SANE(self)\
{\
    if (!self) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "Attempting to work with a NULL demo_client_session\n");\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
    if (self->object_tag != DEMO_CLIENT_SESSION_ALIVE) {\
        fprintf (stderr, "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        fprintf (stderr, "demo_client_session at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, DEMO_CLIENT_SESSION_ALIVE, self->object_tag);\
        demo_client_session_show (self, ICL_CALLBACK_DUMP, stderr);\
        fprintf (stderr, "Please report this to openamq-dev@lists.openamq.org\n");\
        fflush (stderr);\
        abort ();\
    }\
}
#   ifdef __cplusplus
}
#   endif

#   include "demo_client_classes.h"
#   include "demo_constants.h"
#   include "demo_client_connection.h"
#   include "demo_content_basic_list.h"
#   include "icl_mem.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_SESSION_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_SESSION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_DEMO_CLIENT_SESSION_UNSAFE
#   define INCLUDE_DEMO_CLIENT_SESSION_UNSAFE
#   define INCLUDE_DEMO_CLIENT_SESSION_ACTIVE

#   include "demo_client_classes.h"
#   include "demo_constants.h"
#   include "demo_client_connection.h"
#   include "demo_content_basic_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    demo_client_session_animating;

//  Structure of the demo_client_session object

struct _demo_client_session_t {
dbyte
    object_tag;                     //  Object validity marker
demo_client_connection_t
    *connection;                    //  Parent connection object
smt_method_queue_t
    *method_queue;                  //  Replies from protocol agent
dbyte
    channel_nbr;                    //  Session channel number
Bool
    alive;                          //  Is the session alive?
apr_time_t
    timestamp;                      //  Time session was opened
volatile qbyte
    flow_stopped;                   //  Is flow of messages from server stopped?
char
    *error_text;                    //  Last error cause
char
    *chrono_block;                  //  Accumulated chrono deltas
ipr_hash_table_t
    *dp_sinks,                      //  DP sink threads
    *dp_feeds;                      //  DP feed threads
icl_longstr_t *
    channel_id;                     //  unique id of the channel
Bool
    active;                         //  start/stop content frames
dbyte
    reply_code;                     //  reply code from server
icl_shortstr_t
    reply_text;                     //  localised reply text
dbyte
    class_id;                       //  failing method class
dbyte
    method_id;                      //  failing method ID
icl_shortstr_t
    lease;                          //  Lease for connection
icl_shortstr_t
    consumer_tag;                   //  consumer tag
icl_shortstr_t
    exchange;                       //  exchange name
icl_shortstr_t
    routing_key;                    //  Message routing key
qbyte
    message_count;                  //  number of messages pending
icl_shortstr_t
    queue;                          //  queue name
icl_longstr_t *
    properties;                     //  queue properties
//  Handling for basic messages
demo_content_basic_list_t
    *arrived_basic_list;            //  Basic messages
demo_content_basic_list_t
    *returned_basic_list;           //  Returned basic messages
demo_content_basic_list_t
    *chrono_list;                   //  Pending chrono messages
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define demo_client_session_new(connection)  demo_client_session_new_ (__FILE__, __LINE__, connection)
demo_client_session_t *
    demo_client_session_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
demo_client_connection_t * connection   //  Not documented
);

int
    demo_client_session_wait (
demo_client_session_t * self,           //  Reference to object
int timeout                             //  Timeout, in milliseconds
);

int
    demo_client_session_channel_flow (
demo_client_session_t * self,           //  Reference to object
Bool active                             //  start/stop content frames
);

int
    demo_client_session_channel_flow_ok (
demo_client_session_t * self,           //  Reference to object
Bool active                             //  current flow setting
);

int
    demo_client_session_exchange_declare (
demo_client_session_t * self,           //  Reference to object
char * exchange,                        //  exchange name
char * type,                            //  exchange class
Bool passive,                           //  do not create exchange
Bool durable,                           //  request a durable exchange
Bool auto_delete                        //  auto-delete when unused
);

int
    demo_client_session_exchange_delete (
demo_client_session_t * self,           //  Reference to object
char * exchange,                        //  exchange name
Bool if_unused                          //  delete only if unused
);

int
    demo_client_session_queue_declare (
demo_client_session_t * self,           //  Reference to object
char * queue,                           //  queue name
Bool passive,                           //  do not create queue
Bool durable,                           //  request a durable queue
Bool exclusive,                         //  request an exclusive queue
Bool auto_delete                        //  auto-delete queue when unused
);

int
    demo_client_session_queue_bind (
demo_client_session_t * self,           //  Reference to object
char * queue,                           //  queue name
char * exchange,                        //  exchange name
icl_longstr_t * arguments               //  arguments for binding
);

int
    demo_client_session_queue_purge (
demo_client_session_t * self,           //  Reference to object
char * queue                            //  queue name
);

int
    demo_client_session_queue_delete (
demo_client_session_t * self,           //  Reference to object
char * queue,                           //  queue name
Bool if_unused,                         //  delete only if unused
Bool if_empty                           //  delete only if empty
);

int
    demo_client_session_basic_consume (
demo_client_session_t * self,           //  Reference to object
char * queue                            //  queue name
);

int
    demo_client_session_basic_cancel (
demo_client_session_t * self,           //  Reference to object
char * consumer_tag                     //  consumer tag
);

int
    demo_client_session_basic_publish (
demo_client_session_t * self,           //  Reference to object
demo_content_basic_t * content,         //  Message content
char * exchange,                        //  exchange name
char * routing_key                      //  Message routing key
);

int
    demo_client_session_basic_get (
demo_client_session_t * self,           //  Reference to object
char * queue                            //  queue name
);

int
    demo_client_session_push_arrived (
demo_client_session_t * self,           //  Reference to object
demo_content_basic_t * content,         //  Message content
char * exchange,                        //  Value to stamp into content
char * routing_key,                     //  Value to stamp into content
char * consumer_tag                     //  Value to stamp into content
);

int
    demo_client_session_push_returned (
demo_client_session_t * self,           //  Reference to object
demo_content_basic_t * content,         //  Message content
char * exchange,                        //  Value to stamp into content
char * routing_key,                     //  Value to stamp into content
char * consumer_tag                     //  Value to stamp into content
);

int
    demo_client_session_get_basic_arrived_count (
demo_client_session_t * self            //  Reference to object
);

demo_content_basic_t *
    demo_client_session_basic_arrived (
demo_client_session_t * self            //  Session object
);

int
    demo_client_session_get_basic_returned_count (
demo_client_session_t * self            //  Reference to object
);

demo_content_basic_t *
    demo_client_session_basic_returned (
demo_client_session_t * self            //  Session object
);

Bool
    demo_client_session_get_alive (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_error_text (
demo_client_session_t * self            //  Object reference
);

icl_longstr_t *
    demo_client_session_get_channel_id (
demo_client_session_t * self            //  Object reference
);

Bool
    demo_client_session_get_active (
demo_client_session_t * self            //  Object reference
);

int
    demo_client_session_get_reply_code (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_reply_text (
demo_client_session_t * self            //  Object reference
);

int
    demo_client_session_get_class_id (
demo_client_session_t * self            //  Object reference
);

int
    demo_client_session_get_method_id (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_lease (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_consumer_tag (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_exchange (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_routing_key (
demo_client_session_t * self            //  Object reference
);

qbyte
    demo_client_session_get_message_count (
demo_client_session_t * self            //  Object reference
);

char *
    demo_client_session_get_queue (
demo_client_session_t * self            //  Object reference
);

icl_longstr_t *
    demo_client_session_get_properties (
demo_client_session_t * self            //  Object reference
);

smt_thread_t *
    demo_client_session_dp_new (
demo_client_session_t * self,           //  Session object
char * name,                            //  Resource name
int type                                //  Resource type
);

smt_thread_t *
    demo_client_session_dp_lookup (
demo_client_session_t * self,           //  Session object
char * name,                            //  Resource name
int type                                //  Resource type
);

int
    demo_client_session_dp_destroy (
demo_client_session_t * self,           //  Reference to object
char * name,                            //  Resource name
int type                                //  Resource type
);

void
    demo_client_session_selftest (
void);

#define demo_client_session_show(item,opcode,trace_file)  demo_client_session_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    demo_client_session_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define demo_client_session_destroy(self)  demo_client_session_destroy_ (self, __FILE__, __LINE__)
void
    demo_client_session_destroy_ (
demo_client_session_t * ( * self_p ),   //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

void
    demo_client_session_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define demo_client_session_new_in_scope(self_p,_scope,connection)  demo_client_session_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, connection)
void
    demo_client_session_new_in_scope_ (
demo_client_session_t * * self_p,       //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
demo_client_connection_t * connection   //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_SESSION_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_SESSION_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_DEMO_CLIENT_SESSION_INLINE)
#   define INCLUDE_DEMO_CLIENT_SESSION_INLINE
#   define INCLUDE_DEMO_CLIENT_SESSION_ACTIVE

#   include "demo_client_classes.h"
#   include "demo_constants.h"
#   include "demo_client_connection.h"
#   include "demo_content_basic_list.h"
#   include "icl_mem.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_WAIT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CHANNEL_FLOW_OK)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DECLARE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_EXCHANGE_DELETE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DECLARE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_BIND)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_QUEUE_DELETE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CONSUME)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_CANCEL)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_PUBLISH)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_GET)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_ARRIVED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_PUSH_RETURNED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_ARRIVED_COUNT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_ARRIVED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_BASIC_RETURNED_COUNT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_BASIC_RETURNED)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ALIVE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ERROR_TEXT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CHANNEL_ID)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ACTIVE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_CODE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_REPLY_TEXT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CLASS_ID)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_METHOD_ID)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_LEASE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_CONSUMER_TAG)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_EXCHANGE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_ROUTING_KEY)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_MESSAGE_COUNT)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_QUEUE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_GET_PROPERTIES)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_LOOKUP)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DP_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SELFTEST)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_ALLOC)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_FREE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_CLIENT_SESSION_NEW_IN_SCOPE) )
void
    demo_client_session_dump (icl_os_thread_t thread, apr_time_t time, qbyte info);
#endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_DEMO_CLIENT_SESSION_ACTIVE
#   if defined (ICL_IMPORT_DEMO_CLIENT_SESSION_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_DEMO_CLIENT_SESSION_ROOT
#   endif
# endif
#endif
