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

class Emoticon 
{
	PhotoSticker* original;  // �ٽ� : ������ �Ǵ� ���� ���
							 // �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴٴ°�
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


	Emoticon e(&ps); // e �� �̹� �����ϴ� ��ü�� ps�� ����� �߰��ϴ� ��ü

	ps.draw(); // �̷��� �ϸ� �̸�Ƽ�ܾ��� ������ ��µǰ�
	e.draw();  // �̷��� �ϸ� �̸�Ƽ�� ����� �߰��Ǿ ���
}

