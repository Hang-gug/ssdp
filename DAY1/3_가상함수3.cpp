// 가상함수 문법 정리
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// #1. 가상함수 override 시에는 "virtual" 을 붙여도 되고 생략해도 됩니다.
	// virtual void foo() {}
	// void foo() {}	// 위 코드와 동일, 하지만 가독성이 나쁨.

	// #2. 가상함수 override 시에 실수(오타)가 있어도 에러 아닙니다.
	// => 컴파일러는 새로운 함수를 추가한것으로 생각하게 됩니다.
	virtual void fooo() {}
	virtual void goo(double){}

	// #3. 위 문제를 해결하기 위해서 c++11 에서 "override" 키워드 추가
	virtual void fooo()  override {}		// error
	virtual void goo(double) override {}	// error


};

int main()
{
}





