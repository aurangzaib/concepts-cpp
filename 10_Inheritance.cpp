/*

 Description:
 Inheritance
 
 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include "09_Inheritance(Lib).cpp"

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/inheritance-in-c

//------------------------------------------------------------------------------------------------------------
int main() {
    SubClass1<double> sub_instance1;
    sub_instance1.print(sub_instance1.get_child_key());
    cout << sub_instance1.get_child() << endl;

    SubClass2<double> sub_instance2;
    sub_instance2.print(sub_instance2.get_child_key());
    cout << sub_instance2.get_child() << endl;
}