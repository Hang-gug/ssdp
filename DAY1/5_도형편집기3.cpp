#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }


	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }
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
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제할까요 ? ";

			int k;
			std::cin >> k;

			// k번째 도형의 복제본을 만들어서 v에 추가합니다.
			// 어떻게 구현해야 할까요 ?
			// k번째 도형이 뭘까요 ?

			// 방법 #1. 객체 종류 조사!!
			// => 새로운 도형 추가시 "제어문이 추가" 된다.
			// => OCP 를 만족할수 없는 안좋은 디자인
			if (dynamic_cast<Rect*>(v[k]) != nullptr)
			{
				// Rect 를 새로 만들어서 v[k] 내용으로 복사하고
				// v에 추가
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
			}
		}
	}
}




