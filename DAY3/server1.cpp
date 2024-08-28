// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"
// 
// Server1.cpp
#define USING_GUI
#include "cppmaster.h" // ipc 용 함수가 있습니다.

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

int handler(int code, int a, int b)
{
	printf("메세지 도착 : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);
	}
	// 이 함수의 반환 값은 클라이언트에게 전달 됩니다.
	return 0;
}
int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc",		// 서버이름
					&handler);	// 클라이언트 접속시 호출될 함수
								// 클라이언트는 3개의 int 값을 보내게 됩니다.
}




