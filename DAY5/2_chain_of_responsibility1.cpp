#include <iostream>

// chain of responsibility
// => 책임의 고리, 책임의 전가, 책임의 연쇄.. 

// 아래 코드가 "chain of responsibility" 의 핵심 코드 입니다.
struct Handler
{
	Handler* next = nullptr;

	Handle* set_next(Handler* n)
	{
		next = n;
		return next;
	}

	// 아래 함수가 핵심
	void Handle(int problem)
	{
		// #1. 자신이 먼저 처리를 시도
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class Team1 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Team1 Start\n";

		if (problem == 7)
		{
			std::cout << "resolved by Team1\n";
			return true;
		}
		return false;
	}
};

int main()
{
}
