#include <iostream>

// unsigned int => num % 2 => 0 or 1

void isOne(int i)
{
	if (i == 1) std::cout << "one\n";
	else std::cout << "not one\n";
}

int main()
{
	struct { int a : 1; } s;
	struct { unsigned int a : 1; } t;

	s.a = 1;
	t.a = 3;

	isOne(s.a);
	isOne(t.a);

	std::cin.get();
	return 0;
}
