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
	virtual bool is_complete(const std::string& data) { return true; }
	virtual ~IValidator() {}
};

// �ֹ� ��� ��ȣ : 931   1      Ȯ��


class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		data.clear();

		while (1)
		{
			char c = _getch();

			if (c == 13) break; 

			if ( isdigit(c) )
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


