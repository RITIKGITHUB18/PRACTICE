/*
    Interface: is a construct used to define a contract that classes must follow.
    This is achieved using abstract classes with pure virtual functions.

    These pure virtual function don't have an implementation in the base class.
    They must be implemented by the derived class.

    Interfaces are crucial for acheiving Polymorphism and abstraction in OOP.


*/

#include <bits/stdc++.h>
using namespace std;

class BookingInterface
{
public:
    virtual void bookTicket() const = 0;
    virtual double getPrice() const = 0;

    virtual ~BookingInterface() {}
};

class MovieBooking : public BookingInterface
{
private:
    string movieName;
    double price;

public:
    MovieBooking(string name, double cost) : movieName(name), price(cost) {}

    void bookTicket() const override
    {
        cout << "Booking a movie ticket for: " << movieName << endl;
    }

    double getPrice() const override
    {
        return price * 1.1;
    }
};

class ConcertBooking : public BookingInterface
{
private:
    string concertName;
    double price;

public:
    ConcertBooking(string name, double cost) : concertName(name), price(cost) {};

    void bookTicket() const override
    {
        cout << "Booking a concert ticket for: " << concertName << endl;
    }

    double getPrice() const override
    {
        return price * 1.2;
    }
};

class SportBooking : public BookingInterface
{
private:
    string sportName;
    double price;

public:
    SportBooking(string name, double cost) : sportName(name), price(cost) {};
    void bookTicket() const override
    {
        cout << "Booking ticket for sport event: " << sportName << endl;
    }

    double getPrice() const override
    {
        return price * 1.5;
    }
};

void booking(BookingInterface &event)
{
    event.bookTicket();
    cout << "Price for this event is: " << event.getPrice() << endl;
}

int main()
{
    SportBooking sportEvent("IPL-2025", 2500);
    booking(sportEvent);

    return 0;
}
