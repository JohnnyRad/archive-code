/*---------------------------------------------------------------------------
    demo_client_config.c - demo_client_config component

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
 *---------------------------------------------------------------------------*/

#include "icl.h"                        //  iCL base classes
#include "demo_client_config.h"         //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              demo_client_config_t

//  Shorthands for class methods                                               

#define self_new            demo_client_config_new
#define self_annihilate     demo_client_config_annihilate
#define self_load_xmlfile   demo_client_config_load_xmlfile
#define self_load_bucket    demo_client_config_load_bucket
#define self_shadow         demo_client_config_shadow
#define self_commit         demo_client_config_commit
#define self_rollback       demo_client_config_rollback
#define self_cmdline_help   demo_client_config_cmdline_help
#define self_cmdline_parse  demo_client_config_cmdline_parse
#define self_options_help   demo_client_config_options_help
#define self_set_tcp_nodelay  demo_client_config_set_tcp_nodelay
#define self_tcp_nodelay    demo_client_config_tcp_nodelay
#define self_set_tcp_rcvbuf  demo_client_config_set_tcp_rcvbuf
#define self_tcp_rcvbuf     demo_client_config_tcp_rcvbuf
#define self_set_tcp_sndbuf  demo_client_config_set_tcp_sndbuf
#define self_tcp_sndbuf     demo_client_config_tcp_sndbuf
#define self_set_high_water  demo_client_config_set_high_water
#define self_high_water     demo_client_config_high_water
#define self_set_low_water  demo_client_config_set_low_water
#define self_low_water      demo_client_config_low_water
#define self_set_direct     demo_client_config_set_direct
#define self_direct         demo_client_config_direct
#define self_set_batching   demo_client_config_set_batching
#define self_batching       demo_client_config_batching
#define self_set_on_overflow  demo_client_config_set_on_overflow
#define self_on_overflow    demo_client_config_on_overflow
#define self_set_chrono_enabled  demo_client_config_set_chrono_enabled
#define self_chrono_enabled  demo_client_config_chrono_enabled
#define self_set_chrono_floor  demo_client_config_set_chrono_floor
#define self_chrono_floor   demo_client_config_chrono_floor
#define self_set_chrono_density  demo_client_config_set_chrono_density
#define self_chrono_density  demo_client_config_chrono_density
#define self_set_chrono_batch  demo_client_config_set_chrono_batch
#define self_chrono_batch   demo_client_config_chrono_batch
#define self_dump_log       demo_client_config_dump_log
#define self_selftest       demo_client_config_selftest
#define self_terminate      demo_client_config_terminate
#define self_show           demo_client_config_show
#define self_destroy        demo_client_config_destroy
#define self_alloc          demo_client_config_alloc
#define self_free           demo_client_config_free
#define self_read_lock      demo_client_config_read_lock
#define self_write_lock     demo_client_config_write_lock
#define self_unlock         demo_client_config_unlock
#define self_cache_initialise  demo_client_config_cache_initialise
#define self_cache_purge    demo_client_config_cache_purge
#define self_cache_terminate  demo_client_config_cache_terminate
#define self_show_animation  demo_client_config_show_animation
#define self_new_in_scope   demo_client_config_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_NEW))
static icl_stats_t *s_demo_client_config_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DESTROY))
static icl_stats_t *s_demo_client_config_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_LOAD_XMLFILE))
static icl_stats_t *s_demo_client_config_load_xmlfile_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_LOAD_BUCKET))
static icl_stats_t *s_demo_client_config_load_bucket_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SHADOW))
static icl_stats_t *s_demo_client_config_shadow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_COMMIT))
static icl_stats_t *s_demo_client_config_commit_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_ROLLBACK))
static icl_stats_t *s_demo_client_config_rollback_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CMDLINE_HELP))
static icl_stats_t *s_demo_client_config_cmdline_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CMDLINE_PARSE))
static icl_stats_t *s_demo_client_config_cmdline_parse_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_OPTIONS_HELP))
static icl_stats_t *s_demo_client_config_options_help_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY))
static icl_stats_t *s_demo_client_config_set_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TCP_NODELAY))
static icl_stats_t *s_demo_client_config_tcp_nodelay_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF))
static icl_stats_t *s_demo_client_config_set_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TCP_RCVBUF))
static icl_stats_t *s_demo_client_config_tcp_rcvbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF))
static icl_stats_t *s_demo_client_config_set_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TCP_SNDBUF))
static icl_stats_t *s_demo_client_config_tcp_sndbuf_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_HIGH_WATER))
static icl_stats_t *s_demo_client_config_set_high_water_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_HIGH_WATER))
static icl_stats_t *s_demo_client_config_high_water_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_LOW_WATER))
static icl_stats_t *s_demo_client_config_set_low_water_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_LOW_WATER))
static icl_stats_t *s_demo_client_config_low_water_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_DIRECT))
static icl_stats_t *s_demo_client_config_set_direct_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DIRECT))
static icl_stats_t *s_demo_client_config_direct_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_BATCHING))
static icl_stats_t *s_demo_client_config_set_batching_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_BATCHING))
static icl_stats_t *s_demo_client_config_batching_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW))
static icl_stats_t *s_demo_client_config_set_on_overflow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_ON_OVERFLOW))
static icl_stats_t *s_demo_client_config_on_overflow_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED))
static icl_stats_t *s_demo_client_config_set_chrono_enabled_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_ENABLED))
static icl_stats_t *s_demo_client_config_chrono_enabled_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR))
static icl_stats_t *s_demo_client_config_set_chrono_floor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_FLOOR))
static icl_stats_t *s_demo_client_config_chrono_floor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY))
static icl_stats_t *s_demo_client_config_set_chrono_density_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_DENSITY))
static icl_stats_t *s_demo_client_config_chrono_density_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH))
static icl_stats_t *s_demo_client_config_set_chrono_batch_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_BATCH))
static icl_stats_t *s_demo_client_config_chrono_batch_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DUMP_LOG))
static icl_stats_t *s_demo_client_config_dump_log_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SELFTEST))
static icl_stats_t *s_demo_client_config_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TERMINATE))
static icl_stats_t *s_demo_client_config_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SHOW))
static icl_stats_t *s_demo_client_config_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC))
static icl_stats_t *s_demo_client_config_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_ALLOC))
static icl_stats_t *s_demo_client_config_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_FREE))
static icl_stats_t *s_demo_client_config_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_READ_LOCK))
static icl_stats_t *s_demo_client_config_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_WRITE_LOCK))
static icl_stats_t *s_demo_client_config_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_UNLOCK))
static icl_stats_t *s_demo_client_config_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CACHE_INITIALISE))
static icl_stats_t *s_demo_client_config_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CACHE_PURGE))
static icl_stats_t *s_demo_client_config_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CACHE_TERMINATE))
static icl_stats_t *s_demo_client_config_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SHOW_ANIMATION))
static icl_stats_t *s_demo_client_config_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE))
static icl_stats_t *s_demo_client_config_new_in_scope_stats = NULL;
#endif
static void
    demo_client_config_annihilate (
demo_client_config_t * ( * self_p )     //  Reference to object reference
);

