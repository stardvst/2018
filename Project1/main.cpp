#include <iostream>

// is T class?

template <typename T>
struct IsClassT
{
	static bool is;
private:
	template <typename C>
	static bool test(int C::*) { return true; }

	template <typename C>
	static bool test(...) { return false; }
};

template <typename T>
bool IsClassT<T>::is = IsClassT<T>::test<T>(0);

int main()
{
	std::cout << IsClassT<std::string>::is << '\n';
	std::cout << IsClassT<int>::is << '\n';

	std::cin.get();
	return 0;
}