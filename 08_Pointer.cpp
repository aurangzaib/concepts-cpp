#include <iostream>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/dangling-void-null-wild-pointers/?ref=lbp

// ==========================================================================================================
// General
// ==========================================================================================================
// - Pointer is a variable to store address of another variable
// - Raw pointer must be manually deleted after use
// - Pointer can be used to pass func as a param
// - & is reference operator   (address)
// - * is dereference operator (value)
// - There is no difference C-Array and Pointer when accessing value or address
//   Pointer can point to new variable, C-array can't
// - Difference between pointer-to-variable and pointer-to-class:
//   -- Access variable value:       *ptr
//   -- Access class property value : ptr->property

int main() {

    // ==========================================================================================================
    // Variable Declaration
    // ==========================================================================================================
    int var             = 33;
    array<int, 3> arr   = {1, 2, 3};
    int arrc[]          = {99, 98, 97};

    // ==========================================================================================================
    // Pointer Declaration
    // ==========================================================================================================
    int *ptr_var            = &var;
    array<int, 3> *ptr_arr  = &arr;
    int *ptr_arrc           = arrc;

    // ==========================================================================================================
    // Value Using Variable
    // ==========================================================================================================
    cout << var             << endl;
    cout << arr.at(1)       << endl;
    cout << arrc[1]         << endl;
    cout << *(arrc+1)       << endl;

    // ==========================================================================================================
    // Value using Pointer
    // ==========================================================================================================
    cout << *ptr_var        << endl;
    cout << ptr_arr->at(1)  << endl;
    cout << ptr_arrc[1]     << endl;
    cout << *(ptr_arrc+1)   << endl;

    // ==========================================================================================================
    // Address Using Variable
    // ==========================================================================================================
    cout << &var            << endl;
    cout << arr.begin()     << endl;
    cout << &arr            << endl;
    cout << &arr.at(0)      << endl;
    cout << arrc            << endl;

    // ==========================================================================================================
    // Address Using Pointer
    // ==========================================================================================================
    cout << ptr_var         << endl;
    cout << ptr_arr->begin()<< endl;
    cout << ptr_arr         << endl;
    cout << &ptr_arr->at(0) << endl;
    cout << ptr_arrc        << endl;

    // ==========================================================================================================
    // Double pointer
    // ==========================================================================================================
    int **var_ptr_ptr = &ptr_var;
    cout << var             << endl;
    cout << *ptr_var        << endl;
    cout << **var_ptr_ptr   << endl;

    // ==========================================================================================================
    // Dangling pointer
    // ==========================================================================================================
    // - When the memory location pointed by a pointer gets freed/deleted
    // - The pointer becomes dangling pointer
    // - If variable is static, then pointer does not become dangling 

    // ==========================================================================================================
    // Void pointer
    // ==========================================================================================================
    // - Void pointer points to a data which has no type
    // - Void pointer can not be deferenced
    // - Void pointer is a type
    
    void *void_ptr;

    // ==========================================================================================================
    // Null pointer
    // ==========================================================================================================
    // - Null pointer points to a data which has no address
    // - Null pointer is a value

    int *ptr_null_1;
    int *ptr_null_2 = nullptr;
    int *ptr_null_3 = NULL;

    // *ptr_null will be an exception
    // &ptr_null will be address of pointer

    // ==========================================================================================================
    // Wild pointer
    // ==========================================================================================================
    // - When a pointer is not initialized to any address
    // - The pointer will point to a garbage address
    
    int *wild_ptr;
}
