
// CalendarDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Calendar.h"
#include "CalendarDlg.h"
#include "CalendarCtrl.h"
#include "atltypes.h"
#include "CalendarStorage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMap<COleDateTime,COleDateTime&,bool,bool&>	g_CalendarData;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
private:
	CRect m_pRectLink;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	int m_bOnLink;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
, m_bOnLink(0)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCalendarDlg 对话框




CCalendarDlg::CCalendarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalendarDlg::IDD, pParent)
	, m_pCalendarCtrl(NULL)
	, time(COleDateTime::GetCurrentTime())
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CCalendarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalendarDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_ABOUTBOX, &CCalendarDlg::OnBnClickedAboutbox)
	ON_BN_CLICKED(IDC_SHOWHIDE, &CCalendarDlg::OnBnClickedHide)
	ON_WM_TIMER()
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIME, &CCalendarDlg::OnDtnDatetimechange)
	ON_COMMAND(IDM_SHOWEVENTS, &OnShowEvents)
	ON_COMMAND(IDM_EDITEVENTS, &OnEditEvents)
	ON_COMMAND(IDM_MARKDAY, &OnMarkDay)
	ON_COMMAND(IDM_CLEAREVENTS, &OnClearEvents)
	ON_COMMAND(IDM_SETWEEKDAY, &OnSetWeekDay)
END_MESSAGE_MAP()


// CCalendarDlg 消息处理程序

BOOL CCalendarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// 调整窗口大小，窗体运行时默认隐藏 IDC_EVENTS 事件列表
	CRect rect1;
	GetWindowRect(&rect1);
	rect1.bottom -=130;
	MoveWindow(&rect1);

	// 初始化 IDC_DATE 当前时间
	CString str = _T("    当前时间为：");
	str += time.Format(_T("%Y-%m-%d %H:%M:%S"));
	SetDlgItemText(IDC_DATE,str);

	// 初始化 Timer
	SetTimer(1, 1000, NULL);

	// 实例化 CCalendarCtrl
	m_pCalendarCtrl = new CCalendarCtrl;

	CRect rect2;
	GetDlgItem(IDC_Calendar)->GetWindowRect(&rect2);
	ScreenToClient(&rect2);

	VERIFY(m_pCalendarCtrl->Create(WS_CHILD|WS_VISIBLE|WS_VSCROLL, rect2, this, 1, 
		(LPFN_CALENDAR_DATA_CALLBACK)CalendarDataCallback));

	// 重置 CCalendarCtrl
	m_pCalendarCtrl->Reset();

	// 设置焦点
	m_pCalendarCtrl->SetFocus();

	// 设定 IDC_DATETIME CDateTimeCtrl 的上下限
	COleDateTime * pMinRange = new COleDateTime(100,1,1,0,0,0);
	COleDateTime * pMaxRange = new COleDateTime(3000,1,1,0,0,0);
	((CDateTimeCtrl *)GetDlgItem(IDC_DATETIME))->SetRange(pMinRange,pMaxRange);
	// 因为 CDateTimeCtrl 控件本身的限制，在我的系统下限只能到1600年1月1号
	// 当然可以不使用 CDateTimeCtrl，直接用 EDIT 赋值，这样就可以达到 COleDateTime 的范围 100-9999 年

	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalendarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalendarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalendarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalendarDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if(m_pCalendarCtrl && ::IsWindow(m_pCalendarCtrl->m_hWnd))
	{
		CRect rect;
		GetDlgItem(IDC_Calendar)->GetWindowRect(&rect);
		ScreenToClient(&rect);
		m_pCalendarCtrl->MoveWindow(rect);
	}
}

