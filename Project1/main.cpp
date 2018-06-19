#include <iostream>
#include <deque>

// v1
template <typename Container, typename Index>
auto authAndAccess(Container &c, Index i) -> decltype(c[i])
{
	return c[i];
}

// v2
template <typename Container, typename Index>
auto authAndAccess(Container &c, Index i)
{
	return c[i];
}

// v3
template <typename Container, typename Index>
decltype(auto) authAndAccess(Container &&c, Index i)
{
	return c[i];
}

// v4, final c++14 version
template <typename Container, typename Index>
decltype(auto) authAndAccess(Container &&c, Index i)
{
	return std::forward<Container>(c)[i];
}

int main()
{
	std::deque<int> d;
	d.push_back(3);
	d.push_back(26);
	d.push_back(4);
	d.push_back(1);
	d.push_back(9);

	// can use with v1, v3, v4
	// can't use with v2, & is ignored
	authAndAccess(d, 3) = 10;

	int w;
	const int &cw = w;
	auto w1 = cw; // int
	decltype(auto) w2 = cw; // const int &

	std::cin.get();
	return 0;
}
