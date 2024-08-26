// 2_upcasting1-1.cpp
#include <iostream>
// 7 page

class Animal
{
public:
	int age;

	virtual ~Animal() {} // 가상 소멸자 => 다음 시간에 자세히..!
};


class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog d;

//	Animal* pa = &a;
	Animal* pa = &d;

	// static_cast : 컴파일 시간 캐스팅
	//				 컴파일러에게 허용해달라고 요청하는것
	//				 실제 관련 기계어 코드는 없다. 오버헤드 없음.
	//				 잘못되었는지 조사하지 않고, 무조건 허용
	//				 => 컴파일 시간에는 어느 객체를 가리키는 지 알수 없다
	//				 => 컴파일 시간에 조사할수도 없다.
	
	// 따라서 아래 코드는 항상 성공해서 주소가 반환된다
	Dog* p = static_cast<Dog*>(pa);
	std::cout << pa << std::endl; // ok 
	std::cout << p  << std::endl; // ok. 위와 동일.
								  
//	p->color = 0; // 하지만 이렇게 사용하면 잘못된 코드"undefined"


	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 실제 객체를 조사후 맞는 경우만 허용
	//				  "조사"해야 하므로 오버헤드 있음
	//					단, dynamic_cast 를 사용하려면
	//					"반드시 가상함수가 한개이상" 있는 타입만 가능합니다.
	Dog* p1 = dynamic_cast<Dog*>(pa);

	std::cout << p1 << std::endl; // pa가 Dog 를 가리키지 않았다면 0 반환

	// dynamic_cast 로 조사할수 있지만
	// => dynamic_cast 는 되도록 사용하지 않은것인 좋은 디자인 입니다.
	// => 오후에 자세히 설명
}











