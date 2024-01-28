/*

 Description:
 Class

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/c-partially-object-oriented-language/?ref=lbp
// - https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/?ref=lbp
// - https://www.geeksforgeeks.org/friend-class-function-cpp/?ref=lbp
// - https://www.geeksforgeeks.org/constructors-c/?ref=lbp

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*

----------------------------------------------------
Object Oriented Concepts
----------------------------------------------------
- Class
- Encapsulation
- Abstraction
- Polymorphism
- Inheritance
- Dynamic Binding
- Message Passing

----------------------------------------------------
Members
----------------------------------------------------
- Data member:      Properties (Variables)
- Member function:  Methods    (Functions)

----------------------------------------------------
Access Modifier
----------------------------------------------------
- Private
- Protected
- Public

----------------------------------------------------
Private member
----------------------------------------------------
- Accessible by class and friend function/class
- Accessible outside class using methods (NOT directly through instance)
- Default

----------------------------------------------------
Protected member
----------------------------------------------------
- Accessible by class, inherited class and friend class
- Accessible outside class using methods (NOT directly through instance)

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
- Must be defined as public member

----------------------------------------------------
Method access outside class
----------------------------------------------------
- Standard:                    Cls::method
- With template:               Cls<T>::method
- With namespace:              NS::Cls::method
- With namespace and template: NS::Cls<T>::method

----------------------------------------------------
Friend members
----------------------------------------------------
- It has access to private/protected/public without inheriting class
- It is not a member function of a class
- It has no access to "this" operator
- It does not need Class:: operator

----------------------------------------------------
Scope resolution operator (::)
----------------------------------------------------
- To access class methods outside declaration
- To access class static properties

----------------------------------------------------
this
----------------------------------------------------
- To access instance properties inside methods
- To chain methods (return *this)

----------------------------------------------------
Functor
----------------------------------------------------
- A Class whose () operator is overloaded
- Instance can be invoked as a function
- Also called function objects

----------------------------------------------------
Constructor
----------------------------------------------------
- Member function with same name as class
- To initialize class properties
- It has no return type

----------------------------------------------------
Copy Constructor
----------------------------------------------------
- Why provide copy constructor? Otherwise:
- Compiler will create reference instead of copying the instance
- Any changes to first instance will reflect in copied instance

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

----------------------------------------------------
Encapsulation and Abstraction
----------------------------------------------------
- Logic Encapsulation: Only public functions are accessible from outside
- Data Encapsulation:  Data is accessible through functions from outside
- Data Abstraction:    Hide irrelevant data using access modifiers
- Data Binding:        Bind data and functions using class

*/

using namespace std;

// ==========================================================================================================
// Namespace Declaration
// ==========================================================================================================

// Namespace
namespace NS {

// ==========================================================================================================
// Structure Declaration
// ==========================================================================================================

template <typename T, size_t N>
struct Structure {
    array<T, N> arr;
    vector<T> vec;
    string str;
};

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
    Cls();                                                                     // Default         Constructor
    Cls(const Cls &);                                                          // Copy            Constructor
    Cls(const int &, const array<T, N> &, const vector<T> &, const string &);  // Parameterized   Constructor
    ~Cls();                                                                    // Destructor
    Cls set_vector(const vector<T> &);                                         // Setter
    Cls &set_string(const string &);                                           // Setter (with method chaining)
    const vector<T> get_vector();                                              // Getter
    const string get_string();                                                 // Getter
    void reset_vector();                                                       // Reset
    Cls operator+(const Cls &);                                                // Overloading
    void operator=(const Cls &);                                               // Overloading
    void operator+=(const Cls &);                                              // Overloading
    void operator()();                                                         // Functor
    static void func_static();                                                 // Static Method
    friend Cls set_vector(Cls &ins, const vector<T> vec) {                     // Friend Method (definition)
        ins.private_structure.vec = vec;
        return ins;
    }
    // Note: When using friend with template class, its easier to provide inline definition
    // Link: https://isocpp.org/wiki/faq/templates#template-friends
};

