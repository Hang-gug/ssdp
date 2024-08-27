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
		printf("deallocate %p, %zd cnt\n", p, sz);
		free(p);
	}

	// 위 2개 위에 아래 3개도 필요 합니다.
	// => 관례적인 코드이므로 항상 복사해서 사용하면 됩니다.
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
							// generic 생성자 라는 개념. 
};


int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "-----------------" << std::endl;

	v.resize(4); // 이순간 4개 버퍼 할당

	std::cout << "-----------------" << std::endl;

	v.resize(8); // 1. 8개 할당
				 // 2. 4개 버퍼내용 => 8개 버퍼에 복사
				 // 3. 4개 버퍼 제거

	std::cout << "-----------------" << std::endl;

	v.resize(6);	// 이순간 어떻게 동작할까요 ?
					// 1. 6개 메모리 할당하고, 8개는 제거
					// 2. 그냥, 8개 계속 사용하고, size 변수만 6으로

	std::cout << "-----------------" << std::endl;
}
