/*

 Description:
 Abstract Class

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

// ==========================================================================================================
// Notes
// ==========================================================================================================
/*
- Abstract class has at least one pure virtual function. It is used as a base class by inherited classes
- Inherited class from abstract class has to provide the implementation of pure virtual function
- Interface is an abstract class whose all functions are pure virtual
- Pure virtual function does not have implementation
- Abstract class can have pointers (polymorphishm)
- Abstract class cannot have instances
*/

// ==========================================================================================================
// Abstract Class
// ==========================================================================================================
class AbstractClass {
   private:
    vector<int> properties;

   public:
    // Default constructor
    AbstractClass() : properties(vector<int>{1, 2, 3}) {
    }
    // Copy constructor
    AbstractClass(const AbstractClass &ins) : properties(ins.properties) {
    }
    // Param constructor
    AbstractClass(const vector<int> &properties) : properties(properties) {
    }
    // Member Function
    const vector<int> getter() {
        return this->properties;
    }
    // Pure Virtual Function
    virtual void setter() = 0;
};

//------------------------------------------------------------------------------------------------------------
int main() {
    AbstractClass *ptr;
    //  AbstractClass ins; // NOT allowed
}