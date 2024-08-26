#include <iostream>

class Animal
{
public:
	// non-virtual : static binding �ش޶�� �ǹ�(C++ �⺻ ��å)
	void cry1() { std::cout << "Animal cry1" << std::endl; }

	// virtual : dynamic binding �ش޶�� �ǹ�
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};

class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }
};

int main()
{
	Dog d;	  
	Animal* p = &d;

	p->cry1();	 // static binding, ������ Ÿ������ ȣ��
	p->cry2();   // dynamic binding ���� ��ü ������ ȣ��
}


