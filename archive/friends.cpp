/*
 friend function can access private and protected properties
 friend function is not part of class (classname:: not used w/ friend)

 friend class is a class whose members have access to private/protected properties of another class
 */

#include <iostream>

using namespace std;

class Rectangle {
private:
    int width, height;
public:
    Rectangle();
    Rectangle(const int &, const int &);
    inline void print() {
        cout << "height: " << height
             << " width: " << width
             << endl;
    }
    friend Rectangle multiply(const Rectangle &);
};

Rectangle::Rectangle() : width(1), height(1) {}
Rectangle::Rectangle(const int &w, const int &h) : width(w), height(h) {}
Rectangle multiply(const Rectangle &oldRec) {
    Rectangle rec;
    rec.width = oldRec.width * 2;
    rec.height = oldRec.height * 2;
    return rec;
}
int main() {
    Rectangle rec(23, 23);
    rec.print();
    // notice how multiply is called
    // not part of class, still can access properties
    rec = multiply(rec);
    rec.print();
    return 0;
}