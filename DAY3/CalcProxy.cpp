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

// 클라이언트 제작자는 위 클래스 이름을 알수도 없고, 알필요도 없고, 사용해도 안됩니다.
// DLL 내부에서 약속된 함수를 통해서 객체를 생성해야 합니다.

ICalc* create()
{
	return new Calc;
}