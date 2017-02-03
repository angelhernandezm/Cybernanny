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
using System.Diagnostics;
using System.Text;
using Microsoft.WindowsAzure;
using Microsoft.WindowsAzure.ServiceRuntime;
using Microsoft.WindowsAzure.StorageClient;

namespace CyberNanny_webRole {
	// NOTE: You can use the "Rename" command on the "Refactor" menu to change the class name "CyberNanny" in code, svc and config file together.
	public class CyberNannyService : ICyberNanny {
		/// <summary>
		/// Gets the connection string.
		/// </summary>
		/// <param name="settingName">Name of the setting.</param>
		/// <returns></returns>
		private string GetConnectionString(string settingName) {
			try {
				return RoleEnvironment.GetConfigurationSettingValue(settingName);
			} catch (Exception) {
				return "UseDevelopmentStorage=true";
			}
		}


		/// <summary>
		/// Adds the request.
		/// </summary>
		/// <param name="type">The type.</param>
		/// <param name="userIdentifier">The user identifier.</param>
		/// <returns></returns>
		public string AddRequest(Common.RequestType type, int userIdentifier) {
			var retval = string.Empty;

			CloudStorageAccount.SetConfigurationSettingPublisher((configName, configSetter) => {
				configSetter(GetConnectionString("DataConnectionString"));
			});

			var account = CloudStorageAccount.FromConfigurationSetting(Common.ConnectionString);
			var queueClient = account.CreateCloudQueueClient();

			if (userIdentifier.Equals(Common.AngelId) || userIdentifier.Equals(Common.MeryId)) {
				retval = string.Format(Common.Message, new object[] { Guid.NewGuid(), DateTime.Now, userIdentifier, type.ToString() });
				var queueMessage = new CloudQueueMessage(Encoding.Default.GetBytes((retval)));
				var queue = queueClient.GetQueueReference("cybernanny");
				queue.AddMessage(queueMessage);
			}

			return retval;
		}

		/// <summary>
		/// Removes the request.
		/// </summary>
		/// <param name="userIdentifier">The user identifier.</param>
		/// <param name="removeAll">if set to <c>true</c> [remove all].</param>
		/// <returns></returns>
		public bool RemoveRequest(int userIdentifier, bool removeAll, out StringBuilder message) {
			var retval = false;
			message = new StringBuilder();

			CloudStorageAccount.SetConfigurationSettingPublisher((configName, configSetter) => {
				configSetter(GetConnectionString("DataConnectionString"));
			});


			if (userIdentifier.Equals(Common.AngelId) || userIdentifier.Equals(Common.MeryId)) {
				var account = CloudStorageAccount.FromConfigurationSetting(Common.ConnectionString);
				var queueClient = account.CreateCloudQueueClient();
				var queue = queueClient.GetQueueReference("cybernanny");

				if (queue.RetrieveApproximateMessageCount() > 0) {
					if (!removeAll) {
						var messageObj = queue.GetMessage();
						message.Append(messageObj.AsString);
						queue.DeleteMessage(messageObj);
					} else {
						queue.Clear();
					}
					retval = true;
				}
			}
			return retval;
		}
	}
}
