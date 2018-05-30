#include <iostream>
#include <vector>

std::vector<bool> GetPrimes(const int n)
{
	std::vector<bool> primes(n + 1, true);
	for (auto i = 2; i <= n; ++i)
		if (primes[i])
			for (auto j = 2; j * i <= n; ++j)
				primes[j * i] = false;
	return primes;
}

int main()
{
	int a;
	std::cout << "Enter number, Henrik!: ";
	std::cin >> a;
	auto primes = GetPrimes(a);
	for (std::size_t i = 2; i < primes.size(); ++i)
		if (primes[i])
			std::cout << i << ", ";

	std::cin.get();
	return 0;
}