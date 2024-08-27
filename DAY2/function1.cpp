// function1.cpp
#include <iostream>
#include <functional>	// std::bind() �� ������� �ֽ��ϴ�.
using namespace std::placeholders; // _1, _2, _3 ...

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // 4�� �Լ�

	// std::bind : ���ڸ� ������ ���ο� �Լ��� ����� ����
	// ����     : std::bind(M���Լ�, M�� ����)

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // 4�� �Լ� => 0 ���Լ��� �����
	f1();	// foo(1,2,3,4)


	auto f2 = std::bind(&foo, 5, _1, 4, _2); // 4�� => 2�� �Լ� �����

	f2(7, 8);	// 5, 7, 4, 8


	auto f3 = std::bind(&foo, ? ? ? ? );
	f3(9, 4, 6); // 4, 9, 3, 6    �������� �� ? ä�켼��
}