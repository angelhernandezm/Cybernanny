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
#include <strsafe.h>
#include "resource.h"
#include "Nui_Core.h"
#include "DrawDevice.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Default constructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Nui_Core::Nui_Core() {
	m_isInitialized = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Sets an up. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="views">	 	The views. </param>
/// <param name="rect">		 	The rectangle. </param>
/// <param name="initialize">	true to initialize. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Nui_Core::SetUp(const std::map<CString, CStatic*>& views, const CRect& rect, bool initialize) {
	m_rect = rect;
	m_views = views;
	m_isInitialized = false;
	m_millisecondsToWait = 0;

	if (initialize) 
		Initialize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Destructor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

Nui_Core::~Nui_Core() {
	if (m_isInitialized)
		CleanUp();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Capture depth frame. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Nui_Core::CaptureDepthFrame() {
	NUI_IMAGE_FRAME imageFrame;
	NUI_LOCKED_RECT LockedRect;

	if (FAILED(m_pSensor->NuiImageStreamGetNextFrame(m_hDepthStream, m_millisecondsToWait, &imageFrame)))
		return;

	auto pTexture = imageFrame.pFrameTexture;
	pTexture->LockRect(0, &LockedRect, NULL, 0);

	if (LockedRect.Pitch != 0) {
		DWORD frameWidth = 0, frameHeight = 0;
		NuiImageResolutionToSize( imageFrame.eResolution, frameWidth, frameHeight);
		pTexture->UnlockRect(0); 
		m_pSensor->NuiImageStreamReleaseFrame(m_hDepthStream, &imageFrame);
	} 
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Take picture. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="imageBytes">	[in,out] The image in bytes. </param>
/// <param name="bytesCount">	[in,out] Number of bytes. </param>
////////////////////////////////////////////////////////////////////////////////////////////////////

void  Nui_Core::TakePicture(std::shared_ptr<BYTE>& imageBytes, int& bytesCount) {
	byte *bytes;
	NUI_IMAGE_FRAME imageFrame;
	NUI_LOCKED_RECT LockedRect;

	if (SUCCEEDED(m_pSensor->NuiImageStreamGetNextFrame(m_hVideoStream, m_millisecondsToWait, &imageFrame))) {
		auto pTexture = imageFrame.pFrameTexture;
		pTexture->LockRect(0, &LockedRect, NULL, 0);

		if (LockedRect.Pitch != 0) {
			bytes = static_cast<BYTE *>(LockedRect.pBits);
			m_pDrawColor->Draw(bytes, LockedRect.size);
		}

		pTexture->UnlockRect(0);
		imageBytes.reset(new BYTE[LockedRect.size]);
		memcpy(imageBytes.get(), bytes, LockedRect.size);
		bytesCount = LockedRect.size;
		m_pSensor->NuiImageStreamReleaseFrame(m_hVideoStream, &imageFrame );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the color view. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Nui_Core::InitializeColorView() {
	auto width = m_rect.right - m_rect.left;
	auto height = m_rect.bottom - m_rect.left;
	m_pDrawColor = std::shared_ptr<DrawDevice>(new DrawDevice());
	return (m_pDrawColor.get()->Initialize(m_views[TAB_VIEW_1]->m_hWnd, m_pD2DFactory.p, 640, 320, NULL));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the image type supported by sensor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	The image type supported by sensor. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

NUI_IMAGE_TYPE Nui_Core::GetImageTypeSupportedBySensor() {
	return (HasSkeletalEngine(m_pSensor) ? NUI_IMAGE_TYPE_DEPTH_AND_PLAYER_INDEX : NUI_IMAGE_TYPE_DEPTH);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Capture frame in color. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Nui_Core::CaptureFrameInColor() {
	byte *bytes;
	NUI_IMAGE_FRAME imageFrame;
	NUI_LOCKED_RECT LockedRect;

	if (FAILED(m_pSensor->NuiImageStreamGetNextFrame(m_hVideoStream, m_millisecondsToWait, &imageFrame)))
		return;

	auto pTexture = imageFrame.pFrameTexture;

	pTexture->LockRect(0, &LockedRect, NULL, 0);

	if (LockedRect.Pitch != 0) {
		bytes = static_cast<BYTE *>(LockedRect.pBits);
		m_pDrawColor->Draw(bytes, LockedRect.size);
	}

	pTexture->UnlockRect(0);

	m_pSensor->NuiImageStreamReleaseFrame(m_hVideoStream, &imageFrame );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Callback, called when the processing. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD WINAPI Nui_Core::ProcessingCallback() {
	auto index = 0;
	auto keepGoing = true;
	const auto eventCount = 2;
	HANDLE events[eventCount] = {m_hProcessStop, m_hDepthView}; 

	while(keepGoing) {
		index = WaitForMultipleObjects(eventCount, events, FALSE, 100);

		switch(index) {
		case WAIT_TIMEOUT:
			continue;

		case WAIT_OBJECT_0:
			keepGoing = false;
			continue;

		case WAIT_OBJECT_0 + 1:
			CaptureDepthFrame();
			CaptureFrameInColor();
			break;
		}
	}

	return FALSE;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Callback, called when the processing. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <param name="pParam">	The parameter. </param>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

DWORD WINAPI Nui_Core::ProcessingCallback(LPVOID pParam) {
	auto retval = (Nui_Core*) pParam;

	return (retval->ProcessingCallback());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Clean up. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Nui_Core::CleanUp() {
	if (m_hProcessStop != NULL)	{
		SetEvent(m_hProcessStop);
		if (m_hProcessThread != NULL) {
			WaitForSingleObject(m_hProcessThread, INFINITE);
			TerminateThread(m_hProcessThread, NULL);
			CloseHandle(m_hProcessThread);
		}
		CloseHandle(m_hProcessStop);
	}

	if (m_pSensor != NULL) {
		m_pSensor->NuiShutdown();
	}

	if (m_hDepthView != NULL && (m_hDepthView != INVALID_HANDLE_VALUE))	{
		CloseHandle(m_hDepthView);
		m_hDepthView = NULL;
	}

	if (m_hColorView != NULL && (m_hColorView != INVALID_HANDLE_VALUE))	{
		CloseHandle(m_hColorView);
		m_hColorView = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes the sensor. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	true if it succeeds, false if it fails. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Nui_Core::InitializeSensor() {
	auto retval = false;
	auto result = m_pSensor->NuiInitialize(NUI_FLAGS_ALL);

	if (FAILED(result)) {
		if (result == E_NUI_DEVICE_IN_USE) 
			::MessageBox(NULL, L"This Kinect sensor is already in use.", L"Information",  MB_OK | MB_ICONHAND);
		else 
			::MessageBox(NULL, L"Failed to initialize Kinect.", L"Information",  MB_OK | MB_ICONHAND);

		return retval;
	} 

	m_hColorView = CreateEvent(NULL, TRUE, FALSE, NULL);

	if (FAILED(m_pSensor->NuiImageStreamOpen(NUI_IMAGE_TYPE_COLOR,
		NUI_IMAGE_RESOLUTION_640x480, NULL, 2,
		m_hColorView, &m_hVideoStream))) {
			::MessageBox(NULL, L"Unable to open video stream.", L"Information",  MB_OK | MB_ICONHAND);
			return retval;
	}

	m_hDepthView = CreateEvent(NULL, TRUE, FALSE, NULL);

	if (FAILED(m_pSensor->NuiImageStreamOpen(GetImageTypeSupportedBySensor(),
		NUI_IMAGE_RESOLUTION_640x480, NULL, 2,
		m_hDepthView, &m_hDepthStream))) {
			::MessageBox(NULL, L"Unable to open depth stream.", L"Information",  MB_OK | MB_ICONHAND);
			return retval;
	}

	retval = true;

	return retval;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Initializes this object. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

void Nui_Core::Initialize() {
	if (!m_isInitialized) {
		auto sensorCount = 0;

		if (SUCCEEDED(NuiGetSensorCount(&sensorCount)) && sensorCount > 0) {
			if (SUCCEEDED(NuiCreateSensorByIndex(0, &m_pSensor))) {
				auto instanceName = m_pSensor->NuiDeviceConnectionId();
				m_sensorId = CString(instanceName);
				SysFreeString(instanceName);
				D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pD2DFactory);
				auto color = LogEventWithReturn([=]{return InitializeColorView();}, CString("Initializing ColorView"));

				if (color) {
					if ((m_isInitialized = InitializeSensor())) {
						m_hProcessStop = CreateEvent(NULL, FALSE, FALSE, NULL);
						m_hProcessThread = CreateThread(NULL, 0, ProcessingCallback, this, 0, NULL);
					}
				}
			}
		} else {
			m_sensorId = L"Kinect not available";

			::MessageBox(NULL, L"No sensor was found. Please connect a sensor and re-launch the application",
				L"Information",  MB_OK | MB_ICONHAND);

		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Query if this object has been initialized get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	true if been initialized get, false if not. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

bool Nui_Core::HasBeenInitialized_get() const {
	return m_isInitialized;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Starts a time as string get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

CString Nui_Core::StartTimeAsString_get() const {
	auto currentTime = CTime::GetCurrentTime();
	return (currentTime.Format("%A, %B %d, %Y - %H:%M:%S"));
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Gets the sensor identifier get. </summary>
///
/// <remarks>	Angel.hernandez, 12/04/2012. </remarks>
///
/// <returns>	. </returns>
////////////////////////////////////////////////////////////////////////////////////////////////////

CString Nui_Core::SensorId_get() const {
	return m_sensorId;
}