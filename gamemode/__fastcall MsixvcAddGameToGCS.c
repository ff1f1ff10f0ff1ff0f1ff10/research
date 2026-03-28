__int64 __fastcall MsixvcAddGameToGCS(__int64 a1)
{
  HRESULT v2; // eax
  int ActivationFactory; // eax
  int v4; // ebx
  __int64 v5; // rcx
  __int64 v6; // rbx
  __int64 (__fastcall *v7)(__int64, PVOID, __int64 *); // rdi
  HSTRING_HEADER *v8; // rax
  int v9; // eax
  __int64 v10; // rcx
  __int64 v11; // rcx
  HRESULT v12; // eax
  int v13; // eax
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rcx
  int v17; // eax
  __int64 v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rcx
  __int64 v21; // rcx
  __int64 v22; // rbx
  __int64 (__fastcall *v23)(__int64, _QWORD, __int64 *); // rdi
  int v24; // eax
  __int64 v25; // rcx
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // rcx
  __int64 v29; // rcx
  __int64 v30; // rbx
  __int64 (__fastcall *v31)(__int64, HSTRING *); // rdi
  int v32; // eax
  __int64 v33; // rcx
  __int64 v34; // rcx
  __int64 v35; // rcx
  __int64 v36; // rcx
  __int64 v37; // rcx
  int v38; // eax
  __int64 v39; // rcx
  __int64 v40; // rcx
  __int64 v41; // rcx
  __int64 v42; // rcx
  __int64 v43; // rcx
  __int64 (__fastcall *v44)(__int64, PCWSTR, __int128 *); // rbx
  PCWSTR StringRawBuffer; // rax
  __int64 v46; // rcx
  __int64 v47; // rcx
  __int64 v48; // rcx
  __int64 v49; // rcx
  __int64 v50; // rcx
  __int64 v51; // [rsp+28h] [rbp-39h] BYREF
  __int64 v52; // [rsp+30h] [rbp-31h] BYREF
  __int64 v53; // [rsp+38h] [rbp-29h] BYREF
  __int64 v54; // [rsp+40h] [rbp-21h] BYREF
  __int64 v55; // [rsp+48h] [rbp-19h] BYREF
  HSTRING v56; // [rsp+50h] [rbp-11h] BYREF
  __int64 v57; // [rsp+58h] [rbp-9h] BYREF
  HSTRING_HEADER hstringHeader; // [rsp+60h] [rbp-1h] BYREF
  HSTRING string; // [rsp+78h] [rbp+17h] BYREF
  __int64 v60; // [rsp+80h] [rbp+1Fh]
  __int128 v61; // [rsp+88h] [rbp+27h] BYREF
  __int128 v62; // [rsp+98h] [rbp+37h] BYREF
  wil::details::in1diag3 *retaddr; // [rsp+C0h] [rbp+5Fh]

  *(_QWORD *)&v61 = a1;
  v57 = 0;
  v62 = 0;
  if ( !a1 )
    return 2147942487LL;
  v51 = 0;
  string = nullptr;
  v2 = WindowsCreateStringReference(L"Windows.Internal.StateRepository.Package", 0x28u, &hstringHeader, &string);
  if ( v2 < 0 )
  {
    Microsoft::WRL::Details::RaiseException((Microsoft::WRL::Details *)(unsigned int)v2);
    JUMPOUT(0x18000602FLL);
  }
  ActivationFactory = RoGetActivationFactory(string, &GUID_0450ce77_af0d_40ac_93fd_1e5d48c89419, &v51);
  v4 = ActivationFactory;
  if ( ActivationFactory >= 0 )
  {
    v52 = 0;
    v6 = v51;
    v7 = *(__int64 (__fastcall **)(__int64, PVOID, __int64 *))(*(_QWORD *)v51 + 176LL);
    v8 = Microsoft::WRL::Wrappers::HStringReference::HStringReference(&hstringHeader, (const WCHAR **)&v61);
    v9 = v7(v6, v8[1].Reserved.Reserved1, &v52);
    v4 = v9;
    if ( v9 >= 0 )
    {
      v54 = 0;
      v53 = 0;
      string = nullptr;
      v12 = WindowsCreateStringReference(
              L"Windows.Internal.StateRepository.Application",
              0x2Cu,
              &hstringHeader,
              &string);
      if ( v12 < 0 )
      {
        Microsoft::WRL::Details::RaiseException((Microsoft::WRL::Details *)(unsigned int)v12);
        __debugbreak();
      }
      v13 = RoGetActivationFactory(string, &GUID_07adcc9a_e505_48c2_b471_45af8561f6af, &v53);
      v4 = v13;
      if ( v13 >= 0 )
      {
        v55 = 0;
        v17 = (*(__int64 (__fastcall **)(__int64, __int64, __int64 *))(*(_QWORD *)v53 + 144LL))(v53, v52, &v55);
        v4 = v17;
        if ( v17 >= 0 )
        {
          v22 = v55;
          v23 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64 *))(*(_QWORD *)v55 + 48LL);
          if ( v54 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v54 + 16LL))(v54);
          v24 = v23(v22, 0, &v54);
          v4 = v24;
          if ( v24 >= 0 )
          {
            v30 = v54;
            v31 = *(__int64 (__fastcall **)(__int64, HSTRING *))(*(_QWORD *)v54 + 232LL);
            WindowsDeleteString(nullptr);
            v56 = nullptr;
            v32 = v31(v30, &v56);
            v4 = v32;
            if ( v32 >= 0 )
            {
              v38 = CreateGameConfigStoreClient(&v57);
              v4 = v38;
              if ( v38 >= 0 )
              {
                v44 = *(__int64 (__fastcall **)(__int64, PCWSTR, __int128 *))(*(_QWORD *)v57 + 40LL);
                StringRawBuffer = WindowsGetStringRawBuffer(v56, nullptr);
                v4 = v44(v57, StringRawBuffer, &v62);
                if ( v4 < 0 )
                {
                  *(_OWORD *)&hstringHeader.Reserved.Reserved2[4] = 0;
                  v60 = 0;
                  v61 = 0;
                  string = (HSTRING)WindowsGetStringRawBuffer(v56, nullptr);
                  *(_DWORD *)&hstringHeader.Reserved.Reserved2[20] = 2;
                  LODWORD(hstringHeader.Reserved.Reserved1) = 2;
                  LODWORD(v60) = v60 & 0xFFFFFFE0 | 0x11;
                  v4 = (**(__int64 (__fastcall ***)(__int64, HSTRING_HEADER *, __int128 *))v57)(
                         v57,
                         &hstringHeader,
                         &v61);
                }
                if ( v57 )
                  FreeGameConfigStoreClient();
                WindowsDeleteString(v56);
                v56 = nullptr;
                v46 = v55;
                if ( v55 )
                {
                  v55 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v46 + 16LL))(v46);
                }
                v47 = v53;
                if ( v53 )
                {
                  v53 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v47 + 16LL))(v47);
                }
                v48 = v54;
                if ( v54 )
                {
                  v54 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v48 + 16LL))(v48);
                }
                v49 = v52;
                if ( v52 )
                {
                  v52 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v49 + 16LL))(v49);
                }
                v50 = v51;
                if ( v51 )
                {
                  v51 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v50 + 16LL))(v50);
                }
              }
              else
              {
                wil::details::in1diag3::Return_Hr(
                  retaddr,
                  (void *)0xB2,
                  (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
                  (const char *)(unsigned int)v38,
                  v51);
                WindowsDeleteString(v56);
                v56 = nullptr;
                v39 = v55;
                if ( v55 )
                {
                  v55 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v39 + 16LL))(v39);
                }
                v40 = v53;
                if ( v53 )
                {
                  v53 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v40 + 16LL))(v40);
                }
                v41 = v54;
                if ( v54 )
                {
                  v54 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v41 + 16LL))(v41);
                }
                v42 = v52;
                if ( v52 )
                {
                  v52 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v42 + 16LL))(v42);
                }
                v43 = v51;
                if ( v51 )
                {
                  v51 = 0;
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v43 + 16LL))(v43);
                }
              }
            }
            else
            {
              wil::details::in1diag3::Return_Hr(
                retaddr,
                (void *)0xAE,
                (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
                (const char *)(unsigned int)v32,
                v51);
              WindowsDeleteString(v56);
              v56 = nullptr;
              v33 = v55;
              if ( v55 )
              {
                v55 = 0;
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v33 + 16LL))(v33);
              }
              v34 = v53;
              if ( v53 )
              {
                v53 = 0;
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v34 + 16LL))(v34);
              }
              v35 = v54;
              if ( v54 )
              {
                v54 = 0;
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v35 + 16LL))(v35);
              }
              v36 = v52;
              if ( v52 )
              {
                v52 = 0;
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v36 + 16LL))(v36);
              }
              v37 = v51;
              if ( v51 )
              {
                v51 = 0;
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v37 + 16LL))(v37);
              }
            }
          }
          else
          {
            wil::details::in1diag3::Return_Hr(
              retaddr,
              (void *)0xAB,
              (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
              (const char *)(unsigned int)v24,
              v51);
            v25 = v55;
            if ( v55 )
            {
              v55 = 0;
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v25 + 16LL))(v25);
            }
            v26 = v53;
            if ( v53 )
            {
              v53 = 0;
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v26 + 16LL))(v26);
            }
            v27 = v54;
            if ( v54 )
            {
              v54 = 0;
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v27 + 16LL))(v27);
            }
            v28 = v52;
            if ( v52 )
            {
              v52 = 0;
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v28 + 16LL))(v28);
            }
            v29 = v51;
            if ( v51 )
            {
              v51 = 0;
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v29 + 16LL))(v29);
            }
          }
        }
        else
        {
          wil::details::in1diag3::Return_Hr(
            retaddr,
            (void *)0xA9,
            (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
            (const char *)(unsigned int)v17,
            v51);
          v18 = v55;
          if ( v55 )
          {
            v55 = 0;
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v18 + 16LL))(v18);
          }
          v19 = v53;
          if ( v53 )
          {
            v53 = 0;
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16LL))(v19);
          }
          if ( v54 )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v54 + 16LL))(v54);
          v20 = v52;
          if ( v52 )
          {
            v52 = 0;
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v20 + 16LL))(v20);
          }
          v21 = v51;
          if ( v51 )
          {
            v51 = 0;
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v21 + 16LL))(v21);
          }
        }
      }
      else
      {
        wil::details::in1diag3::Return_Hr(
          retaddr,
          (void *)0xA6,
          (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
          (const char *)(unsigned int)v13,
          v51);
        v14 = v53;
        if ( v53 )
        {
          v53 = 0;
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 16LL))(v14);
        }
        if ( v54 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v54 + 16LL))(v54);
        v15 = v52;
        if ( v52 )
        {
          v52 = 0;
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 16LL))(v15);
        }
        v16 = v51;
        if ( v51 )
        {
          v51 = 0;
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 16LL))(v16);
        }
      }
    }
    else
    {
      wil::details::in1diag3::Return_Hr(
        retaddr,
        (void *)0xA2,
        (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
        (const char *)(unsigned int)v9,
        v51);
      v10 = v52;
      if ( v52 )
      {
        v52 = 0;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 16LL))(v10);
      }
      v11 = v51;
      if ( v51 )
      {
        v51 = 0;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 16LL))(v11);
      }
    }
  }
  else
  {
    wil::details::in1diag3::Return_Hr(
      retaddr,
      (void *)0x9F,
      (unsigned int)"onecoreuap\\xbox\\gamemode\\dll\\exports.cpp",
      (const char *)(unsigned int)ActivationFactory,
      v51);
    v5 = v51;
    if ( v51 )
    {
      v51 = 0;
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16LL))(v5);
    }
  }
  return (unsigned int)v4;
}
