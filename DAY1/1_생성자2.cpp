#include <iostream>

class Base
{
public:
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// �Ʒ� �ڵ尡 �� �������� ������ ������
	// => �ٽ� 1. �����Ϸ��� ������ �ּ�ó�� �����մϴ�
	// => �ٽ� 2. �׷���, Base Ŭ�������� ����Ʈ �����ڰ� �����ϴ�
	Derived() { }		// Derived()      : Base() {}
	Derived(int a) { }  // Derived(int a) : Base() { }
};

int main()
{

}
