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

	// 생성자 상속 문법(C++11 추가된 문법)
	// => 생성자를 상속해 달라.
	// => 아래 한줄 때문에, MyList 사용히, std::list 와 동일하게 객체 생성가능
	using std::list<T>::list; // using 타입이름::생성자이름

	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this) //  *this 잘 생각해 보세요
			visitor->visit(e);

	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor tv;
	s.accept(&tv);   
}

// 방문자 패턴
// => 복합객체의 열거를 위부에서 하는 것이 아니라
// => 내부적으로 모든 요소를 열거 하는 것.

// => 외부에서는 "연산만 정의" 해서 "복합객체" 에 전달!




