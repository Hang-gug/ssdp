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
					// �̸��� �����Ƿ� �����ٿ����� ��밡��
					// ���� : {} ���� ���� �ı�

	Point (1, 1);	// unnamed object
					// ���� : ������ ��, �̸��� �����Ƿ� ���� ���忡��
					//		  ������.
					// "temporary  object(�ӽð�ü)"

	std::cout << "------------\n";
}






