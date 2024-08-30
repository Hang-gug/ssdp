#include <iostream>

// 핵심 : 멤버 함수의 호출원리를 이해해 봅시다.

// 핵심 #1. 멤버 함수는 인자로 "this" 가 추가됩니다. "this call" 이라고 합니다.

// 핵심 #2. static 멤버 함수는 "this"가 추가되지 않습니다. 중요!!


class Point
{
	int x = 0;
	int y = 0;
public:
	void set(int a, int b) // void set( Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;
	}						// }
	
	static void foo(int a)  // void foo(int a)
	{
		x = a;				// this->x = a; 로 변경할수 없습니다 error
							// 그래서 static 멤버 함수에서는 멤버 데이타 접근안됩니다.
	}
};
int main()
{
	Point::foo(10);

	Point p1;
	Point p2;

	p1.set(10, 20); // set(&p1, 10, 20) 으로 변경됩니다.
	p2.set(10, 20); // set(&p2, 10, 20)
}


