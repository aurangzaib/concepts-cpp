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
    Students* student;          // Pointer of Base class
    Student1<double> student1;  // Instance of Child class
    Student2<double> student2;  // Instance of Child class

    student = &student1;                       // Polymorphism: student pointer to student1
    student1.print(student->get_child_key());  // Note: print is accessed through student1
    cout << student->get_child() << endl;

    student = &student2;                       // Polymorphism: student pointer to student2
    student2.print(student->get_child_key());  // Note: print is accessed through student2
    cout << student->get_child() << endl;
}