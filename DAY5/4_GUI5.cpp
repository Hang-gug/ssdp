#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;

std::map<int, Window*> this_map;

class Window
{
	int handle;

	Window* parent = nullptr;

	std::vector<Window*> child_vector;
public:

	void add_child(Window* child)
	{
		child->parent = this;

		child_vector.push_back(child);

		ec_add_child(this->handle, child->handle);
	}


	void create(const std::string& title)
	{
		handle = ec_make_window(&msgproc, title);

		this_map[handle] = this;
	}


	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			//self->lbutton_down();
			self->handle_lbutton_down(); // "책임의 고리" 패턴 적용
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// 아래 코드가 "chain of responsibility" 핵심
	void handle_lbutton_down()
	{
		// #1. 자신이 먼저 처리
		if (lbutton_down() == true) // 처리된 경우
			return;					// 종료

		// #2. 처리 되지 않거나, false 반환했다면 부모 윈도우에 전달
		if (parent != nullptr)
			parent->handle_lbutton_down();
	}


	virtual bool lbutton_down() { return false; }
	virtual void key_down() {}
};





class MainWindow : public Window
{
public:
	bool lbutton_down() override 
	{ 
		std::cout << "MainWindow lbutton_down\n"; 
		return true;
	}
};
class ImageView : public Window
{
public:
	bool lbutton_down() override 
	{
		std::cout << "ImageView lbutton_down\n"; 
//		return true;	// 이벤트 처리를 종료해 달라.
		return false;	// 이벤트를 부모윈도우에도 전달해 달라.
	}
};


int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");


	w1.add_child(&w2); 

	ec_process_message();
}


// 대부분의 GUI 라이브러리는 위와 같이 이벤트를 처리 합니다.
// 그런데, 각 라이브러리가 각각 "다른 이름" 으로 위 기술을 소개 합니다.

// IOS(swift) : Responder Chain
// WPF(C#)    : Bublling Event
// MFC(C++)   : Command Routing
