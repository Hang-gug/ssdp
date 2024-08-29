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
	// 1, 2 에 점을 그리고 싶다. 좋은 코드는 ?
	
	int x = 1, y = 2;	// 1. 변수를 만들어서
	draw_pixel(x, y);	//    함수에 전달하자!

	draw_pixel(1, 2);   // 2. 값이 정해졌으므로 literal 을 보내자.
}






