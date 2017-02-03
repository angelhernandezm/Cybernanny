<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
	CodeBehind="Default.aspx.cs" Inherits="CyberNanny_webRole._Default" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
</asp:Content>
<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
	<div>
		<table>
			<tr>
				<td>
					<asp:Label ID="Label1" runat="server" Text="Requesting User ID:"></asp:Label>
				</td>
				<td>
					<asp:TextBox ID="txtUser" runat="server" TextMode="Password" Width="300px"></asp:TextBox>
				</td>
			</tr>
			<tr>
				<td>
					<asp:Label ID="Label2" runat="server" Text="Operation to Perform:"></asp:Label>
				</td>
				<td>
					<asp:DropDownList ID="cboOperations" runat="server" Width="300px">
						<asp:ListItem>Take Picture</asp:ListItem>
						<asp:ListItem>Record Video</asp:ListItem>
					</asp:DropDownList>
				</td>
			</tr>
			<tr>
				<td colspan="2" align="center">
					<asp:Button ID="btnExecute" runat="server" Text="Execute" OnClick="btnExecute_Click" />
				</td>
			</tr>
			<tr>
				<td colspan="2" align="center">
					<asp:CustomValidator ID="validator" runat="server" ErrorMessage="Invalid User ID. Please, check your User ID"
						ForeColor="Red"></asp:CustomValidator>
				</td>
			</tr>
		</table>
	</div>
</asp:Content>
