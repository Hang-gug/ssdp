#include <iostream>
#include <vector>
#include <ranges> // C++20

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// C++20 부터 아래와 같은 개념의 "adaptor" 가 30여개 추가되었습니다.
	std::ranges::take_view tv(v, 3);
	std::ranges::reverse_view rv(tv);

	for (auto e : rv) 
	{
		std::cout << e << ", ";
	}
}