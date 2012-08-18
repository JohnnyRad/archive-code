/*---------------------------------------------------------------------------
    example.c - example component

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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "example.h"                    //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              example_t

//  Shorthands for class methods                                               

#define self_new            example_new
#define self_annihilate     example_annihilate
#define self_load_xmlfile   example_load_xmlfile
#define self_load_bucket    example_load_bucket
#define self_shadow         example_shadow
#define self_commit         example_commit
#define self_rollback       example_rollback
#define self_cmdline_help   example_cmdline_help
#define self_cmdline_parse  example_cmdline_parse
#define self_options_help   example_options_help
#define self_set_port       example_set_port
#define self_port           example_port
#define self_set_monitor    example_set_monitor
#define self_monitor        example_monitor
#define self_set_max_memory_mb  example_set_max_memory_mb
#define self_max_memory_mb  example_max_memory_mb
#define self_set_record_stats  example_set_record_stats
#define self_record_stats   example_record_stats
#define self_set_packio     example_set_packio
#define self_packio         example_packio
#define self_set_heartbeat  example_set_heartbeat
#define self_heartbeat      example_heartbeat
#define self_set_read_timeout  example_set_read_timeout
#define self_read_timeout   example_read_timeout
#define self_set_write_timeout  example_set_write_timeout
#define self_write_timeout  example_write_timeout
#define self_set_tcp_nodelay  example_set_tcp_nodelay
#define self_tcp_nodelay    example_tcp_nodelay
#define self_set_tcp_rcvbuf  example_set_tcp_rcvbuf
#define self_tcp_rcvbuf     example_tcp_rcvbuf
#define self_set_tcp_sndbuf  example_set_tcp_sndbuf
#define self_tcp_sndbuf     example_tcp_sndbuf
#define self_set_frame_max  example_set_frame_max
#define self_frame_max      example_frame_max
#define self_set_log_path   example_set_log_path
#define self_log_path       example_log_path
#define self_set_keep_logs  example_set_keep_logs
#define self_keep_logs      example_keep_logs
#define self_set_archive_path  example_set_archive_path
#define self_archive_path   example_archive_path
#define self_set_archive_cmd  example_set_archive_cmd
#define self_archive_cmd    example_archive_cmd
#define self_set_alert_log  example_set_alert_log
#define self_alert_log      example_alert_log
#define self_set_daily_log  example_set_daily_log
#define self_daily_log      example_daily_log
#define self_set_debug_log  example_set_debug_log
#define self_debug_log      example_debug_log
#define self_set_trace      example_set_trace
#define self_trace          example_trace
#define self_dump_log       example_dump_log
#define self_selftest       example_selftest
#define self_terminate      example_terminate
#define self_show           example_show
#define self_destroy        example_destroy
#define self_alloc          example_alloc
#define self_free           example_free
#define self_read_lock      example_read_lock
#define self_write_lock     example_write_lock
#define self_unlock         example_unlock
#define self_cache_initialise  example_cache_initialise
#define self_cache_purge    example_cache_purge
#define self_cache_terminate  example_cache_terminate
#define self_show_animation  example_show_animation
#define self_new_in_scope   example_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_NEW))
static icl_stats_t *s_example_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DESTROY))
static icl_stats_t *s_example_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_LOAD_XMLFILE))
static icl_stats_t *s_example_load_xmlfile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_LOAD_BUCKET))
static icl_stats_t *s_example_load_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SHADOW))
static icl_stats_t *s_example_shadow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_COMMIT))
static icl_stats_t *s_example_commit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ROLLBACK))
static icl_stats_t *s_example_rollback_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CMDLINE_HELP))
static icl_stats_t *s_example_cmdline_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CMDLINE_PARSE))
static icl_stats_t *s_example_cmdline_parse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_OPTIONS_HELP))
static icl_stats_t *s_example_options_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_PORT))
static icl_stats_t *s_example_set_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_PORT))
static icl_stats_t *s_example_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_MONITOR))
static icl_stats_t *s_example_set_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_MONITOR))
static icl_stats_t *s_example_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_MAX_MEMORY_MB))
static icl_stats_t *s_example_set_max_memory_mb_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_MAX_MEMORY_MB))
static icl_stats_t *s_example_max_memory_mb_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_RECORD_STATS))
static icl_stats_t *s_example_set_record_stats_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_RECORD_STATS))
static icl_stats_t *s_example_record_stats_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_PACKIO))
static icl_stats_t *s_example_set_packio_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_PACKIO))
static icl_stats_t *s_example_packio_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_HEARTBEAT))
static icl_stats_t *s_example_set_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_HEARTBEAT))
static icl_stats_t *s_example_heartbeat_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_READ_TIMEOUT))
static icl_stats_t *s_example_set_read_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_READ_TIMEOUT))
static icl_stats_t *s_example_read_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_WRITE_TIMEOUT))
static icl_stats_t *s_example_set_write_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_WRITE_TIMEOUT))
static icl_stats_t *s_example_write_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TCP_NODELAY))
static icl_stats_t *s_example_set_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TCP_NODELAY))
static icl_stats_t *s_example_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TCP_RCVBUF))
static icl_stats_t *s_example_set_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TCP_RCVBUF))
static icl_stats_t *s_example_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TCP_SNDBUF))
static icl_stats_t *s_example_set_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TCP_SNDBUF))
static icl_stats_t *s_example_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_FRAME_MAX))
static icl_stats_t *s_example_set_frame_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_FRAME_MAX))
static icl_stats_t *s_example_frame_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_LOG_PATH))
static icl_stats_t *s_example_set_log_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_LOG_PATH))
static icl_stats_t *s_example_log_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_KEEP_LOGS))
static icl_stats_t *s_example_set_keep_logs_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_KEEP_LOGS))
static icl_stats_t *s_example_keep_logs_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_ARCHIVE_PATH))
static icl_stats_t *s_example_set_archive_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ARCHIVE_PATH))
static icl_stats_t *s_example_archive_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_ARCHIVE_CMD))
static icl_stats_t *s_example_set_archive_cmd_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ARCHIVE_CMD))
static icl_stats_t *s_example_archive_cmd_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_ALERT_LOG))
static icl_stats_t *s_example_set_alert_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ALERT_LOG))
static icl_stats_t *s_example_alert_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_DAILY_LOG))
static icl_stats_t *s_example_set_daily_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DAILY_LOG))
static icl_stats_t *s_example_daily_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_DEBUG_LOG))
static icl_stats_t *s_example_set_debug_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DEBUG_LOG))
static icl_stats_t *s_example_debug_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TRACE))
static icl_stats_t *s_example_set_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TRACE))
static icl_stats_t *s_example_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DUMP_LOG))
static icl_stats_t *s_example_dump_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SELFTEST))
static icl_stats_t *s_example_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TERMINATE))
static icl_stats_t *s_example_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SHOW))
static icl_stats_t *s_example_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DESTROY_PUBLIC))
static icl_stats_t *s_example_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ALLOC))
static icl_stats_t *s_example_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_FREE))
static icl_stats_t *s_example_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_READ_LOCK))
static icl_stats_t *s_example_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_WRITE_LOCK))
static icl_stats_t *s_example_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_UNLOCK))
static icl_stats_t *s_example_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CACHE_INITIALISE))
static icl_stats_t *s_example_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CACHE_PURGE))
static icl_stats_t *s_example_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CACHE_TERMINATE))
static icl_stats_t *s_example_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SHOW_ANIMATION))
static icl_stats_t *s_example_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_NEW_IN_SCOPE))
static icl_stats_t *s_example_new_in_scope_stats = NULL;
#endif
static void
    example_annihilate (
example_t * ( * self_p )                //  Reference to object reference
);

#define example_alloc()                 example_alloc_ (__FILE__, __LINE__)
static example_t *
    example_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    example_free (
example_t * self                        //  Object reference
);

static void
    example_cache_initialise (
void);

static void
    example_cache_purge (
void);

static void
    example_cache_terminate (
void);

Bool
    example_animating = TRUE;           //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void s_validate_items (example_t *self);
static void s_get_properties (example_t *self);
example_t
    *example_config = NULL;             //  Global properties
static void s_validate_items (example_t *self)
{
    char
        *item_name;

    //  Locate first child and check all items for validity
    ipr_config_locate (self->config, "/config/+", "");
    while (self->config->located) {
        item_name = ipr_config_item (self->config);
        if (streq (item_name, "echo"))
            icl_console_print ("I: %s: %s", self->filename, ipr_config_value (self->config));
        else
        if (strneq (item_name, "server")
        && strneq (item_name, "resources")
        && strneq (item_name, "tuning")
        && strneq (item_name, "logging"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->config);
    }
}

static void s_get_properties (example_t *self)
{
    char
        *value;                         //  Configured value

    //  All properties on server path
    ipr_config_locate (self->config, "/config/server", NULL);

    //  Get port property from config file or built-in defaults
    value = ipr_config_get (self->config, "port", NULL);
    if (value)
        self->port = value;
    else
        self->port = "7654";

    //  All properties on resources path
    ipr_config_locate (self->config, "/config/resources", NULL);

    //  Get monitor property from config file or built-in defaults
    value = ipr_config_get (self->config, "monitor", NULL);
    if (value)
        self->monitor = (int) atol (value);
    else
        self->monitor = 1;

    //  Get max_memory_mb property from config file or built-in defaults
    value = ipr_config_get (self->config, "max_memory_mb", NULL);
    if (value)
        self->max_memory_mb = (size_t) atol (value);
    else
        self->max_memory_mb = 0;

    //  Get record_stats property from config file or built-in defaults
    value = ipr_config_get (self->config, "record_stats", NULL);
    if (value)
        self->record_stats = (Bool) atol (value);
    else
        self->record_stats = 0;

    //  All properties on tuning path
    ipr_config_locate (self->config, "/config/tuning", NULL);

    //  Get packio property from config file or built-in defaults
    value = ipr_config_get (self->config, "packio", NULL);
    if (value)
        self->packio = (int) atol (value);
    else
        self->packio = 1;

    //  Get heartbeat property from config file or built-in defaults
    value = ipr_config_get (self->config, "heartbeat", NULL);
    if (value)
        self->heartbeat = (int) atol (value);
    else
        self->heartbeat = 2;

    //  Get read_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "read_timeout", NULL);
    if (value)
        self->read_timeout = (int) atol (value);
    else
        self->read_timeout = 30;

    //  Get write_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "write_timeout", NULL);
    if (value)
        self->write_timeout = (int) atol (value);
    else
        self->write_timeout = 30;

    //  Get tcp_nodelay property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_nodelay", NULL);
    if (value)
        self->tcp_nodelay = (Bool) atol (value);
    else
        self->tcp_nodelay = 1;

    //  Get tcp_rcvbuf property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_rcvbuf", NULL);
    if (value)
        self->tcp_rcvbuf = (int) atol (value);
    else
        self->tcp_rcvbuf = 0;

    //  Get tcp_sndbuf property from config file or built-in defaults
    value = ipr_config_get (self->config, "tcp_sndbuf", NULL);
    if (value)
        self->tcp_sndbuf = (int) atol (value);
    else
        self->tcp_sndbuf = 0;

    //  Get frame_max property from config file or built-in defaults
    value = ipr_config_get (self->config, "frame_max", NULL);
    if (value)
        self->frame_max = (int) atol (value);
    else
        self->frame_max = 32768;
    if (self->frame_max < 2048) {
        icl_console_print ("W: %s: illegal value %d for frame_max, using %d",
            self->filename, self->frame_max, 2048);
        self->frame_max = 2048;
    }
    if (self->frame_max > 4194304) {
        icl_console_print ("W: %s: illegal value %d for frame_max, using %d",
            self->filename, self->frame_max, 4194304);
        self->frame_max = 4194304;
    }

    //  All properties on logging path
    ipr_config_locate (self->config, "/config/logging", NULL);

    //  Get log_path property from config file or built-in defaults
    value = ipr_config_get (self->config, "log_path", NULL);
    if (value)
        self->log_path = value;
    else
        self->log_path = "logs";

    //  Get keep_logs property from config file or built-in defaults
    value = ipr_config_get (self->config, "keep_logs", NULL);
    if (value)
        self->keep_logs = (Bool) atol (value);
    else
        self->keep_logs = 1;

    //  Get archive_path property from config file or built-in defaults
    value = ipr_config_get (self->config, "archive_path", NULL);
    if (value)
        self->archive_path = value;
    else
        self->archive_path = "archive";

    //  Get archive_cmd property from config file or built-in defaults
    value = ipr_config_get (self->config, "archive_cmd", NULL);
    if (value)
        self->archive_cmd = value;
    else
        self->archive_cmd = "";

    //  Get alert_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "alert_log", NULL);
    if (value)
        self->alert_log = value;
    else
        self->alert_log = "alert.log";

    //  Get daily_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "daily_log", NULL);
    if (value)
        self->daily_log = value;
    else
        self->daily_log = "daily.log";

    //  Get debug_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_log", NULL);
    if (value)
        self->debug_log = value;
    else
        self->debug_log = "debug.log";

    //  Get trace property from config file or built-in defaults
    value = ipr_config_get (self->config, "trace", NULL);
    if (value)
        self->trace = (int) atol (value);
    else
        self->trace = 0;
}
/*  -------------------------------------------------------------------------
    example_new

    Type: Component method
    Creates and initialises a new example_t object, returns a
    reference to the created object.
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    -------------------------------------------------------------------------
 */

