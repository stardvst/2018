#include <iostream>
#include <utility>
#include <typeinfo>
#include <set>
#include <tuple>

void f(std::pair<int, char> p)
{
	std::cout << p.first << ' ' << p.second << '\n';
}

//template <auto value>
//void g()
//{
//	std::cout << typeid(value).name();
//}

/**
 * fold expr
 */
auto sumCpp11()
{
	return 0;
}

template <typename T1, typename... T>
auto sumCpp11(T1 s, T... ts)
{
	return s + sumCpp11(ts...);
}

template <typename... Args>
auto sumCpp17(Args... args)
{
	return (args + ... + 0);
	// or:
	return (args + ...);
}

template <typename T>
auto get_value(T t)
{
	if constexpr(std::is_pointer_v<T>)
		return *t;
	else
		return t;
}

[[deprecated("honestly")]] void term() noexcept
{

}

[[nodiscard]] int foo()
{
	return 45;
}

int main()
{
	/*std::pair p(42, 'z');
	f(p);*/

	//g<10>();

	//std::cout << sumCpp11(5, 6);

	//int *p = new int(15);
	//std::cout << get_value(p) << '\n' << get_value(45);

	//term();

	/*int a;
	std::cout << "Enter number: ";
	std::cin >> a;

	switch (a)
	{
		case 4:
			std::cout << "4";
		case 5:
			std::cout << "5";
			[[fallthrough]];
		case 6:
			std::cout << "6";
	}*/

	//foo();

	double myArr[3] = { 1.0, 2.0, 3.0 };
	auto[a, b, c] = myArr;

	std::cout << a << b << c;

	std::cin.get();
	return 0;
}
