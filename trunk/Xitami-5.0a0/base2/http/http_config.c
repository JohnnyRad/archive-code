/*---------------------------------------------------------------------------
    http_config.c - http_config component

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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "http_config.h"                //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              http_config_t

//  Shorthands for class methods                                               

#define self_new            http_config_new
#define self_annihilate     http_config_annihilate
#define self_load_xmlfile   http_config_load_xmlfile
#define self_load_bucket    http_config_load_bucket
#define self_shadow         http_config_shadow
#define self_commit         http_config_commit
#define self_rollback       http_config_rollback
#define self_cmdline_help   http_config_cmdline_help
#define self_cmdline_parse  http_config_cmdline_parse
#define self_options_help   http_config_options_help
#define self_set_server_name  http_config_set_server_name
#define self_server_name    http_config_server_name
#define self_set_port       http_config_set_port
#define self_port           http_config_port
#define self_set_public_port  http_config_set_public_port
#define self_public_port    http_config_public_port
#define self_set_trace      http_config_set_trace
#define self_trace          http_config_trace
#define self_set_animate    http_config_set_animate
#define self_animate        http_config_animate
#define self_set_verbose    http_config_set_verbose
#define self_verbose        http_config_verbose
#define self_set_listen     http_config_set_listen
#define self_listen         http_config_listen
#define self_set_webroot    http_config_set_webroot
#define self_webroot        http_config_webroot
#define self_set_defaults   http_config_set_defaults
#define self_defaults       http_config_defaults
#define self_set_default_types  http_config_set_default_types
#define self_default_types  http_config_default_types
#define self_set_monitor    http_config_set_monitor
#define self_monitor        http_config_monitor
#define self_set_record_stats  http_config_set_record_stats
#define self_record_stats   http_config_record_stats
#define self_set_log_path   http_config_set_log_path
#define self_log_path       http_config_log_path
#define self_set_keep_logs  http_config_set_keep_logs
#define self_keep_logs      http_config_keep_logs
#define self_set_archive_path  http_config_set_archive_path
#define self_archive_path   http_config_archive_path
#define self_set_archive_cmd  http_config_set_archive_cmd
#define self_archive_cmd    http_config_archive_cmd
#define self_set_alert_log  http_config_set_alert_log
#define self_alert_log      http_config_alert_log
#define self_set_access_log  http_config_set_access_log
#define self_access_log     http_config_access_log
#define self_set_access_log_format  http_config_set_access_log_format
#define self_access_log_format  http_config_access_log_format
#define self_set_debug_log  http_config_set_debug_log
#define self_debug_log      http_config_debug_log
#define self_set_blacklist  http_config_set_blacklist
#define self_blacklist      http_config_blacklist
#define self_set_basic_auth  http_config_set_basic_auth
#define self_basic_auth     http_config_basic_auth
#define self_set_digest_auth  http_config_set_digest_auth
#define self_digest_auth    http_config_digest_auth
#define self_set_password_ttl  http_config_set_password_ttl
#define self_password_ttl   http_config_password_ttl
#define self_set_hit_quota  http_config_set_hit_quota
#define self_hit_quota      http_config_hit_quota
#define self_set_miss_quota  http_config_set_miss_quota
#define self_miss_quota     http_config_miss_quota
#define self_set_password_guard  http_config_set_password_guard
#define self_password_guard  http_config_password_guard
#define self_set_policy_trace  http_config_set_policy_trace
#define self_policy_trace   http_config_policy_trace
#define self_set_nervosity  http_config_set_nervosity
#define self_nervosity      http_config_nervosity
#define self_set_nonce_ttl  http_config_set_nonce_ttl
#define self_nonce_ttl      http_config_nonce_ttl
#define self_set_nonce_quota  http_config_set_nonce_quota
#define self_nonce_quota    http_config_nonce_quota
#define self_set_refresh_by  http_config_set_refresh_by
#define self_refresh_by     http_config_refresh_by
#define self_set_refresh_log  http_config_set_refresh_log
#define self_refresh_log    http_config_refresh_log
#define self_set_address_quota  http_config_set_address_quota
#define self_address_quota  http_config_address_quota
#define self_set_abort_delay  http_config_set_abort_delay
#define self_abort_delay    http_config_abort_delay
#define self_set_coremark_cycles  http_config_set_coremark_cycles
#define self_coremark_cycles  http_config_coremark_cycles
#define self_set_header_max  http_config_set_header_max
#define self_header_max     http_config_header_max
#define self_set_bucket_max  http_config_set_bucket_max
#define self_bucket_max     http_config_bucket_max
#define self_set_read_timeout  http_config_set_read_timeout
#define self_read_timeout   http_config_read_timeout
#define self_set_write_timeout  http_config_set_write_timeout
#define self_write_timeout  http_config_write_timeout
#define self_set_tcp_nodelay  http_config_set_tcp_nodelay
#define self_tcp_nodelay    http_config_tcp_nodelay
#define self_set_tcp_rcvbuf  http_config_set_tcp_rcvbuf
#define self_tcp_rcvbuf     http_config_tcp_rcvbuf
#define self_set_tcp_sndbuf  http_config_set_tcp_sndbuf
#define self_tcp_sndbuf     http_config_tcp_sndbuf
#define self_set_polling_threads  http_config_set_polling_threads
#define self_polling_threads  http_config_polling_threads
#define self_set_working_threads  http_config_set_working_threads
#define self_working_threads  http_config_working_threads
#define self_set_etag       http_config_set_etag
#define self_etag           http_config_etag
#define self_dump_log       http_config_dump_log
#define self_selftest       http_config_selftest
#define self_terminate      http_config_terminate
#define self_show           http_config_show
#define self_destroy        http_config_destroy
#define self_alloc          http_config_alloc
#define self_free           http_config_free
#define self_read_lock      http_config_read_lock
#define self_write_lock     http_config_write_lock
#define self_unlock         http_config_unlock
#define self_cache_initialise  http_config_cache_initialise
#define self_cache_purge    http_config_cache_purge
#define self_cache_terminate  http_config_cache_terminate
#define self_show_animation  http_config_show_animation
#define self_new_in_scope   http_config_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NEW))
static icl_stats_t *s_http_config_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DESTROY))
static icl_stats_t *s_http_config_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LOAD_XMLFILE))
static icl_stats_t *s_http_config_load_xmlfile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LOAD_BUCKET))
static icl_stats_t *s_http_config_load_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SHADOW))
static icl_stats_t *s_http_config_shadow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_COMMIT))
static icl_stats_t *s_http_config_commit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ROLLBACK))
static icl_stats_t *s_http_config_rollback_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CMDLINE_HELP))
static icl_stats_t *s_http_config_cmdline_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CMDLINE_PARSE))
static icl_stats_t *s_http_config_cmdline_parse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_OPTIONS_HELP))
static icl_stats_t *s_http_config_options_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_SERVER_NAME))
static icl_stats_t *s_http_config_set_server_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SERVER_NAME))
static icl_stats_t *s_http_config_server_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PORT))
static icl_stats_t *s_http_config_set_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PORT))
static icl_stats_t *s_http_config_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PUBLIC_PORT))
static icl_stats_t *s_http_config_set_public_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PUBLIC_PORT))
static icl_stats_t *s_http_config_public_port_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TRACE))
static icl_stats_t *s_http_config_set_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TRACE))
static icl_stats_t *s_http_config_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ANIMATE))
static icl_stats_t *s_http_config_set_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ANIMATE))
static icl_stats_t *s_http_config_animate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_VERBOSE))
static icl_stats_t *s_http_config_set_verbose_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_VERBOSE))
static icl_stats_t *s_http_config_verbose_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_LISTEN))
static icl_stats_t *s_http_config_set_listen_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LISTEN))
static icl_stats_t *s_http_config_listen_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_WEBROOT))
static icl_stats_t *s_http_config_set_webroot_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WEBROOT))
static icl_stats_t *s_http_config_webroot_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DEFAULTS))
static icl_stats_t *s_http_config_set_defaults_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DEFAULTS))
static icl_stats_t *s_http_config_defaults_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DEFAULT_TYPES))
static icl_stats_t *s_http_config_set_default_types_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DEFAULT_TYPES))
static icl_stats_t *s_http_config_default_types_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_MONITOR))
static icl_stats_t *s_http_config_set_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_MONITOR))
static icl_stats_t *s_http_config_monitor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_RECORD_STATS))
static icl_stats_t *s_http_config_set_record_stats_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_RECORD_STATS))
static icl_stats_t *s_http_config_record_stats_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_LOG_PATH))
static icl_stats_t *s_http_config_set_log_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LOG_PATH))
static icl_stats_t *s_http_config_log_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_KEEP_LOGS))
static icl_stats_t *s_http_config_set_keep_logs_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_KEEP_LOGS))
static icl_stats_t *s_http_config_keep_logs_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ARCHIVE_PATH))
static icl_stats_t *s_http_config_set_archive_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ARCHIVE_PATH))
static icl_stats_t *s_http_config_archive_path_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ARCHIVE_CMD))
static icl_stats_t *s_http_config_set_archive_cmd_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ARCHIVE_CMD))
static icl_stats_t *s_http_config_archive_cmd_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ALERT_LOG))
static icl_stats_t *s_http_config_set_alert_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ALERT_LOG))
static icl_stats_t *s_http_config_alert_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ACCESS_LOG))
static icl_stats_t *s_http_config_set_access_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ACCESS_LOG))
static icl_stats_t *s_http_config_access_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT))
static icl_stats_t *s_http_config_set_access_log_format_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ACCESS_LOG_FORMAT))
static icl_stats_t *s_http_config_access_log_format_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DEBUG_LOG))
static icl_stats_t *s_http_config_set_debug_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DEBUG_LOG))
static icl_stats_t *s_http_config_debug_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_BLACKLIST))
static icl_stats_t *s_http_config_set_blacklist_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_BLACKLIST))
static icl_stats_t *s_http_config_blacklist_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_BASIC_AUTH))
static icl_stats_t *s_http_config_set_basic_auth_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_BASIC_AUTH))
static icl_stats_t *s_http_config_basic_auth_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DIGEST_AUTH))
static icl_stats_t *s_http_config_set_digest_auth_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DIGEST_AUTH))
static icl_stats_t *s_http_config_digest_auth_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PASSWORD_TTL))
static icl_stats_t *s_http_config_set_password_ttl_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PASSWORD_TTL))
static icl_stats_t *s_http_config_password_ttl_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_HIT_QUOTA))
static icl_stats_t *s_http_config_set_hit_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_HIT_QUOTA))
static icl_stats_t *s_http_config_hit_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_MISS_QUOTA))
static icl_stats_t *s_http_config_set_miss_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_MISS_QUOTA))
static icl_stats_t *s_http_config_miss_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PASSWORD_GUARD))
static icl_stats_t *s_http_config_set_password_guard_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PASSWORD_GUARD))
static icl_stats_t *s_http_config_password_guard_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_POLICY_TRACE))
static icl_stats_t *s_http_config_set_policy_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_POLICY_TRACE))
static icl_stats_t *s_http_config_policy_trace_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_NERVOSITY))
static icl_stats_t *s_http_config_set_nervosity_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NERVOSITY))
static icl_stats_t *s_http_config_nervosity_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_NONCE_TTL))
static icl_stats_t *s_http_config_set_nonce_ttl_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NONCE_TTL))
static icl_stats_t *s_http_config_nonce_ttl_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_NONCE_QUOTA))
static icl_stats_t *s_http_config_set_nonce_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NONCE_QUOTA))
static icl_stats_t *s_http_config_nonce_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_REFRESH_BY))
static icl_stats_t *s_http_config_set_refresh_by_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_REFRESH_BY))
static icl_stats_t *s_http_config_refresh_by_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_REFRESH_LOG))
static icl_stats_t *s_http_config_set_refresh_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_REFRESH_LOG))
static icl_stats_t *s_http_config_refresh_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ADDRESS_QUOTA))
static icl_stats_t *s_http_config_set_address_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ADDRESS_QUOTA))
static icl_stats_t *s_http_config_address_quota_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ABORT_DELAY))
static icl_stats_t *s_http_config_set_abort_delay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ABORT_DELAY))
static icl_stats_t *s_http_config_abort_delay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_COREMARK_CYCLES))
static icl_stats_t *s_http_config_set_coremark_cycles_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_COREMARK_CYCLES))
static icl_stats_t *s_http_config_coremark_cycles_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_HEADER_MAX))
static icl_stats_t *s_http_config_set_header_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_HEADER_MAX))
static icl_stats_t *s_http_config_header_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_BUCKET_MAX))
static icl_stats_t *s_http_config_set_bucket_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_BUCKET_MAX))
static icl_stats_t *s_http_config_bucket_max_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_READ_TIMEOUT))
static icl_stats_t *s_http_config_set_read_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_READ_TIMEOUT))
static icl_stats_t *s_http_config_read_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_WRITE_TIMEOUT))
static icl_stats_t *s_http_config_set_write_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WRITE_TIMEOUT))
static icl_stats_t *s_http_config_write_timeout_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TCP_NODELAY))
static icl_stats_t *s_http_config_set_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TCP_NODELAY))
static icl_stats_t *s_http_config_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TCP_RCVBUF))
static icl_stats_t *s_http_config_set_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TCP_RCVBUF))
static icl_stats_t *s_http_config_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TCP_SNDBUF))
static icl_stats_t *s_http_config_set_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TCP_SNDBUF))
static icl_stats_t *s_http_config_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_POLLING_THREADS))
static icl_stats_t *s_http_config_set_polling_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_POLLING_THREADS))
static icl_stats_t *s_http_config_polling_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_WORKING_THREADS))
static icl_stats_t *s_http_config_set_working_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WORKING_THREADS))
static icl_stats_t *s_http_config_working_threads_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ETAG))
static icl_stats_t *s_http_config_set_etag_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ETAG))
static icl_stats_t *s_http_config_etag_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DUMP_LOG))
static icl_stats_t *s_http_config_dump_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SELFTEST))
static icl_stats_t *s_http_config_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TERMINATE))
static icl_stats_t *s_http_config_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SHOW))
static icl_stats_t *s_http_config_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DESTROY_PUBLIC))
static icl_stats_t *s_http_config_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ALLOC))
static icl_stats_t *s_http_config_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_FREE))
static icl_stats_t *s_http_config_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_READ_LOCK))
static icl_stats_t *s_http_config_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WRITE_LOCK))
static icl_stats_t *s_http_config_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_UNLOCK))
static icl_stats_t *s_http_config_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CACHE_INITIALISE))
static icl_stats_t *s_http_config_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CACHE_PURGE))
static icl_stats_t *s_http_config_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CACHE_TERMINATE))
static icl_stats_t *s_http_config_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SHOW_ANIMATION))
static icl_stats_t *s_http_config_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NEW_IN_SCOPE))
static icl_stats_t *s_http_config_new_in_scope_stats = NULL;
#endif
static void
    http_config_annihilate (
http_config_t * ( * self_p )            //  Reference to object reference
);

#define http_config_alloc()             http_config_alloc_ (__FILE__, __LINE__)
static http_config_t *
    http_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    http_config_free (
http_config_t * self                    //  Object reference
);

static void
    http_config_cache_initialise (
void);

static void
    http_config_cache_purge (
void);

static void
    http_config_cache_terminate (
void);

Bool
    http_config_animating = TRUE;       //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void s_validate_items (http_config_t *self);
static void s_get_properties (http_config_t *self);
http_config_t
    *http_config = NULL;            //  Server properties
static void s_validate_items (http_config_t *self)
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
        && strneq (item_name, "host")
        && strneq (item_name, "resources")
        && strneq (item_name, "logging")
        && strneq (item_name, "security")
        && strneq (item_name, "tuning")
        && strneq (item_name, "cache")
        && strneq (item_name, "access")
        && strneq (item_name, "content"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->config);
    }
}

static void s_get_properties (http_config_t *self)
{
    char
        *value;                         //  Configured value

    //  All properties on server path
    ipr_config_locate (self->config, "/config/server", NULL);

    //  Get server_name property from config file or built-in defaults
    value = ipr_config_get (self->config, "name", NULL);
    if (value)
        self->server_name = value;
    else
        self->server_name = "X5";

    //  Get port property from config file or built-in defaults
    value = ipr_config_get (self->config, "port", NULL);
    if (value)
        self->port = value;
    else
        self->port = "80";

    //  Get public_port property from config file or built-in defaults
    value = ipr_config_get (self->config, "public_port", NULL);
    if (value)
        self->public_port = value;
    else
        self->public_port = "";

    //  Get trace property from config file or built-in defaults
    value = ipr_config_get (self->config, "trace", NULL);
    if (value)
        self->trace = (Bool) atol (value);
    else
        self->trace = 0;

    //  Get animate property from config file or built-in defaults
    value = ipr_config_get (self->config, "animate", NULL);
    if (value)
        self->animate = (Bool) atol (value);
    else
        self->animate = 0;

    //  Get verbose property from config file or built-in defaults
    value = ipr_config_get (self->config, "verbose", NULL);
    if (value)
        self->verbose = (Bool) atol (value);
    else
        self->verbose = 0;

    //  Get listen property from config file or built-in defaults
    value = ipr_config_get (self->config, "listen", NULL);
    if (value)
        self->listen = value;
    else
        self->listen = "*";

    //  All properties on host path
    ipr_config_locate (self->config, "/config/host", NULL);

    //  Get webroot property from config file or built-in defaults
    value = ipr_config_get (self->config, "webroot", NULL);
    if (value)
        self->webroot = value;
    else
        self->webroot = "webpages";

    //  Get defaults property from config file or built-in defaults
    value = ipr_config_get (self->config, "defaults", NULL);
    if (value)
        self->defaults = value;
    else
        self->defaults = "index.html default.html";

    //  Get default_types property from config file or built-in defaults
    value = ipr_config_get (self->config, "default_types", NULL);
    if (value)
        self->default_types = value;
    else
        self->default_types = ".pdf .html";

    //  All properties on resources path
    ipr_config_locate (self->config, "/config/resources", NULL);

    //  Get monitor property from config file or built-in defaults
    value = ipr_config_get (self->config, "monitor", NULL);
    if (value)
        self->monitor = (int) atol (value);
    else
        self->monitor = 0;

    //  Get record_stats property from config file or built-in defaults
    value = ipr_config_get (self->config, "record_stats", NULL);
    if (value)
        self->record_stats = (Bool) atol (value);
    else
        self->record_stats = 0;

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

    //  Get access_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "access_log", NULL);
    if (value)
        self->access_log = value;
    else
        self->access_log = "access.log";

    //  Get access_log_format property from config file or built-in defaults
    value = ipr_config_get (self->config, "access_log_format", NULL);
    if (value)
        self->access_log_format = value;
    else
        self->access_log_format = "CLFX";

    //  Get debug_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "debug_log", NULL);
    if (value)
        self->debug_log = value;
    else
        self->debug_log = "debug.log";

    //  All properties on security path
    ipr_config_locate (self->config, "/config/security", NULL);

    //  Get blacklist property from config file or built-in defaults
    value = ipr_config_get (self->config, "blacklist", NULL);
    if (value)
        self->blacklist = value;
    else
        self->blacklist = "blacklist.txt";

    //  Get basic_auth property from config file or built-in defaults
    value = ipr_config_get (self->config, "basic_auth", NULL);
    if (value)
        self->basic_auth = value;
    else
        self->basic_auth = "passwd";

    //  Get digest_auth property from config file or built-in defaults
    value = ipr_config_get (self->config, "digest_auth", NULL);
    if (value)
        self->digest_auth = value;
    else
        self->digest_auth = "digest";

    //  Get password_ttl property from config file or built-in defaults
    value = ipr_config_get (self->config, "password_ttl", NULL);
    if (value)
        self->password_ttl = (int) atol (value);
    else
        self->password_ttl = 0;

    //  Get hit_quota property from config file or built-in defaults
    value = ipr_config_get (self->config, "hit_quota", NULL);
    if (value)
        self->hit_quota = (int) atol (value);
    else
        self->hit_quota = 0;

    //  Get miss_quota property from config file or built-in defaults
    value = ipr_config_get (self->config, "miss_quota", NULL);
    if (value)
        self->miss_quota = (int) atol (value);
    else
        self->miss_quota = 5;

    //  Get password_guard property from config file or built-in defaults
    value = ipr_config_get (self->config, "password_guard", NULL);
    if (value)
        self->password_guard = (int) atol (value);
    else
        self->password_guard = 10;

    //  Get policy_trace property from config file or built-in defaults
    value = ipr_config_get (self->config, "policy_trace", NULL);
    if (value)
        self->policy_trace = (Bool) atol (value);
    else
        self->policy_trace = 0;

    //  Get nervosity property from config file or built-in defaults
    value = ipr_config_get (self->config, "nervosity", NULL);
    if (value)
        self->nervosity = (int) atol (value);
    else
        self->nervosity = 5;
    if (self->nervosity < 1) {
        icl_console_print ("W: %s: illegal value %d for nervosity, using %d",
            self->filename, self->nervosity, 1);
        self->nervosity = 1;
    }

    //  Get nonce_ttl property from config file or built-in defaults
    value = ipr_config_get (self->config, "nonce_ttl", NULL);
    if (value)
        self->nonce_ttl = (int) atol (value);
    else
        self->nonce_ttl = 60;
    if (self->nonce_ttl < 1) {
        icl_console_print ("W: %s: illegal value %d for nonce_ttl, using %d",
            self->filename, self->nonce_ttl, 1);
        self->nonce_ttl = 1;
    }

    //  Get nonce_quota property from config file or built-in defaults
    value = ipr_config_get (self->config, "nonce_quota", NULL);
    if (value)
        self->nonce_quota = (int) atol (value);
    else
        self->nonce_quota = 25;
    if (self->nonce_quota < 1) {
        icl_console_print ("W: %s: illegal value %d for nonce_quota, using %d",
            self->filename, self->nonce_quota, 1);
        self->nonce_quota = 1;
    }

    //  Get refresh_by property from config file or built-in defaults
    value = ipr_config_get (self->config, "refresh_by", NULL);
    if (value)
        self->refresh_by = value;
    else
        self->refresh_by = "";

    //  Get refresh_log property from config file or built-in defaults
    value = ipr_config_get (self->config, "refresh_log", NULL);
    if (value)
        self->refresh_log = value;
    else
        self->refresh_log = "password_refresh.log";

    //  Get address_quota property from config file or built-in defaults
    value = ipr_config_get (self->config, "address_quota", NULL);
    if (value)
        self->address_quota = (int) atol (value);
    else
        self->address_quota = 5;

    //  Get abort_delay property from config file or built-in defaults
    value = ipr_config_get (self->config, "abort_delay", NULL);
    if (value)
        self->abort_delay = (int) atol (value);
    else
        self->abort_delay = 5;

    //  All properties on tuning path
    ipr_config_locate (self->config, "/config/tuning", NULL);

    //  Get coremark_cycles property from config file or built-in defaults
    value = ipr_config_get (self->config, "coremark_cycles", NULL);
    if (value)
        self->coremark_cycles = (int) atol (value);
    else
        self->coremark_cycles = 250000;

    //  Get header_max property from config file or built-in defaults
    value = ipr_config_get (self->config, "header_max", NULL);
    if (value)
        self->header_max = (int) atol (value);
    else
        self->header_max = 32000;
    if (self->header_max < 2048) {
        icl_console_print ("W: %s: illegal value %d for header_max, using %d",
            self->filename, self->header_max, 2048);
        self->header_max = 2048;
    }
    if (self->header_max > 2097152) {
        icl_console_print ("W: %s: illegal value %d for header_max, using %d",
            self->filename, self->header_max, 2097152);
        self->header_max = 2097152;
    }

    //  Get bucket_max property from config file or built-in defaults
    value = ipr_config_get (self->config, "bucket_max", NULL);
    if (value)
        self->bucket_max = (int) atol (value);
    else
        self->bucket_max = 128000;
    if (self->bucket_max > 2097152) {
        icl_console_print ("W: %s: illegal value %d for bucket_max, using %d",
            self->filename, self->bucket_max, 2097152);
        self->bucket_max = 2097152;
    }

    //  Get read_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "read_timeout", NULL);
    if (value)
        self->read_timeout = (int) atol (value);
    else
        self->read_timeout = 60;

    //  Get write_timeout property from config file or built-in defaults
    value = ipr_config_get (self->config, "write_timeout", NULL);
    if (value)
        self->write_timeout = (int) atol (value);
    else
        self->write_timeout = 60;

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

    //  Get polling_threads property from config file or built-in defaults
    value = ipr_config_get (self->config, "polling_threads", NULL);
    if (value)
        self->polling_threads = (int) atol (value);
    else
        self->polling_threads = 4;

    //  Get working_threads property from config file or built-in defaults
    value = ipr_config_get (self->config, "working_threads", NULL);
    if (value)
        self->working_threads = (int) atol (value);
    else
        self->working_threads = 4;

    //  All properties on cache path
    ipr_config_locate (self->config, "/config/cache", NULL);

    //  Get etag property from config file or built-in defaults
    value = ipr_config_get (self->config, "etag", NULL);
    if (value)
        self->etag = value;
    else
        self->etag = "fixed";

    //  All properties on access path
    ipr_config_locate (self->config, "/config/access", NULL);

    //  All properties on content path
    ipr_config_locate (self->config, "/config/content", NULL);
}
/*  -------------------------------------------------------------------------
    http_config_new

    Type: Component method
    Creates and initialises a new http_config_t object, returns a
    reference to the created object.
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    -------------------------------------------------------------------------
 */

