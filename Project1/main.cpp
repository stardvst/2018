#include <iostream>

//struct Reactor {
//	double offset(double a, double b, double ff) {
//		double a;
//		// ...
//		return a;
//	}
//	double offset(double a, double b) {
//		return offset(a, b, 1.0); // default
//	}
//};

struct Reactor
{
	double offset(double a, double b, double ff = 1.0)
	{
		double a;
		// ...
		return a;
	}
};


int main()
{
	std::cin.get();
	return 0;
}