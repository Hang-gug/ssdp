class Dialog
{
public:
	void close(int code) {}
//	void close(this Dialog& self, int code) {} // 위코드와 동일
											   // this가 암시적 추가가 아닌
												// 개발자가 명시적 표기
												// "python 과 동일"

	static void close2(int code) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok 	
	void(*f2)(int) = &Dialog::close; // error. close 는 멤버함수이므로
									 // this 가 추가된 함수.

	void(*f3)(int) = &Dialog::close2; // ok.. static 멤버 함수는 this 추가안됨
}

// 핵심 #1. 일반 함수 포인터에 멤버함수의 주소를 담을수 없습니다.(this 때문)

// 핵심 #2. 일반 함수 포인터에 static 멤버함수의 주소를 담을수 있습니다.