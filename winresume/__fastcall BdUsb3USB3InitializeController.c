__int64 __fastcall BdUsb3USB3InitializeController(__int64 a1)
{
  __int64 v1; // rbp
  int v2; // esi
  __int64 v3; // rcx
  __int64 v4; // r8
  __int64 v5; // rax
  __int64 v6; // rcx
  __int64 v7; // rdx
  int v8; // edi
  char *v9; // rcx
  unsigned __int64 v10; // rdi
  __int16 v11; // ax
  __int64 v12; // rax
  __int64 v14; // [rsp+40h] [rbp+8h] BYREF

  v14 = a1;
  v1 = KdUsb;
  v2 = -1073741823;
  v3 = 0;
  v4 = *(_QWORD *)(KdUsb + 296736);
  v5 = v4 + 24;
  while ( !*(_BYTE *)(v5 + 1) || *(_BYTE *)v5 != 3 || !*(_QWORD *)(v5 + 8) )
  {
    v3 = (unsigned int)(v3 + 1);
    v5 += 24;
    if ( (unsigned int)v3 >= 6 )
      goto LABEL_33;
  }
  v6 = 3 * v3;
  v7 = *(_QWORD *)(v4 + 8 * v6 + 32);
  *(_QWORD *)(KdUsb + 296720) = v7;
  *(_DWORD *)(v1 + 296728) = *(_DWORD *)(v4 + 8 * v6 + 40);
  *(_QWORD *)(v1 + 296144) = v7;
  *(_DWORD *)(v1 + 296136) = *(_DWORD *)(v1 + 296728);
  v8 = BdUsb3ParseCapabilityRegister(v1 + 296128);
  if ( v8 < 0 )
  {
    v9 = "ParseCapabilityRegister Failed %!STATUS!\n";
LABEL_9:
    KdUsb_printf(v9);
    goto LABEL_25;
  }
  v10 = *(_QWORD *)(v1 + 296176);
  while ( 1 )
  {
    v11 = qword_5402E8(v10);
    if ( (_BYTE)v11 == 10 )
      break;
    if ( (v11 & 0xFF00) != 0 )
    {
      v10 += 4LL * HIBYTE(v11);
      if ( v10 < *(_QWORD *)(v1 + 296144) + (unsigned __int64)*(unsigned int *)(v1 + 296136) )
        continue;
    }
    v10 = 0;
    break;
  }
  *(_QWORD *)(v1 + 296184) = v10;
  if ( !v10 )
  {
    KdUsb_printf("This controller does not provide debug capability.\n");
    v8 = -1073741810;
    v9 = "ParseDebugCapabilityRegister Failed %!STATUS!\n";
    goto LABEL_9;
  }
  KdUsb_printf("Debug Capability Registers Base Address 0x%p\n");
  v12 = qword_5402E8(*(_QWORD *)(v1 + 296184));
  if ( (BYTE2(v12) & 0x1Fu) <= 0xF )
  {
    *(_DWORD *)(v1 + 296224) = 1 << (BYTE2(v12) & 0x1F);
  }
  else
  {
    *(_DWORD *)(v1 + 296224) = 0;
    KdUsb_printf("Invalid value contained in DCERST Max: %d. Valid values are 0 - 15.\n");
  }
  KdUsb_printf("Debug Capability Event Ring Segment Table Max Entries: %d..\n");
  *(_DWORD *)(v1 + 296228) = (unsigned __int8)((unsigned int)qword_5402E8(*(_QWORD *)(v1 + 296184) + 32LL) >> 16);
  KdUsb_printf("Debug Capability Control Register 0x%p Contents 0x%X Max Burst Size: %d\n");
  qword_5402E8(*(_QWORD *)(v1 + 296184) + 36LL);
  KdUsb_printf("Debug Capability Status Register 0x%p ER= 0x%X Port Number = 0x%X\n");
  v8 = BdUsb3Usb3ResetController(v1 + 296128, 5335000);
  if ( v8 < 0 )
  {
    v9 = "ControllerReset Failed %!STATUS!\n";
    goto LABEL_9;
  }
  if ( !*(_QWORD *)(v1 + 296144) )
  {
    KdUsb_printf("Failed to find CapabilityRegisters\n");
    v8 = -1073741823;
  }
LABEL_25:
  if ( LoggingInitialized && KdUsbDbgLog )
  {
    __rdtsc();
    LastLogTime = 5069622;
    KdUsb_printf("%8ld %s line %d value %lx\n");
  }
  v2 = v8;
  if ( v8 >= 0 )
  {
    v2 = BdUsb3USB3SetupDebugSupport((void *)v1);
    if ( v2 >= 0 )
    {
      LODWORD(v14) = 1500000;
      v2 = BdUsb3USB3WaitForConnection(v1, &v14);
      if ( !LoggingInitialized )
        return (unsigned int)v2;
      if ( KdUsbDbgLog )
      {
        __rdtsc();
        LastLogTime = 5069763;
        KdUsb_printf("%8ld %s line %d value %lx\n");
      }
    }
  }
LABEL_33:
  if ( LoggingInitialized && KdUsbDbgLog )
  {
    __rdtsc();
    LastLogTime = 5069863;
    KdUsb_printf("%8ld %s line %d value %lx\n");
  }
  return (unsigned int)v2;
}
