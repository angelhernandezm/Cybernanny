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
using System.Diagnostics;
using System.Linq;
using Microsoft.WindowsAzure;
using Microsoft.WindowsAzure.Diagnostics;
using Microsoft.WindowsAzure.ServiceRuntime;
using Microsoft.WindowsAzure.StorageClient;

namespace CyberNanny_webRole {
	public class WebRole : RoleEntryPoint {
		private CloudQueue queue;

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
		/// Initializes the queue.
		/// </summary>
		private void InitializeQueue() {
			bool storageInitialized = false;

			CloudStorageAccount.SetConfigurationSettingPublisher((configName, configSetter) => {
				configSetter(GetConnectionString("DataConnectionString"));
			});

			var storageAccount = CloudStorageAccount.FromConfigurationSetting("DataConnectionString");

			// initialize queue storage 
			CloudQueueClient queueStorage = storageAccount.CreateCloudQueueClient();
			queue = queueStorage.GetQueueReference("cybernanny");
			Trace.TraceInformation("Creating queue...");

			while (!storageInitialized) {
				try {
					queue.CreateIfNotExist();
					storageInitialized = true;
				} catch (StorageClientException e) {
					if (e.ErrorCode == StorageErrorCode.TransportError) {
						Trace.TraceError("Storage services initialization failure. Message:{0}", e.Message);
						System.Threading.Thread.Sleep(3000);
					} else {
						throw;
					}
				}
			}
		}

		/// <summary>
		/// Called by Windows Azure to initialize the role instance.
		/// </summary>
		/// <returns>
		/// True if initialization succeeds, False if it fails. The default implementation returns True.
		/// </returns>
		public override bool OnStart() {
			// For information on handling configuration changes
			// see the MSDN topic at http://go.microsoft.com/fwlink/?LinkId=166357.

			InitializeQueue();

			return base.OnStart();
		}
	}
}
