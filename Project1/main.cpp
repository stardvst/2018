#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "ctor\n";
	}

	~A()
	{
		std::cout << "dtor\n";
	}
};

// global object
A a;

int main()
{
	auto a = new A;
	static auto b = new A;

	std::cin.get();

	// both dtors are called

	return 0;
}
