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

//! Multiple Inheritence

#include <bits/stdc++.h>
using namespace std;

/*
    Example Description: A Multiple Inheritence from more than one base class.
    This can lead to complexities like the diamond problem where ambiguity arises
    in case of multiple paths of Heritence.
*/

/**
class Delivery
{
public:
    void trackOrder()
    {
        cout << "Tracking the delivery Order" << endl;
    }
};

class ParcelService
{
public:
    void trackParcel()
    {
        cout << "Tracking the parcel Order." << endl;
    }
};

class SwiggyGenie : public Delivery, public ParcelService
{
public:
    void deliverOrder()
    {
        cout << "Delivering both food and parcel" << endl;
    }
};

int main()
{
    SwiggyGenie sg1;
    sg1.trackParcel();
    sg1.deliverOrder();
}
*/
//! Let's take an example in which if both parcelService and Delivery class is having same method called trackOrder

/*
    Then in that scenarios swiggyGenie will face ambiguity when trying to call trackOrder()
    because C++ won’t know which version of the function to use (from Delivery or ParcelService).

    To resolve this ambiguity, you can explicitly override the trackOrder() method in the SwiggyGenie class, deciding which version you want to call,
    or you can explicitly qualify the base class when calling the method.
*/

/*

#include <iostream>
using namespace std;

class Delivery
{
public:
    void trackOrder()
    {
        cout << "Tracking the Delivery Order" << endl;
    }
};

class ParcelService
{
public:
    void trackOrder()
    {
        cout << "Tracking the Parcel Order." << endl;
    }
};

class SwiggyGenie : public Delivery, public ParcelService
{
public:
    void trackOrder()
    {
        // You can decide which base class method to call, or combine them.
        Delivery::trackOrder();      // Calling the Delivery class version
        ParcelService::trackOrder(); // Calling the ParcelService class version
    }

    void deliverOrder()
    {
        cout << "Delivering both food and parcel" << endl;
    }
};

int main()
{
    SwiggyGenie sg1;
    sg1.trackOrder(); // Calls the overridden trackOrder in SwiggyGenie
    sg1.deliverOrder();
}

*/

//! ******************************** second method *****************************************************

/*
#include <iostream>
using namespace std;

class Delivery
{
public:
    void trackOrder()
    {
        cout << "Tracking the Delivery Order" << endl;
    }
};

class ParcelService
{
public:
    void trackOrder()
    {
        cout << "Tracking the Parcel Order." << endl;
    }
};

class SwiggyGenie : public Delivery, public ParcelService
{
public:
    void deliverOrder()
    {
        cout << "Delivering both food and parcel" << endl;
    }
};

int main()
{
    SwiggyGenie sg1;

    // To call the Delivery's version of trackOrder
    sg1.Delivery::trackOrder();

    // To call the ParcelService's version of trackOrder
    sg1.ParcelService::trackOrder();

    sg1.deliverOrder();
}
*/