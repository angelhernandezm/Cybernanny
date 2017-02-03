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

// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "C:\\Program Files\\Microsoft Office\\Office14\\msoutl.olb" no_namespace rename("Folder", "OlkFolder") rename("CopyFile", "OlkCopyFile") rename("GetOrganizer", "GetOrganizerAE")
// Account wrapper class

class Account : public COleDispatchDriver
{
public:
	Account(){} // Calls COleDispatchDriver default constructor
	Account(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	Account(const Account& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _Account methods
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0xf000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Class()
	{
		long result;
		InvokeHelper(0xf00a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Session()
	{
		LPDISPATCH result;
		InvokeHelper(0xf00b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0xf001, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_AccountType()
	{
		long result;
		InvokeHelper(0xfad2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_DisplayName()
	{
		CString result;
		InvokeHelper(0x3001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_UserName()
	{
		CString result;
		InvokeHelper(0xfad3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_SmtpAddress()
	{
		CString result;
		InvokeHelper(0xfad4, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_AutoDiscoverConnectionMode()
	{
		long result;
		InvokeHelper(0xfc6f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_CurrentUser()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc6e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_AutoDiscoverXml()
	{
		CString result;
		InvokeHelper(0xfc70, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_DeliveryStore()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc66, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_ExchangeConnectionMode()
	{
		long result;
		InvokeHelper(0xfc67, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_ExchangeMailboxServerName()
	{
		CString result;
		InvokeHelper(0xfc68, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ExchangeMailboxServerVersion()
	{
		CString result;
		InvokeHelper(0xfc69, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetAddressEntryFromID(LPCTSTR ID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfc6a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ID);
		return result;
	}
	LPDISPATCH GetRecipientFromID(LPCTSTR EntryID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfc6b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, EntryID);
		return result;
	}

	// _Account properties
public:

};
