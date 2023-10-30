#include <iostream>

// ==========================================================================================================
// General
// ==========================================================================================================
/*
 - access levels      public  protected   private
 - same class         yes     yes         yes
 - derived class      yes     yes
 - not members        yes

 - Public Inheritance:    public remains public in derived
 - Protected Inheritance: public remains protected in derived
 - Private Inheritance:   public remains private in derived

 - In most use cases, derived class inherits base as public

 - Public inheritance inherits all base parts except:
        ctor and dtor
        = operator
        friends
        private

*/
using namespace std;

// ==========================================================================================================
// Base Class Declaration
// ==========================================================================================================

template <typename T>
class Printer {
   public:
    inline void print(const T &);
};

class Students {
   private:
    string school;
    vector<int> children;

   protected:
    int standard;
    double grade;
    int child;

   public:
    Students();
    void set_child();
    int get_standard();
    double get_grade();
    int get_child();
    virtual double get_child_key() = 0;
};

// ==========================================================================================================
// Child Class Declaration
// ==========================================================================================================
template <typename T>
class Student1 : public Students, public Printer<T> {
   public:
    Student1();
    double get_child_key();
};

// ==========================================================================================================
// Child Class Declaration
// ==========================================================================================================
template <typename T>
class Student2 : public Students, public Printer<T> {
   public:
    Student2();
    double get_child_key();
};