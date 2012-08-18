/* 
 * $Id: DownloadClient.cpp 20689 2010-10-20 04:12:33Z dgkang $
 * 
 * this file is part of eMule
 * Copyright (C)2002-2006 Merkur ( strEmail.Format("%s@%s", "devteam", "emule-project.net") / http://www.emule-project.net )
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "stdafx.h"
//#include "emule.h"
#include <zlib/zlib.h>
#include "UpDownClient.h"
#include "PartFile.h"
#include "OtherFunctions.h"
#include "ListenSocket.h"
#include "PeerCacheSocket.h"
#include "Preferences.h"
#include "SafeFile.h"
#include "Packets.h"
#include "Statistics.h"
#include "ClientCredits.h"
#include "DownloadQueue.h"
#include "ClientUDPSocket.h"
//#include "emuledlg.h"
//#include "TransferWnd.h"
#include "PeerCacheFinder.h"
#include "Exceptions.h"
#include "clientlist.h"
#include "Kademlia/Kademlia/Kademlia.h"
#include "Kademlia/Kademlia/Prefs.h"
#include "Kademlia/Kademlia/Search.h"
#include "SHAHashSet.h"
#include "SharedFileList.h"
#include "Log.h"
#include "UIMessage.h"
#include "GlobalVariable.h"
#include "resource.h"
#include "StatForServer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//	members of CUpDownClient
//	which are mainly used for downloading functions
CBarShader CUpDownClient::s_StatusBar(16);
void CUpDownClient::DrawStatusBar(CDC* dc, LPCRECT rect, bool onlygreyrect, bool  bFlat) const
{
    if (g_bLowColorDesktop)
        bFlat = true;

    COLORREF crNeither;
    if (bFlat)
    {
        if (g_bLowColorDesktop)
            crNeither = RGB(192, 192, 192);
        else
            crNeither = RGB(224, 224, 224);
    }
    else
    {
        crNeither = RGB(240, 240, 240);
    }

    ASSERT(reqfile);
    s_StatusBar.SetFileSize(reqfile->GetFileSize());
    s_StatusBar.SetHeight(rect->bottom - rect->top);
    s_StatusBar.SetWidth(rect->right - rect->left);
    s_StatusBar.Fill(crNeither);

    if (!onlygreyrect && reqfile && m_abyPartStatus)
    {
        COLORREF crBoth;
        COLORREF crClientOnly;
        COLORREF crPending;
        COLORREF crNextPending;
        if (g_bLowColorDesktop)
        {
            crBoth = RGB(0, 0, 0);
            crClientOnly = RGB(0, 0, 255);
            crPending = RGB(0, 255, 0);
            crNextPending = RGB(255, 255, 0);
        }
        else if (bFlat)
        {
            crBoth = RGB(0, 0, 0);
            crClientOnly = RGB(0, 100, 255);
            crPending = RGB(0, 150, 0);
            crNextPending = RGB(255, 208, 0);
        }
        else
        {
            crBoth = RGB(104, 104, 104);
            crClientOnly = RGB(0, 100, 255);
            crPending = RGB(0, 150, 0);
            crNextPending = RGB(255, 208, 0);
        }

        char* pcNextPendingBlks = NULL;
        if (m_nDownloadState == DS_DOWNLOADING)
        {
            pcNextPendingBlks = new char[m_nPartCount];
            memset(pcNextPendingBlks, 'N', m_nPartCount); // do not use '_strnset' for uninitialized memory!
            for (POSITION pos = m_PendingBlocks_list.GetHeadPosition(); pos != 0; )
            {
                UINT uPart = (UINT)(m_PendingBlocks_list.GetNext(pos)->block->StartOffset / PARTSIZE);
                if (uPart < m_nPartCount)
                    pcNextPendingBlks[uPart] = 'Y';
            }
        }

        for (UINT i = 0; i < m_nPartCount; i++)
        {
            if (m_abyPartStatus[i])
            {
                uint64 uEnd;
                if ( PARTSIZE*(uint64)(i+1) > reqfile->GetFileSize())
                    uEnd = reqfile->GetFileSize();
                else
                    uEnd = PARTSIZE*(uint64)(i+1);

                if (reqfile->IsComplete(PARTSIZE*(uint64)i,PARTSIZE*(uint64)(i+1)-1, false))
                    s_StatusBar.FillRange(PARTSIZE*(uint64)i, uEnd, crBoth);
                else if (GetSessionDown() > 0 && m_nDownloadState == DS_DOWNLOADING && m_nLastBlockOffset >= PARTSIZE*(uint64)i && m_nLastBlockOffset < uEnd)
                    s_StatusBar.FillRange(PARTSIZE*(uint64)i, uEnd, crPending);
                else if (pcNextPendingBlks != NULL && pcNextPendingBlks[i] == 'Y')
                    s_StatusBar.FillRange(PARTSIZE*(uint64)i, uEnd, crNextPending);
                else
                    s_StatusBar.FillRange(PARTSIZE*(uint64)i, uEnd, crClientOnly);
            }
        }
        delete[] pcNextPendingBlks;
    }
    s_StatusBar.Draw(dc, rect->left, rect->top, bFlat);
}

bool CUpDownClient::Compare(const CUpDownClient* tocomp, bool bIgnoreUserhash) const
{
    //Compare only the user hash..
    if (!bIgnoreUserhash && HasValidHash() && tocomp->HasValidHash())
        return !md4cmp(this->GetUserHash(), tocomp->GetUserHash());

    if( m_nSourceFrom==SF_LAN && tocomp->GetSourceFrom()==SF_LAN )
	{
		if( m_nLanConnectIP==tocomp->m_nLanConnectIP && m_nUserPort == tocomp->m_nUserPort)	
			return true;
	}

	if (HasLowID())
    {
        //User is firewalled.. Must do two checks..
        if (GetIP()!=0	&& GetIP() == tocomp->GetIP())
        {
            //The IP of both match
            if (GetUserPort()!=0 && GetUserPort() == tocomp->GetUserPort())
                //IP-UserPort matches
                return true;
            if (GetKadPort()!=0	&& GetKadPort() == tocomp->GetKadPort())
                //IP-KadPort Matches
                return true;
        }
        if (GetUserIDHybrid()!=0
                && GetUserIDHybrid() == tocomp->GetUserIDHybrid()
                && GetServerIP()!=0
                && GetServerIP() == tocomp->GetServerIP()
                && GetServerPort()!=0
                && GetServerPort() == tocomp->GetServerPort())
            //Both have the same lowID, Same serverIP and Port..
            return true;

#if defined(_DEBUG)
        if ( HasValidBuddyID() && tocomp->HasValidBuddyID() )
        {
            //JOHNTODO: This is for future use to see if this will be needed...
            if (!md4cmp(GetBuddyID(), tocomp->GetBuddyID()))
                return true;
        }
#endif

        //Both IP, and Server do not match..
        return false;
    }

    //User is not firewalled.
    if (GetUserPort()!=0)
    {
        //User has a Port, lets check the rest.
        if (GetIP() != 0 && tocomp->GetIP() != 0)
        {
            //Both clients have a verified IP..
            if (GetIP() == tocomp->GetIP() && GetUserPort() == tocomp->GetUserPort())
                //IP and UserPort match..
                return true;
        }
        else
        {
            //One of the two clients do not have a verified IP
            if (GetUserIDHybrid() == tocomp->GetUserIDHybrid() && GetUserPort() == tocomp->GetUserPort())
                //ID and Port Match..
                return true;
        }
    }
    if (GetKadPort()!=0)
    {
        //User has a Kad Port.
        if (GetIP() != 0 && tocomp->GetIP() != 0)
        {
            //Both clients have a verified IP.
            if (GetIP() == tocomp->GetIP() && GetKadPort() == tocomp->GetKadPort())
                //IP and KadPort Match..
                return true;
        }
        else
        {
            //One of the users do not have a verified IP.
            if (GetUserIDHybrid() == tocomp->GetUserIDHybrid() && GetKadPort() == tocomp->GetKadPort())
                //ID and KadProt Match..
                return true;
        }
    }
    //No Matches..
    return false;
}

// Return bool is not if you asked or not..
// false = Client was deleted!
// true = client was not deleted!
bool CUpDownClient::AskForDownload()
{

	if (m_bUDPPending)
	{
		m_nFailedUDPPackets++;
		CGlobalVariable::downloadqueue->AddFailedUDPFileReasks();
	}
	m_bUDPPending = false;

	if (!(socket && socket->IsConnected())) // already connected, skip all the special checks
	{
		if( !PrepareActiveConnectType() )
				return false;

		if ( CGlobalVariable::listensocket->TooManySockets(GetSourceFrom()==SF_LAN,m_nActiveConnectType==ACT_DIRECTTCP,m_nActiveConnectType==ACT_FAKETCP) )
		{
			if (GetDownloadState() != DS_TOOMANYCONNS)
				SetDownloadState(DS_TOOMANYCONNS);
			return true;
		}

		m_dwLastTriedToConnect = ::GetTickCount();
		// if its a lowid client which is on our queue we may delay the reask up to 20 min, to give the lowid the chance to
		// connect to us for its own reask
		if (HasLowID() && GetUploadState() == US_ONUPLOADQUEUE && !m_bReaskPending && GetLastAskedTime() > 0){
			SetDownloadState(DS_ONQUEUE);
			m_bReaskPending = true;
			return true;
		}
		// if we are lowid <-> lowid but contacted the source before already, keep it in the hope that we might turn highid again
		if (HasLowID() && !CGlobalVariable::CanDoCallback(this) && GetLastAskedTime() > 0 && SNT_UNSUPPORT==m_nSupportNatTraverse){
			if (GetDownloadState() != DS_LOWTOLOWIP)
				SetDownloadState(DS_LOWTOLOWIP);
			m_bReaskPending = true;
			return true;
		}
	}

	m_dwLastTriedToConnect = ::GetTickCount();
	SwapToAnotherFile(_T("A4AF check before tcp file reask. CUpDownClient::AskForDownload()"), true, false, false, NULL, true, true);
	SetDownloadState(DS_CONNECTING);
	return TryToConnect();
}

bool CUpDownClient::IsSourceRequestAllowed() const
{
    return IsSourceRequestAllowed(reqfile);
}

bool CUpDownClient::IsSourceRequestAllowed(CPartFile* partfile, bool sourceExchangeCheck) const
{
    DWORD dwTickCount = ::GetTickCount() + CONNECTION_LATENCY;
    unsigned int nTimePassedClient = dwTickCount - GetLastSrcAnswerTime();
    unsigned int nTimePassedFile   = dwTickCount - partfile->GetLastAnsweredTime();
    bool bNeverAskedBefore = GetLastAskedForSources() == 0;
    UINT uSources = partfile->GetSourceCount();
    UINT uValidSources = partfile->GetValidSourcesCount();

    if (partfile != reqfile)
    {
        uSources++;
        uValidSources++;
    }

    UINT uReqValidSources = reqfile->GetValidSourcesCount();

    return (
               //if client has the correct extended protocol
               ExtProtocolAvailable() && GetSourceExchange1Version() > 1 &&
               //AND if we need more sources
               reqfile->GetMaxSourcePerFileSoft() > uSources &&
               //AND if...
               (
                   //source is not complete and file is very rare
                   ( !m_bCompleteSource
                     && (bNeverAskedBefore || nTimePassedClient > SOURCECLIENTREASKS)
                     && (uSources <= RARE_FILE/5)
                     && (!sourceExchangeCheck || partfile == reqfile || uValidSources < uReqValidSources && uReqValidSources > 3)
                   ) ||
                   //source is not complete and file is rare
                   ( !m_bCompleteSource
                     && (bNeverAskedBefore || nTimePassedClient > SOURCECLIENTREASKS)
                     && (uSources <= RARE_FILE || (!sourceExchangeCheck || partfile == reqfile) && uSources <= RARE_FILE / 2 + uValidSources)
                     && (nTimePassedFile > SOURCECLIENTREASKF)
                     && (!sourceExchangeCheck || partfile == reqfile || uValidSources < SOURCECLIENTREASKS/SOURCECLIENTREASKF && uValidSources < uReqValidSources)
                   ) ||
                   // OR if file is not rare
                   ( (bNeverAskedBefore || nTimePassedClient > (unsigned)(SOURCECLIENTREASKS * MINCOMMONPENALTY))
                     && (nTimePassedFile > (unsigned)(SOURCECLIENTREASKF * MINCOMMONPENALTY))
                     && (!sourceExchangeCheck || partfile == reqfile || uValidSources < SOURCECLIENTREASKS/SOURCECLIENTREASKF && uValidSources < uReqValidSources)
                   )
               )
           );
}

void CUpDownClient::SendFileRequest()
{
    // normally asktime has already been reset here, but then SwapToAnotherFile will return without much work, so check to make sure
    SwapToAnotherFile(_T("A4AF check before tcp file reask. CUpDownClient::SendFileRequest()"), true, false, false, NULL, true, true);

    ASSERT(reqfile != NULL);
    if (!reqfile)
        return;
    AddAskedCountDown();

    CSafeMemFile dataFileReq(16+16);
    dataFileReq.WriteHash16(reqfile->GetFileHash());

    if (SupportMultiPacket())
    {
        bool bUseExtMultiPacket = SupportExtMultiPacket();
		if (bUseExtMultiPacket){
            dataFileReq.WriteUInt64(reqfile->GetFileSize());
            if (thePrefs.GetDebugClientTCPLevel() > 0)
                DebugSend("OP__MultiPacket_Ext", this, reqfile->GetFileHash());
        }
		else{
            if (thePrefs.GetDebugClientTCPLevel() > 0)
                DebugSend("OP__MultiPacket", this, reqfile->GetFileHash());
        }

        // OP_REQUESTFILENAME + ExtInfo
        if (thePrefs.GetDebugClientTCPLevel() > 0)
            DebugSend("OP__MPReqFileName", this, reqfile->GetFileHash());
        dataFileReq.WriteUInt8(OP_REQUESTFILENAME);
        if (GetExtendedRequestsVersion() > 0)
            reqfile->WritePartStatus(&dataFileReq);
        if (GetExtendedRequestsVersion() > 1)
            reqfile->WriteCompleteSourcesCount(&dataFileReq);

        // OP_SETREQFILEID
        if (thePrefs.GetDebugClientTCPLevel() > 0)
            DebugSend("OP__MPSetReqFileID", this, reqfile->GetFileHash());
        if (reqfile->GetPartCount() > 1)
            dataFileReq.WriteUInt8(OP_SETREQFILEID);

        if (IsEmuleClient())
        {
            SetRemoteQueueFull(true);
            SetRemoteQueueRank(0);
        }

		// OP_REQUESTSOURCES // OP_REQUESTSOURCES2
        if (IsSourceRequestAllowed())
        {
			if (thePrefs.GetDebugClientTCPLevel() > 0) {
                DebugSend("OP__MPReqSources", this, reqfile->GetFileHash());
                if (GetLastAskedForSources() == 0)
                    Debug(_T("  first source request\n"));
                else
                    Debug(_T("  last source request was before %s\n"), CastSecondsToHM((GetTickCount() - GetLastAskedForSources())/1000));
            }
			if (SupportsSourceExchange2()){
				dataFileReq.WriteUInt8(OP_REQUESTSOURCES2);
				dataFileReq.WriteUInt8(SOURCEEXCHANGE2_VERSION);
				const uint16 nOptions = 0; // 16 ... Reserved
				dataFileReq.WriteUInt16(nOptions);
			}
			else{
            dataFileReq.WriteUInt8(OP_REQUESTSOURCES);
			}
            reqfile->SetLastAnsweredTimeTimeout();
            SetLastAskedForSources();
            if (thePrefs.GetDebugSourceExchange())
				AddDebugLogLine(false, _T("SXSend (%s): Client source request; %s, File=\"%s\""),SupportsSourceExchange2() ? _T("Version 2") : _T("Version 1"), DbgGetClientInfo(), reqfile->GetFileName());
        }

        // OP_AICHFILEHASHREQ
        if (IsSupportingAICH())
        {
            if (thePrefs.GetDebugClientTCPLevel() > 0)
                DebugSend("OP__MPAichFileHashReq", this, reqfile->GetFileHash());
            dataFileReq.WriteUInt8(OP_AICHFILEHASHREQ);
        }

        Packet* packet = new Packet(&dataFileReq, OP_EMULEPROT);
        packet->opcode = bUseExtMultiPacket ? OP_MULTIPACKET_EXT : OP_MULTIPACKET;
        theStats.AddUpDataOverheadFileRequest(packet->size);
        socket->SendPacket(packet, true);
    }
    else
    {
        //This is extended information
        if (GetExtendedRequestsVersion() > 0)
            reqfile->WritePartStatus(&dataFileReq);
        if (GetExtendedRequestsVersion() > 1)
            reqfile->WriteCompleteSourcesCount(&dataFileReq);
        if (thePrefs.GetDebugClientTCPLevel() > 0)
            DebugSend("OP__FileRequest", this, reqfile->GetFileHash());
        Packet* packet = new Packet(&dataFileReq);
        packet->opcode = OP_REQUESTFILENAME;
        theStats.AddUpDataOverheadFileRequest(packet->size);
        socket->SendPacket(packet, true);

        // 26-Jul-2003: removed requesting the file status for files <= PARTSIZE for better compatibility with ed2k protocol (eDonkeyHybrid).
        // if the remote client answers the OP_REQUESTFILENAME with OP_REQFILENAMEANSWER the file is shared by the remote client. if we
        // know that the file is shared, we know also that the file is complete and don't need to request the file status.
        if (reqfile->GetPartCount() > 1)
        {
            if (thePrefs.GetDebugClientTCPLevel() > 0)
                DebugSend("OP__SetReqFileID", this, reqfile->GetFileHash());
            CSafeMemFile dataSetReqFileID(16);
            dataSetReqFileID.WriteHash16(reqfile->GetFileHash());
            packet = new Packet(&dataSetReqFileID);
            packet->opcode = OP_SETREQFILEID;
            theStats.AddUpDataOverheadFileRequest(packet->size);
            socket->SendPacket(packet, true);
        }

        if (IsEmuleClient())
        {
            SetRemoteQueueFull(true);
            SetRemoteQueueRank(0);
        }

        if (IsSourceRequestAllowed())
        {
		    if (thePrefs.GetDebugClientTCPLevel() > 0) {
                DebugSend("OP__RequestSources", this, reqfile->GetFileHash());
                if (GetLastAskedForSources() == 0)
                    Debug(_T("  first source request\n"));
                else
                    Debug(_T("  last source request was before %s\n"), CastSecondsToHM((GetTickCount() - GetLastAskedForSources())/1000));
            }
            reqfile->SetLastAnsweredTimeTimeout();
			
			Packet* packet;
			if (SupportsSourceExchange2()){
				packet = new Packet(OP_REQUESTSOURCES2,19,OP_EMULEPROT);
				PokeUInt8(&packet->pBuffer[0], SOURCEEXCHANGE2_VERSION);
				const uint16 nOptions = 0; // 16 ... Reserved
				PokeUInt16(&packet->pBuffer[1], nOptions);
				md4cpy(&packet->pBuffer[3],reqfile->GetFileHash());
			}
			else{
				packet = new Packet(OP_REQUESTSOURCES,16,OP_EMULEPROT);
            md4cpy(packet->pBuffer,reqfile->GetFileHash());
			}

            theStats.AddUpDataOverheadSourceExchange(packet->size);
            socket->SendPacket(packet, true, true);
            SetLastAskedForSources();
            if (thePrefs.GetDebugSourceExchange())
				AddDebugLogLine(false, _T("SXSend (%s): Client source request; %s, File=\"%s\""),SupportsSourceExchange2() ? _T("Version 2") : _T("Version 1"), DbgGetClientInfo(), reqfile->GetFileName());
        }

        if (IsSupportingAICH())
        {
            if (thePrefs.GetDebugClientTCPLevel() > 0)
                DebugSend("OP__AichFileHashReq", this, reqfile->GetFileHash());
            Packet* packet = new Packet(OP_AICHFILEHASHREQ,16,OP_EMULEPROT);
            md4cpy(packet->pBuffer,reqfile->GetFileHash());
            theStats.AddUpDataOverheadFileRequest(packet->size);
            socket->SendPacket(packet,true,true);
        }
    }
    SetLastAskedTime();
}

void CUpDownClient::SendStartupLoadReq()
{
	if (socket==NULL || reqfile==NULL)
    {
        ASSERT(0);
        return;
    }
    SetDownloadState(DS_ONQUEUE);
    if (thePrefs.GetDebugClientTCPLevel() > 0)
        DebugSend("OP__StartupLoadReq", this);
    CSafeMemFile dataStartupLoadReq(16);
    dataStartupLoadReq.WriteHash16(reqfile->GetFileHash());
    Packet* packet = new Packet(&dataStartupLoadReq);
    packet->opcode = OP_STARTUPLOADREQ;
    theStats.AddUpDataOverheadFileRequest(packet->size);
	if(socket)
		socket->SendPacket(packet, true, true);
#ifdef _DEBUG
	else
		ASSERT(0);
#endif
    m_fQueueRankPending = 1;
    m_fUnaskQueueRankRecv = 0;
}

void CUpDownClient::ProcessFileInfo(CSafeMemFile* data, CPartFile* file)
{
    if (file==NULL)
        throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessFileInfo; file==NULL)");
    if (reqfile==NULL)
        throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessFileInfo; reqfile==NULL)");
    if (file != reqfile)
        throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessFileInfo; reqfile!=file)");
    m_strClientFilename = data->ReadString(GetUnicodeSupport()!=utf8strNone);
    if (thePrefs.GetDebugClientTCPLevel() > 0)
        Debug(_T("  Filename=\"%s\"\n"), m_strClientFilename);
    // 26-Jul-2003: removed requesting the file status for files <= PARTSIZE for better compatibility with ed2k protocol (eDonkeyHybrid).
    // if the remote client answers the OP_REQUESTFILENAME with OP_REQFILENAMEANSWER the file is shared by the remote client. if we
    // know that the file is shared, we know also that the file is complete and don't need to request the file status.
    if (reqfile->GetPartCount() == 1)
    {
        delete[] m_abyPartStatus;
        m_abyPartStatus = NULL;
        m_nPartCount = reqfile->GetPartCount();
        m_abyPartStatus = new uint8[m_nPartCount];
        memset(m_abyPartStatus,1,m_nPartCount);
        m_bCompleteSource = true;

        if (thePrefs.GetDebugClientTCPLevel() > 0)
        {
            int iNeeded = 0;
            UINT i;
            for (i = 0; i < m_nPartCount; i++)
            {
                if (!reqfile->IsComplete((uint64)i*PARTSIZE, ((uint64)(i+1)*PARTSIZE)-1, false))
                    iNeeded++;
            }
            char* psz = new char[m_nPartCount + 1];
            for (i = 0; i < m_nPartCount; i++)
                psz[i] = m_abyPartStatus[i] ? '#' : '.';
            psz[i] = '\0';
            Debug(_T("  Parts=%u  %hs  Needed=%u\n"), m_nPartCount, psz, iNeeded);
            delete[] psz;
        }
        UpdateDisplayedInfo();
        reqfile->UpdateAvailablePartsCount();
        // even if the file is <= PARTSIZE, we _may_ need the hashset for that file (if the file size == PARTSIZE)
        if (reqfile->hashsetneeded)
        {
            if (socket)
            {
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                    DebugSend("OP__HashSetRequest", this, reqfile->GetFileHash());
                Packet* packet = new Packet(OP_HASHSETREQUEST,16);
                md4cpy(packet->pBuffer,reqfile->GetFileHash());
                theStats.AddUpDataOverheadFileRequest(packet->size);
                socket->SendPacket(packet,true,true);
                SetDownloadState(DS_REQHASHSET);
                m_fHashsetRequesting = 1;
                reqfile->hashsetneeded = false;
            }
            else
                ASSERT(0);
        }
        else
        {
            SendStartupLoadReq();
        }
        reqfile->UpdatePartsInfo();
    }
}

void CUpDownClient::ProcessFileStatus(bool bUdpPacket, CSafeMemFile* data, CPartFile* file)
{
    if ( !reqfile || file != reqfile )
    {
        if (reqfile==NULL)
            throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessFileStatus; reqfile==NULL)");
        throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessFileStatus; reqfile!=file)");
    }
    uint16 nED2KPartCount = data->ReadUInt16();
    delete[] m_abyPartStatus;
    m_abyPartStatus = NULL;
    bool bPartsNeeded = false;
    int iNeeded = 0;
    if (!nED2KPartCount)
    {
        m_nPartCount = reqfile->GetPartCount();
        m_abyPartStatus = new uint8[m_nPartCount];
        memset(m_abyPartStatus, 1, m_nPartCount);
        bPartsNeeded = true;
        m_bCompleteSource = true;
        if (bUdpPacket ? (thePrefs.GetDebugClientUDPLevel() > 0) : (thePrefs.GetDebugClientTCPLevel() > 0))
        {
            for (UINT i = 0; i < m_nPartCount; i++)
            {
                if (!reqfile->IsComplete((uint64)i*PARTSIZE, ((uint64)(i+1)*PARTSIZE)-1, false))
                    iNeeded++;
            }
        }
    }
    else
    {
        if (reqfile->GetED2KPartCount() != nED2KPartCount)
        {
            if (thePrefs.GetVerbose())
            {
                DebugLogWarning(_T("FileName: \"%s\""), m_strClientFilename);
                DebugLogWarning(_T("FileStatus: %s"), DbgGetFileStatus(nED2KPartCount, data));
            }
            CString strError;
            strError.Format(_T("ProcessFileStatus - wrong part number recv=%u  expected=%u  %s"), nED2KPartCount, reqfile->GetED2KPartCount(), DbgGetFileInfo(reqfile->GetFileHash()));
            m_nPartCount = 0;
            throw strError;
        }
        m_nPartCount = reqfile->GetPartCount();

        m_bCompleteSource = false;
		if(NULL==m_abyPartStatus)
			m_abyPartStatus = new uint8[m_nPartCount];
        UINT done = 0;
        while (done != m_nPartCount)
        {
            uint8 toread = data->ReadUInt8();
            for (UINT i = 0; i != 8; i++)
            {
                m_abyPartStatus[done] = ((toread>>i)&1)? 1:0;
                if (m_abyPartStatus[done])
                {
                    if (!reqfile->IsComplete((uint64)done*PARTSIZE, ((uint64)(done+1)*PARTSIZE)-1, false))
                    {
                        bPartsNeeded = true;
                        iNeeded++;
                    }
                }
                done++;
                if (done == m_nPartCount)
                    break;
            }
        }
    }

    if (bUdpPacket ? (thePrefs.GetDebugClientUDPLevel() > 0) : (thePrefs.GetDebugClientTCPLevel() > 0))
    {
        TCHAR* psz = new TCHAR[m_nPartCount + 1];
        UINT i;
        for (i = 0; i < m_nPartCount; i++)
            psz[i] = m_abyPartStatus[i] ? _T('#') : _T('.');
        psz[i] = _T('\0');
        Debug(_T("  Parts=%u  %s  Needed=%u\n"), m_nPartCount, psz, iNeeded);
        delete[] psz;
    }

    UpdateDisplayedInfo(bUdpPacket);
    reqfile->UpdateAvailablePartsCount();

    // NOTE: This function is invoked from TCP and UDP socket!
    if (!bUdpPacket)
    {
        if (!bPartsNeeded)
        {
            SetDownloadState(DS_NONEEDEDPARTS);
            SwapToAnotherFile(_T("A4AF for NNP file. CUpDownClient::ProcessFileStatus() TCP"), true, false, false, NULL, true, true);
        }
        else if (reqfile->hashsetneeded) //If we are using the eMule filerequest packets, this is taken care of in the Multipacket!
        {
            if (socket)
            {
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                    DebugSend("OP__HashSetRequest", this, reqfile->GetFileHash());
                Packet* packet = new Packet(OP_HASHSETREQUEST,16);
                md4cpy(packet->pBuffer,reqfile->GetFileHash());
                theStats.AddUpDataOverheadFileRequest(packet->size);
                socket->SendPacket(packet, true, true);
                SetDownloadState(DS_REQHASHSET);
                m_fHashsetRequesting = 1;
                reqfile->hashsetneeded = false;
            }
            else
                ASSERT(0);
        }
        else
        {
           if( DS_DOWNLOADING!=m_nDownloadState )  
				SendStartupLoadReq();
        }
    }
    else
    {
        if (!bPartsNeeded)
        {
            SetDownloadState(DS_NONEEDEDPARTS);
            //SwapToAnotherFile(_T("A4AF for NNP file. CUpDownClient::ProcessFileStatus() UDP"), true, false, false, NULL, true, false);
        }
        else
            SetDownloadState(DS_ONQUEUE);
    }
    reqfile->UpdatePartsInfo();
}

bool CUpDownClient::AddRequestForAnotherFile(CPartFile* file)
{
    for (POSITION pos = m_OtherNoNeeded_list.GetHeadPosition();pos != 0;)
    {
        if (m_OtherNoNeeded_list.GetNext(pos) == file)
            return false;
    }
    for (POSITION pos = m_OtherRequests_list.GetHeadPosition();pos != 0;)
    {
        if (m_OtherRequests_list.GetNext(pos) == file)
            return false;
    }
    m_OtherRequests_list.AddTail(file);
    file->A4AFsrclist.AddTail(this); // [enkeyDEV(Ottavio84) -A4AF-]

    return true;
}

void CUpDownClient::ClearDownloadBlockRequests()
{
    for (POSITION pos = m_DownloadBlocks_list.GetHeadPosition();pos != 0;)
    {
        Requested_Block_Struct* cur_block = m_DownloadBlocks_list.GetNext(pos);
        if (reqfile /*&& !cur_block->bBlockReqHelpRobed*/ )
        {
            reqfile->RemoveBlockFromList(cur_block->StartOffset,cur_block->EndOffset);
        }
        delete cur_block;
    }
    m_DownloadBlocks_list.RemoveAll();

    for (POSITION pos = m_PendingBlocks_list.GetHeadPosition();pos != 0;)
    {
        Pending_Block_Struct *pending = m_PendingBlocks_list.GetNext(pos);
        if (reqfile /*&& !pending->block->bBlockReqHelpRobed*/ )
        {
            reqfile->RemoveBlockFromList(pending->block->StartOffset, pending->block->EndOffset);
        }

        delete pending->block;
        // Not always allocated
        if (pending->zStream)
        {
            inflateEnd(pending->zStream);
            delete pending->zStream;
        }
        delete pending;
    }
    m_PendingBlocks_list.RemoveAll();
}

