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

// CyberNannyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CyberNanny.h"
#include "CyberNannyDlg.h"
#include "afxdialogex.h"
#include "Nui_Core.h"
#include "Utils.h"
#include "ImageFile.h"
#include <ShellAPI.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/// <summary>	The wm add new event. </summary>
int WM_ADD_NEW_EVENT = RegisterWindowMessage (L"Add_New_Event_To_List");


////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Dialog for setting the about. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CCyberNannyDlg dialog

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="pParent">	[in,out] If non-null, the parent. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

CCyberNannyDlg::CCyberNannyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCyberNannyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Exchanges data to/from the controls in this dialog. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="pDX">	[in,out] If non-null, an object that manages the data exchange operation. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EVENTS, m_events);
	DDX_Control(pDX, IDC_TAB1, m_streamTabs);
}

BEGIN_MESSAGE_MAP(CCyberNannyDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_REGISTERED_MESSAGE(WM_ADD_NEW_EVENT, &OnAddNewEvent)
	ON_COMMAND(ID_HELP_ABOUT, &CCyberNannyDlg::OnHelpAbout)
	ON_COMMAND(ID_FILE_EXIT, &CCyberNannyDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUTWINDOWS, &CCyberNannyDlg::OnAboutWindows)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CCyberNannyDlg::OnTabChanged)
END_MESSAGE_MAP()


