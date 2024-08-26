#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}
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
			{
			//	s->draw(); // error

				// 해결책 #1. 조사 후 캐스팅해서 사용

				if (dynamic_cast<Rect*>(s) != nullptr)
				{
					static_cast<Rect*>(s)->draw();
				}
				else if (dynamic_cast<Circle*>(s) != nullptr)
				{
					static_cast<Circle*>(s)->draw();
				}
			}
		}
	}
}
// 실행해서 1, 2, 1, 2, 후에 9 입력해 보세요

// 위 방법의 단점
// => 새로운 도형(Triangle) 이 추가되면
// => if ~ else 가 추가되어야 합니다.
// => OCP 를 만족할수 없습니다.
// => 유연성없는 경직된 디자인!!!

// dynamic_cast 를 사용하는 것은 "좋지 않은 디자인" 이 될 확률이 높습니다.



