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

#include "stdafx.h"
#include "EmailHelper.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

EmailHelper::EmailHelper() {
	m_senderAccount = L"cybernanny@somedomain.com";
	Initialize();	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

EmailHelper::~EmailHelper() {
	if (m_isInitialized) {
		Cleanup();

	}

	CoUninitialize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Cleanups this object. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EmailHelper::Cleanup() {
	m_namespace.Logoff();
	m_application.Quit();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="sender">	The sender. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

EmailHelper::EmailHelper(std::wstring sender) {
	m_senderAccount = sender;
	Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Searches for the first and select account. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	The found and select account. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

Account EmailHelper::FindAndSelectAccount() {
	Account retval;
	VARIANT index;

	auto accounts = (Accounts) (((NameSpace) m_application.get_Session()).get_Accounts());

	for (int nIndex = 0; nIndex < accounts.get_Count(); nIndex++) {
		retval = (Account) accounts.Item(_variant_t(nIndex + 1));
		auto accountName = retval.get_DisplayName();

		if (!_wcsnicmp(accountName, L"cybernanny@somedomain.com", wcslen(accountName))) 
			break;
		else retval = NULL;
	}

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Compose and send. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="target">	 	Target for the. </param>
/// <param name="attachment">	The attachment. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EmailHelper::ComposeAndSend(std::wstring target, std::wstring attachment) {
	if (m_isInitialized) {
		HANDLE hMutex = CreateMutex(NULL, FALSE, EMAILER_MUTEX_NAME);

		if (hMutex != NULL && (GetLastError() == ERROR_ALREADY_EXISTS)) {
			CloseHandle(hMutex);
			return;
		}

		CoInitializeEx(NULL, COINIT_MULTITHREADED);

		auto selectedAccount = FindAndSelectAccount();

		try {
			auto message = MailItem(m_application.CreateItem(NULL));
			message.put_Subject(L"Request from Cyber Nanny");
			message.put_To(target.length() > 0 ? target.c_str() : L"myaccount@hotmail.com");

			// Let's use specified account (otherwise we use default account)
			if (selectedAccount.m_lpDispatch != NULL) 
				message.put_SendUsingAccount(selectedAccount);

			if (attachment.length() > 0) { // Is there an image to attach?
				message.put_Body(L"Request from Cyber Nanny. Please see attached photo and/or video.");
				((_Attachments) message.get_Attachments()).Add(_variant_t(attachment.c_str()), _variant_t(1), 
					_variant_t(VT_EMPTY), _variant_t(L"Photo and/or video"));
			} else message.put_Body(L"Request from Cyber Nanny. Photo could not be attached - Please contact your administrator");

			message.Send();
		} catch (COleException* ex) {
			_com_error err(ex->m_sc);
			OutputDebugString(err.ErrorMessage());
		}

		CloseHandle(hMutex);
		hMutex = NULL;

		CoUninitialize();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Starts an outlook. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EmailHelper::StartOutlook() {
	STARTUPINFO startInfo;
	PROCESS_INFORMATION processInfo;
	ZeroMemory(&startInfo, sizeof(startInfo));
	startInfo.dwFlags = STARTF_USESHOWWINDOW;
	startInfo.wShowWindow = SW_SHOWMINIMIZED;
	auto hCurrentWindow = GetForegroundWindow();
	startInfo.cb = sizeof(startInfo);
	ZeroMemory(&processInfo, sizeof(processInfo));
	TCHAR outlookPath64[] = _T("C:\\Program Files\\Microsoft Office\\Office14\\outlook.exe");
	TCHAR outlookPath32[] = _T("C:\\Program Files (x86)\\Microsoft Office\\Office14\\outlook.exe");

	if (GetFileAttributes(outlookPath64) != -1) 
		CreateProcess(NULL, outlookPath64, NULL, NULL, 1, NORMAL_PRIORITY_CLASS, NULL, NULL, &startInfo, &processInfo);
	else if (GetFileAttributes(outlookPath32) != -1)
		CreateProcess(NULL, outlookPath32, NULL, NULL, 1, NORMAL_PRIORITY_CLASS, NULL, NULL, &startInfo, &processInfo); 

	if(processInfo.hProcess == 0 || (WaitForInputIdle(processInfo.hProcess, 10000)) == WAIT_TIMEOUT)
		m_outlookNotFound = true;

	SetForegroundWindow(hCurrentWindow);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Starts an and or kill outlook. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EmailHelper::StartAndOrKillOutlook() {
	PROCESSENTRY32 process = {0};
	process.dwSize = sizeof(PROCESSENTRY32);
	auto hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	Process32First(hSnapshot, &process);

	do {
		if (!_wcsnicmp(process.szExeFile, L"outlook.exe", wcslen(process.szExeFile))) {
			auto hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process.th32ProcessID);
			TerminateProcess(hProcess, NULL);
			CloseHandle(hProcess);
		}
	} while (Process32Next(hSnapshot, &process));

	CloseHandle(hSnapshot);
	StartOutlook();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes this object. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EmailHelper::Initialize() {
	CLSID clsid;
	CComPtr<IUnknown> pUnk;
	m_isInitialized = false;
	auto ableToAttach = false;
	m_outlookNotFound = false;
	StartAndOrKillOutlook();
	VARIANT dontShowDialog = _variant_t(FALSE);
	CLSIDFromProgID(_T(OUTLOOK_APP_CLASS), &clsid);  

	if (!m_outlookNotFound) {
		CoInitializeEx(NULL, COINIT_MULTITHREADED);

		for (auto count=1; count <= 5 && !ableToAttach; count++) {
			if ((SUCCEEDED(GetActiveObject(clsid, NULL, (IUnknown**)&pUnk)))) 
				ableToAttach = SUCCEEDED(pUnk->QueryInterface(IID_IDispatch, (void **) &m_pDisp));

			Sleep(1000);
		}

		if (ableToAttach) {
			m_application.AttachDispatch(m_pDisp, TRUE);
			m_namespace = NameSpace(m_application.GetNamespace(_T("MAPI")));
			COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
			m_namespace.Logon(covOptional, covOptional, dontShowDialog, covOptional);
			m_isInitialized = true;
		}
	}
}