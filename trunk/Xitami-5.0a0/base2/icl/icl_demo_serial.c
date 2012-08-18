/*---------------------------------------------------------------------------
    icl_demo_serial.c - icl_demo_serial component

    Generated from icl_demo_serial.icl by icl_gen using GSL/4.
    
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
#include "icl_demo_serial.h"            //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              icl_demo_serial_t

//  Shorthands for class methods                                               

#define self_selftest       icl_demo_serial_selftest
#define self_terminate      icl_demo_serial_terminate
#define self_new            icl_demo_serial_new
#define self_show           icl_demo_serial_show
#define self_destroy        icl_demo_serial_destroy
#define self_annihilate     icl_demo_serial_annihilate
#define self_alloc          icl_demo_serial_alloc
#define self_free           icl_demo_serial_free
#define self_read_lock      icl_demo_serial_read_lock
#define self_write_lock     icl_demo_serial_write_lock
#define self_unlock         icl_demo_serial_unlock
#define self_cache_initialise  icl_demo_serial_cache_initialise
#define self_cache_purge    icl_demo_serial_cache_purge
#define self_cache_terminate  icl_demo_serial_cache_terminate
#define self_show_animation  icl_demo_serial_show_animation
#define self_save           icl_demo_serial_save
#define self_load           icl_demo_serial_load
#define self_get_size       icl_demo_serial_get_size
#define self_new_in_scope   icl_demo_serial_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SELFTEST))
static icl_stats_t *s_icl_demo_serial_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_TERMINATE))
static icl_stats_t *s_icl_demo_serial_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_NEW))
static icl_stats_t *s_icl_demo_serial_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SHOW))
static icl_stats_t *s_icl_demo_serial_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_DESTROY_PUBLIC))
static icl_stats_t *s_icl_demo_serial_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_DESTROY))
static icl_stats_t *s_icl_demo_serial_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_ALLOC))
static icl_stats_t *s_icl_demo_serial_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_FREE))
static icl_stats_t *s_icl_demo_serial_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_READ_LOCK))
static icl_stats_t *s_icl_demo_serial_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_WRITE_LOCK))
static icl_stats_t *s_icl_demo_serial_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_UNLOCK))
static icl_stats_t *s_icl_demo_serial_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_CACHE_INITIALISE))
static icl_stats_t *s_icl_demo_serial_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_CACHE_PURGE))
static icl_stats_t *s_icl_demo_serial_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_CACHE_TERMINATE))
static icl_stats_t *s_icl_demo_serial_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SHOW_ANIMATION))
static icl_stats_t *s_icl_demo_serial_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SAVE))
static icl_stats_t *s_icl_demo_serial_save_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_LOAD))
static icl_stats_t *s_icl_demo_serial_load_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_GET_SIZE))
static icl_stats_t *s_icl_demo_serial_get_size_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_NEW_IN_SCOPE))
static icl_stats_t *s_icl_demo_serial_new_in_scope_stats = NULL;
#endif
static void
    icl_demo_serial_annihilate (
icl_demo_serial_t * ( * self_p )        //  Reference to object reference
);

#define icl_demo_serial_alloc()         icl_demo_serial_alloc_ (__FILE__, __LINE__)
static icl_demo_serial_t *
    icl_demo_serial_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    icl_demo_serial_free (
icl_demo_serial_t * self                //  Object reference
);

static void
    icl_demo_serial_cache_initialise (
void);

static void
    icl_demo_serial_cache_purge (
void);

static void
    icl_demo_serial_cache_terminate (
void);

Bool
    icl_demo_serial_animating = TRUE;   //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


#define ICL_DEMO_SERIAL_SIZE 14 + strlen (self->item_dest_name) + strlen (self->item_mime_type) + strlen (self->item_encoding) + (self->item_options? self->item_options->cur_size: 0)
/*  -------------------------------------------------------------------------
    icl_demo_serial_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_serial_selftest (
void)
{
icl_demo_serial_t
    *self;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SELFTEST))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SELFTEST))
    icl_trace_record (NULL, icl_demo_serial_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SELFTEST))
    icl_stats_inc ("icl_demo_serial_selftest", &s_icl_demo_serial_selftest_stats);
#endif

self = icl_demo_serial_new ();
self->size = icl_demo_serial_save (self, self->data, sizeof (self->data));
assert (self->size);
icl_demo_serial_load (self, self->data, self->size);
icl_demo_serial_destroy (&self);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SELFTEST))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SELFTEST))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_selftest_finish"
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
    icl_demo_serial_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_serial_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_TERMINATE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_TERMINATE))
    icl_trace_record (NULL, icl_demo_serial_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_TERMINATE))
    icl_stats_inc ("icl_demo_serial_terminate", &s_icl_demo_serial_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_TERMINATE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_TERMINATE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_terminate_finish"
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
    icl_demo_serial_new

    Type: Component method
    Creates and initialises a new icl_demo_serial_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

icl_demo_serial_t *
    icl_demo_serial_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_demo_serial_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_NEW))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_NEW))
    icl_trace_record (NULL, icl_demo_serial_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_NEW))
    icl_stats_inc ("icl_demo_serial_new", &s_icl_demo_serial_new_stats);
#endif

    self = icl_demo_serial_alloc_ (file, line);
    if (self) {
        self->object_tag   = ICL_DEMO_SERIAL_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, icl_demo_serial_show_);
#endif

}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_NEW))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_NEW))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_new_finish"
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
    icl_demo_serial_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_serial_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
icl_demo_serial_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SHOW))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SHOW))
    icl_trace_record (NULL, icl_demo_serial_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SHOW))
    icl_stats_inc ("icl_demo_serial_show", &s_icl_demo_serial_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <icl_demo_serial file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SHOW))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SHOW))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_show_finish"
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
    icl_demo_serial_destroy

    Type: Component method
    Destroys a icl_demo_serial_t object. Takes the address of a
    icl_demo_serial_t reference (a pointer to a pointer) and nullifies the
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
    icl_demo_serial_destroy_ (
    icl_demo_serial_t * ( * self_p ),   //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    icl_demo_serial_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_DESTROY_PUBLIC))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_serial_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_DESTROY_PUBLIC))
    icl_stats_inc ("icl_demo_serial_destroy", &s_icl_demo_serial_destroy_stats);
#endif

if (self) {
    icl_demo_serial_annihilate (self_p);
    icl_demo_serial_free ((icl_demo_serial_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_DESTROY_PUBLIC))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_DESTROY_PUBLIC))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_destroy_public_finish"
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
    icl_demo_serial_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_serial_annihilate (
    icl_demo_serial_t * ( * self_p )    //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    icl_demo_serial_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_DESTROY))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_DESTROY))
    icl_trace_record (NULL, icl_demo_serial_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_DESTROY))
    icl_stats_inc ("icl_demo_serial_annihilate", &s_icl_demo_serial_annihilate_stats);
#endif

    ICL_DEMO_SERIAL_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_longstr_destroy (&self->item_options);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_DESTROY))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_DESTROY))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_destroy_finish"
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
    icl_demo_serial_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static icl_demo_serial_t *
    icl_demo_serial_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    icl_demo_serial_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_ALLOC))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_ALLOC))
    icl_trace_record (NULL, icl_demo_serial_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_ALLOC))
    icl_stats_inc ("icl_demo_serial_alloc", &s_icl_demo_serial_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    icl_demo_serial_cache_initialise ();

self = (icl_demo_serial_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (icl_demo_serial_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_ALLOC))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_ALLOC))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_alloc_finish"
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
    icl_demo_serial_free

    Type: Component method
    Freess a icl_demo_serial_t object.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_serial_free (
    icl_demo_serial_t * self            //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_FREE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_FREE))
    icl_trace_record (NULL, icl_demo_serial_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_FREE))
    icl_stats_inc ("icl_demo_serial_free", &s_icl_demo_serial_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (icl_demo_serial_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (icl_demo_serial_t));
        self->object_tag = ICL_DEMO_SERIAL_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_FREE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_FREE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_free_finish"
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
    icl_demo_serial_read_lock

    Type: Component method
    Accepts a icl_demo_serial_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_serial_read_lock (
    icl_demo_serial_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_READ_LOCK))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_READ_LOCK))
    icl_trace_record (NULL, icl_demo_serial_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_READ_LOCK))
    icl_stats_inc ("icl_demo_serial_read_lock", &s_icl_demo_serial_read_lock_stats);
#endif

ICL_DEMO_SERIAL_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_READ_LOCK))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_READ_LOCK))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_read_lock_finish"
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
    icl_demo_serial_write_lock

    Type: Component method
    Accepts a icl_demo_serial_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_serial_write_lock (
    icl_demo_serial_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_WRITE_LOCK))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_WRITE_LOCK))
    icl_trace_record (NULL, icl_demo_serial_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_WRITE_LOCK))
    icl_stats_inc ("icl_demo_serial_write_lock", &s_icl_demo_serial_write_lock_stats);
#endif

ICL_DEMO_SERIAL_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_WRITE_LOCK))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_WRITE_LOCK))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_write_lock_finish"
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
    icl_demo_serial_unlock

    Type: Component method
    Accepts a icl_demo_serial_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    icl_demo_serial_unlock (
    icl_demo_serial_t * self            //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_UNLOCK))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_UNLOCK))
    icl_trace_record (NULL, icl_demo_serial_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_UNLOCK))
    icl_stats_inc ("icl_demo_serial_unlock", &s_icl_demo_serial_unlock_stats);
#endif

ICL_DEMO_SERIAL_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_UNLOCK))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_UNLOCK))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_unlock_finish"
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
    icl_demo_serial_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    icl_demo_serial_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_CACHE_INITIALISE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_demo_serial_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_CACHE_INITIALISE))
    icl_stats_inc ("icl_demo_serial_cache_initialise", &s_icl_demo_serial_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (icl_demo_serial_t));
icl_system_register (icl_demo_serial_cache_purge, icl_demo_serial_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_INITIALISE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_CACHE_INITIALISE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_cache_initialise_finish"
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
    icl_demo_serial_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_serial_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_CACHE_PURGE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_PURGE))
    icl_trace_record (NULL, icl_demo_serial_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_CACHE_PURGE))
    icl_stats_inc ("icl_demo_serial_cache_purge", &s_icl_demo_serial_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_PURGE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_CACHE_PURGE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_cache_purge_finish"
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
    icl_demo_serial_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    icl_demo_serial_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_CACHE_TERMINATE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_demo_serial_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_CACHE_TERMINATE))
    icl_stats_inc ("icl_demo_serial_cache_terminate", &s_icl_demo_serial_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_TERMINATE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_CACHE_TERMINATE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_cache_terminate_finish"
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
    icl_demo_serial_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    icl_demo_serial_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SHOW_ANIMATION))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_demo_serial_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SHOW_ANIMATION))
    icl_stats_inc ("icl_demo_serial_show_animation", &s_icl_demo_serial_show_animation_stats);
#endif

icl_demo_serial_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SHOW_ANIMATION))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SHOW_ANIMATION))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_show_animation_finish"
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
    icl_demo_serial_save

    Type: Component method
    Accepts a icl_demo_serial_t reference and returns zero in case of success,
    1 in case of errors.
    Saves the serialised fields to the specified buffer.  Returns amount of
    space used in buffer, in octets.  If the buffer is too small, returns 0.
    Integer data is always saved in network portable format.
    -------------------------------------------------------------------------
 */

