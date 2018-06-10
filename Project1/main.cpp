#include <iostream>
#include <typeinfo>
#include <array>

// case 1
template <typename T>
void f(const T &param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

template <typename T>
void f(T& param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

template <typename T>
void f(T *param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

// case 2
template <typename T>
void f(T &&param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

// case 3
template <typename T>
void f(T param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T(&)[N]) noexcept
{
	return N;
}

// fn -> fn ptr
void someFunc(int a, double b)
{
	std::cout << a << ' ' << b << '\n';
}

template <typename T>
void f1(T param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

template <typename T>
void f2(T &param)
{
	std::cout << __FUNCSIG__ << ": " << typeid(param).name() << '\n';
}

int main()
{
	int x = 0;
	f(x);

	x = 27;
	const int cx = x;
	const int &rx = x;

	const int *px = &x;
	f(px);

	const char *const ptr = "Fun with pointers";
	f(ptr);

	const char name[] = "J. P. Briggs";
	const char *ptrToName = name;
	f(name);

	int keyVals[] = { 1,3,7,9,11,22,35 };
	std::array<int, arraySize(keyVals)> mappedVals;
	//int mappedVals[arraySize(keyVals)];

	f1(someFunc);
	f2(someFunc);

	std::cin.get();
	return 0;
}
