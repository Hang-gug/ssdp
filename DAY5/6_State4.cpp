#include <iostream>

// ���ϴ� �� : ��ü�� ���¿� ���� ���� ��� ��� �Լ��� ��ü�ϴ°�
// �������� ������ "��� �Լ���"
// �������� ������ "��� �Լ���"

// ��� �Լ����� �������̽�
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// �̿ܿ� jump(), slide(), fly() ....
};

// ����(��� �Լ�)�� ������ Ŭ�������� ������ ����
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

	// �ᱹ �Ʒ� ȿ���� ����Լ� 3���� ��Ʈ �� ������ �ִ°�
	NoItem noitem;
	SuperItem superitem;
	RedItem reditem;
	
	IState* current = &noitem;

public:
	void acquire_super_item()
	{
		current = &superitem;

		// Ÿ�̸Ӽ�ġ�ؼ� 3�ʵڿ�
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
				// �̼���, ��ü�� ���´� ���� ������ 
				// ��κ��� ��� �Լ��� ��ü �ȴ�.
				// ��ġ �ٸ� Ŭ������ ����ϴ� ��ó�� ���δ�.
	p->run();
	p->attack();
}

// ���ϴ� ���� �ٸ� Ŭ������ �и��ؼ� �����ϴ� ������ 3������ �ֽ��ϴ�.

// strategy : Ŭ������ ����ϴ� �Ϻ� �˰����� ��ü
//			  �ܺο��� ��ü�Ǵ� ��찡 �����ϴ�.
//			  e.set_validtor(&v)

// state    : ��ü�� ���¿� ���� ���� ��� ��� �Լ��� ��ü
//			  �������� ������ ���۰� ������ ���� ��ü�� ��ü
//		      �ܺ� �Ǵ� ������ ���� ���� ��ü
//			  "3��"�� ��ü��..

// ex) ���Ǳ� ��ư�� ������ "Ŀ��"�� ���ɴϴ�.
// �׷���, ������ �־����Ŀ� ���� �޶� ���ϴ�.
// ������ ������ "��� ����"
// ������ ������ "��� ����" ���� �����ؼ�. 
// ��ü �����ϰ� �մϴ�.

// �����Ҷ� "VendingMachine" ����� ������. insert_coin(), push_button()

// builder :

