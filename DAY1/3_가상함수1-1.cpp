#include <iostream>

class Animal
{
public:
	// non-virtual : static binding 해달라는 의미(C++ 기본 정책)
	void cry1() { std::cout << "Animal cry1" << std::endl; }

	// virtual : dynamic binding 해달라는 의미
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }
};

int main()
{
	Dog d;	  
	Animal* p = &d;

	p->cry1();	 // static binding, 포인터 타입으로 호출
	p->cry2();   // dynamic binding 실제 객체 조사후 호출
}


