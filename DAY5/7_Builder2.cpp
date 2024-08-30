// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����


// ĳ���͸��鶧 �� ������ ����� �ٸ��� �ֽ��ϴ�.

struct IBuilder
{
	virtual void make_hat() = 0;
	virtual void make_uniform() = 0;
	virtual void make_shoes() = 0;
	virtual Character get_result() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* p) { builder = p; }

	// �Ʒ� �ڵ�� ĳ���� ��ü�� ����� ������ ���� �߽��ϴ�.
	// => �׷���, �� ������ ��� �������� �޶����� �ֽ��ϴ�.
	Character construct()
	{
		builder->make_hat();
		builder->make_uniform();
		builder->make_shoes();

		return builder->get_result();
	}
};

class Korean : public IBuilder
{
	Character c;
public:
	void make_hat()     override { c += "��\\"; }
	void make_uniform() override { c += "�Ѻ�\\"; }
	void make_shoes()   override { c += "¤��\n"; }

	Character get_result() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	void make_hat()     override { c += "�߱�����\\"; }
	void make_uniform() override { c += "�纹\\"; }
	void make_shoes()   override { c += "����\n"; }

	Character get_result() override { return c; }
};
int main()
{
	Korean k;
	American a;
	
	Director d;
	d.set_builder(&k); // ���� ������ �����Ҷ� ���� "����" �� ��ü �մϴ�.

	Character c = d.construct();
	std::cout << c << std::endl;

}

