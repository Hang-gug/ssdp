// server.zip 받아서 압축 풀고
// 새로운 visual studio 에서 열어 보세요


// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 클래스를 만들어 봅시다.
// => Remote Proxy

class Calc
{
	int server;
public:
	Calc() {}

	int Add(int a, int b) { return ? ; }
	int Sub(int a, int b) { return ? ; }
};

int main()
{
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





