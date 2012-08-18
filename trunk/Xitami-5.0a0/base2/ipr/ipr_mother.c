/*---------------------------------------------------------------------------
    ipr_mother.c - ipr_mother component

    [Todo]
    Generated from ipr_mother.icl by icl_gen using GSL/4.
    
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
#include "ipr_mother.h"                 //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_mother_t

//  Shorthands for class methods                                               

#define self_new            ipr_mother_new
#define self_allocate       ipr_mother_allocate
#define self_unfilled       ipr_mother_unfilled
#define self_overhang       ipr_mother_overhang
#define self_claim          ipr_mother_claim
#define self_fill           ipr_mother_fill
#define self_remove         ipr_mother_remove
#define self_selftest       ipr_mother_selftest
#define self_terminate      ipr_mother_terminate
#define self_show           ipr_mother_show
#define self_destroy        ipr_mother_destroy
#define self_annihilate     ipr_mother_annihilate
#define self_alloc          ipr_mother_alloc
#define self_free           ipr_mother_free
#define self_link           ipr_mother_link
#define self_unlink         ipr_mother_unlink
#define self_cache_initialise  ipr_mother_cache_initialise
#define self_cache_purge    ipr_mother_cache_purge
#define self_cache_terminate  ipr_mother_cache_terminate
#define self_show_animation  ipr_mother_show_animation
#define self_new_in_scope   ipr_mother_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_NEW))
static icl_stats_t *s_ipr_mother_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_ALLOCATE))
static icl_stats_t *s_ipr_mother_allocate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_UNFILLED))
       icl_stats_t *s_ipr_mother_unfilled_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_OVERHANG))
       icl_stats_t *s_ipr_mother_overhang_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CLAIM))
static icl_stats_t *s_ipr_mother_claim_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_FILL))
static icl_stats_t *s_ipr_mother_fill_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_REMOVE))
static icl_stats_t *s_ipr_mother_remove_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_SELFTEST))
static icl_stats_t *s_ipr_mother_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_TERMINATE))
static icl_stats_t *s_ipr_mother_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_SHOW))
static icl_stats_t *s_ipr_mother_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_mother_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_DESTROY))
static icl_stats_t *s_ipr_mother_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_ALLOC))
static icl_stats_t *s_ipr_mother_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_FREE))
static icl_stats_t *s_ipr_mother_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_LINK))
static icl_stats_t *s_ipr_mother_link_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_UNLINK))
static icl_stats_t *s_ipr_mother_unlink_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CACHE_INITIALISE))
static icl_stats_t *s_ipr_mother_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CACHE_PURGE))
static icl_stats_t *s_ipr_mother_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CACHE_TERMINATE))
static icl_stats_t *s_ipr_mother_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_SHOW_ANIMATION))
static icl_stats_t *s_ipr_mother_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_mother_new_in_scope_stats = NULL;
#endif
#define ipr_mother_annihilate(self)     ipr_mother_annihilate_ (self, __FILE__, __LINE__)
static void
    ipr_mother_annihilate_ (
ipr_mother_t * ( * self_p ),            //  Reference to object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

#define ipr_mother_alloc()              ipr_mother_alloc_ (__FILE__, __LINE__)
static ipr_mother_t *
    ipr_mother_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define ipr_mother_free(self)           ipr_mother_free_ (self, __FILE__, __LINE__)
static void
    ipr_mother_free_ (
ipr_mother_t * self,                    //  Object reference
char * file,                            //  Source file
size_t line                             //  Line number
);

static void
    ipr_mother_cache_initialise (
void);

static void
    ipr_mother_cache_purge (
void);

static void
    ipr_mother_cache_terminate (
void);

Bool
    ipr_mother_animating = TRUE;        //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


/*  -------------------------------------------------------------------------
    ipr_mother_new

    Type: Component method
    Creates and initialises a new ipr_mother_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_mother_t *
    ipr_mother_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_mother_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_NEW))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_NEW))
    icl_trace_record (NULL, ipr_mother_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_NEW))
    icl_stats_inc ("ipr_mother_new", &s_ipr_mother_new_stats);
#endif

    self = ipr_mother_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_MOTHER_ALIVE;
        self->links        = 1;
        self->zombie       = FALSE;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
        self->history_last = 0;

        //  Track possession operation in history
        self->history_file  [0] = file;
        self->history_line  [0] = line;
        self->history_type  [0] = "new";
        self->history_links [0] = self->links;
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_mother_show_);
#endif

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    self->apr_os_thread = apr_os_thread_current ();
#endif
    self->slave_count = 0;
    self->allocated   = 0;
    self->filled      = 0;
    self->claimed     = 0;
    self->closed      = FALSE;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_NEW))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_NEW))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_new_finish"
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
    ipr_mother_allocate

    Type: Component method
    Ensures that mother has enough unfilled space to hold 'size' bytes and
    returns a pointer to that space.
    -------------------------------------------------------------------------
 */

