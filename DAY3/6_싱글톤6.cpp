#include <iostream>
#include <mutex>


template<typename T>
class Singleton
{
private:
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
T* Singleton::sinstance = nullptr;  // <<== !!
std::mutex Singleton::mtx;

// Mouse 클래스도 위와 같은 힙에 만드는 싱글톤으로 하고 싶다
class Mouse : public Singleton< Mouse  >
{

};


int main()
{
	Cursor& c1 = Cursor::get_instance();

}

