// 15page ~ 
#include <iostream>
#include <vector>

// #1. 모든 도형을 타입화 하면 편리합니다.

class Rect
{
//	int x, y, w, h, 생성자 등은 생략
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle
{
public:
	void draw() { std::cout << "draw Circle\n"; }
};

int main()
{
	std::vector<Rect*> v; // Rect 객체만 보관 가능
}

