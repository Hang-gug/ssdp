class Animal 
{
public:
	static void foo(Animal* obj) 
	{
		obj->impl_foo();
	}
	virtual void impl_foo() {}
};
class Dog : public Animal 
{	
	virtual void impl_foo() {}
};

int main()
{
	Animal::foo();
	Dog:foo();

	Animal* p = &d;
	p->cry(); // 
//	p->foo(); // Animal::foo();
	p->foo(p);
}
