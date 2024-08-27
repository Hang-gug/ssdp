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

	// �Ʒ� 2�� �Լ��� MenuItem ������ �ʿ� ������
	// ����ϱ� ���� �ϱ� ���ؼ� Base ������ ������ ���ô�.

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
		std::cout << get_title() << " �޴� ���õ�\n";
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

			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";

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

	root->add(new PopupMenu("����"));
	root->add(new MenuItem("ȭ�����", 11));


	// 
	root->submenu(0)->add(new MenuItem("RED", 11));  // ok

	try
	{
		root->submenu(1)->add(new MenuItem("RED", 11)); // ������ ok
									// ������, ���� �߻�
	}
	catch (...)
	{
	}
	root->command();
}

// root->submenu(0) �� ����� add ȣ���ϰ� �ʹ�.
// �޴�7 : ĳ�����ؼ� ����ض�  - safety �� ����
// �޴�8 : ĳ���� �ʿ� ������ �߸�����ϸ� ���� �߻� - comportable �� ����
