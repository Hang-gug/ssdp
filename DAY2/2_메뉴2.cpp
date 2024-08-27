#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍
// => 모든 것은 "함수" 가 아닌 "객체" 로 표현된다.
// => 프로그램에서 필요한 타입을 먼저 설계 한다.

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() const { return title; }

	
	// 메뉴 선택시 호출될 함수
	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";

		_getch(); // 잠시 대기
	}


};


int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // "메뉴 선택" 시 호출될 함수
}




