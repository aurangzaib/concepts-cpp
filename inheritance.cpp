/*
 access levels      public  protected   private
 same class         yes     yes         yes
 derived class      yes     yes
 not members        yes

 class derived_class: public base_class     --> public remains public in derived
 class derived_class: protected base_class  --> public remains protected in derived
 class derived_class: private base_class    --> public remains private in derived

 in most use cases, derived class inherits base as public

 public inheritance inherits all base parts except:
        ctor and dtor
        = operator
        friends
        private

  derived class uses base class ctor to initialize base class properties

 int A::b(int c) { }    --> method b of class A with param c
 a->b                   --> a is a pointer to an instance, used to access method b
 class A: public B {};  --> A inherits B publicly

  polymorphism:
    ptr to derived class is type-compatible with ptr to base class
    base class ptr can point to any of the derived class instance
    polymorphic class --> a class that declares or inherits virtual members

 virtual functions:
    if a ptr is of base class, it can point to methods of derived class only which are defined in base class also.
    that's why we create virtual members in base class and define actual implementations in derived classes.

 pure virtual functions:
    if base class is abstract, then virtual functions can be defined in base class w/o implementation

 abstract base class:
    a base class which has 1 or more pure virtual function.
    abstract class can't instantiate objects.
    it is used mostly to create pointers of base class pointing to derived classes -- polymorphism
 */

#include <iostream>

using namespace std;

template<class T>
class Output {
public:
    inline static void print(const T &a) {
        cout << a << endl;
    }
};

template<class T>
class Polygon {
protected:
    T width;
    T height;
public:
    Polygon() : width(1), height(1) {}
    Polygon(const T &w, const T &h) : width(w), height(h) {}
    // virtual function --> it makes class polymorphic class
    virtual T virtual_area() { return 0; }
    // pure virtual function --> it makes class abstract base class
    virtual T area()=0;
    //
    inline void print_area() { this->area(); }
};

template<class T>
class Rectangle : public Polygon<T>, public Output<T> {
public:
    Rectangle(const T &w, const T &h) : Polygon<T>(w, h) {}
    inline T area() {
        return this->width * this->height;
    }
};

template<class T>
class Triangle : public Polygon<T>, public Output<T> {
public:
    Triangle(const T &w, const T &h) : Polygon<T>(w, h) {}
    inline T area() {
        return (1.0 / 2.0) * this->width * this->height;
    }
};

int main() {
    // Rectangle instance
    Rectangle<int> rec(2, 3);
    // Triangle instance
    Triangle<double> triag(4, 9);
    // base class ptr pointing to Rectangle instance
    Polygon<int> *ptr_rec = &rec;
    // base class ptr pointing to Triangle instance
    Polygon<double> *ptr_triag = &triag;
    // static property
    Rectangle<int>::print(rec.area());
    Triangle<double>::print(triag.area());
    // polymorphism
    ptr_rec->print_area();
    ptr_triag->print_area();
    return 0;
}