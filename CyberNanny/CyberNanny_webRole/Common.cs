// Copyright (C) 2012 Angel Hernández Matos / Bonafide Ideas.
// You can redistribute this software and/or modify it under the terms of the 
// Microsoft Reciprocal License (Ms-RL).  This program is distributed in the hope 
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
// See License.txt for more details. 

/* Framework version: .NET Framework version 4.0
   C# compiler      : Microsoft (R) Visual C# 2010 Compiler version 4.0.30319.1
   Creation date    : 14/04/2012
   Developer        : Angel Hernández Matos
   e-m@il           : angel@bonafideideas.com 
		            : angeljesus14@hotmail.com
   Website          : http://www.bonafideideas.com
*/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace CyberNanny_webRole {
	public class Common {
		public const int MeryId = 00000000;
		public const int AngelId = 99999999;
		public const string ConnectionString = "DataConnectionString";
		public const string Message = "<?xml version=\"1.0\" encoding=\"utf-8\" ?><cyberNanny>" +
									  "<messageId>{0}</messageId>" +
									  "<dateTime>{1}</dateTime>" +
									  "<requestedBy>{2}</requestedBy>" +
									  "<operation>{3}</operation>" +
									  "</cyberNanny>";

		public enum RequestType : int {
			TakePicture,
			RecordVideo
		}
	}
}