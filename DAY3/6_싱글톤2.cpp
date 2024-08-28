#include <iostream>


// ���� �Ѱ��� ��ü�� ��� �޸𸮿� ��� ������ΰ� ?

// #1. static �������� - mayer's singleton

// #2. static ��� ����Ÿ

// #3. heap 

class Cursor
{
private:
	Cursor() {}

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
	Cursor& c1 = Cursor::get_instance();
}














