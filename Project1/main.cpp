#include <iostream>

class TextBlock
{
public:
	TextBlock(const std::string &text)
		: m_text(text)
	{
	}

	const char &operator[](std::size_t position) const
	{
		std::cout << "const version: ";
		return m_text[position];
	}

	// char won't work
	char &operator[](std::size_t position)
	{
		std::cout << "non-const version: ";
		return m_text[position];
	}

private:
	std::string m_text;
};

int main()
{
	TextBlock tb("Hello");
	std::cout << tb[0] << '\n';
	tb[0] = 'x';
	std::cout << tb[0] << '\n';

	const TextBlock ctb("World");
	std::cout << ctb[0] << '\n';
	//ctb[0] = 'y';
		
	std::cin.get();
	return 0;
}
