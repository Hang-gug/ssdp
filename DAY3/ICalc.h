// ICalc.h 
#pragma once

// 객체의 수명을 "reference counting" 으로 관리 하는 경우
// reference couting 함수는 반드시 interface 에서도 선언되어야 합니다.

// #1. 먼저 reference counting 만을 위한 인터페이스 설계
struct IRefCount
{	
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

// #2. 이제 다양한 Proxy 인터페이스 만들때, IRefCount 에서 상속 받으세요
struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// 위소스 저장하고
// cl CalcProxy2.cpp /LD 로 빌드하고
// DLL 이름을 "CalcProxy.dll"로 변경하세요









// 규칙
// 1. 새로운 Proxy 배포될때 DLL 이름은 동일해야 합니다.
//    => 기존 DLL 덮어쓰기

// 2. DLL 에는 반드시 "create" 함수가 있어야 합니다.

ICalc* load_proxy()
{
	// #1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
	// linux   : dlopen()
	// windows : LoadLibrary()

	using F = ICalc * (*)(); // 함수 포인터 타입
	// typedef ICalc*(*F)()

// #2. DLL 에서 약속된 함수 찾기
	F f = (F)ec_get_function_address(addr, "create");
	// linux   : dlsym()
	// windows : GetProcAddress()

// #3. 약속된 함수로 proxy 만들기.
	return f();
}