void CUpDownClient::RemoveDownloadBlockRequests( uint32 iBlockS, uint32 iBlockE )
{
	POSITION pos1, pos2;
	for (pos1 = m_DownloadBlocks_list.GetHeadPosition();(pos2 = pos1)!= 0;)
	{
		Requested_Block_Struct* cur_block = m_DownloadBlocks_list.GetNext(pos1);
		if( reqfile && cur_block->BlockIdx>=iBlockS && cur_block->BlockIdx<=iBlockE )
		{
#ifdef _DEBUG_PEER
			Debug( _T("Peer(%d) RemoveDownloadBlockRequests(%d) \n"),m_iPeerIndex,cur_block->BlockIdx );
#endif
			reqfile->RemoveBlockFromList(cur_block->StartOffset,cur_block->EndOffset);
			delete cur_block;
			m_DownloadBlocks_list.RemoveAt(pos2);
		}
	}	

	for (pos1 = m_PendingBlocks_list.GetHeadPosition();(pos2 = pos1)!= 0;)
	{
		Pending_Block_Struct *pending = m_PendingBlocks_list.GetNext(pos1);
		if( reqfile && pending->block->BlockIdx>=iBlockS && pending->block->BlockIdx<=iBlockE )
		{
			reqfile->RemoveBlockFromList(pending->block->StartOffset, pending->block->EndOffset);
#ifdef _DEBUG_PEER
			Debug( _T("Peer(%d) RemoveDownloadBlockRequests(%) \n"),m_iPeerIndex,pending->block->BlockIdx );
#endif
			delete pending->block;
			delete pending;
			m_PendingBlocks_list.RemoveAt(pos2);
		}
	}	
}

