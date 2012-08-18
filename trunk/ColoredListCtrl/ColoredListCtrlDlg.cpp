// Author:      SFr frydaysoft@gmx.de

#include "stdafx.h"
#include "ColoredListCtrl.h"
#include "ColoredListCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld f黵 Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte 躡erladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterst黷zung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColoredListCtrlDlg Dialogfeld

CColoredListCtrlDlg::CColoredListCtrlDlg(CWnd* pParent /*=NULL*/)
: CDialog(CColoredListCtrlDlg::IDD, pParent),m_ColListCtrl(COLUMNS_m_ColListCtrl)
{
	//{{AFX_DATA_INIT(CColoredListCtrlDlg)
	m_IntDelInsPos = 0;
	m_IntItemPos = 0;
	m_IntItemSubPos = 0;
	m_StrItemText = _T("Item");
	m_StrSubText1 = _T("Sub1");
	m_StrSubText2 = _T("Sub2");
	m_RadioBits = 0;
	m_StrColoredText = _T("");
	m_IntItemStatePos = 0;
	m_DotFocus = FALSE;
	m_VertLines = FALSE;
	m_WithRect = FALSE;
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf ben鰐igt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    m_VertLines=m_ColListCtrl.GetColumnType();
    m_WithRect=m_ColListCtrl.GetRectType();
    m_DotFocus=m_ColListCtrl.GetFocusType();

}

void CColoredListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColoredListCtrlDlg)
	DDX_Control(pDX, IDC_COMBO_TextCol, m_ComboCtrlText);
	DDX_Control(pDX, IDC_COMBO_BackGnd, m_ComboCtrlBack);
	DDX_Control(pDX, IDC_LIST1, m_ColListCtrl);
	DDX_Text(pDX, IDC_EDIT_ItemDelInsPos, m_IntDelInsPos);
	DDX_Text(pDX, IDC_EDIT_ItemPos, m_IntItemPos);
	DDX_Text(pDX, IDC_EDIT_ItemSubPos, m_IntItemSubPos);
	DDX_Text(pDX, IDC_EDIT_ItemText, m_StrItemText);
	DDX_Text(pDX, IDC_EDIT_SubText1, m_StrSubText1);
	DDX_Text(pDX, IDC_EDIT_SubText2, m_StrSubText2);
	DDX_Radio(pDX, IDC_RADIO_BITS, m_RadioBits);
	DDX_Text(pDX, IDC_EDIT_ItemColoredText, m_StrColoredText);
	DDX_Text(pDX, IDC_EDIT_ItemStatePos, m_IntItemStatePos);
	DDX_Check(pDX, IDC_CHECK_DotFocus, m_DotFocus);
	DDX_Check(pDX, IDC_CHECK_VertLines, m_VertLines);
	DDX_Check(pDX, IDC_CHECK_WithRect, m_WithRect);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CColoredListCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CColoredListCtrlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_delete, OnBUTTONdelete)
	ON_BN_CLICKED(IDC_BUTTON_insert, OnBUTTONinsert)
	ON_BN_CLICKED(IDC_BUTTON_Set, OnBUTTONSet)
	ON_BN_CLICKED(IDC_BUTTON_ColorSet, OnBUTTONColorSet)
	ON_BN_CLICKED(IDC_CHECK_DotFocus, OnCHECKDotFocus)
	ON_BN_CLICKED(IDC_CHECK_WithRect, OnCHECKWithRect)
	ON_BN_CLICKED(IDC_CHECK_VertLines, OnCHECKVertLines)
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CColoredListCtrlDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CColoredListCtrlDlg Nachrichten-Handler

