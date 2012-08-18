// Author:      SFr frydaysoft@gmx.de

#if !defined(AFX_COLOREDLISTCTRLDLG_H__A4203A7F_F819_4697_9A86_45F2B5AC24AF__INCLUDED_)
#define AFX_COLOREDLISTCTRLDLG_H__A4203A7F_F819_4697_9A86_45F2B5AC24AF__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "ColorListCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CColoredListCtrlDlg Dialogfeld

class CColoredListCtrlDlg : public CDialog
{
// Konstruktion
public:
	CColoredListCtrlDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

// Dialogfelddaten
	//{{AFX_DATA(CColoredListCtrlDlg)
	enum { IDD = IDD_COLOREDLISTCTRL_DIALOG };
	CComboBox	m_ComboCtrlText;
	CComboBox	m_ComboCtrlBack;
	CColorListCtrl	m_ColListCtrl;
	UINT	m_IntDelInsPos;
	UINT	m_IntItemPos;
	UINT	m_IntItemSubPos;
	CString	m_StrItemText;
	CString	m_StrSubText1;
	CString	m_StrSubText2;
	int		m_RadioBits;
	CString	m_StrColoredText;
	UINT	m_IntItemStatePos;
	BOOL	m_DotFocus;
	BOOL	m_VertLines;
	BOOL	m_WithRect;
	//}}AFX_DATA

    #define COLUMNS_m_ColListCtrl 3

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CColoredListCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CColoredListCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONdelete();
	afx_msg void OnBUTTONinsert();
	afx_msg void OnBUTTONSet();
	afx_msg void OnBUTTONColorSet();
	afx_msg void OnCHECKDotFocus();
	afx_msg void OnCHECKWithRect();
	afx_msg void OnCHECKVertLines();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_COLOREDLISTCTRLDLG_H__A4203A7F_F819_4697_9A86_45F2B5AC24AF__INCLUDED_)
