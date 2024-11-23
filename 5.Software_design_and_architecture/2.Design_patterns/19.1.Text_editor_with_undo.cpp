#include <iostream>
#include <string>
#include <stack>
#include <memory>
using namespace std;

// Memento: Stores the state of the Originator
class Memento
{
private:
    string state;

public:
    explicit Memento(const string &state) : state(state) {}

    string getState() const
    {
        return state;
    }
};

// Originator: The object whose state needs to be saved and restored
class TextEditor
{
private:
    string content;

public:
    void type(const string &text)
    {
        content += text;
    }

    string getContent() const
    {
        return content;
    }

    // Save the current state to a memento
    shared_ptr<Memento> save() const
    {
        return make_shared<Memento>(content);
    }

    // Restore the state from a memento
    void restore(const shared_ptr<Memento> &memento)
    {
        content = memento->getState();
    }
};

// Caretaker: Manages the history of mementos
class Caretaker
{
private:
    stack<shared_ptr<Memento>> history;

public:
    void save(const shared_ptr<Memento> &memento)
    {
        history.push(memento);
    }

    shared_ptr<Memento> undo()
    {
        if (history.empty())
        {
            return nullptr;
        }
        auto memento = history.top();
        history.pop();
        return memento;
    }
};

// Main function demonstrating the Memento Pattern
int main()
{
    TextEditor editor;
    Caretaker caretaker;

    // Type some text
    editor.type("Hello");
    caretaker.save(editor.save()); // Save state
    cout << "Content after typing 'Hello': " << editor.getContent() << endl;

    editor.type(" World");
    caretaker.save(editor.save()); // Save state
    cout << "Content after typing ' World': " << editor.getContent() << endl;

    editor.type("!!!");
    cout << "Content after typing '!!!': " << editor.getContent() << endl;

    // Undo operations
    editor.restore(caretaker.undo());
    cout << "Content after undo: " << editor.getContent() << endl;

    editor.restore(caretaker.undo());
    cout << "Content after second undo: " << editor.getContent() << endl;

    return 0;
}
