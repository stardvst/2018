#include <iostream>

struct C
{
	C() = default;
	C(const C&) { std::cout << "A copy was made.\n"; }
};

C f()

{
	// calls copy ctor
	/*C c;
	return c;*/

	// doesn't call copy ctor
	return C();
}

int main()
{
	std::cout << "Hello World!\n";
	C obj = f();

	std::cin.get();
	return 0;
}