#define demo_client_config_alloc()      demo_client_config_alloc_ (__FILE__, __LINE__)
static demo_client_config_t *
    demo_client_config_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    demo_client_config_free (
demo_client_config_t * self             //  Object reference
);

static void
    demo_client_config_cache_initialise (
void);

static void
    demo_client_config_cache_purge (
void);

static void
    demo_client_config_cache_terminate (
void);

Bool
    demo_client_config_animating = TRUE;  //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static void s_validate_items (demo_client_config_t *self);
static void s_get_properties (demo_client_config_t *self);
demo_client_config_t
    *demo_client_config = NULL;         //  Global properties
static void s_validate_items (demo_client_config_t *self)
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
        if (strneq (item_name, "tuning")
        && strneq (item_name, "direct")
        && strneq (item_name, "chrono"))
            icl_console_print ("W: %s: unknown item '%s', ignored",
                self->filename, item_name);
        ipr_config_next (self->config);
    }
}

static void s_get_properties (demo_client_config_t *self)
{
    char
        *value;                         //  Configured value

    //  All properties on tuning path
    ipr_config_locate (self->config, "/config/tuning", NULL);

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

    //  Get high_water property from config file or built-in defaults
    value = ipr_config_get (self->config, "high_water", NULL);
    if (value)
        self->high_water = (int) atol (value);
    else
        self->high_water = 0;

    //  Get low_water property from config file or built-in defaults
    value = ipr_config_get (self->config, "low_water", NULL);
    if (value)
        self->low_water = (int) atol (value);
    else
        self->low_water = 0;

    //  Get direct property from config file or built-in defaults
    value = ipr_config_get (self->config, "direct", NULL);
    if (value)
        self->direct = (int) atol (value);
    else
        self->direct = 0;

    //  All properties on direct path
    ipr_config_locate (self->config, "/config/direct", NULL);

    //  Get batching property from config file or built-in defaults
    value = ipr_config_get (self->config, "batching", NULL);
    if (value)
        self->batching = (int) atol (value);
    else
        self->batching = 32768;
    if (self->batching > 2097152) {
        icl_console_print ("W: %s: illegal value %d for batching, using %d",
            self->filename, self->batching, 2097152);
        self->batching = 2097152;
    }

    //  Get on_overflow property from config file or built-in defaults
    value = ipr_config_get (self->config, "on_overflow", NULL);
    if (value)
        self->on_overflow = value;
    else
        self->on_overflow = "trim";

    //  All properties on chrono path
    ipr_config_locate (self->config, "/config/chrono", NULL);

    //  Get chrono_enabled property from config file or built-in defaults
    value = ipr_config_get (self->config, "enabled", NULL);
    if (value)
        self->chrono_enabled = (int) atol (value);
    else
        self->chrono_enabled = 1;

    //  Get chrono_floor property from config file or built-in defaults
    value = ipr_config_get (self->config, "floor", NULL);
    if (value)
        self->chrono_floor = (int) atol (value);
    else
        self->chrono_floor = 100;

    //  Get chrono_density property from config file or built-in defaults
    value = ipr_config_get (self->config, "density", NULL);
    if (value)
        self->chrono_density = (int) atol (value);
    else
        self->chrono_density = 1;

    //  Get chrono_batch property from config file or built-in defaults
    value = ipr_config_get (self->config, "batch", NULL);
    if (value)
        self->chrono_batch = (int) atol (value);
    else
        self->chrono_batch = 150;
}
/*  -------------------------------------------------------------------------
    demo_client_config_new

    Type: Component method
    Creates and initialises a new demo_client_config_t object, returns a
    reference to the created object.
    Creates an empty configuration set.  To fill this, use the load and
    load_bucket methods.
    -------------------------------------------------------------------------
 */

demo_client_config_t *
    demo_client_config_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    demo_client_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_NEW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW))
    icl_trace_record (NULL, demo_client_config_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_NEW))
    icl_stats_inc ("demo_client_config_new", &s_demo_client_config_new_stats);
#endif

    self = demo_client_config_alloc_ (file, line);
    if (self) {
        self->object_tag   = DEMO_CLIENT_CONFIG_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, demo_client_config_show_);
#endif

//
self->config = ipr_config_new (NULL, FALSE);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_NEW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_new_finish"
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
    demo_client_config_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_config_annihilate (
    demo_client_config_t * ( * self_p )  //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    demo_client_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DESTROY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY))
    icl_trace_record (NULL, demo_client_config_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DESTROY))
    icl_stats_inc ("demo_client_config_annihilate", &s_demo_client_config_annihilate_stats);
