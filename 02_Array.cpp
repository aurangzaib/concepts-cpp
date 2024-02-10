/*

 Description:
 Array

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

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
// https://www.educba.com/c-plus-plus-vector-vs-list/
// https://www.geeksforgeeks.org/tuples-in-c/

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*
Array:
     - Static size
     - Same type elements
     - Random access using at()
     - Values stored contiginous
     - Passed by value to a function
Vector:
     - Recommended
     - Dynamic size
     - Same type elements
     - Random access using at()
     - Values stored contiginous
     - Iterator invalid after changes in vector
     - Passed by value to a function
List:
     - Dynamic size
     - Same type elements
     - Random access not possible
     - Values stored non-contiginous
     - Iterator remains valid after changes in list
Tuple:
     - Different type elements
     - Random access using get<>()
     - Values stored contiginous
     - To return multiple values from a function
*/

// ==========================================================================================================
// Declaration
// ==========================================================================================================

template <typename T>
void my_func(T arr[]);

template <typename T, size_t N>
void my_func(array<T, N> &arr);

template <typename T>
void my_func(vector<T> &vec);

template <typename T>
void my_func(T *ptr_arr);

//---------------------------------------------------------------------------------------------------------------
int main() {
    // ==========================================================================================================
    // Initialization
    // ==========================================================================================================

    int arr_c[5] = {1, 2, 3, 4, 5};                 // C Array
    int mat_c[2][3] = {{1, 2, 3}, {4, 5, 6}};       // C Matrix
    array<int, 5> arr = {1, 2, 3, 4, 5};            // C++ Array
    vector<int> vec = {1, 2, 3, 4, 5};              // C++ Vector
    list<int> lst = {1, 2, 3, 4, 5};                // C++ List
    tuple<int, float, string> tpl = {1, 2.1, "3"};  // C++ Tuple with explicit type

    // ==========================================================================================================
    // Alternate Initialization
    // ==========================================================================================================
    int arr_c_alt[] = {1, 2, 3, 4, 5};        // C Array
    array arr_alt = {1, 2, 3, 4, 5};          // C++ Array
    vector vec_alt = {1, 2, 3, 4, 5};         // C++ Vector
    list lst_alt = {1, 2, 3, 4, 5};           // C++ List
    tuple tpl_alt = make_tuple(1, 2.1, "3");  // C++ Tuple with implicit type

    // ==========================================================================================================
    // Size
    // ==========================================================================================================

    sizeof(arr_c) / sizeof(arr_c[0]);
    arr.size();
    vec.size();
    lst.size();
    tuple_size<decltype(tpl)>::value;

    // ==========================================================================================================
    // Read Value
    // ==========================================================================================================

    // Access first element
    arr_c[0];
    arr.front();
    vec.front();
    lst.front();
    get<0>(tpl);

    // Access last element
    arr_c[sizeof(arr_c) / sizeof(arr_c[0]) - 1];
    arr.back();
    vec.back();
    lst.back();

    // Access nth element
    arr_c[2];
    arr.at(2);
    vec.at(2);

    // ==========================================================================================================
    // Read Address
    // ==========================================================================================================
    arr.begin();
    arr.end();
    vec.begin();
    vec.end();

    // ==========================================================================================================
    // Insert
    // ==========================================================================================================

    // Insert first element
    vec.insert(vec.begin(), 33);
    lst.insert(lst.begin(), 33);
    lst.push_front(33);
    auto new_tpl1 = tuple_cat(make_tuple(33.5), tpl);

    // Insert last element
    vec.insert(vec.end(), 55);
    lst.insert(lst.end(), 55);
    vec.push_back(55);
    lst.push_back(55);
    auto new_tpl2 = tuple_cat(tpl, make_tuple(55.5));

    // ==========================================================================================================
    // Iterate
    // ==========================================================================================================

    for (auto loop = 0; loop < sizeof(arr_c) / sizeof(arr_c[0]); loop += 1) {
        cout << arr_c[loop];
    }
    for (const auto &element : arr) {
        cout << element << endl;
    }
    for (const auto &element : vec) {
        cout << element << endl;
    }
    for (const auto &element : lst) {
        cout << element << endl;
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
    cout << vec.empty();

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
void my_func(array<T, N> &arr) {
    cout << arr.at(0) << endl;
}

template <typename T>
void my_func(vector<T> &vec) {
    cout << vec.at(0) << endl;
}

template <typename T>
void my_func(T *ptr_arr, const int a) {
    cout << ptr_arr[0] << endl;
}
