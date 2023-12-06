#include <iostream>
#include <string>
using namespace std;

class rectangle {       // The class
public:
    int a, b;
    string color;
    int area, perimeter;
    //constructors
    rectangle() {
        a = 1;
        b = 1;
    };
    rectangle(int x) {
        b = x; 
        a = x;
    }
    rectangle(int x, int y) {
        a = x;
        b = y;
    }
    //methods
    void control(int x, int y) {
        if (x <= 0 || y <= 0) {
            cout << "Wrong numbers. Try again: ";
            cin >> x >> y;
            control(x,y);

        }
       else { a = x; b = y; }

    }

    int A() {
        area = a * b;
        return area;
    }

    int P() {
        perimeter = 2*(a + b);
        return perimeter;
    }

    //getters
    int Get_a() {
        return a;
    }
    int Get_b() {
        return b;
    }
    int Get_area() {
        return area;
    }
    int Get_perimeter() {
        return perimeter;
    }
    void output() {
        cout << "Side a: " << Get_a() << "\n";
        cout << "Side b: " << Get_b() << "\n";
        cout << "Area: " << Get_area() << "\n";
        cout << "Perimeter: " << Get_perimeter();
    }
    
};

int main() {    

    int A, B;
    
    cout << "Default constructor: " << endl;
    rectangle r1;
    r1.A();
    r1.P();
    r1.output();

    
    cout << endl<< "Enter 1 side of a square: ";
    cin >> A ;
    rectangle r2(A);
    r2.control(A, A);    
    r2.A();
    r2.P();
    r2.output();


    cout <<endl<< "Enter 2 sides of a rectangle: ";
    cin >> A >> B;
    rectangle r3(A, B);
    r3.control(A, B); 
    r3.A();
    r3.P();
    r2.output();
    return 0;
}
