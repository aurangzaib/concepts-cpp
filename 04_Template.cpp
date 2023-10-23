#include <iostream>
using namespace std;

// ==========================================================================================================
// Notes
// ==========================================================================================================
// Templates are used to define a function/class for a generic type ...
// ... where type can be inferred later on usage

// ==========================================================================================================
// Template
// ==========================================================================================================

template <typename T, typename U>
auto multiplier(const T &a, const U &b) {
    return a * b;
}

template <class T, class U>
auto divider(const T &a, const U &b) {
    return a / b;
}

template <typename T, size_t N>
T array[N] = {1, 2, 3};

//----------------------------------------------------------------
int main() {
    auto result_int = multiplier(2, 3);
    auto result_double = multiplier<int, double>(2, 3.123);

    result_int = divider(2, 3);
    result_double = divider<int, double>(2, 3.123);

    return 0;
}