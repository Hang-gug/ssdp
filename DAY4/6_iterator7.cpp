#include <iostream>
#include <vector>

struct Point3D
{
	int x = 1;
	int y = 2;
	int x = 3;
};

int main()
{
	Point3D p;

	for (auto e : p)
	{
		std::cout << e << ", ";
	}
}
// ������ �ؼ� �����޼��� Ȯ���ϼ���