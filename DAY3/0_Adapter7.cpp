#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter 와 Policy Base Design 의 결합

template<typename T, typename C = std::deque<T>> 
class stack
{
//	C* c; // 이렇게 했다면 "object adapter"
	C c; // 실제 STL 은 이렇게 되어 있습니다. "클래스 adapater" !!

public:
	inline void push(const T& e) { c.push_back(e); };
	inline void pop() { c.pop_back(); };
	inline T& top() { return c.back(); };
};

#include <stack> // C++ 표준 stack 헤더
				// 이안의 코드가 위에 있는 코드와 거의 유사 합니다.
				// 흔히 "stack adapter" 라고 부릅니다.
				// 아래 코드에서 "stack" 대신 "std::stack" 으로 변경하면됩니다.
				// cppreference.com 에서 "container library" 찾아보세요
		
int main()
{
	stack<int, std::list<int>>  s1; // list 를 stack 처럼 사용하겠다는 의미
	stack<int, std::vector<int>> s2; // vector 를 stack 처럼 사용하겠다는 의미

	stack<int> s; // std::deque 를 내부 자료구조로 사용
	s.push(10);

}

