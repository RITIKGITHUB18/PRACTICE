/*
    Abstraction:Abstraction in Object-Oriented Programming (OOP) refers to the concept of
    hiding the internal implementation details and showing only the essential features or functionalities of an object to the user.
    This helps in reducing complexity by focusing on what an object does rather than how it does it.

    Abstraction allows us to define the blueprint for the derived class, while leading the specific implementation to those derived classes.

    Real World Example of Abstraction: Food delivery system like swiggy or Zomato
    -> User's interact with the app to place an order but they don't need to know the internal logistics:
        -> how the restaurant process the order,
        -> The delivary process, etc.
*/

#include <bits/stdc++.h>
using namespace std;

class FoodDelivery
{
public:
    virtual void placeOrder() const = 0;

    virtual void payment() const
    {
        cout << "Processing Payment..." << endl;
    }

    virtual ~FoodDelivery()
    {
        cout << "Food Delivery Object destroyed..." << endl;
    }
};

class ZomatoDelivery : public FoodDelivery
{
public:
    void placeOrder() const
    {
        cout << "Placing order through Zomato..." << endl;
    }

    void payment() const override
    {
        cout << "Payment is done to Zomato. " << endl;
    }

    ~ZomatoDelivery()
    {
        cout << "Zomato object is destroyed." << endl;
    }
};

class SwiggyDelivery : public FoodDelivery
{
public:
    void placeOrder() const
    {
        cout << "Placing order through Swiggy..." << endl;
    }

    void payment() const override
    {
        cout << "Payment is done to Swiggy. " << endl;
    }

    ~SwiggyDelivery()
    {
        cout << "Swiggy Object is destroyed." << endl;
    }
};

void processOrder(const FoodDelivery &service)
{
    service.placeOrder();
    service.payment();
};

int main()
{
    ZomatoDelivery zomato;
    SwiggyDelivery swiggy;

    processOrder(zomato);
    processOrder(swiggy);
    return 0;
}
