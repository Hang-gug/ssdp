#include <iostream>
#include <list>
#include <vector>

class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

template<typename T> class MyList : public std::list<T>
{
public:
	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this) //  *this 잘 생각해 보세요
			visitor->visit(e);

	}
};


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };


	TwiceVisitor tv;
	s.accept(&tv);   

}





