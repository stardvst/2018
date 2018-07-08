#include <iostream>

struct A
{
	static A inst;
};

int main()
{
	A a;
	std::cout << sizeof a;

	std::cin.get();
	return 0;
}