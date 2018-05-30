#include <iostream>
#include "Header.h"

void showStr(const std::string &fncName, const std::string &theString)
{
	const char *data = theString.c_str();
	std::cout << fncName << ": @" << &theString << " with c_str() @" << &data << '\n';
	std::cout << fncName << ": globalCharPtr @" << &globalCharPtr << '\n';
}

void f()
{
	showStr("f()", globalString);
}