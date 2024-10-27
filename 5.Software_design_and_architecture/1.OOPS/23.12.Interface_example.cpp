#include <iostream>
#include <cmath> // for M_PI
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define the Shape interface with pure virtual functions
class Shape
{
public:
    // Pure virtual functions
    virtual double area() const = 0;      // Calculate area
    virtual double perimeter() const = 0; // Calculate perimeter

    // Virtual destructor (important for interfaces)
    virtual ~Shape() {}
};

// Circle class implementing the Shape interface
class Circle : public Shape
{
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Override area and perimeter
    double area() const override
    {
        return M_PI * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }
};

// Rectangle class implementing the Shape interface
class Rectangle : public Shape
{
private:
    double width, height;

public:
    // Constructor
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override area and perimeter
    double area() const override
    {
        return width * height;
    }

    double perimeter() const override
    {
        return 2 * (width + height);
    }
};

int main()
{
    // Create instances of Circle and Rectangle
    Shape *circle = new Circle(5.0);
    Shape *rectangle = new Rectangle(4.0, 6.0);

    // Display area and perimeter of each shape
    cout << "Circle - Area: " << circle->area() << ", Perimeter: " << circle->perimeter() << endl;
    cout << "Rectangle - Area: " << rectangle->area() << ", Perimeter: " << rectangle->perimeter() << endl;

    // Clean up
    delete circle;
    delete rectangle;

    return 0;
}
