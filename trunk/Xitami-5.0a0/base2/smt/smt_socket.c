/*---------------------------------------------------------------------------
    smt_socket.c - smt_socket component

    The smt_socket class is used to create socket objects for use with the
    smt_socket_request class.
    Generated from smt_socket.icl by icl_gen using GSL/4.
    
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
#include "smt_socket.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              smt_socket_t

//  Shorthands for class methods                                               

#define self_new            smt_socket_new
#define self_annihilate     smt_socket_annihilate
#define self_connect        smt_socket_connect
#define self_passive        smt_socket_passive
#define self_set_nodelay    smt_socket_set_nodelay
#define self_set_rcvbuf     smt_socket_set_rcvbuf
#define self_set_sndbuf     smt_socket_set_sndbuf
#define self_peeraddr       smt_socket_peeraddr
#define self_trace          smt_socket_trace
#define self_selftest       smt_socket_selftest
#define self_terminate      smt_socket_terminate
#define self_show           smt_socket_show
#define self_destroy        smt_socket_destroy
#define self_alloc          smt_socket_alloc
#define self_free           smt_socket_free
#define self_cache_initialise  smt_socket_cache_initialise
#define self_cache_purge    smt_socket_cache_purge
#define self_cache_terminate  smt_socket_cache_terminate
#define self_show_animation  smt_socket_show_animation
#define self_new_in_scope   smt_socket_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_NEW))
static icl_stats_t *s_smt_socket_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_DESTROY))
static icl_stats_t *s_smt_socket_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CONNECT))
static icl_stats_t *s_smt_socket_connect_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_PASSIVE))
static icl_stats_t *s_smt_socket_passive_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SET_NODELAY))
static icl_stats_t *s_smt_socket_set_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SET_RCVBUF))
static icl_stats_t *s_smt_socket_set_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SET_SNDBUF))
static icl_stats_t *s_smt_socket_set_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_PEERADDR))
static icl_stats_t *s_smt_socket_peeraddr_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_TRACE))
static icl_stats_t *s_smt_socket_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SELFTEST))
static icl_stats_t *s_smt_socket_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_TERMINATE))
static icl_stats_t *s_smt_socket_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SHOW))
static icl_stats_t *s_smt_socket_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_DESTROY_PUBLIC))
static icl_stats_t *s_smt_socket_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_ALLOC))
static icl_stats_t *s_smt_socket_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_FREE))
static icl_stats_t *s_smt_socket_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CACHE_INITIALISE))
static icl_stats_t *s_smt_socket_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CACHE_PURGE))
static icl_stats_t *s_smt_socket_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CACHE_TERMINATE))
static icl_stats_t *s_smt_socket_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SHOW_ANIMATION))
static icl_stats_t *s_smt_socket_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_NEW_IN_SCOPE))
static icl_stats_t *s_smt_socket_new_in_scope_stats = NULL;
#endif
static void
    smt_socket_annihilate (
smt_socket_t * ( * self_p )             //  Reference to object reference
);

#define smt_socket_alloc()              smt_socket_alloc_ (__FILE__, __LINE__)
static smt_socket_t *
    smt_socket_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    smt_socket_free (
smt_socket_t * self                     //  Object reference
);

static void
    smt_socket_cache_initialise (
void);

static void
    smt_socket_cache_purge (
void);

static void
    smt_socket_cache_terminate (
void);

Bool
    smt_socket_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    smt_socket_new

    Type: Component method
    Creates and initialises a new smt_socket_t object, returns a
    reference to the created object.
    Creates a new socket.  After creating a socket you should set any options
    that your application requires, and then call smt_socket_connect or
    smt_socket_passive as appropriate.
    -------------------------------------------------------------------------
 */

smt_socket_t *
    smt_socket_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
apr_status_t
    status;
    smt_socket_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_NEW))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_NEW))
    icl_trace_record (NULL, smt_socket_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_NEW))
    icl_stats_inc ("smt_socket_new", &s_smt_socket_new_stats);
