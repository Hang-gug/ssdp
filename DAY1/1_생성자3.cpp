// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};

// 1. Person 에서 파생된 Student 만들어 보세요
// 2. "int id" 추가해 보세요
// 3. Student 생성자 만들어 보세요
// 4. main 에서 Student 객체 생성해 보세요

class Student : public Person
{
	int id;
public:
	// 아래 코드는 에러
//	Student(int id) : id(id) {} // Student(int id) : Person(), id(id)

	Student(const std::string& name, int age, int id)
		: Person(name, age), id(id) {}
};

int main()
{
	Student s("kim", 30, 15);


	Person p2("kim", 30); // ok. 반드시 초기화해야만 객체 생성 가능


//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
}


