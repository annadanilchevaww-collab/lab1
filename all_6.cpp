#include <iostream>
#include <cmath>
using namespace std;
class NGon {
protected:
    double* sides;  
    int count;      
public:
    NGon(int n, double* storony) {
        count = n;
        sides = new double[count];
        for (int i = 0; i < count; i++) {
            sides[i] = storony[i];
        }
    }
    virtual double perimeter() {
        double p = 0;
        for (int i = 0; i < count; i++) {
            p += sides[i];
        }
        return p;
    }
    virtual ~NGon() {
        delete[] sides;
    }
};

class Triangle : public NGon {
public:
    Triangle(double a, double b, double c) : NGon(3, new double[3]{a, b, c}) {}
    double perimeter() override {
        double p = 0;
        for (int i = 0; i < count; i++) {
            p += sides[i];
        }
        return p;
    }
};

class Square : public NGon {
public:
    Square(double a) : NGon(4, new double[4]{a, a, a, a}) {}
    double perimeter() override {
        double p = 0;
        for (int i = 0; i < count; i++) {
            p += sides[i];
        }
        return p;
    }
};

int main() {
    double a, b, c;  
    double d;       
    cout << "Enter triangle sides: ";
    cin >> a >> b >> c;
    cout << "Enter square side: ";
    cin >> d;
 
    Triangle tri(a, b, c);
    Square sq(d);
    double p_tri = tri.perimeter();
    double p_sq = sq.perimeter();
    cout << "\nTriangle perimeter: " << p_tri << endl;
    cout << "Square perimeter: " << p_sq << endl;
    if (p_tri > p_sq) {
        cout << "Triangle perimeter is greater than square perimeter" << endl;
    }
    else if (p_tri < p_sq) {
        cout << "Triangle perimeter is less than square perimeter" << endl;
    }
    else {
        cout << "Perimeters are equal" << endl;
    }
    
    return 0;
}