// function1.cpp
#include <iostream>
#include <functional>	// std::bind() �� ������� �ֽ��ϴ�.
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
	// C ����� �Լ� �����ʹ� �������� �����մϴ�.
	void(*f)(int);

	f = &goo; // ok
	f = &hoo; // error. ������ ������ �ٸ���.

}





