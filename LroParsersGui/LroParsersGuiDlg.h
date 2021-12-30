// LroParsersGuiDlg.h: 头文件
//

#pragma once
#include "LR0_Parser.h"
#include "ExpressionParser.h"
#include "IoProcess.h"
#include "utils.h"

// CLroParsersGuiDlg 对话框
class CLroParsersGuiDlg : public CDialogEx
{
	// 构造
public:
	CLroParsersGuiDlg(CWnd* pParent = nullptr); // 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LROPARSERSGUI_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CButton m_btnGenLr0Graph;

	Lr0Parsers m_parser;
	afx_msg void OnBnClickedButton2();
	void AutoAdjustColumnWidth(CListCtrl* pListCtrl);
	CListCtrl m_listctrl;
	CEdit m_editInputLr0;
	CButton m_check;
	afx_msg void OnBnClickedButton3();
	CString m_sAnlaysisInput;
	afx_msg void OnBnClickedButton4();
	CButton m_btnProject;
	afx_msg void OnBnClickedButton5();
	void OutputProject(int s_before, const Container* container);

	IoProcess io;

	CString content;
	CButton m_btnResult;
	afx_msg void OnEnChangeEdit2();
};
