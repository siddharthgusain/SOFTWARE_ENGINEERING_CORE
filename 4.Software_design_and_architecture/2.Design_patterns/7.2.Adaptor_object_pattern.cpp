#include <iostream>

// Target Interface (Square)
class Square
{
public:
    virtual void setSide(double side) = 0; // Set the length of one side
    virtual double getArea() const = 0;    // Get the area of the square
    virtual ~Square() = default;
};

// Adaptee Class (Rectangle)
class Rectangle
{
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void setWidth(double w)
    {
        width = w;
    }

    void setHeight(double h)
    {
        height = h;
    }

    double getWidth() const
    {
        return width;
    }

    double getHeight() const
    {
        return height;
    }

    double getArea() const
    {
        return width * height;
    }
};

// Adapter Class (RectangleAdapter)
class RectangleAdapter : public Square
{
private:
    Rectangle *rectangle; // Composition: Holds a reference to the Adaptee

public:
    RectangleAdapter(Rectangle *rect) : rectangle(rect) {}

    void setSide(double side) override
    {
        // Set both width and height of the rectangle to match the square's side length
        rectangle->setWidth(side);
        rectangle->setHeight(side);
    }

    double getArea() const override
    {
        return rectangle->getArea();
    }
};

int main()
{
    // Create a Rectangle instance
    Rectangle rect(4.0, 5.0);

    // Use the adapter to treat it as a Square
    RectangleAdapter adapter(&rect);

    // Set the square's side and calculate the area
    adapter.setSide(10.0);

    std::cout << "Square's area: " << adapter.getArea() << std::endl;

    return 0;
}
