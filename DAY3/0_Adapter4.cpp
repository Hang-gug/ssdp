#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter

// 1. STL 에는 list 가 있습니다.
// 2. 그런데, 사용자가 stack 을 요구합니다.(물론 stack 도 있지만 없다고 가정)

// list 의 인터페이스(함수이름)을 변경해서 stack 처럼 보이게 해봅시다.

template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); };

	void pop() { std::list<T>::pop_back(); };

	T&   top() { return std::list<T>::back(); };
};


int main()
{
	stack<int> s;
	s.push(10);
}
