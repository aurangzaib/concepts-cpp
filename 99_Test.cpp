#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

int main() {
    int var             = 1;
    int *ptr_var        = &var;
    int **double_ptr    = &ptr_var;

    cout << var             << endl;
    cout << *ptr_var        << endl;
    cout << **double_ptr    << endl;
    
    return 0;
}