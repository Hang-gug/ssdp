int main()
{
	// Decorator 대신 필터를 사용하면 안되나요 ?
	FileStream fs("a.txt");
	
	fs.add_fillter(암호화 필터);
	fs.add_fillter(압축 필터);

	fs.write("hello");	// 입력된 데이타를
						// 추가된 필터들을 통해서 데이타 가공하고
						// 화면에 쓴다.

}