// Decorator - 65 page
#include <iostream>

// PhotoSticker : ��ƼĿ �����̶�� ������ ������
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


// ��� : Ŭ������ ��� �߰�
// ���� : ��ü�� ��� �߰�

class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "^^\n";	
		PhotoSticker::draw();	
		std::cout << "^^\n";
	}
};


class Border : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "========\n";
		PhotoSticker::draw();
		std::cout << "========\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();	
	ps.draw();

}

