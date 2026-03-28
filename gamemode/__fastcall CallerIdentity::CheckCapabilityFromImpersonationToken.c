int __fastcall CallerIdentity::CheckCapabilityFromImpersonationToken(
        CallerIdentity *this,
        void *a2,
        unsigned __int16 *a3,
        bool *a4)
{
  int v5; // eax
  void *v6; // rdx
  unsigned int v7; // r8d
  int v9; // [rsp+20h] [rbp-8h]
  wil::details::in1diag3 *retaddr; // [rsp+28h] [rbp+0h]
  void *v11; // [rsp+38h] [rbp+10h] BYREF

  v11 = a2;
  *(_BYTE *)a3 = 0;
  LOBYTE(v11) = 0;
  v5 = CapabilityCheck(this, L"expandedResources", &v11, a4);
  if ( v5 < 0 )
    return wil::details::in1diag3::Return_NtStatus(retaddr, v6, v7, (const char *)(unsigned int)v5, v9);
  *(_BYTE *)a3 = (_BYTE)v11 != 0;
  return 0;
}
