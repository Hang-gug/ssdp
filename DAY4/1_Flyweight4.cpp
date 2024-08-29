#include <iostream>

int main()
{
	// C++, RUST, C#, Java 등의 문자열 클래스를 완벽히 이해하려면
	// 아래 차이를 정확히 알아야 합니다.
	// 
	// #1. 문자열 배열 vs 문자열 포인터
	char sa[] = "abcd";
//	char* sp  = "abcd"; // stack 에는 포인터만, 
						// 실제 문자열은 상수 메모리(.rdata, .rodata)
						// C 언어 : ok. 하지만 아래 *sp='x' 가 런타임에러
						// C++언어 : error. 
	const char* sp = "abcd"; // C++ 은 이렇게만 가능

	*sa = 'x'; // ok
	*sp = 'x'; // runtime-error. 상수메모리를 변경하려고 하고 있다.




	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1[] = "abcd";
	const char* sp2[] = "abcd";
}