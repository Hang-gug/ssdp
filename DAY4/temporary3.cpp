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
//	return pt;	// 1. pt�� �����ؼ� ���Ͽ� �ӽð�ü �������
				// 2. pt �� �ı�
				// 3. �ӽð�ü�� ��ȯ

	// ���Ͽ����θ� ����ϴ� ��ü�� 
	// "����� �������� ����"
	// "����鼭 �����ض�" - RVO ( return value optimization )

	return Point(1, 2);// ���Ͽ� �ӽð�ü�� ������ �ǵ�!
}

int main()
{
	Point ret = foo();

}






