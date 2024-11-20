#include <iostream>
#include <memory>

class Notification
{
public:
    virtual void sendNotification(const std::string &message) = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification
{
public:
    void sendNotification(const std::string &message) override
    {
        std::cout << "Sending Email: " << message << std::endl;
    }
};

class SMSNotification : public Notification
{
public:
    void sendNotification(const std::string &message) override
    {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

class PushNotification : public Notification
{
public:
    void sendNotification(const std::string &message) override
    {
        std::cout << "Sending Push Notification: " << message << std::endl;
    }
};

class NotificationFactory
{
public:
    static Notification *createNotification(const std::string &type)
    {
        if (type == "Email")
        {
            return new EmailNotification();
        }
        else if (type == "SMS")
        {
            return new SMSNotification();
        }
        else if (type == "Push")
        {
            return new PushNotification();
        }
        else
        {
            return nullptr;
        }
    }
};

// Client COde
int main()
{
    // Create an Email notification
    Notification *notification = NotificationFactory::createNotification("Email");
    if (notification)
    {
        notification->sendNotification("Hello via Email!");
    }

    // Create an SMS notification
    notification = NotificationFactory::createNotification("SMS");
    if (notification)
    {
        notification->sendNotification("Hello via SMS!");
    }

    // Create a Push notification
    notification = NotificationFactory::createNotification("Push");
    if (notification)
    {
        notification->sendNotification("Hello via Push Notification!");
    }

    return 0;
}
