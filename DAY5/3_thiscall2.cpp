class Dialog
{
public:
	void close(int code) {}
//	void close(this Dialog& self, int code) {} // ���ڵ�� ����
											   // this�� �Ͻ��� �߰��� �ƴ�
												// �����ڰ� ����� ǥ��
												// "python �� ����"

	static void close2(int code) {}
};

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo;			 // ok 	
	void(*f2)(int) = &Dialog::close; // error. close �� ����Լ��̹Ƿ�
									 // this �� �߰��� �Լ�.

	void(*f3)(int) = &Dialog::close2; // ok.. static ��� �Լ��� this �߰��ȵ�
}

// �ٽ� #1. �Ϲ� �Լ� �����Ϳ� ����Լ��� �ּҸ� ������ �����ϴ�.(this ����)

// �ٽ� #2. �Ϲ� �Լ� �����Ϳ� static ����Լ��� �ּҸ� ������ �ֽ��ϴ�.