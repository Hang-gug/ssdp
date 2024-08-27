// ��� #2. strategy ������ ����� ���ô�.
// => ���ϴ� ���� �ٸ� Ŭ������
// => �޸� �Ҵ� ������ ������ Ŭ������ ���� ���

// �޸� �Ҵ� ��å�� �������̽�
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



