/*---------------------------------------------------------------------------
    ipr_bits.c - ipr_bits component

Implements a bitstring object.
    Generated from ipr_bits.icl by icl_gen using GSL/4.
    
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
#include "ipr_bits.h"                   //  Definitions for our class

//  Shorthand for class type                                                   

#define self_t              ipr_bits_t

//  Shorthands for class methods                                               

#define self_new            ipr_bits_new
#define self_set            ipr_bits_set
#define self_clear          ipr_bits_clear
#define self_test           ipr_bits_test
#define self_reset          ipr_bits_reset
#define self_ones           ipr_bits_ones
#define self_and            ipr_bits_and
#define self_or             ipr_bits_or
#define self_xor            ipr_bits_xor
#define self_not            ipr_bits_not
#define self_first          ipr_bits_first
#define self_last           ipr_bits_last
#define self_next           ipr_bits_next
#define self_prev           ipr_bits_prev
#define self_next_zero      ipr_bits_next_zero
#define self_prev_zero      ipr_bits_prev_zero
#define self_fput           ipr_bits_fput
#define self_fget           ipr_bits_fget
#define self_selftest       ipr_bits_selftest
#define self_annihilate     ipr_bits_annihilate
#define self_count          ipr_bits_count
#define self_terminate      ipr_bits_terminate
#define self_show           ipr_bits_show
#define self_destroy        ipr_bits_destroy
#define self_alloc          ipr_bits_alloc
#define self_free           ipr_bits_free
#define self_read_lock      ipr_bits_read_lock
#define self_write_lock     ipr_bits_write_lock
#define self_unlock         ipr_bits_unlock
#define self_cache_initialise  ipr_bits_cache_initialise
#define self_cache_purge    ipr_bits_cache_purge
#define self_cache_terminate  ipr_bits_cache_terminate
#define self_show_animation  ipr_bits_show_animation
#define self_new_in_scope   ipr_bits_new_in_scope

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEW))
static icl_stats_t *s_ipr_bits_new_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SET))
static icl_stats_t *s_ipr_bits_set_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CLEAR))
static icl_stats_t *s_ipr_bits_clear_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_TEST))
static icl_stats_t *s_ipr_bits_test_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_RESET))
static icl_stats_t *s_ipr_bits_reset_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_ONES))
static icl_stats_t *s_ipr_bits_ones_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_AND))
static icl_stats_t *s_ipr_bits_and_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_OR))
static icl_stats_t *s_ipr_bits_or_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_XOR))
static icl_stats_t *s_ipr_bits_xor_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NOT))
static icl_stats_t *s_ipr_bits_not_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FIRST))
static icl_stats_t *s_ipr_bits_first_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_LAST))
static icl_stats_t *s_ipr_bits_last_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEXT))
static icl_stats_t *s_ipr_bits_next_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_PREV))
static icl_stats_t *s_ipr_bits_prev_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEXT_ZERO))
static icl_stats_t *s_ipr_bits_next_zero_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_PREV_ZERO))
static icl_stats_t *s_ipr_bits_prev_zero_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FPUT))
static icl_stats_t *s_ipr_bits_fput_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FGET))
static icl_stats_t *s_ipr_bits_fget_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SELFTEST))
static icl_stats_t *s_ipr_bits_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_DESTROY))
static icl_stats_t *s_ipr_bits_annihilate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_COUNT))
static icl_stats_t *s_ipr_bits_count_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_TERMINATE))
static icl_stats_t *s_ipr_bits_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SHOW))
static icl_stats_t *s_ipr_bits_show_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_DESTROY_PUBLIC))
static icl_stats_t *s_ipr_bits_destroy_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_ALLOC))
static icl_stats_t *s_ipr_bits_alloc_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FREE))
static icl_stats_t *s_ipr_bits_free_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_READ_LOCK))
static icl_stats_t *s_ipr_bits_read_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_WRITE_LOCK))
static icl_stats_t *s_ipr_bits_write_lock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_UNLOCK))
static icl_stats_t *s_ipr_bits_unlock_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CACHE_INITIALISE))
static icl_stats_t *s_ipr_bits_cache_initialise_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CACHE_PURGE))
static icl_stats_t *s_ipr_bits_cache_purge_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CACHE_TERMINATE))
static icl_stats_t *s_ipr_bits_cache_terminate_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SHOW_ANIMATION))
static icl_stats_t *s_ipr_bits_show_animation_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEW_IN_SCOPE))
static icl_stats_t *s_ipr_bits_new_in_scope_stats = NULL;
#endif
static void
    ipr_bits_annihilate (
ipr_bits_t * ( * self_p )               //  Reference to object reference
);

#define ipr_bits_alloc()                ipr_bits_alloc_ (__FILE__, __LINE__)
static ipr_bits_t *
    ipr_bits_alloc_ (
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

static void
    ipr_bits_free (
ipr_bits_t * self                       //  Object reference
);

static void
    ipr_bits_cache_initialise (
void);

static void
    ipr_bits_cache_purge (
void);

static void
    ipr_bits_cache_terminate (
void);

Bool
    ipr_bits_animating = TRUE;          //  Animation enabled by default
static icl_cache_t
    *s_cache = NULL;


static qbyte
    s_ipr_bits_count = 0;
//  How many bits are set in a given number
static byte s_bit_count [256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
};

//  Lookup for value of byte when the nth bit is set
static byte s_bit_set [8] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
};

//  Lookup for value of byte when the nth bit is cleared
static byte s_bit_clear [8] = {
    0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F
};

//  Index of first set bit in byte
static char s_first_bit_on [256] = {
    0, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    7, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    6, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    5, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
    4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
};

//  Index of first zero bit in byte
static char s_first_bit_off [256] = {
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 7,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 6,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 5,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 4,
    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, 0
};
/*  -------------------------------------------------------------------------
    ipr_bits_new

    Type: Component method
    Creates and initialises a new ipr_bits_t object, returns a
    reference to the created object.
    -------------------------------------------------------------------------
 */

