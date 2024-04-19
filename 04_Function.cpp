/*

 Description:
 Function

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/
#include <functional>
#include <iostream>
using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://iamsorush.com/posts/cpp-variadic-template/

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*
- Multiple functions for multiple param types can be implemented using overloading
- One function for multiple param types can be implemented using template
- Function is not first class citizen (can't be passed, can't be returned)
- Lambda is first class citizen
- Syntax of a function
     const int function(const int& a) const{}
     |__ return          |__ params    |__function can't be changed
- Python: No overloading possible due to dynamic types
*/

// ==========================================================================================================
// Parameter passed by value
// ==========================================================================================================
auto my_function1(int a, int b) {
    return a + b;
}

// ==========================================================================================================
// Parameter passed by reference
// ==========================================================================================================
auto my_function2(int &a, int &b) {
    a = b;
}
auto my_function2(const int &a, const int &b) {
    return a + b;
}

// ==========================================================================================================
// Parameter default value
// ==========================================================================================================
auto my_function3(const int &a = 0, const int &b = 1) {
    return a + b;
}

// ==========================================================================================================
// Constant return value
// ==========================================================================================================
// Not recommended
// https://stackoverflow.com/a/8716406
const auto my_function4(const int &a, const int &b) {
    return a + b;
}

// ==========================================================================================================
// Inline function
// ==========================================================================================================
// Compiler expands (instead of invoke) the function where it is called
// To avoid function call overhead
inline auto my_function5(const int &a, const int &b) {
    return a + b;
}

// ==========================================================================================================
// Function overloading (Compile Time Polymorphism)
// ==========================================================================================================
int multiplier(int input1 = 1, int input2 = 1) {
    return input1 * input2;
}
double multiplier(double input1 = 1.0, double input2 = 1.0) {
    return input1 * input2;
}

// ==========================================================================================================
// Trailing Return Type
// ==========================================================================================================
auto my_function(void) -> int {
    return 1;
}

// ==========================================================================================================
// Recursion
// ==========================================================================================================
// Factorial without recursion:
// n! = n*(n-1)*(n-2)*(n-3)...*(n-n+2)*(n-n+1)
long factorial_without_recursion(long num) {
    if (num < 0)
        return NULL;  // Handle negative numbers
    if (num <= 1)
        return 1;  // Handle <=1 numbers (0, 1)
    for (auto loop = num - 1; loop > 1; loop -= 1) {
        num *= loop;
    }
    return num;
}
// Factorial with recursion:
// https://stackoverflow.com/a/20108832
// Factorial: Number of combinations/arrangements
// 5! = 5 * 4!
// factorial(num) = num * factorial(num - 1)
// Why 0! = 1? Because 0 can be arranged only 1 way
long factorial_with_recursion(const long &num) {
    if (num < 0)
        return NULL;  // Handle negative numbers
    if (num <= 1)
        return 1;                                    // Handle <=1 numbers (0, 1)
    return num * factorial_with_recursion(num - 1);  // Handle > 1 numbers (2,..)
}

// ==========================================================================================================
// Lambda Expression
// ==========================================================================================================
// - Lambda can be passed as a parameter (unlike function)
// - Lambda uses trailing return type
//
// - Variable capture modes:
//     [&]          All variables by reference
//     [=]          All variables by value
//     [v1, &v2]    v1 by value, v2 by reference
//
// - Syntax:
//     Function: auto abc   ()->void{}
//     Lambda:   auto abc=[]()->void{}
auto lamda_tester() -> void {
    int num1 = 33;
    int num2 = 55;
    // Inline Lamda expression with trailing return type
    auto lamda_exp = [&num1](const int &param) -> int {
        if (num1 > param) {
            return num1;
        }
        return param;
    };
    cout << lamda_exp(num2) << endl;
};

// ==========================================================================================================
// Partial Function
// ==========================================================================================================
auto func = [](string name, string address, int age, double height) -> void {
    cout << name << endl;
    cout << address << endl;
    cout << age << endl;
    cout << height << endl;
};
auto partial_func = bind(func, placeholders::_1, "Rosenheim", 30, placeholders::_2);

// ==========================================================================================================
// Fold Expression
// ==========================================================================================================
// TODO

//----------------------------------------------------------------
int main() {
    // Factorial
    const auto num = 5;
    auto combinations = factorial_with_recursion(num);
    cout << combinations << endl;
    // Lamda expression
    lamda_tester();
    // Partial function
    func("Siddiqui", "Rosenheim", 30, 5.9);
    partial_func("Siddiqui", 5.9);
    return 0;
}