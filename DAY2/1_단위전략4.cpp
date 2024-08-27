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
// => 둘다, 클래스가 사용하는 알고리즘(정책)을 다른 클래스로 분리 하는 것

// strategy : 일반적으로 정책 클래스를 "인터페이스"를 통해서 교체

// policy base design : 정책클래스를 "템플릿 인자" 로 교체
// 


//						성능					유연성
// strategy			  : 느리다(가상함수)		실행시간 교체 가능
//											e.set_validator(&v1)
//											e.set_validator(&v2)

// policy base design : 빠르다(인라인도가능)	실행시간 교체할수 없다.
//											객체 생성시만 템플릿 인자로 전달가능


// 디자인 패턴 : 대부분에 객체지향 언어에서 구현 가능한 일반적인 디자인 기술
//			    GoF's design pattern 23개가 가장 유명하고
//				이후 등장하는 추가적인  패턴들도 있음(MVC, MVVM 등...)
// => template method, strategy 등...

// IDioms : 각 언어의 특징을 고려한 디자인 기법
//			(C++ IDioms, Java Idioms 등... )
//			구글에서 "C++ Idioms" 검색후 1번째 링크
// => policy base design, CRTP, object generator