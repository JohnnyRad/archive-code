// Author:      SFr frydaysoft@gmx.de

#if !defined(AFX_COLOREDLISTCTRL_H__A6784F28_01EA_45AD_A375_0C84A92ABC10__INCLUDED_)
#define AFX_COLOREDLISTCTRL_H__A6784F28_01EA_45AD_A375_0C84A92ABC10__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CColoredListCtrlApp:
// Siehe ColoredListCtrl.cpp für die Implementierung dieser Klasse
//

class CColoredListCtrlApp : public CWinApp
{
public:
	CColoredListCtrlApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CColoredListCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CColoredListCtrlApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio fügt zusätzliche Deklarationen unmittelbar vor der vorhergehenden Zeile ein.

#endif // !defined(AFX_COLOREDLISTCTRL_H__A6784F28_01EA_45AD_A375_0C84A92ABC10__INCLUDED_)
