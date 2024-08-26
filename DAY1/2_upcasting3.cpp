// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

// 활용 #2. 동종을 처리하는 함수 만들기. 
// void NewYear(Dog* pDog) // Dog 객체만 인자로 받겠다는 의도
void NewYear(Animal* p)    // 모든 동물 객체를 인자로 받을수 있다.
{
	++(p->age); 
	
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
}











