#include <bits/stdc++.h>
using namespace std;

class abc
{
public:
    static int x, y;

    void print() const
    {
        cout << x << " " << y << endl;
    }

    int a, b;
    static void print_A_b()
    {
        // In static member function we can't pass the instance of that class
        // i.e. we can't pass a or b but we can pass x and y in it as x and y are not associated with any particular object
        printf("I'm inside a static function %s\n", __FUNCTION__);
        printf("x=%d, y=%d", x, y);
    }
};

// This is the particular syntax to define the static member variables
int abc::x;
int abc::y;

int main()
{
    // abc obj1;
    // obj1.x = 1;
    // obj1.y = 2;
    // obj1.print();
    // obj1.print_A_b();

    // abc obj2;
    // obj2.x = 10;
    // obj2.y = 20;
    // obj1.print();
    // obj2.print();

    // * other way to write is like
    abc obj1;
    abc::x = 1;
    abc::y = 2;
    obj1.print(); // non-static function
    abc::print_A_b();

    return 0;
}
