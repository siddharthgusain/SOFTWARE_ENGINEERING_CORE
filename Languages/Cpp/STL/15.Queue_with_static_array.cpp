#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;     // Static array for the queue
    int capacity; // Maximum capacity of the queue
    int front;    // Index of the front element
    int rear;     // Index of the last element
    int size;     // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to release allocated memory
    ~Queue()
    {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() const
    {
        return size == capacity;
    }

    // Enqueue operation to add an element at the rear
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
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
        int dequeuedValue = arr[front];
        front = (front + 1) % capacity;
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
        return arr[front];
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
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5); // Create a queue with a capacity of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout << "Front element: " << q.peek() << endl;
    cout << "Current size: " << q.getSize() << endl;

    return 0;
}
