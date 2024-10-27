#include <iostream>
#include <memory>

// InputDevice interface, representing an abstraction
class InputDevice
{
public:
    virtual void input() const = 0;
    virtual ~InputDevice() = default;
};

// Keyboard class implementing the InputDevice interface
class Keyboard : public InputDevice
{
public:
    void input() const override
    {
        std::cout << "Keyboard input detected." << std::endl;
    }
};

// Mouse class implementing the InputDevice interface
class Mouse : public InputDevice
{
public:
    void input() const override
    {
        std::cout << "Mouse input detected." << std::endl;
    }
};

// Computer depends on the abstraction, not a specific input device
class Computer
{
private:
    std::shared_ptr<InputDevice> inputDevice; // Depend on InputDevice abstraction

public:
    Computer(std::shared_ptr<InputDevice> device) : inputDevice(device) {}

    void getInput()
    {
        inputDevice->input();
    }
};

int main()
{
    // We can easily swap out the input device without changing Computer's implementation
    std::shared_ptr<InputDevice> keyboard = std::make_shared<Keyboard>();
    std::shared_ptr<InputDevice> mouse = std::make_shared<Mouse>();

    Computer computerWithKeyboard(keyboard);
    Computer computerWithMouse(mouse);

    computerWithKeyboard.getInput(); // Output: "Keyboard input detected."
    computerWithMouse.getInput();    // Output: "Mouse input detected."

    return 0;
}