#endif

    self = smt_socket_alloc_ (file, line);
    if (self) {
        self->object_tag   = SMT_SOCKET_ALIVE;
#if defined (DEBUG)
        icl_mem_set_callback (self, smt_socket_show_);
#endif

status = apr_pool_create (&self->pollfd.p, icl_global_pool);
if (status == APR_SUCCESS) {
    apr_pool_tag    (self->pollfd.p, "smt_socket_new");
    self->io_size = 0;

    self->request_list = smt_socket_request_by_socket_new ();

    self->pollfd.desc_type   = APR_POLL_SOCKET;
    //  apr_pollset_poll may be implemented using select, in which case we
    //  need to explicitly ask for APR_POLLHUP, APR_POLLERR and APR_POLLNVAL
    self->pollfd.reqevents   = APR_POLLHUP | APR_POLLERR | APR_POLLNVAL;
    self->pollfd.rtnevents   = 0;
    self->pollfd.client_data = self;
    self->trace              = FALSE;
    status = apr_socket_create (&self->pollfd.desc.s,
        APR_INET, SOCK_STREAM, APR_PROTO_TCP, self->pollfd.p);
    if (status != APR_SUCCESS)
        smt_socket_destroy (&self);
}
else
    smt_socket_destroy (&self);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_NEW))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_NEW))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_new_finish"
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
    smt_socket_annihilate

    Type: Component method
    Closes an open socket and immediately cancels any requests waiting on
    that socket.

    This method must be used to destroy sockets that are passively listening.

    This method may be used to rapidly close a connected socket.  If a tidy
    close is required, use smt_socket_request_close instead.
    -------------------------------------------------------------------------
 */

static void
    smt_socket_annihilate (
    smt_socket_t * ( * self_p )         //  Reference to object reference
)
{

smt_socket_request_t
    *socket_request;
smt_thread_t
    *thread;
    smt_socket_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_DESTROY))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_DESTROY))
    icl_trace_record (NULL, smt_socket_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_DESTROY))
    icl_stats_inc ("smt_socket_annihilate", &s_smt_socket_annihilate_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

//  Clear the socket request list first as we need to activate threads
//  as we destroy socket requests.
socket_request = smt_socket_request_by_socket_first (self->request_list);
while (socket_request) {
    thread = socket_request->thread;
    smt_socket_request_destroy (&socket_request);
    if (thread->pending_count == 0)
        smt_thread_activate (thread);

    socket_request = smt_socket_request_by_socket_first (self->request_list);
}
smt_socket_request_by_socket_destroy (&self->request_list);


//  Close apr socket if it was opened                                      
if (self->pollfd.desc.s)
    apr_socket_close (self->pollfd.desc.s);

//  Destroy apr pool                                                       
apr_pool_destroy (self->pollfd.p);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_DESTROY))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_DESTROY))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_destroy_finish"
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
    smt_socket_connect

    Type: Component method
    Accepts a smt_socket_t reference and returns zero in case of success,
    1 in case of errors.
    Connect to a remote service asychronously.

    Returns SMT_OK immediately if the request was correctly processed; returns
    SMT_SOCKET_ERROR on error.  Note that the socket is not connected
    when the function call returns, but only after the event has been
    delivered.
    -------------------------------------------------------------------------
 */

int
    smt_socket_connect (
    smt_socket_t * self,                //  Reference to object
    smt_thread_t * thread,              //  Thread to deliver reply to
    qbyte msecs,                        //  Timeout for connection
    const char * host,                  //  Host to connect to
    const char * service,               //  Service to connect to
    smt_event_t event                   //  Event to deliver on connection; SMT_NULL_EVENT for simple thread-blocking
)
{
apr_port_t
    port;
apr_sockaddr_t
    *sockaddr;
apr_status_t
    status;
char
    *endptr;
smt_socket_request_t
    *request;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_CONNECT))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_connect_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" msecs=\"%lu\""
