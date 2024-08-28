#include "monitor.h"

// command 패턴 
// => 명령을 캡슐화 한다.
// => 어떤 일을 수행하게 하는 클래스를 만드는 것

class BrightCommand
{
	Monitor& m;
	int value;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() { m.set_brightness(value); }
};

int main()
{
	Monitor m;

	// #1. 그 일을 직접 하거나
	m.set_brightness(90);

	// #2. Command 패턴 사용
	BrightCommand cmd(m, 90);
	cmd.execute();
}