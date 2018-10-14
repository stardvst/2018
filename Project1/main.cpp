#include <iostream>
#include <vector>

struct A
{
	void foo()
	{
		static int i;
		++i;

		std::cout << i << '\n';
	}
};

int main()
{
	A o1, o2, o3;

	o1.foo();
	o2.foo();
	o3.foo();
	o1.foo();

	std::cin.get();
	return 0;
}