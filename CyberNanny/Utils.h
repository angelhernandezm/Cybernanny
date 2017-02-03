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

#pragma once

#include "resource.h"
#include "cybernannySvc.h"
#include "Proxy.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Logs an event. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="f">	  	[in,out] The logger&amp;&amp; to process. </param>
/// <param name="message">	The message. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class logger>
void LogEvent(logger&& f, CString message) {
	EventLogHelper::LogMessage(std::wstring(message.GetString()));
	f();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Logs an event with return. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="f">	  	[in,out] The logger&amp;&amp; to process. </param>
/// <param name="message">	The message. </param>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

template<class logger>
bool LogEventWithReturn(logger&& f, CString message) {
	EventLogHelper::LogMessage(std::wstring(message.GetString()));

	return f();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Defines an alias representing the request. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct _request {
	_request() {
		IsEmpty = true;
	}

	bool IsEmpty;
	std::wstring Action;
	std::wstring DateTime;
	std::wstring MessageId;
	std::wstring Requestor;
	std::wstring EmailRecipient;
} MessageRequest;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Event log helper. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class EventLogHelper {

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Writes an event. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="eventInformation">	[in,out] If non-null, information describing the event. </param>
	/// <param name="isString">		   	true if this object is string. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void WriteEvent(void* eventInformation, bool isString);

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Logs a request. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="request">	The request. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void LogRequest(_request request);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Logs a message. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="message">	The message. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void LogMessage(std::wstring message);

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Utilities. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Utils {
private:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Format xml string. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="strToUse">	[in,out] to use. </param>
	///
	/// <returns>	The formatted xml string. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	std::string FormatXmlString(std::string& strToUse);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Parse request. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="request">	[in,out] The request. </param>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	MessageRequest ParseRequest(std::string& request);
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Utils();

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

	MessageRequest RemoveRequest(int userIdentifier, bool removeAll); 
};