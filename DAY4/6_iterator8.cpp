#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T& rgn;
	int cnt;
public:
	take_view(T& r, int c) : rgn(r), cnt(c) {}

	auto begin() { return rgn.begin(); }
	auto end()   { return rgn.begin() + cnt; } // <== ÇÙ½É
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	take_view tv(v, 3);

	//for (auto e : v)
	for (auto e : tv)
	{
		std::cout << e << ", ";
	}
}