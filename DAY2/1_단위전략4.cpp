#include <stdlib.h>
#include <iostream>

// 방법 #3. policy base design(단위전략) 을 사용해 봅시다.

// 인터페이스

// 장점 : 약한 결합을 통해서 교체 가능한 설계가 가능하다.

// 단점 : 결국 가상함수이므로 메모리 오버헤드와 호출시 성능 저하가 있다




// std::allocator : C++ 표준 메모리 할당기
//					내부적으로 new/delete 사용.
#include <memory>   // 이 헤더 필요

template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff = nullptr;
	int size;

//	MyAllocator<T> alloc; // allocator 이름을 직접 사용
						  // 강한 결합. 교체 불가능.

	Alloc alloc; // 템플릿 인자로 메모리 할당기 타입을 전달
				 

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
	T* allocate(std::size_t sz) 
	{
		return static_cast<T*>(malloc(sizeof(T) * sz));
	}
	void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}
};

int main()
{
	vector<int, MyAllocator<int> > v(4); 
}



