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

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Draw device. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class DrawDevice {
private:

	/// <summary>	Handle of the. </summary>
	HWND                     m_hwnd;
	/// <summary>	The stride. </summary>
	LONG                     m_stride;
	/// <summary>	The bitmap. </summary>
	CComPtr<ID2D1Bitmap>     m_pBitmap;
	/// <summary>	The rectangle destination. </summary>
	RECT                     m_rectDest;
	/// <summary>	The d 2 d factory. </summary>
	CComPtr<ID2D1Factory>    m_pD2DFactory; 
	/// <summary>	Width of the source. </summary>
	UINT                     m_sourceWidth;
	/// <summary>	The 2d rectangle destination. </summary>
	D2D1_RECT_U              m_d2dRectDest;
	/// <summary>	Height of the source. </summary>
	UINT                     m_sourceHeight;
	/// <summary>	The render target. </summary>
	CComPtr<ID2D1HwndRenderTarget> m_pRenderTarget;
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	DrawDevice();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual ~DrawDevice();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Ensures that resources. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	HRESULT EnsureResources();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Draws. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="pBits"> 	[in,out] If non-null, the bits. </param>
	/// <param name="cbBits">	The bits. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Draw(BYTE * pBits, unsigned long cbBits);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="hwnd">		   	Handle of the. </param>
	/// <param name="pD2DFactory"> 	[in,out] If non-null, the d 2 d factory. </param>
	/// <param name="sourceWidth"> 	Width of the source. </param>
	/// <param name="sourceHeight">	Height of the source. </param>
	/// <param name="Stride">	   	The stride. </param>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Initialize(HWND hwnd, ID2D1Factory* pD2DFactory, int sourceWidth, int sourceHeight, int Stride);
};