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

// 위코드가 파일 구조를 Bridge 패턴으로 적용한것

// C++에서는 "PIMPL - Pointer To IMPlementation"
// 이라는 용어로 부릅니다.


// 장점
// 1. 컴파일 속도 향상(컴파일 시간 방화벽)

// 2. 완벽한 정보 은닉
//	  (구현의 헤더를 노출할 필요 없다.
//     추상의 헤더만 전달하면 된다.)

