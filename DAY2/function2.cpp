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
//	void(*f)(int);
//	f = &goo; // ok
//	f = &hoo; // error. 인자의 갯수가 다르다.

	// std::function 은 함수 포인터와 유사한 클래스 입니다
	// 유연성이 좋습니다.

	std::function<void(int)> f;

	f = &goo;

	f(10); // goo(10)

//	f = &hoo; // error

	// 핵심 : std::function 에는 bind 결과를 담을수 있습니다.
	// => 즉, 인자의 갯수가 다른 함수라면
	// => std::bind 로 인자가 한개인 형태로 만들어 담으면 됩니다.
	f = std::bind(&hoo, 5, _1);

	f(10); // hoo(5, 10);

	
	f = std::bind(&foo, ? );
	f(5); // 7, 4, 5, 8   나오게 ? 채워 보세요.

}