#endif

    DEMO_CLIENT_CONFIG_ASSERT_SANE (self);
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DESTROY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_destroy_finish"
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
    demo_client_config_load_xmlfile

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config file into the property set, merging the new loaded data
    with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_load_xmlfile (
    demo_client_config_t * self,        //  Reference to object
    char * filename,                    //  Config file to load
    Bool required                       //  Config file is required?
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_LOAD_XMLFILE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_load_xmlfile_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, demo_client_config_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_LOAD_XMLFILE))
    icl_stats_inc ("demo_client_config_load_xmlfile", &s_demo_client_config_load_xmlfile_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
assert (filename);
if (!ipr_config_load (self->config, filename, required)) {
    icl_shortstr_cpy (self->filename, filename);
    s_validate_items (self);
    s_get_properties (self);
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_XMLFILE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_LOAD_XMLFILE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_load_xmlfile_finish"
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
    demo_client_config_load_bucket

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads a config resource (as a bucket) into the property set, merging the
    new loaded data with any previous data, as defined in ipr_config.icl.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_load_bucket (
    demo_client_config_t * self,        //  Reference to object
    ipr_bucket_t * bucket               //  Config data to load
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_LOAD_BUCKET))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_load_bucket_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, demo_client_config_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_LOAD_BUCKET))
    icl_stats_inc ("demo_client_config_load_bucket", &s_demo_client_config_load_bucket_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
assert (bucket);
ipr_config_load_bucket (self->config, bucket);
s_validate_items (self);
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_BUCKET))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_LOAD_BUCKET))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_load_bucket_finish"
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
    demo_client_config_shadow

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Loads the data from a different property set, and updates all the properties.
    Use this when you want to provide your code with multiple property classes
    that actually contain an identical configuration set.  To use:
    my_config = my_config_new (NULL, NULL, FALSE);
    my_config_shadow (self, your_config->config);
    -------------------------------------------------------------------------
 */

int
    demo_client_config_shadow (
    demo_client_config_t * self,        //  Reference to object
    ipr_config_t * source               //  Config data to shadow
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SHADOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_shadow_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHADOW))
    icl_trace_record (NULL, demo_client_config_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SHADOW))
    icl_stats_inc ("demo_client_config_shadow", &s_demo_client_config_shadow_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
//  Get rid of our own config data
ipr_config_destroy (&self->config);
//  Grab a handle onto the source data
self->config = ipr_config_dup (source);
//  Update our properties, without validation
s_get_properties (self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHADOW))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SHADOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_shadow_finish"
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
    demo_client_config_commit

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the current configuration values to the specified file.  If the
    provided filename is null, uses the original config filename. If both
    filenames are null, does nothing.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_commit (
    demo_client_config_t * self,        //  Reference to object
    char * filename                     //  Config file to save
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_COMMIT))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_commit_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_COMMIT))
    icl_trace_record (NULL, demo_client_config_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_COMMIT))
    icl_stats_inc ("demo_client_config_commit", &s_demo_client_config_commit_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_COMMIT))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_COMMIT))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_commit_finish"
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
    demo_client_config_rollback

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Reloads the saved configuration from the saved file, if any.
    Any changes made to the current configuration are lost.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_rollback (
    demo_client_config_t * self         //  Reference to object
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_ROLLBACK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_rollback_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ROLLBACK))
    icl_trace_record (NULL, demo_client_config_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_ROLLBACK))
    icl_stats_inc ("demo_client_config_rollback", &s_demo_client_config_rollback_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
ipr_config_destroy (&self->config);
self->config = ipr_config_new (self->filename, TRUE);
s_get_properties (self);

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ROLLBACK))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_ROLLBACK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_rollback_finish"
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
    demo_client_config_cmdline_help

    Type: Component method
    Prints command-line help for setting options from the command
    line.
    -------------------------------------------------------------------------
 */

void
    demo_client_config_cmdline_help (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CMDLINE_HELP))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cmdline_help_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, demo_client_config_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CMDLINE_HELP))
    icl_stats_inc ("demo_client_config_cmdline_help", &s_demo_client_config_cmdline_help_stats);
#endif

