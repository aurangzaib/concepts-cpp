#include <iostream>

class polygon {
protected:
    int width;
    int height;
public:
    inline void setValues(const int &w, const int &h) {
        width = w;
        height = h;
    }
};

class rectangle : public polygon {
public:
    inline int area() {
        return width * height;
    }
};

class triangle : public polygon {
public:
    inline float area() {
        return (1 / 2) * width * height;
    }
};

int main() {
    rectangle rec;
    rec.setValues(2, 3);
    triangle triag;
    triag.setValues(5, 6);
    cout << "area of rect: " << rec.area() << endl;
    cout << "area of triag: " << triag.area() << endl;
    return 0;
}