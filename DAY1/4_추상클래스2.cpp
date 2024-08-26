//1_추상클래스2.cpp
#include <iostream>


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
	void use_camera(Camera* p)   { p->take(); }
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

// OCP 규칙

// 기능 확장에는 열려 있고 (Open, 새로운 클래스/모듈이 추가되어도)
// 코드 수정에는 닫혀 있어야(Close, 기존 코드는 수정되지 않도록 )
// 만들어야 한다는 이론(Principle)

// Open Close Principle ( 개방 폐쇄의 법칙 )

// 객체지향 S/W 설계의 5개 원칙 : SOLID

// SRP
// OCP
// LSP
// ISP
// DIP








