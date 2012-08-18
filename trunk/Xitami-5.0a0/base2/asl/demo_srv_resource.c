/*---------------------------------------------------------------------------
    demo_srv_resource.c - demo_srv_resource component

    Provides compiled resources, i.e. external files that are shipped with
    the application.
    Generated from demo_srv_resource.icl by icl_gen using GSL/4.
    
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
#include "demo_srv_resource.h"          //  Definitions for our class

//  Shorthands for class methods                                               

#define self_get            demo_srv_resource_get
#define self_selftest       demo_srv_resource_selftest
#define self_show_animation  demo_srv_resource_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE_GET))
static icl_stats_t *s_demo_srv_resource_get_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE_SELFTEST))
static icl_stats_t *s_demo_srv_resource_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE_SHOW_ANIMATION))
static icl_stats_t *s_demo_srv_resource_show_animation_stats = NULL;
#endif
Bool
    demo_srv_resource_animating = TRUE;  //  Animation enabled by default
typedef struct {
    qbyte size;
    byte  data [1];
} demo_srv_resource_resource_t;
static struct {
    qbyte size;
    byte  data [587];
} res_demo_srv_base_cfg = {
    587,
    {
      0x3c, 0x3f, 0x78, 0x6d, 0x6c, 0x3f, 0x3e, 0x0a, 0x3c, 0x21, 0x2d, 0x2d, 
      0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 
      0x73, 0x20, 0x74, 0x68, 0x65, 0x20, 0x62, 0x61, 0x73, 0x65, 0x20, 0x63, 
      0x6f, 0x6e, 0x66, 0x69, 0x67, 0x75, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 
      0x20, 0x66, 0x69, 0x6c, 0x65, 0x2c, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 
      0x64, 0x65, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x20, 0x76, 0x61, 0x6c, 0x75, 
      0x65, 0x73, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x6c, 0x6c, 0x20, 0x73, 
      0x65, 0x74, 0x74, 0x69, 0x6e, 0x67, 0x73, 0x20, 0x0a, 0x20, 0x20, 0x20, 
      0x20, 0x44, 0x6f, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x65, 0x64, 0x69, 0x74, 
      0x20, 0x74, 0x68, 0x69, 0x73, 0x20, 0x66, 0x69, 0x6c, 0x65, 0x2c, 0x20, 
      0x73, 0x69, 0x6e, 0x63, 0x65, 0x20, 0x69, 0x74, 0x20, 0x69, 0x73, 0x20, 
      0x72, 0x65, 0x70, 0x6c, 0x61, 0x63, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 
      0x68, 0x20, 0x65, 0x61, 0x63, 0x68, 0x20, 0x6e, 0x65, 0x77, 0x20, 0x72, 
      0x65, 0x6c, 0x65, 0x61, 0x73, 0x65, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 
      0x65, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x73, 0x6f, 0x66, 0x74, 0x77, 0x61, 
      0x72, 0x65, 0x2e, 0x20, 0x20, 0x43, 0x72, 0x65, 0x61, 0x74, 0x65, 0x20, 
      0x79, 0x6f, 0x75, 0x72, 0x20, 0x6f, 0x77, 0x6e, 0x20, 0x66, 0x69, 0x6c, 
      0x65, 0x2c, 0x20, 0x64, 0x65, 0x6d, 0x6f, 0x5f, 0x73, 0x72, 0x76, 0x2e, 
      0x63, 0x66, 0x67, 0x2c, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20, 0x74, 0x68, 
      0x65, 0x20, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6e, 0x67, 0x73, 0x20, 0x79, 
      0x6f, 0x75, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6e, 0x65, 0x65, 0x64, 0x2e, 
      0x20, 0x20, 0x53, 0x65, 0x65, 0x20, 0x64, 0x65, 0x6d, 0x6f, 0x5f, 0x73, 
      0x72, 0x76, 0x5f, 0x65, 0x78, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x63, 
      0x66, 0x67, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x6e, 0x20, 0x65, 0x78, 
      0x61, 0x6d, 0x70, 0x6c, 0x65, 0x2e, 0x0a, 0x20, 0x20, 0x2d, 0x2d, 0x3e, 
      0x0a, 0x3c, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x3e, 0x0a, 0x20, 0x20, 
      0x20, 0x20, 0x3c, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x0a, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x70, 0x6f, 0x72, 0x74, 0x20, 0x3d, 
      0x20, 0x22, 0x37, 0x36, 0x35, 0x34, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x62, 0x61, 0x63, 0x6b, 0x67, 0x72, 0x6f, 0x75, 
      0x6e, 0x64, 0x20, 0x3d, 0x20, 0x22, 0x30, 0x22, 0x0a, 0x20, 0x20, 0x20, 
      0x20, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6e, 0x74, 0x65, 0x78, 0x74, 
      0x5f, 0x74, 0x69, 0x6d, 0x65, 0x6f, 0x75, 0x74, 0x20, 0x3d, 0x20, 0x22, 
      0x35, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 
      0x3e, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x72, 0x65, 0x73, 0x6f, 
      0x75, 0x72, 0x63, 0x65, 0x73, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
      0x20, 0x20, 0x6d, 0x61, 0x78, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 
      0x20, 0x3d, 0x20, 0x22, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
      0x30, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x6d, 
      0x6f, 0x6e, 0x69, 0x74, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x22, 0x30, 0x22, 
      0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x3e, 0x0a, 
      0x0a, 0x20, 0x20, 0x20, 0x20, 0x3c, 0x6c, 0x6f, 0x67, 0x67, 0x69, 0x6e, 
      0x67, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 
      0x72, 0x65, 0x63, 0x74, 0x6f, 0x72, 0x79, 0x20, 0x3d, 0x20, 0x22, 0x6c, 
      0x6f, 0x67, 0x73, 0x22, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 
      0x20, 0x63, 0x6f, 0x6e, 0x73, 0x6f, 0x6c, 0x65, 0x20, 0x3d, 0x20, 0x22, 
      0x63, 0x6f, 0x6e, 0x73, 0x6f, 0x6c, 0x65, 0x2e, 0x6c, 0x6f, 0x67, 0x22, 
      0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x3e, 0x0a, 
      0x0a, 0x3c, 0x2f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x3e, 0x0a
    }
};
static struct {
    char *filename;
    void *resource;
} demo_srv_resource_table [1] = {
    { "demo_srv_base.cfg", &res_demo_srv_base_cfg }
};
/*  -------------------------------------------------------------------------
    demo_srv_resource_get

    Type: Component method
    Returns specified resource file as a bucket of data or NULL if the
    resource file is not known.  Note that resources are limited in size
    to the maximum size of a bucket (IPR_BUCKET_MAX).
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    demo_srv_resource_get (
    char * filename                     //  Name of resource to find
)
{
demo_srv_resource_resource_t
    *resource;                      //  Found resource
uint
    index;                          //  Index into resource table
    ipr_bucket_t *
        bucket;                         //  Returned bucket

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SRV_RESOURCE)  ||  defined (BASE_ANIMATE_DEMO_SRV_RESOURCE_GET))
    if (demo_srv_resource_animating)
        icl_console_print ("<demo_srv_resource_get_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_GET))
    icl_trace_record (NULL, demo_srv_resource_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE_GET))
    icl_stats_inc ("demo_srv_resource_get", &s_demo_srv_resource_get_stats);
#endif

//
resource = NULL;
for (index = 0; index < tblsize (demo_srv_resource_table); index++) {
    if (streq (demo_srv_resource_table [index].filename, filename)) {
        resource = demo_srv_resource_table [index].resource;
        break;
    }
}
if (resource) {
    bucket = ipr_bucket_new (0);
    bucket->data = resource->data;
    bucket->cur_size = resource->size;
}
else
    bucket = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_GET))
    icl_trace_record (NULL, demo_srv_resource_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SRV_RESOURCE)   || defined (BASE_ANIMATE_DEMO_SRV_RESOURCE_GET))
    if (demo_srv_resource_animating)
        icl_console_print ("<demo_srv_resource_get_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" filename=\"%s\""
" bucket=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, filename, bucket);
#endif


    return (bucket);
}
/*  -------------------------------------------------------------------------
    demo_srv_resource_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    demo_srv_resource_selftest (
void)
{
ipr_bucket_t
    *bucket;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SRV_RESOURCE)  ||  defined (BASE_ANIMATE_DEMO_SRV_RESOURCE_SELFTEST))
    if (demo_srv_resource_animating)
        icl_console_print ("<demo_srv_resource_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_SELFTEST))
    icl_trace_record (NULL, demo_srv_resource_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE_SELFTEST))
    icl_stats_inc ("demo_srv_resource_selftest", &s_demo_srv_resource_selftest_stats);
#endif

//  Check we can find demo_srv_base.cfg
bucket = demo_srv_resource_get ("demo_srv_base.cfg");
assert (bucket);
ipr_bucket_destroy (&bucket);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_SELFTEST))
    icl_trace_record (NULL, demo_srv_resource_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SRV_RESOURCE)   || defined (BASE_ANIMATE_DEMO_SRV_RESOURCE_SELFTEST))
    if (demo_srv_resource_animating)
        icl_console_print ("<demo_srv_resource_selftest_finish"
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
    demo_srv_resource_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    demo_srv_resource_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_DEMO_SRV_RESOURCE)  ||  defined (BASE_ANIMATE_DEMO_SRV_RESOURCE_SHOW_ANIMATION))
    if (demo_srv_resource_animating)
        icl_console_print ("<demo_srv_resource_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_srv_resource_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE)  ||  defined (BASE_STATS_DEMO_SRV_RESOURCE_SHOW_ANIMATION))
    icl_stats_inc ("demo_srv_resource_show_animation", &s_demo_srv_resource_show_animation_stats);
#endif

demo_srv_resource_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_SHOW_ANIMATION))
    icl_trace_record (NULL, demo_srv_resource_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_DEMO_SRV_RESOURCE)   || defined (BASE_ANIMATE_DEMO_SRV_RESOURCE_SHOW_ANIMATION))
    if (demo_srv_resource_animating)
        icl_console_print ("<demo_srv_resource_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_GET)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_SELFTEST)   || defined (BASE_TRACE_DEMO_SRV_RESOURCE_SHOW_ANIMATION) )
void
demo_srv_resource_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "get"; break;
        case 2: method_name = "selftest"; break;
        case 3: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "demo_srv_resource %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *demo_srv_resource_version_start  = "VeRsIoNsTaRt:ipc";
char *demo_srv_resource_component  = "demo_srv_resource ";
char *demo_srv_resource_version    = "1.0 ";
char *demo_srv_resource_copyright  = "Copyright (c) 1996-2009 iMatix Corporation";
char *demo_srv_resource_filename   = "demo_srv_resource.icl ";
char *demo_srv_resource_builddate  = "2009/02/19 ";
char *demo_srv_resource_version_end  = "VeRsIoNeNd:ipc";

