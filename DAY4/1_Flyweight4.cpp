#include <iostream>

int main()
{
	// C++, RUST, C#, Java ���� ���ڿ� Ŭ������ �Ϻ��� �����Ϸ���
	// �Ʒ� ���̸� ��Ȯ�� �˾ƾ� �մϴ�.
	// 
	// #1. ���ڿ� �迭 vs ���ڿ� ������
	char sa[] = "abcd";
//	char* sp  = "abcd"; // stack ���� �����͸�, 
						// ���� ���ڿ��� ��� �޸�(.rdata, .rodata)
						// C ��� : ok. ������ �Ʒ� *sp='x' �� ��Ÿ�ӿ���
						// C++��� : error. 
	const char* sp = "abcd"; // C++ �� �̷��Ը� ����

	*sa = 'x'; // ok
	*sp = 'x'; // runtime-error. ����޸𸮸� �����Ϸ��� �ϰ� �ִ�.




	char sa1[] = "abcd";
	char sa2[] = "abcd";

	const char* sp1[] = "abcd";
	const char* sp2[] = "abcd";
}