" host=\"%pp\""
" service=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, msecs, host, service);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CONNECT))
    icl_trace_record (NULL, smt_socket_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CONNECT))
    icl_stats_inc ("smt_socket_connect", &s_smt_socket_connect_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

//  Look up host address and port number from service name.
port = (apr_port_t) strtol (service, &endptr, 10);
if (endptr && !*endptr)             //  Service is numeric                 
    status = apr_sockaddr_info_get (&sockaddr, host, APR_INET, port, 0, self->pollfd.p);
else {
    status = apr_sockaddr_info_get (&sockaddr, host, APR_INET, 0, 0, self->pollfd.p);
    if (status == APR_SUCCESS)
        status = apr_getservbyname (sockaddr, service);
}
if (status == APR_SUCCESS) {
    apr_socket_opt_set (self->pollfd.desc.s, APR_SO_NONBLOCK, 1);
    status = apr_socket_connect (self->pollfd.desc.s, sockaddr);
    if (APR_STATUS_IS_EINPROGRESS (status))
        status = APR_SUCCESS;
}
if (status == APR_SUCCESS) {
    request = smt_socket_request_new (thread,
                                      SOCK_CONNECT,
                                      self,
                                      msecs,
                                      SMT_NULL_EVENT,
                                      event);
    if (!request)
        rc = thread->result;
}
if (status != APR_SUCCESS)
    rc = SMT_SOCKET_ERROR;
if (rc != SMT_OK) {
    thread->result = rc;
    thread->error  = status;
    thread->catcher (thread);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CONNECT))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_CONNECT))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_connect_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" msecs=\"%lu\""
" host=\"%pp\""
" service=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, msecs, host, service, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_socket_passive

    Type: Component method
    Accepts a smt_socket_t reference and returns zero in case of success,
    1 in case of errors.
    Setup a socket for passive listening. The service should be a port number
    (as a string) or a well-known TCP/IP service.  The ipaddress can be NULL
    (for "0.0.0.0", meaning "all addresses that this server supports"), or a
    specific IP address, if wanted.  The queue length should be at least 3 and
    as much as 20-30 for very heavily used services.

    Returns SMT_OK immediately if the request was correctly processed;
    returns SMT_SOCKET_ERROR on error.
    -------------------------------------------------------------------------
 */

int
    smt_socket_passive (
    smt_socket_t * self,                //  Reference to object
    smt_thread_t * thread,              //  Thread to deliver reply to
    const char * service,               //  Service to listen on
    const char * ipaddress,             //  IP address to bind to
    int queue_length                    //  Length of connect queue
)
{
apr_port_t
    port;
apr_sockaddr_t
    *sockaddr;
apr_status_t
    status;
char
    *endptr;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_PASSIVE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_passive_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" service=\"%pp\""
" ipaddress=\"%pp\""
" queue_length=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, service, ipaddress, queue_length);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_PASSIVE))
    icl_trace_record (NULL, smt_socket_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_PASSIVE))
    icl_stats_inc ("smt_socket_passive", &s_smt_socket_passive_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

    //  Look up host address and port number from service name.
    port = (apr_port_t) strtol (service, &endptr, 10);
    if (endptr && !*endptr)             //  Service is numeric
        status = apr_sockaddr_info_get (&sockaddr, ipaddress, APR_INET, port, 0, self->pollfd.p);
    else {
        status = apr_sockaddr_info_get (&sockaddr, ipaddress, APR_INET, 0, 0, self->pollfd.p);
        if (status == APR_SUCCESS)
            status = apr_getservbyname (sockaddr, service);
    }
    if (status == APR_SUCCESS) {
        apr_socket_opt_set (self->pollfd.desc.s, APR_SO_NONBLOCK, 1);
#       if (!defined (__WINDOWS__))
        /*  On BSD-socket systems we need to do this to allow the server to
         *  restart on a previously-used socket, without an annoying timeout
         *  of several minutes.  With winsock the reuseaddr option lets the
         *  server work with an already-used socket (!), so we don't do it.
         */
        apr_socket_opt_set (self->pollfd.desc.s, APR_SO_REUSEADDR, 1);
#       endif

        status = apr_socket_bind (self->pollfd.desc.s, sockaddr);
    }
    if (status == APR_SUCCESS)
        status = apr_socket_listen (self->pollfd.desc.s, queue_length);
    if (status != APR_SUCCESS)
        rc = SMT_SOCKET_ERROR;
    if (rc != SMT_OK) {
        thread->result = rc;
        thread->error  = status;
        thread->catcher (thread);
    }

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_PASSIVE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_PASSIVE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_passive_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" thread=\"%pp\""
" service=\"%pp\""
" ipaddress=\"%pp\""
" queue_length=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, thread, service, ipaddress, queue_length, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_socket_set_nodelay

    Type: Component method
    Accepts a smt_socket_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the value of the TCP NODELAY option on the socket, which controls
    whether or not the Nagle algorithm is used for this socket.
    -------------------------------------------------------------------------
 */

int
    smt_socket_set_nodelay (
    smt_socket_t * self,                //  Reference to object
    int value                           //  Option value
)
{
apr_status_t
    status;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_SET_NODELAY))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_set_nodelay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" value=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, value);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SET_NODELAY))
    icl_trace_record (NULL, smt_socket_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SET_NODELAY))
    icl_stats_inc ("smt_socket_set_nodelay", &s_smt_socket_set_nodelay_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

status = apr_socket_opt_set (self->pollfd.desc.s, APR_TCP_NODELAY, value);
if (status != APR_SUCCESS)
    rc = SMT_SOCKET_ERROR;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SET_NODELAY))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_SET_NODELAY))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_set_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" value=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, value, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_socket_set_rcvbuf

    Type: Component method
    Accepts a smt_socket_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the TCP receive buffer size for the socket. Returns the old buffer 
    size, if known. Should be called before calling smt_socket_connect or
    smt_socket_passive on the socket.
    -------------------------------------------------------------------------
 */

