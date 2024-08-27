#include <iostream>

// �׻� Ŭ���� ���̾�׷��� �����ϼ���

// PhotoSticker �� ��� �߰� Ŭ����(Decorator)�� 
// ������ �������̽� �־�� �Ѵ�.
// => �׷��� ��ø�� ��� �߰��� �����ϴ�.

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

	Border b(&e);	// emoticon ����� �߰��� ��ü�� 
					// �ٽ� ����߰�.
	b.draw();

}

