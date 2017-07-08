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

class Polygon {
protected:
    int width;
    int height;
public:
    Polygon() : width(1), height(1) {}
    Polygon(const int &w, const int &h) : width(w), height(h) {}
};

class Rectangle : public Polygon, public Output<int> {
public:
    Rectangle(const int &w, const int &h) : Polygon(w, h) {}
    inline int area() {
        return width * height;
    }
};

class Triangle : public Polygon, public Output<double> {
public:
    Triangle(const int &w, const int &h) : Polygon(w, h) {}
    inline double area() {
        return (1.0 / 2.0) * double(width) * double(height);
    }
};

int main() {
    Rectangle rec(2, 3);
    Triangle triag(4, 5);
    Rectangle::print(rec.area());
    Triangle::print(triag.area());
    return 0;
}