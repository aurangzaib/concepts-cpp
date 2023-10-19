#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// ================================================================
// Raw pointer (C Pointer)
// ================================================================
void raw_pointer(){
  
  // ---------------------------------------------------------------
  // General
  // ---------------------------------------------------------------
  // Pointer: A variable to store address of another variable
  // Raw point should be avoided, use smart pointer instead
  // * --> dereference operator (value)
  // & --> reference operator   (address)
  // Pointer can be used to pass func as a param
  // Raw pointer must be manually deleted after use

  // ---------------------------------------------------------------
  // Initialization
  // ---------------------------------------------------------------
  int var         = 3;
  array arr       = {1,2,3,4};
  int arr_c[]     = {1,2,3,4};
  int *ptr_var    = &var;
  int *ptr_arr    = arr.begin();
  int *ptr_arr_c  = arr_c;
  int *ptr_arr_c2 = &arr_c[0];

  // ---------------------------------------------------------------
  // Address
  // ---------------------------------------------------------------
  // Variable
  &var;
  ptr_var;
  // Array
  arr.begin();
  ptr_arr;
  // C array
  &arr_c;
  arr_c + 0;
  ptr_arr_c;

  // ---------------------------------------------------------------
  // Value
  // ---------------------------------------------------------------
  // Variable
  var;
  *ptr_var;
  // Array
  arr.at(1);
  ptr_arr[1];
  *(ptr_arr + 1);
  // C array
  arr_c[1];
  ptr_arr_c[1];
  *(ptr_arr_c + 1);

  // ---------------------------------------------------------------
  // Address of pointer
  // ---------------------------------------------------------------
  &ptr_var;
  &ptr_arr;
  &ptr_arr_c;

  // ---------------------------------------------------------------
  // Pointer of pointer
  // ---------------------------------------------------------------
  int *ptr_ptr = ptr_var; // pointer of pointer of var
  ptr_ptr;                // address of var
  *ptr_ptr;               // value of var

  // ---------------------------------------------------------------
  // Double pointer
  // ---------------------------------------------------------------
  int **double_ptr = &ptr_var;
  double_ptr;           // address of ptr_var
  *double_ptr;          // address of var
  **double_ptr;         // value of var

  // ---------------------------------------------------------------
  // Array and pointer
  // ---------------------------------------------------------------
  // array and ptr are similar in operation
  // ptr can point to new variable, array can't
  *ptr_arr++;         // get value of array element, increment address
  *++ptr_arr;         // increment address, get value of array element
  ++*ptr_arr;         // same as above

  // ---------------------------------------------------------------
  // Non const address. Non const value
  // ---------------------------------------------------------------

  // Pointer can point to other structure
  // Pointer can change structure value
  int var_a   = 123;
  int *ptr1  = &var_a;

  // ---------------------------------------------------------------
  // Non const address. Const value
  // ---------------------------------------------------------------
  
  // Pointer can point to other structure
  // Pointer cant change structure value
  const int *ptr2 = &var_a;

  // ---------------------------------------------------------------
  // Const address. Non const value
  // ---------------------------------------------------------------

  // Pointer cant point to other structure
  // Pointer can change structure value
  int *const ptr3 = &var_a;

  // ---------------------------------------------------------------
  // Const address. Const value
  // ---------------------------------------------------------------

  // Pointer cant point to other structure
  // Pointer cant change structure value
  const int *const ptr4 = &var_a;

  // ---------------------------------------------------------------
  // Volatile pointer
  // ---------------------------------------------------------------

  // ---------------------------------------------------------------
  // Void pointer
  // ---------------------------------------------------------------

  // Void pointer points to a data which has no type
  // Void pointer can not be deferenced
  // It can be used as a placeholder when datatype of structure is not known
  void *void_ptr;

  // ---------------------------------------------------------------
  // Null pointer
  // ---------------------------------------------------------------

  // Null pointer points to a data which has no address
  int *ptr_null_1;
  int *ptr_null_2 = nullptr;
  int *ptr_null_3 = NULL;

}

//-------------------------------------------------------------------
int main() {
  raw_pointer();
  return 0;
}