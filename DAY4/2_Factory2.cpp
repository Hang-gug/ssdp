#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자신을 만드는 static 멤버 함수는 아주 유용하게 활용됩니다.
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* r1 = new Rect;			// 클래스 이름을 알아야 합니다.
// 2. Rect* r2 = Rect::create();	// 클래스 이름을 몰라도 함수주소만
//									// 알면 객체 생성 가능합니다.

// #1. C++ 에서는 "클래스 이름" 을 자료구조에 보관할수 없습니다.
// v.push_back("Rect"); // 클래스 이름이 아닌 문자열 보관한것. 문자열로는 객체생성안됨
// v.push_back(Rect);   // 이렇게 하고 싶지만, 안됨.

// #2. 하지만 함수 주소는 자료구조에 보관됩니다.
// v.push_back(&Rect::create);












class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) 
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




