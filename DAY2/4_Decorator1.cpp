// Decorator - 65 page
#include <iostream>

// PhotoSticker : 스티커 사진이라고 생각해 보세요
class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n";}
	void draw()	{ std::cout << "draw Photo\n"; }
};

// 스티커 사진에 "이모티콘"등을 그리는 기능을 추가해 봅시다.
// 방법 #1. 상속 사용

class Emoticon : public PhotoSticker
{
public:
	void draw()
	{
		std::cout << "^^\n";	// 추가된 기능
		PhotoSticker::draw();	// 기존에 있던 기능
		std::cout << "^^\n";
	}
};

int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();

	Emoticon e;
	e.take();
	e.draw();
}
