#include <iostream>

struct Aclash
{
	Aclash() : a(4) {}
protected:
	int a;
};

struct Bclash
{
	Bclash() : a(5) {}
protected:
	int a;
};

struct Cclash : Aclash, Bclash
{
	Cclash()
	{
		std::cout << Aclash::a;
	}
};

int main()
{
	Cclash c;

	std::cin.get();
}