size_t
    icl_demo_serial_save (
    icl_demo_serial_t * self,           //  Reference to object
    byte * data,                        //  Buffer to save into
    size_t size                         //  Buffer size
)
{
byte
    *dest;
size_t
    string_size;
byte
    bit_string;
    size_t
        rc = 0;                         //  Return codeReturned size

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SAVE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_save_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" data=\"%pp\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, data, size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SAVE))
    icl_trace_record (NULL, icl_demo_serial_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_SAVE))
    icl_stats_inc ("icl_demo_serial_save", &s_icl_demo_serial_save_stats);
#endif

ICL_DEMO_SERIAL_ASSERT_SANE (self);

assert (data);

if (ICL_DEMO_SERIAL_SIZE <= size) {
    dest = data;
    *(dbyte *) dest = htons (self->item_channel_id);
    dest += 2;
    *(dbyte *) dest = htons (self->item_handle_id);
    dest += 2;
    *(dbyte *) dest = htons (self->item_service_type);
    dest += 2;
    *(dbyte *) dest = htons (self->item_confirm_tag);
    dest += 2;
    dest += 1;
    bit_string = 0;
    bit_string |= (self->item_producer & 1) << 0;
    *(byte *) (dest - 1) = bit_string;
    bit_string |= (self->item_consumer & 1) << 1;
    *(byte *) (dest - 1) = bit_string;
    bit_string |= (self->item_browser & 1) << 2;
    *(byte *) (dest - 1) = bit_string;
    bit_string |= (self->item_temporary & 1) << 3;
    *(byte *) (dest - 1) = bit_string;
    string_size = strlen (self->item_dest_name);
    *(byte *) dest = (byte) string_size;
    dest += 1;
    memcpy (dest, self->item_dest_name, string_size);
    dest += string_size;
    string_size = strlen (self->item_mime_type);
    *(byte *) dest = (byte) string_size;
    dest += 1;
    memcpy (dest, self->item_mime_type, string_size);
    dest += string_size;
    string_size = strlen (self->item_encoding);
    *(byte *) dest = (byte) string_size;
    dest += 1;
    memcpy (dest, self->item_encoding, string_size);
    dest += string_size;
    if (self->item_options) {
        assert (self->item_options->cur_size < 0x10000);
        *(dbyte *) dest = htons ((dbyte) self->item_options->cur_size);
        dest += 2;
        memcpy (dest, self->item_options->data, self->item_options->cur_size);
        dest += self->item_options->cur_size;
    }
    else {
        *(dbyte *) dest = 0;
        dest += 2;
    }
    rc = dest - data;               //  Number of octets processed         
}
else {
    icl_console_print ("icl_demo_serial E: object needs %ld bytes, buffer too small at %ld",
        ICL_DEMO_SERIAL_SIZE, size);
    rc = 0;
}

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SAVE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_SAVE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_save_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" data=\"%pp\""
" size=\"%u\""
" rc=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, data, size, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_demo_serial_load

    Type: Component method
    Accepts a icl_demo_serial_t reference and returns zero in case of success,
    1 in case of errors.
    Loads the serialised fields from the supplied buffer.  Returns number of
    octets loaded; zero means the buffer was empty, or invalid.
    -------------------------------------------------------------------------
 */

