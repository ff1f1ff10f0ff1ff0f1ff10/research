__int64 BlArchGetCpuVendor()
{
  int v0; // eax
  int v2; // [rsp+20h] [rbp-18h] BYREF
  char Str1[4]; // [rsp+24h] [rbp-14h] BYREF
  int v4; // [rsp+28h] [rbp-10h]
  int v5; // [rsp+2Ch] [rbp-Ch]

  BlArchCpuId(0, 0, &v2);
  v0 = v5;
  v5 = v4;
  v4 = v0;
  if ( !strncmp(Str1, "GenuineIntel", 0xCu) )
    return 2;
  if ( !strncmp(Str1, "AuthenticAMD", 0xCu) )
    return 1;
  return strncmp(Str1, "CentaurHauls", 0xCu) == 0 ? 3 : 0;
}
