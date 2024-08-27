#include <stdlib.h>
#include <iostream>

// 방법 #3. policy base design(단위전략) 을 사용해 봅시다.


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
	vector<int> v(4, &ma); 
}



