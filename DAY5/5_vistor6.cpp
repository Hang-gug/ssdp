#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// list : ��� ��Ұ� ����Ÿ��							��������
// �޴� : ��� ��Ұ� ����Ÿ�Ծƴ�(Popup �Ǵ� MenuItem)	tree����

class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
//	virtual void visit(BaseMenu* bm) = 0;
				// => PopupMenu, MenuItem ��� ������ ������
				// => ���� ������ ����ϰڴٴ� �ǵ�

	virtual void visit(PopupMenu* pm) = 0;
	virtual void visit(MenuItem*  mi) = 0;

	virtual ~IMenuVisitor() {}
};




class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " �޴��� ���õ�" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". ����" << std::endl;

			int cmd;
			std::cout << "�޴��� �����ϼ��� >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command();
		}

	}

};

class TitleChangeVisitor : public IMenuVisitor
{
	std::string deco_popup;
	std::string deco_menu;
public:
	TitleChangeVisitor(const std::string& s1, const std::string& s2)
		: deco_popup(s1), deco_menu(s2) {}

	// �ᱹ �Ʒ� �Լ������� "��� �Ѱ�" �� ���� ������ ���� �Դϴ�.
	void visit(PopupMenu* pm)
	{
		auto s = pm->get_title() + deco_popup;
		pm->set_title(s);	
	}

	void visit(MenuItem* mi)
	{
		auto s = mi->get_title() + deco_menu;
		mi->set_title(s);
	}
};






int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));


	// root �� ���� ��� �޴��� ���ؼ� Ÿ��Ʋ�� ������ ���ô�.
	// ��� #1. �ܺο��� ���� �����ϸ鼭 Ÿ��Ʋ ���� - iterator �� �ʿ� �մϴ�.
	// ��� #2. �湮��(visitor) ���� ���

	TitleChangeVisitor tcv(" >", " *");

	root->accept(&tcv);


	root->command();

}




