// function1.cpp
#include <iostream>
#include <functional>	// std::bind() 가 이헤더에 있습니다.
using namespace std::placeholders; // _1, _2, _3 ...

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

class Sample
{
public:
	void goo(int a, int b) {}
};

void goo(int a)        {}
void hoo(int a, int b) {}

int main()
{
	// C 언어의 함수 포인터는 유연성이 부족합니다.
	void(*f)(int);

	f = &goo; // ok
	f = &hoo; // error. 인자의 갯수가 다르다.

}