printf ("Options that override config values; these take an argument:\n");
printf ("  --tcp_nodelay    TCP/IP NODELAY option\n");
printf ("  --tcp_rcvbuf     TCP/IP receive buffer, in bytes\n");
printf ("  --tcp_sndbuf     TCP/IP send buffer, in bytes\n");
printf ("  --high_water     High water mark for message flow control\n");
printf ("  --low_water      Low water mark for message flow control\n");
printf ("  --direct         Enables Direct Mode for connections\n");
printf ("  --batching       Maximum size of Direct Mode batches\n");
printf ("  --on_overflow    Sets action for high-water overflow\n");
printf ("  --chrono_enabled  Enable chrono pingbacks?\n");
printf ("  --chrono_floor   Floor for chrono pingbacks\n");
printf ("  --chrono_density  Sample density as permille\n");
printf ("  --chrono_batch   Batch size for chrono pingbacks\n");
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_HELP))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CMDLINE_HELP))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cmdline_help_finish"
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
    demo_client_config_cmdline_parse

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Parses recognized command-line options starting with --.  Prints an error
    message and exits if the syntax is invalid.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_cmdline_parse (
    demo_client_config_t * self,        //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CMDLINE_PARSE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cmdline_parse_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, demo_client_config_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CMDLINE_PARSE))
    icl_stats_inc ("demo_client_config_cmdline_parse", &s_demo_client_config_cmdline_parse_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

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
            if (streq (arg_name, "--tcp_nodelay"))
                self_set_tcp_nodelay (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_rcvbuf"))
                self_set_tcp_rcvbuf (self, atoi (arg_value));
            else
            if (streq (arg_name, "--tcp_sndbuf"))
                self_set_tcp_sndbuf (self, atoi (arg_value));
            else
            if (streq (arg_name, "--high_water"))
                self_set_high_water (self, atoi (arg_value));
            else
            if (streq (arg_name, "--low_water"))
                self_set_low_water (self, atoi (arg_value));
            else
            if (streq (arg_name, "--direct"))
                self_set_direct (self, atoi (arg_value));
            else
            if (streq (arg_name, "--batching"))
                self_set_batching (self, atoi (arg_value));
            else
            if (streq (arg_name, "--on_overflow"))
                self_set_on_overflow (self, arg_value);
            else
            if (streq (arg_name, "--chrono_enabled"))
                self_set_chrono_enabled (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_floor"))
                self_set_chrono_floor (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_density"))
                self_set_chrono_density (self, atoi (arg_value));
            else
            if (streq (arg_name, "--chrono_batch"))
                self_set_chrono_batch (self, atoi (arg_value));
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_PARSE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CMDLINE_PARSE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cmdline_parse_finish"
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
    demo_client_config_options_help

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Prints full help for all configuration options.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_options_help (
    demo_client_config_t * self,        //  Reference to object
    char * name                         //  Name of application
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_OPTIONS_HELP))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_options_help_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, demo_client_config_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_OPTIONS_HELP))
    icl_stats_inc ("demo_client_config_options_help", &s_demo_client_config_options_help_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

printf ("These are the configured options for %s\n\n", name);

printf ("/config/tuning/tcp_nodelay - TCP/IP NODELAY option\n");
printf ("    From command-line: --tcp_nodelay newvalue\n");
printf ("    If this value is 1, socket data is written immediately, which is usually\n");
printf ("    good for latency. If this value is 0, data is buffered until there is a \n");
printf ("    full packet, which is usually good for throughput.                      \n");
printf ("    Current value is %i. Default value is 1.\n", self->tcp_nodelay);
printf ("\n");

printf ("/config/tuning/tcp_rcvbuf - TCP/IP receive buffer, in bytes\n");
printf ("    From command-line: --tcp_rcvbuf newvalue\n");
printf ("    If this value is greater than zero, the connection to the server will\n");
printf ("    use the specified value. Note: setting this value is delicate, do not\n");
printf ("    use this option unless you know what you are doing.                  \n");
printf ("    Current value is %i.\n", self->tcp_rcvbuf);
printf ("\n");

printf ("/config/tuning/tcp_sndbuf - TCP/IP send buffer, in bytes\n");
printf ("    From command-line: --tcp_sndbuf newvalue\n");
printf ("    If this value is greater than zero, the connection to the server will\n");
printf ("    use the specified value. Note: setting this value is delicate, do not\n");
printf ("    use this option unless you know what you are doing.                  \n");
printf ("    Current value is %i.\n", self->tcp_sndbuf);
printf ("\n");

printf ("/config/tuning/high_water - High water mark for message flow control\n");
printf ("    From command-line: --high_water newvalue\n");
printf ("    Number of messages in arrived queue when message flow from server is\n");
printf ("    stopped. If this property is 0, message flow is never switched off. \n");
printf ("    Current value is %i. Default value is 0.\n", self->high_water);
printf ("\n");

printf ("/config/tuning/low_water - Low water mark for message flow control\n");
printf ("    From command-line: --low_water newvalue\n");
printf ("    Number of messages in arrived queue when message flow from server is\n");
printf ("    started again after it had been switched off on high water mark.    \n");
printf ("    Current value is %i. Default value is 0.\n", self->low_water);
printf ("\n");

printf ("/config/tuning/direct - Enables Direct Mode for connections\n");
printf ("    From command-line: --direct newvalue\n");
printf ("    If set to 1, new connections will by default use Direct Mode.   \n");
printf ("    Applications can override this by setting the connection->direct\n");
printf ("    property on new connections.                                    \n");
printf ("    Current value is %i. Default value is 0.\n", self->direct);
printf ("\n");

printf ("/config/direct/batching - Maximum size of Direct Mode batches\n");
printf ("    From command-line: --batching newvalue\n");
printf ("    Defines the maximum batch size for Direct Mode opportunistic batching on\n");
printf ("    message sends. Setting this higher will improve throughput, and usually \n");
printf ("    with lower latency, but will cause higher memory consumption. Setting   \n");
printf ("    this to zero will switch off batching. Any value less than 2048 is      \n");
printf ("    treated as zero.                                                        \n");
printf ("    Current value is %i. Default value is 32768.\n", self->batching);
printf ("\n");

printf ("/config/direct/on_overflow - Sets action for high-water overflow\n");
printf ("    From command-line: --on_overflow newvalue\n");
printf ("    Specifies how the WireAPI stack should handle an overflow condition, as\n");
printf ("    defined by the arrived message queue reaching the high-water mark. The \n");
printf ("    allowed actions are: 'warn' - issue a message to the console, 'trim' - \n");
printf ("    discard old messages to make space for new ones, 'drop' - drop new     \n");
printf ("    incoming messages, and 'kill' - assert an error and kill the           \n");
printf ("    application.                                                           \n");
printf ("    Current value is '%s'. Default value is 'trim'\n", self->on_overflow);
printf ("\n");

printf ("/config/chrono/enabled - Enable chrono pingbacks?\n");
printf ("    From command-line: --chrono_enabled newvalue\n");
printf ("    Specifies whether chrono pingbacks are enabled or not. If not, then any\n");
printf ("    any chrono information in contents will be ignored. By default chrono  \n");
printf ("    pingbacks are enabled.                                                 \n");
printf ("    Current value is %i. Default value is 1.\n", self->chrono_enabled);
printf ("\n");

printf ("/config/chrono/floor - Floor for chrono pingbacks\n");
printf ("    From command-line: --chrono_floor newvalue\n");
printf ("    Specifies the floor for pingbacks. Only pingbacks that show an       \n");
printf ("    end-to-end latency greater or equal to the floor will be reported. If\n");
printf ("    you set this to zero, all pingbacks will be reported.                \n");
printf ("    Current value is %i. Default value is 100.\n", self->chrono_floor);
printf ("\n");

printf ("/config/chrono/density - Sample density as permille\n");
printf ("    From command-line: --chrono_density newvalue\n");
printf ("    Specifies the sampling density, as a permille. Valid values are 1 to  \n");
printf ("    1000. By default 1/1000th of messages will be sampled. The sampling is\n");
printf ("    randomized if the density is less than 1000 permille.                 \n");
printf ("    Current value is %i. Default value is 1.\n", self->chrono_density);
printf ("\n");

printf ("/config/chrono/batch - Batch size for chrono pingbacks\n");
printf ("    From command-line: --chrono_batch newvalue\n");
printf ("    Specifies the batching size for chrono pingback messages. These track  \n");
printf ("    the latency of contents passing through the architecture. A chrono     \n");
printf ("    pingback is about 15 characters long, so the default batch and promille\n");
printf ("    settings will result in one pingback message every 10,000 received     \n");
printf ("    messages. If you set the batch size too low, you may get excessive back\n");
printf ("    chatter on the network and if you make it too high, you may get latency\n");
printf ("    spikes.                                                                \n");
printf ("    Current value is %i. Default value is 150.\n", self->chrono_batch);
printf ("\n");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_OPTIONS_HELP))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_OPTIONS_HELP))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_options_help_finish"
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
    demo_client_config_set_tcp_nodelay

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_tcp_nodelay (
    demo_client_config_t * self,        //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_tcp_nodelay_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, demo_client_config_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY))
    icl_stats_inc ("demo_client_config_set_tcp_nodelay", &s_demo_client_config_set_tcp_nodelay_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_nodelay);
ipr_config_putp (self->config, "/config/tuning", "tcp_nodelay", strvalue);
self->tcp_nodelay = tcp_nodelay;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_tcp_nodelay_finish"
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
    demo_client_config_tcp_nodelay

    Type: Component method
    -------------------------------------------------------------------------
 */

Bool
    demo_client_config_tcp_nodelay (
    demo_client_config_t * self         //  Reference to self
)
{
    Bool
        tcp_nodelay;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TCP_NODELAY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_tcp_nodelay_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, demo_client_config_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TCP_NODELAY))
    icl_stats_inc ("demo_client_config_tcp_nodelay", &s_demo_client_config_tcp_nodelay_stats);
