#include <memory>

int main()
{
	// C++ ǥ�ؿ� std::shared_ptr �̶�� ����Ʈ �����Ͱ� �ִµ�..
	// sp ������ ����, �̰��� ����ϸ� �ȵǳ��� ??

	std::shared_ptr<int> p1(new int);	// ok
										// p1 �ı��ɶ� �Ҹ��ڰ� delete

	std::shared_ptr<ICalc> p2( load_proxy() ); // ???

}