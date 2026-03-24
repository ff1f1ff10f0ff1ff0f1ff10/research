__int64 __fastcall UnattendSearchPantherUnattend(__int64 a1)
{
  WCHAR *Expand; // rax
  WCHAR *v3; // rdi
  unsigned int v4; // ebx
  HANDLE ProcessHeap; // rax
  signed int LastError; // eax
  signed int v7; // ecx
  signed int v8; // eax

  Expand = AllocateExpand(L"%windir%\\Panther\\Unattend"); // OS searching for unattend.xml | %OEM% %$$% %Panther% %unattend.xml%
  v3 = Expand;
  if ( Expand )
  {
    v4 = UnattendSearchImplicitPath(Expand, a1);
    ProcessHeap = GetProcessHeap();
    HeapFree(ProcessHeap, 0, v3);
  }
  else
  {
    LastError = GetLastError();
    v7 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v7 = LastError;
    if ( v7 >= 0 )
    {
      return (unsigned int)-2147467259;
    }
    else
    {
      v8 = GetLastError();
      v4 = (unsigned __int16)v8 | 0x80070000;
      if ( v8 <= 0 )
        return (unsigned int)v8;
    }
  }
  return v4;
}
