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
using System.Web.UI;
using System.Web.UI.WebControls;
using Microsoft.WindowsAzure;
using Microsoft.WindowsAzure.ServiceRuntime;

namespace CyberNanny_webRole {
	public partial class _Default : System.Web.UI.Page {
		/// <summary>
		/// Handles the Load event of the Page control.
		/// </summary>
		/// <param name="sender">The source of the event.</param>
		/// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
		protected void Page_Load(object sender, EventArgs e) {

		}

		/// <summary>
		/// Handles the Click event of the btnExecute control.
		/// </summary>
		/// <param name="sender">The source of the event.</param>
		/// <param name="e">The <see cref="System.EventArgs"/> instance containing the event data.</param>
		protected void btnExecute_Click(object sender, EventArgs e) {
			int tryParse;

			if (int.TryParse(txtUser.Text, out tryParse) &&
				 (tryParse.Equals(Common.AngelId) || tryParse.Equals(Common.MeryId))) {
				var proxy = new CyberNannyService();
				validator.IsValid = !string.IsNullOrEmpty(proxy.AddRequest((Common.RequestType)cboOperations.SelectedIndex, tryParse));
			} else
				validator.IsValid = false;

		}
	}
}
