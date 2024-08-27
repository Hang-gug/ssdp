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
		printf("%s 쓰기\n", s.c_str());
	}
};

class EncryptDecorator : public Stream
{
	Stream* original;	// 이미 만들어진 객체를 가리키는 포인터
						// 기능 추가의 대상
public:
	EncryptDecorator(Stream* s) : original(s) {}

	// 이제 모든 Stream 관련 함수를 제공하는데,,
	// 데이타를 암호화 한후에 original 에 전달하면 됩니다.
	void write(const std::string& s) override
	{
		auto data = "[ " + s + " ] 암호화됨";

		original->write(data);
	}
};


class ZipDecorator : public Stream
{
	Stream* original;	
public:
	ZipDecorator(Stream* s) : original(s) {}


	void write(const std::string& s) override
	{
		auto data = "[ " + s + " ] 압축됨";

		original->write(data);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");	// 파일에 쓰기

	EncryptDecorator ed(&fs);
	ed.write("hello");	// 1. 암호화 기능 추가
						// 2. fs.wirte(암호화된 데이타)

	ZipDecorator zd(&ed);
	zd.write("hello");  // 1. 데이타 압축기능 추가
					    // 2. ed.write(압축된 데이타)
}

// 구글에서 "C# Stream" 검색 해 보세요
// "이미지 보기" 선택