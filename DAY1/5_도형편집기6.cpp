#include <iostream>
#include <vector>

class NotImplemented
{
};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }


	virtual void draw() = 0;


	virtual Shape* clone()
	{
		throw NotImplemented();
	}

	virtual int get_area() { return -1; }

};




class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
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
		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ �����ұ�� ? ";

			int k;
			std::cin >> k;

			try
			{

				v.push_back(v[k]->clone());
			}
			catch (NotImplemented& e)
			{
			}

		}
	}
}




