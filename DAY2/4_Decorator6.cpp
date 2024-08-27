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

int main()
{
	// 파일에 쓸때 "암호화"하는 기능이 필요 하다!!
	// => 최선의 방법을 생각해 봅시다.!!

	// 방법 #1. 라이브러리 사용자가 직접 "암호화 한후"에 FileStream 에 Write
	// => 좋지 않습니다. 라이브러리가 제공해야 합니다!


	// 방법 #2. FileStream 을 제공하고, 
	//			파생 클래스인 EncrpytFileStream 도 라이브러리에서 제공하자.
	// 
	// 단점 1. NetworkStream, PipeStream 도 모두 파생클래스 필요
	// 
	// 단점 2. 암호화 뿐아니라 데이타압축도 필요하면 "ZipFileStream"도 필요하고
	//         압축, 암호화 모두 지원하려면 
	//		   다시 다중상속된 클래스 필요


	// 방법 #3. Decorator 패턴을 사용하면 어떨까 ??

	FileStream fs("a.txt");
	fs.write("hello");

	EncrpytDecorator ed(&fs); // File 뿐 아니라 Network 도 가능
	ed.write("hello");	// 


	ZipDecorator zd(&ed);
	zd.write("hello");
}
