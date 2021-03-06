﻿// Copyright (C) 2012 Angel Hernández Matos / Bonafide Ideas.
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

// File generated by Wsutil Compiler version 1.0092 
// This file defines C/C++ functions, callbacks, types that correspond to operations,
// and types specified in WSDL and XSD files processed by WsUtil compiler. The generated 
// type definitions, function and callback declarations can be used with various 
// Web Services APIs either in applications that send and receive requests to and 
// from a running web service, or in the implementation of web services, or in both. 
//
// If Wsutil has generated this file from an XSD file, the file contains definition of 
// C/C++ structures types that correspond to types defined in the XSD file. 
// For example, if the following XSD complexType is defined in the XSD file
//
//      <xsd:complexType name="AddRequest">
//          <xsd:sequence>
//              <xsd:element minOccurs="0" name="a" type="xsd:int" />
//              <xsd:element minOccurs="0" name="b" type="xsd:int" />
//          </xsd:sequence>
//      </xsd:complexType>
// 
// this file contains the following definitions of the structure 
//      // AddRequest (xsd:complexType)
//      // <AddRequest xmlns='http://tempuri.org'>
//      // WS_STRUCT_DESCRIPTION* = &calculator_xsd.globalTypes.AddRequest
//      struct AddRequest
//      {
//          int a;
//          int b;
//      };
//
// For more information on how to use the C/C++ types generated in this file to read or write elements of XML documents that conform to 
// this XSD, please see the documentation for 
// WsReadType() and WsWriteType() functions.
// 
#if _MSC_VER > 1000 
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

// The following types were generated:

//     struct _AddRequest;
//     struct _AddRequestResponse;
//     struct _RemoveRequest;
//     struct _RemoveRequestResponse;

// The following header files must be included in this order before this one

// #include <WebServices.h>
// #include "cybernanny2.xsd.h"
// #include "cybernanny3.xsd.h"

////////////////////////////////////////////////
// C structure definitions for generated types
////////////////////////////////////////////////

// typeDescription: n/a
typedef struct _AddRequest 
{
    enum Common_RequestType type;
    int userIdentifier;
} _AddRequest;

// typeDescription: n/a
typedef struct _AddRequestResponse 
{
    WS_STRING AddRequestResult; // optional
} _AddRequestResponse;

// typeDescription: n/a
typedef struct _RemoveRequest 
{
    int userIdentifier;
    BOOL removeAll;
} _RemoveRequest;

// typeDescription: n/a
typedef struct _RemoveRequestResponse 
{
    BOOL RemoveRequestResult;
    struct StringBuilder* message; // optional
} _RemoveRequestResponse;

////////////////////////////////////////////////
// Global web service descriptions.
////////////////////////////////////////////////

typedef struct _cybernanny0_xsd
{
    struct // globalElements
    {
        // xml element: AddRequest ("http://tempuri.org/")
        // c type: _AddRequest
        // elementDescription: cybernanny0_xsd.globalElements.AddRequest
        WS_ELEMENT_DESCRIPTION AddRequest;
        
        // xml element: AddRequestResponse ("http://tempuri.org/")
        // c type: _AddRequestResponse
        // elementDescription: cybernanny0_xsd.globalElements.AddRequestResponse
        WS_ELEMENT_DESCRIPTION AddRequestResponse;
        
        // xml element: RemoveRequest ("http://tempuri.org/")
        // c type: _RemoveRequest
        // elementDescription: cybernanny0_xsd.globalElements.RemoveRequest
        WS_ELEMENT_DESCRIPTION RemoveRequest;
        
        // xml element: RemoveRequestResponse ("http://tempuri.org/")
        // c type: _RemoveRequestResponse
        // elementDescription: cybernanny0_xsd.globalElements.RemoveRequestResponse
        WS_ELEMENT_DESCRIPTION RemoveRequestResponse;
        
    } globalElements;
    struct // externallyReferencedTypes
    {
        WS_STRUCT_DESCRIPTION AddRequest;
        WS_STRUCT_DESCRIPTION AddRequestResponse;
        WS_STRUCT_DESCRIPTION RemoveRequest;
        WS_STRUCT_DESCRIPTION RemoveRequestResponse;
    } externallyReferencedTypes;
} _cybernanny0_xsd;

extern const _cybernanny0_xsd cybernanny0_xsd;

#ifdef __cplusplus
}
#endif

