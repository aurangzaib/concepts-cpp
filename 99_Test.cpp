#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;


int main() {

    // --------------------- Initialization

    int var                 = 99;
    int *ptr_var            = &var;

    array<int, 3> arr       = {1,2,3};
    array<int, 3> *ptr_arr  = &arr;

    int arrc[]              = {1,2,3};
    int *ptr_arrc           = arrc;

    // --------------------- Value
    
    cout << var             << endl;
    cout << *ptr_var        << endl;

    cout << arr.at(1)       << endl;
    cout << ptr_arr->at(1)  << endl;

    cout << arrc[1]         << endl;
    cout << *(ptr_arrc + 1) << endl;

    // --------------------- Address

    cout << &var            << endl;
    cout << ptr_var         << endl;

    cout << arr.begin()     << endl;
    cout << &arr            << endl;
    cout << ptr_arr->begin()<< endl;
    cout << ptr_arr         << endl;

    cout << arrc            << endl;
    cout << ptr_arrc        << endl;
    cout << &arrc[0]        << endl;

    // ------------------- Pointer Address

    cout << &ptr_var        << endl;
    cout << &ptr_arr        << endl;
    cout << &ptr_arrc       << endl;
    
    return 0;
}