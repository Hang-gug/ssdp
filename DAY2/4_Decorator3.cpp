#include <iostream>

// 항상 클래스 다이어그램을 생각하세요





class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};



class Emoticon
{
	PhotoSticker* original;  
	  	
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


	Emoticon e(&ps);


}

