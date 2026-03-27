__int64 SymCryptDetectCpuFeaturesByCpuid()
{
  int v0; // edi
  __int16 *v1; // r9
  int v3; // r8d
  unsigned int v4; // r11d
  int v9; // esi
  int v10; // r10d
  int v16; // eax
  __int64 result; // rax
  int v37; // [rsp+0h] [rbp-20h]
  int v38; // [rsp+4h] [rbp-1Ch]
  int v39; // [rsp+8h] [rbp-18h]
  int v40; // [rsp+Ch] [rbp-14h]

  v0 = 0;
  v1 = word_1C0002162;
  _RAX = 0;
  v3 = -16352;
  v4 = 0;
  __asm { cpuid; Get CPU ID }
  v9 = _RAX;
  v37 = _RAX;
  v38 = _RBX;
  v39 = _RCX;
  v40 = _RDX;
  do
  {
    v10 = *((unsigned __int8 *)v1 - 2);
    if ( v10 != v0 )
    {
      _RAX = *((unsigned __int8 *)v1 - 2);
      __asm { cpuid; Get CPU ID }
      v37 = _RAX;
      v0 = v10;
      v38 = _RBX;
      v39 = _RCX;
      v40 = _RDX;
    }
    if ( v10 > v9 || (v16 = *(&v37 + *((unsigned __int8 *)v1 - 1)), !_bittest(&v16, *(unsigned __int8 *)v1)) )
      v3 |= *(_DWORD *)(v1 + 1);
    ++v4;
    v1 += 4;
  }
  while ( v4 < 0x14 );
  _RAX = 1;
  __asm { cpuid; Get CPU ID }
  if ( (_RCX & 0x8000000) == 0 )
    goto LABEL_10;
  __asm { xgetbv; Get Value of Extended Control Register }
  if ( (_RAX & 6) != 6 )
LABEL_10:
    LOBYTE(v3) = v3 | 0x10;
  if ( (v3 & 4) == 0 )
  {
    _RAX = 0;
    __asm { cpuid; Get CPU ID }
    if ( (_DWORD)_RBX == 1752462657 && (_DWORD)_RCX == 1145913699 && (_DWORD)_RDX == 1769238117 )
    {
      _RAX = 1;
      __asm { cpuid; Get CPU ID }
    }
  }
  _RAX = 1;
  g_SymCryptCpuFeaturesNotPresent = -1073735348;
  __asm { cpuid; Get CPU ID }
  g_SymCryptCpuid1 = -1073735338;
  dword_1C0003044 = -1073735332;
  dword_1C0003048 = -1073735326;
  dword_1C000304C = -1073735320;
  __asm { cpuid; Get CPU ID }
  return result;
}