ipr_bits_t *
    ipr_bits_new_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    ipr_bits_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_NEW))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_new_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEW))
    icl_trace_record (NULL, ipr_bits_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEW))
    icl_stats_inc ("ipr_bits_new", &s_ipr_bits_new_stats);
#endif

    self = ipr_bits_alloc_ (file, line);
    if (self) {
        self->object_tag   = IPR_BITS_ALIVE;
#if (defined (BASE_THREADSAFE))
        self->rwlock = icl_rwlock_new ();
#endif
#if defined (DEBUG)
        icl_mem_set_callback (self, ipr_bits_show_);
#endif

icl_atomic_inc32 ((volatile qbyte *) &s_ipr_bits_count);

self->data = (byte *)&self->real_data;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEW))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_NEW))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_new_finish"
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
    ipr_bits_set

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Sets the specified bit in the bitmap.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_set (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Bit to set, starting at 0
)
{
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_SET))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_set_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SET))
    icl_trace_record (NULL, ipr_bits_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SET))
    icl_stats_inc ("ipr_bits_set", &s_ipr_bits_set_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

self->data [byte_nbr] |= s_bit_set [bit_nbr];
if (self->size < byte_nbr + 1)
    self->size = byte_nbr + 1;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SET))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_SET))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_set_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_clear

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Clears the specified bit in the bitmap.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_clear (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Bit to set, starting at 0
)
{
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_CLEAR))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_clear_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CLEAR))
    icl_trace_record (NULL, ipr_bits_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CLEAR))
    icl_stats_inc ("ipr_bits_clear", &s_ipr_bits_clear_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

self->data [byte_nbr] &= s_bit_clear [bit_nbr];

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CLEAR))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_CLEAR))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_clear_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_test

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Tests the specified bit in the bitmap.  Returns 1 or 0.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_test (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Not documented
)
{
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_TEST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_test_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_TEST))
    icl_trace_record (NULL, ipr_bits_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_TEST))
    icl_stats_inc ("ipr_bits_test", &s_ipr_bits_test_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

rc = ((self->data [byte_nbr] & s_bit_set [bit_nbr]) != 0);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_TEST))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_TEST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_test_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_reset

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Resets all bits to zero.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_reset (
    ipr_bits_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_RESET))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_reset_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_RESET))
    icl_trace_record (NULL, ipr_bits_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_RESET))
    icl_stats_inc ("ipr_bits_reset", &s_ipr_bits_reset_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

self->size = 0;
memset (self->data, IPR_BITS_SIZE, 0);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_RESET))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_RESET))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_reset_finish"
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
    ipr_bits_ones

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Count the number of bits set to 1.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_ones (
    ipr_bits_t * self                   //  Reference to object
)
{
uint
    cur_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_ONES))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_ones_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_ONES))
    icl_trace_record (NULL, ipr_bits_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_ONES))
    icl_stats_inc ("ipr_bits_ones", &s_ipr_bits_ones_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (self->size <= IPR_BITS_SIZE);

for (cur_size = 0; cur_size < self->size; cur_size++)
    rc += s_bit_count [self->data [cur_size]];

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_ONES))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_ONES))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_ones_finish"
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
    ipr_bits_and

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    AND a bit string into the current bit string.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_and (
    ipr_bits_t * self,                  //  Reference to object
    ipr_bits_t * source                 //  Not documented
)
{
uint
    data_size,
    cur_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_AND))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_and_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_AND))
    icl_trace_record (NULL, ipr_bits_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_AND))
    icl_stats_inc ("ipr_bits_and", &s_ipr_bits_and_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (source);
assert (source->size <= IPR_BITS_SIZE);

data_size = min (self->size, source->size);
for (cur_size = 0; cur_size < data_size; cur_size += sizeof (int64_t))
    *(int64_t *) (self->data + cur_size) &= *(int64_t *) (source->data + cur_size);

memset (self->data + cur_size, 0, IPR_BITS_SIZE - cur_size);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_AND))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_AND))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_and_finish"
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
    ipr_bits_or

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    AND a bit string into the current bit string.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_or (
    ipr_bits_t * self,                  //  Reference to object
    ipr_bits_t * source                 //  Not documented
)
{
uint
    data_size,
    cur_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_OR))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_or_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_OR))
    icl_trace_record (NULL, ipr_bits_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_OR))
    icl_stats_inc ("ipr_bits_or", &s_ipr_bits_or_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (source);
assert (source->size <= IPR_BITS_SIZE);

data_size = max (self->size, source->size);
for (cur_size = 0; cur_size < data_size; cur_size += sizeof (int64_t))
    *(int64_t *) (self->data + cur_size) |= *(int64_t *) (source->data + cur_size);

self->size = data_size;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_OR))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_OR))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_or_finish"
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
    ipr_bits_xor

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    XOR a bit string into the current bit string.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_xor (
    ipr_bits_t * self,                  //  Reference to object
    ipr_bits_t * source                 //  Not documented
)
{
uint
    data_size,
    cur_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_XOR))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_xor_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_XOR))
    icl_trace_record (NULL, ipr_bits_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_XOR))
    icl_stats_inc ("ipr_bits_xor", &s_ipr_bits_xor_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (source);
assert (source->size <= IPR_BITS_SIZE);

data_size = max (self->size, source->size);
for (cur_size = 0; cur_size < data_size; cur_size += sizeof (int64_t))
    *(int64_t *) (self->data + cur_size) ^= *(int64_t *) (source->data + cur_size);

self->size = data_size;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_XOR))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_XOR))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_xor_finish"
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
    ipr_bits_not

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    NOT the current bit string.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_not (
    ipr_bits_t * self                   //  Reference to object
)
{
uint
    cur_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_NOT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_not_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NOT))
    icl_trace_record (NULL, ipr_bits_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NOT))
    icl_stats_inc ("ipr_bits_not", &s_ipr_bits_not_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (self->size <= IPR_BITS_SIZE);

for (cur_size = 0; cur_size < self->size; cur_size += sizeof (int64_t))
    *(int64_t *) (self->data + cur_size) = ~(*(int64_t *) (self->data + cur_size));

//  set the rest of the outstream to 1                                     
memset (self->data + cur_size, 0xFF, IPR_BITS_SIZE - cur_size);
self->size = IPR_BITS_SIZE;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NOT))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_NOT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_not_finish"
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
    ipr_bits_first

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Look for the first bit that is set to 1.  Returns -1 if no bit was
    set in the entire bit string.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_first (
    ipr_bits_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_FIRST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_first_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FIRST))
    icl_trace_record (NULL, ipr_bits_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FIRST))
    icl_stats_inc ("ipr_bits_first", &s_ipr_bits_first_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

if (self_test (self, 0))
    rc = 0;
else
    rc = self_next (self, 0);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FIRST))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_FIRST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_first_finish"
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
    ipr_bits_last

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Look for the last bit that is set to 1.  Returns -1 if no bit was
    set in the entire bit string.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_last (
    ipr_bits_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_LAST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_last_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_LAST))
    icl_trace_record (NULL, ipr_bits_dump, 12);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_LAST))
    icl_stats_inc ("ipr_bits_last", &s_ipr_bits_last_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

if (self_test (self, IPR_BITS_SIZE_BITS - 1))
    rc = 0;
else
    rc = self_prev (self, IPR_BITS_SIZE_BITS - 1);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_LAST))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 12);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_LAST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_last_finish"
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
    ipr_bits_next

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Look for the next bit that is set to 1, after the specified bit index.
    Returns -1 if no matching bit was found.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_next (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Bit number to start from
)
{
//  Mask clears all bits lower than current bit index 0-7
static byte clear_trailing_bits [8] = {
    254, 252, 248, 240, 224, 192, 128, 0
};
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
byte
    cur_byte;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_NEXT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_next_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEXT))
    icl_trace_record (NULL, ipr_bits_dump, 13);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEXT))
    icl_stats_inc ("ipr_bits_next", &s_ipr_bits_next_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

cur_byte = self->data [byte_nbr] & clear_trailing_bits [bit_nbr];
while (cur_byte == 0 && byte_nbr < self->size)
    cur_byte = self->data [++byte_nbr];

if (cur_byte > 0)
    rc = byte_nbr * 8 + s_first_bit_on [cur_byte];
else
    rc = -1;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEXT))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 13);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_NEXT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_next_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_prev

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Look for the previous bit that is set to 1, before the specified bit index.
    Returns -1 if no matching bit was found.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_prev (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Bit number to start from
)
{
//  Mask clears all bits higher than current bit index 0-7
static byte clear_leading_bits [8] = {
    0, 1, 3, 7, 15, 31, 63, 127
};
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
byte
    cur_byte;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_PREV))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_prev_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_PREV))
    icl_trace_record (NULL, ipr_bits_dump, 14);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_PREV))
    icl_stats_inc ("ipr_bits_prev", &s_ipr_bits_prev_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

cur_byte = self->data [byte_nbr] & clear_leading_bits [bit_nbr];
while (cur_byte == 0 && byte_nbr < self->size)
    cur_byte = self->data [--byte_nbr];

if (cur_byte > 0)
    rc = byte_nbr * 8 + s_first_bit_on [cur_byte];
else
    rc = -1;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_PREV))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 14);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_PREV))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_prev_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_next_zero

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Look for the next bit that is set to 0, after the specified bit index.
    Returns -1 if no matching bit was found.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_next_zero (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Bit number to start from
)
{
//  Mask sets all bits lower than current bit index 0-7                    
static byte set_trailing_bits [8] = {
    0, 1, 3, 7, 15, 31, 63, 127
};
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
byte
    cur_byte;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_NEXT_ZERO))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_next_zero_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEXT_ZERO))
    icl_trace_record (NULL, ipr_bits_dump, 15);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEXT_ZERO))
    icl_stats_inc ("ipr_bits_next_zero", &s_ipr_bits_next_zero_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

cur_byte = self->data [byte_nbr] | set_trailing_bits [bit_nbr];
while (cur_byte == 255 && byte_nbr < self->size)
    cur_byte = self->data [++byte_nbr];

if (cur_byte < 255)
    rc = byte_nbr * 8 + s_first_bit_off [cur_byte];
else
    rc = -1;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEXT_ZERO))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 15);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_NEXT_ZERO))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_next_zero_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_prev_zero

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Look for the previous bit that is set to 0, before the specified bit index.
    Returns -1 if no matching bit was found.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_prev_zero (
    ipr_bits_t * self,                  //  Reference to object
    uint index                          //  Bit number to start from
)
{
//  Mask sets all bits higher than current bit index 0-7
static byte set_leading_bits [8] = {
    254, 252, 248, 240, 224, 192, 128, 0
};
uint
    byte_nbr = index / 8,
    bit_nbr  = index % 8;
byte
    cur_byte;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_PREV_ZERO))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_prev_zero_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_PREV_ZERO))
    icl_trace_record (NULL, ipr_bits_dump, 16);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_PREV_ZERO))
    icl_stats_inc ("ipr_bits_prev_zero", &s_ipr_bits_prev_zero_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

assert (index < IPR_BITS_SIZE_BITS);

cur_byte = self->data [byte_nbr] | set_leading_bits [bit_nbr];
while (cur_byte == 255 && byte_nbr < self->size)
    cur_byte = self->data [--byte_nbr];

if (cur_byte < 255)
    rc = byte_nbr * 8 + s_first_bit_off [cur_byte];
else
    rc = -1;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_PREV_ZERO))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 16);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_PREV_ZERO))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_prev_zero_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" index=\"%u\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, index, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_fput

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Writes the bitstream to the specified file stream.  To read the bitstream,
    use the fget() function.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_fput (
    ipr_bits_t * self,                  //  Reference to object
    FILE * file                         //  Not documented
)
{
qbyte
    net_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_FPUT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_fput_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FPUT))
    icl_trace_record (NULL, ipr_bits_dump, 17);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FPUT))
    icl_stats_inc ("ipr_bits_fput", &s_ipr_bits_fput_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

net_size = htonl (self->size);
assert (fwrite (&net_size,  sizeof (net_size),   1, file));
assert (fwrite (self->data, sizeof (self->data), 1, file));

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FPUT))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 17);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_FPUT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_fput_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_fget

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    Reads a bitstring from the specified stream.  You must have previously
    written the bitstring using fput().  Overwrites the current bitstream
    with it.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_fget (
    ipr_bits_t * self,                  //  Reference to object
    FILE * file                         //  Not documented
)
{
qbyte
    net_size;
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_FGET))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_fget_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%pp\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FGET))
    icl_trace_record (NULL, ipr_bits_dump, 18);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FGET))
    icl_stats_inc ("ipr_bits_fget", &s_ipr_bits_fget_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

if (fread (&net_size,  sizeof (net_size),   1, file) == 1
 && fread (self->data, sizeof (self->data), 1, file) == 1)
    self->size = ntohl (net_size);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FGET))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 18);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_FGET))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_fget_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" self=\"%pp\""
