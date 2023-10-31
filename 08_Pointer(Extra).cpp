/*

 Description:
 Raw Pointer
 
 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>

using namespace std;

int main() {
    // ==========================================================================================================
    // Non const address. Non const value
    // ==========================================================================================================
    // Pointer can point to other structure
    // Pointer can change structure value
    int var = 123;
    int *ptr1 = &var;

    // ==========================================================================================================
    // Non const address. Const value
    // ==========================================================================================================

    // Pointer can point to other structure
    // Pointer cant change structure value
    const int *ptr2 = &var;

    // ==========================================================================================================
    // Const address. Non const value
    // ==========================================================================================================

    // Pointer cant point to other structure
    // Pointer can change structure value
    int *const ptr3 = &var;

    // ==========================================================================================================
    // Const address. Const value
    // ==========================================================================================================

    // Pointer cant point to other structure
    // Pointer cant change structure value
    const int *const ptr4 = &var;
}