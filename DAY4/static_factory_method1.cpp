// static_factory_method1.cpp
#include <iostream>

class Window
{
public:
	Window() { init(); }

	virtual void init() { std::cout << "Window init\n"; }
};

class MyWindow : public Window
{
	int data;
public:
	MyWindow() : data(99) {}
	void init() override { std::cout << "MyWindow init\n"; int n = data; }
};

int main()
{
	MyWindow w;
}
// 실행하지 말고, 결과 예측해 보세요