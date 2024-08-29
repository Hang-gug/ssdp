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

	~Counter() { std::cout << "~Counter()\n"; }
};

int main()
{
	Counter c;
	std::cout << "----------------\n";
	c.increment().increment().increment();
	std::cout << "----------------\n";

	std::cout << c.cnt << std::endl;

	
}