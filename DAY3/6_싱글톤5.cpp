#include <iostream>
#include <mutex>

// RAII ( C++ IDioms )
// 자원의 할당/해지는 반드시 생성자/소멸자에 의존해라
// 이기법을 사용하면
// "자원의 할당은 자원관리 객체가 초기화 될때 이다."
// "Resource Acquision Is (자원관리객체가) Initialization"


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
//		lock_guard<std::mutex> g(mtx); // <== RAII 핵심
							// 1. g의 생성자에서 mtx.lock()
							// 2. g의 소멸자에서 mtx.unlock()
							// 3. 예외가 발생해서 catch 로 이동할때도
							//	  g의 소멸자는 호출됩니다.즉, unlock 수행
							//    "stack unwinding" 이라는 개념
							// 4. {} 을 사용하면 원하는 시점에 unlock 도 가능
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

