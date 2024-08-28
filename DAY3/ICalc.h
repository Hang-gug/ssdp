#pragma once

// ICalc.h 
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

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