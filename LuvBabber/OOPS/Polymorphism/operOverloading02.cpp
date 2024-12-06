#include <bits/stdc++.h>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {};

    Complex operator+(const Complex &obj)
    {
        real = real + obj.real;
        imag = imag + obj.imag;
        return Complex(real, imag);
    }

    Complex operator-(const Complex &obj)
    {
        real = real - obj.real;
        imag = imag - obj.imag;
        return (real, imag);
    }

    friend ostream &operator<<(ostream &out, const Complex &obj)
    {
        out << obj.real << "+" << obj.imag << "i";
        return out;
    }

    void printComplex()
    {
        if (imag > 0)
        {
            cout << real << "+" << imag << "i" << endl;
        }
        else
        {
            cout << real << imag << "i" << endl;
        }
    }
};

int main()
{
    Complex c1(3.0, 4.0);
    Complex c2(2.0, 5.0);

    // c1 + c2;
    c1 - c2;
    c1.printComplex();
    return 0;
}