void CUpDownClient::SetDownloadState(EDownloadState nNewState, LPCTSTR pszReason)
{
#ifdef _DEBUG_PEER
/*
	if( !(m_nDownloadState==DS_TOOMANYCONNS && nNewState==DS_CONNECTING ) && 
		!(m_nDownloadState==DS_CONNECTING && nNewState==DS_TOOMANYCONNS) ) */
		Debug( _T("Peer(%d) SetDownloadState from(%2d) to(%2d) \n"),m_iPeerIndex,m_nDownloadState,nNewState );
#endif

	if (m_nDownloadState != nNewState)
    {
        switch ( nNewState )
        {
        case DS_CONNECTING:
            m_dwLastTriedToConnect = ::GetTickCount();
            break;
		case DS_ERROR:
			if( (m_iPeerType&ptINet)!=0 ) //this is a INet Peer
			{
//				m_iErrTimes++;
				break;
			}
        case DS_TOOMANYCONNSKAD:
            //This client had already been set to DS_CONNECTING.
            //So we reset this time so it isn't stuck at TOOMANYCONNS for 20mins.
            m_dwLastTriedToConnect = ::GetTickCount()-20*60*1000;
            break;
		case DS_CONNECTED:
        case DS_WAITCALLBACKKAD:
        case DS_WAITCALLBACK:
            break;
        case DS_NONEEDEDPARTS:
			{
				// Since tcp asks never sets reask time if the result is DS_NONEEDEDPARTS
				// If we set this, we will not reask for that file until some time has passed.
				SetLastAskedTime();
				//DontSwapTo(reqfile);

				if( (m_iPeerType&ptINet)!=0 )
					ClearDownloadBlockRequests();
			}
        default:
            switch ( m_nDownloadState )
            {
            case DS_WAITCALLBACK:
            case DS_WAITCALLBACKKAD:
                break;
            default:
                m_dwLastTriedToConnect = ::GetTickCount()-20*60*1000;
                break;
            }
            break;
        }

        if (reqfile)
        {
            if (nNewState == DS_DOWNLOADING)
            {
                if (thePrefs.GetLogUlDlEvents())
                    AddDebugLogLine(DLP_VERYLOW, false, _T("Download session started. User: %s in SetDownloadState(). New State: %i"), DbgGetClientInfo(), nNewState);

                reqfile->AddDownloadingSource(this);
            }
            else if (m_nDownloadState == DS_DOWNLOADING)
            {
                reqfile->RemoveDownloadingSource(this);
            }
        }

        if (nNewState == DS_DOWNLOADING && socket)
        {
            socket->SetTimeOut(CONNECTION_TIMEOUT*4);
        }

        if (m_nDownloadState == DS_DOWNLOADING )
        {
            if (socket)
                socket->SetTimeOut(CONNECTION_TIMEOUT);

            if (thePrefs.GetLogUlDlEvents())
            {
                switch ( nNewState )
                {
                case DS_NONEEDEDPARTS:
                    pszReason = _T("NNP. You don't need any parts from this client.");
                }

                if (thePrefs.GetLogUlDlEvents())
                    AddDebugLogLine(DLP_VERYLOW, false, _T("Download session ended: %s User: %s in SetDownloadState(). New State: %i, Length: %s, Payload: %s, Transferred: %s, Req blocks not yet completed: %i."), pszReason, DbgGetClientInfo(), nNewState, CastSecondsToHM(GetDownTimeDifference(false)/1000), CastItoXBytes(GetSessionPayloadDown(), false, false), CastItoXBytes(GetSessionDown(), false, false), m_PendingBlocks_list.GetCount());
            }

            ResetSessionDown();

            // -khaos--+++> Extended Statistics (Successful/Failed Download Sessions)
            if ( m_bTransferredDownMini && nNewState != DS_ERROR )
                thePrefs.Add2DownSuccessfulSessions(); // Increment our counters for successful sessions (Cumulative AND Session)
            else
                thePrefs.Add2DownFailedSessions(); // Increment our counters failed sessions (Cumulative AND Session)
            thePrefs.Add2DownSAvgTime(GetDownTimeDifference()/1000);
            // <-----khaos-

            m_nDownloadState = (_EDownloadState)nNewState;

            ClearDownloadBlockRequests();

			if( m_pBlockRangeToDo )
				m_pBlockRangeToDo->m_iBlockLastReqed = min(m_pBlockRangeToDo->m_iBlockLastReqed,m_pBlockRangeToDo->m_iBlockCurrentDoing);

			if(m_nDownDatarate<m_nDownDatarateOfPreTransfer)
				m_nDownDatarateOfPreTransfer = (m_nDownDatarateOfPreTransfer+m_nDownloadState)/2;
			else
				m_nDownDatarateOfPreTransfer = m_nDownDatarate;
			m_nDownDatarate = 0;
            m_AvarageDDR_list.RemoveAll();
            m_nSumForAvgDownDataRate = 0;
			m_nDownDataRateMS = 0;
		
            if (nNewState == DS_NONE)
            {
                delete[] m_abyPartStatus;
                m_abyPartStatus = NULL;
                m_nPartCount = 0;
            }
            if (socket && nNewState != DS_ERROR )
                socket->DisableDownloadLimit();
        }
        m_nDownloadState = (_EDownloadState)nNewState;
        if ( GetDownloadState() == DS_DOWNLOADING )
        {
            if ( IsEmuleClient() )
                SetRemoteQueueFull(false);
            SetRemoteQueueRank(0);
            SetAskedCountDown(0);
			m_iErrTimes =0; //< 该Peer的网络状况恢复正常
        }
        UpdateDisplayedInfo(true);
    }
}

void CUpDownClient::ProcessHashSet(const uchar* packet,uint32 size)
{
    if (!m_fHashsetRequesting)
        throw CString(_T("unwanted hashset"));
    if ( (!reqfile) || md4cmp(packet,reqfile->GetFileHash()))
    {
        CheckFailedFileIdReqs(packet);
        throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessHashSet)");
    }
    CSafeMemFile data(packet, size);
    if (reqfile->LoadHashsetFromFile(&data,true))
    {
        m_fHashsetRequesting = 0;
    }
    else
    {
        reqfile->hashsetneeded = true;
        throw GetResString(IDS_ERR_BADHASHSET);
    }
    SendStartupLoadReq();
}

void CUpDownClient::CreateBlockRequests(int iMaxBlocks)
{
	ASSERT( iMaxBlocks >= 1 /*&& iMaxBlocks <= 3*/ );

	int iPendingCount = m_PendingBlocks_list.GetCount(); 

	iMaxBlocks = CreateBlockRequests_Before(iMaxBlocks);
	if(iMaxBlocks < 1)
		return;

	CreateBlockRequests_Process(iMaxBlocks, false);

	CreateBlockRequests_After(iMaxBlocks);

	if( !m_PendingBlocks_list.IsEmpty() && m_PendingBlocks_list.GetCount()>iPendingCount )
		m_LastGetBlockReqTime = ::GetTickCount();
}

void CUpDownClient::CreateBlockRequestsOrg(int iMaxBlocks)
{
	ASSERT( iMaxBlocks >= 1 /*&& iMaxBlocks <= 3*/ );

	int iPendingCount = m_PendingBlocks_list.GetCount(); 

	iMaxBlocks = CUpDownClient::CreateBlockRequests_Before(iMaxBlocks);
	if(iMaxBlocks < 1)
		return;

	CUpDownClient::CreateBlockRequests_Process(iMaxBlocks, true);

	CUpDownClient::CreateBlockRequests_After(iMaxBlocks);

	if( !m_PendingBlocks_list.IsEmpty() && m_PendingBlocks_list.GetCount()>iPendingCount )
		m_LastGetBlockReqTime = ::GetTickCount();
}

void CUpDownClient::CreateBlockRequests_Process(int iMaxBlocks, bool bUseParent)
{
	if (m_DownloadBlocks_list.IsEmpty())
	{
		uint16 count;
		if (iMaxBlocks > m_PendingBlocks_list.GetCount())
		{
			count = (uint16)(iMaxBlocks - m_PendingBlocks_list.GetCount());
		}
		else
		{
			count = 0;
		}

		if (count)
		{
			Requested_Block_Struct** toadd = new Requested_Block_Struct*[count]; //不一定能领取到 count 个,有些可能被ed peer已经领走或做完了
			if( RequestBlock(toadd,&count,bUseParent) )
			{
				for (UINT i = 0; i < count; i++)
					m_DownloadBlocks_list.AddTail(toadd[i]);
			}
			delete[] toadd;		
		}
	}

	while (m_PendingBlocks_list.GetCount() < iMaxBlocks && !m_DownloadBlocks_list.IsEmpty())
	{
		Pending_Block_Struct* pblock = new Pending_Block_Struct;
		pblock->block = m_DownloadBlocks_list.RemoveHead();
		m_PendingBlocks_list.AddTail(pblock);
	}
}

int CUpDownClient::CreateBlockRequests_Before(int iMaxBlocks)
{
	return iMaxBlocks;
}

void CUpDownClient::CreateBlockRequests_After(int iMaxBlocks)
{
	if( this->m_PendingBlocks_list.IsEmpty() )
	{
		// 没有分配到任务
		if (m_DownloadBlocks_list.IsEmpty())
		{
			uint16 count;
			if (iMaxBlocks > m_PendingBlocks_list.GetCount())
			{
				count = (uint16)(iMaxBlocks - m_PendingBlocks_list.GetCount());
			}
			else
			{
				count = 0;
			}

			if (count)
			{
				if( (m_iPeerType&ptINet)==0 || GetDownloadState()!=DS_CONNECTING
					|| m_iErrTimes==0 || 0==reqfile->GetDatarate() ) /// http/ftp已经连接出错了，在连接分配的时候分配不到就不要再抢任务,其它情况可以抢
					reqfile->OnCannotAllocateMission(this);
/*
				Requested_Block_Struct** toadd = new Requested_Block_Struct*[count];
				if (reqfile->OnCannotAllocateMission(this, toadd, &count))
				{
					for (UINT i = 0; i < count; i++)
						m_DownloadBlocks_list.AddTail(toadd[i]);
				}
				delete[] toadd;
*/
			}
		}

	}

#ifdef _DEBUG_PEER
	TRACE( "%s-Peer(%d),PendingBlocksCount=%d,DownloadBlocksCount=%d \n",__FUNCTION__,m_iPeerIndex,m_PendingBlocks_list.GetCount(),m_DownloadBlocks_list.GetCount());
#endif
}

