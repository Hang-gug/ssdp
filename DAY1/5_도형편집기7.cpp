#include <iostream>
#include <vector>

// �ڵ� ������ �����غ� ����

class NotImplemented
{
};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual void draw_imp() = 0;

	void draw()
	{
		std::cout << "lock mutex\n";

		draw_imp();

		std::cout << "unlock mutex\n";
	}




	virtual Shape* clone()
	{
		throw NotImplemented();
	}

	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Rect\n"; }
	Shape* clone()  override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Shape* clone()  override { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// �����غ� ���� #1. ��ü�� ���� ������ "OCP" �� �����ϰ� �Ҽ� ������ ?
		// => "�߻� ���丮 ����" �� ���� �˴ϴ�. 4������ ����� �˴ϴ�.

		// #2. Undo/Redo
		// => "Command ����" �� ���� �˴ϴ�.

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw(); // ������. OCP ����
		}
		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ �����ұ�� ? ";

			int k;
			std::cin >> k;

			try
			{
				v.push_back(v[k]->clone()); // OCP ����. ������
			}
			catch (NotImplemented& e)
			{
			}

		}
	}
}