http_config_t *
    http_config_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    http_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_NEW))
    if (http_config_animating)
        icl_console_print ("<http_config_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NEW))
    icl_trace_record (NULL, http_config_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NEW))
    icl_stats_inc ("http_config_new", &s_http_config_new_stats);
#endif

    self = http_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = HTTP_CONFIG_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, http_config_show_);
#endif

//
self->config = ipr_config_new (NULL, FALSE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NEW))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_NEW))
    if (http_config_animating)
        icl_console_print ("<http_config_new_finish"
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
    http_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_config_annihilate (
    http_config_t * ( * self_p )        //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    http_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DESTROY))
    if (http_config_animating)
        icl_console_print ("<http_config_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY))
    icl_trace_record (NULL, http_config_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DESTROY))
    icl_stats_inc ("http_config_annihilate", &s_http_config_annihilate_stats);
#endif

    HTTP_CONFIG_ASSERT_SANE (self);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DESTROY))
    if (http_config_animating)
        icl_console_print ("<http_config_destroy_finish"
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
    http_config_load_xmlfile

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    http_config_load_xmlfile (
    http_config_t * self,               //  Reference to object
    char * filename,                    //  Config file to load
    Bool required                       //  Config file is required?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_LOAD_XMLFILE))
    if (http_config_animating)
        icl_console_print ("<http_config_load_xmlfile_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, http_config_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LOAD_XMLFILE))
    icl_stats_inc ("http_config_load_xmlfile", &s_http_config_load_xmlfile_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
assert (filename);
if (!ipr_config_load (self->config, filename, required)) {
    icl_shortstr_cpy (self->filename, filename);
    s_validate_items (self);
    s_get_properties (self);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_LOAD_XMLFILE))
    if (http_config_animating)
        icl_console_print ("<http_config_load_xmlfile_finish"
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
    http_config_load_bucket

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    http_config_load_bucket (
    http_config_t * self,               //  Reference to object
    ipr_bucket_t * bucket               //  Config data to load
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_LOAD_BUCKET))
    if (http_config_animating)
        icl_console_print ("<http_config_load_bucket_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, http_config_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LOAD_BUCKET))
    icl_stats_inc ("http_config_load_bucket", &s_http_config_load_bucket_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->config, bucket);
s_validate_items (self);
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_LOAD_BUCKET))
    if (http_config_animating)
        icl_console_print ("<http_config_load_bucket_finish"
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
    http_config_shadow

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    -------------------------------------------------------------------------
 */

int
    http_config_shadow (
    http_config_t * self,               //  Reference to object
    ipr_config_t * source               //  Config data to shadow
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SHADOW))
    if (http_config_animating)
        icl_console_print ("<http_config_shadow_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SHADOW))
    icl_trace_record (NULL, http_config_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SHADOW))
    icl_stats_inc ("http_config_shadow", &s_http_config_shadow_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
//  Get rid of our own config data
ipr_config_destroy (&self->config);
//  Grab a handle onto the source data
self->config = ipr_config_dup (source);
//  Update our properties, without validation
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SHADOW))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SHADOW))
    if (http_config_animating)
        icl_console_print ("<http_config_shadow_finish"
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
    http_config_commit

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    -------------------------------------------------------------------------
 */

int
    http_config_commit (
    http_config_t * self,               //  Reference to object
    char * filename                     //  Config file to save
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_COMMIT))
    if (http_config_animating)
        icl_console_print ("<http_config_commit_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_COMMIT))
    icl_trace_record (NULL, http_config_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_COMMIT))
    icl_stats_inc ("http_config_commit", &s_http_config_commit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_COMMIT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_COMMIT))
    if (http_config_animating)
        icl_console_print ("<http_config_commit_finish"
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
    http_config_rollback

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    -------------------------------------------------------------------------
 */

int
    http_config_rollback (
    http_config_t * self                //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ROLLBACK))
    if (http_config_animating)
        icl_console_print ("<http_config_rollback_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ROLLBACK))
    icl_trace_record (NULL, http_config_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ROLLBACK))
    icl_stats_inc ("http_config_rollback", &s_http_config_rollback_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
ipr_config_destroy (&self->config);
self->config = ipr_config_new (self->filename, TRUE);
s_get_properties (self);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ROLLBACK))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ROLLBACK))
    if (http_config_animating)
        icl_console_print ("<http_config_rollback_finish"
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
    http_config_cmdline_help

    Type: Component method
    Prints command-line help for setting options from the command
    line.
    -------------------------------------------------------------------------
 */

void
    http_config_cmdline_help (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_CMDLINE_HELP))
    if (http_config_animating)
        icl_console_print ("<http_config_cmdline_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, http_config_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CMDLINE_HELP))
    icl_stats_inc ("http_config_cmdline_help", &s_http_config_cmdline_help_stats);
#endif

printf ("Options that override config values; these take an argument:\n");
printf ("  --server_name    Announced server name\n");
printf ("  --port           Server port for HTTP requests\n");
printf ("  --public_port    Public port for HTTP requests\n");
printf ("  --trace          Trace network traffic?\n");
printf ("  --animate        Animate HTTP agent?\n");
printf ("  --verbose        Verbose output?\n");
printf ("  --listen         Address (local network interface) to listen on\n");
printf ("  --webroot        Path to web root directory\n");
printf ("  --defaults       Default file names\n");
printf ("  --default_types  Default document types\n");
printf ("  --monitor        Monitor interval, seconds\n");
printf ("  --record_stats   Record performance statistics\n");
printf ("  --log_path       Active log file directory\n");
printf ("  --keep_logs      Keep log files\n");
printf ("  --archive_path   Archive log file directory\n");
printf ("  --archive_cmd    Archive log file command\n");
printf ("  --alert_log      Error log file name\n");
printf ("  --access_log     Access log file name\n");
printf ("  --access_log_format  Access log file format\n");
printf ("  --debug_log      Debug log file name\n");
printf ("  --blacklist      Blacklist filename\n");
printf ("  --basic_auth     Basic authentication filename\n");
printf ("  --digest_auth    Digest authentication filename\n");
printf ("  --password_ttl   Password time-to-live, in seconds\n");
printf ("  --hit_quota      Password hit quota in pages\n");
printf ("  --miss_quota     Password miss quota in requests\n");
printf ("  --password_guard  Password guard timer, in seconds.\n");
printf ("  --policy_trace   Debug policy execution?\n");
printf ("  --nervosity      Security nervosity, seconds\n");
printf ("  --nonce_ttl      Nonce time-to-live, seconds\n");
printf ("  --nonce_quota    Nonce quota in requests\n");
printf ("  --refresh_by     Shell command for password refresh\n");
printf ("  --refresh_log    Stdout for password refresh\n");
printf ("  --address_quota  Maximum open connections per address\n");
printf ("  --abort_delay    Pause time for hostile connections\n");
printf ("  --coremark_cycles  Duration of CoreMark test\n");
printf ("  --header_max     Max size of HTTP header\n");
printf ("  --bucket_max     Max size of content bucket\n");
printf ("  --read_timeout   Network read timeout, seconds\n");
printf ("  --write_timeout  Network write timeout, seconds\n");
printf ("  --tcp_nodelay    TCP/IP NODELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
printf ("  --polling_threads  Number of polling OS threads\n");
printf ("  --working_threads  Number of working OS threads\n");
printf ("  --etag           ETag header for files\n");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_CMDLINE_HELP))
    if (http_config_animating)
        icl_console_print ("<http_config_cmdline_help_finish"
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
    http_config_cmdline_parse

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    -------------------------------------------------------------------------
 */

int
    http_config_cmdline_parse (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_CMDLINE_PARSE))
    if (http_config_animating)
        icl_console_print ("<http_config_cmdline_parse_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, http_config_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CMDLINE_PARSE))
    icl_stats_inc ("http_config_cmdline_parse", &s_http_config_cmdline_parse_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

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
            if (streq (arg_name, "--server_name"))
                self_set_server_name (self, arg_value);
            else
            if (streq (arg_name, "--port"))
                self_set_port (self, arg_value);
            else
            if (streq (arg_name, "--public_port"))
                self_set_public_port (self, arg_value);
            else
            if (streq (arg_name, "--trace"))
                self_set_trace (self, atoi (arg_value));
            else
            if (streq (arg_name, "--animate"))
                self_set_animate (self, atoi (arg_value));
            else
            if (streq (arg_name, "--verbose"))
                self_set_verbose (self, atoi (arg_value));
            else
            if (streq (arg_name, "--listen"))
                self_set_listen (self, arg_value);
            else
            if (streq (arg_name, "--webroot"))
                self_set_webroot (self, arg_value);
            else
            if (streq (arg_name, "--defaults"))
                self_set_defaults (self, arg_value);
            else
            if (streq (arg_name, "--default_types"))
                self_set_default_types (self, arg_value);
            else
            if (streq (arg_name, "--monitor"))
                self_set_monitor (self, atoi (arg_value));
            else
            if (streq (arg_name, "--record_stats"))
                self_set_record_stats (self, atoi (arg_value));
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
            if (streq (arg_name, "--access_log"))
                self_set_access_log (self, arg_value);
            else
            if (streq (arg_name, "--access_log_format"))
                self_set_access_log_format (self, arg_value);
            else
            if (streq (arg_name, "--debug_log"))
                self_set_debug_log (self, arg_value);
            else
            if (streq (arg_name, "--blacklist"))
                self_set_blacklist (self, arg_value);
            else
            if (streq (arg_name, "--basic_auth"))
                self_set_basic_auth (self, arg_value);
            else
            if (streq (arg_name, "--digest_auth"))
                self_set_digest_auth (self, arg_value);
            else
            if (streq (arg_name, "--password_ttl"))
                self_set_password_ttl (self, atoi (arg_value));
            else
            if (streq (arg_name, "--hit_quota"))
                self_set_hit_quota (self, atoi (arg_value));
            else
            if (streq (arg_name, "--miss_quota"))
                self_set_miss_quota (self, atoi (arg_value));
            else
            if (streq (arg_name, "--password_guard"))
                self_set_password_guard (self, atoi (arg_value));
            else
            if (streq (arg_name, "--policy_trace"))
                self_set_policy_trace (self, atoi (arg_value));
            else
            if (streq (arg_name, "--nervosity"))
                self_set_nervosity (self, atoi (arg_value));
            else
            if (streq (arg_name, "--nonce_ttl"))
                self_set_nonce_ttl (self, atoi (arg_value));
            else
            if (streq (arg_name, "--nonce_quota"))
                self_set_nonce_quota (self, atoi (arg_value));
            else
            if (streq (arg_name, "--refresh_by"))
                self_set_refresh_by (self, arg_value);
            else
            if (streq (arg_name, "--refresh_log"))
                self_set_refresh_log (self, arg_value);
            else
            if (streq (arg_name, "--address_quota"))
                self_set_address_quota (self, atoi (arg_value));
            else
            if (streq (arg_name, "--abort_delay"))
                self_set_abort_delay (self, atoi (arg_value));
            else
            if (streq (arg_name, "--coremark_cycles"))
                self_set_coremark_cycles (self, atoi (arg_value));
            else
            if (streq (arg_name, "--header_max"))
                self_set_header_max (self, atoi (arg_value));
            else
            if (streq (arg_name, "--bucket_max"))
                self_set_bucket_max (self, atoi (arg_value));
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
            if (streq (arg_name, "--polling_threads"))
                self_set_polling_threads (self, atoi (arg_value));
            else
            if (streq (arg_name, "--working_threads"))
                self_set_working_threads (self, atoi (arg_value));
            else
            if (streq (arg_name, "--etag"))
                self_set_etag (self, arg_value);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_CMDLINE_PARSE))
    if (http_config_animating)
        icl_console_print ("<http_config_cmdline_parse_finish"
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
    http_config_options_help

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints full help for all configuration options.
    -------------------------------------------------------------------------
 */

int
    http_config_options_help (
    http_config_t * self,               //  Reference to object
    char * name                         //  Name of application
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_OPTIONS_HELP))
    if (http_config_animating)
        icl_console_print ("<http_config_options_help_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, http_config_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_OPTIONS_HELP))
    icl_stats_inc ("http_config_options_help", &s_http_config_options_help_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

printf ("These are the configured options for %s\n\n", name);

printf ("/config/server/name - Announced server name\n");
printf ("    From command-line: --server_name newvalue\n");
printf ("    Specifies the Server: header field name for HTTP responses.\n");
printf ("    Current value is '%s'. Default value is 'X5'\n", self->server_name);
printf ("\n");

printf ("/config/server/port - Server port for HTTP requests\n");
printf ("    From command-line: --port newvalue\n");
printf ("    Specifies the port that the server opens for HTTP requests. The standard\n");
printf ("    port for HTTP is 80. If you want to run the server in parallel with     \n");
printf ("    other HTTP servers on the same server, choose a server port of 4096 or  \n");
printf ("    higher. If you are serving Internet clients, your network may map a     \n");
printf ("    public port to the server port number. In that case, you may need to    \n");
printf ("    specify the public port number separately.                              \n");
printf ("    Current value is '%s'. Default value is '80'\n", self->port);
printf ("\n");

printf ("/config/server/public_port - Public port for HTTP requests\n");
printf ("    From command-line: --public_port newvalue\n");
printf ("    Specifies the public port for client requests, if not the standard port\n");
printf ("    number for HTTP (80). The server needs to know this value in order to  \n");
printf ("    format accurate redirection responses.                                 \n");
printf ("    Current value is '%s'.\n", self->public_port);
printf ("\n");

printf ("/config/server/trace - Trace network traffic?\n");
printf ("    From command-line: --trace newvalue\n");
printf ("    If set, the HTTP agent displays all socket i/o, which can be useful if  \n");
printf ("    you need to verify what exactly web clients are sending and getting back\n");
printf ("    from the server. Do not enable this with high loads because you will get\n");
printf ("    enormous amounts of output.                                             \n");
printf ("    Current value is %i. Default value is 0.\n", self->trace);
printf ("\n");

printf ("/config/server/animate - Animate HTTP agent?\n");
printf ("    From command-line: --animate newvalue\n");
printf ("    If set, the HTTP agent displays its activity, which can be useful if you\n");
printf ("    need to verify how HTTP requests are being processed. Do not enable this\n");
printf ("    with high loads because you will get enormous amounts of output.        \n");
printf ("    Current value is %i. Default value is 0.\n", self->animate);
printf ("\n");

printf ("/config/server/verbose - Verbose output?\n");
printf ("    From command-line: --verbose newvalue\n");
printf ("    If set, the HTTP agent displays all input and output headers, which can\n");
printf ("    be useful for debugging configuration issues.                          \n");
printf ("    Current value is %i. Default value is 0.\n", self->verbose);
printf ("\n");

printf ("/config/server/listen - Address (local network interface) to listen on\n");
printf ("    From command-line: --listen newvalue\n");
printf ("    Specifies the network interface on which the server should listen for\n");
printf ("    connections. By default this is *, meaning all interfaces. You would \n");
printf ("    choose to set an address when you use this application on a box with \n");
printf ("    multiple network interfaces, e.g. routing between two networks.      \n");
printf ("    Current value is '%s'. Default value is '*'\n", self->listen);
printf ("\n");

printf ("/config/host/webroot - Path to web root directory\n");
printf ("    From command-line: --webroot newvalue\n");
printf ("    Specifies the web root directory. Normally this is used to hold static\n");
printf ("    resources - HTML, images, etc. The web root maps to the / URI.        \n");
printf ("    Current value is '%s'. Default value is 'webpages'\n", self->webroot);
printf ("\n");

printf ("/config/host/defaults - Default file names\n");
printf ("    From command-line: --defaults newvalue\n");
printf ("    Specifies a space-delimited list of file names to use as defaults on an \n");
printf ("    empty URI path (the URI refers to a directory name). If none of the     \n");
printf ("    defaults are present, Xitami will look for a file called .httpdir and if\n");
printf ("    that is present, it will format a directory listing.                    \n");
printf ("    Current value is '%s'. Default value is 'index.html default.html'\n", self->defaults);
printf ("\n");

printf ("/config/host/default_types - Default document types\n");
printf ("    From command-line: --default_types newvalue\n");
printf ("    Specifies a list of default document types. The server implements a    \n");
printf ("    feature called 'default typing' in which you can specify URIs without  \n");
printf ("    file extensions. The default types are specified in order. You can use \n");
printf ("    this to publish a URI that specifies an HTML document, for example, and\n");
printf ("    later replace it with a PDF without breaking the published URI.        \n");
printf ("    Current value is '%s'. Default value is '.pdf .html'\n", self->default_types);
printf ("\n");

printf ("/config/resources/monitor - Monitor interval, seconds\n");
printf ("    From command-line: --monitor newvalue\n");
printf ("    Specifies the interval in seconds at which the server will report its   \n");
printf ("    request/response rates. If zero, no monitoring is shown. The recommended\n");
printf ("    value is 1, if monitoring is desired.                                   \n");
printf ("    Current value is %i. Default value is 0.\n", self->monitor);
printf ("\n");

printf ("/config/resources/record_stats - Record performance statistics\n");
printf ("    From command-line: --record_stats newvalue\n");
printf ("    Specifies whether or not the server records performance statistics in a\n");
printf ("    format suitable for importing into a spreadsheet. If set, the server   \n");
printf ("    creates a file called 'http_stats_(portnumber).del' which contains     \n");
printf ("    performance statistics in a comma-delimited format. For this setting to\n");
printf ("    take effect, the monitor option must also be set.                      \n");
printf ("    Current value is %i. Default value is 0.\n", self->record_stats);
printf ("\n");

printf ("/config/logging/log_path - Active log file directory\n");
printf ("    From command-line: --log_path newvalue\n");
printf ("    Specifies the directory path into which active log files are placed.\n");
printf ("    Current value is '%s'. Default value is 'logs'\n", self->log_path);
printf ("\n");

printf ("/config/logging/keep_logs - Keep log files\n");
printf ("    From command-line: --keep_logs newvalue\n");
printf ("    Specifies whether or not the server should keep logs. If zero, the   \n");
printf ("    server will not keep logs. If 1, it will keep an alert log, an access\n");
printf ("    log, and a debug log as specified.                                   \n");
printf ("    Current value is %i. Default value is 1.\n", self->keep_logs);
printf ("\n");

printf ("/config/logging/archive_path - Archive log file directory\n");
printf ("    From command-line: --archive_path newvalue\n");
printf ("    Specifies the directory path into which archived log files are placed. \n");
printf ("    This can be the same as the active path; archived log files are renamed\n");
printf ("    to avoid conflict with active log files.                               \n");
printf ("    Current value is '%s'. Default value is 'archive'\n", self->archive_path);
printf ("\n");

printf ("/config/logging/archive_cmd - Archive log file command\n");
printf ("    From command-line: --archive_cmd newvalue\n");
printf ("    If specified, this command is run on all archived log files. You can use\n");
printf ("    this option to compress archived log files, or clean up old and unwanted\n");
printf ("    files. When the command is run, the name of the archived log file is    \n");
printf ("    provided to it as a single argument.                                    \n");
printf ("    Current value is '%s'.\n", self->archive_cmd);
printf ("\n");

printf ("/config/logging/alert_log - Error log file name\n");
printf ("    From command-line: --alert_log newvalue\n");
printf ("    The name of the alert log file, which records all errors and warnings \n");
printf ("    issued by the server. Note that the server port number is always added\n");
printf ("    to the name of the log file.                                          \n");
printf ("    Current value is '%s'. Default value is 'alert.log'\n", self->alert_log);
printf ("\n");

printf ("/config/logging/access_log - Access log file name\n");
printf ("    From command-line: --access_log newvalue\n");
printf ("    The name of the access log file, which records all HTTP requests in the\n");
printf ("    specified access log format. Note that the server port number is always\n");
printf ("    added to the name of the log file.                                     \n");
printf ("    Current value is '%s'. Default value is 'access.log'\n", self->access_log);
printf ("\n");

printf ("/config/logging/access_log_format - Access log file format\n");
printf ("    From command-line: --access_log_format newvalue\n");
printf ("    The format of the access log file, which can be one of: CLF - NCSA/httpd\n");
printf ("    common logging format (basic); CLFX - Apache format; or other - custom  \n");
printf ("    log file format.                                                        \n");
printf ("    Current value is '%s'. Default value is 'CLFX'\n", self->access_log_format);
printf ("\n");

printf ("/config/logging/debug_log - Debug log file name\n");
printf ("    From command-line: --debug_log newvalue\n");
printf ("    The name of the debug log file, which records all normal activity,      \n");
printf ("    errors, and debug trace information. Note that the server port number is\n");
printf ("    always added to the name of the log file.                               \n");
printf ("    Current value is '%s'. Default value is 'debug.log'\n", self->debug_log);
printf ("\n");

printf ("/config/security/blacklist - Blacklist filename\n");
printf ("    From command-line: --blacklist newvalue\n");
printf ("    Specifies a text file to use for the blacklist. The blacklist is an easy\n");
printf ("    way to blacklist IP addresses of spammers without modifying the main    \n");
printf ("    server configuration files. This file contains one IP address per line. \n");
printf ("    To disable blacklisting, set the option to a non-existent file or "".   \n");
printf ("    Current value is '%s'. Default value is 'blacklist.txt'\n", self->blacklist);
printf ("\n");

printf ("/config/security/basic_auth - Basic authentication filename\n");
printf ("    From command-line: --basic_auth newvalue\n");
printf ("    Specifies the file to use for Basic authentication. The file uses the   \n");
printf ("    Apache htpasswd format, see                                             \n");
printf ("    http://httpd.apache.org/docs/2.2/misc/password_encryptions.html. The    \n");
printf ("    plain text format of each line in this file, if you don't have the      \n");
printf ("    htpasswd tool, is '{username}:{password}'. You can mix digest and passwd\n");
printf ("    password entries in a single file.                                      \n");
printf ("    Current value is '%s'. Default value is 'passwd'\n", self->basic_auth);
printf ("\n");

printf ("/config/security/digest_auth - Digest authentication filename\n");
printf ("    From command-line: --digest_auth newvalue\n");
printf ("    Specifies the file to use for Digest authentication. The file uses the\n");
printf ("    Apache htdigest format, see                                           \n");
printf ("    http://httpd.apache.org/docs/2.2/misc/password_encryptions.html.      \n");
printf ("    Current value is '%s'. Default value is 'digest'\n", self->digest_auth);
printf ("\n");

printf ("/config/security/password_ttl - Password time-to-live, in seconds\n");
printf ("    From command-line: --password_ttl newvalue\n");
printf ("    If set to a non-zero value, passwords will expire this many seconds  \n");
printf ("    after they are first loaded into Xitami. You can reset an expired    \n");
printf ("    password by editing the password file or setting a new password using\n");
printf ("    the Apache htpasswd / htdigest tools.                                \n");
printf ("    Current value is %i. Default value is 0.\n", self->password_ttl);
printf ("\n");

printf ("/config/security/hit_quota - Password hit quota in pages\n");
printf ("    From command-line: --hit_quota newvalue\n");
printf ("    If greater than zero, specifies the number of requests that a browser  \n");
printf ("    can make using the same user id (+ realm, for Digest authentication).  \n");
printf ("    When this quota is exhausted, the id password expires. You can reset an\n");
printf ("    expired password by editing the password file or setting a new password\n");
printf ("    using the Apache htpasswd / htdigest tools.                            \n");
printf ("    Current value is %i. Default value is 0.\n", self->hit_quota);
printf ("\n");

printf ("/config/security/miss_quota - Password miss quota in requests\n");
printf ("    From command-line: --miss_quota newvalue\n");
printf ("    If greater than zero, specifies the number of failed requests that a   \n");
printf ("    browser can make using the same user id (+ realm, for Digest           \n");
printf ("    authentication). When this quota is exhausted, the id password expires.\n");
printf ("    You can reset an expired password by editing the password file or      \n");
printf ("    setting a new password using the Apache htpasswd / htdigest tools.     \n");
printf ("    Current value is %i. Default value is 5.\n", self->miss_quota);
printf ("\n");

printf ("/config/security/password_guard - Password guard timer, in seconds.\n");
printf ("    From command-line: --password_guard newvalue\n");
printf ("    If greater than zero, specifies the frequency with which Xitami saves  \n");
printf ("    password guard data. The password guard ensures that the hit and miss  \n");
printf ("    quotas are properly written to disk so that if Xitami is restarted this\n");
printf ("    data is not lost. If set to zero, Xitami will never save password guard\n");
printf ("    data.                                                                  \n");
printf ("    Current value is %i. Default value is 10.\n", self->password_guard);
printf ("\n");

printf ("/config/security/policy_trace - Debug policy execution?\n");
printf ("    From command-line: --policy_trace newvalue\n");
printf ("    Specifies whether policy execution is logged or not. Set this option to\n");
printf ("    get a visual trace of policy execution, especially when you write your \n");
printf ("    own policies. Do not use on production servers, it will generate vast  \n");
printf ("    amounts of output and slow things down.                                \n");
printf ("    Current value is %i. Default value is 0.\n", self->policy_trace);
printf ("\n");

printf ("/config/security/nervosity - Security nervosity, seconds\n");
printf ("    From command-line: --nervosity newvalue\n");
printf ("    Specifies the interval in seconds at which the server will reload       \n");
printf ("    externally modified security files (blacklist, password, and digest).   \n");
printf ("    You can reduce this to one second but this will cause latency spikes due\n");
printf ("    to CPU burn and memory churn if you have very large blacklist files.    \n");
printf ("    Current value is %i. Default value is 5.\n", self->nervosity);
printf ("\n");

printf ("/config/security/nonce_ttl - Nonce time-to-live, seconds\n");
printf ("    From command-line: --nonce_ttl newvalue\n");
printf ("    This specifies the validity for Digest authentication nonces. Reducing \n");
printf ("    this will increase chatter, as browsers need to request new nonces more\n");
printf ("    often, but reduces the opportunity for replay attacks.                 \n");
printf ("    Current value is %i. Default value is 60.\n", self->nonce_ttl);
printf ("\n");

printf ("/config/security/nonce_quota - Nonce quota in requests\n");
printf ("    From command-line: --nonce_quota newvalue\n");
printf ("    This specifies the number of requests that a browser can make using the\n");
printf ("    same Digest authentication nonce. When this quota is exhausted, the    \n");
printf ("    nonce expires. If set to 1, browsers must ask for a new nonce at each  \n");
printf ("    request.                                                               \n");
printf ("    Current value is %i. Default value is 25.\n", self->nonce_quota);
printf ("\n");

printf ("/config/security/refresh_by - Shell command for password refresh\n");
printf ("    From command-line: --refresh_by newvalue\n");
printf ("    If specified, the http_access_refresh module runs this command to   \n");
printf ("    refresh expired or unknown passwords. You may use this to tie Xitami\n");
printf ("    authentication to external or system authentication systems. See    \n");
printf ("    documentation for details.                                          \n");
printf ("    Current value is '%s'.\n", self->refresh_by);
printf ("\n");

printf ("/config/security/refresh_log - Stdout for password refresh\n");
printf ("    From command-line: --refresh_log newvalue\n");
printf ("    Specifies the log file for the refresh command. All messages produced by\n");
printf ("    the refresh command (stdout and stderr) will be appended to this file.  \n");
printf ("    Current value is '%s'. Default value is 'password_refresh.log'\n", self->refresh_log);
printf ("\n");

printf ("/config/security/address_quota - Maximum open connections per address\n");
printf ("    From command-line: --address_quota newvalue\n");
printf ("    If greater than zero, specifies the number of open connections a client\n");
printf ("    can have. Setting this value to zero allows unlimited connections per  \n");
printf ("    address. This setting is used by the DoS module to detect and handle   \n");
printf ("    simple attempts to crash the server by overloading it with lots of     \n");
printf ("    connections.                                                           \n");
printf ("    Current value is %i. Default value is 5.\n", self->address_quota);
printf ("\n");

printf ("/config/security/abort_delay - Pause time for hostile connections\n");
printf ("    From command-line: --abort_delay newvalue\n");
printf ("    This specifies the number of seconds that the server will wait, when    \n");
printf ("    shutting a connection due to detected hostile activity. The delay wastes\n");
printf ("    browser time, making attacks less efficient.                            \n");
printf ("    Current value is %i. Default value is 5.\n", self->abort_delay);
printf ("\n");

printf ("/config/tuning/coremark_cycles - Duration of CoreMark test\n");
printf ("    From command-line: --coremark_cycles newvalue\n");
printf ("    Defines the duration of the automatic CoreMark performance test, in  \n");
printf ("    event cycles. If 0, no test will be done. Setting this too high will \n");
printf ("    cause the server to burn CPU at startup. A good value is between 100k\n");
printf ("    and 1M.                                                              \n");
printf ("    Current value is %i. Default value is 250000.\n", self->coremark_cycles);
printf ("\n");

printf ("/config/tuning/header_max - Max size of HTTP header\n");
printf ("    From command-line: --header_max newvalue\n");
printf ("    Defines the limit for HTTP headers; the server will accept up to this   \n");
printf ("    much data. You can increase the limit if you have applications that pass\n");
printf ("    excessive amounts of data as URI arguments, but usually it is           \n");
printf ("    recommended to pass large web forms as POST body data.                  \n");
printf ("    Current value is %i. Default value is 32000.\n", self->header_max);
printf ("\n");

printf ("/config/tuning/bucket_max - Max size of content bucket\n");
printf ("    From command-line: --bucket_max newvalue\n");
printf ("    Defines the limit for content managed as a memory bucket. The HTTP   \n");
printf ("    server can handle contents of any size, but if they exceed the bucket\n");
printf ("    max they will be spooled to disk, which can be slow.                 \n");
printf ("    Current value is %i. Default value is 128000.\n", self->bucket_max);
printf ("\n");

printf ("/config/tuning/read_timeout - Network read timeout, seconds\n");
printf ("    From command-line: --read_timeout newvalue\n");
printf ("    Defines the timeout for network reads. If a client does not send data \n");
printf ("    within this time, it is considered dead. If you get unexpected timeout\n");
printf ("    errors in the logs, you may want to increase this value.              \n");
printf ("    Current value is %i. Default value is 60.\n", self->read_timeout);
printf ("\n");

printf ("/config/tuning/write_timeout - Network write timeout, seconds\n");
printf ("    From command-line: --write_timeout newvalue\n");
printf ("    Defines the timeout for network writes. If a client does not accept data\n");
printf ("    within this time, it is considered dead. If you get unexpected timeout  \n");
printf ("    errors in the logs, you may want to increase this value.                \n");
printf ("    Current value is %i. Default value is 60.\n", self->write_timeout);
printf ("\n");

printf ("/config/tuning/tcp_nodelay - TCP/IP NODELAY option\n");
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
printf ("    Current value is %i. Default value is 0.\n", self->tcp_rcvbuf);
printf ("\n");

printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\n");
printf ("    From command-line: --tcp_sndbuf newvalue\n");
printf ("    If this value is greater than zero, all client connections will use the\n");
printf ("    specified value. Note: setting this value is delicate, do not use this \n");
printf ("    option unless you know what you are doing.                             \n");
printf ("    Current value is %i. Default value is 0.\n", self->tcp_sndbuf);
printf ("\n");

printf ("/config/tuning/polling_threads - Number of polling OS threads\n");
printf ("    From command-line: --polling_threads newvalue\n");
printf ("    On multithreaded builds, defines the number of OS threads dedicated to\n");
printf ("    socket polling.                                                       \n");
printf ("    Current value is %i. Default value is 4.\n", self->polling_threads);
printf ("\n");

printf ("/config/tuning/working_threads - Number of working OS threads\n");
printf ("    From command-line: --working_threads newvalue\n");
printf ("    On multithreaded builds, defines the number of OS threads dedicated to\n");
printf ("    processing, that is, tasks other than socket polling.                 \n");
printf ("    Current value is %i. Default value is 4.\n", self->working_threads);
printf ("\n");

printf ("/config/cache/etag - ETag header for files\n");
printf ("    From command-line: --etag newvalue\n");
printf ("    Defines the ETag header value to use for files. If 'fixed', the ETag  \n");
printf ("    consists of the file's modified time, size, and inode. If the etag    \n");
printf ("    option is 'float', the ETag consists of the file's modified time and  \n");
printf ("    size only. This is useful for large deployments where files are served\n");
printf ("    from multiple file systems. If the ETag option is set to any other    \n");
printf ("    value, no ETag headers will be produced.                              \n");
printf ("    Current value is '%s'. Default value is 'fixed'\n", self->etag);
printf ("\n");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_OPTIONS_HELP))
    if (http_config_animating)
        icl_console_print ("<http_config_options_help_finish"
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
    http_config_set_server_name

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_server_name (
    http_config_t * self,               //  Reference to object
    char * server_name                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_SERVER_NAME))
    if (http_config_animating)
        icl_console_print ("<http_config_set_server_name_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" server_name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, server_name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_SERVER_NAME))
    icl_trace_record (NULL, http_config_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_SERVER_NAME))
    icl_stats_inc ("http_config_set_server_name", &s_http_config_set_server_name_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "name", server_name);
