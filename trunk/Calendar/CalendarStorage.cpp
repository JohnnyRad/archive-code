#include "StdAfx.h"
#include "CalendarStorage.h"

#define RegKeyName "Calendar\\\\"

CCalendarStorage::CCalendarStorage(void)
{
	CString str(_T("software\\\\"));
	str += _T(RegKeyName);
	::RegCreateKeyEx(HKEY_CURRENT_USER,str,0,NULL,0,KEY_WRITE||KEY_READ,0,&m_CalendarRoot,NULL);
}

CCalendarStorage::~CCalendarStorage(void)
{
}

BOOL CCalendarStorage::LoadEvent(const COleDateTime & t,CStringArray * strArray)
{
	CString year;
	year.Format(_T("%d"),t.GetYear());
	CString month;
	month.Format(_T("%d"),t.GetMonth());
	CString day;
	day.Format(_T("%d"),t.GetDay());

	HKEY keyPtr;
	LPTSTR lpValue;
	DWORD size = strArray->GetCount();

	if(ERROR_SUCCESS == ::RegOpenKeyEx(m_CalendarRoot,year,0,NULL,&keyPtr))
	{
		if(ERROR_SUCCESS == ::RegOpenKeyEx(keyPtr,month,0,NULL,&keyPtr))
		{
			if(ERROR_SUCCESS == ::RegQueryValueEx(keyPtr,day,0,NULL,NULL,&size))
			{
				if(NULL == strArray) return TRUE;
				lpValue = new TCHAR[size];
				::RegQueryValueEx(keyPtr,day,0,NULL,(LPBYTE)lpValue,NULL);
				for (; '\0' != *lpValue; lpValue += _tcslen(lpValue) + 1)
				{
					strArray->Add(lpValue);
				}
				return TRUE;
			}else goto NoEvent_Return;
		}else goto NoEvent_Return;
	}else goto NoEvent_Return;

NoEvent_Return:
	return FALSE;
}


BOOL CCalendarStorage::SaveEvent(const COleDateTime & t,const CStringArray & strArray)
{
	CString year;
	year.Format(_T("%d"),t.GetYear());
	CString month;
	month.Format(_T("%d"),t.GetMonth());
	CString day;
	day.Format(_T("%d"),t.GetDay());

	HKEY keyPtr;

	if(ERROR_SUCCESS == ::RegCreateKeyEx(m_CalendarRoot,year,0,0,0,KEY_WRITE,0,&keyPtr,0))
	{
		if(ERROR_SUCCESS == ::RegCreateKeyEx(keyPtr,month,0,0,0,KEY_WRITE,0,&keyPtr,0))
		{
// 			DWORD dwTotalLen = 0;
// 			for(int i = 0 ; i < strArray.GetCount(); i++)
// 			{
// 				dwTotalLen += (strArray.GetAt(i).GetLength() + 1 );
// 			}
// 			dwTotalLen += 1;
// 			CString str;
// 			DWORD dwPos = 0;
//  			for(int i=0;i<strArray.GetCount();i++,dwPos++)
//  			{
// 				str.Append(strArray.GetAt(i));
// 			}
// 			str[dwPos] = '\0';

 			//CRegKey

			DWORD dwTotalLen = 0;
			for(int k = 0 ; k < strArray.GetSize(); k++)
			{
				dwTotalLen += (strArray.GetAt(k).GetLength() + 1 );
			}
			dwTotalLen += 1;

			TCHAR* pData = new TCHAR[dwTotalLen];

			DWORD dwPos = 0;
			for(int k = 0 ; k < strArray.GetSize(); k++)
			{
				CString str = strArray.GetAt(k);
				_tcscpy(&pData[dwPos],str);
				dwPos += (str.GetLength()+1);
			}
			pData[dwPos] = _T('\0');

			::RegSetValueEx(keyPtr,day,0,REG_MULTI_SZ, (const BYTE *)pData,dwTotalLen*sizeof(TCHAR));
		}
	}

NoEvent_Return:
	return FALSE;


}