#endif

//
if (self)
    tcp_nodelay = self->tcp_nodelay;
else
    tcp_nodelay = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_NODELAY))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TCP_NODELAY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_tcp_nodelay_finish"
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
    demo_client_config_set_tcp_rcvbuf

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_tcp_rcvbuf (
    demo_client_config_t * self,        //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_tcp_rcvbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, demo_client_config_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF))
    icl_stats_inc ("demo_client_config_set_tcp_rcvbuf", &s_demo_client_config_set_tcp_rcvbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_rcvbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_rcvbuf", strvalue);
self->tcp_rcvbuf = tcp_rcvbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_tcp_rcvbuf_finish"
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
    demo_client_config_tcp_rcvbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_tcp_rcvbuf (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        tcp_rcvbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TCP_RCVBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_tcp_rcvbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, demo_client_config_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TCP_RCVBUF))
    icl_stats_inc ("demo_client_config_tcp_rcvbuf", &s_demo_client_config_tcp_rcvbuf_stats);
#endif

//
if (self)
    tcp_rcvbuf = self->tcp_rcvbuf;
else
    tcp_rcvbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_RCVBUF))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TCP_RCVBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_tcp_rcvbuf_finish"
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
    demo_client_config_set_tcp_sndbuf

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_tcp_sndbuf (
    demo_client_config_t * self,        //  Reference to object
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_tcp_sndbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, demo_client_config_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF))
    icl_stats_inc ("demo_client_config_set_tcp_sndbuf", &s_demo_client_config_set_tcp_sndbuf_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", tcp_sndbuf);
ipr_config_putp (self->config, "/config/tuning", "tcp_sndbuf", strvalue);
self->tcp_sndbuf = tcp_sndbuf;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_tcp_sndbuf_finish"
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
    demo_client_config_tcp_sndbuf

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_tcp_sndbuf (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        tcp_sndbuf;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TCP_SNDBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_tcp_sndbuf_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, demo_client_config_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TCP_SNDBUF))
    icl_stats_inc ("demo_client_config_tcp_sndbuf", &s_demo_client_config_tcp_sndbuf_stats);
#endif

//
if (self)
    tcp_sndbuf = self->tcp_sndbuf;
else
    tcp_sndbuf = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_SNDBUF))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TCP_SNDBUF))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_tcp_sndbuf_finish"
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
    demo_client_config_set_high_water

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_high_water (
    demo_client_config_t * self,        //  Reference to object
    int high_water                      //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_HIGH_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_high_water_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" high_water=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, high_water);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_HIGH_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_HIGH_WATER))
    icl_stats_inc ("demo_client_config_set_high_water", &s_demo_client_config_set_high_water_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", high_water);
ipr_config_putp (self->config, "/config/tuning", "high_water", strvalue);
self->high_water = high_water;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_HIGH_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_HIGH_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_high_water_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" high_water=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, high_water, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_high_water

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_high_water (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        high_water;                     //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_HIGH_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_high_water_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_HIGH_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_HIGH_WATER))
    icl_stats_inc ("demo_client_config_high_water", &s_demo_client_config_high_water_stats);
#endif

//
if (self)
    high_water = self->high_water;
else
    high_water = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_HIGH_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_HIGH_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_high_water_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" high_water=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, high_water);
#endif


    return (high_water);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_low_water

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_low_water (
    demo_client_config_t * self,        //  Reference to object
    int low_water                       //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_LOW_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_low_water_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" low_water=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, low_water);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_LOW_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_LOW_WATER))
    icl_stats_inc ("demo_client_config_set_low_water", &s_demo_client_config_set_low_water_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", low_water);
ipr_config_putp (self->config, "/config/tuning", "low_water", strvalue);
self->low_water = low_water;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_LOW_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_LOW_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_low_water_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" low_water=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, low_water, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_low_water

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_low_water (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        low_water;                      //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_LOW_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_low_water_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOW_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_LOW_WATER))
    icl_stats_inc ("demo_client_config_low_water", &s_demo_client_config_low_water_stats);
#endif

//
if (self)
    low_water = self->low_water;
else
    low_water = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOW_WATER))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_LOW_WATER))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_low_water_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" low_water=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, low_water);
#endif


    return (low_water);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_direct

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_direct (
    demo_client_config_t * self,        //  Reference to object
    int direct                          //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_DIRECT))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_direct_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_DIRECT))
    icl_trace_record (NULL, demo_client_config_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_DIRECT))
    icl_stats_inc ("demo_client_config_set_direct", &s_demo_client_config_set_direct_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", direct);
ipr_config_putp (self->config, "/config/tuning", "direct", strvalue);
self->direct = direct;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_DIRECT))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_DIRECT))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_direct_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_direct

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_direct (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        direct;                         //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DIRECT))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_direct_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DIRECT))
    icl_trace_record (NULL, demo_client_config_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DIRECT))
    icl_stats_inc ("demo_client_config_direct", &s_demo_client_config_direct_stats);
