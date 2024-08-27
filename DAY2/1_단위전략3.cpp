#include <stdlib.h>
#include <iostream>

// 방법 #2. strategy 패턴을 사용해 봅시다.
// => 변하는 것을 다른 클래스로
// => 메모리 할당 해지를 별도의 클래스로 만들어서 사용

// 메모리 할당 정책의 인터페이스
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

// 이제 다양한 정책을 가지는 메모리 할당기 클래스를 만들면 된다.
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
	vector<int> v(4, &ma); // 메모리 할당 정책을 생성자 인자로 전달
}



