#include <string>
#include <string_view> // C++17

// �Լ� ���ڷ� ���ڿ��� �ް� �ֽ��ϴ�.(�б⸸ �ϱ� ���ؼ�)
// => �ּ��� �ڵ带 ã�� ���ô�.

void f1(std::string s) {}
void f2(const std::string& s) {}
void f3(std::string_view  sv) {}

int main()
{
	std::string s = "abcd";
	f2(s);
	f3(s);
}