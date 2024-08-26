// 2_upcasting1-1.cpp
#include <iostream>
// 7 page

class Animal
{
public:
	int age;
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

	Animal* pa = &a;

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
								  
	p->color = 0; // 하지만 이렇게 사용하면 잘못된 코드"undefined"
}