" file=\"%pp\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, self, file, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_bits_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_bits_selftest (
void)
{
ipr_bits_t
    *bits,
    *bits2;
int
    count,
    next;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_SELFTEST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SELFTEST))
    icl_trace_record (NULL, ipr_bits_dump, 19);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SELFTEST))
    icl_stats_inc ("ipr_bits_selftest", &s_ipr_bits_selftest_stats);
#endif

//  Simple test
bits = ipr_bits_new ();
ipr_bits_set (bits, 9);
ipr_bits_set (bits, 10);
next = ipr_bits_first (bits);
assert (next == 9);
next = ipr_bits_next (bits, next);
assert (next == 10);
next = ipr_bits_next (bits, next);
assert (next == -1);
ipr_bits_destroy (&bits);

//  Fuller test
bits = ipr_bits_new ();
for (count = 0; count < 300; count++)
    ipr_bits_set (bits, count);

next = ipr_bits_first (bits);
for (count = 0; count < 300; count++) {
    assert (next == count);
    next = ipr_bits_next (bits, next);
}
ipr_bits_destroy (&bits);

bits = ipr_bits_new ();
ipr_bits_set (bits, 0);
ipr_bits_set (bits, 1);
ipr_bits_set (bits, 13);
ipr_bits_set (bits, 26);
ipr_bits_set (bits, 39);
ipr_bits_set (bits, 52);
next = ipr_bits_first (bits);
assert (next == 0);
next = ipr_bits_next (bits, next);
assert (next == 1);
next = ipr_bits_next (bits, next);
assert (next == 13);
next = ipr_bits_next (bits, next);
assert (next == 26);
next = ipr_bits_next (bits, next);
assert (next == 39);
next = ipr_bits_next (bits, next);
assert (next == 52);

