//***************************************************************************************
// File: EmptyProject9.cpp
//
// Empty starting point for new Direct3D 9 and/or Direct3D 10 applications
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
// Visual Studio 2010
// Microsoft DirectX SDK (June 2010)
//--------------------------------------------------------------------------------------
// Modified by sgiman, 2022, jul
//***************************************************************************************
#include "DXUT.h"


//--------------------------------------------------------------------------------------
// Cбрасывает любые устройства D3D9, неприемлемые для приложения, возвращая false
//--------------------------------------------------------------------------------------
bool CALLBACK IsD3D9DeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat,
                                      bool bWindowed, void* pUserContext )
{
    // Обычно требуется пропустить форматы обратного буфера, которые не поддерживают альфа-смешивание
    IDirect3D9* pD3D = DXUTGetD3D9Object();
    if( FAILED( pD3D->CheckDeviceFormat( pCaps->AdapterOrdinal, pCaps->DeviceType,
                                         AdapterFormat, D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING,
                                         D3DRTYPE_TEXTURE, BackBufferFormat ) ) )
        return false;

    return true;
}


//-----------------------------------------------------------------------------------------------
// Создать любые ресурсы D3D9, которые будут работать после сброса устройства (D3DPOOL_MANAGED)
// и не привязаны к размеру заднего буфера
//-----------------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9CreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                     void* pUserContext )
{
    return S_OK;
}


//-----------------------------------------------------------------------------------------------
// Создать любые ресурсы D3D9, которые не сохранятся после сброса устройства (D3DPOOL_DEFAULT)
// или которые привязаны к размеру заднего буфера
//-----------------------------------------------------------------------------------------------
HRESULT CALLBACK OnD3D9ResetDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc,
                                    void* pUserContext )
{
    return S_OK;
}


//--------------------------------------------------------------------------------------
// Рендерить сцену с помощью устройства D3D9
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9FrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
    HRESULT hr;

	// Очистить цель рендеринга и zbuffer
    V( pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB( 0, 45, 50, 170 ), 1.0f, 0 ) );

	// Рендеринг сцены
    if( SUCCEEDED( pd3dDevice->BeginScene() ) )
    {
        V( pd3dDevice->EndScene() );
    }
}


//--------------------------------------------------------------------------------------
// Освободить ресурсы D3D9, созданные в обратном вызове OnD3D9ResetDevice
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9LostDevice( void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Освобождаем ресурсы D3D9, созданные в обратном вызове OnD3D9CreateDevice
//--------------------------------------------------------------------------------------
void CALLBACK OnD3D9DestroyDevice( void* pUserContext )
{
}
