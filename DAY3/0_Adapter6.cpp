#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 해결책 #2. 상속이 아닌 포함

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

	s.push_front(0); // error. push_front 멤버 함수는 없다.
}

// private 상속과 포함은 모두
// => list 의 기능을 stack 내부에서만 사용하겠다는 것
// => 차이점은

// private 상속 : 기반 클래스의 가상함수를 override 할수 있는 능력이 있다.
// 포함         : 기반 클래스의 가상함수를 override 할수 없다.

// 위 예제에서는
// list 는 가상함수가 없고, override 할일도 없으므로 포함이 좋다.

