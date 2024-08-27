#include <iostream>
#include <vector>

// STL 컨테이너에 전달할 메모리 할당기 만들기

// 1. 반드시 템플릿일 필요는 없지만, 다양한 타입에 대해서
//    사용해야 하므로 일반적으로는 template 으로 작성

template<typename T> 
class debug_alloc
{
public:

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
