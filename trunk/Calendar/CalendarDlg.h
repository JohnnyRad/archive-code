
// CalendarDlg.h : ͷ�ļ�
//

#pragma once

#include "CalendarCtrl.h"

typedef struct CalendarDataItem
{
	bool bMarked;
	CStringArray csLines;
}CalendarDataItem;


// CCalendarDlg �Ի���
class CCalendarDlg : public CDialog
{
// ����
public:
	CCalendarDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALENDAR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowEvents();
	afx_msg void OnEditEvents();
	afx_msg void OnClearEvents();
	afx_msg void OnMarkDay();
	afx_msg void OnSetWeekDay();
	DECLARE_MESSAGE_MAP()
	CCalendarCtrl * m_pCalendarCtrl;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
private:
	static HRESULT CALLBACK CalendarDataCallback(CCalendarCtrl * pWnd,int cmd, COleDateTime date);
public:
	afx_msg void OnBnClickedAboutbox();
	afx_msg void OnBnClickedHide();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	COleDateTime time;
public:
	afx_msg void OnDtnDatetimechange(NMHDR *pNMHDR, LRESULT *pResult);
};
