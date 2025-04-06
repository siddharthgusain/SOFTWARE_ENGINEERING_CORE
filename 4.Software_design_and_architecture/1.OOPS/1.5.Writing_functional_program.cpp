#include <iostream>
using namespace std;

// Function to calculate area of rectangle
double area(double length, double width)
{
    return length * width;
}

int main()
{
    double length, width;

    cout << "Enter length of the rectangle: ";
    cin >> length;
    cout << "Enter width of the rectangle: ";
    cin >> width;

    // Directly calling the area function
    cout << "Area of the rectangle is: " << area(length, width) << endl;

    return 0;
}
