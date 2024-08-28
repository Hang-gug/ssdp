#include <iostream>
#include <mutex>

// RAII ( C++ IDioms )
// �ڿ��� �Ҵ�/������ �ݵ�� ������/�Ҹ��ڿ� �����ض�
// �̱���� ����ϸ�
// "�ڿ��� �Ҵ��� �ڿ����� ��ü�� �ʱ�ȭ �ɶ� �̴�."
// "Resource Acquision Is (�ڿ�������ü��) Initialization"


template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard()             { mtx.unlock(); }
};

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;


	static Cursor* sinstance;
	static std::mutex mtx;
public:


	static Cursor& get_instance()
	{
	
		std::lock_guard<std::mutex> g(mtx);
//		lock_guard<std::mutex> g(mtx); // <== RAII �ٽ�
							// 1. g�� �����ڿ��� mtx.lock()
							// 2. g�� �Ҹ��ڿ��� mtx.unlock()
							// 3. ���ܰ� �߻��ؼ� catch �� �̵��Ҷ���
							//	  g�� �Ҹ��ڴ� ȣ��˴ϴ�.��, unlock ����
							//    "stack unwinding" �̶�� ����
							// 4. {} �� ����ϸ� ���ϴ� ������ unlock �� ����
//		mtx.lock();

		if (sinstance == nullptr)
			sinstance = new Cursor;
		//		mtx.unlock();
	

		return *sinstance;
	}


};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;

int main()
{
	Cursor& c1 = Cursor::get_instance();

}

