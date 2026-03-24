__int64 __fastcall DwmpReadColorizationParameters(int *a1)
{
  LSTATUS v2; // eax
  signed int v3; // ebx
  int v4; // eax
  HKEY v5; // rcx
  int v6; // eax
  int v7; // ecx
  HKEY v8; // rcx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  bool v15; // cc
  int v17; // r9d
  unsigned int phkResult; // [rsp+20h] [rbp-10h]
  void *v19; // [rsp+28h] [rbp-8h]
  int v20; // [rsp+60h] [rbp+30h] BYREF
  HKEY hKey; // [rsp+68h] [rbp+38h] BYREF

  hKey = nullptr;
  if ( !a1 )
  {
    v3 = -2147024809;
    phkResult = 129;
LABEL_31:
    v17 = v3;
    goto LABEL_32;
  }
  v2 = RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\DWM", 0, 1u, &hKey);
  v3 = v2;
  if ( v2 > 0 )
    v3 = (unsigned __int16)v2 | 0x80070000;
  if ( v3 < 0 )
  {
    phkResult = 137;
    goto LABEL_31;
  }
  v20 = 0;
  v4 = DwmpLoadColorizationParameter(hKey, L"ColorizationColor", &v20);
  v3 = v4;
  if ( v4 < 0 )
  {
    phkResult = 152;
    goto LABEL_28;
  }
  v5 = hKey;
  *a1 = v20;
  v20 = 0;
  v6 = DwmpLoadColorizationParameter(v5, L"ColorizationColorBalance", &v20);
  v7 = v20;
  v20 = 0;
  if ( v6 < 0 )
    v7 = 27;
  a1[2] = v7;
  v4 = DwmpLoadColorizationParameter(hKey, L"ColorizationAfterglow", &v20);
  v3 = v4;
  if ( v4 < 0 )
  {
    phkResult = 154;
    goto LABEL_28;
  }
  v8 = hKey;
  a1[1] = v20;
  v20 = 0;
  v9 = DwmpLoadColorizationParameter(v8, L"ColorizationAfterglowBalance", &v20);
  v10 = v20;
  v20 = 0;
  if ( v9 < 0 )
    v10 = 0;
  a1[3] = v10;
  v11 = DwmpLoadColorizationParameter(hKey, L"ColorizationBlurBalance", &v20);
  v12 = v20;
  v20 = 0;
  if ( v11 < 0 )
    v12 = 73;
  a1[4] = v12;
  v13 = DwmpLoadColorizationParameter(hKey, L"EnableWindowColorization", &v20);
  v14 = v20;
  v20 = 0;
  if ( v13 < 0 )
    v14 = 1;
  a1[5] = v14;
  v4 = DwmpLoadColorizationParameter(hKey, L"ColorizationGlassAttribute", &v20);
  v3 = v4;
  if ( v4 < 0 )
  {
    phkResult = 158;
LABEL_28:
    v17 = v4;
LABEL_32:
    MilInstrumentationCheckHR_MaybeFailFast(4u, (const int *const)&qword_18001B878, 2u, v17, phkResult, v19);
    goto LABEL_22;
  }
  v15 = (unsigned int)a1[2] <= 0x64;
  a1[6] = v20;
  if ( !v15 )
    a1[2] = 27;
  if ( (unsigned int)a1[3] > 0x64 )
    a1[3] = 0;
  if ( (unsigned int)a1[4] > 0x64 )
    a1[4] = 73;
LABEL_22:
  if ( hKey )
    RegCloseKey(hKey);
  return (unsigned int)v3;
}
