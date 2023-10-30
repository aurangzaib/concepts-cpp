// online cpp compile --> http://cpp.sh/

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define someConstant 40

// to avoid global name collision, we use namespace.
namespace a {
    int some;
    int other;
}

namespace b {
    int some;
    int other;
}

int global_var; // static storage, init by default to 0

int main() {
    // constructor initialization
    int x(0);
    // uniform initialization
    int x{0};
    // c initialization
    int x = 0;
    // preprocessor
    // bitwise operators
    // &(AND) |(OR) ^(XOR) ~(NOT) >>(SHR) <<(SHR)
    // sizeof (variable) and vector.size()
    int age;
    string a_string;
    cin >> age;
    cout << age;
    // to get the a string containing spaces etc
    getline(cin, a_string);
    // sstream --> string stream, treat string as stream
    // break; --> to get out of loop
    // continue; --> to skip to next iteration of loop
    int x = 2;
    switch (x) {
        case 1:
            cout << "1";
            break; // otherwise all other cases will also execute
        default:
            cout << "default";
    }
}
