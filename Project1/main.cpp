#include <iostream>

#include "Class.h"

int main()
{
	try
	{
		Vector<int> vector;
		vector.insert(8);
		vector.insert(3);
		vector.insert(1);
		vector.insert(7);
		vector.insert(2);

		for (auto i : vector)
			std::cout << i << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cin.get();
	return 0;
}