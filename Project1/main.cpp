#include <iostream>


#include <vector>
#include <unordered_map>
#include <iostream>
#include <memory>

class Foo
{
public:
	Foo()
	{
		std::cout << "ctor\n";
	}

	void *operator new(size_t) = delete;
	void *operator new(size_t, void *) = delete;
	void *operator new[](size_t) = delete;
	void *operator new[](size_t, void *) = delete;

};

void f(Foo foo)
{

}

int main()
{
	//auto foo = new Foo;

	//Foo *foos = new Foo[5];

	/*void *pn = malloc(sizeof(Foo));
	auto foopn = new (pn) Foo;*/

	/*void *apn = malloc(5 * sizeof(Foo));
	auto fooapn = new (apn) Foo[5];*/

	Foo foo;

	std::cin.get();
	return 0;
}