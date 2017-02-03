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

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Image file. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class ImageFile {
private:
	/// <summary>	Full pathname of the saved image file. </summary>
	std::wstring m_savedImagePath;
	/// <summary>	The image in bytes. </summary>
	std::shared_ptr<BYTE> m_imageBytes;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the bitmap information header. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	The bitmap information header. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	BITMAPINFOHEADER GetBitmapInfoHeader();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Rotate image. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="filePath">	Full pathname of the file. </param>
	/// <param name="newFile"> 	[in,out] The new file. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool RotateImage(const std::wstring& filePath, std::wstring& newFile);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets an encoder clsid. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="format">	Describes the format to use. </param>
	/// <param name="pClsid">	[in,out] If non-null, the clsid. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetEncoderClsid(const WCHAR* format, CLSID* pClsid);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a bitmap file header. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="infoHeader">	The information header. </param>
	///
	/// <returns>	The bitmap file header. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	BITMAPFILEHEADER GetBitmapFileHeader(const BITMAPINFOHEADER& infoHeader);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Helper method that serialize image. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="infoHeader">	The information header. </param>
	/// <param name="fileHeader">	The file header. </param>
	/// <param name="filePath">  	[in,out] Full pathname of the file. </param>
	/// <param name="bytes">	 	[in,out] The bytes. </param>
	/// <param name="byteCount"> 	Number of bytes. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool SerializeImageHelper(const BITMAPINFOHEADER& infoHeader, const BITMAPFILEHEADER& fileHeader, std::wstring& filePath, std::shared_ptr<BYTE>& bytes, int byteCount);

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	ImageFile();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~ImageFile();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Deletes the file. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void DeleteFile();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Serialize image. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="bytes">		[in,out] The bytes. </param>
	/// <param name="byteCount">	Number of bytes. </param>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	std::wstring SerializeImage(std::shared_ptr<BYTE>& bytes, int byteCount);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the image file path get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	std::wstring ImageFilePath_get() const;
};