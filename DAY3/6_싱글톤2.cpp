#include <iostream>


// ���� �Ѱ��� ��ü�� ��� �޸𸮿� ��� ������ΰ� ?

// #1. static �������� - mayer's singleton
// => get_instance()�� ���� ȣ�� �ɶ� Cursor ������ ȣ�� - ����(lazy)�ʱ�ȭ
// => get_instance()�� �ѹ��� ȣ������ ������ Cursor ������ ȣ�� �ȵ�
// => thread - safe !!

// #2. static ��� ����Ÿ
// => main ���� ���� Cursor ������ ȣ�� - �̸�(early)�ʱ�ȭ
// => �����带 ����� ���̹Ƿ� thread - safe
// =>  get_instance()�� �ѹ��� ȣ������ �ʾƵ� Cursor ������ ȣ���. 

// #3. heap 

class Cursor
{
private:
	Cursor() { std::cout << "Cursor()\n"; }

	Cursor(const Cursor&) = delete; 
	Cursor& operator=(const Cursor&) = delete;

//	Cursor instance; // error
	static Cursor instance; // ok

public:
	static Cursor& get_instance()
	{
//		static Cursor instance; 
		return instance;
	}
};
Cursor Cursor::instance; // C++ ������ static ��� ����Ÿ�� �ܺ� ���� �ʿ�

int main()
{
	std::cout << "main\n";

//	Cursor& c1 = Cursor::get_instance();
}














