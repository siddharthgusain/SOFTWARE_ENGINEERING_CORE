#include <iostream>

template <typename T>
class Vector;

// Iterator class for Vector
template <typename T>
class VectorIterator
{
private:
    T *ptr;

public:
    VectorIterator(T *p) : ptr(p) {}

    T &operator*() const { return *ptr; } // overloading "*" operator
    T *operator->() const { return ptr; } // overloading "->"" operator
    T **operator&() { return &ptr; };     // overloading "&"" operator

    // Pre-increment operator
    VectorIterator &operator++()
    {
        ++ptr;
        return *this;
    }

    // Post-increment operator
    VectorIterator operator++(int)
    {
        VectorIterator temp = *this;
        ++ptr;
        return temp;
    }

    // Equality operators
    bool operator==(const VectorIterator &other) const { return ptr == other.ptr; }
    bool operator!=(const VectorIterator &other) const { return ptr != other.ptr; }

    // Friend declaration to allow access to private members of Vector
    friend class Vector<T>;
};

template <typename T>
class Vector
{
public: // public Methods
    // Typedef for iterator
    typedef VectorIterator<T> Iterator;
    Vector()
    {
        reallocate(2); // Making Default first time Heap size be 2 block of memory
    }

    ~Vector()
    {
        delete[] this->m_data_ptr;
    }

    void push_back(T value)
    {
        if (this->current_size >= this->capacity)
        {
            size_t new_capacity = this->capacity + (this->capacity / 2); // Adding Half if current capacity -> Growing by 1.5 Times
            reallocate(new_capacity);
        }

        m_data_ptr[this->current_size] = value;
        this->current_size++;
    }

    size_t size() const
    {
        return this->current_size;
    }

    const T &operator[](size_t index) const
    {
        return this->m_data_ptr[index];
    };

    T &operator[](size_t index)
    {
        return this->m_data_ptr[index];
    };

    // Begin iterator
    Iterator begin() const { return Iterator(this->m_data_ptr); } // Passing First address of Continuous Memory to Iterator Constructor

    // End iterator
    Iterator end() const { return Iterator(this->m_data_ptr + this->current_size); } // Passing Last address of Continuous Memory to Iterator Constructor

private: // private Methods
    void reallocate(size_t new_capacity)
    {
        // 1. Allocate New Memory
        T *new_data_ptr = new T[new_capacity];

        if (new_capacity < this->current_size)
        { // If we are downsizing
            this->current_size = new_capacity;
        }

        // 2. Copy Old Block into New Blocks
        for (int i = 0; i < this->current_size; i++)
        {
            new_data_ptr[i] = this->m_data_ptr[i];
        }

        // 3. Delete Old Block To Let OS reuse that Memory
        delete[] this->m_data_ptr;

        // 4. Add New Block Base Address into m_data_ptr
        this->m_data_ptr = new_data_ptr;

        // 5. Change Capacity
        this->capacity = new_capacity;
    }

private: // private Data Members
    T *m_data_ptr = nullptr;
    size_t current_size = 0; // Number of elements inside Vector
    size_t capacity = 0;     // How Much Heap memory is allocated in Vector
};

// Printing Vector
template <typename T>
void display_vector(const Vector<T> &vec)
{
    std::cout << "Vector: [";
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i]; // vec.operator[](i) -> Another Way of writing
        if (i < vec.size() - 1)
            std::cout << ",";
    }
    std::cout << "]";
}

int main()
{
    Vector<int> vec;

    vec.push_back(20);
    vec.push_back(30);

    display_vector<int>(vec);

    std::cout << std::endl;
    VectorIterator<int> itr = vec.begin();     // begin() return object of Iterator class
    std::cout << &itr << std::endl;            // Overloaded & operator is called
    std::cout << itr.operator&() << std::endl; // Overloaded & operator is called
    std::cout << *itr << std::endl;            // Overloaded * operator is called
    std::cout << itr.operator*();              // Overloaded * operator is called
    return 0;
}

/*
1. Data is Stored in Heap
2. Could be Slow as On Reallocate , a lot of things are done
3. Dynamic as new Heap Allocated Memory is allocated using OS system call during runtime

NOTE: EACH TYPE OF TEMPLATE CLASS CONTAINER WILL HAVE ITS OWN ITERATOR IMPLEMENTATION
-> HOW ALL THESE OVERLOADED OPERATORS BEHAVE IS DIFFERENT FOR EACH DATA STRUCTURES, IN CASE OF CONTINUOUS DATA STRUCTURES
ptr++ MAKES SENSE , IN CASE OF NON-CONTINUOUS DATA STRUCTURES , NEXT ELEMENT IS ACCESSED SIMILAR TO LINKED LIST
SO WE HAVE TO OVERLOAD "++" OPERATOR FOR NON-CONTINUOUS DATA STRUCTURES
*/