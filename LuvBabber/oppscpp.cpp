// // Deep Copy and Shallow copy
// #include <bits/stdc++.h>
// using namespace std;

// class abc
// {
// public:
//     int x;
//     int *y;
//     // Intialisation list :- work as a constructor
//     abc(int _x, int _y) : x(_x), y(new int(_y)) {}

//     // Default dumb copy constructor:it does shallow copy
//     // abc(const abc &obj)
//     // {
//     //     x = obj.x;
//     //     y = obj.y;
//     // }

//     // Smart deep copy
//     abc(const abc &obj)
//     {
//         x = obj.x;
//         y = new int(*obj.y);
//     }

//     void print() const
//     {
//         printf("x:%d\nPTR Y: %p\nValue at Y (*y):%d\n\n", x, y, *y);
//     }

//     // destructor
//     ~abc()
//     {
//         delete y;
//     }
// };

// int main()
// {
//     abc a(1, 2);
//     cout << "Printing a\n";
//     a.print();

//     // copying the value of a in b
//     // abc b(a); //or
//     abc b = a; // call hota hai copy constructor
//     cout << "Printing b\n";
//     b.print();
//     *b.y = 5;
//     cout << "Printing b\n";
//     b.print();

//     cout << "Printing a\n";
//     a.print();

//     return 0;
// }

// ! can constructor be made private? Yes, but you can't access it in a main directly instead you have to make another friend class of the private ctor class to access
// Example
#include <bits/stdc++.h>
using namespace std;

class Box
{
    int width;
    // Intialisation list or ctor
    Box(int _w) : width(_w) {};

public:
    // Getter and setter to access the private variables
    int getter()
    {
        return width;
    }
    void setter(int _v)
    {
        width = _v;
    }

    friend class BoxFactory;
};

class BoxFactory
{
    int count;

public:
    Box getABox(int _w)
    {
        ++count;
        return Box(_w);
    }
};

int main()
{
    BoxFactory bfact;
    Box b = bfact.getABox(5);
    cout << b.getter() << endl;
    return 0;
}