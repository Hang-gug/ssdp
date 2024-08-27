// Decorator - 65 page
#include <iostream>

// PhotoSticker : 스티커 사진이라고 생각해 보세요
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};


// 상속 : 클래스에 기능 추가
// 포함 : 객체에 기능 추가

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

