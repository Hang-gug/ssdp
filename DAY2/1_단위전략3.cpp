// ��� #2. strategy ������ ����� ���ô�.
// => ���ϴ� ���� �ٸ� Ŭ������
// => �޸� �Ҵ� ������ ������ Ŭ������ ���� ���

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



