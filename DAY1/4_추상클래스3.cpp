#include <iostream>


// #1. 카메라와 카메라 사용자가 지켜야 하는 규칙을 먼저 설계 합니다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생 되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};

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









