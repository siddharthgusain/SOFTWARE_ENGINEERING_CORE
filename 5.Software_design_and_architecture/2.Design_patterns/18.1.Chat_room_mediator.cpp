#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Forward declaration
class Mediator;

// Colleague Interface
class Colleague
{
protected:
    Mediator *mediator;
    string name;

public:
    Colleague(string name, Mediator *mediator) : name(name), mediator(mediator) {}
    virtual void sendMessage(const string &message) = 0;
    virtual void receiveMessage(const string &message) = 0;
    virtual ~Colleague() = default;
};

// Mediator Interface
class Mediator
{
public:
    virtual void sendMessage(const string &message, Colleague *sender) = 0;
    virtual ~Mediator() = default;
};

// Concrete Mediator
class ChatRoomMediator : public Mediator
{
private:
    vector<Colleague *> users;

public:
    void addUser(Colleague *user)
    {
        users.push_back(user);
    }

    void sendMessage(const string &message, Colleague *sender) override
    {
        for (Colleague *user : users)
        {
            if (user != sender)
            {
                user->receiveMessage(message);
            }
        }
    }
};

// Concrete Colleague
class User : public Colleague
{
public:
    User(string name, Mediator *mediator) : Colleague(name, mediator) {}

    void sendMessage(const string &message) override
    {
        cout << name << " sends: " << message << endl;
        mediator->sendMessage(message, this);
    }

    void receiveMessage(const string &message) override
    {
        cout << name << " receives: " << message << endl;
    }
};

// Main function demonstrating the Mediator Pattern
int main()
{
    // Create a mediator
    ChatRoomMediator chatRoom;

    // Create users
    User user1("Alice", &chatRoom);
    User user2("Bob", &chatRoom);
    User user3("Charlie", &chatRoom);

    // Add users to the chat room
    chatRoom.addUser(&user1);
    chatRoom.addUser(&user2);
    chatRoom.addUser(&user3);

    // Communication through the mediator
    user1.sendMessage("Hello everyone!");
    user2.sendMessage("Hi Alice!");
    user3.sendMessage("Good morning!");

    return 0;
}
