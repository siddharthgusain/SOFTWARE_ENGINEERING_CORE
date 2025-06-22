#include <iostream>

template <typename T, size_t s>
class Array
{
private:
    T m_data[s]; // Stored in Stack

public:
    Array()
    {
        for (int i = 0; i < s; i++)
        {
            m_data[i] = 0; // or this->m_data[i] = 0; 
        }
    }

    size_t size() const
    {
        return s;
    }

    T &operator[](size_t index)
    {
        return m_data[index];
    }
};

int main()
{
    Array<int, 5> arr; // Static Array in Stack Not in Heap -> Size should be known before compile time
    for (int i = 0; i < arr.size(); i++)
    {
        std::cin >> arr[i]; // Overloading Operator function is called here
        // std::cin >> arr.operator[](i) // Another way of calling operator[] function inside Array class
        // std::cin.operator>>(arr[i]); -> Another way of calling operator function
    }

    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << "\t";
    }
    return 0;
}

/*
-> Simple Default Array implementation using Class syntax
-> Can't resize this array
-> Allocated in Stack
*/