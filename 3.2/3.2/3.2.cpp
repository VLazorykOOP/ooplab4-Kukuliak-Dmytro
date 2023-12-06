#include <iostream>
#include <math.h>
using namespace std;

class complex {
    

public:
    float re, im;
    bool error_state;
    static int i;
    //constructors
    complex() {
        re = 0.0;
        im = 0.0;
        error_state = false;
        i++;
    }

    complex(float x) {
        re = x;
        im = x;
        error_state = false;
        i++;
    }

    complex(float* A) {
        if (A == nullptr) { error_state = true; abort(); }
        re = A[0];
        im = A[1];
        i++;

    }
    complex(float x, float y) {
        re = x;
        im = y;
        i++;
    }

    complex operator=(complex cm)//конструктор копіювання шляхом перевантаження "="
    {
        re = cm.re;
        im = cm.im;
        return *this; // повертає об'єкт, що згенерував виклик
        i++;
    }

    //methods
    void set_value(float x, float y) {
        re = x;
        im = y;
    }
    void output() {
        cout << endl << "Z= " << re << " + " << im << "i";
    }
    float get_re() {
        return re;
    }
    float get_im() {
        return im;
    }
};

//функції, але не методи
    complex addition(complex z1, complex z2) {
        complex result;
        result.re = z1.re + z2.re;
        result.im = z1.im + z2.im;
        return result;
    }

    complex subtraction(complex z1, complex z2) {
        complex result;
        result.re = z1.re - z2.re;
        result.im = z1.im - z2.im;
        return result;
    }

    complex multiplication(complex z1, complex z2) {
        complex result;
        result.re = (z1.re * z2.re - z1.im*z2.im);
        result.im = (z1.re * z2.im + z1.im * z2.re);
        return result;
    }
    complex division(complex z1, complex z2) {
        complex result;
        result.re = (z1.re * z2.re + z1.im*z2.im)/ pow(z2.re,2)+pow(z2.im,2);
        result.im = (z1.im*z2.re - z1.re*z2.im) / pow(z2.re, 2) + pow(z2.im, 2);
        return result;
    }

    float norma(complex z) {
        float N = pow(z.re, 2) + pow(z.im, 2);
        return N;
    }

    complex division_real( complex z, float a) {
        
        complex result;
        if (a == 0) { result.error_state = true; abort(); }
        result.re = z.re / a;
        result.im = z.im / a;
        return result;
    }

    bool great(complex z1, complex z2) {
        if (norma(z1) > norma(z2)) {
            return true;
        }
        else return false;
    }
    bool smaller(complex z1, complex z2) {
        if (norma(z1) < norma(z2)) {
            return true;
        }
        else return false;
    }
    bool equal(complex z1, complex z2) {
        if (norma(z1) == norma(z2)) {
            return true;
        }
        else return false;
    }

    int complex::i = 0;



int main() {
    float a, b, f;
    float A[] = { 5, 10 };
    complex z1;
    z1.output();

    complex z2(100);
    z2.output();

    complex z3(A);
    z3.output();

    complex z4;
    cout << "\nEnter Re and Im: ";
    cin >> a >> b;
    z4.set_value(a, b);

    complex z5 = z4; // Copy constructor

    complex z6;
    z6 = addition(z5, z4);
    z6.output();
    z6 = subtraction(z5, z4);
    z6.output();
    z6 = multiplication(z5, z4);
    z6.output();
    z6 = division(z5, z4);
    z6.output();
    cout << endl << "Norma: " << norma(z6);

    cout << endl << "Enter the real number: ";
    cin >> f;
    z6 = division_real(z5, f);
    z6.output();
    cout << "\nEnter Re and Im: ";
    cin >> a >> b;
    complex z8(a, b);
    cout << "\nEnter Re and Im: ";
    cin >> a >> b;
    complex z9(a, b);
    complex z10 = multiplication(z8, z9);
    z10.output();
    cout << endl<< "Total objects: " << complex::i << endl;

    if ((great(z8, z9)) == true) {
        cout << "The norm of the first complex number is greater that the second`s";

    }
    else if ((smaller(z8, z9)) == true) {
        cout << "The norm of the second complex number is greater that the first`s";
    }
    else cout << "The norms of the compelx digits are equal";


    return 0;
}