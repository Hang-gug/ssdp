// 2_Builder
#include <iostream>
#include <string>

typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정


// 캐릭터만들때 각 공정의 결과는 다를수 있습니다.

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

	// 아래 코드는 캐릭터 자체를 만드는 공정을 정의 했습니다.
	// => 그런데, 각 공정을 어떻게 만들지는 달라질수 있습니다.
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
	void make_hat()     override { c += "갓\\"; }
	void make_uniform() override { c += "한복\\"; }
	void make_shoes()   override { c += "짚신\n"; }

	Character get_result() override { return c; }
};

class American : public IBuilder
{
	Character c;
public:
	void make_hat()     override { c += "야구모자\\"; }
	void make_uniform() override { c += "양복\\"; }
	void make_shoes()   override { c += "구두\n"; }

	Character get_result() override { return c; }
};
int main()
{
	Korean k;
	American a;
	
	Director d;
	d.set_builder(&k); // 국가 선택을 변경할때 마다 "빌더" 를 교체 합니다.

	Character c = d.construct();
	std::cout << c << std::endl;

}

