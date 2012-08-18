/*---------------------------------------------------------------------------
    ipr_uid.c - ipr_uid component

    Provides functions to access and maniuplate the current process
    user and group IDs.
    Generated from ipr_uid.icl by icl_gen using GSL/4.
    
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
#include "ipr_uid.h"                    //  Definitions for our class

//  Shorthands for class methods                                               

#define self_user_name      ipr_uid_user_name
#define self_group_name     ipr_uid_group_name
#define self_set_real_user  ipr_uid_set_real_user
#define self_set_root_user  ipr_uid_set_root_user
#define self_set_real_group  ipr_uid_set_real_group
#define self_set_root_group  ipr_uid_set_root_group
#define self_get_uid        ipr_uid_get_uid
#define self_get_gid        ipr_uid_get_gid
#define self_run_as         ipr_uid_run_as
#define self_selftest       ipr_uid_selftest
#define self_show_animation  ipr_uid_show_animation

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_USER_NAME))
static icl_stats_t *s_ipr_uid_user_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_GROUP_NAME))
static icl_stats_t *s_ipr_uid_group_name_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_REAL_USER))
static icl_stats_t *s_ipr_uid_set_real_user_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_ROOT_USER))
static icl_stats_t *s_ipr_uid_set_root_user_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_REAL_GROUP))
static icl_stats_t *s_ipr_uid_set_real_group_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_ROOT_GROUP))
static icl_stats_t *s_ipr_uid_set_root_group_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_GET_UID))
static icl_stats_t *s_ipr_uid_get_uid_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_GET_GID))
static icl_stats_t *s_ipr_uid_get_gid_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_RUN_AS))
static icl_stats_t *s_ipr_uid_run_as_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SELFTEST))
static icl_stats_t *s_ipr_uid_selftest_stats = NULL;
#endif
#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SHOW_ANIMATION))
static icl_stats_t *s_ipr_uid_show_animation_stats = NULL;
#endif
Bool
    ipr_uid_animating = TRUE;           //  Animation enabled by default
#define REAL_ID             0           //  Arguments for get_uid/get_gid      
#define EFFECTIVE_ID        1
#if (defined (DOES_UID))
/*  -------------------------------------------------------------------------
    Function: get_uid -- internal

    Synopsis: Returns the real (REAL_ID) or effective (EFFECTIVE_ID) uid.
    These values are loaded the first time that the function is called: you
    should not rely on the effective uid after changing the uid.
    -------------------------------------------------------------------------*/

static uid_t
get_uid (int type)
{
    static int
        ruid = -1,
        euid = -1;

    if (ruid == -1)
        ruid = getuid ();
    if (euid == -1)
        euid = geteuid ();

    if (type == REAL_ID)
        return (ruid);
    else
    if (type == EFFECTIVE_ID)
        return (euid);
    else
        return (-1);
}

/*  -------------------------------------------------------------------------
    Function: get_gid -- internal

    Synopsis: Returns the real (REAL_ID) or effective (EFFECTIVE_ID) gid.
    These values are loaded the first time that the function is called: you
    should not rely on the effective gid after changing the gid.
    -------------------------------------------------------------------------*/

