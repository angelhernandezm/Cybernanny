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

// App wrapper class

class App : public COleDispatchDriver
{
public:
	App(){} // Calls COleDispatchDriver default constructor
	App(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	App(const App& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _Application methods
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
	LPDISPATCH get_Assistant()
	{
		LPDISPATCH result;
		InvokeHelper(0x114, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_Name()
	{
		CString result;
		InvokeHelper(0x3001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_Version()
	{
		CString result;
		InvokeHelper(0x116, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH ActiveExplorer()
	{
		LPDISPATCH result;
		InvokeHelper(0x111, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH ActiveInspector()
	{
		LPDISPATCH result;
		InvokeHelper(0x112, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CreateItem(long ItemType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x10a, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ItemType);
		return result;
	}
	LPDISPATCH CreateItemFromTemplate(LPCTSTR TemplatePath, VARIANT& InFolder)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0x10b, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, TemplatePath, &InFolder);
		return result;
	}
	LPDISPATCH CreateObject(LPCTSTR ObjectName)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x115, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, ObjectName);
		return result;
	}
	LPDISPATCH GetNamespace(LPCTSTR Type)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x110, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Type);
		return result;
	}
	void Quit()
	{
		InvokeHelper(0x113, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_COMAddIns()
	{
		LPDISPATCH result;
		InvokeHelper(0x118, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Explorers()
	{
		LPDISPATCH result;
		InvokeHelper(0x119, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Inspectors()
	{
		LPDISPATCH result;
		InvokeHelper(0x11a, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_LanguageSettings()
	{
		LPDISPATCH result;
		InvokeHelper(0x11b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_ProductCode()
	{
		CString result;
		InvokeHelper(0x11c, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_AnswerWizard()
	{
		LPDISPATCH result;
		InvokeHelper(0x11d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_FeatureInstall()
	{
		long result;
		InvokeHelper(0x11e, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FeatureInstall(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x11e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH ActiveWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x11f, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH CopyFile(LPCTSTR FilePath, LPCTSTR DestFolderPath)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_BSTR ;
		InvokeHelper(0xfa62, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, FilePath, DestFolderPath);
		return result;
	}
	LPDISPATCH AdvancedSearch(LPCTSTR Scope, VARIANT& Filter, VARIANT& SearchSubFolders, VARIANT& Tag)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xfa65, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Scope, &Filter, &SearchSubFolders, &Tag);
		return result;
	}
	BOOL IsSearchSynchronous(LPCTSTR LookInFolders)
	{
		BOOL result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfa6c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, LookInFolders);
		return result;
	}
	void GetNewNickNames(VARIANT * pvar)
	{
		static BYTE parms[] = VTS_PVARIANT ;
		InvokeHelper(0xfa48, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pvar);
	}
	LPDISPATCH get_Reminders()
	{
		LPDISPATCH result;
		InvokeHelper(0xfa99, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_DefaultProfileName()
	{
		CString result;
		InvokeHelper(0xfad6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsTrusted()
	{
		BOOL result;
		InvokeHelper(0xfbf3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetObjectReference(LPDISPATCH Item, long ReferenceType)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH VTS_I4 ;
		InvokeHelper(0xfbd6, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Item, ReferenceType);
		return result;
	}
	LPDISPATCH get_Assistance()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc08, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_TimeZones()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc29, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_PickerDialog()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc65, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void RefreshFormRegionDefinition(LPCTSTR RegionName)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfc7f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, RegionName);
	}

	// _Application properties
public:

};
