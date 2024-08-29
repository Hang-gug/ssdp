// temporary1
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	~Point() { std::cout << "~Point()\n"; }
};

int main()
{
//	Point pt(1, 1);	// named object 
					// 이름이 있으므로 다음줄에서도 사용가능
					// 수명 : {} 벗어 날때 파괴

	Point (1, 1);	// unnamed object
					// 수명 : 문장의 끝, 이름이 없으므로 다음 문장에서
					//		  사용못함.
					// "temporary  object(임시객체)"

	std::cout << "------------\n";
}






