#include <vector>
#include <numeric>
#include <string>
#include <iostream>

template <int N>
struct INT
{
	using type = INT<N>;
	using value_type = int;
	static constexpr int value = N;
	using next = INT<N + 1>;
	using prev = INT<N - 1>;
};

template <typename T, typename N>
struct plus : INT<T::value + N::value> {};

template <typename T, typename N>
struct minus : INT<T::value - N::value> {};

int main()
{
	std::cout << plus<INT<5>, INT<3>>::value;

	std::cin.get();
	return 0;
}