#endif

//
if (self)
    direct = self->direct;
else
    direct = 0;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DIRECT))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DIRECT))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_direct_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" direct=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, direct);
#endif


    return (direct);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_batching

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_batching (
    demo_client_config_t * self,        //  Reference to object
    int batching                        //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_BATCHING))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_batching_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" batching=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, batching);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_BATCHING))
    icl_trace_record (NULL, demo_client_config_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_BATCHING))
    icl_stats_inc ("demo_client_config_set_batching", &s_demo_client_config_set_batching_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
if (batching > 2097152) {
    icl_console_print ("W: <command line>: illegal value %d for batching, using %d",
        batching, 2097152);
    batching = 2097152;
}
icl_shortstr_fmt (strvalue, "%i", batching);
ipr_config_putp (self->config, "/config/direct", "batching", strvalue);
self->batching = batching;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_BATCHING))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_BATCHING))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_batching_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" batching=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, batching, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_batching

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_batching (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        batching;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_BATCHING))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_batching_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_BATCHING))
    icl_trace_record (NULL, demo_client_config_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_BATCHING))
    icl_stats_inc ("demo_client_config_batching", &s_demo_client_config_batching_stats);
#endif

//
if (self)
    batching = self->batching;
else
    batching = 32768;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_BATCHING))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_BATCHING))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_batching_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" batching=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, batching);
#endif


    return (batching);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_on_overflow

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_on_overflow (
    demo_client_config_t * self,        //  Reference to object
    char * on_overflow                  //  Not documented
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_on_overflow_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" on_overflow=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, on_overflow);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW))
    icl_trace_record (NULL, demo_client_config_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW))
    icl_stats_inc ("demo_client_config_set_on_overflow", &s_demo_client_config_set_on_overflow_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

ipr_config_putp (self->config, "/config/direct", "on_overflow", on_overflow);
on_overflow = ipr_config_getp (self->config, "/config/direct", "on_overflow", NULL);
assert (on_overflow);
self->on_overflow = on_overflow;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_on_overflow_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" on_overflow=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, on_overflow, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_on_overflow

    Type: Component method
    -------------------------------------------------------------------------
 */

char *
    demo_client_config_on_overflow (
    demo_client_config_t * self         //  Reference to self
)
{
    char *
        on_overflow;                    //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_ON_OVERFLOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_on_overflow_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ON_OVERFLOW))
    icl_trace_record (NULL, demo_client_config_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_ON_OVERFLOW))
    icl_stats_inc ("demo_client_config_on_overflow", &s_demo_client_config_on_overflow_stats);
#endif

//
if (self)
    on_overflow = self->on_overflow;
else
    on_overflow = "trim";
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ON_OVERFLOW))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_ON_OVERFLOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_on_overflow_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" on_overflow=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, on_overflow);
#endif


    return (on_overflow);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_chrono_enabled

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_chrono_enabled (
    demo_client_config_t * self,        //  Reference to object
    int chrono_enabled                  //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_enabled_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_enabled);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED))
    icl_trace_record (NULL, demo_client_config_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED))
    icl_stats_inc ("demo_client_config_set_chrono_enabled", &s_demo_client_config_set_chrono_enabled_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_enabled);
ipr_config_putp (self->config, "/config/chrono", "enabled", strvalue);
self->chrono_enabled = chrono_enabled;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_enabled_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_enabled=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_enabled, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_chrono_enabled

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_chrono_enabled (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        chrono_enabled;                 //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_ENABLED))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_enabled_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_ENABLED))
    icl_trace_record (NULL, demo_client_config_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_ENABLED))
    icl_stats_inc ("demo_client_config_chrono_enabled", &s_demo_client_config_chrono_enabled_stats);
#endif

//
if (self)
    chrono_enabled = self->chrono_enabled;
else
    chrono_enabled = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_ENABLED))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_ENABLED))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_enabled_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_enabled=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_enabled);
#endif


    return (chrono_enabled);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_chrono_floor

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_chrono_floor (
    demo_client_config_t * self,        //  Reference to object
    int chrono_floor                    //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_floor_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_floor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_floor);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR))
    icl_trace_record (NULL, demo_client_config_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR))
    icl_stats_inc ("demo_client_config_set_chrono_floor", &s_demo_client_config_set_chrono_floor_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_floor);
ipr_config_putp (self->config, "/config/chrono", "floor", strvalue);
self->chrono_floor = chrono_floor;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_floor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_floor=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_floor, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_chrono_floor

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_chrono_floor (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        chrono_floor;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_FLOOR))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_floor_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_FLOOR))
    icl_trace_record (NULL, demo_client_config_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_FLOOR))
    icl_stats_inc ("demo_client_config_chrono_floor", &s_demo_client_config_chrono_floor_stats);
#endif

//
if (self)
    chrono_floor = self->chrono_floor;
else
    chrono_floor = 100;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_FLOOR))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_FLOOR))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_floor_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_floor=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_floor);
#endif


    return (chrono_floor);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_chrono_density

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_chrono_density (
    demo_client_config_t * self,        //  Reference to object
    int chrono_density                  //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_density_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_density=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_density);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY))
    icl_trace_record (NULL, demo_client_config_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY))
    icl_stats_inc ("demo_client_config_set_chrono_density", &s_demo_client_config_set_chrono_density_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_density);
ipr_config_putp (self->config, "/config/chrono", "density", strvalue);
self->chrono_density = chrono_density;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_density_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_density=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_density, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_chrono_density

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_chrono_density (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        chrono_density;                 //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_DENSITY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_density_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_DENSITY))
    icl_trace_record (NULL, demo_client_config_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_DENSITY))
    icl_stats_inc ("demo_client_config_chrono_density", &s_demo_client_config_chrono_density_stats);
#endif

//
if (self)
    chrono_density = self->chrono_density;
else
    chrono_density = 1;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_DENSITY))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_DENSITY))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_density_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_density=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_density);
