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

extern "C" __declspec(dllexport) // windows 에서 DLL 안에 함수 만들때 필요
ICalc* create()
{
	return new Calc;
}

// 리눅스용 C++ 컴파일러 : g++ ( gcc )
// vs 이   C++ 컴파일러 : cl.exe

// 윈도우 시작버튼 누르고 "cmd" 입력, 나타나는 창에서 "cl" 입력해 보세요
// => "PATH" 등록 안되어 있어서 error.
// => 단순 "PATH" 등록외에도 몇가지 환경설정 필요.


// 시작 버튼, "developer command".. 로 적으면 나타나는 창 실행 

//-----------------------------
// 1. 소스가 있는 폴더로 이동 (cd 명령)
// 2. 아래 명령으로 빌드

// "cl CalcProxy.cpp /LD"

// "/LD" 가 DLL로 빌드하는 명령.. g++의 -fPic 기능.


