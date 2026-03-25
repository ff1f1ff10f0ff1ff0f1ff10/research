__int64 __fastcall wil::details::ReportFailure_GetLastError(
        wil::details *a1,
        void *a2,
        __int64 a3,
        const char *a4,
        const char *a5,
        const char *a6)
{
  unsigned int v7; // esi
  unsigned int LastErrorFail; // ebx
  void *v11; // [rsp+30h] [rbp-38h]

  v7 = (unsigned int)a2;
  LastErrorFail = wil::details::GetLastErrorFail(
                    a1,
                    a2,
                    (unsigned int)"onecore\\internal\\sdk\\inc\\wil\\opensource\\wil\\resource.h",
                    a4,
                    a5,
                    a6,
                    v11);
  wil::details::ReportFailure(a1, v7, "onecore\\internal\\sdk\\inc\\wil\\opensource\\wil\\resource.h", a4);
  return LastErrorFail;
}
