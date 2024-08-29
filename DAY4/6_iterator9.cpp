#include <iostream>
#include <vector>
#include <ranges> // C++20

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// C++20 ���� �Ʒ��� ���� ������ "adaptor" �� 30���� �߰��Ǿ����ϴ�.
	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv);

	for (auto e : rv) 
	{
		std::cout << e << ", ";
	}
}