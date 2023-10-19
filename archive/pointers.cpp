/*
 http://www.cplusplus.com/doc/tutorial/pointers/

 linked list vs vector
 https://softwareengineering.stackexchange.com/questions/185222/what-is-the-point-of-using-lists-over-vectors-in-c
 bjarne recommend to use std::vector over std::array or std::list
*/
#include <array>
#include <vector>
#include <string>

int main() {

    // strings
    string a_string = "hello"; // static compile time size
    char a_string_2[] = "hello"; // dynamic runtime size
    // pointer and const
    int some_var;
    // non-const ptr, non-const var
    // it can point to new address, it can change  value
    int *ptr = &some_var;
    // non-const ptr, const var
    // it can point to new address, it cant change  value
    const int *ptr = &some_var;
    // same as above
    int const *ptr = &some_var;
    // const ptr, non-const var
    // it cant point to new address, it can change value
    int *const ptr = &some_var;
    // const ptr, const var
    // it cant point to new address, it cant change value
    const int *const ptr = &some_var;

    // conclusion:
    /*
    const is before * --> cant change value
    const is after  * --> cant change address
    */

    // void pointer
    // void pointer points to a value that has no type
    // data pointed to by void ptr cant be dereferenced
    void *some_ptr;
    // null pointer
    // points to an address which doesn't exist
    int *ptr = nullptr; // null pointer
    /*
      void *ptr             --> void ptr
      int *ptr              --> null pointer
      int *ptr = nullptr    --> null pointer
      int *ptr = NULL       --> null pointer
     */

    int a[] = {1, 2, 3};
    int *ptr2 = a + 4; // 4th address doesnt exist

    // pointer to functions --> skipped
    // new and delete --> dynamic mem alloc and dealloc

    // static array with fixed size
    int an_static_array[10];

    // dynamic array with dynamic size
    size_t size = 11;
    int *a_dynamic_array = new int[size];
    delete[] a_dynamic_array;

    // malloc, free, realloc are C counterparts of new and delete
}