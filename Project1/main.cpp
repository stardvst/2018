#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec { 4,7,9,3 };

	// T *const
	const std::vector<int>::iterator it = vec.begin();
	std::cout << *it << '\n';

	// try to modify iterator, and fail
	//it = vec.end();
	// now modify value
	*it = 10;
	std::cout << *(vec.begin()) << '\n';

	// const T *
	std::vector<int>::const_iterator cit = vec.begin();

	// try to modify value, and fail
	//*cit = 8;
	// now modify iterator
	cit = vec.begin() + 2;
	std::cout << *cit << '\n';


	std::cin.get();
	return 0;
}
