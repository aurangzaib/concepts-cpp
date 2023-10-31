#include "07_Class(Lib).hpp"

using namespace std;

// ==========================================================================================================
// Base Class Definition
// ==========================================================================================================

template <typename T>
void Printer<T>::print(const T &value) {
    cout << value << endl;
}

Students::Students() : school("Hochschule Rosenheim"), children(200) {}
void Students::set_child() {
    this->children.push_back(this->child);
}
int Students::get_standard() {
    return this->standard;
}
double Students::get_grade() {
    return this->grade;
}
int Students::get_child() {
    return this->child;
}

// ==========================================================================================================
// Child Class Definition
// ==========================================================================================================

template <typename T>
Student1<T>::Student1() {
    this->child = 120;
    this->standard = 5;
    this->grade = 1.0;
};
template <typename T>
double Student1<T>::get_child_key() {
    return this->child * 1.111;
};

// ==========================================================================================================
// Child Class Definition
// ==========================================================================================================

template <typename T>
Student2<T>::Student2() {
    this->child = 10;
    this->standard = 3;
    this->grade = 4.0;
};
template <typename T>
double Student2<T>::get_child_key() {
    return this->child * 1.222;
};