server_name = ipr_config_getp (self->config, "/config/server", "name", NULL);
assert (server_name);
self->server_name = server_name;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_SERVER_NAME))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_SERVER_NAME))
    if (http_config_animating)
        icl_console_print ("<http_config_set_server_name_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" server_name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, server_name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_server_name

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_server_name (
    http_config_t * self                //  Reference to self
)
{
    char *
        server_name;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SERVER_NAME))
    if (http_config_animating)
        icl_console_print ("<http_config_server_name_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SERVER_NAME))
    icl_trace_record (NULL, http_config_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SERVER_NAME))
    icl_stats_inc ("http_config_server_name", &s_http_config_server_name_stats);
#endif

//
if (self)
    server_name = self->server_name;
else
    server_name = "X5";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SERVER_NAME))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SERVER_NAME))
    if (http_config_animating)
        icl_console_print ("<http_config_server_name_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" server_name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, server_name);
#endif


    return (server_name);
}
/*  -------------------------------------------------------------------------
    http_config_set_port

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_port (
    http_config_t * self,               //  Reference to object
    char * port                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_port_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PORT))
    icl_trace_record (NULL, http_config_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PORT))
    icl_stats_inc ("http_config_set_port", &s_http_config_set_port_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "port", port);
port = ipr_config_getp (self->config, "/config/server", "port", NULL);
assert (port);
self->port = port;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PORT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_port_finish"
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
    http_config_port

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_port (
    http_config_t * self                //  Reference to self
)
{
    char *
        port;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_port_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PORT))
    icl_trace_record (NULL, http_config_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PORT))
    icl_stats_inc ("http_config_port", &s_http_config_port_stats);
#endif

//
if (self)
    port = self->port;
else
    port = "80";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PORT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_port_finish"
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
    http_config_set_public_port

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_public_port (
    http_config_t * self,               //  Reference to object
    char * public_port                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_PUBLIC_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_public_port_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" public_port=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, public_port);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PUBLIC_PORT))
    icl_trace_record (NULL, http_config_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PUBLIC_PORT))
    icl_stats_inc ("http_config_set_public_port", &s_http_config_set_public_port_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "public_port", public_port);
public_port = ipr_config_getp (self->config, "/config/server", "public_port", NULL);
assert (public_port);
self->public_port = public_port;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PUBLIC_PORT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_PUBLIC_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_public_port_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" public_port=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, public_port, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_public_port

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_public_port (
    http_config_t * self                //  Reference to self
)
{
    char *
        public_port;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_PUBLIC_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_public_port_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PUBLIC_PORT))
    icl_trace_record (NULL, http_config_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PUBLIC_PORT))
    icl_stats_inc ("http_config_public_port", &s_http_config_public_port_stats);
#endif

//
if (self)
    public_port = self->public_port;
else
    public_port = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PUBLIC_PORT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_PUBLIC_PORT))
    if (http_config_animating)
        icl_console_print ("<http_config_public_port_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" public_port=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, public_port);
#endif


    return (public_port);
}
/*  -------------------------------------------------------------------------
    http_config_set_trace

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_trace (
    http_config_t * self,               //  Reference to object
    Bool trace                          //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_trace_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TRACE))
    icl_trace_record (NULL, http_config_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TRACE))
    icl_stats_inc ("http_config_set_trace", &s_http_config_set_trace_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", trace);
ipr_config_putp (self->config, "/config/server", "trace", strvalue);
self->trace = trace;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TRACE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_trace_finish"
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
    http_config_trace

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_trace (
    http_config_t * self                //  Reference to self
)
{
    Bool
        trace;                          //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_trace_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TRACE))
    icl_trace_record (NULL, http_config_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TRACE))
    icl_stats_inc ("http_config_trace", &s_http_config_trace_stats);
#endif

//
if (self)
    trace = self->trace;
else
    trace = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TRACE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_trace_finish"
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
    http_config_set_animate

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_animate (
    http_config_t * self,               //  Reference to object
    Bool animate                        //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ANIMATE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_animate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" animate=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, animate);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ANIMATE))
    icl_trace_record (NULL, http_config_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ANIMATE))
    icl_stats_inc ("http_config_set_animate", &s_http_config_set_animate_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", animate);
ipr_config_putp (self->config, "/config/server", "animate", strvalue);
self->animate = animate;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ANIMATE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ANIMATE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" animate=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, animate, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_animate

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_animate (
    http_config_t * self                //  Reference to self
)
{
    Bool
        animate;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ANIMATE))
    if (http_config_animating)
        icl_console_print ("<http_config_animate_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ANIMATE))
    icl_trace_record (NULL, http_config_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ANIMATE))
    icl_stats_inc ("http_config_animate", &s_http_config_animate_stats);
#endif

//
if (self)
    animate = self->animate;
else
    animate = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ANIMATE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ANIMATE))
    if (http_config_animating)
        icl_console_print ("<http_config_animate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" animate=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, animate);
#endif


    return (animate);
}
/*  -------------------------------------------------------------------------
    http_config_set_verbose

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_verbose (
    http_config_t * self,               //  Reference to object
    Bool verbose                        //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_VERBOSE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_verbose_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" verbose=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, verbose);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_VERBOSE))
    icl_trace_record (NULL, http_config_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_VERBOSE))
    icl_stats_inc ("http_config_set_verbose", &s_http_config_set_verbose_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", verbose);
ipr_config_putp (self->config, "/config/server", "verbose", strvalue);
self->verbose = verbose;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_VERBOSE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_VERBOSE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_verbose_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" verbose=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, verbose, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_verbose

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_verbose (
    http_config_t * self                //  Reference to self
)
{
    Bool
        verbose;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_VERBOSE))
    if (http_config_animating)
        icl_console_print ("<http_config_verbose_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_VERBOSE))
    icl_trace_record (NULL, http_config_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_VERBOSE))
    icl_stats_inc ("http_config_verbose", &s_http_config_verbose_stats);
#endif

//
if (self)
    verbose = self->verbose;
else
    verbose = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_VERBOSE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_VERBOSE))
    if (http_config_animating)
        icl_console_print ("<http_config_verbose_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" verbose=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, verbose);
#endif


    return (verbose);
}
/*  -------------------------------------------------------------------------
    http_config_set_listen

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_listen (
    http_config_t * self,               //  Reference to object
    char * listen                       //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_LISTEN))
    if (http_config_animating)
        icl_console_print ("<http_config_set_listen_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" listen=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, listen);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LISTEN))
    icl_trace_record (NULL, http_config_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_LISTEN))
    icl_stats_inc ("http_config_set_listen", &s_http_config_set_listen_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/server", "listen", listen);
listen = ipr_config_getp (self->config, "/config/server", "listen", NULL);
assert (listen);
self->listen = listen;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LISTEN))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_LISTEN))
    if (http_config_animating)
        icl_console_print ("<http_config_set_listen_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" listen=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, listen, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_listen

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_listen (
    http_config_t * self                //  Reference to self
)
{
    char *
        listen;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_LISTEN))
    if (http_config_animating)
        icl_console_print ("<http_config_listen_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LISTEN))
    icl_trace_record (NULL, http_config_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LISTEN))
    icl_stats_inc ("http_config_listen", &s_http_config_listen_stats);
#endif

//
if (self)
    listen = self->listen;
else
    listen = "*";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LISTEN))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_LISTEN))
    if (http_config_animating)
        icl_console_print ("<http_config_listen_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" listen=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, listen);
#endif


    return (listen);
}
/*  -------------------------------------------------------------------------
    http_config_set_webroot

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_webroot (
    http_config_t * self,               //  Reference to object
    char * webroot                      //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_WEBROOT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_webroot_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" webroot=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, webroot);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WEBROOT))
    icl_trace_record (NULL, http_config_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_WEBROOT))
    icl_stats_inc ("http_config_set_webroot", &s_http_config_set_webroot_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/host", "webroot", webroot);
webroot = ipr_config_getp (self->config, "/config/host", "webroot", NULL);
assert (webroot);
self->webroot = webroot;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WEBROOT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_WEBROOT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_webroot_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" webroot=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, webroot, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_webroot

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_webroot (
    http_config_t * self                //  Reference to self
)
{
    char *
        webroot;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_WEBROOT))
    if (http_config_animating)
        icl_console_print ("<http_config_webroot_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WEBROOT))
    icl_trace_record (NULL, http_config_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WEBROOT))
    icl_stats_inc ("http_config_webroot", &s_http_config_webroot_stats);
#endif

//
if (self)
    webroot = self->webroot;
else
    webroot = "webpages";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WEBROOT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_WEBROOT))
    if (http_config_animating)
        icl_console_print ("<http_config_webroot_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" webroot=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, webroot);
#endif


    return (webroot);
}
/*  -------------------------------------------------------------------------
    http_config_set_defaults

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_defaults (
    http_config_t * self,               //  Reference to object
    char * defaults                     //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_DEFAULTS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_defaults_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" defaults=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, defaults);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULTS))
    icl_trace_record (NULL, http_config_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DEFAULTS))
    icl_stats_inc ("http_config_set_defaults", &s_http_config_set_defaults_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/host", "defaults", defaults);
defaults = ipr_config_getp (self->config, "/config/host", "defaults", NULL);
assert (defaults);
self->defaults = defaults;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULTS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_DEFAULTS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_defaults_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" defaults=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, defaults, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_defaults

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_defaults (
    http_config_t * self                //  Reference to self
)
{
    char *
        defaults;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DEFAULTS))
    if (http_config_animating)
        icl_console_print ("<http_config_defaults_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULTS))
    icl_trace_record (NULL, http_config_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DEFAULTS))
    icl_stats_inc ("http_config_defaults", &s_http_config_defaults_stats);
#endif

//
if (self)
    defaults = self->defaults;
else
    defaults = "index.html default.html";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULTS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DEFAULTS))
    if (http_config_animating)
        icl_console_print ("<http_config_defaults_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" defaults=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, defaults);
#endif


    return (defaults);
}
/*  -------------------------------------------------------------------------
    http_config_set_default_types

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_default_types (
    http_config_t * self,               //  Reference to object
    char * default_types                //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_DEFAULT_TYPES))
    if (http_config_animating)
        icl_console_print ("<http_config_set_default_types_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" default_types=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, default_types);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULT_TYPES))
    icl_trace_record (NULL, http_config_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DEFAULT_TYPES))
    icl_stats_inc ("http_config_set_default_types", &s_http_config_set_default_types_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/host", "default_types", default_types);
default_types = ipr_config_getp (self->config, "/config/host", "default_types", NULL);
assert (default_types);
self->default_types = default_types;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULT_TYPES))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_DEFAULT_TYPES))
    if (http_config_animating)
        icl_console_print ("<http_config_set_default_types_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" default_types=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, default_types, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_default_types

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_default_types (
    http_config_t * self                //  Reference to self
)
{
    char *
        default_types;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DEFAULT_TYPES))
    if (http_config_animating)
        icl_console_print ("<http_config_default_types_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULT_TYPES))
    icl_trace_record (NULL, http_config_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DEFAULT_TYPES))
    icl_stats_inc ("http_config_default_types", &s_http_config_default_types_stats);
#endif

//
if (self)
    default_types = self->default_types;
else
    default_types = ".pdf .html";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULT_TYPES))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DEFAULT_TYPES))
    if (http_config_animating)
        icl_console_print ("<http_config_default_types_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" default_types=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, default_types);
#endif


    return (default_types);
}
/*  -------------------------------------------------------------------------
    http_config_set_monitor

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_monitor (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_MONITOR))
    if (http_config_animating)
        icl_console_print ("<http_config_set_monitor_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MONITOR))
    icl_trace_record (NULL, http_config_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_MONITOR))
    icl_stats_inc ("http_config_set_monitor", &s_http_config_set_monitor_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", monitor);
ipr_config_putp (self->config, "/config/resources", "monitor", strvalue);
self->monitor = monitor;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MONITOR))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_MONITOR))
    if (http_config_animating)
        icl_console_print ("<http_config_set_monitor_finish"
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
    http_config_monitor

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_monitor (
    http_config_t * self                //  Reference to self
)
{
    int
        monitor;                        //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_MONITOR))
    if (http_config_animating)
        icl_console_print ("<http_config_monitor_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_MONITOR))
    icl_trace_record (NULL, http_config_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_MONITOR))
    icl_stats_inc ("http_config_monitor", &s_http_config_monitor_stats);
#endif

//
if (self)
    monitor = self->monitor;
else
    monitor = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_MONITOR))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_MONITOR))
    if (http_config_animating)
        icl_console_print ("<http_config_monitor_finish"
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
    http_config_set_record_stats

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_record_stats (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_RECORD_STATS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_record_stats_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_RECORD_STATS))
    icl_trace_record (NULL, http_config_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_RECORD_STATS))
    icl_stats_inc ("http_config_set_record_stats", &s_http_config_set_record_stats_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", record_stats);
ipr_config_putp (self->config, "/config/resources", "record_stats", strvalue);
self->record_stats = record_stats;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_RECORD_STATS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_RECORD_STATS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_record_stats_finish"
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
    http_config_record_stats

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_record_stats (
    http_config_t * self                //  Reference to self
)
{
    Bool
        record_stats;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_RECORD_STATS))
    if (http_config_animating)
        icl_console_print ("<http_config_record_stats_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_RECORD_STATS))
    icl_trace_record (NULL, http_config_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_RECORD_STATS))
    icl_stats_inc ("http_config_record_stats", &s_http_config_record_stats_stats);
#endif

//
if (self)
    record_stats = self->record_stats;
else
    record_stats = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_RECORD_STATS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_RECORD_STATS))
    if (http_config_animating)
        icl_console_print ("<http_config_record_stats_finish"
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
    http_config_set_log_path

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_log_path (
    http_config_t * self,               //  Reference to object
    char * log_path                     //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_LOG_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_log_path_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LOG_PATH))
    icl_trace_record (NULL, http_config_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_LOG_PATH))
    icl_stats_inc ("http_config_set_log_path", &s_http_config_set_log_path_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "log_path", log_path);
log_path = ipr_config_getp (self->config, "/config/logging", "log_path", NULL);
assert (log_path);
self->log_path = log_path;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LOG_PATH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_LOG_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_log_path_finish"
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
    http_config_log_path

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_log_path (
    http_config_t * self                //  Reference to self
)
{
    char *
        log_path;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_LOG_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_log_path_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LOG_PATH))
    icl_trace_record (NULL, http_config_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_LOG_PATH))
    icl_stats_inc ("http_config_log_path", &s_http_config_log_path_stats);
#endif

//
if (self)
    log_path = self->log_path;
else
    log_path = "logs";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_LOG_PATH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_LOG_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_log_path_finish"
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
    http_config_set_keep_logs

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_keep_logs (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_KEEP_LOGS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_keep_logs_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_KEEP_LOGS))
    icl_trace_record (NULL, http_config_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_KEEP_LOGS))
    icl_stats_inc ("http_config_set_keep_logs", &s_http_config_set_keep_logs_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", keep_logs);
ipr_config_putp (self->config, "/config/logging", "keep_logs", strvalue);
self->keep_logs = keep_logs;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_KEEP_LOGS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_KEEP_LOGS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_keep_logs_finish"
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
    http_config_keep_logs

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_keep_logs (
    http_config_t * self                //  Reference to self
)
{
    Bool
        keep_logs;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_KEEP_LOGS))
    if (http_config_animating)
        icl_console_print ("<http_config_keep_logs_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_KEEP_LOGS))
    icl_trace_record (NULL, http_config_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_KEEP_LOGS))
    icl_stats_inc ("http_config_keep_logs", &s_http_config_keep_logs_stats);
#endif

//
if (self)
    keep_logs = self->keep_logs;
else
    keep_logs = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_KEEP_LOGS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_KEEP_LOGS))
    if (http_config_animating)
        icl_console_print ("<http_config_keep_logs_finish"
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
    http_config_set_archive_path

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_archive_path (
    http_config_t * self,               //  Reference to object
    char * archive_path                 //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ARCHIVE_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_archive_path_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_PATH))
    icl_trace_record (NULL, http_config_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ARCHIVE_PATH))
    icl_stats_inc ("http_config_set_archive_path", &s_http_config_set_archive_path_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "archive_path", archive_path);
archive_path = ipr_config_getp (self->config, "/config/logging", "archive_path", NULL);
assert (archive_path);
self->archive_path = archive_path;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_PATH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ARCHIVE_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_archive_path_finish"
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
    http_config_archive_path

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_archive_path (
    http_config_t * self                //  Reference to self
)
{
    char *
        archive_path;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ARCHIVE_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_archive_path_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_PATH))
    icl_trace_record (NULL, http_config_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ARCHIVE_PATH))
    icl_stats_inc ("http_config_archive_path", &s_http_config_archive_path_stats);
#endif

//
if (self)
    archive_path = self->archive_path;
else
    archive_path = "archive";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_PATH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ARCHIVE_PATH))
    if (http_config_animating)
        icl_console_print ("<http_config_archive_path_finish"
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
    http_config_set_archive_cmd

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_archive_cmd (
    http_config_t * self,               //  Reference to object
    char * archive_cmd                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ARCHIVE_CMD))
    if (http_config_animating)
        icl_console_print ("<http_config_set_archive_cmd_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_CMD))
    icl_trace_record (NULL, http_config_dump, 41);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ARCHIVE_CMD))
    icl_stats_inc ("http_config_set_archive_cmd", &s_http_config_set_archive_cmd_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "archive_cmd", archive_cmd);
archive_cmd = ipr_config_getp (self->config, "/config/logging", "archive_cmd", NULL);
assert (archive_cmd);
self->archive_cmd = archive_cmd;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_CMD))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 41);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ARCHIVE_CMD))
    if (http_config_animating)
        icl_console_print ("<http_config_set_archive_cmd_finish"
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
    http_config_archive_cmd

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_archive_cmd (
    http_config_t * self                //  Reference to self
)
{
    char *
        archive_cmd;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ARCHIVE_CMD))
    if (http_config_animating)
        icl_console_print ("<http_config_archive_cmd_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_CMD))
    icl_trace_record (NULL, http_config_dump, 42);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ARCHIVE_CMD))
    icl_stats_inc ("http_config_archive_cmd", &s_http_config_archive_cmd_stats);
#endif

//
if (self)
    archive_cmd = self->archive_cmd;
else
    archive_cmd = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_CMD))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 42);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ARCHIVE_CMD))
    if (http_config_animating)
        icl_console_print ("<http_config_archive_cmd_finish"
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
    http_config_set_alert_log

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_alert_log (
    http_config_t * self,               //  Reference to object
    char * alert_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ALERT_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_alert_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ALERT_LOG))
    icl_trace_record (NULL, http_config_dump, 43);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ALERT_LOG))
    icl_stats_inc ("http_config_set_alert_log", &s_http_config_set_alert_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "alert_log", alert_log);
alert_log = ipr_config_getp (self->config, "/config/logging", "alert_log", NULL);
assert (alert_log);
self->alert_log = alert_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ALERT_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 43);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ALERT_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_alert_log_finish"
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
    http_config_alert_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_alert_log (
    http_config_t * self                //  Reference to self
)
{
    char *
        alert_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ALERT_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_alert_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ALERT_LOG))
    icl_trace_record (NULL, http_config_dump, 44);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ALERT_LOG))
    icl_stats_inc ("http_config_alert_log", &s_http_config_alert_log_stats);
#endif

//
if (self)
    alert_log = self->alert_log;
else
    alert_log = "alert.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ALERT_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 44);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ALERT_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_alert_log_finish"
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
    http_config_set_access_log

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_access_log (
    http_config_t * self,               //  Reference to object
    char * access_log                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ACCESS_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_access_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" access_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, access_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG))
    icl_trace_record (NULL, http_config_dump, 45);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ACCESS_LOG))
    icl_stats_inc ("http_config_set_access_log", &s_http_config_set_access_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "access_log", access_log);
access_log = ipr_config_getp (self->config, "/config/logging", "access_log", NULL);
assert (access_log);
self->access_log = access_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 45);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ACCESS_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_access_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" access_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, access_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_access_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_access_log (
    http_config_t * self                //  Reference to self
)
{
    char *
        access_log;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ACCESS_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_access_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG))
    icl_trace_record (NULL, http_config_dump, 46);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ACCESS_LOG))
    icl_stats_inc ("http_config_access_log", &s_http_config_access_log_stats);
#endif

//
if (self)
    access_log = self->access_log;
else
    access_log = "access.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 46);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ACCESS_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_access_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" access_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, access_log);
#endif


    return (access_log);
}
/*  -------------------------------------------------------------------------
    http_config_set_access_log_format

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_access_log_format (
    http_config_t * self,               //  Reference to object
    char * access_log_format            //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_access_log_format_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" access_log_format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, access_log_format);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT))
    icl_trace_record (NULL, http_config_dump, 47);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT))
    icl_stats_inc ("http_config_set_access_log_format", &s_http_config_set_access_log_format_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "access_log_format", access_log_format);
access_log_format = ipr_config_getp (self->config, "/config/logging", "access_log_format", NULL);
assert (access_log_format);
self->access_log_format = access_log_format;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 47);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_access_log_format_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" access_log_format=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, access_log_format, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_access_log_format

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_access_log_format (
    http_config_t * self                //  Reference to self
)
{
    char *
        access_log_format;              //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ACCESS_LOG_FORMAT))
    if (http_config_animating)
        icl_console_print ("<http_config_access_log_format_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG_FORMAT))
    icl_trace_record (NULL, http_config_dump, 48);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ACCESS_LOG_FORMAT))
    icl_stats_inc ("http_config_access_log_format", &s_http_config_access_log_format_stats);
#endif

//
if (self)
    access_log_format = self->access_log_format;
else
    access_log_format = "CLFX";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG_FORMAT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 48);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ACCESS_LOG_FORMAT))
    if (http_config_animating)
        icl_console_print ("<http_config_access_log_format_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" access_log_format=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, access_log_format);
#endif


    return (access_log_format);
}
/*  -------------------------------------------------------------------------
    http_config_set_debug_log

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_debug_log (
    http_config_t * self,               //  Reference to object
    char * debug_log                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_DEBUG_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_debug_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEBUG_LOG))
    icl_trace_record (NULL, http_config_dump, 49);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DEBUG_LOG))
    icl_stats_inc ("http_config_set_debug_log", &s_http_config_set_debug_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/logging", "debug_log", debug_log);
debug_log = ipr_config_getp (self->config, "/config/logging", "debug_log", NULL);
assert (debug_log);
self->debug_log = debug_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEBUG_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 49);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_DEBUG_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_debug_log_finish"
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
    http_config_debug_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_debug_log (
    http_config_t * self                //  Reference to self
)
{
    char *
        debug_log;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DEBUG_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_debug_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DEBUG_LOG))
    icl_trace_record (NULL, http_config_dump, 50);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DEBUG_LOG))
    icl_stats_inc ("http_config_debug_log", &s_http_config_debug_log_stats);
#endif

//
if (self)
    debug_log = self->debug_log;
else
    debug_log = "debug.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DEBUG_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 50);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DEBUG_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_debug_log_finish"
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
    http_config_set_blacklist

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_blacklist (
    http_config_t * self,               //  Reference to object
    char * blacklist                    //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_BLACKLIST))
    if (http_config_animating)
        icl_console_print ("<http_config_set_blacklist_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" blacklist=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, blacklist);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BLACKLIST))
    icl_trace_record (NULL, http_config_dump, 51);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_BLACKLIST))
    icl_stats_inc ("http_config_set_blacklist", &s_http_config_set_blacklist_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/security", "blacklist", blacklist);
blacklist = ipr_config_getp (self->config, "/config/security", "blacklist", NULL);
assert (blacklist);
self->blacklist = blacklist;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BLACKLIST))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 51);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_BLACKLIST))
    if (http_config_animating)
        icl_console_print ("<http_config_set_blacklist_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" blacklist=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, blacklist, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_blacklist

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_blacklist (
    http_config_t * self                //  Reference to self
)
{
    char *
        blacklist;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_BLACKLIST))
    if (http_config_animating)
        icl_console_print ("<http_config_blacklist_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_BLACKLIST))
    icl_trace_record (NULL, http_config_dump, 52);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_BLACKLIST))
    icl_stats_inc ("http_config_blacklist", &s_http_config_blacklist_stats);
#endif

//
if (self)
    blacklist = self->blacklist;
else
    blacklist = "blacklist.txt";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_BLACKLIST))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 52);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_BLACKLIST))
    if (http_config_animating)
        icl_console_print ("<http_config_blacklist_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" blacklist=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, blacklist);
#endif


    return (blacklist);
}
/*  -------------------------------------------------------------------------
    http_config_set_basic_auth

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_basic_auth (
    http_config_t * self,               //  Reference to object
    char * basic_auth                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_BASIC_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_basic_auth_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" basic_auth=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, basic_auth);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BASIC_AUTH))
    icl_trace_record (NULL, http_config_dump, 53);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_BASIC_AUTH))
    icl_stats_inc ("http_config_set_basic_auth", &s_http_config_set_basic_auth_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/security", "basic_auth", basic_auth);
basic_auth = ipr_config_getp (self->config, "/config/security", "basic_auth", NULL);
assert (basic_auth);
self->basic_auth = basic_auth;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BASIC_AUTH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 53);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_BASIC_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_basic_auth_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" basic_auth=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, basic_auth, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_basic_auth

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_basic_auth (
    http_config_t * self                //  Reference to self
)
{
    char *
        basic_auth;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_BASIC_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_basic_auth_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_BASIC_AUTH))
    icl_trace_record (NULL, http_config_dump, 54);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_BASIC_AUTH))
    icl_stats_inc ("http_config_basic_auth", &s_http_config_basic_auth_stats);
#endif

//
if (self)
    basic_auth = self->basic_auth;
else
    basic_auth = "passwd";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_BASIC_AUTH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 54);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_BASIC_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_basic_auth_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" basic_auth=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, basic_auth);
#endif


    return (basic_auth);
}
/*  -------------------------------------------------------------------------
    http_config_set_digest_auth

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_digest_auth (
    http_config_t * self,               //  Reference to object
    char * digest_auth                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_DIGEST_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_digest_auth_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" digest_auth=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, digest_auth);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DIGEST_AUTH))
    icl_trace_record (NULL, http_config_dump, 55);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_DIGEST_AUTH))
    icl_stats_inc ("http_config_set_digest_auth", &s_http_config_set_digest_auth_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/security", "digest_auth", digest_auth);
digest_auth = ipr_config_getp (self->config, "/config/security", "digest_auth", NULL);
assert (digest_auth);
self->digest_auth = digest_auth;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DIGEST_AUTH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 55);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_DIGEST_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_set_digest_auth_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" digest_auth=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, digest_auth, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_digest_auth

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_digest_auth (
    http_config_t * self                //  Reference to self
)
{
    char *
        digest_auth;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DIGEST_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_digest_auth_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DIGEST_AUTH))
    icl_trace_record (NULL, http_config_dump, 56);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DIGEST_AUTH))
    icl_stats_inc ("http_config_digest_auth", &s_http_config_digest_auth_stats);
#endif

//
if (self)
    digest_auth = self->digest_auth;
else
    digest_auth = "digest";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DIGEST_AUTH))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 56);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DIGEST_AUTH))
    if (http_config_animating)
        icl_console_print ("<http_config_digest_auth_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" digest_auth=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, digest_auth);
#endif


    return (digest_auth);
}
/*  -------------------------------------------------------------------------
    http_config_set_password_ttl

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_password_ttl (
    http_config_t * self,               //  Reference to object
    int password_ttl                    //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_PASSWORD_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_set_password_ttl_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" password_ttl=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, password_ttl);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_TTL))
    icl_trace_record (NULL, http_config_dump, 57);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PASSWORD_TTL))
    icl_stats_inc ("http_config_set_password_ttl", &s_http_config_set_password_ttl_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", password_ttl);
ipr_config_putp (self->config, "/config/security", "password_ttl", strvalue);
self->password_ttl = password_ttl;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_TTL))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 57);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_PASSWORD_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_set_password_ttl_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" password_ttl=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, password_ttl, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_password_ttl

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_password_ttl (
    http_config_t * self                //  Reference to self
)
{
    int
        password_ttl;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_PASSWORD_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_password_ttl_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_TTL))
    icl_trace_record (NULL, http_config_dump, 58);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PASSWORD_TTL))
    icl_stats_inc ("http_config_password_ttl", &s_http_config_password_ttl_stats);
#endif

//
if (self)
    password_ttl = self->password_ttl;
else
    password_ttl = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_TTL))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 58);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_PASSWORD_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_password_ttl_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" password_ttl=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, password_ttl);
#endif


    return (password_ttl);
}
/*  -------------------------------------------------------------------------
    http_config_set_hit_quota

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_hit_quota (
    http_config_t * self,               //  Reference to object
    int hit_quota                       //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_HIT_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_hit_quota_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hit_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hit_quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HIT_QUOTA))
    icl_trace_record (NULL, http_config_dump, 59);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_HIT_QUOTA))
    icl_stats_inc ("http_config_set_hit_quota", &s_http_config_set_hit_quota_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", hit_quota);
ipr_config_putp (self->config, "/config/security", "hit_quota", strvalue);
self->hit_quota = hit_quota;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HIT_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 59);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_HIT_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_hit_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hit_quota=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hit_quota, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_hit_quota

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_hit_quota (
    http_config_t * self                //  Reference to self
)
{
    int
        hit_quota;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_HIT_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_hit_quota_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_HIT_QUOTA))
    icl_trace_record (NULL, http_config_dump, 60);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_HIT_QUOTA))
    icl_stats_inc ("http_config_hit_quota", &s_http_config_hit_quota_stats);
#endif

//
if (self)
    hit_quota = self->hit_quota;
else
    hit_quota = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_HIT_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 60);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_HIT_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_hit_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" hit_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, hit_quota);
#endif


    return (hit_quota);
}
/*  -------------------------------------------------------------------------
    http_config_set_miss_quota

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_miss_quota (
    http_config_t * self,               //  Reference to object
    int miss_quota                      //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_MISS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_miss_quota_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" miss_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, miss_quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MISS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 61);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_MISS_QUOTA))
    icl_stats_inc ("http_config_set_miss_quota", &s_http_config_set_miss_quota_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", miss_quota);
ipr_config_putp (self->config, "/config/security", "miss_quota", strvalue);
self->miss_quota = miss_quota;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MISS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 61);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_MISS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_miss_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" miss_quota=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, miss_quota, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_miss_quota

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_miss_quota (
    http_config_t * self                //  Reference to self
)
{
    int
        miss_quota;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_MISS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_miss_quota_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_MISS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 62);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_MISS_QUOTA))
    icl_stats_inc ("http_config_miss_quota", &s_http_config_miss_quota_stats);
#endif

//
if (self)
    miss_quota = self->miss_quota;
else
    miss_quota = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_MISS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 62);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_MISS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_miss_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" miss_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, miss_quota);
#endif


    return (miss_quota);
}
/*  -------------------------------------------------------------------------
    http_config_set_password_guard

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_password_guard (
    http_config_t * self,               //  Reference to object
    int password_guard                  //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_PASSWORD_GUARD))
    if (http_config_animating)
        icl_console_print ("<http_config_set_password_guard_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" password_guard=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, password_guard);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_GUARD))
    icl_trace_record (NULL, http_config_dump, 63);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_PASSWORD_GUARD))
    icl_stats_inc ("http_config_set_password_guard", &s_http_config_set_password_guard_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", password_guard);
ipr_config_putp (self->config, "/config/security", "password_guard", strvalue);
self->password_guard = password_guard;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_GUARD))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 63);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_PASSWORD_GUARD))
    if (http_config_animating)
        icl_console_print ("<http_config_set_password_guard_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" password_guard=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, password_guard, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_password_guard

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_password_guard (
    http_config_t * self                //  Reference to self
)
{
    int
        password_guard;                 //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_PASSWORD_GUARD))
    if (http_config_animating)
        icl_console_print ("<http_config_password_guard_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_GUARD))
    icl_trace_record (NULL, http_config_dump, 64);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_PASSWORD_GUARD))
    icl_stats_inc ("http_config_password_guard", &s_http_config_password_guard_stats);
#endif

//
if (self)
    password_guard = self->password_guard;
else
    password_guard = 10;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_GUARD))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 64);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_PASSWORD_GUARD))
    if (http_config_animating)
        icl_console_print ("<http_config_password_guard_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" password_guard=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, password_guard);
#endif


    return (password_guard);
}
/*  -------------------------------------------------------------------------
    http_config_set_policy_trace

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_policy_trace (
    http_config_t * self,               //  Reference to object
    Bool policy_trace                   //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_POLICY_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_policy_trace_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" policy_trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, policy_trace);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLICY_TRACE))
    icl_trace_record (NULL, http_config_dump, 65);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_POLICY_TRACE))
    icl_stats_inc ("http_config_set_policy_trace", &s_http_config_set_policy_trace_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", policy_trace);
ipr_config_putp (self->config, "/config/security", "policy_trace", strvalue);
self->policy_trace = policy_trace;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLICY_TRACE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 65);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_POLICY_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_set_policy_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" policy_trace=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, policy_trace, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_policy_trace

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_policy_trace (
    http_config_t * self                //  Reference to self
)
{
    Bool
        policy_trace;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_POLICY_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_policy_trace_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_POLICY_TRACE))
    icl_trace_record (NULL, http_config_dump, 66);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_POLICY_TRACE))
    icl_stats_inc ("http_config_policy_trace", &s_http_config_policy_trace_stats);
#endif

//
if (self)
    policy_trace = self->policy_trace;
else
    policy_trace = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_POLICY_TRACE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 66);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_POLICY_TRACE))
    if (http_config_animating)
        icl_console_print ("<http_config_policy_trace_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" policy_trace=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, policy_trace);
#endif


    return (policy_trace);
}
/*  -------------------------------------------------------------------------
    http_config_set_nervosity

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_nervosity (
    http_config_t * self,               //  Reference to object
    int nervosity                       //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_NERVOSITY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_nervosity_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nervosity=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nervosity);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NERVOSITY))
    icl_trace_record (NULL, http_config_dump, 67);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_NERVOSITY))
    icl_stats_inc ("http_config_set_nervosity", &s_http_config_set_nervosity_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
if (nervosity < 1) {
    icl_console_print ("W: <command line>: illegal value %d for nervosity, using %d",
        nervosity, 1);
    nervosity = 1;
}
icl_shortstr_fmt (strvalue, "%i", nervosity);
ipr_config_putp (self->config, "/config/security", "nervosity", strvalue);
self->nervosity = nervosity;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NERVOSITY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 67);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_NERVOSITY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_nervosity_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nervosity=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nervosity, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_nervosity

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_nervosity (
    http_config_t * self                //  Reference to self
)
{
    int
        nervosity;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_NERVOSITY))
    if (http_config_animating)
        icl_console_print ("<http_config_nervosity_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NERVOSITY))
    icl_trace_record (NULL, http_config_dump, 68);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NERVOSITY))
    icl_stats_inc ("http_config_nervosity", &s_http_config_nervosity_stats);
#endif

//
if (self)
    nervosity = self->nervosity;
else
    nervosity = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NERVOSITY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 68);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_NERVOSITY))
    if (http_config_animating)
        icl_console_print ("<http_config_nervosity_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nervosity=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nervosity);
#endif


    return (nervosity);
}
/*  -------------------------------------------------------------------------
    http_config_set_nonce_ttl

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_nonce_ttl (
    http_config_t * self,               //  Reference to object
    int nonce_ttl                       //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_NONCE_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_set_nonce_ttl_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nonce_ttl=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nonce_ttl);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_TTL))
    icl_trace_record (NULL, http_config_dump, 69);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_NONCE_TTL))
    icl_stats_inc ("http_config_set_nonce_ttl", &s_http_config_set_nonce_ttl_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
if (nonce_ttl < 1) {
    icl_console_print ("W: <command line>: illegal value %d for nonce_ttl, using %d",
        nonce_ttl, 1);
    nonce_ttl = 1;
}
icl_shortstr_fmt (strvalue, "%i", nonce_ttl);
ipr_config_putp (self->config, "/config/security", "nonce_ttl", strvalue);
self->nonce_ttl = nonce_ttl;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_TTL))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 69);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_NONCE_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_set_nonce_ttl_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nonce_ttl=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nonce_ttl, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_nonce_ttl

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_nonce_ttl (
    http_config_t * self                //  Reference to self
)
{
    int
        nonce_ttl;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_NONCE_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_nonce_ttl_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_TTL))
    icl_trace_record (NULL, http_config_dump, 70);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NONCE_TTL))
    icl_stats_inc ("http_config_nonce_ttl", &s_http_config_nonce_ttl_stats);
#endif

//
if (self)
    nonce_ttl = self->nonce_ttl;
else
    nonce_ttl = 60;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_TTL))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 70);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_NONCE_TTL))
    if (http_config_animating)
        icl_console_print ("<http_config_nonce_ttl_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nonce_ttl=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nonce_ttl);
#endif


    return (nonce_ttl);
}
/*  -------------------------------------------------------------------------
    http_config_set_nonce_quota

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_nonce_quota (
    http_config_t * self,               //  Reference to object
    int nonce_quota                     //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_NONCE_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_nonce_quota_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nonce_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nonce_quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_QUOTA))
    icl_trace_record (NULL, http_config_dump, 71);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_NONCE_QUOTA))
    icl_stats_inc ("http_config_set_nonce_quota", &s_http_config_set_nonce_quota_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
if (nonce_quota < 1) {
    icl_console_print ("W: <command line>: illegal value %d for nonce_quota, using %d",
        nonce_quota, 1);
    nonce_quota = 1;
}
icl_shortstr_fmt (strvalue, "%i", nonce_quota);
ipr_config_putp (self->config, "/config/security", "nonce_quota", strvalue);
self->nonce_quota = nonce_quota;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 71);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_NONCE_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_nonce_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nonce_quota=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nonce_quota, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_nonce_quota

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_nonce_quota (
    http_config_t * self                //  Reference to self
)
{
    int
        nonce_quota;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_NONCE_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_nonce_quota_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_QUOTA))
    icl_trace_record (NULL, http_config_dump, 72);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NONCE_QUOTA))
    icl_stats_inc ("http_config_nonce_quota", &s_http_config_nonce_quota_stats);
#endif

//
if (self)
    nonce_quota = self->nonce_quota;
else
    nonce_quota = 25;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 72);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_NONCE_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_nonce_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" nonce_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, nonce_quota);
#endif


    return (nonce_quota);
}
/*  -------------------------------------------------------------------------
    http_config_set_refresh_by

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_refresh_by (
    http_config_t * self,               //  Reference to object
    char * refresh_by                   //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_REFRESH_BY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_refresh_by_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" refresh_by=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, refresh_by);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_BY))
    icl_trace_record (NULL, http_config_dump, 73);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_REFRESH_BY))
    icl_stats_inc ("http_config_set_refresh_by", &s_http_config_set_refresh_by_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/security", "refresh_by", refresh_by);
refresh_by = ipr_config_getp (self->config, "/config/security", "refresh_by", NULL);
assert (refresh_by);
self->refresh_by = refresh_by;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_BY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 73);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_REFRESH_BY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_refresh_by_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" refresh_by=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, refresh_by, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_refresh_by

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_refresh_by (
    http_config_t * self                //  Reference to self
)
{
    char *
        refresh_by;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_REFRESH_BY))
    if (http_config_animating)
        icl_console_print ("<http_config_refresh_by_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_BY))
    icl_trace_record (NULL, http_config_dump, 74);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_REFRESH_BY))
    icl_stats_inc ("http_config_refresh_by", &s_http_config_refresh_by_stats);
#endif

//
if (self)
    refresh_by = self->refresh_by;
else
    refresh_by = "";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_BY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 74);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_REFRESH_BY))
    if (http_config_animating)
        icl_console_print ("<http_config_refresh_by_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" refresh_by=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, refresh_by);
#endif


    return (refresh_by);
}
/*  -------------------------------------------------------------------------
    http_config_set_refresh_log

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_refresh_log (
    http_config_t * self,               //  Reference to object
    char * refresh_log                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_REFRESH_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_refresh_log_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" refresh_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, refresh_log);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_LOG))
    icl_trace_record (NULL, http_config_dump, 75);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_REFRESH_LOG))
    icl_stats_inc ("http_config_set_refresh_log", &s_http_config_set_refresh_log_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/security", "refresh_log", refresh_log);
refresh_log = ipr_config_getp (self->config, "/config/security", "refresh_log", NULL);
assert (refresh_log);
self->refresh_log = refresh_log;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 75);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_REFRESH_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_refresh_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" refresh_log=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, refresh_log, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_refresh_log

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_refresh_log (
    http_config_t * self                //  Reference to self
)
{
    char *
        refresh_log;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_REFRESH_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_refresh_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_LOG))
    icl_trace_record (NULL, http_config_dump, 76);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_REFRESH_LOG))
    icl_stats_inc ("http_config_refresh_log", &s_http_config_refresh_log_stats);
#endif

//
if (self)
    refresh_log = self->refresh_log;
else
    refresh_log = "password_refresh.log";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 76);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_REFRESH_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_refresh_log_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" refresh_log=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, refresh_log);
#endif


    return (refresh_log);
}
/*  -------------------------------------------------------------------------
    http_config_set_address_quota

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_address_quota (
    http_config_t * self,               //  Reference to object
    int address_quota                   //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ADDRESS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_address_quota_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address_quota);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ADDRESS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 77);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ADDRESS_QUOTA))
    icl_stats_inc ("http_config_set_address_quota", &s_http_config_set_address_quota_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", address_quota);
ipr_config_putp (self->config, "/config/security", "address_quota", strvalue);
self->address_quota = address_quota;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ADDRESS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 77);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ADDRESS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_set_address_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address_quota=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address_quota, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_address_quota

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_address_quota (
    http_config_t * self                //  Reference to self
)
{
    int
        address_quota;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ADDRESS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_address_quota_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ADDRESS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 78);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ADDRESS_QUOTA))
    icl_stats_inc ("http_config_address_quota", &s_http_config_address_quota_stats);
#endif

//
if (self)
    address_quota = self->address_quota;
else
    address_quota = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ADDRESS_QUOTA))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 78);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ADDRESS_QUOTA))
    if (http_config_animating)
        icl_console_print ("<http_config_address_quota_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" address_quota=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, address_quota);
#endif


    return (address_quota);
}
/*  -------------------------------------------------------------------------
    http_config_set_abort_delay

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_abort_delay (
    http_config_t * self,               //  Reference to object
    int abort_delay                     //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ABORT_DELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_abort_delay_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" abort_delay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, abort_delay);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ABORT_DELAY))
    icl_trace_record (NULL, http_config_dump, 79);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ABORT_DELAY))
    icl_stats_inc ("http_config_set_abort_delay", &s_http_config_set_abort_delay_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", abort_delay);
ipr_config_putp (self->config, "/config/security", "abort_delay", strvalue);
self->abort_delay = abort_delay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ABORT_DELAY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 79);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ABORT_DELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_abort_delay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" abort_delay=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, abort_delay, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_abort_delay

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_abort_delay (
    http_config_t * self                //  Reference to self
)
{
    int
        abort_delay;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ABORT_DELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_abort_delay_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ABORT_DELAY))
    icl_trace_record (NULL, http_config_dump, 80);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ABORT_DELAY))
    icl_stats_inc ("http_config_abort_delay", &s_http_config_abort_delay_stats);
#endif

//
if (self)
    abort_delay = self->abort_delay;
else
    abort_delay = 5;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ABORT_DELAY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 80);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ABORT_DELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_abort_delay_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" abort_delay=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, abort_delay);
#endif


    return (abort_delay);
}
/*  -------------------------------------------------------------------------
    http_config_set_coremark_cycles

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_coremark_cycles (
    http_config_t * self,               //  Reference to object
    int coremark_cycles                 //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_COREMARK_CYCLES))
    if (http_config_animating)
        icl_console_print ("<http_config_set_coremark_cycles_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" coremark_cycles=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, coremark_cycles);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_COREMARK_CYCLES))
    icl_trace_record (NULL, http_config_dump, 81);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_COREMARK_CYCLES))
    icl_stats_inc ("http_config_set_coremark_cycles", &s_http_config_set_coremark_cycles_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", coremark_cycles);
ipr_config_putp (self->config, "/config/tuning", "coremark_cycles", strvalue);
self->coremark_cycles = coremark_cycles;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_COREMARK_CYCLES))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 81);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_COREMARK_CYCLES))
    if (http_config_animating)
        icl_console_print ("<http_config_set_coremark_cycles_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" coremark_cycles=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, coremark_cycles, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_coremark_cycles

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_coremark_cycles (
    http_config_t * self                //  Reference to self
)
{
    int
        coremark_cycles;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_COREMARK_CYCLES))
    if (http_config_animating)
        icl_console_print ("<http_config_coremark_cycles_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_COREMARK_CYCLES))
    icl_trace_record (NULL, http_config_dump, 82);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_COREMARK_CYCLES))
    icl_stats_inc ("http_config_coremark_cycles", &s_http_config_coremark_cycles_stats);
#endif

//
if (self)
    coremark_cycles = self->coremark_cycles;
else
    coremark_cycles = 250000;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_COREMARK_CYCLES))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 82);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_COREMARK_CYCLES))
    if (http_config_animating)
        icl_console_print ("<http_config_coremark_cycles_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" coremark_cycles=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, coremark_cycles);
#endif


    return (coremark_cycles);
}
/*  -------------------------------------------------------------------------
    http_config_set_header_max

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_header_max (
    http_config_t * self,               //  Reference to object
    int header_max                      //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_HEADER_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_set_header_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" header_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, header_max);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HEADER_MAX))
    icl_trace_record (NULL, http_config_dump, 83);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_HEADER_MAX))
    icl_stats_inc ("http_config_set_header_max", &s_http_config_set_header_max_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
if (header_max < 2048) {
    icl_console_print ("W: <command line>: illegal value %d for header_max, using %d",
        header_max, 2048);
    header_max = 2048;
}
if (header_max > 2097152) {
    icl_console_print ("W: <command line>: illegal value %d for header_max, using %d",
        header_max, 2097152);
    header_max = 2097152;
}
icl_shortstr_fmt (strvalue, "%i", header_max);
ipr_config_putp (self->config, "/config/tuning", "header_max", strvalue);
self->header_max = header_max;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HEADER_MAX))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 83);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_HEADER_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_set_header_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" header_max=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, header_max, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_header_max

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_header_max (
    http_config_t * self                //  Reference to self
)
{
    int
        header_max;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_HEADER_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_header_max_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_HEADER_MAX))
    icl_trace_record (NULL, http_config_dump, 84);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_HEADER_MAX))
    icl_stats_inc ("http_config_header_max", &s_http_config_header_max_stats);
#endif

//
if (self)
    header_max = self->header_max;
else
    header_max = 32000;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_HEADER_MAX))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 84);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_HEADER_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_header_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" header_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, header_max);
#endif


    return (header_max);
}
/*  -------------------------------------------------------------------------
    http_config_set_bucket_max

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_bucket_max (
    http_config_t * self,               //  Reference to object
    int bucket_max                      //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_BUCKET_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_set_bucket_max_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket_max);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BUCKET_MAX))
    icl_trace_record (NULL, http_config_dump, 85);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_BUCKET_MAX))
    icl_stats_inc ("http_config_set_bucket_max", &s_http_config_set_bucket_max_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
if (bucket_max > 2097152) {
    icl_console_print ("W: <command line>: illegal value %d for bucket_max, using %d",
        bucket_max, 2097152);
    bucket_max = 2097152;
}
icl_shortstr_fmt (strvalue, "%i", bucket_max);
ipr_config_putp (self->config, "/config/tuning", "bucket_max", strvalue);
self->bucket_max = bucket_max;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BUCKET_MAX))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 85);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_BUCKET_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_set_bucket_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket_max=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket_max, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_bucket_max

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_bucket_max (
    http_config_t * self                //  Reference to self
)
{
    int
        bucket_max;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_BUCKET_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_bucket_max_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_BUCKET_MAX))
    icl_trace_record (NULL, http_config_dump, 86);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_BUCKET_MAX))
    icl_stats_inc ("http_config_bucket_max", &s_http_config_bucket_max_stats);
#endif

//
if (self)
    bucket_max = self->bucket_max;
else
    bucket_max = 128000;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_BUCKET_MAX))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 86);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_BUCKET_MAX))
    if (http_config_animating)
        icl_console_print ("<http_config_bucket_max_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" bucket_max=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, bucket_max);
#endif


    return (bucket_max);
}
/*  -------------------------------------------------------------------------
    http_config_set_read_timeout

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_read_timeout (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_READ_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_read_timeout_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_READ_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 87);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_READ_TIMEOUT))
    icl_stats_inc ("http_config_set_read_timeout", &s_http_config_set_read_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", read_timeout);
ipr_config_putp (self->config, "/config/tuning", "read_timeout", strvalue);
self->read_timeout = read_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_READ_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 87);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_READ_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_read_timeout_finish"
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
    http_config_read_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_read_timeout (
    http_config_t * self                //  Reference to self
)
{
    int
        read_timeout;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_READ_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_read_timeout_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_READ_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 88);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_READ_TIMEOUT))
    icl_stats_inc ("http_config_read_timeout", &s_http_config_read_timeout_stats);
#endif

//
if (self)
    read_timeout = self->read_timeout;
else
    read_timeout = 60;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_READ_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 88);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_READ_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_read_timeout_finish"
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
    http_config_set_write_timeout

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_write_timeout (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_WRITE_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_write_timeout_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WRITE_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 89);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_WRITE_TIMEOUT))
    icl_stats_inc ("http_config_set_write_timeout", &s_http_config_set_write_timeout_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", write_timeout);
ipr_config_putp (self->config, "/config/tuning", "write_timeout", strvalue);
self->write_timeout = write_timeout;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WRITE_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 89);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_WRITE_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_set_write_timeout_finish"
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
    http_config_write_timeout

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_write_timeout (
    http_config_t * self                //  Reference to self
)
{
    int
        write_timeout;                  //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_WRITE_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_write_timeout_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 90);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WRITE_TIMEOUT))
    icl_stats_inc ("http_config_write_timeout", &s_http_config_write_timeout_stats);
#endif

//
if (self)
    write_timeout = self->write_timeout;
else
    write_timeout = 60;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_TIMEOUT))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 90);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_WRITE_TIMEOUT))
    if (http_config_animating)
        icl_console_print ("<http_config_write_timeout_finish"
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
    http_config_set_tcp_nodelay

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_tcp_nodelay (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_TCP_NODELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_tcp_nodelay_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, http_config_dump, 91);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TCP_NODELAY))
    icl_stats_inc ("http_config_set_tcp_nodelay", &s_http_config_set_tcp_nodelay_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
ipr_config_putp (self->config, "/config/tuning", "tcp_nodelay", strvalue);
self->tcp_nodelay = tcp_nodelay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 91);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_TCP_NODELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_set_tcp_nodelay_finish"
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
    http_config_tcp_nodelay

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    http_config_tcp_nodelay (
    http_config_t * self                //  Reference to self
)
{
    Bool
        tcp_nodelay;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_TCP_NODELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_tcp_nodelay_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, http_config_dump, 92);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TCP_NODELAY))
    icl_stats_inc ("http_config_tcp_nodelay", &s_http_config_tcp_nodelay_stats);
#endif

//
if (self)
    tcp_nodelay = self->tcp_nodelay;
else
    tcp_nodelay = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 92);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_TCP_NODELAY))
    if (http_config_animating)
        icl_console_print ("<http_config_tcp_nodelay_finish"
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
    http_config_set_tcp_rcvbuf

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_tcp_rcvbuf (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_TCP_RCVBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_set_tcp_rcvbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, http_config_dump, 93);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TCP_RCVBUF))
    icl_stats_inc ("http_config_set_tcp_rcvbuf", &s_http_config_set_tcp_rcvbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_rcvbuf", strvalue);
self->tcp_rcvbuf = tcp_rcvbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 93);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_TCP_RCVBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_set_tcp_rcvbuf_finish"
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
    http_config_tcp_rcvbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_tcp_rcvbuf (
    http_config_t * self                //  Reference to self
)
{
    int
        tcp_rcvbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_TCP_RCVBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_tcp_rcvbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, http_config_dump, 94);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TCP_RCVBUF))
    icl_stats_inc ("http_config_tcp_rcvbuf", &s_http_config_tcp_rcvbuf_stats);
#endif

//
if (self)
    tcp_rcvbuf = self->tcp_rcvbuf;
else
    tcp_rcvbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 94);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_TCP_RCVBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_tcp_rcvbuf_finish"
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
    http_config_set_tcp_sndbuf

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_tcp_sndbuf (
    http_config_t * self,               //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_TCP_SNDBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_set_tcp_sndbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, http_config_dump, 95);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_TCP_SNDBUF))
    icl_stats_inc ("http_config_set_tcp_sndbuf", &s_http_config_set_tcp_sndbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_sndbuf", strvalue);
self->tcp_sndbuf = tcp_sndbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 95);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_TCP_SNDBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_set_tcp_sndbuf_finish"
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
    http_config_tcp_sndbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_tcp_sndbuf (
    http_config_t * self                //  Reference to self
)
{
    int
        tcp_sndbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_TCP_SNDBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_tcp_sndbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, http_config_dump, 96);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TCP_SNDBUF))
    icl_stats_inc ("http_config_tcp_sndbuf", &s_http_config_tcp_sndbuf_stats);
#endif

//
if (self)
    tcp_sndbuf = self->tcp_sndbuf;
else
    tcp_sndbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 96);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_TCP_SNDBUF))
    if (http_config_animating)
        icl_console_print ("<http_config_tcp_sndbuf_finish"
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
    http_config_set_polling_threads

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_polling_threads (
    http_config_t * self,               //  Reference to object
    int polling_threads                 //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_POLLING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_polling_threads_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" polling_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, polling_threads);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLLING_THREADS))
    icl_trace_record (NULL, http_config_dump, 97);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_POLLING_THREADS))
    icl_stats_inc ("http_config_set_polling_threads", &s_http_config_set_polling_threads_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", polling_threads);
ipr_config_putp (self->config, "/config/tuning", "polling_threads", strvalue);
self->polling_threads = polling_threads;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLLING_THREADS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 97);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_POLLING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_polling_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" polling_threads=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, polling_threads, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_polling_threads

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_polling_threads (
    http_config_t * self                //  Reference to self
)
{
    int
        polling_threads;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_POLLING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_polling_threads_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_POLLING_THREADS))
    icl_trace_record (NULL, http_config_dump, 98);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_POLLING_THREADS))
    icl_stats_inc ("http_config_polling_threads", &s_http_config_polling_threads_stats);
#endif

//
if (self)
    polling_threads = self->polling_threads;
else
    polling_threads = 4;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_POLLING_THREADS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 98);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_POLLING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_polling_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" polling_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, polling_threads);
#endif


    return (polling_threads);
}
/*  -------------------------------------------------------------------------
    http_config_set_working_threads

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_working_threads (
    http_config_t * self,               //  Reference to object
    int working_threads                 //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_WORKING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_working_threads_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" working_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, working_threads);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WORKING_THREADS))
    icl_trace_record (NULL, http_config_dump, 99);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_WORKING_THREADS))
    icl_stats_inc ("http_config_set_working_threads", &s_http_config_set_working_threads_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", working_threads);
ipr_config_putp (self->config, "/config/tuning", "working_threads", strvalue);
self->working_threads = working_threads;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WORKING_THREADS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 99);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_WORKING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_set_working_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" working_threads=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, working_threads, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_working_threads

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    http_config_working_threads (
    http_config_t * self                //  Reference to self
)
{
    int
        working_threads;                //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_WORKING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_working_threads_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WORKING_THREADS))
    icl_trace_record (NULL, http_config_dump, 100);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WORKING_THREADS))
    icl_stats_inc ("http_config_working_threads", &s_http_config_working_threads_stats);
#endif

//
if (self)
    working_threads = self->working_threads;
else
    working_threads = 4;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WORKING_THREADS))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 100);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_WORKING_THREADS))
    if (http_config_animating)
        icl_console_print ("<http_config_working_threads_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" working_threads=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, working_threads);
#endif


    return (working_threads);
}
/*  -------------------------------------------------------------------------
    http_config_set_etag

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_set_etag (
    http_config_t * self,               //  Reference to object
    char * etag                         //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SET_ETAG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_etag_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" etag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, etag);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ETAG))
    icl_trace_record (NULL, http_config_dump, 101);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SET_ETAG))
    icl_stats_inc ("http_config_set_etag", &s_http_config_set_etag_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/cache", "etag", etag);
etag = ipr_config_getp (self->config, "/config/cache", "etag", NULL);
assert (etag);
self->etag = etag;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ETAG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 101);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SET_ETAG))
    if (http_config_animating)
        icl_console_print ("<http_config_set_etag_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" etag=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, etag, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    http_config_etag

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    http_config_etag (
    http_config_t * self                //  Reference to self
)
{
    char *
        etag;                           //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ETAG))
    if (http_config_animating)
        icl_console_print ("<http_config_etag_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ETAG))
    icl_trace_record (NULL, http_config_dump, 102);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ETAG))
    icl_stats_inc ("http_config_etag", &s_http_config_etag_stats);
#endif

//
if (self)
    etag = self->etag;
else
    etag = "fixed";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ETAG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 102);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ETAG))
    if (http_config_animating)
        icl_console_print ("<http_config_etag_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" etag=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, etag);
#endif


    return (etag);
}
/*  -------------------------------------------------------------------------
    http_config_dump_log

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    Dump current option values to an smt_log file.
    -------------------------------------------------------------------------
 */

