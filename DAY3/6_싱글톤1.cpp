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

	// 규칙 #2. 컴파일러가 자동생성하는 복사 생성자도 
	//			사용할수 없게 해야 합니다
	Cursor(const Cursor&) = delete; // 복사생성자를 만들지 말라고 지시하는것

	Cursor& operator=(const Cursor&) = delete;
									// 복사를 삭제하면 대입도 삭제하는것이 관례



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

//	Cursor c3 = c1; // 이렇게 생성하는 것도 막아야 합니다.
					// "복사 생성자"

//	Cursor c1, c2; // error
}


// 위코드가 "mayer's singleton" 이라는 코드 입니다.
// 
// => effective - C++ 책의 저자인 
// => scott-mayer 가 처음 제안한 코드

// => 현재 C++ 에서 가장 좋다고 평가 받는 코드













