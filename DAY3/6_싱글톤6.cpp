#include <iostream>
#include <mutex>


// CRTP : Curiously Recurring Template Pattern

// => ��� Ŭ���� ���鶧 �̷��� ������� �Ļ� Ŭ���� �̸��� ����ϰ� �ϴ� ���
// => ������ ���ø� ���ڷ� ���� �޴� ��
// => ���� ���� �����ϴ� ���(C++20 �� Range ���̺귯���� �̱�� ���)

template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static T* sinstance;     // <<== !!
	static std::mutex mtx;
public:
	static T& get_instance() // <<== !!
	{
		std::lock_guard<std::mutex> g(mtx);

		if (sinstance == nullptr)
			sinstance = new T; // <<== !!

		return *sinstance;
	}
};

template<typename T> T* Singleton<T>::sinstance = nullptr;  // <<== !!
template<typename T> std::mutex Singleton<T>::mtx;

// Mouse Ŭ������ ���� ���� ���� ����� �̱������� �ϰ� �ʹ�
class Mouse : public Singleton< Mouse  >
{

};


int main()
{
	Mouse& c1 = Mouse::get_instance();

}

// github.com/aosp-mirror     �����ؼ�
//			  ( android open source project, �� �ȵ���̵�ҽ��ڵ�)

// platform system core �������丮 ������

// libutils/include/utils/singleton.h ã�� ������
