#include <iostream>

struct C
{
	C() {}
	C(const C&) { std::cout << "Hello World!\n"; }
};

void f()
{
	C c;
	throw c; // copying the named object c into the exception object.
			 // It is unclear whether this copy may be elided.
}

int main()
{
	try
	{
		f();
	}
	catch (C c)
	{
		c;
		// copying the exception object into the temporary in the exception declaration.
		// It is also unclear whether this copy may be elided.
	}             

	std::cin.get();
	return 0;
}