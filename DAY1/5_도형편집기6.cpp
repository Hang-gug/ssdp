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

	// 공통성과 가변성의 분리
	// => 변하지 않은 공통의 특징은 기반 클래스에서 제공한다.
	// => 변하지 않은 코드 내부에 숨은 변해야 하는 코드를 찾는다.
	// => 변하는 것을 가상함수로 분리한다.

	virtual void draw()
	{
		std::cout << "lock mutex\n";

		std::cout << "draw Rect\n";

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
	void draw() 
	{ 
		std::cout << "lock mutex\n";
		
		std::cout << "draw Rect\n"; 

		std::cout << "unlock mutex\n";
	}


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




