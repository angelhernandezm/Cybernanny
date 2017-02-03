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
#include "DrawDevice.h"
#include "Utils.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

DrawDevice::DrawDevice() {
	m_pBitmap = 0;
	m_pRenderTarget = NULL;

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

DrawDevice::~DrawDevice() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Ensures that resources. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

HRESULT DrawDevice::EnsureResources() {
	auto hr = S_OK;

	if (!m_pRenderTarget) {
		auto size = D2D1::SizeU( m_sourceWidth, m_sourceHeight );

		auto rtProps = D2D1::RenderTargetProperties();
		rtProps.pixelFormat = D2D1::PixelFormat( DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE);
		rtProps.usage = D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE;

		hr = m_pD2DFactory->CreateHwndRenderTarget(rtProps, D2D1::HwndRenderTargetProperties(m_hwnd, size), &m_pRenderTarget);

		if (FAILED(hr))
			return hr;

		hr = m_pRenderTarget->CreateBitmap(D2D1::SizeU(m_sourceWidth, m_sourceHeight), 
			D2D1::BitmapProperties(D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE)),
			&m_pBitmap);

		if (FAILED(hr)) 
			return hr;
	}

	return hr;
}

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

bool DrawDevice::Initialize(HWND hwnd, ID2D1Factory* pD2DFactory, int sourceWidth, int sourceHeight, int Stride) {
	m_hwnd = hwnd;
	m_pD2DFactory = pD2DFactory;
	m_stride = Stride > 0 ? Stride : ((sourceWidth * (32 / 8) + 3) & ~3);
	m_sourceWidth = sourceWidth;
	m_sourceHeight = sourceHeight;

	return true;
}

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

bool DrawDevice::Draw(BYTE * pBits, unsigned long cbBits) {
	// incorrectly sized image data passed in
	if (cbBits < ((m_sourceHeight - 1) * m_stride) + (m_sourceWidth * 4))
		return false;

	// create the resources for this draw device
	// they will be recreated if previously lost
	HRESULT hr = EnsureResources();

	if (FAILED(hr))
		return false;

	// Copy the image that was passed in into the direct2d bitmap
	hr = m_pBitmap->CopyFromMemory(NULL, pBits, m_stride);

	if (FAILED(hr))
		return false;

	m_pRenderTarget->BeginDraw();

	// Draw the bitmap stretched to the size of the window
	m_pRenderTarget->DrawBitmap( m_pBitmap );

	hr = m_pRenderTarget->EndDraw();

	// Device lost, need to recreate the render target
	// We'll dispose it now and retry drawing
	if (hr == D2DERR_RECREATE_TARGET)
		hr = S_OK;

	return SUCCEEDED(hr);
}