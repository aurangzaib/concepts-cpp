/*

 Description:
 Inheritance Declaration

 Modifications:
 ---------------------------------------------------------------------------------------
 Date      Vers.  Comment                                                     Name
 ---------------------------------------------------------------------------------------
 01.10.11  01.00  Created												      Siddiqui
 30.10.23  02.00  Updated                                                     Siddiqui
 ---------------------------------------------------------------------------------------

*/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================================================================================
// Base Class Declaration
// ==========================================================================================================

template <typename T>
class Printer {
   public:
    inline void print(const T &);
};

class BaseClass {
   private:
    string school;
    vector<int> children;

   protected:
    int standard;
    double grade;
    int child;

   public:
    BaseClass();
    void set_child();
    int get_standard();
    double get_grade();
    int get_child();
    virtual double get_child_key() = 0;
};

// ==========================================================================================================
// Sub Class Declaration
// ==========================================================================================================
template <typename T>
class SubClass1 : public BaseClass, public Printer<T> {
   public:
    SubClass1();
    double get_child_key();
};

// ==========================================================================================================
// Sub Class Declaration
// ==========================================================================================================
template <typename T>
class SubClass2 : public BaseClass, public Printer<T> {
   public:
    SubClass2();
    double get_child_key();
};