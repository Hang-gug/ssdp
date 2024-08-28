#include <iostream>
#include <list>
#include <vector>
#include <deque>

// �ذ�å #2. ����� �ƴ� ����

template<typename T>
class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); };

	void pop() { c.pop_back(); };
	T& top()   { return c.back(); };
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(0); // error. push_front ��� �Լ��� ����.
}

// private ��Ӱ� ������ ���
// => list �� ����� stack ���ο����� ����ϰڴٴ� ��
// => ��������

// private ��� : ��� Ŭ������ �����Լ��� override �Ҽ� �ִ� �ɷ��� �ִ�.
// ����         : ��� Ŭ������ �����Լ��� override �Ҽ� ����.

// �� ����������
// list �� �����Լ��� ����, override ���ϵ� �����Ƿ� ������ ����.

