#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = 3;
    int c = a & b;
    cout << c << endl;
    int d = a | b;
    cout << d << endl;
    cout << ~a << endl;
    cout << (~a) << endl;
    cout << ~(a) << endl;

    // ? xor
    cout << (a ^ b) << endl;
    cout << (5 ^ -5) << endl;
    cout << (5 ^ 10) << endl;

    // ? left shift
    cout << (a << 1) << endl;
    cout << (a << 2) << endl;

    // ? right shift
    cout << (50 >> 1) << endl;
    cout << (50 >> 2) << endl;

    cout << (-100 >> 1) << endl;
    unsigned int f = -100;
    cout << (f >> 1) << endl;

    // ? pre/post incre/decre operator
    int g = 5;
    cout << (g++) << endl;
    int h = 10;
    cout << (++h) << endl;
    int i = 10;
    cout << (i--) * 10 << endl;
    int j = 10;
    cout << (--j) * 10 << endl;

    int k = 10;
    cout << ((++j) * (j++)) << endl;
    int l = 10;
    cout << (k++) * (++k) << endl;
}