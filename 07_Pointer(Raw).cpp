#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

// ==========================================================================================================
// Raw pointer
// ==========================================================================================================
void raw_pointer() {

    // ---------------------------------------------------------------
    // General
    // ---------------------------------------------------------------
    // - Pointer is a variable to store address of another variable
    // - Raw pointer should be avoided, use smart pointer
    // - Raw pointer must be manually deleted after use
    // - Pointer can be used to pass func as a param
    // - & --> reference operator   (address)
    // - * --> dereference operator (value)
    // - Difference between pointer-to-variable and pointer-to-class:
    //   - Access variable value:       *ptr
    //   - Access class property value : ptr->property
    // C-array and Pointer are similar in operation
    // Pointer can point to new variable, C-array can't

    // ---------------------------------------------------------------
    // Initialization
    // ---------------------------------------------------------------
    int var             = 3;
    array<int, 4> arr   = {1, 2, 3, 4};

    // ---------------------------------------------------------------
    // Pointer
    // ---------------------------------------------------------------
    int             *var_ptr   = &var; // pointer to a variable
    array<int, 4>   *arr_ptr   = &arr; // pointer to a class

    // ---------------------------------------------------------------
    // Value of Variable
    // ---------------------------------------------------------------
    cout << var                 << endl;           
    cout << *var_ptr            << endl;           
    cout << arr.at(0)           << endl;
    cout << arr_ptr->at(0)      << endl;
    cout << (*arr_ptr).at(0)    << endl;

    // ---------------------------------------------------------------
    // Address of Variable
    // ---------------------------------------------------------------
    cout << &var                << endl;
    cout << var_ptr             << endl;
    cout << &arr                << endl;
    cout << &arr.at(0)          << endl;
    cout << arr.begin()         << endl;
    cout << arr_ptr->begin()    << endl;
    cout << (*arr_ptr).begin()  << endl;
    cout << arr_ptr             << endl;

    // ---------------------------------------------------------------
    // Address of pointer
    // ---------------------------------------------------------------
    cout << &var_ptr            << endl;
    cout << &arr_ptr            << endl;

    // ---------------------------------------------------------------
    // Pointer of pointer
    // ---------------------------------------------------------------
    int *ptr_ptr = var_ptr;
    cout << ptr_ptr             << endl; // address of var
    cout << *ptr_ptr            << endl; // value of var

    // ---------------------------------------------------------------
    // Double pointer
    // ---------------------------------------------------------------
    int **double_ptr = &var_ptr;
    cout << double_ptr            << endl; // address of var_ptr
    cout << *double_ptr           << endl; // address of var
    cout << **double_ptr          << endl; // value of var

    // ---------------------------------------------------------------
    // Array and pointer
    // ---------------------------------------------------------------
    // *arr_ptr++            << endl;  // get value of array element, increment address
    // *++arr_ptr            << endl;  // increment address, get value of array element
    // ++*arr_ptr            << endl;  // same as above

    // ----------------------------------------------------------------
    // Non const address. Non const value
    // ---------------------------------------------------------------
    // Pointer can point to other structure
    // Pointer can change structure value
    int var_a = 123;
    int *ptr1 = &var_a;

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

//---------------------------------------------------------------------------------------------------------------
int main() {
    raw_pointer();
    return 0;
}