int
    http_config_dump_log (
    http_config_t * self,               //  Reference to object
    smt_log_t * logfile                 //  Log file to dump to
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DUMP_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_dump_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, http_config_dump, 103);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DUMP_LOG))
    icl_stats_inc ("http_config_dump_log", &s_http_config_dump_log_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

smt_log_print (logfile, "*******************  Configuration Settings  ********************");
smt_log_print (logfile, "server_name=%s", self->server_name);
smt_log_print (logfile, "port=%s", self->port);
smt_log_print (logfile, "public_port=%s", self->public_port);
smt_log_print (logfile, "trace=%i", self->trace);
smt_log_print (logfile, "animate=%i", self->animate);
smt_log_print (logfile, "verbose=%i", self->verbose);
smt_log_print (logfile, "listen=%s", self->listen);
smt_log_print (logfile, "webroot=%s", self->webroot);
smt_log_print (logfile, "defaults=%s", self->defaults);
smt_log_print (logfile, "default_types=%s", self->default_types);
smt_log_print (logfile, "monitor=%i", self->monitor);
smt_log_print (logfile, "record_stats=%i", self->record_stats);
smt_log_print (logfile, "log_path=%s", self->log_path);
smt_log_print (logfile, "keep_logs=%i", self->keep_logs);
smt_log_print (logfile, "archive_path=%s", self->archive_path);
smt_log_print (logfile, "archive_cmd=%s", self->archive_cmd);
smt_log_print (logfile, "alert_log=%s", self->alert_log);
smt_log_print (logfile, "access_log=%s", self->access_log);
smt_log_print (logfile, "access_log_format=%s", self->access_log_format);
smt_log_print (logfile, "debug_log=%s", self->debug_log);
smt_log_print (logfile, "blacklist=%s", self->blacklist);
smt_log_print (logfile, "basic_auth=%s", self->basic_auth);
smt_log_print (logfile, "digest_auth=%s", self->digest_auth);
smt_log_print (logfile, "password_ttl=%i", self->password_ttl);
smt_log_print (logfile, "hit_quota=%i", self->hit_quota);
smt_log_print (logfile, "miss_quota=%i", self->miss_quota);
smt_log_print (logfile, "password_guard=%i", self->password_guard);
smt_log_print (logfile, "policy_trace=%i", self->policy_trace);
smt_log_print (logfile, "nervosity=%i", self->nervosity);
smt_log_print (logfile, "nonce_ttl=%i", self->nonce_ttl);
smt_log_print (logfile, "nonce_quota=%i", self->nonce_quota);
smt_log_print (logfile, "refresh_by=%s", self->refresh_by);
smt_log_print (logfile, "refresh_log=%s", self->refresh_log);
smt_log_print (logfile, "address_quota=%i", self->address_quota);
smt_log_print (logfile, "abort_delay=%i", self->abort_delay);
smt_log_print (logfile, "coremark_cycles=%i", self->coremark_cycles);
smt_log_print (logfile, "header_max=%i", self->header_max);
smt_log_print (logfile, "bucket_max=%i", self->bucket_max);
smt_log_print (logfile, "read_timeout=%i", self->read_timeout);
smt_log_print (logfile, "write_timeout=%i", self->write_timeout);
smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
smt_log_print (logfile, "polling_threads=%i", self->polling_threads);
smt_log_print (logfile, "working_threads=%i", self->working_threads);
smt_log_print (logfile, "etag=%s", self->etag);
smt_log_print (logfile, "");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 103);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DUMP_LOG))
    if (http_config_animating)
        icl_console_print ("<http_config_dump_log_finish"
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
    http_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_config_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SELFTEST))
    if (http_config_animating)
        icl_console_print ("<http_config_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SELFTEST))
    icl_trace_record (NULL, http_config_dump, 104);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SELFTEST))
    icl_stats_inc ("http_config_selftest", &s_http_config_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SELFTEST))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 104);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SELFTEST))
    if (http_config_animating)
        icl_console_print ("<http_config_selftest_finish"
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
    http_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_config_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_TERMINATE))
    if (http_config_animating)
        icl_console_print ("<http_config_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TERMINATE))
    icl_trace_record (NULL, http_config_dump, 105);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_TERMINATE))
    icl_stats_inc ("http_config_terminate", &s_http_config_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_TERMINATE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 105);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_TERMINATE))
    if (http_config_animating)
        icl_console_print ("<http_config_terminate_finish"
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
    http_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
http_config_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SHOW))
    if (http_config_animating)
        icl_console_print ("<http_config_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW))
    icl_trace_record (NULL, http_config_dump, 106);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SHOW))
    icl_stats_inc ("http_config_show", &s_http_config_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <http_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 106);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SHOW))
    if (http_config_animating)
        icl_console_print ("<http_config_show_finish"
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
    http_config_destroy

    Type: Component method
    Destroys a http_config_t object. Takes the address of a
    http_config_t reference (a pointer to a pointer) and nullifies the
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
    http_config_destroy_ (
    http_config_t * ( * self_p ),       //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    http_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_DESTROY_PUBLIC))
    if (http_config_animating)
        icl_console_print ("<http_config_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_config_dump, 107);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_DESTROY_PUBLIC))
    icl_stats_inc ("http_config_destroy", &s_http_config_destroy_stats);
#endif

if (self) {
    http_config_annihilate (self_p);
    http_config_free ((http_config_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 107);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_DESTROY_PUBLIC))
    if (http_config_animating)
        icl_console_print ("<http_config_destroy_public_finish"
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
    http_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static http_config_t *
    http_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    http_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_ALLOC))
    if (http_config_animating)
        icl_console_print ("<http_config_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ALLOC))
    icl_trace_record (NULL, http_config_dump, 108);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_ALLOC))
    icl_stats_inc ("http_config_alloc", &s_http_config_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    http_config_cache_initialise ();

self = (http_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (http_config_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_ALLOC))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 108);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_ALLOC))
    if (http_config_animating)
        icl_console_print ("<http_config_alloc_finish"
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
    http_config_free

    Type: Component method
    Freess a http_config_t object.
    -------------------------------------------------------------------------
 */

static void
    http_config_free (
    http_config_t * self                //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_FREE))
    if (http_config_animating)
        icl_console_print ("<http_config_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_FREE))
    icl_trace_record (NULL, http_config_dump, 109);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_FREE))
    icl_stats_inc ("http_config_free", &s_http_config_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (http_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (http_config_t));
        self->object_tag = HTTP_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_FREE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 109);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_FREE))
    if (http_config_animating)
        icl_console_print ("<http_config_free_finish"
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
    http_config_read_lock

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_read_lock (
    http_config_t * self                //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_READ_LOCK))
    if (http_config_animating)
        icl_console_print ("<http_config_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_READ_LOCK))
    icl_trace_record (NULL, http_config_dump, 110);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_READ_LOCK))
    icl_stats_inc ("http_config_read_lock", &s_http_config_read_lock_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_READ_LOCK))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 110);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_READ_LOCK))
    if (http_config_animating)
        icl_console_print ("<http_config_read_lock_finish"
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
    http_config_write_lock

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_write_lock (
    http_config_t * self                //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_WRITE_LOCK))
    if (http_config_animating)
        icl_console_print ("<http_config_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, http_config_dump, 111);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_WRITE_LOCK))
    icl_stats_inc ("http_config_write_lock", &s_http_config_write_lock_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 111);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_WRITE_LOCK))
    if (http_config_animating)
        icl_console_print ("<http_config_write_lock_finish"
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
    http_config_unlock

    Type: Component method
    Accepts a http_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    http_config_unlock (
    http_config_t * self                //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_UNLOCK))
    if (http_config_animating)
        icl_console_print ("<http_config_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_UNLOCK))
    icl_trace_record (NULL, http_config_dump, 112);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_UNLOCK))
    icl_stats_inc ("http_config_unlock", &s_http_config_unlock_stats);
#endif

HTTP_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_UNLOCK))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 112);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_UNLOCK))
    if (http_config_animating)
        icl_console_print ("<http_config_unlock_finish"
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
    http_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    http_config_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_CACHE_INITIALISE))
    if (http_config_animating)
        icl_console_print ("<http_config_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, http_config_dump, 113);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CACHE_INITIALISE))
    icl_stats_inc ("http_config_cache_initialise", &s_http_config_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (http_config_t));
icl_system_register (http_config_cache_purge, http_config_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 113);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_CACHE_INITIALISE))
    if (http_config_animating)
        icl_console_print ("<http_config_cache_initialise_finish"
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
    http_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_config_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_CACHE_PURGE))
    if (http_config_animating)
        icl_console_print ("<http_config_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, http_config_dump, 114);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CACHE_PURGE))
    icl_stats_inc ("http_config_cache_purge", &s_http_config_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 114);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_CACHE_PURGE))
    if (http_config_animating)
        icl_console_print ("<http_config_cache_purge_finish"
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
    http_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    http_config_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_CACHE_TERMINATE))
    if (http_config_animating)
        icl_console_print ("<http_config_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, http_config_dump, 115);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_CACHE_TERMINATE))
    icl_stats_inc ("http_config_cache_terminate", &s_http_config_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 115);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_CACHE_TERMINATE))
    if (http_config_animating)
        icl_console_print ("<http_config_cache_terminate_finish"
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
    http_config_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    http_config_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_SHOW_ANIMATION))
    if (http_config_animating)
        icl_console_print ("<http_config_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW_ANIMATION))
    icl_trace_record (NULL, http_config_dump, 116);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_SHOW_ANIMATION))
    icl_stats_inc ("http_config_show_animation", &s_http_config_show_animation_stats);
