HRESULT __stdcall DwmEnableBlurBehindWindow(HWND hWnd, const DWM_BLURBEHIND *pBlurBehind)
{
  int v2; // r8d
  int *v3; // rdi
  HRGN hRgnBlur; // r14
  char v7; // r13
  LPRGNDATA v8; // r12
  DWORD dwFlags; // eax
  DWORD RegionData; // esi
  CApiPortClient *v11; // rax
  int v12; // eax
  HRESULT v13; // ebx
  int v14; // eax
  unsigned int v15; // edx
  HDC DC; // rbx
  HDC v18; // rax
  signed int LastError; // eax
  int v20; // r9d
  unsigned int v21; // [rsp+20h] [rbp-50h]
  void *v22; // [rsp+28h] [rbp-48h]
  void *v23; // [rsp+28h] [rbp-48h]
  int v24; // [rsp+30h] [rbp-40h] BYREF
  __int128 v25; // [rsp+34h] [rbp-3Ch]
  _BOOL8 v26; // [rsp+44h] [rbp-2Ch]
  LPRGNDATA lpRgnData[2]; // [rsp+50h] [rbp-20h] BYREF

  v3 = &g_PortClient;
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McGenEventWrite_EtwEventWriteTransfer(
      (unsigned int)Microsoft_Windows_Dwm_Api_Provider_Context,
      (unsigned int)ApiEnableBlurBehindWindow_Start,
      v2,
      1);
  hRgnBlur = nullptr;
  v7 = 0;
  lpRgnData[0] = nullptr;
  v8 = nullptr;
  if ( !(unsigned int)IsTopLevelWindow(hWnd)
    || !pBlurBehind
    || (dwFlags = pBlurBehind->dwFlags) == 0
    || (dwFlags & 0xFFFFFFF8) != 0 )
  {
    v21 = 110;
    goto LABEL_43;
  }
  if ( (dwFlags & 2) != 0 )
    hRgnBlur = pBlurBehind->hRgnBlur;
  v24 = 1073741857;
  v26 = 0;
  v25 = 0;
  DWORD2(v25) = dwFlags;
  HIDWORD(v25) = pBlurBehind->fEnable;
  *(_QWORD *)&v25 = hWnd;
  v26 = hRgnBlur != nullptr;
  HIDWORD(v26) = pBlurBehind->fTransitionOnMaximized;
  if ( hRgnBlur )
  {
    if ( (unsigned int)IsWindowGdiScaled(hWnd) )
    {
      DC = GetDC(hWnd);
      if ( DC )
      {
        SetLastError(0);
        v18 = GetDC(hWnd);
        if ( !(unsigned int)ScaleRgn(v18, hRgnBlur) )
        {
          LastError = GetLastError();
          v13 = LastError;
          if ( LastError > 0 )
            v13 = (unsigned __int16)LastError | 0x80070000;
          v21 = 139;
          if ( v13 >= 0 )
            v13 = -2003304445;
          goto LABEL_35;
        }
        ReleaseDC(hWnd, DC);
      }
    }
    RegionData = GetRegionData(hRgnBlur, 0, nullptr);
    if ( RegionData )
    {
      v11 = (CApiPortClient *)_guard_dispatch_icall_fptr();
      if ( v11 )
        v3 = (int *)CApiPortClient::CApiPortClient(v11, RegionData);
      else
        v3 = nullptr;
      if ( !v3 )
      {
        v13 = -2147024882;
        v21 = 148;
LABEL_35:
        v20 = v13;
LABEL_44:
        MilInstrumentationCheckHR_MaybeFailFast(4u, (const int *const)&qword_18001CA40, 2u, v20, v21, v22);
        goto LABEL_19;
      }
      v7 = 1;
      v12 = CApiPortClient::LockExtraDataPointer((CApiPortClient *)v3, RegionData, (void **)lpRgnData);
      v13 = v12;
      if ( v12 < 0 )
      {
        MilInstrumentationCheckHR_MaybeFailFast(4u, (const int *const)&qword_18001CA40, 2u, v12, 0x97u, v22);
        v8 = lpRgnData[0];
        goto LABEL_19;
      }
      v8 = lpRgnData[0];
      if ( !GetRegionData(hRgnBlur, RegionData, lpRgnData[0]) )
      {
        v21 = 155;
LABEL_43:
        v20 = -2147024809;
        v13 = -2147024809;
        goto LABEL_44;
      }
    }
  }
  v14 = CApiPortClient::SendRequest((CApiPortClient *)v3, &v24, 28, (int *)lpRgnData, nullptr, 0);
  v13 = v14;
  if ( v14 < 0 )
    MilInstrumentationCheckHR_MaybeFailFast(4u, (const int *const)&qword_18001CA40, 2u, v14, 0xA4u, v23);
  else
    v13 = (HRESULT)lpRgnData[0];
LABEL_19:
  _guard_dispatch_icall_fptr();
  if ( v8 )
    LeaveCriticalSection((LPCRITICAL_SECTION)(v3 + 8));
  if ( v7 && v3 )
    CApiPortClient::`scalar deleting destructor'((CApiPortClient *)v3, v15);
  if ( (Microsoft_Windows_Dwm_ApiEnableBits & 1) != 0 )
    McTemplateU0q_EtwEventWriteTransfer(
      Microsoft_Windows_Dwm_Api_Provider_Context,
      ApiEnableBlurBehindWindow_Stop,
      (unsigned int)v13);
  return v13;
}
