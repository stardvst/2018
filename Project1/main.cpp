#include <iostream>
#include <array>

struct NonMovable
{
	NonMovable(int i) { std::cout << "Non movable " << i << " created.\n"; }
	NonMovable(const NonMovable &) = delete;
	NonMovable(NonMovable &&) = delete;

	std::array<int, 1024> arr;
};

NonMovable make()
{
	// c++14 will try to move this temp
	// C++17 will construct in place; however, this won't work:
	// auto obj = NonMovable(42);
	// return obj;
	return NonMovable(42);
}

int main()
{
	auto largeNonMovObj = make();

	std::cin.get();
	return 0;
}
