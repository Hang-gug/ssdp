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
	ps.take();	// A
	ps.draw();

	Emoticon e;
	e.take();
	e.draw();

	Border b; // 테두리를 그리기 위해
	b.take(); // 다시 사진 촬영 필요
	b.draw();
}

// 위코드에 대해서 생각해 봅시다.

// 1. 이미 사진은 촬영했습니다. "A" 부분에서 
// 2. 위 코드는 촬영된 사진에 이모티콘이 추가된것이 아니라
// 3. 이모티콘을 추가하기 위해 다시 사진을 촬영한것
// 
// 상속 : 객체가 아닌 클래스에 기능 추가

// 위코드의 또 다른 문제점
// => 이모티콘과 Border 를  동시에 추가하려면
// => 다시 Emoticon 과 Border 를 다중상속한 파생 클래스 필요!!
// => 복잡해 진다.