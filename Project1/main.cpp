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

	std::size_t length() const
	{
		if (!lengthIsValid)
		{
			m_length = std::strlen(m_text);
			lengthIsValid = true;
		}
		return m_length;
	}

private:
	char *m_text;
	mutable std::size_t m_length;
	mutable bool lengthIsValid {false};
};

int main()
{
	const TextBlock cctb("Hello");

	std::cout << cctb.length();
		
	std::cin.get();
	return 0;
}
