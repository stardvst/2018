#include <iostream>

struct VClass
{
	int a;
	int b;
	virtual ~VClass() {}
};

int main()
{
	VClass obj;

	auto start_addr = reinterpret_cast<char *>(&obj);
	auto a_addr = reinterpret_cast<char *>(&obj.a);

	std::cout << "vptr is at " << (start_addr == a_addr ? "end" : "start") << '\n';

	std::cin.get();
	return 0;
}