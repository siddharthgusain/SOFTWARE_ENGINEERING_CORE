#include <iostream>

class Keyboard
{
public:
    void input() const
    {
        std::cout << "Keyboard input detected." << std::endl;
    }
};

class Computer
{
private:
    Keyboard keyboard; // Direct dependency on Keyboard

public:
    void getInput()
    {
        keyboard.input();
    }
};

int main()
{
    Computer computer;
    computer.getInput(); // Output: "Keyboard input detected."
    return 0;
}

/*
Problems with This Design
Tight Coupling: The Computer class is tightly coupled to the Keyboard class, making it hard to extend or change input methods (e.g., adding a Mouse class).
Difficult to Test: If we want to test Computer with different input methods, we would have to change its implementation.
*/