static gid_t
get_gid (int type)
{
    static int
        rgid = -1,
        egid = -1;

    if (rgid == -1)
        rgid = getgid ();
    if (egid == -1)
#   if (defined (__UTYPE_HPUX) || defined (__UTYPE_BEOS))
        egid = getgid ();
#   else
        egid = getegid ();
#   endif

    if (type == REAL_ID)
        return (rgid);
    else
    if (type == EFFECTIVE_ID)
        return (egid);
    else
        return (0);
}
#endif
/*  -------------------------------------------------------------------------
    ipr_uid_user_name

    Type: Component method
    Get user name from passwd file.  Places the user name into the
    provided short string.  Returns 0 on success, 1 if the name could
    not be found.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_user_name (
    uid_t uid,                          //  UID to look up
    char * name                         //  String to receive name
)
{
#   if (defined (DOES_UID))
    struct passwd
        *passwd_entry;
#   endif
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_USER_NAME))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_user_name_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_USER_NAME))
    icl_trace_record (NULL, ipr_uid_dump, 1);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_USER_NAME))
    icl_stats_inc ("ipr_uid_user_name", &s_ipr_uid_user_name_stats);
#endif

    rc = 0;
#   if (defined (__MSDOS__))
    icl_shortstr_cpy (name, "user");
#   else
    if ((passwd_entry = getpwuid (uid)) == NULL)
        icl_shortstr_cpy (name, "[none]");
    else
        icl_shortstr_cpy (name, passwd_entry->pw_name);
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_USER_NAME))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 1);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_USER_NAME))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_user_name_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_group_name

    Type: Component method
    Get group name from group file.  Places the group name into the
    provided short string.  Returns 0 on success, 1 if the name could
    not be found.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_group_name (
    uid_t gid,                          //  GID to look up
    char * name                         //  String to receive name
)
{
#   if (defined (DOES_UID))
    struct group
        *group_entry;
#   endif
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_GROUP_NAME))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_group_name_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_GROUP_NAME))
    icl_trace_record (NULL, ipr_uid_dump, 2);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_GROUP_NAME))
    icl_stats_inc ("ipr_uid_group_name", &s_ipr_uid_group_name_stats);
#endif

    rc = 0;
#   if (defined (DOES_UID))
    if ((group_entry = getgrgid (gid)) == NULL)
        icl_shortstr_cpy (name, "[none]");
    else
        icl_shortstr_cpy (name, group_entry->gr_name);
#   else
    icl_shortstr_cpy (name, "group");
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_GROUP_NAME))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 2);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_GROUP_NAME))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_group_name_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" name=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, name, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_set_real_user

    Type: Component method
    This function switches to the real user id. This function can be used
    by 'setuid' programs; i.e. programs that run under a fixed uid such as
    'root'.  Typically such programs need to access root resources, but user
    data files.  To do this they must switch between the 'root' uid and
    the 'user' uid. Use ipr_uid_set_root_user () to switch (back) to the
    'root' uid.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_set_real_user (
void)
{
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_SET_REAL_USER))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_real_user_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_REAL_USER))
    icl_trace_record (NULL, ipr_uid_dump, 3);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_REAL_USER))
    icl_stats_inc ("ipr_uid_set_real_user", &s_ipr_uid_set_real_user_stats);
#endif

#   if (defined (DOES_UID))
    rc = seteuid (get_uid (REAL_ID));
#   else
    rc = 0;
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_REAL_USER))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 3);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_SET_REAL_USER))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_real_user_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_set_root_user

    Type: Component method
    Sets the current process effective user ID to the effective user ID,
    which is root for setuid programs.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_set_root_user (
void)
{
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_SET_ROOT_USER))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_root_user_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_ROOT_USER))
    icl_trace_record (NULL, ipr_uid_dump, 4);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_ROOT_USER))
    icl_stats_inc ("ipr_uid_set_root_user", &s_ipr_uid_set_root_user_stats);
#endif

#   if (defined (DOES_UID))
    rc = seteuid (get_uid (EFFECTIVE_ID));
#   else
    rc = 0;
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_ROOT_USER))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 4);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_SET_ROOT_USER))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_root_user_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_set_real_group

    Type: Component method
    This function switches to the real group id. This function can be used
    by 'setuid' programs; i.e. programs that run under a fixed uid such as
    'root'.  Typically such programs need to access root resources, but user
    data files.  To do this they must switch between the 'root' gid and
    the 'user' gid. Use ipr_uid_set_root_group () to switch (back) to the
    'root' gid.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_set_real_group (
void)
{
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_SET_REAL_GROUP))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_real_group_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_REAL_GROUP))
    icl_trace_record (NULL, ipr_uid_dump, 5);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_REAL_GROUP))
    icl_stats_inc ("ipr_uid_set_real_group", &s_ipr_uid_set_real_group_stats);
#endif

#   if (defined (DOES_UID))
    rc = setegid (get_gid (REAL_ID));
#   else
    rc = 0;
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_REAL_GROUP))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 5);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_SET_REAL_GROUP))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_real_group_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_set_root_group

    Type: Component method
    Sets the current process effective group ID to the effective group ID,
    which is root for setuid programs.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_set_root_group (
void)
{
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_SET_ROOT_GROUP))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_root_group_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_ROOT_GROUP))
    icl_trace_record (NULL, ipr_uid_dump, 6);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SET_ROOT_GROUP))
    icl_stats_inc ("ipr_uid_set_root_group", &s_ipr_uid_set_root_group_stats);
#endif

#   if (defined (DOES_UID))
    rc = setegid (get_gid (EFFECTIVE_ID));
#   else
    rc = 0;
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SET_ROOT_GROUP))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 6);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_SET_ROOT_GROUP))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_set_root_group_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_get_uid

    Type: Component method
    Returns the current process user id.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_get_uid (
void)
{
    int
        uid;                            //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_GET_UID))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_get_uid_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_GET_UID))
    icl_trace_record (NULL, ipr_uid_dump, 7);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_GET_UID))
    icl_stats_inc ("ipr_uid_get_uid", &s_ipr_uid_get_uid_stats);
#endif

#   if (defined (DOES_UID))
    uid = get_uid (EFFECTIVE_ID);
#   else
    uid = 0;
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_GET_UID))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 7);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_GET_UID))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_get_uid_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" uid=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, uid);
#endif


    return (uid);
}
/*  -------------------------------------------------------------------------
    ipr_uid_get_gid

    Type: Component method
    Returns the current process group id.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_get_gid (
void)
{
    int
        gid;                            //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_GET_GID))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_get_gid_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_GET_GID))
    icl_trace_record (NULL, ipr_uid_dump, 8);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_GET_GID))
    icl_stats_inc ("ipr_uid_get_gid", &s_ipr_uid_get_gid_stats);
#endif

#   if (defined (DOES_UID))
    gid = get_gid (REAL_ID);
#   else
    gid = 0;
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_GET_GID))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 8);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_GET_GID))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_get_gid_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" gid=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, gid);
#endif


    return (gid);
}
/*  -------------------------------------------------------------------------
    ipr_uid_run_as

    Type: Component method
    Sets the current program's user and group to new values as specified as names.
    The program must be currently running as 'root'.  Returns 0 if the new names
    could be correctly used.  Returns -1 if the user/group could not be changed.
    The group name may be null.
    -------------------------------------------------------------------------
 */

