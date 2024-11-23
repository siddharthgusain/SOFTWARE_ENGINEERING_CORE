#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Forward declaration of Visitor
class Visitor;

// Element Interface
class Shape
{
public:
    virtual void accept(Visitor &visitor) = 0; // Accept a visitor
    virtual ~Shape() = default;
};

// Concrete Element: Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }

    void accept(Visitor &visitor) override;
};

// Concrete Element: Rectangle
class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void accept(Visitor &visitor) override;
};

// Visitor Interface
class Visitor
{
public:
    virtual void visit(Circle &circle) = 0;
    virtual void visit(Rectangle &rectangle) = 0;
    virtual ~Visitor() = default;
};

// Concrete Visitor: DrawVisitor
class DrawVisitor : public Visitor
{
public:
    void visit(Circle &circle) override
    {
        cout << "Drawing Circle with radius: " << circle.getRadius() << endl;
    }

    void visit(Rectangle &rectangle) override
    {
        cout << "Drawing Rectangle with width: " << rectangle.getWidth()
             << " and height: " << rectangle.getHeight() << endl;
    }
};

// Concrete Visitor: ExportVisitor
class ExportVisitor : public Visitor
{
public:
    void visit(Circle &circle) override
    {
        cout << "Exporting Circle to JSON: { \"radius\": " << circle.getRadius() << " }" << endl;
    }

    void visit(Rectangle &rectangle) override
    {
        cout << "Exporting Rectangle to JSON: { \"width\": " << rectangle.getWidth()
             << ", \"height\": " << rectangle.getHeight() << " }" << endl;
    }
};

// Accept method implementations for Concrete Elements
void Circle::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void Rectangle::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

// Main function demonstrating the Visitor Pattern
int main()
{
    vector<shared_ptr<Shape>> shapes = {
        make_shared<Circle>(5.0),
        make_shared<Rectangle>(3.0, 4.0),
    };

    // Create visitors
    DrawVisitor drawVisitor;
    ExportVisitor exportVisitor;

    // Use visitors
    cout << "Drawing Shapes:" << endl;
    for (auto &shape : shapes)
    {
        shape->accept(drawVisitor);
    }

    cout << "\nExporting Shapes to JSON:" << endl;
    for (auto &shape : shapes)
    {
        shape->accept(exportVisitor);
    }

    return 0;
}
