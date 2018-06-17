#include <iostream>

class Widget
{
public:
	Widget(int i) : m_int(i)
	{
		std::cout << "ctor for " << i << ": " << this << '\n';
	}

	~Widget()
	{
		std::cout << "dtor for " << m_old << ": " << this << '\n';
	}

	Widget(const Widget &rhs)
	{
		m_int = rhs.m_int;
		std::cout << "copy ctor for " << rhs.m_old << ": " << this << '\n';
	}

	const Widget &operator=(const Widget &rhs)
	{
		m_old = m_int;
		m_int = rhs.m_int;
		return *this;
	}

	int get() const
	{
		return m_int;
	}

private:
	int m_int;
	int m_old;
};

int main()
{
	Widget w1(4);
	Widget w2(7);
	Widget w3(8);
	Widget w4(1);

	std::cout << "w1: " << w1.get() << '\n';
	std::cout << "w2: " << w2.get() << '\n';
	std::cout << "w3: " << w3.get() << '\n';
	std::cout << "w4: " << w4.get() << "\n\n";

	w4 = w3 = w2 = w1;

	std::cout << "w1: " << w1.get() << '\n';
	std::cout << "w2: " << w2.get() << '\n';
	std::cout << "w3: " << w3.get() << '\n';
	std::cout << "w4: " << w4.get() << '\n';

	// can't with const &
	Widget &ref = w1 = w2;

	std::cin.get();
	return 0;
}
