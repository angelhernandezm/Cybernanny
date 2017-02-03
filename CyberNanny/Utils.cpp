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
#include <strsafe.h>
#include "resource.h"
#include "Utils.h"
#include <memory.h>
#include "cybernannysvc.h"
#include <webservices.h>
#import "msxml6.dll"
#include <msxml6.h>
#include <typeinfo.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Logs a request. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="request">	The request. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EventLogHelper::LogRequest(_request request) {
	WriteEvent(&request, false);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Logs a message. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="message">	The message. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EventLogHelper::LogMessage(std::wstring message) {
	WriteEvent(&message, true);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Writes an event. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="eventInformation">	[in,out] If non-null, information describing the event. </param>
/// <param name="isString">		   	true if this object is string. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void EventLogHelper::WriteEvent(void* eventInformation, bool isString) {
	HANDLE hEventLog;
	auto delimiter = std::wstring(18, '*');
	auto application = delimiter + std::wstring(L"\n") +  std::wstring(L"* Cyber Nanny *") + std::wstring(L"\n") + 
					   delimiter + std::wstring(L"\n");

	if ((hEventLog = OpenEventLog(NULL, L"Application")) != NULL) {
		if (isString) {
			auto message = static_cast<std::wstring*>(eventInformation);
			LPWSTR myStrings[2] = {(WCHAR*) application.c_str(), (WCHAR*) message->c_str() };
			ReportEvent(hEventLog, EVENTLOG_INFORMATION_TYPE, 0x1, 0x2, NULL, 2, NULL, (LPCWSTR*)myStrings, NULL);
		} else {
			auto request = reinterpret_cast<_request*>(eventInformation);
			auto requestor =  std::wstring(_wtoi(request->Requestor.c_str()) == 99999999 ? L"Angel" : L"Mery");
 			auto firstLine = std::wstring(L"A request with ID \"").append(request->MessageId).append(L"\" was received ");
			auto secondLine = std::wstring(L"on ").append(request->DateTime).append(L". The request was made by ");
			auto thirdLine = std::wstring(request->Requestor).append(L" - ").append(requestor)
				.append(L". The operation requested was \"").append(request->Action).append(L"\".");
			LPWSTR myStrings[4] = {(WCHAR*) application.c_str(), (WCHAR*) firstLine.c_str(), (WCHAR*) secondLine.c_str(), (WCHAR*) thirdLine.c_str() };
			ReportEvent(hEventLog, EVENTLOG_INFORMATION_TYPE, 0x1, 0x1, NULL, 4, NULL, (LPCWSTR*)myStrings, NULL);
		}

		CloseEventLog(hEventLog);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Utils::Utils() {

}

 ////////////////////////////////////////////////////////////////////////////////////////////////////
 /// <summary>	Parse request. </summary>
 ///
 /// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
 ///
 /// <param name="request">	[in,out] The request. </param>
 ///
 /// <returns>	. </returns>
 ////////////////////////////////////////////////////////////////////////////////////////////////////

 MessageRequest Utils::ParseRequest(std::string& request) {
	BSTR nodeContent;
	WCHAR nodeText[50];
	MessageRequest retval;
	long childrenCount = 0;
	auto parsed = FormatXmlString(request);

	if (parsed.length() > 0) {
		IXMLDOMDocumentPtr docPtr;
		IXMLDOMNodeListPtr children;
		IXMLDOMNodePtr selectedNode, childNode;

		docPtr.CreateInstance("Msxml2.DOMDocument.6.0");
		if (SUCCEEDED(docPtr->loadXML(_bstr_t(parsed.c_str()), NULL))) {
			if ((SUCCEEDED(docPtr->selectSingleNode(_bstr_t("cyberNanny"), &selectedNode)))) {
				selectedNode->get_childNodes(&children);
				children->get_length(&childrenCount);

				for (auto nCount = 0; nCount < childrenCount; nCount++) {
					nodeContent = SysAllocString(nodeText);
					children->get_item(nCount, &childNode);
					childNode->get_text(&nodeContent);

					if (nCount == 0)
						retval.MessageId = (WCHAR*) nodeContent;
					else if (nCount == 1) 
						retval.DateTime = (WCHAR*) nodeContent;
					else if (nCount == 2) 
						retval.Requestor = (WCHAR*) nodeContent;
					else if (nCount == 3) 
						retval.Action = (WCHAR*) nodeContent;

					SysFreeString(nodeContent);
				}

				retval.EmailRecipient = _wtoi(retval.Requestor.c_str()) == 99999999 ? L"myaccount@hotmail.com" : L"mywifesaccount@hotmail.com";

				retval.IsEmpty = false;
			}
		}
	} 

	return retval;
 }

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Format xml string. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="strToUse">	[in,out] to use. </param>
///
/// <returns>	The formatted xml string. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Utils::FormatXmlString(std::string& strToUse) {
	auto retval = std::string();

	if (strToUse.length() > 0 && (strToUse.find("cyberNanny") != std::string::npos)) {
		strToUse = strToUse.substr(strToUse.find("&lt;"));
		auto endElement = strToUse.find("</m_StringValue>");
		strToUse = strToUse.substr(0, endElement);

		for (size_t pos = 0; pos <= strToUse.length(); ++pos) {
			auto current = strToUse.c_str()[pos];
			if (current != '&') {
				retval.append(1, current);
			} else {
				auto end = strToUse.find(";", pos);
				auto specialChar = strToUse.substr(pos, end - pos + 1);

				if (specialChar == "&lt;") {
					retval.append(1,'<');
				} else if (specialChar == "&gt;")  {
					retval.append(1, '>');
				} else if (specialChar == "&quot;") {
					retval.append(1, '"');
				} else if (specialChar == "&amp;") {
					retval.append(1, '&');
				} else if (specialChar == "&apos;") {
					retval.append(1, '\'');
				}

				pos += specialChar.length() - 1;
			}
		}
	}

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Removes the request. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="userIdentifier">	Identifier for the user. </param>
/// <param name="removeAll">	 	true to remove all. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

MessageRequest Utils::RemoveRequest(int userIdentifier, bool removeAll) { 
	std::string body;
	MessageRequest retval;
	const WS_XML_NODE* node;
	WS_XML_BUFFER *xmlBuffer;
	WS_XML_READER *xmlReader;
	auto found = FALSE, result = FALSE;
	Proxy proxy;
	proxy.SetUp(SERVICE_URL, HOST_URL, 4096);
	proxy.Initialize();

	if (proxy.IsInitialized_get()) {
		if (SUCCEEDED(WsCreateXmlBuffer(proxy.Heap_get(), NULL, 0,   &xmlBuffer, proxy.Error_get()))) {
			std::unique_ptr<StringBuilder> buffer(new StringBuilder);
			buffer->_any = xmlBuffer;
			auto tempPtr = buffer.get();
			auto heap = proxy.Heap_get();
			auto error = proxy.Error_get();
			auto proxyObj = proxy.Proxy_get();

			if (SUCCEEDED(BasicHttpBinding_ICyberNanny_RemoveRequest(proxyObj, userIdentifier,
				removeAll, &result, &tempPtr, heap, NULL, NULL, NULL, error))) {
					if (SUCCEEDED(WsCreateReader(NULL, NULL, &xmlReader, proxy.Error_get()))) {
						if ((SUCCEEDED(WsSetInputToBuffer(xmlReader, tempPtr->_any, NULL, 0, proxy.Error_get())))) {
							if ((SUCCEEDED(WsMoveReader(xmlReader, WS_MOVE_TO_ROOT_ELEMENT, &found, proxy.Error_get())))) {
								if (SUCCEEDED(WsGetReaderNode(xmlReader, &node, proxy.Error_get()))) {
									if (node->nodeType == WS_XML_NODE_TYPE_ELEMENT) {
										auto elementNode = (WS_XML_ELEMENT_NODE*) node;
										body = std::string((char*) elementNode->ns->bytes);
										CoInitialize(NULL);
										retval = ParseRequest(body);
										CoUninitialize();
									}
								}
							}
						}

						// If we don't release resources here we might leak memory because a copy of WS_ENDPOINT_ADDRESS
						// gets created when the web service is invoked. The original implementation did it in the destructor 
						// of the Proxy class.
						WsFreeReader(xmlReader);
						WsCloseServiceProxy(proxyObj, NULL, error);
						WsFreeServiceProxy(proxyObj);
						WsFreeHeap(heap);
						WsFreeError(error); 
					}
			}
		}
	}

	return retval;
}