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
#include "ImageFile.h"
#include <Rpc.h>
#include <GDIPlus.h>

using namespace Gdiplus;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ImageFile::ImageFile() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

ImageFile::~ImageFile() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Deletes the file. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void ImageFile::DeleteFile() {
	if (m_savedImagePath.length() > 0) {
		auto hMutex = CreateMutex(NULL, FALSE, DELETE_FILE_MUTEX_NAME);

		if (hMutex != NULL && (GetLastError() == ERROR_ALREADY_EXISTS)) {
			CloseHandle(hMutex);
			return;
		}

		::DeleteFile(m_savedImagePath.c_str());

		CloseHandle(hMutex);
	}
}

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

std::wstring ImageFile::SerializeImage(std::shared_ptr<BYTE>& bytes, int byteCount) {
	RPC_WSTR guidAsStr; 
	WCHAR tempPath[MAX_PATH];
	std::wstring retval, tempFile;
	std::unique_ptr<GUID> guid(new GUID);
	CoCreateGuid(guid.get());
	UuidToString(guid.get(), &guidAsStr);
	auto str = std::wstring((LPTSTR) guidAsStr);
	GetTempPath(MAX_PATH, tempPath);
	tempFile = std::wstring(tempPath).append(L"photo_").append(str).append(L".bmp");
	auto infoHeader = GetBitmapInfoHeader();
	auto fileHeader = GetBitmapFileHeader(infoHeader);

	if (SerializeImageHelper(infoHeader, fileHeader, tempFile, bytes, byteCount)) { 
		if (RotateImage(tempFile, retval))
			m_savedImagePath = retval;
	} else retval = L"";

	return retval;
}

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

bool ImageFile::RotateImage(const std::wstring& filePath, std::wstring& newFile) {
	CLSID jpgClsid;
	newFile = filePath;
	auto retval = false;
	ULONG_PTR gdiplusToken;
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	if ((retval = GetEncoderClsid(L"image/jpeg", &jpgClsid))) {
		auto fileToRotate = new Image(filePath.c_str(), FALSE);
		newFile.replace(newFile.find(L"bmp"), 3, L"jpg");
		fileToRotate->RotateFlip(Rotate180FlipNone);
		fileToRotate->Save(newFile.c_str(), &jpgClsid, NULL);
		delete fileToRotate;
	}

	::DeleteFile(filePath.c_str());

	GdiplusShutdown(gdiplusToken);

	return retval;
}

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

bool ImageFile::GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
	UINT  num = 0;        
	UINT  size = 0;       
	auto retval = false;

	ImageCodecInfo* pImageCodecInfo = NULL;

	if ((GetImageEncodersSize(&num, &size)) == Status::Ok && (pImageCodecInfo = (ImageCodecInfo*)(malloc(size))) != NULL) {
		if (GetImageEncoders(num, size, pImageCodecInfo) == Status::Ok) {
			for(auto index = 0; index < num; ++index)  {
				if(wcscmp(pImageCodecInfo[index].MimeType, format) == 0 ) {
					*pClsid = pImageCodecInfo[index].Clsid;
					free(pImageCodecInfo);
					pImageCodecInfo = NULL;
					retval = true;
					break;
				}    
			}
		}
	}


	if (!pImageCodecInfo)
		free(pImageCodecInfo);

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the image file path get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

std::wstring ImageFile::ImageFilePath_get() const {
	return m_savedImagePath;
}

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

bool ImageFile::SerializeImageHelper(const BITMAPINFOHEADER& infoHeader, const BITMAPFILEHEADER& fileHeader,
									 std::wstring& filePath, std::shared_ptr<BYTE>& bytes, int byteCount) { 
	auto retval = false;
	auto hFile = CreateFile(filePath.c_str(), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile !=  INVALID_HANDLE_VALUE) {
		auto newFile = CFile(hFile);
		newFile.Write(&fileHeader, sizeof(BITMAPFILEHEADER));
		newFile.Write(&infoHeader, sizeof(BITMAPINFOHEADER));
		newFile.Write(bytes.get(), byteCount);
		newFile.Close();
		retval = true;
	}

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the bitmap information header. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	The bitmap information header. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

BITMAPINFOHEADER ImageFile::GetBitmapInfoHeader() {
	BITMAPINFOHEADER retval = {0};

	retval.biSize = sizeof(BITMAPINFOHEADER);
	retval.biBitCount = 32;
	retval.biPlanes = 1;
	retval.biCompression = BI_RGB;
	retval.biWidth = 640;
	retval.biHeight = 480;
	retval.biSizeImage = ((((retval.biWidth * retval.biBitCount) + 31) & ~31) >> 3) * retval.biHeight;

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets a bitmap file header. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="infoHeader">	The information header. </param>
///
/// <returns>	The bitmap file header. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

BITMAPFILEHEADER ImageFile::GetBitmapFileHeader(const BITMAPINFOHEADER& infoHeader) {
	BITMAPFILEHEADER retval = {0};

	auto nBitsOffset = sizeof(BITMAPFILEHEADER) + infoHeader.biSize; 
	auto lImageSize = infoHeader.biSizeImage;
	auto lFileSize = nBitsOffset + lImageSize;
	retval.bfType = 'B'+('M'<<8);
	retval.bfOffBits = nBitsOffset;
	retval.bfSize = lFileSize;

	return retval;
}