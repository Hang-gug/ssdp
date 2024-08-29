#include <string>
#include <string_view> // C++17

int main()
{
	std::string s = "abcd";

	// #1.
	std::string      ss = s;
	std::string_view sv = s;

	// #2.
	std::string      ss1 = "abcd";
	std::string_view ss2 = "abcd";
}