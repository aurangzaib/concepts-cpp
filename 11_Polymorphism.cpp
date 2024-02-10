/*

 Description:
 Polymorphism

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

// ==========================================================================================================
// General
// ==========================================================================================================
/*

----------------------------------------------------
Polymorphism
----------------------------------------------------
- Base method called with sub property
- Also called late binding

----------------------------------------------------
Virtual Function
----------------------------------------------------
- To use sub method with sub property using base pointer
- Define virtual function in base class
- Base class becomes abstract class

----------------------------------------------------
Note:
----------------------------------------------------
- Polymorphism = Run time polymorphism
- Overloading  = Compile time polymorphism

*/

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/cpp-polymorphism

#include <iostream>
using namespace std;

class Base {
   private:
    int prop = 0;

   public:
    Base(const int a) : prop(a) {}

    void getter() {
        cout << "Base function: ";
        cout << prop << endl;
    }

    virtual void print() = 0;
};

class Sub : public Base {
   private:
    int prop;

   public:
    Sub(const int a, const int b) : Base(a), prop(b) {}
    void getter() {
        cout << "Sub function: ";
        cout << prop << endl;
    }

    void print() {
        getter();
    }
};

int main() {
    Base *base_ptr;
    Sub sub(1,   // value for inherited property
            2);  // value for own property

    // ----------------------------------------------------
    // With polymorphism
    // ----------------------------------------------------
    base_ptr = &sub;
    base_ptr->getter();  // Base method with Sub property
    base_ptr->print();   // Sub method with Sub property

    // ----------------------------------------------------
    // Without polymorphism (same results)
    // ----------------------------------------------------
    sub.Base::getter();  // Base method with Sub property
    sub.getter();        // Sub method with Sub property
}
