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
			self->handle_lbutton_down(); // "å���� ��" ���� ����
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// �Ʒ� �ڵ尡 "chain of responsibility" �ٽ�
	void handle_lbutton_down()
	{
		// #1. �ڽ��� ���� ó��
		if (lbutton_down() == true) // ó���� ���
			return;					// ����

		// #2. ó�� ���� �ʰų�, false ��ȯ�ߴٸ� �θ� �����쿡 ����
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
		return true;
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

