﻿// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C 언어에서 프로그램 이란 ?
// 1. main 함수의 1번째 문장부터 순차적으로 실행되는 실행흐름.
// 2. 실행흐름을 변경하려면 제어문을 사용한다.
// 3. 실행흐름을 반복하려면 반복문을 사용한다.
// 4. 프로그램을 기능 별로 분리하려면 "함수" 를 사용한다.
// 5. 프로그램의 기본 단위는 "함수" 이다.

// => "structural programming" 이라고 합니다.


// 장점 : CPU 가 동작하는 방식과 동일하다.
//		  빠르고, 메모리 사용량도 작다

// 단점 : 유연성이 부족하고 유지보수가 어렵다.
//		  아래 메뉴예제에서, 
//		  => 새로운 메뉴가 추가된다면 ?
//		  => 하위 메뉴가 존재 한다면 ?


int main()
{
	// C 언어 스타일로 만든 메뉴 예제

	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


