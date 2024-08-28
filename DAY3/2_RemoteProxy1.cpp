// server.zip 받아서 압축 풀고
// 새로운 visual studio 에서 열어 보세요


// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

// 클라이 언트를 아래 처럼 작성할때 문제점

// 1. 모든 클라이언트 제작자가 IPC 기술을 알아야 합니다.

// 2. 서버 장애 발생시, 각각의 클라이 언트에서 장애 처리를 해야 합니다.
//	  (주서버 대신, 백업 서버 사용)

// 3. 자주 사용되는 요청의 결과는  cache 하는 것이 좋을때가 있습니다.
//	  (현재는 기능 없음)
// 
// 4. 덧셈은 1, 뺄셈은 2 라는 명령 코드를 외워야 합니다.
//    실제 환경에는 수십~ 수백의 명령이 있습니다.


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





