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
    int getter() const
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