#include <iostream>

struct Day
{
	explicit Day(int d) : val(d) {}
	int val;
};

class Month
{
public:
	static Month Jan() { return Month(1); }
	static Month Feb() { return Month(2); }
	static Month Mar() { return Month(3); }

private:
	explicit Month(int m) : val(m) {}
	int val;
};

struct Year
{
	explicit Year(int y) : val(y) {}
	int val;
};

class Date
{
public:
	// error prone: Date(3, 4, 1990)... what?;
	Date(int month, int day, int year);

	// better!
	Date(const Month &m, const Day &d, const Year &y);
};

int main()
{
	//Date d1(30, 3, 1995);

	//Date d2(Day{ 30 }, Month{ 3 }, Year{ 1995 });

	Date d3(Month::Mar(), Day{ 30 }, Year{ 1995 });

	std::cin.get();
}
