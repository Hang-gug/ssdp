#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter 와 Policy Base Design 의 결합

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
	stack<int, std::list<int>>  s1; // list 를 stack 처럼 사용하겠다는 의미
	stack<int, std::vector<int>> s2; // vector 를 stack 처럼 사용하겠다는 의미

	stack<int> s; // std::deque 를 내부 자료구조로 사용
	s.push(10);

}

