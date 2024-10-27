#include <iostream>

class IEmailService
{
    virtual void sendEmail() = 0;
};

class MailChimp : public IEmailService
{
public:
    void sendEmail()
    {
        std::cout << "Sending EMail from MailChimp" << std::endl;
    }
};

class SendGrid : public IEmailService
{
public:
    void sendEmail()
    {
        std::cout << "Sending EMail from SendGrid" << std::endl;
    }
};

template <class T>
class CreateUserController
{
    T emailServiceObj;

public:
    CreateUserController(T obj)
    {
        this->emailServiceObj = obj;
    }

    void executeSendEmail()
    {
        emailServiceObj.sendEmail();
    }
};

int main()
{
    MailChimp mailChimpClient;
    SendGrid sendGridClient;
    CreateUserController<MailChimp> obj(mailChimpClient);
    CreateUserController<SendGrid> obj1(sendGridClient);

    obj.executeSendEmail();
    obj1.executeSendEmail();
}

/*
Because we can interchange which implementation of an IEmailService we pass in, we're adhering to LSP.
*/