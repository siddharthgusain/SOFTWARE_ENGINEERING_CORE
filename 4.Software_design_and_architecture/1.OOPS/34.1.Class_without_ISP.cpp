#include <iostream>

class Printer
{
public:
    virtual void printDocument(const std::string &doc) = 0;
    virtual void scanDocument(const std::string &doc) = 0;
    virtual void faxDocument(const std::string &doc) = 0;
    virtual void stapleDocument(const std::string &doc) = 0;
    virtual ~Printer() = default;
};

class BasicPrinter : public Printer
{
public:
    void printDocument(const std::string &doc) override
    {
        std::cout << "Printing document: " << doc << std::endl;
    }

    void scanDocument(const std::string &doc) override
    {
        // BasicPrinter cannot scan, so we leave this blank or raise an error
    }

    void faxDocument(const std::string &doc) override
    {
        // BasicPrinter cannot fax, so we leave this blank or raise an error
    }

    void stapleDocument(const std::string &doc) override
    {
        // BasicPrinter cannot staple, so we leave this blank or raise an error
    }
};

/*
Problems with This Design
Unnecessary Implementation: The BasicPrinter class does not need to implement methods like scanDocument, faxDocument, or stapleDocument since it only supports printing.
Violation of ISP: BasicPrinter is forced to depend on methods that it doesn’t need, leading to empty or error-prone implementations.
*/