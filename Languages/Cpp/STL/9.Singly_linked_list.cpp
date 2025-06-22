#include <iostream>

#include <iostream>

template <typename T>
class ForwardLinkedList
{
private:
    // Node structure
    struct Node
    {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;
    size_t list_size;

public:
    // Constructor
    ForwardLinkedList() : head(nullptr), list_size(0) {}

    // Destructor to free memory
    ~ForwardLinkedList()
    {
        clear();
    }

    // Add element to the front
    void push_front(const T &value)
    {
        Node *new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        ++list_size;
    }

    // Remove element from the front
    void pop_front()
    {
        if (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            --list_size;
        }
    }

    // Access first element
    T &front()
    {
        if (!head)
            throw std::out_of_range("List is empty");
        return head->data;
    }

    const T &front() const
    {
        if (!head)
            throw std::out_of_range("List is empty");
        return head->data;
    }

    // Check if list is empty
    bool empty() const
    {
        return head == nullptr;
    }

    // Get size of the list
    size_t size() const
    {
        return list_size;
    }

    // Clear the list
    void clear()
    {
        while (head)
        {
            pop_front();
        }
    }

    // Iterator class for ForwardLinkedList
    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *node) : current(node) {}

        T &operator*() const { return current->data; }

        Iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }
    };

    // Begin iterator
    Iterator begin() const { return Iterator(head); }

    // End iterator (nullptr)
    Iterator end() const { return Iterator(nullptr); }
};

int main()
{
    ForwardLinkedList<int> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    std::cout << "List elements: ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    list.pop_front();
    std::cout << "After pop_front, first element is: " << list.front() << std::endl;

    return 0;
}
