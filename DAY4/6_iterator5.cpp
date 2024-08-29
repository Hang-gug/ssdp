#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};


//----------------------------------
// 1. ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ�� "����" �� ����մϴ�.
// 2. �������� �̵��ϰ� ��� ������ "raw pointer" �� �����ϰ� ����ϵ���!!
// => operator++, operator* ������ ������ 

template<typename T>
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p) : current(p) {}

	// ���� ��ӵ� �Լ� ����
	slist_iterator& operator++() 
	{
		current = current->next;
		return *this;
	}

	T& operator*() { return currrent->data; }
};



// �����̳�(collection) ������ iterator �� ������ �־�� �մϴ�.
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




// C++ ��� �������� �� �ڵ��� ����

// #1. s.iterator() �� ��ȯ�� �ݺ��ڴ� "new" �� �����ߴ�
// => delete �ؾ� ���� ������ ?


// #2. �������� �̵��ϴ� �Լ� "next" �� �����Լ� �Դϴ�.
// => ������� �ֽ��ϴ�.
// => �����ȿ��� ȣ��ɼ� �ִ� �Լ� �̹Ƿ� ������ �߿�


// #3. Raw Array �� ��ȯ�Ҷ��� "raw pointer" ����ؼ� ++�� �̵��մϴ�.
// => �ᱹ �̵� ����� �ٸ��� �˴ϴ�.
// => ��� "�÷����� ������ ���" �� ���� �˴ϴ�.