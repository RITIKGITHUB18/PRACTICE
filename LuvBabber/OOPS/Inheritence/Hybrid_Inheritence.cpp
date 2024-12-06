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
    4) hierarchy Inheritence
    5) Hybrid Inheritence
*/

//! Hybrid Inheritence

/*
    Hybrid inheritance is a combination of two or more types of inheritance.
    It usually combines hierarchical and multiple inheritance.
    This can also lead to ambiguity if not handled properly (as in the diamond problem).
*/

#include <iostream>
using namespace std;

// Base class representing general delivery
class Delivery
{
public:
    Delivery()
    {
        cout << "Delivery Constructor" << endl;
    }

    virtual ~Delivery()
    {
        cout << "Delivery Destructor" << endl;
    }

    virtual void deliverOrder()
    {
        cout << "Delivering general order." << endl;
    }
};

// Another base class representing a food service
class FoodService
{
public:
    FoodService()
    {
        cout << "FoodService Constructor" << endl;
    }

    virtual ~FoodService()
    {
        cout << "FoodService Destructor" << endl;
    }

    virtual void prepareFood()
    {
        cout << "Preparing food." << endl;
    }
};

// First derived class inheriting from both Delivery and FoodService
class FoodDelivery : public virtual Delivery, public virtual FoodService
{
public:
    FoodDelivery()
    {
        cout << "FoodDelivery Constructor" << endl;
    }

    ~FoodDelivery()
    {
        cout << "FoodDelivery Destructor" << endl;
    }

    // Override deliverOrder to handle food-specific deliveries
    void deliverOrder() override
    {
        cout << "Delivering food order." << endl;
    }

    void deliverFood()
    {
        cout << "Delivering food via regular service." << endl;
    }
};

// Another derived class, specializing in fast food delivery
class ExpressFoodDelivery : public virtual FoodDelivery
{
public:
    ExpressFoodDelivery()
    {
        cout << "ExpressFoodDelivery Constructor" << endl;
    }

    ~ExpressFoodDelivery()
    {
        cout << "ExpressFoodDelivery Destructor" << endl;
    }

    // Override deliverOrder for express delivery
    void deliverOrder() override
    {
        cout << "Delivering food through express service." << endl;
    }

    void fastDelivery()
    {
        cout << "Using express delivery to deliver food." << endl;
    }
};

// VIPService class to demonstrate another angle of hybrid inheritance
class VIPService
{
public:
    VIPService()
    {
        cout << "VIPService Constructor" << endl;
    }

    virtual ~VIPService()
    {
        cout << "VIPService Destructor" << endl;
    }

    virtual void provideVIPService()
    {
        cout << "Providing VIP service to the customer." << endl;
    }
};

// ExpressFoodDelivery inheriting from VIPService as well, making it hybrid
class PremiumExpressFoodDelivery : public ExpressFoodDelivery, public VIPService
{
public:
    PremiumExpressFoodDelivery()
    {
        cout << "PremiumExpressFoodDelivery Constructor" << endl;
    }

    ~PremiumExpressFoodDelivery()
    {
        cout << "PremiumExpressFoodDelivery Destructor" << endl;
    }

    // Can access VIP services, express delivery, and food preparation
    void providePremiumService()
    {
        cout << "Providing premium express food delivery service." << endl;
    }
};

// Main function to demonstrate the behavior of hybrid inheritance
int main()
{
    // Create an object of PremiumExpressFoodDelivery
    PremiumExpressFoodDelivery premiumDelivery;

    // Call methods from various levels of inheritance
    premiumDelivery.prepareFood();           // From FoodService
    premiumDelivery.deliverOrder();          // From ExpressFoodDelivery (overrides FoodDelivery and Delivery)
    premiumDelivery.deliverFood();           // From FoodDelivery
    premiumDelivery.fastDelivery();          // From ExpressFoodDelivery
    premiumDelivery.provideVIPService();     // From VIPService
    premiumDelivery.providePremiumService(); // From PremiumExpressFoodDelivery

    return 0;
}
