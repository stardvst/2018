#include <iostream>
#include <memory>
#include <map>

template <typename It>
void dwim(It b, It e)
{
	while (b != e)
		//typename std::iterator_traits<it>::value_type curValue = *b;
		auto curValue = *b;
}

class Widget {};

int main()
{
	auto derefUPLess = [](const std::unique_ptr<Widget> &p1, const std::unique_ptr<Widget> &p2)
	{
		return *p1 < *p2;
	};

	auto derefLess = [](const auto &p1, const auto &p2) { return *p1 < *p2; };

	std::map<std::string, int> m;
	for (const std::pair<std::string, int> &p : m)
	{
		// wrong... pair type is std::pair<CONST std::string, int>
		// => auto is better
	}

	std::cin.get();
}
