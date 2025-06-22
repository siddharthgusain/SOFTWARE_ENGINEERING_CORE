#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};

// Queue class using linked list
class Queue
{
private:
    Node *front; // Pointer to the front node
    Node *rear;  // Pointer to the rear node
    int size;    // Number of elements in the queue

public:
    // Constructor to initialize the queue
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // Destructor to free allocated memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Enqueue operation to add an element at the rear
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear == nullptr)
        {
            front = rear = newNode; // If queue is empty, both front and rear point to the new node
        }
        else
        {
            rear->next = newNode; // Link the new node to the end of the queue
            rear = newNode;       // Update rear to the new node
        }
        size++;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation to remove an element from the front
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; // Return -1 for an empty queue
        }
        Node *temp = front;             // Store the front node temporarily
        int dequeuedValue = temp->data; // Retrieve the data from the front node
        front = front->next;            // Move front to the next node
        if (front == nullptr)
        { // If the queue becomes empty
            rear = nullptr;
        }
        delete temp; // Free the memory of the removed node
        size--;
        cout << "Dequeued: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    // Peek at the front element
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1; // Return -1 for an empty queue
        }
        return front->data;
    }

    // Get the current size of the queue
    int getSize() const
    {
        return size;
    }

    // Print the elements in the queue
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q; // Create a queue

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Front element: " << q.peek() << endl;
    cout << "Current size: " << q.getSize() << endl;

    return 0;
}
