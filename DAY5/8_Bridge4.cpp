// ���� ����
// => ��� Point ����� �� Ŭ������ ���� �ϼ���
// => ���� ����ڴ� �� Ŭ������ ������� �ʽ��ϴ�.
// => �������� ����ϰ� �ؾ� �մϴ�.
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
// ������ - bridge
// => ���� ����ڰ� ����ϴ� Ŭ����
// => ���� ����� "������(POINTIMPL)"�� �����մϴ�.
// Point.h

class PointImpl; // ���漱�� ������ 
				 // PointImpl* �� ���� ����
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


