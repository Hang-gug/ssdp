#include <iostream>

// 원하는 것 : 객체에 상태에 따라 거의 모든 멤버 함수를 교체하는것
// 아이템이 없을때 "멤버 함수들"
// 아이템이 있을때 "멤버 함수들"

// 멤버 함수들의 인터페이스
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 이외에 jump(), slide(), fly() ....
};

// 동작(멤버 함수)만 가지는 클래스들을 별도로 설계
class NoItem : public IState
{
public:
	void run() override     { std::cout << "run" << std::endl; }
	void attack() override  { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run() override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class RedItem : public IState
{
public:
	void run() override { std::cout << "slower run" << std::endl; }
	void attack() override { std::cout << "super power attack" << std::endl; }
};

class Character
{
	int gold;
	int item;

	// 결국 아래 효과는 멤버함수 3개의 세트 를 가지고 있는것
	NoItem noitem;
	SuperItem superitem;
	RedItem reditem;
	
	IState* current = &noitem;

public:
	void acquire_super_item()
	{
		current = &superitem;

		// 타이머설치해서 3초뒤에
		// current = &noitem;
	}

	void run() { current->run(); }
	void attack() { current->attack(); }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_super_item();
				// 이순간, 객체는 상태는 유지 하지만 
				// 대부분의 멤버 함수가 교체 된다.
				// 마치 다른 클래스를 사용하는 것처럼 보인다.
	p->run();
	p->attack();
}

// 변하는 것을 다른 클래스로 분리해서 구현하는 패턴을 3가지가 있습니다.

// strategy : 클래스가 사용하는 일부 알고리즘의 교체
//			  외부에서 교체되는 경우가 많습니다.
//			  e.set_validtor(&v)

// state    : 객체에 상태에 따라 거의 모든 멤버 함수의 교체
//			  아이템이 있을때 동작과 없을때 동작 전체의 교체
//		      외부 또는 내부의 의해 상태 교체
//			  "3초"뒤 교체등..

// ex) 자판기 버튼을 누르면 "커피"가 나옵니다.
// 그런데, 동전을 넣었느냐에 따라 달라 집니다.
// 동전이 없을때 "모든 동작"
// 동전이 있을때 "모든 동작" 따로 설계해서. 
// 교체 가능하게 합니다.

// 복습할때 "VendingMachine" 만들어 보세요. insert_coin(), push_button()

// builder :

