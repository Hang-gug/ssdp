// 32bit 로 빌드하세요
#define USING_GUI
#include "cppmaster.h"

// 각 OS 는 대부분 UI 를 만드는 "C언어의 함수"를 제공합니다.

int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	int h1 = ec_make_window(foo,  // 이벤트 처리할 함수 주소(인자가int 4개인함수)
							"A"); // 윈도우 caption 문자열

	int h2 = ec_make_window(foo, "B");


	// h2 를 h1 의 자식윈도우로 붙이기. 
	ec_add_child(h1, h2);


	ec_process_message(); // 프로그램을 종료하지 말고
						  // 윈도우에서 발생하는 event 를 처리해 달라
}

