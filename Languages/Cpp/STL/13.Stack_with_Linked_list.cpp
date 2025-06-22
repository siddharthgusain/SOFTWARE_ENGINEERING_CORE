#include <iostream>

// Node structure for a linked list
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() { top = nullptr; }

    // Push operation to add an element to the stack
    // Overflow will Never Happen
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        std::cout << x << " pushed into stack\n";
    }

    // Pop operation to remove the top element from the stack
    int pop()
    {
        if (!top)
        {
            std::cout << "Stack Underflow\n";
            return 0; // Indicates empty stack
        }
        else
        {
            int poppedValue = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return poppedValue;
        }
    }

    // Peek operation to get the top element without removing it
    int peek()
    {
        if (!top)
        {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            return top->data;
        }
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return (top == nullptr);
    }
};

// Main function to demonstrate stack operations
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " popped from stack\n";
    std::cout << "Top element is " << s.peek() << std::endl;
    return 0;
}
