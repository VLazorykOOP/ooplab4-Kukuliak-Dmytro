#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class arr {
public:
    vector<char> A;
    arr() : A(5, '_') {} // Initialize the vector in the constructor

    arr(unsigned short size) : A(size, '_') {}

    arr(unsigned short size, char x) : A(size, x) {};

    void output() {
        for (auto i : A) {
            cout << i << " ";
        }
        cout << endl;

    }

    void scalar_mask(unsigned char mask) {
        for (auto element : A) {
            element = element ^ mask;
        }
    }

    void bicode() {
        for (auto i : A) {
            cout << bitset<8>(i)<< endl;
            
        }
        cout << endl;
    }

    
};

class matrix : public arr {
public:
    vector<arr> AA;
    matrix() : AA(5, arr()) {} // Initialize the vector of arr objects in the constructor
    
    matrix(unsigned short size) : AA(size, arr(size)) {}

    matrix(unsigned short size, char x) : AA(size, arr(size, x)){}

    matrix(unsigned short i, unsigned short j, char x) : AA(i, arr(j, x)) {}

    void output() {
        cout << endl;
        for (auto i : AA) {
            i.output(); // Call the output method from arr for each element in AA
        }
    }

    void setvalue(unsigned short i, unsigned short j, char x) {
        AA[i].A[j] = x;
    }

    char getvalue(unsigned short i, unsigned short j) {
       return AA[i].A[j];
    }

    void bicode() {
        for (auto i : AA) {
            i.bicode(); // Call the output method from arr for each element in AA
        }
    }

};

int main() {
   arr test;
    test.output();
    matrix test1;
    test1.output();
   arr test2(10);
   test2.output();
    matrix test3(4);
    test3.output();
    matrix test4(4, 'D');
    test4.output();
    matrix test5(3, 4, 'r');
    test5.output();
   matrix test6(5, 6, 'f');
   test6.output();
   test6.setvalue(0, 2, 'e');
    test6.output();
    cout << test6.getvalue(0, 2);
    matrix test7(4, 'b');
    test7.output();
   test7.scalar_mask('0x0F');
   test7.output();
   test2.bicode();
    test7.bicode();
}
