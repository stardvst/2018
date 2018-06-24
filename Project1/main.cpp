#include <iostream>

// not UB
// inits a, x, then b
struct Wrinkle
{
	Wrinkle(int i) : a(++i), b(++i), x(++i)
	{
		std::cout << a << ' ' << b << ' ' << x << '\n';
	}

private:
	int a;
	int x;
	int b;
};

int main()
{
	Wrinkle w(0);

	std::cin.get();
	return 0;
}