bits2 = ipr_bits_new ();
ipr_bits_set (bits2, 26);
ipr_bits_set (bits2, 52);
ipr_bits_set (bits2, 99);
ipr_bits_clear (bits2, 99);

ipr_bits_and (bits2, bits);
next = ipr_bits_first (bits2);
assert (next == 26);
next = ipr_bits_next (bits2, next);
assert (next == 52);

ipr_bits_or (bits2, bits);
next = ipr_bits_first (bits2);
assert (next == 0);
next = ipr_bits_next (bits2, next);
assert (next == 1);
next = ipr_bits_next (bits2, next);
assert (next == 13);
next = ipr_bits_next (bits2, next);
assert (next == 26);
next = ipr_bits_next (bits2, next);
assert (next == 39);
next = ipr_bits_next (bits2, next);
assert (next == 52);

ipr_bits_clear (bits2, 26);
ipr_bits_clear (bits2, 52);
ipr_bits_xor (bits2, bits);
next = ipr_bits_first (bits2);
assert (next == 26);
next = ipr_bits_next (bits2, next);
assert (next == 52);

ipr_bits_reset (bits);
ipr_bits_destroy (&bits);
ipr_bits_destroy (&bits2);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SELFTEST))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 19);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_SELFTEST))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_selftest_finish"
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
    ipr_bits_annihilate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_bits_annihilate (
    ipr_bits_t * ( * self_p )           //  Reference to object reference
)
{
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t
        *rwlock;
#endif

    ipr_bits_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_DESTROY))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_destroy_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_DESTROY))
    icl_trace_record (NULL, ipr_bits_dump, 20);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_DESTROY))
    icl_stats_inc ("ipr_bits_annihilate", &s_ipr_bits_annihilate_stats);
