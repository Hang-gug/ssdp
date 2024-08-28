#include <memory>

int main()
{
	// C++ 표준에 std::shared_ptr 이라는 스마트 포인터가 있는데..
	// sp 만들지 말고, 이것을 사용하면 안되나요 ??

	std::shared_ptr<int> p1(new int);	// ok
										// p1 파괴될때 소멸자가 delete

	std::shared_ptr<ICalc> p2( load_proxy() ); // ???

}