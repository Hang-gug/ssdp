#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter �� Policy Base Design �� ����

template<typename T, typename C = std::deque<T>> 
class stack
{
	C c;
public:
	void push(const T& e) { c.push_back(e); };

	void pop() { c.pop_back(); };
	T& top() { return c.back(); };
};

int main()
{
	stack<int, std::list<int>>  s1; // list �� stack ó�� ����ϰڴٴ� �ǹ�
	stack<int, std::vector<int>> s2; // vector �� stack ó�� ����ϰڴٴ� �ǹ�

	stack<int> s; // std::deque �� ���� �ڷᱸ���� ���
	s.push(10);

}

