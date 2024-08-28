#include "monitor.h"

// command ���� 
// => ����� ĸ��ȭ �Ѵ�.
// => � ���� �����ϰ� �ϴ� Ŭ������ ����� ��

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

	// #1. �� ���� ���� �ϰų�
	m.set_brightness(90);

	// #2. Command ���� ���
	BrightCommand cmd(m, 90);
	cmd.execute();
}