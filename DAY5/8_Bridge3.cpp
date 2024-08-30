// Point.h
class Point
{
	int x, y;

	int debug; // 나중에 추가(변경)된소스

public:
	void print();
};

// Point.cpp
#include "Point.h"

void Point::print() { } // 구현 생략



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


