#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() const { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch(); 
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:

	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// main 의 주석을 참고해서 아래 코드를 생각해 보세요
	void command()
	{

	}
};

int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심 메뉴");

	pm.add(&m1);
	pm.add(&m2);

	pm.command();  // 팝업메뉴 선택시 동작을 생각해 보세요
					// 1. 김밥
					// 2. 라면
					// 3. 종료
					// 메뉴를 선택하세요 >>
}