example_t *
    example_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    example_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_NEW))
    if (example_animating)
        icl_console_print ("<example_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_NEW))
    icl_trace_record (NULL, example_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_NEW))
    icl_stats_inc ("example_new", &s_example_new_stats);
#endif

    self = example_alloc_ (file, line);
    if (self) {
        self->object_tag   = EXAMPLE_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, example_show_);
#endif

//
self->config = ipr_config_new (NULL, FALSE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_NEW))
    icl_trace_record (NULL, example_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_NEW))
    if (example_animating)
        icl_console_print ("<example_new_finish"
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
    example_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    example_annihilate (
    example_t * ( * self_p )            //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    example_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_DESTROY))
    if (example_animating)
        icl_console_print ("<example_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DESTROY))
    icl_trace_record (NULL, example_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DESTROY))
    icl_stats_inc ("example_annihilate", &s_example_annihilate_stats);
#endif

    EXAMPLE_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

ipr_config_destroy (&self->config);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DESTROY))
    icl_trace_record (NULL, example_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_DESTROY))
    if (example_animating)
        icl_console_print ("<example_destroy_finish"
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
    example_load_xmlfile

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    example_load_xmlfile (
    example_t * self,                   //  Reference to object
    char * filename,                    //  Config file to load
    Bool required                       //  Config file is required?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_LOAD_XMLFILE))
    if (example_animating)
        icl_console_print ("<example_load_xmlfile_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_LOAD_XMLFILE))
    icl_trace_record (NULL, example_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_LOAD_XMLFILE))
    icl_stats_inc ("example_load_xmlfile", &s_example_load_xmlfile_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

//
assert (filename);
if (!ipr_config_load (self->config, filename, required)) {
    icl_shortstr_cpy (self->filename, filename);
    s_validate_items (self);
    s_get_properties (self);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_LOAD_XMLFILE))
    icl_trace_record (NULL, example_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_LOAD_XMLFILE))
    if (example_animating)
        icl_console_print ("<example_load_xmlfile_finish"
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
    example_load_bucket

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    example_load_bucket (
    example_t * self,                   //  Reference to object
    ipr_bucket_t * bucket               //  Config data to load
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_LOAD_BUCKET))
    if (example_animating)
        icl_console_print ("<example_load_bucket_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_LOAD_BUCKET))
    icl_trace_record (NULL, example_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_LOAD_BUCKET))
    icl_stats_inc ("example_load_bucket", &s_example_load_bucket_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->config, bucket);
s_validate_items (self);
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_LOAD_BUCKET))
    icl_trace_record (NULL, example_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_LOAD_BUCKET))
    if (example_animating)
        icl_console_print ("<example_load_bucket_finish"
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
    example_shadow

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    -------------------------------------------------------------------------
 */

int
    example_shadow (
    example_t * self,                   //  Reference to object
    ipr_config_t * source               //  Config data to shadow
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SHADOW))
    if (example_animating)
        icl_console_print ("<example_shadow_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" source=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, source);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SHADOW))
    icl_trace_record (NULL, example_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SHADOW))
    icl_stats_inc ("example_shadow", &s_example_shadow_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

//
//  Get rid of our own config data
ipr_config_destroy (&self->config);
//  Grab a handle onto the source data
self->config = ipr_config_dup (source);
//  Update our properties, without validation
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SHADOW))
    icl_trace_record (NULL, example_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SHADOW))
    if (example_animating)
        icl_console_print ("<example_shadow_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" source=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, source, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_commit

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    -------------------------------------------------------------------------
 */

int
    example_commit (
    example_t * self,                   //  Reference to object
    char * filename                     //  Config file to save
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_COMMIT))
    if (example_animating)
        icl_console_print ("<example_commit_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_COMMIT))
    icl_trace_record (NULL, example_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_COMMIT))
    icl_stats_inc ("example_commit", &s_example_commit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
if (filename)
    ipr_config_save (self->config, filename);
else
if (strused (self->filename))
    ipr_config_save (self->config, self->filename);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_COMMIT))
    icl_trace_record (NULL, example_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_COMMIT))
    if (example_animating)
        icl_console_print ("<example_commit_finish"
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
    example_rollback

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    -------------------------------------------------------------------------
 */

int
    example_rollback (
    example_t * self                    //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_ROLLBACK))
    if (example_animating)
        icl_console_print ("<example_rollback_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ROLLBACK))
    icl_trace_record (NULL, example_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ROLLBACK))
    icl_stats_inc ("example_rollback", &s_example_rollback_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
ipr_config_destroy (&self->config);
self->config = ipr_config_new (self->filename, TRUE);
s_get_properties (self);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ROLLBACK))
    icl_trace_record (NULL, example_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_ROLLBACK))
    if (example_animating)
        icl_console_print ("<example_rollback_finish"
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
    example_cmdline_help

    Type: Component method
    Prints command-line help for setting options from the command
    line.
    -------------------------------------------------------------------------
 */

void
    example_cmdline_help (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_CMDLINE_HELP))
    if (example_animating)
        icl_console_print ("<example_cmdline_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_HELP))
    icl_trace_record (NULL, example_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CMDLINE_HELP))
    icl_stats_inc ("example_cmdline_help", &s_example_cmdline_help_stats);
#endif

