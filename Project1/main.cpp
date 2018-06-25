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

int main()
{
	auto ob = new A;
	auto arr = new A[10];

	// infinite loop of dtors
	delete[] ob;

	// exception
	delete arr;

	std::cin.get();ddddddddd
}