void CUpDownClient::SendBlockRequests()
{
    if (thePrefs.GetDebugClientTCPLevel() > 0)
        DebugSend("OP__RequestParts", this, reqfile!=NULL ? reqfile->GetFileHash() : NULL);

    m_dwLastBlockReceived = ::GetTickCount();
    if (!reqfile)
        return;

    // prevent locking of too many blocks when we are on a slow (probably standby/trickle) slot
    int blockCount = 3;
    if (IsEmuleClient() && m_byCompatibleClient==0 && reqfile->GetFileSize()-reqfile->GetCompletedSize() <= (uint64)PARTSIZE*4)
    {
        // if there's less than two chunks left, request fewer blocks for
        // slow downloads, so they don't lock blocks from faster clients.
        // Only trust eMule clients to be able to handle less blocks than three
        if (GetDownloadDatarate() < 600 || GetSessionPayloadDown() < 40*1024)
        {
            blockCount = 1;
        }
        else if (GetDownloadDatarate() < 1200)
        {
            blockCount = 2;
        }
    }
    CreateBlockRequests(blockCount);

    if (m_PendingBlocks_list.IsEmpty())
    {
        SendCancelTransfer();
        SetDownloadState(DS_NONEEDEDPARTS);
        SwapToAnotherFile(_T("A4AF for NNP file. CUpDownClient::SendBlockRequests()"), true, false, false, NULL, true, true);
        return;
    }

    bool bI64Offsets = false;
    POSITION pos = m_PendingBlocks_list.GetHeadPosition();
    for (uint32 i = 0; i != 3; i++)
    {
        POSITION posLast = pos;
		if (pos)
        {
            Pending_Block_Struct* pending = m_PendingBlocks_list.GetNext(pos);
            ASSERT( pending->block->StartOffset <= pending->block->EndOffset );
            if (pending->block->StartOffset > 0xFFFFFFFF || pending->block->EndOffset >= 0xFFFFFFFF)
            {
                bI64Offsets = true;
                if (!SupportsLargeFiles())
                {
                    ASSERT( false );
                    SendCancelTransfer();
                    SetDownloadState(DS_ERROR);
                }
                break;
            }

			if( reqfile && reqfile->IsComplete(pending->block->StartOffset,pending->block->EndOffset,false) )
			{
				delete pending->block;
				if (pending->zStream)
				{
					inflateEnd(pending->zStream);
					delete pending->zStream;
				}
				delete pending;
				m_PendingBlocks_list.RemoveAt(posLast);
			}
        }
    }

    Packet* packet;
    if (bI64Offsets)
    {
        const int iPacketSize = 16+(3*8)+(3*8); // 64
        packet = new Packet(OP_REQUESTPARTS_I64, iPacketSize, OP_EMULEPROT);
        CSafeMemFile data((const BYTE*)packet->pBuffer, iPacketSize);
        data.WriteHash16(reqfile->GetFileHash());
        pos = m_PendingBlocks_list.GetHeadPosition();
        for (uint32 i = 0; i != 3; i++)
        {
            if (pos)
            {
                Pending_Block_Struct* pending = m_PendingBlocks_list.GetNext(pos);
                ASSERT( pending->block->StartOffset <= pending->block->EndOffset );
                //ASSERT( pending->zStream == NULL );
                //ASSERT( pending->totalUnzipped == 0 );
                pending->fZStreamError = 0;
                pending->fRecovered = 0;
                data.WriteUInt64(pending->block->StartOffset);
            }
            else
                data.WriteUInt64(0);
        }
        pos = m_PendingBlocks_list.GetHeadPosition();
        for (uint32 i = 0; i != 3; i++)
        {
            if (pos)
            {
                Requested_Block_Struct* block = m_PendingBlocks_list.GetNext(pos)->block;
                uint64 endpos = block->EndOffset+1;
                data.WriteUInt64(endpos);
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                {
                    CString strInfo;
                    strInfo.Format(_T("  Block request %u: "), i);
                    strInfo += DbgGetBlockInfo(block);
                    strInfo.AppendFormat(_T(",  Complete=%s"), reqfile->IsComplete(block->StartOffset, block->EndOffset, false) ? _T("Yes(NOTE:)") : _T("No"));
                    strInfo.AppendFormat(_T(",  PureGap=%s"), reqfile->IsPureGap(block->StartOffset, block->EndOffset) ? _T("Yes") : _T("No(NOTE:)"));
                    strInfo.AppendFormat(_T(",  AlreadyReq=%s"), reqfile->IsAlreadyRequested(block->StartOffset, block->EndOffset) ? _T("Yes") : _T("No(NOTE:)"));
                    strInfo += _T('\n');
                    Debug(strInfo);
                }
            }
            else
            {
                data.WriteUInt64(0);
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                    Debug(_T("  Block request %u: <empty>\n"), i);
            }
        }
    }
    else
    {
        const int iPacketSize = 16+(3*4)+(3*4); // 40
        packet = new Packet(OP_REQUESTPARTS,iPacketSize);
        CSafeMemFile data((const BYTE*)packet->pBuffer, iPacketSize);
        data.WriteHash16(reqfile->GetFileHash());
        pos = m_PendingBlocks_list.GetHeadPosition();
#ifdef TRACE_BLOCK_PACKET
		uint32 iStart[3];
#endif
        for (uint32 i = 0; i != 3; i++)
        {
            if (pos)
            {
                Pending_Block_Struct* pending = m_PendingBlocks_list.GetNext(pos);
                ASSERT( pending->block->StartOffset <= pending->block->EndOffset );
                //ASSERT( pending->zStream == NULL );
                //ASSERT( pending->totalUnzipped == 0 );
                pending->fZStreamError = 0;
                pending->fRecovered = 0;
                data.WriteUInt32((uint32)pending->block->StartOffset);
#ifdef TRACE_BLOCK_PACKET
				iStart[i] = (uint32)pending->block->StartOffset;
#endif
            }
            else
                data.WriteUInt32(0);

        }
        pos = m_PendingBlocks_list.GetHeadPosition();
        for (uint32 i = 0; i != 3; i++)
        {
            if (pos)
            {
                Requested_Block_Struct* block = m_PendingBlocks_list.GetNext(pos)->block;
                uint64 endpos = block->EndOffset+1;
                data.WriteUInt32((uint32)endpos);
#ifdef TRACE_BLOCK_PACKET				
				CString sTempLog;
				sTempLog.Format(_T("RequestData: %u-%u"), iStart[i], block->EndOffset);
				AddPeerLog(new CTraceSendMessage(sTempLog));
#endif
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                {
                    CString strInfo;
                    strInfo.Format(_T(" Peer(%d) Block request %u: "),m_iPeerIndex, i);
                    strInfo += DbgGetBlockInfo(block);
                    strInfo.AppendFormat(_T(",  Complete=%s"), reqfile->IsComplete(block->StartOffset, block->EndOffset, false) ? _T("Yes(NOTE:)") : _T("No"));
                    strInfo.AppendFormat(_T(",  PureGap=%s"), reqfile->IsPureGap(block->StartOffset, block->EndOffset) ? _T("Yes") : _T("No(NOTE:)"));
                    strInfo.AppendFormat(_T(",  AlreadyReq=%s"), reqfile->IsAlreadyRequested(block->StartOffset, block->EndOffset) ? _T("Yes") : _T("No(NOTE:)"));
                    strInfo += _T('\n');
                    Debug(strInfo);
                }
            }
            else
            {
                data.WriteUInt32(0);
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                    Debug(_T("  Block request %u: <empty>\n"), i);
            }
        }
    }

    theStats.AddUpDataOverheadFileRequest(packet->size);
    socket->SendPacket(packet,true,true);
}

/* Barry - Originally this only wrote to disk when a full 180k block
           had been received from a client, and only asked for data in
		   180k blocks.

		   This meant that on average 90k was lost for every connection
		   to a client data source. That is a lot of wasted data.

		   To reduce the lost data, packets are now written to a buffer
		   and flushed to disk regularly regardless of size downloaded.
		   This includes compressed packets.

		   Data is also requested only where gaps are, not in 180k blocks.
		   The requests will still not exceed 180k, but may be smaller to
		   fill a gap.
*/
void CUpDownClient::ProcessBlockPacket(const uchar *packet, uint32 size, bool packed, bool bI64Offsets)
{
    if (!bI64Offsets)
    {
        uint32 nDbgStartPos = *((uint32*)(packet+16));
        if (thePrefs.GetDebugClientTCPLevel() > 1)
        {
            if (packed)
                Debug(_T("  Start=%u  BlockSize=%u  Size=%u  %s\n"), nDbgStartPos, *((uint32*)(packet + 16+4)), size-24, DbgGetFileInfo(packet));
            else
                Debug(_T("  Start=%u  End=%u  Size=%u  %s\n"), nDbgStartPos, *((uint32*)(packet + 16+4)), *((uint32*)(packet + 16+4)) - nDbgStartPos, DbgGetFileInfo(packet));
        }
    }

    // Ignore if no data required
    if (!(GetDownloadState() == DS_DOWNLOADING || GetDownloadState() == DS_NONEEDEDPARTS))
    {
        TRACE("%s - Invalid download state\n", __FUNCTION__);
        return;
    }



    // Update stats
    m_dwLastBlockReceived = ::GetTickCount();

    // Read data from packet
    CSafeMemFile data(packet, size);
    uchar fileID[16];
    data.ReadHash16(fileID);
    int nHeaderSize = 16;

    // Check that this data is for the correct file
    if ( (!reqfile) || md4cmp(packet, reqfile->GetFileHash()))
    {
        throw GetResString(IDS_ERR_WRONGFILEID) + _T(" (ProcessBlockPacket)");
    }

    // Find the start & end positions, and size of this chunk of data
    uint64 nStartPos;
    uint64 nEndPos;
    uint32 nBlockSize = 0;

    if (bI64Offsets)
    {
        nStartPos = data.ReadUInt64();
        nHeaderSize += 8;
    }
    else
    {
        nStartPos = data.ReadUInt32();
        nHeaderSize += 4;
    }
    if (packed)
    {
        nBlockSize = data.ReadUInt32();
        nHeaderSize += 4;
        nEndPos = nStartPos + (size - nHeaderSize);
    }
    else
    {
        if (bI64Offsets)
        {
            nEndPos = data.ReadUInt64();
            nHeaderSize += 8;
        }
        else
        {
            nEndPos = data.ReadUInt32();
            nHeaderSize += 4;
        }
    }
    uint32 uTransferredFileDataSize = size - nHeaderSize;

    // Check that packet size matches the declared data size + header size (24)
    if (nEndPos == nStartPos || size != ((nEndPos - nStartPos) + nHeaderSize))
        throw GetResString(IDS_ERR_BADDATABLOCK) + _T(" (ProcessBlockPacket)");

    // -khaos--+++>
    // Extended statistics information based on which client and remote port sent this data.
    // The new function adds the bytes to the grand total as well as the given client/port.
    // bFromPF is not relevant to downloaded data.  It is purely an uploads statistic.
    thePrefs.Add2SessionTransferData(GetClientSoft(), GetUserPort(), false, false, uTransferredFileDataSize, false);
    // <-----khaos-

    m_nDownDataRateMS += uTransferredFileDataSize;

    // Move end back one, should be inclusive
    nEndPos--;

    // Loop through to find the reserved block that this is within
	for (POSITION pos = m_PendingBlocks_list.GetHeadPosition(); pos != NULL; )
	{
		POSITION posLast = pos;
		Pending_Block_Struct *cur_block = m_PendingBlocks_list.GetNext(pos);
		if ((cur_block->block->StartOffset <= nStartPos) && (cur_block->block->EndOffset >= nStartPos))
		{
			// Found reserved block

			if (cur_block->fZStreamError)
			{
				if (thePrefs.GetVerbose())
					AddDebugLogLine(false, _T("PrcBlkPkt: Ignoring %u bytes of block starting at %u because of errornous zstream state for file \"%s\" - %s"), uTransferredFileDataSize, nStartPos, reqfile->GetFileName(), DbgGetClientInfo());
				reqfile->RemoveBlockFromList(cur_block->block->StartOffset, cur_block->block->EndOffset);
				return;
			}

			// Remember this start pos, used to draw part downloading in list
			m_nLastBlockOffset = nStartPos;

			// Occasionally packets are duplicated, no point writing it twice
			// This will be 0 in these cases, or the length written otherwise
			uint32 lenWritten = 0;

			// Handle differently depending on whether packed or not
			if (!packed)
			{
				// Write to disk (will be buffered in part file class)
				lenWritten = reqfile->WriteToBuffer(uTransferredFileDataSize,
					packet + nHeaderSize,
					nStartPos,
					nEndPos,
					cur_block->block,
					this);
			}
			else // Packed
			{
				ASSERT( (int)size > 0 );
				// Create space to store unzipped data, the size is only an initial guess, will be resized in unzip() if not big enough
				uint32 lenUnzipped = (size * 2);
				// Don't get too big
				if (lenUnzipped > (EMBLOCKSIZE + 300))
					lenUnzipped = (EMBLOCKSIZE + 300);
				BYTE *unzipped = new BYTE[lenUnzipped];

				// Try to unzip the packet
				int result = unzip(cur_block, packet + nHeaderSize, uTransferredFileDataSize, &unzipped, &lenUnzipped);
				// no block can be uncompressed to >2GB, 'lenUnzipped' is obviously errornous.
				if (result == Z_OK && (int)lenUnzipped >= 0)
				{
					if (lenUnzipped > 0) // Write any unzipped data to disk
					{
						ASSERT( (int)lenUnzipped > 0 );

						// Use the current start and end positions for the uncompressed data
						nStartPos = cur_block->block->StartOffset + cur_block->totalUnzipped - lenUnzipped;
						nEndPos = cur_block->block->StartOffset + cur_block->totalUnzipped - 1;

						if (nStartPos > cur_block->block->EndOffset || nEndPos > cur_block->block->EndOffset)
						{
							if (thePrefs.GetVerbose())
								DebugLogError(_T("PrcBlkPkt: ") + GetResString(IDS_ERR_CORRUPTCOMPRPKG),reqfile->GetFileName(),666);
							reqfile->RemoveBlockFromList(cur_block->block->StartOffset, cur_block->block->EndOffset);
							// There is no chance to recover from this error
						}
						else
						{
							// Write uncompressed data to file
							lenWritten = reqfile->WriteToBuffer(uTransferredFileDataSize,
								unzipped,
								nStartPos,
								nEndPos,
								cur_block->block,
								this);
							if(lenUnzipped>uTransferredFileDataSize)
							{
								m_nDownDataRateMS += (lenUnzipped-uTransferredFileDataSize);
							}							
						}
					}
				}
				else
				{
					if (thePrefs.GetVerbose())
					{
						CString strZipError;
						if (cur_block->zStream && cur_block->zStream->msg)
							strZipError.Format(_T(" - %hs"), cur_block->zStream->msg);
						if (result == Z_OK && (int)lenUnzipped < 0)
						{
							ASSERT(0);
							strZipError.AppendFormat(_T("; Z_OK,lenUnzipped=%d"), lenUnzipped);
						}
						DebugLogError(_T("PrcBlkPkt: ") + GetResString(IDS_ERR_CORRUPTCOMPRPKG) + strZipError, reqfile->GetFileName(), result);
					}
					reqfile->RemoveBlockFromList(cur_block->block->StartOffset, cur_block->block->EndOffset);

					// If we had an zstream error, there is no chance that we could recover from it nor that we
					// could use the current zstream (which is in error state) any longer.
					if (cur_block->zStream)
					{
						inflateEnd(cur_block->zStream);
						delete cur_block->zStream;
						cur_block->zStream = NULL;
					}

					// Although we can't further use the current zstream, there is no need to disconnect the sending
					// client because the next zstream (a series of 10K-blocks which build a 180K-block) could be
					// valid again. Just ignore all further blocks for the current zstream.
					cur_block->fZStreamError = 1;
					cur_block->totalUnzipped = 0;
				}
				delete [] unzipped;
			}

			// These checks only need to be done if any data was written
			if (lenWritten >= 0)
			{
				m_nTransferredDown += uTransferredFileDataSize;
				m_nCurSessionPayloadDown += lenWritten;
				SetTransferredDownMini();
				if (credits)
					credits->AddDownloaded(uTransferredFileDataSize, GetIP());

			

				// If finished reserved block
				if (nEndPos == cur_block->block->EndOffset)
				{
					reqfile->RemoveBlockFromList(cur_block->block->StartOffset, cur_block->block->EndOffset);
#ifdef _DEBUG_PEER
					Debug( _T("Peer(%d)-speed(%d)-lenWritten(%d) ED2K Finished BlockJob(%d):%I64u-%I64u \n"),m_iPeerIndex,GetDownloadDatarate(),lenWritten,cur_block->block->BlockIdx,cur_block->block->StartOffset,cur_block->block->EndOffset );
#endif
					delete cur_block->block;
					// Not always allocated
					if (cur_block->zStream)
					{
						inflateEnd(cur_block->zStream);
						delete cur_block->zStream;
					}
					delete cur_block;
					m_PendingBlocks_list.RemoveAt(posLast);

					// Request next block
					if (thePrefs.GetDebugClientTCPLevel() > 0)
						DebugSend("More block requests", this);
					SendBlockRequests();
				}
			}

            // Stop looping and exit method
            return;
        }
    }
#ifdef TRACE_BLOCK_PACKET
	CString sTempLog;
	sTempLog.Format(_T("Peer(%d) Dropping packet(%I64u-%I64u)-totalbytes=%d \n",m_iPeerIndex,nStartPos,nEndPos,size));
	AddPeerLog(new CTraceError(sTempLog));
#endif
	TRACE("%s - Peer(%d) Dropping packet(%I64u-%I64u)-totalbytes=%d \n", __FUNCTION__,m_iPeerIndex,nStartPos,nEndPos,size);
}

