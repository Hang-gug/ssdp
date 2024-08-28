#pragma once

// ICalc.h 
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// ��Ģ
// 1. ���ο� Proxy �����ɶ� DLL �̸��� �����ؾ� �մϴ�.
//    => ���� DLL �����

// 2. DLL ���� �ݵ�� "create" �Լ��� �־�� �մϴ�.

ICalc* load_proxy()
{
	// #1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
	// linux   : dlopen()
	// windows : LoadLibrary()

	using F = ICalc * (*)(); // �Լ� ������ Ÿ��
	// typedef ICalc*(*F)()

// #2. DLL ���� ��ӵ� �Լ� ã��
	F f = (F)ec_get_function_address(addr, "create");
	// linux   : dlsym()
	// windows : GetProcAddress()

// #3. ��ӵ� �Լ��� proxy �����.
	return f();
}