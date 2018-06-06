#include <iostream>

class B
{
public:
	B(int b) : m_b(b)
	{
		std::cout << "ctor B " << b << "\n";
	}

	~B()
	{
		std::cout << "dtor B " << m_b << "\n";
	}

	void print()
	{
		std::cout << "B::print " << m_b << "\n";
	}

private:
	int m_b;
};

class A
{
public:
	A(int a) : m_a(a)
	{
		std::cout << "ctor A " << a << "\n";
	}

	~A()
	{
		std::cout << "dtor A " << m_a << "\n";
	}

private:
	static B b;
	int m_a;
};

B A::b(7);

// global object
A a(1);

int main()
{
	auto a = new A(2);
	static auto b = new A(3);

	int aa, bb;
	std::cin >> aa;
	std::cin >> bb;
	if (aa + bb < 10)
	{
		static B b(4);
		b.print();
	}

	std::cin.get();

	// both dtors are called

	return 0;
}
