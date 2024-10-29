#include <iostream>

using namespace std;

class Vehicle // Interface
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

class VehicleFactory
{
public:
    static Vehicle *getVehicle(string vehicleType)
    {
        if (vehicleType == "Car")
        {
            return new Car();
        }
        else if (vehicleType == "Bike")
        {
            return new Bike();
        }
        // Any More Type can be added only at one place
    }
};

// Client Code which uses these classes
int main()
{
    string vehicleType;
    cin >> vehicleType;
    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();

    return 0;
}

// Factory class will Hide this logic in itself
// Client Doesn't know how objects are created