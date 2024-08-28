#include "monitor.h"

// command 패턴 
// => 명령을 캡슐화 한다.
// => 어떤 일을 수행하게 하는 클래스를 만드는 것

class BrightCommand
{
	Monitor& m;
	int value;
	int old_value;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() 
	{ 
		old_value = m.get_brightness();
		m.set_brightness(value);
	}
	void undo()
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;

	// #1. 그 일을 직접 하거나

	int old_value = m.get_brightness();

	m.set_brightness(90);  // A

	// 여기서 모니터 m 을 A의 실행 이전 상태로 복구해 보세요
	m.set_brightness( ? );  




	// #2. Command 패턴 사용
	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}