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

// Emoticon, Border 는 모두 기능 추가 클래스(Decorator)입니다.
// => 일반적으로 동일한 멤버가 있는 경우가 많습니다.

// 공통의 특징이 많은 경우,
// 기반 클래스로 제공합니다.(물론, 생략되는 경우도 많습니다.)

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