int
    smt_socket_set_rcvbuf (
    smt_socket_t * self,                //  Reference to object
    int new_size,                       //  New buffer size
    int * old_size                      //  Old buffer size
)
{
apr_status_t
    status = APR_SUCCESS;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_SET_RCVBUF))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_set_rcvbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" new_size=\"%i\""
" old_size=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, new_size, old_size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SET_RCVBUF))
    icl_trace_record (NULL, smt_socket_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SET_RCVBUF))
    icl_stats_inc ("smt_socket_set_rcvbuf", &s_smt_socket_set_rcvbuf_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

if (old_size)
    status = apr_socket_opt_get (self->pollfd.desc.s, APR_SO_RCVBUF, old_size);
if (status == APR_SUCCESS)
    status = apr_socket_opt_set (self->pollfd.desc.s, APR_SO_RCVBUF, new_size);
if (status != APR_SUCCESS)
    rc = SMT_SOCKET_ERROR;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SET_RCVBUF))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_SET_RCVBUF))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_set_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" new_size=\"%i\""
" old_size=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, new_size, old_size, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_socket_set_sndbuf

    Type: Component method
    Accepts a smt_socket_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the TCP send buffer size for the socket. Returns the old buffer 
    size, if known. Should be called before calling smt_socket_connect or
    smt_socket_passive on the socket.
    -------------------------------------------------------------------------
 */

int
    smt_socket_set_sndbuf (
    smt_socket_t * self,                //  Reference to object
    int new_size,                       //  New buffer size
    int * old_size                      //  Old buffer size
)
{
apr_status_t
    status = APR_SUCCESS;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_SET_SNDBUF))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_set_sndbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" new_size=\"%i\""
" old_size=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, new_size, old_size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SET_SNDBUF))
    icl_trace_record (NULL, smt_socket_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SET_SNDBUF))
    icl_stats_inc ("smt_socket_set_sndbuf", &s_smt_socket_set_sndbuf_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

if (old_size)
    status = apr_socket_opt_get (self->pollfd.desc.s, APR_SO_SNDBUF, old_size);
if (status == APR_SUCCESS)
    status = apr_socket_opt_set (self->pollfd.desc.s, APR_SO_SNDBUF, new_size);
if (status != APR_SUCCESS)
    rc = SMT_SOCKET_ERROR;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SET_SNDBUF))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_SET_SNDBUF))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_set_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" new_size=\"%i\""
" old_size=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, new_size, old_size, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_socket_peeraddr

    Type: Component method
    Returns the peer IP address of a connected socket, if any.
    -------------------------------------------------------------------------
 */

char *
    smt_socket_peeraddr (
    smt_socket_t * self                 //  Not documented
)
{
apr_sockaddr_t
    *sockaddr;
    char *
        addr;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_PEERADDR))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_peeraddr_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_PEERADDR))
    icl_trace_record (NULL, smt_socket_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_PEERADDR))
    icl_stats_inc ("smt_socket_peeraddr", &s_smt_socket_peeraddr_stats);
