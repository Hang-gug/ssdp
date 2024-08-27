#include <stdlib.h>
#include <iostream>

// ��� #3. policy base design(��������) �� ����� ���ô�.

// �������̽�

// ���� : ���� ������ ���ؼ� ��ü ������ ���谡 �����ϴ�.

// ���� : �ᱹ �����Լ��̹Ƿ� �޸� �������� ȣ��� ���� ���ϰ� �ִ�




// std::allocator : C++ ǥ�� �޸� �Ҵ��
//					���������� new/delete ���.
#include <memory>   // �� ��� �ʿ�

template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MyAllocator<T> alloc; // allocator �̸��� ���� ���
						  // ���� ����. ��ü �Ұ���.

	Alloc alloc; // ���ø� ���ڷ� �޸� �Ҵ�� Ÿ���� ����
				 

public:
	vector(int sz) : size(sz)
	{
		buff = alloc.allocate(sz);
	}
	~vector()
	{
		alloc.deallocate(buff, size);
	}
};

template<typename T> class MyAllocator 
{
public:
	inline T* allocate(std::size_t sz) 
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	inline void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}
};

int main()
{
//	vector<int, MyAllocator<int> > v(4); 

	vector<int > v(4);
}




// strategy vs policy base design
// => �Ѵ�, Ŭ������ ����ϴ� �˰���(��å)�� �ٸ� Ŭ������ �и� �ϴ� ��

// strategy : �Ϲ������� ��å Ŭ������ "�������̽�"�� ���ؼ� ��ü

// policy base design : ��åŬ������ "���ø� ����" �� ��ü
// 


//						����					������
// strategy			  : ������(�����Լ�)		����ð� ��ü ����
//											e.set_validator(&v1)
//											e.set_validator(&v2)

// policy base design : ������(�ζ��ε�����)	����ð� ��ü�Ҽ� ����.
//											��ü �����ø� ���ø� ���ڷ� ���ް���


// ������ ���� : ��κп� ��ü���� ���� ���� ������ �Ϲ����� ������ ���
//			    GoF's design pattern 23���� ���� �����ϰ�
//				���� �����ϴ� �߰�����  ���ϵ鵵 ����(MVC, MVVM ��...)
// => template method, strategy ��...

// IDioms : �� ����� Ư¡�� ����� ������ ���
//			(C++ IDioms, Java Idioms ��... )
//			���ۿ��� "C++ Idioms" �˻��� 1��° ��ũ
// => policy base design, CRTP, object generator