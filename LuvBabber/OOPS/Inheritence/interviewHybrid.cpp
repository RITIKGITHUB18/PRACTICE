#include <iostream>
using namespace std;

// Base class 1: General Vehicle
class Vehicle
{
public:
    void start()
    {
        cout << "Starting the vehicle..." << endl;
    }
};

// Base class 2: Features for Electric Vehicles
class ElectricFeatures
{
public:
    void chargeBattery()
    {
        cout << "Charging the battery..." << endl;
    }
};

// Intermediate derived class: Car (inherits from Vehicle)
class Car : public Vehicle
{
public:
    void drive()
    {
        cout << "Driving the car..." << endl;
    }
};

// Final class: ElectricCar (inherits from both Car and ElectricFeatures)
class ElectricCar : public Car, public ElectricFeatures
{
public:
    void ecoMode()
    {
        cout << "Switching to eco mode..." << endl;
    }
};

// Main function
int main()
{
    ElectricCar myElectricCar;

    // Calling methods from different base and derived classes
    myElectricCar.start();         // From Vehicle
    myElectricCar.drive();         // From Car
    myElectricCar.chargeBattery(); // From ElectricFeatures
    myElectricCar.ecoMode();       // From ElectricCar

    return 0;
}
