// 6_Bridge1 - 90 page
#include <iostream>

struct IMP3
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual ~IMP3() {}
};
class IPod : public IMP3
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

// IMP3, IPod : 실제 구현을 가진 클래스(인터페이스)

// 요구사항이 자주 발생하는 경우, 구현을 직접 사용하게 하지말고
// 간접층을 만들어서 제공합니다.
// "사용자가 사용하는 별도의 클래스를 만들자는 것"

class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr)
			impl = new IPod;
	}
	// 이제 핵심 기능은 impl 에 의존하게 됩니다.
	void play() { impl->play(); }
	void stop() { impl->stop(); }
};


class People
{
public:
	void use(IMP3* p) 
	{
		p->play();
		p->stop();

		p->play_one_minute();
	}
};
int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