// CCyberNannyDlg message handlers

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initialises this dialog and the controls within it. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CCyberNannyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Initialization code
	CreateStatusBar();
	CreateTabControl();

	// Initialize Kinect Object here
	m_isPolling = NULL;
	m_Kinect.SetUp(m_views, m_viewRect, true);
	m_timer = SetTimer(IDS_UPDATE_STATUSBAR_TIMER, 1000, NULL);
	m_pollingTimer = SetTimer(IDS_POLLING_TIMER, 15000, NULL);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Paints this window. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCyberNannyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates the status bar. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::CreateStatusBar() {
	CRect rect;
	UINT BASED_CODE indicators[] = {IDS_APPLICATION_RUNNING, IDS_EXECUTION_START, IDS_KINECT_STATUS};
	m_statusBar.Create(this);
	m_statusBar.SetIndicators(indicators, 3);
	GetClientRect(&rect);
	m_statusBar.EnableToolTips(TRUE);
	m_statusBar.SetPaneInfo(0, IDS_APPLICATION_RUNNING, SBPS_NORMAL, rect.Width() / 3.5);
	m_statusBar.SetPaneInfo(1, IDS_EXECUTION_START, SBPS_NORMAL, rect.Width() / 2.5);
	m_statusBar.SetPaneInfo(2, IDS_KINECT_STATUS, SBPS_NORMAL, rect.Width() / 3);
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST, IDS_APPLICATION_RUNNING);
	UpdateStatusBar();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Updates the status bar. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::UpdateStatusBar() {
	m_statusBar.SetPaneText(1, m_Kinect.StartTimeAsString_get(), TRUE);
	m_statusBar.SetPaneText(2, m_Kinect.SensorId_get(), TRUE);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the help about action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnHelpAbout() {
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Back, called when the polling queue. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="pParam">	The parameter. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD WINAPI CCyberNannyDlg::PollingQueueCallBack(LPVOID pParam) {
	auto retval = (CCyberNannyDlg*) pParam;
	return (retval->PollingQueue());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the polling queue. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD WINAPI CCyberNannyDlg::PollingQueue() {
	Utils parser;
	ProcessRequest(parser.RemoveRequest(99999999, false));
	CloseHandle(m_isPolling);
	m_isPolling = NULL;

	return FALSE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Process the request described by request. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="request">	The request. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::ProcessRequest(_request request) {
	if (!request.IsEmpty) {
		auto byteCount = 0;
		ImageFile imageFile;
		std::shared_ptr<BYTE> bytes;
		m_Kinect.TakePicture(bytes, byteCount);
		imageFile.SerializeImage(bytes, byteCount);
		EventLogHelper::LogRequest(request);
		auto currentTime = CTime::GetCurrentTime().Format("%A, %B %d, %Y - %H:%M:%S");
		auto newEvent =  std::wstring(L"Action: ").append(request.Action).append(L" - Requested By: ")
			.append((_wtoi(request.Requestor.c_str()) == 99999999 ? L"Angel" : L"Mery" ))
			.append(L" - On: ").append(currentTime);

		CString *message = new CString(newEvent.c_str());
		PostMessage(WM_ADD_NEW_EVENT, (WPARAM) message, NULL);
		m_emailer.ComposeAndSend(request.EmailRecipient, imageFile.ImageFilePath_get()); 
		imageFile.DeleteFile();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the add new event action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="wParam">	The wParam field of the message. </param>
/// <param name="lParam">	The lParam field of the message. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

LRESULT CCyberNannyDlg::OnAddNewEvent(WPARAM wParam, LPARAM lParam) {
	CString eventId;
	auto newEvent = (CString*) wParam;
	auto lstEvents = (CListBox*) GetDlgItem(IDC_EVENTS);
	eventId.Format(L"Event #:%d - ", lstEvents->GetCount() + 1);
	newEvent->Insert(0, eventId);
	lstEvents->AddString(newEvent->GetString());
	delete newEvent;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the timer action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="nIDEvent">	The identifier event. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnTimer(UINT nIDEvent) {
	switch(nIDEvent) {
	case IDS_UPDATE_STATUSBAR_TIMER:
		UpdateStatusBar();
		break;

	case IDS_POLLING_TIMER:
		if (m_Kinect.HasBeenInitialized_get() &&  m_isPolling == NULL) {
			m_isPolling = CreateMutex(NULL, TRUE, POLLING_MUTEX_NAME);
			HANDLE hThread = CreateThread(NULL, 0, PollingQueueCallBack, this, 0, NULL);
			WaitForSingleObject(hThread, 5000);
			CloseHandle(hThread);
		}
		break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the file exit action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnFileExit() {
	if (::MessageBox(m_hWnd, L"Are you sure you want to quit \"Cyber Nanny\"? ",
		L"Confirm", MB_YESNO | MB_ICONQUESTION) == 6) {

			if (m_views.size() > 0) {
				std::for_each(m_views.begin(), m_views.end(),[=](std::pair<CString, CStatic*> item) {
					item.second->DestroyWindow();
					delete item.second;
				});
			}

			EndDialog(IDOK);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the cancel action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnCancel() {
	// Let's disable the ESC button
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the about windows action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnAboutWindows() {
	ShellAbout(m_hWnd, L"CyberNanny v.1.0", L"Application for looking after babies when dad is not around. Written by Angel Hernandez. Microsoft MVP Visual C++", NULL);

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Creates the tab control. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::CreateTabControl() {
	CRect rect;
	auto nIndex = 0;
	auto tabs = std::map<CString, TCITEM>();
	auto tabContainer = GetDlgItem(IDC_TAB1);
	tabContainer->GetClientRect(&rect);
	CString views[] = {TAB_VIEW_1};
	tabs.insert(std::pair<CString, TCITEM>(L"Color View", TCITEM()));

	std::for_each(tabs.begin(), tabs.end(), [&] (std::pair<CString, TCITEM> tab) {
		tab.second.mask = TCIF_TEXT;
		tab.second.pszText =  (LPWSTR) tab.first.GetBuffer();
		m_streamTabs.InsertItem(nIndex, &tab.second);
		m_viewRect.left = rect.left + 5;
		m_viewRect.top = rect.top + 25;
		m_viewRect.right = rect.right - 5;
		m_viewRect.bottom = rect.bottom - 5;

		m_views[views[nIndex]] = new CStatic;
		m_views[views[nIndex]]->Create(views[nIndex], WS_CHILD | WS_VISIBLE | SS_CENTER | SS_BLACKFRAME,
			CRect(m_viewRect.left, m_viewRect.top, m_viewRect.right, m_viewRect.bottom), tabContainer, 1);
		nIndex++;
	});
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the tab changed action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="pNMHDR"> 	[in,out] If non-null, the nmhdr. </param>
/// <param name="pResult">	[out] if non-null, the result. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnTabChanged(NMHDR *pNMHDR, LRESULT *pResult) {
	TCITEM item;
	auto bufSize = 30;
	item.mask = TCIF_TEXT;
	unique_ptr<wchar_t> buffer (new wchar_t[bufSize]);
	item.pszText = buffer.get();
	item.cchTextMax = bufSize;
	CString views[] = {TAB_VIEW_1, TAB_VIEW_2, TAB_VIEW_3};
	auto selected = m_streamTabs.GetItem(m_streamTabs.GetCurSel(), &item);

	for (auto nIndex = 0; nIndex < 3; nIndex++) 
		::ShowWindow(m_views[views[nIndex]]->m_hWnd, (nIndex == m_streamTabs.GetCurSel() ? SW_SHOW : SW_HIDE));

	*pResult = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Executes the destroy action. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void CCyberNannyDlg::OnDestroy() {
	KillTimer(m_timer);
	KillTimer(m_pollingTimer);
}