printf ("Options that override config values; these take an argument:\n");
printf ("  --port           Server port for client connections\n");
printf ("  --monitor        Monitor interval, seconds\n");
printf ("  --max_memory_mb  Maximum allowed memory, MBytes\n");
printf ("  --record_stats   Record performance statistics\n");
printf ("  --packio         Pack network data before writing\n");
printf ("  --heartbeat      Heartbeat from client to server, seconds\n");
printf ("  --read_timeout   Timeout on network reads, seconds\n");
printf ("  --write_timeout  Timeout on network writes, seconds\n");
printf ("  --tcp_nodelay    TCP/IP NDELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
printf ("  --frame_max      Maximum size of AMQP content frames\n");
printf ("  --log_path       Active log file directory\n");
printf ("  --keep_logs      Keep log files\n");
printf ("  --archive_path   Archive log file directory\n");
printf ("  --archive_cmd    Archive command\n");
printf ("  --alert_log      Alert log file name\n");
printf ("  --daily_log      Daily log file name\n");
printf ("  --debug_log      Debug log file name\n");
printf ("  --trace          Protocol trace level\n");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_HELP))
    icl_trace_record (NULL, example_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_CMDLINE_HELP))
    if (example_animating)
        icl_console_print ("<example_cmdline_help_finish"
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
    example_cmdline_parse

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    -------------------------------------------------------------------------
 */

int
    example_cmdline_parse (
    example_t * self,                   //  Reference to object
    char * name,                        //  Name of application
    int argc,                           //  Argument count
    char ** argv                        //  Argument list
)
{
int
    argn;                           //  Argument number
char
    *arg_name,
    *arg_value;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_CMDLINE_PARSE))
    if (example_animating)
        icl_console_print ("<example_cmdline_parse_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" argc=\"%i\""
" argv=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, argc, argv);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_PARSE))
    icl_trace_record (NULL, example_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CMDLINE_PARSE))
    icl_stats_inc ("example_cmdline_parse", &s_example_cmdline_parse_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

//
argn = 1;
while (argn < argc) {
    arg_name = argv [argn];
    if (streq (arg_name, "--help")) {
        self_options_help (self, name);
        exit (EXIT_SUCCESS);
    }
    else
    if (ipr_str_prefixed (argv [argn], "--")) {
        argn++;
        if (argn < argc && *argv [argn] != '-') {
            arg_value = argv [argn];
            argn++;

            //  Set property
            if (streq (arg_name, "--port"))
                self_set_port (self, arg_value);
            else
            if (streq (arg_name, "--monitor"))
                self_set_monitor (self, atoi (arg_value));
            else
            if (streq (arg_name, "--max_memory_mb"))
                self_set_max_memory_mb (self, atoi (arg_value));
            else
            if (streq (arg_name, "--record_stats"))
                self_set_record_stats (self, atoi (arg_value));
            else
            if (streq (arg_name, "--packio"))
                self_set_packio (self, atoi (arg_value));
            else
            if (streq (arg_name, "--heartbeat"))
                self_set_heartbeat (self, atoi (arg_value));
            else
            if (streq (arg_name, "--read_timeout"))
                self_set_read_timeout (self, atoi (arg_value));
            else
            if (streq (arg_name, "--write_timeout"))
                self_set_write_timeout (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_nodelay"))
                self_set_tcp_nodelay (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_rcvbuf"))
                self_set_tcp_rcvbuf (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_sndbuf"))
                self_set_tcp_sndbuf (self, atoi (arg_value));
            else
            if (streq (arg_name, "--frame_max"))
                self_set_frame_max (self, atoi (arg_value));
            else
            if (streq (arg_name, "--log_path"))
                self_set_log_path (self, arg_value);
            else
            if (streq (arg_name, "--keep_logs"))
                self_set_keep_logs (self, atoi (arg_value));
            else
            if (streq (arg_name, "--archive_path"))
                self_set_archive_path (self, arg_value);
            else
            if (streq (arg_name, "--archive_cmd"))
                self_set_archive_cmd (self, arg_value);
            else
            if (streq (arg_name, "--alert_log"))
                self_set_alert_log (self, arg_value);
            else
            if (streq (arg_name, "--daily_log"))
                self_set_daily_log (self, arg_value);
            else
            if (streq (arg_name, "--debug_log"))
                self_set_debug_log (self, arg_value);
            else
            if (streq (arg_name, "--trace"))
                self_set_trace (self, atoi (arg_value));
            else {
                icl_console_print ("E: unrecognised option '%s'", arg_name);
                exit (EXIT_FAILURE);
            }
        }
        else {
            icl_console_print ("E: %s option needs a parameter", arg_name);
            exit (EXIT_FAILURE);
        }
    }
    else
        argn++;
}
rc = argc;                          //  Return final arg count

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_PARSE))
    icl_trace_record (NULL, example_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_CMDLINE_PARSE))
    if (example_animating)
        icl_console_print ("<example_cmdline_parse_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" argc=\"%i\""
" argv=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, argc, argv, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_options_help

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Prints full help for all configuration options.
    -------------------------------------------------------------------------
 */

int
    example_options_help (
    example_t * self,                   //  Reference to object
    char * name                         //  Name of application
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_OPTIONS_HELP))
    if (example_animating)
        icl_console_print ("<example_options_help_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_OPTIONS_HELP))
    icl_trace_record (NULL, example_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_OPTIONS_HELP))
    icl_stats_inc ("example_options_help", &s_example_options_help_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

printf ("These are the configured options for %s\n\n", name);

printf ("/config/server/port - Server port for client connections\n");
printf ("    From command-line: --port newvalue\n");
printf ("    Specifies the port on which the server should open its connections.\n");
printf ("    Current value is '%s'. Default value is '7654'\n", self->port);
printf ("\n");

printf ("/config/resources/monitor - Monitor interval, seconds\n");
printf ("    From command-line: --monitor newvalue\n");
printf ("    Specifies the interval in seconds at which the server will report its   \n");
printf ("    message rates. If zero, no monitoring is shown. The recommended value is\n");
printf ("    1, if monitoring is desired.                                            \n");
printf ("    Current value is %i. Default value is 1.\n", self->monitor);
printf ("\n");

printf ("/config/resources/max_memory_mb - Maximum allowed memory, MBytes\n");
printf ("    From command-line: --max_memory_mb newvalue\n");
printf ("    Specifies the maximum memory allowed for the server, in MB. When the   \n");
printf ("    server reaches this limit, it will attempt to free resources and refuse\n");
printf ("    new connections until memory has been made available. If zero, no limit\n");
printf ("    is used.                                                               \n");
printf ("    Current value is %zu.\n", self->max_memory_mb);
printf ("\n");

printf ("/config/resources/record_stats - Record performance statistics\n");
printf ("    From command-line: --record_stats newvalue\n");
printf ("    Specifies whether or not the server records performance statistics in a \n");
printf ("    format suitable for importing into a spreadsheet. If set, the server    \n");
printf ("    creates a file called 'amq_server_stats_(portnumber).del' which contains\n");
printf ("    performance statistics in a comma-delimited format. For this setting to \n");
printf ("    take effect, the monitor option must also be set.                       \n");
printf ("    Current value is %i. Default value is 0.\n", self->record_stats);
printf ("\n");

printf ("/config/tuning/packio - Pack network data before writing\n");
printf ("    From command-line: --packio newvalue\n");
printf ("    If set, data is packed into larger buffers before writing. This can     \n");
printf ("    improve performance significantly on some systems, especially Windows   \n");
printf ("    and Linux with 2.4 kernels. If you disable this setting, you should test\n");
printf ("    the performance using a bulk message transfer test.                     \n");
printf ("    Current value is %i. Default value is 1.\n", self->packio);
printf ("\n");

printf ("/config/tuning/heartbeat - Heartbeat from client to server, seconds\n");
printf ("    From command-line: --heartbeat newvalue\n");
printf ("    Defines the timeout for connection heartbeating.\n");
printf ("    Current value is %i. Default value is 2.\n", self->heartbeat);
printf ("\n");

printf ("/config/tuning/read_timeout - Timeout on network reads, seconds\n");
printf ("    From command-line: --read_timeout newvalue\n");
printf ("    Defines the timeout for network reads. If a peer does not respond within\n");
printf ("    this time, it is considered dead. If you get unexpected timeout errors  \n");
printf ("    in the logs, you may want to increase this value.                       \n");
printf ("    Current value is %i. Default value is 30.\n", self->read_timeout);
printf ("\n");

printf ("/config/tuning/write_timeout - Timeout on network writes, seconds\n");
printf ("    From command-line: --write_timeout newvalue\n");
printf ("    Defines the timeout for network writes. If a peer does not accept data\n");
printf ("    within this time, it is considered dead. If you get unexpected timeout\n");
printf ("    errors in the logs, you may want to increase this value.              \n");
printf ("    Current value is %i. Default value is 30.\n", self->write_timeout);
printf ("\n");

printf ("/config/tuning/tcp_nodelay - TCP/IP NDELAY option\n");
printf ("    From command-line: --tcp_nodelay newvalue\n");
printf ("    If this value is 1, socket data is written immediately, which is usually\n");
printf ("    good for latency. If this value is 0, data is buffered until there is a \n");
printf ("    full packet, which is usually good for throughput.                      \n");
printf ("    Current value is %i. Default value is 1.\n", self->tcp_nodelay);
printf ("\n");

printf ("/config/tuning/tcp_rcvbuf - TCP/IP receive buffer, in bytes\n");
printf ("    From command-line: --tcp_rcvbuf newvalue\n");
printf ("    If this value is greater than zero, all client connections will use the\n");
printf ("    specified value. Note: setting this value is delicate, do not use this \n");
printf ("    option unless you know what you are doing.                             \n");
printf ("    Current value is %i.\n", self->tcp_rcvbuf);
printf ("\n");

printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\n");
printf ("    From command-line: --tcp_sndbuf newvalue\n");
printf ("    If this value is greater than zero, all client connections will use the\n");
printf ("    specified value. Note: setting this value is delicate, do not use this \n");
printf ("    option unless you know what you are doing.                             \n");
printf ("    Current value is %i.\n", self->tcp_sndbuf);
printf ("\n");

printf ("/config/tuning/frame_max - Maximum size of AMQP content frames\n");
printf ("    From command-line: --frame_max newvalue\n");
printf ("    Defines the maximum frame size the server will accept. Larger frame     \n");
printf ("    sizes are useful for applications that create very large message headers\n");
printf ("    but will cause congestion on multi-channel connections.                 \n");
printf ("    Current value is %i. Default value is 32768.\n", self->frame_max);
printf ("\n");

printf ("/config/logging/log_path - Active log file directory\n");
printf ("    From command-line: --log_path newvalue\n");
printf ("    Specifies the directory path into which active log files are placed.\n");
printf ("    Current value is '%s'. Default value is 'logs'\n", self->log_path);
printf ("\n");

printf ("/config/logging/keep_logs - Keep log files\n");
printf ("    From command-line: --keep_logs newvalue\n");
printf ("    Specifies whether or not the server should keep logs. If zero, the      \n");
printf ("    server will not keep logs. If 1, it will keep an alert log, a daily log,\n");
printf ("    and a debug log as specified.                                           \n");
printf ("    Current value is %i. Default value is 1.\n", self->keep_logs);
printf ("\n");

printf ("/config/logging/archive_path - Archive log file directory\n");
printf ("    From command-line: --archive_path newvalue\n");
printf ("    Specifies the directory path into which archived log files are placed. \n");
printf ("    This can be the same as the active path; archived log files are renamed\n");
printf ("    to avoid conflict with active log files.                               \n");
printf ("    Current value is '%s'. Default value is 'archive'\n", self->archive_path);
printf ("\n");

printf ("/config/logging/archive_cmd - Archive command\n");
printf ("    From command-line: --archive_cmd newvalue\n");
printf ("    If specified, this command is run on all archived log files. You can use\n");
printf ("    this option to compress archived log files, or clean up old and unwanted\n");
printf ("    files. When the command is run, the name of the archived log file is    \n");
printf ("    provided as an argument to it.                                          \n");
printf ("    Current value is '%s'.\n", self->archive_cmd);
printf ("\n");

printf ("/config/logging/alert_log - Alert log file name\n");
printf ("    From command-line: --alert_log newvalue\n");
printf ("    The name of the alert log file, which records all alerts issued by the \n");
printf ("    server. Note that the server port number is always added to the name of\n");
printf ("    the log file.                                                          \n");
printf ("    Current value is '%s'. Default value is 'alert.log'\n", self->alert_log);
printf ("\n");

printf ("/config/logging/daily_log - Daily log file name\n");
printf ("    From command-line: --daily_log newvalue\n");
printf ("    The name of the daily log file, which records all normal activity as   \n");
printf ("    well as errors. Note that the server port number is always added to the\n");
printf ("    name of the log file.                                                  \n");
printf ("    Current value is '%s'. Default value is 'daily.log'\n", self->daily_log);
printf ("\n");

printf ("/config/logging/debug_log - Debug log file name\n");
printf ("    From command-line: --debug_log newvalue\n");
printf ("    The name of the debug log file, which records all normal activity,      \n");
printf ("    errors, and debug trace information. Note that the server port number is\n");
printf ("    always added to the name of the log file.                               \n");
printf ("    Current value is '%s'. Default value is 'debug.log'\n", self->debug_log);
printf ("\n");

printf ("/config/logging/trace - Protocol trace level\n");
printf ("    From command-line: --trace newvalue\n");
printf ("    Specifies the protocol debug level, which can be 0 (no tracing), 1 (show\n");
printf ("    information and protocol methods), 2 (show protocol animation), 3 (show \n");
printf ("    wire-level data). You should not use any tracing on production servers  \n");
printf ("    except in low-volume scenarios.                                         \n");
printf ("    Current value is %i. Default value is 0.\n", self->trace);
printf ("\n");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_OPTIONS_HELP))
    icl_trace_record (NULL, example_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_OPTIONS_HELP))
    if (example_animating)
        icl_console_print ("<example_options_help_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_set_port

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_port (
    example_t * self,                   //  Reference to object
    char * port                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_PORT))
    if (example_animating)
        icl_console_print ("<example_set_port_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" port=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, port);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_PORT))
    icl_trace_record (NULL, example_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_PORT))
    icl_stats_inc ("example_set_port", &s_example_set_port_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "port", port);
