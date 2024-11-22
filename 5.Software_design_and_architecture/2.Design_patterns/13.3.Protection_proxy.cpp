#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Subject Interface
class Document
{
public:
    virtual void display() = 0;
    virtual ~Document() = default;
};

// Real Subject: The actual document
class RealDocument : public Document
{
private:
    string content;

public:
    RealDocument(const string &content) : content(content) {}

    void display() override
    {
        cout << "Displaying document content: " << content << "\n";
    }
};

// Proxy: Protection Proxy to control access
class DocumentProxy : public Document
{
private:
    unique_ptr<RealDocument> realDocument;
    string content;
    string userRole;

public:
    DocumentProxy(const string &content, const string &userRole)
        : content(content), userRole(userRole), realDocument(nullptr) {}

    void display() override
    {
        if (userRole == "Admin")
        {
            if (!realDocument)
            {
                realDocument = make_unique<RealDocument>(content);
            }
            realDocument->display();
        }
        else
        {
            cout << "Access Denied: You do not have permission to view this document.\n";
        }
    }
};

// Main function demonstrating usage
int main()
{
    // Proxy with admin role
    cout << "Admin accessing the document:\n";
    DocumentProxy adminDoc("Confidential Company Strategy", "Admin");
    adminDoc.display();

    // Proxy with employee role
    cout << "\nEmployee accessing the document:\n";
    DocumentProxy employeeDoc("Confidential Company Strategy", "Employee");
    employeeDoc.display();

    return 0;
}

/*
The Protection Proxy pattern is used to control access to a resource or object based on certain permissions or access rules.
This is particularly useful in security-sensitive applications where different users have different levels of access.
*/