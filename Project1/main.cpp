#include <iostream>
#include <utility>

//struct foo
//{
//	void test() { std::cout << "test" << std::endl; }
//	void test() const { std::cout << "test const" << std::endl; }
//
//private:
//	int a{};
//};
//
//int main()
//{
//	foo f1;
//	f1.test();     // prints "test"
//
//	foo const f2;
//	f2.test();     // prints "test const"
//
//	foo().test();
//
//	system("pause");
//	return 0;
//}

struct Widget final
{
	explicit Widget(std::string name) : m_name(std::move(name)) {};
	~Widget() = default;
	Widget(const Widget &w) { std::cout << "copy" << std::endl; m_name = w.m_name; }
	Widget &operator=(const Widget &w) { std::cout << "copy assign" << std::endl; m_name = w.m_name; return *this; }
	Widget(Widget&& w) noexcept { std::cout << "move" << std::endl; m_name = std::move(w.m_name); }
	Widget &operator=(Widget &&w) noexcept { std::cout << "move assign" << std::endl; m_name = std::move(w.m_name); return *this; }

private:
	std::string m_name;
};

struct bar
{
	Widget &data() & { return m_widget; }
	Widget &&data() && { return std::move(m_widget); }
	const Widget &data() const & { return m_widget; }

private:
	Widget m_widget{ "bar" };
};

int main()
{
	bar b1;
	auto w1 = b1.data();

	const bar b2;
	const auto& w2 = b2.data();

	auto w3 = bar().data();

	system("pause");
	return 0;
}