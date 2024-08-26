#include <iostream>
#include <string>
#include <conio.h>

// Validation 정책은 사용자가 변경할수 있어야 합니다.

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에서 변해야 하는 곳이 있다면
	//    분리되어야 한다.
	// => 변하는 것을 별도의 가상함수로  분리한다.

	virtual bool validate(char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if ( validate(c) ) // 값의 유효성 확인(변하는것)을 가상함수에 의존
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


