#include <iostream>
#include <string>
#include <vector>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// ��� ����� �������̽�
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() {}
	virtual bool can_undo()    { return false; }
	virtual bool can_execute() { return true; }

	virtual ~ICommand() {}
};

// �簢���� �߰��ϴ� ���
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }

	void undo() override
	{
		Shape* s = v.back();  // ��ȯ�� ���� �ȵ�.
		v.pop_back();		  // ���Ŵ� ������ �Լ���

		delete s;
	}
};




int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw();
			}
		}
	}
}







