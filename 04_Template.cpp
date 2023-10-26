#include <iostream>
using namespace std;

// ==========================================================================================================
// Notes
// ==========================================================================================================
// To define a function/class for a generic type where type can be inferred later on usage
// Type as well as value can be templatized     (<typename T, size_t N>)
// typename or class for template type are same (<typename T, class U>)

// ==========================================================================================================
// Template
// ==========================================================================================================

template <typename T, typename U>
auto multiplier(const T &a, const U &b) {
    return a * b;
}

template <typename T, size_t N>
T array[N] = {1, 2, 3};

//----------------------------------------------------------------
int main() {
    auto result_int = multiplier(2, 3);
    auto result_double = multiplier<int, double>(2, 3.123);

    cout << result_int << endl;
    cout << result_double << endl;
    
    return 0;
}