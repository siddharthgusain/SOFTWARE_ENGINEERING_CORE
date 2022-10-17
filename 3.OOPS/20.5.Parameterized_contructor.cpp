#include <iostream>

class Student
{
    int marks;

public:
    Student(int marks); // Parametrized contructor declaration
    int get_marks();
};

Student::Student(int marks) // Parametrized constructor definition
{
    std::cout << "parameterized constructor called" << std::endl;
    this->marks = marks;
}

int Student::get_marks()
{
    return this->marks;
}

int main()
{
    Student s1(10);            // implicit call
    Student s2 = Student(100); // explicit call
    std::cout << s1.get_marks() << std::endl;
    std::cout << s2.get_marks();
    return 0;
}