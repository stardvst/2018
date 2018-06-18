#include <iostream>

class Base
{
public:
	Base(int a = 0, int b = 0) : m_a(a), m_b(b) { }
	int a() const { return m_a; }
	int b() const { return m_b; }

	// doesn't copy b, oops!
	Base(const Base &base) : m_a(base.m_a) { }

private:
	int m_a;
	int m_b;
};

class Derived : public Base
{
public:
	Derived(int a, int b, int c) : Base(a, b), m_c(c) {}
	int c() const { return m_c; }

	// doesn't copy base part
	Derived(const Derived &derived) : m_c(derived.m_c) {}

private:
	int m_c;
};

int main()
{
	Base b1(1, 2);
	Base b2 = b1;

	std::cout << "b1: " << b1.a() << ' ' << b1.b() << '\n';
	std::cout << "b2: " << b2.a() << ' ' << b2.b() << '\n';

	Derived d1(10, 11, 12);
	Derived d2 = d1;

	std::cout << "d1: " << d1.a() << ' ' << d1.b() << ' ' << d1.c() << '\n';
	std::cout << "d2: " << d2.a() << ' ' << d2.b() << ' ' << d2.c() << '\n';

	std::cin.get();
	return 0;
}