#endif

    IPR_BITS_ASSERT_SANE (self);
#if (defined (BASE_THREADSAFE))
    rwlock = self->rwlock;
    if (rwlock)
         icl_rwlock_write_lock (rwlock);
#endif

icl_atomic_dec32 ((volatile qbyte *) &s_ipr_bits_count);
#if (defined (BASE_THREADSAFE))
    if (rwlock)
        icl_rwlock_unlock (rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_DESTROY))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 20);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_DESTROY))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_destroy_finish"
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
    ipr_bits_count

    Type: Component method
    -------------------------------------------------------------------------
 */

qbyte
    ipr_bits_count (
void)
{
    qbyte
        count;                          //  Number of instances

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_COUNT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_count_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_COUNT))
    icl_trace_record (NULL, ipr_bits_dump, 21);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_COUNT))
    icl_stats_inc ("ipr_bits_count", &s_ipr_bits_count_stats);
#endif

count = (int) s_ipr_bits_count;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_COUNT))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 21);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_COUNT))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_count_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" count=\"%lu\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, count);
#endif


    return (count);
}
/*  -------------------------------------------------------------------------
    ipr_bits_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_bits_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_TERMINATE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_TERMINATE))
    icl_trace_record (NULL, ipr_bits_dump, 22);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_TERMINATE))
    icl_stats_inc ("ipr_bits_terminate", &s_ipr_bits_terminate_stats);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_TERMINATE))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 22);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_TERMINATE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_terminate_finish"
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
    ipr_bits_show

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_bits_show_ (
    void * item,                        //  The opaque pointer
    int opcode,                         //  The callback opcode
    FILE * trace_file,                  //  File to print to
    char * file,                        //  Source file
    size_t line                         //  Line number
)
{
ipr_bits_t
    *self;
int
    container_links;


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_SHOW))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_show_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SHOW))
    icl_trace_record (NULL, ipr_bits_dump, 23);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SHOW))
    icl_stats_inc ("ipr_bits_show", &s_ipr_bits_show_stats);
#endif

self = item;
container_links = 0;
assert (opcode == ICL_CALLBACK_DUMP);

fprintf (trace_file, "    <ipr_bits file = \"%s\" line = \"%lu\"  pointer = \"%p\" />\n", file, (unsigned long) line, self);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SHOW))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 23);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_SHOW))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_show_finish"
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
    ipr_bits_destroy

    Type: Component method
    Destroys a ipr_bits_t object. Takes the address of a
    ipr_bits_t reference (a pointer to a pointer) and nullifies the
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
    ipr_bits_destroy_ (
    ipr_bits_t * ( * self_p ),          //  Reference to object reference
    char * file,                        //  Source fileSource file
    size_t line                         //  Line numberLine number
)
{
    ipr_bits_t *
        self = *self_p;                 //  Dereferenced Reference to object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_DESTROY_PUBLIC))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_destroy_public_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_bits_dump, 24);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_DESTROY_PUBLIC))
    icl_stats_inc ("ipr_bits_destroy", &s_ipr_bits_destroy_stats);
#endif

if (self) {
    ipr_bits_annihilate (self_p);
    ipr_bits_free ((ipr_bits_t *) self);
    *self_p = NULL;
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_DESTROY_PUBLIC))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 24);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_DESTROY_PUBLIC))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_destroy_public_finish"
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
    ipr_bits_alloc

    Type: Component method
    -------------------------------------------------------------------------
 */

