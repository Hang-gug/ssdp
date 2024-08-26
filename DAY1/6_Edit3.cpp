#include <iostream>
#include <string>
#include <conio.h>


// 변하는 것을 분리하는 2가지 방법
// 1. 변하는 것을 가상함수로 - template method 패턴
// 2. 변하는 것을 다른 클래스로 - strategy 패턴

// "변해야 한다" => 교체 가능해야 한다 => 약한 결합이어야 합니다.
// 인터페이스 필요

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool is_complete(const std::string& data) {return true;}
	virtual ~IValidator() {}
};

// 주민 등록 번호 : 931   1      확인


class Edit
{
	std::string data;
	
	IValidator* val = nullptr;
public:
	void set_validator(IValidator* v) { val = v; }

	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if ( val->validate(data, c) )	// 값의 유효성 여부를
											// 다른 클래스에 위임
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


