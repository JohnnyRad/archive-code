/*---------------------------------------------------------------------------
    icl_trace.c - icl_trace component

    Class to enable trace of program behaviour.
    To trace any program operation, call the trace method during operation.
    The trace is replayed via the dump method.
    Generated from icl_trace.icl by icl_gen using GSL/4.
    
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
#include "icl_trace.h"                  //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_trace_t

//  Shorthands for class methods                                               

#define self_new            icl_trace_new
#define self_annihilate     icl_trace_annihilate
#define self_record         icl_trace_record
#define self_dump           icl_trace_dump
#define self_terminate      icl_trace_terminate
#define self_selftest       icl_trace_selftest
#define self_show           icl_trace_show
#define self_destroy        icl_trace_destroy
#define self_alloc          icl_trace_alloc
#define self_free           icl_trace_free
#define self_show_animation  icl_trace_show_animation
#define self_new_in_scope   icl_trace_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_NEW))
static icl_stats_t *s_icl_trace_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_DESTROY))
static icl_stats_t *s_icl_trace_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_RECORD))
       icl_stats_t *s_icl_trace_record_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_DUMP))
static icl_stats_t *s_icl_trace_dump_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_TERMINATE))
static icl_stats_t *s_icl_trace_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_SELFTEST))
static icl_stats_t *s_icl_trace_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_SHOW))
static icl_stats_t *s_icl_trace_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_DESTROY_PUBLIC))
static icl_stats_t *s_icl_trace_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_ALLOC))
static icl_stats_t *s_icl_trace_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_FREE))
static icl_stats_t *s_icl_trace_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_SHOW_ANIMATION))
static icl_stats_t *s_icl_trace_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_NEW_IN_SCOPE))
static icl_stats_t *s_icl_trace_new_in_scope_stats = NULL;
#endif
static void
    icl_trace_annihilate (
icl_trace_t * ( * self_p )              //  Reference to object reference
);

#define icl_trace_alloc()               icl_trace_alloc_ (__FILE__, __LINE__)
static icl_trace_t *
    icl_trace_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_trace_free (
icl_trace_t * self                      //  Object reference
);

Bool
    icl_trace_animating = TRUE;         //  Animation enabled by default

//  Types

icl_trace_t
    *s_icl_trace = NULL;
/*  -------------------------------------------------------------------------
    icl_trace_new

    Type: Component method
    Creates and initialises a new icl_trace_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_trace_t *
    icl_trace_new_ (
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    uint size                           //  Size for this trace
)
{
uint
    idx;
    icl_trace_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_NEW))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_new_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, size);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_NEW))
    icl_stats_inc ("icl_trace_new", &s_icl_trace_new_stats);
#endif

self = icl_trace_alloc_ (file, line);
if (self) {
    self->object_tag   = ICL_TRACE_ALIVE;

    self->array = malloc (size * sizeof (icl_trace_item_t));
    self->size  = size;
    self->idx   = 0;

    for (idx = 0; idx < size; idx++) {
        self->array [idx].dump   = NULL;
#if (defined (BASE_THREADSAFE))
        self->array [idx].thread = 0;
#endif
        self->array [idx].info   = 0;
    }
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_NEW))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_new_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" file=\"%s\""
" line=\"%u\""
" size=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, file, line, size, self);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    icl_trace_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_trace_annihilate (
    icl_trace_t * ( * self_p )          //  Reference to object reference
)
{

    icl_trace_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_DESTROY))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_destroy_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_DESTROY))
    icl_stats_inc ("icl_trace_annihilate", &s_icl_trace_annihilate_stats);
#endif

ICL_TRACE_ASSERT_SANE (self);

free (self->array);

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_DESTROY))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_destroy_finish"
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
    icl_trace_dump

    Type: Component method
    This method dumps the dumped animation trace to the console.
    -------------------------------------------------------------------------
 */

void
    icl_trace_dump (
    icl_trace_t * self                  //  The trace structure
)
{
uint
    trace_idx;
icl_trace_item_t
    *trace;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_DUMP))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_dump_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_DUMP))
    icl_stats_inc ("icl_trace_dump", &s_icl_trace_dump_stats);
