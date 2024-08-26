#include <iostream>


// 추상 클래스 : 지켜야하는 규칙(순수 가상함수) 외에 다른 멤버도 있는 경우
// 인터 페이스 : 지켜야하는 규칙 만 있는 경우. 
// 
// java, C# : interface, abstract 라는 별도 키워드 존재
// C++      : 키워드 없음, 순수 가상함수 문법만 존재

// #1. 카메라와 카메라 사용자가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생 되어야 한다." 라고 표현하지 말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다." 라고 표현 합니다.

#define interface struct

//class ICamera		// class  : 접근 지정자 생략시 private
struct ICamera	// struct : 접근 지정자 생략시 public
//interface ICamera	// 90년대 유행했는 방식	
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // 인터페이스도 결국은 기반 클래스!!!
						  // 따라서, 소멸자를 가상함수로!!
};

// 강한 결합(tightly coupling)
// => 하나의 클래스가 다른 클래스 사용시
// => 클래스 이름을 직접 사용하는 것
// => 경직된, 교체 불가능한 디자인

// 약한 결합(loosely coupling)
// => 하나의 클래스가 다른 클래스 사용시
// => 규칙을 담은 인터페이스를 통해서 사용하는 것
// => 유연한, 교체 가능한 디자인





// #2. 실제 카메라가 없어도, 사용하는 코드를 작성할수 있습니다.
// => 규칙대로만 사용하면 됩니다.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// #3. 모든 카메라는 "규칙"을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

	UHDCamera uhc;
	p.use_camera(&uhc); // ok. 나중에 추가된 새로운 카메라객체지만
						// People 을 수정하지 않고도 사용가능
						// OCP 만족!!
}









