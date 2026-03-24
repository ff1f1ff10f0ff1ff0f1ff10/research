__int64 __fastcall IumGenericSyscall(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rax
  __int64 v6; // [rsp+30h] [rbp+8h] BYREF
  __int64 v7; // [rsp+38h] [rbp+10h]
  __int64 v8; // [rsp+40h] [rbp+18h]
  __int64 v9; // [rsp+48h] [rbp+20h]

  v6 = a1;
  v7 = a2;
  v8 = a3;
  v9 = a4;
  return SkSyscall(v4, &v6);
}
