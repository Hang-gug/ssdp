#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// function override : 기반 클래스 멤버 함수를 파생클래스가 다시 만드는것
	void cry() { std::cout << "Dog cry" << std::endl; } 
};

int main()
{
	Animal a; a.cry(); // "Animal cry"
	Dog d;	  d.cry(); // "Dog cry"

	Animal* p = &d; 

	// 실제   객체 : Dog
	// 포인터 타입 : Animal*

	p->cry();	// C++, C# : Animal Cry
				// Java, Python, Swift, kotlin 등 대부분의 언어 : Dog Cry
}

// p->cry() 를 실제 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(function binding )

// 1. static binding :


// 2. dynamic binding : 

