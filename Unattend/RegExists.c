__int64 __fastcall RegExists(HKEY a1)
{
  unsigned int v1; // ebx
  HKEY hKey; // [rsp+48h] [rbp+10h] BYREF //

  v1 = 0;
  hKey = nullptr;
  if ( !RegOpenKeyExW(a1, L"SYSTEM\\Setup", 0, 0x20019u, &hKey) && hKey )
  {
    LOBYTE(v1) = RegQueryValueExW(hKey, L"UnattendFile", nullptr, nullptr, nullptr, nullptr) == 0;
    RegCloseKey(hKey);
  }
  SetLastError(0);
  return v1;
