#include <iostream>


struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};

class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

// Emoticon, Border �� ��� ��� �߰� Ŭ����(Decorator)�Դϴ�.
// => �Ϲ������� ������ ����� �ִ� ��찡 �����ϴ�.

// ������ Ư¡�� ���� ���,
// ��� Ŭ������ �����մϴ�.(����, �����Ǵ� ��쵵 �����ϴ�.)

class Decorator : public IDraw
{
//	int x, y;
	IDraw* original;
public:
	Decorator(IDraw* ori) : original(ori) {}

	void draw() override
	{
		original->draw();
	}		
};

class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "^^\n";
		Decorator::draw();
		std::cout << "^^\n";
	}
};
class Border : public Decorator
{
public:
	Border(IDraw* ps) : Decorator(ps) {}

	void draw()
	{
		std::cout << "========\n";
		Decorator::draw();
		std::cout << "========\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();

	Emoticon e(&ps);
	e.draw();

	Border b(&e);	
	b.draw();

}

