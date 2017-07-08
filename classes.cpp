#include <iostream>

// members      --> property and methods
// private      --> members are accessible by same and friend class
// protected    --> members are accessible by same, derived and friend class
// public       --> members are accessible from anywhere where instance is visible
// ::           --> scope resolution operator

// struct has by default public
// constructor(ctor) is used to initialize properties of the class
// ctor has no return type
// in class, property can be accessed by this->prop or directly prop

// operators:
// syntax:
// typename operator sign (:::){:::}

// operators that can be overloaded:
//+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
//<<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
//~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new

// static members --> class members, can be accessed directly from class w/o creating instance
// difference b/w static and public propery:
//      both can be accessed outside of class
//      public requires instance to be called
//      static can be called from class directly
// syntax
//      instance.publicProperty;
//      class::staticProperty;

using namespace std;
struct someStruct {
    int x;
    double y;
    string z;
};

class siblingClass {
private:
    double d;
public:
    siblingClass() : d(10.0) {}

    siblingClass(double d) : d(d) {}

    inline void printProperty() const {
        cout << "sibling class: " << d << endl;
    }
};

// class has by default private
class someClass {
private:
    int a;
    double b;
    someStruct c;
    siblingClass d;

public:

    static int static_property = 3;
    int public_property = 2;

    someClass();

    someClass(int, double, someStruct, const siblingClass &);

    ~someClass();

    void printProperty(void) const;

    bool compareFunc(const someClass &) const;

    someClass operator+(const someClass &);

    someClass &operator=(const someClass &);

    void operator+=(const someClass &);
};

someClass::someClass() {
    a = 0;
    b = 0.0;
    c = {.x= 1, .y=1.0, .z="hello world"};
    /* same as: c = {x:1, y:1.0, z:"Hello World"} */
    d = siblingClass(12.3);
}

someClass::someClass(int a, double b, someStruct c, const siblingClass &d) : a(a), b(b), c(c), d(d) {}

someClass::~someClass() {}

void someClass::printProperty() const {
    cout << c.x << " " << c.y << " " << c.z << endl;
    d.printProperty();
}

bool someClass::compareFunc(const someClass &compareInst) const {
    string result = this->a > compareInst.a ? "greater" : "lesser";
    cout << this->a << " is " << result << " than " << compareInst.a << endl;
    return this->a > compareInst.a;
}

someClass someClass::operator+(const someClass &anInstance) {
    someClass newInst;
    newInst.a = a + anInstance.a;
    newInst.b = b + anInstance.b;
    newInst.c.x = c.x + anInstance.c.x;
    newInst.c.y = c.x + anInstance.c.y;
    return newInst;
};

void someClass::operator+=(const someClass &anInstance) {
    a += anInstance.a;
    b += anInstance.b;
    c.x += anInstance.c.x;
    c.y += anInstance.c.y;
};

someClass &someClass::operator=(const someClass &anInstance) {
    a = anInstance.a;
    b = anInstance.b;
    c.x = anInstance.c.x;
    c.y = anInstance.c.y;
    return *this;
}

int main() {
    someStruct x = {.x=1, .y=2.0, .z="god damn it"}; // init w/o ctor
    siblingClass _x_(2.3);

    someClass anInstance(1, 1.0, x, _x_); // {} can also be used instd of ()
    someClass secondInstance(2, 3.0, x, _x_);
    someClass thirdInstance;
    someClass *aPtr = &anInstance;

    // access by instance
    anInstance.printProperty();
    // access by pointer
    aPtr->printProperty();
    // access by dereferenced pointer
    (*aPtr).printProperty();
    aPtr->compareFunc(secondInstance);
    // + overloaded operator
    thirdInstance = anInstance + secondInstance;
    thirdInstance.printProperty();
    // += overloaded operator
    anInstance += secondInstance;
    anInstance.printProperty();
    // = overloaded operator
    anInstance = secondInstance;
    anInstance.printProperty();
    cout << "public property: " << anInstance.public_property;
    cout << "static property: " << someClass::static_property;
    return 0;
}