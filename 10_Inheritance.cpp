#include "07_Class(Lib).cpp"

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/inheritance-in-c

//------------------------------------------------------------------------------------------------------------
int main() {
    Student1<double> student1;
    student1.print(student1.get_child_key());
    cout << student1.get_child() << endl;

    Student2<double> student2;
    student2.print(student2.get_child_key());
    cout << student2.get_child() << endl;
}