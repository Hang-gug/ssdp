#include <iostream>

class Base
{
public:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d; // ok. 아무 문제 없음. 

//	Derived* p = new Derived; // 생성자 호출
//	delete p;				  // 이순간 소멸자 호출.  아무 문제 없음. 


	// 아래 코드가 이 예제의 핵심 입니다.
	// => 실행해서 결과 확인해 보세요
	Base* p = new Derived;
	delete p;				

	// 1. 소멸자 호출도 결국 함수 호출입니다.
	// 2. 소멸자가 "virtual" 이면 : dynamic binding
	//		   "non-virtual"     : static binding
	// 
	// 3. 컴파일러는 "p가 가리키는 곳의 타입은 알수 없고"
	//    "p자체의 타입(Base*)" 만 알수 있습니다

	// 4. 따라서, 컴파일 할때
	// => Base의 소멸자가 "virtual 인지 아닌지"를 조사후 binding 결정

}	
