#include <iostream>
#include <string>
#include <conio.h>


struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool is_complete(const std::string& data) { return true; }
	virtual ~IValidator() {}
};


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

			if (c == 13 && (val == nullptr || val->is_complete(data))) break;

			if (val == nullptr || val->validate(data, c))	
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};


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
	// =========================
	// strategy
	Edit e;

	LimitDigitValidator v(5);
	e.set_validator(&v);	

	LimitDigitValidator v2(15);
	e.set_validator(&v2);   
	// =========================

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


