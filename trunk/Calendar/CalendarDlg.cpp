
// CalendarDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCalendarDlg �Ի���




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


// CCalendarDlg ��Ϣ�������

BOOL CCalendarDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// �������ڴ�С����������ʱĬ������ IDC_EVENTS �¼��б�
	CRect rect1;
	GetWindowRect(&rect1);
	rect1.bottom -=130;
	MoveWindow(&rect1);

	// ��ʼ�� IDC_DATE ��ǰʱ��
	CString str = _T("    ��ǰʱ��Ϊ��");
	str += time.Format(_T("%Y-%m-%d %H:%M:%S"));
	SetDlgItemText(IDC_DATE,str);

	// ��ʼ�� Timer
	SetTimer(1, 1000, NULL);

	// ʵ���� CCalendarCtrl
	m_pCalendarCtrl = new CCalendarCtrl;

	CRect rect2;
	GetDlgItem(IDC_Calendar)->GetWindowRect(&rect2);
	ScreenToClient(&rect2);

	VERIFY(m_pCalendarCtrl->Create(WS_CHILD|WS_VISIBLE|WS_VSCROLL, rect2, this, 1, 
		(LPFN_CALENDAR_DATA_CALLBACK)CalendarDataCallback));

	// ���� CCalendarCtrl
	m_pCalendarCtrl->Reset();

	// ���ý���
	m_pCalendarCtrl->SetFocus();

	// �趨 IDC_DATETIME CDateTimeCtrl ��������
	COleDateTime * pMinRange = new COleDateTime(100,1,1,0,0,0);
	COleDateTime * pMaxRange = new COleDateTime(3000,1,1,0,0,0);
	((CDateTimeCtrl *)GetDlgItem(IDC_DATETIME))->SetRange(pMinRange,pMaxRange);
	// ��Ϊ CDateTimeCtrl �ؼ���������ƣ����ҵ�ϵͳ����ֻ�ܵ�1600��1��1��
	// ��Ȼ���Բ�ʹ�� CDateTimeCtrl��ֱ���� EDIT ��ֵ�������Ϳ��Դﵽ COleDateTime �ķ�Χ 100-9999 ��

	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalendarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalendarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalendarDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
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
			//ִ����ʾLIST�б�����
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetDlgItem(IDC_LINK)->GetWindowRect(&m_pRectLink);
	ScreenToClient(m_pRectLink);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_pRectLink.PtInRect(point))
	{
		m_bOnLink = 1;
		HCURSOR hCursor;
		hCursor=AfxGetApp()->LoadStandardCursor(IDC_HAND);
		
		//�������ΪС��״
		SetCursor(hCursor);
	}else m_bOnLink = 0;
	CDialog::OnMouseMove(nFlags, point);
}

void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CCalendarDlg::OnBnClickedHide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str;
	GetDlgItemText(IDC_SHOWHIDE,str);
	CRect rect;
	GetWindowRect(&rect);
	
	if(_T("�����¼�") == str)
	{
		rect.bottom -= 130;
		MoveWindow(&rect);
		SetDlgItemText(IDC_SHOWHIDE,_T("��ʾ�¼�"));
	}
	else
	{
		rect.bottom += 130;
		MoveWindow(&rect);
		SetDlgItemText(IDC_SHOWHIDE,_T("�����¼�"));
	}
}

void CCalendarDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent = 1)
	{
		time = COleDateTime::GetCurrentTime();
		CString str = _T("    ��ǰʱ��Ϊ��");
		str += time.Format(_T("%Y-%m-%d %H:%M:%S"));
		SetDlgItemText(IDC_DATE,str);
	}

	CDialog::OnTimer(nIDEvent);
}

void CCalendarDlg::OnDtnDatetimechange(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pCalendarCtrl->Goto(COleDateTime(pDTChange->st),true);
	*pResult = 0;
}



class CWeekDayDlg : public CDialog
{
public:
	CWeekDayDlg();

	// �Ի�������
	enum { IDD = IDD_WEEKDAYDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


