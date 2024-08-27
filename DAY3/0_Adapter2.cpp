#include <iostream>
#include <string>
#include <vector>

class TextView
{
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};



//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// Adapter 패턴 
// => 기존 클래스의 인터페이스(함수 이름)을 변경해서 
//    시스템에 맞도록 변경하는 패턴

// 종류
// 클래스 어답터 : 클래스의 인터페이스를 변경
// 객체   어답터 : 객체의 인터페이스를 변경

// 클래스 어답터
class Text : public TextView, public Shape
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() override
	{
		TextView::show();
	}
};

// 객체 어답터
class ObjectAdapter : public Shape
{
	TextView* tview;
public:
	ObjectAdapter(TextView* tv) : tview(tv) {}


};



int main()
{
	std::vector<Shape*> v;

	TextView tv("ABCD"); // TextView : 클래스(타입)
						 // tv       : 객체(변수)

	// #1. 이미 만들어진 "객체 tv" 를 v에 넣을수 있을까 ?

//	v.push_back( &tv ); // error. tv 는 Shape 로 부터 파생되지 않았다

	// #2. 위에 만든 "Text" 를 사용해서 "tv 를 v에 넣을수" 있을까 ?
	// => 할수 없다!!
	// => Text 는 "클래스의 인터페이스를 변경하는 클래스 어답터" 이다
}






