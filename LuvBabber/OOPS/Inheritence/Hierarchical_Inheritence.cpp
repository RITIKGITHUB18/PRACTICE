/*
    Inheritence: Allows a class to inherit properties and behaviors(fields or method)
    from another class(called base class or parent class).

    This enables code reusablility, abstraction and extensibility
*/

/*
    Types of Inheritenc:
    1) Single Inheritence
    2) Multiple Inheritence
    3) Multi level Inheritence
    4) hierarchy Inheritence [X]
    5) Hybrid Inheritence
*/

//! Hierarchical Inheritence

#include <bits/stdc++.h>
using namespace std;

class Delivery
{
public:
    void deliverOrder()
    {
        cout << "Delivering the order." << endl;
    }
};

class FoodDelivery : public Delivery
{
public:
    void deliverFood()
    {
        cout << "Delivering food." << endl;
    }
};

class GroceryDelivery : public Delivery
{
public:
    void deliverGrocery()
    {
        cout << "Delivering groceries." << endl;
    }
};

int main()
{
    FoodDelivery food;
    GroceryDelivery grocery;
    food.deliverFood();
    food.deliverOrder();

    grocery.deliverGrocery();
    return 0;
}