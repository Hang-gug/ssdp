// ICalc.h 
#pragma once

// ��ü�� ������ "reference counting" ���� ���� �ϴ� ���
// reference couting �Լ��� �ݵ�� interface ������ ����Ǿ�� �մϴ�.

// #1. ���� reference counting ���� ���� �������̽� ����
struct IRefCount
{	
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

// #2. ���� �پ��� Proxy �������̽� ���鶧, IRefCount ���� ��� ��������
struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// ���ҽ� �����ϰ�
// cl CalcProxy2.cpp /LD �� �����ϰ�
// DLL �̸��� "CalcProxy.dll"�� �����ϼ���









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