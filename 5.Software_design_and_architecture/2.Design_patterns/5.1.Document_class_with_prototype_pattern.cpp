#include <iostream>
#include <memory>
#include <string>

// Abstract Prototype class
class Document
{
public:
    virtual ~Document() {}
    virtual std::unique_ptr<Document> clone() const = 0; // Pure virtual clone method
    virtual void showDocument() const = 0;               // Display document content
};

// Concrete Prototype 1: Report
class Report : public Document
{
public:
    Report(const std::string &content) : content(content) {}

    // Implement clone method
    std::unique_ptr<Document> clone() const override
    {
        return std::make_unique<Report>(*this); // Return a copy of the object
    }

    void showDocument() const override
    {
        std::cout << "Report Document: " << content << std::endl;
    }

private:
    std::string content;
};

// Concrete Prototype 2: Invoice
class Invoice : public Document
{
public:
    Invoice(const std::string &details) : details(details) {}

    // Implement clone method
    std::unique_ptr<Document> clone() const override
    {
        return std::make_unique<Invoice>(*this); // Return a copy of the object
    }

    void showDocument() const override
    {
        std::cout << "Invoice Document: " << details << std::endl;
    }

private:
    std::string details;
};

// Concrete Prototype 3: Letter
class Letter : public Document
{
public:
    Letter(const std::string &message) : message(message) {}

    // Implement clone method
    std::unique_ptr<Document> clone() const override
    {
        return std::make_unique<Letter>(*this); // Return a copy of the object
    }

    void showDocument() const override
    {
        std::cout << "Letter Document: " << message << std::endl;
    }

private:
    std::string message;
};

int main()
{
    // Create initial templates
    std::unique_ptr<Document> reportTemplate = std::make_unique<Report>("Annual Financial Report 2024");
    std::unique_ptr<Document> invoiceTemplate = std::make_unique<Invoice>("Invoice #12345 for $500");
    std::unique_ptr<Document> letterTemplate = std::make_unique<Letter>("Dear John, Thank you for your business.");

    // Clone the templates to create new documents
    std::unique_ptr<Document> clonedReport = reportTemplate->clone();
    std::unique_ptr<Document> clonedInvoice = invoiceTemplate->clone();
    std::unique_ptr<Document> clonedLetter = letterTemplate->clone();

    // Display the cloned documents
    clonedReport->showDocument();
    clonedInvoice->showDocument();
    clonedLetter->showDocument();

    return 0;
}
