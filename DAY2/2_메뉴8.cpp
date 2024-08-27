#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;

	// 아래 2개 함수는 MenuItem 에서는 필요 없지만
	// 사용하기 쉽게 하기 위해서 Base 에서도 제공해 봅시다.

	virtual void add(BaseMenu*)
	{
		throw unsupported_operation();
	}
	
	virtual BaseMenu* submenu(int idx) 
	{
		throw unsupported_operation();
	}
};




class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}


	void add(BaseMenu* m) { v.push_back(m); }



	void command()
	{
		while (1)
		{
			system("cls");

			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << '\n';
			}

			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;



			v[cmd - 1]->command();
		}
	}

	BaseMenu* submenu(int idx) { return v[idx]; }
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add(new PopupMenu("색상"));
	root->add(new MenuItem("화면끄기", 11));


	// 
	root->submenu(0)->add(new MenuItem("RED", 11));  // ok

	try
	{
		root->submenu(1)->add(new MenuItem("RED", 11)); // 컴파일 ok
									// 하지만, 예외 발생
	}
	catch (...)
	{
	}
	root->command();
}

// root->submenu(0) 의 결과에 add 호출하고 싶다.
// 메뉴7 : 캐스팅해서 사용해라  - safety 를 강조
// 메뉴8 : 캐스팅 필요 없지만 잘못사용하면 예외 발생 - comportable 를 강조
