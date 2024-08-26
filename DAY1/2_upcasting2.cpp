// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// upcasting 활용 #1. 
	std::vector<Dog*>    v1; // Dog 객체만 보관하겠다는 의도.
	std::vector<Animal*> v2; // 모든 동물 객체를 보관하겠다는 의도.
							 // 동종(동일 기반 클래스의 가진 타입)을 
							 //	보관하는 컨테이너
}