port = ipr_config_getp (self->config, "/config/server", "port", NULL);
assert (port);
self->port = port;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_PORT))
    icl_trace_record (NULL, example_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_PORT))
    if (example_animating)
        icl_console_print ("<example_set_port_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" port=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, port, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_port

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_port (
    example_t * self                    //  Reference to self
)
{
    char *
        port;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_PORT))
    if (example_animating)
        icl_console_print ("<example_port_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_PORT))
    icl_trace_record (NULL, example_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_PORT))
    icl_stats_inc ("example_port", &s_example_port_stats);
#endif

//
if (self)
    port = self->port;
else
    port = "7654";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_PORT))
    icl_trace_record (NULL, example_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_PORT))
    if (example_animating)
        icl_console_print ("<example_port_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" port=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, port);
#endif


    return (port);
}
/*  -------------------------------------------------------------------------
    example_set_monitor

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_monitor (
    example_t * self,                   //  Reference to object
    int monitor                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_MONITOR))
    if (example_animating)
        icl_console_print ("<example_set_monitor_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" monitor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, monitor);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_MONITOR))
    icl_trace_record (NULL, example_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_MONITOR))
    icl_stats_inc ("example_set_monitor", &s_example_set_monitor_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", monitor);
ipr_config_putp (self->config, "/config/resources", "monitor", strvalue);
self->monitor = monitor;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_MONITOR))
    icl_trace_record (NULL, example_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_MONITOR))
    if (example_animating)
        icl_console_print ("<example_set_monitor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" monitor=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, monitor, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_monitor

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_monitor (
    example_t * self                    //  Reference to self
)
{
    int
        monitor;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_MONITOR))
    if (example_animating)
        icl_console_print ("<example_monitor_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_MONITOR))
    icl_trace_record (NULL, example_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_MONITOR))
    icl_stats_inc ("example_monitor", &s_example_monitor_stats);
#endif

//
if (self)
    monitor = self->monitor;
else
    monitor = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_MONITOR))
    icl_trace_record (NULL, example_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_MONITOR))
    if (example_animating)
        icl_console_print ("<example_monitor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" monitor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, monitor);
#endif


    return (monitor);
}
/*  -------------------------------------------------------------------------
    example_set_max_memory_mb

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_max_memory_mb (
    example_t * self,                   //  Reference to object
    size_t max_memory_mb                //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_MAX_MEMORY_MB))
    if (example_animating)
        icl_console_print ("<example_set_max_memory_mb_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" max_memory_mb=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, max_memory_mb);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_MAX_MEMORY_MB))
    icl_trace_record (NULL, example_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_MAX_MEMORY_MB))
    icl_stats_inc ("example_set_max_memory_mb", &s_example_set_max_memory_mb_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%zu", max_memory_mb);
ipr_config_putp (self->config, "/config/resources", "max_memory_mb", strvalue);
self->max_memory_mb = max_memory_mb;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_MAX_MEMORY_MB))
    icl_trace_record (NULL, example_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_MAX_MEMORY_MB))
    if (example_animating)
        icl_console_print ("<example_set_max_memory_mb_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" max_memory_mb=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, max_memory_mb, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_max_memory_mb

    Type: Component method
    -------------------------------------------------------------------------
 */

size_t
    example_max_memory_mb (
    example_t * self                    //  Reference to self
)
{
    size_t
        max_memory_mb;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_MAX_MEMORY_MB))
    if (example_animating)
        icl_console_print ("<example_max_memory_mb_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_MAX_MEMORY_MB))
    icl_trace_record (NULL, example_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_MAX_MEMORY_MB))
    icl_stats_inc ("example_max_memory_mb", &s_example_max_memory_mb_stats);
#endif

//
if (self)
    max_memory_mb = self->max_memory_mb;
else
    max_memory_mb = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_MAX_MEMORY_MB))
    icl_trace_record (NULL, example_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_MAX_MEMORY_MB))
    if (example_animating)
        icl_console_print ("<example_max_memory_mb_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" max_memory_mb=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, max_memory_mb);
