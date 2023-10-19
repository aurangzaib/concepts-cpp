/*
 operators syntax:
    typename operator sign (:::){:::}


 copy assignment    --> skipped
 move assignment    --> skipped

 const instances:
    all properties will become read-only
    const instances can only access const methods
*/

#include <iostream>

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
  inline void printProperty() const { cout << "sibling class: " << d << endl; }
};

// class has by default private
class someClass {
 private:
  int a;
  double b;
  someStruct c;
  siblingClass d;

 public:
  static int static_property;
  const int public_property = 2;
  someClass();
  someClass(const someClass &);
  someClass(const int &, const double &, const someStruct &,
            const siblingClass &);
  ~someClass();
  void printProperty(void);  // can't be accessed by const instances
  bool compareFunc(const someClass &) const;
  someClass operator+(const someClass &);
  someClass &operator=(const someClass &);
  void operator+=(const someClass &);
};

// static property init outside of class
int someClass::static_property = 3;
// default ctor
someClass::someClass() {
  a = 0;
  b = 0.0;
  c = {.x = 1,
       .y = 1.0,
       .z = "hello world"};  // c = {x:1, y:1.0, z:"Hello World"}
  d = siblingClass(12.3);
}
// copy ctor
someClass::someClass(const someClass &inst)
    : a(inst.a), b(inst.b), c(inst.c), d(inst.d) {}
// ctor
someClass::someClass(const int &a, const double &b, const someStruct &c,
                     const siblingClass &d)
    : a(a), b(b), c(c), d(d) {}
// dtor
someClass::~someClass() {}
void someClass::printProperty() {
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
  someStruct x = {.x = 1, .y = 2.0, .z = "god damn it"};  // init w/o ctor
  siblingClass _x_(2.3);
  someClass anInstance(1, 1.0, x, _x_);
  someClass secondInstance(2, 3.0, x, _x_);
  someClass thirdInstance;
  // const instance
  const someClass fourthInstance;

  // copy constructor will be called
  someClass fifthInstance(anInstance);
  // an array
  int arr[1];

  // pointer to the object
  someClass *aPtr = &anInstance;
  // pointer to the array (no &)
  int *arrPtr = arr;

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
  cout << "public property: " << anInstance.public_property               << endl;
  cout << "static property from class   : " << someClass::static_property << endl;
  cout << "static property from instance: " << anInstance.static_property << endl;
  return 0;
}
