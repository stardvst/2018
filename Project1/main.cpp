#include <iostream>

struct base
{
	base() { std::cout << value() << std::endl; }
	virtual ~base() {}
	virtual const int value() const { return 0; }
};

struct derived : base
{
	//derived() { std::cout << value() << std::endl; }
	const int value() const override { return 1; }
};

int main()
{
	derived d;
	std::cout << d.value();

	std::cin.get();
}
