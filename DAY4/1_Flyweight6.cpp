#include <string>
#include <string_view> // C++17

// 함수 인자로 문자열을 받고 있습니다.(읽기만 하기 위해서)
// => 최선의 코드를 찾아 봅시다.

void f1(std::string s) {}
void f2(const std::string& s) {}
void f3(std::string_view  sv) {}

int main()
{
	std::string s = "abcd";
	f2(s);
	f3(s);
}