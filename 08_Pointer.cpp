/*

 Description:
 Raw Pointer

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
#include <array>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/?ref=lbp

// ==========================================================================================================
// General
// ==========================================================================================================
// - Pointer is a variable to store address of another variable
// - Pointer has same type as variable (int, vector etc.)
// - Raw pointer must be manually deleted after use
// - Pointer can be used to pass func as a param
// - & is reference operator   (address)
// - * is dereference operator (value)
// - No difference between C-Array and Pointer when accessing value or address
// - Pointer can point to new variable, C-array can't
// - Difference between pointer-to-variable and pointer-to-class:
//   -- Access variable value:       *ptr
//   -- Access class property value : ptr->property

int main() {
    // ==========================================================================================================
    // Variable Declaration
    // ==========================================================================================================
    int var = 33;
    array<int, 3> arr = {1, 2, 3};
    int arrc[] = {99, 98, 97};

    // ==========================================================================================================
    // Pointer Declaration
    // ==========================================================================================================
    int *ptr_var = &var;
    array<int, 3> *ptr_arr = &arr;
    int *ptr_arrc = arrc;

    // ==========================================================================================================
    // Value Using Variable
    // ==========================================================================================================
    cout << var << endl;
    cout << arr.at(1) << endl;
    cout << arrc[1] << endl;
    cout << *(arrc + 1) << endl;

    // ==========================================================================================================
    // Value using Pointer
    // ==========================================================================================================
    cout << *ptr_var << endl;
    cout << ptr_arr->at(1) << endl;
    cout << (*ptr_arr).at(1);
    cout << ptr_arrc[1] << endl;
    cout << *(ptr_arrc + 1) << endl;

    // ==========================================================================================================
    // Address Using Variable
    // ==========================================================================================================
    cout << &var << endl;
    cout << arr.begin() << endl;
    cout << &arr << endl;
    cout << &arr.at(0) << endl;
    cout << arrc << endl;

    // ==========================================================================================================
    // Address Using Pointer
    // ==========================================================================================================
    cout << ptr_var << endl;
    cout << ptr_arr->begin() << endl;
    cout << ptr_arr << endl;
    cout << &ptr_arr->at(0) << endl;
    cout << ptr_arrc << endl;

    // ==========================================================================================================
    // Double pointer
    // ==========================================================================================================
    // ----------------------
    // Declaration
    // ----------------------
    int **ptr_ptr_var = &ptr_var;
    // ----------------------
    // Value
    // ----------------------
    cout << var << endl;
    cout << *ptr_var << endl;
    cout << **ptr_ptr_var << endl;
    // ----------------------
    // Address
    // ----------------------
    cout << &var << endl;
    cout << ptr_var << endl;
    cout << *ptr_ptr_var << endl;

    // ==========================================================================================================
    // Dangling pointer
    // ==========================================================================================================
    // - When the pointed memory location gets freed/deleted, pointer becomes dangling pointer
    // - If variable is static, then pointer does not become dangling

    // ==========================================================================================================
    // Void pointer
    // ==========================================================================================================
    // - Pointer with void type but points to nothing
    // - It can't be deferenced
    // - It is a type

    void *void_ptr;

    // ==========================================================================================================
    // Null pointer
    // ==========================================================================================================
    // - Pointer with a type but points to NULL
    // - It can't be deferenced
    // - It is a value

    int *ptr_null_2 = nullptr;
    int *ptr_null_3 = NULL;

    // *ptr_null will be an exception
    // &ptr_null will be address of pointer

    // ==========================================================================================================
    // Wild pointer
    // ==========================================================================================================
    // - When a pointer is not initialized to any address
    // - It points to a random memory address

    int *wild_ptr;

    // ==========================================================================================================
    // Summary of pointer types
    // ==========================================================================================================
    // | Type of pointer  | Description                                        |
    // -------------------------------------------------------------------------
    // | Valid pointer    | Valid type     Valid address      Valid value      |
    // | Dangling pointer | Valid type     Valid address      Random value     |
    // | Wild pointer     | Valid type     Random address     Random value     |
    // | Void pointer     | Void type      No address         No value         |
    // | Null pointer     | valid type     No address         NULL value       |
    // -------------------------------------------------------------------------
}
