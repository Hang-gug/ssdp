// 구현 계층
// => 모든 Point 기능은 이 클래스에 구현 하세요
// => 최종 사용자는 이 클래스를 사용하지 않습니다.
// => 간접층을 사용하게 해야 합니다.
// PointImpl.h
class PointImpl
{
	int x, y;

	int debug;

public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 

//=====================================
// 간접층 - bridge
// => 최종 사용자가 사용하는 클래스
// => 실제 기능은 "구현층(POINTIMPL)"에 의존합니다.
// Point.h

class PointImpl; // 전방선언만 있으면 
				 // PointImpl* 는 선언 가능
class Point
{
	PointImpl* impl;
public:
	Point();
	void print();
};

// Point.cpp
#include "Point.h"
#include "PointImpl.h"

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


