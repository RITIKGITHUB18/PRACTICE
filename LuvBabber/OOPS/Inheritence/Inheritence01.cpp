/*
    Inheritence: Allows a class to inherit properties and behaviors(fields or method)
    from another class(called base class or parent class).

    This enables code reusablility, abstraction and extensibility
*/

/*
    Types of Inheritenc:
    1) Single Inheritence [X]
    2) Multiple Inheritence [X]
    3) Multi level Inheritence [X]
    4) hierarchy Inheritence [X]
    5) Hybrid Inheritence [X]
*/

//! single Inheritence

#include <bits/stdc++.h>
using namespace std;

class Delivery
{
public:
    void trackOrder()
    {
        cout << "Tracking Order" << endl;
    }
};

class FoodDelivery : public Delivery
{
public:
    void deliverFood()
    {
        cout << "Delivering Food Items" << endl;
    }
};

int main()
{
    FoodDelivery fd1;
    fd1.trackOrder();
    fd1.deliverFood();
}