size_t
    icl_demo_serial_load (
    icl_demo_serial_t * self,           //  Reference to object
    byte * data,                        //  Buffer to load from
    size_t size                         //  Buffer size
)
{
byte
    *src,                           //  Pointer into buffer                
    *max;                           //  Limit of buffer validity           
size_t
    string_size;
Bool
    underflow = FALSE;
byte
    bit_string = 0;
    size_t
        rc = 0;                         //  Return codeReturned size

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_LOAD))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_load_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" data=\"%pp\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, data, size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_LOAD))
    icl_trace_record (NULL, icl_demo_serial_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_LOAD))
    icl_stats_inc ("icl_demo_serial_load", &s_icl_demo_serial_load_stats);
#endif

ICL_DEMO_SERIAL_ASSERT_SANE (self);

assert (data);
src = data;
max = data + size;
if (src < max) {
    self->item_channel_id = ntohs (*(dbyte *) src);
    src += 2;
}
else
    underflow = TRUE;
if (src < max) {
    self->item_handle_id = ntohs (*(dbyte *) src);
    src += 2;
}
else
    underflow = TRUE;
if (src < max) {
    self->item_service_type = ntohs (*(dbyte *) src);
    src += 2;
}
else
    underflow = TRUE;
if (src < max) {
    self->item_confirm_tag = ntohs (*(dbyte *) src);
    src += 2;
}
else
    underflow = TRUE;