int CUpDownClient::unzip(Pending_Block_Struct* block, const BYTE* zipped, uint32 lenZipped, BYTE** unzipped, uint32* lenUnzipped, int iRecursion)
{
#define TRACE_UNZIP	/*TRACE*/

    TRACE_UNZIP("unzip: Zipd=%6u Unzd=%6u Rcrs=%d", lenZipped, *lenUnzipped, iRecursion);
    int err = Z_DATA_ERROR;
    try
    {
        // Save some typing
        z_stream *zS = block->zStream;

        // Is this the first time this block has been unzipped
        if (zS == NULL)
        {
            // Create stream
            block->zStream = new z_stream;
            zS = block->zStream;

            // Initialise stream values
            zS->zalloc = (alloc_func)0;
            zS->zfree = (free_func)0;
            zS->opaque = (voidpf)0;

            // Set output data streams, do this here to avoid overwriting on recursive calls
            zS->next_out = (*unzipped);
            zS->avail_out = (*lenUnzipped);

            // Initialise the z_stream
            err = inflateInit(zS);
            if (err != Z_OK)
            {
                TRACE_UNZIP("; Error: new stream failed: %d\n", err);
                return err;
            }

            ASSERT( block->totalUnzipped == 0 );
        }

        // Use whatever input is provided
        zS->next_in	 = const_cast<Bytef*>(zipped);
        zS->avail_in = lenZipped;

        // Only set the output if not being called recursively
        if (iRecursion == 0)
        {
            zS->next_out = (*unzipped);
            zS->avail_out = (*lenUnzipped);
        }

        // Try to unzip the data
        TRACE_UNZIP("; inflate(ain=%6u tin=%6u aout=%6u tout=%6u)", zS->avail_in, zS->total_in, zS->avail_out, zS->total_out);
        err = inflate(zS, Z_SYNC_FLUSH);

        // Is zip finished reading all currently available input and writing all generated output
        if (err == Z_STREAM_END)
        {
            // Finish up
            err = inflateEnd(zS);
            if (err != Z_OK)
            {
                TRACE_UNZIP("; Error: end stream failed: %d\n", err);
                return err;
            }
            TRACE_UNZIP("; Z_STREAM_END\n");

            // Got a good result, set the size to the amount unzipped in this call (including all recursive calls)
            (*lenUnzipped) = (zS->total_out - block->totalUnzipped);
            block->totalUnzipped = zS->total_out;
        }
        else if ((err == Z_OK) && (zS->avail_out == 0) && (zS->avail_in != 0))
        {
            // Output array was not big enough, call recursively until there is enough space
            TRACE_UNZIP("; output array not big enough (ain=%u)\n", zS->avail_in);

            // What size should we try next
            uint32 newLength = (*lenUnzipped) *= 2;
            if (newLength == 0)
                newLength = lenZipped * 2;

            // Copy any data that was successfully unzipped to new array
            BYTE *temp = new BYTE[newLength];
            ASSERT( zS->total_out - block->totalUnzipped <= newLength );
            memcpy(temp, (*unzipped), (zS->total_out - block->totalUnzipped));
            delete[] (*unzipped);
            (*unzipped) = temp;
            (*lenUnzipped) = newLength;

            // Position stream output to correct place in new array
            zS->next_out = (*unzipped) + (zS->total_out - block->totalUnzipped);
            zS->avail_out = (*lenUnzipped) - (zS->total_out - block->totalUnzipped);

            // Try again
            err = unzip(block, zS->next_in, zS->avail_in, unzipped, lenUnzipped, iRecursion + 1);
        }
        else if ((err == Z_OK) && (zS->avail_in == 0))
        {
            TRACE_UNZIP("; all input processed\n");
            // All available input has been processed, everything ok.
            // Set the size to the amount unzipped in this call (including all recursive calls)
            (*lenUnzipped) = (zS->total_out - block->totalUnzipped);
            block->totalUnzipped = zS->total_out;
        }
        else
        {
            // Should not get here unless input data is corrupt
            if (thePrefs.GetVerbose())
            {
                CString strZipError;
                if (zS->msg)
                    strZipError.Format(_T(" %d: '%hs'"), err, zS->msg);
                else if (err != Z_OK)
                    strZipError.Format(_T(" %d: '%hs'"), err, zError(err));
                TRACE_UNZIP("; Error: %s\n", strZipError);
                DebugLogError(_T("Unexpected zip error%s in file \"%s\""), strZipError, reqfile ? reqfile->GetFileName() : NULL);
            }
        }

        if (err != Z_OK)
            (*lenUnzipped) = 0;
    }
    catch (...)
    {
        if (thePrefs.GetVerbose())
            DebugLogError(_T("Unknown exception in %hs: file \"%s\""), __FUNCTION__, reqfile ? reqfile->GetFileName() : NULL);
        err = Z_DATA_ERROR;
        ASSERT(0);
    }

    return err;
}

uint32 CUpDownClient::CalculateDownloadRate()
{
    // Patch By BadWolf - Accurate datarate Calculation
    TransferredData newitem = {m_nDownDataRateMS,::GetTickCount()};
    m_AvarageDDR_list.AddTail(newitem);
    m_nSumForAvgDownDataRate += m_nDownDataRateMS;
    m_nDownDataRateMS = 0;

    while (m_AvarageDDR_list.GetCount()>500)
        m_nSumForAvgDownDataRate -= m_AvarageDDR_list.RemoveHead().datalen;

    if (m_AvarageDDR_list.GetCount() > 1)
    {
        DWORD dwDuration = m_AvarageDDR_list.GetTail().timestamp - m_AvarageDDR_list.GetHead().timestamp;
        if (dwDuration)
            m_nDownDatarate = (UINT)(1000U * (ULONGLONG)m_nSumForAvgDownDataRate / dwDuration);
    }
    else
        m_nDownDatarate = 0;
    // END Patch By BadWolf
    m_cShowDR++;
    if (m_cShowDR == 30)
    {
        m_cShowDR = 0;
        UpdateDisplayedInfo();
    }

    return m_nDownDatarate;
}

void CUpDownClient::CheckDownloadTimeout()
{
    if (IsDownloadingFromPeerCache() && m_pPCDownSocket && m_pPCDownSocket->IsConnected())
    {
        ASSERT( DOWNLOADTIMEOUT < m_pPCDownSocket->GetTimeOut() );
        if (GetTickCount() - m_dwLastBlockReceived > DOWNLOADTIMEOUT)
        {
            OnPeerCacheDownSocketTimeout();
        }
    }
    else
    {
        if ((::GetTickCount() - m_dwLastBlockReceived) > DOWNLOADTIMEOUT)
        {
            ASSERT( socket != NULL );
            if (socket != NULL)
            {
                //ASSERT( !socket->IsRawDataMode() );
                if (!socket->IsRawDataMode())
                    SendCancelTransfer();
            }
            SetDownloadState(DS_ONQUEUE, _T("Timeout. More than 100 seconds since last complete block was received."));
        }
    }
}

uint16 CUpDownClient::GetAvailablePartCount() const
{
    UINT result = 0;
    for (UINT i = 0; i < m_nPartCount; i++)
    {
        if (IsPartAvailable(i))
            result++;
    }
    return (uint16)result;
}

void CUpDownClient::SetRemoteQueueRank(UINT nr, bool bUpdateDisplay)
{
    m_nRemoteQueueRank = nr;
    UpdateDisplayedInfo(bUpdateDisplay);
}

void CUpDownClient::UDPReaskACK(uint16 nNewQR)
{
    m_bUDPPending = false;
    SetRemoteQueueRank(nNewQR, true);
    SetLastAskedTime();
}

void CUpDownClient::UDPReaskFNF()
{
    m_bUDPPending = false;
    if (GetDownloadState() != DS_DOWNLOADING)
    { // avoid premature deletion of 'this' client
        if (thePrefs.GetVerbose())
            AddDebugLogLine(DLP_LOW, false, _T("UDP FNF-Answer: %s - %s"),DbgGetClientInfo(), DbgGetFileInfo(reqfile ? reqfile->GetFileHash() : NULL));
        if (reqfile)
            reqfile->m_DeadSourceList.AddDeadSource(this);
        switch (GetDownloadState())
        {
        case DS_ONQUEUE:
        case DS_NONEEDEDPARTS:
            DontSwapTo(reqfile);
            if (SwapToAnotherFile(_T("Source says it doesn't have the file. CUpDownClient::UDPReaskFNF()"), true, true, true, NULL, false, false))
                break;
            /*fall through*/
        default:
            CGlobalVariable::downloadqueue->RemoveSource(this);
            if (!socket)
            {
                if (Disconnected(_T("UDPReaskFNF socket=NULL")))
                    delete this;
            }
        }
    }
    else
    {
        if (thePrefs.GetVerbose())
            DebugLogWarning(_T("UDP FNF-Answer: %s - did not remove client because of current download state"),GetUserName());
    }
}

const bool CUpDownClient::IsInNoNeededList(const CPartFile* fileToCheck) const
{
    for (POSITION pos = m_OtherNoNeeded_list.GetHeadPosition();pos != 0;m_OtherNoNeeded_list.GetNext(pos))
    {
        if (m_OtherNoNeeded_list.GetAt(pos) == fileToCheck)
            return true;
    }

    return false;
}

