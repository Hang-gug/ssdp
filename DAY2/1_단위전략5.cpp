#include <iostream>
#include <vector>

// STL 컨테이너에 전달할 메모리 할당기 만들기

// 1. 반드시 템플릿일 필요는 없지만, 다양한 타입에 대해서
//    사용해야 하므로 일반적으로는 template 으로 작성

// 2. 약속된 함수를 제공해야 합니다.
// => 인터페이스가 아닌 문서(C++ 표준문서)로 약속되어 있습니다.

template<typename T> 
class debug_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);

		printf("allocate %p, %zd cnt\n", p, sz);

		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		free(p);
	}

};


int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4);

	std::cout << "-----------------" << std::endl;

	v.resize(8);

	std::cout << "-----------------" << std::endl;
}
