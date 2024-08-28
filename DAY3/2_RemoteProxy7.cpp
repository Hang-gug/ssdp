#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// raw pointer
// => 객체가 아닙니다.
// => 생성자/소멸자/복사생성자/대입연산자 개념이 없습니다.

// proxy
// => 다양한 이유로 대신할것을 만드는 패턴. 



int main()
{
	ICalc* calc1 = load_proxy();
}





