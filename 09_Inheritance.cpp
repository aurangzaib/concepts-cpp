/*

 Description:
 Inheritance

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.11.13  01.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
using namespace std;

// ==========================================================================================================
// General
// ==========================================================================================================
/*
- Sub class can access protected and public properties of base class

- Inheritance:
    private:   public becomes private
    protected: public becomes protected
    public:    public becomes public

- If sub class and base class have same property/method name:
    - this->prop // property of sub class
    - Base::prop // property of base class

- Composition is not allowed from abstract class

- In most use cases, sub class inherits base as public

- Public inheritance inherits all base parts except:
    ctor and dtor
    = operator
    friends
    private

- Note: C++ uses classname unlike super() in Python
*/

class Base {
   private:
    int prop1;

   protected:
    int prop2;

   public:
    // ----------------------------------------------------
    // Base Default Constructor
    // ----------------------------------------------------
    Base() : prop1(1), prop2(3) {
    }

    // ----------------------------------------------------
    // Base Parameterized Constructor
    // ----------------------------------------------------
    Base(const int &a, const int &b) {
        this->prop1 = a;
        this->prop2 = b;
    }

    // ----------------------------------------------------
    // Base Public Methods
    // ----------------------------------------------------
    void getter() {
        cout << "Base prop1: " << this->prop1 << endl;
        cout << "Base prop2: " << this->prop2 << endl;
    }
};

class Sub : public Base {  // Inheritance
   private:
    int prop1;
    Base base;  // Composition

   protected:
    int prop2;

   public:
    // ----------------------------------------------------
    // Sub Default Constructor
    // ----------------------------------------------------
    Sub() : Base(11, 12), base(), prop1(14), prop2(15) {
    }

    // ----------------------------------------------------
    // Sub Parameterized Constructor
    // ----------------------------------------------------
    Sub(const int &a, const int &b, const int &c, const int &d, const Base &e)
        : Base(a, b),  // Inhertiance
          base(e),     // Composition (Dependency Injection)
          prop1(c),    // Own property
          prop2(d) {
    }

    // ----------------------------------------------------
    // Sub Public Methods
    // ----------------------------------------------------
    void getter() {
        cout << "Composition properties: " << endl;
        this->base.getter();

        cout << "Inheritance properties: " << endl;
        Base::getter();

        cout << "Sub properties: " << endl;
        cout << "Sub prop1: " << this->prop1 << endl;
        cout << "Sub prop2: " << this->prop2 << endl;

        cout << "Similar name properties: " << endl;
        cout << "Base protected: " << Base::prop2 << endl;
        cout << "Sub protected: " << this->prop2 << endl;
    }
};

int main() {
    // ----------------------------------------------------
    // Instance of base class
    // ----------------------------------------------------
    Base instance_base(11, 12);

    // ----------------------------------------------------
    // Instance of Sub class (inheritance + dependency injection)
    // ----------------------------------------------------
    Sub instance(21, 22, 31, 32, instance_base);

    // ----------------------------------------------------
    // Sub method
    // ----------------------------------------------------
    instance.getter();

    // ----------------------------------------------------
    // Base method
    // ----------------------------------------------------
    cout << "Base properties using sub instance: " << endl;
    instance.Base::getter();
}
