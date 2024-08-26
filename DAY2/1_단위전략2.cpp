// ��� #1. template method ������ ����� ���ô�.
// => ���ϴ� ���� �����Լ���!!
// => vector ���� ���ϰ� ���� ���� "�޸� �Ҵ�� ���� ���"

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

	// �޸� �Ҵ�/������ å������ �����Լ� ����
	// => vector �� ��� ��� �Լ����� �޸��Ҵ�/������ �ʿ��ϸ�
	//    �Ʒ� �����Լ� ���
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


