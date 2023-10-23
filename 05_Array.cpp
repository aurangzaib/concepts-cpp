#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// https://en.cppreference.com/w/cpp/container/list
// https://en.cppreference.com/w/cpp/container/array
// https://en.cppreference.com/w/cpp/container/vector
// https://www.geeksforgeeks.org/tuples-in-c/
// https://www.educba.com/c-plus-plus-vector-vs-list/

// ==========================================================================================================
// General
// ==========================================================================================================
// Array:
//      - Static size
//      - Static type element
//      - Random access using at()
// Vector:
//      - Recommended
//      - Dynamic size
//      - Static type element
//      - Random access using at()
//      - Iterator invalid after changes in vector
// List:
//      - Dynamic size
//      - Static type element
//      - Random access not possible
//      - Iterator remains valid after changes in list
// Tuple:
//      - Dynamic type element
//      - Random access using get<>()
//      - To return multiple values from a function

// ==========================================================================================================
// Declaration
// ==========================================================================================================

template <typename T>
void my_func(T arr[]);

template <typename T, size_t N>
void my_func(array<T, N> arr);

template <typename T>
void my_func(vector<T> vec);

template <typename T>
void my_func(T *ptr_arr);

//---------------------------------------------------------------------------------------------------------------
int main() {
    // ==========================================================================================================
    // Initialization
    // ==========================================================================================================

    int arr_c[]                     = {1, 2, 3, 4, 5};              // C Array
    int mat_c[2][3]                 = {{1, 2, 3}, {4, 5, 6}};       // C Matrix
    array<int, 5> arr               = {1, 2, 3, 4, 5};              // C++ Array
    vector<int> vec                 = {1, 2, 3, 4, 5};              // C++ Vector
    list<int> lst                   = {1, 2, 3, 4, 5};              // C++ List
    tuple<int, float, string> tpl   = {1, 1.1, "1.1"};              // C++ Tuple with explicit type
    tuple tpl1                      = make_tuple(2, 2.2, "2.2");    // C++ Tuple with inferred type

    // ==========================================================================================================
    // Size
    // ==========================================================================================================

    sizeof(arr_c) / sizeof(arr_c[0]);
    arr.size();
    vec.size();
    lst.size();
    tuple_size<decltype(tpl)>::value;

    // ==========================================================================================================
    // Read
    // ==========================================================================================================

    // Access first element
    arr_c[0];
    arr.front();
    vec.front();
    lst.front();
    get<0>(tpl);
    arr.begin();  // Address

    // Access last element
    arr_c[sizeof(arr_c) / sizeof(arr_c[0]) - 1];
    arr.back();
    vec.back();
    lst.back();
    arr.end();  // Address

    // Access nth element
    arr_c[2];
    arr.at(2);
    vec.at(2);

    // ==========================================================================================================
    // Insert
    // ==========================================================================================================

    // Insert first element
    vec.insert(vec.begin(), 33);
    lst.insert(lst.begin(), 33);
    lst.push_front(33);
    auto new_tpl1 = tuple_cat(make_tuple(33.5), tpl);

    // Insert last element
    lst.insert(lst.end(), 55);
    vec.insert(vec.end(), 55);
    lst.push_back(55);
    vec.push_back(55);
    auto new_tpl2 = tuple_cat(tpl, make_tuple(33.5));

    // ==========================================================================================================
    // Iterate
    // ==========================================================================================================

    for (auto loop = 0; loop < sizeof(arr_c) / sizeof(arr_c[0]); loop += 1) {
        cout << arr_c[loop];
    }
    for (auto loop = 0; loop < arr.size(); loop += 1) {
        cout << arr.at(loop);
    }
    for (auto loop = 0; loop < vec.size(); loop += 1) {
        cout << vec.at(loop);
    }
    for (const auto &iterator : vec) {
        cout << iterator;
    }
    for (const auto &iterator : lst) {
        cout << iterator;
    }

    // ==========================================================================================================
    // Array and Function Invocation
    // ==========================================================================================================
    my_func(arr_c);
    my_func(arr);
    my_func(vec);
    my_func(arr.begin());

    // ==========================================================================================================
    // Remove
    // ==========================================================================================================

    // Remove first element
    vec.erase(vec.begin());

    // Remove last element
    vec.erase(vec.end() - 1);
    vec.pop_back();

    // Remove all elements
    vec.clear();

    // Check if all empty
    vec.empty();

    return 0;
}

// ==========================================================================================================
// Array and Function Definition
// ==========================================================================================================

template <typename T>
void my_func(T arr[]) {
    cout << arr[0] << endl;
}

template <typename T, size_t N>
void my_func(array<T, N> arr) {
    cout << arr.at(0) << endl;
}

template <typename T>
void my_func(vector<T> vec) {
    cout << vec.at(0) << endl;
}

template <typename T>
void my_func2(T *ptr_arr) {
    cout << ptr_arr[0] << endl;
}
