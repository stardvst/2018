//#include <iostream>
//
//template <typename It>
//void dwim(It b, It e)
//{
//	while (b != e)
//		/* typename std::iterator_traits<it>::value_type */ auto curValue = *b;
//}
//
//int main()
//{
//	
//
//	std::cin.get();
//}

#include <iostream>

class A
{
public:
	A(int) :i (new int) {}
	const A& operator=(const A& o) const { i = new int; std::cout << "operator=" << std::endl; return *this; }

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