#endif

apr_socket_addr_get (&sockaddr, APR_REMOTE, self->pollfd.desc.s);
apr_sockaddr_ip_get (&addr, sockaddr);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_PEERADDR))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_PEERADDR))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_peeraddr_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" addr=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, addr);
#endif


    return (addr);
}
/*  -------------------------------------------------------------------------
    smt_socket_trace

    Type: Component method
    Accepts a smt_socket_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the trace flag for this socket.
    -------------------------------------------------------------------------
 */

int
    smt_socket_trace (
    smt_socket_t * self,                //  Reference to object
    Bool enabled                        //  Not documented
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_TRACE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_TRACE))
    icl_trace_record (NULL, smt_socket_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_TRACE))
    icl_stats_inc ("smt_socket_trace", &s_smt_socket_trace_stats);
#endif

SMT_SOCKET_ASSERT_SANE (self);

self->trace = enabled;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_TRACE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_TRACE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" enabled=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, enabled, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    smt_socket_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_socket_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_SELFTEST))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SELFTEST))
    icl_trace_record (NULL, smt_socket_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SELFTEST))
    icl_stats_inc ("smt_socket_selftest", &s_smt_socket_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SELFTEST))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_SELFTEST))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_selftest_finish"
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
    smt_socket_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_socket_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_TERMINATE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_TERMINATE))
    icl_trace_record (NULL, smt_socket_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_TERMINATE))
    icl_stats_inc ("smt_socket_terminate", &s_smt_socket_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_TERMINATE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_TERMINATE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_terminate_finish"
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
    smt_socket_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_socket_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
smt_socket_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_SHOW))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SHOW))
    icl_trace_record (NULL, smt_socket_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SHOW))
    icl_stats_inc ("smt_socket_show", &s_smt_socket_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <smt_socket file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SHOW))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_SHOW))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_show_finish"
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
    smt_socket_destroy

    Type: Component method
    Destroys a smt_socket_t object. Takes the address of a
    smt_socket_t reference (a pointer to a pointer) and nullifies the
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
    smt_socket_destroy_ (
    smt_socket_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    smt_socket_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_DESTROY_PUBLIC))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_socket_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_DESTROY_PUBLIC))
    icl_stats_inc ("smt_socket_destroy", &s_smt_socket_destroy_stats);
#endif

if (self) {
    smt_socket_annihilate (self_p);
    smt_socket_free ((smt_socket_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_DESTROY_PUBLIC))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_DESTROY_PUBLIC))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_destroy_public_finish"
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
    smt_socket_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static smt_socket_t *
    smt_socket_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    smt_socket_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_ALLOC))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_ALLOC))
    icl_trace_record (NULL, smt_socket_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_ALLOC))
    icl_stats_inc ("smt_socket_alloc", &s_smt_socket_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    smt_socket_cache_initialise ();

self = (smt_socket_t *) icl_mem_cache_alloc_ (s_cache, file, line);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_ALLOC))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_ALLOC))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_alloc_finish"
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
    smt_socket_free

    Type: Component method
    Freess a smt_socket_t object.
    -------------------------------------------------------------------------
 */

static void
    smt_socket_free (
    smt_socket_t * self                 //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_FREE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_FREE))
    icl_trace_record (NULL, smt_socket_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_FREE))
    icl_stats_inc ("smt_socket_free", &s_smt_socket_free_stats);
#endif

if (self) {

    self->object_tag = SMT_SOCKET_DEAD;
    icl_mem_free (self);
}
self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_FREE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_FREE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_free_finish"
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
    smt_socket_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    smt_socket_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_CACHE_INITIALISE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_socket_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CACHE_INITIALISE))
    icl_stats_inc ("smt_socket_cache_initialise", &s_smt_socket_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (smt_socket_t));
