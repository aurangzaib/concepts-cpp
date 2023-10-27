#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

namespace NS {
struct Structure {
    int a;
};

template <typename T>
class Cls {
   private:
    T num = 99;

   public:
    T my_func();
    inline friend T my_func(const Cls &ins) {
        cout << ins.num << endl;
        return ins.num;
    }
};
}  // namespace NS

template <typename T>
T NS::Cls<T>::my_func() {
    cout << this->num << endl;
    return this->num;
}

int main() {
    NS::Cls<int> ins;
    ins.my_func();
    my_func(ins);
}