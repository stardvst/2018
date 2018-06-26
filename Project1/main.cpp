#include <iostream>

class A
{
public:
	A(int) :i (new int) {}
	const A& operator=(const A& o) const { *i = 7; std::cout << "operator=" << std::endl; return *this; }

private:
	int* i;
};

int main()
{
	const A o(1);
	A o_(2);
	o = o_;

	std::cin.get();
}

