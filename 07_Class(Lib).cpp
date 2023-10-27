#include "07_Class(Lib).h"

using namespace std;

// ==========================================================================================================
// Link
// ==========================================================================================================
// - https://www.geeksforgeeks.org/inheritance-in-c

// ==========================================================================================================
// Base Class Definition
// ==========================================================================================================

BMW::BMW() {
    this->company = "BMW";
    this->color = "Black";
    this->year = 2023;
}
void BMW::get_company() {
    cout << "Company: " << this->company << endl;
}
void BMW::get_fuel() {
    cout << "Fuel: " << this->fuel << "L" << endl;
}
void BMW::get_code() {
    cout << "Code: " << this->code << endl;
}
void BMW::get_speed() {
    cout << "Speed: " << this->speed << endl;
}

// ==========================================================================================================
// Child Class Definition
// ==========================================================================================================

Series1::Series1() {
    this->code = "1er";
    this->price = 30.500;
    this->fuel = 40;
    this->speed = 150;
}
void Series1::get_availability() {
    cout << false << endl;
}

// ==========================================================================================================
// Child Class Definition
// ==========================================================================================================

Series3::Series3() {
    this->code = "3er";
    this->price = 40.500;
    this->fuel = 60;
    this->speed = 250;
}
void Series3::get_availability() {
    cout << true << endl;
}
