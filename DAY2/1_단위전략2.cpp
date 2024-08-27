#include <stdlib.h>
#include <iostream>
// ��� #1. template method ������ ����� ���ô�.
// => ���ϴ� ���� �����Լ���!!
// => vector ���� ���ϰ� ���� ���� "�޸� �Ҵ�� ���� ���"

template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = allocate(size);
	}
	~vector()
	{
		deallocate(buff, size);
	}

	// �޸� �Ҵ�/������ å������ �����Լ� ����
	// => vector �� ��� ��� �Լ����� �޸��Ҵ�/������ �ʿ��ϸ�
	//    �Ʒ� �����Լ� ���
	virtual T* allocate(std::size_t sz)
	{
		return new T[sz];
	}
	virtual void deallocate(T* p, std::size_t sz)
	{
		delete[] p;
	}
};

// �� �ڵ��� �ǵ�
// vector �� �޸� �Ҵ� ����� �����Ϸ���
// �Ļ� Ŭ������ ���� ��ӵ� �����Լ��� override �ϸ�˴ϴ�.

template<typename T> class MyVector : public vector<T>
{
public:
	MyVector(std::size_t sz) : vector<T>(sz) {}

	T* allocate(std::size_t sz) override 
	{
		return static_cast<T*>( malloc(sizeof(T) * sz) );
	}
	void deallocate(T* p, std::size_t sz) override
	{
		free(p);
	}
};

int main()
{
	MyVector<int> v(4);
}


