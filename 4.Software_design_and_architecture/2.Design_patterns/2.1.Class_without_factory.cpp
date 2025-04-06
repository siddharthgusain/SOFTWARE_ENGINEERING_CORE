#include <iostream>

using namespace std;

class Vehicle
{
public:
    virtual void createVehicle() = 0;
};

class Car : public Vehicle
{
public:
    void createVehicle() override
    {
        cout << "Creating Car";
    }
};

class Bike : public Vehicle
{
public:
    void createVehicle() override
    {
        cout << "Creating Bike";
    }
};

// Client Code which uses these classes
int main()
{
    string vehicleType;
    cin >> vehicleType;
    Vehicle *vehicle = nullptr;

    if (vehicleType == "Car")
    {
        vehicle = new Car();
    }
    else if (vehicleType == "Bike")
    {
        vehicle = new Bike();
    }

    vehicle->createVehicle();

    return 0;
}

// Logic of Object Creation is Present in CLient/Consumer of Library
// Factory class will Hide this logic in itself