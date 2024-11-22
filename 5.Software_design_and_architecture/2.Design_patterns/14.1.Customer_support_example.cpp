#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Abstract Handler
class SupportHandler
{
protected:
    shared_ptr<SupportHandler> nextHandler;

public:
    virtual ~SupportHandler() = default;

    void setNextHandler(shared_ptr<SupportHandler> handler)
    {
        nextHandler = handler;
    }

    virtual void handleRequest(const string &issue) = 0;
};

// Concrete Handler: Level 1 Support
class Level1Support : public SupportHandler
{
public:
    void handleRequest(const string &issue) override
    {
        if (issue == "password reset")
        {
            cout << "Level 1 Support: Resolved issue: " << issue << "\n";
        }
        else if (nextHandler)
        {
            cout << "Level 1 Support: Forwarding issue to next level...\n";
            nextHandler->handleRequest(issue);
        }
        else
        {
            cout << "Level 1 Support: Unable to resolve issue: " << issue << "\n";
        }
    }
};

// Concrete Handler: Level 2 Support
class Level2Support : public SupportHandler
{
public:
    void handleRequest(const string &issue) override
    {
        if (issue == "software installation")
        {
            cout << "Level 2 Support: Resolved issue: " << issue << "\n";
        }
        else if (nextHandler)
        {
            cout << "Level 2 Support: Forwarding issue to next level...\n";
            nextHandler->handleRequest(issue);
        }
        else
        {
            cout << "Level 2 Support: Unable to resolve issue: " << issue << "\n";
        }
    }
};

// Concrete Handler: Level 3 Support
class Level3Support : public SupportHandler
{
public:
    void handleRequest(const string &issue) override
    {
        if (issue == "server outage")
        {
            cout << "Level 3 Support: Resolved issue: " << issue << "\n";
        }
        else
        {
            cout << "Level 3 Support: Unable to resolve issue: " << issue << "\n";
        }
    }
};

// Main function demonstrating usage
int main()
{
    // Create handlers
    auto level1 = make_shared<Level1Support>();
    auto level2 = make_shared<Level2Support>();
    auto level3 = make_shared<Level3Support>();

    // Set up the chain
    level1->setNextHandler(level2);
    level2->setNextHandler(level3);

    // Client sends requests
    cout << "Client: Issue - Password reset\n";
    level1->handleRequest("password reset");

    cout << "\nClient: Issue - Software installation\n";
    level1->handleRequest("software installation");

    cout << "\nClient: Issue - Server outage\n";
    level1->handleRequest("server outage");

    cout << "\nClient: Issue - Network issue\n";
    level1->handleRequest("network issue");

    return 0;
}
