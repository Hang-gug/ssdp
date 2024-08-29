#include <string>
#include <string_view> // C++17

// �Լ� ���ڷ� ���ڿ��� �ް� �ֽ��ϴ�.(�б⸸ �ϱ� ���ؼ�)
// => �ּ��� �ڵ带 ã�� ���ô�.

// void f1(std::string s) {} // worst!!! ���� ������

void f2(const std::string& s) {} // good ������ best �� �ƴ�.!


void f3(std::string_view  sv) {}


int main()
{
	std::string s = "abcd";
	
	// �Ʒ� �ڵ�� ū ���̰� �����ϴ�
	f2(s);
	f3(s);

	// �Ʒ� �ڵ尡 �ٽ� �Դϴ�
	// => ���ڷ� literal �� ���� ������ ���.
	f2("hello");
	f3("hello");
}

// C++17 ���� �Լ��� �б� ���� ���ڿ��� ��������
// const std::string& ���ٴ� std::string_view �� �����ϴ�

// RUST       C++
// str    : std::string_view
// String : std::string
