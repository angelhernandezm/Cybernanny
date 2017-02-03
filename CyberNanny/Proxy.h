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

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
#include <WebServices.h>
#include "cybernanny0.xsd.h"
#include "cybernanny2.xsd.h"
#include "cybernannySvc.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Proxy. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Proxy {
private:
	/// <summary>	Size of the heap. </summary>
	int m_heapSize;
	/// <summary>	The heap. </summary>
	WS_HEAP* m_heap;
	/// <summary>	The error. </summary>
	WS_ERROR* m_error;
	/// <summary>	true if this object is initialized. </summary>
	bool m_isInitialized;
	/// <summary>	The proxy. </summary>
	WS_SERVICE_PROXY* m_proxy;
	/// <summary>	The channel properties. </summary>
	WS_CHANNEL_PROPERTY m_channelProps[2];
	/// <summary>	Name of the host. </summary>
	std::wstring m_serviceUrl, m_hostName;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Proxy();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~Proxy();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Closes the proxy. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void CloseProxy();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Initialize();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the heap get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	null if it fails, else. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	WS_HEAP* Heap_get();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the error get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	null if it fails, else. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	WS_ERROR* Error_get();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Query if this object is initialized get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	true if initialized get, false if not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool IsInitialized_get();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the proxy get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	null if it fails, else. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	WS_SERVICE_PROXY* Proxy_get();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets an up. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="serviceUrl">	URL of the service. </param>
	/// <param name="hostName">  	Name of the host. </param>
	/// <param name="heapSize">  	Size of the heap. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetUp(std::wstring serviceUrl, std::wstring hostName, int heapSize);
};