// 7_싱글톤1 - 123 page
#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하고
//		   어디서든지 동일한 방법으로 접근 가능한 객체

// => 결국 "전역변수"
// => 그런데, 전역변수는 좋지 않다고 알려져 있습니다.
// => 그래서, "싱글톤" 에 대한 비판도 많습니다.


class Cursor
{
	// 규칙 #1. 생성자는 private 에
private:
	Cursor() {}

	// 규칙 #2.



	// 규칙 #3. 오직 한개의 객체를 생성해서 반환하는 static 멤버 함수
public:
	static Cursor& get_instance()
	{
		static Cursor instance; // 핵심 : static 지역변수

		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();

	std::cout << &c1 << std::endl;
	std::cout << &c2 << std::endl;

//	Cursor c1, c2; // error
}















