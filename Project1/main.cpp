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
		// ...
		// ...
		// ...
		return m_text[position];
	}

	char &operator[](std::size_t position)
	{
		//// ...
		//// ...
		//// ...
		//return m_text[position];
		
		return 
			const_cast<char &>(
				static_cast<const TextBlock &>(*this)[position]
			);
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
