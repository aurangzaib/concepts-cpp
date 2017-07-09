// http://www.cplusplus.com/doc/tutorial/templates/
// typename and class in template are same. interchangeable.
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;
template<typename T>
T Max(T const &a, T const &b) const {
    return a > b ? a : b;
}
// function template
// when logic is same for different types, we can use template
template<typename T, typename U>
// 'class' can be used instead of 'typename'
void some_func(T a, U b, int c) {
    T d = a * b * c;
}

template<class T>
class aClass {
private :
    T _member_;
public:
    aClass(T a) : _member_(a) {}
    ~aClass() { cout << "dtor called" << endl; }
    void print();
    void increment(T value) { _member_ += value; }
    void decrement(T value) { _member_ -= value; }
    T operator+=(T value) {
        _member_ += value;
        return _member_;
    }
    T operator-=(T value);
};

template<class T>
void aClass<T>::print() {
    cout << "member value: " << _member_ << endl;
}
template<class T>
T aClass<T>::operator-=(T value) {
    _member_ -= value;
    return _member_;
}
void a_func(int a[]) {
    cout << a[1];
}
int main() {
    // usage of function template
    some_func<int, int, 2>(1, 2);
    some_func<int, float, 2>(1, 2.0);
    // type is not necessary when calling function
    some_func(1, 2.0);
    Max<int>(1, 2);
    aClass<float> anInstance(23);
    anInstance.increment(1.4);
    anInstance.decrement(1.4);
    anInstance.print();
    cout << "+ operator: " << anInstance += 1 << endl;
    cout << "- operator: " << anInstance -= 1 << endl;
}

// Template specialization
// skipped