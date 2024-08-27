#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

class EncryptDecorator : public Stream
{
	Stream* original;	// �̹� ������� ��ü�� ����Ű�� ������
						// ��� �߰��� ���
public:
	EncryptDecorator(Stream* s) : original(s) {}

	// ���� ��� Stream ���� �Լ��� �����ϴµ�,,
	// ����Ÿ�� ��ȣȭ ���Ŀ� original �� �����ϸ� �˴ϴ�.
	void write(const std::string& s) override
	{
		auto data = "[ " + s + " ] ��ȣȭ��";

		original->write(data);
	}

};



int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	EncrpytDecorator ed(&fs);
	ed.write("hello");	


	ZipDecorator zd(&ed);
	zd.write("hello");
}
