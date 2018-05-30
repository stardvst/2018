#include <iostream>

class Foo
{
public:
	static Foo *create()
	{
		return new Foo;
	}
	~Foo() {}

	// error message says "... is a deleted function" - very clear
	Foo(const Foo &) = delete;
	Foo &operator=(const Foo &) = delete;

private:

	// error message says "... is private" - not clear whether it's just private or not allowed to do
	Foo(const Foo &) {}
	Foo &operator=(const Foo &) {}

	Foo() { std::cout << "created\n"; }
};

void f(Foo foo)
{
}

int main()
{
	Foo *foo = Foo::create();
	f(*foo);

	std::cin.get();
	return 0;
}