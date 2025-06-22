#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    vector<int> arr; // Vector to store the queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element

public:
    // Constructor to initialize the queue
    Queue() : front(0), rear(-1) {}

    // Check if the queue is empty
    bool isEmpty() const
    {
        return front > rear;
    }

    // Enqueue operation to add an element at the rear
    void enqueue(int value)
    {
        rear++;
        if (rear >= arr.size())
        {
            arr.push_back(value);
        }
        else
        {
            arr[rear] = value;
        }
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
        int dequeuedValue = arr[front];
        front++;
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
        return arr[front];
    }

    // Get the current size of the queue
    int getSize() const
    {
        return isEmpty() ? 0 : rear - front + 1;
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
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
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
    q.enqueue(40);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(50);
    q.enqueue(60);

    q.display();

    cout << "Front element: " << q.peek() << endl;
    cout << "Current size: " << q.getSize() << endl;

    return 0;
}
