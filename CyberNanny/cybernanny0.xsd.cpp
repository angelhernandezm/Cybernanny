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
#include "stdafx.h"
#include <WebServices.h>
#include "cybernanny2.xsd.h"
#include "cybernanny3.xsd.h"
#include "cybernanny0.xsd.h"

typedef struct _cybernanny0_xsdLocalDefinitions 
{
    struct  // global elements
    {
    char unused;
        struct // _AddRequest
        {
            WS_FIELD_DESCRIPTION type;
            WS_FIELD_DESCRIPTION userIdentifier;
            WS_FIELD_DESCRIPTION* _AddRequestFields [2]; 
        } _AddRequestdescs; // end of _AddRequest
        struct // _AddRequestResponse
        {
            WS_FIELD_DESCRIPTION AddRequestResult;
            WS_FIELD_DESCRIPTION* _AddRequestResponseFields [1]; 
        } _AddRequestResponsedescs; // end of _AddRequestResponse
        struct // _RemoveRequest
        {
            WS_FIELD_DESCRIPTION userIdentifier;
            WS_FIELD_DESCRIPTION removeAll;
            WS_FIELD_DESCRIPTION* _RemoveRequestFields [2]; 
        } _RemoveRequestdescs; // end of _RemoveRequest
        struct // _RemoveRequestResponse
        {
            WS_FIELD_DESCRIPTION RemoveRequestResult;
            WS_FIELD_DESCRIPTION message;
            WS_FIELD_DESCRIPTION* _RemoveRequestResponseFields [2]; 
        } _RemoveRequestResponsedescs; // end of _RemoveRequestResponse
    } globalElements;  // end of global elements
    struct // XML dictionary
    {
        struct // XML string list
        {
            WS_XML_STRING _AddRequestTypeName;  // AddRequest
            WS_XML_STRING _AddRequestTypeNamespace;  // http://tempuri.org/
            WS_XML_STRING _AddRequesttypeLocalName;  // type
            WS_XML_STRING _AddRequestuserIdentifierLocalName;  // userIdentifier
            WS_XML_STRING _AddRequestResponseTypeName;  // AddRequestResponse
            WS_XML_STRING _AddRequestResponseAddRequestResultLocalName;  // AddRequestResult
            WS_XML_STRING _RemoveRequestTypeName;  // RemoveRequest
            WS_XML_STRING _RemoveRequestremoveAllLocalName;  // removeAll
            WS_XML_STRING _RemoveRequestResponseTypeName;  // RemoveRequestResponse
            WS_XML_STRING _RemoveRequestResponseRemoveRequestResultLocalName;  // RemoveRequestResult
            WS_XML_STRING _RemoveRequestResponsemessageLocalName;  // message
        } xmlStrings; // end of XML string list
        WS_XML_DICTIONARY dict;  
    } dictionary;  // end of XML dictionary
} _cybernanny0_xsdLocalDefinitions;

const static _cybernanny0_xsdLocalDefinitions cybernanny0_xsdLocalDefinitions =
{
    {  // global elements
        0,
        {   // _AddRequest
            { // field description for type
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequesttypeLocalName, // type
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_ENUM_TYPE,
            (WS_ENUM_DESCRIPTION*)&cybernanny2_xsd.globalTypes.Common_RequestType,
            WsOffsetOf(_AddRequest, type),
             WS_FIELD_OPTIONAL,
            0,
            0xffffffff
            },    // end of field description for type
            { // field description for userIdentifier
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestuserIdentifierLocalName, // userIdentifier
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_INT32_TYPE,
            0,
            WsOffsetOf(_AddRequest, userIdentifier),
             WS_FIELD_OPTIONAL,
            0,
            0xffffffff
            },    // end of field description for userIdentifier
            {    // fields description for _AddRequest
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._AddRequestdescs.type,
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._AddRequestdescs.userIdentifier,
            },
        },    // _AddRequest
        {   // _AddRequestResponse
            { // field description for AddRequestResult
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestResponseAddRequestResultLocalName, // AddRequestResult
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_STRING_TYPE,
            0,
            WsOffsetOf(_AddRequestResponse, AddRequestResult),
             WS_FIELD_OPTIONAL| WS_FIELD_NILLABLE,
            0,
            0xffffffff
            },    // end of field description for AddRequestResult
            {    // fields description for _AddRequestResponse
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._AddRequestResponsedescs.AddRequestResult,
            },
        },    // _AddRequestResponse
        {   // _RemoveRequest
            { // field description for userIdentifier
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestuserIdentifierLocalName, // userIdentifier
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_INT32_TYPE,
            0,
            WsOffsetOf(_RemoveRequest, userIdentifier),
             WS_FIELD_OPTIONAL,
            0,
            0xffffffff
            },    // end of field description for userIdentifier
            { // field description for removeAll
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestremoveAllLocalName, // removeAll
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_BOOL_TYPE,
            0,
            WsOffsetOf(_RemoveRequest, removeAll),
             WS_FIELD_OPTIONAL,
            0,
            0xffffffff
            },    // end of field description for removeAll
            {    // fields description for _RemoveRequest
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestdescs.userIdentifier,
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestdescs.removeAll,
            },
        },    // _RemoveRequest
        {   // _RemoveRequestResponse
            { // field description for RemoveRequestResult
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestResponseRemoveRequestResultLocalName, // RemoveRequestResult
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_BOOL_TYPE,
            0,
            WsOffsetOf(_RemoveRequestResponse, RemoveRequestResult),
             WS_FIELD_OPTIONAL,
            0,
            0xffffffff
            },    // end of field description for RemoveRequestResult
            { // field description for message
            WS_ELEMENT_FIELD_MAPPING,
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestResponsemessageLocalName, // message
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_STRUCT_TYPE,
            (void*)&cybernanny3_xsd.globalTypes.StringBuilder,
            WsOffsetOf(_RemoveRequestResponse, message),
            WS_FIELD_POINTER| WS_FIELD_OPTIONAL| WS_FIELD_NILLABLE,
            0,
            0xffffffff
            },    // end of field description for message
            {    // fields description for _RemoveRequestResponse
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestResponsedescs.RemoveRequestResult,
            (WS_FIELD_DESCRIPTION*)&cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestResponsedescs.message,
            },
        },    // _RemoveRequestResponse
    }, // end of global elements
    {    // dictionary 
        { // xmlStrings
            WS_XML_STRING_DICTIONARY_VALUE("AddRequest",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 0),
            WS_XML_STRING_DICTIONARY_VALUE("http://tempuri.org/",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 1),
            WS_XML_STRING_DICTIONARY_VALUE("type",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 2),
            WS_XML_STRING_DICTIONARY_VALUE("userIdentifier",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 3),
            WS_XML_STRING_DICTIONARY_VALUE("AddRequestResponse",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 4),
            WS_XML_STRING_DICTIONARY_VALUE("AddRequestResult",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 5),
            WS_XML_STRING_DICTIONARY_VALUE("RemoveRequest",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 6),
            WS_XML_STRING_DICTIONARY_VALUE("removeAll",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 7),
            WS_XML_STRING_DICTIONARY_VALUE("RemoveRequestResponse",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 8),
            WS_XML_STRING_DICTIONARY_VALUE("RemoveRequestResult",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 9),
            WS_XML_STRING_DICTIONARY_VALUE("message",&cybernanny0_xsdLocalDefinitions.dictionary.dict, 10),
        },  // end of xmlStrings
        
        {   // cybernanny0_xsddictionary
        // 579b65b4-a1e0-43d4-98e1-8d48f4e235fd 
        { 0x579b65b4, 0xa1e0, 0x43d4, { 0x98, 0xe1, 0x8d,0x48, 0xf4, 0xe2, 0x35, 0xfd } },
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings,
        11,
        TRUE,
        },
    },   //  end of dictionary
}; //  end of cybernanny0_xsdLocalDefinitions

