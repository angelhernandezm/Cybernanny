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
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace CyberNanny_webRole {
	[ServiceContract]
	public interface ICyberNanny {
		/// <summary>
		/// Adds the request.
		/// </summary>
		/// <param name="type">The type.</param>
		/// <param name="userIdentifier">The user identifier.</param>
		/// <returns></returns>
		[OperationContract]
		string AddRequest(Common.RequestType type, int userIdentifier);

		/// <summary>
		/// Removes the request.
		/// </summary>
		/// <param name="userIdentifier">The user identifier.</param>
		/// <param name="removeAll">if set to <c>true</c> [remove all].</param>
		/// <param name="message">The message.</param>
		/// <returns></returns>
		[OperationContract]
		bool RemoveRequest(int userIdentifier, bool removeAll, out StringBuilder message);
	}
}
