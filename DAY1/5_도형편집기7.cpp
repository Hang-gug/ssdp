#include <iostream>
#include <vector>

// 코드 정리와 생각해볼 문제

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

		// 생각해볼 문제 #1. 객체의 생성 과정을 "OCP" 를 만족하게 할수 없을까 ?
		// => "추상 팩토리 패턴" 을 배우면 됩니다. 4일차에 만들게 됩니다.

		// #2. Undo/Redo
		// => "Command 패턴" 을 배우면 됩니다.

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw(); // 다형성. OCP 만족
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복제할까요 ? ";

			int k;
			std::cin >> k;

			try
			{
				v.push_back(v[k]->clone()); // OCP 만족. 다형성
			}
			catch (NotImplemented& e)
			{
			}

		}
	}
}




