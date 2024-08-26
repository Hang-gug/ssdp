#include <iostream>
// ��� Ŭ������ ����Ҹ��ڷ� �ؾ� �ϴ� ������ �Ʒ� ����
// Base* �� p �� delete �Ҷ� ������ �ʿ� �մϴ�.
// "delete p"

// �׷���, �����Լ��� �߰��ϸ� "�����Լ� ���̺�"�� ������尡 �ְ� �˴ϴ�.

// �� �ٸ� �ذ�å : protected �Ҹ���

class Base
{
protected:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived;
//	delete p;	// error. protected �̹Ƿ�

	// protected �Ҹ��� �ǵ��� ��ó�� "delete p" ��������
	// �Ʒ� ó�� ĳ�����ؼ� delete �϶�� ��!!
	// => �Ҹ��ڰ� ������ �ƴϹǷ� ����ڰ� �����ؼ� ����϶�� �ǵ�!
	delete static_cast<Derived*>(p);
}

// ���ۿ��� "C++ core guideline" �˻���
// => 1��° ��ũ ����