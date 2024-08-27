#include <iostream>

// 항상 클래스 다이어그램을 생각하세요

// PhotoSticker 와 기능 추가 클래스(Decorator)는 
// 공통의 인터페이스 있어야 한다.
// => 그래야 중첩된 기능 추가가 가능하다.

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



class Emoticon : public IDraw
{
	IDraw* original;
public:
	Emoticon(IDraw* ps) : original(ps) {}

	void draw()
	{
		std::cout << "^^\n";
		original->draw();
		std::cout << "^^\n";
	}
};


class Border : public IDraw
{
	IDraw* original;
public:
	Border(IDraw* ps) : original(ps) {}

	void draw()
	{
		std::cout << "========\n";
		original->draw();
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

	Border b(&e);	// emoticon 기능을 추가한 객체에 
					// 다시 기능추가.
	b.draw();

}

