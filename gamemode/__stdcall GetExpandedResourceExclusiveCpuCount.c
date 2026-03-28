HRESULT __stdcall GetExpandedResourceExclusiveCpuCount(ULONG *exclusiveCpuCount)
{
  int LargestValidResourceRequest; // ebx
  HRESULT v3; // ebx
  int v5; // [rsp+30h] [rbp-39h] BYREF
  int v6; // [rsp+34h] [rbp-35h] BYREF
  HRESULT v7; // [rsp+38h] [rbp-31h] BYREF
  _OWORD v8[2]; // [rsp+40h] [rbp-29h] BYREF
  __int64 v9; // [rsp+60h] [rbp-9h]
  char v10[32]; // [rsp+70h] [rbp+7h] BYREF
  HRESULT *v11; // [rsp+90h] [rbp+27h]
  int v12; // [rsp+98h] [rbp+2Fh]
  int v13; // [rsp+9Ch] [rbp+33h]
  int *v14; // [rsp+A0h] [rbp+37h]
  int v15; // [rsp+A8h] [rbp+3Fh]
  int v16; // [rsp+ACh] [rbp+43h]

  *exclusiveCpuCount = 0;
  v5 = 0;
  RtlGetDeviceFamilyInfoEnum(0, &v5, 0);
  if ( v5 == 5 )
  {
    *exclusiveCpuCount = 6;
  }
  else
  {
    memset(v8, 0, sizeof(v8));
    v9 = 0;
    LargestValidResourceRequest = RmGameModeGetLargestValidResourceRequest(v8);
    if ( LargestValidResourceRequest < 0 )
    {
      v3 = LargestValidResourceRequest | 0x10000000;
      goto LABEL_7;
    }
    *exclusiveCpuCount = DWORD1(v8[0]);
  }
  v3 = 0;
LABEL_7:
  if ( (unsigned int)dword_18000E000 > 4 )
  {
    v16 = 0;
    v13 = 0;
    v14 = &v6;
    v11 = &v7;
    v15 = 4;
    v12 = 4;
    v7 = v3;
    tlgWriteTransfer_EventWriteTransfer(&dword_18000E000, &dword_18000B0AC, 0, 0, 4, v10, v5);
  }
  return v3;
}
