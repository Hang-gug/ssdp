#include <iostream>
#include <string>
#include <conio.h>


// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - template method ����
// 2. ���ϴ� ���� �ٸ� Ŭ������ - strategy ����

// "���ؾ� �Ѵ�" => ��ü �����ؾ� �Ѵ� => ���� �����̾�� �մϴ�.
// �������̽� �ʿ�

struct IValidator
{
	virtual bool validate(const std::string& data, char c) = 0;
	virtual bool is_complete(const std::string& data) {return true;}
	virtual ~IValidator() {}
};

// �ֹ� ��� ��ȣ : 931   1      Ȯ��


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

			if ( val == nullptr || val->validate(data, c) )	// ���� ��ȿ�� ���θ�
											// �ٸ� Ŭ������ ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// ���� ���� ��ȿ���� Ȯ���ϴ� �پ��� ��å�� ���� "Validator" �� �����մϴ�.

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
	e.set_validator(&v);	// edit �� ���� ��ȿ�� ��å�� ���� ��ü ����

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


