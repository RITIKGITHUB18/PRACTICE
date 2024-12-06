#include <bits/stdc++.h>
using namespace std;

class Vector
{
    int x, y;

public:
    Vector(int _x, int _y) : x(_x), y(_y) {}

    // v1->dest <- v2->src
    void operator+(const Vector &src)
    {
        // this would point to v1
        // src would be ref to v2

        this->x = this->x + src.x;
        this->y = this->y + src.y;
    }

    // ! overload ++ operator
    void operator++()
    {
        // this would point to v1
        // src would be ref to v2

        this->x++;
        this->y++;
    }

    void display()
    {
        cout << "x: " << x << endl;
        cout << "y: " << y << endl;
    }
};

int main()
{
    Vector v1(2, 3);
    v1.display();
    Vector v2(4, 5);
    // v1 + v2; -> Addition answer should be stored in v1;
    v1 + v2;
    cout << "Printing v1 after vector addition" << endl;
    v1.display();
    cout << "Printing v1 after vector incrementation" << endl;
    ++v1;
    v1.display();
    return 0;
}