#endif


    return (max_memory_mb);
}
/*  -------------------------------------------------------------------------
    example_set_record_stats

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_record_stats (
    example_t * self,                   //  Reference to object
    Bool record_stats                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_RECORD_STATS))
    if (example_animating)
        icl_console_print ("<example_set_record_stats_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" record_stats=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, record_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_RECORD_STATS))
    icl_trace_record (NULL, example_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_RECORD_STATS))
    icl_stats_inc ("example_set_record_stats", &s_example_set_record_stats_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", record_stats);
ipr_config_putp (self->config, "/config/resources", "record_stats", strvalue);
self->record_stats = record_stats;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_RECORD_STATS))
    icl_trace_record (NULL, example_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_RECORD_STATS))
    if (example_animating)
        icl_console_print ("<example_set_record_stats_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" record_stats=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, record_stats, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_record_stats

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    example_record_stats (
    example_t * self                    //  Reference to self
)
{
    Bool
        record_stats;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_RECORD_STATS))
    if (example_animating)
        icl_console_print ("<example_record_stats_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_RECORD_STATS))
    icl_trace_record (NULL, example_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_RECORD_STATS))
    icl_stats_inc ("example_record_stats", &s_example_record_stats_stats);
#endif

//
if (self)
    record_stats = self->record_stats;
else
    record_stats = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_RECORD_STATS))
    icl_trace_record (NULL, example_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_RECORD_STATS))
    if (example_animating)
        icl_console_print ("<example_record_stats_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" record_stats=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, record_stats);
#endif


    return (record_stats);
}
/*  -------------------------------------------------------------------------
    example_set_packio

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_packio (
    example_t * self,                   //  Reference to object
    int packio                          //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_PACKIO))
    if (example_animating)
        icl_console_print ("<example_set_packio_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" packio=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, packio);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_PACKIO))
    icl_trace_record (NULL, example_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_PACKIO))
    icl_stats_inc ("example_set_packio", &s_example_set_packio_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", packio);
ipr_config_putp (self->config, "/config/tuning", "packio", strvalue);
self->packio = packio;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_PACKIO))
    icl_trace_record (NULL, example_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_PACKIO))
    if (example_animating)
        icl_console_print ("<example_set_packio_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" packio=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, packio, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_packio

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_packio (
    example_t * self                    //  Reference to self
)
{
    int
        packio;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_PACKIO))
    if (example_animating)
        icl_console_print ("<example_packio_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_PACKIO))
    icl_trace_record (NULL, example_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_PACKIO))
    icl_stats_inc ("example_packio", &s_example_packio_stats);
#endif

//
if (self)
    packio = self->packio;
else
    packio = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_PACKIO))
    icl_trace_record (NULL, example_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_PACKIO))
    if (example_animating)
        icl_console_print ("<example_packio_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" packio=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, packio);
#endif


    return (packio);
}
/*  -------------------------------------------------------------------------
    example_set_heartbeat

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_heartbeat (
    example_t * self,                   //  Reference to object
    int heartbeat                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_HEARTBEAT))
    if (example_animating)
        icl_console_print ("<example_set_heartbeat_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_HEARTBEAT))
    icl_trace_record (NULL, example_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_HEARTBEAT))
    icl_stats_inc ("example_set_heartbeat", &s_example_set_heartbeat_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", heartbeat);
ipr_config_putp (self->config, "/config/tuning", "heartbeat", strvalue);
self->heartbeat = heartbeat;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_HEARTBEAT))
    icl_trace_record (NULL, example_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_HEARTBEAT))
    if (example_animating)
        icl_console_print ("<example_set_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_heartbeat

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_heartbeat (
    example_t * self                    //  Reference to self
)
{
    int
        heartbeat;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_HEARTBEAT))
    if (example_animating)
        icl_console_print ("<example_heartbeat_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_HEARTBEAT))
    icl_trace_record (NULL, example_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_HEARTBEAT))
    icl_stats_inc ("example_heartbeat", &s_example_heartbeat_stats);
#endif

//
if (self)
    heartbeat = self->heartbeat;
else
    heartbeat = 2;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_HEARTBEAT))
    icl_trace_record (NULL, example_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_HEARTBEAT))
    if (example_animating)
        icl_console_print ("<example_heartbeat_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" heartbeat=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, heartbeat);
#endif


    return (heartbeat);
}
/*  -------------------------------------------------------------------------
    example_set_read_timeout

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_read_timeout (
    example_t * self,                   //  Reference to object
    int read_timeout                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_READ_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_set_read_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" read_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, read_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_READ_TIMEOUT))
    icl_trace_record (NULL, example_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_READ_TIMEOUT))
    icl_stats_inc ("example_set_read_timeout", &s_example_set_read_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", read_timeout);
ipr_config_putp (self->config, "/config/tuning", "read_timeout", strvalue);
self->read_timeout = read_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_READ_TIMEOUT))
    icl_trace_record (NULL, example_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_READ_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_set_read_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" read_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, read_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_read_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_read_timeout (
    example_t * self                    //  Reference to self
)
{
    int
        read_timeout;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_READ_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_read_timeout_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_READ_TIMEOUT))
    icl_trace_record (NULL, example_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_READ_TIMEOUT))
    icl_stats_inc ("example_read_timeout", &s_example_read_timeout_stats);
#endif

//
if (self)
    read_timeout = self->read_timeout;
else
    read_timeout = 30;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_READ_TIMEOUT))
    icl_trace_record (NULL, example_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_READ_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_read_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" read_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, read_timeout);
#endif


    return (read_timeout);
}
/*  -------------------------------------------------------------------------
    example_set_write_timeout

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_write_timeout (
    example_t * self,                   //  Reference to object
    int write_timeout                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_WRITE_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_set_write_timeout_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" write_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, write_timeout);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_WRITE_TIMEOUT))
    icl_trace_record (NULL, example_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_WRITE_TIMEOUT))
    icl_stats_inc ("example_set_write_timeout", &s_example_set_write_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", write_timeout);
ipr_config_putp (self->config, "/config/tuning", "write_timeout", strvalue);
self->write_timeout = write_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_WRITE_TIMEOUT))
    icl_trace_record (NULL, example_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_WRITE_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_set_write_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" write_timeout=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, write_timeout, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_write_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_write_timeout (
    example_t * self                    //  Reference to self
)
{
    int
        write_timeout;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_WRITE_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_write_timeout_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_WRITE_TIMEOUT))
    icl_trace_record (NULL, example_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_WRITE_TIMEOUT))
    icl_stats_inc ("example_write_timeout", &s_example_write_timeout_stats);
#endif

//
if (self)
    write_timeout = self->write_timeout;
else
    write_timeout = 30;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_WRITE_TIMEOUT))
    icl_trace_record (NULL, example_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_WRITE_TIMEOUT))
    if (example_animating)
        icl_console_print ("<example_write_timeout_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" write_timeout=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, write_timeout);
#endif


    return (write_timeout);
}
/*  -------------------------------------------------------------------------
    example_set_tcp_nodelay

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_tcp_nodelay (
    example_t * self,                   //  Reference to object
    Bool tcp_nodelay                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_TCP_NODELAY))
    if (example_animating)
        icl_console_print ("<example_set_tcp_nodelay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_NODELAY))
    icl_trace_record (NULL, example_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TCP_NODELAY))
    icl_stats_inc ("example_set_tcp_nodelay", &s_example_set_tcp_nodelay_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
ipr_config_putp (self->config, "/config/tuning", "tcp_nodelay", strvalue);
self->tcp_nodelay = tcp_nodelay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_NODELAY))
    icl_trace_record (NULL, example_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_TCP_NODELAY))
    if (example_animating)
        icl_console_print ("<example_set_tcp_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_tcp_nodelay

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    example_tcp_nodelay (
    example_t * self                    //  Reference to self
)
{
    Bool
        tcp_nodelay;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_TCP_NODELAY))
    if (example_animating)
        icl_console_print ("<example_tcp_nodelay_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TCP_NODELAY))
    icl_trace_record (NULL, example_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TCP_NODELAY))
    icl_stats_inc ("example_tcp_nodelay", &s_example_tcp_nodelay_stats);
#endif

//
if (self)
    tcp_nodelay = self->tcp_nodelay;
else
    tcp_nodelay = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TCP_NODELAY))
    icl_trace_record (NULL, example_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_TCP_NODELAY))
    if (example_animating)
        icl_console_print ("<example_tcp_nodelay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_nodelay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_nodelay);
#endif


    return (tcp_nodelay);
}
/*  -------------------------------------------------------------------------
    example_set_tcp_rcvbuf

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_tcp_rcvbuf (
    example_t * self,                   //  Reference to object
    int tcp_rcvbuf                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_TCP_RCVBUF))
    if (example_animating)
        icl_console_print ("<example_set_tcp_rcvbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_RCVBUF))
    icl_trace_record (NULL, example_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TCP_RCVBUF))
    icl_stats_inc ("example_set_tcp_rcvbuf", &s_example_set_tcp_rcvbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_rcvbuf", strvalue);
self->tcp_rcvbuf = tcp_rcvbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_RCVBUF))
    icl_trace_record (NULL, example_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_TCP_RCVBUF))
    if (example_animating)
        icl_console_print ("<example_set_tcp_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_tcp_rcvbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_tcp_rcvbuf (
    example_t * self                    //  Reference to self
)
{
    int
        tcp_rcvbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_TCP_RCVBUF))
    if (example_animating)
        icl_console_print ("<example_tcp_rcvbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TCP_RCVBUF))
    icl_trace_record (NULL, example_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TCP_RCVBUF))
    icl_stats_inc ("example_tcp_rcvbuf", &s_example_tcp_rcvbuf_stats);
#endif

//
if (self)
    tcp_rcvbuf = self->tcp_rcvbuf;
else
    tcp_rcvbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TCP_RCVBUF))
    icl_trace_record (NULL, example_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_TCP_RCVBUF))
    if (example_animating)
        icl_console_print ("<example_tcp_rcvbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_rcvbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_rcvbuf);
#endif


    return (tcp_rcvbuf);
}
/*  -------------------------------------------------------------------------
    example_set_tcp_sndbuf

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_tcp_sndbuf (
    example_t * self,                   //  Reference to object
    int tcp_sndbuf                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_TCP_SNDBUF))
    if (example_animating)
        icl_console_print ("<example_set_tcp_sndbuf_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_SNDBUF))
    icl_trace_record (NULL, example_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TCP_SNDBUF))
    icl_stats_inc ("example_set_tcp_sndbuf", &s_example_set_tcp_sndbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_sndbuf", strvalue);
self->tcp_sndbuf = tcp_sndbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_SNDBUF))
    icl_trace_record (NULL, example_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_TCP_SNDBUF))
    if (example_animating)
        icl_console_print ("<example_set_tcp_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_tcp_sndbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_tcp_sndbuf (
    example_t * self                    //  Reference to self
)
{
    int
        tcp_sndbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_TCP_SNDBUF))
    if (example_animating)
        icl_console_print ("<example_tcp_sndbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TCP_SNDBUF))
    icl_trace_record (NULL, example_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TCP_SNDBUF))
    icl_stats_inc ("example_tcp_sndbuf", &s_example_tcp_sndbuf_stats);
#endif

//
if (self)
    tcp_sndbuf = self->tcp_sndbuf;
else
    tcp_sndbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TCP_SNDBUF))
    icl_trace_record (NULL, example_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_TCP_SNDBUF))
    if (example_animating)
        icl_console_print ("<example_tcp_sndbuf_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" tcp_sndbuf=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, tcp_sndbuf);
#endif


    return (tcp_sndbuf);
}
/*  -------------------------------------------------------------------------
    example_set_frame_max

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_frame_max (
    example_t * self,                   //  Reference to object
    int frame_max                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_FRAME_MAX))
    if (example_animating)
        icl_console_print ("<example_set_frame_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_FRAME_MAX))
    icl_trace_record (NULL, example_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_FRAME_MAX))
    icl_stats_inc ("example_set_frame_max", &s_example_set_frame_max_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
if (frame_max < 2048) {
    icl_console_print ("W: <command line>: illegal value %d for frame_max, using %d",
        frame_max, 2048);
    frame_max = 2048;
}
if (frame_max > 4194304) {
    icl_console_print ("W: <command line>: illegal value %d for frame_max, using %d",
        frame_max, 4194304);
    frame_max = 4194304;
}
icl_shortstr_fmt (strvalue, "%i", frame_max);
ipr_config_putp (self->config, "/config/tuning", "frame_max", strvalue);
self->frame_max = frame_max;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_FRAME_MAX))
    icl_trace_record (NULL, example_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_FRAME_MAX))
    if (example_animating)
        icl_console_print ("<example_set_frame_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_frame_max

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_frame_max (
    example_t * self                    //  Reference to self
)
{
    int
        frame_max;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_FRAME_MAX))
    if (example_animating)
        icl_console_print ("<example_frame_max_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_FRAME_MAX))
    icl_trace_record (NULL, example_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_FRAME_MAX))
    icl_stats_inc ("example_frame_max", &s_example_frame_max_stats);
#endif

//
if (self)
    frame_max = self->frame_max;
else
    frame_max = 32768;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_FRAME_MAX))
    icl_trace_record (NULL, example_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_FRAME_MAX))
    if (example_animating)
        icl_console_print ("<example_frame_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" frame_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, frame_max);
#endif


    return (frame_max);
}
/*  -------------------------------------------------------------------------
    example_set_log_path

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_log_path (
    example_t * self,                   //  Reference to object
    char * log_path                     //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_LOG_PATH))
    if (example_animating)
        icl_console_print ("<example_set_log_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log_path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_LOG_PATH))
    icl_trace_record (NULL, example_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_LOG_PATH))
    icl_stats_inc ("example_set_log_path", &s_example_set_log_path_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "log_path", log_path);
log_path = ipr_config_getp (self->config, "/config/logging", "log_path", NULL);
assert (log_path);
self->log_path = log_path;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_LOG_PATH))
    icl_trace_record (NULL, example_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_LOG_PATH))
    if (example_animating)
        icl_console_print ("<example_set_log_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log_path=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log_path, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_log_path

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_log_path (
    example_t * self                    //  Reference to self
)
{
    char *
        log_path;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_LOG_PATH))
    if (example_animating)
        icl_console_print ("<example_log_path_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_LOG_PATH))
    icl_trace_record (NULL, example_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_LOG_PATH))
    icl_stats_inc ("example_log_path", &s_example_log_path_stats);
#endif

//
if (self)
    log_path = self->log_path;
else
    log_path = "logs";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_LOG_PATH))
    icl_trace_record (NULL, example_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_LOG_PATH))
    if (example_animating)
        icl_console_print ("<example_log_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" log_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, log_path);
#endif


    return (log_path);
}
/*  -------------------------------------------------------------------------
    example_set_keep_logs

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_keep_logs (
    example_t * self,                   //  Reference to object
    Bool keep_logs                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_KEEP_LOGS))
    if (example_animating)
        icl_console_print ("<example_set_keep_logs_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" keep_logs=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, keep_logs);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_KEEP_LOGS))
    icl_trace_record (NULL, example_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_KEEP_LOGS))
    icl_stats_inc ("example_set_keep_logs", &s_example_set_keep_logs_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", keep_logs);
ipr_config_putp (self->config, "/config/logging", "keep_logs", strvalue);
self->keep_logs = keep_logs;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_KEEP_LOGS))
    icl_trace_record (NULL, example_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_KEEP_LOGS))
    if (example_animating)
        icl_console_print ("<example_set_keep_logs_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" keep_logs=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, keep_logs, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_keep_logs

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    example_keep_logs (
    example_t * self                    //  Reference to self
)
{
    Bool
        keep_logs;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_KEEP_LOGS))
    if (example_animating)
        icl_console_print ("<example_keep_logs_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_KEEP_LOGS))
    icl_trace_record (NULL, example_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_KEEP_LOGS))
    icl_stats_inc ("example_keep_logs", &s_example_keep_logs_stats);
#endif

//
if (self)
    keep_logs = self->keep_logs;
else
    keep_logs = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_KEEP_LOGS))
    icl_trace_record (NULL, example_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_KEEP_LOGS))
    if (example_animating)
        icl_console_print ("<example_keep_logs_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" keep_logs=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, keep_logs);
#endif


    return (keep_logs);
}
/*  -------------------------------------------------------------------------
    example_set_archive_path

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_archive_path (
    example_t * self,                   //  Reference to object
    char * archive_path                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_ARCHIVE_PATH))
    if (example_animating)
        icl_console_print ("<example_set_archive_path_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_path);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_PATH))
    icl_trace_record (NULL, example_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_ARCHIVE_PATH))
    icl_stats_inc ("example_set_archive_path", &s_example_set_archive_path_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "archive_path", archive_path);
archive_path = ipr_config_getp (self->config, "/config/logging", "archive_path", NULL);
assert (archive_path);
self->archive_path = archive_path;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_PATH))
    icl_trace_record (NULL, example_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_ARCHIVE_PATH))
    if (example_animating)
        icl_console_print ("<example_set_archive_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_path=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_path, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_archive_path

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_archive_path (
    example_t * self                    //  Reference to self
)
{
    char *
        archive_path;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_ARCHIVE_PATH))
    if (example_animating)
        icl_console_print ("<example_archive_path_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_PATH))
    icl_trace_record (NULL, example_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ARCHIVE_PATH))
    icl_stats_inc ("example_archive_path", &s_example_archive_path_stats);
#endif

//
if (self)
    archive_path = self->archive_path;
else
    archive_path = "archive";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_PATH))
    icl_trace_record (NULL, example_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_ARCHIVE_PATH))
    if (example_animating)
        icl_console_print ("<example_archive_path_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_path=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_path);
#endif


    return (archive_path);
}
/*  -------------------------------------------------------------------------
    example_set_archive_cmd

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_archive_cmd (
    example_t * self,                   //  Reference to object
    char * archive_cmd                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_ARCHIVE_CMD))
    if (example_animating)
        icl_console_print ("<example_set_archive_cmd_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_cmd=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_cmd);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_CMD))
    icl_trace_record (NULL, example_dump, 41);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_ARCHIVE_CMD))
    icl_stats_inc ("example_set_archive_cmd", &s_example_set_archive_cmd_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "archive_cmd", archive_cmd);
archive_cmd = ipr_config_getp (self->config, "/config/logging", "archive_cmd", NULL);
assert (archive_cmd);
self->archive_cmd = archive_cmd;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_CMD))
    icl_trace_record (NULL, example_dump, 0x10000 + 41);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_ARCHIVE_CMD))
    if (example_animating)
        icl_console_print ("<example_set_archive_cmd_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_cmd=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_cmd, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_archive_cmd

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_archive_cmd (
    example_t * self                    //  Reference to self
)
{
    char *
        archive_cmd;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_ARCHIVE_CMD))
    if (example_animating)
        icl_console_print ("<example_archive_cmd_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_CMD))
    icl_trace_record (NULL, example_dump, 42);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ARCHIVE_CMD))
    icl_stats_inc ("example_archive_cmd", &s_example_archive_cmd_stats);
#endif

//
if (self)
    archive_cmd = self->archive_cmd;
else
    archive_cmd = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_CMD))
    icl_trace_record (NULL, example_dump, 0x10000 + 42);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_ARCHIVE_CMD))
    if (example_animating)
        icl_console_print ("<example_archive_cmd_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" archive_cmd=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, archive_cmd);
#endif


    return (archive_cmd);
}
/*  -------------------------------------------------------------------------
    example_set_alert_log

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_alert_log (
    example_t * self,                   //  Reference to object
    char * alert_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_ALERT_LOG))
    if (example_animating)
        icl_console_print ("<example_set_alert_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alert_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alert_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_ALERT_LOG))
    icl_trace_record (NULL, example_dump, 43);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_ALERT_LOG))
    icl_stats_inc ("example_set_alert_log", &s_example_set_alert_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "alert_log", alert_log);
alert_log = ipr_config_getp (self->config, "/config/logging", "alert_log", NULL);
assert (alert_log);
self->alert_log = alert_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_ALERT_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 43);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_ALERT_LOG))
    if (example_animating)
        icl_console_print ("<example_set_alert_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alert_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alert_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_alert_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_alert_log (
    example_t * self                    //  Reference to self
)
{
    char *
        alert_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_ALERT_LOG))
    if (example_animating)
        icl_console_print ("<example_alert_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ALERT_LOG))
    icl_trace_record (NULL, example_dump, 44);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ALERT_LOG))
    icl_stats_inc ("example_alert_log", &s_example_alert_log_stats);
#endif

//
if (self)
    alert_log = self->alert_log;
else
    alert_log = "alert.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ALERT_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 44);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_ALERT_LOG))
    if (example_animating)
        icl_console_print ("<example_alert_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" alert_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, alert_log);
#endif


    return (alert_log);
}
/*  -------------------------------------------------------------------------
    example_set_daily_log

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_daily_log (
    example_t * self,                   //  Reference to object
    char * daily_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_DAILY_LOG))
    if (example_animating)
        icl_console_print ("<example_set_daily_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" daily_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, daily_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_DAILY_LOG))
    icl_trace_record (NULL, example_dump, 45);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_DAILY_LOG))
    icl_stats_inc ("example_set_daily_log", &s_example_set_daily_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "daily_log", daily_log);
daily_log = ipr_config_getp (self->config, "/config/logging", "daily_log", NULL);
assert (daily_log);
self->daily_log = daily_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_DAILY_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 45);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_DAILY_LOG))
    if (example_animating)
        icl_console_print ("<example_set_daily_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" daily_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, daily_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_daily_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_daily_log (
    example_t * self                    //  Reference to self
)
{
    char *
        daily_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_DAILY_LOG))
    if (example_animating)
        icl_console_print ("<example_daily_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DAILY_LOG))
    icl_trace_record (NULL, example_dump, 46);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DAILY_LOG))
    icl_stats_inc ("example_daily_log", &s_example_daily_log_stats);
#endif

//
if (self)
    daily_log = self->daily_log;
else
    daily_log = "daily.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DAILY_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 46);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_DAILY_LOG))
    if (example_animating)
        icl_console_print ("<example_daily_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" daily_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, daily_log);
#endif


    return (daily_log);
}
/*  -------------------------------------------------------------------------
    example_set_debug_log

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_debug_log (
    example_t * self,                   //  Reference to object
    char * debug_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_DEBUG_LOG))
    if (example_animating)
        icl_console_print ("<example_set_debug_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_DEBUG_LOG))
    icl_trace_record (NULL, example_dump, 47);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_DEBUG_LOG))
    icl_stats_inc ("example_set_debug_log", &s_example_set_debug_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "debug_log", debug_log);
debug_log = ipr_config_getp (self->config, "/config/logging", "debug_log", NULL);
assert (debug_log);
self->debug_log = debug_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_DEBUG_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 47);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_DEBUG_LOG))
    if (example_animating)
        icl_console_print ("<example_set_debug_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_debug_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    example_debug_log (
    example_t * self                    //  Reference to self
)
{
    char *
        debug_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_DEBUG_LOG))
    if (example_animating)
        icl_console_print ("<example_debug_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DEBUG_LOG))
    icl_trace_record (NULL, example_dump, 48);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DEBUG_LOG))
    icl_stats_inc ("example_debug_log", &s_example_debug_log_stats);
#endif

//
if (self)
    debug_log = self->debug_log;
else
    debug_log = "debug.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DEBUG_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 48);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_DEBUG_LOG))
    if (example_animating)
        icl_console_print ("<example_debug_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" debug_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, debug_log);
#endif


    return (debug_log);
}
/*  -------------------------------------------------------------------------
    example_set_trace

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_set_trace (
    example_t * self,                   //  Reference to object
    int trace                           //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

icl_shortstr_t
    strvalue;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SET_TRACE))
    if (example_animating)
        icl_console_print ("<example_set_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TRACE))
    icl_trace_record (NULL, example_dump, 49);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SET_TRACE))
    icl_stats_inc ("example_set_trace", &s_example_set_trace_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

EXAMPLE_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", trace);
ipr_config_putp (self->config, "/config/logging", "trace", strvalue);
self->trace = trace;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SET_TRACE))
    icl_trace_record (NULL, example_dump, 0x10000 + 49);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SET_TRACE))
    if (example_animating)
        icl_console_print ("<example_set_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_trace

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    example_trace (
    example_t * self                    //  Reference to self
)
{
    int
        trace;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_TRACE))
    if (example_animating)
        icl_console_print ("<example_trace_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TRACE))
    icl_trace_record (NULL, example_dump, 50);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TRACE))
    icl_stats_inc ("example_trace", &s_example_trace_stats);
#endif

//
if (self)
    trace = self->trace;
else
    trace = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TRACE))
    icl_trace_record (NULL, example_dump, 0x10000 + 50);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_TRACE))
    if (example_animating)
        icl_console_print ("<example_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, trace);
#endif


    return (trace);
}
/*  -------------------------------------------------------------------------
    example_dump_log

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    Dump current option values to an smt_log file.
    -------------------------------------------------------------------------
 */

