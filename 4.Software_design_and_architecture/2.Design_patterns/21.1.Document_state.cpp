#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Forward declaration of Context class
class Document;

// State Interface
class State
{
public:
    virtual void publish(Document &doc) = 0;
    virtual void unpublish(Document &doc) = 0;
    virtual string getStateName() const = 0;
    virtual ~State() = default;
};

// Context: Document
class Document
{
private:
    shared_ptr<State> currentState;

public:
    void setState(shared_ptr<State> state)
    {
        currentState = state;
    }

    void publish()
    {
        if (currentState)
            currentState->publish(*this);
    }

    void unpublish()
    {
        if (currentState)
            currentState->unpublish(*this);
    }

    string getStateName() const
    {
        return currentState ? currentState->getStateName() : "No State";
    }
};

// Concrete States
class DraftState : public State
{
public:
    void publish(Document &doc) override
    {
        cout << "Transitioning from Draft to Moderation." << endl;
        doc.setState(make_shared<ModerationState>());
    }

    void unpublish(Document &doc) override
    {
        cout << "Draft cannot be unpublished. No action taken." << endl;
    }

    string getStateName() const override
    {
        return "Draft";
    }
};

class ModerationState : public State
{
public:
    void publish(Document &doc) override
    {
        cout << "Transitioning from Moderation to Published." << endl;
        doc.setState(make_shared<PublishedState>());
    }

    void unpublish(Document &doc) override
    {
        cout << "Transitioning from Moderation to Draft." << endl;
        doc.setState(make_shared<DraftState>());
    }

    string getStateName() const override
    {
        return "Moderation";
    }
};

class PublishedState : public State
{
public:
    void publish(Document &doc) override
    {
        cout << "Document is already Published. No action taken." << endl;
    }

    void unpublish(Document &doc) override
    {
        cout << "Transitioning from Published to Draft." << endl;
        doc.setState(make_shared<DraftState>());
    }

    string getStateName() const override
    {
        return "Published";
    }
};

// Main function demonstrating the State Pattern
int main()
{
    // Create a document in the Draft state
    Document doc;
    doc.setState(make_shared<DraftState>());

    cout << "Current State: " << doc.getStateName() << endl;

    // Publish the document to move to Moderation
    doc.publish();
    cout << "Current State: " << doc.getStateName() << endl;

    // Publish again to move to Published
    doc.publish();
    cout << "Current State: " << doc.getStateName() << endl;

    // Unpublish to move back to Draft
    doc.unpublish();
    cout << "Current State: " << doc.getStateName() << endl;

    return 0;
}
