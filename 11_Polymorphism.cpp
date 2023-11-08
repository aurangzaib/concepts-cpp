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

#include "09_Inheritance(Lib).cpp"

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/cpp-polymorphism

// ==========================================================================================================
// General
// ==========================================================================================================
/*
----------------------------------------------------
Compile Time Polymorphism
----------------------------------------------------
- Function overloading
- Operator overloading

----------------------------------------------------
Run Time Polymorphism
----------------------------------------------------
- Achieved using pointer and virtual function
- Also called Late Binding
- Function overriding

----------------------------------------------------
Note
----------------------------------------------------
- Base pointer can point to any of the child class instance
- Base pointer can point to child class methods only which are defined in base class also.
- Thats why we create virtual members in base class and define actual implementations in derived classes.

*/

int main() {
    BaseClass* base_instance;          // Pointer of Base class
    SubClass1<double> sub_instance1;   // Instance of Child class
    SubClass2<double> sub_instance2;   // Instance of Child class

    base_instance = &sub_instance1;                       // Polymorphism: base_instance pointer to sub_instance1
    sub_instance1.print(base_instance->get_child_key());  // Note: print is accessed through sub_instance1
    cout << base_instance->get_child() << endl;

    base_instance = &sub_instance2;                       // Polymorphism: base_instance pointer to sub_instance2
    sub_instance2.print(base_instance->get_child_key());  // Note: print is accessed through sub_instance2
    cout << base_instance->get_child() << endl;
}
