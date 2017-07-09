/*
 int A::b(int c) { }    --> method b of class A with param c
 a->b                   --> a is a pointer to an instance, used to access method b
 class A: public B {};  --> A inherits B publicly
 */

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
    Rectangle<int> rec(2, 3);
    Triangle<double> triag(4, 9);
    Rectangle<int>::print(rec.area());
    Triangle<double>::print(triag.area());
    return 0;
}