#include <iostream>

//template <int N>
//constexpr int fibonacci()
//{
//	return fibonacci<N - 1>() + fibonacci<N - 2>();
//}
//
//template <>
//constexpr int fibonacci<1>()
//{
//	return 1;
//}
//
//template <>
//constexpr int fibonacci<0>()
//{
//	return 0;
//}

template <int N>
constexpr int fibonacci()
{
	if constexpr (N >= 2)
		return fibonacci<N - 1>() + fibonacci<N - 2>();
	return N;
}

int main()
{
	std::cout << fibonacci<8>();

	std::cin.get();
	return 0;
}
