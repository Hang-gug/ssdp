// 방법 #2. strategy 패턴을 사용해 봅시다.
// => 변하는 것을 다른 클래스로
// => 메모리 할당 해지를 별도의 클래스로 만들어서 사용

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
};

int main()
{
	vector<int> v(4); 
}



