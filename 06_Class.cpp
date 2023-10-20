#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*
------------------------------------
Members
------------------------------------
- Data member:      Properties
- Member function:  Methods

-------------------------------------
Private member
-------------------------------------
- Members are accessible inside class
- Members are accessible outside class only using functions
- Memebers are accessible using friend function/class
- Class has by default private

-------------------------------------
Protected member
-------------------------------------
- Members are accessible by same, derived and friend

-------------------------------------
Public member
-------------------------------------
- Members are accessible inside/outside using instance
- Struct has by default public (once per instance)
- Separate for each instance

-------------------------------------
Static members
-------------------------------------
- Members are accesible inside/outside using class (no instance required)
- Shared by all instances (once per class)
- Initialized outside of the class

-------------------------------------
Scope resolution operator (::)
-------------------------------------
- To access class property/method from outside the class

-------------------------------------
this
-------------------------------------
- To access class property/method from inside the class
- Inside class, property can be accessed by this->prop or directly prop

-------------------------------------
Constructor (ctor)
-------------------------------------
- To initialize class properties
- Has no return type

-------------------------------------
Desstructor (dtor)
-------------------------------------
- Called after end-of-life of object e.g. after main

-------------------------------------
Operators that can be overloaded
-------------------------------------
+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
<<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new

-------------------------------------
Syntax of a method
-------------------------------------
const int class::method(const int& a) const{}
|__ return type         |__ params    |__method can't be changed

-------------------------------------
Constant instance
-------------------------------------
- All properties will become read-only
- Can only access constant methods

*/

using namespace std;

namespace NSClass {

// ==========================================================================================================
// Class
// ==========================================================================================================

// Structure
template <typename T, size_t N>
struct Structure {
    array<T, N> arr;
    vector<T> vec;
    string str;
};

// Class
template <typename T, size_t N>
class Class {
   private:
    int num;
    Structure<T, N> private_structure;

   protected:
    Structure<T, N> protected_structure;

   public:
    static int num_static;                                                       // Static property
    Class();                                                                     // Default Constructor
    Class(const Class &);                                                        // Copy Constructor
    Class(const int &, const array<T, N> &, const vector<T> &, const string &);  // Constructor
    void set_vector(const vector<T> &);                                          // Setter
    void set_string(const string &);                                             // Setter
    const vector<T> get_vector();                                                // Getter
    const string get_string();                                                   // Getter
    Class operator+(const Class &);                                              // Overloading
    void operator=(const Class &);                                               // Overloading
    static void func_static();                                                   // Static method
};

// Static Property
template <typename T, size_t N>
int NSClass::Class<T, N>::num_static = 999;

// Default Constructor
template <typename T, size_t N>
NSClass::Class<T, N>::Class() : num(0) {
    this->private_structure.arr.fill(0);
}

// Copy Constructor
template <typename T, size_t N>
NSClass::Class<T, N>::Class(const Class &inst) : num(inst.num) {
    // Option 1
    private_structure.arr = inst.private_structure.arr;
    private_structure.vec = inst.private_structure.vec;
    private_structure.str = inst.private_structure.str;
    // Option 2
    this->private_structure.arr = inst.private_structure.arr;
    this->private_structure.vec = inst.private_structure.vec;
    this->private_structure.str = inst.private_structure.str;
    // Option 3
    this->private_structure = {
        .arr = inst.private_structure.arr,
        .vec = inst.private_structure.vec,
        .str = inst.private_structure.str,
    };
};

// Constructor
template <typename T, size_t N>
NSClass::Class<T, N>::Class(const int &num, const array<T, N> &arr, const vector<T> &vec, const string &str) {
    this->num = num;
    this->private_structure = {.arr = arr, .vec = vec, .str = str};
}

// Setters
template <typename T, size_t N>
void NSClass::Class<T, N>::set_vector(const vector<T> &vec) {
    // remove old elements
    this->private_structure.vec.clear();
    // add new elements
    for (const auto &itr : vec) {
        this->private_structure.vec.push_back(itr);
    }
}
template <typename T, size_t N>
void NSClass::Class<T, N>::set_string(const string &str) {
    this->private_structure.str = str;
}

// Getters
template <typename T, size_t N>
const vector<T> NSClass::Class<T, N>::get_vector() {
    return this->private_structure.vec;
}
template <typename T, size_t N>
const string NSClass::Class<T, N>::get_string() {
    return this->private_structure.str;
}

// Overloading
template <typename T, size_t N>
NSClass::Class<T, N> NSClass::Class<T, N>::operator+(const Class &inst) {
    Class new_inst;
    new_inst.num = this->num + inst.num;
    return new_inst;
}
template <typename T, size_t N>
void NSClass::Class<T, N>::operator=(const Class &inst) {
    this->num = num;
    this->private_structure = inst.private_structure;
    this->protected_structure = inst.protected_structure;
}

// Static method
template <typename T, size_t N>
void NSClass::Class<T, N>::func_static() {
    cout << endl << Class::num_static << endl;
}

// ==========================================================================================================
// Test
// ==========================================================================================================

void Test() {
    // Instantiation
    NSClass::Class<int, 3> ins1;
    NSClass::Class<int, 3> ins2(33, (array<int, 3>){1, 2, 3}, (vector<int>){4, 5, 6}, "Hello World");

    // Getter Setter
    vector<int> vec1 = ins1.get_vector();
    vector<int> vec2 = ins2.get_vector();
    ins1.set_vector(vector<int>{99, 99, 99});
    vector<int> vec3 = ins1.get_vector();

    // Overloading
    NSClass::Class<int, 3> ins3 = ins1 + ins2;
    ins1 = ins2;

    // ins1 is not a reference of ins2
    vector<int> vec4 = ins1.get_vector();
    ins2.set_vector((vector<int>){-99, -99, -99});
    vector<int> vec5 = ins1.get_vector();
    vector<int> vec6 = ins2.get_vector();

    // Static property
    NSClass::Class<int, 1>::func_static();
    NSClass::Class<int, 1>::num_static = 998;
    NSClass::Class<int, 1>::func_static();
    ins1.num_static = 997;
    ins1.func_static();

    // Pointers
    int var = 0;
    int arr[] = {1, 2, 3, 4};
    const int *var_ptr = &var;                 // Pointer to variable
    const int *arr_ptr = arr;                  // Pointer to array
    NSClass::Class<int, 3> *inst_ptr = &ins1;  // Pointer to instance
    cout << var_ptr;                           // Access by Pointer
    cout << arr_ptr[0];                        // Access by Pointer
    ins1.get_vector();                         // Access by Instance
    inst_ptr->get_vector();                    // Access by Pointer
    (*inst_ptr).get_vector();                  // Access by Dereferenced Pointer

    // Debugger point
    return;
}

}  // namespace NSClass

//---------------------------------------------------------------------------------------------------------------
int main() {
    NSClass::Test();
    return 0;
}