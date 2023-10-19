#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// ================================================================
// Link
// ================================================================
// https://en.cppreference.com/w/cpp/container/array
// https://en.cppreference.com/w/cpp/container/vector

// ================================================================
// Declaration
// ================================================================

template<typename T>
void my_func(T arr[]);

template<typename T, size_t N>
void my_func(array<T, N> arr);

template<typename T>
void my_func(vector<T> vec);

template<typename T>
void my_func(T *ptr_arr);

//------------------------------------------------------------------
int main() {

  // ================================================================
  // Initialization
  // ================================================================

  int           arr_c[]       = {1, 2, 3, 4, 5};      // C Array
  int           mat_c[2][3]   = {{1,2,3}, {4,5,6}};   // C Matrix
  array<int, 5> arr           = {1, 2, 3, 4, 5};      // C++ Array (fixed size)
  vector<int>   vec           = {1, 2, 3, 4, 5};      // C++ Vector (dynamic length)
 
  // ================================================================
  // Size
  // ================================================================

  sizeof(arr_c)/sizeof(arr_c[0]);
  arr.size();
  vec.size();

  // ================================================================
  // Read
  // ================================================================

  // Access first element
  arr_c[0];
  arr.front();
  vec.front();
  arr.begin();  // Address

  // Access last element
  arr_c[sizeof(arr_c)/sizeof(arr_c[0]) - 1];
  arr.back();
  vec.back();
  arr.end();    // Address
  
  // Access nth element
  arr_c[2];
  arr.at(2);
  vec.at(2);

  // ================================================================
  // Insert
  // ================================================================

  // Insert first element
  vec.insert(vec.begin(), 33);

  // Insert last element
  vec.insert(vec.end(), 55);
  vec.push_back(55);

  // ================================================================
  // Iterate
  // ================================================================
  
  for (auto loop = 0; loop < sizeof(arr_c) / sizeof(arr_c[0]); loop += 1) { cout << arr_c[loop]; }
  for (auto loop = 0; loop < arr.size(); loop += 1)                       { cout << arr.at(loop); }
  for (auto loop = 0; loop < vec.size(); loop += 1)                       { cout << vec.at(loop); }
  for (const auto &iterator : vec)                                        { cout << iterator; }

  // ================================================================
  // Array and Function Invocation
  // ================================================================
  my_func(arr_c);
  my_func(arr);
  my_func(vec);
  my_func(arr.begin());

  // ================================================================
  // Remove
  // ================================================================

  // remove first element
  vec.erase(vec.begin()); 

  // remove last element
  vec.erase(vec.end() - 1);
  vec.pop_back();   

  // remove all elements
  vec.clear();
  
  // check if all empty
  vec.empty();

  return 0;
}

// ================================================================
// Array and Function Definition
// ================================================================

template<typename T>
void my_func(T arr[])         { cout << arr[0] << endl; }

template<typename T, size_t N>
void my_func(array<T, N> arr) { cout << arr.at(0) << endl; }

template<typename T>
void my_func(vector<T> vec)   { cout << vec.at(0) << endl; }

template<typename T>
void my_func(T *ptr_arr)      { cout << ptr_arr[0] << endl; }
