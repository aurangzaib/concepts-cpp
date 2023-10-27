#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
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
- Accessible outside class using methods (NOT directly though instance)
- Default

----------------------------------------------------
Protected member
----------------------------------------------------
- Accessible by class, inherited class and friend class
- Accessible outside class using methods (NOT directly though instance)

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
Friend members
----------------------------------------------------
- It has access to private/protected/public without inheriting class
- It is not a member function of a class
- It has no access to "this" operator
- It does not need Class:: operator

----------------------------------------------------
Scope resolution operator (::)
----------------------------------------------------
- To access class methods
- To access static properties

----------------------------------------------------
this->
----------------------------------------------------
- To access class properties
- To chain methods (return *this)

----------------------------------------------------
Functor
----------------------------------------------------
- A Class whose () operator is overloaded
- Instance can be called as a function
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
- When copy constructor is not defined
    - Compiler will create reference instead of copying the instance
    - Any changes to first instance will reflect in copied instance
- That is why copy constructor should be defined

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
};  // End of structure

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
    void set_vector(const vector<T> &);                                        // Setter
    Cls &set_string(const string &);                                           // Setter (with method chaining)
    const vector<T> get_vector();                                              // Getter
    const string get_string();                                                 // Getter
    void reset_vector();                                                       // Reset
    Cls operator+(const Cls &);                                                // Overloading
    void operator=(const Cls &);                                               // Overloading
    void operator+=(const Cls &);                                              // Overloading
    static void func_static();                                                 // Static Method
    friend void reset_vector(Cls &ins) {                                       // Friend Method (definition)
        ins.private_structure.vec.clear();
    }
    // !! Note: When using friend with template class..
    // ..It is easier to define function inside class !!
    // Link: https://isocpp.org/wiki/faq/templates#template-friends
};

// ==========================================================================================================
// Functor Declaration
// ==========================================================================================================

class Functors {
   private:
    int num = 33;

   public:
    int operator()(const int &);  // Overloading () operator
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
void NS::Cls<T, N>::set_vector(const vector<T> &vec) {
    // remove old elements
    this->private_structure.vec.clear();
    // insert new elements
    for (const T &itr : vec) {
        this->private_structure.vec.push_back(itr);
    }
}
template <typename T, size_t N>
NS::Cls<T, N> &NS::Cls<T, N>::set_string(const string &str) {
    this->private_structure.str = str;
    // Method chaining
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

// Static method
template <typename T, size_t N>
void NS::Cls<T, N>::func_static() {
    cout << endl << Cls::num_static << endl;
}

// ==========================================================================================================
// Functor Definition
// ==========================================================================================================

int NS::Functors::operator()(const int &param) {
    return this->num + param;
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

    // Method chaining
    ins1.set_string("Hello").get_string();

    // Static property
    NS::Cls<int, size>::num_static = 998;
    NS::Cls<int, size>::func_static();
    ins1.num_static = 997;
    ins1.func_static();

    // Reset with public function
    ins1.reset_vector();

    // Reset with friend function
    // No namespace is used
    reset_vector(ins1);

    // Functor
    NS::Functors functor;
    cout << functor(1);

    // Debugger point
    return;
}

//---------------------------------------------------------------------------------------------------------------
int main() {
    NS::Test();
    return 0;
}
