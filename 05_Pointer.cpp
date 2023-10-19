#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

//------------------------------------------------------------------
int main() {

  // ================================================================
  // General
  // ================================================================
  // Pointer: A variable to store address of another variable
  // * --> dereference operator
  // & --> reference operator

  // ================================================================
  // Initialization
  // ================================================================
  int var     = 3;
  array arr   = {1,2,3,4};
  int arr_c[] = {1,2,3,4};
  int *ptr_var    = &var;
  int *ptr_arr    = arr.begin();
  int *ptr_arr_c  = arr_c;
  int *ptr_arr_c2 = &arr_c[0];

  // ================================================================
  // Address
  // ================================================================
  // -------------- variable
  &var;
  ptr_var;
  // -------------- array
  arr.begin();
  ptr_arr;
  // -------------- array
  &arr_c;
  arr_c + 0;
  ptr_arr_c;

  // ================================================================
  // Value
  // ================================================================
  // -------------- variable
  var;
  *ptr_var;
  // -------------- array
  arr.at(1);
  ptr_arr[1];
  *(ptr_arr + 1);
  // -------------- array
  arr_c[1];
  ptr_arr_c[1];
  *(ptr_arr_c + 1);

  // ================================================================
  // Address of pointer
  // ================================================================
  &ptr_var;
  &ptr_arr;
  &ptr_arr_c;

  // ================================================================
  // Pointer of pointer
  // ================================================================
  int *ptr_ptr = ptr_var; // pointer of pointer of var
  ptr_ptr;                // address of var
  *ptr_ptr;               // value of var

  // ================================================================
  // Double pointer
  // ================================================================
  int **double_ptr = &ptr_var;
  double_ptr;           // address of ptr_var
  *double_ptr;          // address of var
  **double_ptr;         // value of var

  // ================================================================
  // Array and pointer
  // ================================================================
  // arrays and ptr are similar in operation
  // ptr can point to new variable, array can't
  *ptr_arr++;         // get value of array element, increment address
  *++ptr_arr;         // increment address, get value of array element
  ++*ptr_arr;         // same as above


  return 0;
}