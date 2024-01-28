/*

 Description:
 Inheritance Definition

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include "10_Inheritance(ExtraLib).hpp"

using namespace std;

// ==========================================================================================================
// Base Class Definition
// ==========================================================================================================

template <typename T>
void Printer<T>::print(const T &value) {
    cout << value << endl;
}

BaseClass::BaseClass() : school("Hochschule Rosenheim"), children(200) {}
void BaseClass::set_child() {
    this->children.push_back(this->child);
}
int BaseClass::get_standard() {
    return this->standard;
}
double BaseClass::get_grade() {
    return this->grade;
}
int BaseClass::get_child() {
    return this->child;
}

// ==========================================================================================================
// Sub Class Definition
// ==========================================================================================================

template <typename T>
SubClass1<T>::SubClass1() {
    this->child = 120;
    this->standard = 5;
    this->grade = 1.0;
};
template <typename T>
double SubClass1<T>::get_child_key() {
    return this->child * 1.111;
};

// ==========================================================================================================
// Sub Class Definition
// ==========================================================================================================

template <typename T>
SubClass2<T>::SubClass2() {
    this->child = 10;
    this->standard = 3;
    this->grade = 4.0;
};
template <typename T>
double SubClass2<T>::get_child_key() {
    return this->child * 1.222;
};