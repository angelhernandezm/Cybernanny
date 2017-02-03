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

#include "resource.h"
#include "NuiApi.h"
#include "Utils.h"
#include "DrawDevice.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Nui core. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class Nui_Core {
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	Nui_Core();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~Nui_Core();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes this object. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void Initialize();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the sensor identifier get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	CString SensorId_get() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Query if this object has been initialized get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	true if been initialized get, false if not. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool HasBeenInitialized_get() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Starts a time as string get. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	CString StartTimeAsString_get() const;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Take picture. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="imageBytes">	[in,out] The image in bytes. </param>
	/// <param name="bytesCount">	[in,out] Number of bytes. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void TakePicture(std::shared_ptr<BYTE>& imageBytes, int& bytesCount);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets an up. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="views">	 	The views. </param>
	/// <param name="rect">		 	The rectangle. </param>
	/// <param name="initialize">	true to initialize. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void SetUp(const std::map<CString, CStatic*>& views, const CRect& rect, bool initialize);

private:
	/// <summary>	The rectangle. </summary>
	CRect m_rect;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Clean up. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void CleanUp();
	
	/// <summary>	Identifier for the sensor. </summary>
	CString m_sensorId;
	
	/// <summary>	true if this object is initialized. </summary>
	bool m_isInitialized;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes the sensor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool InitializeSensor();
	
	/// <summary>	The milliseconds to wait. </summary>
	int m_millisecondsToWait;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Initializes the color view. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	true if it succeeds, false if it fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool InitializeColorView();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Capture frame in color. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void CaptureFrameInColor();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Capture depth frame. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void CaptureDepthFrame();
	
	/// <summary>	The sensor. </summary>
	CComPtr<INuiSensor> m_pSensor;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Callback, called when the processing. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	DWORD WINAPI ProcessingCallback();
	
	/// <summary>	The d 2 d factory. </summary>
	CComPtr<ID2D1Factory> m_pD2DFactory;
	
	/// <summary>	The views. </summary>
	std::map<CString, CStatic*> m_views;

	/// <summary>	The draw color. </summary>
	std::shared_ptr<DrawDevice> m_pDrawColor;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the image type supported by sensor. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <returns>	The image type supported by sensor. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	NUI_IMAGE_TYPE GetImageTypeSupportedBySensor();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Callback, called when the processing. </summary>
	///
	/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
	///
	/// <param name="pParam">	The parameter. </param>
	///
	/// <returns>	. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static DWORD WINAPI ProcessingCallback(LPVOID pParam);

	/// <summary>	The depth stream. </summary>
	HANDLE  m_hColorView, m_hVideoStream, m_hProcessStop, m_hProcessThread, m_capturingFrame, m_hDepthView, m_hDepthStream;
};