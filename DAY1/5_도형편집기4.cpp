#include <iostream>
#include <vector>

// #1. �����丵(Refactoring) ���� ���Ǵ� ������ ��� �Դϴ�.
//     �ǹ̸� ������ ������

//     "Replace Conditional With Polymorphism"
//      ���(if, switch) �� ������(�����Լ�)�� �����ض�
//		2-1.cpp �� 2-2.cpp �� �����ض�. 


// #2. ������ �����̶� ?
// => 1995�⿡ �߰��� å�� ����, 4���� ����
// => "GoF's design pattern" ���� �˻��� �̹��� ����
// => ��� �����ϴ� �ڵ� ����� "�̸��� �ο�" �Ѱ�
// => 23���� �̸� �ο�
// => �̹� �����ϴ� ����� "���ƴ�"�� �ǹǷ� "Gangs Of Four" �� ���ڷ�
//    "GOF's design pattern"


// #3. prototype
// => ��ü�� ���纻�� ���鶧 ����ϴ� ����
// => clone() �����Լ� 
// => 4������ ����ε� ���� ����.

// #4. "���� ���α׷��� Undo/Redo" �� �������� ??
// => �̹� �θ� �˷��� "Undo/Redo" ����� ���� �մϴ�.
// => ����, ��� �ϸ� �ɱ� ? ������� ����..
// => "Command" ������ ���� �˴ϴ�.
// => 4������ ����!!


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw Shape\n"; }


	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	// �ڽ��� ���纻�� ����� �����Լ��� ���� �����ϰ� Ȱ��˴ϴ�.
	virtual Shape* clone()
	{
//		Shape* s = new Shape;   // ���ο� ������ ����
//		s->color = this->color; // ���� �����ϰ� �����ؼ�
//		return s;				// ��ȯ �մϴ�.

		// �׷���, C++������ ���� �����ڸ� ����ϸ� �˴ϴ�.
		return new Shape(*this);
	}
};


class Rect : public Shape
{
public:
	void draw() { std::cout << "draw Rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw Circle\n"; }

	virtual Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ �����ұ�� ? ";

			int k;
			std::cin >> k;

			// k ��° ������ ������ ���ʿ� ����.
			// => "Tell, Don't ask" ��Ģ
			v.push_back(v[k]->clone()); // ������!!!
							// ���ο� ���� Ŭ������ �߰� �Ǿ
							// �� �ڵ�� ������ �ʿ� ����.
							// ��, ���ο� ���� Ŭ���������ڴ�
							// clone() �� �����ؾ� �Ѵ�.

		}
	}
}




