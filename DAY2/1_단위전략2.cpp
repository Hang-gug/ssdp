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
		buff = new T[size];
	}
	~vector()
	{
		delete[] buff;
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

int main()
{
	vector<int> v(4);
}


