// 아래 매크로는 VS 에서 fopen 사용시 나오는 경고 제거
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// 모든 Stream 이 지켜야 하는 규칙을 설계
struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}

	// write 외에도 read, close, open, flush 등의 함수 모양을 약속
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
		printf("%s 쓰기\n", s.c_str() );
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	// 아래 같은 클래스도 있다고 가정해 봅시다.
	/*
	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");

	PipeStream ps("my named pipe");
	ps.write("hello");
	*/

}
