// temporary1
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	~Point() { std::cout << "~Point()\n"; }
};

void draw_pixel(int a, int b) {}

void draw_line(const Point& from, const Point& to) {}

int main()
{
	// 1, 2 �� ���� �׸��� �ʹ�. ���� �ڵ�� ?
	
	int x = 1, y = 2;	// 1. ������ ����
	draw_pixel(x, y);	//    �Լ��� ��������!

	draw_pixel(1, 2);   // 2. ���� ���������Ƿ� literal �� ������.
}






