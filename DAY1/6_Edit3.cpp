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

			if (c == 13 && (val == nullptr || val->is_complete(data))  ) break;

			if ( val == nullptr || val->validate(data, c) )	// 값의 유효성 여부를
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

// 이제 값의 유효성을 확인하는 다양한 정책을 가진 "Validator" 를 제공합니다.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int v = 9999) : limit(v) {}

	bool validate(const std::string& s, char c) override
	{
		return isdigit(c) && (limit == 9999 || s.size() < limit);
	}

	bool is_complete(const std::string& s) override
	{
		return s.size() == limit;
	}
};


int main()
{
	Edit e;

	LimitDigitValidator v(5);
	e.set_validator(&v);	// edit 에 값의 유효성 정책을 담은 객체 전달

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


