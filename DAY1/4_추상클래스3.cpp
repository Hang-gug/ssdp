#include <iostream>


// �߻� Ŭ���� : ���Ѿ��ϴ� ��Ģ(���� �����Լ�) �ܿ� �ٸ� ����� �ִ� ���
// ���� ���̽� : ���Ѿ��ϴ� ��Ģ �� �ִ� ���. 
// 
// java, C# : interface, abstract ��� ���� Ű���� ����
// C++      : Ű���� ����, ���� �����Լ� ������ ����

// #1. ī�޶�� ī�޶� ����ڰ� ���Ѿ� �ϴ� ��Ģ�� ���� ���� �մϴ�.
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ� �Ǿ�� �Ѵ�." ��� ǥ������ ����
//       "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�." ��� ǥ�� �մϴ�.

#define interface struct

//class ICamera		// class  : ���� ������ ������ private
struct ICamera	// struct : ���� ������ ������ public
//interface ICamera	// 90��� �����ߴ� ���	
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // �������̽��� �ᱹ�� ��� Ŭ����!!!
						  // ����, �Ҹ��ڸ� �����Լ���!!
};

// ���� ����(tightly coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����
// => Ŭ���� �̸��� ���� ����ϴ� ��
// => ������, ��ü �Ұ����� ������

// ���� ����(loosely coupling)
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ����
// => ��Ģ�� ���� �������̽��� ���ؼ� ����ϴ� ��
// => ������, ��ü ������ ������





// #2. ���� ī�޶� ���, ����ϴ� �ڵ带 �ۼ��Ҽ� �ֽ��ϴ�.
// => ��Ģ��θ� ����ϸ� �˴ϴ�.
class People
{
public:
	void use_camera(ICamera* c) { c->take(); }
};

// #3. ��� ī�޶�� "��Ģ"�� ���Ѿ� �մϴ�.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

	UHDCamera uhc;
	p.use_camera(&uhc); // ok. ���߿� �߰��� ���ο� ī�޶�ü����
						// People �� �������� �ʰ� ��밡��
						// OCP ����!!
}