if (src < max) {
    bit_string = *(byte *) src;
    src++;
    self->item_producer = (bit_string >> 0) & 1;
}
else
    underflow = TRUE;
if (src < max) {
    self->item_consumer = (bit_string >> 1) & 1;
}
else
    underflow = TRUE;
if (src < max) {
    self->item_browser = (bit_string >> 2) & 1;
}
else
    underflow = TRUE;
if (src < max) {
    self->item_temporary = (bit_string >> 3) & 1;
}
else
    underflow = TRUE;
if (src < max) {
    string_size = *(byte *) src;
    src += 1;
    memcpy (self->item_dest_name, src, string_size);
    self->item_dest_name [string_size] = 0;
    src += string_size;
}
else
    underflow = TRUE;
if (src < max) {
    string_size = *(byte *) src;
    src += 1;
    memcpy (self->item_mime_type, src, string_size);
    self->item_mime_type [string_size] = 0;
    src += string_size;
}
else
    underflow = TRUE;
if (src < max) {
    string_size = *(byte *) src;
    src += 1;
    memcpy (self->item_encoding, src, string_size);
    self->item_encoding [string_size] = 0;
    src += string_size;
}
else
    underflow = TRUE;
if (src < max) {
    string_size = ntohs (*(dbyte *) src);
    src += 2;
    icl_longstr_destroy (&self->item_options);
    self->item_options = icl_longstr_new (src, string_size);
    src += string_size;
}
else
    underflow = TRUE;
