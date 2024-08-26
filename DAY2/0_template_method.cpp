// github.com / codenuri / ssdp 에서 DAY2.zip 받으시면 됩니다.

#include <iostream>
#include <vector>

class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	// ==============================
	// template method 
	// => 변하지 않은 코드내부에서 변하는 것을 가상함수로!!
	// => 교재 28 page
	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";
	}

	virtual void draw_imp() = 0;

	// ==============================

	virtual Shape* clone() { throw NotImplemented(); }
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

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw(); 
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제할까요 ? ";

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




