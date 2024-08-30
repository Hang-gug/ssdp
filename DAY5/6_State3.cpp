#include <iostream>

// 방법 #2. 변하는 것을 가상함수로!

class Character
{
	int gold;
	int item;
public:
	virtual void run() { std::cout << "run" << std::endl; }
	virtual void attack() { std::cout << "attack" << std::endl; }
};

class SuperItem : public Character
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new SuperItem;	// 아이템 획득
	p->run();
	p->attack();
}



