#include <iostream>

void print()
{
	std::cout << "print\n";
}

void(*p)() = print;
void (**pp)() noexcept = &p;

struct S
{
	typedef void(*p)();
	operator p() { std::cout << "operator p\n"; return nullptr; }
};

int main()
{
	(*pp)();

	void(*q)() /*noexcept*/ = S();

	std::cin.get();
	return 0;
}
