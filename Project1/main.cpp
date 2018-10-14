#include <iostream>
#include <vector>

using byVal = struct
{
	int arr[10];
};

void f(byVal a)
{
	std::cout << a.arr[0] << '\n';
	std::cout << &a << '\n';
	a.arr[0] = 10;
	std::cout << a.arr[0] << '\n';
}

int main()
{
	byVal a;
	a.arr[0] = 5;

	std::cout << &a << ' ' << a.arr[0] << '\n';

	f(a);

	std::cout << a.arr[0] << '\n';

	std::cin.get();
	return 0;
}