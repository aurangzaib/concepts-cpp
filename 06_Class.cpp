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
----------------------------------------------------
Members
----------------------------------------------------
- Data member:      Properties (Variables)
- Member function:  Methods    (Functions)

----------------------------------------------------
Private member
----------------------------------------------------
- Accessible inside class
- Accessible outside class using methods (NOT directly though instance)
- Accessible using friend function/class
- Default

----------------------------------------------------
Protected member
----------------------------------------------------
- Accessible by same, derived and friend

----------------------------------------------------
Public member
----------------------------------------------------
- Accessible inside/outside using instance
- Struct has by default public
- Separate for each instance

----------------------------------------------------
Static members
----------------------------------------------------
- Accesible inside/outside using class and instance
- Shared by all instances (once per class)
- Initialized outside of class definition

----------------------------------------------------
Scope resolution operator (::)
----------------------------------------------------
- Access class members outside the class definition

----------------------------------------------------
this->
----------------------------------------------------
- Access class members from inside the class
- Optional

----------------------------------------------------
Constructor (ctor)
----------------------------------------------------
- Initialize class properties
- No return type

----------------------------------------------------
Desstructor (dtor)
----------------------------------------------------
- Called after end-of-life of object e.g. after main

----------------------------------------------------
Operators that can be overloaded
----------------------------------------------------
+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
<<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new

----------------------------------------------------
Constant instance
----------------------------------------------------
- All properties will become read-only
- Can only access constant methods

*/

using namespace std;

// ==========================================================================================================
// Namespace
// ==========================================================================================================

namespace NS {

// ==========================================================================================================
// Structure
// ==========================================================================================================

template <typename T, size_t N>
struct Structure {
    array<T, N> arr;
    vector<T> vec;
    string str;
}; // End of structure

// ==========================================================================================================
// Class Declaration
// ==========================================================================================================

template <typename T, size_t N>
class Cls {
   private:
    int num;
    Structure<T, N> private_structure;

   protected:
    Structure<T, N> protected_structure;

   public:
    static int num_static;                                                     // Static Property
    Cls();                                                                     // Default Constructor
    Cls(const Cls &);                                                          // Copy    Constructor
    Cls(const int &, const array<T, N> &, const vector<T> &, const string &);  // Param   Constructor
    ~Cls();                                                                    // Destructor
    void set_vector(const vector<T> &);                                        // Setter
    void set_string(const string &);                                           // Setter
    const vector<T> get_vector();                                              // Getter
    const string get_string();                                                 // Getter
    Cls operator+(const Cls &);                                                // Overloading
    void operator=(const Cls &);                                               // Overloading
    void operator+=(const Cls &);                                              // Overloading
    static void func_static();                                                 // Static Method
};// End of class

// ==========================================================================================================
// Test Declaration
// ==========================================================================================================

void Test();

} // End of namespace

// ==========================================================================================================
// Class Definition
// ==========================================================================================================

// Static Property
template <typename T, size_t N>
int NS::Cls<T, N>::num_static = 999;

// Default Constructor
template <typename T, size_t N>
NS::Cls<T, N>::Cls() : num(0) {
    this->private_structure.arr.fill(0);
}

// Copy Constructor
template <typename T, size_t N>
NS::Cls<T, N>::Cls(const Cls &inst) : num(inst.num) {
    // Option 1
    this->private_structure.arr = inst.private_structure.arr;
    this->private_structure.vec = inst.private_structure.vec;
    this->private_structure.str = inst.private_structure.str;
    // Option 2
    private_structure.arr = inst.private_structure.arr;
    private_structure.vec = inst.private_structure.vec;
    private_structure.str = inst.private_structure.str;
    // Option 3
    this->private_structure = {
        .arr = inst.private_structure.arr,
        .vec = inst.private_structure.vec,
        .str = inst.private_structure.str,
    };
};

// Param Constructor
template <typename T, size_t N>
NS::Cls<T, N>::Cls(const int &num, const array<T, N> &arr, const vector<T> &vec, const string &str) {
    this->num = num;
    this->private_structure = {.arr = arr, .vec = vec, .str = str};
}

// Destructor
template <typename T, size_t N>
NS::Cls<T, N>::~Cls() {
    cout << endl << "Destructor is called" << endl;
}

// Setters
template <typename T, size_t N>
void NS::Cls<T, N>::set_vector(const vector<T> &vec) {
    // remove old elements
    this->private_structure.vec.clear();
    // insert new elements
    for (const T &itr : vec) {
        this->private_structure.vec.push_back(itr);
    }
}
template <typename T, size_t N>
void NS::Cls<T, N>::set_string(const string &str) {
    this->private_structure.str = str;
}

// Getters
template <typename T, size_t N>
const vector<T> NS::Cls<T, N>::get_vector() {
    return this->private_structure.vec;
}
template <typename T, size_t N>
const string NS::Cls<T, N>::get_string() {
    return this->private_structure.str;
}

// Overloading
template <typename T, size_t N>
NS::Cls<T, N> NS::Cls<T, N>::operator+(const Cls &inst) {
    Cls new_inst;
    new_inst.num = this->num + inst.num;
    return new_inst;
}
template <typename T, size_t N>
void NS::Cls<T, N>::operator=(const Cls &inst) {
    this->num = num;
    this->private_structure = inst.private_structure;
    this->protected_structure = inst.protected_structure;
}
template <typename T, size_t N>
void NS::Cls<T, N>::operator+=(const Cls &inst) {
    this->num += num;
    for (size_t loop = 0; loop < this->private_structure.arr.size(); loop += 1) {
        this->private_structure.arr.at(loop) += inst.private_structure.arr.at(loop);
    }
    for (size_t loop = 0; loop < this->private_structure.vec.size(); loop += 1) {
        this->private_structure.vec.at(loop) += inst.private_structure.vec.at(loop);
    }
    this->private_structure.str += inst.private_structure.str;
}

// Static method
template <typename T, size_t N>
void NS::Cls<T, N>::func_static() {
    cout << endl << Cls::num_static << endl;
}

// ==========================================================================================================
// Test Definition
// ==========================================================================================================

void NS::Test() {
    // size of array
    const int size = 3;

    // Instantiation
    NS::Cls<int, size> ins1;        // Default constructor
    NS::Cls<int, size> ins2(ins1);  // Copy constructor
    NS::Cls<int, size> ins3(33, (array<int, size>){1, 2, 3}, (vector<int>){4, 5, 6}, "Hello World");  // Cosntructor
    // Getter Setter
    vector<int> vec1 = ins1.get_vector();
    vector<int> vec2 = ins3.get_vector();
    ins1.set_vector(vector<int>{99, 99, 99});
    vector<int> vec3 = ins1.get_vector();

    // Overloading
    NS::Cls<int, size> ins4 = ins1 + ins3;  // + overloaded
    ins1 = ins3;                            // = overloaded
    ins1 += ins3;                           // += overloaded

    // ins1 is not a reference of ins3
    vector<int> vec4 = ins1.get_vector();
    ins3.set_vector((vector<int>){-99, -99, -99});
    vector<int> vec5 = ins1.get_vector();
    vector<int> vec6 = ins3.get_vector();

    // Static property
    NS::Cls<int, size>::num_static = 998;
    NS::Cls<int, size>::func_static();
    ins1.num_static = 997;
    ins1.func_static();

    // Debugger point
    return;
}

//---------------------------------------------------------------------------------------------------------------
int main() {
    NS::Test();
    return 0;
}
