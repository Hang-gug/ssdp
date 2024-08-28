#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #1. private 상속

// private 상속의 의미
// => 구현은 물려 받지만(파생 클래스가 내부적으로 사용)
// => 인터페이스는 물려 받지 않겠다(기반 클래스 함수를 외부 노출하지 않겠다)


template<typename T> 
//class stack : public std::list<T>
class stack   : private std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e); };

	void pop() { std::list<T>::pop_back(); };
	T& top() { return std::list<T>::back(); };
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(0); // error. private 상속이므로 private 멤버 함수!!!
}


