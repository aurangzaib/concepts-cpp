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

using namespace std;

// ==========================================================================================================
// General
// ==========================================================================================================
/*
- Access levels      Public  Protected   Private
- Same class         yes     yes         yes
- Inherit class      yes     yes
- Non members        yes

- Inheritance:
    Private:   Public becomes private
    Protected: Public becomes protected
    Public:    Public becomes public

- In most use cases, derived class inherits base as public

- Public inheritance inherits all base parts except:
    ctor and dtor
    = operator
    friends
    private

*/

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