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
//	Point pt(1, 2);
//	return pt;	// 1. pt를 복사해서 리턴용 임시객체 만ㄴ들고
				// 2. pt 는 파괴
				// 3. 임시객체를 반환

	// 리턴용으로만 사용하는 객체는 
	// "만들고 리턴하지 말고"
	// "만들면서 리턴해라" - RVO ( return value optimization )

	return Point(1, 2);// 리턴용 임시객체만 만들라는 의도!
}

int main()
{
	Point ret = foo();

}






