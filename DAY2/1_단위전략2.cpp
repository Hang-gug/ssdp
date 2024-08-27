#include <stdlib.h>
#include <iostream>
// 방법 #1. template method 패턴을 사용해 봅시다.
// => 변하는 것을 가상함수로!!
// => vector 에서 변하고 싶은 것은 "메모리 할당과 해지 방법"

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

	// 메모리 할당/해지를 책임지는 가상함수 제공
	// => vector 의 모든 멤버 함수에서 메모리할당/해지가 필요하면
	//    아래 가상함수 사용
	virtual T* allocate(std::size_t sz)
	{
		return new T[sz];
	}
	virtual void deallocate(T* p, std::size_t sz)
	{
		delete[] p;
	}
};

// 위 코드의 의도
// vector 의 메모리 할당 방식을 변경하려면
// 파생 클래스를 만들어서 약속된 가상함수를 override 하면됩니다.

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