#endif


    return (chrono_density);
}
/*  -------------------------------------------------------------------------
    demo_client_config_set_chrono_batch

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_set_chrono_batch (
    demo_client_config_t * self,        //  Reference to object
    int chrono_batch                    //  Not documented
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

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_batch_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_batch=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_batch);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH))
    icl_trace_record (NULL, demo_client_config_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH))
    icl_stats_inc ("demo_client_config_set_chrono_batch", &s_demo_client_config_set_chrono_batch_stats);
#endif

#if (defined (BASE_THREADSAFE))
    rwlock = self ? self->rwlock : NULL;
    if (rwlock)
        icl_rwlock_write_lock (rwlock);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

//
icl_shortstr_fmt (strvalue, "%i", chrono_batch);
ipr_config_putp (self->config, "/config/chrono", "batch", strvalue);
self->chrono_batch = chrono_batch;

#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_set_chrono_batch_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_batch=\"%i\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_batch, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    demo_client_config_chrono_batch

    Type: Component method
    -------------------------------------------------------------------------
 */

int
    demo_client_config_chrono_batch (
    demo_client_config_t * self         //  Reference to self
)
{
    int
        chrono_batch;                   //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_BATCH))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_batch_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_BATCH))
    icl_trace_record (NULL, demo_client_config_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CHRONO_BATCH))
    icl_stats_inc ("demo_client_config_chrono_batch", &s_demo_client_config_chrono_batch_stats);
#endif

//
if (self)
    chrono_batch = self->chrono_batch;
else
    chrono_batch = 150;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_BATCH))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CHRONO_BATCH))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_chrono_batch_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" chrono_batch=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, chrono_batch);
#endif


    return (chrono_batch);
}
/*  -------------------------------------------------------------------------
    demo_client_config_dump_log

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    Dump current option values to an smt_log file.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_dump_log (
    demo_client_config_t * self,        //  Reference to object
    smt_log_t * logfile                 //  Log file to dump to
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DUMP_LOG))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_dump_log_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, demo_client_config_dump, 35);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DUMP_LOG))
    icl_stats_inc ("demo_client_config_dump_log", &s_demo_client_config_dump_log_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

smt_log_print (logfile, "*******************  Configuration Settings  ********************");
smt_log_print (logfile, "tcp_nodelay=%i", self->tcp_nodelay);
smt_log_print (logfile, "tcp_rcvbuf=%i", self->tcp_rcvbuf);
smt_log_print (logfile, "tcp_sndbuf=%i", self->tcp_sndbuf);
smt_log_print (logfile, "high_water=%i", self->high_water);
smt_log_print (logfile, "low_water=%i", self->low_water);
smt_log_print (logfile, "direct=%i", self->direct);
smt_log_print (logfile, "batching=%i", self->batching);
smt_log_print (logfile, "on_overflow=%s", self->on_overflow);
smt_log_print (logfile, "chrono_enabled=%i", self->chrono_enabled);
smt_log_print (logfile, "chrono_floor=%i", self->chrono_floor);
smt_log_print (logfile, "chrono_density=%i", self->chrono_density);
smt_log_print (logfile, "chrono_batch=%i", self->chrono_batch);
smt_log_print (logfile, "");

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DUMP_LOG))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 35);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DUMP_LOG))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_dump_log_finish"
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
    demo_client_config_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_config_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SELFTEST))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SELFTEST))
    icl_trace_record (NULL, demo_client_config_dump, 36);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SELFTEST))
    icl_stats_inc ("demo_client_config_selftest", &s_demo_client_config_selftest_stats);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SELFTEST))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 36);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SELFTEST))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_selftest_finish"
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
    demo_client_config_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_config_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TERMINATE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TERMINATE))
    icl_trace_record (NULL, demo_client_config_dump, 37);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_TERMINATE))
    icl_stats_inc ("demo_client_config_terminate", &s_demo_client_config_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TERMINATE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 37);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_TERMINATE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_terminate_finish"
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
    demo_client_config_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_config_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
demo_client_config_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SHOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW))
    icl_trace_record (NULL, demo_client_config_dump, 38);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SHOW))
    icl_stats_inc ("demo_client_config_show", &s_demo_client_config_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <demo_client_config file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 38);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SHOW))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_show_finish"
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
    demo_client_config_destroy

    Type: Component method
    Destroys a demo_client_config_t object. Takes the address of a
    demo_client_config_t reference (a pointer to a pointer) and nullifies the
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
    demo_client_config_destroy_ (
    demo_client_config_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    demo_client_config_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_client_config_dump, 39);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC))
    icl_stats_inc ("demo_client_config_destroy", &s_demo_client_config_destroy_stats);
#endif

if (self) {
    demo_client_config_annihilate (self_p);
    demo_client_config_free ((demo_client_config_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 39);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_destroy_public_finish"
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
    demo_client_config_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static demo_client_config_t *
    demo_client_config_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    demo_client_config_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_ALLOC))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ALLOC))
    icl_trace_record (NULL, demo_client_config_dump, 40);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_ALLOC))
    icl_stats_inc ("demo_client_config_alloc", &s_demo_client_config_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    demo_client_config_cache_initialise ();

self = (demo_client_config_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (demo_client_config_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ALLOC))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 40);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_ALLOC))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_alloc_finish"
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
    demo_client_config_free

    Type: Component method
    Freess a demo_client_config_t object.
    -------------------------------------------------------------------------
 */

static void
    demo_client_config_free (
    demo_client_config_t * self         //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_FREE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_FREE))
    icl_trace_record (NULL, demo_client_config_dump, 41);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_FREE))
    icl_stats_inc ("demo_client_config_free", &s_demo_client_config_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (demo_client_config_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (demo_client_config_t));
        self->object_tag = DEMO_CLIENT_CONFIG_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_FREE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 41);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_FREE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_free_finish"
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
    demo_client_config_read_lock

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_read_lock (
    demo_client_config_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_READ_LOCK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_READ_LOCK))
    icl_trace_record (NULL, demo_client_config_dump, 42);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_READ_LOCK))
    icl_stats_inc ("demo_client_config_read_lock", &s_demo_client_config_read_lock_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_READ_LOCK))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 42);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_READ_LOCK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_read_lock_finish"
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
    demo_client_config_write_lock

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_write_lock (
    demo_client_config_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_WRITE_LOCK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, demo_client_config_dump, 43);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_WRITE_LOCK))
    icl_stats_inc ("demo_client_config_write_lock", &s_demo_client_config_write_lock_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_WRITE_LOCK))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 43);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_WRITE_LOCK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_write_lock_finish"
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
    demo_client_config_unlock

    Type: Component method
    Accepts a demo_client_config_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    demo_client_config_unlock (
    demo_client_config_t * self         //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_UNLOCK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_UNLOCK))
    icl_trace_record (NULL, demo_client_config_dump, 44);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_UNLOCK))
    icl_stats_inc ("demo_client_config_unlock", &s_demo_client_config_unlock_stats);
