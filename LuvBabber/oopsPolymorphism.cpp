#include <bits/stdc++.h>
using namespace std;

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    // virtual
    virtual void makeSound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }

    virtual ~Animal()
    {
        cout << "~Animal Dtor" << endl;
    }
};

class Dog : public Animal
{
public:
    // here writing the override increases the readability nothing more then this
    void makeSound() override
    {
        std::cout << "Dog barks" << std::endl;
    }

    ~Dog()
    {
        cout << "~Dog Dtor" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Cat meows" << std::endl;
    }

    ~Cat()
    {
        cout << "~Cat Dtor" << endl;
    }
};

// let's call a function for making the sound
void sound(Animal *animal)
{
    animal->makeSound(); // Polymorphic
    // animal->makeSound is behaving as per required object allocated at runtime
}

int main()
{
    // Animal *animalPtr;
    // Dog dogObj;
    // Cat catObj;

    // animalPtr = &dogObj;
    // sound(animalPtr);
    // animalPtr = &catObj;
    // sound(animalPtr);
    // animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"

    // ! dynamic allocation of memory in heap
    Animal *animalPtr = new Dog();
    sound(animalPtr);
    delete animalPtr;

    return 0;
}

// Real-Life Example
/*
  Types Of Polymorphism: 1) Compile-Time Polymorphism
                            2) Run-Time Polymorphism


**/

/*
    Example Description:where we can have a base class "Booking" with different derived classes such as MovieBooking, EventBooking, and SportsBooking.

    Base Class: Bookig Common Attributes like (BookTickets(), GetPrices());
    Derived Class:
    1) MovieBooking: handles movie ticket booking
    2) SportsBooking: handles Sports ticket booking
    3) EventBooking: handles Event ticket booking
*/

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
