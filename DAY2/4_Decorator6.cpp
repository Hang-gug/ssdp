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

int main()
{
	// ���Ͽ� ���� "��ȣȭ"�ϴ� ����� �ʿ� �ϴ�!!
	// => �ּ��� ����� ������ ���ô�.!!

	// ��� #1. ���̺귯�� ����ڰ� ���� "��ȣȭ ����"�� FileStream �� Write
	// => ���� �ʽ��ϴ�. ���̺귯���� �����ؾ� �մϴ�!


	// ��� #2. FileStream �� �����ϰ�, 
	//			�Ļ� Ŭ������ EncrpytFileStream �� ���̺귯������ ��������.
	// 
	// ���� 1. NetworkStream, PipeStream �� ��� �Ļ�Ŭ���� �ʿ�
	// 
	// ���� 2. ��ȣȭ �Ӿƴ϶� ����Ÿ���൵ �ʿ��ϸ� "ZipFileStream"�� �ʿ��ϰ�
	//         ����, ��ȣȭ ��� �����Ϸ��� 
	//		   �ٽ� ���߻�ӵ� Ŭ���� �ʿ�


	// ��� #3. Decorator ������ ����ϸ� ��� ??

	FileStream fs("a.txt");
	fs.write("hello");

	EncrpytDecorator ed(&fs); // File �� �ƴ϶� Network �� ����
	ed.write("hello");	// 


	ZipDecorator zd(&ed);
	zd.write("hello");
}