const _cybernanny0_xsd cybernanny0_xsd =
{
    {// globalElements
        {
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeName, // AddRequest
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_STRUCT_TYPE,
            (void*)&cybernanny0_xsd.externallyReferencedTypes.AddRequest,
        },
        {
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestResponseTypeName, // AddRequestResponse
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_STRUCT_TYPE,
            (void*)&cybernanny0_xsd.externallyReferencedTypes.AddRequestResponse,
        },
        {
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestTypeName, // RemoveRequest
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_STRUCT_TYPE,
            (void*)&cybernanny0_xsd.externallyReferencedTypes.RemoveRequest,
        },
        {
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestResponseTypeName, // RemoveRequestResponse
            (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
            WS_STRUCT_TYPE,
            (void*)&cybernanny0_xsd.externallyReferencedTypes.RemoveRequestResponse,
        },
    }, // globalElements
    {  // begin of externallyReferencedTypes
        {
        sizeof(_AddRequest),
        __alignof(_AddRequest),
        (WS_FIELD_DESCRIPTION**)&cybernanny0_xsdLocalDefinitions.globalElements._AddRequestdescs._AddRequestFields,
        WsCountOf(cybernanny0_xsdLocalDefinitions.globalElements._AddRequestdescs._AddRequestFields),
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeName, // AddRequest
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
        0,
        0,
        0,
        },   // end of struct description for _AddRequest
        {
        sizeof(_AddRequestResponse),
        __alignof(_AddRequestResponse),
        (WS_FIELD_DESCRIPTION**)&cybernanny0_xsdLocalDefinitions.globalElements._AddRequestResponsedescs._AddRequestResponseFields,
        WsCountOf(cybernanny0_xsdLocalDefinitions.globalElements._AddRequestResponsedescs._AddRequestResponseFields),
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestResponseTypeName, // AddRequestResponse
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
        0,
        0,
        0,
        },   // end of struct description for _AddRequestResponse
        {
        sizeof(_RemoveRequest),
        __alignof(_RemoveRequest),
        (WS_FIELD_DESCRIPTION**)&cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestdescs._RemoveRequestFields,
        WsCountOf(cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestdescs._RemoveRequestFields),
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestTypeName, // RemoveRequest
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
        0,
        0,
        0,
        },   // end of struct description for _RemoveRequest
        {
        sizeof(_RemoveRequestResponse),
        __alignof(_RemoveRequestResponse),
        (WS_FIELD_DESCRIPTION**)&cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestResponsedescs._RemoveRequestResponseFields,
        WsCountOf(cybernanny0_xsdLocalDefinitions.globalElements._RemoveRequestResponsedescs._RemoveRequestResponseFields),
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._RemoveRequestResponseTypeName, // RemoveRequestResponse
        (WS_XML_STRING*)&cybernanny0_xsdLocalDefinitions.dictionary.xmlStrings._AddRequestTypeNamespace, // http://tempuri.org/
        0,
        0,
        0,
        },   // end of struct description for _RemoveRequestResponse
    }, // end of externallyReferencedTypes;
}; // end of _cybernanny0_xsd