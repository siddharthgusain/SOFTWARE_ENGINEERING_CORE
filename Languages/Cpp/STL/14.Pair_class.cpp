#include <iostream>
using namespace std;

// Implementation of a simple pair class
template <typename T1, typename T2>
class Pair
{
public:
    T1 first;  // First value of the pair
    T2 second; // Second value of the pair

    // Default constructor
    Pair() : first(T1()), second(T2()) {}

    // Parameterized constructor
    Pair(const T1 &firstVal, const T2 &secondVal) : first(firstVal), second(secondVal) {}

    // Copy constructor
    Pair(const Pair &other) : first(other.first), second(other.second) {}

    // Assignment operator
    Pair &operator=(const Pair &other)
    {
        if (this != &other)
        {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    // Comparison operators
    bool operator==(const Pair &other) const
    {
        return first == other.first && second == other.second;
    }

    bool operator!=(const Pair &other) const
    {
        return !(*this == other);
    }

    bool operator<(const Pair &other) const
    {
        return (first < other.first || (first == other.first && second < other.second));
    }

    bool operator>(const Pair &other) const
    {
        return (first > other.first || (first == other.first && second > other.second));
    }

    // Utility function to print the pair
    void print() const
    {
        cout << "(" << first << ", " << second << ")";
    }
};

int main()
{
    // Create pairs
    Pair<int, string> p1(1, "Hello");
    Pair<int, string> p2(2, "World");

    // Accessing elements
    cout << "Pair 1: ";
    p1.print();
    cout << "\nPair 2: ";
    p2.print();

    // Comparing pairs
    cout << "\nAre pairs equal? " << (p1 == p2 ? "Yes" : "No") << endl;

    // Assigning pairs
    p1 = p2;
    cout << "After assignment, Pair 1: ";
    p1.print();
    cout << endl;

    return 0;
}
