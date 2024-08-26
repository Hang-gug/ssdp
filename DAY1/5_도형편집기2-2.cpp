#include <iostream>
#include <vector>

// #1. 모든 파생 클래스의 공통의 특징은 
//     "반드시 기반 클래스에도 있어야 합니다."
//     (문법이 아닌 디자인 규칙)
//     그래야 Shape* 로 draw() 호출 가능합니다.

// #2. 기반 클래스 함수중 파생 클래스가 override 하는 것은
//     반드시 "virtual" 로 만들어야 한다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();	
		}
	}
}




