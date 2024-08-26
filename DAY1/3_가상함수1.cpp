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

// 1. static binding : 컴파일러가 컴파일 시간에 함수 호출을 결정
//						컴파일러는 p가 가리키는 실제 객체의 종류는
//						알수 없다.
//						단지, p가 Animal* 라는 것만 알수 있다.
//						"Animal Cry" 호출
// 논리적이지 않지만, 빠르다!
// C++/C# 의 기본 바인딩 정책

// 2. dynamic binding : 컴파일 시간에는 "p가 가리키는 객체를 조사"하는
//						기계어 코드를 생성하고
//						실행할때 메모리를 조사해서 
//						실제 객체가 어떤 타입인지에 따라 호출 결정
//						객체가 "Dog" 타입이면
//						"Dog Cry" 호출
// 논리적이지만, 느리다.
// java, python, swift, kotlin 등의 대부분의 객체지향 언어 방식
// C++/C# 의 가상함수

// 결국
// java등은 "위 내용을 몰라도 됩니다." 그냥, Dog 호출
// => 쉽습니다.

// C++ : java 보다 어렵습니다.
// 위 내용을 알고, 적절히 사용해야 합니다.

