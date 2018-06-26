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
	virtual void f() { std::cout << "A" << std::endl; }
};

class B : public A
{
private:
	void  f() override { std::cout << "B" << std::endl; }
};

int main()
{
	A* p = new B;
	p->f();

	std::cin.get();
}
