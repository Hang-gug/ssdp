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

// IMP3, IPod : ���� ������ ���� Ŭ����(�������̽�)

// �䱸������ ���� �߻��ϴ� ���, ������ ���� ����ϰ� ��������
// �������� ���� �����մϴ�.
// "����ڰ� ����ϴ� ������ Ŭ������ �����ڴ� ��"

class MP3
{
	IMP3* impl;
public:
	MP3(IMP3* p = nullptr) : impl(p)
	{
		if (impl == nullptr)
			impl = new IPod;
	}
	// ���� �ٽ� ����� impl �� �����ϰ� �˴ϴ�.
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