static ipr_bits_t *
    ipr_bits_alloc_ (
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{

    ipr_bits_t *
        self = NULL;                    //  Object reference

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_ALLOC))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_alloc_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_ALLOC))
    icl_trace_record (NULL, ipr_bits_dump, 25);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_ALLOC))
    icl_stats_inc ("ipr_bits_alloc", &s_ipr_bits_alloc_stats);
#endif

//  Initialise cache if necessary
if (!s_cache)
    ipr_bits_cache_initialise ();

self = (ipr_bits_t *) icl_mem_cache_alloc_ (s_cache, file, line);
if (self)
    memset (self, 0, sizeof (ipr_bits_t));


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_ALLOC))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 25);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_ALLOC))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_alloc_finish"
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
    ipr_bits_free

    Type: Component method
    Freess a ipr_bits_t object.
    -------------------------------------------------------------------------
 */

static void
    ipr_bits_free (
    ipr_bits_t * self                   //  Object reference
)
{


#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_FREE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_free_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FREE))
    icl_trace_record (NULL, ipr_bits_dump, 26);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_FREE))
    icl_stats_inc ("ipr_bits_free", &s_ipr_bits_free_stats);
#endif

if (self) {

#if (defined (BASE_THREADSAFE))
    if (self->rwlock)
        icl_rwlock_destroy (&self->rwlock);
#endif
        memset (&self->object_tag, 0, sizeof (ipr_bits_t) - ((byte *) &self->object_tag - (byte *) self));
//        memset (self, 0, sizeof (ipr_bits_t));
        self->object_tag = IPR_BITS_DEAD;
        icl_mem_free (self);
    }
    self = NULL;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_FREE))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 26);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_FREE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_free_finish"
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
    ipr_bits_read_lock

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_read_lock (
    ipr_bits_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_READ_LOCK))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_read_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_READ_LOCK))
    icl_trace_record (NULL, ipr_bits_dump, 27);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_READ_LOCK))
    icl_stats_inc ("ipr_bits_read_lock", &s_ipr_bits_read_lock_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_read_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_READ_LOCK))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 27);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_READ_LOCK))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_read_lock_finish"
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
    ipr_bits_write_lock

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_write_lock (
    ipr_bits_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_WRITE_LOCK))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_write_lock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_WRITE_LOCK))
    icl_trace_record (NULL, ipr_bits_dump, 28);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_WRITE_LOCK))
    icl_stats_inc ("ipr_bits_write_lock", &s_ipr_bits_write_lock_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_write_lock (self->rwlock);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_WRITE_LOCK))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 28);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_WRITE_LOCK))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_write_lock_finish"
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
    ipr_bits_unlock

    Type: Component method
    Accepts a ipr_bits_t reference and returns zero in case of success,
    1 in case of errors.
    -------------------------------------------------------------------------
 */