// ==========================================================================================================
// Test Declaration
// ==========================================================================================================

void Test();

}  // namespace NS

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
NS::Cls<T, N>::Cls(const Cls &ins) : num(ins.num), protected_structure(ins.protected_structure) {
    // Option 1
    this->private_structure = ins.private_structure;
    // Option 2
    private_structure = ins.private_structure;
    // Option 3
    this->private_structure = {
        .arr = ins.private_structure.arr,
        .vec = ins.private_structure.vec,
        .str = ins.private_structure.str,
    };
};

// Parameterized Constructor
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
NS::Cls<T, N> NS::Cls<T, N>::set_vector(const vector<T> &vec) {
    // remove old elements
    this->private_structure.vec.clear();
    // insert new elements
    for (const T &element : vec) {
        this->private_structure.vec.push_back(element);
    }
    // Method chaining
    return *this;
}
template <typename T, size_t N>
NS::Cls<T, N> &NS::Cls<T, N>::set_string(const string &str) {
    this->private_structure.str = str;

    return *this;
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

// Reset with public function
template <typename T, size_t N>
void NS::Cls<T, N>::reset_vector() {
    this->private_structure.vec.clear();
}

// Overloading
template <typename T, size_t N>
NS::Cls<T, N> NS::Cls<T, N>::operator+(const Cls &ins) {
    Cls new_inst;
    new_inst.num = this->num + ins.num;
    return new_inst;
}
template <typename T, size_t N>
void NS::Cls<T, N>::operator=(const Cls &ins) {
    this->num = num;
    this->private_structure = ins.private_structure;
    this->protected_structure = ins.protected_structure;
}
template <typename T, size_t N>
void NS::Cls<T, N>::operator+=(const Cls &ins) {
    this->num += num;
    for (size_t loop = 0; loop < this->private_structure.arr.size(); loop += 1) {
        this->private_structure.arr.at(loop) += ins.private_structure.arr.at(loop);
    }
    for (size_t loop = 0; loop < this->private_structure.vec.size(); loop += 1) {
        this->private_structure.vec.at(loop) += ins.private_structure.vec.at(loop);
    }
    this->private_structure.str += ins.private_structure.str;
}

// Functor
template <typename T, size_t N>
void NS::Cls<T, N>::operator()() {
    for (const auto &element : this->private_structure.vec) {
        cout << element << endl;
    }
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
    NS::Cls<int, size> ins1;                                                                           // Default ctor
    NS::Cls<int, size> ins2(ins1);                                                                     // Copy ctor
    NS::Cls<int, size> ins3(33, array<int, 3>{1, 2, 3}, vector<int>{4, 5, 6}, string{"Hello World"});  // Param ctor
    NS::Cls<int, size> ins4(33, array{1, 2, 3}, vector{4, 5, 6}, "Hello World");                       // Param ctor

    // Getter Setter
    vector<int> vec1 = ins1.get_vector();
    vector<int> vec2 = ins3.get_vector();
    ins1.set_vector(vector<int>{99, 99, 99});
    vector<int> vec3 = ins1.get_vector();

    // Overloading
    NS::Cls<int, size> ins5 = ins1 + ins3;  // + operator
    ins1 = ins3;                            // = operator
    ins1 += ins3;                           // += operator

    // Method chaining
    ins1.set_string("Hello").get_string();

    // No reference
    vector<int> vec4 = ins1.get_vector();
    vector<int> vec5 = ins3.get_vector();

    // Function and functor
    ins3.set_vector(vector<int>{-97, -98, -99})();

    // Friend function and functor
    set_vector(ins3, vector<int>{-1, -2, -3})();

    // Static property
    NS::Cls<int, size>::num_static = 998;
    NS::Cls<int, size>::func_static();
    ins1.num_static = 997;
    ins1.func_static();

    // Reset with public function
    ins1.reset_vector();

    // Functor
    ins1();

    // Debugger point
    return;
}

//---------------------------------------------------------------------------------------------------------------
int main() {
    NS::Test();
    return 0;
}
