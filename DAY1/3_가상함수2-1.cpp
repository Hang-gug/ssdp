#include <iostream>
// 기반 클래스를 가상소멸자로 해야 하는 이유는 아래 같이
// Base* 인 p 를 delete 할때 때문에 필요 합니다.
// "delete p"

// 그런데, 가상함수를 추가하면 "가상함수 테이블"의 오버헤드가 있게 됩니다.

// 또 다른 해결책 : protected 소멸자

class Base
{
protected:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived;
//	delete p;	// error. protected 이므로

	// protected 소멸자 의도는 위처럼 "delete p" 하지말고
	// 아래 처럼 캐스팅해서 delete 하라는 것!!
	// => 소멸자가 가상이 아니므로 사용자가 주의해서 사용하라는 의도!
	delete static_cast<Derived*>(p);
}

// 구글에서 "C++ core guideline" 검색후
// => 1번째 링크 선택