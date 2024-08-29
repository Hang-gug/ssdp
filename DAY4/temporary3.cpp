// temporary1
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	~Point() { std::cout << "~Point()\n"; }
};

Point foo()
{
	Point pt(1, 2);

	return pt;
}

int main()
{
	Point ret = foo();

}






