#ifndef HEADER_H
#define HEADER_H

#include <string>

const char *const globalCharPtr("some text");
const std::string globalString(globalCharPtr);

void showStr(const std::string &sourceName, const std::string &other);

void f();

#endif