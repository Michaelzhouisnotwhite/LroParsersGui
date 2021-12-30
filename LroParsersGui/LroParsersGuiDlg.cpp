// LroParsersGuiDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "LroParsersGui.h"
#include "LroParsersGuiDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLroParsersGuiDlg 对话框


CLroParsersGuiDlg::CLroParsersGuiDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LROPARSERSGUI_DIALOG, pParent)
	  , m_sAnlaysisInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLroParsersGuiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btnGenLr0Graph);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_EDIT1, m_editInputLr0);
	DDX_Control(pDX, IDC_CHECK1, m_check);
	DDX_Text(pDX, IDC_EDIT2, m_sAnlaysisInput);
	DDX_Control(pDX, IDC_BUTTON5, m_btnProject);
	DDX_Control(pDX, IDC_BUTTON4, m_btnResult);
}

BEGIN_MESSAGE_MAP(CLroParsersGuiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLroParsersGuiDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLroParsersGuiDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CLroParsersGuiDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CLroParsersGuiDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CLroParsersGuiDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT2, &CLroParsersGuiDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CLroParsersGuiDlg 消息处理程序

BOOL CLroParsersGuiDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE); // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// ShowWindow(SW_MAXIMIZE);

	// ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码

	DWORD dwStyle = m_listctrl.GetExtendedStyle(); //listcontrol部分  
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_listctrl.SetExtendedStyle(dwStyle);

	m_check.SetCheck(TRUE);
	m_check.EnableWindow(FALSE);

	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

void CLroParsersGuiDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLroParsersGuiDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLroParsersGuiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLroParsersGuiDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Lr0Parsers tmp;
	m_parser = tmp;
	CString expressions;
	m_editInputLr0.GetWindowTextW(expressions);
	if (expressions.IsEmpty())
	{
		return;
	}
	SplitStr splitStr(expressions.GetBuffer(0), '\n');
	expressions.ReleaseBuffer();
	for (int i = 0; i < splitStr.NSubStrs(); i++)
	{
		auto str_tmp = splitStr.SubStr(i);
		if (str_tmp[wcslen(str_tmp) - 1] == '\r')
		{
			str_tmp[wcslen(str_tmp) - 1] = '\0';
		}
		m_parser.library.Add(ExpressionParser(str_tmp));
	}

	m_parser.StartParsing();
	OnBnClickedButton2();
}


void CLroParsersGuiDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_listctrl.ShowWindow(TRUE);
	for (int i = 0; i < 50; ++i)
	{
		m_listctrl.DeleteColumn(0);
	}
	m_listctrl.DeleteAllItems();
	m_listctrl.InsertColumn(0, L"");
	for (int i = 0; i < m_parser.T.tAction.vts.size(); i++)
	{
		m_listctrl.InsertColumn(i + 1, CString(m_parser.T.tAction.vts[i]), LVCFMT_CENTER, 40);
	}
	for (int i = 0; i < m_parser.T.tGoto.vns.size(); i++)
	{
		m_listctrl.InsertColumn(i + 1 + m_parser.T.tAction.vts.size(), CString(m_parser.T.tGoto.vns[i]), LVCFMT_CENTER,
		                        40);
	}
	AutoAdjustColumnWidth(&m_listctrl);

	for (int i = 0; i < m_parser.T.max_index + 1; ++i)
	{
		CString tmp;
		tmp.Format(_T("%d"), i);
		m_listctrl.InsertItem(i, tmp);
		for (int j = 0; j < m_parser.T.tAction.vts.size(); j++)
		{
			if (m_parser.T.tAction.table[i][j] == -1)
			{
				m_listctrl.SetItemText(i, j + 1, L"");
			}
			else if (m_parser.T.tAction.table[i][j] == Action::ACC)
			{
				m_listctrl.SetItemText(i, j + 1, L"acc");
			}
			else
			{
				tmp.Format(L"%d", m_parser.T.tAction.table[i][j]);
				m_listctrl.SetItemText(i, j + 1, CString(m_parser.T.tAction.type[i][j]) + tmp);
			}
		}
		for (int j = 0; j < m_parser.T.tGoto.vns.size(); j++)
		{
			if (m_parser.T.tGoto.table[i][j] == -1)
			{
				m_listctrl.SetItemText(i, j + 1 + m_parser.T.tAction.vts.size(), L"");
			}
			else
			{
				tmp.Format(L"%d", m_parser.T.tGoto.table[i][j]);
				m_listctrl.SetItemText(i, j + 1 + m_parser.T.tAction.vts.size(), tmp);
			}
		}
	}
}

