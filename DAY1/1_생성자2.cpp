#include <iostream>

class Base
{
public:
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 아래 코드가 왜 에러인지 생각해 보세요
	// => 핵심 1. 컴파일러가 오른쪽 주석처럼 변경합니다
	// => 핵심 2. 그런데, Base 클래스에는 디폴트 생성자가 없습니다
	Derived() { }		// Derived()      : Base() {}
	Derived(int a) { }  // Derived(int a) : Base() { }
};

int main()
{

}