HRESULT CALLBACK CCalendarDlg::CalendarDataCallback(CCalendarCtrl * pWnd,int cmd, COleDateTime date)
{
	CCalendarStorage store;
	CStringArray strArray;
	CCalendarCell* pCell = pWnd->GetCell(date);

	switch(cmd)
	{
	case cmdTimeChanged:
		{
			CWnd *pMainWnd =AfxGetMainWnd();
			CDateTimeCtrl * dtCtrl = (CDateTimeCtrl *)pMainWnd->GetDlgItem(IDC_DATETIME);
			dtCtrl->SetTime(date);

		}
	break;

	case cmdLoad:
		if(pWnd)
		{
			if(!store.LoadEvent(date,&strArray))
				return FALSE;
			pCell->csaLines.Copy(strArray);
		}
		else
		{
			//执行显示LIST列表数据
		}

	break;

	case cmdSave:
		strArray.Add(CString(_T("test")));
		store.SaveEvent(COleDateTime::GetCurrentTime(),strArray);
	break;

	case cmdMark:
		if(pWnd)
		{
			bool bMarked = NULL;
			if(g_CalendarData.Lookup(date,bMarked))
			{
				CCalendarCell* pCell = pWnd->GetCell(date);
				pCell->bMark = bMarked;
			}
		}
	break;


	default:
		//		CalendarDataItem* p = NULL;
		// 		if(g_CalendarData.Lookup(date, (void*&)p))
		// 		{
		// 			CCalendarCell* pCell = pWnd->GetCell(date);
		// 			pCell->bMark = p->bMarked;
		// 			pCell->csaLines.Copy(p->csLines);
		// 		}
	break;
	}
	return 0;
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_LINK)->GetWindowRect(&m_pRectLink);
	ScreenToClient(m_pRectLink);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pRectLink.PtInRect(point))
	{
		m_bOnLink = 1;
		HCURSOR hCursor;
		hCursor=AfxGetApp()->LoadStandardCursor(IDC_HAND);
		
		//将鼠标设为小手状
		SetCursor(hCursor);
	}else m_bOnLink = 0;
	CDialog::OnMouseMove(nFlags, point);
}

void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_bOnLink)
	{
		CString link;
		GetDlgItemText(IDC_LINK,link);
		ShellExecute(0,NULL,link,NULL,NULL,SW_NORMAL);   
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void CCalendarDlg::OnBnClickedAboutbox()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CCalendarDlg::OnBnClickedHide()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItemText(IDC_SHOWHIDE,str);
	CRect rect;
	GetWindowRect(&rect);
	
	if(_T("隐藏事件") == str)
	{
		rect.bottom -= 130;
		MoveWindow(&rect);
		SetDlgItemText(IDC_SHOWHIDE,_T("显示事件"));
	}
	else
	{
		rect.bottom += 130;
		MoveWindow(&rect);
		SetDlgItemText(IDC_SHOWHIDE,_T("隐藏事件"));
	}
}

void CCalendarDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent = 1)
	{
		time = COleDateTime::GetCurrentTime();
		CString str = _T("    当前时间为：");
		str += time.Format(_T("%Y-%m-%d %H:%M:%S"));
		SetDlgItemText(IDC_DATE,str);
	}

	CDialog::OnTimer(nIDEvent);
}

void CCalendarDlg::OnDtnDatetimechange(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	m_pCalendarCtrl->Goto(COleDateTime(pDTChange->st),true);
	*pResult = 0;
}



class CWeekDayDlg : public CDialog
{
public:
	CWeekDayDlg();

	// 对话框数据
	enum { IDD = IDD_WEEKDAYDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_WeekDay;
};

CWeekDayDlg::CWeekDayDlg() : CDialog(CWeekDayDlg::IDD)
{
}

void CWeekDayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO, m_WeekDay);
}

BEGIN_MESSAGE_MAP(CWeekDayDlg, CDialog)
END_MESSAGE_MAP()


void CCalendarDlg::OnSetWeekDay()
{
	CWeekDayDlg w;
	if(IDOK == w.DoModal())
	{
		m_pCalendarCtrl->SetFirstWeekDay(w.m_WeekDay+1);	
		m_pCalendarCtrl->UpdateCells();
	}
	
	
}
void CCalendarDlg::OnClearEvents()
{
	m_pCalendarCtrl->invokeCallback(cmdClear);
}
void CCalendarDlg::OnMarkDay()
{
	CArray<COleDateTime,COleDateTime&> dwaSelection;
	m_pCalendarCtrl->GetSelectedItems(dwaSelection);
	for(int i=0; i<dwaSelection.GetSize(); i++)
	{
		bool bMarked = NULL;
		if(!g_CalendarData.Lookup(dwaSelection[i], bMarked))
		{
			bMarked = true;
			g_CalendarData.SetAt(dwaSelection[i],bMarked);
		}
		bMarked = true;
	}
	m_pCalendarCtrl->UpdateCells();
}
void CCalendarDlg::OnEditEvents()
{
	m_pCalendarCtrl->invokeCallback(cmdSave);
	AfxMessageBox(_T("hello!"));
}

void CCalendarDlg::OnShowEvents()
{
	m_pCalendarCtrl->invokeCallback(cmdLoad);
	AfxMessageBox(_T("hello!"));
}


