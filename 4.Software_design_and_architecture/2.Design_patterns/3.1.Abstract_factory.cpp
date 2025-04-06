#include <iostream>
#include <memory>
#include <string>

// Abstract Product Interfaces
class Button
{
public:
    virtual void paint() = 0;
    virtual ~Button() = default;
};

class Checkbox
{
public:
    virtual void paint() = 0;
    virtual ~Checkbox() = default;
};

// Concrete Products for Windows
class WindowsButton : public Button
{
public:
    void paint() override
    {
        std::cout << "Rendering a button in Windows style\n";
    }
};

class WindowsCheckbox : public Checkbox
{
public:
    void paint() override
    {
        std::cout << "Rendering a checkbox in Windows style\n";
    }
};

// Concrete Products for macOS
class MacButton : public Button
{
public:
    void paint() override
    {
        std::cout << "Rendering a button in macOS style\n";
    }
};

class MacCheckbox : public Checkbox
{
public:
    void paint() override
    {
        std::cout << "Rendering a checkbox in macOS style\n";
    }
};

// Abstract Factory Interface
class GUIFactory
{
public:
    virtual Button *createButton() const = 0;
    virtual Checkbox *createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Factory for Windows
class WindowsFactory : public GUIFactory
{
public:
    WindowsButton *createButton() const override
    {
        return new WindowsButton();
    }

    WindowsCheckbox *createCheckbox() const override
    {
        return new WindowsCheckbox();
    }
};

// Concrete Factory for macOS
class MacFactory : public GUIFactory
{
public:
    MacButton *createButton() const override
    {
        return new MacButton();
    }

    MacCheckbox *createCheckbox() const override
    {
        return new MacCheckbox();
    }
};

// PlatformFactory Class for Platform Detection and Factory Creation
class PlatformFactory
{
public:
    static GUIFactory *createFactory(const std::string &osType)
    {
        if (osType == "Windows")
        {
            return new WindowsFactory();
        }
        else if (osType == "Mac")
        {
            return new MacFactory();
        }
        else
        {
            return nullptr; // Unsupported platform
        }
    }
};

// Function to render UI using the provided factory
void renderUI(const GUIFactory &factory)
{
    auto button = factory.createButton();
    auto checkbox = factory.createCheckbox();
    button->paint();
    checkbox->paint();
}

int main()
{
    std::string osType;
    std::cin >> osType;

    // Use PlatformFactory to get the appropriate GUIFactory
    GUIFactory *factory = PlatformFactory::createFactory(osType);

    if (factory)
    {
        renderUI(*factory);
    }
    else
    {
        std::cerr << "Unsupported OS type: " << osType << std::endl;
    }

    return 0;
}

// Any UI element can be added by creating there own interface