int
    example_dump_log (
    example_t * self,                   //  Reference to object
    smt_log_t * logfile                 //  Log file to dump to
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_DUMP_LOG))
    if (example_animating)
        icl_console_print ("<example_dump_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" logfile=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, logfile);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DUMP_LOG))
    icl_trace_record (NULL, example_dump, 51);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DUMP_LOG))
    icl_stats_inc ("example_dump_log", &s_example_dump_log_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

smt_log_print (logfile, "*******************  Configuration Settings  ********************");
smt_log_print (logfile, "port=%s", self->port);
smt_log_print (logfile, "monitor=%i", self->monitor);
smt_log_print (logfile, "max_memory_mb=%zu", self->max_memory_mb);
smt_log_print (logfile, "record_stats=%i", self->record_stats);
smt_log_print (logfile, "packio=%i", self->packio);
smt_log_print (logfile, "heartbeat=%i", self->heartbeat);
smt_log_print (logfile, "read_timeout=%i", self->read_timeout);
smt_log_print (logfile, "write_timeout=%i", self->write_timeout);
smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
smt_log_print (logfile, "frame_max=%i", self->frame_max);
smt_log_print (logfile, "log_path=%s", self->log_path);
smt_log_print (logfile, "keep_logs=%i", self->keep_logs);
smt_log_print (logfile, "archive_path=%s", self->archive_path);
smt_log_print (logfile, "archive_cmd=%s", self->archive_cmd);
smt_log_print (logfile, "alert_log=%s", self->alert_log);
smt_log_print (logfile, "daily_log=%s", self->daily_log);
smt_log_print (logfile, "debug_log=%s", self->debug_log);
smt_log_print (logfile, "trace=%i", self->trace);
smt_log_print (logfile, "");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DUMP_LOG))
    icl_trace_record (NULL, example_dump, 0x10000 + 51);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_DUMP_LOG))
    if (example_animating)
        icl_console_print ("<example_dump_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" logfile=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, logfile, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    example_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    example_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SELFTEST))
    if (example_animating)
        icl_console_print ("<example_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SELFTEST))
    icl_trace_record (NULL, example_dump, 52);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SELFTEST))
    icl_stats_inc ("example_selftest", &s_example_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SELFTEST))
    icl_trace_record (NULL, example_dump, 0x10000 + 52);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SELFTEST))
    if (example_animating)
        icl_console_print ("<example_selftest_finish"
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
    example_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    example_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_TERMINATE))
    if (example_animating)
        icl_console_print ("<example_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TERMINATE))
    icl_trace_record (NULL, example_dump, 53);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_TERMINATE))
    icl_stats_inc ("example_terminate", &s_example_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_TERMINATE))
    icl_trace_record (NULL, example_dump, 0x10000 + 53);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_TERMINATE))
    if (example_animating)
        icl_console_print ("<example_terminate_finish"
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
    example_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    example_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
example_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SHOW))
    if (example_animating)
        icl_console_print ("<example_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SHOW))
    icl_trace_record (NULL, example_dump, 54);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SHOW))
    icl_stats_inc ("example_show", &s_example_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <example file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SHOW))
    icl_trace_record (NULL, example_dump, 0x10000 + 54);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SHOW))
    if (example_animating)
        icl_console_print ("<example_show_finish"
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
    example_destroy

    Type: Component method
    Destroys a example_t object. Takes the address of a
    example_t reference (a pointer to a pointer) and nullifies the
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
    example_destroy_ (
    example_t * ( * self_p ),           //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    example_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_DESTROY_PUBLIC))
    if (example_animating)
        icl_console_print ("<example_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DESTROY_PUBLIC))
    icl_trace_record (NULL, example_dump, 55);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_DESTROY_PUBLIC))
    icl_stats_inc ("example_destroy", &s_example_destroy_stats);
#endif

if (self) {
    example_annihilate (self_p);
    example_free ((example_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_DESTROY_PUBLIC))
    icl_trace_record (NULL, example_dump, 0x10000 + 55);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_DESTROY_PUBLIC))
    if (example_animating)
        icl_console_print ("<example_destroy_public_finish"
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
    example_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static example_t *
    example_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    example_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_ALLOC))
    if (example_animating)
        icl_console_print ("<example_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ALLOC))
    icl_trace_record (NULL, example_dump, 56);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_ALLOC))
    icl_stats_inc ("example_alloc", &s_example_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    example_cache_initialise ();

self = (example_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (example_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_ALLOC))
    icl_trace_record (NULL, example_dump, 0x10000 + 56);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_ALLOC))
    if (example_animating)
        icl_console_print ("<example_alloc_finish"
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
    example_free

    Type: Component method
    Freess a example_t object.
    -------------------------------------------------------------------------
 */

static void
    example_free (
    example_t * self                    //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_FREE))
    if (example_animating)
        icl_console_print ("<example_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_FREE))
    icl_trace_record (NULL, example_dump, 57);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_FREE))
    icl_stats_inc ("example_free", &s_example_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (example_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (example_t));
        self->object_tag = EXAMPLE_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_FREE))
    icl_trace_record (NULL, example_dump, 0x10000 + 57);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_FREE))
    if (example_animating)
        icl_console_print ("<example_free_finish"
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
    example_read_lock

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_read_lock (
    example_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_READ_LOCK))
    if (example_animating)
        icl_console_print ("<example_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_READ_LOCK))
    icl_trace_record (NULL, example_dump, 58);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_READ_LOCK))
    icl_stats_inc ("example_read_lock", &s_example_read_lock_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_READ_LOCK))
    icl_trace_record (NULL, example_dump, 0x10000 + 58);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_READ_LOCK))
    if (example_animating)
        icl_console_print ("<example_read_lock_finish"
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
    example_write_lock

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_write_lock (
    example_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_WRITE_LOCK))
    if (example_animating)
        icl_console_print ("<example_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_WRITE_LOCK))
    icl_trace_record (NULL, example_dump, 59);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_WRITE_LOCK))
    icl_stats_inc ("example_write_lock", &s_example_write_lock_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_WRITE_LOCK))
    icl_trace_record (NULL, example_dump, 0x10000 + 59);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_WRITE_LOCK))
    if (example_animating)
        icl_console_print ("<example_write_lock_finish"
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
    example_unlock

    Type: Component method
    Accepts a example_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    example_unlock (
    example_t * self                    //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_UNLOCK))
    if (example_animating)
        icl_console_print ("<example_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_UNLOCK))
    icl_trace_record (NULL, example_dump, 60);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_UNLOCK))
    icl_stats_inc ("example_unlock", &s_example_unlock_stats);
#endif

EXAMPLE_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_UNLOCK))
    icl_trace_record (NULL, example_dump, 0x10000 + 60);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_UNLOCK))
    if (example_animating)
        icl_console_print ("<example_unlock_finish"
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
    example_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    example_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_CACHE_INITIALISE))
    if (example_animating)
        icl_console_print ("<example_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CACHE_INITIALISE))
    icl_trace_record (NULL, example_dump, 61);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CACHE_INITIALISE))
    icl_stats_inc ("example_cache_initialise", &s_example_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (example_t));
