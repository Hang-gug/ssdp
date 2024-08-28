#define USING_GUI
#include "cppmaster.h"

// Client �����ڴ� ���������ڿ��� 2���� ������ �޾ƾ� �մϴ�.

// ICalc.h       : �������̽��� �ִ� ���
// CalcProxy.dll : Proxy ���� �ڵ尡 �ִ� �������

#include "ICalc.h"

ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll"); 

	using F = ICalc*(*)(); // �Լ� ������ Ÿ��

	F f = (F)ec_get_function_address(addr, "create");

	return f();
}
int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





