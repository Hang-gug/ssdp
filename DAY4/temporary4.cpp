#include <iostream>

class Counter
{
public:
	int cnt = 0;

	Counter increment()
	{
		++cnt;
		return *this;
	}
};

int main()
{
	Counter c;
	c.increment();
	c.increment();
	std::cout << c.cnt << std::endl;
}