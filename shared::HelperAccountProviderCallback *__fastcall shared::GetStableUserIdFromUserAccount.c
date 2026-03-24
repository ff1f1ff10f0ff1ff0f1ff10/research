shared::HelperAccountProviderCallback *__fastcall shared::GetStableUserIdFromUserAccount(
        shared::HelperAccountProviderCallback *a1,
        _QWORD *a2,
        _QWORD *a3,
        __int64 a4)
{
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  std::_Ref_count_base *v11; // rdi
  struct _Mtx_internal_imp_t *v12; // rbx
  int v13; // eax
  __int64 v14; // rax
  __int64 (__fastcall *v15)(__int64, _QWORD, __int64, std::_Ref_count_base *, shared::HelperAccountProviderCallback **); // r10
  __int64 v16; // r11
  int v17; // eax
  __int64 v18; // rax
  int v19; // eax
  int v20; // r14d
  int v21; // r15d
  __int64 v22; // rax
  __int64 v23; // r8
  __int64 v24; // rax
  char v26; // [rsp+30h] [rbp-69h]
  shared::HelperAccountProviderCallback *v27; // [rsp+38h] [rbp-61h] BYREF
  std::_Ref_count_base *v28[2]; // [rsp+40h] [rbp-59h] BYREF
  char *v29; // [rsp+58h] [rbp-41h]
  _BYTE v30[56]; // [rsp+60h] [rbp-39h] BYREF
  const char *v31; // [rsp+98h] [rbp-1h] BYREF
  int v32; // [rsp+A0h] [rbp+7h]

  v27 = a1;
  if ( !*a2 )
  {
    v31 = "..\\useridentityhelpers.cpp";
    v32 = 585;
    v7 = cdp::MakeException<std::invalid_argument,>(v28, a2, "Expected provider.");
    cdp::CdpThrow<std::invalid_argument>(&v31, v7);
  }
  if ( !*a3 )
  {
    v31 = "..\\useridentityhelpers.cpp";
    v32 = 586;
    v8 = cdp::MakeException<std::invalid_argument,>(v28, a2, "Expected account.");
    cdp::CdpThrow<std::invalid_argument>(&v31, v8);
  }
  v27 = (shared::HelperAccountProviderCallback *)operator new(0x1F0u);
  v9 = shared::HelperAccountProviderCallback::HelperAccountProviderCallback(v27);
  *(_OWORD *)v28 = 0;
  if ( v9 )
  {
    LOBYTE(v10) = v26;
    std::shared_ptr<shared::HelperAccountProviderCallback>::_Setpd<shared::HelperAccountProviderCallback *,cdp::detail::iunknown_deleter<shared::HelperAccountProviderCallback>>(
      v28,
      v9,
      v10);
  }
  v11 = v28[0];
  v12 = (std::_Ref_count_base *)((char *)v28[0] + 32);
  v29 = (char *)v28[0] + 32;
  v13 = _Mtx_lock((std::_Ref_count_base *)((char *)v28[0] + 32));
  if ( v13 )
    std::_Throw_C_error(v13);
  LODWORD(v27) = 0;
  v14 = std::string::c_str(a4);
  v17 = v15(v16, *a3, v14, v11, &v27);
  if ( v17 < 0 )
  {
    v31 = "..\\useridentityhelpers.cpp";
    v32 = 597;
    v18 = cdp::MakeException<cdp::hresult_exception,>(
            v30,
            &v31,
            (unsigned int)v17,
            "Could not call GetStableUserIdAsync.");
    cdp::CdpThrow<cdp::hresult_exception>(&v31, v18);
  }
  *((_DWORD *)v11 + 68) = (_DWORD)v27;
  v19 = _Mtx_unlock(v12);
  if ( v19 )
    std::_Throw_C_error(v19);
  v27 = (shared::HelperAccountProviderCallback *)(1000 * qword_1804646E8);
  std::string::string(
    &v31,
    "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > __cdecl shared::GetStableUse"
    "rIdFromUserAccount(const class std::shared_ptr<class ICDPAccountProvider> &,const class std::shared_ptr<class ICDPAc"
    "count> &,const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &)");
  v20 = shared::CancellableBlockingCall((char *)v11 + 112, &v31, &v27);
  std::string::_Tidy_deallocate(&v31);
  v21 = *((_DWORD *)v11 + 69);
  if ( v21 < 0 )
  {
    cdp::detail::StringFormat(&v31, "GetStableUserIdFromUserAccount providerWaitResult=0x%08X");
    shared::AggregatedTelemetryLogger::Log((unsigned int)v21, &v31, "..\\useridentityhelpers.cpp", 606);
    std::string::_Tidy_deallocate(&v31);
  }
  if ( v20 < 0 )
  {
    v31 = "..\\useridentityhelpers.cpp";
    v32 = 607;
    v22 = cdp::MakeException<cdp::hresult_exception,>(
            v30,
            &v31,
            (unsigned int)v20,
            "Timed out while requesting Stable User Id.");
    cdp::CdpThrow<cdp::hresult_exception>(&v31, v22);
  }
  v23 = *((unsigned int *)v11 + 69);
  if ( (int)v23 < 0 )
  {
    v31 = "..\\useridentityhelpers.cpp";
    v32 = 608;
    v24 = cdp::MakeException<cdp::hresult_exception,>(v30, &v31, v23, "Failure while requesting Stable User Id.");
    cdp::CdpThrow<cdp::hresult_exception>(&v31, v24);
  }
  std::string::string(a1, (char *)v11 + 376);
  if ( v28[1] )
    std::_Ref_count_base::_Decref(v28[1]);
  return a1;
}
