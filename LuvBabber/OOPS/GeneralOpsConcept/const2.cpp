#include <bits/stdc++.h>
using namespace std;

// Const member function , instialization list

class abc
{
    // mutable int x; we can use the "Mutable" keyword to change the value of x in any const member function this is generally used for the debuging the code
    int x;
    int *y;
    int z;

public:
    // ctor: Old style to write the constructor
    // abc(int _x, int _y)
    // {
    //     x = _x;
    //     y = new int(_y);
    // }

    //! intialization List: new way to write the ctor

    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z)
    {
        // furthur modification or if you want ot write any cout statement you can write it here
        // Const Members: const member variables can only be initialized using an initialization list. Once they are initialized, their values cannot be changed.
    }

    // const member function
    int getX() const // we want during reading the value it don't get change
    {
        return x;
    }

    void setX(int val)
    {
        x = val;
    }

    // const member function
    int getY() const // we want during reading the value it don't get change
    {
        return *y;
    }

    void setY(int val)
    {
        *y = val;
    }
};

void printABC(const abc &a)
{
    cout << a.getX() << " " << a.getY() << endl;
}

int main()
{
    abc a(1, 2);
    printABC(a);
    return 0;
}
