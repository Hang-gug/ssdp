// 아래 매크로는 VS 에서 fopen 사용시 나오는 경고 제거
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class FileStream
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

	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");

	PipeStream ps("my named pipe");
	ps.write("hello");

}