byte *
    ipr_mother_allocate (
    ipr_mother_t * ( * self_p ),        //  The mother to extend
    size_t size                         //  Required length of data
)
{
ipr_mother_t
    *new_mother;
    ipr_mother_t *
        self = *self_p;                 //  Dereferenced The mother to extend
    byte *
        data;                           //  Returned data space

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_ALLOCATE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_allocate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_ALLOCATE))
    icl_trace_record (NULL, ipr_mother_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_ALLOCATE))
    icl_stats_inc ("ipr_mother_allocate", &s_ipr_mother_allocate_stats);
#endif

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == self->apr_os_thread);
#endif
    //  Sanity check
    if (self->allocated - self->claimed + size > IPR_MOTHER_BUCKET_SIZE) {
        icl_console_print ("Attempt to read greater than mother size.");
        abort ();
    }

    //  If not enough data remain, start a new mother
    if (IPR_MOTHER_BUCKET_SIZE - self->allocated < size) {
        new_mother = ipr_mother_new ();
        if (self->filled > self->allocated) {
            memcpy (new_mother->data,
                    self->data + self->allocated,
                    self->filled - self->allocated);

            new_mother->filled = self->filled - self->allocated;
            self->filled       = self->allocated;
        }
        self->closed = TRUE;
        ipr_mother_unlink (self_p);
        self = *self_p
             = new_mother;
    }
    data = self->data +  self->allocated;
    self->allocated   += size;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_ALLOCATE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_ALLOCATE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_allocate_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" self=\"%pp\""
" data=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, self, data);
#endif


    return (data);
}
/*  -------------------------------------------------------------------------
    ipr_mother_claim

    Type: Component method
    Creates a bucket pointing to the next data in the mother.  If the mother
    does not have enough data, as defined by its cur_size field, no bucket is
    created.
    -------------------------------------------------------------------------
 */

ipr_bucket_t *
    ipr_mother_claim_ (
    ipr_mother_t * self,                //  The mother from which to obtain data
    size_t size,                        //  Required length of obtained data
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_bucket_t *
        slave = NULL;                   //  Returned pointer to slave bucket

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_CLAIM))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_claim_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CLAIM))
    icl_trace_record (NULL, ipr_mother_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CLAIM))
    icl_stats_inc ("ipr_mother_claim", &s_ipr_mother_claim_stats);
#endif

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == self->apr_os_thread);
#endif
    if (self->filled - self->claimed >= size) {
        assert (self->claimed + size <= self->allocated);
        slave = ipr_bucket_new_ (file, line, 0);
        slave->data = self->data + self->claimed;
        slave->max_size = size;
        slave->cur_size = size;
        self->claimed += size;

        icl_atomic_inc32 (&self->slave_count);
        slave->mother = ipr_mother_link (self);

    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CLAIM))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_CLAIM))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_claim_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" file=\"%s\""
