#include "07_Class(Lib).cpp"

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/cpp-polymorphism

// ==========================================================================================================
// General
// ==========================================================================================================
/*
----------------------------------------------------
Compile Time Polymorphism
----------------------------------------------------
- Function overloading
- Operator overloading

----------------------------------------------------
Run Time Polymorphism
----------------------------------------------------
- Achieved using pointer and virtual function
- Also called Late Binding
- Function overriding

*/

void get_info(BMW *car) {
    car->get_company();
    car->get_code();
    car->get_fuel();
    car->get_speed();
}

int main() {
    cout << "Polymorphism" << endl;
    cout << "-----------------------" << endl;
    BMW *car;
    Series1 series1;
    Series3 series3;

    car = &series1;
    get_info(car);
    cout << "-----------------------" << endl;
    car = &series3;
    get_info(car);
}