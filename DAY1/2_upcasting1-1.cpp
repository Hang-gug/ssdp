// 2_upcasting1-1.cpp

// 7 page

class Animal
{
public:
	int age;
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

	Animal* pa = &a;

	// static_cast : ������ �ð� ĳ����
	//				 �߸��Ǿ����� �������� �ʰ�, ������ ���
	Dog* p = static_cast<Dog*>(pa);
}











