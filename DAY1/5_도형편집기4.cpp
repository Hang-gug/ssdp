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