int
    ipr_bits_unlock (
    ipr_bits_t * self                   //  Reference to object
)
{
    int
        rc = 0;                         //  Return code

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_UNLOCK))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_unlock_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_UNLOCK))
    icl_trace_record (NULL, ipr_bits_dump, 29);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_UNLOCK))
    icl_stats_inc ("ipr_bits_unlock", &s_ipr_bits_unlock_stats);
#endif

IPR_BITS_ASSERT_SANE (self);

#if (defined (BASE_THREADSAFE))
    icl_rwlock_unlock (self->rwlock);
#endif


#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_UNLOCK))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 29);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_UNLOCK))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_unlock_finish"
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
    ipr_bits_cache_initialise

    Type: Component method
    Initialise the cache and register purge method with the meta-cache.
    -------------------------------------------------------------------------
 */

static void
    ipr_bits_cache_initialise (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_CACHE_INITIALISE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_cache_initialise_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_bits_dump, 30);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CACHE_INITIALISE))
    icl_stats_inc ("ipr_bits_cache_initialise", &s_ipr_bits_cache_initialise_stats);
#endif

s_cache = icl_cache_get (sizeof (ipr_bits_t));
icl_system_register (ipr_bits_cache_purge, ipr_bits_cache_terminate);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CACHE_INITIALISE))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 30);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_CACHE_INITIALISE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_cache_initialise_finish"
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
    ipr_bits_cache_purge

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_bits_cache_purge (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_CACHE_PURGE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_cache_purge_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CACHE_PURGE))
    icl_trace_record (NULL, ipr_bits_dump, 31);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CACHE_PURGE))
    icl_stats_inc ("ipr_bits_cache_purge", &s_ipr_bits_cache_purge_stats);
#endif

icl_mem_cache_purge (s_cache);

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CACHE_PURGE))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 31);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_CACHE_PURGE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_cache_purge_finish"
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
    ipr_bits_cache_terminate

    Type: Component method
    -------------------------------------------------------------------------
 */

static void
    ipr_bits_cache_terminate (
void)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_CACHE_TERMINATE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_cache_terminate_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_bits_dump, 32);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_CACHE_TERMINATE))
    icl_stats_inc ("ipr_bits_cache_terminate", &s_ipr_bits_cache_terminate_stats);
#endif

s_cache = NULL;

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_CACHE_TERMINATE))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 32);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_CACHE_TERMINATE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_cache_terminate_finish"
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
    ipr_bits_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_bits_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_SHOW_ANIMATION))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_bits_dump, 33);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_SHOW_ANIMATION))
    icl_stats_inc ("ipr_bits_show_animation", &s_ipr_bits_show_animation_stats);
#endif

ipr_bits_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 33);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_SHOW_ANIMATION))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_show_animation_finish"
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
    ipr_bits_new_in_scope

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_bits_new_in_scope_ (
    ipr_bits_t * * self_p,              //  Not documented
    icl_scope_t * _scope,               //  Not documented
    char * file,                        //  Source file for call
    size_t line                         //  Line number for call
)
{
    icl_destroy_t *
        _destroy;                       //  Not documented

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_BITS)  ||  defined (BASE_ANIMATE_IPR_BITS_NEW_IN_SCOPE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_new_in_scope_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_bits_dump, 34);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_BITS)  ||  defined (BASE_STATS_IPR_BITS_NEW_IN_SCOPE))
    icl_stats_inc ("ipr_bits_new_in_scope", &s_ipr_bits_new_in_scope_stats);
#endif

*self_p = ipr_bits_new_ (file,line);

