#include <bits/stdc++.h>
using namespace std;

class abc
{

public:
    int x;
    int *y;
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // Default copy constructor will look like this here shallow copy will happen
    /**
        abc(const abc &obj)
        {
            this->x = obj.x;
            this->y = obj.y;
        }
    */

    // Smart Copy constructor-> deep copy will take place

    abc(const abc &obj)
    {
        this->x = obj.x;
        this->y = new int(*obj.y);
    }

    void Print()
    {
        cout << "X: " << x << endl;
        cout << "Content Of Y: " << *y << endl;
        cout << "Y: " << y << endl;
    }

    ~abc()
    {
        delete y;
    }
};

int main2()
{
    abc a(1, 2);
    cout << "\nPrinting a: " << endl;
    a.Print();

    // new object b
    abc b = a; // a copy contructor is called
    cout << "\nPrinting b: " << endl;

    b.Print();

    // Modifying the value;
    *b.y = 20; // b.y ko dereference kr k value ko wapas se assign krna hai

    cout << "\nPrinting b after modification of b: " << endl;
    b.Print();

    cout << "\nPrinting a after modification of b: " << endl;
    a.Print();

    return 0;
}

int main()
{
    // Problem with shallow copy
    abc *c = new abc(3, 4);
    abc d = *c; //* shallow copy is taking place
    cout << "\nPrinting c: " << endl;
    c->Print();
    delete c;
    cout << "\nPrinting d: " << endl;
    d.Print();

    // Let's say we are going to delete the y value after the completing  execution of a;

    cout << "\n********** MAIN-2 ***********" << endl;
    main2();
    return 0;
}
