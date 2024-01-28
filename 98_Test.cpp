#include <functional>
#include <iostream>
#include <math.h>
#include <vector>
#include <array>

using namespace std;

class Base {
   private:
    int a = 0;

   public:
    void getter() {
        cout << a << endl;
    }
    virtual void print() = 0;
};
class Sub : public Base {
   private:
    int a = 1;

   public:
    void getter() {
        cout << a << endl;
    }
    void print() {
        getter();
    }
};

int main() {
    Base *ptr_base;
    Sub sub;

    // With polymorphism
    ptr_base = &sub;
    ptr_base->getter();
    ptr_base->print();

    // Without polymorphsm
    sub.Base::getter();
    sub.getter();
}