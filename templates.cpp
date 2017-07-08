// http://www.cplusplus.com/doc/tutorial/templates/

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

template<typename T>
T Max(T const &a, T const &b) {
    return a > b ? a : b;
}

int Max(int a, int b) {
    return a < b ? b : a;
}

template<class T>
class aClass {

private :
    T _member_;
public:
    aClass(T a) : _member_(a) {}

    ~aClass() {
        cout << "dtor called" << endl;
    }

    void print();

    void increment(T value) {
        _member_ = _member_ + value;
    }

    void decrement(T value) {
        _member_ = _member_ - value;
    }

    T operator+(T value) {
        _member_ += value;
        return _member_;
    }

    T operator-(T value);
};

template<class T>
void aClass<T>::print() {
    cout << "member value: " << _member_ << endl;
}

template<class T>
T aClass<T>::operator-(T value) {
    _member_ -= value;
    return _member_;
}

void a_func(int a[]) {
    cout << a[1];
}

class a_class {
private:
    int a;
public:
    a_class(int a) : a(a) {}

    ~a_class()() {}

    void a_func();
};

int main() {
    aClass<float> anInstance(23);
    anInstance.increment(1.4);
    anInstance.decrement(1.4);
    anInstance.print();
    cout << "+ operator: " << anInstance + 1 << endl;
    cout << "- operator: " << anInstance - 1 << endl;
    cout << (uint64_t) (int64_t) -1 << endl;
}

// Template specialization
// skipped