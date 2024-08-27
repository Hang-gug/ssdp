// function1.cpp
#include <iostream>
#include <functional>

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // 4항 함수

	// std::bind : 인자를 고정한 새로운 함수를 만드는 도구
	// 사용법     : std::bind(M항함수, M개 인자)

	auto f1 = std::bind(&foo, 1, 2, 3, 4);
	f1();
}