#endif

http_config_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW_ANIMATION))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 116);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_SHOW_ANIMATION))
    if (http_config_animating)
        icl_console_print ("<http_config_show_animation_finish"
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
    http_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    http_config_new_in_scope_ (
    http_config_t * * self_p,           //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_HTTP_CONFIG)  ||  defined (BASE_ANIMATE_HTTP_CONFIG_NEW_IN_SCOPE))
    if (http_config_animating)
        icl_console_print ("<http_config_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_config_dump, 117);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_HTTP_CONFIG)  ||  defined (BASE_STATS_HTTP_CONFIG_NEW_IN_SCOPE))
    icl_stats_inc ("http_config_new_in_scope", &s_http_config_new_in_scope_stats);
#endif

*self_p = http_config_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) http_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, http_config_dump, 0x10000 + 117);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_HTTP_CONFIG)   || defined (BASE_ANIMATE_HTTP_CONFIG_NEW_IN_SCOPE))
    if (http_config_animating)
        icl_console_print ("<http_config_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG)   || defined (BASE_TRACE_HTTP_CONFIG_NEW)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_HTTP_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_HTTP_CONFIG_SHADOW)   || defined (BASE_TRACE_HTTP_CONFIG_COMMIT)   || defined (BASE_TRACE_HTTP_CONFIG_ROLLBACK)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_HTTP_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_HTTP_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_HTTP_CONFIG_SET_SERVER_NAME)   || defined (BASE_TRACE_HTTP_CONFIG_SERVER_NAME)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PUBLIC_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_PUBLIC_PORT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ANIMATE)   || defined (BASE_TRACE_HTTP_CONFIG_ANIMATE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_VERBOSE)   || defined (BASE_TRACE_HTTP_CONFIG_VERBOSE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LISTEN)   || defined (BASE_TRACE_HTTP_CONFIG_LISTEN)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WEBROOT)   || defined (BASE_TRACE_HTTP_CONFIG_WEBROOT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULTS)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULTS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEFAULT_TYPES)   || defined (BASE_TRACE_HTTP_CONFIG_DEFAULT_TYPES)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MONITOR)   || defined (BASE_TRACE_HTTP_CONFIG_MONITOR)   || defined (BASE_TRACE_HTTP_CONFIG_SET_RECORD_STATS)   || defined (BASE_TRACE_HTTP_CONFIG_RECORD_STATS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_LOG_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_LOG_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_KEEP_LOGS)   || defined (BASE_TRACE_HTTP_CONFIG_KEEP_LOGS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_PATH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ARCHIVE_CMD)   || defined (BASE_TRACE_HTTP_CONFIG_ARCHIVE_CMD)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ALERT_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_ALERT_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ACCESS_LOG_FORMAT)   || defined (BASE_TRACE_HTTP_CONFIG_ACCESS_LOG_FORMAT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DEBUG_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_DEBUG_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BLACKLIST)   || defined (BASE_TRACE_HTTP_CONFIG_BLACKLIST)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BASIC_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_BASIC_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_DIGEST_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_DIGEST_AUTH)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HIT_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_HIT_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_MISS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_MISS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_PASSWORD_GUARD)   || defined (BASE_TRACE_HTTP_CONFIG_PASSWORD_GUARD)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLICY_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_POLICY_TRACE)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NERVOSITY)   || defined (BASE_TRACE_HTTP_CONFIG_NERVOSITY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_TTL)   || defined (BASE_TRACE_HTTP_CONFIG_SET_NONCE_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_NONCE_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_BY)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_BY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_REFRESH_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_REFRESH_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ADDRESS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_ADDRESS_QUOTA)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ABORT_DELAY)   || defined (BASE_TRACE_HTTP_CONFIG_ABORT_DELAY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_COREMARK_CYCLES)   || defined (BASE_TRACE_HTTP_CONFIG_COREMARK_CYCLES)   || defined (BASE_TRACE_HTTP_CONFIG_SET_HEADER_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_HEADER_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_SET_BUCKET_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_BUCKET_MAX)   || defined (BASE_TRACE_HTTP_CONFIG_SET_READ_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_READ_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WRITE_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_TIMEOUT)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_HTTP_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_HTTP_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_HTTP_CONFIG_SET_POLLING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_POLLING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_WORKING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_WORKING_THREADS)   || defined (BASE_TRACE_HTTP_CONFIG_SET_ETAG)   || defined (BASE_TRACE_HTTP_CONFIG_ETAG)   || defined (BASE_TRACE_HTTP_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_HTTP_CONFIG_SELFTEST)   || defined (BASE_TRACE_HTTP_CONFIG_TERMINATE)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW)   || defined (BASE_TRACE_HTTP_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_HTTP_CONFIG_ALLOC)   || defined (BASE_TRACE_HTTP_CONFIG_FREE)   || defined (BASE_TRACE_HTTP_CONFIG_READ_LOCK)   || defined (BASE_TRACE_HTTP_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_HTTP_CONFIG_UNLOCK)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_HTTP_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_HTTP_CONFIG_SHOW_ANIMATION)   || defined (BASE_TRACE_HTTP_CONFIG_NEW_IN_SCOPE) )
void
http_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
        case 11: method_name = "set server_name"; break;
        case 12: method_name = "server_name"; break;
        case 13: method_name = "set port"; break;
        case 14: method_name = "port"; break;
        case 15: method_name = "set public_port"; break;
        case 16: method_name = "public_port"; break;
        case 17: method_name = "set trace"; break;
        case 18: method_name = "trace"; break;
        case 19: method_name = "set animate"; break;
        case 20: method_name = "animate"; break;
        case 21: method_name = "set verbose"; break;
        case 22: method_name = "verbose"; break;
        case 23: method_name = "set listen"; break;
        case 24: method_name = "listen"; break;
        case 25: method_name = "set webroot"; break;
        case 26: method_name = "webroot"; break;
        case 27: method_name = "set defaults"; break;
        case 28: method_name = "defaults"; break;
        case 29: method_name = "set default_types"; break;
        case 30: method_name = "default_types"; break;
        case 31: method_name = "set monitor"; break;
        case 32: method_name = "monitor"; break;
        case 33: method_name = "set record_stats"; break;
        case 34: method_name = "record_stats"; break;
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
        case 45: method_name = "set access_log"; break;
        case 46: method_name = "access_log"; break;
        case 47: method_name = "set access_log_format"; break;
        case 48: method_name = "access_log_format"; break;
        case 49: method_name = "set debug_log"; break;
        case 50: method_name = "debug_log"; break;
        case 51: method_name = "set blacklist"; break;
        case 52: method_name = "blacklist"; break;
        case 53: method_name = "set basic_auth"; break;
        case 54: method_name = "basic_auth"; break;
        case 55: method_name = "set digest_auth"; break;
        case 56: method_name = "digest_auth"; break;
        case 57: method_name = "set password_ttl"; break;
        case 58: method_name = "password_ttl"; break;
        case 59: method_name = "set hit_quota"; break;
        case 60: method_name = "hit_quota"; break;
        case 61: method_name = "set miss_quota"; break;
        case 62: method_name = "miss_quota"; break;
        case 63: method_name = "set password_guard"; break;
        case 64: method_name = "password_guard"; break;
        case 65: method_name = "set policy_trace"; break;
        case 66: method_name = "policy_trace"; break;
        case 67: method_name = "set nervosity"; break;
        case 68: method_name = "nervosity"; break;
        case 69: method_name = "set nonce_ttl"; break;
        case 70: method_name = "nonce_ttl"; break;
        case 71: method_name = "set nonce_quota"; break;
        case 72: method_name = "nonce_quota"; break;
        case 73: method_name = "set refresh_by"; break;
        case 74: method_name = "refresh_by"; break;
        case 75: method_name = "set refresh_log"; break;
        case 76: method_name = "refresh_log"; break;
        case 77: method_name = "set address_quota"; break;
        case 78: method_name = "address_quota"; break;
        case 79: method_name = "set abort_delay"; break;
        case 80: method_name = "abort_delay"; break;
        case 81: method_name = "set coremark_cycles"; break;
        case 82: method_name = "coremark_cycles"; break;
        case 83: method_name = "set header_max"; break;
        case 84: method_name = "header_max"; break;
        case 85: method_name = "set bucket_max"; break;
        case 86: method_name = "bucket_max"; break;
        case 87: method_name = "set read_timeout"; break;
        case 88: method_name = "read_timeout"; break;
        case 89: method_name = "set write_timeout"; break;
        case 90: method_name = "write_timeout"; break;
        case 91: method_name = "set tcp_nodelay"; break;
        case 92: method_name = "tcp_nodelay"; break;
        case 93: method_name = "set tcp_rcvbuf"; break;
        case 94: method_name = "tcp_rcvbuf"; break;
        case 95: method_name = "set tcp_sndbuf"; break;
        case 96: method_name = "tcp_sndbuf"; break;
        case 97: method_name = "set polling_threads"; break;
        case 98: method_name = "polling_threads"; break;
        case 99: method_name = "set working_threads"; break;
        case 100: method_name = "working_threads"; break;
        case 101: method_name = "set etag"; break;
        case 102: method_name = "etag"; break;
        case 103: method_name = "dump log"; break;
        case 104: method_name = "selftest"; break;
        case 105: method_name = "terminate"; break;
        case 106: method_name = "show"; break;
        case 107: method_name = "destroy public"; break;
        case 108: method_name = "alloc"; break;
        case 109: method_name = "free"; break;
        case 110: method_name = "read lock"; break;
        case 111: method_name = "write lock"; break;
        case 112: method_name = "unlock"; break;
        case 113: method_name = "cache initialise"; break;
        case 114: method_name = "cache purge"; break;
        case 115: method_name = "cache terminate"; break;
        case 116: method_name = "show animation"; break;
        case 117: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "http_config %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *http_config_version_start    = "VeRsIoNsTaRt:ipc";
char *http_config_component        = "http_config ";
char *http_config_version          = "1.0 ";
char *http_config_copyright        = "Copyright (c) 1996-2009 iMatix Corporation";
char *http_config_filename         = "http_config.icl ";
char *http_config_builddate        = "2009/02/19 ";
char *http_config_version_end      = "VeRsIoNeNd:ipc";

