#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Iterator Interface
template <typename T>
class Iterator
{
public:
    virtual bool hasNext() const = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};

// Concrete Iterator
template <typename T>
class VectorIterator : public Iterator<T>
{
private:
    const vector<T> &collection;
    size_t index;

public:
    VectorIterator(const vector<T> &collection) : collection(collection), index(0) {}

    bool hasNext() const override
    {
        return index < collection.size();
    }

    T next() override
    {
        return collection[index++];
    }
};

// Aggregate Interface
template <typename T>
class Aggregate
{
public:
    virtual unique_ptr<Iterator<T>> createIterator() const = 0;
    virtual ~Aggregate() = default;
};

// Concrete Aggregate
template <typename T>
class NumberCollection : public Aggregate<T>
{
private:
    vector<T> numbers;

public:
    void addNumber(const T &number)
    {
        numbers.push_back(number);
    }

    unique_ptr<Iterator<T>> createIterator() const override
    {
        return make_unique<VectorIterator<T>>(numbers);
    }
};

// Main function demonstrating the pattern
int main()
{
    // Create a collection
    NumberCollection<int> numbers;
    numbers.addNumber(10);
    numbers.addNumber(20);
    numbers.addNumber(30);

    // Get an iterator for the collection
    unique_ptr<Iterator<int>> iterator = numbers.createIterator();

    // Iterate through the collection
    while (iterator->hasNext())
    {
        cout << iterator->next() << " ";
    }

    return 0;
}
