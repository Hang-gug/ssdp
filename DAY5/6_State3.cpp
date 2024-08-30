#include <iostream>

// ��� #2. ���ϴ� ���� �����Լ���!

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

	p = new SuperItem;	// ������ ȹ��
	p->run();
	p->attack();
}



