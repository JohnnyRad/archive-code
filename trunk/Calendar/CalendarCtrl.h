/* PERF__FREZ/PUB
 * ====================================================
 * CalendarCtrl.h
 * Frederic Rezeau
 * 
 * Perf'Control Personal Edition calendar 
 *
 * If you like it, feel free to use it. 
 *
 * www.performlabs.com 
 * ==================================================== 
 */
///////////////////////////////////////////////////////
/*	Modified by VYSE
*
*	Fix 2038 limit of time_t by throughly adopting COleDateTime as Time Type
*	Add every date cell can display if any events exist
*	Move event display function out of this Ctrl
*	
*/
///////////////////////////////////////////////////////

#ifndef _PERF_CALENDARCTRL_H___INCLUDED
#define _PERF_CALENDARCTRL_H___INCLUDED
#include "afxwin.h"

#define CALENDAR_LIGHTGREY		RGB(235,235,235)
#define CALENDAR_LINE_HEIGHT	15
#define CALENDAR_HEADER_HEIGHT	20
#define CALENDAR_ROWS			6
#define CALENDAR_COLUMNS		7

#define IDM_SHOWEVENTS	1400
#define IDM_EDITEVENTS	1401
#define IDM_CLEAREVENTS	1402
#define IDM_MARKDAY		1403
#define IDM_SETWEEKDAY	1404

#define cmdTimeChanged 0
#define cmdLoad	1
#define cmdSave 2
#define cmdClear 3
#define cmdTruncate 4
#define cmdMark 5

typedef HRESULT (CALLBACK FAR * LPFN_CALENDAR_DATA_CALLBACK)(CWnd*,int,COleDateTime);

/////////////////////////////////////////////////////////////////////////////
// class CCalendarCell --   
/////////////////////////////////////////////////////////////////////////////
struct CCalendarCell
{
	COleDateTime	date;
	CStringArray	csaLines;
	bool			bPartial;
	bool			bMark;
};

/////////////////////////////////////////////////////////////////////////////
// class CCalendarCtrl --   
/////////////////////////////////////////////////////////////////////////////
class CCalendarCtrl : public CWnd
{

public:
	CCalendarCtrl();
	virtual ~CCalendarCtrl();

	BOOL Create(DWORD dwStyle, const CRect &wndRect, CWnd *pParent, UINT nID, LPFN_CALENDAR_DATA_CALLBACK pfnDataCallback);

	void Reset();
	void Goto(const COleDateTime& dtDate, bool bSelect = false);

	void SetFirstWeekDay(int nWeekday) { m_nFirstWeekDay = nWeekday; }
	int GetFirstWeekDay() { return m_nFirstWeekDay; }

	int GetSelectedItems(CArray<COleDateTime,COleDateTime&> & dwaSelection);
	const COleDateTime& GetMinDate() { return m_dayCells[0][0].date; };
	const COleDateTime& GetMaxDate() { return m_dayCells[CALENDAR_ROWS-1][CALENDAR_COLUMNS-1].date; };
	
	void UpdateCells();

	CCalendarCell* GetCell(COleDateTime date);
	CCalendarCell* GetCell (CPoint point, int &nRow, int &nCol);	

	//{{AFX_VIRTUAL(CCalendarCtrl)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

protected:	

	void DrawHeader(CDC* pDC);
	void DrawGrid(CDC* pDC);
	void DrawCells(CDC* pDC);

	bool GetGridCellFromPoint(CPoint point, int &nRow, int &nCol);
	bool GetRectFromCell(int nRow, int nCol, CRect& rect);
	void GetLastSelectedGridCell(int &nRow, int &nCol);
	void AdjustSelection();

	// helper func
	COLORREF GetFadedBlue(unsigned char percent);

	//{{AFX_MSG(CCalendarCtrl)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CFont			m_DefaultFont;
	CCalendarCell	m_dayCells[CALENDAR_ROWS][CALENDAR_COLUMNS];
	int				m_nMaxSel;
	COleDateTime	m_BoundUp;
	COleDateTime	m_BoundDown;
	COleDateTime	m_DateCurrent;
	BOOL			m_bSelectionStarted;
	COleDateTime	m_SelectionRange[3];
	CMap<COleDateTime,COleDateTime&,void *,void *>	m_RandomSelection;
	int				m_nFirstWeekDay; // 1 = sunday	
	bool			m_bMonthIsOdd;
	int				m_nVscrollPos;
	int				m_nVscrollMax;

	LPFN_CALENDAR_DATA_CALLBACK	
					m_pfnDataCallback;
	CMenu menu;
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	BOOL invokeCallback(int cmd);
};


#endif // _PERF_CALENDARCTRL_H___INCLUDED
