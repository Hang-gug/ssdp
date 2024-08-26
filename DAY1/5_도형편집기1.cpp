// 15page ~ 
#include <iostream>
#include <vector>

// #1. 모든 도형을 타입화 하면 편리합니다.

// #2. 모든 도형은 "색상" 등의 공통의 특징이 있다.
//     기반 클래스로 제공.
//	   기반 클래스가 있다면 모든 도형을 하나의 컨테이너에 보관 가능

class Shape
{
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape 
{
//	int x, y, w, h, 생성자 등은 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Rect*> v; // Rect 객체만 보관 가능
}

