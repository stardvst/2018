#include <numeric>
#include <iostream>

template <unsigned int N>
struct UINT
{
	using type = UINT<N>;
	using value_type = unsigned int;
	static constexpr unsigned int value = N;
	using next = UINT<N + 1>;
	using prev = UINT<N - 1>;
};

template <>
struct UINT<0>
{
	using type = UINT<0>;
	using value_type = unsigned int;
	static constexpr unsigned int value = 0;
	using next = UINT<1>;
	using prev = UINT<0>;
};

template <unsigned int N>
struct binary : UINT<binary<N / 10>::type::value * 2 + (N % 10)> {};

template <>
struct binary<0> : UINT<0> {};

int main()
{
	std::cout << binary<101>::value;

	std::cin.get();
	return 0;
}