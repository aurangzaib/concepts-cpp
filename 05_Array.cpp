#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// ================================================================
// General
// ================================================================
// https://en.cppreference.com/w/cpp/container/array
// https://en.cppreference.com/w/cpp/container/vector

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
  // Read
  // ================================================================

  // Size of array
  sizeof(arr_c)/sizeof(arr_c[0]);
  arr.size();
  vec.size();

  // Access first element
  arr_c[0];
  arr.front();
  vec.front();

  // Access last element
  arr_c[sizeof(arr_c)/sizeof(arr_c[0]) - 1];
  arr.back();
  vec.back();

  // Access nth element
  arr_c[2];
  arr.at(2);
  vec.at(2);

  // arr.at(index): Value with bound check
  // arr.front():   Value of first element
  // arr.back():    Value of last element
  // arr.begin():   Address of first element
  // arr.end():     Address of last element

  // ================================================================
  // Insert
  // ================================================================

  // insert element
  vec.insert(vec.begin(), 33);
  vec.insert(vec.end(), 55);
  vec.push_back(55);

  // ================================================================
  // Remove
  // ================================================================

// remove second element
  vec.erase(vec.begin() + 1); 

  // remove last element 
  vec.pop_back();   
  vec.erase(vec.end());          

  // remove all elements
  vec.clear();
  
  // check if all removed
  vec.empty();

  // ================================================================
  // C Array and Pointer
  // ================================================================

  arr_c[0];     // Value of first element
  *arr_c;       // Value of first element
  *(arr_c + 1); // Value of second element
  (arr_c + 1);  // Address of second element
  &arr_c[1];    // Address of second element

  return 0;

}

// ================================================================
// Array and Function
// ================================================================
void my_func(int arr[]) {
  cout << arr[0];
}
