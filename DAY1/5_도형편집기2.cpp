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

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();	// error.
							// v 는 "Shape*" 를 보관하는 vector이므로
							// s 의 타입은 "Shape*" 입니다.
							// 그런데, Shape 에는 draw 가 없습니다.
		}
	}
}
// 위 코드는 어느 부분에서 왜 에러일까요 ??
// 어떻게 해결해야 할까요 ??
// => 2-1, 2-2 예제 참고



