#include <iostream>

struct A
{
	void foo() const
	{
		std::cout << "A's this: " << std::showbase << std::internal << std::hex << this << '\n';
	}
	char data1[32];
};

struct B
{
	void bar() const
	{
		std::cout << "B's this: " << std::showbase << std::internal << std::hex << this << '\n';
	}
	char data2[64];
};

struct C : A, B {};

void call_by_ptr(const C& obj, void (C::*mem_fn)() const)
{
	void *data[2];
	std::memcpy(data, &mem_fn, sizeof(mem_fn));
	std::cout << "------------------------------\n"
		"Object ptr:\t" << &obj <<
		"\nFptr:\t" << data[0] <<
		"\nPtr adj:\t" << data[1] << '\n';
	(obj.*mem_fn)();
}

int main()
{
	C obj;
//	call_by_ptr(obj, &C::foo);
//	call_by_ptr(obj, &C::bar);

	std::cout << sizeof(&C::foo);

	std::cin.get();
	return 0;
}