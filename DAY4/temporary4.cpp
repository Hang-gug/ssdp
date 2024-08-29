#include <iostream>

// call by value    : 복사본 생성
// call by reference : 복사본 생성 안함

// return by value    : 복사본 생성 (임시객체 )
// return by reference : 복사본 생성 안함

// 단, 지역변수는 절대 참조 반환하면  안됩니다.

Point& foo()
{
	Point pt(2, 3);
	return pt; // 에러 없지만 절대 사용금지
				// 요즘은 경고 나옵니다.
}

// 함수 호출 종료되어도 파괴되지 않은 것만 참조반환 가능
// => *this, 전역변수, static 지역변수, 멤버 데이타등.. 

class Counter
{
public:
	int cnt = 0;

//	Counter increment()
	Counter& increment()
	{
		++cnt;
		return *this;
	}

	~Counter() { std::cout << "~Counter()\n"; }
};

int main()
{
	Counter c;

	std::cout << "----------------\n";
	c.increment().increment().increment();
	std::cout << "----------------\n";

	std::cout << c.cnt << std::endl;

	
}