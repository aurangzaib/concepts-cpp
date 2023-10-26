#include <iostream>
#include <array>

using namespace std;

void raw_pointer() {

    // ==========================================================================================================
    // Main topics
    // ==========================================================================================================

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
    //   -- Access variable value:       *ptr
    //   -- Access class property value : ptr->property
    // - C-array and Pointer are similar in operation
    // - Pointer can point to new variable, C-array can't
    // - Variable and C-Array pointers have same access syntax
    // - Variable and class pointers have same declaration syntax 

    // ---------------------------------------------------------------
    // Declaration
    // ---------------------------------------------------------------
    int var            = 3;
    array<int, 4> arr  = {1, 2, 3, 4};
    int arrc[]         = {1, 2, 3, 4};

    // ---------------------------------------------------------------
    // Pointer
    // ---------------------------------------------------------------
    int             *var_ptr   = &var; // Pointer to a variable
    array<int, 4>   *arr_ptr   = &arr; // Pointer to a class
    int             *arrc_ptr  = arrc; // Pointer to c-array 

    // ---------------------------------------------------------------
    // Value
    // ---------------------------------------------------------------
    cout << var                 << endl; // Variable     
    cout << *var_ptr            << endl;           
    cout << arr.at(0)           << endl; // Class
    cout << arr_ptr->at(0)      << endl;
    cout << (*arr_ptr).at(0)    << endl;
    cout << arrc[0]             << endl; // C-array
    cout << *(arrc_ptr + 0)     << endl;

    // ---------------------------------------------------------------
    // Address
    // ---------------------------------------------------------------
    cout << &var                << endl; // Variable
    cout << var_ptr             << endl;
    cout << &arr                << endl; // Class
    cout << &arr.at(0)          << endl;
    cout << arr.begin()         << endl;
    cout << arr_ptr->begin()    << endl;
    cout << (*arr_ptr).begin()  << endl;
    cout << arr_ptr             << endl;
    cout << arrc                << endl; // C-array
    cout << &arrc[0]            << endl;
    cout << arrc_ptr            << endl;

    // ---------------------------------------------------------------
    // Address (pointer)
    // ---------------------------------------------------------------
    cout << &var_ptr            << endl;
    cout << &arr_ptr            << endl;
    cout << &arrc_ptr           << endl;

    // ---------------------------------------------------------------
    // Double pointer
    // ---------------------------------------------------------------
    int **var_ptr_ptr = &var_ptr;
    cout << var             << endl;
    cout << *var_ptr        << endl;
    cout << **var_ptr_ptr   << endl;

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

    // ---------------------------------------------------------------
    // Volatile pointer
    // ---------------------------------------------------------------

    // ==========================================================================================================
    // Extra topics
    // ==========================================================================================================

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

}

//---------------------------------------------------------------------------------------------------------------
int main() {
    raw_pointer();
    return 0;
}