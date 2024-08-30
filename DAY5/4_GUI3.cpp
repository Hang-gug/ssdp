#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window;

std::map<int, Window*> this_map; // 윈도우 번호를 키값으로 this 를 보관하는
								 // 자료구조!!!
								 // 거의 모든 GUI 라이브러리 내부에 있는 기술

class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(&msgproc, title);

		// 윈도우 번호를 키값으로 "객체 주소(this)" 보관
		this_map[handle] = this;
	}


	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
//			lbutton_down();  // this->lbutton_down() 인데 this가 없습니다.
			self->lbutton_down();
			break;

		case WM_KEYDOWN:     
			self->key_down();     
			break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down()     {}
};

class MainWindow : public Window
{
public:
	void lbutton_down() override { std::cout << "MainWindow lbutton_down\n";	}
};
class ImageView : public Window
{
public:
	void lbutton_down() override { std::cout << "ImageView lbutton_down\n";	}
};
int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");

	ec_process_message();
}

