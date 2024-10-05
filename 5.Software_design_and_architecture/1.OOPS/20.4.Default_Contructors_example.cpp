#include <iostream>

class Student
{
    int marks;

public:
    Student(); // default constructor declaration
    int get_marks();
};

Student::Student() // default constructor definition
{
    std::cout << "default constructor is called" << std::endl;
    marks = 0;
}

int Student::get_marks()
{
    return this->marks;
}

int main()
{
    Student s1;                  // default constructor is called
    std::cout << s1.get_marks(); // output : 0
    return 0;
}