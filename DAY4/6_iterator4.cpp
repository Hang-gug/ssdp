#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 모든 반복자가 지켜야 하는 규칙
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// 모든 컨테이너(컬렉션)가 지켜야 하는 규칙
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//----------------------------------
// 싱글리스트의 반복자 코드
// => 1번째 요소를 가리키는 포인터를 가지고 있다가
// => 약속된 함수에서 이동할수 있으면 됩니다.
template<typename T> 
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p) : current(p) {}

	// 이제 약속된 함수 구현
	T& next() override
	{
		T& ret = current->data;

		current = current->next;

		return ret;
	}

	bool hasNext() override { return current != nullptr; }
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
}
