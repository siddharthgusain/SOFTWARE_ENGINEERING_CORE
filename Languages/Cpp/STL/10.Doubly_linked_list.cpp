#include <iostream>

template <typename T>
class DoublyLinkedList
{
private:
    // Node structure for the doubly linked list
    struct Node
    {
        T data;
        Node *next;
        Node *prev;

        Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    size_t list_size;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        clear();
    }

    // Add element to the front
    void push_front(const T &value)
    {
        Node *new_node = new Node(value);
        new_node->next = head;

        if (head)
        {
            head->prev = new_node;
        }
        else
        {
            tail = new_node; // If list was empty, new node is also the tail
        }
        head = new_node;
        ++list_size;
    }

    // Add element to the end
    void push_back(const T &value)
    {
        Node *new_node = new Node(value);
        new_node->prev = tail;

        if (tail)
        {
            tail->next = new_node;
        }
        else
        {
            head = new_node; // If list was empty, new node is also the head
        }
        tail = new_node;
        ++list_size;
    }

    // Remove element from the front
    void pop_front()
    {
        if (!head)
            return;

        Node *temp = head;
        head = head->next;

        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // List is now empty
        }

        delete temp;
        --list_size;
    }

    // Remove element from the end
    void pop_back()
    {
        if (!tail)
            return;

        Node *temp = tail;
        tail = tail->prev;

        if (tail)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr; // List is now empty
        }

        delete temp;
        --list_size;
    }

    // Access the first element
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

    // Access the last element
    T &back()
    {
        if (!tail)
            throw std::out_of_range("List is empty");
        return tail->data;
    }

    const T &back() const
    {
        if (!tail)
            throw std::out_of_range("List is empty");
        return tail->data;
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

    // Iterator class for DoublyLinkedList
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

        Iterator &operator--()
        {
            current = current->prev;
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }

        bool operator==(const Iterator &other) const
        {
            return current == other.current;
        }
    };

    // Begin iterator
    Iterator begin() const { return Iterator(head); }

    // End iterator (nullptr)
    Iterator end() const { return Iterator(nullptr); }

    // Reverse iterator
    Iterator rbegin() const { return Iterator(tail); }

    // Reverse end iterator (nullptr)
    Iterator rend() const { return Iterator(nullptr); }
};

int main()
{
    DoublyLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_front(0);

    std::cout << "List elements in forward order: ";
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "List elements in reverse order: ";
    for (auto it = list.rbegin(); it != list.rend(); --it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    list.pop_front();
    std::cout << "After pop_front, first element is: " << list.front() << std::endl;

    list.pop_back();
    std::cout << "After pop_back, last element is: " << list.back() << std::endl;

    return 0;
}
