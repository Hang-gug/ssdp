#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};


//----------------------------------
// 1. 모든 반복자가 지켜야 하는 규칙을 "문서" 로 약속합니다.
// 2. 다음으로 이동하고 요소 접근은 "raw pointer" 와 동일하게 사용하도록!!
// => operator++, operator* 연산자 재정의 

template<typename T>
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p) : current(p) {}


	inline slist_iterator& operator++() 
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }
};


template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // 동적할당이 아닌 임시객체(값)로 반환
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.begin();

	std::cout << *it << std::endl; // 40
	++it;
		
	std::cout << *it << std::endl;	// 30
}




// C++ 언어 관점에서 위 코드의 단점

// #1. s.iterator() 가 반환한 반복자는 "new" 로 생성했다
// => delete 해야 하지 않을까 ?


// #2. 다음으로 이동하는 함수 "next" 가 가상함수 입니다.
// => 오버헤드 있습니다.
// => 루프안에서 호출될수 있는 함수 이므로 성능이 중요


// #3. Raw Array 를 순환할때는 "raw pointer" 사용해서 ++로 이동합니다.
// => 결국 이동 방식이 다르게 됩니다.
// => 모든 "컬렉션을 동일한 방법" 에 위배 됩니다.