#include <iostream>

// call by value    : ���纻 ����
// call by reference : ���纻 ���� ����

// return by value    : ���纻 ���� (�ӽð�ü )
// return by reference : ���纻 ���� ����

// ��, ���������� ���� ���� ��ȯ�ϸ�  �ȵ˴ϴ�.

Point& foo()
{
	Point pt(2, 3);
	return pt; // ���� ������ ���� ������
				// ������ ��� ���ɴϴ�.
}

// �Լ� ȣ�� ����Ǿ �ı����� ���� �͸� ������ȯ ����
// => *this, ��������, static ��������, ��� ����Ÿ��.. 

class Counter
{
public:
	int cnt = 0;

//	Counter increment()
	Counter& increment()
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