icl_system_register (smt_socket_cache_purge, smt_socket_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_INITIALISE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_CACHE_INITIALISE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_cache_initialise_finish"
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
    smt_socket_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_socket_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_CACHE_PURGE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_PURGE))
    icl_trace_record (NULL, smt_socket_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CACHE_PURGE))
    icl_stats_inc ("smt_socket_cache_purge", &s_smt_socket_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_PURGE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_CACHE_PURGE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_cache_purge_finish"
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
    smt_socket_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    smt_socket_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_CACHE_TERMINATE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_socket_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_CACHE_TERMINATE))
    icl_stats_inc ("smt_socket_cache_terminate", &s_smt_socket_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_TERMINATE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_CACHE_TERMINATE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_cache_terminate_finish"
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
    smt_socket_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    smt_socket_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_SHOW_ANIMATION))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_socket_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_SHOW_ANIMATION))
    icl_stats_inc ("smt_socket_show_animation", &s_smt_socket_show_animation_stats);
#endif

smt_socket_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_SHOW_ANIMATION))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_SHOW_ANIMATION))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_show_animation_finish"
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
    smt_socket_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    smt_socket_new_in_scope_ (
    smt_socket_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_SMT_SOCKET)  ||  defined (BASE_ANIMATE_SMT_SOCKET_NEW_IN_SCOPE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_socket_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_SMT_SOCKET)  ||  defined (BASE_STATS_SMT_SOCKET_NEW_IN_SCOPE))
    icl_stats_inc ("smt_socket_new_in_scope", &s_smt_socket_new_in_scope_stats);
#endif

*self_p = smt_socket_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) smt_socket_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_NEW_IN_SCOPE))
    icl_trace_record (NULL, smt_socket_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_SMT_SOCKET)   || defined (BASE_ANIMATE_SMT_SOCKET_NEW_IN_SCOPE))
    if (smt_socket_animating)
        icl_console_print ("<smt_socket_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, _destroy);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_SMT_SOCKET)   || defined (BASE_TRACE_SMT_SOCKET_NEW)   || defined (BASE_TRACE_SMT_SOCKET_DESTROY)   || defined (BASE_TRACE_SMT_SOCKET_CONNECT)   || defined (BASE_TRACE_SMT_SOCKET_PASSIVE)   || defined (BASE_TRACE_SMT_SOCKET_SET_NODELAY)   || defined (BASE_TRACE_SMT_SOCKET_SET_RCVBUF)   || defined (BASE_TRACE_SMT_SOCKET_SET_SNDBUF)   || defined (BASE_TRACE_SMT_SOCKET_PEERADDR)   || defined (BASE_TRACE_SMT_SOCKET_TRACE)   || defined (BASE_TRACE_SMT_SOCKET_SELFTEST)   || defined (BASE_TRACE_SMT_SOCKET_TERMINATE)   || defined (BASE_TRACE_SMT_SOCKET_SHOW)   || defined (BASE_TRACE_SMT_SOCKET_DESTROY_PUBLIC)   || defined (BASE_TRACE_SMT_SOCKET_ALLOC)   || defined (BASE_TRACE_SMT_SOCKET_FREE)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_INITIALISE)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_PURGE)   || defined (BASE_TRACE_SMT_SOCKET_CACHE_TERMINATE)   || defined (BASE_TRACE_SMT_SOCKET_SHOW_ANIMATION)   || defined (BASE_TRACE_SMT_SOCKET_NEW_IN_SCOPE) )
void
smt_socket_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "connect"; break;
        case 4: method_name = "passive"; break;
        case 5: method_name = "set nodelay"; break;
        case 6: method_name = "set rcvbuf"; break;
        case 7: method_name = "set sndbuf"; break;
        case 8: method_name = "peeraddr"; break;
        case 9: method_name = "trace"; break;
        case 10: method_name = "selftest"; break;
        case 11: method_name = "terminate"; break;
        case 12: method_name = "show"; break;
        case 13: method_name = "destroy public"; break;
        case 14: method_name = "alloc"; break;
        case 15: method_name = "free"; break;
        case 16: method_name = "cache initialise"; break;
        case 17: method_name = "cache purge"; break;
        case 18: method_name = "cache terminate"; break;
        case 19: method_name = "show animation"; break;
        case 20: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "smt_socket %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *smt_socket_version_start     = "VeRsIoNsTaRt:ipc";
char *smt_socket_component         = "smt_socket ";
char *smt_socket_version           = "1.0 ";
char *smt_socket_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *smt_socket_filename          = "smt_socket.icl ";
char *smt_socket_builddate         = "2009/02/19 ";
char *smt_socket_version_end       = "VeRsIoNeNd:ipc";

