#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>

using namespace std;

// ================================================================
// Link
// ================================================================

// ================================================================
// Notes
// ================================================================
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

namespace Classes {

// Structure
template <typename T, size_t N>
struct Structure {
    vector<T> vec = {};
    array<T, N> arr = {};
    string str = "hello world";
};

// Class
template <typename T, size_t N>
class Class {
   private:
    int a;
    array<T, N> arr;
    vector<T> vec;
    Structure<int, 5> private_structure;

   protected:
    Structure<double, 3> protected_structure;

   public:
    Class() : a(0) { arr.fill(1); };
    Class(Structure<T, N>);
    void set_vector() {
        for (auto loop = 0; loop < this->private_structure.vec.size();
             loop += 1) {
            this->private_structure.vec.at(loop) = loop * 10;
        }
    }
    vector<T> get_vector() { return this->private_structure.vec; }
    string get_string();
};

}  // namespace Classes

int main() {
    Classes::Class<int, 5> ins();
    ins.set_vector();
}