" line=\"%u\""
" slave=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, file, line, slave);
#endif


    return (slave);
}
/*  -------------------------------------------------------------------------
    ipr_mother_fill

    Type: Component method
    Accepts a ipr_mother_t reference and returns zero in case of success,
    1 in case of errors.
    Consumes free space in the master bucket.
    -------------------------------------------------------------------------
 */

int
    ipr_mother_fill (
    ipr_mother_t * self,                //  Reference to objectThe mother from which to consume data
    size_t size                         //  Required length of consumed data
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_FILL))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_fill_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_FILL))
    icl_trace_record (NULL, ipr_mother_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_FILL))
    icl_stats_inc ("ipr_mother_fill", &s_ipr_mother_fill_stats);
#endif

IPR_MOTHER_ASSERT_SANE (self);
if (!self->zombie) {

#if (defined (BASE_THREADSAFE) && defined (DEBUG))
    assert (apr_os_thread_current () == self->apr_os_thread);
#endif
    if (self->closed)
        assert (self->filled + size <= self->allocated);
    else
        assert (self->filled + size <= IPR_MOTHER_BUCKET_SIZE);
    self->filled += size;
}
else
    rc = -1;                        //  Return error on zombie object.

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_FILL))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_FILL))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_fill_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" size=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, size, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_mother_remove

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_mother_remove (
    ipr_bucket_t * slave                //  Slave bucket being destroyed
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_REMOVE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_remove_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" slave=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, slave);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_REMOVE))
    icl_trace_record (NULL, ipr_mother_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_REMOVE))
    icl_stats_inc ("ipr_mother_remove", &s_ipr_mother_remove_stats);
#endif

icl_atomic_dec32 (&slave->mother->slave_count);
ipr_mother_unlink (&slave->mother);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_REMOVE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_REMOVE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_remove_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" slave=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, slave);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_mother_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_mother_selftest (
void)
{
ipr_mother_t *mother;
ipr_bucket_t *slave1,
             *slave2;
byte         *data;
int          i;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_SELFTEST))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_SELFTEST))
    icl_trace_record (NULL, ipr_mother_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_SELFTEST))
    icl_stats_inc ("ipr_mother_selftest", &s_ipr_mother_selftest_stats);
#endif

mother = ipr_mother_new ();
data = ipr_mother_allocate (&mother, 40000);
for (i = 0; i < 60000; i++)
    data[i] = (byte) i & 255;
ipr_mother_fill (mother, 60000);
slave1 = ipr_mother_claim (mother, 40000);

data = ipr_mother_allocate (&mother, 40000);
for (i = 0; i < 20000; i++)
    data[20000 + i] = (byte) (60000+i) & 255;
ipr_mother_fill (mother, 20000);
slave2 = ipr_mother_claim (mother, 40000);

for (i = 0; i < 40000; i++) {
    assert (slave1->data[i] == (byte) (i & 255));
    assert (slave2->data[i] == ((byte) (40000+i) & 255));
}
ipr_bucket_destroy (&slave2);
ipr_bucket_destroy (&slave1);
ipr_mother_destroy (&mother);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_SELFTEST))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_SELFTEST))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_selftest_finish"
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
    ipr_mother_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_mother_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_TERMINATE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_TERMINATE))
    icl_trace_record (NULL, ipr_mother_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_TERMINATE))
    icl_stats_inc ("ipr_mother_terminate", &s_ipr_mother_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_TERMINATE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_TERMINATE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_terminate_finish"
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
    ipr_mother_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_mother_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
    ipr_mother_t
        *self;
    int
        container_links;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    qbyte
        history_index;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_SHOW))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_SHOW))
    icl_trace_record (NULL, ipr_mother_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_SHOW))
    icl_stats_inc ("ipr_mother_show", &s_ipr_mother_show_stats);
#endif