if (underflow) {
    icl_console_print ("icl_demo_serial E: Insufficient buffer data provided to decode");
    rc = 0;
}
else
    rc = src - data;                //  Number of octets processed

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_LOAD))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_LOAD))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_load_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" data=\"%pp\""
" size=\"%u\""
" rc=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, data, size, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_demo_serial_get_size

    Type: Component method
    Accepts a icl_demo_serial_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

size_t
    icl_demo_serial_get_size (
    icl_demo_serial_t * self            //  Reference to object
)
{
    size_t
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_GET_SIZE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_get_size_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_GET_SIZE))
    icl_trace_record (NULL, icl_demo_serial_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_GET_SIZE))
    icl_stats_inc ("icl_demo_serial_get_size", &s_icl_demo_serial_get_size_stats);
#endif

ICL_DEMO_SERIAL_ASSERT_SANE (self);

rc = ICL_DEMO_SERIAL_SIZE;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_GET_SIZE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_GET_SIZE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_get_size_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" rc=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    icl_demo_serial_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    icl_demo_serial_new_in_scope_ (
    icl_demo_serial_t * * self_p,       //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL)  ||  defined (BASE_ANIMATE_ICL_DEMO_SERIAL_NEW_IN_SCOPE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_serial_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL)  ||  defined (BASE_STATS_ICL_DEMO_SERIAL_NEW_IN_SCOPE))
    icl_stats_inc ("icl_demo_serial_new_in_scope", &s_icl_demo_serial_new_in_scope_stats);
#endif

*self_p = icl_demo_serial_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) icl_demo_serial_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_NEW_IN_SCOPE))
    icl_trace_record (NULL, icl_demo_serial_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL)   || defined (BASE_ANIMATE_ICL_DEMO_SERIAL_NEW_IN_SCOPE))
    if (icl_demo_serial_animating)
        icl_console_print ("<icl_demo_serial_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SELFTEST)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_NEW)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SHOW)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_DESTROY_PUBLIC)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_DESTROY)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_ALLOC)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_FREE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_READ_LOCK)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_WRITE_LOCK)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_UNLOCK)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_INITIALISE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_PURGE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_CACHE_TERMINATE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SHOW_ANIMATION)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_SAVE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_LOAD)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_GET_SIZE)   || defined (BASE_TRACE_ICL_DEMO_SERIAL_NEW_IN_SCOPE) )
void
icl_demo_serial_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "selftest"; break;
        case 2: method_name = "terminate"; break;
        case 3: method_name = "new"; break;
        case 4: method_name = "show"; break;
        case 5: method_name = "destroy public"; break;
        case 6: method_name = "destroy"; break;
        case 7: method_name = "alloc"; break;
        case 8: method_name = "free"; break;
        case 9: method_name = "read lock"; break;
        case 10: method_name = "write lock"; break;
        case 11: method_name = "unlock"; break;
        case 12: method_name = "cache initialise"; break;
        case 13: method_name = "cache purge"; break;
        case 14: method_name = "cache terminate"; break;
        case 15: method_name = "show animation"; break;
        case 16: method_name = "save"; break;
        case 17: method_name = "load"; break;
        case 18: method_name = "get size"; break;
        case 19: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "icl_demo_serial %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *icl_demo_serial_version_start  = "VeRsIoNsTaRt:ipc";
char *icl_demo_serial_component    = "icl_demo_serial ";
char *icl_demo_serial_version      = "1.0 ";
char *icl_demo_serial_copyright    = "Copyright (c) 1996-2009 iMatix Corporation";
char *icl_demo_serial_filename     = "icl_demo_serial.icl ";
char *icl_demo_serial_builddate    = "2009/02/19 ";
char *icl_demo_serial_version_end  = "VeRsIoNeNd:ipc";