#endif

    if (self == NULL)
        self = s_icl_trace;

    if (self) {
        icl_console_mode (ICL_CONSOLE_DATE,   FALSE);
        icl_console_mode (ICL_CONSOLE_TIME,   TRUE);
        icl_console_mode (ICL_CONSOLE_MICRO,  TRUE);
        icl_console_mode (ICL_CONSOLE_THREAD, TRUE);
        icl_console_print ("--------------------  START OF TRACE  ---------------------");
        trace_idx = (self->idx + 1) % self->size;
        while (trace_idx != self->idx % self->size) {
            trace = &self->array [trace_idx];
            if (trace->dump)
#if (defined (BASE_THREADSAFE))
                (trace->dump) (
                    trace->thread, trace->time, trace->info);
#else
                (trace->dump) (
                    0, trace->time, trace->info);
#endif
            trace_idx = (trace_idx + 1) % self->size;
        }
        icl_console_print ("----------------------  END OF TRACE  ---------------------");
    }
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_DUMP))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_dump_finish"
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
    icl_trace_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_trace_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_TERMINATE))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_TERMINATE))
    icl_stats_inc ("icl_trace_terminate", &s_icl_trace_terminate_stats);
#endif


icl_trace_destroy (&s_icl_trace);
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_TERMINATE))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_terminate_finish"
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
    icl_trace_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_trace_selftest (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_SELFTEST))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_SELFTEST))
    icl_stats_inc ("icl_trace_selftest", &s_icl_trace_selftest_stats);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_SELFTEST))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_selftest_finish"
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
    icl_trace_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_trace_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
icl_trace_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_SHOW))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_show_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_SHOW))
    icl_stats_inc ("icl_trace_show", &s_icl_trace_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <icl_trace file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_SHOW))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_show_finish"
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
    icl_trace_destroy

    Type: Component method
    Destroys a icl_trace_t object. Takes the address of a
    icl_trace_t reference (a pointer to a pointer) and nullifies the
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
    icl_trace_destroy_ (
    icl_trace_t * ( * self_p ),         //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_trace_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_DESTROY_PUBLIC))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_destroy_public_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_DESTROY_PUBLIC))
    icl_stats_inc ("icl_trace_destroy", &s_icl_trace_destroy_stats);
#endif

if (self) {
    icl_trace_annihilate (self_p);
    icl_trace_free ((icl_trace_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_DESTROY_PUBLIC))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_destroy_public_finish"
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
    icl_trace_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_trace_t *
    icl_trace_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_trace_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_ALLOC))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_alloc_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_ALLOC))
    icl_stats_inc ("icl_trace_alloc", &s_icl_trace_alloc_stats);
#endif

self = (icl_trace_t *) malloc (sizeof (icl_trace_t));
if (self)
    memset (self, 0, sizeof (icl_trace_t));


#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_ALLOC))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_alloc_finish"
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
    icl_trace_free

    Type: Component method
    Freess a icl_trace_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_trace_free (
    icl_trace_t * self                  //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_FREE))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_free_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_FREE))
    icl_stats_inc ("icl_trace_free", &s_icl_trace_free_stats);
#endif

if (self) {

        memset (&self->object_tag, 0, sizeof (icl_trace_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_trace_t));
        self->object_tag = ICL_TRACE_DEAD;
        free (self);
    }
    self = NULL;
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_FREE))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_free_finish"
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
    icl_trace_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_trace_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_SHOW_ANIMATION))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_show_animation_start"
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

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_SHOW_ANIMATION))
    icl_stats_inc ("icl_trace_show_animation", &s_icl_trace_show_animation_stats);
#endif

icl_trace_animating = enabled;
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_SHOW_ANIMATION))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_show_animation_finish"
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
    icl_trace_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_trace_new_in_scope_ (
    icl_trace_t * * self_p,             //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line,                        //  Line number for call
    uint size                           //  Size for this trace
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_TRACE)  ||  defined (BASE_ANIMATE_ICL_TRACE_NEW_IN_SCOPE))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_new_in_scope_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, size);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_TRACE)  ||  defined (BASE_STATS_ICL_TRACE_NEW_IN_SCOPE))
    icl_stats_inc ("icl_trace_new_in_scope", &s_icl_trace_new_in_scope_stats);
#endif

*self_p = icl_trace_new_ (file,line,size);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_trace_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_TRACE)   || defined (BASE_ANIMATE_ICL_TRACE_NEW_IN_SCOPE))
    if (icl_trace_animating)
        icl_console_print ("<icl_trace_new_in_scope_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self_p=\"%pp\""
" _scope=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" size=\"%u\""
" _destroy=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self_p, _scope, file, line, size, _destroy);
#endif

}
//  Embed the version information in the resulting binary                      

char *icl_trace_version_start      = "VeRsIoNsTaRt:ipc";
char *icl_trace_component          = "icl_trace ";
char *icl_trace_version            = "1.1 ";
char *icl_trace_copyright          = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_trace_filename           = "icl_trace.icl ";
char *icl_trace_builddate          = "2009/02/19 ";
char *icl_trace_version_end        = "VeRsIoNeNd:ipc";

