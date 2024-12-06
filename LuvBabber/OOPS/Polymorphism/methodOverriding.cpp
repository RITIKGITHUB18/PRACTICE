/*
  Types Of Polymorphism: 1) Compile-Time Polymorphism
                            2) Run-Time Polymorphism
    Polymorphism:- means One things behaving in many ways,
    so It's a concept in programming that lets the same function, object or interface
    or interface do different things depending on the situation.

**/

/*
    Example Description: Where we can have a base class "Booking" with different derived classes such as MovieBooking, EventBooking, and SportsBooking.

    Base Class: Booking Common Attributes like (BookTickets(), GetPrices());
    Derived Class:
    1) MovieBooking: handles movie ticket booking
    2) SportsBooking: handles Sports ticket booking
    3) EventBooking: handles Event ticket booking
*/

/**

#include <bits/stdc++.h>
using namespace std;

class Booking
{
protected:
    string bookingType;
    double price;

public:
    Booking(string type, double cost) : bookingType(type), price(cost) {};

    virtual void bookTicket() const
    {
        cout << "Booking a generic ticket: " << endl;
    }

    virtual double getPrice() const
    {
        return price;
    }

    // Virtual destructor

    virtual ~Booking()
    {
        cout << "Booking Dtor" << endl;
    }
};

class MovieBooking : public Booking
{
private:
    string movieName;

public:
    MovieBooking(string name, double cost) : movieName(name), Booking("Movie", cost) {};

    void bookTicket() const override
    {
        cout << "Booking a movie ticket: " << movieName << endl;
    }

    double getPrice() const override
    {
        return price * 1.1;
    }
};

class EventBooking : public Booking
{
private:
    string eventName;
public:
    EventBooking(string name, double cost) : eventName(name), Booking("Event", cost) {};

    void bookTicket() const override
    {
        cout << "Booking a ticket for Event: " << eventName << endl;
    }

    double getPrice() const override
    {
        return price * 1.2;
    }
};

class SportBooking : public Booking
{
private:
    string sportName;

public:
    SportBooking(string name, double cost) : sportName(name), Booking("Sports", cost) {};

    void bookTicket() const override
    {
        cout << "Booking ticket for sports: " << sportName << endl;
    }

    double getPrice() const override
    {
        return price * 1.5;
    }
};

void processBooking(const Booking &booking)
{
    booking.bookTicket();
    cout << "Total Price: " << booking.getPrice() << endl;
}

int main()
{
    MovieBooking movie("Dangal", 250);
    EventBooking event("ColdPlay", 7800);
    SportBooking sport("Cric-T20", 2400);
    processBooking(movie);
    processBooking(event);
    processBooking(sport);
    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

class Delivery
{
public:
    virtual void deliverOrder()
    {
        cout << "Delivering order through standard method." << endl;
    }
};

class ExpressDelivery : public Delivery
{
public:
    void deliverOrder() override
    {
        cout << "Delivering order through express method." << endl;
    }
};

class NoContactDelivery : public Delivery
{
public:
    void deliverOrder() override
    {
        cout << "Delivering order with no-contact delivery method." << endl;
    }
};

void deliver(Delivery &delivery)
{
    delivery.deliverOrder();
}

int main()
{
    NoContactDelivery d1;

    Delivery *d2 = new ExpressDelivery();
    deliver(*d2);
    deliver(d1);
}