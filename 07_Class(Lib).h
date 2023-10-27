#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

// Base/Parent Abstract Class
class BMW {
   private:
    string company;
    string color;
    int year;

   protected:
    double price;
    string code;
    int speed;
    int fuel;

   public:
    BMW();
    void get_company();
    void get_fuel();
    void get_code();
    void get_speed();
    virtual void get_availability() = 0;
};

// Inherited/Child Class
class Series1 : public BMW {
   public:
    Series1();
    void get_availability();
};

// Inherited/Child Class
class Series3 : public BMW {
   public:
    Series3();
    void get_availability();
};