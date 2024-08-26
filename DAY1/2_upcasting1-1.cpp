// 2_upcasting1-1.cpp
#include <iostream>
// 7 page

class Animal
{
public:
	int age;

	virtual ~Animal() {} // ���� �Ҹ��� => ���� �ð��� �ڼ���..!
};


class Dog : public Animal
{
public:
	int color;
};

int main()
{
	Animal a;
	Dog d;

//	Animal* pa = &a;
	Animal* pa = &d;

	// static_cast : ������ �ð� ĳ����
	//				 �����Ϸ����� ����ش޶�� ��û�ϴ°�
	//				 ���� ���� ���� �ڵ�� ����. ������� ����.
	//				 �߸��Ǿ����� �������� �ʰ�, ������ ���
	//				 => ������ �ð����� ��� ��ü�� ����Ű�� �� �˼� ����
	//				 => ������ �ð��� �����Ҽ��� ����.
	
	// ���� �Ʒ� �ڵ�� �׻� �����ؼ� �ּҰ� ��ȯ�ȴ�
	Dog* p = static_cast<Dog*>(pa);
	std::cout << pa << std::endl; // ok 
	std::cout << p  << std::endl; // ok. ���� ����.
								  
//	p->color = 0; // ������ �̷��� ����ϸ� �߸��� �ڵ�"undefined"


	// dynamic_cast : ����ð� ĳ����
	//				  ����ð��� ���� ��ü�� ������ �´� ��츸 ���
	//				  "����"�ؾ� �ϹǷ� ������� ����
	//					��, dynamic_cast �� ����Ϸ���
	//					"�ݵ�� �����Լ��� �Ѱ��̻�" �ִ� Ÿ�Ը� �����մϴ�.
	Dog* p1 = dynamic_cast<Dog*>(pa);

	std::cout << p1 << std::endl; // pa�� Dog �� ����Ű�� �ʾҴٸ� 0 ��ȯ

	// dynamic_cast �� �����Ҽ� ������
	// => dynamic_cast �� �ǵ��� ������� �������� ���� ������ �Դϴ�.
	// => ���Ŀ� �ڼ��� ����
}