const bool CUpDownClient::SwapToRightFile(CPartFile* SwapTo, CPartFile* cur_file, bool ignoreSuspensions, bool SwapToIsNNPFile, bool curFileisNNPFile, bool& wasSkippedDueToSourceExchange, bool doAgressiveSwapping, bool debug)
{
    bool printDebug = debug && thePrefs.GetLogA4AF();

    if (printDebug)
    {
        AddDebugLogLine(DLP_LOW, false, _T("oooo Debug: SwapToRightFile. Start compare SwapTo: %s and cur_file %s"), SwapTo?SwapTo->GetFileName():_T("null"), cur_file->GetFileName());
        AddDebugLogLine(DLP_LOW, false, _T("oooo Debug: doAgressiveSwapping: %s"), doAgressiveSwapping?_T("true"):_T("false"));
    }

    if (!SwapTo)
    {
        return true;
    }

    if (!curFileisNNPFile && cur_file->GetSourceCount() < cur_file->GetMaxSources() ||
            curFileisNNPFile && cur_file->GetSourceCount() < cur_file->GetMaxSources()*.8)
    {

        if (printDebug)
            AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: cur_file does probably not have too many sources."));

        if (SwapTo->GetSourceCount() > SwapTo->GetMaxSources() ||
                SwapTo->GetSourceCount() >= SwapTo->GetMaxSources()*.8 &&
                SwapTo == reqfile &&
                (
                    GetDownloadState() == DS_LOWTOLOWIP ||
                    GetDownloadState() == DS_REMOTEQUEUEFULL
                )
           )
        {
            if (printDebug)
                AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: SwapTo is about to be deleted due to too many sources on that file, so we can steal it."));
            return true;
        }

        if (ignoreSuspensions  || !IsSwapSuspended(cur_file, doAgressiveSwapping, curFileisNNPFile))
        {
            if (printDebug)
                AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: No suspend block."));

            DWORD tempTick = ::GetTickCount();
            bool rightFileHasHigherPrio = CPartFile::RightFileHasHigherPrio(SwapTo, cur_file);
            uint32 allNnpReaskTime = FILEREASKTIME*2*(m_OtherNoNeeded_list.GetSize() + ((GetDownloadState() == DS_NONEEDEDPARTS)?1:0)); // wait two reask interval for each nnp file before reasking an nnp file

            if (!SwapToIsNNPFile && (!curFileisNNPFile || GetLastAskedTime(cur_file) == 0 || tempTick-GetLastAskedTime(cur_file) > allNnpReaskTime) && rightFileHasHigherPrio ||
                    SwapToIsNNPFile && curFileisNNPFile &&
                    (
                        GetLastAskedTime(SwapTo) != 0 &&
                        (
                            GetLastAskedTime(cur_file) == 0 ||
                            tempTick-GetLastAskedTime(SwapTo) < tempTick-GetLastAskedTime(cur_file) && (tempTick-GetLastAskedTime(cur_file) > allNnpReaskTime || rightFileHasHigherPrio && tempTick-GetLastAskedTime(SwapTo) < allNnpReaskTime)
                        ) ||
                        rightFileHasHigherPrio && GetLastAskedTime(SwapTo) == 0 && GetLastAskedTime(cur_file) == 0
                    ) ||
                    SwapToIsNNPFile && !curFileisNNPFile)
            {
                if (printDebug)
                    if (!SwapToIsNNPFile && !curFileisNNPFile && rightFileHasHigherPrio)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: Higher prio."));
                    else if (!SwapToIsNNPFile && (GetLastAskedTime(cur_file) == 0 || tempTick-GetLastAskedTime(cur_file) > allNnpReaskTime) && rightFileHasHigherPrio)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: Time to reask nnp and it had higher prio."));
                    else if (GetLastAskedTime(SwapTo) != 0 &&
                             (
                                 GetLastAskedTime(cur_file) == 0 ||
                                 tempTick-GetLastAskedTime(SwapTo) < tempTick-GetLastAskedTime(cur_file) && (tempTick-GetLastAskedTime(cur_file) > allNnpReaskTime || rightFileHasHigherPrio && tempTick-GetLastAskedTime(SwapTo) < allNnpReaskTime)
                             )
                            )
                        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: Both nnp and cur_file has longer time since reasked."));
                    else if (SwapToIsNNPFile && !curFileisNNPFile)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: SwapToIsNNPFile && !curFileisNNPFile"));
                    else
                        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: Higher prio for unknown reason!"));

                if (IsSourceRequestAllowed(cur_file) && (cur_file->AllowSwapForSourceExchange() || cur_file == reqfile && RecentlySwappedForSourceExchange()) ||
                        !(IsSourceRequestAllowed(SwapTo) && (SwapTo->AllowSwapForSourceExchange() || SwapTo == reqfile && RecentlySwappedForSourceExchange())) ||
                        (GetDownloadState()==DS_ONQUEUE && GetRemoteQueueRank() <= 50))
                {
                    if (printDebug)
                        AddDebugLogLine(DLP_LOW, false, _T("oooo Debug: Source Request check ok."));
                    return true;
                }
                else
                {
                    if (printDebug)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: Source Request check failed."));
                    wasSkippedDueToSourceExchange = true;
                }
            }

            if (IsSourceRequestAllowed(cur_file, true) && (cur_file->AllowSwapForSourceExchange() || cur_file == reqfile && RecentlySwappedForSourceExchange()) &&
                    !(IsSourceRequestAllowed(SwapTo, true) && (SwapTo->AllowSwapForSourceExchange() || SwapTo == reqfile && RecentlySwappedForSourceExchange())) &&
                    (GetDownloadState()!=DS_ONQUEUE || GetDownloadState()==DS_ONQUEUE && GetRemoteQueueRank() > 50))
            {
                wasSkippedDueToSourceExchange = true;

                if (printDebug)
                    AddDebugLogLine(DLP_LOW, false, _T("oooo Debug: Source Exchange."));
                return true;
            }
        }
        else if (printDebug)
        {
            AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: Suspend block."));
        }
    }
    else if (printDebug)
    {
        AddDebugLogLine(DLP_VERYLOW, false, _T("oooo Debug: cur_file probably has too many sources."));
    }

    if (printDebug)
        AddDebugLogLine(DLP_LOW, false, _T("oooo Debug: Return false"));

    return false;
}

bool CUpDownClient::SwapToAnotherFile(LPCTSTR reason, bool bIgnoreNoNeeded, bool ignoreSuspensions, bool bRemoveCompletely, CPartFile* toFile, bool allowSame, bool isAboutToAsk, bool debug)
{
    if( (m_iPeerType&ptINet)!=0 )
		return false;

	bool printDebug = debug && thePrefs.GetLogA4AF();

    if (printDebug)
        AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: Switching source %s Remove = %s; bIgnoreNoNeeded = %s; allowSame = %s; Reason = \"%s\""), DbgGetClientInfo(), (bRemoveCompletely ? _T("Yes") : _T("No")), (bIgnoreNoNeeded ? _T("Yes") : _T("No")), (allowSame ? _T("Yes") : _T("No")), reason);

    if (!bRemoveCompletely && allowSame && thePrefs.GetA4AFSaveCpu())
    {
        // Only swap if we can't keep the old source
        if (printDebug)
            AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: return false since prefs setting to save cpu is enabled."));
        return false;
    }

    bool doAgressiveSwapping = (bRemoveCompletely || !allowSame || isAboutToAsk);
    if (printDebug)
        AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: doAgressiveSwapping: %s"), doAgressiveSwapping?_T("true"):_T("false"));

    if (!bRemoveCompletely && !ignoreSuspensions && allowSame && GetTimeUntilReask(reqfile, doAgressiveSwapping, true, false) > 0 && (GetDownloadState() != DS_NONEEDEDPARTS || m_OtherRequests_list.IsEmpty()))
    {
        if (printDebug)
            AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: return false due to not reached reask time: GetTimeUntilReask(...) > 0"));

        return false;
    }

    if (!bRemoveCompletely && allowSame && m_OtherRequests_list.IsEmpty() && (/* !bIgnoreNoNeeded ||*/ m_OtherNoNeeded_list.IsEmpty()))
    {
        // no file to swap too, and it's ok to keep it
        if (printDebug)
            AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: return false due to no file to swap too, and it's ok to keep it."));
        return false;
    }

    if (!bRemoveCompletely &&
            (GetDownloadState() != DS_ONQUEUE &&
             GetDownloadState() != DS_NONEEDEDPARTS &&
             GetDownloadState() != DS_TOOMANYCONNS &&
             GetDownloadState() != DS_REMOTEQUEUEFULL &&
             GetDownloadState() != DS_CONNECTED
            ))
    {
        if (printDebug)
            AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: return false due to wrong state."));
        return false;
    }

    CPartFile* SwapTo = NULL;
    CPartFile* cur_file = NULL;
    POSITION finalpos = NULL;
    CTypedPtrList<CPtrList, CPartFile*>* usedList = NULL;

    if (allowSame && !bRemoveCompletely)
    {
        SwapTo = reqfile;
        if (printDebug)
            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: allowSame: File %s SourceReq: %s"), reqfile->GetFileName(), IsSourceRequestAllowed(reqfile)?_T("true"):_T("false"));
    }

    bool SwapToIsNNP = (SwapTo != NULL && SwapTo == reqfile && GetDownloadState() == DS_NONEEDEDPARTS);

    CPartFile* skippedDueToSourceExchange = NULL;
    bool skippedIsNNP = false;

    if (!m_OtherRequests_list.IsEmpty())
    {
        if (printDebug)
            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: m_OtherRequests_list"));

        for (POSITION pos = m_OtherRequests_list.GetHeadPosition();pos != 0;m_OtherRequests_list.GetNext(pos))
        {
            cur_file = m_OtherRequests_list.GetAt(pos);

            if (printDebug)
                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Checking file: %s SoureReq: %s"), cur_file->GetFileName(), IsSourceRequestAllowed(cur_file)?_T("true"):_T("false"));

            if (!bRemoveCompletely && !ignoreSuspensions && allowSame && IsSwapSuspended(cur_file, doAgressiveSwapping, false))
            {
                if (printDebug)
                    AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: continue due to IsSwapSuspended(file) == true"));
                continue;
            }

            if (cur_file != reqfile && CGlobalVariable::downloadqueue->IsPartFile(cur_file) && !cur_file->IsStopped()
                    && (cur_file->GetStatus(false) == PS_READY || cur_file->GetStatus(false) == PS_EMPTY))
            {
                if (printDebug)
                    AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: It's a partfile, not stopped, etc."));

                if (toFile != NULL)
                {
                    if (cur_file == toFile)
                    {
                        if (printDebug)
                            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Found toFile."));

                        SwapTo = cur_file;
                        SwapToIsNNP = false;
                        usedList = &m_OtherRequests_list;
                        finalpos = pos;
                        break;
                    }
                }
                else
                {
                    bool wasSkippedDueToSourceExchange = false;
                    if (SwapToRightFile(SwapTo, cur_file, ignoreSuspensions, SwapToIsNNP, false, wasSkippedDueToSourceExchange, doAgressiveSwapping, debug))
                    {
                        if (printDebug)
                            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Swapping to file %s"), cur_file->GetFileName());

                        if (SwapTo && wasSkippedDueToSourceExchange)
                        {
                            if (debug && thePrefs.GetLogA4AF()) AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Swapped due to source exchange possibility"));
                            bool discardSkipped = false;
                            if (SwapToRightFile(skippedDueToSourceExchange, SwapTo, ignoreSuspensions, skippedIsNNP, SwapToIsNNP, discardSkipped, doAgressiveSwapping, debug))
                            {
                                skippedDueToSourceExchange = SwapTo;
                                skippedIsNNP = skippedIsNNP?true:(SwapTo == reqfile && GetDownloadState() == DS_NONEEDEDPARTS);
                                if (printDebug)
                                    AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Skipped file was better than last skipped file."));
                            }
                        }

                        SwapTo = cur_file;
                        SwapToIsNNP = false;
                        usedList = &m_OtherRequests_list;
                        finalpos=pos;
                    }
                    else
                    {
                        if (printDebug)
                            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Keeping file %s"), SwapTo->GetFileName());
                        if (wasSkippedDueToSourceExchange)
                        {
                            if (printDebug)
                                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Kept the file due to source exchange possibility"));
                            bool discardSkipped = false;
                            if (SwapToRightFile(skippedDueToSourceExchange, cur_file, ignoreSuspensions, skippedIsNNP, false, discardSkipped, doAgressiveSwapping, debug))
                            {
                                skippedDueToSourceExchange = cur_file;
                                skippedIsNNP = false;
                                if (printDebug)
                                    AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Skipped file was better than last skipped file."));
                            }
                        }
                    }
                }
            }
        }
    }

    //if ((!SwapTo || SwapTo == reqfile && GetDownloadState() == DS_NONEEDEDPARTS) && bIgnoreNoNeeded){
    if (printDebug)
        AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: m_OtherNoNeeded_list"));

    for (POSITION pos = m_OtherNoNeeded_list.GetHeadPosition();pos != 0;m_OtherNoNeeded_list.GetNext(pos))
    {
        cur_file = m_OtherNoNeeded_list.GetAt(pos);

        if (printDebug)
            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Checking file: %s "), cur_file->GetFileName());

        if (!bRemoveCompletely && !ignoreSuspensions && allowSame && IsSwapSuspended(cur_file, doAgressiveSwapping, true))
        {
            if (printDebug)
                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: continue due to !IsSwapSuspended(file) == true"));
            continue;
        }

        if (cur_file != reqfile && CGlobalVariable::downloadqueue->IsPartFile(cur_file) && !cur_file->IsStopped()
                && (cur_file->GetStatus(false) == PS_READY || cur_file->GetStatus(false) == PS_EMPTY) )
        {
            if (printDebug)
                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: It's a partfile, not stopped, etc."));

            if (toFile != NULL)
            {
                if (cur_file == toFile)
                {
                    if (printDebug)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Found toFile."));

                    SwapTo = cur_file;
                    usedList = &m_OtherNoNeeded_list;
                    finalpos = pos;
                    break;
                }
            }
            else
            {
                bool wasSkippedDueToSourceExchange = false;
                if (SwapToRightFile(SwapTo, cur_file, ignoreSuspensions, SwapToIsNNP, true, wasSkippedDueToSourceExchange, doAgressiveSwapping, debug))
                {
                    if (printDebug)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Swapping to file %s"), cur_file->GetFileName());

                    if (SwapTo && wasSkippedDueToSourceExchange)
                    {
                        if (printDebug)
                            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Swapped due to source exchange possibility"));
                        bool discardSkipped = false;
                        if (SwapToRightFile(skippedDueToSourceExchange, SwapTo, ignoreSuspensions, skippedIsNNP, SwapToIsNNP, discardSkipped, doAgressiveSwapping, debug))
                        {
                            skippedDueToSourceExchange = SwapTo;
                            skippedIsNNP = skippedIsNNP?true:(SwapTo == reqfile && GetDownloadState() == DS_NONEEDEDPARTS);
                            if (printDebug)
                                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Skipped file was better than last skipped file."));
                        }
                    }

                    SwapTo = cur_file;
                    SwapToIsNNP = true;
                    usedList = &m_OtherNoNeeded_list;
                    finalpos=pos;
                }
                else
                {
                    if (printDebug)
                        AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Keeping file %s"), SwapTo->GetFileName());
                    if (wasSkippedDueToSourceExchange)
                    {
                        if (debug && thePrefs.GetVerbose()) AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Kept the file due to source exchange possibility"));
                        bool discardSkipped = false;
                        if (SwapToRightFile(skippedDueToSourceExchange, cur_file, ignoreSuspensions, skippedIsNNP, true, discardSkipped, doAgressiveSwapping, debug))
                        {
                            skippedDueToSourceExchange = cur_file;
                            skippedIsNNP = true;
                            if (printDebug)
                                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Skipped file was better than last skipped file."));
                        }
                    }
                }
            }
        }
    }
    //}

    if (SwapTo)
    {
        if (printDebug)
        {
            if (SwapTo != reqfile)
            {
                AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: Found file to swap to %s"), SwapTo->GetFileName());
            }
            else
            {
                AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: Will keep current file. %s"), SwapTo->GetFileName());
            }
        }

        CString strInfo(reason);
        if (skippedDueToSourceExchange)
        {
            bool wasSkippedDueToSourceExchange = false;
            bool skippedIsBetter = SwapToRightFile(SwapTo, skippedDueToSourceExchange, ignoreSuspensions, SwapToIsNNP, skippedIsNNP, wasSkippedDueToSourceExchange, doAgressiveSwapping, debug);
            if (skippedIsBetter || wasSkippedDueToSourceExchange)
            {
                SwapTo->SetSwapForSourceExchangeTick();
                SetSwapForSourceExchangeTick();

                strInfo = _T("******SourceExchange-Swap****** ") + strInfo;
                if (printDebug)
                {
                    AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Due to sourceExchange."));
                }
                else if (thePrefs.GetLogA4AF() && reqfile == SwapTo)
                {
                    AddDebugLogLine(DLP_LOW, false, _T("ooo Didn't swap source due to source exchange possibility. %s Remove = %s '%s' Reason: %s"), DbgGetClientInfo(), (bRemoveCompletely ? _T("Yes") : _T("No") ), (this->reqfile)?this->reqfile->GetFileName():_T("null"), strInfo);
                }
            }
            else if (printDebug)
            {
                AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Normal. SwapTo better than skippedDueToSourceExchange."));
            }
        }
        else if (printDebug)
        {
            AddDebugLogLine(DLP_VERYLOW, false, _T("ooo Debug: Normal. skippedDueToSourceExchange == NULL"));
        }

        if (SwapTo != reqfile && DoSwap(SwapTo,bRemoveCompletely, strInfo))
        {
            if (debug && thePrefs.GetLogA4AF()) AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: Swap successful."));
            if (usedList && finalpos)
            {
                usedList->RemoveAt(finalpos);
            }
            return true;
        }
        else if (printDebug)
        {
            AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: Swap didn't happen."));
        }
    }

    if (printDebug)
        AddDebugLogLine(DLP_LOW, false, _T("ooo Debug: Done %s"), DbgGetClientInfo());

    return false;
}

