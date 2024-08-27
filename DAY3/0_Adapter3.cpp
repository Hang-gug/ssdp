// 디자인 패턴을 계속 공부하면 
// => 어느 순간, 다양한 패턴이 유사해 보이기 시작합니다.
// => 이때는 항상 "의도" 를 생각하세요

// decorator vs object adapter 는 코드가 유사해 보입니다.

// Decorator
class ZipDecorator : public Stream
{
	Stream* stream;
public:
	ZipDecorator(Stream* s) : stream(s) {}

	void write(const std::string& s) override
	{
		auto data = "[ " + s + " 압축됨 ]";

		stream->write(data);
	}
};

// ObjectAdapter
class ObjectAdapter : public Shape
{
	TextView* tview;
public:
	ObjectAdapter(TextView* t) : tview(t) {}

	void draw() override
	{
		tview->show();
	}
};


// Decorator : 의도는 기능의 추가, 인터페이스는 변경되지 않는다.
FileStream fs("a.txt");
ZipDecorator zd(&fs);

fs.write("hello");
zd.write("hello"); // original 객체와 동일한 함수 !!!


// Adapter : 의도는 인터페이스의 변경, 기능이 추가되는 것은 아닙.
TextView tv("hello");
ObjectAdapter oa(&tv);

tv.show();
oa.draw(); // original 객체와 다른 인터페이스, 기능은 동일
