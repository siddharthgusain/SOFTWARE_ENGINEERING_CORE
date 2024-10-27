#include <iostream>
#include <string>

// Interface for basic printing functionality
class IPrinter
{
public:
    virtual void printDocument(const std::string &doc) = 0;
    virtual ~IPrinter() = default;
};

// Interface for scanning functionality
class IScanner
{
public:
    virtual void scanDocument(const std::string &doc) = 0;
    virtual ~IScanner() = default;
};

// Interface for fax functionality
class IFax
{
public:
    virtual void faxDocument(const std::string &doc) = 0;
    virtual ~IFax() = default;
};

// Interface for stapling functionality
class IStapler
{
public:
    virtual void stapleDocument(const std::string &doc) = 0;
    virtual ~IStapler() = default;
};

// BasicPrinter now only implements IPrinter
class BasicPrinter : public IPrinter
{
public:
    void printDocument(const std::string &doc) override
    {
        std::cout << "Printing document: " << doc << std::endl;
    }
};

// AdvancedPrinter implements multiple interfaces
class AdvancedPrinter : public IPrinter, public IScanner, public IFax, public IStapler
{
public:
    void printDocument(const std::string &doc) override
    {
        std::cout << "Printing document: " << doc << std::endl;
    }

    void scanDocument(const std::string &doc) override
    {
        std::cout << "Scanning document: " << doc << std::endl;
    }

    void faxDocument(const std::string &doc) override
    {
        std::cout << "Faxing document: " << doc << std::endl;
    }

    void stapleDocument(const std::string &doc) override
    {
        std::cout << "Stapling document: " << doc << std::endl;
    }
};
