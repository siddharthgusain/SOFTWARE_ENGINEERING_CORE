#include <iostream>
#define MAX 1000 // Maximum size of the stack

class Stack
{
private:
    int arr[MAX]; // Array to store stack elements
    int top;      // Index of the top element

public:
    // Constructor to initialize the stack
    Stack() { top = -1; }

    // Push operation to add an element to the stack
    bool push(int x)
    {
        if (top >= (MAX - 1))
        {
            std::cout << "Stack Overflow\n";
            return false;
        }
        else
        {
            arr[++top] = x;
            std::cout << x << " pushed into stack\n";
            return true;
        }
    }

    // Pop operation to remove the top element from the stack
    int pop()
    {
        if (top < 0)
        {
            std::cout << "Stack Underflow\n";
            return 0; // Indicates empty stack
        }
        else
        {
            int x = arr[top--];
            return x;
        }
    }

    // Peek operation to get the top element without removing it
    int peek()
    {
        if (top < 0)
        {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            return arr[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return (top < 0);
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
