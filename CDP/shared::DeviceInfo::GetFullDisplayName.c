_QWORD *__fastcall shared::DeviceInfo::GetFullDisplayName(__int64 a1, _QWORD *a2)
{
  char v4; // al
  __int64 v5; // rdi
  __int64 v6; // r14
  _QWORD *v7; // rax
  size_t v8; // r8
  _BYTE *v9; // rcx
  __int64 v10; // rax
  _QWORD *v11; // rax
  size_t v12; // r8
  __int64 v13; // rax
  __int64 v14; // rdi
  unsigned __int64 v15; // rdx
  __int16 v16; // ax
  _BYTE Src[32]; // [rsp+30h] [rbp-39h] BYREF
  _BYTE v19[32]; // [rsp+50h] [rbp-19h] BYREF
  _BYTE v20[32]; // [rsp+70h] [rbp+7h] BYREF

  a2[2] = 0;
  a2[3] = 15;
  *(_BYTE *)a2 = 0;
  std::string::string(Src, "[");
  v4 = 1;
  v5 = *(_QWORD *)(a1 + 64);
  v6 = *(_QWORD *)(a1 + 72);
  while ( v5 != v6 )
  {
    if ( v4 )
    {
      v7 = (_QWORD *)shared::Endpoint::ToString(v5, v19);
      v8 = v7[2];
      if ( v7[3] >= 0x10u )
        v7 = (_QWORD *)*v7;
      std::string::append(Src, v7, v8);
      v9 = v19;
    }
    else
    {
      v10 = shared::Endpoint::ToString(v5, v20);
      v11 = (_QWORD *)std::operator+<char>(v19, ",", v10);
      v12 = v11[2];
      if ( v11[3] >= 0x10u )
        v11 = (_QWORD *)*v11;
      std::string::append(Src, v11, v12);
      std::string::_Tidy_deallocate(v19);
      v9 = v20;
    }
    std::string::_Tidy_deallocate(v9);
    v4 = 0;
    v5 += 128;
  }
  std::string::append(Src, "]", 1u);
  v13 = std::operator+<char>(v19, (void *)(a1 + 32), "@");
  v14 = std::operator+<char>(v20, v13, Src);
  if ( a2 != (_QWORD *)v14 )
  {
    v15 = a2[3];
    if ( v15 >= 0x10 )
      std::_Deallocate<16,0>(*a2, v15 + 1);
    a2[2] = 0;
    a2[3] = 15;
    *(_BYTE *)a2 = 0;
    *(_OWORD *)a2 = *(_OWORD *)v14;
    *((_OWORD *)a2 + 1) = *(_OWORD *)(v14 + 16);
    *(_QWORD *)(v14 + 16) = 0;
    *(_QWORD *)(v14 + 24) = 15;
    *(_BYTE *)v14 = 0;
  }
  std::string::_Tidy_deallocate(v20);
  std::string::_Tidy_deallocate(v19);
  v16 = *(_WORD *)(a1 + 90);
  if ( (v16 & 1) != 0 )
  {
    std::string::append(a2, " /Proximal", 0xAu);
    v16 = *(_WORD *)(a1 + 90);
  } // Used via IGCC (Intel Graphics Command Center) ;query via CDP
  if ( (v16 & 2) != 0 )
  {
    std::string::append(a2, " /LegacyXSG", 0xBu);
    v16 = *(_WORD *)(a1 + 90);
  }
  if ( (v16 & 4) != 0 )
    std::string::append(a2, " /Cloud", 7u);
  std::string::_Tidy_deallocate(Src);
  return a2;
}