BOOL CColoredListCtrlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzuf黦en des Men黚efehls "Info..." zum Systemmen?

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol f黵 dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Gro遝s Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// ZU ERLEDIGEN: Hier zus鋞zliche Initialisierung einf黦en

    CStringArray Head;
    CByteArray   Cols;
    Head.Add("Item");
    Cols.Add(40);       //40%
    Head.Add("Sub1");
    Cols.Add(30);       //70%
    Head.Add("Sub2");
    Cols.Add(30);       //100%
    m_ColListCtrl.InitCtrl(&Head, &Cols);

    CString Linetitle;
    int pos=0;
    for (int x=0; x<10;x++)
    {
        Head.RemoveAll();
        Linetitle.Format("Line %d",x);
        Head.Add(Linetitle);
        Linetitle.Format("SubLine %d-1",x);
        Head.Add(Linetitle);
        Linetitle.Format("SubLine %d-2",x);
        Head.Add(Linetitle);
        pos=m_ColListCtrl.AddItem(&Head);
        if (pos!=LISTCTRL_ERROR) ;
    }
    m_ColListCtrl.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0, (LPARAM)LVS_EX_FULLROWSELECT); 

    for (x=0; x<COLLIST_MAX;x++)
    {
        
        m_ComboCtrlText.AddString(colList[x].str);
        m_ComboCtrlBack.AddString(colList[x].str);
    }
    m_ComboCtrlBack.SetCurSel(0);
    m_ComboCtrlText.SetCurSel(1);

	return TRUE;  // Geben Sie TRUE zur點k, au遝r ein Steuerelement soll den Fokus erhalten
}

void CColoredListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfl鋍he "Minimieren" hinzuf黦en, ben鰐igen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. F黵 MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch f黵 Sie erledigt.

void CColoredListCtrlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Ger鋞ekontext f黵 Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, w鋒rend der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CColoredListCtrlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CColoredListCtrlDlg::OnBUTTONdelete() 
{
	// delete an item
    UpdateData(TRUE);
    m_ColListCtrl.DeleteItem(m_IntDelInsPos);
}

void CColoredListCtrlDlg::OnBUTTONinsert() 
{
    //insert new item
	UpdateData(TRUE);
    CStringArray line;
    line.Add(m_StrItemText);
    line.Add(m_StrSubText1);
    line.Add(m_StrSubText2);
    m_ColListCtrl.AddItem(&line);

}

void CColoredListCtrlDlg::OnBUTTONSet() 
{
	// set state normal=0,select=1 or focused=2
    UpdateData(TRUE);

    switch(m_RadioBits)
    {
        case 0: m_ColListCtrl.SetItemState( int(m_IntItemStatePos), 0             , LVIS_SELECTED|LVIS_FOCUSED|LVS_EX_FULLROWSELECT);   break;
        case 1: m_ColListCtrl.SetItemState( int(m_IntItemStatePos), LVIS_SELECTED , LVIS_SELECTED|LVS_EX_FULLROWSELECT);                break;
        case 2: m_ColListCtrl.SetItemState( int(m_IntItemStatePos), LVIS_FOCUSED  , LVIS_FOCUSED|LVS_EX_FULLROWSELECT);                 
                m_ColListCtrl.SetFocus();
                break;
    }
}

void CColoredListCtrlDlg::OnBUTTONColorSet() 
{
    // set color & text
    UpdateData(TRUE);
    int BackColIndex,TextColIndex;


    BackColIndex=m_ComboCtrlBack.GetCurSel();
    TextColIndex=m_ComboCtrlText.GetCurSel();

    if (BackColIndex!=CB_ERR) BackColIndex=colList[BackColIndex].col;
    if (TextColIndex!=CB_ERR) TextColIndex=colList[TextColIndex].col;

    if (m_StrColoredText.GetLength())m_ColListCtrl.SetItemText(int (m_IntItemPos), int (m_IntItemSubPos), LPCTSTR(m_StrColoredText));
    m_ColListCtrl.SetItemBackgndColor(ITEM_COLOR(BackColIndex), int (m_IntItemPos), int (m_IntItemSubPos) );
    m_ColListCtrl.SetItemTextColor(ITEM_COLOR(TextColIndex), int (m_IntItemPos), int (m_IntItemSubPos) );
}

void CColoredListCtrlDlg::OnCHECKDotFocus() 
{
    UpdateData(TRUE);
    m_ColListCtrl.SetFocusType(m_DotFocus);
}

void CColoredListCtrlDlg::OnCHECKWithRect() 
{
    UpdateData(TRUE);
    m_ColListCtrl.SetRectType(m_WithRect);
}

void CColoredListCtrlDlg::OnCHECKVertLines() 
{
    UpdateData(TRUE);
    m_ColListCtrl.SetColumnType(m_VertLines);
}

void CColoredListCtrlDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
