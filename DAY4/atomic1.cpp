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
	for (int i = 0; i < 1000000; ++i) // 0 6��
	{
//		++x;
		
		// �� ������ �Ʒ� ���
		/*
		__asm
		{
			mov eax, x
			add eax, 1
			mov x, eax 
		}
		*/
		// mutex : OS �� �����ϴ� ����ȭ ����.
		//			������尡 �ֽ��ϴ�
		//			�ܼ�, 1 ������ ����ϱ⿡��...
		/*
		m.lock();
		++x;
		m.unlock();
		*/

		// intel, arm ���� CPU ���� lock ���� ����� �ֽ��ϴ�.
		// lock-free ��� : OS �� lock �� ���ٴ� �ǹ�..
		/*
		__asm
		{
			lock inc x;
		}
		*/
	//	x.fetch_add(1); // �� �Լ��� ������ ���� ����.

		++x; // x.operator++() ȣ���Ѱ�. �ᱹ ���� ����
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