self = item;
container_links = 0;
    assert (opcode == ICL_CALLBACK_DUMP);

    fprintf (trace_file, "    <ipr_mother zombie = \"%u\" links = \"%u\" containers = \"%u\" file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", self->zombie, self->links, container_links, file, (unsigned long) line, self);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    if (self->history_last > IPR_MOTHER_HISTORY_LENGTH) {
        fprintf (trace_file, "        <!-- possess history too large (%d) - call iMatix-tech -->\n",
            self->history_last);
        history_index = (self->history_last + 1) % IPR_MOTHER_HISTORY_LENGTH;
        self->history_last %= IPR_MOTHER_HISTORY_LENGTH;
    }
    else
        history_index = 0;

    for (; history_index != self->history_last; history_index = (history_index + 1) % IPR_MOTHER_HISTORY_LENGTH) {
        fprintf (trace_file, "       <%s file = \"%s\" line = \"%lu\" links = \"%lu\" />\n",
            self->history_type [history_index],
            self->history_file [history_index],
            (unsigned long) self->history_line  [history_index],
            (unsigned long) self->history_links [history_index]);
    }
    fprintf (trace_file, "    </ipr_mother>\n");
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_SHOW))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_SHOW))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_show_finish"
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
    ipr_mother_destroy

    Type: Component method
    Destroys a ipr_mother_t object. Takes the address of a
    ipr_mother_t reference (a pointer to a pointer) and nullifies the
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
    ipr_mother_destroy_ (
    ipr_mother_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_mother_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_DESTROY_PUBLIC))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_destroy_public_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_mother_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_mother_destroy", &s_ipr_mother_destroy_stats);
#endif

if (self) {
    if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
        ipr_mother_annihilate_ (self_p, file, line);

    if (self->links == 0) {
        icl_console_print ("Missing link on ipr_mother object");
        ipr_mother_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
        abort ();
    }

    if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0)
        ipr_mother_free_ ((ipr_mother_t *) self, file, line);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_DESTROY_PUBLIC))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_destroy_public_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_mother_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_mother_annihilate_ (
    ipr_mother_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    int
        history_last;
#endif

    ipr_mother_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_DESTROY))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_destroy_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY))
    icl_trace_record (NULL, ipr_mother_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_DESTROY))
    icl_stats_inc ("ipr_mother_annihilate", &s_ipr_mother_annihilate_stats);
#endif

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    //  Track possession operation in history
    history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
    self->history_file  [history_last % IPR_MOTHER_HISTORY_LENGTH] = file;
    self->history_line  [history_last % IPR_MOTHER_HISTORY_LENGTH] = line;
    self->history_type  [history_last % IPR_MOTHER_HISTORY_LENGTH] = "destroy";
    self->history_links [history_last % IPR_MOTHER_HISTORY_LENGTH] = self->links;
#endif

    IPR_MOTHER_ASSERT_SANE (self);


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_DESTROY))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_destroy_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" self=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_mother_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_mother_t *
    ipr_mother_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_mother_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_ALLOC))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_ALLOC))
    icl_trace_record (NULL, ipr_mother_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_ALLOC))
    icl_stats_inc ("ipr_mother_alloc", &s_ipr_mother_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_mother_cache_initialise ();

self = (ipr_mother_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_mother_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_ALLOC))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_ALLOC))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_alloc_finish"
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
    ipr_mother_free

    Type: Component method
    Freess a ipr_mother_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_mother_free_ (
    ipr_mother_t * self,                //  Object reference
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    int
        history_last;
#endif


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_FREE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_free_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_FREE))
    icl_trace_record (NULL, ipr_mother_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_FREE))
    icl_stats_inc ("ipr_mother_free", &s_ipr_mother_free_stats);
#endif

    if (self) {
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_MOTHER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_MOTHER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_MOTHER_HISTORY_LENGTH] = "free";
        self->history_links [history_last % IPR_MOTHER_HISTORY_LENGTH] = self->links;
