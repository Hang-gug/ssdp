#include <stdlib.h>
#include <iostream>

// ��� #2. strategy ������ ����� ���ô�.
// => ���ϴ� ���� �ٸ� Ŭ������
// => �޸� �Ҵ� ������ ������ Ŭ������ ���� ���

// ����
// => �޸� �Ҵ� ��å�� vector �� �и��Ǿ� �ִ�.
// => list, set, map ����� ��밡���ϴ�.
// => �������� "strategy" ������ ����!!

// �׷���, C++ �������� �����ϴ� ����
// => �޸� �Ҵ�/���� �� �����Լ��� ���ؼ� �ϰ� �ִ�.
// => �����Լ��� �޸� �������(�����Լ� ���̺�)�� �ְ�
// => ȣ��� ������嵵 �ִ�.


// �޸� �Ҵ� ��å�� �������̽�
template<typename T>
struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;

	virtual ~IAllocator() {}
};


template<typename T>
class vector
{
	T* buff = nullptr;
	int size;
	IAllocator<T>* alloc;
public:
	vector(int sz, IAllocator<T>* p) : size(sz), alloc(p)
	{
		buff = alloc->allocate(sz);
	}
	~vector()
	{
		alloc->deallocate(buff, size);
	}
};

// ���� �پ��� ��å�� ������ �޸� �Ҵ�� Ŭ������ ����� �ȴ�.
template<typename T> class MyAllocator : public IAllocator<T>
{
public:
	T* allocate(std::size_t sz) override
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz) override
	{
		free(p);
	}
};

int main()
{
	MyAllocator<int> ma;
	vector<int> v(4, &ma); // �޸� �Ҵ� ��å�� ������ ���ڷ� ����
}



