cdp::Socket::Thread *__fastcall cdp::Socket::Thread::Thread(cdp::Socket::Thread *this)
{
  __int64 v2; // rax
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  _QWORD *v6; // rax
  __int64 v7; // rax
  unsigned int v8; // edx
  __int64 v9; // rax
  unsigned int v10; // edx
  __int64 v11; // rax
  cdp::Socket::BufferCache *v13; // [rsp+20h] [rbp-39h] BYREF
  std::_Ref_count_base *v14; // [rsp+28h] [rbp-31h]
  void (__fastcall *v15)(HANDLE *); // [rsp+30h] [rbp-29h] BYREF
  __int64 v16; // [rsp+38h] [rbp-21h] BYREF
  std::_Ref_count_base *v17; // [rsp+40h] [rbp-19h]
  cdp::Socket::Thread *v18; // [rsp+48h] [rbp-11h]
  _BYTE v19[8]; // [rsp+50h] [rbp-9h] BYREF
  int v20; // [rsp+58h] [rbp-1h]

  v18 = this;
  *(_QWORD *)this = CreateIoCompletionPort((HANDLE)0xFFFFFFFFFFFFFFFFLL, nullptr, 0, 0);
  *(_OWORD *)((char *)this + 8) = 0;
  _Mtx_init_in_situ((cdp::Socket::Thread *)((char *)this + 24), 2);
  *((_QWORD *)this + 13) = 0;
  *((_QWORD *)this + 14) = 0;
  *((_QWORD *)this + 15) = 0;
  cdp::CdpWaitableFlag::CdpWaitableFlag((cdp::Socket::Thread *)((char *)this + 128));
  *((_QWORD *)this + 36) = 0;
  *((_QWORD *)this + 37) = 0;
  *((_QWORD *)this + 38) = 0;
  *((_QWORD *)this + 39) = 0;
  v2 = std::_Allocate<16,std::_Default_allocate_traits,0>(56);
  *(_QWORD *)v2 = v2;
  *(_QWORD *)(v2 + 8) = v2;
  *(_QWORD *)(v2 + 16) = v2;
  *(_WORD *)(v2 + 24) = 257;
  *((_QWORD *)this + 38) = v2;
  _Cnd_init_in_situ((cdp::Socket::Thread *)((char *)this + 320));
  *((_QWORD *)this + 49) = 0;
  *((_QWORD *)this + 50) = 0;
  v3 = std::_Allocate<16,std::_Default_allocate_traits,0>(48);
  *(_QWORD *)v3 = v3;
  *(_QWORD *)(v3 + 8) = v3;
  *(_QWORD *)(v3 + 16) = v3;
  *(_WORD *)(v3 + 24) = 257;
  *((_QWORD *)this + 49) = v3;
  v13 = (cdp::Socket::Thread *)((char *)this + 408);
  *((_QWORD *)this + 51) = 0;
  *((_QWORD *)this + 52) = 0;
  v4 = std::_Allocate<16,std::_Default_allocate_traits,0>(48);
  *(_QWORD *)v4 = v4;
  *(_QWORD *)(v4 + 8) = v4;
  *(_QWORD *)(v4 + 16) = v4;
  *(_WORD *)(v4 + 24) = 257;
  *((_QWORD *)this + 51) = v4;
  if ( ((*(_QWORD *)this + 1LL) & 0xFFFFFFFFFFFFFFFEuLL) == 0 )
  {
    v13 = (cdp::Socket::BufferCache *)".\\socket.cpp";
    LODWORD(v14) = 136;
    v5 = cdp::MakeException<cdp::HResultException<-2147467259>,>(v19, &v13, "Failed to create the IO completion port");
    cdp::CdpThrow<cdp::HResultException<-2147467259>>(&v13, v5);
  }
  shared::SharedInstanceManager::GetInstanceThrowIfNull<shared::ISharedSettingsManager>(&v16);
  v6 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, cdp::Socket::BufferCache **))(*(_QWORD *)v16 + 16LL))(v16, &v13);
  v15 = (void (__fastcall *)(HANDLE *))(*(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)*v6 + 392LL))(*v6);
  if ( v14 )
    std::_Ref_count_base::_Decref(v14);
  v7 = std::make_unique<cdp::Socket::BufferCache,unsigned int const &,unsigned __int64 &,0>(
         &v13,
         &dword_1803C173C,
         &v15);
  std::unique_ptr<cdp::Socket::BufferCache>::operator=((char *)this + 288, v7);
  if ( v13 )
    cdp::Socket::BufferCache::`scalar deleting destructor'(v13, v8);
  v9 = std::make_unique<cdp::Socket::BufferCache,unsigned int const &,unsigned __int64 &,0>(&v13, byte_1803C1738, &v15);
  std::unique_ptr<cdp::Socket::BufferCache>::operator=((char *)this + 296, v9);
  if ( v13 )
    cdp::Socket::BufferCache::`scalar deleting destructor'(v13, v10);
  cdp::Socket::Thread::FillAcceptConnectMap(this, 2);
  cdp::Socket::Thread::FillAcceptConnectMap(this, 5);
  v13 = this;
  v15 = cdp::Socket::Thread::Proc;
  v11 = std::thread::thread(v19, &v15, &v13);
  std::thread::operator=((char *)this + 8, v11);
  if ( v20 )
  {
    _o_terminate();
    __debugbreak();
  }
  std::string::string(v19, (void *)"CDP_SocketIOCP");
  cdp::SetThreadName((char *)this + 8);
  std::string::_Tidy_deallocate(v19);
  if ( v17 )
    std::_Ref_count_base::_Decref(v17);
  return this;
}