#endif

        memset (&self->object_tag, 0, sizeof (ipr_mother_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_mother_t));
        self->object_tag = IPR_MOTHER_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_FREE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_FREE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_free_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_mother_link

    Type: Component method
    Adds a link (reference count) to an object.

    If the object has been zombified (ie destroyed while extra links were present),
    this method returns NULL and does not add any links.

    This method does not lock the object.
    -------------------------------------------------------------------------
 */

ipr_mother_t *
    ipr_mother_link_ (
    ipr_mother_t * self,                //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    int
        history_last;
#endif

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_LINK))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_link_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_LINK))
    icl_trace_record (NULL, ipr_mother_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_LINK))
    icl_stats_inc ("ipr_mother_link", &s_ipr_mother_link_stats);
#endif

    if (self) {
        IPR_MOTHER_ASSERT_SANE (self);
        if (file)
            icl_mem_possess_ (self, file, line);
        icl_atomic_inc32 ((volatile qbyte *) &self->links);
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
        //  Track possession operation in history
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_MOTHER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_MOTHER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_MOTHER_HISTORY_LENGTH] = "link";
        self->history_links [history_last % IPR_MOTHER_HISTORY_LENGTH] = self->links;
#endif
    }
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_LINK))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_LINK))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_link_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%u\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif


    return (self);
}
/*  -------------------------------------------------------------------------
    ipr_mother_unlink

    Type: Component method
    Removes a link (reference count) to an object.  Sets the object pointer to NULL
    to indicate that it is no longer valid.
    -------------------------------------------------------------------------
 */

void
    ipr_mother_unlink_ (
    ipr_mother_t * ( * self_p ),        //  Reference to object reference
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
    int
        history_last;
#endif

    ipr_mother_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_UNLINK))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_unlink_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_UNLINK))
    icl_trace_record (NULL, ipr_mother_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_UNLINK))
    icl_stats_inc ("ipr_mother_unlink", &s_ipr_mother_unlink_stats);
