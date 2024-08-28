#include <iostream>
#include <mutex>


// CRTP : Curiously Recurring Template Pattern

// => 기반 클래스 만들때 미래에 만들어질 파생 클래스 이름을 사용하게 하는 기술
// => 원리는 템플릿 인자로 전달 받는 것
// => 요즘 아주 유행하는 기술(C++20 의 Range 라이브러리가 이기술 사용)

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

// Mouse 클래스도 위와 같은 힙에 만드는 싱글톤으로 하고 싶다
class Mouse : public Singleton< Mouse  >
{

};


int main()
{
	Mouse& c1 = Mouse::get_instance();

}

// github.com/aosp-mirror     접속해서
//			  ( android open source project, 즉 안드로이드소스코드)

// platform system core 레포지토리 선택후

// libutils/include/utils/singleton.h 찾아 보세요
