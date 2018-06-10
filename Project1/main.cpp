#include <iostream>

class Transaction
{
public:
	Transaction()
	{
		log();
	}

	virtual void log() const = 0
	{
		std::cout << "Transaction::log\n";
	}
};

class BuyTransaction : public Transaction
{
public:
	void log() const override
	{
		std::cout << "BuyTransaction::log\n";
	}
};

class SellTransaction : public Transaction
{
public:
	void log() const override
	{
		std::cout << "SellTransaction::log\n";
	}
};

int main()
{
	// Transaction::log has no body -> linker error
	// Transaction::log has body -> calls Transaction::log(). hmmm
	BuyTransaction b;

	std::cin.get();
	return 0;
}