bool CUpDownClient::DoSwap(CPartFile* SwapTo, bool bRemoveCompletely, LPCTSTR reason)
{
    if (thePrefs.GetLogA4AF())
        AddDebugLogLine(DLP_LOW, false, _T("ooo Swapped source %s Remove = %s '%s'   -->   %s Reason: %s"), DbgGetClientInfo(), (bRemoveCompletely ? _T("Yes") : _T("No") ), (this->reqfile)?this->reqfile->GetFileName():_T("null"), SwapTo->GetFileName(), reason);

    // 17-Dez-2003 [bc]: This "reqfile->srclists[sourcesslot].Find(this)" was the only place where
    // the usage of the "CPartFile::srclists[100]" is more effective than using one list. If this
    // function here is still (again) a performance problem there is a more effective way to handle
    // the 'Find' situation. Hint: usage of a node ptr which is stored in the CUpDownClient.
    POSITION pos = reqfile->srclist.Find(this);
    if (pos)
    {
        reqfile->srclist.RemoveAt(pos);
    }
    else
    {
        AddDebugLogLine(DLP_HIGH, true, _T("o-o Unsync between parfile->srclist and client otherfiles list. Swapping client where client has file as reqfile, but file doesn't have client in srclist. %s Remove = %s '%s'   -->   '%s'  SwapReason: %s"), DbgGetClientInfo(), (bRemoveCompletely ? _T("Yes") : _T("No") ), (this->reqfile)?this->reqfile->GetFileName():_T("null"), SwapTo->GetFileName(), reason);
    }

    // remove this client from the A4AF list of our new reqfile
    POSITION pos2 = SwapTo->A4AFsrclist.Find(this);
    if (pos2)
    {
        SwapTo->A4AFsrclist.RemoveAt(pos2);
    }
    else
    {
        AddDebugLogLine(DLP_HIGH, true, _T("o-o Unsync between parfile->srclist and client otherfiles list. Swapping client where client has file in another list, but file doesn't have client in a4af srclist. %s Remove = %s '%s'   -->   '%s'  SwapReason: %s"), DbgGetClientInfo(), (bRemoveCompletely ? _T("Yes") : _T("No") ), (this->reqfile)?this->reqfile->GetFileName():_T("null"), SwapTo->GetFileName(), reason);
    }

    //  Comment UI
    UINotify(WM_FILE_REMOVE_SOURCE,(WPARAM)SwapTo,(LPARAM)this, this, true);
    //theApp.emuledlg->transferwnd->downloadlistctrl.RemoveSource(this,SwapTo);

    reqfile->RemoveDownloadingSource(this);

    if (!bRemoveCompletely)
    {
        reqfile->A4AFsrclist.AddTail(this);
        if (GetDownloadState() == DS_NONEEDEDPARTS)
            m_OtherNoNeeded_list.AddTail(reqfile);
        else
            m_OtherRequests_list.AddTail(reqfile);

        //  Comment UI
        //uint32 struPFilePeer[] = {(uint32)reqfile,(uint32)this,(uint32)true};
        //SendMessage(CGlobalVariable::m_hListenWnd,WM_FILE_ADD_PEER,0,(LPARAM)struPFilePeer);
        SendMessage(CGlobalVariable::m_hListenWnd,WM_FILE_ADD_SOURCE,(WPARAM)reqfile,(LPARAM)this);
        //theApp.emuledlg->transferwnd->downloadlistctrl.AddSource(reqfile,this,true);

    }
    else
    {
        m_fileReaskTimes.RemoveKey(reqfile);
    }

    SetDownloadState(DS_NONE);
    CPartFile* pOldRequestFile = reqfile;
    SetRequestFile(SwapTo);
    pOldRequestFile->UpdatePartsInfo();
    pOldRequestFile->UpdateAvailablePartsCount();

    SwapTo->srclist.AddTail(this);

    //  Comment UI
    //uint32 struPFilePeer[] = {(uint32)SwapTo,(uint32)this,(uint32)false};
    //SendMessage(CGlobalVariable::m_hListenWnd,WM_FILE_ADD_PEER,0,(LPARAM)struPFilePeer);
    //theApp.emuledlg->transferwnd->downloadlistctrl.AddSource(SwapTo,this,false);
    SendMessage(CGlobalVariable::m_hListenWnd,WM_FILE_ADD_SOURCE_NA,(WPARAM)SwapTo,(LPARAM)this);

    return true;
}

void CUpDownClient::DontSwapTo(/*const*/ CPartFile* file)
{
    DWORD dwNow = ::GetTickCount();

    for (POSITION pos = m_DontSwap_list.GetHeadPosition(); pos != 0; m_DontSwap_list.GetNext(pos))
        if (m_DontSwap_list.GetAt(pos).file == file)
        {
            m_DontSwap_list.GetAt(pos).timestamp = dwNow ;
            return;
        }
    PartFileStamp newfs = {file, dwNow };
    m_DontSwap_list.AddHead(newfs);
}

bool CUpDownClient::IsSwapSuspended(const CPartFile* file, const bool allowShortReaskTime, const bool fileIsNNP)
{
    if (file == reqfile)
    {
        return false;
    }

    // Don't swap if we have reasked this client too recently
    if (GetTimeUntilReask(file, allowShortReaskTime, true, fileIsNNP) > 0)
        return true;

    if (m_DontSwap_list.GetCount()==0)
        return false;

    for (POSITION pos = m_DontSwap_list.GetHeadPosition(); pos != 0 && m_DontSwap_list.GetCount()>0; m_DontSwap_list.GetNext(pos))
    {
        if (m_DontSwap_list.GetAt(pos).file == file)
        {
            if ( ::GetTickCount() - m_DontSwap_list.GetAt(pos).timestamp  >= PURGESOURCESWAPSTOP )
            {
                m_DontSwap_list.RemoveAt(pos);
                return false;
            }
            else
                return true;
        }
        else if (m_DontSwap_list.GetAt(pos).file == NULL) // in which cases should this happen?
            m_DontSwap_list.RemoveAt(pos);
    }

    return false;
}