if (*self_p) {
    _destroy = icl_destroy_new   ((void * *) self_p, (icl_destructor_fn *) ipr_bits_destroy_);
    icl_destroy_list_queue (_scope, _destroy);
    icl_destroy_unlink (&_destroy);
}
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEW_IN_SCOPE))
    icl_trace_record (NULL, ipr_bits_dump, 0x10000 + 34);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_BITS)   || defined (BASE_ANIMATE_IPR_BITS_NEW_IN_SCOPE))
    if (ipr_bits_animating)
        icl_console_print ("<ipr_bits_new_in_scope_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_BITS)   || defined (BASE_TRACE_IPR_BITS_NEW)   || defined (BASE_TRACE_IPR_BITS_SET)   || defined (BASE_TRACE_IPR_BITS_CLEAR)   || defined (BASE_TRACE_IPR_BITS_TEST)   || defined (BASE_TRACE_IPR_BITS_RESET)   || defined (BASE_TRACE_IPR_BITS_ONES)   || defined (BASE_TRACE_IPR_BITS_AND)   || defined (BASE_TRACE_IPR_BITS_OR)   || defined (BASE_TRACE_IPR_BITS_XOR)   || defined (BASE_TRACE_IPR_BITS_NOT)   || defined (BASE_TRACE_IPR_BITS_FIRST)   || defined (BASE_TRACE_IPR_BITS_LAST)   || defined (BASE_TRACE_IPR_BITS_NEXT)   || defined (BASE_TRACE_IPR_BITS_PREV)   || defined (BASE_TRACE_IPR_BITS_NEXT_ZERO)   || defined (BASE_TRACE_IPR_BITS_PREV_ZERO)   || defined (BASE_TRACE_IPR_BITS_FPUT)   || defined (BASE_TRACE_IPR_BITS_FGET)   || defined (BASE_TRACE_IPR_BITS_SELFTEST)   || defined (BASE_TRACE_IPR_BITS_DESTROY)   || defined (BASE_TRACE_IPR_BITS_COUNT)   || defined (BASE_TRACE_IPR_BITS_TERMINATE)   || defined (BASE_TRACE_IPR_BITS_SHOW)   || defined (BASE_TRACE_IPR_BITS_DESTROY_PUBLIC)   || defined (BASE_TRACE_IPR_BITS_ALLOC)   || defined (BASE_TRACE_IPR_BITS_FREE)   || defined (BASE_TRACE_IPR_BITS_READ_LOCK)   || defined (BASE_TRACE_IPR_BITS_WRITE_LOCK)   || defined (BASE_TRACE_IPR_BITS_UNLOCK)   || defined (BASE_TRACE_IPR_BITS_CACHE_INITIALISE)   || defined (BASE_TRACE_IPR_BITS_CACHE_PURGE)   || defined (BASE_TRACE_IPR_BITS_CACHE_TERMINATE)   || defined (BASE_TRACE_IPR_BITS_SHOW_ANIMATION)   || defined (BASE_TRACE_IPR_BITS_NEW_IN_SCOPE) )
void
ipr_bits_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "new"; break;
        case 2: method_name = "set"; break;
        case 3: method_name = "clear"; break;
        case 4: method_name = "test"; break;
        case 5: method_name = "reset"; break;
        case 6: method_name = "ones"; break;
        case 7: method_name = "and"; break;
        case 8: method_name = "or"; break;
        case 9: method_name = "xor"; break;
        case 10: method_name = "not"; break;
        case 11: method_name = "first"; break;
        case 12: method_name = "last"; break;
        case 13: method_name = "next"; break;
        case 14: method_name = "prev"; break;
        case 15: method_name = "next zero"; break;
        case 16: method_name = "prev zero"; break;
        case 17: method_name = "fput"; break;
        case 18: method_name = "fget"; break;
        case 19: method_name = "selftest"; break;
        case 20: method_name = "destroy"; break;
        case 21: method_name = "count"; break;
        case 22: method_name = "terminate"; break;
        case 23: method_name = "show"; break;
        case 24: method_name = "destroy public"; break;
        case 25: method_name = "alloc"; break;
        case 26: method_name = "free"; break;
        case 27: method_name = "read lock"; break;
        case 28: method_name = "write lock"; break;
        case 29: method_name = "unlock"; break;
        case 30: method_name = "cache initialise"; break;
        case 31: method_name = "cache purge"; break;
        case 32: method_name = "cache terminate"; break;
        case 33: method_name = "show animation"; break;
        case 34: method_name = "new in scope"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_bits %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_bits_version_start       = "VeRsIoNsTaRt:ipc";
char *ipr_bits_component           = "ipr_bits ";
char *ipr_bits_version             = "1.1 ";
char *ipr_bits_copyright           = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_bits_filename            = "ipr_bits.icl ";
char *ipr_bits_builddate           = "2009/02/19 ";
char *ipr_bits_version_end         = "VeRsIoNeNd:ipc";

