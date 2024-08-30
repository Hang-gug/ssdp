// 32bit 로 빌드하세요
#define USING_GUI
#include "cppmaster.h"



class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&msgproc, title);
	}

	// 핵심 #1. 아래 함수가 static 멤버 함수 이어야 하는 이유를 알아야 합니다.
	// => 다른 함수의 인자로 전달되는 함수(C 언어의 callback 함수)를
	//    클래스로 만들때는 "static 멤버로 해야 합니다."

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.create("A"); // 이순간 윈도우가 생성되어야 합니다.

	ec_process_message();
}

