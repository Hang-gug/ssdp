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
	void use_camera(? c) { c->take(); }
};
















class Camera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);


	HDCamera hc;
	p.use_camera(&hc); // ??
}