icl_system_register (example_cache_purge, example_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CACHE_INITIALISE))
    icl_trace_record (NULL, example_dump, 0x10000 + 61);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_CACHE_INITIALISE))
    if (example_animating)
        icl_console_print ("<example_cache_initialise_finish"
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
    example_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    example_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_CACHE_PURGE))
    if (example_animating)
        icl_console_print ("<example_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CACHE_PURGE))
    icl_trace_record (NULL, example_dump, 62);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CACHE_PURGE))
    icl_stats_inc ("example_cache_purge", &s_example_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CACHE_PURGE))
    icl_trace_record (NULL, example_dump, 0x10000 + 62);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_CACHE_PURGE))
    if (example_animating)
        icl_console_print ("<example_cache_purge_finish"
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
    example_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    example_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_CACHE_TERMINATE))
    if (example_animating)
        icl_console_print ("<example_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CACHE_TERMINATE))
    icl_trace_record (NULL, example_dump, 63);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_CACHE_TERMINATE))
    icl_stats_inc ("example_cache_terminate", &s_example_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_CACHE_TERMINATE))
    icl_trace_record (NULL, example_dump, 0x10000 + 63);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_CACHE_TERMINATE))
    if (example_animating)
        icl_console_print ("<example_cache_terminate_finish"
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
    example_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    example_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_SHOW_ANIMATION))
    if (example_animating)
        icl_console_print ("<example_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SHOW_ANIMATION))
    icl_trace_record (NULL, example_dump, 64);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_SHOW_ANIMATION))
    icl_stats_inc ("example_show_animation", &s_example_show_animation_stats);