#endif

DEMO_CLIENT_CONFIG_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_UNLOCK))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 44);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_UNLOCK))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_unlock_finish"
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
    demo_client_config_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    demo_client_config_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CACHE_INITIALISE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_client_config_dump, 45);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CACHE_INITIALISE))
    icl_stats_inc ("demo_client_config_cache_initialise", &s_demo_client_config_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (demo_client_config_t));
icl_system_register (demo_client_config_cache_purge, demo_client_config_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_INITIALISE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 45);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CACHE_INITIALISE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cache_initialise_finish"
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
    demo_client_config_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_config_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CACHE_PURGE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, demo_client_config_dump, 46);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CACHE_PURGE))
    icl_stats_inc ("demo_client_config_cache_purge", &s_demo_client_config_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_PURGE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 46);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CACHE_PURGE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cache_purge_finish"
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
    demo_client_config_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    demo_client_config_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CACHE_TERMINATE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_client_config_dump, 47);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_CACHE_TERMINATE))
    icl_stats_inc ("demo_client_config_cache_terminate", &s_demo_client_config_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_TERMINATE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 47);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_CACHE_TERMINATE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_cache_terminate_finish"
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
    demo_client_config_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_client_config_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SHOW_ANIMATION))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_client_config_dump, 48);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_SHOW_ANIMATION))
    icl_stats_inc ("demo_client_config_show_animation", &s_demo_client_config_show_animation_stats);
#endif

demo_client_config_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 48);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_SHOW_ANIMATION))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_show_animation_finish"
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
    demo_client_config_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_client_config_new_in_scope_ (
    demo_client_config_t * * self_p,    //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)  ||  defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_client_config_dump, 49);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG)  ||  defined (BASE_STATS_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE))
    icl_stats_inc ("demo_client_config_new_in_scope", &s_demo_client_config_new_in_scope_stats);
#endif

*self_p = demo_client_config_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) demo_client_config_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE))
    icl_trace_record (NULL, demo_client_config_dump, 0x10000 + 49);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG)   || defined (BASE_ANIMATE_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE))
    if (demo_client_config_animating)
        icl_console_print ("<demo_client_config_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_XMLFILE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOAD_BUCKET)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHADOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_COMMIT)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ROLLBACK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_HELP)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CMDLINE_PARSE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_OPTIONS_HELP)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_NODELAY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_NODELAY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_RCVBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_RCVBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_TCP_SNDBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TCP_SNDBUF)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_HIGH_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_HIGH_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_LOW_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_LOW_WATER)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_DIRECT)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DIRECT)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_BATCHING)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_BATCHING)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_ON_OVERFLOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ON_OVERFLOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_ENABLED)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_ENABLED)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_FLOOR)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_FLOOR)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_DENSITY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_DENSITY)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SET_CHRONO_BATCH)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CHRONO_BATCH)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DUMP_LOG)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SELFTEST)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_DESTROY_PUBLIC)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_ALLOC)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_FREE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_READ_LOCK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_WRITE_LOCK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_UNLOCK)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_INITIALISE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_PURGE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_CACHE_TERMINATE)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_SHOW_ANIMATION)   || defined (BASE_TRACE_DEMO_CLIENT_CONFIG_NEW_IN_SCOPE) )
void
demo_client_config_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
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
        case 11: method_name = "set tcp_nodelay"; break;
        case 12: method_name = "tcp_nodelay"; break;
        case 13: method_name = "set tcp_rcvbuf"; break;
        case 14: method_name = "tcp_rcvbuf"; break;
        case 15: method_name = "set tcp_sndbuf"; break;
        case 16: method_name = "tcp_sndbuf"; break;
        case 17: method_name = "set high_water"; break;
        case 18: method_name = "high_water"; break;
        case 19: method_name = "set low_water"; break;
        case 20: method_name = "low_water"; break;
        case 21: method_name = "set direct"; break;
        case 22: method_name = "direct"; break;
        case 23: method_name = "set batching"; break;
        case 24: method_name = "batching"; break;
        case 25: method_name = "set on_overflow"; break;
        case 26: method_name = "on_overflow"; break;
        case 27: method_name = "set chrono_enabled"; break;
        case 28: method_name = "chrono_enabled"; break;
        case 29: method_name = "set chrono_floor"; break;
        case 30: method_name = "chrono_floor"; break;
        case 31: method_name = "set chrono_density"; break;
        case 32: method_name = "chrono_density"; break;
        case 33: method_name = "set chrono_batch"; break;
        case 34: method_name = "chrono_batch"; break;
        case 35: method_name = "dump log"; break;
        case 36: method_name = "selftest"; break;
        case 37: method_name = "terminate"; break;
        case 38: method_name = "show"; break;
        case 39: method_name = "destroy public"; break;
        case 40: method_name = "alloc"; break;
        case 41: method_name = "free"; break;
        case 42: method_name = "read lock"; break;
        case 43: method_name = "write lock"; break;
        case 44: method_name = "unlock"; break;
        case 45: method_name = "cache initialise"; break;
        case 46: method_name = "cache purge"; break;
        case 47: method_name = "cache terminate"; break;
        case 48: method_name = "show animation"; break;
        case 49: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_client_config %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_client_config_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_client_config_component  = "demo_client_config ";
char *demo_client_config_version   = "1.0 ";
char *demo_client_config_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_client_config_filename  = "demo_client_config.icl ";
char *demo_client_config_builddate  = "2009/02/19 ";
char *demo_client_config_version_end  = "VeRsIoNeNd:ipc";

