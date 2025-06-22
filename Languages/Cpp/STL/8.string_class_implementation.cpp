#include <iostream>
#include <cstring>  // For strlen, strcpy, etc.
#include <iterator> // For std::iterator

class String
{
public:
    // Default constructor
    String() : data(nullptr), size(0) {}

    // Constructor from C-string
    String(const char *str)
    {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    // Copy constructor
    String(const String &other)
    {
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    // Move constructor
    String(String &&other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    // Destructor
    ~String()
    {
        delete[] data;
    }

    // Copy assignment
    String &operator=(const String &other)
    {
        if (this == &other)
            return *this; // self-assignment check
        delete[] data;
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
        return *this;
    }

    // Move assignment
    String &operator=(String &&other) noexcept
    {
        if (this == &other)
            return *this; // self-assignment check
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
        return *this;
    }

    // Size of the string
    std::size_t length() const
    {
        return size;
    }

    // Get C-string
    const char *c_str() const
    {
        return data;
    }

    // Indexing operator
    char &operator[](std::size_t index)
    {
        return data[index];
    }

    const char &operator[](std::size_t index) const
    {
        return data[index];
    }

    // Iterator class
    class Iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = char;
        using difference_type = std::ptrdiff_t;
        using pointer = char *;
        using reference = char &;

        Iterator(pointer ptr) : ptr(ptr) {}

        reference operator*() const { return *ptr; }
        pointer operator->() { return ptr; }

        // Prefix increment
        Iterator &operator++()
        {
            ++ptr;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) { return a.ptr == b.ptr; }
        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.ptr != b.ptr; }

    private:
        pointer ptr;
    };

    // Iterator methods
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

private:
    char *data;
    std::size_t size;
};

// Overloaded stream operator
std::ostream &operator<<(std::ostream &os, const String &str)
{
    os << str.c_str();
    return os;
}

// Overloaded stream extraction operator
std::istream &operator>>(std::istream &is, String &str)
{
    char buffer[1000]; // Arbitrary buffer size for simplicity
    is >> buffer;
    str = String(buffer);
    return is;
}

int main()
{
    String str;
    std::cout << "Enter a string: ";
    std::cin >> str;
    std::cout << "You entered: " << str << std::endl;

    // Using iterators
    for (String::Iterator it = str.begin(); it != str.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
