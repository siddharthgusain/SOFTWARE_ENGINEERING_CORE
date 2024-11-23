#include <iostream>
#include <string>
#include <stack>
#include <memory>

using namespace std;

// Command Interface
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

// Receiver: TextEditor
class TextEditor
{
private:
    string text;

public:
    void addText(const string &newText)
    {
        text += newText;
        cout << "Added text: " << newText << "\n";
    }

    void removeText(size_t length)
    {
        if (length <= text.length())
        {
            text = text.substr(0, text.length() - length);
            cout << "Removed text of length: " << length << "\n";
        }
    }

    const string &getText() const
    {
        return text;
    }

    void display() const
    {
        cout << "Current Text: " << text << "\n";
    }
};

// Concrete Command: AddTextCommand
class AddTextCommand : public Command
{
private:
    TextEditor *editor; // Association
    string textToAdd;

public:
    AddTextCommand(TextEditor *editor, const string &text) : editor(editor), textToAdd(text) {}

    void execute() override
    {
        editor->addText(textToAdd);
    }

    void undo() override
    {
        editor->removeText(textToAdd.length());
    }
};

// Concrete Command: RemoveTextCommand
class RemoveTextCommand : public Command
{
private:
    TextEditor *editor;
    size_t lengthToRemove;

public:
    RemoveTextCommand(TextEditor *editor, size_t length) : editor(editor), lengthToRemove(length) {}

    void execute() override
    {
        editor->removeText(lengthToRemove);
    }

    void undo() override
    {
        // In a real-world app, you would store the removed text for redo
        // For simplicity, we're just adding back some arbitrary text here
        editor->addText("UNDO");
    }
};

// Invoker: CommandHistory (handles undo/redo)
class CommandHistory
{
private:
    stack<shared_ptr<Command>> undoStack;
    stack<shared_ptr<Command>> redoStack;

public:
    void executeCommand(shared_ptr<Command> cmd)
    {
        cmd->execute();
        undoStack.push(cmd);
        while (!redoStack.empty())
            redoStack.pop(); // Clear redo stack on new command
    }

    void undo()
    {
        if (!undoStack.empty())
        {
            shared_ptr<Command> cmd = undoStack.top();
            undoStack.pop();
            cmd->undo();
            redoStack.push(cmd);
        }
        else
        {
            cout << "Nothing to undo.\n";
        }
    }

    void redo()
    {
        if (!redoStack.empty())
        {
            shared_ptr<Command> cmd = redoStack.top();
            redoStack.pop();
            cmd->execute();
            undoStack.push(cmd);
        }
        else
        {
            cout << "Nothing to redo.\n";
        }
    }
};

// Main function demonstrating usage
int main()
{
    // Create a receiver (TextEditor)
    TextEditor myEditor;

    // Create command objects
    shared_ptr<Command> addHello = make_shared<AddTextCommand>(&myEditor, "Hello ");
    shared_ptr<Command> addWorld = make_shared<AddTextCommand>(&myEditor, "World!");
    shared_ptr<Command> removeHello = make_shared<RemoveTextCommand>(&myEditor, 6);

    // Create an invoker (CommandHistory)
    CommandHistory history;

    // Perform actions
    history.executeCommand(addHello);
    myEditor.display(); // Output: Hello

    history.executeCommand(addWorld);
    myEditor.display(); // Output: Hello World!

    history.undo();     // Undo last action
    myEditor.display(); // Output: Hello

    history.redo();     // Redo last undone action
    myEditor.display(); // Output: Hello World!

    history.executeCommand(removeHello); // Remove "Hello"
    myEditor.display();                  // Output: World!

    return 0;
}

/*

1. Command Interface:
Defines two methods: execute() for executing the command and undo() for reverting the command.
Receiver (TextEditor):

2. The TextEditor class holds the text content and provides methods to manipulate the text (add/remove).
Concrete Commands:

3. AddTextCommand: Adds a string to the text.

4. RemoveTextCommand: Removes a certain number of characters from the end of the text.
Both commands implement execute() to perform the action and undo() to revert the action.
Invoker (CommandHistory):

5. CommandHistory is responsible for managing command execution and supporting undo/redo functionality.
It stores executed commands in two stacks: one for undo and one for redo.
Client:

6. The client creates instances of the TextEditor, Command objects, and CommandHistory, setting up the commands and invoking them.

*/