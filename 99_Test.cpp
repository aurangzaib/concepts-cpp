#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

int main() {

    // Variable and its pointer
    int var         = 0;
    int *ptr_var    = &var;

    // Class and its pointer
    array<int, 3> arr         = {1,2,3};
    array<int, 3> *ptr_arr    = &arr;

    // Variable value
    cout << var                 << endl;
    cout << *ptr_var            << endl;

    // Class property value
    cout << arr.at(0)           << endl;
    cout << ptr_arr->at(0)      << endl;
    cout << (*ptr_arr).at(0)    << endl;

    // Variable address
    cout << &var                << endl;
    cout << ptr_var             << endl;

    // Class address
    cout << &arr                << endl;
    cout << arr.begin()         << endl; 
    cout << ptr_arr->begin()    << endl;
    cout << ptr_arr             << endl;

    // Pointer address
    cout << &ptr_var            << endl;
    cout << &ptr_arr            << endl;

    return 0;
}