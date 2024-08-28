#include <iostream>


// 오직 한개의 객체를 어느 메모리에 어떻게 만들것인가 ?

// #1. static 지역변수 - mayer's singleton
// => get_instance()가 최초 호출 될때 Cursor 생성자 호출 - 늦은(lazy)초기화
// => get_instance()를 한번도 호출하지 않으면 Cursor 생성자 호출 안됨
// => thread - safe !!

// #2. static 멤버 데이타
// => main 보다 먼저 Cursor 생성자 호출 - 이른(early)초기화
// => 스레드를 만들기 전이므로 thread - safe
// =>  get_instance()를 한번도 호출하지 않아도 Cursor 생성자 호출됨. 

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
Cursor Cursor::instance; // C++ 에서는 static 멤버 데이타는 외부 정의 필요

int main()
{
	std::cout << "main\n";

//	Cursor& c1 = Cursor::get_instance();
}














