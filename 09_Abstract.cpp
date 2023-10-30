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
// - Abstract class has at least one pure virtual function (it is used as a base class by other classes)
// - Inherited class from abstract class has to provide the implementation of pure virtual function
// - Interface is an abstract class whose all functions are pure virtual
// - Pure virtual function does not have implementation
// - Abstract class can have pointers (Polymorphishm)
// - Abstract class cannot have instances

// ==========================================================================================================
// Abstract Class
// ==========================================================================================================
class AbstractClass {
   private:
    vector<int> properties;

   public:
    AbstractClass() : properties(vector<int>{1, 2, 3}) {}                     // Default constructor
    AbstractClass(const AbstractClass &ins) : properties(ins.properties) {}   // Copy constructor
    AbstractClass(const vector<int> &properties) : properties(properties) {}  // Param constructor
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