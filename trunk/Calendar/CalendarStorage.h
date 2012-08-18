#pragma once

class CCalendarStorage
{
public:
	CCalendarStorage(void);
	~CCalendarStorage(void);
	BOOL LoadEvent(const COleDateTime &,CStringArray * strArray = NULL);
	BOOL SaveEvent(const COleDateTime &,const CStringArray &);
private:
	HKEY m_CalendarRoot;
};
