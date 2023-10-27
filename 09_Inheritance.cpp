#include "07_Class(Lib).cpp"

//------------------------------------------------------------------------------------------------------------
int main() {
    Series1 series1;
    Series3 series3;
    cout << "Inheritance" << endl;
    cout << "-----------------------" << endl;
    series1.get_company();
    series1.get_code();
    series1.get_fuel();
    series1.get_speed();
    cout << "-----------------------" << endl;
    series3.get_company();
    series3.get_code();
    series3.get_fuel();
    series3.get_speed();
}