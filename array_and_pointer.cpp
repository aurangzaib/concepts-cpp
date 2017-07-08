// http://www.cplusplus.com/doc/tutorial/pointers/

#include <array>
#include <vector>
#include <string>

int main() {

    // always prefer stl array
    // #include <array>
    array<int, 4> my_array{1, 2, 3, 4};
    my_array.size();

    // still better, vector can be used which has dynamic size
    vector<int> my_vector{1, 2, 3, 4};
    cout << my_vector.size();
    // always use .at() to access element, it has boundary checks

    // strings
    string a_string = "hello"; // static compile time size
    char a_string_2[] = "hello"; // dynamic runtime size

    // pointer --> variable which stores a/d of another variable

    // dereference operator --> *
    // reference operator --> &

    int aa = 33;

    // case-1: pointer
    int *a_ptr = &aa;   // another way --> int *a_ptr; a_ptr = &aa;
    cout << &aa         // address of a
         << a_ptr       // address of a
         << aa          // value of a
         << *a_ptr      // value of a
         << &a_ptr;     // address of a_ptr

    *a_ptr = 3; // --> update value of aa

    // case-2: pointer to a pointer
    int *a_ptr_to_ptr = a_ptr;

    // case-3: double pointer
    int **a_ptr_ptr = &a_ptr;
    cout << &a_ptr_ptr  // address of a_ptr_ptr
         << a_ptr_ptr   // address of a_ptr
         << *a_ptr_ptr  // address of aa
         << **a_ptr_ptr;// value of a

    // int **a_ptr_ptr = &aa --> wrong

    // arrays and pointers
    int an_array[] = {1, 2, 3};

    cout << an_array
         << *an_array
         << *(an_array + 1)
         << &an_array[2]
         << (an_array + 2);

    int *an_array_ptr = an_array; // note: there is no & needed for array

    // arrays and ptr are similar in operation
    // ptr can point to new variable, array can't


    *an_array_ptr++; // increment a/d, dereference un-incremented
    *++an_array_ptr; // increment a/d, dereference incremented
    ++*an_array_ptr; // dereference, increment a/d
    (*an_array_ptr)++;// same as *an_array_ptr++

    *p++ = *q++;
    // above statement means:
    *p = *q;
    ++q;
    ++p;

    *p++ = *++q;
    // above statement means:
    ++q;
    *p = *q;
    ++p;

    *++p = *++q;
// above statement means:
    ++q;
    ++p;
    *p = *q;

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
    int *ptr; // uninitialized pointer
    int a[] = {1, 2, 3};
    int *ptr2 = a + 4; // 4th address doesnt exist
    /*
      void *ptr             --> void ptr
      int *ptr              --> null pointer
      int *ptr = nullptr    --> null pointer
      int *ptr = NULL       --> null pointer
     */

    // pointer to functions
    // not done


    // new and delete --> dynamic mem alloc and dealloc

    // static array with fixed size
    int an_static_array[10];

    // dynamic array with dynamic size
    size_t size = 11;
    int *a_dynamic_array;
    a_dynamic_array = new int[size];
    delete[] a_dynamic_array;

    // malloc, free, realloc are C counterparts of new and delete
}