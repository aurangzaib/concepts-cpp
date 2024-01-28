/*

 Description:
 Template

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.17  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
#include <array>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/templates-cpp/?ref=lbp

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*
- Template is used to define a function/class where type is inferred on invocation
- Type as well as value can be templatized     (<typename T, size_t N>)
- typename or class for template type are same (<typename T, class U>)
*/

// ==========================================================================================================
// Template
// ==========================================================================================================

template <typename T, typename U>
auto multiplier(const T &a, const U &b) {
    return a * b;
}

template <typename T, size_t N>
array<T, N> arr = {1.1, 2.2, 3.3};

// ==========================================================================================================
// Variadic Template
// ==========================================================================================================
// A function which takes N arguments
template <typename... T>
void variadic_function(T... params) {
    // Number of parameters
    cout << sizeof...(params) << endl;
    // Unpack the parameters
    for (const auto &elem : {params...}) {
        cout << elem << endl;
    }
}
auto variadic_tester = []() -> void { variadic_function(1, 2, 3); };

// ==========================================================================================================
// Template Specialization
// ==========================================================================================================
// https://en.cppreference.com/w/cpp/language/template_specialization

//----------------------------------------------------------------
int main() {
    auto result_int = multiplier(2, 3);
    auto result_double = multiplier<int, double>(2, 3.123);

    cout << result_int << endl;
    cout << result_double << endl;

    for (const auto &value : arr<double, 3>) {
        cout << value << endl;
    }
    // Variadic template
    variadic_tester();
    return 0;
}