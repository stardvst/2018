//#include <iostream>
//
//int foo(int inValue, int &outValue) {
//	outValue = 2 * inValue;
//	return inValue * 3;
//}
//
//int main() {
//
//	int number = 4; // useless but necessary
//	int answer = foo(5, number);
//
//	// design issue - which is invalue, which - outvalue
//
//	std::cin.get();
//	return 0;
//}

//struct twoNumbers {
//	int value1;
//	int value2;
//};
//
//twoNumbers fooStruct(int invalue) {
//	return { invalue * 2, invalue * 3 };
//}
//
//int main() {
//	int number, answer;
//	twoNumbers result = fooStruct(6);
//	number = result.value1; // what value1?
//	answer = result.value2; // what value2?
//}

#include <iostream>
#include <tuple>

std::tuple<int, int> fooTwo(int inValue)
{
	return { inValue * 2, inValue * 3 };
}

int main()
{
	/*int number, answer;
	std::tie(answer, number) = fooTwo(9);
	*/

	auto[answer, number] = fooTwo(9);
	std::cout << answer << ' ' << number;

	std::cin.get();
}
