__int64 __fastcall locationapi_IID_Lookup(__int64 **Buf1, int *a2)
{
  int v3; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  __int64 **v9; // rdx
  signed __int64 v10; // rcx

  v3 = -1;
  v5 = memcmp_0(Buf1, &IID_ICivicAddressReportFactory, 0x10u);
  if ( v5 <= 0 )
  {
    if ( !v5 )
    {
      v3 = 8;
LABEL_13:
      *a2 = v3;
      return 1;
    }
  }
  else
  {
    v3 = 4;
  }
  v6 = memcmp_0(Buf1, locationapi_ProxyVtblList[v3 + 4][1], 0x10u);
  if ( v6 >= 0 )
  {
    v3 += 4;
    if ( !v6 )
      goto LABEL_13;
  }
  v7 = memcmp_0(Buf1, locationapi_ProxyVtblList[v3 + 2][1], 0x10u);
  if ( v7 >= 0 )
  {
    v3 += 2;
    if ( !v7 )
      goto LABEL_13;
  }
  v8 = memcmp_0(Buf1, locationapi_ProxyVtblList[v3 + 1][1], 0x10u);
  if ( v8 >= 0 )
  {
    ++v3;
    if ( !v8 )
      goto LABEL_13;
  }
  if ( ++v3 < 12 )
  {
    _mm_lfence();
    v9 = locationapi_ProxyVtblList[v3][1];
    v10 = (char *)*Buf1 - (char *)*v9;
    if ( *Buf1 == *v9 )
      v10 = (char *)Buf1[1] - (char *)v9[1];
    if ( !v10 )
      goto LABEL_13;
  }
  return 0;
}
