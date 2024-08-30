#include <iostream>

// 방법 #1. 캐릭터의 상태에 따라 동작을 변경하는 제어문
// 단점 : 동작함수가 많거나, 아이템이 많아지만 제어문이 너무 많아진다.

class Character
{
	int gold;
	int item;
public:
	void run() 
	{ 
		if ( item == 1)
			std::cout << "run" << std::endl; 

		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack()
	{
		if ( item == 1 )
			std::cout << "attack" << std::endl; 
		else if ( item == 2 )
			std::cout << "power attack" << std::endl;
	}
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



