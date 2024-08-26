#include <iostream>
#include <vector>

// #1. ��� �Ļ� Ŭ������ ������ Ư¡�� 
//     "�ݵ�� ��� Ŭ�������� �־�� �մϴ�."
//     (������ �ƴ� ������ ��Ģ)
//     �׷��� Shape* �� draw() ȣ�� �����մϴ�.

// #2. ��� Ŭ���� �Լ��� �Ļ� Ŭ������ override �ϴ� ����
//     �ݵ�� "virtual" �� ������ �Ѵ�.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }
};
class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }
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
				s->draw();	
		}
	}
}




