#include <iostream>
#include <vector>
#include <memory>

struct ABC
{
	~ABC() { std::cout << "dtor\n"; }
	std::shared_ptr<ABC> other;
};

int main()
{
	{
		std::shared_ptr<ABC> a1(new ABC);
		std::shared_ptr<ABC> a2(new ABC);

		a1->other = a2;
		// a2->other = a1;

		std::cout << a1.use_count() << ", " << a2.use_count() << '\n';
	}
	std::cin.get();
	return 0;
}