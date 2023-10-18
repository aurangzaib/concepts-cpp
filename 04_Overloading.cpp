#include <iostream>
using namespace std;

// ================================================================
// General
// ================================================================

// Function overloading is not available in Python due to dynamic types

// ================================================================
// Function overloading
// ================================================================

int multiplier(int input1=1, int input2=1) {
    return input1 * input2;
}
double multiplier(double input1=1.0, double input2=1.0) {
  return input1 * input2;
}

// ================================================================
// Operator overloading
// ================================================================

//----------------------------------------------------------------
int main(){
    auto result1 = multiplier(1, 2);
    auto result2 = multiplier(1.0, 2.0);
    return 0;
}