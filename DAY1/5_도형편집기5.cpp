#include <iostream>
#include <vector>

class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	// 가상함수 : 파생 클래스가 override 하지 않으면 기본 구현 제공하겠다는 의도
	// 순수가상함수 : 파생클래스 제작자에게 반드시 구현을 제공하라고 지시하는 것
	virtual void draw() = 0;

	// 아래 함수도
	// 1. "= 0" 도 좋고
	// 2. "기본 구현에서 예외발생" 하는 디자인도 Python, C# 등에서 널리 사용
	virtual Shape* clone()
	{
		throw NotImplemented();
	}

	virtual int get_area() { return 0; }

};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제할까요 ? ";

			int k;
			std::cin >> k;


			v.push_back(v[k]->clone()); 

		}
	}
}




