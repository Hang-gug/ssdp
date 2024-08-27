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

class Emoticon 
{
	PhotoSticker* original;  // 핵심 : 포인터 또는 참조 멤버
							 // 의도 : 외부에 이미 생성된 객체를 가리키겠다는것
							 //		  	
public:
	Emoticon(PhotoSticker* ps) : original(ps) {}

	void draw()
	{
		std::cout << "^^\n";	
		original->draw();	
		std::cout << "^^\n";
	}
};





class Border 
{
	PhotoSticker* original;
public:
	Border(PhotoSticker* ps) : original(ps) {}

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


	Emoticon e(&ps); // e 는 이미 존재하는 객체인 ps에 기능을 추가하는 객체

	ps.draw(); // 이렇게 하면 이모티콘없이 사진이 출력되고
	e.draw();  // 이렇게 하면 이모티콘 기능이 추가되어서 출력
}

