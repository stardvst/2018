#include <iostream>

template typename T>
class TD;

template <typename T>
void f(const T &param);

int main()
{
	const int theAnswer = 42;

	auto x = theAnswer; // int 
	auto y = &theAnswer; // const int *

	TD<decltype(x)> xType;
	TD<decltype(y)> yType;

	std::cin.get();
	return 0;
}