#endif

    if (self) {
        IPR_MOTHER_ASSERT_SANE (self);
        if (self->links == 0) {
            icl_console_print ("Missing link on ipr_mother object");
            ipr_mother_show_ (self, ICL_CALLBACK_DUMP, stderr, file, line);
            abort ();
        }

#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_IPR_MOTHER)
        //  Track possession operation in history.  Pre-empt value of links
        //  after operation; otherwise race condition can result in writing
        //  to freed memory.
        history_last = icl_atomic_inc32 ((volatile qbyte *) &self->history_last) + 1;
        self->history_file  [history_last % IPR_MOTHER_HISTORY_LENGTH] = file;
        self->history_line  [history_last % IPR_MOTHER_HISTORY_LENGTH] = line;
        self->history_type  [history_last % IPR_MOTHER_HISTORY_LENGTH] = "unlink";
        self->history_links [history_last % IPR_MOTHER_HISTORY_LENGTH] = self->links - 1;
#endif
        if (icl_atomic_dec32 ((volatile qbyte *) &self->links) == 0) {

        if (icl_atomic_cas32 (&self->zombie, TRUE, FALSE) == FALSE)
            ipr_mother_annihilate_ (self_p, file, line);
        ipr_mother_free_ ((ipr_mother_t *) self, file, line);
    }
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_UNLINK))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_UNLINK))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_unlink_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%s\""
" line=\"%i\""
" links=\"%i\""
" zombie=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, line, self?self->links:0, self?self->zombie:0);
#endif

}
/*  -------------------------------------------------------------------------
    ipr_mother_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_mother_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_CACHE_INITIALISE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_mother_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CACHE_INITIALISE))
    icl_stats_inc ("ipr_mother_cache_initialise", &s_ipr_mother_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_mother_t));
icl_system_register (ipr_mother_cache_purge, ipr_mother_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_CACHE_INITIALISE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_cache_initialise_finish"
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
    ipr_mother_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_mother_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_CACHE_PURGE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_PURGE))
    icl_trace_record (NULL, ipr_mother_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CACHE_PURGE))
    icl_stats_inc ("ipr_mother_cache_purge", &s_ipr_mother_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_PURGE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_CACHE_PURGE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_cache_purge_finish"
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
    ipr_mother_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_mother_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_CACHE_TERMINATE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_mother_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_CACHE_TERMINATE))
    icl_stats_inc ("ipr_mother_cache_terminate", &s_ipr_mother_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_CACHE_TERMINATE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_cache_terminate_finish"
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
    ipr_mother_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_mother_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_SHOW_ANIMATION))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_mother_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_SHOW_ANIMATION))
    icl_stats_inc ("ipr_mother_show_animation", &s_ipr_mother_show_animation_stats);
#endif

ipr_mother_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_SHOW_ANIMATION))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_show_animation_finish"
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
    ipr_mother_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_mother_new_in_scope_ (
    ipr_mother_t * * self_p,            //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_MOTHER)  ||  defined (BASE_ANIMATE_IPR_MOTHER_NEW_IN_SCOPE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_mother_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_MOTHER)  ||  defined (BASE_STATS_IPR_MOTHER_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_mother_new_in_scope", &s_ipr_mother_new_in_scope_stats);
#endif

*self_p = ipr_mother_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_mother_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_mother_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_MOTHER)   || defined (BASE_ANIMATE_IPR_MOTHER_NEW_IN_SCOPE))
    if (ipr_mother_animating)
        icl_console_print ("<ipr_mother_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_MOTHER)   || defined (BASE_TRACE_IPR_MOTHER_NEW)   || defined (BASE_TRACE_IPR_MOTHER_ALLOCATE)   || defined (BASE_TRACE_IPR_MOTHER_UNFILLED)   || defined (BASE_TRACE_IPR_MOTHER_OVERHANG)   || defined (BASE_TRACE_IPR_MOTHER_CLAIM)   || defined (BASE_TRACE_IPR_MOTHER_FILL)   || defined (BASE_TRACE_IPR_MOTHER_REMOVE)   || defined (BASE_TRACE_IPR_MOTHER_SELFTEST)   || defined (BASE_TRACE_IPR_MOTHER_TERMINATE)   || defined (BASE_TRACE_IPR_MOTHER_SHOW)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_MOTHER_DESTROY)   || defined (BASE_TRACE_IPR_MOTHER_ALLOC)   || defined (BASE_TRACE_IPR_MOTHER_FREE)   || defined (BASE_TRACE_IPR_MOTHER_LINK)   || defined (BASE_TRACE_IPR_MOTHER_UNLINK)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_PURGE)   || defined (BASE_TRACE_IPR_MOTHER_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_MOTHER_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_MOTHER_NEW_IN_SCOPE) )
void
ipr_mother_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "allocate"; break;
        case 3: method_name = "unfilled"; break;
        case 4: method_name = "overhang"; break;
        case 5: method_name = "claim"; break;
        case 6: method_name = "fill"; break;
        case 7: method_name = "remove"; break;
        case 8: method_name = "selftest"; break;
        case 9: method_name = "terminate"; break;
        case 10: method_name = "show"; break;
        case 11: method_name = "destroy public"; break;
        case 12: method_name = "destroy"; break;
        case 13: method_name = "alloc"; break;
        case 14: method_name = "free"; break;
        case 15: method_name = "link"; break;
        case 16: method_name = "unlink"; break;
        case 17: method_name = "cache initialise"; break;
        case 18: method_name = "cache purge"; break;
        case 19: method_name = "cache terminate"; break;
        case 20: method_name = "show animation"; break;
        case 21: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_mother %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_mother_version_start     = "VeRsIoNsTaRt:ipc";
char *ipr_mother_component         = "ipr_mother ";
char *ipr_mother_version           = "2.0 ";
char *ipr_mother_copyright         = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_mother_filename          = "ipr_mother.icl ";
char *ipr_mother_builddate         = "2009/02/19 ";
char *ipr_mother_version_end       = "VeRsIoNeNd:ipc";

