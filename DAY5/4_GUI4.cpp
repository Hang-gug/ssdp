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

		// 실제 자식윈도우 부착은 "C언어 함수" 사용
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
			self->lbutton_down();
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};

class MainWindow : public Window
{
public:
	void lbutton_down() override { std::cout << "MainWindow lbutton_down\n"; }
};
class ImageView : public Window
{
public:
	void lbutton_down() override { std::cout << "ImageView lbutton_down\n"; }
};
int main()
{
	MainWindow w1;
	w1.create("MainWindow");

	ImageView w2;
	w2.create("ImageView");


	w1.add_child(&w2); // w2를 w1의 자식윈도우로 부착

	ec_process_message();
}

