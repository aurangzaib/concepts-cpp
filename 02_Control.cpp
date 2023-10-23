#include <iostream>
#include <array>
#include <vector>
using namespace std;

// ==========================================================================================================
// Operators
// ==========================================================================================================

// >>
// <<
// ==
// <=
// >=
// !=

//----------------------------------------------------------------
int main() {
    int max_count = 10;
    int arr_count[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // ==========================================================================================================
    // Control
    // ==========================================================================================================

    // if operator
    if (max_count < 10) {
    } else if (max_count == 10) {
    } else {
    }

    // binary operator
    (max_count < 10) && (arr_count[0] = 1);

    // ternary operator
    (max_count < 10) ? (arr_count[0] = 1) : (arr_count[1] = 2);

    // switch operator
    switch (max_count) {
        case 0:
            cout << 0;
            break;
        case 1:
        case 2:
            cout << 1;
            break;
        default:
            cout << "default";
            break;
    }

    // ==========================================================================================================
    // Iterators
    // ==========================================================================================================

    // For loop
    for (auto counter = 0; counter < max_count; counter += 1) {
        cout << counter;
    }
    
    // For range
    for (auto iterator : arr_count) {
        cout << "Iterator value: " << iterator;
    }

    // For range (const): Preferred for read
    for (const auto &iterator : arr_count) {
        cout << "Iterator value: " << iterator;
    }

    // For range (reference): Preferred for write
    for (auto &iterator : arr_count) {
        iterator = 1;
    }

    // while loop
    auto counter = 0;
    while (counter < max_count) {
        counter += 1;
    }

    // continue:    Skip iteration
    // break:       Exit the loop

    return 0;
}