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

	
	// 아래 함수는 "virtual" 로 할까요 ? "non-virtual" 로 할까요 ?
	// => 파생 클래스가 override 할 이유 없습니다. - non-virtual
	void set_color(int c) { color = c; }

	// 면적 구하는 함수
	// => 모든 도형은 면적 구하는 방법이 다릅니다.
	// => 파생 클래스가 override 하게 됩니다. - virtual 
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
				s->draw();	// 다형성(Polymorphism)
							// => 동일한 표현식이 상황(실제객체종류)에 따라
							//    다르게 동작하는 것

			// 객체지향 언어의 3가지 특징 : 캡슐화, 상속, 다형성

			// 장점 : 새로운 도형이 추가되어도 "s->draw()" 는 수정되지 않습니다.
			//		  OCP 를 만족하는 아주 좋은 코드 입니다.
		}
	}
}




