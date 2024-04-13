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
    Base() : a(1) {
    }
    Base(int a) : a(a) {
    }
    void print() {
        cout << "base method" << endl;
        cout << this->a << endl;
    }
};

class Sub : public Base {
   private:
    int a = 0;

   public:
    Sub(int a) : a(a) {
    }
    void print() {
        cout << "sub method" << endl;
        cout << this->a << endl;
    }
};

int main() {
    Base *ptr;
    Sub ins(11);

    ins.
}