#endif

example_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_SHOW_ANIMATION))
    icl_trace_record (NULL, example_dump, 0x10000 + 64);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_SHOW_ANIMATION))
    if (example_animating)
        icl_console_print ("<example_show_animation_finish"
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
    example_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    example_new_in_scope_ (
    example_t * * self_p,               //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_EXAMPLE)  ||  defined (BASE_ANIMATE_EXAMPLE_NEW_IN_SCOPE))
    if (example_animating)
        icl_console_print ("<example_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_NEW_IN_SCOPE))
    icl_trace_record (NULL, example_dump, 65);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_EXAMPLE)  ||  defined (BASE_STATS_EXAMPLE_NEW_IN_SCOPE))
    icl_stats_inc ("example_new_in_scope", &s_example_new_in_scope_stats);
#endif

*self_p = example_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) example_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_NEW_IN_SCOPE))
    icl_trace_record (NULL, example_dump, 0x10000 + 65);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_EXAMPLE)   || defined (BASE_ANIMATE_EXAMPLE_NEW_IN_SCOPE))
    if (example_animating)
        icl_console_print ("<example_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_EXAMPLE)   || defined (BASE_TRACE_EXAMPLE_NEW)   || defined (BASE_TRACE_EXAMPLE_DESTROY)   || defined (BASE_TRACE_EXAMPLE_LOAD_XMLFILE)   || defined (BASE_TRACE_EXAMPLE_LOAD_BUCKET)   || defined (BASE_TRACE_EXAMPLE_SHADOW)   || defined (BASE_TRACE_EXAMPLE_COMMIT)   || defined (BASE_TRACE_EXAMPLE_ROLLBACK)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_HELP)   || defined (BASE_TRACE_EXAMPLE_CMDLINE_PARSE)   || defined (BASE_TRACE_EXAMPLE_OPTIONS_HELP)   || defined (BASE_TRACE_EXAMPLE_SET_PORT)   || defined (BASE_TRACE_EXAMPLE_PORT)   || defined (BASE_TRACE_EXAMPLE_SET_MONITOR)   || defined (BASE_TRACE_EXAMPLE_MONITOR)   || defined (BASE_TRACE_EXAMPLE_SET_MAX_MEMORY_MB)   || defined (BASE_TRACE_EXAMPLE_MAX_MEMORY_MB)   || defined (BASE_TRACE_EXAMPLE_SET_RECORD_STATS)   || defined (BASE_TRACE_EXAMPLE_RECORD_STATS)   || defined (BASE_TRACE_EXAMPLE_SET_PACKIO)   || defined (BASE_TRACE_EXAMPLE_PACKIO)   || defined (BASE_TRACE_EXAMPLE_SET_HEARTBEAT)   || defined (BASE_TRACE_EXAMPLE_HEARTBEAT)   || defined (BASE_TRACE_EXAMPLE_SET_READ_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_READ_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_SET_WRITE_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_WRITE_TIMEOUT)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_NODELAY)   || defined (BASE_TRACE_EXAMPLE_TCP_NODELAY)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_RCVBUF)   || defined (BASE_TRACE_EXAMPLE_TCP_RCVBUF)   || defined (BASE_TRACE_EXAMPLE_SET_TCP_SNDBUF)   || defined (BASE_TRACE_EXAMPLE_TCP_SNDBUF)   || defined (BASE_TRACE_EXAMPLE_SET_FRAME_MAX)   || defined (BASE_TRACE_EXAMPLE_FRAME_MAX)   || defined (BASE_TRACE_EXAMPLE_SET_LOG_PATH)   || defined (BASE_TRACE_EXAMPLE_LOG_PATH)   || defined (BASE_TRACE_EXAMPLE_SET_KEEP_LOGS)   || defined (BASE_TRACE_EXAMPLE_KEEP_LOGS)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_PATH)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_PATH)   || defined (BASE_TRACE_EXAMPLE_SET_ARCHIVE_CMD)   || defined (BASE_TRACE_EXAMPLE_ARCHIVE_CMD)   || defined (BASE_TRACE_EXAMPLE_SET_ALERT_LOG)   || defined (BASE_TRACE_EXAMPLE_ALERT_LOG)   || defined (BASE_TRACE_EXAMPLE_SET_DAILY_LOG)   || defined (BASE_TRACE_EXAMPLE_DAILY_LOG)   || defined (BASE_TRACE_EXAMPLE_SET_DEBUG_LOG)   || defined (BASE_TRACE_EXAMPLE_DEBUG_LOG)   || defined (BASE_TRACE_EXAMPLE_SET_TRACE)   || defined (BASE_TRACE_EXAMPLE_TRACE)   || defined (BASE_TRACE_EXAMPLE_DUMP_LOG)   || defined (BASE_TRACE_EXAMPLE_SELFTEST)   || defined (BASE_TRACE_EXAMPLE_TERMINATE)   || defined (BASE_TRACE_EXAMPLE_SHOW)   || defined (BASE_TRACE_EXAMPLE_DESTROY_PUBLIC)   || defined (BASE_TRACE_EXAMPLE_ALLOC)   || defined (BASE_TRACE_EXAMPLE_FREE)   || defined (BASE_TRACE_EXAMPLE_READ_LOCK)   || defined (BASE_TRACE_EXAMPLE_WRITE_LOCK)   || defined (BASE_TRACE_EXAMPLE_UNLOCK)   || defined (BASE_TRACE_EXAMPLE_CACHE_INITIALISE)   || defined (BASE_TRACE_EXAMPLE_CACHE_PURGE)   || defined (BASE_TRACE_EXAMPLE_CACHE_TERMINATE)   || defined (BASE_TRACE_EXAMPLE_SHOW_ANIMATION)   || defined (BASE_TRACE_EXAMPLE_NEW_IN_SCOPE) )
void
example_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "destroy"; break;
        case 3: method_name = "load xmlfile"; break;
        case 4: method_name = "load bucket"; break;
        case 5: method_name = "shadow"; break;
        case 6: method_name = "commit"; break;
        case 7: method_name = "rollback"; break;
        case 8: method_name = "cmdline help"; break;
        case 9: method_name = "cmdline parse"; break;
        case 10: method_name = "options help"; break;
        case 11: method_name = "set port"; break;
        case 12: method_name = "port"; break;
        case 13: method_name = "set monitor"; break;
        case 14: method_name = "monitor"; break;
        case 15: method_name = "set max_memory_mb"; break;
        case 16: method_name = "max_memory_mb"; break;
        case 17: method_name = "set record_stats"; break;
        case 18: method_name = "record_stats"; break;
        case 19: method_name = "set packio"; break;
        case 20: method_name = "packio"; break;
        case 21: method_name = "set heartbeat"; break;
        case 22: method_name = "heartbeat"; break;
        case 23: method_name = "set read_timeout"; break;
        case 24: method_name = "read_timeout"; break;
        case 25: method_name = "set write_timeout"; break;
        case 26: method_name = "write_timeout"; break;
        case 27: method_name = "set tcp_nodelay"; break;
        case 28: method_name = "tcp_nodelay"; break;
        case 29: method_name = "set tcp_rcvbuf"; break;
        case 30: method_name = "tcp_rcvbuf"; break;
        case 31: method_name = "set tcp_sndbuf"; break;
        case 32: method_name = "tcp_sndbuf"; break;
        case 33: method_name = "set frame_max"; break;
        case 34: method_name = "frame_max"; break;
        case 35: method_name = "set log_path"; break;
        case 36: method_name = "log_path"; break;
        case 37: method_name = "set keep_logs"; break;
        case 38: method_name = "keep_logs"; break;
        case 39: method_name = "set archive_path"; break;
        case 40: method_name = "archive_path"; break;
        case 41: method_name = "set archive_cmd"; break;
        case 42: method_name = "archive_cmd"; break;
        case 43: method_name = "set alert_log"; break;
        case 44: method_name = "alert_log"; break;
        case 45: method_name = "set daily_log"; break;
        case 46: method_name = "daily_log"; break;
        case 47: method_name = "set debug_log"; break;
        case 48: method_name = "debug_log"; break;
        case 49: method_name = "set trace"; break;
        case 50: method_name = "trace"; break;
        case 51: method_name = "dump log"; break;
        case 52: method_name = "selftest"; break;
        case 53: method_name = "terminate"; break;
        case 54: method_name = "show"; break;
        case 55: method_name = "destroy public"; break;
        case 56: method_name = "alloc"; break;
        case 57: method_name = "free"; break;
        case 58: method_name = "read lock"; break;
        case 59: method_name = "write lock"; break;
        case 60: method_name = "unlock"; break;
        case 61: method_name = "cache initialise"; break;
        case 62: method_name = "cache purge"; break;
        case 63: method_name = "cache terminate"; break;
        case 64: method_name = "show animation"; break;
        case 65: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "example %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *example_version_start        = "VeRsIoNsTaRt:ipc";
char *example_component            = "example ";
char *example_version              = "1.0 ";
char *example_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *example_filename             = "example.icl ";
char *example_builddate            = "2009/02/19 ";
char *example_version_end          = "VeRsIoNeNd:ipc";

