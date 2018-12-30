
#include <iostream>

template <typename T>
class AutoPtr final
{
public:
	explicit AutoPtr(T *p = nullptr) : ptr(p) {}
	~AutoPtr() { delete ptr; }

	//AutoPtr(const AutoPtr &a)
	//{
	//	ptr = new T;
	//	*ptr = *a.ptr;
	//}

	//AutoPtr &operator=(const AutoPtr &a)
	//{
	//	if (&a == this) return *this;

	//	delete ptr;
	//	ptr = new T;
	//	*ptr = *a.ptr;

	//	return *this;
	//}

	AutoPtr(const AutoPtr &a) = delete;
	AutoPtr &operator=(const AutoPtr &a) = delete;

	AutoPtr(AutoPtr &&a) noexcept
	{
		ptr = a.ptr;
		a.ptr = nullptr;
	}

	AutoPtr &operator=(AutoPtr &&a) noexcept
	{
		if (&a == this) return *this;

		delete ptr;
		ptr = a.ptr;
		a.ptr = nullptr;

		return *this;
	}

	T &operator*() const { return *ptr; }
	T *operator->() const { return ptr; }
	bool isNull() const { return !ptr; }

private:
	T *ptr;
};

class Resource final
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

AutoPtr<Resource> generate()
{
	AutoPtr<Resource> res(new Resource);
	return res;
}

int main()
{
	AutoPtr<Resource> res;
	res = generate();

	system("pause");
	return 0;
}