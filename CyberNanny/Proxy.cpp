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
#include "Proxy.h"
#include <WebServices.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes this object. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Proxy::Initialize() {
	auto retval = false;
	auto propCount = 0;
	vector<void*> propertyValue;
	vector<WS_CHANNEL_PROPERTY_ID> properties;
	WS_ENVELOPE_VERSION soapVersion = WS_ENVELOPE_VERSION_SOAP_1_1;
	WS_ADDRESSING_VERSION addressingVersion = WS_ADDRESSING_VERSION_TRANSPORT;
	WS_ENDPOINT_ADDRESS endpoint = WS_STRING_VALUE((WCHAR*)m_serviceUrl.c_str());
	endpoint.url.chars = ((WCHAR*) m_serviceUrl.c_str());
	endpoint.url.length = (ULONG) wcslen(endpoint.url.chars);

	if (m_isInitialized)
		return retval;

	properties.push_back(WS_CHANNEL_PROPERTY_ENVELOPE_VERSION);
	properties.push_back(WS_CHANNEL_PROPERTY_ADDRESSING_VERSION);
	propertyValue.push_back(&soapVersion);
	propertyValue.push_back(&addressingVersion);

	for (ULONG propertiesCount = 0; propertiesCount < properties.size(); propertiesCount++) {
		m_channelProps[propertiesCount].id = properties.at(propertiesCount);
		m_channelProps[propertiesCount].value = propertyValue.at(propertiesCount);
		m_channelProps[propertiesCount].valueSize =  (propertiesCount  == 0 ? sizeof(soapVersion) : sizeof(addressingVersion));
	}

	// Let's initialize our proxy
	if (SUCCEEDED(WsCreateError(NULL, NULL,  &m_error)) && SUCCEEDED(WsCreateHeap(m_heapSize, m_heapSize / 2, NULL, NULL, &m_heap, m_error))) {
		if  (SUCCEEDED(WsCreateServiceProxy(WS_CHANNEL_TYPE_REQUEST, WS_HTTP_CHANNEL_BINDING, NULL, NULL, NULL, 
			m_channelProps, properties.size(), &m_proxy, m_error))) {
				auto hr = WsOpenServiceProxy(m_proxy, &endpoint, NULL, m_error);
				retval = (SUCCEEDED(hr));
		}
	}

	m_isInitialized = true;

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Proxy::Proxy() {
	m_isInitialized = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets an up. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="serviceUrl">	URL of the service. </param>
/// <param name="hostName">  	Name of the host. </param>
/// <param name="heapSize">  	Size of the heap. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Proxy::SetUp(std::wstring serviceUrl, std::wstring hostName, int heapSize) {
	m_heapSize = heapSize;
	m_hostName = hostName;
	m_serviceUrl = serviceUrl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Proxy::~Proxy() {
	m_heap = NULL;
	m_proxy = NULL;
	m_error = NULL;

} 

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the proxy get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	null if it fails, else. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

WS_SERVICE_PROXY* Proxy::Proxy_get() {
	return m_proxy;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the heap get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	null if it fails, else. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

WS_HEAP* Proxy::Heap_get() {
	return m_heap;
} 

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the error get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	null if it fails, else. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

WS_ERROR* Proxy::Error_get() {
	return m_error;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Query if this object is initialized get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	true if initialized get, false if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Proxy::IsInitialized_get() {
	return m_isInitialized;
}