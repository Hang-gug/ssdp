// protected 생성자 의도
// => 자신의 객체는 만들수 없지만( 추상적인 개념을 나타내는 타입(클래스))
// => 파생 클래스의 객체는 만들수 있게(구체적(concrete) 개념을 나타내는 타입)

class Animal
{
// public:	// A, B 모두 에러 아님.
// private:	// A, B 모두 에러!!. 객체 생성 안됨. 생성자를 호출할수 없으므로

protected:	// 핵심
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// A. error. 
	Dog    d;	// B. ok. 
}



