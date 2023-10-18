#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// ================================================================
// General
// ================================================================
// https://en.cppreference.com/w/cpp/container/array


int main() {

  // ================================================================
  // Initialization
  // ================================================================

  // C Arrays (deprecated)
  int arr1[5]   =   {};                 // explicit size
  int arr2[]    =   {1, 2, 3, 4, 5};    // implicit size
  int arr3[2][3]  = {{1,2,3}, {4,5,6}}; // Mutidim arrays

  // C++ Arrays (fixed length)
  array<int, 5> arr4 = {1, 2, 3, 4, 5};

  // C++ Vectors (dynamic length)
  vector<int> arr5 = {1, 2, 3, 4, 5};

  // ================================================================
  // Access
  // ================================================================

  // C Arrays
  arr2[0] ;                               // C Array First Element
  arr2[2] ;                               // C Array Second Element
  arr2[sizeof(arr2)/sizeof(arr2[0]) - 1]; // C Array Last Element
  sizeof(arr2)/sizeof(arr2[0]) ;          // C Array Size

  // C++ Arrays
  arr4.front();                           // C++ Array First Element
  arr4.at(2)  ;                           // C++ Array Second Element
  arr4[2]     ;                           // C++ Array Second Element
  arr4.back() ;                           // C++ Array Last Element
  arr4.size() ;                           // C++ Array Size

  // C++ Vectors
  arr5.front();                           // C++ Vector First Element
  arr5.at(2)  ;                           // C++ Vector Second Element
  arr5[2]     ;                           // C++ Vector Second Element
  arr5.back() ;                           // C++ Vector Last Element
  arr5.size() ;                           // C++ Vector Size
  arr5.insert(arr5.begin(), 22);          // C++ Vector insert new element at start
  arr5.insert(arr5.end(), 23);            // C++ Vector insert new element at end
  arr5.push_back(24);                     // C++ Vector insert new element at end    
  arr5.pop_back();                        // C++ Vector remove new element at end

  return 0;
}