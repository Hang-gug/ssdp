#include <iostream>
#include <list>
#include <vector>
#include <deque>

// Adapter �� Policy Base Design �� ����

template<typename T, typename C = std::deque<T>> 
class stack
{
//	C* c; // �̷��� �ߴٸ� "object adapter"
	C c; // ���� STL �� �̷��� �Ǿ� �ֽ��ϴ�. "Ŭ���� adapater" !!

public:
	inline void push(const T& e) { c.push_back(e); };
	inline void pop() { c.pop_back(); };
	inline T& top() { return c.back(); };
};

#include <stack> // C++ ǥ�� stack ���
				// �̾��� �ڵ尡 ���� �ִ� �ڵ�� ���� ���� �մϴ�.
				// ���� "stack adapter" ��� �θ��ϴ�.
				// �Ʒ� �ڵ忡�� "stack" ��� "std::stack" ���� �����ϸ�˴ϴ�.
				// cppreference.com ���� "container library" ã�ƺ�����
		
int main()
{
	stack<int, std::list<int>>  s1; // list �� stack ó�� ����ϰڴٴ� �ǹ�
	stack<int, std::vector<int>> s2; // vector �� stack ó�� ����ϰڴٴ� �ǹ�

	stack<int> s; // std::deque �� ���� �ڷᱸ���� ���
	s.push(10);

}

