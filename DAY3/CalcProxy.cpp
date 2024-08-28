// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Ŭ���̾�Ʈ �����ڴ� �� Ŭ���� �̸��� �˼��� ����, ���ʿ䵵 ����, ����ص� �ȵ˴ϴ�.
// DLL ���ο��� ��ӵ� �Լ��� ���ؼ� ��ü�� �����ؾ� �մϴ�.

extern "C" __declspec(dllexport) // windows ���� DLL �ȿ� �Լ� ���鶧 �ʿ�
ICalc* create()
{
	return new Calc;
}

// �������� C++ �����Ϸ� : g++ ( gcc )
// vs ��   C++ �����Ϸ� : cl.exe

// ������ ���۹�ư ������ "cmd" �Է�, ��Ÿ���� â���� "cl" �Է��� ������
// => "PATH" ��� �ȵǾ� �־ error.
// => �ܼ� "PATH" ��Ͽܿ��� ��� ȯ�漳�� �ʿ�.


// ���� ��ư, "developer command".. �� ������ ��Ÿ���� â ���� 

//-----------------------------
// 1. �ҽ��� �ִ� ������ �̵� (cd ���)
// 2. �Ʒ� ������� ����

// "cl CalcProxy.cpp /LD"

// "/LD" �� DLL�� �����ϴ� ���.. g++�� -fPic ���.


