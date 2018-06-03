#include <iostream>
#include <cstring>

class TextBlock
{
public:
	TextBlock(const char *pText)
	{
		m_text = new char[strlen(pText)];
		strcpy(m_text, pText);
	}

	~TextBlock()
	{
		delete m_text;
	}

	char &operator[](std::size_t position) const
	{
		return m_text[position];
	}

	char *get() const
	{
		return m_text;
	}

private:
	char *m_text;
};

int main()
{
	const TextBlock cctb("Hello");

	char *pc = &cctb[0];

	*pc = 'J';

	std::cout << cctb.get(); // Jello... what?!
		
	std::cin.get();
	return 0;
}
