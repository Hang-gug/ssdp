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

	Dog* p1 = &d;		// ok
	int* p2 = &d;		// error

	// 핵심 #1. 기반 클래스 포인터로 파생 클래스 객체를 가리킬수 있다.
	// => upcasting 이라고 합니다.
	// => 가능한 이유는 "메모리 그림"을 생각해 보세요
	
	Animal* p3 = &d;	// ok. 

	// 핵심 #2. 컴파일러는 "p3"가 가리키는 곳에 실제 어떤 종류의 객체가 
	// 있는지 알수 없습니다.
	// => 컴파일러가 아는 것은 "p3" 자체의 타입이 "Animal*" 라는 것만 알수있다
	// => 아래 코드를 생각해 보세요
	// if (사용자 입력 == 1) p3 = &a; 

	// 핵심 #3. static type check

	p3->age = 0; // ok
	p3->color = 0; // ??



}











