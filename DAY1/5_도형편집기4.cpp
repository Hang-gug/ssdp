#include <iostream>
#include <vector>

// #1. 리팩토링(Refactoring) 에서 사용되는 유명한 용어 입니다.
//     의미를 생각해 보세요

//     "Replace Conditional With Polymorphism"
//      제어문(if, switch) 를 다형성(가상함수)로 변경해라
//		2-1.cpp 를 2-2.cpp 로 변경해라. 


// #2. 디자인 패턴이란 ?
// => 1995년에 발간된 책의 제목, 4명의 저자
// => "GoF's design pattern" 구글 검색후 이미지 보기
// => 당시 유행하던 코딩 기법에 "이름을 부여" 한것
// => 23개의 이름 부여
// => 이미 존재하던 기법을 "훔쳤다"는 의므로 "Gangs Of Four" 의 약자로
//    "GOF's design pattern"


// #3. prototype
// => 객체의 복사본을 만들때 사용하는 패턴
// => clone() 가상함수 
// => 4일차에 제대로된 예제 등장.

// #4. "현재 프로그램에 Undo/Redo" 를 넣으려면 ??
// => 이미 널리 알려진 "Undo/Redo" 기술은 존재 합니다.
// => 따라서, 어떻게 하면 될까 ? 고민하지 말고..
// => "Command" 패턴을 배우면 됩니다.
// => 4일차에 구현!!


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




