// 2_upcasting1-1.cpp

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
	//				 잘못되었는지 조사하지 않고, 무조건 허용
	Dog* p = static_cast<Dog*>(pa);
}











