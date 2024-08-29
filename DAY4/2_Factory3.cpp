#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;
public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto it = create_map.find(type);

		if (it != create_map.end())
		{
			p = it->second();
		}
		return p;
	}
};


// 공장에 제품을 등록하는 기능을 수행하는 클래스
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 전역변수 생성자가 호출되는 시점을 생각해 보세요
AutoRegister ar(1, &Rect::create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};







int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




