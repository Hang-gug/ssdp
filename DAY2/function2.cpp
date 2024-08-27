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
//	void(*f)(int);
//	f = &goo; // ok
//	f = &hoo; // error. ������ ������ �ٸ���.

	// std::function �� �Լ� �����Ϳ� ������ Ŭ���� �Դϴ�
	// �������� �����ϴ�.

	std::function<void(int)> f;

	f = &goo;

	f(10); // goo(10)

//	f = &hoo; // error

	// �ٽ� : std::function ���� bind ����� ������ �ֽ��ϴ�.
	// => ��, ������ ������ �ٸ� �Լ����
	// => std::bind �� ���ڰ� �Ѱ��� ���·� ����� ������ �˴ϴ�.
	f = std::bind(&hoo, 5, _1);

	f(10); // hoo(5, 10);

	
	f = std::bind(&foo, ? );
	f(5); // 7, 4, 5, 8   ������ ? ä�� ������.

}





