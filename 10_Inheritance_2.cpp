/*

 Description:
 Inheritance - 2
 
 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 30.11.13  01.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
using namespace std;

class Base {
private:
  int prop1;
  int prop2;

protected:
  int prop3;

public:
  // ----------------------------------------------------
  // Base Default Constructor
  // ----------------------------------------------------
  Base() : prop1(1), prop2(2), prop3(3) {}

  // ----------------------------------------------------
  // Base Parameterized Constructor
  // ----------------------------------------------------
  Base(const int &a, const int &b, const int &c) {
    this->prop1 = a;
    this->prop2 = b;
    this->prop3 = c;
  }

  // ----------------------------------------------------
  // Base Public Methods
  // ----------------------------------------------------
  void getter() {
    cout << "Base prop1: " << this->prop1 << endl;
    cout << "Base prop2: " << this->prop2 << endl;
    cout << "Base prop3: " << this->prop3 << endl;
  }
};

class Sub : public Base {
private:
  int prop1;
  int prop2;
  Base base;

protected:
  int prop3;

public:
  // ----------------------------------------------------
  // Sub Default Constructor
  // ----------------------------------------------------
  Sub() : Base(11, 12, 13), base(), prop1(14), prop2(15), prop3(16) {}

  // ----------------------------------------------------
  // Sub Parameterized Constructor
  // ----------------------------------------------------
  Sub(const int &a, const int &b, const int &c, const int &d, const int &e,
      const int &f, const Base &g)
      : Base(a, b, c), base(g) {
    this->prop1 = d;
    this->prop2 = e;
    this->prop3 = f;
  }

  // ----------------------------------------------------
  // Sub Public Methods
  // ----------------------------------------------------
  void getter() {
    cout << "Composition Properties: " << endl;
    this->base.getter();
    cout << "Sub properties: " << endl;
    cout << "Sub prop1: " << this->prop1 << endl;
    cout << "Sub prop2: " << this->prop2 << endl;
    cout << "Sub prop3: " << this->prop3 << endl;
  }
  void getters() {
    cout << "Base properties: " << endl;
    Base::getter();
    this->getter();
  }
};

int main() {
  // ----------------------------------------------------
  // Instance of base class
  // ----------------------------------------------------
  Base instance_base(11, 12, 13);

  // ----------------------------------------------------
  // Instance of Sub class with inherited properties from Base class
  // ----------------------------------------------------
  Sub instance(21, 22, 23, 31, 32, 33, instance_base);

  // ----------------------------------------------------
  // Call Sub method using Sub instance
  // ----------------------------------------------------
  instance.getters();

  // ----------------------------------------------------
  // Call Base method using Sub instance
  // ----------------------------------------------------
  cout << "Base properties: " << endl;
  instance.Base::getter();
}