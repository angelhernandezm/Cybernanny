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
// MailItem wrapper class

class MailItem : public COleDispatchDriver
{
public:
	MailItem(){} // Calls COleDispatchDriver default constructor
	MailItem(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	MailItem(const MailItem& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// _MailItem methods
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
	LPDISPATCH get_Actions()
	{
		LPDISPATCH result;
		InvokeHelper(0xf817, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Attachments()
	{
		LPDISPATCH result;
		InvokeHelper(0xf815, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_BillingInformation()
	{
		CString result;
		InvokeHelper(0x8535, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_BillingInformation(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8535, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Body()
	{
		CString result;
		InvokeHelper(0x9100, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Body(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x9100, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Categories()
	{
		CString result;
		InvokeHelper(0x9001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Categories(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x9001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Companies()
	{
		CString result;
		InvokeHelper(0x853b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Companies(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x853b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ConversationIndex()
	{
		CString result;
		InvokeHelper(0xfac0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ConversationTopic()
	{
		CString result;
		InvokeHelper(0x70, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	DATE get_CreationTime()
	{
		DATE result;
		InvokeHelper(0x3007, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	CString get_EntryID()
	{
		CString result;
		InvokeHelper(0xf01e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_FormDescription()
	{
		LPDISPATCH result;
		InvokeHelper(0xf095, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_GetInspector()
	{
		LPDISPATCH result;
		InvokeHelper(0xf03e, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Importance()
	{
		long result;
		InvokeHelper(0x17, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Importance(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x17, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_LastModificationTime()
	{
		DATE result;
		InvokeHelper(0x3008, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	LPUNKNOWN get_MAPIOBJECT()
	{
		LPUNKNOWN result;
		InvokeHelper(0xf100, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}
	CString get_MessageClass()
	{
		CString result;
		InvokeHelper(0x1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_MessageClass(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_Mileage()
	{
		CString result;
		InvokeHelper(0x8534, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Mileage(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8534, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_NoAging()
	{
		BOOL result;
		InvokeHelper(0x850e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_NoAging(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x850e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_OutlookInternalVersion()
	{
		long result;
		InvokeHelper(0x8552, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_OutlookVersion()
	{
		CString result;
		InvokeHelper(0x8554, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_Saved()
	{
		BOOL result;
		InvokeHelper(0xf0a3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long get_Sensitivity()
	{
		long result;
		InvokeHelper(0x36, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Sensitivity(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x36, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Size()
	{
		long result;
		InvokeHelper(0xe08, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString get_Subject()
	{
		CString result;
		InvokeHelper(0x37, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_Subject(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x37, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_UnRead()
	{
		BOOL result;
		InvokeHelper(0xf01c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_UnRead(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xf01c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_UserProperties()
	{
		LPDISPATCH result;
		InvokeHelper(0xf816, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Close(long SaveMode)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xf023, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SaveMode);
	}
	LPDISPATCH Copy()
	{
		LPDISPATCH result;
		InvokeHelper(0xf032, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Delete()
	{
		InvokeHelper(0xf04a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Display(VARIANT& Modal)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xf0a6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Modal);
	}
	LPDISPATCH Move(LPDISPATCH DestFldr)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xf034, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, DestFldr);
		return result;
	}
	void PrintOut()
	{
		InvokeHelper(0xf033, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void Save()
	{
		InvokeHelper(0xf048, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void SaveAs(LPCTSTR Path, VARIANT& Type)
	{
		static BYTE parms[] = VTS_BSTR VTS_VARIANT ;
		InvokeHelper(0xf051, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Path, &Type);
	}
	BOOL get_AlternateRecipientAllowed()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AlternateRecipientAllowed(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_AutoForwarded()
	{
		BOOL result;
		InvokeHelper(0x5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_AutoForwarded(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_BCC()
	{
		CString result;
		InvokeHelper(0xe02, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_BCC(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xe02, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_CC()
	{
		CString result;
		InvokeHelper(0xe03, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_CC(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xe03, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_DeferredDeliveryTime()
	{
		DATE result;
		InvokeHelper(0xf, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_DeferredDeliveryTime(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0xf, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_DeleteAfterSubmit()
	{
		BOOL result;
		InvokeHelper(0xe01, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_DeleteAfterSubmit(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xe01, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_ExpiryTime()
	{
		DATE result;
		InvokeHelper(0x15, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_ExpiryTime(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x15, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_FlagDueBy()
	{
		DATE result;
		InvokeHelper(0x30, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_FlagDueBy(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x30, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_FlagRequest()
	{
		CString result;
		InvokeHelper(0x8530, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_FlagRequest(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8530, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FlagStatus()
	{
		long result;
		InvokeHelper(0x1090, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FlagStatus(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x1090, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_HTMLBody()
	{
		CString result;
		InvokeHelper(0xf404, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_HTMLBody(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xf404, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_OriginatorDeliveryReportRequested()
	{
		BOOL result;
		InvokeHelper(0x23, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_OriginatorDeliveryReportRequested(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x23, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_ReadReceiptRequested()
	{
		BOOL result;
		InvokeHelper(0x29, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ReadReceiptRequested(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x29, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ReceivedByEntryID()
	{
		CString result;
		InvokeHelper(0x3f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ReceivedByName()
	{
		CString result;
		InvokeHelper(0x40, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ReceivedOnBehalfOfEntryID()
	{
		CString result;
		InvokeHelper(0x43, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_ReceivedOnBehalfOfName()
	{
		CString result;
		InvokeHelper(0x44, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	DATE get_ReceivedTime()
	{
		DATE result;
		InvokeHelper(0xe06, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	BOOL get_RecipientReassignmentProhibited()
	{
		BOOL result;
		InvokeHelper(0x2b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_RecipientReassignmentProhibited(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x2b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_Recipients()
	{
		LPDISPATCH result;
		InvokeHelper(0xf814, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	BOOL get_ReminderOverrideDefault()
	{
		BOOL result;
		InvokeHelper(0x851c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ReminderOverrideDefault(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x851c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_ReminderPlaySound()
	{
		BOOL result;
		InvokeHelper(0x851e, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ReminderPlaySound(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x851e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_ReminderSet()
	{
		BOOL result;
		InvokeHelper(0x8503, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_ReminderSet(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8503, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ReminderSoundFile()
	{
		CString result;
		InvokeHelper(0x851f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_ReminderSoundFile(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x851f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_ReminderTime()
	{
		DATE result;
		InvokeHelper(0x8502, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_ReminderTime(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x8502, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_RemoteStatus()
	{
		long result;
		InvokeHelper(0x8511, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_RemoteStatus(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8511, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_ReplyRecipientNames()
	{
		CString result;
		InvokeHelper(0x50, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_ReplyRecipients()
	{
		LPDISPATCH result;
		InvokeHelper(0xf013, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_SaveSentMessageFolder()
	{
		LPDISPATCH result;
		InvokeHelper(0xf401, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void putref_SaveSentMessageFolder(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xf401, DISPATCH_PROPERTYPUTREF, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_SenderName()
	{
		CString result;
		InvokeHelper(0xc1a, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_Sent()
	{
		BOOL result;
		InvokeHelper(0xf402, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	DATE get_SentOn()
	{
		DATE result;
		InvokeHelper(0x39, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	CString get_SentOnBehalfOfName()
	{
		CString result;
		InvokeHelper(0x42, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_SentOnBehalfOfName(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x42, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_Submitted()
	{
		BOOL result;
		InvokeHelper(0xf403, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	CString get_To()
	{
		CString result;
		InvokeHelper(0xe04, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_To(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xe04, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_VotingOptions()
	{
		CString result;
		InvokeHelper(0xf01b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_VotingOptions(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xf01b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_VotingResponse()
	{
		CString result;
		InvokeHelper(0x8524, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_VotingResponse(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8524, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ClearConversationIndex()
	{
		InvokeHelper(0xf822, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH Forward()
	{
		LPDISPATCH result;
		InvokeHelper(0xf813, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH Reply()
	{
		LPDISPATCH result;
		InvokeHelper(0xf810, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH ReplyAll()
	{
		LPDISPATCH result;
		InvokeHelper(0xf811, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Send()
	{
		InvokeHelper(0xf075, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_Links()
	{
		LPDISPATCH result;
		InvokeHelper(0xf405, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_ItemProperties()
	{
		LPDISPATCH result;
		InvokeHelper(0xfa09, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_BodyFormat()
	{
		long result;
		InvokeHelper(0xfa49, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_BodyFormat(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xfa49, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_DownloadState()
	{
		long result;
		InvokeHelper(0xfa4d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void ShowCategoriesDialog()
	{
		InvokeHelper(0xfa0b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_InternetCodepage()
	{
		long result;
		InvokeHelper(0x3fde, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_InternetCodepage(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3fde, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_MarkForDownload()
	{
		long result;
		InvokeHelper(0x8571, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_MarkForDownload(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8571, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IsConflict()
	{
		BOOL result;
		InvokeHelper(0xfaa4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL get_IsIPFax()
	{
		BOOL result;
		InvokeHelper(0x859b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IsIPFax(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x859b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_FlagIcon()
	{
		long result;
		InvokeHelper(0xfacc, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_FlagIcon(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xfacc, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_HasCoverSheet()
	{
		BOOL result;
		InvokeHelper(0xfab0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_HasCoverSheet(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xfab0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_AutoResolvedWinner()
	{
		BOOL result;
		InvokeHelper(0xfaba, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Conflicts()
	{
		LPDISPATCH result;
		InvokeHelper(0xfabb, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_SenderEmailAddress()
	{
		CString result;
		InvokeHelper(0xc1f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_SenderEmailType()
	{
		CString result;
		InvokeHelper(0xc1e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	BOOL get_EnableSharedAttachments()
	{
		BOOL result;
		InvokeHelper(0xfac4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_EnableSharedAttachments(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0xfac4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Permission()
	{
		long result;
		InvokeHelper(0xfac6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Permission(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xfac6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_PermissionService()
	{
		long result;
		InvokeHelper(0xfacb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_PermissionService(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xfacb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	LPDISPATCH get_PropertyAccessor()
	{
		LPDISPATCH result;
		InvokeHelper(0xfafd, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void AddBusinessCard(LPDISPATCH contact)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xfb96, DISPATCH_METHOD, VT_EMPTY, NULL, parms, contact);
	}
	LPDISPATCH get_SendUsingAccount()
	{
		LPDISPATCH result;
		InvokeHelper(0xfad1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_SendUsingAccount(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xfad1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_TaskSubject()
	{
		CString result;
		InvokeHelper(0xfc1f, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_TaskSubject(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfc1f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_TaskDueDate()
	{
		DATE result;
		InvokeHelper(0x8105, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_TaskDueDate(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x8105, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_TaskStartDate()
	{
		DATE result;
		InvokeHelper(0x8104, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_TaskStartDate(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x8104, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_TaskCompletedDate()
	{
		DATE result;
		InvokeHelper(0x810f, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_TaskCompletedDate(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x810f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	DATE get_ToDoTaskOrdinal()
	{
		DATE result;
		InvokeHelper(0x85a0, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}
	void put_ToDoTaskOrdinal(DATE newValue)
	{
		static BYTE parms[] = VTS_DATE ;
		InvokeHelper(0x85a0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void MarkAsTask(long MarkInterval)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xfbfe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, MarkInterval);
	}
	void ClearTaskFlag()
	{
		InvokeHelper(0xfc09, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_IsMarkedAsTask()
	{
		BOOL result;
		InvokeHelper(0xfc0a, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH GetConversation()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc54, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_ConversationID()
	{
		CString result;
		InvokeHelper(0xfc75, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Sender()
	{
		LPDISPATCH result;
		InvokeHelper(0xfc7b, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void put_Sender(LPDISPATCH newValue)
	{
		static BYTE parms[] = VTS_DISPATCH ;
		InvokeHelper(0xfc7b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_PermissionTemplateGuid()
	{
		CString result;
		InvokeHelper(0xfc7d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_PermissionTemplateGuid(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0xfc7d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_RTFBody()
	{
		VARIANT result;
		InvokeHelper(0xfc84, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_RTFBody(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xfc84, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	CString get_RetentionPolicyName()
	{
		CString result;
		InvokeHelper(0xfc8b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	DATE get_RetentionExpirationDate()
	{
		DATE result;
		InvokeHelper(0xfc8a, DISPATCH_PROPERTYGET, VT_DATE, (void*)&result, NULL);
		return result;
	}

	// _MailItem properties
public:

};
