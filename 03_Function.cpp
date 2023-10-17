#pragma once
#include <iostream>
using namespace std;

// ================================================================
// 1- Parameter passed by value
// ================================================================
// Not recommended
auto my_function1(int a, int b) { return a + b; }

// ================================================================
// Parameter passed by reference
// ================================================================
// Recommended
auto my_function2(const int &a, const int &b) { return a + b; }

// ================================================================
// Return value constant
// ================================================================
// Not recommended
// https://stackoverflow.com/a/8716406
const auto my_function3(const int &a, const int &b) { return a + b; }

// ================================================================
// Inline function
// ================================================================
// To avoid function call overhead
// Compiler expands (rather than invoke) the function where it is called
inline auto my_function4(const int &a, const int &b) { return a + b; }

// ================================================================
// Parameter default value
// ================================================================
auto my_function5(const int &a=0, const int &b=1) { return a + b; }
