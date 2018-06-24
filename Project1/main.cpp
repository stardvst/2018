#include <iostream>
#include <gsl/gsl>

int *ret(int n)
{
	if (n > 5) return NULL;
	auto ntt = new int(888);
	return ntt;
}

int main()
{
	int a = 5;
	gsl::not_null<int *> p(&a);

	std::cout << *p;

	//p = nullptr;

	std::cin.get();
}