int
    ipr_uid_run_as (
    char * user,                        //  Name of user to switch to
    char * group                        //  Name of group to switch to
)
{
#   if (defined (DOES_UID))
    struct passwd
        *pwdbuf = NULL;
    struct group
        *grpbuf = NULL;
#   endif
    int
        rc;                             //  Return value

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_RUN_AS))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_run_as_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" user=\"%s\""
" group=\"%s\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, user, group);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_RUN_AS))
    icl_trace_record (NULL, ipr_uid_dump, 9);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_RUN_AS))
    icl_stats_inc ("ipr_uid_run_as", &s_ipr_uid_run_as_stats);
#endif

    rc = 0;
    assert (user);
#   if (defined (DOES_UID))
    if (group) {
        grpbuf = getgrnam (group);
        if (grpbuf)
            rc = setgid (grpbuf->gr_gid);
        else
            rc = -1;
    }
    if (rc == 0) {
        pwdbuf = getpwnam (user);
        if (pwdbuf)
            rc = setuid (pwdbuf-> pw_uid);
        else
            rc = -1;
    }
#   endif
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_RUN_AS))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 9);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_RUN_AS))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_run_as_finish"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
" user=\"%s\""
" group=\"%s\""
" rc=\"%i\""
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
, user, group, rc);
#endif


    return (rc);
}
/*  -------------------------------------------------------------------------
    ipr_uid_selftest

    Type: Component method
    -------------------------------------------------------------------------
 */

void
    ipr_uid_selftest (
void)
{
icl_shortstr_t
    user,
    group;

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_SELFTEST))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_selftest_start"
#if (defined (BASE_THREADSAFE))
" thread=\"%pp\""
#endif
"/>"
#if (defined (BASE_THREADSAFE))
, apr_os_thread_current ()
#endif
);
#endif

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SELFTEST))
    icl_trace_record (NULL, ipr_uid_dump, 10);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SELFTEST))
    icl_stats_inc ("ipr_uid_selftest", &s_ipr_uid_selftest_stats);