void CLroParsersGuiDlg::AutoAdjustColumnWidth(CListCtrl* pListCtrl)
{
	pListCtrl->SetRedraw(FALSE);

	CHeaderCtrl* pHeader = pListCtrl->GetHeaderCtrl();
	int nColumnCount = pHeader->GetItemCount();
	for (int i = 0; i < nColumnCount; i++)
	{
		// pListCtrl->SetColumnWidth(i, LVSCW_AUTOSIZE);
		// int nColumnWidth = pListCtrl->GetColumnWidth(i);
		pListCtrl->SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
		int nHeaderWidth = pListCtrl->GetColumnWidth(i);
		pListCtrl->SetColumnWidth(i, nHeaderWidth);
	}
	int width = 0;
	for (int i = 0; i < nColumnCount; ++i)
	{
		width += pListCtrl->GetColumnWidth(i);
	}

	for (int i = 0; i < nColumnCount; ++i)
	{
		pListCtrl->SetColumnWidth(i, width / nColumnCount);
	}
	pListCtrl->SetRedraw(TRUE);
}


void CLroParsersGuiDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	if (m_check.GetCheck())
	{
		m_parser.InputAnalysis(m_sAnlaysisInput + L"#");
	}
	else
	{
		m_parser.InputAnalysis(m_sAnlaysisInput);
	}
}


void CLroParsersGuiDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i = 0; i < 50; ++i)
	{
		m_listctrl.DeleteColumn(0);
	}
	m_listctrl.DeleteAllItems();

	m_listctrl.InsertColumn(0, L"步骤");
	m_listctrl.InsertColumn(1, L"状态栈");
	m_listctrl.InsertColumn(2, L"符号栈");
	m_listctrl.InsertColumn(3, L"输入串", LVCFMT_RIGHT);
	m_listctrl.InsertColumn(4, L"ACTION");
	m_listctrl.InsertColumn(5, L"GOTO");

	AutoAdjustColumnWidth(&m_listctrl);

	for (int i = 0; i < m_parser.state_history.size(); i++)
	{
		m_listctrl.InsertItem(i, Int2String(i));

		std::vector<CString> tmp = {
			Int2String(m_parser.state_history[i], 1), Wchar2String(m_parser.symbol_history[i]),
			Wchar2String(m_parser.input_history[i]),
			CString(m_parser.type_stack[i]) + Int2String(m_parser.action_stack[i]), Int2String(m_parser.goto_stack[i])
		};
		if (tmp[3] == CString(Action::E) + Int2String(Action::ACC))
		{
			tmp[3] = L"acc";
		}
		else if (tmp[3] == CString(Action::E) + Int2String(-1))
		{
			tmp[3] = L"error";
		}

		if (tmp[4] == Int2String(-1))
		{
			tmp[4] = L"";
		}

		for (int j = 0; j < 5; ++j)
		{
			m_listctrl.SetItemText(i, j + 1, tmp[j]);
		}
	}
}


void CLroParsersGuiDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	content = L"{";
	OutputProject(-1, &m_parser.root);
	content += L"}";
	io.SetFilePath(L"./output/project.json");
	int res = io.Dump2File(content);

	if (res == NORMAL)
	{
		MessageBoxW(L"项目集规范集已导出至：" + io.GetFilePath(), L"信息", MB_ICONINFORMATION);
	}
}

void CLroParsersGuiDlg::OutputProject(int s_before, const Container* container)
{
	CString tmp;
	if (container->data == '\0')
	{
		tmp.Format(L"\"I%d\": {\"data\":\"\" ,", container->s);
	}
	else
	{
		tmp.Format(L"\"I%d\": {\"data\":\"%d %wc\" ,", container->s, s_before, container->data);
	}
	content += tmp;
	content += L"\"content\":\"";
	for (const auto& node : container->containers)
	{
		content += CString(node.e->GetLeft()) + L" -> ";
		for (unsigned i = 0; i < node.e->length; i++)
		{
			if (node.where == i)
			{
				content += L"@";
			}
			content += CString(node.e->right[i]);
		}
		if (node.where == node.e->length)
		{
			content += L"@";
		}
		content += L";";
	}
	content += L"\"}";
	for (const auto& node : container->nodes)
	{
		content += L",";
		OutputProject(container->s, node);
	}
}


void CLroParsersGuiDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
