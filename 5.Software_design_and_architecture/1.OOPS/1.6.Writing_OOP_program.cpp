#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Function to calculate area
    double area() const {
        return length * width;
    }
};

int main() {
    double length, width;

    cout << "Enter length of the rectangle: ";
    cin >> length;
    cout << "Enter width of the rectangle: ";
    cin >> width;

    // Creating an object of Rectangle
    Rectangle rect(length, width);
    cout << "Area of the rectangle is: " << rect.area() << endl;

    return 0;
}
