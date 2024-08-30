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
	Character construct()
	{
		Character c;
		c = c + Hat("야구모자");
		c = c + Uniform("파란색티셔츠");
		c = c + Shoes("운동화");
		return c;
	}
};
int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}
