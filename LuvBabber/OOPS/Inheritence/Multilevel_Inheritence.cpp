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

//! Multi level Inheritence

/*
    In multilevel inheritance, a class is derived from another derived class, forming a chain of inheritance.
*/

/*
    Example Description: A system like BookMyShow can have different types of bookings.
    First, we can have a Booking base class,
    then derive EventBooking,
    and finally derive ConcertBooking from EventBooking.
*/

/*
#include <bits/stdc++.h>
using namespace std;

class Booking
{
public:
    void bookTicket()
    {
        cout << "Booking a generic event." << endl;
    }
};

class EventBooking : public Booking
{
public:
    void bookEvent()
    {
        cout << "Booking an event ticket." << endl;
    }
};

class ConcertBooking : public EventBooking
{
public:
    void bookConcert()
    {
        cout << "Booking a concert ticket." << endl;
    }
};

int main()
{
    ConcertBooking cb1;
    cb1.bookTicket();
    cb1.bookEvent();
    cb1.bookConcert();
}

*/

//! According to Interview Modification

//* 1. Overriding the bookTicket Method
/*
#include <iostream>
using namespace std;

class Booking
{
public:
    virtual void bookTicket()
    { // Virtual function to allow overriding
        cout << "Booking a generic event." << endl;
    }
};

class EventBooking : public Booking
{
public:
    void bookTicket() override
    { // Override the method
        cout << "Booking an event ticket." << endl;
    }

    void bookEvent()
    {
        cout << "Booking an event." << endl;
    }
};

class ConcertBooking : public EventBooking
{
public:
    void bookTicket() override
    { // Override the method again
        cout << "Booking a concert ticket." << endl;
    }

    void bookConcert()
    {
        cout << "Booking a concert." << endl;
    }
};

int main()
{
    Booking *b1 = new ConcertBooking();
    b1->bookTicket(); // Demonstrates runtime polymorphism
    Booking *b2 = new EventBooking();
    b2->bookTicket();
    delete b2;
    delete b1;
    return 0;
}

*/
//****************************** 2. Adding a Destructor and Making It Virtual

/*
    A virtual destructor ensures that when an object of a derived class is deleted through a base class pointer,
    the derived class's destructor is called, preventing resource leaks.
*/

// /*

#include <iostream>
using namespace std;

class Booking
{
public:
    virtual ~Booking()
    { // Virtual destructor
        cout << "Booking Destructor" << endl;
    }
    virtual void bookTicket()
    {
        cout << "Booking a generic event." << endl;
    }
};

class EventBooking : public Booking
{
public:
    ~EventBooking()
    {
        cout << "EventBooking Destructor" << endl;
    }
    void bookTicket() override
    {
        cout << "Booking an event ticket." << endl;
    }
};

class ConcertBooking : public EventBooking
{
public:
    ~ConcertBooking()
    {
        cout << "ConcertBooking Destructor" << endl;
    }
    void bookTicket() override
    {
        cout << "Booking a concert ticket." << endl;
    }
};

int main()
{
    Booking *b1 = new ConcertBooking();
    b1->bookTicket(); // Demonstrates runtime polymorphism

    delete b1;
    return 0;
}
// */

// **********************************  3. Adding Constructors and Explaining Constructor Chaining

/*
    Constructors are called from the base class to the derived class (top to bottom in the inheritance hierarchy),
    while destructors are called in the reverse order (bottom to top).
*/

/*
#include <iostream>
using namespace std;

class Booking
{
public:
    Booking()
    {
        cout << "Booking Constructor" << endl;
    }
    virtual ~Booking()
    {
        cout << "Booking Destructor" << endl;
    }
    virtual void bookTicket()
    {
        cout << "Booking a generic event." << endl;
    }
};

class EventBooking : public Booking
{
public:
    EventBooking()
    {
        cout << "EventBooking Constructor" << endl;
    }
    ~EventBooking()
    {
        cout << "EventBooking Destructor" << endl;
    }
};

class ConcertBooking : public EventBooking
{
public:
    ConcertBooking()
    {
        cout << "ConcertBooking Constructor" << endl;
    }
    ~ConcertBooking()
    {
        cout << "ConcertBooking Destructor" << endl;
    }
};

int main()
{
    Booking *b1 = new ConcertBooking();
    b1->bookTicket(); // Demonstrates runtime polymorphism

    delete b1;
    return 0;
}

*/

// **********************************  4. Demonstrating Access Control (public, protected, private)

/*
#include <iostream>
using namespace std;

class Booking
{
protected: // Make this protected to restrict access
    void bookTicket()
    {
        cout << "Booking a generic event." << endl;
    }
};

class EventBooking : public Booking
{
public:
    void bookEvent()
    {
        bookTicket(); // Can still access protected method within derived class
        cout << "Booking an event." << endl;
    }
};

int main()
{
    EventBooking eb;
    eb.bookEvent(); // Works fine
    // eb.bookTicket();  // Error: bookTicket is protected and not accessible here
    return 0;
}

*/

//***************************  Using final to Prevent Further Inheritance

// Marking a class or method as final prevents further inheritance or overriding.

/*
#include <iostream>
using namespace std;

class ConcertBooking final : public EventBooking
{
public:
    void bookConcert()
    {
        cout << "Booking a concert ticket." << endl;
    }
};

// class SpecialConcertBooking : public ConcertBooking {  // Error: Cannot inherit from final class
// };

*/