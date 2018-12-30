#include <iostream>
#include <chrono>

template <typename T>
class DynamicArray
{
public:
	DynamicArray(int l) : array(new T[l]), length(l) {}
	~DynamicArray() { delete array; }

	//DynamicArray(const DynamicArray &arr)
	//	: length(arr.length)
	//{
	//	array = new T[length];
	//	for (int i = 0; i < length; ++i)
	//		array[i] = arr.array[i];
	//}

	//DynamicArray& operator=(const DynamicArray &arr)
	//{
	//	if (&arr == this)
	//		return *this;

	//	delete[] array;

	//	length = arr.length;
	//	array = new T[length];

	//	for (int i = 0; i < length; ++i)
	//		array[i] = arr.array[i];

	//	return *this;
	//}

		// Copy constructor
	DynamicArray(const DynamicArray &arr) = delete;

	// Copy assignment
	DynamicArray& operator=(const DynamicArray &arr) = delete;

	// Move constructor
	DynamicArray(DynamicArray &&arr)
		: length(arr.length), array(arr.array)
	{
		arr.length = 0;
		arr.array = nullptr;
	}

	// Move assignment
	DynamicArray& operator=(DynamicArray &&arr)
	{
		if (&arr == this)
			return *this;

		delete[] array;

		length = arr.length;
		array = arr.array;
		arr.length = 0;
		arr.array = nullptr;

		return *this;
	}

	int getLength() const { return length; }
	T& operator[](int index) { return array[index]; }
	const T& operator[](int index) const { return array[index]; }

private:
	T *array;
	int length;
};

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now()) {}
	void reset() { m_beg = clock_t::now();}
	double elapsed() const {return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();}
};

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int> &arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}

int main()
{
	Timer t;

	DynamicArray<int> arr(1000000);

	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;

	arr = cloneArrayAndDouble(arr);

	std::cout << t.elapsed();

	system("pause");
	return 0;
}