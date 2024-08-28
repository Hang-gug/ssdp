#include <iostream>
#include <mutex>


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

		if (sinstance == nullptr)
			sinstance = new Cursor;

		return *sinstance;
	}


};
Cursor* Cursor::sinstance = nullptr;
std::mutex Cursor::mtx;


// Mouse 클래스도 위와 같은 힙에 만드는 싱글톤으로 하고 싶다
class Mouse
{

};


int main()
{
	Cursor& c1 = Cursor::get_instance();

}

