// Copyright (C) 2012 Angel Hernández Matos / Bonafide Ideas.
// You can redistribute this software and/or modify it under the terms of the 
// Microsoft Reciprocal License (Ms-RL).  This program is distributed in the hope 
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
// See License.txt for more details. 

/* C++ compiler      : Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 16.00.40219.01 for 80x86
   Creation date     : 14/04/2012
   Developer         : Angel Hernández Matos
   e-m@il            : angel@bonafideideas.com 
 					 : angeljesus14@hotmail.com
   Website           : http://www.bonafideideas.com
*/

// CyberNannyDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "Nui_Core.h"
#include "EmailHelper.h"
#include "Proxy.h"

// CCyberNannyDlg dialog
class CCyberNannyDlg : public CDialogEx
{
	// Construction
public:
	CCyberNannyDlg(CWnd* pParent = NULL);	// standard constructor

	// Dialog Data
	enum { IDD = IDD_CYBERNANNY_DIALOG };

protected:
	CRect m_viewRect;
	Nui_Core m_Kinect;
	HANDLE m_isPolling;
	EmailHelper m_emailer;
	UINT_PTR m_timer, m_pollingTimer;
	std::map<CString, CStatic*> m_views;
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg LRESULT OnAddNewEvent(WPARAM wParam, LPARAM lParam);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HCURSOR OnQueryDragIcon();
	void CreateStatusBar();
	void CreateTabControl();
	void UpdateStatusBar();
	DECLARE_MESSAGE_MAP()
public:
	CMenu m_mainMenu;
	CListBox m_events;
	CTabCtrl m_streamTabs;
	CStatusBar m_statusBar;
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnAboutWindows();
	afx_msg void OnTabChanged(NMHDR *pNMHDR, LRESULT *pResult);


private:
	DWORD WINAPI PollingQueue();
	void ProcessRequest(_request request);
	static DWORD WINAPI PollingQueueCallBack(LPVOID pParam);
};