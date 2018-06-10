#include <iostream>
#include <vector>

template <typename T>
void f(T param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

template <typename T>
void f(std::initializer_list<T> param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

// template, not type-deduction
//auto createInitList()
//{
//	return { 1,2,3 };
//}

int main()
{
	auto x1 = 27;
	auto x2(27);
	auto x3 = { 27 };
	auto x4{ 27 };

	auto x5 = { 4,6,7 };
	f(x5);

	//f({ 11, 23, 9 });


	// template, not type-deduction
	std::vector<int> v;
	auto resetV = [&v](const auto &newValue) { v = newValue; };

	resetV({ 1,2,3 });

	std::cin.get();
	return 0;
}
