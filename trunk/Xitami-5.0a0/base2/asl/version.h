/*==========================================================
 *
 *  version.h - version information for ASL
 *
 *  Should be the last file included in parent source program.
 *  Generated by iMatix Boom
 *  
 *  Copyright (c) 1996-2009 iMatix Corporation
 *  All rights reserved.
 *  
 *  This file is licensed under the BSD license as follows:
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of iMatix Corporation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *==========================================================*/

#undef  VERSION         /*  Scrap any previous definitions  */
#undef  PRODUCT
#undef  COPYRIGHT
#undef  BUILDDATE
#undef  BUILDMODEL
#define VERSION         "1.2c0"
#define PRODUCT         "ASL/1.2c0"
#define COPYRIGHT       "Copyright (c) 1996-2009 iMatix Corporation"
#define BUILDDATE       ""
#ifndef SVN_REVISION
#define SVN_REVISION    "11949"
#endif
#if defined (DEBUG)
#   define BUILDMODEL   "Debug release for internal use only"
#else
#   define BUILDMODEL   "Production release"
#endif
#if defined (VERSION_EMBED)
/*  Embed the version information in the resulting binary   */
char *asl_version_start = "VeRsIoNsTaRt:asl";
char *asl_version = VERSION;
char *asl_product = PRODUCT;
char *asl_copyright = COPYRIGHT;
char *asl_buildmodel = BUILDMODEL;
char *asl_svn_revision = SVN_REVISION;
char *asl_version_end = "VeRsIoNeNd:asl";
#endif
