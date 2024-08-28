#include <memory>

int main()
{
	// C++ ǥ�ؿ� std::shared_ptr �̶�� ����Ʈ �����Ͱ� �ִµ�..
	// sp ������ ����, �̰��� ����ϸ� �ȵǳ��� ??

	std::shared_ptr<int> p1(new int);	// ok
										// p1�� ���������� �Ҵ�� �޸� �ּҺ���
										// ��������� �����ϴ� ��ɵ� ����.
										// p1 �ı��ɶ� �Ҹ��ڿ��� ��������� ����
										// 0 �̵Ǹ� delete
				// �׷���, ���ڵ�� "�������Ͽ��� new �ϰ�
				//				   "�������Ͽ��� delete �Ѱ�"

	std::shared_ptr<ICalc> p2( load_proxy() ); // �̷��� �ϸ� �ȵ˴ϴ�.
				// DLL ���� new �Ѱ��� ���������� delete �Ѱ�

	sp<ICalc> p3(load_proxy());
				// �Ҹ��ڿ��� delete �� �ƴ� Release() ȣ��
				// Release �� DLL �ȿ� �ְ�, �ű⼭ delete 

}