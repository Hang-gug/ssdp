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

	// 이제 약속된 함수 구현
	slist_iterator& operator++() 
	{
		current = current->next;
		return *this;
	}

	T& operator*() { return currrent->data; }
};



// 컨테이너(collection) 에서는 iterator 를 꺼낼수 있어야 합니다.
template<typename T> class slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}

	delete it;
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