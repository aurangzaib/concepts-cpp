#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

class Cls {
   private:
    int a;
    int b;

   public:
    Cls() : a(33), b(55) {}
    Cls operator+(const Cls &param) {
        Cls ins;
        ins.a = this->a + param.a;
        ins.b = this->b + param.b;
        return ins;
    }
    void print() {
        cout << "a: " << this->a << endl;
        cout << "b: " << this->b << endl;
    }
};

int main() {
    Cls ins1;
    Cls ins2;
    Cls ins3 = ins1 + ins2;
    ins3.print();
}