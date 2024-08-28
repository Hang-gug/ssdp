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

ICalc* create()
{
	return new Calc;
}