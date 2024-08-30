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

	p = new SuperItem;	// 아이템 획득 ??
						// 이코드는 
						// => 기존 객체의 동작이 변경된 것이 아니라
						// => 동작이 다른 새로운 객체 생성
						// => 동작만 변경되어야 하는데, 상태도 변경된것
						// "상태는 유지하면서 동작만 변경할수 없을까 ?"
	p->run();
	p->attack();
}



