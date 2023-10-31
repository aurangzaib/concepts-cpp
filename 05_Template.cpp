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
using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/templates-cpp/?ref=lbp

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*
- To define a function/class for a generic type where type can be inferred later on usage
- Type as well as value can be templatized     (<typename T, size_t N>)
- typename or class for template type are same (<typename T, class U>)
- Variadic template is a function which takes N parameters
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

//----------------------------------------------------------------
int main() {
    auto result_int = multiplier(2, 3);
    auto result_double = multiplier<int, double>(2, 3.123);

    cout << result_int << endl;
    cout << result_double << endl;

    for (const auto &value : arr<double, 3>) {
        cout << value << endl;
    }

    return 0;
}