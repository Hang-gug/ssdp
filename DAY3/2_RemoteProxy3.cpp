#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Proxy 제작자 : Server 제작자가 만들어서 배포
// Proxy 사용자 : Client 제작자가 사용.


int main()
{
	// 아래 처럼 만들면 "강한 결합" 입니다.
	// 새로운  Proxy 가 나오면 아래 코드는 수정되어야 합니다.
	// OCP 위반
	// Calc* calc = new Calc;

	// 인터페이스 기반의 약한결합으로 사용해야 합니다.



	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





