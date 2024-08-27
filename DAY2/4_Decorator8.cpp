int main()
{
	// Decorator 대신 필터를 사용하면 안되나요 ?
	FileStream fs("a.txt");
	
	fs.add_fillter(암호화 필터);
	fs.add_fillter(압축 필터);

	fs.write("hello");	// 입력된 데이타를
						// 추가된 필터들을 통해서 데이타 가공하고
						// 화면에 쓴다.

	// Decorator : original 에 직접 접근할수 있다.
	// 하지만 위 코드는 original(기능 추가되기전 객체)를 접근할수 없다.

	fs.write("aaaa"); // 암호화 하지 않고 쓰고 싶다.??

}
// 파이썬의 @ 를 자세히 공부해 보세요. "decorator" 라고 부릅니다.
// => 코드는 다르지만, 결국 기능추가 입니다

