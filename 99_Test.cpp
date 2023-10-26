#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

namespace MySpace {
template <typename A, size_t B>
class MyCls {
   private:
    array<A, B> arr;

   public:
    MyCls();
    MyCls(const MyCls &);
    MyCls(const array<A, B> &);
    void set(const array<A, B> &);
    array<A, B> get();
    void print();
};
}  // namespace MySpace

template <typename A, size_t B>
MySpace::MyCls<A, B>::MyCls() {
    for (size_t counter = 0; counter < arr.size(); counter += 1) {
        arr.at(counter) = counter;
    }
}

template <typename A, size_t B>
MySpace::MyCls<A, B>::MyCls(const MyCls &ins) {
    arr = ins.arr;
}

template <typename A, size_t B>
MySpace::MyCls<A, B>::MyCls(const array<A, B> &arr) {
    this->arr = arr;
}

template <typename A, size_t B>
void MySpace::MyCls<A, B>::set(const array<A, B> &arr) {
    this->arr = arr;
}

template <typename A, size_t B>
array<A, B> MySpace::MyCls<A, B>::get() {
    return arr;
}

template <typename A, size_t B>
void MySpace::MyCls<A, B>::print() {
    for (const A &itr : arr) {
        cout << itr << endl;
    }
}

int main() {
    MySpace::MyCls<int, 3> cls;
    cls.print();
    cls.set(array<int, 3>{99, 98, 97});
    cls.print();
}