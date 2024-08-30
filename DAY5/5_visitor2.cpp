#include <iostream>
#include <list>
#include <vector>

class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

template<typename T> class MyList : public std::list<T>
{
public:

	// ������ ��� ����(C++11 �߰��� ����)
	// => �����ڸ� ����� �޶�.
	// => �Ʒ� ���� ������, MyList �����, std::list �� �����ϰ� ��ü ��������
	using std::list<T>::list; // using Ÿ���̸�::�������̸�

	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this) //  *this �� ������ ������
			visitor->visit(e);

	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor tv;
	s.accept(&tv);   
}

// �湮�� ����
// => ���հ�ü�� ���Ÿ� ���ο��� �ϴ� ���� �ƴ϶�
// => ���������� ��� ��Ҹ� ���� �ϴ� ��.

// => �ܺο����� "���길 ����" �ؼ� "���հ�ü" �� ����!




