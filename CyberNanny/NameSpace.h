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
// NameSpace wrapper class

class NameSpace : public COleDispatchDriver
{
public:
	NameSpace(){} // Calls COleDispatchDriver default constructor
	NameSpace(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	NameSpace(const NameSpace& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _NameSpace methods
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
	LPDISPATCH get_CurrentUser()
	{
		LPDISPATCH result;
		InvokeHelper(0x2101, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Folders()
	{
		LPDISPATCH result;
		InvokeHelper(0x2103, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_Type()
	{
		CString result;
		InvokeHelper(0x2104, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AddressLists()
	{
		LPDISPATCH result;
		InvokeHelper(0x210d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreateRecipient(LPCTSTR RecipientName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x210a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, RecipientName);
		return result;
	}
	LPDISPATCH GetDefaultFolder(long FolderType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x210b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FolderType);
		return result;
	}
	LPDISPATCH GetFolderFromID(LPCTSTR EntryIDFolder, VARIANT& EntryIDStore)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x2108, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, EntryIDFolder, &EntryIDStore);
		return result;
	}
	LPDISPATCH GetItemFromID(LPCTSTR EntryIDItem, VARIANT& EntryIDStore)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x2109, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, EntryIDItem, &EntryIDStore);
		return result;
	}
	LPDISPATCH GetRecipientFromID(LPCTSTR EntryID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2107, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, EntryID);
		return result;
	}
	LPDISPATCH GetSharedDefaultFolder(LPDISPATCH Recipient, long FolderType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0x210c, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Recipient, FolderType);
		return result;
	}
	void Logoff()
	{
		InvokeHelper(0x2106, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Logon(VARIANT& Profile, VARIANT& Password, VARIANT& ShowDialog, VARIANT& NewSession)
	{
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x2105, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Profile, &Password, &ShowDialog, &NewSession);
	}
	LPDISPATCH PickFolder()
	{
		LPDISPATCH result;
		InvokeHelper(0x210e, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void RefreshRemoteHeaders()
	{
		InvokeHelper(0x2117, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_SyncObjects()
	{
		LPDISPATCH result;
		InvokeHelper(0x2118, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void AddStore(VARIANT& Store)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x2119, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Store);
	}
	void RemoveStore(LPDISPATCH Folder)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0x211a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Folder);
	}
	BOOL get_Offline()
	{
		BOOL result;
		InvokeHelper(0xfa4c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void Dial(VARIANT& ContactItem)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfa0d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &ContactItem);
	}
	LPUNKNOWN get_MAPIOBJECT()
	{
		LPUNKNOWN result;
		InvokeHelper(0xf100, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	long get_ExchangeConnectionMode()
	{
		long result;
		InvokeHelper(0xfac1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void AddStoreEx(VARIANT& Store, long Type)
	{
		static BYTE parms[] = VTS_VARIANT VTS_I4 ;
		InvokeHelper(0xfac5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Store, Type);
	}
	LPDISPATCH get_Accounts()
	{
		LPDISPATCH result;
		InvokeHelper(0xfad0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_CurrentProfileName()
	{
		CString result;
		InvokeHelper(0xfad5, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Stores()
	{
		LPDISPATCH result;
		InvokeHelper(0xfad8, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetSelectNamesDialog()
	{
		LPDISPATCH result;
		InvokeHelper(0xfae1, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void SendAndReceive(BOOL showProgressDialog)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xfad7, DISPATCH_METHOD, VT_EMPTY, NULL, parms, showProgressDialog);
	}
	LPDISPATCH get_DefaultStore()
	{
		LPDISPATCH result;
		InvokeHelper(0xfaec, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetAddressEntryFromID(LPCTSTR ID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfb04, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ID);
		return result;
	}
	LPDISPATCH GetGlobalAddressList()
	{
		LPDISPATCH result;
		InvokeHelper(0xfb05, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetStoreFromID(LPCTSTR ID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfb06, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ID);
		return result;
	}
	LPDISPATCH get_Categories()
	{
		LPDISPATCH result;
		InvokeHelper(0xfba5, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH OpenSharedFolder(LPCTSTR Path, VARIANT& Name, VARIANT& DownloadAttachments, VARIANT& UseTTL)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xfbf6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Path, &Name, &DownloadAttachments, &UseTTL);
		return result;
	}
	LPDISPATCH OpenSharedItem(LPCTSTR Path)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfbf7, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Path);
		return result;
	}
	LPDISPATCH CreateSharingItem(VARIANT& Context, VARIANT& Provider)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xfbe4, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, &Context, &Provider);
		return result;
	}
	CString get_ExchangeMailboxServerName()
	{
		CString result;
		InvokeHelper(0xfc05, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ExchangeMailboxServerVersion()
	{
		CString result;
		InvokeHelper(0xfc04, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL CompareEntryIDs(LPCTSTR FirstEntryID, LPCTSTR SecondEntryID)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xfbfc, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, FirstEntryID, SecondEntryID);
		return result;
	}
	CString get_AutoDiscoverXml()
	{
		CString result;
		InvokeHelper(0xfc03, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long get_AutoDiscoverConnectionMode()
	{
		long result;
		InvokeHelper(0xfc2e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreateContactCard(LPDISPATCH AddressEntry)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xfc85, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, AddressEntry);
		return result;
	}

	// _NameSpace properties
public:

};