uint32 CUpDownClient::GetTimeUntilReask(const CPartFile* file, const bool allowShortReaskTime, const bool useGivenNNP, const bool givenNNP) const
{
    DWORD lastAskedTimeTick = GetLastAskedTime(file);
    if (lastAskedTimeTick != 0)
    {
        DWORD tick = ::GetTickCount();

        DWORD reaskTime;
        if (allowShortReaskTime || file == reqfile && GetDownloadState() == DS_NONE)
        {
            reaskTime = MIN_REQUESTTIME;
        }
        else if (useGivenNNP && givenNNP  ||
                 file != reqfile && IsInNoNeededList(file))
        {
            reaskTime = FILEREASKTIME*2;
        }
		 else if ( file == reqfile && GetDownloadState() == DS_NONEEDEDPARTS )
		 {
			 reaskTime = FILEREASKTIME; ///TODO 可以再按对方的下载速度调整这个时间	
		 }
        else
        {
//#ifdef _DEBUG_LAN_ // VC-Huby[2006-12-30]: 这个代码逻辑已调试OK
            if ( GetRemoteQueueRank()==0 )	//刚刚断掉了，可以及时确认一遍自己新的QueueRank，但要依据ErrTimes决定重连时间
            {
				if( GetDownloadState()==DS_ONQUEUE )
					reaskTime = min( (m_iErrTimes+1)*3*60*1000,FILEREASKTIME); //2Min
				else if( HasLowID() && !CGlobalVariable::CanDoCallback(this) )
					reaskTime = min( (m_iErrTimes+1)*10*60*1000,FILEREASKTIME ); //L2L 至少间隔16Min重连
				else
					reaskTime = min( (m_iErrTimes+1)*8*60*1000,FILEREASKTIME); //16Min
            }
            else
                reaskTime = FILEREASKTIME;
//#else
//			reaskTime = FILEREASKTIME;
//#endif
        }

        if (tick-lastAskedTimeTick < reaskTime)
        {
            return reaskTime-(tick-lastAskedTimeTick);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

uint32 CUpDownClient::GetTimeUntilReask(const CPartFile* file) const
{
    return GetTimeUntilReask(file, false);
}

uint32 CUpDownClient::GetTimeUntilReask() const
{
    return GetTimeUntilReask(reqfile);
}

bool CUpDownClient::IsValidSource() const
{
    bool valid = false;
    switch (GetDownloadState())
    {
    case DS_DOWNLOADING:
    case DS_ONQUEUE:
    case DS_CONNECTED:
    case DS_NONEEDEDPARTS:
    case DS_REMOTEQUEUEFULL:
    case DS_REQHASHSET:
        valid = IsEd2kClient();
    }
    return valid;
}

void CUpDownClient::StartDownload()
{
    SetDownloadState(DS_DOWNLOADING);
    InitTransferredDownMini();
    SetDownStartTime();
    m_lastPartAsked = (uint16)-1;
    SendBlockRequests();
}

void CUpDownClient::SendCancelTransfer(Packet* packet)
{
    if (socket == NULL || !IsEd2kClient())
    {
        ASSERT(0);
        return;
    }

    if (!GetSentCancelTransfer())
    {
        if (thePrefs.GetDebugClientTCPLevel() > 0)
            DebugSend("OP__CancelTransfer", this);

        bool bDeletePacket;
        Packet* pCancelTransferPacket;
        if (packet)
        {
            pCancelTransferPacket = packet;
            bDeletePacket = false;
        }
        else
        {
            pCancelTransferPacket = new Packet(OP_CANCELTRANSFER, 0);
            bDeletePacket = true;
        }
        theStats.AddUpDataOverheadFileRequest(pCancelTransferPacket->size);
        socket->SendPacket(pCancelTransferPacket,bDeletePacket,true);
        SetSentCancelTransfer(1);
    }

    if (m_pPCDownSocket)
    {
        m_pPCDownSocket->Safe_Delete();
        m_pPCDownSocket = NULL;
        SetPeerCacheDownState(PCDS_NONE);
    }
}

void CUpDownClient::SetRequestFile(CPartFile* pReqFile)
{
    if (pReqFile != reqfile || reqfile == NULL)
        ResetFileStatusInfo();
    reqfile = pReqFile;
}

void CUpDownClient::ProcessAcceptUpload()
{
    if( reqfile && reqfile->DownloadFromOriginal() )
		return;

	m_fQueueRankPending = 1;
	AddPeerLog(new CTraceServerMessage(GetResString(IDS_ACCEPT_REQUEST)));
    if (reqfile && !reqfile->IsStopped() && (reqfile->GetStatus()==PS_READY || reqfile->GetStatus()==PS_EMPTY))
    {
        SetSentCancelTransfer(0);
        if (GetDownloadState() == DS_ONQUEUE)
        {
            // PC-TODO: If remote client does not answer the PeerCache query within a timeout,
            // automatically fall back to ed2k download.
            if (   !SupportPeerCache()						// client knows peercache protocol
                    || !thePrefs.IsPeerCacheDownloadEnabled()	// user has enabled peercache downloads
                    || !CGlobalVariable::m_pPeerCache->IsCacheAvailable() // we have found our cache and its usable
                    || !CGlobalVariable::m_pPeerCache->IsClientPCCompatible(GetVersion(), GetClientSoft()) // the client version is accepted by the cache
                    || !SendPeerCacheFileRequest()) // request made
            {
                StartDownload();
            }
        }
    }
    else
    {
        SendCancelTransfer();
        SetDownloadState((reqfile==NULL || reqfile->IsStopped()) ? DS_NONE : DS_ONQUEUE);
    }
}

uint32 CUpDownClient::GetLastAskedTime(const CPartFile* partFile) const
{
    CPartFile* file = (CPartFile*)partFile;
    if (file == NULL)
    {
        file = reqfile;
    }

    DWORD lastChangedTick;
    return m_fileReaskTimes.Lookup(file, lastChangedTick)?lastChangedTick:0;
}

void CUpDownClient::SetReqFileAICHHash(CAICHHash* val)
{
    if (m_pReqFileAICHHash != NULL && m_pReqFileAICHHash != val)
        delete m_pReqFileAICHHash;
    m_pReqFileAICHHash = val;
}

void CUpDownClient::SendAICHRequest(CPartFile* pForFile, uint16 nPart)
{
    CAICHRequestedData request;
    request.m_nPart = nPart;
    request.m_pClient = this;
    request.m_pPartFile = pForFile;
    CAICHHashSet::m_liRequestedData.AddTail(request);
    m_fAICHRequested = TRUE;
    CSafeMemFile data;
    data.WriteHash16(pForFile->GetFileHash());
    data.WriteUInt16(nPart);
    pForFile->GetAICHHashset()->GetMasterHash().Write(&data);
    Packet* packet = new Packet(&data, OP_EMULEPROT, OP_AICHREQUEST);
    if (thePrefs.GetDebugClientTCPLevel() > 0)
        DebugSend("OP__AichRequest", this, (uchar*)packet->pBuffer);
    theStats.AddUpDataOverheadFileRequest(packet->size);
    SafeSendPacket(packet);
}

void CUpDownClient::ProcessAICHAnswer(const uchar* packet, UINT size)
{
    if( reqfile /*&& reqfile->DownloadFromOriginal()*/ && reqfile->HasNullHash() )
	{
		return;
	}

	if (m_fAICHRequested == FALSE)
    {
        throw CString(_T("Received unrequested AICH Packet"));
    }
    m_fAICHRequested = FALSE;

    CSafeMemFile data(packet, size);
    if (size <= 16)
    {
        CAICHHashSet::ClientAICHRequestFailed(this);
        return;
    }
    uchar abyHash[16];
    data.ReadHash16(abyHash);
    CPartFile* pPartFile = CGlobalVariable::downloadqueue->GetFileByID(abyHash);
    CAICHRequestedData request = CAICHHashSet::GetAICHReqDetails(this);
    uint16 nPart = data.ReadUInt16();
    if (pPartFile != NULL && request.m_pPartFile == pPartFile && request.m_pClient == this && nPart == request.m_nPart)
    {
        CAICHHash ahMasterHash(&data);
        if ( (pPartFile->GetAICHHashset()->GetStatus() == AICH_TRUSTED || pPartFile->GetAICHHashset()->GetStatus() == AICH_VERIFIED)
                && ahMasterHash == pPartFile->GetAICHHashset()->GetMasterHash())
        {
            if (pPartFile->GetAICHHashset()->ReadRecoveryData((uint64)request.m_nPart*PARTSIZE, &data))
            {
                // finally all checks passed, everythings seem to be fine
                AddDebugLogLine(DLP_DEFAULT, false, _T("AICH Packet Answer: Succeeded to read and validate received recoverydata"));
                CAICHHashSet::RemoveClientAICHRequest(this);
                pPartFile->AICHRecoveryDataAvailable(request.m_nPart);
                return;
            }
            else
                AddDebugLogLine(DLP_DEFAULT, false, _T("AICH Packet Answer: Succeeded to read and validate received recoverydata"));
        }
        else
            AddDebugLogLine(DLP_HIGH, false, _T("AICH Packet Answer: Masterhash differs from packethash or hashset has no trusted Masterhash"));
    }
    else
        AddDebugLogLine(DLP_HIGH, false, _T("AICH Packet Answer: requested values differ from values in packet"));

    CAICHHashSet::ClientAICHRequestFailed(this);
}

void CUpDownClient::ProcessAICHRequest(const uchar* packet, UINT size)
{
    if (size != (UINT)(16 + 2 + CAICHHash::GetHashSize()))
        throw CString(_T("Received AICH Request Packet with wrong size"));

    CSafeMemFile data(packet, size);
    uchar abyHash[16];
    data.ReadHash16(abyHash);
    uint16 nPart = data.ReadUInt16();
    CAICHHash ahMasterHash(&data);
    CKnownFile* pKnownFile = NULL;
    //  Comment UI
    //CGlobalVariable::sharedfiles->GetFileByID(abyHash);
    if (pKnownFile != NULL)
    {
        if (pKnownFile->GetAICHHashset()->GetStatus() == AICH_HASHSETCOMPLETE && pKnownFile->GetAICHHashset()->HasValidMasterHash()
                && pKnownFile->GetAICHHashset()->GetMasterHash() == ahMasterHash && pKnownFile->GetPartCount() > nPart
                && pKnownFile->GetFileSize() > (uint64)EMBLOCKSIZE && (uint64)pKnownFile->GetFileSize() - PARTSIZE*(uint64)nPart > EMBLOCKSIZE)
        {
            CSafeMemFile fileResponse;
            fileResponse.WriteHash16(pKnownFile->GetFileHash());
            fileResponse.WriteUInt16(nPart);
            pKnownFile->GetAICHHashset()->GetMasterHash().Write(&fileResponse);
            if (pKnownFile->GetAICHHashset()->CreatePartRecoveryData((uint64)nPart*PARTSIZE, &fileResponse))
            {
                AddDebugLogLine(DLP_HIGH, false, _T("AICH Packet Request: Sucessfully created and send recoverydata for %s to %s"), pKnownFile->GetFileName(), DbgGetClientInfo());
                if (thePrefs.GetDebugClientTCPLevel() > 0)
                    DebugSend("OP__AichAnswer", this, pKnownFile->GetFileHash());
                Packet* packAnswer = new Packet(&fileResponse, OP_EMULEPROT, OP_AICHANSWER);
                theStats.AddUpDataOverheadFileRequest(packAnswer->size);
                SafeSendPacket(packAnswer);
                return;
            }
            else
                AddDebugLogLine(DLP_HIGH, false, _T("AICH Packet Request: Failed to create recoverydata for %s to %s"), pKnownFile->GetFileName(), DbgGetClientInfo());
        }
        else
        {
            AddDebugLogLine(DLP_HIGH, false, _T("AICH Packet Request: Failed to create ecoverydata - Hashset not ready or requested Hash differs from Masterhash for %s to %s"), pKnownFile->GetFileName(), DbgGetClientInfo());
        }

    }
    else
        AddDebugLogLine(DLP_HIGH, false, _T("AICH Packet Request: Failed to find requested shared file -  %s"), DbgGetClientInfo());

    if (thePrefs.GetDebugClientTCPLevel() > 0)
        DebugSend("OP__AichAnswer", this, abyHash);
    Packet* packAnswer = new Packet(OP_AICHANSWER, 16, OP_EMULEPROT);
    md4cpy(packAnswer->pBuffer, abyHash);
    theStats.AddUpDataOverheadFileRequest(packAnswer->size);
    SafeSendPacket(packAnswer);
}

void CUpDownClient::ProcessAICHFileHash(CSafeMemFile* data, CPartFile* file)
{
    CPartFile* pPartFile = file;
    if (pPartFile == NULL)
    {
        uchar abyHash[16];
        data->ReadHash16(abyHash);
        pPartFile = CGlobalVariable::downloadqueue->GetFileByID(abyHash);
    }
    CAICHHash ahMasterHash(data);
    if (pPartFile != NULL && pPartFile == GetRequestFile())
    {
        SetReqFileAICHHash(new CAICHHash(ahMasterHash));
        pPartFile->GetAICHHashset()->UntrustedHashReceived(ahMasterHash, GetConnectIP());
    }
    else
        AddDebugLogLine(DLP_HIGH, false, _T("ProcessAICHFileHash(): PartFile not found or Partfile differs from requested file, %s"), DbgGetClientInfo());
}

bool CUpDownClient::RequestBlock( Requested_Block_Struct** newblocks, uint16* pCount, bool )
{
	return reqfile->GetNextRequestedBlock(this, newblocks, pCount);
}

bool CUpDownClient::BlockReqNeedHelp( Requested_Block_Struct* pBlock,bool& bIsCompleted )
{
	if( pBlock->EndOffset - pBlock->StartOffset + 1 == pBlock->transferred ) 
	{
		// 已经传输完成的
		return false;
	}

	if( reqfile->IsComplete(pBlock->StartOffset,pBlock->EndOffset,false) )
	{
		bIsCompleted = true;
		return false;
	}

	if( pBlock->bBlockReqHelpRobed )
		return false;	

	return true;
}

bool CUpDownClient::BlockReqHelpByClient( CUpDownClient* pClient,bool bPeekCanHelp,bool bCloseToFinish )
{
	int iHelpCount = 0;
	for( POSITION pos = this->m_PendingBlocks_list.GetHeadPosition(); pos ; ) 
	{
		POSITION posLast = pos;
		Pending_Block_Struct* pBlock = this->m_PendingBlocks_list.GetNext(pos);
		ASSERT( pBlock );
		if( pBlock ) 
		{
			bool bIsCompleted = false;
			if( !BlockReqNeedHelp(pBlock->block,bIsCompleted) )
			{
				if(bIsCompleted)
				{
					reqfile->RemoveBlockFromList(pBlock->block->StartOffset,pBlock->block->EndOffset);
					delete pBlock->block;
					if (pBlock->zStream)
					{
						inflateEnd(pBlock->zStream);
						delete pBlock->zStream;
					}
					delete pBlock;
					m_PendingBlocks_list.RemoveAt( posLast );
				}
				continue;
			}

			int part_index = (int)(pBlock->block->StartOffset / PARTSIZE);
			if( pClient->IsPartAvailable( part_index ) ) 
			{
				if(!bPeekCanHelp)
				{
					pBlock->block->bBlockReqHelpRobed = TRUE;
					Pending_Block_Struct* pBlockNew = new Pending_Block_Struct;
					Requested_Block_Struct* pReqBlockNew = new Requested_Block_Struct; 
					pBlockNew->block = pReqBlockNew;
					pReqBlockNew->StartOffset = pBlock->block->StartOffset;
					pReqBlockNew->EndOffset = pBlock->block->EndOffset;
					md4cpy(pReqBlockNew->FileID,pBlock->block->FileID);
					pReqBlockNew->transferred = 0;
					pReqBlockNew->BlockIdx = pBlock->block->BlockIdx;
					pClient->m_PendingBlocks_list.AddTail(pBlockNew);
					reqfile->BlockReqHelped(pBlock->block,pReqBlockNew);
					if(!bCloseToFinish)
					{
						delete pBlock->block;
						if (pBlock->zStream)
						{
							inflateEnd(pBlock->zStream);
							delete pBlock->zStream;
						}
						delete pBlock;						
						m_PendingBlocks_list.RemoveAt( posLast );
					}
#ifdef _DEBUG_PEER
					Debug( _T("Peer(%d)-type(%d)-speed(%d)-state(%d)-lowid(%d) PendingBlocks_list-BlockReqHelpByClient-Peer(%d)-type(%d)-speed(%d)-state(%d)-lowid(%d) [%d,%I64u,%I64u] \n"),\
						m_iPeerIndex,m_iPeerType,GetDownloadDatarate(),GetDownloadState(),HasLowID(),\
						pClient->m_iPeerIndex,pClient->m_iPeerType,pClient->GetDownloadDatarate(),pClient->GetDownloadState(),pClient->HasLowID(),\
						pReqBlockNew->BlockIdx,pReqBlockNew->StartOffset,pReqBlockNew->EndOffset );
#endif
				}

				iHelpCount++;
			}
		}
	}

	for( POSITION pos = this->m_DownloadBlocks_list.GetHeadPosition(); pos ; ) 
	{
		Requested_Block_Struct* pBlock = this->m_DownloadBlocks_list.GetNext(pos);
		ASSERT( pBlock );
		if( pBlock ) 
		{
			bool bIsCompeleted = false;
			if( !BlockReqNeedHelp(pBlock,bIsCompeleted) )
				continue;
			int part_index = (int)(pBlock->StartOffset / PARTSIZE);
			if( pClient->IsPartAvailable( part_index ) ) 
			{
                if(!bPeekCanHelp)
				{
					pBlock->bBlockReqHelpRobed = TRUE;
					Requested_Block_Struct* pReqBlockNew = new Requested_Block_Struct; 
					pReqBlockNew->StartOffset = pBlock->StartOffset;
					pReqBlockNew->EndOffset = pBlock->EndOffset;
					md4cpy(pReqBlockNew->FileID,pBlock->FileID);
					pReqBlockNew->transferred = 0;
					pReqBlockNew->BlockIdx = pBlock->BlockIdx;
					pClient->m_DownloadBlocks_list.AddTail(pReqBlockNew);
#ifdef _DEBUG_PEER
					Debug( _T("Peer(%d) DownloadBlocks_list-BlockReqHelpByClient-Peer(%d) [%d,%I64u,%I64u] \n"),m_iPeerIndex,pClient->m_iPeerIndex,
						pReqBlockNew->BlockIdx,pReqBlockNew->StartOffset,pReqBlockNew->EndOffset );
#endif
				}

				iHelpCount++;
			}
		}
	}

	return (iHelpCount>0);
}

UINT CUpDownClient::TimeToFinishBlockReq( )
{
	if( m_PendingBlocks_list.GetCount()==0 && m_DownloadBlocks_list.GetCount()==0 )
		return 0;

	uint64 total = 0;
	for( POSITION pos = this->m_PendingBlocks_list.GetHeadPosition(); pos ; ) 
	{
		Pending_Block_Struct* block = this->m_PendingBlocks_list.GetNext(pos);
		ASSERT( block );

		total += block->block->EndOffset - block->block->StartOffset - block->block->transferred;

	}

	for( POSITION pos = this->m_DownloadBlocks_list.GetHeadPosition(); pos ; ) 
	{
		Requested_Block_Struct* block = this->m_DownloadBlocks_list.GetNext(pos);
		ASSERT( block );

		total += block->EndOffset - block->StartOffset - block->transferred;

	}

	if( total ) 
	{
		UINT speed = this->GetDownloadDatarateMS();
		if( speed ) 
			return (UINT)(total / speed); 
		else
			return UINT(-1);
	}
	else
		return 0;		
}
