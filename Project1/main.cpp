#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

struct Number
{
	static Number *instance();

	static void setType(const std::string &t)
	{
		type = t;
		delete inst;
		inst = nullptr;
	}

	virtual void setValue(int in) { value = in; }
	virtual int getValue() const { return value; }

protected:
	int value;
	Number() { std::cout << "ctor: "; }

private:
	static std::string type;
	static Number *inst;
};

std::string Number::type = "decimal";
Number *Number::inst = nullptr;

struct Octal : Number
{
	friend struct Number;

	void setValue(int in)
	{
		char buf[10];
		sprintf(buf, "%o", in);
		sscanf(buf, "%d", &value);
	}
protected:
	Octal() {}
};

Number *Number::instance()
{
	if (!inst)
		if (type == "octal")
			inst = new Octal;
		else
			inst = new Number;
	return inst;
}

int main()
{
	Number::instance()->setValue(42);
	std::cout << "Value is " << Number::instance()->getValue() << '\n';

	Number::setType("octal");
	Number::instance()->setValue(64);
	std::cout << "Value is " << Number::instance()->getValue() << '\n';

	std::cin.get();
}