void BgpDisplayBootUxState()
{
  int *RegionContext; // rsi
  int *v1; // rdi
  wchar_t *v2; // rbx
  unsigned int i; // r14d
  const wchar_t *v4; // r8
  __int64 v5; // r9
  int v6; // eax
  int v7; // ecx
  __int64 v8; // [rsp+20h] [rbp-E0h]
  int v9; // [rsp+20h] [rbp-E0h]
  int v10; // [rsp+20h] [rbp-E0h]
  int v11; // [rsp+28h] [rbp-D8h]
  int v12; // [rsp+28h] [rbp-D8h]
  int v13; // [rsp+38h] [rbp-C8h]
  wchar_t Dst[104]; // [rsp+70h] [rbp-90h] BYREF

  if ( (dword_5428F0 & 0x20) == 0 )
    return;
  RegionContext = (int *)BgpTxtGetRegionContext(qword_5429A8);
  v1 = (int *)BgpTxtGetRegionContext(qword_5429B0);
  switch ( dword_542A50 )
  {
    case 2:
      v2 = L"Meiryo Console";
      break;
    case 1:
      v2 = L"Malgun Gothic Console";
      break;
    case 3:
      v2 = L"Microsoft YaHei Console";
      break;
    default:
      v2 = L"Microsoft JhengHei Console";
      if ( dword_542A50 != 4 )
        v2 = L"Segoe Mono Boot";
      break;
  }
  for ( i = 0; i < 4; ++i )
  {
    if ( !i )
    {
      if ( (_DWORD)xmmword_542890 == 4 )
      {
        v7 = 24;
      }
      else
      {
        v7 = 1;
        if ( (_DWORD)xmmword_542890 == 5 )
          v7 = 32;
      }
      v11 = v7;
      v9 = DWORD1(BgInternal);
      swprintf_s(Dst, 0x64u, L"DISP [%dx%dx%d]");
LABEL_26:
      BgpDisplayStringEx(Dst, v9, v11, (__int64)v2, v13);
      continue;
    }
    if ( i != 1 )
    {
      if ( i == 2 )
      {
        if ( !RegionContext )
          continue;
        v4 = L"ANIM [%dx%d] (%d, %d) {%d}";
        v5 = (unsigned int)RegionContext[2];
        v13 = RegionContext[5];
        v11 = *RegionContext;
        v6 = RegionContext[3];
      }
      else
      {
        if ( !v1 )
          continue;
        v4 = L"TEXT [%dx%d] (%d, %d) {%d}";
        v5 = (unsigned int)v1[2];
        v13 = v1[5];
        v11 = *v1;
        v6 = v1[3];
      }
      LODWORD(v8) = v6;
      swprintf_s(Dst, 0x64u, v4, v5, v8);
      goto LABEL_26;
    }
    if ( qword_542938 )
    {
      v12 = dword_54294C;
      v10 = dword_542958;
      swprintf_s(Dst, 0x64u, L"LOGO [%dx%d] (%d, %d)", (unsigned int)dword_542954);
      BgpDisplayStringEx(Dst, v10, v12, (__int64)v2, v13);
    }
  }
  if ( RegionContext )
    BlMmFreeHeap(RegionContext);
  if ( v1 )
    BlMmFreeHeap(v1);
}
