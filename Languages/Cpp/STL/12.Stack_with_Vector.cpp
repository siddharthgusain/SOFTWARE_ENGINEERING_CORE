#include <iostream>
#include <vector>

class Stack
{
private:
    std::vector<int> stack; // Vector to store stack elements -> Aggregation of vector class -> Stack class "has-a" vector object 

public:
    // Push operation to add an element to the stack
    void push(int x)
    {
        stack.push_back(x);
        std::cout << x << " pushed into stack\n";
    }

    // Pop operation to remove the top element from the stack
    int pop()
    {
        if (stack.empty())
        {
            std::cout << "Stack Underflow\n";
            return 0; // Indicates the stack is empty
        }
        else
        {
            int topElement = stack.back();
            stack.pop_back();
            return topElement;
        }
    }

    // Peek operation to get the top element without removing it
    int peek()
    {
        if (stack.empty())
        {
            std::cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            return stack.back();
        }
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return stack.empty();
    }

    // Return the size of the stack
    int size()
    {
        return stack.size();
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
    std::cout << "Stack size is " << s.size() << std::endl;

    return 0;
}
