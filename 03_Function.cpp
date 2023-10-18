#include <iostream>
using namespace std;

// ================================================================
// General
// ================================================================

// Functions are not first class citizen (can't be passed, can't be returned)
// Lambdas are first class citizen


// ================================================================
// Parameter passed by value
// ================================================================

// Not recommended
auto my_function1(int a, int b) { return a + b; }

// ================================================================
// Parameter passed by reference
// ================================================================

// Recommended
auto my_function2(const int &a, const int &b) { return a + b; }

// ================================================================
// Constant return value
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

auto my_function5(const int &a = 0, const int &b = 1) { return a + b; }

// ================================================================
// Factorial without recursion
// ================================================================

// n! = n*(n-1)*(n-2)*(n-3)...*(n-n+2)*(n-n+1)
long factorial_without_recursion(long num) {
  if (num < 0) return NULL;     // Handle negative numbers
  else if (num <= 1) return 1;  // Handle <=1 numbers (0, 1)
  for (uint loop = num - 1; loop > 1; loop -= 1) {
    num *= loop;
  }
  return num;
}

// ================================================================
// Factorial with recursion
// ================================================================

// Algorithm (https://stackoverflow.com/a/20108832):
//      Number of combinations/arrangements
//      5! = 5 * 4!
//      factorial(num) = num * factorial(num - 1)
// Why 0! = 1?
//      0 can be arranged only 1 way
long factorial_with_recursion(long num) {
  if (num < 0) return NULL;                        // Handle negative numbers
  else if (num <= 1) return 1;                     // Handle <=1 numbers (0, 1)
  return num * factorial_with_recursion(num - 1);  // Handle > 1 numbers (2,..)
}

//----------------------------------------------------------------
int main() {
  auto result = factorial_without_recursion(0);
  return 0;
}