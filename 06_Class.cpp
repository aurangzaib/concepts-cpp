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
*this* pointer
-------------------------------------
- To access class property/method from inside the class
- Inside class, property can be accessed by this->prop or directly prop

-------------------------------------
Constructor (ctor)
-------------------------------------
- Used to initialize properties of the class
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

*/

using namespace std;

namespace NSClass1 {

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
    Class();                                                                     // Default Constructor
    Class(const Class &);                                                        // Copy Constructor
    Class(const int &, const array<T, N> &, const vector<T> &, const string &);  // Constructor
    void set_vector(const vector<T> &);                                          // Setter
    void set_string(const string &);                                             // Setter
    const vector<T> get_vector();                                                // Getter
    const string get_string();                                                   // Getter
    Class operator+(const Class &);                                              // Overloading
    void operator=(const Class &);                                               // Overloading
};

// Default Constructor
template <typename T, size_t N>
NSClass1::Class<T, N>::Class() : num(0) {
    this->private_structure.arr.fill(0);
}

// Copy Constructor
template <typename T, size_t N>
NSClass1::Class<T, N>::Class(const Class &inst) : num(inst.num) {
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
NSClass1::Class<T, N>::Class(const int &num, const array<T, N> &arr, const vector<T> &vec, const string &str) {
    this->num = num;
    this->private_structure = {.arr = arr, .vec = vec, .str = str};
}

// Setters
template <typename T, size_t N>
void NSClass1::Class<T, N>::set_vector(const vector<T> &vec) {
    // remove old elements
    this->private_structure.vec.clear();
    // add new elements
    for (const auto &itr : vec) {
        this->private_structure.vec.push_back(itr);
    }
}
template <typename T, size_t N>
void NSClass1::Class<T, N>::set_string(const string &str) {
    this->private_structure.str = str;
}

// Getters
template <typename T, size_t N>
const vector<T> NSClass1::Class<T, N>::get_vector() {
    return this->private_structure.vec;
}
template <typename T, size_t N>
const string NSClass1::Class<T, N>::get_string() {
    return this->private_structure.str;
}

// Overloading
template <typename T, size_t N>
NSClass1::Class<T, N> NSClass1::Class<T, N>::operator+(const Class &inst) {
    Class new_inst;
    new_inst.num = this->num + inst.num;
    return new_inst;
}

template <typename T, size_t N>
void NSClass1::Class<T, N>::operator=(const Class &inst) {
    this->num = num;
    this->private_structure = inst.private_structure;
    this->protected_structure = inst.protected_structure;
}

// ==========================================================================================================
// Test
// ==========================================================================================================

void Test() {
    // Instantiation
    NSClass1::Class<int, 3> ins1;
    NSClass1::Class<int, 3> ins2(33, (array<int, 3>){1, 2, 3}, (vector<int>){4, 5, 6}, "Hello World");

    // Getter Setter
    vector<int> vec1 = ins1.get_vector();
    vector<int> vec2 = ins2.get_vector();
    ins1.set_vector(vector<int>{99, 99, 99});
    vector<int> vec3 = ins1.get_vector();

    // Overloading
    NSClass1::Class<int, 3> ins3 = ins1 + ins2;
    ins1 = ins2;

    // ins1 is not a reference of ins2
    vector<int> vec4 = ins1.get_vector();
    ins2.set_vector((vector<int>){-99, -99, -99});
    vector<int> vec5 = ins1.get_vector();
    vector<int> vec6 = ins2.get_vector();

    // Debugger point
    return;
}

}  // namespace NSClass1

//---------------------------------------------------------------------------------------------------------------
int main() {
    NSClass1::Test();
    return 0;
}