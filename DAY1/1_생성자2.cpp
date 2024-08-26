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
//	Derived() { }		// Derived()      : Base() {}
//	Derived(int a) { }  // Derived(int a) : Base() { }

	// 해결책 
	// => 기반 클래스에 디폴트 생성자가 없다면
	// => 파생 클래스에서 반드시 기반 클래스의 다른 생성자를 명시적으로
	//    호출해야 합니다.
	Derived()     : Base(0) { }		
	Derived(int a): Base(a) { }  


};

int main()
{

}
