#include <iostream>
#include <vector>

// #1. 리팩토링(Refactoring) 에서 사용되는 유명한 용어 입니다.
//     의미를 생각해 보세요

//     "Replace Conditional With Polymorphism"
//      제어문(if, switch) 를 다형성(가상함수)로 변경해라
//		2-1.cpp 를 2-2.cpp 로 변경해라. 



class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }


	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용됩니다.
	virtual Shape* clone()
	{
//		Shape* s = new Shape;   // 새로운 도형을 만들어서
//		s->color = this->color; // 나와 동일하게 설정해서
//		return s;				// 반환 합니다.

		// 그런데, C++에서는 복사 생성자를 사용하면 됩니다.
		return new Shape(*this);
	}
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

			// k 번째 도형의 종류를 알필요 없다.
			// => "Tell, Don't ask" 규칙
			v.push_back(v[k]->clone()); // 다형성!!!
							// 새로운 도형 클래스가 추가 되어도
							// 이 코드는 수정될 필요 없다.
							// 단, 새로운 도형 클래스설계자는
							// clone() 을 제공해야 한다.

		}
	}
}




