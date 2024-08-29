// atomic1
#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>

std::mutex m;

//int x = 0;
std::atomic<int> x = 0;

void foo()
{
	for (int i = 0; i < 1000000; ++i) // 0 6개
	{
//		++x;
		
		// 위 한줄은 아래 어셈
		/*
		__asm
		{
			mov eax, x
			add eax, 1
			mov x, eax 
		}
		*/
		// mutex : OS 가 제공하는 동기화 도구.
		//			오버헤드가 있습니다
		//			단순, 1 증가에 사용하기에는...
		/*
		m.lock();
		++x;
		m.unlock();
		*/

		// intel, arm 등의 CPU 에는 lock 등의 명령이 있습니다.
		// lock-free 기술 : OS 의 lock 이 없다는 의미..
		/*
		__asm
		{
			lock inc x;
		}
		*/
	//	x.fetch_add(1); // 이 함수의 구현이 위와 유사.

		++x; // x.operator++() 호출한것. 결국 위와 동일
	}
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);
	std::thread t3(&foo);

	t1.join();	t2.join(); t3.join();

	std::cout << x << std::endl;

}