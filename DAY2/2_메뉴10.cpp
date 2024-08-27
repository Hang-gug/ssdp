#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>	
using namespace std::placeholders;

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	virtual void command() = 0;
};








class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	~PopupMenu()
	{
		for (auto m : v)
			delete m;
	}



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
};


class MenuItem : public BaseMenu
{
	int id;

//	void(*handler)(); // 함수 포인터

	using HANDLER = std::function<void()>;

	std::vector< HANDLER >  v;

public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr ) 
		: BaseMenu(title), id(id) 
	{
		if (h != nullptr)
			v.push_back(h);
	}

	void add_handler(HANDLER h) { v.push_back(h); }

	void command()
	{
		for (auto f : v)
			f();	// f 는 std::function 이므로 () 로 호출.
	}
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상 변경");
	PopupMenu* pm2 = new PopupMenu("해상도 변경");

	root->add(pm1);
	root->add(pm2);

	pm1->add(new MenuItem("RED", 11));
	pm1->add(new MenuItem("GREEN", 12));
	pm1->add(new MenuItem("BLUE", 13));

	pm2->add(new MenuItem("HD", 21));
	pm2->add(new MenuItem("FHD", 22));
	pm2->add(new MenuItem("UHD", 23));
	pm2->add(new MenuItem("8K", 24));

	root->command();


	delete root;

}