#endif

ipr_uid_user_name  (ipr_uid_get_uid (), user);
ipr_uid_group_name (ipr_uid_get_gid (), group);
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SELFTEST))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 10);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_SELFTEST))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_selftest_finish"
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
    ipr_uid_show_animation

    Type: Component method
    Enables animation of the component. Animation is sent to stdout.
    To enable animation you must generate using the option -animate:1.
    -------------------------------------------------------------------------
 */

void
    ipr_uid_show_animation (
    Bool enabled                        //  Are we enabling or disabling animation?
)
{

#if (defined (BASE_ANIMATE)  ||  defined (BASE_ANIMATE_IPR_UID)  ||  defined (BASE_ANIMATE_IPR_UID_SHOW_ANIMATION))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_show_animation_start"
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

#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_uid_dump, 11);
#endif

#if (defined (BASE_STATS)  ||  defined (BASE_STATS_IPR_UID)  ||  defined (BASE_STATS_IPR_UID_SHOW_ANIMATION))
    icl_stats_inc ("ipr_uid_show_animation", &s_ipr_uid_show_animation_stats);
#endif

ipr_uid_animating = enabled;
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_SHOW_ANIMATION))
    icl_trace_record (NULL, ipr_uid_dump, 0x10000 + 11);
#endif

#if (defined (BASE_ANIMATE)   || defined (BASE_ANIMATE_IPR_UID)   || defined (BASE_ANIMATE_IPR_UID_SHOW_ANIMATION))
    if (ipr_uid_animating)
        icl_console_print ("<ipr_uid_show_animation_finish"
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
#if (defined (BASE_TRACE)   || defined (BASE_TRACE_IPR_UID)   || defined (BASE_TRACE_IPR_UID_USER_NAME)   || defined (BASE_TRACE_IPR_UID_GROUP_NAME)   || defined (BASE_TRACE_IPR_UID_SET_REAL_USER)   || defined (BASE_TRACE_IPR_UID_SET_ROOT_USER)   || defined (BASE_TRACE_IPR_UID_SET_REAL_GROUP)   || defined (BASE_TRACE_IPR_UID_SET_ROOT_GROUP)   || defined (BASE_TRACE_IPR_UID_GET_UID)   || defined (BASE_TRACE_IPR_UID_GET_GID)   || defined (BASE_TRACE_IPR_UID_RUN_AS)   || defined (BASE_TRACE_IPR_UID_SELFTEST)   || defined (BASE_TRACE_IPR_UID_SHOW_ANIMATION) )
void
ipr_uid_dump (icl_os_thread_t thread, apr_time_t time, qbyte info)
{
    dbyte
        method = info & 0xFFFF;
    char
        *method_name = NULL;
        
    switch (method) {
        case 1: method_name = "user name"; break;
        case 2: method_name = "group name"; break;
        case 3: method_name = "set real user"; break;
        case 4: method_name = "set root user"; break;
        case 5: method_name = "set real group"; break;
        case 6: method_name = "set root group"; break;
        case 7: method_name = "get uid"; break;
        case 8: method_name = "get gid"; break;
        case 9: method_name = "run as"; break;
        case 10: method_name = "selftest"; break;
        case 11: method_name = "show animation"; break;
    }
    icl_console_print_thread_time (thread, time,
                                   "ipr_uid %s%s",
                                   (info > 0xFFFF) ? "/" : "",
                                   method_name);
}
#endif

//  Embed the version information in the resulting binary                      

char *ipr_uid_version_start        = "VeRsIoNsTaRt:ipc";
char *ipr_uid_component            = "ipr_uid ";
char *ipr_uid_version              = "1.0 ";
char *ipr_uid_copyright            = "Copyright (c) 1996-2009 iMatix Corporation";
char *ipr_uid_filename             = "ipr_uid.icl ";
char *ipr_uid_builddate            = "2009/02/19 ";
char *ipr_uid_version_end          = "VeRsIoNeNd:ipc";

