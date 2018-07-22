#include <iostream>
#include <memory>

int main()
{
	auto p = std::make_unique<int>(64);

	auto lambda = [ptr=move(p)]
	{
		std::cout << *ptr;
	};
	
	lambda();

	// can't use anymore...
	// std::cout << *p;

	std::cin.get();
	return 0;
}