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

class Divider {
 public:
  static void line() { cout << "-----------------------------" << endl; }
  static void plus() { cout << "+++++++++++++++++++++++++++++" << endl; }
};

class Base {
 private:
  int base_private;

 protected:
  int base_protected;

 public:
  int base_public;
  Base() : base_private(1), base_protected(2), base_public(3) {}
  Base(const int &a, const int &b, const int &c): base_private(a), base_protected(b), base_public(c) {}
  void getter() {
    cout << this->base_private << endl;
    cout << this->base_protected << endl;
    cout << this->base_public << endl;
  }
};

class Sub : public Base {
 private:
  int sub_private;
  Base base = Base(77, 88, 99);  // Composition

 protected:
  int sub_protected;

 public:
  Base base_public = Base(44, 55, 66);
  int sub_public;
  Sub(): Base(11, 22, 33), sub_private(97), sub_protected(98), sub_public(99) {}
  void getter() {
    // ----------------------------------------------------
    // Base private properties using public function
    // ----------------------------------------------------
    Base::getter();
    Divider::line();

    // ----------------------------------------------------
    // Base private properties using composition
    // ----------------------------------------------------
    this->base.getter();
    cout << this->Sub::base_public.base_public << endl;
    Divider::line();

    // ----------------------------------------------------
    // Base protected/public properties
    // ----------------------------------------------------
    cout << this->base_protected << endl;
    cout << this->Base::base_public << endl;
    Divider::line();

    // ----------------------------------------------------
    // Sub private/protected/public properties
    // ----------------------------------------------------
    cout << this->sub_private << endl;
    cout << this->sub_protected << endl;
    cout << this->sub_public << endl;
  }
};

int main() {
  Sub ins;
  ins.getter();
  Divider::line();
  // ----------------------------------------------------
  // Base private properties using sub instance
  // ----------------------------------------------------
  ins.Base::getter();
}   